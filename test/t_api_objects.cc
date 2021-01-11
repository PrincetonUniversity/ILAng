/// \file
/// Unit test for c++ API, state objects

#include <ilang/ilang++.h>
#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

// ILA constants

enum struct actions : int { IDLE=0, ZERO, ACC, OUT };
enum struct pe_states : int { IDLE=0, WORKING, DONE };

constexpr unsigned char NUM_PES = 2;
constexpr unsigned char ROWS_PER_PE = 2;

constexpr unsigned char BITS_DIM = 8;  // bits
constexpr unsigned char BITS_DATA = 8; // bits
constexpr unsigned char BITS_STATE = 4; // bits

constexpr unsigned char MAT_COLS = 4;
constexpr unsigned char MAT_ROWS = NUM_PES * ROWS_PER_PE;
constexpr unsigned char VEC_SIZE = MAT_COLS;
constexpr unsigned char OUT_SIZE = MAT_ROWS;

// Helper utilities

ExprRef state_const(actions a) { return BvConst(static_cast<int>(a), BITS_STATE); }
ExprRef state_const(pe_states ps) { return BvConst(static_cast<int>(ps), BITS_STATE); }

// Ila generators

Ila mat_vec_mult_impl_objects() {
  Ila ila ("block_mat_vec_mult_with_objects");
  // computes matrix * vector product, and adds to accumulated totals

  // inputs
  auto action = ila.NewBvInput("action", BITS_STATE);

  // state set by previous instructions
  auto vec = ila.NewObjectState("vec", SortRef::VECTOR(VEC_SIZE, SortRef::BV(BITS_DATA)));
  auto mat = ila.NewObjectState("mat", 
    SortRef::VECTOR(MAT_ROWS, SortRef::VECTOR(MAT_COLS, SortRef::BV(BITS_DATA)))
  );

  // states
  auto todo = ila.NewBvState("todo", BITS_STATE);
  auto idle = ila.NewBoolState("idle");
  auto out = ila.NewObjectState("outq", SortRef::VECTOR(OUT_SIZE, SortRef::BV(BITS_DATA)));

  auto pes = ila.NewObjectState("pes", SortRef::VECTOR(NUM_PES, SortRef::STRUCT({
    {"state", SortRef::BV(BITS_STATE)},
    {"acc", SortRef::VECTOR(ROWS_PER_PE, SortRef::BV(BITS_DATA))},
  })));

  ila.AddInit(idle);
  for (int i = 0; i != NUM_PES; ++i) {
    ila.AddInit(pes.nth(i).member("state") == state_const(pe_states::IDLE));
    for (int j = 0; j != ROWS_PER_PE; ++j) {
      ila.AddInit(pes.nth(i).member("acc").nth(j) == BvConst(0, BITS_DATA));
    }
  }

  { // START instruction
    auto instr = ila.NewInstr("START");
    instr.SetDecode(idle & (action != state_const(actions::IDLE)));
    instr.SetUpdate(todo, action);
    instr.SetUpdate(idle, BoolConst(false));
  }

  for (int i = 0; i != NUM_PES; ++i) { // PE-specific instructions
    std::string prefix = "pe" + std::to_string(i) + "_";
    auto child = ila.NewChild("pe" + std::to_string(i));

    auto pe_state = pes.nth(i).member("state");
    auto pe_acc = pes.nth(i).member("acc");

    auto ith_turn = !idle & (pe_state == state_const(pe_states::IDLE));
    if (i > 0) {
      ith_turn = ith_turn 
                & (pes.nth(i-1).member("state") == state_const(pe_states::DONE));
    }

    { // pe_zero
      auto instr = child.NewInstr(prefix + "zero");
      instr.SetDecode(ith_turn & (todo == state_const(actions::ZERO)));
      for (int i = 0; i != ROWS_PER_PE; ++i) {
        instr.SetUpdate(pe_acc.nth(i), BvConst(0, BITS_DATA));
      }
      instr.SetUpdate(pe_state, state_const(pe_states::DONE));
    }

    { // pe_acc
      auto instr = child.NewInstr(prefix + "acc");
      instr.SetDecode(ith_turn & (todo == state_const(actions::ACC)));

      size_t offset = i * ROWS_PER_PE;
      for (int r = 0; r != ROWS_PER_PE; ++r) {
        auto total = pe_acc.nth(r);
        for (int c = 0; c != MAT_COLS; ++c) {
          total = total + mat.nth(offset + r).nth(c) * vec.nth(c);
        }
        instr.SetUpdate(pe_acc.nth(r), total);
      }
      
      instr.SetUpdate(pe_state, state_const(pe_states::DONE));
    }

    { // pe_out
      auto instr = child.NewInstr(prefix + "out");
      instr.SetDecode(ith_turn & (todo == state_const(actions::OUT)));

      size_t offset = i * ROWS_PER_PE;
      for (int r = 0; r != ROWS_PER_PE; ++r) {
        instr.SetUpdate(out.nth(offset + r), pe_acc.nth(r));
      }
      
      instr.SetUpdate(pe_state, state_const(pe_states::DONE));
    }

    { // pe_reset
      auto instr = child.NewInstr(prefix + "reset");
      auto should_reset = (pe_state == state_const(pe_states::DONE)) 
            & (pes.nth(NUM_PES - 1).member("state") == state_const(pe_states::DONE));
      if (i > 0) {
        should_reset = should_reset 
            & (pes.nth(i-1).member("state") == state_const(pe_states::IDLE));
      }
      instr.SetDecode(should_reset);
      instr.SetUpdate(pe_state, state_const(pe_states::IDLE));
      if (i == NUM_PES - 1) instr.SetUpdate(idle, BoolConst(true));
    }
  }

  return ila;
}

