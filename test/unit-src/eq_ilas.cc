/// \file
/// Source for constructing equivalent ILAs.

#include "../unit-include/eq_ilas.h"
#include <ilang/ilang++.h>

namespace ilang {

// Flat ILA 1:
// - no child-ILA
// - every computation is done in an increaing order of the index/address
InstrLvlAbsPtr EqIlaGen::GetIlaFlat1(const std::string& name) {
  auto ila = InstrLvlAbs::New(name);

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
  ila->SetValid(asthub::BoolConst(true));

  // Instruction 1: (start == 1 && opcode = 1)
  //  * copy the value of %reg n-1 to %reg n (for all n = [1:15])
  auto instr_1 = ila->NewInstr();

  { // decode
    auto decode_start = asthub::Eq(start, asthub::BoolConst(true));
    auto decode_opcode = asthub::Eq(opcode, asthub::BvConst(1, 3));
    auto decode = asthub::And(decode_start, decode_opcode);
    instr_1->set_decode(decode);
  }

  { // updates
    instr_1->set_update(regs[0], regs[0]);
    for (auto i = 1; i < reg_num_; i++) {
      instr_1->set_update(regs[i], regs[i - 1]);
    }
  }

  // Instruction 2: (start == 1 && opcode == 2)
  //  * copy the value of %reg n-1 to %reg n (n = %counter).
  //  * if (%counter == 0) then copy %reg 15 to %reg 0

  auto instr_2 = ila->NewInstr();
  { // decode
    auto decode_start = asthub::Eq(start, asthub::BoolConst(true));
    auto decode_opcode = asthub::Eq(opcode, asthub::BvConst(2, 3));
    auto decode = asthub::And(decode_start, decode_opcode);
    instr_2->set_decode(decode);
  }

  { // updates
    for (auto i = 0; i < reg_num_; i++) {
      auto cnd_i = asthub::Eq(cnt, asthub::BvConst(i, 8));
      ExprPtr next_i = NULL;
      if (i == 0) {
        next_i = asthub::Ite(cnd_i, regs[reg_num_ - 1], regs[0]);
      } else {
        next_i = asthub::Ite(cnd_i, regs[i - 1], regs[i]);
      }
      instr_2->set_update(regs[i], next_i);
    }
  }

  // Instruction 3: (start == 1 && opcode == 3)
  //  - swap the value stored in %memory, pointed by %address, with %register n.
  //  - (n == %counter)
  auto instr_3 = ila->NewInstr();

  { // decode
    auto decode_start = asthub::Eq(start, asthub::BoolConst(true));
    auto decode_opcode = asthub::Eq(opcode, asthub::BvConst(3, 3));
    auto decode = asthub::And(decode_start, decode_opcode);
    instr_3->set_decode(decode);
  }

  { // updates
    auto mem_val = asthub::Load(mem, addr);
    for (auto i = 0; i < reg_num_; i++) {
      auto cnd_i = asthub::Eq(cnt, asthub::BvConst(i, 8));
      auto next_i = asthub::Ite(cnd_i, mem_val, regs[i]);
      instr_3->set_update(regs[i], next_i);
    }

    auto reg_val = regs[0];
    for (auto i = 1; i < reg_num_; i++) {
      auto cnd_i = asthub::Eq(cnt, asthub::BvConst(i, 8));
      reg_val = asthub::Ite(cnd_i, regs[i], reg_val);
    }
    auto mem_next = asthub::Store(mem, addr, reg_val);
    instr_3->set_update(mem, mem_next);
  }

  // Instruction 4: (start == 1 && opcode == 4)
  //  - sum up the value in %register [0-14] and store to %register 15.
  auto instr_4 = ila->NewInstr();

  { // decode
    auto decode_start = asthub::Eq(start, asthub::BoolConst(true));
    auto decode_opcode = asthub::Eq(opcode, asthub::BvConst(4, 3));
    auto decode = asthub::And(decode_start, decode_opcode);
    instr_4->set_decode(decode);
  }

  { // updates
    auto sum = regs[0];
    for (auto i = 1; i < reg_num_; i++) {
      sum = asthub::Add(sum, regs[i]);
    }
    instr_4->set_update(regs[reg_num_ - 1], sum);
  }

  return ila;
}

// Flat ILA 2:
// - no child-ILA
// - every computation is done in a decreasing order of the index/address
InstrLvlAbsPtr EqIlaGen::GetIlaFlat2(const std::string& name) {
  auto ila = InstrLvlAbs::New(name);

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
  ila->SetValid(asthub::BoolConst(true));

  // Instruction 1: (start == 1 && opcode = 1)
  //  * copy the value of %reg n-1 to %reg n (for all n = [1:15])
  auto instr_1 = ila->NewInstr();

  { // decode
    auto decode_start = asthub::Eq(start, asthub::BoolConst(true));
    auto decode_opcode = asthub::Eq(opcode, asthub::BvConst(1, 3));
    auto decode = asthub::And(decode_start, decode_opcode);
    instr_1->set_decode(decode);
  }

  { // updates
    instr_1->set_update(regs[0], regs[0]);
    for (auto i = 1; i < reg_num_; i++) {
      instr_1->set_update(regs[i], regs[i - 1]);
    }
  }

  // Instruction 2: (start == 1 && opcode == 2)
  //  * copy the value of %reg n-1 to %reg n (n = %counter).
  //  * if (%counter == 0) then copy %reg 15 to %reg 0
  auto instr_2 = ila->NewInstr();

  { // decode
    auto decode_start = asthub::Eq(start, asthub::BoolConst(true));
    auto decode_opcode = asthub::Eq(opcode, asthub::BvConst(2, 3));
    auto decode = asthub::And(decode_start, decode_opcode);
    instr_2->set_decode(decode);
  }

  { // updates
    for (auto i = 0; i < reg_num_; i++) {
      auto cnd_i = asthub::Eq(cnt, asthub::BvConst(i, 8));
      ExprPtr next_i = NULL;
      if (i == 0) {
        next_i = asthub::Ite(cnd_i, regs[reg_num_ - 1], regs[0]);
      } else {
        next_i = asthub::Ite(cnd_i, regs[i - 1], regs[i]);
      }
      instr_2->set_update(regs[i], next_i);
    }
  }

  // Instruction 3: (start == 1 && opcode == 3)
  //  - swap the value stored in %memory, pointed by %address, with %register n.
  //  - (n == %counter)
  auto instr_3 = ila->NewInstr();

  { // decode
    auto decode_start = asthub::Eq(start, asthub::BoolConst(true));
    auto decode_opcode = asthub::Eq(opcode, asthub::BvConst(3, 3));
    auto decode = asthub::And(decode_start, decode_opcode);
    instr_3->set_decode(decode);
  }

  { // updates
    auto mem_val = asthub::Load(mem, addr);
    for (auto i = 0; i < reg_num_; i++) {
      auto cnd_i = asthub::Eq(cnt, asthub::BvConst(i, 8));
      auto next_i = asthub::Ite(cnd_i, mem_val, regs[i]);
      instr_3->set_update(regs[i], next_i);
    }

    auto reg_val = regs[reg_num_ - 1];
    for (auto i = reg_num_ - 2; i >= 0; i--) {
      auto cnd_i = asthub::Eq(cnt, asthub::BvConst(i, 8));
      reg_val = asthub::Ite(cnd_i, regs[i], reg_val);
    }
    auto mem_next = asthub::Store(mem, addr, reg_val);
    instr_3->set_update(mem, mem_next);
  }

  // Instruction 4: (start == 1 && opcode == 4)
  //  - sum up the value in %register [0-14] and store to %register 15.
  auto instr_4 = ila->NewInstr();

  { // decode
    auto decode_start = asthub::Eq(start, asthub::BoolConst(true));
    auto decode_opcode = asthub::Eq(opcode, asthub::BvConst(4, 3));
    auto decode = asthub::And(decode_start, decode_opcode);
    instr_4->set_decode(decode);
  }

  { // updates
    auto sum = regs[reg_num_ - 2];
    for (auto i = reg_num_ - 3; i >= 0; i--) {
      sum = asthub::Add(sum, regs[i]);
    }
    instr_4->set_update(regs[reg_num_ - 1], sum);
  }

  return ila;
}

// Hier ILA 1:
// - with child-ILA
// - every computation is done in an increaing order of the index/address
InstrLvlAbsPtr EqIlaGen::GetIlaHier1(const std::string& name) {
  auto m = Ila(name);

  // input variables.
  auto start = m.NewBoolInput("start");
  auto opcode = m.NewBvInput("opcode", 3);

  // state variables.
  std::vector<ExprRef> regs;
  for (auto i = 0; i < reg_num(); i++) {
    auto reg_name = "reg_" + std::to_string(i);
    auto reg = m.NewBvState(reg_name, reg_wid());
    regs.push_back(reg);
  }

  auto addr = m.NewBvState("address", reg_wid());
  auto cnt = m.NewBvState("counter", reg_wid());
  auto mem = m.NewMemState("memory", reg_wid(), reg_wid());

  // valid
  m.SetValid(BoolConst(true));

  // Instruction 1: (start == 1 && opcode = 1)
  //  * copy the value of %reg n-1 to %reg n (for all n = [1:15])
  auto instr_1 = m.NewInstr("instr1");
  auto child_1_valid = m.NewBvState("c1vld", reg_wid());
  auto child_1 = m.NewChild("child1");
  instr_1.SetProgram(child_1);

  { // decode
    auto decode_start = (start == true);
    auto decode_opcode = (opcode == k_opcode::op1);
    auto decode_bound = ((child_1_valid >= 0) & (child_1_valid < reg_num()));
    auto decode = (decode_start & decode_opcode & decode_bound);
    instr_1.SetDecode(decode);
  }

  { // updates
    instr_1.SetUpdate(child_1_valid, child_1_valid + 1);
  }

  { // Child ILA 1
    auto& c = child_1;

    // child-states
    auto& ucnt = child_1_valid;
    auto uptr = c.NewBvState("uptr", reg_wid());

    // XXX invariant:
    // 1. uptr \in [0, reg_num)
    // 2. ucnt \in [0, reg_wid]

    // child-instrs
    { // instr_0
      auto instr_0 = c.NewInstr("instr_0");
      // decode
      instr_0.SetDecode((uptr == 0) & (ucnt != 0) & (!start)); // XXX start
      // updates
      instr_0.SetUpdate(uptr, BvConst(reg_num() - 1, reg_wid()));
      instr_0.SetUpdate(ucnt, ucnt - 1);
    }
    for (auto i = 1; i < reg_num(); i++) {
      auto instr_i = c.NewInstr("instr_" + std::to_string(i));
      // decode
      instr_i.SetDecode((uptr == i) & (!start)); // XXX start
      // updates
      instr_i.SetUpdate(regs[i], regs[i - 1]);
      instr_i.SetUpdate(uptr, uptr - 1);
    }
  }

// Instruction 2: (start == 1 && opcode == 2)
//  * copy the value of %reg n-1 to %reg n (n = %counter).
//  * if (%counter == 0) then copy %reg 15 to %reg 0
#if 0
  auto instr_2 = m.NewInstr("instr2");
  auto child_2_valid = m.NewBvState("c2vld", reg_wid());
  auto child_2 = m.NewChild("child2");
  instr_2.SetProgram(child_2);

  { // decode
    auto decode_start = start;
    auto decode_opcode = (opcode == 2);
    auto decode = (decode_start & decode_opcode);
    instr_2.SetDecode(decode);
  }

  { // updates
    for (auto i = 0; i < reg_num(); i++) {
      auto cnd_i = asthub::Eq(cnt, asthub::BvConst(i, 8));
      ExprPtr next_i = NULL;
      if (i == 0) {
        next_i = asthub::Ite(cnd_i, regs[reg_num_ - 1], regs[0]);
      } else {
        next_i = asthub::Ite(cnd_i, regs[i - 1], regs[i]);
      }
      instr_2->set_update(regs[i], next_i);
    }
  }
#endif

  return m.get();
}

// Hier ILA 2:
// - with child-ILA
// - every computation is done in an decreasing order of the index/address
InstrLvlAbsPtr EqIlaGen::GetIlaHier2(const std::string& name) {
  auto m = Ila(name);

  // input variables.
  auto start = m.NewBoolInput("start");
  auto opcode = m.NewBvInput("opcode", 3);

  // state variables.
  std::vector<ExprRef> regs;
  for (auto i = 0; i < reg_num(); i++) {
    auto reg_name = "reg_" + std::to_string(i);
    auto reg = m.NewBvState(reg_name, reg_wid());
    regs.push_back(reg);
  }

  auto addr = m.NewBvState("address", reg_wid());
  auto cnt = m.NewBvState("counter", reg_wid());
  auto mem = m.NewMemState("memory", reg_wid(), reg_wid());

  auto pipes = std::vector<decltype(m.NewBvState("", reg_wid()))>();
  for (auto i = 0; i != pipe_num(); i++) {
    auto pipe = m.NewBvState("pipe_" + std::to_string(i), reg_wid());
    pipes.push_back(pipe);
  }

  // valid
  auto pipe_empty = (pipes.back() == k_opcode::op0);
  m.SetValid(pipe_empty);

  auto child_0 = m.NewChild("child0");
  {
    // TODO
  }

  // Instruction 1: (start == 1 && opcode = 1)
  //  * copy the value of %reg n-1 to %reg n (for all n = [1:15])

  return m.get();
}

} // namespace ilang
