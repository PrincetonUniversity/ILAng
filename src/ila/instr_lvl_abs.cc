/// \file
/// The source for the class InstrLvlAbs.

#include "ila/instr_lvl_abs.h"

// Do the simplification by hashing AST sub-trees.
static const bool kUnifyAst = true;

namespace ila {

InstrLvlAbs::InstrLvlAbs(const std::string& name, const InstrLvlAbsPtr parent)
    : Object(name), parent_(parent) {
  ILA_WARN_IF(name == "") << "ILA name not specified...";
  InitObject();
}

InstrLvlAbs::~InstrLvlAbs() {}

InstrLvlAbsPtr InstrLvlAbs::New(const std::string& name,
                                const InstrLvlAbsPtr parent) {
  return std::make_shared<InstrLvlAbs>(name, parent);
}

const ExprPtr InstrLvlAbs::input(const std::string& name) const {
  auto pos = inputs_.find(Symbol(name));
  if (pos == inputs_.end())
    return NULL;
  else
    return pos->second;
}

const ExprPtr InstrLvlAbs::state(const std::string& name) const {
  auto pos = states_.find(Symbol(name));
  if (pos == states_.end())
    return NULL;
  else
    return pos->second;
}

const InstrPtr InstrLvlAbs::instr(const std::string& name) const {
  auto pos = instrs_.find(Symbol(name));
  if (pos == instrs_.end()) {
    return NULL;
  } else {
    return pos->second;
  }
}

const ExprPtr InstrLvlAbs::free_var(const std::string& name) const {
  auto pos = free_vars_.find(Symbol(name));
  return (pos == free_vars_.end()) ? NULL : pos->second;
}

const InstrLvlAbsPtr InstrLvlAbs::child(const std::string& name) const {
  auto pos = childs_.find(Symbol(name));
  if (pos == childs_.end()) {
    return NULL;
  } else {
    return pos->second;
  }
}

void InstrLvlAbs::AddInput(const ExprPtr input_var) {
  // sanity check
  ILA_NOT_NULL(input_var);
  ILA_ASSERT(input_var->is_var()) << "Register non-var to Inputs.";
  // should be the first
  auto name = input_var->name();
  auto posi = inputs_.find(name);
  auto poss = states_.find(name);
  ILA_ASSERT(posi == inputs_.end() && poss == states_.end())
      << "Input variable " << input_var << " has been declared.";
  // register to the simplifier
  auto var = Unify(input_var);
  // register to Inputs
  inputs_.push_back(name, var);
}

void InstrLvlAbs::AddState(const ExprPtr state_var) {
  // sanity check
  ILA_NOT_NULL(state_var);
  ILA_ASSERT(state_var->is_var()) << "Register non-var to States.";
  // should be the first
  auto name = state_var->name();
  auto poss = states_.find(name);
  auto posi = inputs_.find(name);
  ILA_ASSERT(poss == states_.end() && posi == inputs_.end())
      << "State variable " << state_var << "has been declared.";
  // register to the simplifier
  auto var = Unify(state_var);
  // register to States
  states_.push_back(name, var);
}

#if 0
void InstrLvlAbs::AddFreeVar(const ExprPtr free_var) {
  // sanity check
  ILA_NOT_NULL(free_var);
  ILA_ASSERT(free_var->is_var()) << "Register non-var to free_vars_.";
  // should be the first
  auto name = free_var->name();
  auto poss = states_.find(name);
  auto posi = inputs_.find(name);
  ILA_ASSERT(poss == states_.end() && posi == inputs_.end())
      << "Free variable " << free_var << "has been declared.";
  // register to free_vars_
  free_vars_.push_back(name, free_var);
}
#endif

void InstrLvlAbs::AddInit(const ExprPtr cntr_expr) {
  // sanity check
  ILA_NOT_NULL(cntr_expr);
  ILA_ASSERT(cntr_expr->is_bool()) << "Initial condition must be Boolean.";
  // simplify
  auto cntr = Unify(cntr_expr);
  // register to Initial conditions
  inits_.push_back(cntr);
}

void InstrLvlAbs::SetFetch(const ExprPtr fetch_expr) {
  // sanity check
  ILA_NOT_NULL(fetch_expr);
  ILA_ASSERT(fetch_expr->is_bv()) << "Fetch function must be bit-vector.";
  // should be the first
  ILA_ASSERT(!fetch_) << "Fetch function has been assigned.";
  // simplify
  auto fetch = Unify(fetch_expr);
  // set as fetch function
  fetch_ = fetch;
}

void InstrLvlAbs::SetValid(const ExprPtr valid_expr) {
  // sanity check
  ILA_NOT_NULL(valid_expr);
  ILA_ASSERT(valid_expr->is_bool()) << "Valid function must be Boolean.";
  // should be the first
  ILA_ASSERT(!valid_) << "Valid function has been assigned.";
  // simplify
  auto valid = Unify(valid_expr);
  // set as valid function
  valid_ = valid;
}

void InstrLvlAbs::AddInstr(const InstrPtr instr) {
  ILA_NOT_NULL(instr);
  // register the instruction and idx
  auto name = instr->name();
  instrs_.push_back(name, instr);
}

void InstrLvlAbs::AddChild(const InstrLvlAbsPtr child) {
  ILA_NOT_NULL(child);
  /// register the child-ILA and idx
  auto name = child->name();
  childs_.push_back(name, child);
}

const ExprPtr InstrLvlAbs::NewBoolInput(const std::string& name) {
  ExprPtr bool_input = ExprFuse::NewBoolVar(name);
  // set host
  bool_input->set_host(shared_from_this());
  // register
  AddInput(bool_input);
  return bool_input;
}

const ExprPtr InstrLvlAbs::NewBvInput(const std::string& name,
                                      const int& bit_width) {
  ExprPtr bv_input = ExprFuse::NewBvVar(name, bit_width);
  // set host
  bv_input->set_host(shared_from_this());
  // register
  AddInput(bv_input);
  return bv_input;
}

const ExprPtr InstrLvlAbs::NewBoolState(const std::string& name) {
  ExprPtr bool_state = ExprFuse::NewBoolVar(name);
  // set host
  bool_state->set_host(shared_from_this());
  // register
  AddState(bool_state);
  return bool_state;
}

const ExprPtr InstrLvlAbs::NewBvState(const std::string& name,
                                      const int& bit_width) {
  ExprPtr bv_state = ExprFuse::NewBvVar(name, bit_width);
  // set host
  bv_state->set_host(shared_from_this());
  // register
  AddState(bv_state);
  return bv_state;
}

const ExprPtr InstrLvlAbs::NewMemState(const std::string& name,
                                       const int& addr_width,
                                       const int& data_width) {
  ExprPtr mem_state = ExprFuse::NewMemVar(name, addr_width, data_width);
  // set host
  mem_state->set_host(shared_from_this());
  // register
  AddState(mem_state);
  return mem_state;
}

const ExprPtr InstrLvlAbs::NewBoolFreeVar(const std::string& name) {
  // create new var
  ExprPtr bool_var = ExprFuse::NewBoolVar(name);
  // set host
  bool_var->set_host(shared_from_this());
  return bool_var;
}

const ExprPtr InstrLvlAbs::NewBvFreeVar(const std::string& name,
                                        const int& bit_width) {
  // create new var
  ExprPtr bv_var = ExprFuse::NewBvVar(name, bit_width);
  // set host
  bv_var->set_host(shared_from_this());
  return bv_var;
}

const ExprPtr InstrLvlAbs::NewMemFreeVar(const std::string& name,
                                         const int& addr_width,
                                         const int& data_width) {
  // create new var
  ExprPtr mem_var = ExprFuse::NewMemVar(name, addr_width, data_width);
  // set host
  mem_var->set_host(shared_from_this());
  return mem_var;
}

const InstrPtr InstrLvlAbs::NewInstr(const std::string& name) {
  auto tmp_name = (name == "") ? "I." + std::to_string(instr_num()) : name;
  InstrPtr instr = Instr::New(tmp_name, shared_from_this());
  // register
  AddInstr(instr);
  return instr;
}

const InstrLvlAbsPtr InstrLvlAbs::NewChild(const std::string& name) {
  InstrLvlAbsPtr child = New(name, shared_from_this());
  // inherit states
  for (size_t i = 0; i != states_.size(); i++) {
    child->AddState(states_[i]);
  }
  // inherit inputs
  for (size_t i = 0; i != inputs_.size(); i++) {
    child->AddInput(inputs_[i]);
  }
  // register
  AddChild(child);
  return child;
}

bool InstrLvlAbs::Check() const {
  // TODO
  // check input
  // check state
  // check init
  // check fetch
  // check valid
  // check instr
  // check child-ILA?
  // check sequencing
  // HZ comment: should we also check the host() of Exprs matches the ILAs?
  return true;
}

void InstrLvlAbs::MergeChild() {
  // TODO
  // merge shared states
  // merge simplifier
}

void InstrLvlAbs::SortInstr() {
  // TODO
  // check this is a micro-ILA and has sequencing
  // sort instructions based on the sequencing
}

void InstrLvlAbs::AddSeqTran(const InstrPtr src, const InstrPtr dst,
                             const ExprPtr cnd) {
  // XXX src, dst should already registered.
  auto cnd_simplified = Unify(cnd);
  instr_seq_.AddTran(src, dst, cnd_simplified);
}

std::ostream& InstrLvlAbs::Print(std::ostream& out) const {
  out << "ILA." << name();
  return out;
}

std::ostream& operator<<(std::ostream& out, InstrLvlAbs& ila) {
  return ila.Print(out);
}

std::ostream& operator<<(std::ostream& out, InstrLvlAbsPtr ila) {
  return ila->Print(out);
}

ExprPtr InstrLvlAbs::Unify(const ExprPtr e) {
  return kUnifyAst ? expr_mngr_->GetRep(e) : e;
}

void InstrLvlAbs::InitObject() {
  // local
  inputs_.clear();
  states_.clear();
  inits_.clear();
  instrs_.clear();
  childs_.clear();
  instr_seq_.clear();
  // shared
  if (parent_) {
    expr_mngr_ = parent_->expr_mngr();
  } else {
    expr_mngr_ = kUnifyAst ? ExprMngr::New() : NULL;
  }
}

} // namespace ila

