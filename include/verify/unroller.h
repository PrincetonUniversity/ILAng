/// \file
/// Header for unrolling ILA execution.

#ifndef UNROLLER_H__
#define UNROLLER_H__

#include "ila/instr_lvl_abs.h"
#include "ila/z3_expr_adapter.h"
#include "z3++.h"
#include <set>
#include <vector>

/// \namespace ila
namespace ila {

/// \brief Base class for unrolling ILA execution in different settings.
class Unroller {
public:
  /// Type alias for z3::expr.
  typedef z3::expr ZExpr;
  /// Type for containing a vector of z3::expr.
  typedef z3::expr_vector ZExprVec;
  /// Type alias for a set of ExprPtr.
  typedef std::set<ExprPtr> IExprSet;
  /// Type alias for a vector of ExprPtr.
  typedef ExprPtrVec IExprVec;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor
  Unroller(z3::context& ctx);
  /// Default virtual destructor.
  virtual ~Unroller();

  // ------------------------- METHODS -------------------------------------- //
  /// Add a predicate that should be asserted globally.
  inline void AddGlobPred(const ExprPtr p);
  /// Add a predicate that should be asserted in the initial condition.
  inline void AddInitPred(const ExprPtr p);
  /// Clear the global predicates.
  inline void ClearGlobPred();
  /// Clear the initial predicates.
  inline void ClearInitPred();

  /// Legacy unrolling of instruction sequence.
  ZExpr InstrSeq(const std::vector<InstrPtr>& seq, const int& pos = 0);

protected:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The set of dependant state variables.
  IExprSet vars_;
  /// The set of predicates to be asserted of each step.
  IExprVec k_pred_;
  /// The set of state update functions of each step.
  IExprVec k_next_;

  // ------------------------- METHODS -------------------------------------- //
  /// [Application-specific] Collect the set of dependant state variables.
  virtual void CollectVar() = 0;
  /// [Application-specific] Define state updates and predicates of each step.
  virtual void Transition(const size_t& idx) = 0;

  /// Unroll by substituting internal expression.
  ZExpr UnrollSubs(const size_t& len, const int& pos = 0);
  /// Unroll without substituting internal expression.
  ZExpr UnrollAssn(const size_t& len, const int& pos = 0);
  /// Unroll without asserting state equality between each step.
  ZExpr UnrollNone(const size_t& len, const int& pos = 0);

  // ------------------------- HELPERS -------------------------------------- //
  /// Return the state update of an instruction (unchanged if not defined).
  ExprPtr StateUpdCmpl(const InstrPtr instr, const ExprPtr var);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// z3::context of the unroller.
  z3::context& ctx_;
  /// z3 expression generator.
  Z3ExprAdapter gen_;

  /// The set of global predicates.
  IExprVec g_pred_;
  /// The set of initial predicates.
  IExprVec i_pred_;

  /// The set of z3::expr representing the latest states of previous steps.
  ZExprVec k_prev_;
  /// The set of z3::expr representing the current states (var_k).
  ZExprVec k_curr_z3_;
  /// The set of z3::expr representing the next states (N(var_k)).
  ZExprVec k_next_z3_;

  /// The set of constraints that should be asserted at the end.
  ZExprVec cstr_;

  /// Perform substitution if true;
  bool f_subs_ = true;

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the underlying z3::context.
  inline z3::context& ctx() const { return ctx_; }
  /// Return the z3::expr generator.
  inline Z3ExprAdapter& gen() { return gen_; }

  // ------------------------- HELPERS -------------------------------------- //
  /// Boot-strapping information needed for unrolling, e.g. dependant vars.
  void BootStrap(const int& pos);

  /// Assert the set of predicates at the given time-stamp.
  void AssertPred(const IExprVec& pred_vec, const int& stamp);
  /// Assert the set of predicates at the given time-stamp with substitution.
  void AssertPredSubs(const IExprVec& pred_vec, const int& stamp,
                      const ZExprVec& src_vec, const ZExprVec& dst_vec);

  /// \brief Generate z3::expr for the next state functions with substitution.
  /// \param[in] next_z destination z3::epxr container
  /// \param[in] next_i source next state functions
  /// \param[in] stamp time stamp of the step
  /// \param[in] src the source for substitution
  /// \param[in] dst the destination for substitution
  void UpdateNextSubs(ZExprVec& next_z, const IExprVec& next_i,
                      const int& stamp, const ZExprVec& src,
                      const ZExprVec& dst);

  /// Assert equal between the z3::expr and the Expr w.r.t the time stamp.
  void AssertVarEqual(const ZExprVec& z, const IExprSet& e, const int& stamp);

