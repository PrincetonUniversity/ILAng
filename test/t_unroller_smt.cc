/// \file
/// Unit tests for Unroller using SmtShim

#ifdef SMTSWITCH_TEST
#include <smt-switch/boolector_factory.h>
#include <smt-switch/smt.h>
#endif // SMTSWITCH_TEST

#include <ilang/ila-mngr/u_unroller_smt.h>
#include <ilang/ila/ast_hub.h>
#include <ilang/target-smt/smt_switch_itf.h>
#include <ilang/target-smt/z3_expr_adapter.h>

#include "unit-include/simple_cpu.h"
#include "unit-include/util.h"

namespace ilang {

#define DBG_TAG "UnrollerSmt"

class TestUnrollerSmt : public ::testing::Test {
public:
  TestUnrollerSmt() {}
  ~TestUnrollerSmt() {}

  void SetUp() {
    DebugLog::Enable(DBG_TAG);

    MemVal init_mem_val(0);
    init_mem_val.set_data(0, GenLoad(0, 0));
    init_mem_val.set_data(1, GenLoad(1, 1));
    init_mem_val.set_data(2, GenAdd(2, 0, 1));
    init_mem_val.set_data(3, GenStore(2, 2));
    init_mem = asthub::MemConst(init_mem_val, 8, 8);
  }
  void TearDown() { DebugLog::Disable(DBG_TAG); }

  ExprPtr init_mem = nullptr;

  template <class Generator> auto UnrollTestSequence(SmtShim<Generator>& shim) {
    using namespace asthub;
    auto m = SimpleCpu("m");

    /*
     * reg0 = Load 0
     * reg1 = Load 1
     * reg2 = reg0 + reg1
     * Store reg2 2
     */
    std::vector<InstrPtr> seq = {m->instr("Load"), m->instr("Load"),
                                 m->instr("Add"), m->instr("Store")};

    auto unroller = new PathUnroller<Generator>(shim);

    // ILA init
    for (size_t i = 0; i != m->init_num(); i++) {
      unroller->AssertInitial(m->init(i));
    }
    { // instruction memory
      auto ir = m->state("ir");
      unroller->AssertInitial(Eq(ir, init_mem));
    }

    // concretize data
    unroller->AssertStep(Eq(m->state("r0"), 7), 0);
    unroller->AssertStep(Eq(m->state("r1"), 7), 0);
    unroller->AssertStep(Eq(Load(m->state("mem"), 0), 3), 0);
    unroller->AssertStep(Eq(Load(m->state("mem"), 1), 3), 0);

    // unroll
    auto exec = unroller->Unroll(seq);
    auto prop = unroller->GetSmtCurrent(Ne(Load(m->state("mem"), 2), 6), 4);
    auto smt_form = shim.BoolAnd(exec, prop);

    // reset
    unroller->ClearGlobalAssertion();
    unroller->ClearInitialAssertion();
    unroller->ClearStepAssertion();
    delete unroller;

    return smt_form;
  };

}; // class TestUnrollerSmt

TEST_F(TestUnrollerSmt, z3) {
  z3::context ctx;
  Z3ExprAdapter gen(ctx);
  auto shim = SmtShim(gen);

  auto p = UnrollTestSequence(shim);

  z3::solver s(ctx);
  s.add(p);
  auto res = s.check();
  EXPECT_EQ(res, z3::unsat);
}

#ifdef SMTSWITCH_TEST
TEST_F(TestUnrollerSmt, btor) {
  auto solver = smt::BoolectorSolverFactory::create(false);
  auto switch_itf = SmtSwitchItf(solver);
  auto shim = SmtShim(switch_itf);

  auto p = UnrollTestSequence(shim);

  solver->assert_formula(p);
  auto res = solver->check_sat();
  EXPECT_TRUE(res.is_unsat());
}

#endif // SMTSWITCH_TEST

} // namespace ilang
