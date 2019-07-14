#ifndef ILANG_UTIL_VALIDATE_MODEL_H__
#define ILANG_UTIL_VALIDATE_MODEL_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ila/z3_expr_adapter.h>

namespace ilang {
  bool deterministic_check(const InstrLvlAbsPtr& model_ptr_);  
  bool complete_check(const InstrLvlAbsPtr& model_ptr_);
}




#endif
