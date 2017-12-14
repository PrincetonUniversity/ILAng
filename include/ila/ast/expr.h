/// \file
/// Header for the class Expr

#ifndef __EXPR_H__
#define __EXPR_H__

#include "ila/ast.h"
#include <memory>
#include <string>

/// \namespace ila
namespace ila {

/// \class Expr
/// The class for expression, which is the basic type for variables,
/// constraints, state update expressions, etc.
class Expr : public Ast {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  Expr();
  /// The constructor for the class Expr with arity.
  Expr(const int& arity);
  /// The constructor for the class Expr with name.
  Expr(const std::string& name);
  /// The constructor for the class Expr with name and arity.
  Expr(const std::string& name, const int& arity);
  /// The uniform constructor for the class Expr.
  Expr(ExprType type = ExprType::EXPR_BV, const int& arity = 0,
       const std::string& name = "");
  /// The destructor for the class Expr.
  ~Expr();

  /// Is type expr.
  bool IsExpr() const { return true; }

  typedef std::shared_ptr<Expr> ExprPtr;

  /// Compare two expression with object.
  static bool Equal(const Expr& lhs, const Expr& rhs);
  /// Compare two expression with pointer.
  static bool Equal(const ExprPtr lhs, const ExprPtr rhs);
  /// Overload comparison.
  friend bool operator==(const Expr& lhs, const Expr& rhs);

private:
}; // class Expr

/// \def Pointer for Expr.
typedef Expr::ExprPtr ExprPtr;

} // namespace ila

#endif // __EXPR_H__

