/// \file
/// Source for generating verification condition for equivalecne checking.

#include "backend/eq_check_crr.h"
#include "backend/abs_knob.h"
#include "backend/unroller.h"
#include "util/log.h"

namespace ila {

const std::string CommDiag::k_suff_orig_ = "org";
const std::string CommDiag::k_suff_appl_ = "apl";

const std::string CommDiag::k_suff_old_ = "old";
const std::string CommDiag::k_suff_new_ = "new";
const std::string CommDiag::k_suff_apl_ = "apl";

using namespace ExprFuse;

CommDiag::CommDiag(z3::context& ctx, const CrrPtr crr) : ctx_(ctx), crr_(crr) {}

CommDiag::~CommDiag() {}

bool CommDiag::EqCheck(const int& max) {
  // refinement relation sanity check
  auto sc_res = SanityCheck();
  ILA_WARN_IF(!sc_res) << "The refinement relation sanity check fail.";

  // determine the number of steps for unrolling (check valid if specified)
  auto step_orig_a = DetStepOrig(crr_->refine_a(), max);
  auto step_appl_a = DetStepAppl(crr_->refine_a(), max);

  auto step_orig_b = DetStepOrig(crr_->refine_b(), max);
  auto step_appl_b = DetStepAppl(crr_->refine_b(), max);

  if (step_orig_a < 0 || step_appl_a < 0 || step_orig_b < 0 ||
      step_appl_b < 0) {
    ILA_ERROR << "Fail determining unroll step.";
    return false;
  }

  // generate transition relation
  auto cstr_tran_a = GenTranRel(crr_->refine_a(), step_orig_a, step_appl_a);
  auto cstr_tran_b = GenTranRel(crr_->refine_b(), step_orig_b, step_appl_b);

  auto s = z3::solver(ctx_);
  s.add(cstr_tran_a);
  if (s.check() == z3::unsat) {
    ILA_ERROR << "Dead transition relation.";
    ILA_DLOG("Verbose-CrrEqCheck") << s;
    return false;
  }
  s.reset();
  s.add(cstr_tran_b);
  if (s.check() == z3::unsat) {
    ILA_ERROR << "Dead transition relation.";
    ILA_DLOG("Verbose-CrrEqCheck") << s;
    return false;
  }
  s.reset();

  // generate assumptions (old state equivalent)
  auto cstr_assm = GenAssm();

  // generate property to check (new state equivalent)
  auto cstr_prop = GenProp();

  // check
  s.add(cstr_tran_a && cstr_tran_b && cstr_assm);
  s.add(!cstr_prop);
  auto res = s.check();
  if (res == z3::sat) {
    ILA_DLOG("Verbose-CrrEqCheck") << s.get_model();
  }

  return (res == z3::unsat);
}

bool CommDiag::IncEqCheck(const int& min, const int& max) {
  // sanity check
  auto sc_res = SanityCheck(); // XXX need refresh
  ILA_WARN_IF(!sc_res) << "Sanity check fail";

  const auto ma = crr_->refine_a()->coi(); // representative ILA
  const auto mb = crr_->refine_b()->coi();
  const auto stts_a = AbsKnob::GetSttTree(ma); // used for marking
  const auto stts_b = AbsKnob::GetSttTree(mb);
  auto cf = ctx_.bool_const("cmpl_flag"); // flag indicating flushing completion

  auto s = z3::solver(ctx_); // solver
  { // default basic condition (old/new/apply path & assm & prop)
    auto appl_instr_a = GetZ3ApplInstr(stts_a, crr_->refine_a());
    auto appl_instr_b = GetZ3ApplInstr(stts_b, crr_->refine_b());
    s.add(appl_instr_a);
    s.add(appl_instr_b);
    // add assumption if complete
    auto assm = GetZ3Assm();
    s.add(z3::implies(cf, assm));
    // assert propoerty if complete
    auto prop = GetZ3Prop();
    s.add(!(z3::implies(cf, prop)));
    s.push(); // record backtracking point
  }

  // Incrementally unrolling and check
  ILA_ASSERT(max >= min) << "Invalid range [" << min << ", " << max << "]";
  auto num_appl_a = min;
  auto num_appl_b = min;
  auto num_orig_a = min;
  auto num_orig_b = min;
  for (auto i = min; i <= max; i++) { // if (num < i) --> already fixed
    // transition relation
    // auto flush_orig_a =

    // check prop

    // check if num is sufficient (if not fixed yet) and increment accordingly
    // check num_appl_a sufficient
    // check num_appl_b sufficient
    // check num_orig_a sufficient
    // check num_orig_a sufficient
  }

  // no bug found up to the given bound
  return true;
}

void CommDiag::Reset() {
  unroll_appl_.ClearPred();
  unroll_orig_.ClearPred();
}

bool CommDiag::SanityCheck() {
  // check refinement
  auto res_a = SanityCheckRefinement(crr_->refine_a());
  auto res_b = SanityCheckRefinement(crr_->refine_b());

  // check relation
  auto res_r = SanityCheckRelation(crr_->relation(), crr_->refine_a()->coi(),
                                   crr_->refine_b()->coi());

  return res_a && res_b && res_r;
}

bool CommDiag::SanityCheckRefinement(const RefPtr ref) {
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
  auto g = Z3ExprAdapter(ctx_);

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
    s.add(!cmpl_unique);
    if (s.check() == z3::unsat) {
      ILA_ERROR << "Flushing function implies completion.";
      return false;
    }
  }

