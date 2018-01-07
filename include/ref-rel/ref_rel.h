/// \file
/// Header for the refinement relation

#ifndef __REF_REL_H__
#define __REF_REL_H__

#include "ila/expr_fuse.h"
#include "ila/instr.h"
#include "ila/instr_lvl_abs.h"
#include <vector>

/// \namespace ila
namespace ila {

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

  // ------------------------- METHODS -------------------------------------- //

private:
  class RefUnit;
  typedef std::shared_ptr<RefUnit> RefUnitPtr;
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

  // ------------------------- HELPER CLASS --------------------------------- //
  /// \brief Refinement unit, used to stored:
  /// - instruction application function (trigger condition)
  /// - instruction commit condition (e.g. dummy end decode)
  /// - stall function (flushing function in Birch-Dill commutative diagram)
  /// - (optional) relavant (child-)ILAs
  class RefUnit {
  public:
    /// Instruction application function for ILA model A.
    ExprPtr app_ma_;
    /// Instruction application function for ILA model B.
    ExprPtr app_mb_;
    /// Instruction commit point for ILA model A.
    ExprPtr commit_ma_;
    /// Instruction commit point for ILA model B.
    ExprPtr commit_mb_;
    /// Stall function for ILA model A.
    ExprPtr stall_ma_;
    /// Stall function for ILA model B.
    ExprPtr stall_mb_;
    /// Relevant (child-)ILAs (optional).
    std::vector<InstrLvlAbsPtr> deps_;
  }; // class RefUnit

  // ------------------------- HELPERS -------------------------------------- //
}; // class RefRel

} // namespace ila

#endif // __REF_REL_H__

