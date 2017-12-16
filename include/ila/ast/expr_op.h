/// \file
/// Header for the class ExprOp

#ifndef __EXPR_OP_H__
#define __EXPR_OP_H__

#include "ila/ast/expr.h"
#include <string>

/// \namespace ila
namespace ila {

/// \class ExprOp
/// Expression for operations, e.g. AND, OR, ADD, etc. Operations are
/// non-terminating nodes in the AST.
class ExprOp : public Expr {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor. DO NOT USE. (op should have arguments)
  ExprOp();
  /// Constructor.
  ExprOp(const ExprPtrVec& args);
  /// Constructor with explicity specified name.
  ExprOp(const std::string& name, const ExprPtrVec& args);
  /// Constructor for unary operators.
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
  virtual std::ostream& Print(std::ostream& out) const = 0;

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

}; // class ExprOp

class ExprOpAnd : protected ExprOp {
  ExprOpAnd(const ExprPtr& arg0, const ExprPtr& arg1);
  std::string op_name() const { return "AND"; }
  virtual z3::expr GetZ3Expr(z3::context& z3_ctx,
                             const Z3ExprVec& z3expr_vec) const;
};

class ExprOpOr : protected ExprOp {
  ExprOpOr(const ExprPtr& arg0, const ExprPtr& arg1);
  std::string op_name() const { return "OR"; }
  virtual z3::expr GetZ3Expr(z3::context& z3_ctx,
                             const Z3ExprVec& z3expr_vec) const;
}

} // namespace ilak

#endif // __EXPR_OP_H__

