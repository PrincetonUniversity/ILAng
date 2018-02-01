/// \file
/// ILA modeling for speculative execution with pipeline

#include "ila/instr_lvl_abs.h"

using namespace ila;
using namespace ExprFuse;

// ------------------------- Instruction Definition ------------------------- //
/*
 * Instruction: [15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00] [f_flush]
 * NOP:         [ 0  0  0  0| ----------------------------------]     0
 * BR:          [ 0  0  0  1| CND (REG) |            ADDR (IMM) ]     0
 * LD:          [ 0  0  1  0| DST (REG) |            ADDR (IMM) ]     0
 * MV:          [ 0  0  1  1| DST (REG) |            VAL  (IMM) ]     0
 * FLUSH:       [-----------------------------------------------]     1
 */

// ------------------------- Macros & Constants ----------------------------- //
#define REG_NUM 4
#define REG_SIZE 8
#define INSTR_SIZE 16
#define OP_LENGTH 4
#define IDX_LENGTH 4
#define IMM_LENGTH 8

#define OP_LO 12
#define OP_HI (OP_LO + OP_LENGTH - 1)
#define IDX_LO 8
#define IDX_HI (IDX_LO + IDX_LENGTH - 1)
#define IMM_LO 0
#define IMM_HI (IMM_LO + IMM_LENGTH - 1)

#define SECRET_ADDR 0xff
#define SECRET_DATA 0xff

auto ONE = BvConst(1, REG_SIZE);
auto ZERO = BvConst(0, REG_SIZE);
auto TRUE = BoolConst(true);
auto FALSE = BoolConst(false);

enum OPCODE { NOP = 0, BR, LD, MV, FLUSH };
auto OP_NOP = BvConst(OPCODE::NOP, OP_LENGTH);
auto OP_BR = BvConst(OPCODE::BR, OP_LENGTH);
auto OP_LD = BvConst(OPCODE::LD, OP_LENGTH);
auto OP_MV = BvConst(OPCODE::MV, OP_LENGTH);
auto OP_FLUSH = BvConst(OPCODE::FLUSH, OP_LENGTH);

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
  val.set_data(2, GenLd(2, SECRET_ADDR));
  return val;
}

