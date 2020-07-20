/// \file
/// Source of instruction sequencing

#include <ilang/ila/transition.h>

#include <ilang/util/log.h>

namespace ilang {

// ------------------------- InstrTranEdge ---------------------------------- //
// typedef InstrTranEdge::ItEdgePtr ItEdgePtr;

InstrTranEdge::InstrTranEdge(const InstrPtr& src, const InstrPtr& dst,
                             const ExprPtr& cnd)
    : src_(src), dst_(dst), cnd_(cnd) {}

InstrTranEdge::~InstrTranEdge() {}

const InstrPtr InstrTranEdge::src() const { return src_; }

const InstrPtr InstrTranEdge::dst() const { return dst_; }

const ExprPtr InstrTranEdge::cnd() const { return cnd_; }

// ------------------------- InstrTranNode ---------------------------------- //
typedef InstrTranNode::ItNodePtr ItNodePtr;

InstrTranNode::InstrTranNode(const InstrPtr& instr) : instr_(instr) {
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
  ILA_ASSERT(i < next_.size()) << "Access overflow for out-going nodes.";
  return next_.at(i);
}

const ItNodePtr InstrTranNode::prev(const size_t& i) const {
  ILA_ASSERT(i < prev_.size()) << "Access overflow for in-comming nodes.";
  return prev_.at(i);
}

void InstrTranNode::AddNext(const ItNodePtr& next) { next_.push_back(next); }

void InstrTranNode::AddPrev(const ItNodePtr& prev) { prev_.push_back(prev); }

// ------------------------- InstrSeq --------------------------------------- //

InstrSeq::InstrSeq() { clear(); }

InstrSeq::~InstrSeq() { clear(); }

void InstrSeq::clear() {
  edges_.clear();
  nodes_.clear();
}

InstrSeqPtr InstrSeq::New() { return std::make_shared<InstrSeq>(); }

void InstrSeq::AddTran(const InstrPtr& src, const InstrPtr& dst,
                       const ExprPtr& cnd) {
  // update edges
  auto edge = std::make_shared<InstrTranEdge>(src, dst, cnd);
  edges_.insert(edge);

  // update nodes
  ItNodePtr src_node = nullptr;
  ItNodePtr dst_node = nullptr;

  auto src_it = nodes_.find(src);
  if (src_it == nodes_.end()) { // instr first seen
    src_node = std::make_shared<InstrTranNode>(src);
    nodes_.emplace(src, src_node);
  } else { // instr exists
    src_node = src_it->second;
  }

  auto dst_it = nodes_.find(dst);
  if (dst_it == nodes_.end()) { // instr first seen
    dst_node = std::make_shared<InstrTranNode>(dst);
    nodes_.emplace(dst, dst_node);
  } else { // instr exists
    dst_node = dst_it->second;
  }

  src_node->AddNext(dst_node);
  dst_node->AddPrev(src_node);
}

void InstrSeq::set_root(const InstrPtr& i) {
  ILA_WARN_IF(root_) << "Overwriting root node " << root_ << " to " << i;
  root_ = i;
}

} // namespace ilang
