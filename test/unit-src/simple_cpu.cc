/// \file
/// The ILA model of a simple processor.

#include "../unit-include/simple_cpu.h"
#include "ila++.h"
#include "util/log.h"

/*
 * INSTR: [7:0]
 * OP:    [7:6]
 * ARG0:  [5:4]
 * ARG1:  [3:2]
 * ARG2:  [1:0]
 *
 * OP: Load(0), Add(1), Store(2)
 */
#define REG_SIZE 8
#define REG_NUM 4
enum OP { LOAD = 0, ADD, STORE };

namespace ila {

std::shared_ptr<InstrLvlAbs> SimpleCpu(const std::string& name) {
  Ila m(name);

  // state
  auto ir = m.NewMemState("ir", REG_SIZE, REG_SIZE);
  auto mem = m.NewMemState("mem", REG_SIZE, REG_SIZE);
  auto pc = m.NewBvState("pc", REG_SIZE);
  std::vector<ExprRef> regs;
  for (auto i = 0; i != REG_NUM; i++) {
    auto name = "r" + std::to_string(i);
    auto ri = m.NewBvState(name, REG_SIZE);
    regs.push_back(ri);
  }

  // init
  m.AddInit(pc == 0);

  // helpers
  auto fetch = Load(ir, pc);
  auto op = fetch(7, 6);
  auto arg0 = fetch(5, 4);
  auto arg1 = fetch(3, 2);
  auto arg2 = fetch(1, 0);
  auto imm = fetch(3, 0);

  { // Instr: Load (arg0 is src reg; imm is the address)
    auto instr = m.NewInstr("Load");
    instr.SetDecode(op == OP::LOAD);

    // pc
    instr.SetUpdate(pc, pc + 1);
    // regs
    auto addr = ZExt(imm, REG_SIZE);
    auto val = Load(mem, addr);
    for (auto i = 0; i != REG_NUM; i++) {
      auto cond = (arg0 == i);
      auto next = Ite(cond, val, regs[i]);
      instr.SetUpdate(regs[i], next);
    }
  }

  { // Instr: Add (arg0 is dst reg; arg1 is input 1; arg2 is input 2)
    auto instr = m.NewInstr("Add");
    instr.SetDecode(op == OP::ADD);

    // pc
    instr.SetUpdate(pc, pc + 1);
    // regs
    auto in1 = regs[0];
    for (auto i = 1; i != REG_NUM; i++) {
      auto cond = (arg1 == i);
      in1 = Ite(cond, regs[i], in1);
    }
    auto in2 = regs[0];
    for (auto i = 1; i != REG_NUM; i++) {
      auto cond = (arg2 == i);
      in2 = Ite(cond, regs[i], in2);
    }
    auto val = in1 + in2;
    for (auto i = 0; i != REG_NUM; i++) {
      auto cond = (arg0 == i);
      auto next = Ite(cond, val, regs[i]);
      instr.SetUpdate(regs[i], next);
    }
  }

  { // Instr: Store (arg0 is src reg; imm is address)
    auto instr = m.NewInstr("Store");
    instr.SetDecode(op == OP::STORE);

    // pc
    instr.SetUpdate(pc, pc + 1);
    // mem
    auto addr = ZExt(imm, REG_SIZE);
    auto val = regs[0];
    for (auto i = 1; i != REG_NUM; i++) {
      auto cond = (arg0 == i);
      val = Ite(cond, regs[i], val);
    }
    auto store = Store(mem, addr, val);
    instr.SetUpdate(mem, store);
  }

  return m.get();
}

Ila SimpleCpuRef(const std::string& name) {
  auto m = SimpleCpu(name);
  return Ila(m);
}

int GenLoad(const int& dst, const int& addr) {
  ILA_ASSERT(dst < 4) << "2 bit reg";
  ILA_ASSERT(addr < 32) << "4 bit imm";
  int w = OP::LOAD << 6;
  w |= dst << 4;
  w |= addr;
  return w;
}

int GenAdd(const int& dst, const int& in1, const int& in2) {
  ILA_ASSERT(dst < 4) << "2 bit reg";
  ILA_ASSERT(in1 < 4) << "4 bit imm";
  ILA_ASSERT(in2 < 4) << "4 bit imm";
  int w = OP::ADD << 6;
  w |= dst << 4;
  w |= in1 << 2;
  w |= in2;
  return w;
}

int GenStore(const int& src, const int& addr) {
  ILA_ASSERT(src < 4) << "2 bit reg";
  ILA_ASSERT(addr < 32) << "4 bit imm";
  int w = OP::STORE << 6;
  w |= src << 4;
  w |= addr;
  return w;
}

} // namespace ila