// Forward declarations

void add_pe(Ila parent, int id, int offset);
ExprRef mat_cell(Ila parent, int row, int col);

Ila mat_vec_mult_impl_plain() {
  Ila ila ("bmvm_plain");
  // Ila ila ("block_mat_vec_mult_plain");
  // computes matrix * vector product, and adds to accumulated totals

  // inputs
  auto action = ila.NewBvInput("action", BITS_STATE);
  
  // state set by previous instructions
  auto vec0 = ila.NewBvState("vec0", BITS_DATA);
  auto vec1 = ila.NewBvState("vec1", BITS_DATA);
  auto vec2 = ila.NewBvState("vec2", BITS_DATA);
  auto vec3 = ila.NewBvState("vec3", BITS_DATA);

  auto mat00 = ila.NewBvState("mat00", BITS_DATA);
  auto mat01 = ila.NewBvState("mat01", BITS_DATA);
  auto mat02 = ila.NewBvState("mat02", BITS_DATA);
  auto mat03 = ila.NewBvState("mat03", BITS_DATA);
  
  auto mat10 = ila.NewBvState("mat10", BITS_DATA);
  auto mat11 = ila.NewBvState("mat11", BITS_DATA);
  auto mat12 = ila.NewBvState("mat12", BITS_DATA);
  auto mat13 = ila.NewBvState("mat13", BITS_DATA);
  
  auto mat20 = ila.NewBvState("mat20", BITS_DATA);
  auto mat21 = ila.NewBvState("mat21", BITS_DATA);
  auto mat22 = ila.NewBvState("mat22", BITS_DATA);
  auto mat23 = ila.NewBvState("mat23", BITS_DATA);
  
  auto mat30 = ila.NewBvState("mat30", BITS_DATA);
  auto mat31 = ila.NewBvState("mat31", BITS_DATA);
  auto mat32 = ila.NewBvState("mat32", BITS_DATA);
  auto mat33 = ila.NewBvState("mat33", BITS_DATA);

  // states
  auto todo = ila.NewBvState("todo", BITS_STATE);
  auto idle = ila.NewBoolState("idle");

  auto out0 = ila.NewBvState("out0", BITS_DATA);
  auto out1 = ila.NewBvState("out1", BITS_DATA);
  auto out2 = ila.NewBvState("out2", BITS_DATA);
  auto out3 = ila.NewBvState("out3", BITS_DATA);

  auto pe0_state = ila.NewBvState("pe0_state", BITS_STATE);
  auto pe1_state = ila.NewBvState("pe1_state", BITS_STATE);

  auto pe0_acc0 = ila.NewBvState("pe0_acc0", BITS_DATA);
  auto pe0_acc1 = ila.NewBvState("pe0_acc1", BITS_DATA);
  auto pe1_acc0 = ila.NewBvState("pe1_acc0", BITS_DATA);
  auto pe1_acc1 = ila.NewBvState("pe1_acc1", BITS_DATA);

  ila.AddInit(idle);
  ila.AddInit(pe0_state == state_const(pe_states::IDLE));
  ila.AddInit(pe1_state == state_const(pe_states::IDLE));
  ila.AddInit(pe0_acc0 == BvConst(0, BITS_DATA));
  ila.AddInit(pe0_acc1 == BvConst(0, BITS_DATA));
  ila.AddInit(pe1_acc0 == BvConst(0, BITS_DATA));
  ila.AddInit(pe1_acc1 == BvConst(0, BITS_DATA));

  { // START instruction
    auto instr = ila.NewInstr("START");
    instr.SetDecode(idle & (action != state_const(actions::IDLE)));
    instr.SetUpdate(todo, action);
    instr.SetUpdate(idle, BoolConst(false));
  }

  for (int i = 0; i != NUM_PES; ++i) { // PE-specific instructions
    add_pe(ila, i, i*ROWS_PER_PE);
  }

  return ila;
}

