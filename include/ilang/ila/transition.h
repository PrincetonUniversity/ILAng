/// \file
/// Header for the class InstrTran, InstrTranGraph, and InstrSeq

#ifndef ILANG_ILA_TRANSITION_H__
#define ILANG_ILA_TRANSITION_H__

#include <ilang/ila/instr.h>

/// \namespace ilang
namespace ilang {

/// \brief Instruction transition edge, includeing:
/// - "src": source instruction
/// - "dst": target instruction
/// - "cnd": guard (transition condition)
class InstrTranEdge {
public:
  /// Pointer type for passing around the InstrTran.
  typedef std::shared_ptr<InstrTranEdge> ItEdgePtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with all components.
  InstrTranEdge(const InstrPtr& src, const InstrPtr& dst, const ExprPtr& cnd);
  /// Default destructor.
  ~InstrTranEdge();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the source instruction.
  const InstrPtr src() const;
  /// Return the target instruction.
  const InstrPtr dst() const;
  /// Return the guarded transition condition.
  const ExprPtr cnd() const;

private:
  /// Source instruction, the starting point of the transition.
  InstrPtr src_;
  /// Target instruction, the ending/destination point of the transition.
  InstrPtr dst_;
  /// Transition condition for the guarded transition.
  ExprPtr cnd_;

}; // class InstrTranEdge

/// \brief Node for instruction-transition node, each node represent an
/// instruction.
class InstrTranNode {
public:
  /// Pointer type for ITNode.
  typedef std::shared_ptr<InstrTranNode> ItNodePtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  InstrTranNode(const InstrPtr& instr);
  /// Default destructir.
  ~InstrTranNode();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the represented instruction.
  const InstrPtr instr() const;

  /// Return the number of out-going node.
  size_t next_num() const;
  /// Return the number of in-comming node.
  size_t prev_num() const;

  /// Access the i-th out-going node.
  const ItNodePtr next(const size_t& i) const;
  /// Access the i-th in-comming node.
  const ItNodePtr prev(const size_t& i) const;

  // ------------------------- METHODS -------------------------------------- //
  /// Update the set of out-going node.
  void AddNext(const ItNodePtr& next);
  /// Update the set of in-comming node.
  void AddPrev(const ItNodePtr& prev);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The represented instruction.
  InstrPtr instr_;
  /// The set of out-going node.
  std::vector<ItNodePtr> next_;
  /// The set of out-going node.
  std::vector<ItNodePtr> prev_;

}; // class InstrTranNode

/// \brief Instruction Sequencing does:
/// - maintain the set of transition edges
/// - construct the graph (should be single thread of control)
/// - perform checks on the transition
/// - sort the instructions based on the transition.
class InstrSeq {
public:
  /// Pointer type for passing around InstrSeq.
  typedef std::shared_ptr<InstrSeq> InstrSeqPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  InstrSeq();
  /// Default destructor.
  ~InstrSeq();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Reset all stored sequences.
  void clear();

  // ------------------------- HELPERS -------------------------------------- //
  /// Create a new ITG, used for hiding implementation specific types.
  static InstrSeqPtr New();

  // ------------------------- METHODS -------------------------------------- //
  /// Add one transition to the set.
  void AddTran(const InstrPtr& src, const InstrPtr& dst, const ExprPtr& cnd);

  /// Set the root node (entry instruction).
  void set_root(const InstrPtr& i);

  /// Return the root node (entry instruction).
  InstrPtr root() const { return root_; }

private:
  /// Pointer type for passing around InstrTranEdge.
  typedef InstrTranEdge::ItEdgePtr ItEdgePtr;
  /// Pointer type for passing around InstrTranNode.
  typedef InstrTranNode::ItNodePtr ItNodePtr;

  // ------------------------- MEMBERS -------------------------------------- //
  /// The root node (instruction).
  InstrPtr root_ = nullptr;
  /// The set of transition relations (edges).
  std::set<ItEdgePtr> edges_;
  /// The instruction to node mapping.
  std::map<InstrPtr, ItNodePtr> nodes_;

}; // class InstrSeq

/// Pointer type for passing around InstrSeq.
typedef InstrSeq::InstrSeqPtr InstrSeqPtr;

} // namespace ilang

#endif // ILANG_ILA_TRANSITION_H__
