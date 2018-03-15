// main function for c++ api tutorial

#include "ila++.h"
#include "z3++.h"

using namespace ila;

void defineState() {
  std::cout << "----------defineState example----------\n";
  Ila m("abs");

  auto bool_var = m.NewBoolState("bool_var");
  auto bv_var = m.NewBvState("bv_var", 8);
  auto mem_var = m.NewMemState("mem_var", 8, 8);
  for (unsigned i = 0; i != m.state_num(); i++) {
    std::cout << "state " << i << ": " << m.state(i) << "\n";
  }

  auto bool_in = m.NewBoolInput("bool_in");
  auto bv_in = m.NewBvInput("bv_in", 8);
  for (unsigned i = 0; i != m.input_num(); i++) {
    std::cout << "input " << i << ": " << m.input(i) << "\n";
  }
}

void defineInstr() {
  std::cout << "----------defineInstr example----------\n";
  Ila m("abs");

  // define states
  auto zero_start = m.NewBoolInput("zero_start");
  std::vector<ExprRef> regs;
  for (auto i = 0; i != 4; i++) {
    regs.push_back(m.NewBvState("bv_" + std::to_string(i), 8));
  }

  // define the instruction by setting the decode function and state updates
  auto instr = m.NewInstr("ZeroRegs");
  instr.SetDecode(zero_start == true);
  for (auto i = 0; i != 4; i++) {
    instr.SetUpdate(regs[i], BvConst(0, 8));
  }

  std::cout << "instr: " << instr << "\n";
}

void defineChild() {
  std::cout << "----------defineChild example----------\n";
  Ila m("parent");

  // define parent states
  for (auto i = 0; i != 4; i++) {
    m.NewBvState("bv_" + std::to_string(i), 8);
  }
  // define parent inputs
  m.NewBoolInput("bool_input");

  // define child ILA
  auto child = m.NewChild("child");
  child.NewBoolState("child_state");

  for (size_t i = 0; i != child.state_num(); i++) {
    std::cout << "state " << i << ": " << child.state(i) << "\n";
  }
  for (size_t i = 0; i != child.input_num(); i++) {
    std::cout << "input " << i << ": " << child.input(i) << "\n";
  }
}

/* Consider a toy CPU.
 * - register bit-width: 8
 * - number of general purpose register: 4
 * - bit-fields of the instruction (8 bits)
 *   INSTR: [7:0]
 *   OP:    [7:6]
 *   ARG0:  [5:4]
 *   ARG1:  [3:2]
 *   ARG2:  [1:0]
 * - opcode: Load(0), Add(1), Store(2)
 */
#define REG_SIZE 8
#define REG_NUM 4

enum OP { LOAD = 0, ADD, STORE };

Ila simple_cpu(const std::string& cpu_name) {
  Ila m(cpu_name);

  // define memory states
  auto ir = m.NewMemState("ir", REG_SIZE, REG_SIZE);
  auto mem = m.NewMemState("mem", REG_SIZE, REG_SIZE);
  // define bit-vector states
  auto pc = m.NewBvState("pc", REG_SIZE);
  std::vector<ExprRef> regs;
  for (auto i = 0; i != REG_NUM; i++) {
    auto name = "r" + std::to_string(i);
    auto ri = m.NewBvState(name, REG_SIZE);
    regs.push_back(ri);
  }

  // define initial condition
  m.AddInit(pc == 0);

  // define fetch function of the ILA.
  auto fetch = Load(ir, pc);
  m.SetFetch(fetch);

  // can also have helpers
  auto op = fetch(7, 6);
  auto arg0 = fetch(5, 4);
  auto arg1 = fetch(3, 2);
  auto arg2 = fetch(1, 0);
  auto imm = fetch(3, 0);

  { // Instr: Load (arg0 is src reg; imm is the address)
    auto instr = m.NewInstr("Load");
    instr.SetDecode(op == OP::LOAD);

    // [pc] next state function
    instr.SetUpdate(pc, pc + 1);
    // [regs] next state function
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

    // [pc] next state function
    instr.SetUpdate(pc, pc + 1);
    // [regs] next state function
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

    // [pc] next state function
    instr.SetUpdate(pc, pc + 1);
    // [mem] next state function
    auto addr = ZExt(imm, REG_SIZE);
    auto val = regs[0];
    for (auto i = 1; i != REG_NUM; i++) {
      auto cond = (arg0 == i);
      val = Ite(cond, regs[i], val);
    }
    auto store = Store(mem, addr, val);
    instr.SetUpdate(mem, store);
  }

  return m;
}

int GenLoad(const int& dst, const int& addr) {
  int w = OP::LOAD << 6;
  w |= dst << 4;
  w |= addr;
  return w;
}

int GenAdd(const int& dst, const int& in1, const int& in2) {
  int w = OP::ADD << 6;
  w |= dst << 4;
  w |= in1 << 2;
  w |= in2;
  return w;
}

int GenStore(const int& src, const int& addr) {
  int w = OP::STORE << 6;
  w |= src << 4;
  w |= addr;
  return w;
}

void boundedUnroller() {
  std::cout << "----------boundedUnroller example----------\n";
  auto m = simple_cpu("cpu");

  z3::context ctx;
  IlaZ3Unroller un = (ctx);

  // add ILA initial condition to the unroller
  for (size_t i = 0; i != m.init_num(); i++) {
    un.AddInitPred(m.init(i));
  }
  // initialize program to the memory
  auto ir = m.state("ir");
  un.AddInitPred(ir.Load(0) == GenLoad(0, 0));   // reg0 = Load mem[0]
  un.AddInitPred(ir.Load(1) == GenLoad(1, 1));   // reg1 = Load mem[1]
  un.AddInitPred(ir.Load(2) == GenAdd(2, 0, 1)); // reg3 = reg0 + reg1
  un.AddInitPred(ir.Load(3) == GenStore(2, 2));  // Store reg3 to mem[2]
  // initialize memory
  auto mem = m.state("mem");
  un.AddInitPred((mem.Load(0) + mem.Load(1)) == 5);

  // unroll 4 steps
  auto trans_rel = un.UnrollMonoConn(m, 4);

  // get the current state at step 4 (end of 3 and begging of 4)
  auto prop = (mem.Load(2) == 5);
  auto prop_z3 = un.CurrState(prop, 4);

  z3::solver s(ctx);
  s.add(trans_rel);
  s.add(!prop_z3);
  std::cout << s.check() << "\n";
}

int main() {
  try {
    defineState();
    defineInstr();
    defineChild();
    simple_cpu("simple_cpu");
    boundedUnroller();
  } catch (...) {
    std::cout << "unexpected error.\n";
  }
  std::cout << "complete example!\n";
  return 0;
}