// construct top-level ILA
InstrLvlAbsPtr SpecExecIla() {
  auto ila = InstrLvlAbs::New("m_top");

  // ------------------------- States --------------------------------------- //
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
  auto f_flush = ila->NewBoolState("f_flush");
  // register files
  ExprPtrVec regs;
  for (auto i = 0; i != REG_NUM; i++) {
    auto reg_name = "reg" + std::to_string(i);
    regs.push_back(ila->NewBvState(reg_name, REG_SIZE));
  }
  // execution opcode
  auto op_exec = ila->NewBvState("op_exec", OP_LENGTH);
  // execution register index
  auto idx_exec = ila->NewBvState("idx_exec", IDX_LENGTH);
  // execution immediate
  auto imm_exec = ila->NewBvState("imm_exec", IMM_LENGTH);
  // commit opcode
  auto op_comm = ila->NewBvState("op_comm", OP_LENGTH);

  // ------------------------- Valid ---------------------------------------- //
  ila->SetValid(TRUE);

  // ------------------------- Fetch ---------------------------------------- //
  auto instr_w = Load(ir, vpc);
  ila->SetFetch(instr_w);
  auto opcode = Extract(instr_w, OP_HI, OP_LO);

  // ------------------------- Inits ---------------------------------------- //
  { // pc, vpc, f_flush, op_exec, op_comm, idx_exec, imm_exec, regs, mem, cache
    ila->AddInit(Eq(pc, ZERO));          // default value
    ila->AddInit(Eq(vpc, ZERO));         // same as pc
    ila->AddInit(Eq(f_flush, FALSE));    // no need to flush
    ila->AddInit(Eq(op_exec, OP_FLUSH)); // no previous instr (not NOP)
    ila->AddInit(Eq(op_comm, OP_FLUSH)); // no previous instr (not NOP)

    for (auto i = 0; i != REG_NUM; i++)
      ila->AddInit(Eq(regs[i], ZERO)); // initialize to be 0

    auto secret_addr = BvConst(SECRET_ADDR, REG_SIZE);
    auto secret_data = BvConst(SECRET_DATA, REG_SIZE);
    ila->AddInit(Eq(secret_data, Load(mem, secret_addr)));   // contains secret
    ila->AddInit(Ne(secret_data, Load(cache, secret_addr))); // no secret
  }

  // ------------------------- Instruction: Branch -------------------------- //
  { // decode
    auto instr = ila->NewInstr("Branch");
    auto decode = And(Eq(opcode, OP_BR), Not(f_flush));
    instr->SetDecode(decode);

    // state updates
    instr->AddUpdate(vpc, Add(vpc, ONE)); // speculatively not-taken
    instr->AddUpdate(op_exec, OP_BR);     // pass down
    instr->AddUpdate(idx_exec, Extract(instr_w, IDX_HI, IDX_LO)); // pass down
    instr->AddUpdate(imm_exec, Extract(instr_w, IMM_HI, IMM_LO)); // pass down
  }

  { // child-ILA for instruction Branch
    auto child = ila->NewChild("BranchChild");
    // state
    auto br_addr = child->NewBvState("br_addr", REG_SIZE);
    auto br_take = child->NewBoolState("br_take");
    // valid
    child->SetValid(TRUE);
    // fetch
    child->SetFetch(Concat(op_exec, op_comm));
    // init
    child->AddInit(Eq(br_take, FALSE));

    { // exec child-instruction
      auto instr = child->NewInstr("BranchExec");
      auto decode = And(Eq(op_exec, OP_BR), Not(f_flush));
      instr->SetDecode(decode);

      // state updates
      auto br_take_nxt = FALSE;
      for (auto i = 0; i != REG_NUM; i++) {
        auto reg_idx_i = BvConst(i, IDX_LENGTH);
        br_take_nxt =
            Ite(Eq(reg_idx_i, idx_exec), Eq(regs[i], ONE), br_take_nxt);
      }
      instr->AddUpdate(br_take, br_take_nxt); // compare with 1
      instr->AddUpdate(br_addr, imm_exec);    // pass down

      instr->AddUpdate(cache, cache);   // unchanged
      instr->AddUpdate(op_comm, OP_BR); // pass down
    }

    { // commit child-instruction
      auto instr = child->NewInstr("BranchComm");
      auto decode = And(Eq(op_comm, OP_BR), Not(f_flush));
      instr->SetDecode(decode);

      // state updates
      auto pc_nxt = Ite(br_take, br_addr, Add(pc, ONE));
      instr->AddUpdate(pc, pc_nxt); // update pc based on previous result
      instr->AddUpdate(mem, mem);   // unchanged
      for (auto i = 0; i != REG_NUM; i++)
        instr->AddUpdate(regs[i], regs[i]); // unchanged
      instr->AddUpdate(f_flush, br_take); // speculate not take (flush if take)
    }
  }

  // ------------------------- Instruction: Load ---------------------------- //
  { // decode
    auto instr = ila->NewInstr("Load");
    auto decode = And(Eq(opcode, OP_LD), Not(f_flush));
    instr->SetDecode(decode);

    // state updates
    instr->AddUpdate(vpc, Add(vpc, ONE)); // normal prediction
    instr->AddUpdate(op_exec, OP_LD);     // pass down
    instr->AddUpdate(idx_exec, Extract(instr_w, IDX_HI, IDX_LO)); // pass down
    instr->AddUpdate(imm_exec, Extract(instr_w, IMM_HI, IMM_LO)); // pass down
  }

  { // child-ILA for instruction Load
    auto child = ila->NewChild("LoadChild");
    // state
    auto ld_data = child->NewBvState("ld_data", REG_SIZE);
    auto ld_idx = child->NewBvState("ld_idx", IDX_LENGTH);
    // valid
    child->SetValid(TRUE);
    // fetch
    child->SetFetch(Concat(op_exec, op_comm));
    // init
    child->AddInit(Eq(ld_data, ZERO));

    { // exec child-instruction
      auto instr = child->NewInstr("LoadExec");
      auto decode = And(Eq(op_exec, OP_LD), Not(f_flush));
      instr->SetDecode(decode);

      // state updates
      instr->AddUpdate(ld_idx, idx_exec); // pass down
      auto addr = imm_exec;
      auto ld_data_nxt = Load(mem, addr);
      instr->AddUpdate(ld_data, ld_data_nxt); // pre-load data

      instr->AddUpdate(cache, Store(cache, addr, ld_data_nxt)); // caching
      instr->AddUpdate(op_comm, OP_LD);                         // pass down
    }

    { // comm child-instruction
      auto instr = child->NewInstr("LoadComm");
      auto decode = And(Eq(op_comm, OP_LD), Not(f_flush));
      instr->SetDecode(decode);

      // state updates
      instr->AddUpdate(pc, Add(pc, ONE)); // normal increment
      instr->AddUpdate(mem, mem);         // unchanged
      instr->AddUpdate(f_flush, FALSE);   // always success
      for (auto i = 0; i != REG_NUM; i++) {
        auto reg_i_nxt =
            Ite(Eq(ld_idx, BvConst(i, IDX_LENGTH)), ld_data, regs[i]);
        instr->AddUpdate(regs[i], reg_i_nxt); // only update specified register
      }
    }
  }

  // ------------------------- Instruction: MV ------------------------------ //
  { // decode
    auto instr = ila->NewInstr("Move");
    auto decode = And(Eq(opcode, OP_MV), Not(f_flush));
    instr->SetDecode(decode);

    // state updates
    instr->AddUpdate(vpc, Add(vpc, ONE)); // normal prediction
    instr->AddUpdate(op_exec, OP_MV);     // pass down
    instr->AddUpdate(idx_exec, Extract(instr_w, IDX_HI, IDX_LO)); // pass down
    instr->AddUpdate(imm_exec, Extract(instr_w, IMM_HI, IMM_LO)); // pass down
  }

  { // child-ILA for instruction Move
    auto child = ila->NewChild("MoveChild");
    // state
    auto mv_data = child->NewBvState("mv_data", REG_SIZE);
    auto mv_idx = child->NewBvState("mv_idx", IDX_LENGTH);
    // valid
    child->SetValid(TRUE);
    // fetch
    child->SetFetch(Concat(op_exec, op_comm));
    // init
    child->AddInit(Eq(mv_data, ZERO));

    { // exec child-instruction
      auto instr = child->NewInstr("MoveExec");
      auto decode = And(Eq(op_exec, OP_MV), Not(f_flush));
      instr->SetDecode(decode);

      // state updates
      instr->AddUpdate(mv_idx, idx_exec);  // pass down
      instr->AddUpdate(mv_data, imm_exec); // pass down

      instr->AddUpdate(cache, cache);   // unchanged
      instr->AddUpdate(op_comm, OP_MV); // pass down
    }

    { // comm child-instruction
      auto instr = child->NewInstr("MoveComm");
      auto decode = And(Eq(op_comm, OP_MV), Not(f_flush));
      instr->SetDecode(decode);

      // state updates
      instr->AddUpdate(pc, Add(pc, ONE)); // normal increment
      instr->AddUpdate(mem, mem);         // unchanged
      instr->AddUpdate(f_flush, FALSE);   // always success

      for (auto i = 0; i != REG_NUM; i++) {
        auto reg_i_nxt =
            Ite(Eq(mv_idx, BvConst(i, IDX_LENGTH)), mv_data, regs[i]);
        instr->AddUpdate(regs[i], reg_i_nxt); // only update the specified reg
      }
    }
  }

  // ------------------------- Instruction: NOP ----------------------------- //
  { // decode
    auto instr = ila->NewInstr("Nop");
    // XXX try using negate form for totality
    auto decode = And(Eq(opcode, OP_NOP), Not(f_flush));
    instr->SetDecode(decode);

    // state updates
    instr->AddUpdate(vpc, Add(vpc, ONE)); // normal prediction
    instr->AddUpdate(op_exec, OP_NOP);    // pass down
    instr->AddUpdate(idx_exec, idx_exec); // don't care
    instr->AddUpdate(imm_exec, imm_exec); // don't care
  }

  { // child-ILA for instruction NOP
    auto child = ila->NewChild("NopChild");
    // valid
    child->SetValid(TRUE);
    // fetch
    child->SetFetch(Concat(op_exec, op_comm));

    { // exec child-instruction
      auto instr = child->NewInstr("NopExec");
      // XXX try using negate form for totality
      auto decode = And(Eq(op_exec, OP_NOP), Not(f_flush));
      instr->SetDecode(decode);

      // state updates
      instr->AddUpdate(cache, cache);    // unchanged
      instr->AddUpdate(op_comm, OP_NOP); // pass down
    }

    { // comm child-instruction
      auto instr = child->NewInstr("NopComm");
      // XXX try using negate form for totality
      auto decode = And(Eq(op_comm, OP_NOP), Not(f_flush));
      instr->SetDecode(decode);

      // state updates
      instr->AddUpdate(pc, Add(pc, ONE)); // normal increment
      instr->AddUpdate(mem, mem);         // unchanged
      instr->AddUpdate(f_flush, FALSE);   // always success
      for (auto i = 0; i != REG_NUM; i++)
        instr->AddUpdate(regs[i], regs[i]); // unchanged
    }
  }

  // ------------------------- Instruction: FLUSH --------------------------- //
  { // decode
    auto instr = ila->NewInstr("Flush");
    instr->SetDecode(f_flush);

    // state updates
    instr->AddUpdate(vpc, pc);            // reset pc
    instr->AddUpdate(op_exec, OP_FLUSH);  // insert bubble
    instr->AddUpdate(idx_exec, idx_exec); // don't care
    instr->AddUpdate(imm_exec, imm_exec); // don't care
  }

  { // child-ILA for instruction FLUSH
    auto child = ila->NewChild("FlushChild");
    // valid
    child->SetValid(TRUE);
    // fetch
    child->SetFetch(Concat(op_exec, op_comm));

    { // exec child-instruction
      auto instr = child->NewInstr("FlushExec");
      auto decode = Or(f_flush, Eq(op_exec, OP_FLUSH));
      instr->SetDecode(decode);

      // state updates
      instr->AddUpdate(cache, cache);      // unchanged
      instr->AddUpdate(op_comm, OP_FLUSH); // pass down
    }

    { // comm child-instruction
      auto instr = child->NewInstr("FlushComm");
      auto decode = Or(f_flush, Eq(op_comm, OP_FLUSH));
      instr->SetDecode(decode);

      // state updates
      instr->AddUpdate(pc, pc);         // unchanged!!
      instr->AddUpdate(mem, mem);       // unchanged
      instr->AddUpdate(f_flush, FALSE); // reset flushing flag
      for (auto i = 0; i != REG_NUM; i++)
        instr->AddUpdate(regs[i], regs[i]); // unchanged
    }
  }

  ILA_INFO << "Generate Spec-Pipe ILA: " << ila;

  return ila;
}