// helper function -- adds a child ILA for a single PE

void add_pe(Ila parent, int id, int offset) {

  auto todo = parent.state("todo");
  auto idle = parent.state("idle");

  std::string prefix = "pe" + std::to_string(id) + "_";
  auto child = parent.NewChild("pe" + std::to_string(id));

  auto pe_state = parent.state(prefix + "state");
  // notice here that we hardcode the number of rows each pe has
  auto pe_acc0 = parent.state(prefix + "acc0");
  auto pe_acc1 = parent.state(prefix + "acc1");

  auto pe_turn = !idle & (pe_state == state_const(pe_states::IDLE));
  if (id > 0) {
    auto prev_pe_state = parent.state("pe" + std::to_string(id-1) + "_state");
    pe_turn = pe_turn & (prev_pe_state == state_const(pe_states::DONE));
  }

  { // pe_zero
    auto instr = child.NewInstr(prefix + "zero");
    instr.SetDecode(pe_turn & (todo == state_const(actions::ZERO)));
    instr.SetUpdate(pe_acc0, BvConst(0, BITS_DATA));
    instr.SetUpdate(pe_acc1, BvConst(0, BITS_DATA));
    instr.SetUpdate(pe_state, state_const(pe_states::DONE));
  }

  { // pe_acc
    auto instr = child.NewInstr(prefix + "acc");
    instr.SetDecode(pe_turn & (todo == state_const(actions::ACC)));

    auto pe_acc0_next = pe_acc0; 
    for (int i = 0; i != MAT_COLS; ++i) {
      pe_acc0_next = pe_acc0_next + (
        mat_cell(parent, offset, i) * parent.state("vec" + std::to_string(i))
      );
    }
    instr.SetUpdate(pe_acc0, pe_acc0_next);

    auto pe_acc1_next = pe_acc1;
    for (int i = 0; i != MAT_COLS; ++i) {
      pe_acc1_next = pe_acc1_next + (
        mat_cell(parent, offset + 1, i) * parent.state("vec" + std::to_string(i))
      );
    }
    instr.SetUpdate(pe_acc1, pe_acc1_next);
    
    instr.SetUpdate(pe_state, state_const(pe_states::DONE));
  }

  { // pe_out
    auto instr = child.NewInstr(prefix + "out");
    instr.SetDecode(pe_turn & (todo == state_const(actions::OUT)));
    instr.SetUpdate(parent.state("out" + std::to_string(offset)), pe_acc0);
    instr.SetUpdate(parent.state("out" + std::to_string(offset + 1)), pe_acc1);
    instr.SetUpdate(pe_state, state_const(pe_states::DONE));
  }

  { // pe_reset
    auto instr = child.NewInstr(prefix + "reset");
    auto should_reset = (pe_state == state_const(pe_states::DONE)) 
          & (parent.state("pe1_state") == state_const(pe_states::DONE));
    if (id > 0) {
      auto prev_pe_state = parent.state("pe" + std::to_string(id-1) + "_state");
      should_reset = should_reset & (prev_pe_state == state_const(pe_states::IDLE));
    }
    instr.SetDecode(should_reset);
    instr.SetUpdate(pe_state, state_const(pe_states::IDLE));
    if (id == NUM_PES - 1) instr.SetUpdate(idle, BoolConst(true));
  }

}

