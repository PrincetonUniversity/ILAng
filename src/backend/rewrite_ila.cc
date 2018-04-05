/// \file
/// Source for function object for rewriting ILA.

#include "backend/rewrite_ila.h"
#include "backend/abs_knob.h"

namespace ila {

// create state
// create child
// instruction & child-program
bool FuncObjRewrIla::pre(const InstrLvlAbsCnstPtr src) {
  auto pos = ila_map_.find(src);
  ILA_ASSERT(pos != ila_map_.end()) << "ILA dst for " << src << " not found.";
  auto dst = pos->second;
  ILA_ASSERT(dst->state_num() ==
             (dst->parent() ? dst->parent()->state_num() : 0))
      << "Rewriting ILA to partially constructed ILA not support.";

  // input
  AbsKnob::DuplInp(src, dst, expr_map_);
  // state
  AbsKnob::DuplStt(src, dst, expr_map_);

  // child
  for (decltype(src->child_num()) i = 0; i != src->child_num(); i++) {
    auto c_src = src->child(i);
    auto c_dst = dst->NewChild(c_src->name().str());
    c_dst->set_spec(c_src->is_spec());
    UpdtIla(c_src, c_dst);
  }

  // fetch
  auto f_src = src->fetch();
  auto f_dst = AbsKnob::Rewrite(f_src, expr_map_);
  dst->SetFetch(f_dst);

  // valid
  auto v_src = src->valid();
  auto v_dst = AbsKnob::Rewrite(v_src, expr_map_);
  dst->SetValid(v_dst);

  // init
  for (decltype(src->init_num()) i = 0; i != src->init_num(); i++) {
    auto i_src = src->init(i);
    auto i_dst = AbsKnob::Rewrite(i_src, expr_map_);
    dst->AddInit(i_dst);
  }

  // instruction && child-program
  for (decltype(src->instr_num()) i = 0; i != src->instr_num(); i++) {
    // create
    auto i_src = src->instr(i);
    auto i_dst = dst->NewInstr(i_src->name().str());
    // rewrite
    RewriteInstr(i_src, i_dst);
    // child-program
    // TODO
  }

  // sequence
  // TODO

  return false;
}

void FuncObjRewrIla::post(const InstrLvlAbsCnstPtr src) const {
  // nothing
}

#if 0
void FuncObjRewrIla::ImitateInput(const InstrLvlAbsCnstPtr src,
                                  const InstrLvlAbsPtr dst) {
  auto inps = AbsKnob::GetInp(src);
  for (auto it = inps.begin(); it != inps.end(); it++) {
    // declare new input if not exist (not parent states)
    auto inp_src = *it;
    auto inp_dst = dst->find_input(inp_src->name());
    if (!inp_dst) { // not exist --> child-input --> create
      inp_dst = NewInput(dst, inp_src);
    }
    // update rewrite rule
    UpdtExpr(inp_src, inp_dst);
  }
}

void FuncObjRewrIla::ImitateState(const InstrLvlAbsCnstPtr src,
                                  const InstrLvlAbsPtr dst) {
  auto stts = AbsKnob::GetStt(src);
  for (auto it = stts.begin(); it != stts.end(); it++) {
    auto stt_src = *it;
    auto stt_dst = dst->find_state(stt_src->name());
    if (!stt_dst) { // not exist --> child-state --> create
      stt_dst = NewState(dst, stt_src);
    }
    // update rewrite rule
    UpdtExpr(stt_src, stt_dst);
  }
}

ExprPtr FuncObjRewrIla::NewInput(const InstrLvlAbsPtr m, const ExprPtr inp) {
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

ExprPtr FuncObjRewrIla::NewState(const InstrLvlAbsPtr m, const ExprPtr stt) {
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
#endif

void FuncObjRewrIla::RewriteInstr(const InstrCnstPtr src, const InstrPtr dst) {
  // decode
  auto d_src = src->decode();
  auto d_dst = AbsKnob::Rewrite(d_src, expr_map_);
  dst->set_decode(d_dst);

  // update
  for (auto it = expr_map_.begin(); it != expr_map_.end(); it++) {
    // state
    auto s_src = it->first;
    auto s_dst = it->second;
    // update function
    auto u_src = src->update(s_src);
    if (u_src) {
      auto u_dst = AbsKnob::Rewrite(u_src, expr_map_);
      dst->set_update(s_dst, u_dst);
    }
  }
}

} // namespace ila

