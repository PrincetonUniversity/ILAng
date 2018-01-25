/// \file
/// Source for constructing equivalent ILAs.

#include "../unit-include/eq_ilas.h"

namespace ila {

// Flat ILA 1:
// - no child-ILA
// - every computation is done in an increaing order of the index/address
InstrLvlAbsPtr EqIlaGen::GetIlaFlat1() {
  auto ila = InstrLvlAbs::New("Flat_1");

  // input variables.
  auto start = ila->NewBoolInput("start");
  auto opcode = ila->NewBvInput("opcode", 3);

  // state variables.
  std::vector<ExprPtr> regs;
  for (auto i = 0; i < reg_num_; i++) {
    auto reg_name = "reg_" + std::to_string(i);
    auto reg = ila->NewBvState(reg_name, 8);
    regs.push_back(reg);
  }

  auto addr = ila->NewBvState("address", 8);
  auto cnt = ila->NewBvState("counter", 8);
  auto mem = ila->NewMemState("memory", 8, 8);

  // valid
  ila->SetValid(ExprFuse::BoolConst(true));

  // Instruction 1: (start == 1 && opcode = 1)
  //  * copy the value of %reg n-1 to %reg n (for all n = [1:15])
  auto instr_1 = ila->NewInstr();

  { // decode
    auto decode_start = ExprFuse::Eq(start, ExprFuse::BoolConst(true));
    auto decode_opcode = ExprFuse::Eq(opcode, ExprFuse::BvConst(1, 3));
    auto decode = ExprFuse::And(decode_start, decode_opcode);
    instr_1->SetDecode(decode);
  }

  { // updates
    instr_1->AddUpdate(regs[0], regs[0]);
    for (auto i = 1; i < reg_num_; i++) {
      instr_1->AddUpdate(regs[i], regs[i - 1]);
    }
  }

  // Instruction 2: (start == 1 && opcode == 2)
  //  * copy the value of %reg n-1 to %reg n (n = %counter).
  //  * if (%counter == 0) then copy %reg 15 to %reg 0

  auto instr_2 = ila->NewInstr();
  { // decode
    auto decode_start = ExprFuse::Eq(start, ExprFuse::BoolConst(true));
    auto decode_opcode = ExprFuse::Eq(opcode, ExprFuse::BvConst(2, 3));
    auto decode = ExprFuse::And(decode_start, decode_opcode);
    instr_2->SetDecode(decode);
  }

  { // updates
    for (auto i = 0; i < reg_num_; i++) {
      auto cnd_i = ExprFuse::Eq(cnt, ExprFuse::BvConst(i, 8));
      ExprPtr next_i = NULL;
      if (i == 0) {
        next_i = ExprFuse::Ite(cnd_i, regs[reg_num_ - 1], regs[0]);
      } else {
        next_i = ExprFuse::Ite(cnd_i, regs[i - 1], regs[i]);
      }
      instr_2->AddUpdate(regs[i], next_i);
    }
  }

  // Instruction 3: (start == 1 && opcode == 3)
  //  - swap the value stored in %memory, pointed by %address, with %register n.
  //  - (n == %counter)
  auto instr_3 = ila->NewInstr();

  { // decode
    auto decode_start = ExprFuse::Eq(start, ExprFuse::BoolConst(true));
    auto decode_opcode = ExprFuse::Eq(opcode, ExprFuse::BvConst(3, 3));
    auto decode = ExprFuse::And(decode_start, decode_opcode);
    instr_3->SetDecode(decode);
  }

  { // updates
    auto mem_val = ExprFuse::Load(mem, addr);
    for (auto i = 0; i < reg_num_; i++) {
      auto cnd_i = ExprFuse::Eq(cnt, ExprFuse::BvConst(i, 8));
      auto next_i = ExprFuse::Ite(cnd_i, mem_val, regs[i]);
      instr_3->AddUpdate(regs[i], next_i);
    }

    auto reg_val = regs[0];
    for (auto i = 1; i < reg_num_; i++) {
      auto cnd_i = ExprFuse::Eq(cnt, ExprFuse::BvConst(i, 8));
      reg_val = ExprFuse::Ite(cnd_i, regs[i], reg_val);
    }
    auto mem_next = ExprFuse::Store(mem, addr, reg_val);
    instr_3->AddUpdate(mem, mem_next);
  }

  // Instruction 4: (start == 1 && opcode == 4)
  //  - sum up the value in %register [0-14] and store to %register 15.
  auto instr_4 = ila->NewInstr();

  { // decode
    auto decode_start = ExprFuse::Eq(start, ExprFuse::BoolConst(true));
    auto decode_opcode = ExprFuse::Eq(opcode, ExprFuse::BvConst(4, 3));
    auto decode = ExprFuse::And(decode_start, decode_opcode);
    instr_4->SetDecode(decode);
  }

  { // updates
    auto sum = regs[0];
    for (auto i = 1; i < reg_num_; i++) {
      sum = ExprFuse::Add(sum, regs[i]);
    }
    instr_4->AddUpdate(regs[reg_num_ - 1], sum);
  }

  return ila;
}

// Flat ILA 2:
// - no child-ILA
// - every computation is done in a decreasing order of the index/address
InstrLvlAbsPtr EqIlaGen::GetIlaFlat2() {
  auto ila = InstrLvlAbs::New("Flat_2");

  // input variables.
  auto start = ila->NewBoolInput("start");
  auto opcode = ila->NewBvInput("opcode", 3);

  // state variables.
  std::vector<ExprPtr> regs;
  for (auto i = 0; i < reg_num_; i++) {
    auto reg_name = "reg_" + std::to_string(i);
    auto reg = ila->NewBvState(reg_name, 8);
    regs.push_back(reg);
  }

  auto addr = ila->NewBvState("address", 8);
  auto cnt = ila->NewBvState("counter", 8);
  auto mem = ila->NewMemState("memory", 8, 8);

  // valid
  ila->SetValid(ExprFuse::BoolConst(true));

  // Instruction 1: (start == 1 && opcode = 1)
  //  * copy the value of %reg n-1 to %reg n (for all n = [1:15])
  auto instr_1 = ila->NewInstr();

  { // decode
    auto decode_start = ExprFuse::Eq(start, ExprFuse::BoolConst(true));
    auto decode_opcode = ExprFuse::Eq(opcode, ExprFuse::BvConst(1, 3));
    auto decode = ExprFuse::And(decode_start, decode_opcode);
    instr_1->SetDecode(decode);
  }

  { // updates
    instr_1->AddUpdate(regs[0], regs[0]);
    for (auto i = 1; i < reg_num_; i++) {
      instr_1->AddUpdate(regs[i], regs[i - 1]);
    }
  }

  // Instruction 2: (start == 1 && opcode == 2)
  //  * copy the value of %reg n-1 to %reg n (n = %counter).
  //  * if (%counter == 0) then copy %reg 15 to %reg 0
  auto instr_2 = ila->NewInstr();

  { // decode
    auto decode_start = ExprFuse::Eq(start, ExprFuse::BoolConst(true));
    auto decode_opcode = ExprFuse::Eq(opcode, ExprFuse::BvConst(2, 3));
    auto decode = ExprFuse::And(decode_start, decode_opcode);
    instr_2->SetDecode(decode);
  }

  { // updates
    for (auto i = 0; i < reg_num_; i++) {
      auto cnd_i = ExprFuse::Eq(cnt, ExprFuse::BvConst(i, 8));
      ExprPtr next_i = NULL;
      if (i == 0) {
        next_i = ExprFuse::Ite(cnd_i, regs[reg_num_ - 1], regs[0]);
      } else {
        next_i = ExprFuse::Ite(cnd_i, regs[i - 1], regs[i]);
      }
      instr_2->AddUpdate(regs[i], next_i);
    }
  }

  // Instruction 3: (start == 1 && opcode == 3)
  //  - swap the value stored in %memory, pointed by %address, with %register n.
  //  - (n == %counter)
  auto instr_3 = ila->NewInstr();

  { // decode
    auto decode_start = ExprFuse::Eq(start, ExprFuse::BoolConst(true));
    auto decode_opcode = ExprFuse::Eq(opcode, ExprFuse::BvConst(3, 3));
    auto decode = ExprFuse::And(decode_start, decode_opcode);
    instr_3->SetDecode(decode);
  }

  { // updates
    auto mem_val = ExprFuse::Load(mem, addr);
    for (auto i = 0; i < reg_num_; i++) {
      auto cnd_i = ExprFuse::Eq(cnt, ExprFuse::BvConst(i, 8));
      auto next_i = ExprFuse::Ite(cnd_i, mem_val, regs[i]);
      instr_3->AddUpdate(regs[i], next_i);
    }

    auto reg_val = regs[reg_num_ - 1];
    for (auto i = reg_num_ - 2; i >= 0; i--) {
      auto cnd_i = ExprFuse::Eq(cnt, ExprFuse::BvConst(i, 8));
      reg_val = ExprFuse::Ite(cnd_i, regs[i], reg_val);
    }
    auto mem_next = ExprFuse::Store(mem, addr, reg_val);
    instr_3->AddUpdate(mem, mem_next);
  }

  // Instruction 4: (start == 1 && opcode == 4)
  //  - sum up the value in %register [0-14] and store to %register 15.
  auto instr_4 = ila->NewInstr();

  { // decode
    auto decode_start = ExprFuse::Eq(start, ExprFuse::BoolConst(true));
    auto decode_opcode = ExprFuse::Eq(opcode, ExprFuse::BvConst(4, 3));
    auto decode = ExprFuse::And(decode_start, decode_opcode);
    instr_4->SetDecode(decode);
  }

  { // updates
    auto sum = regs[reg_num_ - 2];
    for (auto i = reg_num_ - 3; i >= 0; i--) {
      sum = ExprFuse::Add(sum, regs[i]);
    }
    instr_4->AddUpdate(regs[reg_num_ - 1], sum);
  }

  return ila;
}

} // namespace ila

