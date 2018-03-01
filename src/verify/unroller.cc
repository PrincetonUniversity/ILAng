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

void Unroller::ClearGlobPred() { g_pred_.clear(); }

void Unroller::ClearInitPred() { i_pred_.clear(); }

ZExpr Unroller::Equal(const ExprPtr a, const int& ta, const ExprPtr b,
                      const int& tb) {
  auto a_expr = gen().GetExpr(a, SuffNorm(ta));
  auto b_expr = gen().GetExpr(b, SuffNorm(tb));
  return a_expr == b_expr;
}

ZExpr Unroller::UnrollSubs(const size_t& len, const int& pos) {
  // bootstrap basic information
  BootStrap(pos);

  // unroll based on g_pred, i_pred, and transition relation (with guard)
  for (size_t i = 0; i != len; i++) {
    // time-stamp for this time-frame
    auto k_suffix = SuffNorm(pos + i);

    // get transition relation (k_next_) and step-specific predicate (k_pred_)
    Transition(i);

    // the source for substitution
    Clear(k_curr_z3_);
    IExprToZExpr(vars_, k_suffix, k_curr_z3_);

    // alias (reference)
    auto subs_src = k_curr_z3_;
    auto subs_dst = k_prev_z3_;
    // rewrite and add initial predicate
    if (i == 0) {
      IExprToZExpr(i_pred_, k_suffix, cstr_, subs_src, subs_dst);
    }
    // rewrite and add global predicate
    IExprToZExpr(g_pred_, k_suffix, cstr_, subs_src, subs_dst);
    // rewrite and add step-specific predicate
    IExprToZExpr(k_pred_, k_suffix, cstr_, subs_src, subs_dst);

    // rewrite and add transition relation
    Clear(k_next_z3_);
    IExprToZExpr(k_next_, k_suffix, k_next_z3_, subs_src, subs_dst);
    // update next state function to the prev for next step
    CopyZExprVec(k_next_z3_, k_prev_z3_);
  }

  // add constraints for transition relation (k_prev_ has the last value)
  AssertEqual(k_prev_z3_, vars_, SuffNorm(len));

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
    auto k_suffix = SuffNorm(pos + i);

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

    // assert transition relation
    Clear(k_next_z3_);
    IExprToZExpr(k_next_, k_suffix, k_next_z3_);
    // assert equal between next state value and next state var
    AssertEqual(k_next_z3_, vars_, SuffNorm(pos + i + 1));
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
    auto k_suffix = SuffNorm(pos + i);

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

void Unroller::BootStrap(const int& pos) {
  vars_.clear();
  k_pred_.clear();
  k_next_.clear();
  // collect dependant state variables
  CollectVar();
  ILA_ASSERT(!vars_.empty()) << "No state variable defined.";

  Clear(k_prev_z3_);
  Clear(k_curr_z3_);
  Clear(k_next_z3_);
  Clear(cstr_);
  // prepare the table
  for (auto it = vars_.begin(); it != vars_.end(); it++) {
    auto ivar = *it;
    auto zvar = gen().GetExpr(ivar, SuffNorm(pos));
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

ZExpr Unroller::ConjPred(const ZExprVec& vec) {
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

void ListUnroll::CollectVar() {
  // collect the set of vars
  std::set<ExprPtr> vars;
  for (size_t i = 0; i != seq_.size(); i++) {
    auto m = seq_[i]->host();
    ILA_NOT_NULL(m);
    // add states if no child-ILAs
    for (size_t i = 0; i != m->state_num(); i++) {
      vars.insert(m->state(i));
    }
  }

  // update to the global set
  vars_.clear();
  for (auto it = vars.begin(); it != vars.end(); it++) {
    vars_.push_back(*it);
  }
}

void ListUnroll::Transition(const size_t& idx) {
  ILA_CHECK(idx < seq_.size()) << "Out-of-bound transition not defined.";
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

  // add customized step predicate (k_pred_)
  // auto cust = CustKPred(seq_);
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

void MonoUnroll::CollectVar() {
  ILA_ASSERT(vars_.empty()) << "var not clear yet.";
  CollectHier(top_);
  for (auto it = dep_vars_.begin(); it != dep_vars_.end(); it++) {
    vars_.push_back(*it);
  }
}

// - decode is embedded in the update function
// - instruction selection is encoded as step predicate
// - next state var is the representation of the update function
void MonoUnroll::Transition(const size_t& idx) {
  // check whether the table has been generated.
  if (!k_next_.empty()) {
    ILA_ASSERT(k_next_.size() == vars_.size()) << "Table size mismatch.";
    return;
  }

  // collect the set of insturctions

  auto var_num = vars_.size();

  // next state function (k_next_)
  for (size_t v_idx = 0; v_idx != var_num; v_idx++) {
    //
  }

  // step predicate (k_pred_)
}

void MonoUnroll::CollectHier(const InstrLvlAbsPtr m) {
  ILA_NOT_NULL(m);

  // traverse the child-ILAs
  for (size_t i = 0; i != m->child_num(); i++) {
    CollectHier(m->child(i));
  }

  // child-states must contain parent-states
  if (m->child_num() != 0)
    return;

  // add states if no child-ILAs
  for (size_t i = 0; i != m->state_num(); i++) {
    dep_vars_.insert(m->state(i));
  }
}

} // namespace ila

