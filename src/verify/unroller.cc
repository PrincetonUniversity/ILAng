/// \file
/// Source for unrolling ILA execution.

#include "verify/unroller.h"
#include "util/log.h"
#include <map>
#include <vector>

namespace ila {

typedef Unroller::ZExpr ZExpr;

/******************************************************************************/
// Unroller
/******************************************************************************/
Unroller::Unroller(z3::context& ctx)
    : ctx_(ctx), gen_(Z3ExprAdapter(ctx)), k_prev_z3_(ctx), k_curr_z3_(ctx),
      k_next_z3_(ctx), cstr_(ctx) {}

Unroller::~Unroller() {}

void Unroller::AddGlobPred(const ExprPtr p) { g_pred_.push_back(p); }

void Unroller::AddInitPred(const ExprPtr p) { i_pred_.push_back(p); }

void Unroller::AddStepPred(const ExprPtr p, const int& k) {
  s_pred_[k].push_back(p);
}

void Unroller::ClearGlobPred() { g_pred_.clear(); }

void Unroller::ClearInitPred() { i_pred_.clear(); }

void Unroller::ClearStepPred() { s_pred_.clear(); }

void Unroller::SetExtraSuffix(const std::string& suff) { extra_suff_ = suff; }

void Unroller::ResetExtraSuffix() { extra_suff_ = ""; }

ZExpr Unroller::CurrState(const ExprPtr v, const int& t) {
  return gen().GetExpr(v, SuffCurr(t));
}

ZExpr Unroller::NextState(const ExprPtr v, const int& t) {
  return gen().GetExpr(v, SuffNext(t));
}

ZExpr Unroller::GetZ3Expr(const ExprPtr v, const int& t) {
  return gen().GetExpr(v, SuffCurr(t));
}

ZExpr Unroller::Equal(const ExprPtr a, const int& ta, const ExprPtr b,
                      const int& tb) {
  auto a_expr = gen().GetExpr(a, SuffCurr(ta));
  auto b_expr = gen().GetExpr(b, SuffCurr(tb));
  return a_expr == b_expr;
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

  // accumulate all constraints and return
  auto cstr = ConjPred(cstr_);
  return cstr;
}

ZExpr Unroller::UnrollAssn(const size_t& len, const int& pos) {
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
    AssertEqual(k_next_z3_, vars_, SuffCurr(pos + i + 1));
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

ExprPtr Unroller::StateUpdCmpl(const InstrPtr instr, const ExprPtr var) {
  auto upd = instr->GetUpdate(var);
  return (upd) ? upd : var;
}

void Unroller::UpdDepVar(const std::vector<InstrPtr>& seq,
                         std::set<ExprPtr>& dep_var) {
  for (size_t i = 0; i != seq.size(); i++) {
    auto m = seq[i]->host();
    ILA_NOT_NULL(m);
    for (size_t i = 0; i != m->state_num(); i++) {
      dep_var.insert(m->state(i));
    }
  }
}

void Unroller::UpdDepVar(const InstrLvlAbsPtr top, std::set<ExprPtr>& dep_var) {
  ILA_NOT_NULL(top);
  // traverse the child-ILAs
  for (size_t i = 0; i != top->child_num(); i++) {
    UpdDepVar(top->child(i), dep_var);
  }
  // child-states must contain parent-states
  if (top->child_num() != 0)
    return;
  // add states if no child-ILAs
  for (size_t i = 0; i != top->state_num(); i++) {
    dep_var.insert(top->state(i));
  }
}

void Unroller::BootStrap(const int& pos) {
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
// ListUnroll
/******************************************************************************/
ListUnroll::ListUnroll(z3::context& ctx) : Unroller(ctx) {}

ListUnroll::~ListUnroll() {}

ZExpr ListUnroll::InstrSeqSubs(const InstrVec& seq, const int& pos) {
  // set up target transition relation
  seq_ = seq;
  return UnrollSubs(seq.size(), pos);
}

ZExpr ListUnroll::InstrSeqAssn(const InstrVec& seq, const int& pos) {
  // set up target transition relation
  seq_ = seq;
  return UnrollAssn(seq.size(), pos);
}

ZExpr ListUnroll::InstrSeqNone(const InstrVec& seq, const int& pos) {
  // set up target transition relation
  seq_ = seq;
  return UnrollNone(seq.size(), pos);
}

void ListUnroll::DefineDepVar() {
  // collect the set of vars
  std::set<ExprPtr> dep_var;
  UpdDepVar(seq_, dep_var);

  // update to the global set
  vars_.clear();
  for (auto it = dep_var.begin(); it != dep_var.end(); it++) {
    vars_.push_back(*it);
  }
}

void ListUnroll::Transition(const int& idx) {
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
  auto dec = instr->GetDecode();
  ILA_NOT_NULL(dec);
  k_pred_.push_back(dec);
}

/******************************************************************************/
// MonoUnroll
/******************************************************************************/
MonoUnroll::MonoUnroll(z3::context& ctx) : Unroller(ctx) {}

MonoUnroll::~MonoUnroll() {}

ZExpr MonoUnroll::MonoSubs(const InstrLvlAbsPtr top, const int& length,
                           const int& pos) {
  top_ = top;
  return UnrollSubs(length, pos);
}

void MonoUnroll::DefineDepVar() {
  vars_.clear();
  std::set<ExprPtr> dep_var;
  UpdDepVar(top_, dep_var);

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

  // collect the set of insturctions
  std::set<InstrPtr> instrs;
  // for (

  auto var_num = vars_.size();

  // next state function (k_next_)
  for (size_t v_idx = 0; v_idx != var_num; v_idx++) {
    //
  }

  // step predicate (k_pred_)
}

} // namespace ila