ExprRef mat_cell(Ila parent, int row, int col) {
  return parent.state("mat" + std::to_string(row) + std::to_string(col));
}

InstrRef pe_instr(Ila parent, int pe, const std::string& instr) {
  std::string peid = "pe" + std::to_string(pe);
  return parent.child(peid).instr(peid+"_"+instr);
}

std::vector<InstrRef> test_seq(Ila ila) {
  std::vector<InstrRef> v {};
  v.push_back(ila.instr("START"));
  for (int i = 0; i != NUM_PES; ++i) v.push_back(pe_instr(ila, i, "acc"));
  for (int i = 0; i != NUM_PES; ++i) v.push_back(pe_instr(ila, i, "reset"));
  v.push_back(ila.instr("START"));
  for (int i = 0; i != NUM_PES; ++i) v.push_back(pe_instr(ila, i, "out"));
  for (int i = 0; i != NUM_PES; ++i) v.push_back(pe_instr(ila, i, "reset"));
  return v;
}


// ------- TEST CODE --------

TEST(TestApiObjects, Unrolling) {
  auto ila1 = mat_vec_mult_impl_objects();
  auto ila2 = mat_vec_mult_impl_plain();

  z3::context ctx;
  z3::solver solver(ctx);
  z3::params ps(ctx);
  ps.set(":timeout", 100u);  // 100ms timeout
  solver.set(ps);

  auto unroller = IlaZ3Unroller(ctx);
  
  auto same_inputs = ila1.input("action") == ila2.input("action");
  unroller.AddGlobPred(same_inputs);

  auto same_state = (ila1.state("idle") & ila2.state("idle"));
  
  // state set by previous instructions
  for (int r = 0; r != MAT_ROWS; ++r) {
    for (int c = 0; c != MAT_COLS; ++c) {
      same_state = same_state & (
        ila1.object("mat").nth(r).nth(c) == mat_cell(ila2, r, c)
      );
    }
  }
  for (int i = 0; i != VEC_SIZE; ++i) {
    same_state = same_state & (
      ila1.object("vec").nth(i) == ila2.state("vec" + std::to_string(i))
    );
  }

  // state
  for (int pe = 0; pe != NUM_PES; ++pe) {
    same_state = same_state & (
      ila1.object("pes").nth(pe).member("state") == state_const(pe_states::IDLE)
      & ila2.state("pe" + std::to_string(pe) + "_state") == state_const(pe_states::IDLE)
    );
    for (int r = 0; r != ROWS_PER_PE; ++r) {
      same_state = same_state & (
        ila1.object("pes").nth(pe).member("acc").nth(r) ==
        ila2.state("pe" + std::to_string(pe) + "_acc" + std::to_string(r))
      );
    }
  }
  unroller.AddInitPred(same_state);

  // Populate solver with example matrix and vector
  // Also works if you comment out, but may timeout
  
  for (int r = 0; r != MAT_ROWS; ++r) {
    for (int c = 0; c != MAT_COLS; ++c) {
      unroller.AddInitPred(
        ila1.object("mat").nth(r).nth(c) == BvConst(r * MAT_ROWS + c + 1, BITS_DATA)
      );
    }
  }

  for (int i = 0; i != VEC_SIZE; ++i) {
    unroller.AddInitPred(ila1.object("vec").nth(i) == BvConst(i + 1, BITS_DATA));
  }

  // create smt problem

  solver.add(unroller.UnrollPathConn(test_seq(ila1)));
  solver.add(unroller.UnrollPathConn(test_seq(ila2)));

  // no goal
  EXPECT_EQ(solver.check(), z3::sat);

  // goal: both done
  int end = test_seq(ila1).size();
  auto both_done =     
    unroller.Equal(ila1.state("idle"), end, BoolConst(true), end)
    && unroller.Equal(ila2.state("idle"), end, BoolConst(true), end);
  solver.push();
  solver.add(!both_done);
  EXPECT_EQ(solver.check(), z3::unsat);
  solver.pop();

  // goal: same outputs
  auto same_outs = both_done;
  for (int r = 0; r != OUT_SIZE; ++r) {
    same_outs = same_outs && unroller.Equal(
        ila1.object("outq").nth(r), end,
        ila2.state("out" + std::to_string(r)), end
    );
  }
  solver.add(!same_outs);
  EXPECT_EQ(solver.check(), z3::unsat);
}

}