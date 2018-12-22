/// \file
/// Source for constructing MCM ILAs.

#include "../unit-include/mcm_ilas.h"

namespace ilang {

void McmIlaGen::GetLitmusSbReg(InstrLvlAbsPtr& T1, InstrLvlAbsPtr& T2) {
  T1 = InstrLvlAbs::New("T1");
  {
    auto x = T1->NewBvState("x", 8);
    auto y = T1->NewBvState("y", 8);
    auto r1 = T1->NewBvState("r1", 8);
    T1->AddInit(ExprFuse::Eq(x, ExprFuse::BvConst(0, 8)));
    T1->AddInit(ExprFuse::Eq(y, ExprFuse::BvConst(0, 8)));
    {
      auto instr = T1->NewInstr("store [x], 1");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(x, ExprFuse::BvConst(1, 8));
    }
    {
      auto instr = T1->NewInstr("load r1, [y]");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(r1, y);
    }
  }
  T2 = InstrLvlAbs::New("T2");
  {
    auto x = T2->NewBvState("x", 8);
    auto y = T2->NewBvState("y", 8);
    auto r2 = T2->NewBvState("r2", 8);
    T2->AddInit(ExprFuse::Eq(ExprFuse::Add(x, y), ExprFuse::BvConst(0, 8)));

    {
      auto instr = T2->NewInstr("store [y], 1");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(y, ExprFuse::BvConst(1, 8));
    }
    {
      auto instr = T2->NewInstr("load r2, [x]");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(r2, x);
    }
  }
}
void McmIlaGen::GetLitmusMpReg(InstrLvlAbsPtr& T1, InstrLvlAbsPtr& T2) {
  T1 = InstrLvlAbs::New("T1");
  {
    auto x = T1->NewBvState("x", 8);
    auto y = T1->NewBvState("y", 8);
    T1->AddInit(ExprFuse::Eq(x, ExprFuse::BvConst(0, 8)));
    T1->AddInit(ExprFuse::Eq(y, ExprFuse::BvConst(0, 8)));
    {
      auto instr = T1->NewInstr("store [x], 1");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(x, ExprFuse::BvConst(1, 8));
    }
    {
      auto instr = T1->NewInstr("store [y], 1");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(y, ExprFuse::BvConst(1, 8));
    }
  }
  T2 = InstrLvlAbs::New("T2");
  {
    auto x = T2->NewBvState("x", 8);
    auto y = T2->NewBvState("y", 8);
    auto r1 = T2->NewBvState("r1", 8);
    auto r2 = T2->NewBvState("r2", 8);

    {
      auto instr = T2->NewInstr("load r1, [y]");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(r1, y);
    }
    {
      auto instr = T2->NewInstr("load r2, [x]");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(r2, x);
    }
  }
}
void McmIlaGen::GetLitmusSbMem(InstrLvlAbsPtr& T1, InstrLvlAbsPtr& T2) {
  auto x = ExprFuse::BvConst(0x4, 8); // x : addr 4
  auto y = ExprFuse::BvConst(0x8, 8); // y : addr 8

  T1 = InstrLvlAbs::New("T1");
  {
    auto mem = T1->NewMemState("mem", 8, 8);
    auto r1 = T1->NewBvState("r1", 8);

    T1->AddInit(ExprFuse::Eq(ExprFuse::Load(mem, x), ExprFuse::BvConst(0, 8)));

    {
      auto instr = T1->NewInstr("store [x], 1");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(mem, ExprFuse::Store(mem, x, ExprFuse::BvConst(1, 8)));
    }
    {
      auto instr = T1->NewInstr("load r1, [y]");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(r1, ExprFuse::Load(mem, y));
    }
  }
  T2 = InstrLvlAbs::New("T2");
  {
    auto mem = T2->NewMemState("mem", 8, 8);
    auto r2 = T2->NewBvState("r2", 8);

    T2->AddInit(ExprFuse::Eq(ExprFuse::Load(mem, y), ExprFuse::BvConst(0, 8)));

    {
      auto instr = T2->NewInstr("store [y], 1");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(mem, ExprFuse::Store(mem, y, ExprFuse::BvConst(1, 8)));
    }
    {
      auto instr = T2->NewInstr("load r2, [x]");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(r2, ExprFuse::Load(mem, x));
    }
  }
} // void McmIlaGen::GetLitmusSbMem(InstrLvlAbsPtr & T1, InstrLvlAbsPtr & T2)

void McmIlaGen::GetLitmusMpMem(InstrLvlAbsPtr& T1, InstrLvlAbsPtr& T2) {

  auto x = ExprFuse::BvConst(0x4, 8); // x : addr 4
  auto y = ExprFuse::BvConst(0x8, 8); // y : addr 8

  T1 = InstrLvlAbs::New("T1");
  {
    auto mem = T1->NewMemState("mem", 8, 8);

    T1->AddInit(ExprFuse::Eq(ExprFuse::Load(mem, x), ExprFuse::BvConst(0, 8)));

    {
      auto instr = T1->NewInstr("store [x], 1");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(mem, ExprFuse::Store(mem, x, ExprFuse::BvConst(1, 8)));
    }
    {
      auto instr = T1->NewInstr("store [y], 1");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(mem, ExprFuse::Store(mem, y, ExprFuse::BvConst(1, 8)));
    }
  }
  T2 = InstrLvlAbs::New("T2");
  {
    auto mem = T2->NewMemState("mem", 8, 8);
    auto r1 = T2->NewBvState("r1", 8);
    auto r2 = T2->NewBvState("r2", 8);

    T2->AddInit(ExprFuse::Eq(ExprFuse::Load(mem, y), ExprFuse::BvConst(0, 8)));

    {
      auto instr = T2->NewInstr("load r1, [y]");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(r1, ExprFuse::Load(mem, y));
    }
    {
      auto instr = T2->NewInstr("load r2, [x]");
      instr->set_decode(ExprFuse::BoolConst(true));
      instr->set_update(r2, ExprFuse::Load(mem, x));
    }
  }

} // void McmIlaGen::GetLitmusMpMem(InstrLvlAbsPtr & T1, InstrLvlAbsPtr & T2)

InstrLvlAbsPtr McmIlaGen::GetIlaOneInstSimp() {
  // parameters
  static const unsigned reg_num_ = 8;

  auto ila = InstrLvlAbs::New("OneInstSimp");

  // state variables.
  std::vector<ExprPtr> regs;
  for (unsigned i = 0; i < reg_num_; i++) {
    auto reg_name = "r" + std::to_string(i);
    auto reg = ila->NewBvState(reg_name, 8);
    regs.push_back(reg);
  }
  auto pc = ila->NewBvState("pc", 8);

  // valid
  ila->SetValid(ExprFuse::BoolConst(true));

  // init : pc == 0 /\ r0 == 0
  ila->AddInit(ExprFuse::Eq(pc, ExprFuse::BvConst(0, 8)));
  ila->AddInit(ExprFuse::Eq(regs[0], ExprFuse::BvConst(0, 8)));

  // Instruction 1: (pc == 0)  : r0 = r0 ; r1 = r2 + r3 . we don't update pc
  // explicitly
  auto instr_1 = ila->NewInstr("ADD: r1 <- r2 + r3");
  {
    auto decode = ExprFuse::Eq(pc, ExprFuse::BvConst(0, 8));
    instr_1->set_decode(decode);
    instr_1->set_update(regs[1], ExprFuse::Add(regs[2], regs[3]));
  }

  return ila;
}

InstrLvlAbsPtr McmIlaGen::GetIlaMultiInstLinearSimp() {
  // parameters
  static const unsigned reg_num_ = 8;

  auto ila = InstrLvlAbs::New("MultiInstLinearSimp");

  // state variables.
  std::vector<ExprPtr> regs;
  for (unsigned i = 0; i < reg_num_; i++) {
    auto reg_name = "r" + std::to_string(i);
    auto reg = ila->NewBvState(reg_name, 8);
    regs.push_back(reg);
  }
  auto pc = ila->NewBvState("pc", 8);

  // valid
  ila->SetValid(ExprFuse::BoolConst(true));

  // init : pc == 0 /\ r0 == 0
  ila->AddInit(ExprFuse::Eq(pc, ExprFuse::BvConst(0, 8)));
  ila->AddInit(ExprFuse::Eq(regs[0], ExprFuse::BvConst(0, 8)));
  ila->AddInit(ExprFuse::Eq(regs[1], ExprFuse::BvConst(1, 8)));
  ila->AddInit(ExprFuse::Eq(regs[2], ExprFuse::BvConst(2, 8)));

  // Instruction 1: (pc == 0)  : r1 += 1 ; pc += 1
  auto instr_1 = ila->NewInstr("pc-0:INC r1");
  {
    auto decode = ExprFuse::Eq(pc, ExprFuse::BvConst(0, 8));
    instr_1->set_decode(decode);
    instr_1->set_update(regs[1],
                        ExprFuse::Add(regs[1], ExprFuse::BvConst(1, 8)));
    instr_1->set_update(pc, ExprFuse::Add(pc, ExprFuse::BvConst(1, 8)));
  }

  // Instruction 2: (pc == 1)  : r1 -= 1 ; pc += 1
  auto instr_2 = ila->NewInstr("pc-1:DEC r1");
  {
    auto decode = ExprFuse::Eq(pc, ExprFuse::BvConst(1, 8));
    instr_2->set_decode(decode);
    instr_2->set_update(regs[1],
                        ExprFuse::Sub(regs[1], ExprFuse::BvConst(1, 8)));
    instr_2->set_update(pc, ExprFuse::Add(pc, ExprFuse::BvConst(1, 8)));
  }

  // Instruction 3: (pc == 2)  : r1 = r2 ; r2 = r1 ; pc NC
  auto instr_3 = ila->NewInstr("pc-2:SWAP r1 <=> r2");
  {
    auto decode = ExprFuse::Eq(pc, ExprFuse::BvConst(2, 8));
    instr_3->set_decode(decode);
    instr_3->set_update(regs[1], regs[2]);
    instr_3->set_update(regs[2], regs[1]);
    instr_3->set_update(pc, pc);
  }

  return ila;
}

InstrLvlAbsPtr McmIlaGen::GetIlaMultiInstCcSimp() {
  // parameters
  static const unsigned reg_num_ = 8;

  auto ila = InstrLvlAbs::New("MultiInstCcSimp");

  // state variables.
  std::vector<ExprPtr> regs;
  for (unsigned i = 0; i < reg_num_; i++) {
    auto reg_name = "r" + std::to_string(i);
    auto reg = ila->NewBvState(reg_name, 8);
    regs.push_back(reg);
  }
  auto pc = ila->NewBvState("pc", 8);

  // valid
  ila->SetValid(ExprFuse::BoolConst(true));

  // init : pc == 0 /\ r0 == 0
  ila->AddInit(ExprFuse::Eq(pc, ExprFuse::BvConst(0, 8)));
  ila->AddInit(ExprFuse::Eq(regs[0], ExprFuse::BvConst(0, 8)));

  // Instruction 1: (pc == 0)  : r1 += 1 ; pc += 1
  auto instr_1 = ila->NewInstr("pc-0:INC r1");
  {
    auto decode = ExprFuse::Eq(pc, ExprFuse::BvConst(0, 8));
    instr_1->set_decode(decode);
    instr_1->set_update(regs[1],
                        ExprFuse::Add(regs[0], ExprFuse::BvConst(1, 8)));
  }

  // Instruction 2: (pc == 0)  : r1 -= 1 ; pc += 1
  auto instr_2 = ila->NewInstr("pc-0:DEC r1");
  {
    auto decode = ExprFuse::Eq(pc, ExprFuse::BvConst(0, 8));
    instr_2->set_decode(decode);
    instr_2->set_update(regs[1],
                        ExprFuse::Sub(regs[0], ExprFuse::BvConst(1, 8)));
  }

  // Instruction 3: (pc == 0)  : r1 = r2 ; r2 = r1 ; pc NC
  auto instr_3 = ila->NewInstr("pc-0:SWAP r1 <= r2");
  {
    auto decode = ExprFuse::Eq(pc, ExprFuse::BvConst(0, 8));
    instr_3->set_decode(decode);
    instr_3->set_update(regs[1], regs[2]);
    instr_3->set_update(regs[2], regs[1]);
  }

  return ila;
}

#define REG_VAL(x)                                                             \
  ExprFuse::Ite(                                                               \
      ExprFuse::Eq((x), ExprFuse::BvConst(3, 2)), regs[3],                     \
      ExprFuse::Ite(                                                           \
          ExprFuse::Eq((x), ExprFuse::BvConst(2, 2)), regs[2],                 \
          ExprFuse::Ite(                                                       \
              ExprFuse::Eq((x), ExprFuse::BvConst(1, 2)), regs[1],             \
              ExprFuse::Ite(ExprFuse::Eq((x), ExprFuse::BvConst(0, 2)),        \
                            regs[0], regs[0]))))

#define UPDATE_COND(ridx, val)                                                 \
  ExprFuse::Ite(ExprFuse::Eq(rd, ExprFuse::BvConst((ridx), 2)), val, regs[ridx])
#define UPDATE_R(val, inst)                                                    \
  do {                                                                         \
    for (unsigned idx = 0; idx < reg_num_; idx++)                              \
      (inst)->set_update(regs[idx], UPDATE_COND(idx, (val)));                  \
  } while (0);

InstrLvlAbsPtr McmIlaGen::GetIlaOneInstPcDecode(const std::string& ila_name,
                                                bool initRegs) {
  // parameters
  static const unsigned reg_num_ = 4;

  auto ila = InstrLvlAbs::New(ila_name);

  // state variables.
  std::vector<ExprPtr> regs;
  for (unsigned i = 0; i < reg_num_; i++) {
    auto reg_name = "r" + std::to_string(i);
    auto reg = ila->NewBvState(reg_name, 8);
    regs.push_back(reg);
  }
  auto pc = ila->NewBvState("pc", 8);
  auto mem = ila->NewMemState("mem", 8, 8);

  // aux variables
  auto inst = ExprFuse::Load(mem, pc); // 8 bit wide
  auto opcode = ExprFuse::Extract(
      inst, 1, 0); // 2 bit wide , // 7-6 rs , 5-4 rt, 3-2 rd, 1-0 op
  auto rs = ExprFuse::Extract(inst, 7, 6);
  auto rt = ExprFuse::Extract(inst, 5, 4);
  auto rd = ExprFuse::Extract(inst, 3, 2);
  auto rs_val = REG_VAL(rs);
  auto rt_val = REG_VAL(rt);
  auto rd_val = REG_VAL(rd);
  auto OP_ADDI = ExprFuse::BvConst(0, 2);
  auto OP_ADDR = ExprFuse::BvConst(1, 2);
  auto OP_LOAD = ExprFuse::BvConst(2, 2);
  auto OP_STORE = ExprFuse::BvConst(3, 2);

  // valid
  ila->SetValid(ExprFuse::BoolConst(true));

  // init : pc == 0 /\ r0 == 0
  ila->AddInit(ExprFuse::Eq(pc, ExprFuse::BvConst(0, 8)));
  ila->AddInit(ExprFuse::Eq(regs[0], ExprFuse::BvConst(0, 8)));

  if (initRegs)
    for (unsigned i = 1; i < reg_num_; i++)
      ila->AddInit(ExprFuse::Eq(regs[i], ExprFuse::BvConst(0, 8)));

  // Instruction 1: ADDI
  auto instr_1 = ila->NewInstr("ADDI");
  {
    auto decode = ExprFuse::Eq(opcode, OP_ADDI);
    instr_1->set_decode(decode);

    UPDATE_R(ExprFuse::Add(rs_val, ExprFuse::ZExt(rt, 8)), instr_1);
    instr_1->set_update(pc, ExprFuse::Add(pc, ExprFuse::BvConst(1, 8)));
  }

  // Instruction 2: ADDR
  auto instr_2 = ila->NewInstr("ADDR");
  {
    auto decode = ExprFuse::Eq(opcode, OP_ADDR);
    instr_2->set_decode(decode);
    UPDATE_R(ExprFuse::Add(rs_val, rt_val), instr_2);
    instr_2->set_update(pc, ExprFuse::Add(pc, ExprFuse::BvConst(1, 8)));
  }

  // Instruction 3: LOAD rd = [rs]
  auto instr_3 = ila->NewInstr("LOAD");
  {
    auto decode = ExprFuse::Eq(opcode, OP_LOAD);
    instr_3->set_decode(decode);
    UPDATE_R(ExprFuse::Load(mem, rs_val), instr_3);
    instr_3->set_update(pc, ExprFuse::Add(pc, ExprFuse::BvConst(1, 8)));
  }

  // Instruction 4: STORE [rs], rt
  auto instr_4 = ila->NewInstr("STORE");
  {
    auto decode = ExprFuse::Eq(opcode, OP_STORE);
    instr_4->set_decode(decode);
    instr_4->set_update(mem, ExprFuse::Store(mem, rs_val, rt_val));
    instr_4->set_update(pc, ExprFuse::Add(pc, ExprFuse::BvConst(1, 8)));
  }

  return ila;
}

InstrLvlAbsPtr McmIlaGen::GetSys1Ila1() {
  return GetIlaOneInstPcDecode("Sys1Ila1");
}
InstrLvlAbsPtr McmIlaGen::GetSys1Ila2() {
  return GetIlaOneInstPcDecode("Sys1Ila2");
}

InstrLvlAbsPtr McmIlaGen::GetSys2Ila1() {
  return GetIlaOneInstPcDecode("Sys2Ila1");
}
InstrLvlAbsPtr McmIlaGen::GetSys2Ila2() {
  return GetIlaOneInstPcDecode("Sys2Ila2");
}
InstrLvlAbsPtr McmIlaGen::GetSys2Ila3() {
  return GetIlaOneInstPcDecode("Sys2Ila3");
}

} // namespace ilang
