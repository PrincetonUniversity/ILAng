/// \file
/// Header for wrapping the ila.

#ifndef __WRAP_INSTR_LVL_ABS_H__
#define __WRAP_INSTR_LVL_ABS_H__

#include "ila/instr_lvl_abs.h"
#include "python-api/wrap_expr.h"

namespace ila {
namespace pyapi {

class InstrLvlAbsWrap {

  InstrLvlAbsPtr ptr;

public:
  InstrLvlAbsWrap(const std::string& name) : ptr(InstrLvlAbs::New(name)) {}

  ~InstrLvlAbsWrap() {}

  // FIXME return instruction
  void NewBvInput(const std::string& name, const int& bit_width) {
    ptr->NewBvInput(name, bit_width);
  }

  ExprWrap* input(const std::string& name) {
    return new ExprWrap(ptr->input(name));
  }

}; // class InstrLvlAbsWrap

} // namespace pyapi
} // namespace ila

#endif // __WRAP_INSTR_LVL_ABS_H__