// NOP: [ 0  0  0  0| ----------------------------------]
int GenNop() { return 0; }

// BR:  [ 0  0  0  1|       CND |            ADDR (IMM) ]
int GenBr(const int& cnd, const int& addr) {
  ILA_ASSERT(cnd < REG_NUM) << "Invalid reg num.";
  ILA_ASSERT((addr >> (IMM_HI + 1)) == 0) << "Invalid address.";
  int w = OPCODE::BR << OP_LO;
  w |= cnd << IDX_LO;
  w |= addr << IMM_LO;
  return w;
}

// LD:  [ 0  0  1  0|       DST |            ADDR (IMM) ]
int GenLd(const int& dst, const int& addr) {
  ILA_ASSERT(dst < REG_NUM) << "Invalid reg num.";
  ILA_ASSERT((addr >> (IMM_HI + 1)) == 0) << "Invalid address.";
  int w = OPCODE::LD << OP_LO;
  w |= dst << IDX_LO;
  w |= addr << IMM_LO;
  return w;
}

// MV:  [ 0  0  1  1|       DST |            VAL  (IMM) ]
int GenMv(const int& dst, const int& val) {
  ILA_ASSERT(dst < REG_NUM) << "Invalid reg num.";
  ILA_ASSERT((val >> (IMM_HI + 1)) == 0) << "Invalid value.";
  int w = OPCODE::MV << OP_LO;
  w |= dst << IDX_LO;
  w |= val << IMM_LO;
  return w;
}

