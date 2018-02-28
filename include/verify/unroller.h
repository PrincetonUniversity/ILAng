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
  /// Type for containing a set of z3::expr.
  typedef z3::expr_vector ZExprVec;
  /// Type alias for a set of ExprPtr.
  typedef ExprPtrVec IExprVec;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor
  Unroller(z3::context& ctx);
  /// Default virtual destructor.
  virtual ~Unroller();

  // ------------------------- METHODS -------------------------------------- //
  /// Add a predicate that should be asserted globally.
  void AddGlobPred(const ExprPtr p);
  /// Add a predicate that should be asserted in the initial condition.
  void AddInitPred(const ExprPtr p);
  /// Clear the global predicates.
  void ClearGlobPred();
  /// Clear the initial predicates.
  void ClearInitPred();

  // ------------------------- HELPERS -------------------------------------- //
  /// Return the z3::expr representing a and b are equal at their time-stamps.
  ZExpr Equal(const ExprPtr a, const int& ta, const ExprPtr b, const int& tb);

protected:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The set of dependant state variables.
  IExprVec vars_;
  /// The set of predicates to be asserted of each step.
  IExprVec k_pred_;
  /// The set of state update functions of each step.
  IExprVec k_next_;

  // ------------------------- METHODS -------------------------------------- //
  /// [Application-specific] Collect the set of dependant state variables.
  virtual void CollectVar() = 0;
  /// [Application-specific] Define state updates and predicates of each step.
  virtual void Transition(const size_t& idx) = 0;

  /// [Customize] Suffix generator for normal expressions of each step.
  virtual inline std::string SuffNorm(const int& t) const {
    return std::to_string(t);
  }
  /// [Customize] Suffix generator for next state symbol of each step.
  virtual inline std::string SuffNext(const int& t) const {
    return std::to_string(t) + ".nxt";
  }

  /// Unroll while substituting internal expression.
  ZExpr UnrollSubs(const size_t& len, const int& pos);
  /// Unroll without substituting internal expression.
  ZExpr UnrollAssn(const size_t& len, const int& pos);
  /// Unroll without asserting state equality between each step.
  ZExpr UnrollNone(const size_t& len, const int& pos);

  // ------------------------- HELPERS -------------------------------------- //
  /// Return the state update function (unchanged if not defined).
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
  ZExprVec k_prev_z3_;
  /// The set of z3::expr representing the current states.
  ZExprVec k_curr_z3_;
  /// The set of z3::expr representing the next states.
  ZExprVec k_next_z3_;

  /// The set of constraints that should be asserted.
  ZExprVec cstr_;

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the underlying z3::context.
  inline z3::context& ctx() const { return ctx_; }
  /// Return the z3::expr generator.
  inline Z3ExprAdapter& gen() { return gen_; }

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Boot-strapping information needed for unrolling.
  /// - collect dependant state variables
  /// - prepare rewriting table
  void BootStrap(const int& pos);

  /// Assert equal between the z3::expr and the Expr w.r.t the suffix.
  void AssertEqual(const ZExprVec& z, const IExprVec& e,
                   const std::string& suffix);

  /// Clear the z3::epxr container.
  inline void Clear(ZExprVec& z3_vec);

  /// Generate and append the z3::expr for the set of Expr w.r.t. the suffix.
  void IExprToZExpr(const IExprVec& i_expr_src, const std::string& suffix,
                    ZExprVec& z_expr_dst);
  /// \brief Generate and append the z3::expr for the set of Expr w.r.t. the
  /// suffix while substituting internal expressions.
  void IExprToZExpr(const IExprVec& i_expr_src, const std::string& suffix,
                    ZExprVec& z_expr_dst, const ZExprVec& subs_src,
                    const ZExprVec& subs_dst);

  /// Wrapper for assigning (copying) z3::expr_vector from src to dst.
  void CopyZExprVec(const ZExprVec& src, ZExprVec& dst);

  /// Conjunct (AND) all the predicates in the set.
  ZExpr ConjPred(const ZExprVec& vec);

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
  /// relations between steps. "N(var_i) == var_i.nxt_suff"
  /// \param[in] seq the sequence of instructions.
  /// \param[in] pos the starting time frame.
  /// \param[in] nxt_suff the suffix added to the next state values.
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

/// \brief Application class for unrolling the ILA as a monolithic transition
/// system.
class MonoUnroll : public Unroller {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  MonoUnroll(z3::context& ctx);
  /// Default destructor.
  ~MonoUnroll();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Unroll the ILA with internal states substituted.
  /// \param[in] top the top-level ILA.
  /// \param[in] length number of steps to unroll.
  /// \param[in] pos the starting time frame.
  ZExpr MonoSubs(const InstrLvlAbsPtr top, const int& length,
                 const int& pos = 0);

  /// \brief Unroll the ILA while asserting states are equal between each step.
  /// \param[in] top the top-level ILA.
  /// \param[in] length number of steps to unroll.
  /// \param[in] pos the starting time frame.
  ZExpr MonoAssn(const InstrLvlAbsPtr top, const int& length,
                 const int& pos = 0);

  /// \brief Unroll the ILA without asserting states relations between steps.
  /// \param[in] top the top-level ILA.
  /// \param[in] length number of steps to unroll.
  /// \param[in] pos the starting time frame.
  /// \param[in] nxt_suff the suffix added to the next state values.
  ZExpr MonoNone(const InstrLvlAbsPtr top, const int& length,
                 const int& pos = 0);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The sequence of instructions.
  InstrLvlAbsPtr top_;
  /// Internal container for collecting dependant state vars.
  std::set<ExprPtr> dep_vars_;

  // ------------------------- METHODS -------------------------------------- //
  /// [Application-specific] Collect the set of dependant state variables.
  void CollectVar();
  /// [Application-specific] Define state updates and predicates of each step.
  void Transition(const size_t& idx);

  void CollectHier(const InstrLvlAbsPtr m);
}; // class BulkUnroll

} // namespace ila

#endif // UNROLLER_H__

