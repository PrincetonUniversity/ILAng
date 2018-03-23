/// \file
/// Header for generating verification condition for equivalence checking.

#ifndef EQ_CHECK_CRR_H__
#define EQ_CHECK_CRR_H__

#include "ila/instr_lvl_abs.h"
#include "refinement/comp_ref_rel.h"
#include "z3++.h"

/// \namespace ila
namespace ila {

/// \brief Generator for commutating diagram-based equivalence checking.
class CommDiag {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  CommDiag(const CrrPtr crr);
  /// Default destructor.
  ~CommDiag();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Generate verification condition up to the given maximum bound.
  z3::expr GenVerCond(z3::context& ctx, const int& max);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The refinement relation.
  CrrPtr crr_;

  /// \brief Check the refinement mapping is valid.
  /// - F: flushing function (states + inputs)
  /// - A: apply function (states + inputs)
  /// - Eq: equivalence of all state variables (not including inputs)
  /// - Property: !(F ^ A) is unsat
  /// - Property: A(s0) & !(F(s1) & A(s0) & Eq(s0, s1)) is unsat
  bool CheckRefinement(const RefPtr ref) const;

  /// Top-level ILA for target A.
  InstrLvlAbsPtr ma_ = NULL;
  /// Top-level ILA for target B.
  InstrLvlAbsPtr mb_ = NULL;

  /// Categorize the target to either A or B.
  void RegisterTarget(const InstrLvlAbsPtr t);

}; // class CommDiag

} // namespace ila

#endif // EQ_CHECK_CRR_H__

