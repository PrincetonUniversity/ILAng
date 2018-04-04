/// \file
/// Source for a collection of ILA helpers.

#include "backend/abs_knob.h"
#include "backend/expr_rewrite.h"

namespace ila {

class FuncObjInsertExprVar {
public:
  FuncObjInsertExprVar(ExprSet& vars) : vars_(vars) {}

  void operator()(const ExprPtr e) const {
    if (e->is_var()) {
      vars_.insert(e);
    }
  }

private:
  ExprSet& vars_;

}; // class FuncObjInsertExprVar

class FuncObjInsertILAInp {
public:
  FuncObjInsertILAInp(ExprSet& vars) : vars_(vars) {}

  void operator()(const InstrLvlAbsCnstPtr m) const {
    AbsKnob::InsertInp(m, vars_);
  }

private:
  ExprSet& vars_;
}; // class FuncObjInsertILAStt

class FuncObjInsertILAStt {
public:
  FuncObjInsertILAStt(ExprSet& vars) : vars_(vars) {}

  void operator()(const InstrLvlAbsCnstPtr m) const {
    AbsKnob::InsertStt(m, vars_);
  }

private:
  ExprSet& vars_;
}; // class FuncObjInsertILAStt

/******************************************************************************/
ExprSet AbsKnob::GetVar(const ExprPtr e) {
  auto vars = ExprSet();
  auto func = FuncObjInsertExprVar(vars);
  e->DepthFirstVisit(func);
  return vars;
}

/******************************************************************************/
void AbsKnob::InsertStt(const InstrCnstPtr instr, ExprSet& vars) {
  auto host = instr->host();
  ILA_NOT_NULL(host);
  InsertStt(host, vars);
}

void AbsKnob::InsertSttTree(const InstrCnstPtr instr, ExprSet& vars) {
  auto host = instr->host();
  ILA_NOT_NULL(host);
  InsertSttTree(host, vars);
}

/******************************************************************************/
void AbsKnob::InsertVar(const InstrLvlAbsCnstPtr m, ExprSet& vars) {
  InsertStt(m, vars);
  InsertInp(m, vars);
}

void AbsKnob::InsertStt(const InstrLvlAbsCnstPtr m, ExprSet& stts) {
  for (decltype(m->state_num()) i = 0; i != m->state_num(); i++) {
    stts.insert(m->state(i));
  }
}

void AbsKnob::InsertInp(const InstrLvlAbsCnstPtr m, ExprSet& inps) {
  for (decltype(m->input_num()) i = 0; i != m->input_num(); i++) {
    inps.insert(m->input(i));
  }
}

void AbsKnob::InsertVarTree(const InstrLvlAbsCnstPtr top, ExprSet& vars) {
  InsertSttTree(top, vars);
  InsertInpTree(top, vars);
}

void AbsKnob::InsertSttTree(const InstrLvlAbsCnstPtr top, ExprSet& stts) {
  auto f = FuncObjInsertILAStt(stts);
  top->DepthFirstVisit(f);
}

void AbsKnob::InsertInpTree(const InstrLvlAbsCnstPtr top, ExprSet& inps) {
  auto f = FuncObjInsertILAInp(inps);
  top->DepthFirstVisit(f);
}

ExprSet AbsKnob::GetVar(const InstrLvlAbsCnstPtr m) {
  auto vars = ExprSet();
  InsertVar(m, vars);
  return vars;
}

ExprSet AbsKnob::GetStt(const InstrLvlAbsCnstPtr m) {
  auto stts = ExprSet();
  InsertStt(m, stts);
  return stts;
}

ExprSet AbsKnob::GetInp(const InstrLvlAbsCnstPtr m) {
  auto inps = ExprSet();
  InsertInp(m, inps);
  return inps;
}

ExprSet AbsKnob::GetVarTree(const InstrLvlAbsCnstPtr top) {
  auto vars = ExprSet();
  InsertVarTree(top, vars);
  return vars;
}

ExprSet AbsKnob::GetSttTree(const InstrLvlAbsCnstPtr top) {
  auto stts = ExprSet();
  InsertSttTree(top, stts);
  return stts;
}

ExprSet AbsKnob::GetInpTree(const InstrLvlAbsCnstPtr top) {
  auto inps = ExprSet();
  InsertInp(top, inps);
  return inps;
}

/******************************************************************************/

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

std::set<InstrPtr> AbsKnob::GetInstrOfIla(const InstrLvlAbsPtr top) {
  std::set<InstrPtr> instrs;
  GetInstrOfIla(top, instrs);
  return instrs;
}

InstrLvlAbsPtr AbsKnob::ExtrDeptModl(const InstrPtr instr,
                                     const std::string& name) {
  ILA_NOT_NULL(instr);
  ILA_NOT_NULL(instr->host());

  auto h = instr->host();
  auto m = InstrLvlAbs::New(name);

  try { // Create new state/input variables in the new ILA.
    CopyVar(h, m);
  } catch (...) {
    ILA_ERROR << "Error in copy variables from " << h << " to " << m;
    return h;
  }

  try { // Rewrite ILA attributes, e.g. fetch, valid, etc.
    CopyAttr(h, m);
  } catch (...) {
    ILA_ERROR << "Error in copying ILA attributes from " << h << " to " << m;
    return h;
  }

  // TODO child-program and sub-trees

  return m;
}

void AbsKnob::CopyIla(const InstrLvlAbsCnstPtr src, const InstrLvlAbsPtr dst) {
  ILA_NOT_NULL(src);
  ILA_NOT_NULL(dst);
  // check that dst is empty
  ILA_ASSERT(dst->instr_num() == 0) << "Non-empty container " << dst;
  ILA_ASSERT(dst->child_num() == 0) << "Non-empty container " << dst;

  try { // Create new state/input variables in the new ILA.
    CopyVar(src, dst);
    ILA_ASSERT(src->state_num() == dst->state_num()) << "State num mismatch";
    ILA_ASSERT(src->input_num() == dst->input_num()) << "Input num mismatch";
  } catch (...) {
    ILA_ERROR << "Error in copying variables from " << src << " to " << dst;
    return;
  }

  // create rewriting map
  auto rule = ExprMap();
  // auto vars = GetVarOfIla(dst);
  for (decltype(src->state_num()) i = 0; i != src->state_num(); i++) {
    // rule.insert(
  }

  try { // Rewrite fetch
    // auto fetch =
  } catch (...) {
    return;
  }
}

void AbsKnob::CopyVar(const InstrLvlAbsCnstPtr src, const InstrLvlAbsPtr dst) {
  // copy state
  for (decltype(src->state_num()) i = 0; i != src->state_num(); i++) {
    CopyStVar(src->state(i), dst);
  }
  // copy input
  for (decltype(src->input_num()) i = 0; i != src->input_num(); i++) {
    CopyInVar(src->input(i), dst);
  }
}

void AbsKnob::CopyAttr(const InstrLvlAbsCnstPtr src, const InstrLvlAbsPtr dst) {
  // TODO
  // fetch
  // valid
  // init
  // spec
}

ExprPtr AbsKnob::Rewrite(const ExprPtr e, const ExprMap& rule) {
  auto func_obj = FuncObjRewrite(rule);
  // rewrite all sub-trees
  e->DepthFirstVisitPrePost(func_obj);
  // return rewrited/copied node
  auto res = func_obj.get(e);
  ILA_ASSERT(res) << "Fail rewriting " << e;
  return res;
}

ExprPtr AbsKnob::CopyStVar(const ExprPtr src, const InstrLvlAbsPtr dst_host) {
  ILA_NOT_NULL(src);
  ILA_ASSERT(src->is_var());

  // bypass if is parent state
  auto copy = dst_host->state(src->name().str());
  if (copy) {
    ILA_ASSERT(copy->host() != dst_host) << "State " << src << " exists.";
    return copy;
  }
  // create new state var
  if (src->is_bool()) {
    copy = dst_host->NewBoolState(src->name().str());
  } else if (src->is_bv()) {
    copy = dst_host->NewBvState(src->name().str(), src->sort()->bit_width());
  } else {
    ILA_ASSERT(src->is_mem()) << "Unknown type of " << src;
    copy = dst_host->NewMemState(src->name().str(), src->sort()->addr_width(),
                                 src->sort()->data_width());
  }

  return copy;
}

ExprPtr AbsKnob::CopyInVar(const ExprPtr src, const InstrLvlAbsPtr dst_host) {
  ILA_NOT_NULL(src);
  ILA_ASSERT(src->is_var());
  ILA_ASSERT(!src->is_mem()) << "Mem var typed input not support.";

  // bypass if is parent input
  auto copy = dst_host->input(src->name().str());
  if (copy) {
    ILA_ASSERT(copy->host() != dst_host) << "Input " << src << " exists.";
    return copy;
  }
  // create new input var
  if (src->is_bool()) {
    copy = dst_host->NewBoolInput(src->name().str());
  } else {
    ILA_ASSERT(src->is_bv()) << "Unknown type of " << src;
    copy = dst_host->NewBvInput(src->name().str(), src->sort()->bit_width());
  }

  return copy;
}

} // namespace ila

