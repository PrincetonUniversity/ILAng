/// \file
/// Header for the class ILAFuse

#ifndef __ILA_FUSE_H__
#define __ILA_FUSE_H__

#include "ila/expr_fuse.h"
#include "ila/instr.h"
#include "ila/instr_lvl_abs.h"
#include <string>

/// \namespace ila
namespace ila {

/// \class ILAFuse
/// ILAFuse is the uniform interface and wrapper for defining an ILA, except for
/// AST construction, which is defined by ExprFuse.
class ILAFuse : public ExprFuse {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor. NOT USED. Not for constructing objects.
  ILAFuse();
  /// Default destructor. NOT USED. Not for constructing objects.
  ~ILAFuse();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  // static functions for wrapping the hierarchy of AST.

  /// Create a new ILA (InstrLvlAbs) with the name.
  static InstrLvlAbsPtr NewILA(const std::string& name);

  /// Create a new instruction (Instr) with the name.
  static InstrPtr NewInstr(const std::string& name);

private:
  // ------------------------- MEMBERS -------------------------------------- //

  // ------------------------- HELPERS -------------------------------------- //

}; // class ILAFuse

} // namespace ila

#endif // __ILA_FUSE_H__

