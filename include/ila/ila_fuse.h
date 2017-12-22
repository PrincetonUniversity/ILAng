/// \file
/// Header for the class IlaFuse

#ifndef __ILA_FUSE_H__
#define __ILA_FUSE_H__

#include "ila/expr_fuse.h"
#include "ila/instr.h"
#include "ila/instr_lvl_abs.h"
#include <string>

/// \namespace ila
namespace ila {

/// \class IlaFuse
/// IlaFuse is the uniform interface and wrapper for defining an ILA, except for
/// AST construction, which is defined by ExprFuse.
class IlaFuse : public ExprFuse {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor. NOT USED. Not for constructing objects.
  IlaFuse();
  /// Default destructor. NOT USED. Not for constructing objects.
  ~IlaFuse();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  // static functions for wrapping the hierarchy of AST.

private:
  // ------------------------- MEMBERS -------------------------------------- //

  // ------------------------- HELPERS -------------------------------------- //

}; // class IlaFuse

} // namespace ila

#endif // __ILA_FUSE_H__

