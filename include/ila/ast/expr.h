/// \file
/// Header for the class Expr

#ifndef __EXPR_H__
#define __EXPR_H__

#include "ila/ast.h"

/// \namespace ila
namespace ila {

/// \class Expr
/// The class for expression, which is the basic type for variables,
/// constraints, state update expressions, etc.
class Expr : public Ast {
public:
  /// The constructor for the class Expr.
  Expr();
  /// The constructor for the class Expr with arity.
  Expr(const int& arity);
  /// The destructor for the class Expr.
  ~Expr();

  /// Is type expr.
  bool IsExpr() const { return true; }

private:
}; // class Expr

} // namespace ila

#endif // __EXPR_H__

