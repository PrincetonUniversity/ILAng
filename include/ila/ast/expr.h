/// \file
/// Header for the class Expr

#ifndef __EXPR_H__
#define __EXPR_H__

#include "ila/ast.h"
#include "ila/ast/sort.h"
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
  /// Default destructor.
  ~Expr();

  typedef std::shared_ptr<Expr> ExprPtr;

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  /// Is type expr.
  bool IsExpr() const { return true; }

  /// Return true if this is a Boolean expression.
  virtual bool IsBool() const = 0;
  /// Return true if this is a Bitvector expression.
  virtual bool IsBv() const = 0;

  /// Compare two expression with object.
  static bool Equal(const Expr& lhs, const Expr& rhs);
  /// Compare two expression with pointer.
  static bool Equal(const ExprPtr lhs, const ExprPtr rhs);
  /// Overload comparison.
  friend bool operator==(const Expr& lhs, const Expr& rhs);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The sort of the expr.
  Sort sort_;
  /// Number of arguments.
  int arity_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class Expr

/// \def Pointer for Expr.
typedef Expr::ExprPtr ExprPtr;

} // namespace ila

#endif // __EXPR_H__

