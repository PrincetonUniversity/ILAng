/// \file
/// Unit tests for program fragment checker

#include <ilang/ila-mngr/v_eq_check_progfrag.h>
#include <ilang/ilang++.h>
#include <ilang/util/fs.h>

#include "unit-include/config.h"
#include "unit-include/simple_cpu.h"
#include "unit-include/util.h"

namespace ilang {

namespace pf2graph {

  using namespace pfast;

  TEST(Pf2cfg, CutPointGraph) {

    auto file_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "aes");
    auto ila_file = os_portable_append_dir(file_dir, "aes.json");
    InstrLvlAbsPtr ila = ImportIlaPortable(ila_file).get();

    ProgramFragment pf {
      {ila->state("aes_address")},
      Block{
        Assume{asthub::Gt(ila->state("aes_key"), 0)},
        Assume{asthub::Gt(ila->state("aes_key"), 0)},
        Call{ila->instr("WRITE_ADDRESS")},
        Call{ila->instr("START_ENCRYPT")},
        Assert{asthub::Gt(ila->state("aes_key"), 0)},
        Call{ila->instr("START_ENCRYPT")},
        Assert{asthub::Gt(ila->state("aes_key"), 0)}
      }
    };

    bool cmp_same_fragment = (pf == ProgramFragment{
      {ila->state("aes_address")},
      Block{
        Assume{asthub::Gt(ila->state("aes_key"), 0)},
        Assume{asthub::Gt(ila->state("aes_key"), 0)},
        Call{ila->instr("WRITE_ADDRESS")},
        Call{ila->instr("START_ENCRYPT")},
        Assert{asthub::Gt(ila->state("aes_key"), 0)},
        Call{ila->instr("START_ENCRYPT")},
        Assert{asthub::Gt(ila->state("aes_key"), 0)}
      }
    });
    EXPECT_TRUE(cmp_same_fragment);

    bool cmp_diff_fragment = (pf == ProgramFragment{
      {ila->state("aes_address")},
      Block{
        Assume{asthub::Gt(ila->state("aes_key"), 0)},
        Call{ila->instr("WRITE_ADDRESS")},
        Assert{asthub::Gt(ila->state("aes_key"), 0)}
      }
    }
    );
    EXPECT_FALSE(cmp_diff_fragment);
  }

  TEST(Pf2cfg, Counter) {

    // create ILA

    Ila m {"Counter"};

    constexpr int OP_INC = 1;
    constexpr int OP_DEC = 2;

    auto ctr = m.NewBvState("ctr", 8);
    auto op = m.NewBvInput("op", 2);

    InstrPtr inst_inc;
    {
      auto instr = m.NewInstr("INC");
      instr.SetDecode(op == OP_INC);
      instr.SetUpdate(ctr, ctr + 1);
      inst_inc = instr.get();
    }

    InstrPtr inst_dec;
    { auto instr = m.NewInstr("DEC");
      instr.SetDecode(op == OP_DEC);
      instr.SetUpdate(ctr, Ite(ctr == 0, BvConst(0, 8), ctr + 1));
      inst_dec = instr.get();
    }

    // program fragment
    ProgramFragment pf {{ /* no params */ }, {
      Assume {asthub::Eq(ctr.get(), 0)},
      Call {inst_inc},
      Assert {asthub::Eq(ctr.get(), 1)}
    }};

    PFToCHCEncoder encoder {m.get(), pf};
    
    std::cout << "\nEncoded successfully!\n" << std::endl;

    std::cout << encoder.to_string() << std::endl;

    z3::check_result res = encoder.check_assertions();
    EXPECT_EQ(res, z3::unsat);

  }

  // TEST(Pf2cfg, UnrollerSMTTest) {
    
  //   using namespace pfast;

  //   auto m = SimpleCpu("m");

  //   Block b;

  //   // initial conditions of CPU
  //   for (size_t i = 0; i != m->init_num(); i++) {
  //     b.push_back(Assert(m->init(i)));
  //   }

  //   // 
  //   ProgramFragment pf {{ /* no params */ }, {
  //     Call(m->instr("Load")),
  //     Call(m->instr("Load")),
  //     Call(m->instr("Add")),
  //     Call(m->instr("Store"))
  //   }};

  // }

}

}