/// \file
/// Source for unrolling ILA execution.

#include "verify/unroller.h"
#include "util/log.h"
#include <map>
#include <vector>

namespace ila {

Unroller::Unroller(z3::context& ctx) : ctx_(ctx), gen_(Z3ExprAdapter(ctx)) {}

Unroller::~Unroller() {}

z3::expr Unroller::InstrSeq(const std::vector<InstrPtr>& seq, const int& pos) {
  // collect all dependant states
  auto st_set = GetAllVar(seq);

  auto seq_len = seq.size();

  // collect z3::expr mapping of states for each time frame
  std::vector<std::map<ExprPtr, z3::expr>> frame_map;
  frame_map.resize(seq_len);

  ILA_DLOG("Unroller.InstrSeq") << "Start generating table.";
  // go through each time frame (pos+i to pos+i+1)
  for (size_t i = 0; i != seq_len; i++) {
    auto prev = std::to_string(pos + i);

    ILA_DLOG("Unroller.InstrSeq") << "Table for frame " << i;
    // enumerate each state to get the update function
    for (auto it = st_set.begin(); it != st_set.end(); it++) {
      auto var = *it;
      auto upd = StateUpdCmpl(seq[i], var, prev);
      frame_map[i].insert({var, upd});
    }

    // decode function
    auto dec = seq[i]->GetDecode();
    auto zdec = gen_.GetExpr(dec, prev);
    frame_map[i].insert({dec, zdec});
  }

  // accumulating variable
  auto upd_acc = ctx().bool_val(true);

  // rewrite (starting from the second frame)
  for (size_t i = 1; i != seq_len; i++) {
    auto prev = std::to_string(pos + i);
    z3::expr_vector src_vec(ctx());
    z3::expr_vector dst_vec(ctx());

    // prepart source and destination for substitution
    for (auto it = st_set.begin(); it != st_set.end(); it++) {
      auto var = *it;
      auto src = gen_.GetExpr(var, prev);
      auto dst = frame_map[i - 1].at(var);
      src_vec.push_back(src);
      dst_vec.push_back(dst);
    }

    // substitute states
    for (auto it = st_set.begin(); it != st_set.end(); it++) {
      auto var = *it;
      auto org = frame_map[i].at(var);
      auto sub = org.substitute(src_vec, dst_vec);
      frame_map[i].erase(var);
      frame_map[i].insert({var, sub});
    }
    // substitute decode
    auto dec = seq[i]->GetDecode();
    auto org = frame_map[i].at(dec);
    auto sub = org.substitute(src_vec, dst_vec);
    frame_map[i].erase(dec);
    frame_map[i].insert({dec, sub});

    // accumulate in construction
    upd_acc = upd_acc && sub;
  }

  // accumulate final constraint
  // auto upd_acc = ctx().bool_val(true);
  auto next = std::to_string(pos + seq_len + 1);
  // states
  std::map<ExprPtr, z3::expr>& last_frame = frame_map.back();
  for (auto it = st_set.begin(); it != st_set.end(); it++) {
    auto var = *it;
    auto end_var = gen_.GetExpr(var, next);
    auto end_upd = last_frame.at(var);
    auto cstr = (end_var == end_upd);
    upd_acc = upd_acc && cstr;
  }
  // decodes is accumulated when generating the table

  upd_acc = upd_acc.simplify();
  return upd_acc;
}

z3::expr Unroller::InstrUpdDflt(const InstrLvlAbsPtr ila,
                                const std::string& prev,
                                const std::string& next) {
  ILA_NOT_NULL(ila);

  // update function accumulator
  auto upd_acc = ctx().bool_val(true);
  // enumerate through all states in the ILA.
  auto state_num = ila->state_num();
  for (size_t i = 0; i != state_num; i++) {
    auto var_i = ila->state(i);                // state var
    auto next_var = gen_.GetExpr(var_i, next); // next state var
    auto next_upd = gen_.GetExpr(var_i, prev); // next state function
    auto connect = (next_var == next_upd);     // assert same
    upd_acc = (connect && upd_acc);            // add to the accumulator
  }

  upd_acc = upd_acc.simplify();
  return upd_acc;
}

z3::expr Unroller::InstrUpdCmpl(const InstrPtr instr, const std::string& prev,
                                const std::string& next) {
  ILA_NOT_NULL(instr);
  auto ila = instr->host(); // can only unroll Instr with host ILA
  ILA_NOT_NULL(ila);

  // update function accumulator
  auto upd_acc = ctx().bool_val(true);
  // enumerate through all states in the ILA.
  auto state_num = ila->state_num();
  for (size_t i = 0; i != state_num; i++) {
    auto var_i = ila->state(i);           // state var
    auto upd_i = instr->GetUpdate(var_i); // next state function

    if (upd_i) { // update function has been defined
      auto next_var = gen_.GetExpr(var_i, next); // next state var
      auto next_upd = gen_.GetExpr(upd_i, prev); // next state function
      auto connect = (next_var == next_upd);     // assert same
      upd_acc = (connect && upd_acc);            // add to the accumulator
    } else { // update function not yet defined
      ILA_DLOG("Unroller") << instr << ": " << var_i << " update not defined.";
    }
  }

  upd_acc = upd_acc.simplify();
  return upd_acc;
}

z3::expr Unroller::StateUpdCmpl(const InstrPtr instr, const ExprPtr var,
                                const std::string& prev) {
  auto upd = instr->GetUpdate(var);
  if (upd) { // update function has been defined
    return gen_.GetExpr(upd, prev);
  } else { // update function not yet defined
    return gen_.GetExpr(var, prev);
  }
}

std::set<ExprPtr> Unroller::GetAllVar(const std::vector<InstrPtr>& seq) const {
  ILA_CHECK(!seq.empty()) << "Unrolling empty sequence.";

  // the set of host ILAs (used for collecting all states)
  std::set<InstrLvlAbsPtr> ila_set;
  for (size_t i = 0; i != seq.size(); i++) {
    auto h = seq[i]->host();
    ILA_NOT_NULL(h);
    ila_set.insert(h);
  }

  // collect all dependant states
  std::set<ExprPtr> st_set;
  for (auto it = ila_set.begin(); it != ila_set.end(); it++) {
    auto m = *it;
    for (size_t i = 0; i != m->state_num(); i++) {
      st_set.insert(m->state(i));
    }
  }
  ILA_ASSERT(!st_set.empty()) << "No state in the given model.";

  return st_set;
}

} // namespace ila

