/// \file
/// Functions to construct equivalent ILAs (wrapped in a class).

#include "ila/instr_lvl_abs.h"

namespace ila {

class TwoEqIla {
public:
  InstrLvlAbsPtr GetIlaFlat1();
  InstrLvlAbsPtr GetIlaFlat2();
  InstrLvlAbsPtr GetIlaHier1();
  InstrLvlAbsPtr GetIlaHier2();

private:
}; // TwoEqIla

// ILA behavior:
//
// Input variables:
//  - start
//  - opcode
//
// Architecture states:
//  - register [0-15] (at least 8 bits)
//  - address
//  - counter
//  - memory (data width is 8)
//
// Instruction 1: (start == 1 && opcode = 1)
//  * copy the value of %reg n-1 to %reg n (for all n = [1:15])
//
// Instruction 2: (start == 1 && opcode == 2)
//  * copy the value of %reg n-1 to %reg n (n = %counter).
//  * if (%counter == 0) then copy %reg 15 to %reg 0
//
// Instruction 3: (start == 1 && opcode == 3)
//  * copy the value stored in %memory, pointed by %address, to %register n.
//  * (n == %counter)
//
// Instruction 4: (start == 1 && opcode == 4)
//  * sum up the value in %register [0-15] and store to %memory pointed by
//    %address.

// ILA flat 1:
// - no child-ILA
// - every computation is done in the increaing order of the index/address
InstrLvlAbsPtr TwoEqIla::GetIlaFlat1() {
  auto ila = InstrLvlAbs::New("Flat_1");

  // input variables.
  auto start = ila->NewBoolInput("start");
  auto opcode = ila->NewBvInput("opcode", 3);

  // state variables.
  std::vector<ExprPtr> regs;
  for (auto i = 0; i < 15; i++) {
    auto reg_name = "reg_" + std::to_string(i);
    auto reg = ila->NewBvState(reg_name, 8);
  }

  auto addr = ila->NewBvState("address", 8);
  auto cnt = ila->NewBvState("counter", 8);
  auto mem = ila->NewMemState("memory", 8, 8);

  // instructions.
  auto instr_1 = ila->NewInstr();
  auto instr_2 = ila->NewInstr();
  auto instr_3 = ila->NewInstr();
  auto instr_4 = ila->NewInstr();

  // Instruction 1: (start == 1 && opcode = 1)
  //  * copy the value of %reg n-1 to %reg n (for all n = [1:15])

  { // decode
    auto decode_start = ExprFuse::Eq(start, ExprFuse::BoolConst(true));
    auto decode_opcode = ExprFuse::Eq(opcode, ExprFuse::BvConst(1, 8));
    auto decode = ExprFuse::And(decode_start, decode_opcode);
    instr_1->SetDecode(decode);
  }

  { // updates
    instr_1->AddUpdate(regs[0], regs[0]);
    for (auto i = 1; i < 16; i++) {
      instr_1->AddUpdate(regs[i], regs[i - 1]);
    }
  }

  // Instruction 2: (start == 1 && opcode == 2)
  //  * copy the value of %reg n-1 to %reg n (n = %counter).
  //  * if (%counter == 0) then copy %reg 15 to %reg 0

  { // decode
    auto decode_start = ExprFuse::Eq(start, ExprFuse::BoolConst(true));
    auto decode_opcode = ExprFuse::Eq(opcode, ExprFuse::BvConst(2, 8));
    auto decode = ExprFuse::And(decode_start, decode_opcode);
    instr_2->SetDecode(decode);
  }

  // TODO updates

  // Instruction 3: (start == 1 && opcode == 3)
  //  * copy the value stored in %memory, pointed by %address, to %register n.
  //  * (n == %counter)

  { // decode
    auto decode_start = ExprFuse::Eq(start, ExprFuse::BoolConst(true));
    auto decode_opcode = ExprFuse::Eq(opcode, ExprFuse::BvConst(3, 8));
    auto decode = ExprFuse::And(decode_start, decode_opcode);
    instr_3->SetDecode(decode);
  }

  // TODO updates

  // Instruction 4: (start == 1 && opcode == 4)
  //  * sum up the value in %register [0-15] and store to %memory pointed by
  //    %address.

  { // decode
    auto decode_start = ExprFuse::Eq(start, ExprFuse::BoolConst(true));
    auto decode_opcode = ExprFuse::Eq(opcode, ExprFuse::BvConst(4, 8));
    auto decode = ExprFuse::And(decode_start, decode_opcode);
    instr_4->SetDecode(decode);
  }

  // TODO updates

  return ila;
}

} // namespace ila

