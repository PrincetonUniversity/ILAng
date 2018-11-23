/// \file
/// Header for wrapping the ila.

#ifndef WRAP_INSTR_LVL_ABS_H__
#define WRAP_INSTR_LVL_ABS_H__

#include "ila/instr_lvl_abs.h"
#include "python-api/wrap_expr.h"

namespace ila {
namespace pyapi {

/// \brief The wrapper class for InstrLvlAbs
class InstrLvlAbsWrap {
  // ------------------------- MEMBERS -------------------------------------- //
  /// Wrapped data.
  InstrLvlAbsPtr ptr_;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor for Boost.Python API.
  InstrLvlAbsWrap(const std::string& name) : ptr_(InstrLvlAbs::New(name)) {}

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  /// Create new bitvector input.
  ExprWrap* NewBvInput(const std::string& name, const int& bit_width);
  /// Get the input with name.
  ExprWrap* input(const std::string& name);
  /// TODO

}; // class InstrLvlAbsWrap

} // namespace pyapi
} // namespace ila

#endif // WRAP_INSTR_LVL_ABS_H__

