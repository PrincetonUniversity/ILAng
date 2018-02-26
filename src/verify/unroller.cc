/// \file
/// Source for unrolling ILA execution.

#include "verify/unroller.h"
#include "util/log.h"
#include <map>
#include <vector>

namespace ila {

typedef Unroller::ZExpr ZExpr;

Unroller::Unroller(z3::context& ctx)
    : ctx_(ctx), gen_(Z3ExprAdapter(ctx)), k_prev_(ctx), k_curr_z3_(ctx),
      k_next_z3_(ctx), cstr_(ctx) {}

Unroller::~Unroller() {}

void Unroller::AddGlobPred(const ExprPtr p) { g_pred_.push_back(p); }

void Unroller::AddInitPred(const ExprPtr p) { i_pred_.push_back(p); }

void Unroller::ClearGlobPred() { g_pred_.clear(); }

void Unroller::ClearInitPred() { i_pred_.clear(); }

ZExpr Unroller::UnrollSubs(const size_t& len, const int& pos) {
  // bootstrap basic information
  BootStrap(pos);

  // unroll based on g_pred, i_pred, and transition relation (with guard)
  for (size_t i = 0; i != len; i++) {
    // time-stamp for this time-frame
    // auto k_suff = std::to_string(pos + i);
    auto k_stamp = pos + i;

    // get transition relation (i_next_) and step-specific predicate (k_pred_)
    Transition(i);

    // the source for substitution
    ZExprVec k_curr(ctx());
    GenZExprVec(k_curr, vars_, k_stamp);

    // rewrite and add initial predicate
    if (i == 0) {
      AssertPredSubs(i_pred_, k_stamp, k_curr, k_prev_);
    }
    // rewrite and add global predicate
    AssertPredSubs(g_pred_, k_stamp, k_curr, k_prev_);
    // rewrite and add step-specific predicate
    AssertPredSubs(k_pred_, k_stamp, k_curr, k_prev_);

    // rewrite and add transition relation
    UpdateNextSubs(k_next_z3_, k_next_, k_stamp, k_curr, k_prev_);

    // update next state function to the prev for next step
    AssignZExprVec(k_prev_, k_next_z3_);
  }

  // add constraints for transition relation (k_prev_ has the last value)
  AssertVarEqual(k_prev_, vars_, len);

  // accumulate all constraints and return
  auto cstr = ConjPred(cstr_);
  return cstr;
}

ZExpr Unroller::UnrollAssn(const size_t& len, const int& pos) {
  // TODO
}

ExprPtr Unroller::StateUpdCmpl(const InstrPtr instr, const ExprPtr var) {
  auto upd = instr->GetUpdate(var);
  return (upd) ? upd : var;
}

void Unroller::BootStrap(const int& pos) {
  // collect dependant state variables
  vars_.clear();
  CollectVar();
  ILA_ASSERT(!vars_.empty()) << "No state variable defined.";

  // prepare the table
  k_prev_.resize(0);
  for (auto it = vars_.begin(); it != vars_.end(); it++) {
    auto suff = std::to_string(pos);
    auto ivar = *it;
    auto zvar = gen().GetExpr(ivar, suff);
    k_prev_.push_back(zvar);
  }
}

void Unroller::AssertPredSubs(const IExprVec& pred_vec, const int& stamp,
                              const ZExprVec& src_vec,
                              const ZExprVec& dst_vec) {
  auto suffix = std::to_string(stamp);
  for (auto it = pred_vec.begin(); it != pred_vec.end(); it++) {
    auto pred = *it;
    auto expr = gen().GetExpr(pred, suffix);
    auto expr_subs = Substitute(expr, src_vec, dst_vec);
    cstr_.push_back(expr_subs);
  }
}

void Unroller::UpdateNextSubs(ZExprVec& next_z, const IExprVec& next_i,
                              const int& stamp, const ZExprVec& src,
                              const ZExprVec& dst) {
  auto suffix = std::to_string(stamp);
  next_z.resize(0);
  for (auto it = next_i.begin(); it != next_i.end(); it++) {
    auto i_expr = *it;
    auto z_expr = gen().GetExpr(i_expr, suffix);
    auto z_subs = Substitute(z_expr, src, dst);
    next_z.push_back(z_subs);
  }
}

void Unroller::AssertVarEqual(const ZExprVec& a, const IExprSet& b,
                              const int& stamp) {
  auto suffix = std::to_string(stamp);
  ILA_ASSERT(a.size() == b.size()) << "Var num mismatch.";
  auto i = 0;
  for (auto it = b.begin(); it != b.end(); it++, i++) {
    auto bi = gen().GetExpr(*it, suffix);
    auto ai = a[i];
    auto equal = (ai == bi);
    cstr_.push_back(equal);
  }
}

ZExpr Unroller::Substitute(ZExpr expr, const ZExprVec& src_vec,
                           const ZExprVec& dst_vec) const {
  return expr.substitute(src_vec, dst_vec);
}

void Unroller::GenZExprVec(ZExprVec& dst, const IExprSet& src,
                           const int& stamp) {
  dst.resize(0);
  auto suffix = std::to_string(stamp);
  for (auto it = src.begin(); it != src.end(); it++) {
    auto i_expr = *it;
    auto z_expr = gen().GetExpr(i_expr, suffix);
    dst.push_back(z_expr);
  }
}

void Unroller::AssignZExprVec(ZExprVec& dst, const ZExprVec& src) {
  dst.resize(0);
  for (unsigned i = 0; i != src.size(); i++) {
    dst.push_back(src[i]);
  }
}

ZExpr Unroller::ConjPred(const ZExprVec& vec) {
  auto conj = ctx().bool_val(true);
  for (size_t i = 0; i != vec.size(); i++) {
    conj = (conj && vec[i]);
  }
  conj = conj.simplify();
  return conj;
}

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
  auto next = std::to_string(pos + seq_len);
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

ListUnroll::ListUnroll(z3::context& ctx) : Unroller(ctx) {}

ListUnroll::~ListUnroll() {}

ZExpr ListUnroll::InstrSeqSubs(const InstrVec& seq, const int& pos) {
  // set up target transition relation
  seq_ = seq;
  auto cstr = UnrollSubs(seq.size(), pos);
  return cstr;
}

void ListUnroll::CollectVar() {
  for (size_t i = 0; i != seq_.size(); i++) {
    auto m = seq_[i]->host();
    ILA_NOT_NULL(m);
    // add states if no child-ILAs
    for (size_t i = 0; i != m->state_num(); i++) {
      vars_.insert(m->state(i));
    }
  }
}

void ListUnroll::Transition(const size_t& idx) {
  ILA_CHECK(idx < seq_.size()) << "Out-of-bound transition not defined.";
  auto instr = seq_[idx];

  // update next state function (k_next_)
  k_next_.resize(0);
  for (auto it = vars_.begin(); it != vars_.end(); it++) {
    auto var = *it;
    auto next = StateUpdCmpl(instr, var);
    k_next_.push_back(next);
  }

  // update step predicate (k_pred_)
  k_pred_.resize(0);
  auto dec = instr->GetDecode();
  ILA_NOT_NULL(dec);
  k_pred_.push_back(dec);
}

#if 0
BulkUnroll::BulkUnroll(z3::context& ctx, const InstrLvlAbsPtr top)
    : Unroller(ctx), top_(top) {}

BulkUnroll::~BulkUnroll() {}

void BulkUnroll::CollectVar() { VisitHierCollectVar(top_); }

void BulkUnroll::VisitHierCollectVar(const InstrLvlAbsPtr m) {
  ILA_NOT_NULL(m);

  // traverse the child-ILAs
  for (size_t i = 0; i != m->child_num(); i++) {
    VisitHierCollectVar(m->child(i));
  }

  // child-states must contain parent-states
  if (m->child_num() != 0)
    return;

  // add states if no child-ILAs
  for (size_t i = 0; i != m->state_num(); i++) {
    ivar_.insert(m->state(i));
  }
}
#endif

} // namespace ila

