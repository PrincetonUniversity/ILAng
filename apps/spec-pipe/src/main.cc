/// \file
/// ILA modeling for speculative execution with pipeline

#include "ila/instr_lvl_abs.h"

using namespace ila;
using namespace ExprFuse;

// ------------------------- Instruction Definition ------------------------- //
/*
 * Instruction: [15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00]
 * NOP:         [ 0  0  0  0| ----------------------------------]
 * BR:          [ 0  0  0  1|       CND |            ADDR (IMM) ]
 * LD:          [ 0  0  1  0|       DST |            ADDR (IMM) ]
 * MV:          [ 0  0  1  1|       DST |            VAL  (IMM) ]
 */

// ------------------------- Macros & Constants ----------------------------- //
#define REG_NUM 4
#define REG_SIZE 8
#define INSTR_SIZE 16
#define OP_SIZE 4

#define OP_OFF 12
#define DST_HI 11
#define DST_LO 8
#define CND_HI 11
#define CND_LO 8
#define IMM_HI 7
#define IMM_LO 0

auto ONE = BvConst(1, REG_SIZE);
auto ZERO = BvConst(0, REG_SIZE);
auto TRUE = BoolConst(true);
auto FALSE = BoolConst(false);

enum OPCODE { NOP = 0, BR, LD, MV };
auto OP_NOP = BvConst(OPCODE::NOP, OP_SIZE);
auto OP_BR = BvConst(OPCODE::BR, OP_SIZE);
auto OP_LD = BvConst(OPCODE::LD, OP_SIZE);
auto OP_MV = BvConst(OPCODE::MV, OP_SIZE);

// ------------------------- Function Declaration --------------------------- //
MemVal IrInitVal();
InstrLvlAbsPtr SpecExecIla();
int GenNop();
int GenBr(const int& cnd, const int& addr);
int GenLd(const int& dst, const int& addr);
int GenMv(const int& dst, const int& val);

// main function
int main() {
  SetToStdErr(1);
  DebugLog::Enable("SpecExec");

  auto ila = SpecExecIla();

  DebugLog::Disable("SpecExec");
  return 0;
}

// initialize the constant value in the ir (the program)
MemVal IrInitVal() {
  /*
   * 0: mv %0 1     // branch condition (taken)
   * 1: br %0 4     // taken -- jump to 4 (nop)
   * 2: ld %2 0xff  // load secret to register 2 (should not be reached)
   * 3: nop
   * 4: nop
   */
  MemVal val(GenNop());
  val.set_data(0, GenMv(0, 1));
  val.set_data(1, GenBr(0, 4));
  val.set_data(2, GenLd(2, 0xff));
  return val;
}

// construct top-level ILA
InstrLvlAbsPtr SpecExecIla() {
  auto ila = InstrLvlAbs::New("m_top");

  // define state
  // data memory
  auto mem = ila->NewMemState("memory", REG_SIZE, REG_SIZE);
  // instruction memory
  auto ir = MemConst(IrInitVal(), REG_SIZE, INSTR_SIZE);
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

    auto init_op_exec = Eq(u_op_exec, OP_NOP);
    ila->AddInit(init_op_exec);

    auto init_op_comm = Eq(u_op_comm, OP_NOP);
    ila->AddInit(init_op_comm);
  }

  // instrs: branch, load, stall, and add
  { // branch
    auto instr = ila->NewInstr("Branch");
    auto decode = And(Eq(opcode, OP_BR), Not(f_spec));
    instr->SetDecode(decode);

    auto mem_nxt = mem;
    auto ir_nxt = ir;
    auto pc_nxt = pc;
    // increment vpc for pre-fetch
    auto vpc_nxt = Add(vpc, ONE);
    auto f_spec_nxt = f_spec;
    auto u_op_exec_nxt = OP_BR;
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

// NOP:         [ 0  0  0  0| ----------------------------------]
int GenNop() { return 0; }

// BR:          [ 0  0  0  1|       CND |            ADDR (IMM) ]
int GenBr(const int& cnd, const int& addr) {
  ILA_ASSERT(cnd < REG_NUM) << "Invalid reg num.";
  ILA_ASSERT((addr >> (IMM_HI + 1)) == 0) << "Invalid address.";
  int w = OPCODE::BR << OP_OFF;
  w |= cnd << CND_LO;
  w |= addr << IMM_LO;
  return w;
}

// LD:          [ 0  0  1  0|       DST |            ADDR (IMM) ]
int GenLd(const int& dst, const int& addr) {
  ILA_ASSERT(dst < REG_NUM) << "Invalid reg num.";
  ILA_ASSERT((addr >> (IMM_HI + 1)) == 0) << "Invalid address.";
  int w = OPCODE::LD << OP_OFF;
  w |= dst << DST_LO;
  w |= addr << IMM_LO;
  return w;
}

// MV:          [ 0  0  1  1|       DST |            VAL  (IMM) ]
int GenMv(const int& dst, const int& val) {
  ILA_ASSERT(dst < REG_NUM) << "Invalid reg num.";
  ILA_ASSERT((val >> (IMM_HI + 1)) == 0) << "Invalid value.";
  int w = OPCODE::MV << OP_OFF;
  w |= dst << DST_LO;
  w |= val << IMM_LO;
  return w;
}

