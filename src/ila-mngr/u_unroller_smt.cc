/// \file
/// The implementation of UnrollerSmt, PathUnroller, and MonoUnroller.

#include <ilang/ila-mngr/u_unroller_smt.h>

#include <ilang/target-smt/smt_switch_itf.h>
#include <ilang/target-smt/z3_expr_adapter.h>

namespace ilang {

//
// UnrollerSmt
//

template <class Generator>
typename UnrollerSmt<Generator>::SmtExpr
UnrollerSmt<Generator>::Unroll_(const size_t& len, const size_t& begin) {
  return smt_gen_.GetShimExpr(nullptr, ""); // TODO
}

template <class Generator>
typename UnrollerSmt<Generator>::SmtExpr
UnrollerSmt<Generator>::UnrollWithStepsUnconnected_(const size_t& len,
                                                    const size_t& begin) {
  return smt_gen_.GetShimExpr(nullptr, ""); // TODO
}

//
// PathUnroller
//

template <class Generator> void PathUnroller<Generator>::SetDecidingVars() {
  // TODO
}

template <class Generator>
void PathUnroller<Generator>::MakeOneTransition(const size_t& idx) {
  // TODO
}

//
// Concretize SMT generators
//
template class PathUnroller<SmtSwitchItf>;
template class PathUnroller<Z3ExprAdapter>;

} // namespace ilang
