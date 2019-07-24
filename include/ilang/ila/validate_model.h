/// \file
/// Header for validating/completing fuctions to ILA models

#ifndef ILANG_ILA_VALIDATE_MODEL_H__
#define ILANG_ILA_VALIDATE_MODEL_H__

#include <ilang/ila/instr_lvl_abs.h>

/// \namespace ilang
namespace ilang {

/// Unified ID for default state-update methods to auto-complete ILA models.
/// OLD_VALUE: s_next <- s
/// NONDET_VALUE: s_next <- nondet_func()
enum DEFAULT_UPDATE_METHOD { OLD_VALUE = 0, NONDET_VALUE = 1 };

/// Check whether the model (pointed by model_ptr_) is deterministic.
/// Determinism means no more than one instruction can be decoded truth.
bool CheckDeterminism(const InstrLvlAbsPtr& model_ptr_);
/// Check whether the model (pointed by model_ptr_) is complete.
/// Completeness means every assignment to input and state corresponds an
/// instruction.
bool CheckCompleteness(const InstrLvlAbsPtr& model_ptr_);
/// Use a default update method to complete model.
void CompleteModel(const InstrLvlAbsPtr& model_ptr_,
                    DEFAULT_UPDATE_METHOD dum);
} // namespace ilang

#endif // ILANG_ILA_VALIDATE_MODEL_H__
