/// \file
/// A collection of ILA helpers.

#include <ilang/ila-mngr/u_abs_knob.h>

#include <ilang/ila-mngr/u_rewriter.h>
#include <ilang/util/log.h>

namespace ilang {

namespace absknob {

ExprPtr DuplInp(const InstrLvlAbsPtr& m, const ExprPtr& inp) {
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

ExprPtr DuplStt(const InstrLvlAbsPtr& m, const ExprPtr& stt) {
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

class FuncObjInsertExprVar {
public:
  FuncObjInsertExprVar(ExprSet& vars) : vars_(vars) {}

  void operator()(const ExprPtr& e) const {
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

  void operator()(const InstrLvlAbsCnstPtr& m) const { InsertInp(m, vars_); }

private:
  ExprSet& vars_;
}; // class FuncObjInsertILAStt

class FuncObjInsertILAStt {
public:
  FuncObjInsertILAStt(ExprSet& vars) : vars_(vars) {}

  void operator()(const InstrLvlAbsCnstPtr& m) const { InsertStt(m, vars_); }

private:
  ExprSet& vars_;
}; // class FuncObjInsertILAStt

class FuncObjInsertILAInstr {
public:
  FuncObjInsertILAInstr(InstrVec& instrs) : instrs_(instrs) {}

  void operator()(const InstrLvlAbsCnstPtr& m) const {
    InsertInstr(m, instrs_);
  }

private:
  InstrVec& instrs_;

}; // class FuncOjbInsertILAInstr

/******************************************************************************/
ExprSet GetVar(const ExprPtr& e) {
  auto vars = ExprSet();
  auto func = FuncObjInsertExprVar(vars);
  e->DepthFirstVisit(func);
  return vars;
}

/******************************************************************************/
void InsertStt(const InstrCnstPtr instr, ExprSet& vars) {
  auto host = instr->host();
  ILA_NOT_NULL(host);
  InsertStt(host, vars);
}

void InsertSttTree(const InstrCnstPtr instr, ExprSet& vars) {
  auto host = instr->host();
  ILA_NOT_NULL(host);
  InsertSttTree(host, vars);
}

/******************************************************************************/
void InsertVar(const InstrLvlAbsCnstPtr& m, ExprSet& vars) {
  InsertStt(m, vars);
  InsertInp(m, vars);
}

void InsertStt(const InstrLvlAbsCnstPtr& m, ExprSet& stts) {
  for (decltype(m->state_num()) i = 0; i != m->state_num(); i++) {
    stts.insert(m->state(i));
  }
}

void InsertInp(const InstrLvlAbsCnstPtr& m, ExprSet& inps) {
  for (decltype(m->input_num()) i = 0; i != m->input_num(); i++) {
    inps.insert(m->input(i));
  }
}

void InsertVarTree(const InstrLvlAbsCnstPtr& top, ExprSet& vars) {
  InsertSttTree(top, vars);
  InsertInpTree(top, vars);
}

void InsertSttTree(const InstrLvlAbsCnstPtr& top, ExprSet& stts) {
  auto f = FuncObjInsertILAStt(stts);
  top->DepthFirstVisit(f);
}

void InsertInpTree(const InstrLvlAbsCnstPtr& top, ExprSet& inps) {
  auto f = FuncObjInsertILAInp(inps);
  top->DepthFirstVisit(f);
}

ExprSet GetVar(const InstrLvlAbsCnstPtr& m) {
  auto vars = ExprSet();
  InsertVar(m, vars);
  return vars;
}

ExprSet GetStt(const InstrLvlAbsCnstPtr& m) {
  auto stts = ExprSet();
  InsertStt(m, stts);
  return stts;
}

ExprSet GetInp(const InstrLvlAbsCnstPtr& m) {
  auto inps = ExprSet();
  InsertInp(m, inps);
  return inps;
}

ExprSet GetVarTree(const InstrLvlAbsCnstPtr& top) {
  auto vars = ExprSet();
  InsertVarTree(top, vars);
  return vars;
}

ExprSet GetSttTree(const InstrLvlAbsCnstPtr& top) {
  auto stts = ExprSet();
  InsertSttTree(top, stts);
  return stts;
}

ExprSet GetInpTree(const InstrLvlAbsCnstPtr& top) {
  auto inps = ExprSet();
  InsertInp(top, inps);
  return inps;
}

void InsertInstr(const InstrLvlAbsCnstPtr& m, InstrVec& instrs) {
  for (decltype(m->instr_num()) i = 0; i != m->instr_num(); i++) {
    instrs.insert(instrs.end(), m->instr(i));
  }
}

InstrVec GetInstr(const InstrLvlAbsCnstPtr& m) {
  auto instrs = InstrVec();
  InsertInstr(m, instrs);
  return instrs;
}

void InsertInstrTree(const InstrLvlAbsCnstPtr& top, InstrVec& instrs) {
  auto f = FuncObjInsertILAInstr(instrs);
  top->DepthFirstVisit(f);
}

InstrVec GetInstrTree(const InstrLvlAbsCnstPtr& m) {
  auto instrs = InstrVec();
  InsertInstrTree(m, instrs);
  return instrs;
}

/******************************************************************************/
ExprPtr Rewrite(const ExprPtr& e, const ExprMap& rule) {
  ILA_ASSERT(e) << "Rewriting NULL pointer";
  auto func = FuncObjRewrExpr(rule);
  // rewrite all sub-trees
  e->DepthFirstVisitPrePost(func);
  // return rewrited/copied node
  auto rewr = func.get(e);
  ILA_ASSERT(rewr) << "Fail rewriting " << e;
  return rewr;
}

void RewriteInstr(const InstrCnstPtr src, const InstrPtr& dst,
                  const ExprMap& expr_map) {
  // decode
  auto d_src = src->decode();
  auto d_dst = Rewrite(d_src, expr_map);
  dst->set_decode(d_dst);

  // update
  for (const auto& state : src->updated_states()) {
    auto update_src = src->update(state);
    auto update_dst = Rewrite(update_src, expr_map);
    dst->set_update(state, update_dst);
  }
}

// this function will change the input ! You can copy it first.
void FlattenIla(const InstrLvlAbsPtr& ila_ptr_) {
  ILA_NOT_NULL(ila_ptr_);
  ILA_INFO << "Flatten " << ila_ptr_;

  // let's first record all the child's input/states
  auto expr_map = ExprMap();
  CnstIlaMap ila_map_;

  auto recordInpStates = [&](const InstrLvlAbsCnstPtr& a) {
    if (a == ila_ptr_)
      return; // will not change the top

    DuplInp(a, ila_ptr_, expr_map);
    DuplStt(a, ila_ptr_, expr_map);
    DuplInit(a, ila_ptr_, expr_map);

    ila_map_.insert({a, ila_ptr_});
    // remember to change the decode !!! to factor in the valid state
  };

  ila_ptr_->DepthFirstVisit(recordInpStates);

  FuncObjFlatIla flattener(ila_ptr_, ila_map_, expr_map);
  ila_ptr_->DepthFirstVisitPrePost(flattener);
}

InstrLvlAbsPtr ExtrDeptModl(const InstrPtr& instr, const std::string& name) {
  ILA_NOT_NULL(instr);
  ILA_NOT_NULL(instr->host());

  auto src = instr->host();
  auto dst = InstrLvlAbs::New(name);

  auto expr_map = ExprMap();

  try { // Create new state/input variables in the new ILA.
    DuplInp(src, dst, expr_map);
    DuplStt(src, dst, expr_map);
    DuplFetch(src, dst, expr_map);
    DuplValid(src, dst, expr_map);
    DuplInit(src, dst, expr_map);
    DuplInstrSeq(src, dst);
  } catch (...) {
    ILA_ERROR << "Error in duplicating attr. from " << src << " to " << dst;
    return src;
  }

  auto ila_map = CnstIlaMap({{src, dst}});
  // target instruction, child-ILAs
  auto prog_src = instr->program();
  if (prog_src) { // duplicate child-ILA
    auto prog_dst = dst->NewChild(prog_src->name().str());
    ila_map.insert({prog_src, prog_dst});

    auto func = FuncObjRewrIla(ila_map, expr_map);
    try {
      prog_src->DepthFirstVisitPrePost(func);
    } catch (...) {
      ILA_ERROR << "Error in duplicating child-program " << prog_src;
    }
  }

  // duplicate instruction
  DuplInstr(instr, dst, expr_map, ila_map);

  return dst;
}

InstrLvlAbsPtr CopyIlaTree(const InstrLvlAbsCnstPtr& src,
                           const std::string& dst_name) {
  ILA_NOT_NULL(src);
  ILA_WARN_IF(src->parent()) << "Copying non-root ILA " << src;

  auto dst = InstrLvlAbs::New(dst_name);
  dst->set_spec(src->is_spec());

  auto ila_map = CnstIlaMap({{src, dst}});
  auto expr_map = ExprMap();

  auto func = FuncObjRewrIla(ila_map, expr_map);
  src->DepthFirstVisitPrePost(func);

  return dst;
}

/******************************************************************************/
void DuplInp(const InstrLvlAbsCnstPtr& src, const InstrLvlAbsPtr& dst,
             ExprMap& expr_map) {
  for (const auto& inp_src : GetInp(src)) {
    // declare new input if not exist (not parent states)
    auto inp_dst = dst->find_input(inp_src->name());
    if (!inp_dst) { // not exist --> child-input --> create
      inp_dst = DuplInp(dst, inp_src);
    }
    // update rewrite rule
    expr_map.try_emplace(inp_src, inp_dst);
  }
}

void DuplStt(const InstrLvlAbsCnstPtr& src, const InstrLvlAbsPtr& dst,
             ExprMap& expr_map) {
  for (const auto& stt_src : GetStt(src)) {
    auto stt_dst = dst->find_state(stt_src->name());
    if (!stt_dst) { // not exist --> child-state --> create
      stt_dst = DuplStt(dst, stt_src);
    }
    // update rewrite rule
    expr_map.try_emplace(stt_src, stt_dst);
  }
}

ExprPtr DuplFetch(const InstrLvlAbsCnstPtr& src, const InstrLvlAbsPtr& dst,
                  const ExprMap& expr_map) {
  auto f_src = src->fetch();
  if (!f_src) {
    ILA_WARN << "Fetch not set for " << src;
    return nullptr;
  }
  auto f_dst = Rewrite(f_src, expr_map);
  dst->SetFetch(f_dst);
  return f_dst;
}

ExprPtr DuplValid(const InstrLvlAbsCnstPtr& src, const InstrLvlAbsPtr& dst,
                  const ExprMap& expr_map) {
  auto v_src = src->valid();
  if (!v_src) {
    ILA_WARN << "Valid not set for " << src;
    return nullptr;
  }
  auto v_dst = Rewrite(v_src, expr_map);
  dst->SetValid(v_dst);
  return v_dst;
}

void DuplInit(const InstrLvlAbsCnstPtr& src, const InstrLvlAbsPtr& dst,
              const ExprMap& expr_map) {
  for (decltype(src->init_num()) i = 0; i != src->init_num(); i++) {
    auto i_src = src->init(i);
    auto i_dst = Rewrite(i_src, expr_map);
    dst->AddInit(i_dst);
  }
}

InstrPtr DuplInstr(const InstrCnstPtr i_src, const InstrLvlAbsPtr& dst,
                   const ExprMap& expr_map, const CnstIlaMap& ila_map) {
  // create
  auto i_dst = dst->NewInstr(i_src->name().str());
  // rewrite
  RewriteInstr(i_src, i_dst, expr_map);
  // connect child-program
  auto p_src = i_src->program();
  if (p_src) {
    auto pos = ila_map.find(p_src);
    ILA_ASSERT(pos != ila_map.end())
        << "Child-program " << p_src << " not mapped.";
    auto p_dst = pos->second;
    i_dst->set_program(p_dst);
  }
  return i_dst;
}

void DuplInstrSeq(const InstrLvlAbsCnstPtr& src, const InstrLvlAbsPtr& dst) {
  // ILA_WARN << "DuplInstrSeq not implemented yet.";
  // TODO
}

} // namespace absknob

} // namespace ilang
