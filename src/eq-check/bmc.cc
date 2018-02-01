/// \file
/// Source for bounded model checking

#include "eq-check/bmc.h"

namespace ila {
Bmc::Bmc() {}

Bmc::~Bmc() {}

z3::context& Bmc::ctx() { return ctx_; }

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
    ILA_ASSERT(init_i->host()) << "Legacy BMC can only have single-ILA init.";
    auto init_e = mod_gen.Node(init_i, suffix_init);
    solver.add(init_e);
  }

  // invariants
  for (auto i = 0; i != invs_.size(); i++) {
    auto inv_i = invs_[i];
    ILA_ASSERT(inv_i->host()) << "Legacy BMC can only have single-ILA inv.";
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

z3::check_result Bmc::BmcProp(InstrLvlAbsPtr m, const int& k) {
  ILA_NOT_NULL(m);
  ILA_ASSERT(k > 0) << "Invalid unroll steps.";

  ModelExprGen gen(ctx_);
  z3::solver solver(ctx_);

  // transition relations
  auto cnst_tran = UnrollCmplIla(m, k);
  solver.add(cnst_tran);

  // initial condition
  // invariants
  // properties

  // check the result
  auto result = solver.check();

  // report false model

  return result;
}

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

} // namespace ila

