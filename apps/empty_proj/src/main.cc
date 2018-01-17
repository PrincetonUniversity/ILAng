#include "ila/expr_fuse.h"
#include "ila/instr.h"
#include "ila/instr_lvl_abs.h"

using namespace ila;

int main() {
  // ILA
  auto ila = InstrLvlAbs::New("test_ila");
  // input
  auto inp = ila->NewBoolInput("input");
  // State
  auto reg = ila->NewBvState("reg", 8);
  auto sig = ila->NewBoolState("sig");
  auto mem = ila->NewMemState("mem", 8, 8);
  // fetch
  auto fetch = reg;
  ila->SetFetch(fetch);
  // valid
  auto valid = ExprFuse::Eq(inp, ExprFuse::BoolConst(true));
  ila->SetValid(valid);
  // Instruction
  auto instr = ila->NewInstr("add_reg");
  auto decode = ExprFuse::Eq(reg, ExprFuse::BvConst(0, 8));
  instr->SetDecode(decode);
  auto reg_update = ExprFuse::Add(reg, ExprFuse::BvConst(1, 8));
  instr->AddUpdate(reg, reg_update);
  // TODO
  return 0;
}

