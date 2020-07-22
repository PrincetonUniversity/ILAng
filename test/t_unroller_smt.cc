/// \file
/// Unit tests for Unroller using SmtShim

#ifdef SMTSWITCH_TEST
#include <smt-switch/boolector_factory.h>
#include <smt-switch/smt.h>
#endif // SMTSWITCH_TEST

#include <ilang/ila-mngr/u_unroller_smt.h>
#include <ilang/ilang++.h>
#include <ilang/target-smt/smt_switch_itf.h>
#include <ilang/target-smt/z3_expr_adapter.h>

#include "unit-include/util.h"

namespace ilang {

TEST(TestUnroller, z3) {
  z3::context ctx;
  Z3ExprAdapter gen(ctx);
  auto shim = SmtShim(gen);
  auto unroller = PathUnroller(shim);
}

#ifdef SMTSWITCH_TEST
TEST(TestUnroller, btor) {
  auto solver = smt::BoolectorSolverFactory::create(false);
  auto switch_itf = SmtSwitchItf(solver);
  auto shim = SmtShim(switch_itf);
  auto unroller = PathUnroller(shim);
}
#endif // SMTSWITCH_TEST

} // namespace ilang
