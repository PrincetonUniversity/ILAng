/// \file
/// Unit tests for smt-switch interface (with Boolector)

#ifdef SMTSWITCH_TEST

#include <smt-switch/boolector_factory.h>
#include <smt-switch/smt.h>

#include <ilang/ilang++.h>
#include <ilang/target-smt/smt_switch_itf.h>

#include "unit-include/util.h"

#define BV_SIZE 4

namespace ilang {

class TestSmtSwitch : public ::testing::Test {
public:
  TestSmtSwitch()
      : var_bool_a(m.NewBoolState("var_bool_a")),
        var_bool_b(m.NewBoolState("var_bool_b")),
        var_bv_a(m.NewBvState("var_bv_a", BV_SIZE)),
        var_bv_b(m.NewBvState("var_bv_b", BV_SIZE)),
        var_mem_a(m.NewMemState("var_mem_a", BV_SIZE, BV_SIZE)),
        var_mem_b(m.NewMemState("var_mem_b", BV_SIZE, BV_SIZE)) {
    // use boolector for the unit tests
    s = smt::BoolectorSolverFactory::create(false);
  }

  ~TestSmtSwitch() {}

  void SetUp() {}

  void TearDown() {
    // reset all created terms etc.
    s->reset();
  }

  void CheckUnsat(const ExprRef& e) {
    auto term = ResetAndGetSmtTerm(s, e);
    s->assert_formula(term);
    auto res = s->check_sat();
    EXPECT_TRUE(res.is_unsat());
  }

  smt::SmtSolver s;

