/// \file
/// Source for a collection of ILA helpers.

#include "backend/abs_knob.h"

namespace ila {

AbsKnob::AbsKnob() {}

void AbsKnob::GetVarOfIla(const InstrLvlAbsPtr top, std::set<ExprPtr>& vars) {
  ILA_NOT_NULL(top);
  // traverse the child-ILAs
  for (size_t i = 0; i != top->child_num(); i++) {
    GetVarOfIla(top->child(i), vars);
  }
  // child-states must contain parent-states
  if (top->child_num() != 0)
    return;
  // add states if no child-ILAs
  for (size_t i = 0; i != top->state_num(); i++) {
    vars.insert(top->state(i));
  }
}

} // namespace ila

