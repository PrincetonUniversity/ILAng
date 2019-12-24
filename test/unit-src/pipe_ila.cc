
#include "../unit-include/pipe_ila.h"
#include <ilang/ilang++.h>
#include <ilang/util/log.h>

namespace ilang {

#define SET_UPDATE(INST, RD, RES)                                              \
  do {                                                                         \
    (INST).SetUpdate(r0, Ite((RD) == 0, (RES), r0));                           \
    (INST).SetUpdate(r1, Ite((RD) == 1, (RES), r1));                           \
    (INST).SetUpdate(r2, Ite((RD) == 2, (RES), r2));                           \
    (INST).SetUpdate(r3, Ite((RD) == 3, (RES), r3));                           \
  } while (0);

Ila SimplePipe::BuildModel() {
  // build the ila
  auto pipe_ila = Ila("simplePipe");
  pipe_ila.SetValid(BoolConst(true));
  
  auto inst = pipe_ila.NewBvInput("inst", 8);
  auto r0 = pipe_ila.NewBvState("r0", 8);
  auto r1 = pipe_ila.NewBvState("r1", 8);
  auto r2 = pipe_ila.NewBvState("r2", 8);
  auto r3 = pipe_ila.NewBvState("r3", 8);

  auto op = inst(7, 6);
  auto rs1 = inst(5, 4);
  auto rs2 = inst(3, 2);
  auto rd = inst(1, 0);

  auto rs1_val = Ite(rs1 == 0, r0, Ite(rs1 == 1, r1, Ite(rs1 == 2, r2, r3)));

  auto rs2_val = Ite(rs2 == 0, r0, Ite(rs2 == 1, r1, Ite(rs2 == 2, r2, r3)));
  
  auto NOP = pipe_ila.NewInstr("NOP");
  {
    NOP.SetDecode(op == BvConst(0, 2));
    NOP.SetUpdate(r0, r0);
    NOP.SetUpdate(r1, r1);
    NOP.SetUpdate(r2, r2);
    NOP.SetUpdate(r3, r3);
  }

  auto ADD = pipe_ila.NewInstr("ADD");
  {
    ADD.SetDecode(op == BvConst(1, 2));
    auto res = rs1_val + rs2_val;
    SET_UPDATE(ADD, rd, res);
  }

  auto SUB = pipe_ila.NewInstr("SUB");
  {
    SUB.SetDecode(op == BvConst(2, 2));
    auto res = rs1_val - rs2_val;
    SET_UPDATE(SUB, rd, res);
  }

  auto AND = pipe_ila.NewInstr("AND");
  {
    AND.SetDecode(op == BvConst(3, 2));
    auto res = rs1_val & rs2_val;
    SET_UPDATE(AND, rd, res);
  }

  return pipe_ila;
}

Ila UndetVal::BuildModel() {
  auto m = Ila("undetval");
  auto r0 = m.NewBvState("r0", 8);
  auto r1 = m.NewBvState("r1", 8);
  auto r2 = m.NewBvState("r2", 8);
  auto r3 = m.NewBvState("r3", 8);
  auto r4 = m.NewBvState("r4", 8);

  auto f1 = FuncRef("nondet8_1", SortRef::BV(8));
  auto f2 = FuncRef("nondet8_2", SortRef::BV(8));

  auto nondet = f1();

  auto INST = m.NewInstr("INST");
  {
    INST.SetDecode(BoolConst(true));
    INST.SetUpdate(r0, nondet + 1);
    INST.SetUpdate(r1, nondet + 2);
    INST.SetUpdate(r2, f1() + 3);
    INST.SetUpdate(r3, f2() + 4);
    INST.SetUpdate(r4, f2() + 5);
  }

  return m;
}

Ila UndetFunc::BuildModel() {
  auto m = Ila("undetfunc");
  auto r0 = m.NewBvState("r0", 8);
  auto r1 = m.NewBvState("r1", 8);
  auto r2 = m.NewBvState("r2", 8);
  auto r3 = m.NewBvState("r3", 8);
  auto r4 = m.NewBvState("r4", 8);

  auto f1 = FuncRef("nondet8_1", SortRef::BV(8), SortRef::BV(8));
  auto f2 =
      FuncRef("nondet8_2", SortRef::BV(8), SortRef::BV(8), SortRef::BV(8));

  auto nondet = f1(r0);

  auto INST = m.NewInstr("INST2");
  {
    INST.SetDecode(BoolConst(true));
    INST.SetUpdate(r0, nondet + 1);
    INST.SetUpdate(r1, nondet + 2);
    INST.SetUpdate(r2, f1(r0) + 1);
    INST.SetUpdate(r3, f2(r1, r2) + 2);
    INST.SetUpdate(r4, f2(r3, r4) + 3);
  }

  return m;
}

Ila UndetFunc::BuildIteUknModel() {
  auto m = Ila("undetfunc");
  m.SetValid(BoolConst(true));
  auto en = m.NewBvInput("en", 1);
  auto r0 = m.NewBvState("r0", 8);
  auto r1 = m.NewBvState("r1", 8);
  auto r2 = m.NewBvState("r2", 8);
  auto r3 = m.NewBvState("r3", 8);
  auto f1 = FuncRef("__unknown__2", SortRef::BV(8));

  auto INST = m.NewInstr("INST");
  {
    INST.SetDecode(BoolConst(true));
    INST.SetUpdate(r0, Ite(en == 1, r1+1, f1() ) );
    INST.SetUpdate(r1, Ite(en == 1, r0+1, f1() ) );
    INST.SetUpdate(r2, Ite(en == 1, r0+r1+1, r2 ) );
    INST.SetUpdate(r3, r0+r1+r2+r3 );
  }
  return m;
}

Ila MonitorTest::BuildModel() {
  auto m = Ila("monitortest");
  auto en = m.NewBvInput("en", 1);
  auto r0 = m.NewBvInput("r0", 8);
  auto r1 = m.NewBvInput("r1", 8);
  auto r2 = m.NewBvState("r2", 8);

  auto INST = m.NewInstr("INST3");
  {
    INST.SetDecode(en == 1);
    INST.SetUpdate(r2, r1 + r2);
  }

  return m;
}

Ila CntTest::BuildModel() {
  auto m = Ila("counter");
  auto en = m.NewBvInput("en", 1);
  auto v  = m.NewBvState("v" , 4);
  auto INC = m.NewInstr("INC");
  {
    INC.SetDecode(en == 1);
    INC.SetUpdate(v, v + 1);
  }
  return m;
}

} // namespace ilang
