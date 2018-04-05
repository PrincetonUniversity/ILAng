/// \file
/// Source for a collection of ILA helpers.

#include "backend/abs_knob.h"
#include "backend/rewrite_expr.h"
#include "backend/rewrite_ila.h"

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

class FuncObjInsertILAInstr {
public:
  FuncObjInsertILAInstr(InstrVec& instrs) : instrs_(instrs) {}

  void operator()(const InstrLvlAbsCnstPtr m) const {
    AbsKnob::InsertInstr(m, instrs_);
  }

private:
  InstrVec& instrs_;

}; // class FuncOjbInsertILAInstr

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

void AbsKnob::InsertInstr(const InstrLvlAbsCnstPtr m, InstrVec& instrs) {
  for (decltype(m->instr_num()) i = 0; i != m->instr_num(); i++) {
    instrs.insert(instrs.end(), m->instr(i));
  }
}

void AbsKnob::InsertInstrTree(const InstrLvlAbsCnstPtr top, InstrVec& instrs) {
  auto f = FuncObjInsertILAInstr(instrs);
  top->DepthFirstVisit(f);
}

InstrVec AbsKnob::GetInstrTree(const InstrLvlAbsCnstPtr m) {
  auto instrs = InstrVec();
  InsertInstrTree(m, instrs);
  return instrs;
}

/******************************************************************************/
ExprPtr AbsKnob::Rewrite(const ExprPtr e, const ExprMap& rule) {
  auto func = FuncObjRewrExpr(rule);
  // rewrite all sub-trees
  e->DepthFirstVisitPrePost(func);
  // return rewrited/copied node
  auto rewr = func.get(e);
  ILA_ASSERT(rewr) << "Fail rewriting " << e;
  return rewr;
}

InstrLvlAbsPtr AbsKnob::ExtrDeptModl(const InstrPtr instr,
                                     const std::string& name) {
  ILA_NOT_NULL(instr);
  ILA_NOT_NULL(instr->host());

  auto h = instr->host();
  auto m = InstrLvlAbs::New(name);

  try { // Create new state/input variables in the new ILA.
    // TODO
  } catch (...) {
    ILA_ERROR << "Error in copy variables from " << h << " to " << m;
    return h;
  }

  try { // Rewrite ILA attributes, e.g. fetch, valid, etc.
    // TODO
  } catch (...) {
    ILA_ERROR << "Error in copying ILA attributes from " << h << " to " << m;
    return h;
  }

  // TODO child-program and sub-trees

  return m;
}

InstrLvlAbsPtr AbsKnob::CopyIlaTree(const InstrLvlAbsCnstPtr src,
                                    const std::string& dst_name) {
  ILA_NOT_NULL(src);

  auto dst = InstrLvlAbs::New(dst_name);
  dst->set_spec(src->is_spec());

  auto ila_map = CnstIlaMap({{src, dst}});
  auto expr_map = ExprMap();

  auto func = FuncObjRewrIla(ila_map, expr_map);
  src->DepthFirstVisitPrePost(func);

  return dst;
}

ExprPtr AbsKnob::DuplInp(const InstrLvlAbsPtr m, const ExprPtr inp) {
  ILA_ASSERT(inp->is_var()) << "Creating input from non-var Expr.";
  if (inp->is_bool()) {
    return m->NewBoolInput(inp->name().str());
  } else if (inp->is_bv()) {
    return m->NewBvInput(inp->name().str(), inp->sort()->bit_width());
  } else {
    ILA_ASSERT(inp->is_mem()) << "Unknown sort of " << inp;
    return m->NewMemInput(inp->name().str(), inp->sort()->addr_width(),
                          inp->sort()->data_width());
  }
}

ExprPtr AbsKnob::DuplStt(const InstrLvlAbsPtr m, const ExprPtr stt) {
  ILA_ASSERT(stt->is_var()) << "Creating state from non-var Expr.";
  if (stt->is_bool()) {
    return m->NewBoolState(stt->name().str());
  } else if (stt->is_bv()) {
    return m->NewBvState(stt->name().str(), stt->sort()->bit_width());
  } else {
    ILA_ASSERT(stt->is_mem()) << "Unkown sort of " << stt;
    return m->NewMemState(stt->name().str(), stt->sort()->addr_width(),
                          stt->sort()->data_width());
  }
}

void AbsKnob::DuplInp(const InstrLvlAbsCnstPtr src, const InstrLvlAbsPtr dst,
                      ExprMap& expr_map) {
  auto inps = AbsKnob::GetInp(src);
  for (auto it = inps.begin(); it != inps.end(); it++) {
    // declare new input if not exist (not parent states)
    auto inp_src = *it;
    auto inp_dst = dst->find_input(inp_src->name());
    if (!inp_dst) { // not exist --> child-input --> create
      inp_dst = DuplInp(dst, inp_src);
    }
    // update rewrite rule
    if (expr_map.find(inp_src) == expr_map.end()) {
      expr_map.insert({inp_src, inp_dst});
    }
  }
}

void AbsKnob::DuplStt(const InstrLvlAbsCnstPtr src, const InstrLvlAbsPtr dst,
                      ExprMap& expr_map) {
  auto stts = AbsKnob::GetStt(src);
  for (auto it = stts.begin(); it != stts.end(); it++) {
    auto stt_src = *it;
    auto stt_dst = dst->find_state(stt_src->name());
    if (!stt_dst) { // not exist --> child-state --> create
      stt_dst = DuplStt(dst, stt_src);
    }
    // update rewrite rule
    if (expr_map.find(stt_src) == expr_map.end()) {
      expr_map.insert({stt_src, stt_dst});
    }
  }
}

} // namespace ila

