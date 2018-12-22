/// \file
/// Header for generating verification condition for equivalence checking.

#ifndef EQ_CHECK_CRR_H__
#define EQ_CHECK_CRR_H__

#include "z3++.h"
#include <ilang/ila/comp_ref_rel.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/verification/unroller.h>

/// \namespace ilang
namespace ilang {

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
  /// relation up to the given unrolling bound.
  /// \param[in] max unrolling bound.
  bool EqCheck(const int& max = 10);

  /// \brief Incrementally checking equivalence between two models based on
  /// the refinement relation up to the given unrolling bound.
  /// \param[in] min #step of unrolling.
  /// \param[in] max #step of unrolling.
  bool IncEqCheck(const int& min = 0, const int& max = 10, const int& step = 1);

  bool IncCheck(const int& min = 0, const int& max = 10, const int& step = 1);

  typedef MonoUnroll Unroll;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The underlying z3 context.
  z3::context& ctx_;
  /// The refinement relation.
  CrrPtr crr_;

  // ------------------------- IncCheck ------------------------------------- //

  void Init();

  enum UID { A_OLD, A_NEW, B_OLD, B_NEW };

  struct UnrlUnit {
    int lo = 0;
    int hi = 0;
  } uu_a_old_, uu_a_new_, uu_b_old_, uu_b_new_;

  Unroll unrl_a_old_ = Unroll(ctx_, k_suff_old_);
  Unroll unrl_a_new_ = Unroll(ctx_, k_suff_new_);
  Unroll unrl_b_old_ = Unroll(ctx_, k_suff_old_);
  Unroll unrl_b_new_ = Unroll(ctx_, k_suff_new_);

  ExprSet stts_a_;
  ExprSet stts_b_;

  Unroll& GetUnrl(const UID& uid);
  Unroll& GetUnrlOld();
  Unroll& GetUnrlNew();
  Unroll& GetUnrlApl();

  RefPtr GetRefine(const UID& uid);
  UnrlUnit& GetUnrlUnit(const UID& uid);
  const ExprSet& GetStts(const UID& uid);

  z3::expr GetZ3IncFlsh(const UID& uid);
  z3::expr GetZ3IncCmpl(const UID& uid);

  // ------------------------- IncEqCheck ----------------------------------- //
  static const std::string k_suff_old_;
  static const std::string k_suff_new_;
  static const std::string k_suff_apl_;
  MonoUnroll unrl_old_ = MonoUnroll(ctx_, k_suff_old_);
  MonoUnroll unrl_new_ = MonoUnroll(ctx_, k_suff_new_);
  MonoUnroll unrl_apl_ = MonoUnroll(ctx_, k_suff_apl_);

  z3::expr GetZ3ApplInstr(const ExprSet& stts, const RefPtr ref);
  z3::expr GetZ3Assm();
  z3::expr GetZ3Prop();
  z3::expr GetZ3Cmpl(const ExprPtr cmpl, MonoUnroll& un, const int& begin,
                     const int& end) const;
  z3::expr GetZ3IncUnrl(MonoUnroll& un, const RefPtr ref, const int& begin,
                        const int& length, const ExprSet& stts) const;
  bool CheckCmpl(z3::solver& s, z3::expr& cmpl_expr) const;

  // ------------------------- MonoCheck ------------------------------------ //
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

} // namespace ilang

#endif // EQ_CHECK_CRR_H__
