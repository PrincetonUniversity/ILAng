
#include "../unit-include/memswap.h"
#include <ilang/ilang++.h>
#include <ilang/util/log.h>

namespace ilang {

  Ila MemorySwap::BuildModel() {
    // build the ila
    auto memswap = Ila("MemorySwap");
    memswap.SetValid( BoolConst(true) );

    auto addra = memswap.NewBvInput("addra", 32);
    auto addrb = memswap.NewBvInput("addrb", 32);
    auto start = memswap.NewBvInput("start", 1);

    auto mema = memswap.NewMemState("mema",32,8);
    auto memb = memswap.NewMemState("memb",32,8);
    
    {
      auto SWAP = memswap.NewInstr("SWAP");
      SWAP.SetDecode(start == 1);

      auto dataa = Load(mema,addra);
      auto datab = Load(memb,addrb);

      SWAP.SetUpdate(mema, Store(mema,addra, datab));
      SWAP.SetUpdate(memb, Store(memb,addrb, dataa));
    }
    return memswap; 
  }
} // namespace ilang
