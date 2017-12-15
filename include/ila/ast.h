/// \file
/// Header for the class Ast.

#ifndef __AST_H__
#define __AST_H__

#include "ila/object.h"
#include "z3++.h"
#include <memory>
#include <string>

/// \namespace ila
namespace ila {

/// \class Ast
/// The class for the Abstract Syntax Tree. An Ast object can be an expression
/// or function definition (interpreted or uninterpreted).
class Ast : public Object {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  Ast();
  /// Constructor with name.
  Ast(const std::string& name);
  /// Default destructor.
  virtual ~Ast();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  /// Is type Ast.
  bool IsAst() const { return true; }

  /// Is type Ast::Sort.
  virtual bool IsSort() const { return false; }
  /// Is type Ast::Expr.
  virtual bool IsExpr() const { return false; }
  /// Is type Ast::Func.
  virtual bool IsFunc() const { return false; }

  /// Get SMT formula of the AST node.
  virtual z3::expr GetZ3Expr(z3::context& z3_ctx) const = 0;

  /// Output function.
  virtual std::ostream& Print(std::ostream& out) const = 0;

private:
  // ------------------------- MEMBERS -------------------------------------- //

  // ------------------------- HELPERS -------------------------------------- //

}; // class Ast

typedef std::shared_ptr<Ast> AstPtr;

} // namespace ila

#endif // __AST_H__

