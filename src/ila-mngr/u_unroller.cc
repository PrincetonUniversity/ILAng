/// \file
/// A collection of unroller classes for unrolling ILA execution.

#include <ilang/ila-mngr/u_unroller.h>

#include <map>
#include <vector>

#include <ilang/ila-mngr/u_abs_knob.h>
#include <ilang/util/log.h>

namespace ilang {

using namespace asthub;

typedef z3::expr ZExpr;

/******************************************************************************/
// Unroller
/******************************************************************************/
Unroller::Unroller(z3::context& ctx, const std::string& suff)
    : ctx_(ctx), gen_(Z3ExprAdapter(ctx)), k_prev_z3_(ctx), k_curr_z3_(ctx),
      k_next_z3_(ctx), cstr_(ctx) {
  // SetExtraSuffix(suff);
  extra_suff_ = suff;
}

Unroller::~Unroller() {}

void Unroller::AddGlobPred(const ExprPtr& p) { g_pred_.push_back(p); }

void Unroller::AddInitPred(const ExprPtr& p) { i_pred_.push_back(p); }

void Unroller::AddStepPred(const ExprPtr& p, const int& k) {
  s_pred_[k].push_back(p);
}

void Unroller::ClearGlobPred() { g_pred_.clear(); }

void Unroller::ClearInitPred() { i_pred_.clear(); }

void Unroller::ClearStepPred() { s_pred_.clear(); }

void Unroller::ClearPred() {
  ClearGlobPred();
  ClearInitPred();
  ClearStepPred();
}

ZExpr Unroller::CurrState(const ExprPtr& v, const int& t) {
  ILA_ASSERT(v->is_var()) << "Use GetZ3Expr for non-var Expr";
  return gen().GetExpr(v, SuffCurr(t));
}

ZExpr Unroller::NextState(const ExprPtr& v, const int& t) {
  ILA_ASSERT(v->is_var()) << "Next state only exist for var";
  return gen().GetExpr(v, SuffNext(t));
}

ZExpr Unroller::GetZ3Expr(const ExprPtr& e, const int& t) {
  return gen().GetExpr(e, SuffCurr(t));
}

ZExpr Unroller::GetZ3Expr(const ExprPtr& e) {
  return gen().GetExpr(e, extra_suff_);
}

ZExpr Unroller::Equal(const ExprPtr& a, const int& ta, const ExprPtr& b,
                      const int& tb) {
  auto a_expr = gen().GetExpr(a, SuffCurr(ta));
  auto b_expr = gen().GetExpr(b, SuffCurr(tb));
  return a_expr == b_expr;
}

z3::func_decl Unroller::GetZ3FuncDecl(const FuncPtr& f) const {
  return f->GetZ3FuncDecl(ctx_);
}

ZExpr Unroller::UnrollSubs(const size_t& len, const int& pos) {
  // bootstrap basic information
  BootStrap(pos);

  // unroll based on g_pred, i_pred, and transition relation (with guard)
  for (size_t i = 0; i != len; i++) {
    // time-stamp for this time-frame
    auto k_suffix = SuffCurr(pos + i);

    // get transition relation (k_next_) and step-specific predicate (k_pred_)
    Transition(i);

    // the source for substitution
    Clear(k_curr_z3_);
    IExprToZExpr(vars_, k_suffix, k_curr_z3_);

    // alias (reference)
    auto subs_src = k_curr_z3_;
    auto subs_dst = k_prev_z3_;
    // rewrite and assert initial predicate
    if (i == 0) {
      IExprToZExpr(i_pred_, k_suffix, cstr_, subs_src, subs_dst);
    }
    // rewrite and assert global predicate
    IExprToZExpr(g_pred_, k_suffix, cstr_, subs_src, subs_dst);
    // rewrite and assert step-specific predicate
    IExprToZExpr(k_pred_, k_suffix, cstr_, subs_src, subs_dst);
    // rewrite and assert (external) step-specific predicate
    IExprToZExpr(s_pred_[i], k_suffix, cstr_, subs_src, subs_dst);

    // rewrite and add transition relation
    Clear(k_next_z3_);
    IExprToZExpr(k_next_, k_suffix, k_next_z3_, subs_src, subs_dst);
    // update next state function to the prev for next step
    CopyZExprVec(k_next_z3_, k_prev_z3_);
  }

  // add constraints for transition relation (k_prev_ has the last value)
  AssertEqual(k_prev_z3_, vars_, SuffCurr(len));

  { // extend for end states (invariant and step-specific predicates)
    auto k_suffix = SuffCurr(len);
    IExprToZExpr(g_pred_, k_suffix, cstr_);
    IExprToZExpr(s_pred_[len], k_suffix, cstr_);
  }

  // accumulate all constraints and return
  auto cstr = ConjPred(cstr_);
  return cstr;
}

ZExpr Unroller::UnrollAssn(const size_t& len, const int& pos, bool cache) {
  // bootstrap basic information
  BootStrap(pos, cache);

  // unroll based on g_pred, i_pred, and transition relation (with guard)
  for (size_t i = 0; i != len; i++) {
    // time-stamp for this time-frame
    auto k_suffix = SuffCurr(pos + i);

    // get transition relation (k_next_) and step-specific predicate (k_pred_)
    Transition(i);

    // assert initial predicate
    if (i == 0) {
      IExprToZExpr(i_pred_, k_suffix, cstr_);
    }
    // assert global predicate
    IExprToZExpr(g_pred_, k_suffix, cstr_);
    // assert (external) step-specific predicate
    IExprToZExpr(s_pred_[i], k_suffix, cstr_);
    // assert step-specific predicate
    IExprToZExpr(k_pred_, k_suffix, cstr_);

    // assert transition relation
    Clear(k_next_z3_);
    IExprToZExpr(k_next_, k_suffix, k_next_z3_);
    // assert equal between next state value and next state var
    AssertEqual(k_next_z3_, vars_, SuffCurr(pos + i + 1));
  }

  { // extend for end states (invariant and step-specific predicates)
    auto k_suffix = SuffCurr(len);
    IExprToZExpr(g_pred_, k_suffix, cstr_);
    IExprToZExpr(s_pred_[len], k_suffix, cstr_);
  }

  // accumulate all constraints and return
  auto cstr = ConjPred(cstr_);
  return cstr;
}

ZExpr Unroller::UnrollNone(const size_t& len, const int& pos) {
  // bootstrap basic information
  BootStrap(pos);

  // unroll based on g_pred, i_pred, and transition relation (with guard)
  for (size_t i = 0; i != len; i++) {
    // time-stamp for this time-frame
    auto k_suffix = SuffCurr(pos + i);

    // get transition relation (k_next_) and step-specific predicate (k_pred_)
    Transition(i);

    // assert initial predicate
    if (i == 0) {
      IExprToZExpr(i_pred_, k_suffix, cstr_);
    }
    // assert global predicate
    IExprToZExpr(g_pred_, k_suffix, cstr_);
    // assert step-specific predicate
    IExprToZExpr(k_pred_, k_suffix, cstr_);
    // assert (external) step-specific predicate
    IExprToZExpr(s_pred_[i], k_suffix, cstr_);

    // assert transition relation
    Clear(k_next_z3_);
    IExprToZExpr(k_next_, k_suffix, k_next_z3_);
    // assert equal between next state value and next state var
    AssertEqual(k_next_z3_, vars_, SuffNext(pos + i));
  }

  // accumulate all constraints and return
  auto cstr = ConjPred(cstr_);
  return cstr;
}

ExprPtr Unroller::StateUpdCmpl(const InstrPtr& instr, const ExprPtr& var) {
  auto upd = instr->update(var);
  return (upd) ? upd : var;
}

ExprPtr Unroller::DecodeCmpl(const InstrPtr& instr) {
  auto dec = instr->decode();
  return (dec) ? dec : BoolConst(true);
}

ExprPtr Unroller::NewFreeVar(const ExprPtr& var, const std::string& name) {
  auto host = var->host();
  ILA_NOT_NULL(host);

  if (var->is_bool()) {
    return host->NewBoolFreeVar(name);
  } else if (var->is_bv()) {
    return host->NewBvFreeVar(name, var->sort()->bit_width());
  } else {
    ILA_ASSERT(var->is_mem()) << "Unknown sort for " << var;
    return host->NewMemFreeVar(name, var->sort()->addr_width(),
                               var->sort()->data_width());
  }
}

void Unroller::BootStrap(const int& pos, bool cache) {
  if (!cache) {
    vars_.clear();
    k_pred_.clear();
    k_next_.clear();
    // collect dependant state variables
    DefineDepVar();
    ILA_ASSERT(!vars_.empty()) << "No state variable defined.";

    Clear(k_prev_z3_);
    Clear(k_curr_z3_);
    Clear(k_next_z3_);
    Clear(cstr_);

    // prepare the table
    for (auto it = vars_.begin(); it != vars_.end(); it++) {
      auto ivar = *it;
      auto zvar = gen().GetExpr(ivar, SuffCurr(pos));
      k_prev_z3_.push_back(zvar);
    }
  } else { // cache
    if (vars_.empty()) {
      DefineDepVar();
      ILA_ASSERT(k_prev_z3_.empty()) << "Unexpected behavior in cacheing";
      for (auto it = vars_.begin(); it != vars_.end(); it++) {
        auto ivar = *it;
        auto zvar = gen().GetExpr(ivar, SuffCurr(pos));
        k_prev_z3_.push_back(zvar);
      }
    }
  }
}

void Unroller::AssertEqual(const ZExprVec& a, const IExprVec& b,
                           const std::string& suffix) {
  ILA_ASSERT(a.size() == b.size()) << "Var num mismatch.";
  for (unsigned i = 0; i != a.size(); i++) {
    auto ai = a[i];
    auto bi = gen().GetExpr(b[i], suffix);
    auto equal = (ai == bi);
    cstr_.push_back(equal);
  }
}

void Unroller::Clear(ZExprVec& z3_vec) { z3_vec.resize(0); }

void Unroller::IExprToZExpr(const IExprVec& i_expr_src,
                            const std::string& suffix, ZExprVec& z_expr_dst) {
  for (auto it = i_expr_src.begin(); it != i_expr_src.end(); it++) {
    auto i_expr = *it;
    auto z_expr = gen().GetExpr(i_expr, suffix);
    z_expr_dst.push_back(z_expr);
  }
}

void Unroller::IExprToZExpr(const IExprVec& i_expr_src,
                            const std::string& suffix, ZExprVec& z_expr_dst,
                            const ZExprVec& subs_src,
                            const ZExprVec& subs_dst) {
  for (auto it = i_expr_src.begin(); it != i_expr_src.end(); it++) {
    auto i_expr = *it;
    auto z_expr = gen().GetExpr(i_expr, suffix);
    auto z_subs = z_expr.substitute(subs_src, subs_dst);
    z_expr_dst.push_back(z_subs);
  }
}

void Unroller::CopyZExprVec(const ZExprVec& src, ZExprVec& dst) {
  Clear(dst);
  for (unsigned i = 0; i != src.size(); i++) {
    dst.push_back(src[i]);
  }
}

ZExpr Unroller::ConjPred(const ZExprVec& vec) const {
  auto conj = ctx().bool_val(true);
  for (size_t i = 0; i != vec.size(); i++) {
    conj = (conj && vec[i]);
  }
  conj = conj.simplify();
  return conj;
}

/******************************************************************************/
// PathUnroll
/******************************************************************************/
PathUnroll::PathUnroll(z3::context& ctx, const std::string& suff)
    : Unroller(ctx, suff) {}

PathUnroll::~PathUnroll() {}

ZExpr PathUnroll::PathSubs(const InstrVec& seq, const int& pos) {
  // set up target transition relation
  seq_ = seq;
  return UnrollSubs(seq.size(), pos);
}

ZExpr PathUnroll::PathAssn(const InstrVec& seq, const int& pos) {
  // set up target transition relation
  seq_ = seq;
  return UnrollAssn(seq.size(), pos);
}

ZExpr PathUnroll::PathNone(const InstrVec& seq, const int& pos) {
  // set up target transition relation
  seq_ = seq;
  return UnrollNone(seq.size(), pos);
}

void PathUnroll::DefineDepVar() {
  // collect the set of vars
  auto dep_var = ExprSet();
  for (auto it = seq_.begin(); it != seq_.end(); it++) {
    absknob::InsertStt(*it, dep_var);
  }
  // update to the global set
  vars_.clear();
  for (auto it = dep_var.begin(); it != dep_var.end(); it++) {
    vars_.push_back(*it);
  }
}

void PathUnroll::Transition(const int& idx) {
  ILA_CHECK(idx < (int)seq_.size()) << "Out-of-bound transition not defined.";
  auto instr = seq_[idx];

  // update next state function (k_next_)
  k_next_.resize(0);
  for (auto it = vars_.begin(); it != vars_.end(); it++) {
    auto var = *it;
    auto next = StateUpdCmpl(instr, var);
    k_next_.push_back(next);
  }

  // update step predicate (k_pred_)
  k_pred_.resize(0);
  auto dec = instr->decode();
  ILA_NOT_NULL(dec);
  k_pred_.push_back(dec);
}

/******************************************************************************/
// MonoUnroll
/******************************************************************************/
MonoUnroll::MonoUnroll(z3::context& ctx, const std::string& suff)
    : Unroller(ctx, suff) {}

MonoUnroll::~MonoUnroll() {}

ZExpr MonoUnroll::MonoSubs(const InstrLvlAbsPtr& top, const int& length,
                           const int& pos) {
  top_ = top;
  return UnrollSubs(length, pos);
}

ZExpr MonoUnroll::MonoAssn(const InstrLvlAbsPtr& top, const int& length,
                           const int& pos) {
  top_ = top;
  return UnrollAssn(length, pos);
}

ZExpr MonoUnroll::MonoNone(const InstrLvlAbsPtr& top, const int& length,
                           const int& pos) {
  top_ = top;
  return UnrollNone(length, pos);
}

ZExpr MonoUnroll::MonoIncr(const InstrLvlAbsPtr& top, const int& length,
                           const int& pos) {
  top_ = top;
  return UnrollAssn(length, pos,
                    false); // XXX non-cache has better performance
}

void MonoUnroll::DefineDepVar() {
  vars_.clear();
  auto dep_var = absknob::GetSttTree(top_);
  // update global
  ILA_ASSERT(!dep_var.empty()) << "No state var found.";
  for (auto it = dep_var.begin(); it != dep_var.end(); it++) {
    vars_.push_back(*it);
  }
}

// - decode is embedded in the update function
// - instruction selection is encoded as step predicate
// - next state var is the representation of the update function
void MonoUnroll::Transition(const int& idx) {
  // check whether the table has been generated.
  if (!k_next_.empty()) {
    ILA_ASSERT(k_next_.size() == vars_.size()) << "Table size mismatch.";
    return;
  }

  // extract the set of insturctions
  auto instr_set = absknob::GetInstrTree(top_);

  // create the set of selection bits
  std::vector<ExprPtr> sel_bits;
  for (auto it = instr_set.begin(); it != instr_set.end(); it++) {
    auto instr = *it;
    auto host = instr->host();
    auto sel = host->NewBoolFreeVar(instr->name().str() + ".sel");
    sel_bits.push_back(sel);
  }
  // dummy selection bits (used for deadlock)
  auto sel_dum = top_->NewBoolFreeVar("dead.sel");

  auto var_num = vars_.size();
  auto instr_num = instr_set.size();
  ILA_ASSERT(instr_num == sel_bits.size());

  // next state function
  for (size_t v_idx = 0; v_idx != var_num; v_idx++) {
    auto var = vars_[v_idx];
    auto var_next = NewFreeVar(var, var->name().str() + ".vnxt");
    // add virtual next state to the update table
    k_next_.push_back(var_next);

    // accumulate update and decode function constraints
    auto not_dec = BoolConst(true);
    auto acc_dec = BoolConst(true);
    auto acc_upd = BoolConst(true);
    // loop through all instructions
    for (size_t i_idx = 0; i_idx != instr_set.size(); i_idx++) {
      auto instr = instr_set.at(i_idx);
      auto sel = sel_bits.at(i_idx);
      // sel -> decode
      auto decode = DecodeCmpl(instr);
      acc_dec = And(acc_dec, Imply(sel, decode));
      not_dec = And(not_dec, Not(decode));
      // sel -> Next(v, v')
      auto next = StateUpdCmpl(instr, var);
      auto equal = Eq(var_next, next);
      acc_upd = And(acc_upd, Imply(sel, equal));
    }
    // dummy selection
    acc_dec = And(acc_dec, Imply(sel_dum, not_dec));
    acc_upd = And(acc_upd, Imply(sel_dum, Eq(var_next, var)));

    // add to predicate
    k_pred_.push_back(acc_dec);
    k_pred_.push_back(acc_upd);
  }

  // one-hot encoding (need to include dummy)
  // at least one (c1 \/ c2 \/ ... \/ cm)
  auto one_hot_at_least_one = sel_dum;
  for (size_t i = 0; i != instr_num; i++) {
    auto sel_i = sel_bits.at(i);
    one_hot_at_least_one = Or(one_hot_at_least_one, sel_i);
  }
  k_pred_.push_back(one_hot_at_least_one);
  // at most one (/\i<m /\j>i (!ci \/ !cj))
  auto one_hot_at_most_one = BoolConst(true);
  for (size_t i = 0; i != instr_num; i++) {
    auto sel_i = sel_bits.at(i);
    for (size_t j = i + 1; j != instr_num; j++) {
      auto sel_j = sel_bits.at(j);
      auto not_both_true = Or(Not(sel_i), Not(sel_j));
      one_hot_at_most_one = And(one_hot_at_most_one, not_both_true);
    }
  }
  k_pred_.push_back(one_hot_at_most_one);
}

} // namespace ilang
