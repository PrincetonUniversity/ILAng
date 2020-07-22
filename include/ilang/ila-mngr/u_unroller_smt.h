/// \file
/// Class UnrollerSmt, PathUnroller, and MonoUnroller - a collection of
/// ILA unrollers with SmtShim support.

#ifndef ILANG_ILA_MNGR_U_UNROLLER_SMT_H__
#define ILANG_ILA_MNRG_U_UNROLLER_SMT_H__

#include <map>
#include <string>
#include <vector>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/target-smt/smt_shim.h>
#include <ilang/util/log.h>

/// \namespace ilang
namespace ilang {

/// \brief Base class for unrolling ILA execution in different settings.
template <class Generator> class UnrollerSmt {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor.
  UnrollerSmt(SmtShim<Generator>& smt_shim, const std::string& suffix)
      : smt_gen_(smt_shim), unroller_suffix_(suffix) {}

  // ------------------------- METHODS -------------------------------------- //
  //
  // Control property/predicate beyond the transition.
  //
  /// Add the predicate p to be asserted globally.
  inline void AssertGlobal(const ExprPtr& p) { global_pred_.insert(p); }
  /// Add the predicate p to be asserted at the first step (initial condition).
  inline void AssertInitial(const ExprPtr& p) { initial_pred_.insert(p); }
  /// Add the predicate p to be asserted at the k-th step.
  inline void AssertStep(const ExprPtr& p, const int& k) {
    step_pred_[k].insert(p);
  }
  /// Clear all the global assertions.
  inline void ClearGlobalAssertion() { global_pred_.clear(); }
  /// Clear all the initial assertions.
  inline void ClearInitialAssertion() { initial_pred_.clear(); }
  /// Clear all the step-specific assertions.
  inline void ClearStepAssertion() { step_pred_.clear(); }

  //
  // Access SMT formula in the unrolled execution.
  //
  /// Return the SMT formula of expr at the beginning k-th step.
  inline auto GetSmtCurrent(const ExprPtr& expr, const size_t& k) const {
    return smt_gen_.GetShimExpr(expr, SuffixCurrent(k));
  }
  /// Return the SMT formula of expr at the end of k-th step.
  inline auto GetSmtNext(const ExprPtr& expr, const size_t& k) const {
    return smt_gen_.GetShimExpr(expr, SuffixNext(k));
  }
  /// Return the SMT function declaration of uninterpreted function func.
  inline auto GetSmtFuncDecl(const FuncPtr& func) const {
    return smt_gen_.GetShimFunc(func);
  }

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The underlying (templated) SMT generator.
  SmtShim<Generator>& smt_gen_;
  /// Unroller specific suffix.
  const std::string unroller_suffix_;

  /// Predicates to be asserted globally.
  ExprSet global_pred_;
  /// Predicates to be asserted initially.
  ExprSet initial_pred_;
  /// Predicates to be asserted at each step.
  std::map<size_t, ExprSet> step_pred_;

  // ------------------------- HELPERS -------------------------------------- //
  /// Return suffix for current state.
  inline std::string SuffixCurrent(const size_t& t) const {
    return std::to_string(t) + "_" + unroller_suffix_;
  }
  /// Return suffix for next state.
  inline std::string SuffixNext(const size_t& t) const {
    return std::to_string(t) + "_" + unroller_suffix_ + ".nxt";
  }

protected:
  // ------------------------- TYPES ---------------------------------------- //
  typedef decltype(smt_gen_.GetShimExpr(nullptr, "")) SmtExpr;
  typedef decltype(smt_gen_.GetShimFunc(nullptr)) SmtFunc;
  typedef std::vector<ExprPtr> IlaExprVec;
  typedef std::vector<SmtExpr> SmtExprVec;

  // ------------------------- MEMBERS -------------------------------------- //
  //
  IlaExprVec deciding_vars_;
  //
  IlaExprVec update_holder_;
  //
  IlaExprVec assert_holder_;

  // ------------------------- METHODS -------------------------------------- //
  ///
  virtual void SetDecidingVars() = 0;

  ///
  virtual void MakeOneTransition(const size_t& idx) = 0;

  ///
  SmtExpr Unroll_(const size_t& len, const size_t& begin);

  ///
  SmtExpr UnrollWithStepsUnconnected_(const size_t& len, const size_t& begin);

private:
  // ------------------------- MEMBERS -------------------------------------- //

  // ------------------------- METHODS -------------------------------------- //

  // ------------------------- HELPERS -------------------------------------- //

}; // class UnrollerSmt

/// \brief Application class for unrolling a sequence of instructions.
template <class Generator> class PathUnroller : public UnrollerSmt<Generator> {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor.
  PathUnroller(SmtShim<Generator>& smt_shim, const std::string& suffix = "")
      : UnrollerSmt<Generator>(smt_shim, suffix) {}

  // ------------------------- METHODS -------------------------------------- //
  ///
  auto Unroll(const InstrVec& seq, const size_t& begin = 0) {
    seq_ = seq;
    return this->Unroll_(seq.size(), begin);
  }

  ///
  auto UnrollWithStepUnconnected(const InstrVec& seq, const size_t& begin) {
    seq_ = seq;
    return this->UnrollWithStepsUnconnected_(seq.size(), begin);
  }

protected:
  // ------------------------- METHODS -------------------------------------- //
  ///
  void SetDecidingVars();

  ///
  void MakeOneTransition(const size_t& idx);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The sequence of instructions.
  InstrVec seq_;

}; // class PathUnroller

} // namespace ilang

#endif // ILANG_ILA_MNGR_U_UNROLLER_SMT_H__