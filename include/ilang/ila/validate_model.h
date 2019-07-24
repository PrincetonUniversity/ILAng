#ifndef ILANG_ILA_VALIDATE_MODEL_H__
#define ILANG_ILA_VALIDATE_MODEL_H__

#include <ilang/ila/ast_fuse.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ila/z3_expr_adapter.h>

/// \namespace ilang
namespace ilang {

/// Unified ID for default state-update methods to auto-complete ILA models.
/// OLD_VALUE: s_next <- s
/// NONDET_VALUE: s_next <- nondet_func()
enum DEFAULT_UPDATE_METHOD { OLD_VALUE = 0, NONDET_VALUE = 1 };

bool CheckDeterminism(const InstrLvlAbsPtr& model_ptr_);
bool CheckCompleteness(const InstrLvlAbsPtr& model_ptr_);
void CompleteModel(const InstrLvlAbsPtr& model_ptr_,
                    DEFAULT_UPDATE_METHOD dum);
} // namespace ilang

#endif // ILANG_ILA_VALIDATE_MODEL_H__
