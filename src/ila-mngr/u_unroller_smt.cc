/// \file
/// The implementation of UnrollerSmt, PathUnroller, and MonoUnroller.

#include <ilang/ila-mngr/u_unroller_smt.h>

#include <ilang/ila-mngr/u_abs_knob.h>
#include <ilang/target-smt/smt_switch_itf.h>
#include <ilang/target-smt/z3_expr_adapter.h>

namespace ilang {

//
// UnrollerSmt
//

template <class Generator>
typename UnrollerSmt<Generator>::SmtExpr
UnrollerSmt<Generator>::Unroll_(const size_t& len, const size_t& begin) {
  // reset to clean starting state
  deciding_vars_.clear();
  update_holder_.clear();
  assert_holder_.clear();

  // setup deciding variable (and the order)
  SetDecidingVars();
  ILA_ASSERT(!deciding_vars_.empty());

  // placeholder for generated SMT terms
  SmtExprVec smt_holder;

  // unroll each step
  for (size_t i = 0; i < len; i++) {
    auto suffix = SuffixCurrent(begin + i);
    auto suffix_next = SuffixCurrent(begin + i + 1);

    // proceed and update placeholders
    MakeOneTransition(i);

    // append global and step-specific properties
    InterpIlaExprAndAppend(global_pred_, suffix, smt_holder);
    InterpIlaExprAndAppend(step_pred_[i], suffix, smt_holder);
    InterpIlaExprAndAppend(assert_holder_, suffix, smt_holder);
    // append initial properties
    if (i == 0) {
      InterpIlaExprAndAppend(initial_pred_, suffix, smt_holder);
    }

    // append transition (state updates)
    SmtExprVec smt_next_val;
    SmtExprVec smt_next_var;
    InterpIlaExprAndAppend(update_holder_, suffix, smt_next_val);
    InterpIlaExprAndAppend(deciding_vars_, suffix_next, smt_next_var);
    ElementWiseEqualAndAppend(smt_next_val, smt_next_var, smt_holder);
  }

  { // take care of the end state
    auto suffix = SuffixCurrent(len);
    InterpIlaExprAndAppend(global_pred_, suffix, smt_holder);
    InterpIlaExprAndAppend(step_pred_[len], suffix, smt_holder);
  }

  return ConjunctAll(smt_holder);
}

template <class Generator>
typename UnrollerSmt<Generator>::SmtExpr
UnrollerSmt<Generator>::UnrollWithStepsUnconnected_(const size_t& len,
                                                    const size_t& begin) {
  // TODO
  ILA_CHECK(false) << "Not implemented";
  return smt_gen_.GetShimExpr(nullptr, "");
}

// Concretize SMT generators
template class UnrollerSmt<Z3ExprAdapter>;
#ifdef SMTSWITCH_INTERFACE
template class UnrollerSmt<SmtSwitchItf>;
#endif // SMTSWITCH_INTERFACE

//
// PathUnroller
//

template <class Generator> void PathUnroller<Generator>::SetDecidingVars() {
  ExprSet unique_vars;
  for (const auto& instr : seq_) {
    absknob::InsertStt(instr, unique_vars);
  }
  // move to global order
  this->deciding_vars_.clear();
  for (const auto& s : unique_vars) {
    this->deciding_vars_.push_back(s);
  }
}

template <class Generator>
void PathUnroller<Generator>::MakeOneTransition(const size_t& idx) {
  ILA_ASSERT(idx < seq_.size());
  auto instr = seq_.at(idx);

  // update next state function
  auto CompleteStateUpdate = [](const InstrPtr& instr, const ExprPtr& s) {
    auto update = instr->update(s);
    return (update) ? update : s;
  };

  this->update_holder_.clear();
  for (const auto& s : this->deciding_vars_) {
    this->update_holder_.push_back(CompleteStateUpdate(instr, s));
  }

  // step specific property
  this->assert_holder_.clear();
  auto decode = instr->decode();
  ILA_NOT_NULL(decode);
  this->assert_holder_.push_back(decode);
}

// Concretize SMT generators
template class PathUnroller<Z3ExprAdapter>;
#ifdef SMTSWITCH_INTERFACE
template class PathUnroller<SmtSwitchItf>;
#endif // SMTSWITCH_INTERFACE

} // namespace ilang
