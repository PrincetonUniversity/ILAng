/// \file
/// The source for the class InstrLvlAbs.

#include "ila/instr_lvl_abs.h"

namespace ila {

InstrLvlAbs::InstrLvlAbs(const std::string& name) : Object(name) {
  ILA_WARN_IF(name == "") << "ILA name not specified...\n";
  InitObject();
}

InstrLvlAbs::~InstrLvlAbs() {}

InstrLvlAbsPtr InstrLvlAbs::NewILA(const std::string& name) {
  return std::make_shared<InstrLvlAbs>(name);
}

bool InstrLvlAbs::is_spec() const { return is_spec_; }

void InstrLvlAbs::set_simplify(bool simplify) { simplify_ = simplify; }

void InstrLvlAbs::set_spec(bool spec) { is_spec_ = spec; }

void InstrLvlAbs::AddInput(const ExprPtr& input_var) {
  // should only register terminating variable
  ILA_ASSERT(input_var->is_var()) << "Register non-var to Inputs\n";
  // should be the first
  auto name = input_var->name();
  auto pos = inputs_.find(name);
  ILA_ASSERT(pos == inputs_.end()) << "Input variable " << input_var
                                   << " has been declared.\n";
  // register to the simplifier
  auto var = expr_mngr_->Simplify(input_var, simplify_);
  // register to Inputs
  inputs_[name] = var;
}

void InstrLvlAbs::AddState(const ExprPtr& state_var) {
  // should only register terminating variable
  auto name = state_var->name();
  // should be the first
  auto pos = states_.find(name);
  ILA_ASSERT(pos == states_.end()) << "State variable " << state_var
                                   << "has been declared.\n";
  // register to the simplifier
  auto var = expr_mngr_->Simplify(state_var, simplify_);
  // register to States
  states_[name] = var;
}

void InstrLvlAbs::AddInit(const ExprPtr& cntr_expr) {
  ILA_NOT_NULL(cntr_expr); // NULL pointer
  ILA_ASSERT(cntr_expr->is_bv()) << "Initial condition should be Boolean\n";
  // register to Initial conditions
  inits_.push_back(cntr_expr);
}

void InstrLvlAbs::InitObject() {
  inputs_.clear();
  states_.clear();
  inits_.clear();
  fetch_ = NULL;
  valid_ = NULL;
  instrs_.clear();
  instr_idxs_.clear();
  child_.clear();

  is_spec_ = true;
  simplify_ = true;

  expr_mngr_ = std::make_shared<ExprMngr>();
  expr_mngr_->Reset();
}

} // namespace ila

