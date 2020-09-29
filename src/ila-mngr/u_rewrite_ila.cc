/// \file
/// Function objects for rewriting an ILA.

#include <ilang/ila-mngr/u_rewriter.h>

#include <ilang/ila-mngr/u_abs_knob.h>
#include <ilang/util/log.h>

// enforce parent valid condition on child-decode
#define VALID_STACK
#undef VALID_STACK

namespace ilang {

InstrLvlAbsPtr FuncObjRewrIla::get(const InstrLvlAbsCnstPtr& m) const {
  auto pos = ila_map_.find(m);
  ILA_CHECK(pos != ila_map_.end()) << m << " not found";
  return pos->second;
}

bool FuncObjRewrIla::pre(const InstrLvlAbsCnstPtr& src) {
  auto pos = ila_map_.find(src);
  ILA_ASSERT(pos != ila_map_.end()) << "ILA dst for " << src << " not found.";
  auto dst = pos->second;
  ILA_ASSERT(dst->state_num() ==
             (dst->parent() ? dst->parent()->state_num() : 0))
      << "Rewriting ILA to partially constructed ILA not support.";

  // input
  absknob::DuplInp(src, dst, expr_map_);
  // state
  absknob::DuplStt(src, dst, expr_map_);

  // child
  for (decltype(src->child_num()) i = 0; i != src->child_num(); i++) {
    auto c_src = src->child(i);
    auto c_dst = dst->NewChild(c_src->name().str());
    c_dst->set_spec(c_src->is_spec());
    ila_map_.insert({c_src, c_dst});
  }

  // fetch
  absknob::DuplFetch(src, dst, expr_map_);
  // valid
  absknob::DuplValid(src, dst, expr_map_);
  // init
  absknob::DuplInit(src, dst, expr_map_);

  // instruction && child-program
  for (decltype(src->instr_num()) i = 0; i != src->instr_num(); i++) {
    auto i_src = src->instr(i);
    absknob::DuplInstr(i_src, dst, expr_map_, ila_map_);
  }

  // sequence
  absknob::DuplInstrSeq(src, dst);

  return false;
}

void FuncObjRewrIla::post(const InstrLvlAbsCnstPtr& src) const {
  // nothing
}

/// Constructor.
FuncObjFlatIla::FuncObjFlatIla(const InstrLvlAbsCnstPtr& top_,
                               const IlaMap& ila_map, const ExprMap& expr_map)
    : ila_map_(ila_map), expr_map_(expr_map), top_ila_(top_) {
#ifdef VALID_STACK
  valid_cond_stack_.push(asthub::BoolConst(true));
#endif // VALID_STACK
}

bool FuncObjFlatIla::pre(const InstrLvlAbsCnstPtr& src) {
  if (src == top_ila_)
    return false; // skip the top level ila, do nothing
  auto pos = ila_map_.find(src);
  ILA_ASSERT(pos != ila_map_.end()) << "ILA dst for " << src << " not found.";
  auto dst = pos->second;

  auto valid_cond_ = src->valid();
  if (!valid_cond_) {
    ILA_WARN << "valid condition for " << src << " is unset";
    valid_cond_ = asthub::BoolConst(true);
  }
#ifdef VALID_STACK
  valid_cond_ = absknob::Rewrite(valid_cond_, expr_map_);
  valid_cond_stack_.push(asthub::And(valid_cond_stack_.top(), valid_cond_));
  const auto& hierarchical_valid_cond = valid_cond_stack_.top();
#endif // VALID_STACK

  // instruction && child-program
  for (decltype(src->instr_num()) i = 0; i != src->instr_num(); i++) {
    auto i_src = src->instr(i);
    auto i_dst = absknob::DuplInstr(i_src, dst, expr_map_, ila_map_);
#ifdef VALID_STACK
    auto new_decode = asthub::And(i_dst->decode(), hierarchical_valid_cond);
    i_dst->ForceSetDecode(new_decode);
#endif // VALID_STACK
  }

  // sequence - do we need to do this?
  // absknob::DuplInstrSeq(src, dst);

  return false;
}

void FuncObjFlatIla::post(const InstrLvlAbsCnstPtr& src) {
  // pop the stack
#ifdef VALID_STACK
  valid_cond_stack_.pop();
#endif // VALID_STACK
}

} // namespace ilang
