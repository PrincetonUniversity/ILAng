/// \file
/// Source for generating verification condition for equivalecne checking.

#include "refinement/eq_check_crr.h"
#include "backend/unroller.h"
#include "util/log.h"

namespace ila {

using namespace ExprFuse;

CommDiag::CommDiag(const CrrPtr crr) : crr_(crr) {}

CommDiag::~CommDiag() {}

z3::expr CommDiag::GenVerCond(z3::context& ctx, const int& max) {
  ILA_ASSERT(ma_ && mb_) << "Need to specify two targets before VC generation.";

  // check the refinement is valid.
  ILA_CHECK(CheckRefinement(crr_->refine_a())) << "Check fail.";
  ILA_CHECK(CheckRefinement(crr_->refine_b())) << "Check fail.";

  return ctx.bool_val(true);
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

  z3::context c;
  z3::solver s(c);
  Z3ExprAdapter g(c);

  // check flushing and apply are exclusive
  auto exc = g.GetExpr(Not(Xor(f, a)));
  s.add(exc);
  if (s.check() == z3::sat) {
    ILA_ERROR << "Non-exclusive flushing function and apply function.";
    ILA_DLOG("Verbose-CheckRefine") << s.get_model();
    return false;
  }

  // check flushing and apply does not affect state equivalence
  auto suff_old = "o";
  auto suff_new = "n";

  // collect all state variables
  std::set<ExprPtr> vars;

  return true;
}

void CommDiag::RegisterTarget(const InstrLvlAbsPtr t) {
  ILA_NOT_NULL(t);
  ILA_ASSERT(!ma_ || !mb_) << "Both two target has been set.";
  mb_ = ma_ ? t : mb_;
  ma_ = ma_ ? ma_ : t;
}

} // namespace ila

