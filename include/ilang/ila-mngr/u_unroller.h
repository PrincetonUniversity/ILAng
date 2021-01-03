/// \file
/// A collection of unroller classes for unrolling ILA execution.

#ifndef ILANG_ILA_MNGR_U_UNROLLER_H__
#define ILANG_ILA_MNGR_U_UNROLLER_H__

#include <map>
#include <vector>

#include <z3++.h>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/target-smt/z3_expr_adapter.h>

/// \namespace ilang
namespace ilang {

/// \brief Base class for unrolling ILA execution in different settings.
class Unroller {
protected:
  /// Type alias for z3::expr.
  typedef z3::expr ZExpr;
  /// Type for containing a set of z3::expr.
  typedef z3::expr_vector ZExprVec;
  /// Type alias for a set of ExprPtr.
  typedef ExprPtrVec IExprVec;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor
  Unroller(z3::context& ctx, const std::string& suffix);
  /// Default virtual destructor.
  virtual ~Unroller();

  // ------------------------- METHODS -------------------------------------- //
  /// Add a predicate that should be asserted globally.
  void AddGlobPred(const ExprPtr& p);
  /// Add a predicate that should be asserted in the initial condition.
  void AddInitPred(const ExprPtr& p);
  /// Add a predicate that should be asserted at the k-th step.
  void AddStepPred(const ExprPtr& p, const int& k);
  /// Clear the global predicates.
  void ClearGlobPred();
  /// Clear the initial predicates.
  void ClearInitPred();
  /// Clear the step-specific predicates.
  void ClearStepPred();
  /// Clear all predicates.
  void ClearPred();

  // ------------------------- HELPERS -------------------------------------- //
  /// Return the z3::expr representing the current state at the time.
  ZExpr CurrState(const ExprPtr& v, const int& t);
  /// Return the z3::expr representing the next state at the time.
  ZExpr NextState(const ExprPtr& v, const int& t);
  /// Return the z3::expr representing the current-based Expr at the time.
  ZExpr GetZ3Expr(const ExprPtr& e, const int& t);
  /// Return the z3::expr representing a unique Expr (regardless of time).
  ZExpr GetZ3Expr(const ExprPtr& e);
  /// Return the z3::expr representing a and b are equal at their time.
  ZExpr Equal(const ExprPtr& va, const int& ta, const ExprPtr& vb,
              const int& tb);
  /// Return the z3::func_decl representing f.
  z3::func_decl GetZ3FuncDecl(const FuncPtr& f) const;

protected:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The set of dependant state variables.
  IExprVec vars_;
  /// The set of predicates to be asserted of each step.
  IExprVec k_pred_;
  /// The set of state update functions of each step.
  IExprVec k_next_;

  // ------------------------- METHODS -------------------------------------- //
  /// \brief [Application-specific] Define dependant state variables.
  /// - "vars_" should be assigned with the state vars uniquely.
  /// - "vars_" will be cleared before caling this function.
  /// = The var order stored in "vars_" will be the globally agree-upon order.
  virtual void DefineDepVar() = 0;

  /// \brief [Application-specific] Define next state update functions.
  /// - "k_next_" should be assigned with the next state expression.
  /// - "k_next_" follows the global order as stored in "vars_".
  /// - "k_next_" will NOT be cleared before calling (is the only modifier).
  /// - "k_pred_" can be used to store step-specific predicates, e.g. decode.
  /// - "k_pred_" will NOT be cleared before calling (is the only modifier).
  virtual void Transition(const int& idx) = 0;

  /// Unroll while substituting internal expression.
  ZExpr UnrollSubs(const size_t& len, const int& pos);
  /// Unroll without substituting internal expression.
  ZExpr UnrollAssn(const size_t& len, const int& pos, bool cache = false);
  /// Unroll without asserting state equality between each step.
  ZExpr UnrollNone(const size_t& len, const int& pos);

  // ------------------------- HELPERS -------------------------------------- //
  /// Return the state update function (unchanged if not defined).
  static ExprPtr StateUpdCmpl(const InstrPtr& instr, const ExprPtr& var);
  /// Return the decode function (true if not defined).
  static ExprPtr DecodeCmpl(const InstrPtr& instr);

  /// Create a new free variable (with same sort) under the same host.
  static ExprPtr NewFreeVar(const ExprPtr& var, const std::string& name);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// z3::context of the unroller.
  z3::context& ctx_;
  /// z3 expression generator.
  Z3ExprAdapter gen_;

  /// Extra suffix for customized applications.
  std::string extra_suff_ = "";

  /// The set of global predicates.
  IExprVec g_pred_;
  /// The set of initial predicates.
  IExprVec i_pred_;
  /// The mapping of (external) step-specific predicates.
  std::map<int, IExprVec> s_pred_;

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
  void BootStrap(const int& pos, bool cache = false);

  /// Assert equal between the z3::expr and the Expr w.r.t the suffix.
  void AssertEqual(const ZExprVec& z, const IExprVec& e,
                   const std::string& suffix);

