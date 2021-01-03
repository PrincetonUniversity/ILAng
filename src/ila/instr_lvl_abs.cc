/// \file
/// The source for the class InstrLvlAbs.

#include <ilang/ila/instr_lvl_abs.h>

#include <ilang/util/log.h>

// Do the simplification by hashing AST sub-trees.
static const bool kUnifyAst = false;
// please design a better hash function  -- HZ
// ISSUE: hash collision on large designs like AES128 function
// updated to a new hash function, there's now an optional pass
// (SimplifySyntactic) for users to apply -- BYH

namespace ilang {

InstrLvlAbs::InstrLvlAbs(const std::string& name, const InstrLvlAbsPtr& parent)
    : Object(name), parent_(parent) {
  ILA_WARN_IF(name == "") << "ILA name not specified...";
  InitObject();
}

InstrLvlAbs::~InstrLvlAbs() {}

InstrLvlAbsPtr InstrLvlAbs::New(const std::string& name,
                                const InstrLvlAbsPtr& parent) {
  return std::make_shared<InstrLvlAbs>(name, parent);
}

const ExprPtr InstrLvlAbs::input(const std::string& name) const {
  auto inp = find_input(Symbol(name));
  return inp;
}

const ExprPtr InstrLvlAbs::state(const std::string& name) const {
  auto stt = find_state(Symbol(name));
  return stt;
}

const InstrPtr InstrLvlAbs::instr(const std::string& name) const {
  auto instr = find_instr(Symbol(name));
  return instr;
}

const InstrLvlAbsPtr InstrLvlAbs::child(const std::string& name) const {
  auto child = find_child(Symbol(name));
  return child;
}

const ExprPtr InstrLvlAbs::find_input(const Symbol& name) const {
  auto pos = inputs_.find(name);
  return (pos == inputs_.end()) ? nullptr : pos->second;
}

const ExprPtr InstrLvlAbs::find_state(const Symbol& name) const {
  auto pos = states_.find(name);
  return (pos == states_.end()) ? nullptr : pos->second;
}

const InstrPtr InstrLvlAbs::find_instr(const Symbol& name) const {
  auto pos = instrs_.find(name);
  return (pos == instrs_.end()) ? nullptr : pos->second;
}

const InstrLvlAbsPtr InstrLvlAbs::find_child(const Symbol& name) const {
  auto pos = childs_.find(name);
  return (pos == childs_.end()) ? nullptr : pos->second;
}

void InstrLvlAbs::AddInput(const ExprPtr& input_var) {
  // sanity check
  ILA_NOT_NULL(input_var);
  ILA_ASSERT(input_var->is_var()) << "Register non-var to Inputs.";

  auto name = input_var->name();
  ILA_ASSERT(inputs_.find(name) == inputs_.end()) << name;
  ILA_ASSERT(states_.find(name) == states_.end()) << name;

  // register to the simplifier
  auto var = Unify(input_var);
  // register to Inputs
  inputs_.push_back(name, var);
}

void InstrLvlAbs::AddState(const ExprPtr& state_var) {
  // sanity check
  ILA_NOT_NULL(state_var);
  ILA_ASSERT(state_var->is_var()) << "Register non-var to States.";

  auto name = state_var->name();
  ILA_ASSERT(inputs_.find(name) == inputs_.end());
  ILA_ASSERT(states_.find(name) == states_.end());

  // register to the simplifier
  auto var = Unify(state_var);
  // register to States
  states_.push_back(name, var);
}

void InstrLvlAbs::AddInit(const ExprPtr& cntr_expr) {
  // sanity check
  ILA_NOT_NULL(cntr_expr);
  ILA_ASSERT(cntr_expr->is_bool()) << "Initial condition must be Boolean.";
  // simplify
  auto cntr = Unify(cntr_expr);
  // register to Initial conditions
  inits_.push_back(cntr);
}

void InstrLvlAbs::SetFetch(const ExprPtr& fetch_expr) {
  ILA_ASSERT(!fetch_) << "Fetch alraedy defined";
  ForceSetFetch(fetch_expr);
}

void InstrLvlAbs::SetValid(const ExprPtr& valid_expr) {
  ILA_ASSERT(!valid_) << "Valid already defined";
  ForceSetValid(valid_expr);
}

void InstrLvlAbs::AddInstr(const InstrPtr& instr) {
  ILA_NOT_NULL(instr);
  // register the instruction and idx
  auto name = instr->name();
  instrs_.push_back(name, instr);
}

void InstrLvlAbs::AddChild(const InstrLvlAbsPtr& child) {
  ILA_NOT_NULL(child);
  /// register the child-ILA and idx
  auto name = child->name();
  childs_.push_back(name, child);
}

const ExprPtr InstrLvlAbs::NewBoolInput(const std::string& name) {
  ExprPtr bool_input = asthub::NewBoolVar(name);
  // set host
  bool_input->set_host(shared_from_this());
  // register
  AddInput(bool_input);
  return bool_input;
}

const ExprPtr InstrLvlAbs::NewBvInput(const std::string& name,
                                      const int& bit_width) {
  ExprPtr bv_input = asthub::NewBvVar(name, bit_width);
  // set host
  bv_input->set_host(shared_from_this());
  // register
  AddInput(bv_input);
  return bv_input;
}

const ExprPtr InstrLvlAbs::NewMemInput(const std::string& name,
                                       const int& addr_width,
                                       const int& data_width) {
  ExprPtr mem_input = asthub::NewMemVar(name, addr_width, data_width);
  // set host
  mem_input->set_host(shared_from_this());
  // register
  AddInput(mem_input);
  return mem_input;
}

const ExprPtr InstrLvlAbs::NewBoolState(const std::string& name) {
  ExprPtr bool_state = asthub::NewBoolVar(name);
  // set host
  bool_state->set_host(shared_from_this());
  // register
  AddState(bool_state);
  return bool_state;
}

const ExprPtr InstrLvlAbs::NewBvState(const std::string& name,
                                      const int& bit_width) {
  ExprPtr bv_state = asthub::NewBvVar(name, bit_width);
  // set host
  bv_state->set_host(shared_from_this());
  // register
  AddState(bv_state);
  return bv_state;
}

const ExprPtr InstrLvlAbs::NewMemState(const std::string& name,
                                       const int& addr_width,
                                       const int& data_width) {
  ExprPtr mem_state = asthub::NewMemVar(name, addr_width, data_width);
  // set host
  mem_state->set_host(shared_from_this());
  // register
  AddState(mem_state);
  return mem_state;
}

const ExprPtr InstrLvlAbs::NewBoolFreeVar(const std::string& name) {
  // create new var
  ExprPtr bool_var = asthub::NewBoolVar(name);
  // set host
  bool_var->set_host(shared_from_this());
  return bool_var;
}

const ExprPtr InstrLvlAbs::NewBvFreeVar(const std::string& name,
                                        const int& bit_width) {
  // create new var
  ExprPtr bv_var = asthub::NewBvVar(name, bit_width);
  // set host
  bv_var->set_host(shared_from_this());
  return bv_var;
}

const ExprPtr InstrLvlAbs::NewMemFreeVar(const std::string& name,
                                         const int& addr_width,
                                         const int& data_width) {
  // create new var
  ExprPtr mem_var = asthub::NewMemVar(name, addr_width, data_width);
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

void InstrLvlAbs::ForceSetFetch(const ExprPtr& fetch_expr) {
  // sanity check
  ILA_NOT_NULL(fetch_expr);
  ILA_ASSERT(fetch_expr->is_bv()) << "Fetch function must be bit-vector.";
  // simplify
  auto fetch = Unify(fetch_expr);
  // set as fetch function
  fetch_ = fetch;
}

void InstrLvlAbs::ForceSetValid(const ExprPtr& valid_expr) {
  // sanity check
  ILA_NOT_NULL(valid_expr);
  ILA_ASSERT(valid_expr->is_bool()) << "Valid function must be Boolean.";
  // simplify
  auto valid = Unify(valid_expr);
  // set as valid function
  valid_ = valid;
}

void InstrLvlAbs::AddSeqTran(const InstrPtr& src, const InstrPtr& dst,
                             const ExprPtr& cnd) {
  // XXX src, dst should already registered.
  auto cnd_simplified = Unify(cnd);
  if (!instr_seq_) {
    instr_seq_ = InstrSeq::New();
  }
  instr_seq_->AddTran(src, dst, cnd_simplified);
}

std::string InstrLvlAbs::GetRootName() const {
  if (parent()) {
    return parent()->GetRootName() + "." + name().str();
  } else {
    return name().str();
  }
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

std::ostream& operator<<(std::ostream& out, InstrLvlAbsCnstPtr ila) {
  return ila->Print(out);
}

ExprPtr InstrLvlAbs::Unify(const ExprPtr& e) {
  return kUnifyAst ? expr_mngr_->GetRep(e) : e;
}

void InstrLvlAbs::InitObject() {
  // local
  inputs_.clear();
  states_.clear();
  inits_.clear();
  instrs_.clear();
  childs_.clear();
  // shared
  if (parent_) {
    expr_mngr_ = parent_->expr_mngr();
  } else {
    expr_mngr_ = kUnifyAst ? ExprMngr::New() : nullptr;
  }
}

} // namespace ilang
