#ifndef ILANG_UTIL_VALIDATE_MODEL_H__
#define ILANG_UTIL_VALIDATE_MODEL_H__

#include <ilang/ila/ast_fuse.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ila/z3_expr_adapter.h>

namespace ilang {
enum DEFAULT_UPDATE_METHOD { OLD_VALUE = 0, NONDET_VALUE = 1 };

bool deterministic_check(const InstrLvlAbsPtr& model_ptr_);
bool complete_check(const InstrLvlAbsPtr& model_ptr_);
void complete_model(const InstrLvlAbsPtr& model_ptr_,
                    DEFAULT_UPDATE_METHOD dum);
} // namespace ilang

#endif
