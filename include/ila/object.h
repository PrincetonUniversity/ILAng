/// \file
/// The header for the class Object.

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "ila/symbol.h"
#include <memory>
#include <string>

/// \namespace ila
namespace ila {

/// \class Object
/// Object is the basest type in the ILA structure. It can be either the AST
/// node, Instr, or a (child-)ILA.
class Object {
public:
  /// The constructor for Object.
  Object();
  /// The constructor for Object with string name.
  Object(const std::string& name);
  /// The destructor for the class Object.
  ~Object();

  /// Get the name (symbol)
  const Symbol& Name() const;

  /// Is type InstrLvlAbs.
  virtual bool IsInstrLvlAbs() const { return false; }
  /// Is type Instr.
  virtual bool IsInstr() const { return false; }
  /// Is type Ast.
  virtual bool IsAst() const { return false; }

private:
  /// Symbol (name) of the object.
  Symbol symbol_;

}; // class Object

typedef std::shared_ptr<Object> ObjPtr;

} // namespace ila

#endif // __OBJECT_H__

