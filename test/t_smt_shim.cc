/// \file
/// Unit tests for SmtShim

#ifdef SMTSWITCH_TEST
#include <smt-switch/boolector_factory.h>
#include <smt-switch/smt.h>
#endif // SMTSWITCH_TEST

#include <ilang/ilang++.h>
#include <ilang/target-smt/smt_shim.h>
#include <ilang/target-smt/smt_switch_itf.h>
#include <ilang/target-smt/z3_expr_adapter.h>

#include "unit-include/util.h"

#define BV_SIZE 4

namespace ilang {

class TestSmtShim : public ::testing::Test {
public:
  TestSmtShim()
      : var_bool_a(m.NewBoolState("var_bool_a")),
        var_bool_b(m.NewBoolState("var_bool_b")),
        var_bv_a(m.NewBvState("var_bv_a", BV_SIZE)),
        var_bv_b(m.NewBvState("var_bv_b", BV_SIZE)),
        var_mem_a(m.NewMemState("var_mem_a", BV_SIZE, BV_SIZE)),
        var_mem_b(m.NewMemState("var_mem_b", BV_SIZE, BV_SIZE)) {}

  ~TestSmtShim() {}
  void SetUp() {}
  void TearDown() {}

  void CheckUnsatZ3(const ExprRef& e) {
    z3::context ctx;
    z3::solver solver(ctx);
    Z3ExprAdapter gen(ctx);
    auto shim = SmtShim(gen);

    auto z3_expr = shim.GetShimExpr(e.get());
    solver.add(z3_expr);
    auto res = solver.check();
    EXPECT_TRUE(res == z3::unsat);
  }

  void CheckUnsatSwitch(const ExprRef& e) {
#ifdef SMTSWITCH_TEST
    auto solver = smt::BoolectorSolverFactory::create(false);
    auto switch_itf = SmtSwitchItf(solver);
    auto shim = SmtShim(switch_itf);

    auto switch_term = shim.GetShimExpr(e.get());
    solver->assert_formula(switch_term);
    auto res = solver->check_sat();
    EXPECT_TRUE(res.is_unsat());
#endif // SMTSWITCH_TEST
  }

