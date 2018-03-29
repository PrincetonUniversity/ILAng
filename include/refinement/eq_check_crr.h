/// \file
/// Header for generating verification condition for equivalence checking.

#ifndef EQ_CHECK_CRR_H__
#define EQ_CHECK_CRR_H__

#include "backend/unroller.h"
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
  CommDiag(z3::context& ctx, const CrrPtr crr);
  /// Default destructor.
  ~CommDiag();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Check equivalence between two models based on the refinement
  /// relation provided up to the given unroll bound.
  /// \param[in] max unroll bound.
  bool EqCheck(const int& max = 10);

  /// \brief Generate verification condition up to the given maximum bound. This
  /// equals to tran && !prop
  z3::expr GenVerCond(const int& max);

  /// \brief Generate verification condition for the transition path.
  z3::expr GenVerCondTran(const int& max);
  /// \brief Generate verification condition for the property.
  z3::expr GenVerCondProp();

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The underlying z3 context.
  z3::context& ctx_;
  /// The refinement relation.
  CrrPtr crr_;
  /// The z3 expr adapter used.
  Z3ExprAdapter g_ = Z3ExprAdapter(ctx_);

  static const std::string k_suff_orig_;
  static const std::string k_suff_appl_;
  MonoUnroll unroll_appl_ = MonoUnroll(ctx_, k_suff_appl_);
  MonoUnroll unroll_orig_ = MonoUnroll(ctx_, k_suff_orig_);

  /// \brief Check the refinement mapping is valid.
  /// - F: flushing function (states + inputs)
  /// - A: apply function (states + inputs)
  /// - Eq: equivalence of all state variables (not including inputs)
  /// - Property: !(F ^ A) is unsat
  /// - Property: A(s0) & !(F(s1) & A(s0) & Eq(s0, s1)) is unsat
  bool CheckRefinement(const RefPtr ref);

  /// \brief Generate verification condition for one part of the commutating
  /// diagram up to the given bound.
  /// - (so_0 = sn_0) for all state variables
  /// - unroll, starting from so_0 for k steps, F(so_i) for all i >= 0
  /// - unroll, starting from sn_0 for 1 step, A(sn_0)
  /// - unroll, starting from sn_1 for k steps, F(sn_i) for all i > 0
  /// - if #step in CRR < max, k = #step, otherwise k = max
  /// - if #step not known, OR all cmpl in i-th steps for i > 0 and return
  z3::expr GenVerCondRefine(const RefPtr ref, const int& max);

  bool SanityCheck() const;
  bool SanityCheckRefinement(const RefPtr ref) const;
  bool SanityCheckRelation(const RelPtr rel, const InstrLvlAbsPtr ma,
                           const InstrLvlAbsPtr mb) const;

  int DetStepOrig(const RefPtr ref, const int& max);
  int DetStepAppl(const RefPtr ref, const int& max);
  bool CheckStepOrig(const RefPtr ref, const int& k);
  bool CheckStepAppl(const RefPtr ref, const int& k);

  z3::expr GenInit(const RefPtr ref);

  z3::expr GenTranRel(const RefPtr ref, const int& k_orig, const int& k_appl);
  z3::expr GenAssm();
  z3::expr GenProp();

  z3::expr AtLeastOnce(const ExprPtr cmpl, const int& start, const int& end,
                       MonoUnroll& unroller) const;
  z3::expr AtMostOnce(const ExprPtr cmpl, const int& start, const int& end,
                      MonoUnroll& unroller) const;
  z3::expr UnrollFlush(const RefPtr ref, const int& start, const int& end,
                       MonoUnroll& unroller, const int& base);

}; // class CommDiag

} // namespace ila

#endif // EQ_CHECK_CRR_H__

