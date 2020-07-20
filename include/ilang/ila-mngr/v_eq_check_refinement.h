/// \file
/// Refinement-based ILA equivalence checking using the commutative diagram
/// approach.

#ifndef ILANG_ILA_MNGR_V_EQ_CHECK_REFINEMENT_H__
#define ILANG_ILA_MNGR_V_EQ_CHECK_REFINEMENT_H__

#include <z3++.h>

#include <ilang/ila-mngr/u_unroller.h>
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
  void set_tgt(const InstrLvlAbsPtr& tgt);
  /// Define the target instruction (source for coi).
  void set_tgt(const InstrPtr& tgt);
  /// Define the apply function.
  void set_appl(const ExprPtr& appl);
  /// Define the flushing function.
  void set_flush(const ExprPtr& flush);
  /// Define the completion scenario (e.g. dummy end).
  void set_cmpl(const ExprPtr& cmpl);
  /// Specify the number of steps required for flushing. XXX
  inline void set_step(const int& step) { set_step_orig(step); }
  /// Specify the number of steps required for flushing apply path.
  void set_step_appl(const int& step);
  /// Specify the number of steps required for flushing original path.
  void set_step_orig(const int& step);
  /// Add an invariant.
  void add_inv(const ExprPtr& inv);

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new refinement mapping. Used for hiding implementation
  /// specific type details.
  static RefPtr New();

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Cone-of-influence (as an ILA).
  InstrLvlAbsPtr coi_ = nullptr;
  /// Apply function.
  ExprPtr appl_ = nullptr;
  /// Flushing function.
  ExprPtr flush_ = nullptr;
  /// Completion indicator.
  ExprPtr cmpl_ = asthub::BoolConst(true);
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
  void add(const ExprPtr& rel);
  /// Return the conjuncted (ANDed) relation.
  inline ExprPtr get() const { return acc_; }

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new relation mapping. Used for hiding implementation
  /// specific type details.
  static RelPtr New();

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Cached output for conjuncting all relations.
  ExprPtr acc_ = asthub::BoolConst(true);

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
  z3::expr GetZ3Cmpl(const ExprPtr& cmpl, MonoUnroll& un, const int& begin,
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
  bool SanityCheckRelation(const RelPtr rel, const InstrLvlAbsPtr& ma,
                           const InstrLvlAbsPtr& mb) const;

  int DetStepOrig(const RefPtr ref, const int& max);
  int DetStepAppl(const RefPtr ref, const int& max);
  bool CheckStepOrig(const RefPtr ref, const int& k);
  bool CheckStepAppl(const RefPtr ref, const int& k);

  z3::expr GenInit(const RefPtr ref);
  z3::expr GenTranRel(const RefPtr ref, const int& k_orig, const int& k_appl);
  z3::expr GenAssm();
  z3::expr GenProp();

  z3::expr AtLeastOnce(MonoUnroll& unroller, const ExprPtr& cmpl,
                       const int& start, const int& end) const;
  z3::expr AtMostOnce(MonoUnroll& unroller, const ExprPtr& cmpl,
                      const int& start, const int& end) const;
  z3::expr UnrollFlush(MonoUnroll& unroller, const RefPtr ref, const int& base,
                       const int& length, const int& start);

}; // class CommDiag

} // namespace ilang

#endif // ILANG_ILA_MNGR_V_EQ_CHECK_REFINEMENT_H__
