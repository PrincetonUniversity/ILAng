/// \file
/// Unit test for c++ API

#include "ila++.h"
#include "unit-include/simple_cpu.h"
#include "unit-include/util.h"
#include <vector>

#define REG_NUM 16
#define REG_SIZE 8

namespace ila {

TEST(TestApi, Construct) {
  Ila ila("top");

  // state
  auto flag = ila.NewBoolState("flag");
  std::vector<ExprRef> regs;
  for (auto i = 0; i != REG_NUM; i++) {
    std::string reg_name = "reg" + std::to_string(i);
    regs.push_back(ila.NewBvState(reg_name, REG_SIZE));
  }
  auto mem = ila.NewMemState("mem", REG_SIZE, REG_SIZE);

  // input
  auto bool_in = ila.NewBoolInput("bool_in");
  auto bv_in = ila.NewBvInput("bv_in", REG_SIZE);
  EXPECT_EQ(2, ila.input_num());
  EXPECT_EQ(bool_in.get(), ila.input(0).get());
  EXPECT_EQ(bv_in.get(), ila.input("bv_in").get());

  // init
  auto flag_init = (flag == BoolConst(true));
  auto regs_init = (regs[0] != BvConst(0, REG_SIZE));
  auto mem_init =
      (mem == MemConst(0, std::map<int, int>(), REG_SIZE, REG_SIZE));
  ila.AddInit(flag_init);
  ila.AddInit(regs_init);
  ila.AddInit(mem_init);

  // fetch
  auto fetch = mem.Load(regs[0]);
  ila.SetFetch(fetch);
  EXPECT_EQ(fetch.get(), ila.fetch().get());

  // valid
  auto valid = (regs[0] == regs[1]);
  ila.SetValid(valid);
  EXPECT_EQ(valid.get(), ila.valid().get());

  // instr and ast
  {
    auto instr = ila.NewInstr("instr_0");
    auto decode = (regs[1] < regs[2]);
    instr.SetDecode(decode);

    instr.SetUpdate(regs[0], bv_in);
    instr.SetUpdate(flag, (regs[1] < regs[2]));
    instr.SetUpdate(mem, mem.Store(regs[2], regs[3]));

    EXPECT_EQ(1, ila.instr_num());
    EXPECT_EQ(instr.get(), ila.instr(0).get());
  }

  // child
  auto child = ila.NewChild("child");

  EXPECT_EQ(1, ila.child_num());
  EXPECT_EQ(child.get(), ila.child(0).get());
  EXPECT_EQ(child.get(), ila.child("child").get());
}

TEST(TestApi, ExprOps) {
  Ila ila("host");

  auto v_bool = ila.NewBoolState("v_bool");
  auto v_bv = ila.NewBvState("v_bv", REG_SIZE);
  auto v_mem = ila.NewMemState("v_mem", REG_SIZE, REG_SIZE);

  auto i_bool = ila.NewBoolInput("i_bool");
  auto i_bv = ila.NewBvInput("i_bv", REG_SIZE);

  // test
  auto n_negate = -v_bv;
  auto n_not = !v_bool;
  auto n_cmpl = ~n_negate;

  auto n_and_bv = n_negate & n_cmpl;
  auto n_and_bool = n_not & i_bool;
  auto n_and_bool_c = n_and_bool & true;

  auto n_or_bv = n_and_bv | n_cmpl;
  auto n_or_bool = n_and_bool | i_bool;
  auto n_or_bool_c = n_or_bool | false;

  auto n_xor_bv = n_or_bv ^ n_and_bv;
  auto n_xor_bool = n_or_bool ^ n_and_bool;
  auto n_xor_bool_c = n_xor_bool ^ true;

  auto n_shl_bv = n_or_bv << n_and_bv;
  auto n_shl_int = n_or_bv << 2;

  auto n_ashr_bv = n_or_bv >> n_and_bv;
  auto n_ashr_int = n_or_bv >> 3;

  auto n_lshr_bv = Lshr(n_or_bv, n_and_bv);
  auto n_lshr_int = Lshr(n_or_bv, 4);

  auto n_add_bv = n_xor_bv + n_or_bv;
  auto n_sub_bv = n_add_bv - n_xor_bv;
  auto n_add_bv_c = n_add_bv + 1;
  auto n_sub_bv_c = n_sub_bv - 5;

  auto n_eq_bv = n_add_bv == n_sub_bv;
  auto n_eq_bool = n_xor_bool == n_eq_bv;
  auto n_eq_bv_c = n_add_bv == 3;
  auto n_eq_bool_c = n_eq_bool == false;

  auto n_ne_bv = n_add_bv != n_sub_bv;
  auto n_ne_bool = n_ne_bv != n_eq_bool;
  auto n_ne_bv_c = n_add_bv != 4;

  auto n_lt_bv = n_add_bv < n_sub_bv;
  auto n_gt_bv = n_add_bv > n_sub_bv;
  auto n_le_bv = n_add_bv <= n_sub_bv;
  auto n_ge_bv = n_add_bv >= n_sub_bv;
  auto n_lt_bv_c = n_add_bv < 2;
  auto n_gt_bv_c = n_add_bv > 1;
  auto n_le_bv_c = n_add_bv <= 3;
  auto n_ge_bv_c = n_add_bv >= 0;
  auto n_ult_bv = Ult(n_add_bv, n_sub_bv);
  auto n_ugt_bv = Ugt(n_add_bv, n_sub_bv);
  auto n_ule_bv = Ule(n_add_bv, n_sub_bv);
  auto n_uge_bv = Uge(n_add_bv, n_sub_bv);
  auto n_ult_bv_c = Ult(n_add_bv, 1);
  auto n_ugt_bv_c = Ugt(n_add_bv, 2);
  auto n_ule_bv_c = Ule(n_add_bv, 3);
  auto n_uge_bv_c = Uge(n_add_bv, 4);

  auto n_load_bv = v_mem.Load(n_add_bv);
  auto n_load_bv_static = Load(v_mem, n_add_bv);
  auto n_store_mem = v_mem.Store(n_add_bv, n_load_bv);
  auto n_store_mem_static = Store(v_mem, n_add_bv, n_load_bv);

  auto n_extract_bv = n_load_bv(4, 0);
  auto n_append_bv = n_extract_bv.Append(n_load_bv);
  auto n_extract_static = Extract(n_load_bv, 4, 0);
  auto n_select_bv = SelectBit(n_load_bv, 0);
  auto n_extract_single_bv = n_extract_bv(1);
  auto n_zext_bv = n_extract_single_bv.ZExt(REG_SIZE);
  auto n_zext_static = ZExt(n_extract_single_bv, REG_SIZE);
  auto n_sext_bv = n_extract_single_bv.SExt(REG_SIZE);
  auto n_sext_static = SExt(n_extract_single_bv, REG_SIZE);
  auto n_concat_bv = Concat(n_append_bv, n_extract_bv);

  auto n_imply_bool = Imply(n_ne_bool, n_xor_bool);
  auto n_ite_bool = Ite(n_imply_bool, n_ne_bool, n_xor_bool);
  auto n_ite_bv = Ite(n_ite_bool, n_load_bv, n_sub_bv);

  auto tmp = n_ite_bv;
}

TEST(TestApi, Function) {
  auto s_out = SortRef::BOOL();
  auto s_arg0 = SortRef::BOOL();
  auto s_arg1 = SortRef::BV(8);
  auto s_arg2 = SortRef::MEM(8, 32);

  FuncRef f0("f0", s_out);
  FuncRef f1("f1", s_out, s_arg0);
  FuncRef f2("f2", s_out, s_arg0, s_arg1);
  FuncRef f3("f3", s_out, {s_arg0, s_arg1, s_arg2});

  Ila ila("host");
  auto i0 = BoolConst(true);
  auto i1 = BvConst(0, 8);
  auto i2 = ila.NewMemState("i2", 8, 32);

  auto n0 = f0();
  auto n1 = f1(i0);
  auto n2 = f2(i0, i1);
  auto n3 = f3({i0, i1, i2});
}

TEST(TestApi, NonConstruct) {
  Ila ila("host");

  auto v_bool = ila.NewBoolState("v_bool");
  auto c_bool = BoolConst(true);

  auto a = v_bool | c_bool;
  auto b = a & v_bool;
  auto c = a & v_bool;

  EXPECT_TRUE(TopEqual(b, c));
}

TEST(TestApi, ReplaceArg) {
  Ila ila("host");
  auto v_bool = ila.NewBoolState("v_bool");
  auto c_bool = BoolConst(true);

  auto a = v_bool | c_bool;
  auto b = a & v_bool;
  auto c = a | v_bool;

  auto x = a ^ b;
  auto y = b ^ c;

  y.ReplaceArg(b, a);
  y.ReplaceArg(1, b);
  EXPECT_TRUE(TopEqual(x, y));
}

TEST(TestApi, Unroll) {
  z3::context c;
  IlaZ3Unroller unroller(c);

  auto m0 = SimpleCpuRef("m0");
  auto m1 = SimpleCpuRef("m1");

  std::map<int, int> init_mem_val;
  {
    init_mem_val[0] = GenLoad(0, 0);
    init_mem_val[1] = GenLoad(1, 1);
    init_mem_val[2] = GenAdd(2, 0, 1);
    init_mem_val[3] = GenStore(2, 2);
  }
  auto init_mem = MemConst(0, init_mem_val, 8, 8);

  // dummy predicates
  unroller.AddGlobPred(BoolConst(true));
  unroller.AddStepPred(0, BoolConst(true));
  unroller.AddStepPred(1, BoolConst(true));
  unroller.AddStepPred(5, BoolConst(true));

  // m0
  for (size_t i = 0; i != m0.init_num(); i++) {
    unroller.AddInitPred(m0.init(i));
  }
  unroller.AddInitPred(init_mem == m0.state("ir"));
  auto cstr00 = unroller.UnrollMonoConn(m0, 4);

  auto cstr01 = unroller.UnrollMonoFree(m0, 4);
  for (auto i = 0; i != 4; i++) {
    for (size_t si = 0; si != m0.state_num(); si++) {
      auto var = m0.state(si);
      auto next_val = unroller.NextState(var, i);
      auto next_var = unroller.CurrState(var, i + 1);
      cstr01 = cstr01 && (next_val == next_var);
    }
  }

  unroller.ClearInitPred();
  unroller.ClearGlobPred();
  unroller.ClearStepPred();

  unroller.SetExtraSuffix("path");

  // m1
  for (size_t i = 0; i != m1.init_num(); i++) {
    unroller.AddInitPred(m1.init(i));
  }
  unroller.AddInitPred(init_mem == m1.state("ir"));
  std::vector<InstrRef> path = {m1.instr("Load"), m1.instr("Load"),
                                m1.instr("Add"), m1.instr("Store")};
  auto cstr10 = unroller.UnrollPathConn(path);
  unroller.ResetExtraSuffix();
  auto cstr11 = unroller.UnrollPathConn(path);

  z3::solver s(c);
  s.add(cstr00);
  s.add(cstr10);
  EXPECT_EQ(z3::sat, s.check());

  s.reset();
  s.add(cstr01);
  s.add(cstr10);
  // connect initial value
  ASSERT_EQ(m0.state_num(), m1.state_num());
  for (size_t i = 0; i != m0.state_num(); i++) {
    auto var0 = m0.state(i);
    auto var1 = m1.state(i);
    auto eq = unroller.Equal(var0, 0, var1, 0);
    s.add(eq);
  }
  // assert end value equal
  auto mem0 = m0.state("mem");
  auto mem1 = m1.state("mem");
  auto prop = unroller.Equal(mem0, 4, mem1, 4);
  s.add(!prop);
  // should not be equal due to extra suffix
  EXPECT_EQ(z3::sat, s.check());

  // check two unrolling are equal
  s.reset();
  s.add(cstr00);
  s.add(cstr11);
  for (size_t i = 0; i != m0.state_num(); i++) {
    auto var0 = m0.state(i);
    auto var1 = m1.state(i);
    auto eq = unroller.Equal(var0, 0, var1, 0);
    s.add(eq);
  }
  s.add(!prop);
  EXPECT_EQ(z3::unsat, s.check());

  // check the sequence can reach the end
  s.reset();
  s.add(cstr01);
  s.add(cstr11);
  for (size_t i = 0; i != m0.state_num(); i++) {
    auto var0 = m0.state(i);
    auto var1 = m1.state(i);
    auto eq = unroller.Equal(var0, 0, var1, 0);
    s.add(eq);
  }
  s.add(prop);
  EXPECT_EQ(z3::sat, s.check());
}

TEST(TestApi, Log) {
  LogLevel(0);
  LogPath("");
  EnableDebug("API_INFO");

  std::string msg = "";

  GET_STDERR_MSG(LogToErr(true), msg);
#ifndef NDEBUG
  EXPECT_FALSE(msg.empty());
#endif

  DisableDebug("API_INFO");
  LogPath("");

  GET_STDERR_MSG(LogToErr(false), msg);
#ifndef NDEBUG
  EXPECT_TRUE(msg.empty());
#endif
}

} // namespace ila

