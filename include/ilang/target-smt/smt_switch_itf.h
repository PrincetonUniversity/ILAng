/// \file
/// Class SmtSwitchItf - the interface to external library smt-switch.

#ifndef ILANG_ILA_MNGR_U_SMT_SWITCH_H__
#define ILANG_ILA_MNGR_U_SMT_SWITCH_H__

#ifdef SMTSWITCH_INTERFACE

#include <string>
#include <unordered_map>

#include <smt-switch/smt.h>

#include <ilang/ila/ast_hub.h>

/// \namespace ilang
namespace ilang {

/// \brief The class that interface Expr to smt-switch Terms.
class SmtSwitchItf {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  SmtSwitchItf(smt::SmtSolver& solver);
  /// Default destructor.
  ~SmtSwitchItf();

  // ------------------------- METHODS -------------------------------------- //
  /// Get the SMT Term of the AST node.
  smt::Term GetSmtTerm(const ExprPtr& expr, const std::string& suffix = "");
  /// Reset the solver and the interface.
  void Reset();
  /// Return the underlying SMT solver;
  inline smt::SmtSolver& solver() const { return solver_; }

  /// Check if Term is generated.
  bool pre(const ExprPtr& expr);
  /// Generate Term if not already.
  void post(const ExprPtr& expr);

  // ------------------------- SHIM INTERFACE ------------------------------- //
  /// Unified SmtShim interface to get smt::Term.
  inline auto GetShimExpr(const ExprPtr& expr, const std::string& suffix) {
    return GetSmtTerm(expr, suffix);
  }
  /// Unified SmtShim interface to get smt::Func.
  inline auto GetShimFunc(const FuncPtr& func) { return Func2Term(func); }
  /// Unified SmtShim interface to AND two boolean smt::Term.
  inline auto BoolAnd(const smt::Term& a, const smt::Term& b) {
    return solver_->make_term(smt::PrimOp::And, a, b);
  }
  /// Unified SmtShim interface to EQUAL two smt::Term.
  inline auto Equal(const smt::Term& a, const smt::Term& b) {
    return solver_->make_term(smt::PrimOp::Equal, a, b);
  }

private:
  /// Type for cacheing the generated expressions.
  typedef std::unordered_map<const ExprPtr, smt::Term, ExprHash> ExprTermMap;
  /// Type for cacheing the generated functions.
  typedef std::unordered_map<const FuncPtr, smt::Term, FuncHash> FuncTermMap;

  // ------------------------- MEMBERS -------------------------------------- //
  /// The underlying SMT solver.
  smt::SmtSolver& solver_;
  /// Container for cacheing expression Terms.
  ExprTermMap expr_map_;
  /// Container for cacheing function Terms.
  FuncTermMap func_map_;
  /// Name suffix for each expression generation (e.g., time step).
  std::string suffix_ = "";

  // ------------------------- HELPERS -------------------------------------- //
  /// Insert the SMT Term of the given node into the map.
  void PopulateExprMap(const ExprPtr& expr);
  /// Make Term of expr variable.
  smt::Term ExprVar2Term(const ExprPtr& expr);
  /// Make Term of expr constant.
  smt::Term ExprConst2Term(const ExprPtr& expr);
  /// Make Term of expr operator.
  smt::Term ExprOp2Term(const ExprPtr& expr, const smt::TermVec& arg_terms);
  /// Make Term of func.
  smt::Term Func2Term(const FuncPtr& func);
  /// Make smt::Sort of ilang::SortPtr.
  smt::Sort IlaSort2SmtSort(const SortPtr& s);

}; // class SmtSwitchItf

} // namespace ilang

#endif // SMTSWITCH_INTERFACE

#endif // ILANG_ILA_MNGR_U_SMT_SWITCH_H__

