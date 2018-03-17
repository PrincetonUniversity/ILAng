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

// Forward declaration for host.
class InstrLvlAbs;

/// \brief The class for the Abstract Syntax Tree. An Ast object can be an
/// expression or function definition (interpreted or uninterpreted).
class Ast : public Object {
public:
  /// Type for forward declaration of ILA.
  typedef std::shared_ptr<InstrLvlAbs> InstrLvlAbsPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  Ast();
  /// Constructor with name.
  Ast(const std::string& name);
  /// Default destructor.
  virtual ~Ast();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Is type Ast.
  bool is_ast() const { return true; }

  /// Is type Ast::Expr.
  virtual bool is_expr() const { return false; }
  /// Is type Ast::Func.
  virtual bool is_func() const { return false; }

  /// Return the hosting ILA.
  inline InstrLvlAbsPtr host() const { return host_; }
  /// Set the hosting ILA.
  void set_host(InstrLvlAbsPtr host);

  // ------------------------- METHODS -------------------------------------- //

  /// Output function.
  virtual std::ostream& Print(std::ostream& out) const = 0;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Pointer to the host ILA.
  InstrLvlAbsPtr host_ = NULL;

  // ------------------------- HELPERS -------------------------------------- //

}; // class Ast

} // namespace ila

#endif // AST_H__

