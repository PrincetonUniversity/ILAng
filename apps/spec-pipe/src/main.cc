#include "ila/instr_lvl_abs.h"

using namespace ila;

#define REG_NUM 4
#define REG_SIZE 8
#define INSTR_SIZE 8
#define OP_SIZE 4

int main() {
  SetToStdErr(1);
  DebugLog::Enable("SpecExec");

  auto ila = InstrLvlAbs::New("SpecPipe");

  // input

  // state
  // data memory
  auto mem = ila->NewMemState("memory", REG_SIZE, REG_SIZE);
  // instruction memory
  auto ir = ila->NewMemState("ir", REG_SIZE, INSTR_SIZE);
  // actual program counter
  auto pc = ila->NewBvState("pc", REG_SIZE);
  // virtual program counter
  auto vpc = ila->NewBvState("vpc", REG_SIZE);
  // speculation flag
  auto f_spec = ila->NewBoolState("f_spec");
  // register files
  ExprPtrVec regs;
  for (auto i = 0; i < REG_NUM; i++) {
    auto reg_name = "reg" + std::to_string(i);
    regs.push_back(ila->NewBvState(reg_name, REG_SIZE));
  }
  // opcode (pipeline interface)
  auto opcode = ila->NewBvState("opcode", OP_SIZE);

  // valid
  // fetch
  // initial condition

  // instrs: branch, load, stall, add, etc
  // branch
  // laod
  // stall
  // add

  DebugLog::Disable("SpecExec");
  return 0;
}

