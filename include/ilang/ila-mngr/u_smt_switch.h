/// \file
/// Header for the smt-switch interface.

#ifndef ILANG_ILA_MNGR_U_SMT_SWITCH_H__
#define ILANG_ILA_MNGR_U_SMT_SWITCH_H__

#include <ilang/config.h>

#ifdef SMTSWITCH_INTERFACE

#include <string>
#include <unordered_map>

#include <smt-switch/smt.h>

#include <ilang/ila/expr_fuse.h>

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

  /// Type for cacheing the generated expressions.
  typedef std::unordered_map<const ExprPtr, smt::Term, ExprHash> ExprMap;

  // ------------------------- METHODS -------------------------------------- //
  /// Get the SMT Term of the AST node.
  smt::Term GetSmtTerm(const ExprPtr expr, const std::string& suffix = "");

  /// Function object for getting SMT Term.
  void operator()(const ExprPtr expr);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The underlying SMT solver.
  smt::SmtSolver& solver_;
  /// Container for cacheing intermediate expressions.
  ExprMap expr_map_;
  /// Name suffix for each expression generation (e.g., time step).
  std::string suffix_ = "";

  // ------------------------- HELPERS -------------------------------------- //
  /// Insert the SMT Term of the given node into the map.
  void PopulateExprMap(const ExprPtr expr);
  /// Make Term of expr based on its argument terms.
  smt::Term Expr2Term(const ExprPtr expr, const smt::TermVec& arg_terms);
  /// Make Term of expr variable.
  smt::Term ExprVar2Term(const ExprPtr expr);
  /// Make Term of expr constant.
  smt::Term ExprConst2Term(const ExprPtr expr);
  /// Make Term of expr operator.
  smt::Term ExprOp2Term(const ExprPtr expr, const smt::TermVec& arg_terms);

}; // class SmtSwitchItf

}; // namespace ilang

#endif // SMTSWITCH_INTERFACE

#endif // ILANG_ILA_MNGR_U_SMT_SWITCH_H__