  Ila m = Ila("host");
  ExprRef var_bool_a;
  ExprRef var_bool_b;
  ExprRef var_bv_a;
  ExprRef var_bv_b;
  ExprRef var_mem_a;
  ExprRef var_mem_b;

}; // class TestSmtSwitch

TEST_F(TestSmtSwitch, OpBvNeg) {
  auto neg_a = -var_bv_a;
  auto neg_neg_a = -neg_a;
  auto prop = neg_neg_a != var_bv_a;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBoolNot) {
  auto not_a = !var_bool_a;
  auto not_not_a = !not_a;
  auto prop = not_not_a != var_bool_a;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvComplement) {
  auto com_a = ~var_bv_a;
  auto com_com_a = ~com_a;
  auto prop = com_com_a != var_bv_a;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBoolAnd) {
  auto a_and_not_a = var_bool_a & !var_bool_a;
  CheckUnsat(a_and_not_a);
}

TEST_F(TestSmtSwitch, OpBvAnd) {
  auto a_and_all1 = var_bv_a & BvConst((1 << BV_SIZE) - 1, BV_SIZE);
  auto prop = a_and_all1 != var_bv_a;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBoolOr) {
  auto a_or_not_a = var_bool_a | !var_bool_a;
  auto prop = !a_or_not_a;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvOr) {
  auto a_or_0 = var_bv_a | BvConst(0, BV_SIZE);
  auto prop = a_or_0 != var_bv_a;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBoolXor) {
  auto a_xor_b = var_bool_a ^ var_bool_b;
  auto a_eq_b = var_bool_a == var_bool_b;
  auto prop = a_xor_b & a_eq_b;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvXor) {
  auto a_xor_b = var_bv_a ^ var_bv_b;
  auto a_eq_b = var_bv_a == var_bv_b;
  auto prop = a_eq_b & (a_xor_b == BvConst((1 << BV_SIZE) - 1, BV_SIZE));
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvShl) {
  auto a_shl_all = var_bv_a << BV_SIZE;
  auto prop = a_shl_all != BvConst(0, BV_SIZE);
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvAshr) {
  auto a_ashr_all = var_bv_a >> BV_SIZE;
  auto is_pos = a_ashr_all == BvConst(0, BV_SIZE);
  auto is_neg = a_ashr_all == BvConst((1 << BV_SIZE) - 1, BV_SIZE);
  auto prop = !(is_pos | is_neg);
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvLshr) {
  auto a_ashr_all = Lshr(var_bv_a, BvConst(BV_SIZE, BV_SIZE));
  auto prop = a_ashr_all != BvConst(0, BV_SIZE);
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvAdd) {
  auto a_plus_0 = var_bv_a + BvConst(0, BV_SIZE);
  auto prop = a_plus_0 != var_bv_a;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvSub) {
  auto a_minus_0 = var_bv_a - BvConst(0, BV_SIZE);
  auto prop = a_minus_0 != var_bv_a;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvAddSub) {
  auto a_plus_b = var_bv_a + var_bv_b;
  auto a_plus_b_minus_b = a_plus_b - var_bv_b;
  auto prop = a_plus_b_minus_b != var_bv_a;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvMul) {
  auto a_times_0 = var_bv_a * BvConst(0, BV_SIZE);
  auto prop = a_times_0 != BvConst(0, BV_SIZE);
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvDiv) {
  auto a_div_1 = var_bv_a / BvConst(1, BV_SIZE);
  auto prop = a_div_1 != var_bv_a;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvSrem) {
  auto div = BvConst(3, BV_SIZE);
  auto a_srem_3 = SRem(var_bv_a, div);
  auto prop = !(Slt(a_srem_3, div));
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvUrem) {
  auto div = BvConst(3, BV_SIZE);
  auto a_urem_3 = URem(var_bv_a, div);
  auto prop = !(Ult(a_urem_3, div));
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvSmod) {
  auto div = BvConst(3, BV_SIZE);
  auto a_smod_3 = SMod(var_bv_a, div);
  auto prop = !(Slt(a_smod_3, div));
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvSltSge) {
  auto a_slt_b = var_bv_a < var_bv_b;
  auto a_sge_b = var_bv_a >= var_bv_b;
  auto prop = a_slt_b & a_sge_b;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvSleSgt) {
  auto a_sle_b = var_bv_a <= var_bv_b;
  auto a_sgt_b = var_bv_a > var_bv_b;
  auto prop = a_sle_b & a_sgt_b;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvSltSgteq) {
  auto a_slt_b = var_bv_a < var_bv_b;
  auto a_sgt_b = var_bv_a > var_bv_b;
  auto a_eq_b = var_bv_a == var_bv_b;
  auto prop = !(a_slt_b | a_sgt_b | a_eq_b);
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvUltUge) {
  auto a_ult_b = Ult(var_bv_a, var_bv_b);
  auto a_uge_b = Uge(var_bv_a, var_bv_b);
  auto prop = a_ult_b & a_uge_b;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvUleUgt) {
  auto a_ule_b = Ule(var_bv_a, var_bv_b);
  auto a_ugt_b = Ugt(var_bv_a, var_bv_b);
  auto prop = a_ule_b & a_ugt_b;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvUltUgteq) {
  auto a_ult_b = Ult(var_bv_a, var_bv_b);
  auto a_ugt_b = Ugt(var_bv_a, var_bv_b);
  auto a_eq_b = var_bv_a == var_bv_b;
  auto prop = !(a_ult_b | a_ugt_b | a_eq_b);
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpMemLoad) {
  auto data_a = Load(var_mem_a, var_bv_a);
  auto data_b = Load(var_mem_a, var_bv_b);
  auto prop = (var_bv_a == var_bv_b) & (data_a != data_b);
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpMemStore) {
  auto new_mem = Store(var_mem_a, var_bv_a, var_bv_b);
  auto data = Load(new_mem, var_bv_a);
  auto prop = data != var_bv_b;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvConcat) {
  auto a_con_b = Concat(var_bv_a, var_bv_b);
  auto b_con_a = Concat(var_bv_b, var_bv_a);
  auto prop = (var_bv_a == var_bv_b) & (a_con_b != b_con_a);
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvExtract) {
  auto a_con_b = Concat(var_bv_a, var_bv_b);
  auto extract_a_con_b = Extract(a_con_b, BV_SIZE - 1, 0);
  auto prop = extract_a_con_b != var_bv_b;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvZext) {
  auto zext_a = ZExt(var_bv_a, 2 * BV_SIZE);
  auto zero_con_a = Concat(BvConst(0, BV_SIZE), var_bv_a);
  auto prop = zext_a != zero_con_a;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvSext) {
  auto pos_a = Lshr(var_bv_a, 1);
  auto sext_a = SExt(pos_a, 2 * BV_SIZE);
  auto zero_con_a = Concat(BvConst(0, BV_SIZE), pos_a);
  auto prop = sext_a != zero_con_a;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvRotate) {
  auto left_rotate_1 = LRotate(var_bv_a, 1);
  auto right_rotate_back = RRotate(left_rotate_1, 1);
  auto prop = right_rotate_back != var_bv_a;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBoolImply) {
  auto a_imply_b = Imply(var_bool_a, var_bool_b);
  auto prop = a_imply_b & var_bool_a & !var_bool_b;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBoolIte) {
  auto ite_a_0_a = Ite(var_bool_a, BoolConst(false), var_bool_a);
  auto prop = ite_a_0_a;
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpBvIte) {
  auto ite_c_a_b = Ite(var_bool_a, var_bv_a, var_bv_b);
  auto prop = (var_bv_a == var_bv_b) & (ite_c_a_b != var_bv_a);
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, OpApplyFunc) {
  auto func = FuncRef("func", SortRef::BOOL(), SortRef::BV(BV_SIZE));
  auto out1 = func(var_bv_a);
  auto out2 = func(var_bv_b);
  auto prop = (var_bv_a == var_bv_b) & (out1 != out2);
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, ConstBool) {
  auto a_is_0 = var_bool_a == BoolConst(false);
  auto b_is_1 = var_bool_b == BoolConst(true);
  auto prop = a_is_0 & b_is_1 & (var_bool_a == var_bool_b);
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, ConstBv) {
  auto a_is_0 = var_bv_a == BvConst(0, BV_SIZE);
  auto b_is_1 = var_bv_b == BvConst(1, BV_SIZE);
  auto prop = a_is_0 & b_is_1 & (var_bv_a == var_bv_b);
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, ConstMem) {
  std::map<NumericType, NumericType> data_pair;
  data_pair[0] = 0;
  data_pair[1] = 1;
  data_pair[2] = 2;
  data_pair[3] = 3;
  auto const_mem = MemConst(0, data_pair, BV_SIZE, BV_SIZE);
  auto save_addr = (var_bv_a <= 3) & (var_bv_a >= 0);
  auto is_linear = Load(const_mem, var_bv_a) == var_bv_a;
  auto prop = !Imply(save_addr, is_linear);
  CheckUnsat(prop);
}

TEST_F(TestSmtSwitch, DiscreteUsage) {
  auto a_ult_b = Ult(var_bv_a, var_bv_b);
  auto a_ugt_b = Ugt(var_bv_a, var_bv_b);
  auto a_eq_b = var_bv_a == var_bv_b;

  auto itf = SmtSwitchItf(s);
  s->assert_formula(itf.GetSmtTerm(a_ult_b.get()));
  s->assert_formula(itf.GetSmtTerm(a_ugt_b.get()));
  s->assert_formula(itf.GetSmtTerm(a_eq_b.get()));

  auto res = s->check_sat();
  EXPECT_TRUE(res.is_unsat());
}

TEST_F(TestSmtSwitch, DISABLED_MultiIssue) {
  auto itf = SmtSwitchItf(s);

  auto a_and_not_a = var_bool_a & !var_bool_a;
  s->assert_formula(itf.GetSmtTerm(a_and_not_a.get()));
  auto res = s->check_sat();
  EXPECT_TRUE(res.is_unsat());

  itf.Reset(); // XXX solver not properly reseted

  auto a_or_b = var_bool_a | var_bool_b;
  s->assert_formula(itf.GetSmtTerm(a_or_b.get()));
  EXPECT_TRUE(res.is_sat());
}

}; // namespace ilang

#endif // SMTSWITCH_TEST
