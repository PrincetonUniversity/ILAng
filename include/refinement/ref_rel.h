/// \file
/// Header for the refinement relation

#ifndef REF_REL_H__
#define REF_REL_H__

#include "ila/expr_fuse.h"
#include "ila/instr.h"
#include "ila/instr_lvl_abs.h"
#include <vector>

/// \namespace ila
namespace ila {

class CompRefRel {
public:
private:
}; // CompRefRel

#if 0
/// \brief Refinement unit, used to stored:
/// - instruction application function (trigger condition)
/// - instruction commit condition (e.g. dummy end decode)
/// - stall function (flushing function in Birch-Dill commutative diagram)
/// - (optional) relavant (child-)ILAs
class RefUnit {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  RefUnit();
  /// Default destructor.
  ~RefUnit();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Set the application function of the ILA.
  void set_app(const InstrLvlAbsPtr ila, const ExprPtr app);
  /// Set the commit point of the ILA.
  void set_commit(const InstrLvlAbsPtr ila, const ExprPtr com);
  /// Set the stall function of the ILA.
  void set_stall(const InstrLvlAbsPtr ila, const ExprPtr stall);
  /// Add one relevant ILA.
  void add_dep(const InstrLvlAbsPtr ila);

  /// Return the application function of the ILA.
  ExprPtr app(const InstrLvlAbsPtr ila) const;
  /// Return the commit point of the ILA.
  ExprPtr commit(const InstrLvlAbsPtr ila) const;
  /// Return the stall function of the ILA.
  ExprPtr stall(const InstrLvlAbsPtr ila) const;
  /// Return the i-th relevant ILA.
  InstrLvlAbsPtr dep(const size_t& i) const;

  /// Return the number of relevant ILAs.
  size_t dep_num() const;

private:
  typedef std::map<InstrLvlAbsPtr, ExprPtr> IlaExprMap;

  // ------------------------- MEMBERS -------------------------------------- //
  /// Instruction application function for ILAs.
  IlaExprMap app_;
  /// Instruction commit point for ILAs.
  IlaExprMap commit_;
  /// Stall function for ILAs.
  IlaExprMap stall_;
  /// Relevant (child-)ILAs (optional).
  std::vector<InstrLvlAbsPtr> dep_;

  // ------------------------- HELPERS -------------------------------------- //
  /// Reset all members.
  void clear();
}; // class RefUnit

/// Pointer type for maintaining the refinement unit.
typedef std::shared_ptr<RefUnit> RefUnitPtr;

/// \brief The class for refinement relation. This is only the container for
/// maitaining the refinement, but not handle the verification tasks.
class RefRel {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor
  RefRel(const InstrLvlAbsPtr ila_a, const InstrLvlAbsPtr ila_b);
  /// Default destructor.
  ~RefRel();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the number of state mapping.
  size_t state_map_num() const;
  /// Return the number of invariants of the ILA.
  size_t inv_num(const InstrLvlAbsPtr ila) const;
  /// Return the number of refinement unit.
  size_t unit_num() const;

  /// Access the i-th state mapping.
  ExprPtr state_map(const size_t& i) const;
  /// Access the i-th invariant of the ILA.
  ExprPtr inv(const InstrLvlAbsPtr ila, const size_t& i) const;
  /// Access the i-th refinement unit.
  RefUnitPtr unit(const size_t& i) const;

  /// Return the reference ILA model. i must be either 0 or 1.
  InstrLvlAbsPtr ila(const size_t& i) const;

  // ------------------------- METHODS -------------------------------------- //

private:
  /// Type for a set of refinement unit.
  typedef std::vector<RefUnitPtr> RefUnitVec;

  // ------------------------- MEMBERS -------------------------------------- //
  /// Reference ILA model A.
  InstrLvlAbsPtr ma_;
  /// Reference ILA model B.
  InstrLvlAbsPtr mb_;
  /// The set of state mappings (between states of ILA A and B).
  ExprPtrVec state_maps_;
  /// Invariants of ILA A.
  ExprPtrVec inv_ma_;
  /// Invariants of ILA B.
  ExprPtrVec inv_mb_;
  /// Refinement units (i.e. instructions)
  RefUnitVec units_;

  // ------------------------- HELPERS -------------------------------------- //
  /// Reset all members.
  void clear();
}; // class RefRel

/// Pointer type for passing around the refinement relation.
typedef std::shared_ptr<RefRel> RefRelPtr;
#endif

} // namespace ila

#endif // REF_REL_H__

