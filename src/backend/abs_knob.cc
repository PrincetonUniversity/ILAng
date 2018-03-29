/// \file
/// Source for a collection of ILA helpers.

#include "backend/abs_knob.h"

namespace ila {

class FuncObjAddVarToSet {
public:
  FuncObjAddVarToSet(std::set<ExprPtr>& vars) : vars_(vars) {}

  void operator()(const ExprPtr e) const {
    if (e->is_var()) {
      vars_.insert(e);
    }
  }

private:
  std::set<ExprPtr>& vars_;

}; // class DfsFuncObjAddVarToSet

AbsKnob::AbsKnob() {}

void AbsKnob::GetVarOfIla(const InstrLvlAbsPtr top, std::set<ExprPtr>& vars) {
  ILA_NOT_NULL(top);
  GetInVarOfIla(top, vars);
  GetStVarOfIla(top, vars);
}

void AbsKnob::GetInVarOfIla(const InstrLvlAbsPtr top, std::set<ExprPtr>& vars) {
  ILA_NOT_NULL(top);
  // traverse the child-ILAs
  for (size_t i = 0; i != top->child_num(); i++) {
    GetVarOfIla(top->child(i), vars);
  }
  // child-states must contain parent-states
  if (top->child_num() != 0)
    return;
  // add states if no child-ILAs
  for (size_t i = 0; i != top->input_num(); i++) {
    vars.insert(top->input(i));
  }
}

void AbsKnob::GetStVarOfIla(const InstrLvlAbsPtr top, std::set<ExprPtr>& vars) {
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

void AbsKnob::GetVarOfExpr(const ExprPtr e, std::set<ExprPtr>& vars) {
  ILA_NOT_NULL(e);
  auto obj = FuncObjAddVarToSet(vars);
  e->DepthFirstVisit(obj);
}

} // namespace ila

