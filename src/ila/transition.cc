/// \file
/// Source of instruction sequencing

#include "ila/transition.h"
#include "util/log.h"

namespace ila {

// ------------------------- InstrTranEdge ---------------------------------- //
InstrTranEdge::InstrTranEdge(const InstrPtr src, const InstrPtr dst,
                             const ExprPtr cnd)
    : src_(src), dst_(dst), cnd_(cnd) {}

InstrTranEdge::~InstrTranEdge() {}

const InstrPtr InstrTranEdge::src() const { return src_; }

const InstrPtr InstrTranEdge::dst() const { return dst_; }

const ExprPtr InstrTranEdge::cnd() const { return cnd_; }

// ------------------------- InstrTranNode ---------------------------------- //
typedef InstrTranNode::ItNodePtr ItNodePtr;

InstrTranNode::InstrTranNode(const InstrPtr instr) : instr_(instr) {
  next_.clear();
  prev_.clear();
}

InstrTranNode::~InstrTranNode() {
  next_.clear();
  prev_.clear();
}

const InstrPtr InstrTranNode::instr() const { return instr_; }

size_t InstrTranNode::next_num() const { return next_.size(); }

size_t InstrTranNode::prev_num() const { return prev_.size(); }

const ItNodePtr InstrTranNode::next(const size_t& i) const {
  ILA_ASSERT(i < next_.size()) << "Access overflow for out-going nodes.\n";
  return next_[i];
}

const ItNodePtr InstrTranNode::prev(const size_t& i) const {
  ILA_ASSERT(i < prev_.size()) << "Access overflow for in-comming nodes.\n";
  return prev_[i];
}

void InstrTranNode::AddNext(const ItNodePtr next) { next_.push_back(next); }

void InstrTranNode::AddPrev(const ItNodePtr prev) { prev_.push_back(prev); }

// ------------------------- InstrSeq --------------------------------------- //
typedef InstrSeq::InstrIdxKeyVec InstrIdxKeyVec;
typedef InstrSeq::InstrIdxKeyVecPtr InstrIdxKeyVecPtr;

InstrSeq::InstrSeq() {
  edges_.clear();
  nodes_.clear();
  sorted_ = std::make_shared<InstrIdxKeyVec>();
}

InstrSeq::~InstrSeq() {}

InstrSeqPtr InstrSeq::New() { return std::make_shared<InstrSeq>(); }

void InstrSeq::AddTran(const InstrPtr src, const InstrPtr dst,
                       const ExprPtr cnd) {
  // TODO
}

bool InstrSeq::CheckTransition() const {
  // TODO
  return true;
}

InstrIdxKeyVecPtr InstrSeq::Sort() {
  // ILA_ASSERT(sorted_->empty());
  // TODO
  return sorted_;
}

} // namespace ila

