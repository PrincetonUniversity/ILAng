/// \file
/// Header for the refinement relation

#ifndef COMP_REF_REL_H__
#define COMP_REF_REL_H__

#include <ilang/ila/instr_lvl_abs.h>

/// \namespace ilang
namespace ilang {

/// \brief Refinement mapping defines how to map micro-architectural states to
/// architectural states for comparison.
/// - Standard flushing refinement operation (stall in the Birch/Dill paper)
/// - Support dummy end child-instruction (commit point)
/// - Support specifying number of steps
class RefinementMap {
public:
  /// Pointer type for passing around the refinement mapping.
  typedef std::shared_ptr<RefinementMap> RefPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  RefinementMap();
  /// Default destructor.
  ~RefinementMap();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the target (top-ILA containing the COI).
  inline InstrLvlAbsPtr coi() const { return coi_; }
  /// Return the target (top-ILA).
  inline InstrLvlAbsPtr ila() const { return coi_; }
  /// Return the apply function.
  inline ExprPtr appl() const { return appl_; }
  /// Return the constraint for flushing (stall).
  inline ExprPtr flush() const { return flush_; }
  /// Return the constraint for completion indicator.
  inline ExprPtr cmpl() const { return cmpl_; }
  /// Return the number of steps required for flushing apply path.
  inline const int& step_appl() const { return step_appl_; }
  /// Return the number of steps required for flushing original path.
  inline const int& step_orig() const { return step_orig_; }
  /// Return the number of steps required for flushing. XXX
  inline const int& step() const { return step_orig(); }
  /// Return the number of invariant.
  inline size_t inv_num() const { return invs_.size(); }
  /// Access the i-th invariant.
  inline ExprPtr inv(const size_t& i) const { return invs_.at(i); }

  /// Define the target ILA (source for coi).
  void set_tgt(const InstrLvlAbsPtr tgt);
  /// Define the target instruction (source for coi).
  void set_tgt(const InstrPtr tgt);
  /// Define the apply function.
  void set_appl(const ExprPtr appl);
  /// Define the flushing function.
  void set_flush(const ExprPtr flush);
  /// Define the completion scenario (e.g. dummy end).
  void set_cmpl(const ExprPtr cmpl);
  /// Specify the number of steps required for flushing. XXX
  inline void set_step(const int& step) { set_step_orig(step); }
  /// Specify the number of steps required for flushing apply path.
  void set_step_appl(const int& step);
  /// Specify the number of steps required for flushing original path.
  void set_step_orig(const int& step);
  /// Add an invariant.
  void add_inv(const ExprPtr inv);

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new refinement mapping. Used for hiding implementation
  /// specific type details.
  static RefPtr New();

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Cone-of-influence (as an ILA).
  InstrLvlAbsPtr coi_ = NULL;
  /// Apply function.
  ExprPtr appl_ = NULL;
  /// Flushing function.
  ExprPtr flush_ = NULL;
  /// Completion indicator.
  ExprPtr cmpl_ = ExprFuse::BoolConst(true);
  /// Number of steps for flushing apply path.
  int step_appl_ = -1;
  /// Number of steps for flushing original path.
  int step_orig_ = -1;
  /// A set of invariant.
  std::vector<ExprPtr> invs_;

}; // RefinementMap

/// Pointer type for passing around the refinement mapping.
typedef RefinementMap::RefPtr RefPtr;

/// \brief Relation mapping defines how arch states of two models are mapped,
/// i.e., state mapping.
class RelationMap {
public:
  /// Pointer type for passing around the relation mapping.
  typedef std::shared_ptr<RelationMap> RelPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  RelationMap();
  /// Default destructor.
  ~RelationMap();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Add one relation.
  void add(const ExprPtr rel);
  /// Return the conjuncted (ANDed) relation.
  inline ExprPtr get() const { return acc_; }

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new relation mapping. Used for hiding implementation
  /// specific type details.
  static RelPtr New();

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Cached output for conjuncting all relations.
  ExprPtr acc_ = ExprFuse::BoolConst(true);

}; // RelationMap

/// Pointer type for passing around the relation mapping.
typedef RelationMap::RelPtr RelPtr;

/// \brief Compositional refinement relation defines a unit (element for the
/// composition) of refinement relation, which specifies
/// - how to start (apply function),
/// - what to compare (relation), and
/// - when to check (refinement).
class CompRefRel {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Pointer type for passing around the compositional relation mapping.
  typedef std::shared_ptr<CompRefRel> CrrPtr;

  /// Default constructor.
  CompRefRel(const RefPtr ref_a, const RefPtr ref_b, const RelPtr rel);
  /// Default destructor.
  ~CompRefRel();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the refinement for model A.
  inline RefPtr refine_a() const { return ref_a_; }
  /// Return the refinement for model B.
  inline RefPtr refine_b() const { return ref_b_; }
  /// Return the relation (state mapping) between model A and B.
  inline RelPtr relation() const { return rel_; }

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new CRR object. Used for hiding implementation
  /// specific type details.
  static CrrPtr New(const RefPtr ref_a = RefinementMap::New(),
                    const RefPtr ref_b = RefinementMap::New(),
                    const RelPtr rel = RelationMap::New());

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Refinement mapping for model A.
  RefPtr ref_a_;
  /// Refinement mapping for model B.
  RefPtr ref_b_;
  /// Relation mapping.
  RelPtr rel_;

}; // CompRefRel

/// Pointer type for passing around the compositional relation mapping.
typedef CompRefRel::CrrPtr CrrPtr;

} // namespace ilang

#endif // COMP_REF_REL_H__
