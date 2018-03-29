/// \file
/// Source for generating verification condition for equivalecne checking.

#include "refinement/eq_check_crr.h"
#include "backend/abs_knob.h"
#include "backend/unroller.h"
#include "util/log.h"

namespace ila {

const std::string k_suff_old = "o";
const std::string k_suff_new = "n";

using namespace ExprFuse;

const std::string CommDiag::k_suff_orig_ = "org";
const std::string CommDiag::k_suff_appl_ = "apl";

CommDiag::CommDiag(z3::context& ctx, const CrrPtr crr) : ctx_(ctx), crr_(crr) {}

CommDiag::~CommDiag() {}

bool CommDiag::EqCheck(const int& max) {
  // refinement relation sanity check
  auto sc_res = SanityCheck();
  ILA_WARN_IF(!sc_res) << "The refinement relation sanity check fail.";

  // determine the number of steps for unrolling (check valid if specified)
  auto step_orig_a = DetStepOrig(crr_->refine_a(), max);
  auto step_appl_a = DetStepAppl(crr_->refine_a(), max);
  ILA_CHECK(step_orig_a >= 0 && step_appl_a >= 0) << "Fail determining #step";

  auto step_orig_b = DetStepOrig(crr_->refine_b(), max);
  auto step_appl_b = DetStepAppl(crr_->refine_b(), max);
  ILA_CHECK(step_orig_b >= 0 && step_appl_b >= 0) << "Fail determining #step";

  // generate transition relation
  auto cstr_tran_a = GenTranRel(crr_->refine_a(), step_orig_a, step_appl_a);
  auto cstr_tran_b = GenTranRel(crr_->refine_b(), step_orig_b, step_appl_b);

  // generate assumptions (old state equivalent)
  auto cstr_assm = GenAssm();

  // generate property to check (new state equivalent)
  auto cstr_prop = GenProp();

  // check
  z3::solver s(ctx_);
  s.add(cstr_tran_a && cstr_tran_b);
  s.add(cstr_assm);
  s.add(!cstr_prop);
  auto res = s.check();
  if (res == z3::sat) {
    ILA_DLOG("EqCheck") << s.get_model();
  }

  return (res == z3::unsat);
}

z3::expr CommDiag::GenVerCond(const int& max) {
  // check the refinement is valid.
  ILA_CHECK(CheckRefinement(crr_->refine_a())) << "Refinement check fail.";
  ILA_CHECK(CheckRefinement(crr_->refine_b())) << "Refinement check fail.";
  ILA_CHECK(
      !(crr_->refine_a()->coi()->name() == crr_->refine_b()->coi()->name()))
      << "Comparing two abstraction with same name not supported.";

  auto tran = GenVerCondTran(max);
  auto prop = GenVerCondProp();

  return tran && !prop;
}

z3::expr CommDiag::GenVerCondTran(const int& max) {
  // generate vc for each model.
  auto vc_ref_a = GenVerCondRefine(crr_->refine_a(), max);
  auto vc_ref_b = GenVerCondRefine(crr_->refine_b(), max);
  // old states are equal
  auto eq_old = g_.GetExpr(crr_->relation()->get(), k_suff_old);
  return (vc_ref_a && vc_ref_b && eq_old);
}

z3::expr CommDiag::GenVerCondProp() {
  // property: old state are equal -> new state should be equal
  auto eq_new = g_.GetExpr(crr_->relation()->get(), k_suff_new);
  return eq_new;
}

bool CommDiag::CheckRefinement(const RefPtr ref) {
  return SanityCheckRefinement(ref);
}

z3::expr CommDiag::GenVerCondRefine(const RefPtr ref, const int& max) {
  MonoUnroll uo(ctx_);
  MonoUnroll un(ctx_);
  uo.SetExtraSuffix(k_suff_old);
  un.SetExtraSuffix(k_suff_new);
  auto m = ref->coi();
  auto k = 1;
// FIXME
#if 0 
  auto k = ref->step() == -1 ? max : ref->step();
  if (ref->step() > max) {
    ILA_ERROR << "Unroll bound " << max << " not sufficient for " << m;
    return ctx_.bool_val(false);
  }
#endif
  std::set<ExprPtr> vars;
  AbsKnob::GetStVarOfIla(m, vars);

  // (so_0 == sn_0)
  auto eq = ctx_.bool_val(true);
  for (auto it = vars.begin(); it != vars.end(); it++) {
    auto so_0 = uo.CurrState(*it, 0);
    auto sn_0 = un.CurrState(*it, 0);
    eq = eq && (so_0 == sn_0);
  }

  // unroll path for old state, from 0 to k, with F(so_i) for all i >= 0
  uo.AddGlobPred(ref->flush());
  for (size_t i = 0; i != ref->inv_num(); i++) {
    uo.AddGlobPred(ref->inv(i));
  }
  auto path_old = uo.MonoAssn(m, k, 0);
  // connect end state to the interface (with no step suffix)
  for (auto it = vars.begin(); it != vars.end(); it++) {
    auto so_k = uo.CurrState(*it, k);
    auto so = g_.GetExpr(*it, k_suff_old);
    path_old = path_old && (so_k == so);
  }

  // unroll path for new state, from 0 to k, with A(sn_0) and F(sn_i) for i > 0
  un.AddInitPred(ref->appl());
  for (auto i = 1; i != k + 1; i++) {
    un.AddStepPred(ref->flush(), i);
  }
  for (size_t i = 0; i != ref->inv_num(); i++) {
    un.AddGlobPred(ref->inv(i));
  }
  auto path_new = un.MonoAssn(m, k + 1, 0);
  // connect end state to the interface (with no step suffix)
  for (auto it = vars.begin(); it != vars.end(); it++) {
    auto sn_k = un.CurrState(*it, k + 1);
    auto sn = g_.GetExpr(*it, k_suff_new);
    path_new = path_new && (sn_k == sn);
  }

  // extract completion indicator
  auto complete = k > 0 ? ctx_.bool_val(false) : ctx_.bool_val(true);
  for (auto i = 1; i != k + 1; i++) {
    complete = complete || un.GetZ3Expr(ref->cmpl(), i);
    // FIXME also complete for uo
  }

  return (eq && path_old && path_new && complete);
}

bool CommDiag::SanityCheck() const {
  // check refinement
  auto res_a = SanityCheckRefinement(crr_->refine_a());
  auto res_b = SanityCheckRefinement(crr_->refine_b());

  // check relation
  auto res_r = SanityCheckRelation(crr_->relation(), crr_->refine_a()->coi(),
                                   crr_->refine_b()->coi());

  return res_a && res_b && res_r;
}

bool CommDiag::SanityCheckRefinement(const RefPtr ref) const {
  ILA_NOT_NULL(ref);

  auto m = ref->coi();
  auto f = ref->flush();
  auto a = ref->appl();
  auto c = ref->cmpl();
  ILA_CHECK(m) << "Refinement target not set.";
  ILA_CHECK(f) << "Flushing function not set for " << m;
  ILA_CHECK(a) << "Apply function not set set for " << m;
  ILA_CHECK(c) << "Complete condition not set for " << m;

  auto s = z3::solver(ctx_);
  auto g = Z3ExprAdapter(ctx_); // FIXME use unroller all the way

  // check flushing and apply does not hold at the same time
  auto exc = g.GetExpr(And(f, a));
  s.reset();
  s.add(exc);
  if (s.check() == z3::sat) {
    ILA_DLOG("Verbose-CrrEqCheck") << s.get_model();
    ILA_ERROR << "Non-exclusive flushing function and apply function.";
    return false;
  }

  // check flushing does not imply complete (if need to unroll)
  if ((ref->step_orig() != 0) || (ref->step_appl() != 0)) {
    auto cmpl_unique = g.GetExpr(Imply(f, c));
    s.reset();
    s.add(cmpl_unique);
    if (s.check() == z3::sat) {
      ILA_DLOG("Verbose-CrrEqCheck") << s.get_model();
      ILA_ERROR << "Flushing function implies completion.";
    }
    return false;
  }

  // default equivalence: state variables (not including inputs)
  std::set<ExprPtr> vars;
  AbsKnob::GetStVarOfIla(m, vars);
  // check flushing and apply does not affect state equivalence
  auto eq = ctx_.bool_val(true);
  for (auto it = vars.begin(); it != vars.end(); it++) {
    auto so = g.GetExpr(*it, k_suff_old);
    auto sn = g.GetExpr(*it, k_suff_new);
    eq = eq && (so == sn);
  }
  auto an = g.GetExpr(a, k_suff_new);
  auto fo = g.GetExpr(f, k_suff_old);
  // check: a_n -> (a_n & f_o & eq_o_n)
  s.reset();
  s.add(an && !(fo && an && eq));
  if (s.check() == z3::sat) {
    ILA_ERROR << "Flushing and apply function intervene state equivalence.";
    ILA_DLOG("Verbose-CrrEqCheck") << s.get_model();
    return false;
  }

  return true;
}

bool CommDiag::SanityCheckRelation(const RelPtr rel, const InstrLvlAbsPtr ma,
                                   const InstrLvlAbsPtr mb) const {
  ILA_NOT_NULL(rel);
  std::set<ExprPtr> rel_vars;
  auto rel_expr = rel->get();
  AbsKnob::GetVarOfExpr(rel_expr, rel_vars);

  std::set<ExprPtr> ref_vars;
  AbsKnob::GetStVarOfIla(ma, ref_vars);
  AbsKnob::GetStVarOfIla(mb, ref_vars);

  // check: rel_vars <= ref_vars
  for (auto it = rel_vars.begin(); it != rel_vars.end(); it++) {
    auto pos = ref_vars.find(*it);
    if (pos == ref_vars.end()) { // rel has var not in ref
      ILA_ERROR << "Relation depends on var not defined in refinement.";
      return false;
    }
  }
  return true;
}

int CommDiag::DetStepOrig(const RefPtr ref, const int& max) {
  auto k = ref->step_orig();
  ILA_WARN_IF((max > 0) && (k > max)) << "Max bound < #step";

  for (auto n = (k >= 0) ? k : 0; n <= max; n++) {
    auto res = CheckStepOrig(ref, n);
    if (res) {
      ILA_INFO << "#orig flush (" << ref->coi() << "): " << n;
      return n;
    }
  }

  ILA_ERROR << "#step not determined, increase max bound";
  return -1;
}

int CommDiag::DetStepAppl(const RefPtr ref, const int& max) {
  auto k = ref->step_appl();
  ILA_WARN_IF((max > 0) && (k > max)) << "Max bound < #step";

  for (auto n = (k >= 0) ? k : 0; n <= max; n++) {
    auto res = CheckStepAppl(ref, n);
    if (res) {
      ILA_INFO << "#appl flush (" << ref->coi() << "): " << n;
      return n;
    }
  }

  ILA_ERROR << "#step not determined, increase max bound";
  return -1;
}

bool CommDiag::CheckStepOrig(const RefPtr ref, const int& k) {
  // ensure initial state to follow the flush && apply paradiam
  auto init = GenInit(ref);
  // unroll the transition relation
  auto& u = unroll_orig_;
  u.AddGlobPred(ref->flush());
  for (size_t i = 0; i != ref->inv_num(); i++) {
    u.AddGlobPred(ref->inv(i));
  }
  auto tran = u.MonoAssn(ref->coi(), k, 0);
  // start checking
  auto s = z3::solver(ctx_);
  // at least once
  auto at_least_once = AtLeastOnce(ref->cmpl(), 0, k, u);
  s.reset();
  s.add(init && tran && !at_least_once);
  if (s.check() == z3::sat) {
    return false;
  }
  // at most once
  auto at_most_once = AtMostOnce(ref->cmpl(), 0, k, u);
  s.add(init && tran && !at_most_once);
  if (s.check() == z3::sat) {
    return false;
  }
  // valid #unroll step
  return true;
}

bool CommDiag::CheckStepAppl(const RefPtr ref, const int& k) {
  // ensure initial state to follow the flush && apply paradiam
  auto init = GenInit(ref);
  // unroll the transition relation
  auto& u = unroll_appl_;
  u.AddInitPred(ref->appl());
  for (auto i = 1; i != k + 1; i++) {
    u.AddStepPred(ref->flush(), i);
  }
  for (size_t i = 0; i != ref->inv_num(); i++) {
    u.AddGlobPred(ref->inv(i));
  }
  auto tran = u.MonoAssn(ref->coi(), k + 1, 0);
  // start checking
  auto s = z3::solver(ctx_);
  // at least once
  auto at_least_once = AtLeastOnce(ref->cmpl(), 1, k + 1, u);
  s.reset();
  s.add(init && tran && !at_least_once);
  if (s.check() == z3::sat) {
    return false;
  }
  // at most once
  auto at_most_once = AtMostOnce(ref->cmpl(), 1, k + 1, u);
  s.add(init && tran && !at_most_once);
  if (s.check() == z3::sat) {
    return false;
  }
  // valid #unroll step
  return true;
}

z3::expr CommDiag::GenInit(const RefPtr ref) {
  // default equivalence: state variables (not including inputs)
  std::set<ExprPtr> vars;
  AbsKnob::GetStVarOfIla(ref->coi(), vars);
  auto eq = ctx_.bool_val(true);
  for (auto it = vars.begin(); it != vars.end(); it++) {
    auto so = unroll_orig_.GetZ3Expr(*it, 0);
    auto sn = unroll_appl_.GetZ3Expr(*it, 0);
    eq = eq && (so == sn);
  }
  auto an = unroll_appl_.GetZ3Expr(ref->appl(), 0);
  auto fo = unroll_orig_.GetZ3Expr(ref->flush(), 0);
  return (an && fo && eq);
}

z3::expr CommDiag::GenTranRel(const RefPtr ref, const int& k_orig,
                              const int& k_appl) {
  auto init = GenInit(ref);
  auto orig = UnrollFlush(ref, 0, k_orig, unroll_orig_, 0);
  auto appl = UnrollFlush(ref, 1, k_appl, unroll_appl_, 0);
  return (init && orig && appl);
}

z3::expr CommDiag::GenAssm() {
  // TODO
  return ctx_.bool_val(true);
}

z3::expr CommDiag::GenProp() {
  // TODO
  return ctx_.bool_val(true);
}

z3::expr CommDiag::AtLeastOnce(const ExprPtr cmpl, const int& start,
                               const int& end, MonoUnroll& unroller) const {
  auto cstr = unroller.GetZ3Expr(BoolConst(false), 0);
  for (auto i = start; i != end; i++) {
    cstr = cstr || unroller.GetZ3Expr(cmpl, i);
  }
  return cstr;
}

z3::expr CommDiag::AtMostOnce(const ExprPtr cmpl, const int& start,
                              const int& end, MonoUnroll& unroller) const {
  auto cstr = unroller.GetZ3Expr(BoolConst(true), 0);
  for (auto i = start; i != end; i++) {
    auto cmpl_i = unroller.GetZ3Expr(cmpl, i);
    for (auto j = i + 1; j != end; j++) {
      auto cmpl_j = unroller.GetZ3Expr(cmpl, j);
      cstr = cstr && (!cmpl_i || !cmpl_j);
    }
  }
  return cstr;
}

z3::expr CommDiag::UnrollFlush(const RefPtr ref, const int& start,
                               const int& end, MonoUnroll& unroller,
                               const int& base) {
  // TODO
  auto cstr = ctx_.bool_val(true);
  return cstr;
}

} // namespace ila