  // check flushing and apply does not affect state equivalence
  auto init = GenInit(ref);
  auto an = unroll_appl_.GetZ3Expr(a, 0);
  // check: /\s_n, a_n -> (a_n & f_o & eq_o_n)
  s.reset();
  auto appl_z3 = z3::expr_vector(ctx_);
  auto appl_vars = AbsKnob::GetVar(a);
  for (auto it = appl_vars.begin(); it != appl_vars.end(); it++) {
    appl_z3.push_back(unroll_appl_.CurrState(*it, 0));
  }
  s.add(z3::forall(appl_z3, an && !init));
  // s.add(an && !(fo && an && eq));
  if (s.check() == z3::sat) {
    ILA_ERROR << "Flushing and apply function intervene state equivalence.";
    ILA_DLOG("Verbose-CrrEqCheck") << s.get_model();
    return false;
  }

  return true;
}

bool CommDiag::SanityCheckRelation(const RelPtr rel, const InstrLvlAbsPtr ma,
                                   const InstrLvlAbsPtr mb) const {
  ILA_ERROR_IF(ma->name() == mb->name())
      << "Only EQ-Check ILAs with different names.";

  ILA_NOT_NULL(rel);
  auto rel_expr = rel->get();
  auto rel_vars = AbsKnob::GetVar(rel_expr);

  auto ref_vars = ExprSet();
  AbsKnob::InsertStt(ma, ref_vars);
  AbsKnob::InsertStt(mb, ref_vars);

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
  u.ClearPred();
  u.AddGlobPred(ref->flush());
  for (decltype(ref->inv_num()) i = 0; i != ref->inv_num(); i++) {
    u.AddGlobPred(ref->inv(i));
  }
  auto tran = u.MonoAssn(ref->coi(), k, 0);
  // start checking
  auto s = z3::solver(ctx_);
  // sanity check on transition
  s.add(init && tran);
  if (s.check() == z3::unsat) {
    ILA_ERROR << "Dead transition: " << ref->coi() << " #step: " << k;
    ILA_DLOG("Verbose-CrrEqCheck") << s;
    ILA_CHECK(false);
  }

  // at least once
  auto at_least_once = AtLeastOnce(u, ref->cmpl(), 0, k);
  s.reset();
  s.add(init && tran && !at_least_once);
  if (s.check() == z3::sat) {
    return false;
  }
  // at most once
  auto at_most_once = AtMostOnce(u, ref->cmpl(), 0, k);
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
  u.ClearPred();
  u.AddInitPred(ref->appl());
  for (auto i = 1; i <= k + 1; i++) {
    u.AddStepPred(ref->flush(), i);
  }
  for (decltype(ref->inv_num()) i = 0; i != ref->inv_num(); i++) {
    u.AddGlobPred(ref->inv(i));
  }
  auto tran = u.MonoAssn(ref->coi(), k + 1, 0);
  // start checking
  auto s = z3::solver(ctx_);
  // at least once
  auto at_least_once = AtLeastOnce(u, ref->cmpl(), 1, k + 1);
  s.reset();
  s.add(init && tran && !at_least_once);
  if (s.check() == z3::sat) {
    return false;
  }
  // at most once
  auto at_most_once = AtMostOnce(u, ref->cmpl(), 1, k + 1);
  s.add(init && tran && !at_most_once);
  if (s.check() == z3::sat) {
    return false;
  }
  // valid #unroll step
  return true;
}

