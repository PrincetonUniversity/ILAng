/// \file
/// Source for generating verification condition for equivalecne checking.

#include "refinement/eq_check_crr.h"
#include "backend/abs_knob.h"
#include "backend/unroller.h"
#include "util/log.h"

namespace ila {

using namespace ExprFuse;

CommDiag::CommDiag(z3::context& ctx, const CrrPtr crr) : ctx_(ctx), crr_(crr) {}

CommDiag::~CommDiag() {}

z3::expr CommDiag::GenVerCond(const int& max) {
  ILA_ASSERT(ma_ && mb_) << "Need to specify two targets before VC generation.";

  // check the refinement is valid.
  ILA_CHECK(CheckRefinement(crr_->refine_a())) << "Refinement check fail.";
  ILA_CHECK(CheckRefinement(crr_->refine_b())) << "Refinement check fail.";
  ILA_CHECK(
      !(crr_->refine_a()->coi()->name() == crr_->refine_b()->coi()->name()))
      << "Comparing same abstraction.";

  // generate vc for each model.
  auto vc_ref_a = GenVerCondRefine(crr_->refine_a(), max);
  auto vc_ref_b = GenVerCondRefine(crr_->refine_b(), max);

  return ctx_.bool_val(true);
}

bool CommDiag::CheckRefinement(const RefPtr ref) const {
  ILA_NOT_NULL(ref);

  // check target
  auto m = ref->coi();
  ILA_CHECK(m) << "Refinement target not set.";

  // check flushing
  auto f = ref->flush();
  ILA_CHECK(f) << "Flushing function not set.";

  // check apply
  auto a = ref->appl();
  ILA_CHECK(a) << "Apply function not set.";

  z3::solver s(ctx_);
  Z3ExprAdapter g(ctx_);

  // check flushing and apply are exclusive
  auto exc = g.GetExpr(Not(Xor(f, a)));
  s.add(exc);
  if (s.check() == z3::sat) {
    ILA_ERROR << "Non-exclusive flushing function and apply function.";
    ILA_DLOG("Verbose-CheckRefine") << s.get_model();
    return false;
  }

  // check flushing and apply does not affect state equivalence
  // collect all state variables
  auto suff_old = "o";
  auto suff_new = "n";

  std::set<ExprPtr> vars;
  AbsKnob::GetVarOfIla(m, vars);

  auto eq = ctx_.bool_val(true);
  for (auto it = vars.begin(); it != vars.end(); it++) {
    auto so = g.GetExpr(*it, suff_old);
    auto sn = g.GetExpr(*it, suff_new);
    eq = eq && (so == sn);
  }

  auto ao = g.GetExpr(a, suff_old);
  auto fn = g.GetExpr(f, suff_new);

  s.add(ao && !(fn && ao && eq));
  if (s.check() == z3::sat) {
    ILA_ERROR << "Flushing and apply function intervene state equivalence.";
    ILA_DLOG("Verbose-CheckRefine") << s.get_model();
    return false;
  }

  return true;
}

z3::expr CommDiag::GenVerCondRefine(const RefPtr ref, const int& max) const {
  MonoUnroll un(ctx_);

  return ctx_.bool_val(true);
}

void CommDiag::RegisterTarget(const InstrLvlAbsPtr t) {
  ILA_NOT_NULL(t);
  ILA_ASSERT(!ma_ || !mb_) << "Both two target has been set.";
  mb_ = ma_ ? t : mb_;
  ma_ = ma_ ? ma_ : t;
}

} // namespace ila