  Ila m = Ila("host");
  ExprRef var_bool_a;
  ExprRef var_bool_b;
  ExprRef var_bv_a;
  ExprRef var_bv_b;
  ExprRef var_mem_a;
  ExprRef var_mem_b;
};

TEST_F(TestSmtShim, OpBoolNot) {
  auto not_a = !var_bool_a;
  auto not_not_a = !not_a;
  auto prop = not_not_a != var_bool_a;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvNeg) {
  auto neg_a = -var_bv_a;
  auto neg_neg_a = -neg_a;
  auto prop = neg_neg_a != var_bv_a;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvComplement) {
  auto com_a = ~var_bv_a;
  auto com_com_a = ~com_a;
  auto prop = com_com_a != var_bv_a;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBoolAnd) {
  auto a_and_not_a = var_bool_a & !var_bool_a;
  CheckUnsatZ3(a_and_not_a);
  CheckUnsatSwitch(a_and_not_a);
}

TEST_F(TestSmtShim, OpBvAnd) {
  auto a_and_all1 = var_bv_a & BvConst((1 << BV_SIZE) - 1, BV_SIZE);
  auto prop = a_and_all1 != var_bv_a;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBoolOr) {
  auto a_or_not_a = var_bool_a | !var_bool_a;
  auto prop = !a_or_not_a;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvOr) {
  auto a_or_0 = var_bv_a | BvConst(0, BV_SIZE);
  auto prop = a_or_0 != var_bv_a;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBoolXor) {
  auto a_xor_b = var_bool_a ^ var_bool_b;
  auto a_eq_b = var_bool_a == var_bool_b;
  auto prop = a_xor_b & a_eq_b;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvXor) {
  auto a_xor_b = var_bv_a ^ var_bv_b;
  auto a_eq_b = var_bv_a == var_bv_b;
  auto prop = a_eq_b & (a_xor_b == BvConst((1 << BV_SIZE) - 1, BV_SIZE));
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvShl) {
  auto a_shl_all = var_bv_a << BV_SIZE;
  auto prop = a_shl_all != BvConst(0, BV_SIZE);
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvAshr) {
  auto a_ashr_all = var_bv_a >> BV_SIZE;
  auto is_pos = a_ashr_all == BvConst(0, BV_SIZE);
  auto is_neg = a_ashr_all == BvConst((1 << BV_SIZE) - 1, BV_SIZE);
  auto prop = !(is_pos | is_neg);
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvLshr) {
  auto a_ashr_all = Lshr(var_bv_a, BvConst(BV_SIZE, BV_SIZE));
  auto prop = a_ashr_all != BvConst(0, BV_SIZE);
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvAdd) {
  auto a_plus_0 = var_bv_a + BvConst(0, BV_SIZE);
  auto prop = a_plus_0 != var_bv_a;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvSub) {
  auto a_minus_0 = var_bv_a - BvConst(0, BV_SIZE);
  auto prop = a_minus_0 != var_bv_a;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvAddSub) {
  auto a_plus_b = var_bv_a + var_bv_b;
  auto a_plus_b_minus_b = a_plus_b - var_bv_b;
  auto prop = a_plus_b_minus_b != var_bv_a;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvMul) {
  auto a_times_0 = var_bv_a * BvConst(0, BV_SIZE);
  auto prop = a_times_0 != BvConst(0, BV_SIZE);
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvDiv) {
  auto a_div_1 = var_bv_a / BvConst(1, BV_SIZE);
  auto prop = a_div_1 != var_bv_a;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvSrem) {
  auto div = BvConst(3, BV_SIZE);
  auto a_srem_3 = SRem(var_bv_a, div);
  auto prop = !(Slt(a_srem_3, div));
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvUrem) {
  auto div = BvConst(3, BV_SIZE);
  auto a_urem_3 = URem(var_bv_a, div);
  auto prop = !(Ult(a_urem_3, div));
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvSmod) {
  auto div = BvConst(3, BV_SIZE);
  auto a_smod_3 = SMod(var_bv_a, div);
  auto prop = !(Slt(a_smod_3, div));
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvSltSge) {
  auto a_slt_b = var_bv_a < var_bv_b;
  auto a_sge_b = var_bv_a >= var_bv_b;
  auto prop = a_slt_b & a_sge_b;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvSleSgt) {
  auto a_sle_b = var_bv_a <= var_bv_b;
  auto a_sgt_b = var_bv_a > var_bv_b;
  auto prop = a_sle_b & a_sgt_b;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvSltSgteq) {
  auto a_slt_b = var_bv_a < var_bv_b;
  auto a_sgt_b = var_bv_a > var_bv_b;
  auto a_eq_b = var_bv_a == var_bv_b;
  auto prop = !(a_slt_b | a_sgt_b | a_eq_b);
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvUltUge) {
  auto a_ult_b = Ult(var_bv_a, var_bv_b);
  auto a_uge_b = Uge(var_bv_a, var_bv_b);
  auto prop = a_ult_b & a_uge_b;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvUleUgt) {
  auto a_ule_b = Ule(var_bv_a, var_bv_b);
  auto a_ugt_b = Ugt(var_bv_a, var_bv_b);
  auto prop = a_ule_b & a_ugt_b;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvUltUgteq) {
  auto a_ult_b = Ult(var_bv_a, var_bv_b);
  auto a_ugt_b = Ugt(var_bv_a, var_bv_b);
  auto a_eq_b = var_bv_a == var_bv_b;
  auto prop = !(a_ult_b | a_ugt_b | a_eq_b);
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpMemLoad) {
  auto data_a = Load(var_mem_a, var_bv_a);
  auto data_b = Load(var_mem_a, var_bv_b);
  auto prop = (var_bv_a == var_bv_b) & (data_a != data_b);
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpMemStore) {
  auto new_mem = Store(var_mem_a, var_bv_a, var_bv_b);
  auto data = Load(new_mem, var_bv_a);
  auto prop = data != var_bv_b;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvConcat) {
  auto a_con_b = Concat(var_bv_a, var_bv_b);
  auto b_con_a = Concat(var_bv_b, var_bv_a);
  auto prop = (var_bv_a == var_bv_b) & (a_con_b != b_con_a);
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvExtract) {
  auto a_con_b = Concat(var_bv_a, var_bv_b);
  auto extract_a_con_b = Extract(a_con_b, BV_SIZE - 1, 0);
  auto prop = extract_a_con_b != var_bv_b;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvZext) {
  auto zext_a = ZExt(var_bv_a, 2 * BV_SIZE);
  auto zero_con_a = Concat(BvConst(0, BV_SIZE), var_bv_a);
  auto prop = zext_a != zero_con_a;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvSext) {
  auto pos_a = Lshr(var_bv_a, 1);
  auto sext_a = SExt(pos_a, 2 * BV_SIZE);
  auto zero_con_a = Concat(BvConst(0, BV_SIZE), pos_a);
  auto prop = sext_a != zero_con_a;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvRotate) {
  auto left_rotate_1 = LRotate(var_bv_a, 1);
  auto right_rotate_back = RRotate(left_rotate_1, 1);
  auto prop = right_rotate_back != var_bv_a;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBoolImply) {
  auto a_imply_b = Imply(var_bool_a, var_bool_b);
  auto prop = a_imply_b & var_bool_a & !var_bool_b;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBoolIte) {
  auto ite_a_0_a = Ite(var_bool_a, BoolConst(false), var_bool_a);
  auto prop = ite_a_0_a;
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpBvIte) {
  auto ite_c_a_b = Ite(var_bool_a, var_bv_a, var_bv_b);
  auto prop = (var_bv_a == var_bv_b) & (ite_c_a_b != var_bv_a);
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, OpApplyFunc) {
  auto func = FuncRef("func", SortRef::BOOL(), SortRef::BV(BV_SIZE));
  auto out1 = func(var_bv_a);
  auto out2 = func(var_bv_b);
  auto prop = (var_bv_a == var_bv_b) & (out1 != out2);
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, ConstBool) {
  auto a_is_0 = var_bool_a == BoolConst(false);
  auto b_is_1 = var_bool_b == BoolConst(true);
  auto prop = a_is_0 & b_is_1 & (var_bool_a == var_bool_b);
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, ConstBv) {
  auto a_is_0 = var_bv_a == BvConst(0, BV_SIZE);
  auto b_is_1 = var_bv_b == BvConst(1, BV_SIZE);
  auto prop = a_is_0 & b_is_1 & (var_bv_a == var_bv_b);
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, ConstMem) {
  std::map<NumericType, NumericType> data_pair;
  data_pair[0] = 0;
  data_pair[1] = 1;
  data_pair[2] = 2;
  data_pair[3] = 3;
  auto const_mem = MemConst(0, data_pair, BV_SIZE, BV_SIZE);
  auto save_addr = (var_bv_a <= 3) & (var_bv_a >= 0);
  auto is_linear = Load(const_mem, var_bv_a) == var_bv_a;
  auto prop = !Imply(save_addr, is_linear);
  CheckUnsatZ3(prop);
  CheckUnsatSwitch(prop);
}

TEST_F(TestSmtShim, DiscreteUsage) {
  auto a_ult_b = Ult(var_bv_a, var_bv_b);
  auto a_ugt_b = Ugt(var_bv_a, var_bv_b);
  auto a_eq_b = var_bv_a == var_bv_b;

  { // z3
    z3::context ctx;
    z3::solver solver(ctx);
    Z3ExprAdapter gen(ctx);
    auto shim = SmtShim(gen);

    solver.add(shim.GetShimExpr(a_ult_b.get()));
    solver.add(shim.GetShimExpr(a_ugt_b.get()));
    solver.add(shim.GetShimExpr(a_eq_b.get()));

    auto res = solver.check();
    EXPECT_TRUE(res == z3::unsat);
  }

#ifdef SMTSWITCH_TEST
  { // switch
    auto solver = smt::BoolectorSolverFactory::create(false);
    auto itf = SmtSwitchItf(solver);
    auto shim = SmtShim(itf);

    solver->assert_formula(shim.GetShimExpr(a_ult_b.get()));
    solver->assert_formula(shim.GetShimExpr(a_ugt_b.get()));
    solver->assert_formula(shim.GetShimExpr(a_eq_b.get()));

    auto res = solver->check_sat();
    EXPECT_TRUE(res.is_unsat());
  }
#endif // SMTSWITCH_TEST
}

} // namespace ilang
