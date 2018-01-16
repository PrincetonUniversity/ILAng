/// \file
/// Header for wrapping the ila.

#ifndef __WRAP_INSTR_LVL_ABS_H__
#define __WRAP_INSTR_LVL_ABS_H__

#include "ila/instr_lvl_abs.h"
#include "python-api/wrap_expr.h"

namespace ila {

class WrapInstrLvlAbs {

  InstrLvlAbsPtr ptr;

public:
  WrapInstrLvlAbs(const std::string& name) : ptr(InstrLvlAbs::New(name)) {}

  ~WrapInstrLvlAbs() {}

  void NewBvInput(const std::string& name, const int& bit_width) {
    ptr->NewBvInput(name, bit_width);
  }

  ExprRef* input(const std::string& name) {
    // return ptr->input(name);
    return NULL;
  }

}; // class WrapInstrLvlAbs

} // namespace ila

#endif // __WRAP_INSTR_LVL_ABS_H__

