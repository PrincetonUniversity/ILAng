/// \file
/// Source for bounded model checking

#include "eq-check/bmc.h"

namespace ila {

typedef Bmc::UpdateMap UpdateMap;
typedef Bmc::InstrSet InstrSet;

Bmc::Bmc() {}

Bmc::~Bmc() {}

// z3::context& Bmc::ctx() { return ctx_; }

// void Bmc::set_def_tran(bool use) { def_tran_ = use; }

void Bmc::AddInit(ExprPtr init) { inits_.push_back(init); }

void Bmc::AddInvariant(ExprPtr inv) { invs_.push_back(inv); }

z3::check_result Bmc::BmcLegacy(InstrLvlAbsPtr m0, const int& k0,
                                InstrLvlAbsPtr m1, const int& k1) {
  ILA_NOT_NULL(m0);
  ILA_NOT_NULL(m1);

  ModelExprGen mod_gen(ctx_);
  z3::solver solver(ctx_);

  // unroll m0
  auto cnst_m0 = UnrollCmplIla(m0, k0);
  solver.add(cnst_m0);

  // untoll m1
  auto cnst_m1 = UnrollCmplIla(m1, k1);
  solver.add(cnst_m1);

  auto state_num_m0 = m0->state_num();
  auto suffix_init = std::to_string(0);
  auto suffix_k0 = std::to_string(k0);
  auto suffix_k1 = std::to_string(k1);
  for (size_t i = 0; i != state_num_m0; i++) {
    auto state_m0 = m0->state(i);
    auto state_m1 = m1->state(state_m0->name().str());
    ILA_ASSERT(state_m1 != NULL) << "State unmatched: " << state_m0;

    // equal initial condition
    auto state_m0_init = mod_gen.Node(state_m0, suffix_init);
    auto state_m1_init = mod_gen.Node(state_m1, suffix_init);
    auto init_cnst_i = (state_m0_init == state_m1_init);
    solver.add(init_cnst_i);

    // assert equal final state
    auto state_m0_final = mod_gen.Node(state_m0, suffix_k0);
    auto state_m1_final = mod_gen.Node(state_m1, suffix_k1);
    auto assert_i = (state_m0_final == state_m1_final);
    solver.add(!assert_i);
  }

  // equal input
  auto input_num_m0 = m0->input_num();
  for (size_t i = 0; i != input_num_m0; i++) {
    auto input_m0 = m0->input(i);
    auto input_m1 = m1->input(input_m0->name().str());
    ILA_ASSERT(input_m1 != NULL) << "Input unmatched: " << input_m0;

    auto input_m0_init = mod_gen.Node(input_m0, suffix_init);
    auto input_m1_init = mod_gen.Node(input_m1, suffix_init);
    auto init_input = (input_m0_init == input_m1_init);
    solver.add(init_input);
  }

  // initial condition
  for (size_t i = 0; i != inits_.size(); i++) {
    auto init_i = inits_[i];
    // ILA_ASSERT(init_i->host()) << "Legacy BMC can only have single-ILA
    // init.";
    auto init_e = mod_gen.Node(init_i, suffix_init);
    solver.add(init_e);
  }

  // invariants
  for (size_t i = 0; i != invs_.size(); i++) {
    auto inv_i = invs_[i];
    // ILA_ASSERT(inv_i->host()) << "Legacy BMC can only have single-ILA inv.";
    // XXX Only apply invariants on initial states.
    auto inv_e = mod_gen.Node(inv_i, suffix_init);
    solver.add(inv_e);
  }

  auto result = solver.check();

  if (result == z3::sat) {
    auto m = solver.get_model();
    ILA_DLOG("Bmc.Legacy") << m;
  }

  return result;
}

#if 0
z3::check_result Bmc::BmcProp(InstrLvlAbsPtr m, const int& k) {
  ILA_NOT_NULL(m);
  ILA_ASSERT(k > 0) << "Invalid unroll steps.";

  ModelExprGen gen(ctx_);
  z3::solver solver(ctx_);

  // transition relations
  auto cnst_tran = UnrollCmplIla(m, k); // XXX
  solver.add(cnst_tran);

  // TODO
  // initial condition
  // invariants
  // properties

  // check the result
  auto result = solver.check();

  // report false model

  return result;
}
#endif

// ------------------- PRIVATE FUNCTIONS ------------------------------------ //

z3::expr Bmc::UnrollCmplIla(InstrLvlAbsPtr m, const int& k, const int& pos) {
  ILA_NOT_NULL(m);
  ILA_ASSERT(k > 0) << "Invalid unroll steps.";
  ILA_ASSERT(pos >= 0) << "Negative starting frame number.";

  ModelExprGen gen(ctx_);
  auto cnst = ctx_.bool_val(true);

  for (auto i = 0; i != k; i++) {
    auto suf_prev = std::to_string(pos + i);
    auto suf_next = std::to_string(pos + i + 1);
    /// FIXME May not be one hot and flat -- based on flags.
    auto cnst_i = gen.IlaOneHotFlat(m, suf_prev, suf_next);
    /// FIXME Use rewrite for better performance -- based on flags (or def)
    cnst = cnst_i && cnst;
  }

  return cnst;
}

#if 0
// - Traverse the hierarchy to collect state/instr dependency map.
// - Check totality and insert default instruction for states (in next steps).
// - Generate guard (valid and decode function) of each instruction.
// - Generate state transition relation of each instruction.
// - Check if one-hot and generate instruction selection relation.
z3::expr Bmc::IlaStep(InstrLvlAbsPtr m, const std::string& suf_prev,
                      const std::string& suf_next) {
  // traverse the hierarchy to collect state update map
  UpdateMap updt_map;
  CollectUpdateMap(m, updt_map);

  // for each state
  for (auto it = updt_map.begin(); it != updt_map.end(); it++) {
    // check totality and insert default instruction if needed
    MkCmplByDefInstr(it->first, it->second);
  }

  auto res = ctx_.bool_val(true);
  // recursively generate guard relation of each instruction
  auto guard_rel = GenGuardRel(m, suf_prev);
  res = res && guard_rel;

  // recursively generate transition relation of each instruction
  auto tran_rel = GenTranRel(m, suf_prev, suf_next);
  res = res && tran_rel;

  auto sel_candid = MergeInstrSet(updt_map);
  // for each state
  for (auto it = sel_candid.begin(); it != sel_candid.end(); it++) {
    // check one-hot
    auto one_hot = CheckOneHot(*it);
    if (!one_hot) {
      // generate instruction selection relation if needed
      auto sel_rel = GenSelRel(*it);
      res = res && sel_rel;
    }
  }

  res = res.simplify();
  return res;
}

// Check if need to use default transition for all instructions.
void Bmc::CollectUpdateMap(InstrLvlAbsPtr m, UpdateMap& map) const {
  ILA_DLOG("Bmc.IlaStep") << "Collecting state update mapping for " << m;

  // collect self
  auto instr_num = m->instr_num();
  auto state_num = m->state_num();
  // for each instruction
  for (size_t i = 0; i != instr_num; i++) {
    auto instr = m->instr(i);
    // for each state
    for (size_t j = 0; j != state_num; j++) {
      auto state = m->state(j);
      // check if there is an update
      auto updt = instr->GetUpdate(state);
      // update map if use default or there is an update
      if (updt || def_tran_) {
        map.insert(state, instr);
      }
    }
  }

  // collect child
  auto child_num = m->child_num();
  for (size_t i = 0; i != child_num; i++) {
    auto child = m->child(i);
    CollectUpdateMap(child, map);
  }
}

void Bmc::MkCmplByDefInstr(ExprPtr s, InstrSet& updts) {
  using namespace ExprFuse;

  ILA_DLOG("Bmc.IlaStep") << "Check transition totality for state " << s;
  // conjunct all guards (decode)
  auto guard = BoolConst(false);
  for (auto it = updts.begin(); it != updts.end(); it++) {
    auto guard_i = (*it)->GetDecode(); // XXX host valid not considered
    guard = Or(guard, guard_i);
  }
  auto cnst = gen_.GetExpr(guard);

  // check totality
  z3::solver solver(ctx_);
  solver.add(!cnst);
  auto res = solver.check();

  // create default instruction for the state if not total
  if (res == z3::sat) {
    ILA_DLOG("Bmc.IlaStep") << "Complete transition for state " << s;
    auto m = s->host();
    auto instr = m->NewInstr("DefInstr." + s->name().str());
    // default condition
    instr->SetDecode(Not(guard));
    // remain unchanged
    instr->AddUpdate(s, s);
  }
}

z3::expr Bmc::GenGuardRel(InstrLvlAbsPtr m, const std::string& suf_prev) {
  auto res = ctx_.bool_val(true);
  // TODO guards are bind to suffix

  res = res.simplify();
  return res;
}

z3::expr Bmc::GenTranRel(InstrLvlAbsPtr m, const std::string& suf_prev,
                         const std::string& suf_next) {
  auto res = ctx_.bool_val(true);
  // TODO

  res = res.simplify();
  return res;
}

std::set<InstrSet> Bmc::MergeInstrSet(UpdateMap& updts) {
  std::set<InstrSet> merge;
  // TODO
  return merge;
}

bool Bmc::CheckOneHot(InstrSet updts) {
  // TODO
  return true;
}

z3::expr Bmc::GenSelRel(InstrSet updts) {
  auto res = ctx_.bool_val(true);
  // FIXME this should not be used

  return res;
}
#endif

} // namespace ila

