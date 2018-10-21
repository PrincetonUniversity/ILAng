/// \file
/// Source for constructing MCM ILAs.

#include "../unit-include/mcm_ilas.h"

namespace ila {
  InstrLvlAbsPtr McmIlaGen::GetIlaOneInstSimp()
  {
    // parameters
    static const unsigned reg_num_ = 8;

    auto ila = InstrLvlAbsPtr::New("OneInstSimp");

    // state variables.
    std::vector<ExprPtr> regs;
    for (auto i = 0; i < reg_num_; i++) {
      auto reg_name = "r" + std::to_string(i);
      auto reg = ila->NewBvState(reg_name, 8);
      regs.push_back(reg);
    }
    auto pc = ila->NewBvState("pc", 8);

    // valid
    ila->SetValid(ExprFuse::BoolConst(true));

    // init : pc == 0 /\ r0 == 0
    ila->AddInit( ExprFuse::Eq(pc, ExprFuse::BvConst(0,8) ) );
    ila->AddInit( ExprFuse::Eq(regs[0], ExprFuse::BvConst(0,8) ) );

    // Instruction 1: (pc == 0)  : r0 = r0 ; r1 = r2 + r3 . we don't update pc explicitly
    auto instr_1 = ila->NewInstr("ADD: r1 <- r2 + r3");
    {
      auto decode = ExprFuse::Eq(pc, ExprFuse::BvConst(0,8) );
      instr_1->SetDecode(decode);
      instr_1->AddUpdate(regs[1], ExprFuse::Add(regs[2], regs[3]) );
    }

    return ila;
  }

  InstrLvlAbsPtr McmIlaGen::GetIlaMultiInstLinearSimp()
  {
    // parameters
    static const unsigned reg_num_ = 8;

    auto ila = InstrLvlAbsPtr::New("MultiInstLinearSimp");

    // state variables.
    std::vector<ExprPtr> regs;
    for (auto i = 0; i < reg_num_; i++) {
      auto reg_name = "r" + std::to_string(i);
      auto reg = ila->NewBvState(reg_name, 8);
      regs.push_back(reg);
    }
    auto pc = ila->NewBvState("pc", 8);

    // valid
    ila->SetValid(ExprFuse::BoolConst(true));

    // init : pc == 0 /\ r0 == 0
    ila->AddInit( ExprFuse::Eq(pc, ExprFuse::BvConst(0,8) ) );
    ila->AddInit( ExprFuse::Eq(regs[0], ExprFuse::BvConst(0,8) ) );

    // Instruction 1: (pc == 0)  : r1 += 1 ; pc += 1
    auto instr_1 = ila->NewInstr("pc-0:INC r1");
    {
      auto decode = ExprFuse::Eq(pc, ExprFuse::BvConst(0,8) );
      instr_1->SetDecode(decode);
      instr_1->AddUpdate(regs[1], ExprFuse::Add(regs[0] , ExprFuse::BvConst(1,8) ) );
      instr_1->AddUpdate(pc, ExprFuse::Add(pc, ExprFuse::BvConst(1,8)));
    }

    // Instruction 2: (pc == 1)  : r1 -= 1 ; pc += 1
    auto instr_2 = ila->NewInstr("pc-1:DEC r1");
    {
      auto decode = ExprFuse::Eq(pc, ExprFuse::BvConst(1,8) );
      instr_2->SetDecode(decode);
      instr_2->AddUpdate(regs[1], ExprFuse::Sub(regs[0] , ExprFuse::BvConst(1,8) ) );
      instr_2->AddUpdate(pc, ExprFuse::Add(pc, ExprFuse::BvConst(1,8)));
    }

    // Instruction 3: (pc == 2)  : r1 = r2 ; r2 = r1 ; pc NC
    auto instr_3 = ila->NewInstr("pc-2:SWAP r1 <=> r2");
    {
      auto decode = ExprFuse::Eq(pc, ExprFuse::BvConst(2,8) );
      instr_3->SetDecode(decode);
      instr_3->AddUpdate(regs[1], regs[2] );
      instr_3->AddUpdate(regs[2], regs[1] );
      instr_3->AddUpdate(pc, pc);
    }

    return ila;
  }

  InstrLvlAbsPtr McmIlaGen::GetIlaMultiInstCcSimp()
  {
    // parameters
    static const unsigned reg_num_ = 8;

    auto ila = InstrLvlAbsPtr::New("MultiInstCcSimp");

    // state variables.
    std::vector<ExprPtr> regs;
    for (auto i = 0; i < reg_num_; i++) {
      auto reg_name = "r" + std::to_string(i);
      auto reg = ila->NewBvState(reg_name, 8);
      regs.push_back(reg);
    }
    auto pc = ila->NewBvState("pc", 8);

    // valid
    ila->SetValid(ExprFuse::BoolConst(true));

    // init : pc == 0 /\ r0 == 0
    ila->AddInit( ExprFuse::Eq(pc, ExprFuse::BvConst(0,8) ) );
    ila->AddInit( ExprFuse::Eq(regs[0], ExprFuse::BvConst(0,8) ) );

    // Instruction 1: (pc == 0)  : r1 += 1 ; pc += 1
    auto instr_1 = ila->NewInstr("pc-0:INC r1");
    {
      auto decode = ExprFuse::Eq(pc, ExprFuse::BvConst(0,8) );
      instr_1->SetDecode(decode);
      instr_1->AddUpdate(regs[1], ExprFuse::Add(regs[0] , ExprFuse::BvConst(1,8) ) );
    }

    // Instruction 2: (pc == 0)  : r1 -= 1 ; pc += 1
    auto instr_2 = ila->NewInstr("pc-0:DEC r1");
    {
      auto decode = ExprFuse::Eq(pc, ExprFuse::BvConst(0,8) );
      instr_2->SetDecode(decode);
      instr_2->AddUpdate(regs[1], ExprFuse::Sub(regs[0] , ExprFuse::BvConst(1,8) ) );
    }

    // Instruction 3: (pc == 0)  : r1 = r2 ; r2 = r1 ; pc NC
    auto instr_3 = ila->NewInstr("pc-0:SWAP r1 <= r2");
    {
      auto decode = ExprFuse::Eq(pc, ExprFuse::BvConst(0,8) );
      instr_3->SetDecode(decode);
      instr_3->AddUpdate(regs[1], regs[2] );
      instr_3->AddUpdate(regs[2], regs[1] );
    }

    return ila;
  }

#define REG_VAL(x) ExprFuse::Ite( ExprFuse::Eq((x), ExprFuse::BvConst(3,2)) , reg[3] , \
                   ExprFuse::Ite( ExprFuse::Eq((x), ExprFuse::BvConst(2,2)) , reg[2] , \
                   ExprFuse::Ite( ExprFuse::Eq((x), ExprFuse::BvConst(1,2)) , reg[1] , \
                   ExprFuse::Ite( ExprFuse::Eq((x), ExprFuse::BvConst(0,2)) , reg[0] , \
                    ))))

