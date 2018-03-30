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

  bool SanityCheck();
  bool SanityCheckRefinement(const RefPtr ref);
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

  z3::expr AtLeastOnce(MonoUnroll& unroller, const ExprPtr cmpl,
                       const int& start, const int& end) const;
  z3::expr AtMostOnce(MonoUnroll& unroller, const ExprPtr cmpl,
                      const int& start, const int& end) const;
  z3::expr UnrollFlush(MonoUnroll& unroller, const RefPtr ref, const int& base,
                       const int& length, const int& start);

}; // class CommDiag

} // namespace ila

#endif // EQ_CHECK_CRR_H__

