/// \file
/// Source for function object for rewriting ILA.

#include "backend/rewrite_ila.h"
#include "backend/abs_knob.h"

namespace ila {

InstrLvlAbsPtr FuncObjRewrIla::get(const InstrLvlAbsCnstPtr m) const {
  auto pos = ila_map_.find(m);
  ILA_ASSERT(pos != ila_map_.end()) << m << " not found";
  return pos->second;
}

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
    ila_map_.insert({c_src, c_dst});
  }

  // fetch
  AbsKnob::DuplFetch(src, dst, expr_map_);
  // valid
  AbsKnob::DuplValid(src, dst, expr_map_);
  // init
  AbsKnob::DuplInit(src, dst, expr_map_);

  // instruction && child-program
  for (decltype(src->instr_num()) i = 0; i != src->instr_num(); i++) {
    auto i_src = src->instr(i);
    AbsKnob::DuplInstr(i_src, dst, expr_map_, ila_map_);
  }

  // sequence
  // TODO

  return false;
}

void FuncObjRewrIla::post(const InstrLvlAbsCnstPtr src) const {
  // nothing
}

} // namespace ila

