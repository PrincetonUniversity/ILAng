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

CommDiag::CommDiag(z3::context& ctx, const CrrPtr crr) : ctx_(ctx), crr_(crr) {}

CommDiag::~CommDiag() {}

bool CommDiag::EqCheck(const int& max) {
  max_ = max;

  // refinement relation sanity check
  auto sc_res = SanityCheck();
  ILA_WARN_IF(!sc_res) << "The refinement relation sanity check fail.";

  // determine the number of steps for unrolling (check valid if specified)
  auto pp_res = PreProcDetBnd(max);
  ILA_WARN_IF(!pp_res) << "Error during preprocessing.";

  // generate verification condition
  auto cstr_tran = GenTranRel();

  // generate assumptions (old state equivalent)
  auto cstr_assm = GenAssm();

  // generate property to check (new state equivalent)
  auto cstr_prop = GenProp();

  // check
  z3::solver s(ctx_);
  s.add(cstr_tran);
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
  ILA_NOT_NULL(ref);

  // check target
  auto m = ref->coi();
  ILA_CHECK(m) << "Refinement target not set.";
  // check flushing
  auto f = ref->flush();
  ILA_CHECK(f) << "Flushing function not set for " << m;
  // check apply
  auto a = ref->appl();
  ILA_CHECK(a) << "Apply function not set set for " << m;
  // check complete
  ILA_CHECK(ref->cmpl()) << "Complete condition not set for " << m;

  z3::solver s(ctx_);

  // check flushing and apply does not hold at the same time
  auto exc = g_.GetExpr(And(f, a));
  s.add(exc);
  if (s.check() == z3::sat) {
    ILA_DLOG("Verbose-CheckRefine") << s.get_model();
    ILA_ERROR << "Non-exclusive flushing function and apply function.";
    return false;
  }

  // collect all state variables
  std::set<ExprPtr> vars;
  AbsKnob::GetVarOfIla(m, vars);
  // check flushing and apply does not affect state equivalence
  // default equivalence: state variables (not including inputs)
  auto eq = ctx_.bool_val(true);
  for (auto it = vars.begin(); it != vars.end(); it++) {
    auto so = g_.GetExpr(*it, k_suff_old);
    auto sn = g_.GetExpr(*it, k_suff_new);
    eq = eq && (so == sn);
  }
  auto an = g_.GetExpr(a, k_suff_new);
  auto fo = g_.GetExpr(f, k_suff_old);
  // should be unsat
  s.add(an && !(fo && an && eq));
  if (s.check() == z3::sat) {
    ILA_ERROR << "Flushing and apply function intervene state equivalence.";
    ILA_DLOG("Verbose-CheckRefine") << s.get_model();
    return false;
  }

  return true;
}

z3::expr CommDiag::GenVerCondRefine(const RefPtr ref, const int& max) {
  MonoUnroll uo(ctx_);
  MonoUnroll un(ctx_);
  uo.SetExtraSuffix(k_suff_old);
  un.SetExtraSuffix(k_suff_new);
  auto m = ref->coi();
  auto k = ref->step() == -1 ? max : ref->step();
  if (ref->step() > max) {
    ILA_ERROR << "Unroll bound " << max << " not sufficient for " << m;
    return ctx_.bool_val(false);
  }
  std::set<ExprPtr> vars;
  AbsKnob::GetVarOfIla(m, vars);

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
  }

  return (eq && path_old && path_new && complete);
}

bool CommDiag::SanityCheck() {
  // TODO
  return true;
}

bool CommDiag::PreProcDetBnd(const int& max) {
  // TODO
  return true;
}

z3::expr CommDiag::GenTranRel() {
  // TODO
  return ctx_.bool_val(true);
}

z3::expr CommDiag::GenAssm() {
  // TODO
  return ctx_.bool_val(true);
}

z3::expr CommDiag::GenProp() {
  // TODO
  return ctx_.bool_val(true);
}

int CommDiag::DetBndOld(const RefPtr ref) {
  // TODO
  int bnd = 0;
  ILA_INFO << "#old flush (" << ref->coi() << "): " << bnd;
  return bnd;
}

int CommDiag::DetBndNew(const RefPtr ref) {
  // TODO
  int bnd = 0;
  ILA_INFO << "#new flush (" << ref->coi() << "): " << bnd;
  return bnd;
}

} // namespace ila

