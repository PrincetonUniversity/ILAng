/// \file
/// Source for function object for rewriting ILA.

#include <ilang/util/log.h>
#include <ilang/verification/abs_knob.h>
#include <ilang/verification/rewrite_ila.h>

namespace ilang {

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
  AbsKnob::DuplInstrSeq(src, dst);

  return false;
}

void FuncObjRewrIla::post(const InstrLvlAbsCnstPtr src) const {
  // nothing
}

// -----------------------------------------------------------------------------------------

/// Constructor.
FuncObjFlatIla::FuncObjFlatIla(const InstrLvlAbsCnstPtr& top_,
                               const IlaMap& ila_map, const ExprMap& expr_map)
    : ila_map_(ila_map), expr_map_(expr_map), top_ila_(top_) {
  valid_cond_stack_.push(ExprFuse::BoolConst(true));
}

bool FuncObjFlatIla::pre(const InstrLvlAbsCnstPtr src) {
  if (src == top_ila_)
    return false; // skip the top level ila, do nothing
  auto pos = ila_map_.find(src);
  ILA_ASSERT(pos != ila_map_.end()) << "ILA dst for " << src << " not found.";
  auto dst = pos->second;

  auto valid_cond_ = src->valid();
  if (!valid_cond_) {
    ILA_WARN << "valid condition for " << src << " is unset";
    valid_cond_ = ExprFuse::BoolConst(true);
  }
  valid_cond_stack_.push(ExprFuse::And(valid_cond_stack_.top(), valid_cond_));
  const auto& hierarchical_valid_cond = valid_cond_stack_.top();

  // instruction && child-program
  for (decltype(src->instr_num()) i = 0; i != src->instr_num(); i++) {
    auto i_src = src->instr(i);
    auto i_dst = AbsKnob::DuplInstr(i_src, dst, expr_map_, ila_map_);
    auto new_decode = ExprFuse::And(i_dst->decode(), hierarchical_valid_cond);
  }

  // sequence - do we need to do this?
  // AbsKnob::DuplInstrSeq(src, dst);

  return false;
}

void FuncObjFlatIla::post(const InstrLvlAbsCnstPtr src) {
  // pop the stack
  valid_cond_stack_.pop();
}

} // namespace ilang