#define UPDATE_COND(ridx, val) ExprFuse::Ite( ExprFuse::Eq(rd, ExprFuse::BvConst((ridx),2)), \
                            val, regs[ridx])
#define UPDATE_R(val, inst) do { \
                        for(unsigned idx = 0; idx < reg_num_; idx ++)  \
                            (inst)->AddUpdate(regs[idx], UPDATE_COND(idx, (val)) ); \
                      } while(0);

  InstrLvlAbsPtr McmIlaGen::GetIlaOneInstPcDecode(const std::string & ila_name)
  {
    // parameters
    static const unsigned reg_num_ = 4;

    auto ila = InstrLvlAbsPtr::New(ila_name);

    // state variables.
    std::vector<ExprPtr> regs;
    for (auto i = 0; i < reg_num_; i++) {
      auto reg_name = "r" + std::to_string(i);
      auto reg = ila->NewBvState(reg_name, 8);
      regs.push_back(reg);
    }
    auto pc = ila->NewBvState("pc", 8);
    auto mem = ila->NewMemState("mem", 8, 8);

    // aux variables
    auto inst = ExprFuse::Load(mem, pc); // 8 bit wide
    auto opcode = ExprFuse::Extract(inst, 1,0); // 2 bit wide , // 7-6 rs , 5-4 rt, 3-2 rd, 1-0 op
    auto rs = ExprFuse::Extract(inst, 7, 6);
    auto rt = ExprFuse::Extract(inst, 5, 4);
    auto rd = ExprFuse::Extract(inst, 3, 2);
    auto rs_val = REG_VAL(rs);
    auto rt_val = REG_VAL(rt);
    auto rd_val = REG_VAL(rd);
    auto OP_ADDI = ExprFuse::BvConst(0,2);
    auto OP_ADDR = ExprFuse::BvConst(1,2);
    auto OP_LOAD = ExprFuse::BvConst(2,2);
    auto OP_STORE = ExprFuse::BvConst(3,2);


    // valid
    ila->SetValid(ExprFuse::BoolConst(true));

    // init : pc == 0 /\ r0 == 0
    ila->AddInit( ExprFuse::Eq(pc, ExprFuse::BvConst(0,8) ) );
    ila->AddInit( ExprFuse::Eq(regs[0], ExprFuse::BvConst(0,8) ) );

    // Instruction 1: ADDI
    auto instr_1 = ila->NewInstr("ADDI");
    {
      auto decode = ExprFuse::Eq(opcode, OP_ADDI );
      instr_1->SetDecode(decode);
      UPDATE_R( ExprFuse::Add(rs_val, ExprFuse::ZExt(rt, 8) )  , instr_1);
    }

    // Instruction 2: ADDR
    auto instr_2 = ila->NewInstr("ADDR"); 
    {
      auto decode = ExprFuse::Eq(opcode, OP_ADDR );
      instr_2->SetDecode(decode);
      UPDATE_R( ExprFuse::Add( rs_val, rt_val )  , instr_2);
    }

    // Instruction 3: LOAD rd = [rs]
    auto instr_3 = ila->NewInstr("LOAD");
    {
      auto decode = ExprFuse::Eq(opcode, OP_LOAD );
      instr_3->SetDecode(decode);
      UPDATE_R( ExprFuse::LOAD(mem, rs_val)  , instr_3);
    }

    // Instruction 4: STORE [rs], rt
    auto instr_4 = ila->NewInstr("STORE");
    {
      auto decode = ExprFuse::Eq(opcode, OP_STORE );
      instr_4->SetDecode(decode);
      instr_4->AddUpdate( mem, ExprFuse::STORE(mem, rs_val, rt_val ) );
    }

    return ila;
  }

  InstrLvlAbsPtr McmIlaGen::GetSys1Ila1()
  {
    return GetIlaOneInstPcDecode("Sys1Ila1");
  }
  InstrLvlAbsPtr McmIlaGen::GetSys1Ila2()
  {
    return GetIlaOneInstPcDecode("Sys1Ila2");
  }

  InstrLvlAbsPtr McmIlaGen::GetSys2Ila1()
  {
    return GetIlaOneInstPcDecode("Sys2Ila1");
  }
  InstrLvlAbsPtr McmIlaGen::GetSys2Ila2()
  {
    return GetIlaOneInstPcDecode("Sys2Ila2");
  }
  InstrLvlAbsPtr McmIlaGen::GetSys2Ila3()
  {
    return GetIlaOneInstPcDecode("Sys2Ila3");
  }

} // namespace ila

