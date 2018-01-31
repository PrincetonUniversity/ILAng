#include "ila/instr_lvl_abs.h"

using namespace ila;
using namespace ExprFuse;

// Macros and constants

#define REG_NUM 4
#define REG_SIZE 8
#define INSTR_SIZE 8
#define OP_SIZE 4

auto TRUE = BoolConst(true);
auto FALSE = BoolConst(false);

auto ZERO = BvConst(0, REG_SIZE);
auto ONE = BvConst(1, REG_SIZE);

enum OPCODE { STALL = 0, BRANCH, LOAD, ADD };
auto OP_STALL = BvConst(OPCODE::STALL, OP_SIZE);
auto OP_BRANCH = BvConst(OPCODE::BRANCH, OP_SIZE);
auto OP_LOAD = BvConst(OPCODE::LOAD, OP_SIZE);
auto OP_ADD = BvConst(OPCODE::ADD, OP_SIZE);

// function declaration
MemVal GetIrVal();
InstrLvlAbsPtr SpecExecIla();

// main function
int main() {
  SetToStdErr(1);
  DebugLog::Enable("SpecExec");

  auto ila = SpecExecIla();

  DebugLog::Disable("SpecExec");
  return 0;
}

// initialize the constant value in the ir
MemVal GetIrVal() {
  // FIXME store instruction, not opcode
  MemVal val(OPCODE::STALL);

  val.set_data(0, OPCODE::BRANCH);
  val.set_data(1, OPCODE::LOAD);
  val.set_data(2, OPCODE::ADD);
  val.set_data(3, OPCODE::STALL);

  return val;
}

// construct top-level ILA
InstrLvlAbsPtr SpecExecIla() {
  auto ila = InstrLvlAbs::New("m_top");

  // define state
  // data memory
  auto mem = ila->NewMemState("memory", REG_SIZE, REG_SIZE);
  // instruction memory
  auto ir_val = GetIrVal();
  auto ir = MemConst(ir_val, REG_SIZE, INSTR_SIZE);
  // auto ir = ila->NewMemState("ir", REG_SIZE, INSTR_SIZE);
  // cache
  auto cache = ila->NewMemState("cache", REG_SIZE, REG_SIZE);
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
  auto u_op_exec = ila->NewBvState("u_op_exec", OP_SIZE);
  auto u_op_comm = ila->NewBvState("u_op_comm", OP_SIZE);

  // valid
  ila->SetValid(TRUE);

  // fetch
  auto instr_w = Load(ir, vpc);
  ila->SetFetch(instr_w);
  auto opcode = Extract(instr_w, 7, 4);

  { // initial conditions
    auto init_vpc = Eq(vpc, pc);
    ila->AddInit(init_vpc);

    auto init_pc = Eq(pc, ZERO);
    ila->AddInit(init_pc);

    auto init_fspec = Eq(f_spec, TRUE);
    ila->AddInit(init_fspec);

    auto init_op_exec = Eq(u_op_exec, OP_STALL);
    ila->AddInit(init_op_exec);

    auto init_op_comm = Eq(u_op_comm, OP_STALL);
    ila->AddInit(init_op_comm);
  }

  // instrs: branch, load, stall, and add
  { // branch
    auto instr = ila->NewInstr("Branch");
    auto decode = And(Eq(opcode, OP_BRANCH), Not(f_spec));
    instr->SetDecode(decode);

    auto mem_nxt = mem;
    auto ir_nxt = ir;
    auto pc_nxt = pc;
    // increment vpc for pre-fetch
    auto vpc_nxt = Add(vpc, ONE);
    auto f_spec_nxt = f_spec;
    auto u_op_exec_nxt = OP_BRANCH;
    for (auto i = 0; i != REG_NUM; i++) {
      auto reg_i_nxt = regs[i];
    }

    // not considering interfering
    instr->AddUpdate(vpc, vpc_nxt);
    instr->AddUpdate(u_op_exec, u_op_exec_nxt);

    // child-ILA for branch micro-instr
  }

  // laod
  // stall
  // add

  return ila;
}

