
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
  auto oprand1 = proc.NewBvInput("oprand1", 2);
  auto oprand2 = proc.NewBvInput("oprand2", 2);

  auto rf  = proc.NewMemState("rf",  8, 8);
  auto mem = proc.NewMemState("mem", 8, 8);

  { // ADD1
    auto ADD1 = proc.NewInstr("ADD1");
    ADD1.SetDecode(op == 0);
    ADD1.SetUpdate(rf, Store(rf, oprand1, Load(rf, oprand2)));
  }
  { // STORE
    auto STORE = proc.NewInstr("STORE");
    STORE.SetDecode(op == 1);
    STORE.SetUpdate(mem, Store(mem, Load(rf, oprand1), Load(rf, oprand2)));
  }
  { // LOAD
    auto LOAD = proc.NewInstr("LOAD");
    LOAD.SetDecode(op == 2);
    LOAD.SetUpdate(rf, Store(rf, oprand1, Load(mem, Load(rf, oprand2))));
  }

  return proc;
}

} // namespace ilang
