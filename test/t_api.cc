/// \file
/// Unit test for c++ API

#include <vector>

#include <ilang/ilang++.h>
#include <ilang/util/fs.h>

#include "unit-include/config.h"
#include "unit-include/eq_ilas.h"
#include "unit-include/ila_sim_test.h"
#include "unit-include/simple_cpu.h"
#include "unit-include/util.h"

#define REG_NUM 16
#define REG_SIZE 8

namespace ilang {

TEST(TestApi, LogicShift) {
  auto c = BvConst(0xFFFFFFFE, 32);
  //                 01234567   8*4 = 32
  // there is no guarantee that >> is logic shift
  // although it is usually implemented as such for
  // unsigned vars
}

TEST(TestApi, Construct) {
  Ila ila("top");
  EXPECT_EQ(ila.name(), "top");

  // state
  auto flag = ila.NewBoolState("flag");
  std::vector<ExprRef> regs;
  for (auto i = 0; i != REG_NUM; i++) {
    std::string reg_name = "reg" + std::to_string(i);
    regs.push_back(ila.NewBvState(reg_name, REG_SIZE));
  }
  auto mem = ila.NewMemState("mem", REG_SIZE, REG_SIZE);
  EXPECT_EQ(mem.name(), "mem");

  // input
  auto bool_in = ila.NewBoolInput("bool_in");
  auto bv_in = ila.NewBvInput("bv_in", REG_SIZE);
  EXPECT_EQ(2, ila.input_num());
  EXPECT_EQ(bool_in.get(), ila.input(0).get());
  EXPECT_EQ(bv_in.get(), ila.input("bv_in").get());
  EXPECT_EQ(bool_in.name(), "bool_in");
  EXPECT_EQ(bv_in.name(), "bv_in");

  // init
  auto flag_init = (flag == BoolConst(true));
  auto regs_init = (regs[0] != BvConst(0, REG_SIZE));
  auto mem_init = (mem == MemConst(0, {}, REG_SIZE, REG_SIZE));
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
    EXPECT_EQ(instr.name(), "instr_0");
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

/// helper function
bool SameOp(const ExprRef& l, const ExprRef& r) {
  std::shared_ptr<ExprOp> lp = std::dynamic_pointer_cast<ExprOp>(l.get());
  std::shared_ptr<ExprOp> rp = std::dynamic_pointer_cast<ExprOp>(r.get());
  ILA_NOT_NULL(lp);
  ILA_NOT_NULL(rp);
  return lp->op_name() == rp->op_name();
}

TEST(TestApi, ExprOps) {
  Ila ila("host");

  auto v_bool = ila.NewBoolState("v_bool");
  auto v_bv = ila.NewBvState("v_bv", REG_SIZE);
  auto v_mem = ila.NewMemState("v_mem", REG_SIZE, REG_SIZE);

  auto i_bool = ila.NewBoolInput("i_bool");
  auto i_bv = ila.NewBvInput("i_bv", REG_SIZE);

  EXPECT_EQ(-1, v_bool.bit_width());
  EXPECT_EQ(REG_SIZE, v_bv.bit_width());
  EXPECT_EQ(-1, v_mem.bit_width());

  EXPECT_EQ(-1, v_bool.addr_width());
  EXPECT_EQ(-1, v_bv.addr_width());
  EXPECT_EQ(REG_SIZE, v_mem.addr_width());

  EXPECT_EQ(-1, v_bool.data_width());
  EXPECT_EQ(-1, v_bv.data_width());
  EXPECT_EQ(REG_SIZE, v_mem.data_width());

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

  auto n_div_bv = n_add_bv / n_sub_bv;
  auto n_mul_bv = n_sub_bv_c * n_add_bv_c;
  auto n_srem_bv = SRem(n_div_bv, n_mul_bv);
  auto n_urem_bv = URem(n_div_bv, n_mul_bv);
  auto n_smod_bv = SMod(n_div_bv, n_mul_bv);

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

  SetUnsignedComparison(true);

  auto n_unsigned_lt_bv = n_add_bv < n_sub_bv;
  auto n_unsigned_gt_bv = n_add_bv > n_sub_bv;
  auto n_unsigned_le_bv = n_add_bv <= n_sub_bv;
  auto n_unsigned_ge_bv = n_add_bv >= n_sub_bv;
  auto n_unsigned_lt_bv_c = n_add_bv < 2;
  auto n_unsigned_gt_bv_c = n_add_bv > 1;
  auto n_unsigned_le_bv_c = n_add_bv <= 3;
  auto n_unsigned_ge_bv_c = n_add_bv >= 0;

  SetUnsignedComparison(false);

  auto n_ult_bv = Ult(n_add_bv, n_sub_bv);
  auto n_ugt_bv = Ugt(n_add_bv, n_sub_bv);
  auto n_ule_bv = Ule(n_add_bv, n_sub_bv);
  auto n_uge_bv = Uge(n_add_bv, n_sub_bv);
  auto n_slt_bv = Slt(n_add_bv, n_sub_bv);
  auto n_sgt_bv = Sgt(n_add_bv, n_sub_bv);
  auto n_sle_bv = Sle(n_add_bv, n_sub_bv);
  auto n_sge_bv = Sge(n_add_bv, n_sub_bv);

  auto n_ult_bv_c = Ult(n_add_bv, 1);
  auto n_ugt_bv_c = Ugt(n_add_bv, 2);
  auto n_ule_bv_c = Ule(n_add_bv, 3);
  auto n_uge_bv_c = Uge(n_add_bv, 4);
  auto n_slt_bv_c = Slt(n_add_bv, 1);
  auto n_sgt_bv_c = Sgt(n_add_bv, 2);
  auto n_sle_bv_c = Sle(n_add_bv, 3);
  auto n_sge_bv_c = Sge(n_add_bv, 4);

  EXPECT_TRUE(SameOp(n_lt_bv, n_slt_bv));
  EXPECT_TRUE(SameOp(n_gt_bv, n_sgt_bv));
  EXPECT_TRUE(SameOp(n_le_bv, n_sle_bv));
  EXPECT_TRUE(SameOp(n_ge_bv, n_sge_bv));

  EXPECT_TRUE(SameOp(n_unsigned_lt_bv, n_ult_bv));
  EXPECT_TRUE(SameOp(n_unsigned_gt_bv, n_ugt_bv));
  EXPECT_TRUE(SameOp(n_unsigned_le_bv, n_ule_bv));
  EXPECT_TRUE(SameOp(n_unsigned_ge_bv, n_uge_bv));

  EXPECT_TRUE(SameOp(n_lt_bv_c, n_slt_bv_c));
  EXPECT_TRUE(SameOp(n_gt_bv_c, n_sgt_bv_c));
  EXPECT_TRUE(SameOp(n_le_bv_c, n_sle_bv_c));
  EXPECT_TRUE(SameOp(n_ge_bv_c, n_sge_bv_c));

  EXPECT_TRUE(SameOp(n_unsigned_lt_bv_c, n_ult_bv_c));
  EXPECT_TRUE(SameOp(n_unsigned_gt_bv_c, n_ugt_bv_c));
  EXPECT_TRUE(SameOp(n_unsigned_le_bv_c, n_ule_bv_c));
  EXPECT_TRUE(SameOp(n_unsigned_ge_bv_c, n_uge_bv_c));

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
  auto n_lrotate_bv = LRotate(n_concat_bv, REG_SIZE);
  auto n_rrotate_bv = RRotate(n_concat_bv, REG_SIZE);

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
  EXPECT_EQ(f0.name(), "f0");
  EXPECT_EQ(f1.name(), "f1");
  EXPECT_EQ(f2.name(), "f2");
  EXPECT_EQ(f3.name(), "f3");

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

TEST(TestApi, EntryNum) {
  Ila ila("hots");

  auto mem = ila.NewMemState("mem", 16, 32);

  EXPECT_EQ(0, mem.GetEntryNum());

#ifndef NDEBUG
  EXPECT_DEATH(mem.SetEntryNum(-1), ".*");
#endif
  EXPECT_TRUE(mem.SetEntryNum(8));
  EXPECT_FALSE(mem.SetEntryNum(16));
  EXPECT_EQ(8, mem.GetEntryNum());

  auto bl = ila.NewBoolState("bl");

#ifndef NDEBUG
  EXPECT_DEATH(bl.SetEntryNum(8), ".*");
  EXPECT_DEATH(bl.GetEntryNum(), ".*");
#endif
}

TEST(TestApi, OutStream) {
  auto m = SimpleCpuRef("m");
  std::string msg = "";

  // ila
  GET_STDOUT_MSG((std::cout << m), msg);
  EXPECT_TRUE(msg.find(m.name()) != std::string::npos);

  // state
  for (size_t i = 0; i < m.state_num(); i++) {
    auto state = m.state(i);
    GET_STDOUT_MSG((std::cout << state), msg);
    EXPECT_TRUE(msg.find(state.name()) != std::string::npos);
  }

  auto pc = m.state("pc");

  // instr
  for (size_t i = 0; i < m.instr_num(); i++) {
    auto instr = m.instr(i);
    GET_STDOUT_MSG((std::cout << instr), msg);
    EXPECT_TRUE(msg.find(instr.name()) != std::string::npos);

    GET_STDOUT_MSG((std::cout << instr.GetDecode()), msg);
    EXPECT_FALSE(msg.empty());

    auto next_pc = instr.GetUpdate(pc);
    GET_STDOUT_MSG((std::cout << next_pc), msg); // not NULL
    EXPECT_FALSE(msg.empty());
  }
}

TEST(TestApi, VerilogGen) {
  auto tmp_dir = GetRandomFileName();
  os_portable_mkdir(tmp_dir);

  // ila
  auto m = SimpleCpuRef("m");
  auto tmp_file_ila = GetRandomFileName(tmp_dir);
  std::ofstream fout(tmp_file_ila);
  m.ExportToVerilog(fout);
  fout.close();

  // instr
  for (size_t i = 0; i < m.instr_num(); i++) {
    auto instr = m.instr(i);

    auto tmp_file_instr = GetRandomFileName(tmp_dir);
    fout.open(tmp_file_instr);
    instr.ExportToVerilog(fout);
    fout.close();

    auto tmp_file_instr_child = GetRandomFileName(tmp_dir);
    fout.open(tmp_file_instr_child);
    instr.ExportToVerilogWithChild(fout);
    fout.close();
  }

  os_portable_remove_directory(tmp_dir);
}

TEST(TestApi, Unroll) {
  z3::context c;
  auto unroller = IlaZ3Unroller(c);

  auto m0 = SimpleCpuRef("m0");
  auto m1 = SimpleCpuRef("m1");

  std::map<NumericType, NumericType> init_mem_val;
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

  auto suff_unroller = IlaZ3Unroller(c, "path");

  // m1
  for (size_t i = 0; i != m1.init_num(); i++) {
    suff_unroller.AddInitPred(m1.init(i));
  }
  suff_unroller.AddInitPred(init_mem == m1.state("ir"));
  std::vector<InstrRef> path = {m1.instr("Load"), m1.instr("Load"),
                                m1.instr("Add"), m1.instr("Store")};
  auto cstr10 = suff_unroller.UnrollPathConn(path);

  for (size_t i = 0; i != m1.init_num(); i++) {
    unroller.AddInitPred(m1.init(i));
  }
  unroller.AddInitPred(init_mem == m1.state("ir"));
  auto cstr11 = unroller.UnrollPathSubs(path);

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

TEST(TestApi, UnrollPathFreeWithFunc) {
  z3::context ctx;
  z3::solver solver(ctx);

  auto unroller = IlaZ3Unroller(ctx);
  auto m0 = IlaSimTest("m0").model;
  auto m1 = IlaSimTest("m1").model;

  // start from saem state
  auto same_state = BoolConst(true);
  for (size_t i = 0; i < m0.state_num(); i++) {
    auto state_0 = m0.state(i);
    auto state_1 = m1.state(state_0.name());
    same_state = same_state & (state_0 == state_1);
  }
  unroller.AddInitPred(same_state);

  // always share same input
  auto same_input = BoolConst(true);
  for (size_t i = 0; i < m0.input_num(); i++) {
    auto input_0 = m0.input(i);
    auto input_1 = m1.input(input_0.name());
    same_input = same_input & (input_0 == input_1);
  }
  unroller.AddGlobPred(same_input);

  // unroll instr sequence
  auto seq0 = {m0.instr("WRITE_ADDRESS"), m0.instr("START_ENCRYPT")};
  auto seq1 = {m1.instr("WRITE_ADDRESS"), m1.instr("START_ENCRYPT")};
  auto path0 = unroller.UnrollPathConn(seq0);
  auto path1 = unroller.UnrollPathFree(seq1);

  auto connect = ctx.bool_val(true);
  for (size_t i = 0; i < m1.state_num(); i++) {
    auto state = m1.state(i);
    connect = connect &&
              (unroller.NextState(state, 0) == unroller.CurrState(state, 1)) &&
              (unroller.NextState(state, 1) == unroller.CurrState(state, 2));
  }

  // func
  auto farg = SortRef::BV(128);
  auto func = unroller.GetZ3FuncDecl(FuncRef("process128", farg, farg, farg));
  auto x = ctx.bv_const("x", 128);
  auto y = ctx.bv_const("y", 128);
  auto fdef = z3::forall(x, y, func(x, y) == (x + y)); // dummy

  // check length
  auto to_check = unroller.Equal(m0.state("length"), 2, m1.state("length"), 2);

  // SMT query
  solver.add(path0);
  solver.add(path1);
  solver.add(fdef);
  solver.add(!to_check);
  EXPECT_EQ(solver.check(), z3::sat);
  solver.add(connect);
  EXPECT_EQ(solver.check(), z3::unsat);
}

TEST(TestApi, Portable) {
  // SetToStdErr(1);
  EnableDebug("Portable");
  auto example = EqIlaGen();
  auto buff_spec = example.GetIlaFlat1("flat1");

  auto portable_file_name =
      std::string(ILANG_TEST_BIN_ROOT) + "/tmp_portable.json";

  auto res = ExportIlaPortable(Ila(buff_spec), portable_file_name);
  EXPECT_TRUE(res);

  auto read_ila = ImportIlaPortable(portable_file_name);

  DisableDebug("Portable");
}

} // namespace ilang
