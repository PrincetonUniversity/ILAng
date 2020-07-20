/// \file
/// Source for multi-ILA unroller

#include <ilang/mcm/inter_ila_unroller.h>

#include <map>
#include <vector>

#include <ilang/mcm/set_op.h>
#include <ilang/util/log.h>

namespace ilang {

/******************************************************************************/
// InterIlaUnroller
/******************************************************************************/

InterIlaUnroller::InterIlaUnroller(z3::context& ctx, const IlaPtrVec& iv,
                                   MemoryModelCreator mm_selector)
    : ctx_(ctx), sys_ila_(iv),
      global_ila_(InstrLvlAbs::New("__GLOBAL_INIT__")) {

  FindSharedStates();
  createDummyGlobalIla();
  mm_ = mm_selector(ctx_, cstr_, shared_states_, private_states_, global_ila_);
}

InterIlaUnroller::~InterIlaUnroller() {}

void InterIlaUnroller::createDummyGlobalIla() {
  // add one instruction to update all to itself
  size_t state_num = global_ila_->state_num();
  InstrPtr init_instr_ptr = global_ila_->NewInstr("__INIT__");

  init_instr_ptr->set_decode(std::make_shared<ExprConst>(BoolVal(true)));

  for (size_t idx = 0; idx != state_num; ++idx) {
    auto state = global_ila_->state(idx);

    init_instr_ptr->set_update(state, state); // update itself to itself
    // This may seem strange, but remember:
    // the z3 expr generated on that step is already constrained by
    // GenSysInitConstraints so when it is referred, the initial value
    // constraints will apply
  }
  // mm->SetGlobalILA(global_ila_);
}

void InterIlaUnroller::FindSharedStates() {
  SharedStatesSet temp_shared_states_;
  for (auto&& ila_ptr_ : sys_ila_) {
    ILA_NOT_NULL(ila_ptr_);
    // currently not directly handle hierarchy, you need to flatten the
    // ILA first
    ILA_ASSERT(ila_ptr_->child_num() == 0)
        << " Implementation bug: "
        << "currently inter_ila_unroller does not handle hierarchy, please "
           "flatten ILA: "
        << ila_ptr_->name() << " first.";
    for (size_t i = 0; i != ila_ptr_->state_num(); i++) {
      auto state_var_ = ila_ptr_->state(i);
      // check type
      if (!temp_shared_states_[state_var_->name().str()]
               .empty()) { // will use the override operator ==
        ILA_ASSERT(
            (temp_shared_states_[state_var_->name().str()].front()->sort()) ==
            (state_var_->sort()))
            << "Implementation bug: Assuming states having the same name have "
               "the same sort!";
      }
      // BUG FIX: add state here: always push
      temp_shared_states_[state_var_->name().str()].push_back(state_var_);
      // insert to the list of state var of the same name
      // will automatically create an empty list if not previously exists
      // Here I use .str(), because I'm afraid that Symbol("A") != Symbol("A")
    }
  }
  // sanitize pass
  // create dummy states
  for (auto&& name_vlist_pair : temp_shared_states_) {
    auto name = name_vlist_pair.first;
    auto vars = name_vlist_pair.second;
    if (vars.size() > 1) { // if it has been de
      shared_states_.insert(name);
      auto vsort = vars.front()->sort();

      if (vsort->is_bool()) {
        global_ila_->NewBoolState(name);
      } else if (vsort->is_bv()) {
        global_ila_->NewBvState(name, vsort->bit_width());
      } else if (vsort->is_mem()) {
        global_ila_->NewMemState(name, vsort->addr_width(),
                                 vsort->data_width());
      } else
        ILA_ASSERT(false) << "Implementation bug: Unknown sort for var:"
                          << name;
      // else we don't know what type it is and cannot create a dummy state of
      // it
    }
  }
  // create private states
  for (auto&& ila_ptr_ : sys_ila_) {
    auto ila_name = ila_ptr_->name().str();
    // please don't remove the following dlog info
    private_states_.insert({ila_name, StateNameSet()});
    for (size_t i = 0; i != ila_ptr_->state_num(); i++) {
      auto state_var_ = ila_ptr_->state(i);
      auto state_name_ = state_var_->name().str();
      if (!IN(state_name_, shared_states_))
        private_states_[ila_name].insert(state_name_);
    }
  }
}

void InterIlaUnroller::Unroll(const ProgramTemplate& tmpl) {
  // store to constraints
  // time stamps
  // ordered or not
  // find the shared variables and apply pi-functions
  // need to know when to create more steps: go through the tmpl
  size_t ila_num = sys_ila_.size();
  ILA_ASSERT(ila_num == tmpl.size());
  mm_->InitSize(tmpl);
  for (size_t idx = 0; idx != ila_num; ++idx) {
    mm_->RegisterSteps(idx, tmpl[idx]); // register those instructions,
  }
  mm_->FinishRegisterSteps();
}

void InterIlaUnroller::LinkStates(const std::vector<bool>& ordered) {
  size_t ila_num = sys_ila_.size();
  ILA_ASSERT(ila_num == ordered.size());
  mm_->ApplyAxioms();          // link shared states
  mm_->SetLocalState(ordered); // link private states
}

void InterIlaUnroller::AddSingleTraceStepProperty(
    const ExprPtr& property, std::function<bool(const TraceStep&)> filter) {
  mm_->AddSingleTraceStepProperty(property, filter);
} // we need to make sure to add state to the read list

void InterIlaUnroller::GetSingleTraceStepProperty(
    const ExprPtr& property, std::function<bool(const TraceStep&)> filter,
    std::function<void(const z3::expr&)> collector) {
  mm_->GetSingleTraceStepProperty(property, filter, collector);
}

void InterIlaUnroller::SetFinalProperty(const ExprPtr& property) {
  mm_->SetFinalProperty(property);
}

void InterIlaUnroller::GenSysInitConstraints() {
  // we need to get the constraints of init conditions and replace
  // global the variables there with the unified shared names
  // An alternative (currently used) may be directly giving the unroller the
  // exprs with host removed (if they are shared variables). capture by copy
  // should be fine, we are just copying it once
  auto isSharedVar = [this](const ExprPtr& exp) -> bool {
    return (this->shared_states_).find(exp->name().str()) !=
           (this->shared_states_).end();
  };
  // replace if found (is shared state)

  HostRemoveRestore host_remover;

  size_t ila_num = sys_ila_.size();
  ZExprVec init_cond_vec;

  for (size_t idx = 0; idx != ila_num; ++idx) {
    auto& ila_ptr = sys_ila_[idx];
    // auto &unroller_ptr = unrollers_[idx];
    InstrVec InitInstVec; // Only one instruction init
    InitInstVec.push_back(Instr::New("__INIT__", ila_ptr));
    InitInstVec[0]->set_decode(asthub::BoolConst(true));

    size_t init_num = ila_ptr->init_num();
    for (size_t init_cond_idx = 0; init_cond_idx != init_num; ++init_cond_idx) {
      ExprPtr init_cond = ila_ptr->init(init_cond_idx);
      host_remover.RecordAndReplaceIf(init_cond, isSharedVar, global_ila_);
      // We need to create a global ila, and set all to that to make a predicate
      init_cond_vec.push_back(mm_->ConvertZ3(init_cond, std::to_string(0)));
      // unroller_ptr->AddInitPred( init_cond );
    }

    // add the init condition
    // ZExpr constr = unroller_ptr->PathNone( InitInstVec , 0 ); // this will
    // only give us the initial condition
    cstr_.push_back(ConjPred(init_cond_vec));
  }
  host_remover.RestoreAll(global_ila_); // this will not affect the generated z3
  // you need to give a pointer to that to restore the host?
  // A sanity check can be put here to check if the initial conditions of
  // several components are compatible or not
  ILA_WARN_IF(!CurrConstrSat())
      << "The initial conditions of ILAs are incompatible (unsat)";
}

bool InterIlaUnroller::CurrConstrSat() {
  // This is to check if the current constraints are satisfiable.
  z3::solver solver(ctx());

  auto cnst = ConjPred(cstr_);
  solver.add(cnst);
  auto result = solver.check();

  if (result == z3::sat) {
    auto m = solver.get_model();
    // ILA_DLOG("InterIlaUnroller.CurrConstrSat") << m;
    return true;
  }
  return false;
}

bool InterIlaUnroller::CheckSat() {
  z3::solver solver(ctx());

  // auto cnst = ConjPred( cstr_ );
  unsigned idx = 0;
  for (const auto& c : cstr_) {
    solver.add(c, ("p" + std::to_string(++idx)).c_str());
  }
  auto result = solver.check();

  if (result == z3::sat) {
    model_ptr_.reset(new z3::model(solver.get_model()));
    // ILA_DLOG("InterIlaUnroller.CurrConstrSat") << m;
    return true;
  }
  // unsat/unknow
  ILA_DLOG("InterIlaUnroller.CheckSat") << "Unsat core:" << solver.unsat_core();
  model_ptr_.reset(); // delete old value
  return false;
}

z3::model& InterIlaUnroller::GetModel() {
  ILA_NOT_NULL(model_ptr_); // you cannot get model from an unsat check
  return *(
      model_ptr_.get()); // dangerous, will only usable before it is destroyed
}

const InterIlaUnroller::ZExprVec&
InterIlaUnroller::DebugAccessConstrList() const {
  return cstr_;
}
const InterIlaUnroller::TraceStepPtrSet&
InterIlaUnroller::DebugAccessAllTraceStepPtrSet() const {
  return mm_->GetAllTraceSteps();
}

void InterIlaUnroller::Push() { zexpr_vec_pos_stack_.push(cstr_.size()); }
void InterIlaUnroller::Pop() {
  ILA_ASSERT(!zexpr_vec_pos_stack_.empty())
      << "Unable to pop, inbalanced push/pop";
  size_t prev_size_ = zexpr_vec_pos_stack_.top();
  zexpr_vec_pos_stack_.pop();
  ILA_ASSERT(cstr_.size() >= prev_size_)
      << "Implementation bug, the constraint list should not be shrinked other "
         "than pop";
  cstr_.erase(cstr_.begin() + prev_size_, cstr_.end());
  // cstr_.resize( prev_size_ ); cannot create zexpr without initial value
}

InterIlaUnroller::ZExpr InterIlaUnroller::ConjPred(const ZExprVec& vec) const {
  auto conj = ctx().bool_val(true);
  for (size_t i = 0; i != vec.size(); i++) {
    conj = (conj && vec[i]);
  }
  conj = conj.simplify();
  return conj;
}

/******************************************************************************/
// Helper Class: HostRemoveRestore
/******************************************************************************/

// HZ Comment: There are more issues I need to sort out
// e.g., the functions (0-ary or o.w.) depends on host
// ExprOp seems not (except applying the 0-ary func)
// Should they be removed also?
// Also, more to think about for hierarchical ila

void HostRemoveRestore::RecordAndRemove(ExprPtr expr) {
  size_t num = expr->arg_num();
  for (size_t i = 0; i != num; ++i)
    RecordAndRemove(expr->arg(i));
  if (expr->is_var()) { // currently we only deal with expr vars, maybe also
                        // func?
    auto pos = map_.find(expr);
    if (pos != map_.end()) { // if exp is already registered
      ILA_ASSERT(pos->second == expr->host())
          << "Implementation bug: host() of expr:" << expr
          << " is already filled and they do not match.";
      // and then, no need to save, just remove
    } else
      map_.insert(std::make_pair(expr, expr->host()));
    expr->set_host(NULL);
  }
}
void HostRemoveRestore::RecordAndRemoveIf(ExprPtr expr, ExprJudgeFunc f) {
  ILA_ASSERT(f != nullptr) << "ExprJudgeFunc cannot be a null pointer";

  size_t num = expr->arg_num();
  for (size_t i = 0; i != num; ++i)
    RecordAndRemoveIf(expr->arg(i), f);
  if (expr->is_var() &&
      f(expr)) { // currently we only deal with expr vars, maybe also func?
    auto pos = map_.find(expr);
    if (pos != map_.end()) { // if exp is already registered
      ILA_ASSERT(pos->second == expr->host())
          << "Implementation bug: host() of expr:" << expr
          << " is already filled and they do not match.";
      // and then, no need to save, just remove
    } else
      map_.insert(std::make_pair(expr, expr->host()));
    expr->set_host(NULL);
  }
}

void HostRemoveRestore::RecordAndReplaceIf(ExprPtr expr, ExprJudgeFunc f,
                                           InstrLvlAbsPtr h) {
  ILA_ASSERT(f != nullptr) << "ExprJudgeFunc cannot be a null pointer";

  size_t num = expr->arg_num();
  for (size_t i = 0; i != num; ++i)
    RecordAndReplaceIf(expr->arg(i), f, h);
  if (expr->is_var() &&
      f(expr)) { // currently we only deal with expr vars, maybe also func?
    auto pos = map_.find(expr);
    if (pos != map_.end()) { // if exp is already registered
      ILA_ASSERT(pos->second == expr->host())
          << "Implementation bug: host() of expr:" << expr
          << " is already filled and they do not match.";
      // and then, no need to save, just remove
    } else
      map_.insert(std::make_pair(expr, expr->host()));
    expr->set_host(h);
  }
}

void HostRemoveRestore::Restore(ExprPtr expr) {
  size_t num = expr->arg_num();
  for (size_t i = 0; i != num; ++i)
    Restore(expr->arg(i));
  if (expr->is_var() &&
      expr->host() == NULL) { // currenlty we only limit ourselves to expr vars
    auto pos = map_.find(expr);
    if (pos != map_.end())
      expr->set_host(pos->second);
  }
}
void HostRemoveRestore::RestoreAll(InstrLvlAbsPtr h) {
  for (auto& expr_host_pair : map_) {
    ILA_ASSERT(expr_host_pair.first->host() == h)
        << "Unable to restore to expr:" << expr_host_pair.first
        << " , host field is already set to other host.";
    expr_host_pair.first->set_host(expr_host_pair.second);
  }
}

} // namespace ilang
