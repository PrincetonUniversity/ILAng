/// \file
/// Source for bounded model checking

#include <ilang/ila-mngr/v_eq_check_legacy_bmc.h>

#include <ilang/util/log.h>
#include <ilang/util/z3_helper.h>

namespace ilang {

LegacyBmc::LegacyBmc() {}

LegacyBmc::~LegacyBmc() {}

void LegacyBmc::AddInit(ExprPtr init) { inits_.push_back(init); }

void LegacyBmc::AddInvariant(ExprPtr inv) { invs_.push_back(inv); }

z3::check_result LegacyBmc::Check(InstrLvlAbsPtr m0, const int& k0,
                                  InstrLvlAbsPtr m1, const int& k1) {
  ILA_NOT_NULL(m0);
  ILA_NOT_NULL(m1);

  auto gen = Z3ExprAdapter(ctx_);
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
    auto state_m1 = m1->find_state(state_m0->name());
    ILA_NOT_NULL(state_m1);

    // equal initial condition
    auto state_m0_init = gen.GetExpr(state_m0, suffix_init);
    auto state_m1_init = gen.GetExpr(state_m1, suffix_init);
    auto init_cnst_i = (state_m0_init == state_m1_init);
    solver.add(init_cnst_i);

    // assert equal final state
    auto state_m0_final = gen.GetExpr(state_m0, suffix_k0);
    auto state_m1_final = gen.GetExpr(state_m1, suffix_k1);
    auto assert_i = (state_m0_final == state_m1_final);
    solver.add(!assert_i);
  }

  // equal input
  auto input_num_m0 = m0->input_num();
  for (size_t i = 0; i != input_num_m0; i++) {
    auto input_m0 = m0->input(i);
    auto input_m1 = m1->find_input(input_m0->name());
    ILA_NOT_NULL(input_m1);

    auto input_m0_init = gen.GetExpr(input_m0, suffix_init);
    auto input_m1_init = gen.GetExpr(input_m1, suffix_init);
    auto init_input = (input_m0_init == input_m1_init);
    solver.add(init_input);
  }

  // initial condition
  for (size_t i = 0; i != inits_.size(); i++) {
    auto init_i = inits_[i];
    auto init_e = gen.GetExpr(init_i, suffix_init);
    solver.add(init_e);
  }

  // invariants
  for (size_t i = 0; i != invs_.size(); i++) {
    auto inv_i = invs_[i];
    // XXX Only apply invariants on initial states.
    auto inv_e = gen.GetExpr(inv_i, suffix_init);
    solver.add(inv_e);
  }

  auto result = solver.check();

  if (result == z3::sat) {
    auto m = solver.get_model();
    ILA_DLOG("Bmc.Legacy") << m;
  }

  return result;
}

// ------------------- PRIVATE FUNCTIONS ------------------------------------ //

z3::expr LegacyBmc::UnrollCmplIla(InstrLvlAbsPtr m, const int& k,
                                  const int& pos) {
  ILA_NOT_NULL(m);
  ILA_ASSERT(k > 0) << "Invalid unroll steps.";
  ILA_ASSERT(pos >= 0) << "Negative starting frame number.";

  auto cnst = ctx_.bool_val(true);

  for (auto i = 0; i != k; i++) {
    auto suf_prev = std::to_string(pos + i);
    auto suf_next = std::to_string(pos + i + 1);
    /// XXX May not be one hot and flat -- based on flags.
    auto cnst_i = IlaOneHotFlat(m, suf_prev, suf_next);
    /// XXX Use rewrite for better performance -- based on flags (or def)
    cnst = cnst_i && cnst;
  }

  return cnst;
}

z3::expr LegacyBmc::Instr(const InstrPtr& instr, const std::string& suffix_prev,
                          const std::string& suffix_next, bool complete) {
  ILA_NOT_NULL(instr);
  ILA_DLOG("ModelGen.Instr")
      << (complete ? "Complete " : "Partial ") << "Instruction: " << instr
      << " (" << suffix_prev << ", " << suffix_next << ")";

  auto ila = instr->host();
  ILA_NOT_NULL(ila);

  auto cnst = ctx_.bool_val(true);

  auto state_num = ila->state_num();
  for (size_t i = 0; i != state_num; i++) {
    auto state_n = ila->state(i);
    auto update_n = instr->update(state_n);

    if (update_n) { // update function specified
      auto next_val_e = gen_.GetExpr(update_n, suffix_prev);
      auto next_var_e = gen_.GetExpr(state_n, suffix_next);
      auto eq_cnst = (next_var_e == next_val_e);
      cnst = cnst && eq_cnst;
    } else if (complete == true) {
      auto next_val_e = gen_.GetExpr(state_n, suffix_prev);
      auto next_var_e = gen_.GetExpr(state_n, suffix_next);
      auto eq_cnst = (next_var_e == next_val_e);
      cnst = cnst && eq_cnst;
    }
  }

  auto decode_n = instr->decode();
  ILA_NOT_NULL(decode_n);
  auto decode_e = gen_.GetExpr(decode_n, suffix_prev);
  auto instr_cnst = Z3Implies(ctx_, decode_e, cnst);
  return instr_cnst;
}

z3::expr LegacyBmc::IlaOneHotFlat(const InstrLvlAbsPtr& ila,
                                  const std::string& suffix_prev,
                                  const std::string& suffix_next) {
  ILA_NOT_NULL(ila);
  ILA_DLOG("ModelGen.IlaOneHotFlat")
      << "One-hot Flat ILA: " << ila << " (" << suffix_prev << ", "
      << suffix_next << ")";
  auto& gen = gen_;
  auto valid_n = ila->valid();
  ILA_NOT_NULL(valid_n);
  auto valid_e = gen.GetExpr(valid_n, suffix_prev);

  auto cnst = ctx_.bool_val(true);
  auto instr_num = ila->instr_num();
  for (size_t i = 0; i != instr_num; i++) {
    auto instr_i = ila->instr(i);
    auto instr_cnst = Instr(instr_i, suffix_prev, suffix_next, true);
    // Assume one-hot encoding of the instruction decode.
    cnst = cnst && instr_cnst;
  }

  auto ila_cnst = Z3Implies(ctx_, valid_e, cnst);
  return ila_cnst;
}

} // namespace ilang