  /// Clear the z3::epxr container.
  void Clear(ZExprVec& z3_vec);

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
  ZExpr ConjPred(const ZExprVec& vec) const;

  /// Suffix generator for current state expressions of each step.
  inline std::string SuffCurr(const int& t) const {
    return std::to_string(t) + "_" + extra_suff_;
  }
  /// Suffix generator for next state symbol of each step.
  inline std::string SuffNext(const int& t) const {
    return std::to_string(t) + "_" + extra_suff_ + ".nxt";
  }

}; // class Unroller

/// \brief Application class for unrolling a path of instruction sequence.
class PathUnroll : public Unroller {
public:
  /// Type of a list of instruction sequence.
  typedef std::vector<InstrPtr> InstrVec;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  PathUnroll(z3::context& ctx, const std::string& suff = "");
  /// Default destructor.
  ~PathUnroll();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Unroll a sequence of instructions with internal states substituted.
  /// \param[in] seq the sequence of instructions.
  /// \param[in] pos the starting time frame.
  ZExpr PathSubs(const std::vector<InstrPtr>& seq, const int& pos = 0);

  /// \brief Unroll a sequence of instructions while asserting states are equal
  /// between each step.
  /// \param[in] seq the sequence of instructions.
  /// \param[in] pos the starting time frame.
  ZExpr PathAssn(const std::vector<InstrPtr>& seq, const int& pos = 0);

  /// \brief Unroll a sequence of instructions without asserting states
  /// relations between steps. "N(var_i) == var_i.nxt_suff"
  /// \param[in] seq the sequence of instructions.
  /// \param[in] pos the starting time frame.
  ZExpr PathNone(const std::vector<InstrPtr>& seq, const int& pos = 0);

protected:
  // ------------------------- METHODS -------------------------------------- //
  /// \brief [Application-specific] Define dependant state variables.
  /// - "vars_" should be assigned with the state vars uniquely.
  /// - "vars_" will be cleared before caling this function.
  /// = The var order stored in "vars_" will be the globally agree-upon order.
  void DefineDepVar();

  /// \brief [Application-specific] Define next state update functions.
  /// - "k_next_" should be assigned with the next state expression.
  /// - "k_next_" follows the global order as stored in "vars_".
  /// - "k_next_" will NOT be cleared before calling (is the only modifier).
  /// - "k_pred_" can be used to store step-specific predicates, e.g. decode.
  /// - "k_pred_" will NOT be cleared before calling (is the only modifier).
  void Transition(const int& idx);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The sequence of instructions.
  InstrVec seq_;
}; // class PathUnroll

/// \brief Application class for unrolling the ILA as a monolithic transition
/// system.
class MonoUnroll : public Unroller {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  MonoUnroll(z3::context& ctx, const std::string& suff = "");
  /// Default destructor.
  ~MonoUnroll();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Unroll the ILA with internal states substituted.
  /// \param[in] top the top-level ILA.
  /// \param[in] length number of steps to unroll.
  /// \param[in] pos the starting time frame.
  ZExpr MonoSubs(const InstrLvlAbsPtr& top, const int& length,
                 const int& pos = 0);

  /// \brief Unroll the ILA while asserting states are equal between each step.
  /// \param[in] top the top-level ILA.
  /// \param[in] length number of steps to unroll.
  /// \param[in] pos the starting time frame.
  ZExpr MonoAssn(const InstrLvlAbsPtr& top, const int& length,
                 const int& pos = 0);

  /// \brief Unroll the ILA without asserting states relations between steps.
  /// \param[in] top the top-level ILA.
  /// \param[in] length number of steps to unroll.
  /// \param[in] pos the starting time frame.
  ZExpr MonoNone(const InstrLvlAbsPtr& top, const int& length,
                 const int& pos = 0);

  /// \brief Incrementally unrolling the ILA using MonoAssn (with transition
  /// relation being cached).
  /// \param[in] top the top-level ILA.
  /// \param[in] length number of steps to unroll.
  /// \param[in] pos the starting time frame.
  ZExpr MonoIncr(const InstrLvlAbsPtr& top, const int& length, const int& pos);

protected:
  // ------------------------- METHODS -------------------------------------- //
  /// \brief [Application-specific] Define dependant state variables.
  /// - "vars_" should be assigned with the state vars uniquely.
  /// - "vars_" will be cleared before caling this function.
  /// - The var order stored in "vars_" will be the globally agree-upon order.
  void DefineDepVar();

  /// \brief [Application-specific] Define next state update functions.
  /// - "k_next_" should be assigned with the next state expression.
  /// - "k_next_" follows the global order as stored in "vars_".
  /// - "k_next_" will NOT be cleared before calling (is the only modifier).
  /// - "k_pred_" can be used to store step-specific predicates, e.g. decode.
  /// - "k_pred_" will NOT be cleared before calling (is the only modifier).
  void Transition(const int& idx);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The sequence of instructions.
  InstrLvlAbsPtr top_;

}; // class MonoUnroll

} // namespace ilang

#endif // ILANG_ILA_MNGR_U_UNROLLER_H__
