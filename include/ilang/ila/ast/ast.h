/// \file
/// Class Ast - abstract syntax tree (virtual) base clase.

#ifndef ILANG_ILA_AST_AST_H__
#define ILANG_ILA_AST_AST_H__

#include <memory>
#include <string>

#include <ilang/ila/object.h>

/// \namespace ilang
namespace ilang {

// Forward declaration for host.
class InstrLvlAbs;

/// \brief The class for the Abstract Syntax Tree. An Ast object can be an
/// expression or function definition (interpreted or uninterpreted).
class Ast : public Object {
protected:
  /// Type for forward declaration of ILA.
  typedef std::shared_ptr<InstrLvlAbs> InstrLvlAbsPtr;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  Ast() {}
  /// Constructor with name.
  Ast(const std::string& name) : Object(name) {}
  /// Default destructor.
  virtual ~Ast() {}

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
  void set_host(const InstrLvlAbsPtr& host) { host_ = host; }

  // ------------------------- METHODS -------------------------------------- //

  /// Output function.
  virtual std::ostream& Print(std::ostream& out) const = 0;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Pointer to the host ILA.
  InstrLvlAbsPtr host_ = nullptr;

}; // class Ast

} // namespace ilang

#endif // ILANG_ILA_AST_AST_H__
