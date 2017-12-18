/// \file
/// Header for the class ExprOp

#ifndef __EXPR_OP_H__
#define __EXPR_OP_H__

#include "ila/ast/expr.h"
#include "util/log.h"
#include <string>

/// \namespace ila
namespace ila {

/// \class ExprOp
/// Expression for operations, e.g. AND, OR, ADD, etc. Operations are
/// non-terminating nodes in the AST.
class ExprOp : public Expr {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor. DO NOT USE.
  ExprOp();
  /// Constructor for unary operators.
  ExprOp(const ExprPtr arg);
  /// Constructor for binary operators.
  ExprOp(const ExprPtr arg0, const ExprPtr arg1);
  virtual ~ExprOp();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the prefix of the variable expression.
  const std::string& prefix() const { return k_prefix_op_; }
  /// Return the name of the operation.
  virtual std::string op_name() const = 0;

  // ------------------------- METHODS -------------------------------------- //
  /// Return trus since this is an operation.
  bool IsOp() const { return true; }

  /// Return the z3 expression for the node.
  virtual z3::expr GetZ3Expr(z3::context& z3_ctx,
                             const Z3ExprVec& z3expr_vec) const = 0;

  /// Output to stream.
  // virtual std::ostream& Print(std::ostream& out) const = 0;
  std::ostream& Print(std::ostream& out) const;

protected:
  // ------------------------- HELPERS -------------------------------------- //
  /// Print unary operations.
  static std::ostream& PrintUnaryOp(std::ostream& out, ExprPtr op);
  /// Print binary operations.
  static std::ostream& PrintBinaryOp(std::ostream& out, ExprPtr op);
  /// Print n-ary operations.
  static std::ostream& PrintNaryOp(std::ostream& out, ExprPtr op);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Static prefix for the operation expressions.
  static const std::string k_prefix_op_;
  /// Static counter for un-named op expressions.
  static unsigned counter_;

  // ------------------------- HELPERS -------------------------------------- //
  /// Derived the sort for symmetric binary operations.
  static SortPtr DeriveSortSymBinary(const SortPtr s0, const SortPtr s1);

}; // class ExprOp

/// \class ExprOpAnd is the class wrapper for binary logical AND operation.
class ExprOpAnd : public ExprOp {
public:
  ExprOpAnd(const ExprPtr arg0, const ExprPtr arg1);
  std::string op_name() const { return "AND"; }
  z3::expr GetZ3Expr(z3::context& z3_ctx, const Z3ExprVec& z3expr_vec) const;
  // std::ostream& Print(std::ostream& out) const;
}; // class ExprOpAnd

/// \class ExprOpOr is the class wrapper for binary logical OR operation.
class ExprOpOr : public ExprOp {
public:
  ExprOpOr(const ExprPtr arg0, const ExprPtr arg1);
  std::string op_name() const { return "OR"; }
  z3::expr GetZ3Expr(z3::context& z3_ctx, const Z3ExprVec& z3expr_vec) const;
  // std::ostream& Print(std::ostream& out) const;
}; // class ExprOpOr

} // namespace ilak

#endif // __EXPR_OP_H__

