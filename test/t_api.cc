/// \file
/// Unit test for c++ API

#include "ila++.h"
#include "unit-include/util.h"
#include <vector>

#define REG_NUM 16
#define REG_SIZE 8

namespace ila {

TEST(TestApi, BasicConstruct) {
  LogLevel(0);
  LogPath("");
  EnableDebug("TestApi");
  LogToErr(true);

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

  // valid
  auto valid = (regs[0] == regs[1]);
  ila.SetValid(valid);

  // instr and ast
  {
    auto instr = ila.NewInstr("instr_0");
    auto decode = (regs[1] < regs[2]);
    instr.SetDecode(decode);

    instr.SetUpdate(regs[0], bv_in);
    instr.SetUpdate(flag, (regs[1] < regs[2]));
    instr.SetUpdate(mem, mem.Store(regs[2], regs[3]));

    // ast
    auto n_negate = -regs[3];
    auto n_not = !flag;
    auto n_cmpl = ~n_negate;

    auto n_and_bv = n_negate & n_cmpl;
    auto n_and_bool = n_not & bool_in;

    auto n_or_bv = n_and_bv | n_cmpl;
    auto n_or_bool = n_and_bool | bool_in;

    auto n_xor_bv = n_or_bv ^ n_and_bv;
    auto n_xor_bool = n_or_bool ^ n_and_bool;

    auto n_add_bv = n_xor_bv + n_or_bv;
    auto n_sub_bv = n_add_bv - n_xor_bv;

    auto n_eq_bv = n_add_bv == n_sub_bv;
    auto n_eq_bool = n_xor_bool == n_eq_bv;

    auto n_ne_bv = n_add_bv != n_sub_bv;
    auto n_ne_bool = n_ne_bv != n_eq_bool;

    auto n_lt_bv = n_add_bv < n_sub_bv;
    auto n_gt_bv = n_add_bv > n_sub_bv;
    auto n_le_bv = n_add_bv <= n_sub_bv;
    auto n_ge_bv = n_add_bv >= n_sub_bv;

    auto n_load_bv = mem.Load(n_add_bv);
    auto n_store_mem = mem.Store(n_add_bv, n_load_bv);

    auto n_extract_bv = n_load_bv(4, 0);
    auto n_append_bv = n_extract_bv.Append(n_load_bv);
    auto n_concat_bv = Concat(n_append_bv, n_extract_bv);

    auto n_imply_bool = Imply(n_ne_bool, n_xor_bool);
    auto n_ite_bool = Ite(n_imply_bool, n_ne_bool, n_xor_bool);
    auto n_ite_bv = Ite(n_ite_bool, n_load_bv, n_sub_bv);
  }

  // child
  auto child = ila.NewChild("child");

  DisableDebug("TestApi");
  LogPath("");
  LogToErr(false);
}

} // namespace ila