z3::expr CommDiag::GetZ3ApplInstr(const ExprSet& stts, const RefPtr ref) {
  auto acc = ctx_.bool_val(true);
  { // take one step (apply)
    auto& un = unrl_apl_;
    un.ClearPred();
    un.AddStepPred(ref->appl(), 0);
    auto apply_one_step = un.MonoAssn(ref->coi(), 1 /*length*/, 0 /*base*/);
    un.ClearPred();
    acc = acc && apply_one_step;
  }

  // apply_0 == old_0
  // apply_1 == new_0
  // flush(old_0)
  // flush(new_0)

  // appl/orig state equal
  auto eq = ctx_.bool_val(true);
  for (auto it = stts.begin(); it != stts.end(); it++) {
    auto so = unroll_orig_.CurrState(*it, 0);
    auto sa = unroll_appl_.CurrState(*it, 0);
    eq = eq && (so == sa);
  }
  // constrain apply and flush on each path
  auto apply_on_sa = unroll_appl_.GetZ3Expr(ref->appl(), 0);
  auto flush_on_so = unroll_orig_.GetZ3Expr(ref->flush(), 0);
  // apply take one step
  auto& un = unroll_appl_;
  un.ClearPred();
  un.AddStepPred(ref->appl(), 0);
  auto apply_one_step = un.MonoAssn(ref->coi(), 1 /*length*/, 0 /*base*/);
  un.ClearPred();
  // return
  return (eq && apply_on_sa && flush_on_so && apply_one_step);
}

z3::expr CommDiag::GenInit(const RefPtr ref) {
  // default equivalence: state variables (not including inputs)
  auto vars = AbsKnob::GetSttTree(ref->coi());
  auto eq = ctx_.bool_val(true);
  for (auto it = vars.begin(); it != vars.end(); it++) {
    auto so = unroll_orig_.CurrState(*it, 0);
    auto sn = unroll_appl_.CurrState(*it, 0);
    eq = eq && (so == sn);
  }
  auto an = unroll_appl_.GetZ3Expr(ref->appl(), 0);
  auto fo = unroll_orig_.GetZ3Expr(ref->flush(), 0);
  return (an && fo && eq);
}

z3::expr CommDiag::GenTranRel(const RefPtr ref, const int& k_orig,
                              const int& k_appl) {
  auto init = GenInit(ref);
  auto orig = UnrollFlush(unroll_orig_, ref, 0, k_orig, 0);
  auto appl = UnrollFlush(unroll_appl_, ref, 0, k_appl + 1, 1);
  return (init && orig && appl);
}

z3::expr CommDiag::GetZ3Assm() { return GenAssm(); }

z3::expr CommDiag::GetZ3Prop() { return GenProp(); }

z3::expr CommDiag::GenAssm() {
  auto eq = unroll_orig_.GetZ3Expr(crr_->relation()->get());
  return eq;
}

z3::expr CommDiag::GenProp() {
  auto eq = unroll_appl_.GetZ3Expr(crr_->relation()->get());
  return eq;
}

z3::expr CommDiag::AtLeastOnce(MonoUnroll& unroller, const ExprPtr cmpl,
                               const int& start, const int& end) const {
  auto cstr = unroller.GetZ3Expr(BoolConst(false), 0);
  for (auto i = start; i <= end; i++) {
    cstr = cstr || unroller.GetZ3Expr(cmpl, i);
  }
  return cstr;
}

z3::expr CommDiag::AtMostOnce(MonoUnroll& unroller, const ExprPtr cmpl,
                              const int& start, const int& end) const {
  auto cstr = unroller.GetZ3Expr(BoolConst(true), 0);
  for (auto i = start; i <= end; i++) {
    auto cmpl_i = unroller.GetZ3Expr(cmpl, i);
    for (auto j = i + 1; j <= end; j++) {
      auto cmpl_j = unroller.GetZ3Expr(cmpl, j);
      cstr = cstr && (!cmpl_i || !cmpl_j);
    }
  }
  return cstr;
}

z3::expr CommDiag::UnrollFlush(MonoUnroll& unroller, const RefPtr ref,
                               const int& base, const int& length,
                               const int& start) {
  ILA_ASSERT(base + length >= start);
  unroller.ClearPred();
  // add invariant
  for (decltype(ref->inv_num()) i = 0; i != ref->inv_num(); i++) {
    unroller.AddGlobPred(ref->inv(i));
  }
  // add flush
  for (auto i = start; i <= base + length; i++) {
    unroller.AddStepPred(ref->flush(), i);
  }
  // unroll
  auto path = unroller.MonoAssn(ref->coi(), length, base);

  auto vars = AbsKnob::GetStt(ref->coi());
  auto mark = ctx_.bool_val(true);
  // mark complete step with representing state
  for (auto i = start; i <= base + length; i++) {
    auto cmpl_i = unroller.GetZ3Expr(ref->cmpl(), i);
    auto eq = ctx_.bool_val(true);
    for (auto it = vars.begin(); it != vars.end(); it++) {
      auto s_i = unroller.CurrState(*it, i);
      auto s = unroller.GetZ3Expr(*it);
      eq = eq && (s == s_i);
    }
    mark = mark && (z3::implies(cmpl_i, eq));
  }

  // XXX complete proved to be one and exactly one

  return path && mark;
}

} // namespace ila

