/// \file
/// ILA vs. ILA equivalence checking driver.

#include <ilang/ila-mngr/v_eq_check_refinement.h>

#include <tuple>

#include <ilang/ila-mngr/u_abs_knob.h>
#include <ilang/ila-mngr/u_unroller.h>
#include <ilang/util/log.h>
#include <ilang/util/z3_helper.h>

namespace ilang {

const std::string CommDiag::k_suff_orig_ = "org";
const std::string CommDiag::k_suff_appl_ = "apl";

const std::string CommDiag::k_suff_old_ = "old";
const std::string CommDiag::k_suff_new_ = "new";
const std::string CommDiag::k_suff_apl_ = "apl";

using namespace asthub;

CommDiag::CommDiag(z3::context& ctx, const CrrPtr crr) : ctx_(ctx), crr_(crr) {
  Init();
}

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

bool CommDiag::IncCheck(const int& min, const int& max, const int& step) {
  // initialization
  for (UID uid : {A_OLD, A_NEW, B_OLD, B_NEW}) {
    auto& uu = GetUnrlUnit(uid);
    uu.lo = 0;
    uu.hi = min;
  }

  // apply instruction
  const auto& stts_a = stts_a_; // used for marking
  const auto& stts_b = stts_b_;

  auto s = z3::solver(ctx_); // solver
  { // default basic condition (old/new/apply path & assm & prop)
    auto appl_instr_a = GetZ3ApplInstr(stts_a, crr_->refine_a());
    auto appl_instr_b = GetZ3ApplInstr(stts_b, crr_->refine_b());
    s.add(appl_instr_a);
    s.add(appl_instr_b);
    s.push(); // record backtracking point
  }

  auto cf = ctx_.bool_const("cmpl_flag"); // flag indicating flushing completion
  // assumption and property to check
  auto assm = GetZ3Assm();
  auto prop = GetZ3Prop();
  // check only if complete
  assm = Z3Implies(ctx_, cf, assm);
  prop = Z3Implies(ctx_, cf, prop);

  // incrementally unroll flushing
  for (auto i = min; i <= max; i += step) { // if (num < i) --> already fixed
    // check if complete
    auto all_path_complete = true;
    for (UID uid : {A_OLD, A_NEW, B_OLD, B_NEW}) {
      auto& uu = GetUnrlUnit(uid);
      all_path_complete = all_path_complete && (uu.hi < i);
    }
    if (all_path_complete) {
      ILA_DLOG("Verbose-CrrEqCheck") << "Complete";
      return true;
    }

    // unroll new flushing path
    for (UID uid : {A_OLD, A_NEW, B_OLD, B_NEW}) {
      auto& uu = GetUnrlUnit(uid);
      if (uu.hi == i) { // need to unroll new step
        auto tran = GetZ3IncFlsh(uid);
        s.add(tran);
      }
    }
    s.push(); // recording the current transition relation

    // accumulate completion indicator
    auto cmpl_acc = ctx_.bool_val(true);
    for (UID uid : {A_OLD, A_NEW, B_OLD, B_NEW}) {
      auto cmpl_i = GetZ3IncCmpl(uid);
      cmpl_acc = cmpl_acc && cmpl_i;
    }
    s.add(cf == cmpl_acc);

    // check prop
    s.add(assm);
    s.add(!prop);
    auto res = s.check();
    ILA_INFO << "Result: " << res;
    if (res == z3::sat) {
      return false;
    }

    // pop back to transition relation (removing marking and prop)
    s.pop();

    // push partial property
    auto partial_assm = GetZ3Assm();
    auto partial_cmpl = Z3Implies(ctx_, cmpl_acc, partial_assm);
    auto partial_prop = GetZ3Prop();
    s.add(Z3Implies(ctx_, partial_cmpl && partial_assm, partial_prop));
    s.push();

    // check if num is sufficient (if not fixed yet) and increment accordingly
    for (UID uid : {A_OLD, A_NEW, B_OLD, B_NEW}) {
      auto& uu = GetUnrlUnit(uid);
      uu.lo = uu.hi;
      if (uu.hi == i) { // new step
        auto cmpl_i = GetZ3IncCmpl(uid);
        auto sufficient = CheckCmpl(s, cmpl_i);
        uu.hi = sufficient ? uu.hi : uu.hi + step;
      }
    }
  }

  return true;
}

void CommDiag::Init() {
  SanityCheck();
  // unroller initialized with flushing function
  for (auto uid : {A_OLD, A_NEW, B_OLD, B_NEW}) {
    auto& un = GetUnrl(uid);
    auto ref = GetRefine(uid);
    un.ClearPred();
    un.AddGlobPred(ref->flush());
  }
  // state vars of each ILA
  stts_a_ = absknob::GetSttTree(crr_->refine_a()->ila());
  stts_b_ = absknob::GetSttTree(crr_->refine_b()->ila());
}

CommDiag::Unroll& CommDiag::GetUnrl(const UID& uid) {
  switch (uid) {
  case A_OLD:
    return unrl_old_;
    break;
  case A_NEW:
    return unrl_new_;
    break;
  case B_OLD:
    return unrl_old_;
    break;
  case B_NEW:
    return unrl_new_;
    break;
  default:
    ILA_ASSERT(false) << "unknon uid " << uid;
    return unrl_old_;
    break;
  }
}

CommDiag::Unroll& CommDiag::GetUnrlOld() { return unrl_a_old_; }

CommDiag::Unroll& CommDiag::GetUnrlNew() { return unrl_a_new_; }

CommDiag::Unroll& CommDiag::GetUnrlApl() { return unrl_apl_; }

RefPtr CommDiag::GetRefine(const UID& uid) {
  switch (uid) {
  case A_OLD:
    return crr_->refine_a();
    break;
  case A_NEW:
    return crr_->refine_a();
    break;
  case B_OLD:
    return crr_->refine_b();
    break;
  case B_NEW:
    return crr_->refine_b();
    break;
  default:
    ILA_ASSERT(false) << "unknon uid " << uid;
    return nullptr;
    break;
  }
}

CommDiag::UnrlUnit& CommDiag::GetUnrlUnit(const UID& uid) {
  switch (uid) {
  case A_OLD:
    return uu_a_old_;
    break;
  case A_NEW:
    return uu_a_new_;
    break;
  case B_OLD:
    return uu_b_old_;
    break;
  case B_NEW:
    return uu_b_new_;
    break;
  default:
    ILA_ASSERT(false) << "unknon uid " << uid;
    return uu_a_old_;
    break;
  }
}

const ExprSet& CommDiag::GetStts(const UID& uid) {
  switch (uid) {
  case A_OLD:
    return stts_a_;
    break;
  case A_NEW:
    return stts_a_;
    break;
  case B_OLD:
    return stts_b_;
    break;
  case B_NEW:
    return stts_b_;
    break;
  default:
    ILA_ASSERT(false) << "unknon uid " << uid;
    return stts_a_;
    break;
  }
}

z3::expr CommDiag::GetZ3IncFlsh(const UID& uid) {
  auto& un = GetUnrl(uid);
  auto& uu = GetUnrlUnit(uid);
  auto ref = GetRefine(uid);
  auto& stts = GetStts(uid);
  // transition relation
  auto tran = un.MonoIncr(ref->ila(), uu.hi - uu.lo /*length*/, uu.lo /*base*/);
  // mark
  for (auto pos = uu.lo; pos <= uu.hi; pos++) {
    auto cmpl = un.GetZ3Expr(ref->cmpl(), pos);
    auto eq = ctx_.bool_val(true);
    for (auto it = stts.begin(); it != stts.end(); it++) {
      auto s_i = un.CurrState(*it, pos);
      auto s = un.GetZ3Expr(*it); // representative
      eq = eq && (s == s_i);
    }
    auto mark = Z3Implies(ctx_, cmpl, eq);
    tran = tran && mark;
  }
  return tran;
}

z3::expr CommDiag::GetZ3IncCmpl(const UID& uid) {
  auto& un = GetUnrl(uid);
  auto& uu = GetUnrlUnit(uid);
  auto cmpl = GetRefine(uid)->cmpl();
  // OR all completion predicate
  auto cmpl_acc = ctx_.bool_val(false);
  for (auto i = 0; i <= uu.hi; i++) {
    auto cmpl_i = un.GetZ3Expr(cmpl, i);
    cmpl_acc = cmpl_acc || cmpl_i;
  }
  return cmpl_acc;
}

bool CommDiag::IncEqCheck(const int& min, const int& max, const int& step) {
  // sanity check
  auto sc_res = SanityCheck(); // XXX need refresh
  ILA_WARN_IF(!sc_res) << "Sanity check fail";

  const auto ma = crr_->refine_a()->coi(); // representative ILA
  const auto mb = crr_->refine_b()->coi();
  const auto stts_a = absknob::GetSttTree(ma); // used for marking
  const auto stts_b = absknob::GetSttTree(mb);

  auto s = z3::solver(ctx_); // solver
  { // default basic condition (old/new/apply path & assm & prop)
    auto appl_instr_a = GetZ3ApplInstr(stts_a, crr_->refine_a());
    auto appl_instr_b = GetZ3ApplInstr(stts_b, crr_->refine_b());
    s.add(appl_instr_a);
    s.add(appl_instr_b);
    s.push(); // record backtracking point
  }

  auto cf = ctx_.bool_const("cmpl_flag"); // flag indicating flushing completion
  // assumption and property to check
  auto assm = GetZ3Assm();
  auto prop = GetZ3Prop();
  // check only if complete
  assm = Z3Implies(ctx_, cf, assm);
  prop = Z3Implies(ctx_, cf, prop);

  // Incrementally unrolling and check
  ILA_ASSERT(max >= min) << "Invalid range [" << min << ", " << max << "]";
  auto num_old_a = min;
  auto num_new_a = min;
  auto num_old_b = min;
  auto num_new_b = min;
  auto inc_unrl_old_a = Unroll(ctx_, k_suff_old_);
  auto inc_unrl_new_a = Unroll(ctx_, k_suff_new_);
  auto inc_unrl_old_b = Unroll(ctx_, k_suff_old_);
  auto inc_unrl_new_b = Unroll(ctx_, k_suff_new_);
  inc_unrl_old_a.AddGlobPred(crr_->refine_a()->flush());
  inc_unrl_new_a.AddGlobPred(crr_->refine_a()->flush());
  inc_unrl_old_b.AddGlobPred(crr_->refine_b()->flush());
  inc_unrl_new_b.AddGlobPred(crr_->refine_b()->flush());

  for (auto i = min; i <= max; i += step) { // if (num < i) --> already fixed
    // transition relation
    if ((num_old_a < i) && (num_old_b < i) && (num_new_a < i) &&
        (num_new_b < i)) {
      ILA_DLOG("Verbose-CrrEqCheck") << "Complete";
      return true;
    }

    // unroll new flushing path
    if (num_old_a == i) { // need to unroll new step
      auto tran =
          GetZ3IncUnrl(inc_unrl_old_a, crr_->refine_a(), i, step, stts_a);
      s.add(tran);
    }
    if (num_new_a == i) { // need to unroll new step
      auto tran =
          GetZ3IncUnrl(inc_unrl_new_a, crr_->refine_a(), i, step, stts_a);
      s.add(tran);
    }
    if (num_old_b == i) { // need to unroll new step
      auto tran =
          GetZ3IncUnrl(inc_unrl_old_b, crr_->refine_b(), i, step, stts_b);
      s.add(tran);
    }
    if (num_new_b == i) { // need to unroll new step
      auto tran =
          GetZ3IncUnrl(inc_unrl_new_b, crr_->refine_b(), i, step, stts_b);
      s.add(tran);
    }
    s.push(); // recording the current transition relation

    // accumulate completion indicator
    auto cmpl_a = crr_->refine_a()->cmpl();
    auto cmpl_b = crr_->refine_b()->cmpl();
    // XXX only create if necessary (need cache)
    auto cmpl_old_a = GetZ3Cmpl(cmpl_a, inc_unrl_old_a, 0, num_old_a);
    auto cmpl_new_a = GetZ3Cmpl(cmpl_a, inc_unrl_new_a, 0, num_new_a);
    auto cmpl_old_b = GetZ3Cmpl(cmpl_b, inc_unrl_old_b, 0, num_old_b);
    auto cmpl_new_b = GetZ3Cmpl(cmpl_b, inc_unrl_new_b, 0, num_new_b);
    s.add(cf == (cmpl_old_a && cmpl_new_a && cmpl_old_b && cmpl_new_b));

    // check prop
    s.add(assm);
    s.add(!prop);
    ILA_INFO << "Start checking " << num_old_a << " " << num_new_a << " "
             << num_old_b << " " << num_new_b;
    auto res = s.check();
    ILA_INFO << "Result: " << res;
    if (res == z3::sat) {
      auto m = s.get_model();

      ILA_WARN << "Model A";
      for (auto it = stts_a.begin(); it != stts_a.end(); it++) {
        auto var_expr = inc_unrl_old_a.GetZ3Expr(*it, num_old_a);
        auto var_repr = inc_unrl_old_a.GetZ3Expr(*it);
        ILA_WARN << var_expr << ": " << m.eval(var_expr) << "; " << var_repr
                 << ": " << m.eval(var_repr);
      }
      for (auto it = stts_a.begin(); it != stts_a.end(); it++) {
        auto var_expr = inc_unrl_new_a.GetZ3Expr(*it, num_new_a);
        auto var_repr = inc_unrl_new_a.GetZ3Expr(*it);
        ILA_WARN << var_expr << ": " << m.eval(var_expr) << "; " << var_repr
                 << ": " << m.eval(var_repr);
      }

      ILA_WARN << "Model B";
      for (auto it = stts_b.begin(); it != stts_b.end(); it++) {
        auto var_expr = inc_unrl_old_b.GetZ3Expr(*it, num_old_b);
        auto var_repr = inc_unrl_old_b.GetZ3Expr(*it);
        ILA_WARN << var_expr << ": " << m.eval(var_expr) << "; " << var_repr
                 << ": " << m.eval(var_repr);
      }
      for (auto it = stts_b.begin(); it != stts_b.end(); it++) {
        auto var_expr = inc_unrl_new_b.GetZ3Expr(*it, num_new_b);
        auto var_repr = inc_unrl_new_b.GetZ3Expr(*it);
        ILA_WARN << var_expr << ": " << m.eval(var_expr) << "; " << var_repr
                 << ": " << m.eval(var_repr);
      }

      return false;
    }

    // pop back to transition relation (removing marking and prop)
    s.pop();

    // push partial property
    auto partial_assm = GetZ3Assm();
    auto partial_cmpl =
        Z3Implies(ctx_, cmpl_old_a && cmpl_new_a && cmpl_old_b && cmpl_new_b,
                  partial_assm);
    auto partial_prop = GetZ3Prop();
    s.add(Z3Implies(ctx_, partial_cmpl && partial_assm, partial_prop));
    s.push();

    // check if num is sufficient (if not fixed yet) and increment accordingly
    if (num_old_a == i) { // new step
      auto sufficient = CheckCmpl(s, cmpl_old_a);
      num_old_a = sufficient ? num_old_a : num_old_a + step;
    }
    if (num_new_a == i) { // new step
      auto sufficient = CheckCmpl(s, cmpl_new_a);
      num_new_a = sufficient ? num_new_a : num_new_a + step;
    }
    if (num_old_b == i) { // new step
      auto sufficient = CheckCmpl(s, cmpl_old_b);
      num_old_b = sufficient ? num_old_b : num_old_b + step;
    }
    if (num_new_b == i) { // new step
      auto sufficient = CheckCmpl(s, cmpl_new_b);
      num_new_b = sufficient ? num_new_b : num_new_b + step;
    }
  }

  // no bug found up to the given bound
  return true;
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
  auto appl_vars = absknob::GetVar(a);
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

bool CommDiag::SanityCheckRelation(const RelPtr rel, const InstrLvlAbsPtr& ma,
                                   const InstrLvlAbsPtr& mb) const {
  ILA_ERROR_IF(ma->name() == mb->name())
      << "Only EQ-Check ILAs with different names.";

  ILA_NOT_NULL(rel);
  auto rel_expr = rel->get();
  auto rel_vars = absknob::GetVar(rel_expr);

  auto ref_vars = ExprSet();
  absknob::InsertStt(ma, ref_vars);
  absknob::InsertStt(mb, ref_vars);

  // check: rel_vars <= ref_vars
  for (auto it = rel_vars.begin(); it != rel_vars.end(); it++) {
    auto pos = ref_vars.find(*it);
    if (pos == ref_vars.end()) { // rel has var not in ref
      ILA_ERROR << "Relation depends on " << *it << " -- not in refinement.";
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
    // invariant
    for (decltype(ref->inv_num()) i = 0; i != ref->inv_num(); i++) {
      un.AddGlobPred(ref->inv(i));
    }
    // apply
    un.AddStepPred(ref->appl(), 0);
    auto apply_one_step = un.MonoAssn(ref->coi(), 1 /*length*/, 0 /*base*/);
    un.ClearPred();
    acc = acc && apply_one_step;
  }
  { // connect old/new with the apply step
    auto eq = ctx_.bool_val(true);
    for (auto it = stts.begin(); it != stts.end(); it++) {
      // apply_0 == old_0)
      auto sa_0 = unrl_apl_.CurrState(*it, 0);
      auto so_0 = unrl_old_.CurrState(*it, 0);
      eq = eq && (sa_0 == so_0);
      // apply_1 == new_0)
      auto sa_1 = unrl_apl_.CurrState(*it, 1);
      auto sn_0 = unrl_new_.CurrState(*it, 0);
      eq = eq && (sa_1 == sn_0);
    }
    acc = acc && eq;
  }
  // flush(old_0)
  auto flush_on_old = unrl_old_.GetZ3Expr(ref->flush(), 0);
  // flush(new_0)
  auto flush_on_new = unrl_new_.GetZ3Expr(ref->flush(), 0);
  // return
  return acc && flush_on_old && flush_on_new;
}

z3::expr CommDiag::GenInit(const RefPtr ref) {
  // default equivalence: state variables (not including inputs)
  auto vars = absknob::GetSttTree(ref->coi());
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

z3::expr CommDiag::GetZ3Assm() {
  auto& un = GetUnrlOld();
  auto eq = un.GetZ3Expr(crr_->relation()->get());
  return eq;
}

z3::expr CommDiag::GetZ3Prop() {
  auto& un = GetUnrlNew();
  auto eq = un.GetZ3Expr(crr_->relation()->get());
  return eq;
}

z3::expr CommDiag::GetZ3Cmpl(const ExprPtr& cmpl, MonoUnroll& un,
                             const int& begin, const int& end) const {
  auto cmpl_acc = ctx_.bool_val(false);
  for (auto i = begin; i <= end; i++) {
    auto cmpl_i = un.GetZ3Expr(cmpl, i);
    cmpl_acc = cmpl_acc || cmpl_i;
  }
  return cmpl_acc;
}

z3::expr CommDiag::GetZ3IncUnrl(MonoUnroll& un, const RefPtr ref,
                                const int& begin, const int& length,
                                const ExprSet& stts) const {
  auto tran = un.MonoIncr(ref->coi(), length /*length*/, begin /*base*/);
  // mark
  for (auto pos = begin; pos <= begin + length; pos++) {
    auto cmpl = un.GetZ3Expr(ref->cmpl(), pos);
    auto eq = ctx_.bool_val(true);
    for (auto it = stts.begin(); it != stts.end(); it++) {
      auto s_i = un.CurrState(*it, pos);
      auto s = un.GetZ3Expr(*it); // representative
      eq = eq && (s == s_i);
    }
    auto mark = Z3Implies(ctx_, cmpl, eq);
    tran = tran && mark;
  }
  return tran;
}

bool CommDiag::CheckCmpl(z3::solver& s, z3::expr& cmpl_expr) const {
  s.push();
  s.add(!cmpl_expr);
  auto must_cmpl = (s.check() == z3::unsat);
  s.pop();

  if (must_cmpl) {
    s.add(cmpl_expr); // added
    s.push();         // added
    return true;
  } else {
    return false;
  }
}

z3::expr CommDiag::GenAssm() {
  auto eq = unroll_orig_.GetZ3Expr(crr_->relation()->get());
  return eq;
}

z3::expr CommDiag::GenProp() {
  auto eq = unroll_appl_.GetZ3Expr(crr_->relation()->get());
  return eq;
}

z3::expr CommDiag::AtLeastOnce(MonoUnroll& unroller, const ExprPtr& cmpl,
                               const int& start, const int& end) const {
  auto cstr = unroller.GetZ3Expr(BoolConst(false), 0);
  for (auto i = start; i <= end; i++) {
    cstr = cstr || unroller.GetZ3Expr(cmpl, i);
  }
  return cstr;
}

z3::expr CommDiag::AtMostOnce(MonoUnroll& unroller, const ExprPtr& cmpl,
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

  auto vars = absknob::GetStt(ref->coi());
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
    mark = mark && Z3Implies(ctx_, cmpl_i, eq);
  }

  // XXX complete proved to be one and exactly one

  return path && mark;
}

} // namespace ilang
