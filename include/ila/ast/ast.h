/// \file
/// Header for the class Ast.

#ifndef AST_H__
#define AST_H__

#include "ila/object.h"
#include "z3++.h"
#include <memory>
#include <string>

/// \namespace ila
namespace ila {

/// \brief The class for the Abstract Syntax Tree. An Ast object can be an
/// expression or function definition (interpreted or uninterpreted).
class Ast : public Object {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  Ast();
  /// Default destructor.
  virtual ~Ast();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Is type Ast.
  bool is_ast() const { return true; }

  /// Is type Ast::Sort.
  virtual bool is_sort() const { return false; }
  /// Is type Ast::Expr.
  virtual bool is_expr() const { return false; }
  /// Is type Ast::Func.
  virtual bool is_func() const { return false; }

  // ------------------------- METHODS -------------------------------------- //

  /// Output function.
  virtual std::ostream& Print(std::ostream& out) const = 0;

private:
  // ------------------------- MEMBERS -------------------------------------- //

  // ------------------------- HELPERS -------------------------------------- //

}; // class Ast

} // namespace ila

#endif // AST_H__

