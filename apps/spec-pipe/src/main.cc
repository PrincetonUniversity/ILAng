#include "ila/instr_lvl_abs.h"

using namespace ila;

#define REG_NUM 4
#define REG_SIZE 8
#define INSTR_SIZE 8
#define OP_SIZE 4

enum OPCODE { STALL = 0, BRANCH, LOAD, ADD };

void child_br(InstrLvlAbsPtr m);

int main() {
  SetToStdErr(1);
  DebugLog::Enable("SpecExec");

  auto ila = InstrLvlAbs::New("m_top");

  // some constant
  auto TRUE = ExprFuse::BoolConst(true);
  auto FALSE = ExprFuse::BoolConst(false);

  auto ZERO = ExprFuse::BvConst(0, REG_SIZE);
  auto ONE = ExprFuse::BvConst(1, REG_SIZE);

  auto OP_STALL = ExprFuse::BvConst(OPCODE::STALL, OP_SIZE);
  auto OP_BRANCH = ExprFuse::BvConst(OPCODE::BRANCH, OP_SIZE);
  auto OP_LOAD = ExprFuse::BvConst(OPCODE::LOAD, OP_SIZE);
  auto OP_ADD = ExprFuse::BvConst(OPCODE::ADD, OP_SIZE);

  // define input

  // define state
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
  for (auto i = 0; i != REG_NUM; i++) {
    auto reg_name = "reg" + std::to_string(i);
    regs.push_back(ila->NewBvState(reg_name, REG_SIZE));
  }
  // micro-opcode (pipeline interface)
  auto u_op = ila->NewBvState("u_op", OP_SIZE);

  // valid
  ila->SetValid(ExprFuse::BoolConst(true));

  // fetch
  auto instr_w = ExprFuse::Load(ir, vpc);
  ila->SetFetch(instr_w);
  // FIXME extract
  auto opcode = ila->NewBvState("opcode", OP_SIZE); // temp workaround

  { // initial conditions
    auto init_vpc = ExprFuse::Eq(vpc, pc);
    ila->AddInit(init_vpc);

    auto init_pc = ExprFuse::Eq(pc, ZERO);
    ila->AddInit(init_pc);

    auto init_fspec = ExprFuse::Eq(f_spec, TRUE);
    ila->AddInit(init_fspec);

    auto init_opcode = ExprFuse::Eq(opcode, OP_STALL);
  }

  // instrs: branch, load, stall, and add
  { // branch
    auto instr = ila->NewInstr("Branch");
    auto decode = ExprFuse::Eq(opcode, OP_BRANCH);
    instr->SetDecode(decode);

    auto mem_nxt = mem;
    auto ir_nxt = ir;
    auto pc_nxt = pc;
    // increment vpc for pre-fetch
    auto vpc_nxt = ExprFuse::Add(vpc, ONE);
    auto f_spec_nxt = f_spec;
    auto u_op_nxt = OP_BRANCH;
    for (auto i = 0; i != REG_NUM; i++) {
      auto reg_i_nxt = regs[i];
    }

    // not considering interfering
    instr->AddUpdate(vpc, vpc_nxt);
    instr->AddUpdate(u_op, u_op_nxt);

    // child-ILA for branch micro-instr
    child_br(ila);
  }

  // laod
  // stall
  // add

  DebugLog::Disable("SpecExec");
  return 0;
}

void child_br(InstrLvlAbsPtr m) {
  // TODO
}

