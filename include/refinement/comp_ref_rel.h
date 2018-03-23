/// \file
/// Header for the refinement relation

#ifndef COMP_REF_REL_H__
#define COMP_REF_REL_H__

#include "ila/instr_lvl_abs.h"

/// \namespace ila
namespace ila {

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
  /// Return the apply function.
  inline ExprPtr appl() const { return appl_; }
  /// Return the constraint for flushing (stall).
  inline ExprPtr flush() const { return flush_; }
  /// Return the constraint for completion indicator.
  inline ExprPtr cmpl() const { return cmpl_; }
  /// Return the number of steps required for flushing.
  inline const int& step() const { return step_; }
  /// Define the apply function.
  void set_appl(const ExprPtr appl);
  /// Define the flushing function.
  void set_flush(const ExprPtr flush);
  /// Define the completion scenario (e.g. dummy end).
  void set_cmpl(const ExprPtr cmpl);
  /// Specify the number of steps required for flushing (0 if not known).
  void set_step(const int& step);

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new refinement mapping. Used for hiding implementation
  /// specific type details.
  static RefPtr New();

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Apply function.
  ExprPtr appl_ = NULL;
  /// Flushing function.
  ExprPtr flush_ = NULL;
  /// Completion indicator.
  ExprPtr cmpl_ = NULL;
  /// Number of steps for flushing.
  int step_ = 0;

}; // RefinementMap

/// Pointer type for passing around the refinement mapping.
typedef RefinementMap::RefPtr RefPtr;

/// \brief Relation mapping defines how arch states of two models are mapped,
/// i.e., state mapping.
class RelationMap {
public:
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

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Cached output for conjuncting all relations.
  ExprPtr acc_ = ExprFuse::BoolConst(true);

}; // RelationMap

/// Pointer type for passing around the relation (state mapping).
typedef std::shared_ptr<RelationMap> RelPtr;

/// \brief Compositional refinement relation defines a unit (element for the
/// composition) of refinement relation, which specifies
/// - how to start (apply function),
/// - what to compare (relation), and
/// - when to check (refinement).
class CompRefRel {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
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

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Refinement mapping for model A.
  RefPtr ref_a_;
  /// Refinement mapping for model B.
  RefPtr ref_b_;
  /// Relation mapping.
  RelPtr rel_;

}; // CompRefRel

} // namespace ila

#endif // COMP_REF_REL_H__

