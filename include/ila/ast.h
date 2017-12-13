/// \file
/// Header for the class Ast.

#ifndef __AST_H__
#define __AST_H__

#include "ila/object.h"
#include <memory>

/// \namespace ila
namespace ila {

/// \class Ast
/// The class for the Abstract Syntax Tree. An Ast object can be an expression
/// or function definition (interpreted or uninterpreted).
class Ast : public Object {
public:
  /// The constructor for the class Ast.
  Ast();
  /// The constructor for the class Ast with arity.
  Ast(const int& arity);
  /// The destructor for the class Ast.
  ~Ast();

  /// Is type Ast.
  bool IsAst() const { return true; }

  /// Is type Expr.
  virtual bool IsExpr() const { return false; }
  /// Is type Func.
  virtual bool IsFunc() const { return false; }

  /// Getting the arity.
  const int& Arity() const;

private:
  /// Arity.
  int arity_;

}; // class Ast

typedef std::shared_ptr<Ast> AstPtr;

} // namespace ila

#endif // __AST_H__

