/// \file
/// Class LiaCvtr - the converter for linear integer arithmetic SMT expressions.

#ifndef ILANG_TARGET_SMT_LIA_CVTR_H__
#define ILANG_TARGET_SMT_LIA_CVTR_H__

#ifdef SMTSWITCH_INTERFACE

#include <string>
#include <unordered_map>

#include <smt-switch/smt.h>

#include <ilang/ila/ast_hub.h>
#include <ilang/target-smt/smt_switch_itf.h>

/// \namepsace ilang
namespace ilang {

class LiaCvtr : public SmtSwitchItf {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  LiaCvtr(smt::SmtSolver& solver);
  /// Default destructor.
  ~LiaCvtr();

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
  /// Make Term of expr variable.
  smt::Term ExprVar2Term(const ExprPtr& expr);
  /// Make Term of expr constant.
  smt::Term ExprConst2Term(const ExprPtr& expr);
  /// Make Term of expr operator.
  smt::Term ExprOp2Term(const ExprPtr& expr, const smt::TermVec& arg_terms);
  /// Make Term of func.
  smt::Term Func2Term(const FuncPtr& func);
  /// Make smt::Sort of ilang::SortPtr.
  smt::Sort IlaSort2LiaSort(const SortPtr& s);

}; // class LiaCvtr

} // namespace ilang

#endif // SMTSWITCH_INTERFACE

#endif // ILANG_TARGET_SMT_LIA_CVTR_H__

