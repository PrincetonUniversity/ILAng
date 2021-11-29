
#include "../unit-include/memswap.h"
#include <ilang/ilang++.h>
#include <ilang/util/log.h>

namespace ilang {

Ila MemorySwap::BuildModel() {
  // build the ila
  auto memswap = Ila("MemorySwap");
  memswap.SetValid(BoolConst(true));

  auto addra = memswap.NewBvInput("addra", 32);
  auto addrb = memswap.NewBvInput("addrb", 32);
  auto start = memswap.NewBvInput("start", 1);

  auto mema = memswap.NewMemState("mema", 32, 8);
  auto memb = memswap.NewMemState("memb", 32, 8);

  {
    auto SWAP = memswap.NewInstr("SWAP");
    SWAP.SetDecode(start == 1);

    auto dataa = Load(mema, addra);
    auto datab = Load(memb, addrb);

    SWAP.SetUpdate(mema, Store(mema, addra, datab)); //mema[addra] = memb[addrb]
    SWAP.SetUpdate(memb, Store(memb, addrb, dataa)); //memb[addrb] = mema[addra]
  }
  return memswap;
}


Ila MemorySwap::BuildSimpleLargeArray() {
  auto ila = Ila("LargeArray");
  ila.SetValid(BoolConst(true));
  auto wen  = ila.NewBvInput("wen",  1);
  auto ren  = ila.NewBvInput("ren",  1);
  auto addr = ila.NewBvInput("addr", 4);
  auto data = ila.NewBvInput("data", 8);
  auto odata = ila.NewBvState("odata", 8);

  auto array = ila.NewMemState("array", 4, 8);

  {
    auto WRITE = ila.NewInstr("WRITE");
    WRITE.SetDecode(wen == 1);
    WRITE.SetUpdate(array,Store(array, addr,data));
  }

  {
    auto READ = ila.NewInstr("READ");
    READ.SetDecode(ren == 1);
    READ.SetUpdate(odata, Load(array, addr));
  }
  return ila;
}

Ila MemorySwap::BuildSimpleSwapModel() {
  // build the ila
  auto memswap = Ila("MemorySwap");
  memswap.SetValid(BoolConst(true));

  auto addra = memswap.NewBvInput("addra", 4);
  auto addrb = memswap.NewBvInput("addrb", 4);
  auto start = memswap.NewBvInput("start", 1);

  auto mema = memswap.NewMemState("mema", 4, 8);
  auto memb = memswap.NewMemState("memb", 4, 8);

  {
    auto SWAP = memswap.NewInstr("SWAPExpand");
    SWAP.SetDecode(start == 1);

    auto dataa = Load(mema, addra);
    auto datab = Load(memb, addrb);

    SWAP.SetUpdate(mema, Store(mema, addra, datab)); //mema[addra] = memb[addrb]
    SWAP.SetUpdate(memb, Store(memb, addrb, dataa)); //memb[addrb] = mema[addra]
  }
  return memswap;
}

Ila MemorySwap::BuildRdModel() {
  // build the ila
  auto memswap = Ila("MemRd");
  memswap.SetValid(BoolConst(true));

  auto addra = memswap.NewBvInput("addra", 32);
  auto start = memswap.NewBvInput("start", 1);
  auto membuf = memswap.NewBvState("membuf", 8);

  auto mema = memswap.NewMemState("mema", 32, 8);

  {
    auto SWAP = memswap.NewInstr("Rd");
    SWAP.SetDecode(start == 1);

    auto dataa = Load(mema, addra);

    SWAP.SetUpdate(membuf, dataa);
  }
  return memswap;
}

Ila MemorySwap::BuildRfAsMemModel() {
  // build the ila
  auto proc = Ila("proc");
  proc.SetValid(BoolConst(true));

  auto op = proc.NewBvInput("op", 2);
  auto operand1 = proc.NewBvInput("operand1", 2);
  auto operand2 = proc.NewBvInput("operand2", 2);

  auto rf  = proc.NewMemState("rf",  2, 8);
  auto mem = proc.NewMemState("mem", 8, 8);

  { // ADD1
    auto ADD1 = proc.NewInstr("ADD1");
    ADD1.SetDecode(op == 0);
    ADD1.SetUpdate(rf, Store(rf, operand1, Load(rf, operand2) + 1));
  }
  { // STORE
    auto STORE = proc.NewInstr("STORE");
    STORE.SetDecode(op == 1);
    STORE.SetUpdate(mem, Store(mem, Load(rf, operand1), Load(rf, operand2)));
  }
  { // LOAD
    auto LOAD = proc.NewInstr("LOAD");
    LOAD.SetDecode(op == 2);
    LOAD.SetUpdate(rf, Store(rf, operand1, Load(mem, Load(rf, operand2))));
  }

  return proc;
}


Ila MemorySwap::BuildRfAsMemModelRegEntry6() {
  // build the ila
  auto proc = Ila("proc");
  proc.SetValid(BoolConst(true));

  auto op = proc.NewBvInput("op", 2);
  auto operand1 = proc.NewBvInput("operand1", 3);
  auto operand2 = proc.NewBvInput("operand2", 3);

  auto rf  = proc.NewMemState("rf",  3, 8); // but only r0-r5
  auto mem = proc.NewMemState("mem", 8, 8);

  rf.SetEntryNum(6); // but only r0-r5
  auto operand1_clipped = Ite( Ugt( operand1,  5), BvConst(0,3), operand1);
  auto operand2_clipped = Ite( Ugt( operand2,  5), BvConst(0,3), operand2);

  { // ADD1
    auto ADD1 = proc.NewInstr("ADD1");
    ADD1.SetDecode(op == 0);
    ADD1.SetUpdate(rf, 
      Ite(Ugt( operand1,  5), rf,
      Store(rf, operand1_clipped, Load(rf, operand2_clipped) + 1))
      );
  }
  { // STORE
    auto STORE = proc.NewInstr("STORE");
    STORE.SetDecode(op == 1);
    STORE.SetUpdate(mem, Store(mem, Load(rf, operand1_clipped), Load(rf, operand2_clipped)));
  }
  { // LOAD
    auto LOAD = proc.NewInstr("LOAD");
    LOAD.SetDecode(op == 2);
    LOAD.SetUpdate(rf, 
      Ite(Ugt( operand1,  5), rf,
      Store(rf, operand1_clipped, Load(mem, Load(rf, operand2_clipped)))));
  }

  return proc;
}

Ila MemorySwap::BuildResetterTest() {
  // build the ila
  auto proc = Ila("proc");
  auto v = proc.NewBvState("v",1);
  proc.SetValid(BoolConst(true));
  { //
    auto inst = proc.NewInstr("inst");
    inst.SetDecode(BoolConst(true));
    inst.SetUpdate(v, BvConst(1,1));
  }
  return proc;
}


} // namespace ilang
