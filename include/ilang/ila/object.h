/// \file
/// The header for the class Object.

#ifndef ILANG_ILA_OBJECT_H__
#define ILANG_ILA_OBJECT_H__

#include <memory>
#include <string>

#include <ilang/ila/symbol.h>

/// \namespace ilang
namespace ilang {

/// \brief The basest type in the ILA structure. It can be either Ast,
/// Instr, or InstrLvlAbs.
class Object {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  Object();
  /// Constructor with string name.
  Object(const std::string& name);
  /// Default destructor.
  virtual ~Object();

  /// Pointer type for normal use of Object.
  typedef std::shared_ptr<Object> ObjPtr;

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Get the symbol (name).
  const Symbol& name() const;

  /// Is type InstrLvlAbs.
  virtual bool is_instr_lvl_abs() const { return false; }
  /// Is type Instr.
  virtual bool is_instr() const { return false; }
  /// Is type Ast.
  virtual bool is_ast() const { return false; }

  // ------------------------- METHODS -------------------------------------- //
  /// Output function.
  virtual std::ostream& Print(std::ostream& out) const = 0;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Symbol (name) of the object.
  Symbol symbol_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class Object

/// Pointer type for normal use of Object.
typedef Object::ObjPtr ObjPtr;

} // namespace ilang

#endif // ILANG_ILA_OBJECT_H__
