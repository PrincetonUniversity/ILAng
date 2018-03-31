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

template <class I>
void AbsKnob::GetStVarOfInstr(const I& instrs, std::set<ExprPtr>& vars) {
  std::set<InstrLvlAbsPtr> hosts;
  for (auto it = instrs.begin(); it != instrs.end(); it++) {
    auto instr = *it;
    auto h = instr->host();
    ILA_NOT_NULL(h);
    hosts.insert(h);
  }
  for (auto it = hosts.begin(); it != hosts.end(); it++) {
    GetStVarOfIla(*it, vars);
  }
}
// define the supported template type
template void
AbsKnob::GetStVarOfInstr<std::set<InstrPtr>>(const std::set<InstrPtr>& instrs,
                                             std::set<ExprPtr>& vars);
template void AbsKnob::GetStVarOfInstr<std::vector<InstrPtr>>(
    const std::vector<InstrPtr>& instrs, std::set<ExprPtr>& vars);

std::set<ExprPtr> AbsKnob::GetVarOfIla(const InstrLvlAbsPtr top) {
  std::set<ExprPtr> vars;
  GetVarOfIla(top, vars);
  return vars;
}

std::set<ExprPtr> AbsKnob::GetStVarOfIla(const InstrLvlAbsPtr top) {
  std::set<ExprPtr> vars;
  GetStVarOfIla(top, vars);
  return vars;
}

std::set<ExprPtr> AbsKnob::GetInVarOfIla(const InstrLvlAbsPtr top) {
  std::set<ExprPtr> vars;
  GetInVarOfIla(top, vars);
  return vars;
}

std::set<ExprPtr> AbsKnob::GetVarOfExpr(const ExprPtr e) {
  std::set<ExprPtr> vars;
  GetVarOfExpr(e, vars);
  return vars;
}

void AbsKnob::GetVarOfExpr(const ExprPtr e, std::set<ExprPtr>& vars) {
  ILA_NOT_NULL(e);
  auto obj = FuncObjAddVarToSet(vars);
  e->DepthFirstVisit(obj);
}

template <class I> std::set<ExprPtr> AbsKnob::GetStVarOfInstr(const I& instrs) {
  std::set<ExprPtr> vars;
  GetStVarOfInstr(instrs, vars);
  return vars;
}

template <class I>
void AbsKnob::GetInstrOfIla(const InstrLvlAbsPtr top, I& instrs) {
  ILA_NOT_NULL(top);
  // traverse the child-ILAs
  for (decltype(top->child_num()) i = 0; i != top->child_num(); i++) {
    GetInstrOfIla(top->child(i), instrs);
  }
  // add instr
  for (decltype(top->instr_num()) i = 0; i != top->instr_num(); i++) {
    instrs.insert(instrs.end(), top->instr(i));
  }
}
// define the supported template type
template void
AbsKnob::GetInstrOfIla<std::set<InstrPtr>>(const InstrLvlAbsPtr top,
                                           std::set<InstrPtr>& instrs);
template void
AbsKnob::GetInstrOfIla<std::vector<InstrPtr>>(const InstrLvlAbsPtr top,
                                              std::vector<InstrPtr>& instrs);

} // namespace ila

