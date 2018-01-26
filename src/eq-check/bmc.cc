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
  ILA_ASSERT(k0 > 0) << "Non-positive unroll step " << k0;
  for (auto i = 0; i != k0; i++) {
    auto suffix_i = std::to_string(i);
    auto suffix_n = std::to_string(i + 1);
    auto cnst_i = mod_gen.IlaOneHotFlat(m0, suffix_i, suffix_n);
    solver.add(cnst_i);
  }

  // untoll m1
  ILA_ASSERT(k1 > 0) << "Non-positive unroll step " << k1;
  for (auto i = 0; i != k1; i++) {
    auto suffix_i = std::to_string(i);
    auto suffix_n = std::to_string(i + 1);
    auto cnst_i = mod_gen.IlaOneHotFlat(m1, suffix_i, suffix_n);
    solver.add(cnst_i);
  }

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

  auto result = solver.check();

  if (result == z3::sat) {
    auto m = solver.get_model();
    ILA_DLOG("Bmc.Legacy") << m;
  }

  return result;
}

} // namespace ila