  /// Wrapper for doing z3::expr substitution.
  inline ZExpr Substitute(ZExpr z, const ZExprVec& subs_src,
                          const ZExprVec& subs_dst) const;

  /// Clear the z3::epxr container.
  inline void ClearZVec(ZExprVec& z3_vec);

  /// Generate the z3::expr for the set of Expr w.r.t the time stamp.
  void ESetToZVec(ZExprVec& z3_dst, const IExprSet& expr_src, const int& stamp);
  /// Generate the z3::expr for the vector of Expr w.r.t. the time stamp.
  void EVecToZVec(ZExprVec& z3_dst, const IExprVec& expr_src, const int& stamp);
  /// \brief Generate the z3::expr for the vector of Expr w.r.t. the time stamp
  /// while substituting fanins.
  void EVecToZVecSubs(ZExprVec& z3_dst, const IExprVec& expr_src,
                      const int& stamp, const ZExprVec& subs_src,
                      const ZExprVec& subs_dst);

  /// \brief Generate and assert the z3::expr for the vector of Expr w.r.t the
  /// time stamp.
  void AssertEVec(const IExprVec& expr_src, const int& stamp);
  /// \brief Generate and assert the z3::expr for the vector of Expr w.r.t. the
  /// time stamp while substituting fanins.
  void AssertEVecSubs(const IExprVec& expr_src, const int& stamp,
                      const ZExprVec& subs_src, const ZExprVec& subs_dst);

  /// Generate z3:expr for a set of Expr given a time stamp.
  void GenZExprVec(ZExprVec& dst, const IExprSet& src, const int& stamp);

  /// Wrapper for assigning (copying) z3::expr_vector from src to dst.
  void AssignZExprVec(ZExprVec& dst, const ZExprVec& src);

  /// Conjunct all the predicates in the set.
  ZExpr ConjPred(const ZExprVec& vec);

  // legacy
  z3::expr InstrUpdDflt(const InstrLvlAbsPtr ila, const std::string& prev,
                        const std::string& next);

  z3::expr InstrUpdCmpl(const InstrPtr instr, const std::string& prev,
                        const std::string& next);

  z3::expr StateUpdCmpl(const InstrPtr instr, const ExprPtr var,
                        const std::string& prev);

  std::set<ExprPtr> GetAllVar(const std::vector<InstrPtr>& seq) const;

}; // class Unroller

/// \brief Application class for unrolling a list of instruction sequence.
class ListUnroll : public Unroller {
public:
  /// Type of a list of instruction sequence.
  typedef std::vector<InstrPtr> InstrVec;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  ListUnroll(z3::context& ctx);
  /// Default destructor.
  ~ListUnroll();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Unroll a sequence of instructions with internal states substituted.
  /// \param[in] seq the sequence of instructions.
  /// \param[in] pos the starting time frame.
  ZExpr InstrSeqSubs(const std::vector<InstrPtr>& seq, const int& pos = 0);

  /// \brief Unroll a sequence of instructions while asserting states are equal
  /// between each step.
  /// \param[in] seq the sequence of instructions.
  /// \param[in] pos the starting time frame.
  ZExpr InstrSeqAssn(const std::vector<InstrPtr>& seq, const int& pos = 0);

  /// \brief Unroll a sequence of instructions without asserting states
  /// relations between steps.
  /// \param[in] seq the sequence of instructions.
  /// \param[in] pos the starting time frame.
  ZExpr InstrSeqNone(const std::vector<InstrPtr>& seq, const int& pos = 0);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The sequence of instructions.
  InstrVec seq_;

  // ------------------------- METHODS -------------------------------------- //
  /// [Application-specific] Collect the set of dependant state variables.
  void CollectVar();
  /// [Application-specific] Define state updates and predicates of each step.
  void Transition(const size_t& idx);
};

#if 0
class BulkUnroll : public Unroller {
public:
  BulkUnroll(z3::context& ctx, const InstrLvlAbsPtr top);
  ~BulkUnroll();

  ZExpr IlaBulkAssn(const InstrLvlAbsPtr top, const int& length,
                    const int& pos = 0);

  ZExpr IlaBulkSubs(const InstrLvlAbsPtr top, const int& length,
                    const int& pos = 0);

private:
  InstrLvlAbsPtr top_;

  void BootStrap(const InstrLvlAbsPtr top);
  void CollectVar();
  void VisitHierCollectVar(const InstrLvlAbsPtr m);
};
#endif

} // namespace ila

#endif // UNROLLER_H__

