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
      Assert {asthub::Eq(ctr.get(), 1)},
      Call {inst_dec},
      Call {inst_dec},
      Assert {asthub::Eq(ctr.get(), 0)},  // dec should not go less than 0
      Call {inst_inc},
      Call {inst_inc},
      Call {inst_dec},
      Call {inst_inc},
      Assert {asthub::Eq(ctr.get(), 2)},
    }};

    PFToCHCEncoder encoder {m.get(), pf};
    
    // std::cout << "\nEncoded successfully!\n" << std::endl;

    // std::cout << encoder.to_string() << std::endl;

    z3::check_result res = encoder.check_assertions();
    EXPECT_EQ(res, z3::unsat);
  }

  TEST(Pf2cfg, UnrollerSMTTest) {
    
    using namespace pfast;
    using namespace asthub;

    auto m = SimpleCpu("m");

    Block b;

    // initial conditions of CPU
    for (size_t i = 0; i != m->init_num(); i++) {
      b.push_back(Assume{m->init(i)});
    }

    MemVal init_mem_val(0);
    init_mem_val.set_data(0, GenLoad(0, 0));
    init_mem_val.set_data(1, GenLoad(1, 1));
    init_mem_val.set_data(2, GenAdd(2, 0, 1));
    init_mem_val.set_data(3, GenStore(2, 2));

    { // instruction memory
      auto ir = m->state("ir");
      b.push_back(Assume{Eq(ir, MemConst(init_mem_val, 8, 8))});
    }

    // concretize data
    b.insert(b.end(), {
      Assume{Eq(m->state("r0"), 7)},
      Assume{Eq(m->state("r1"), 7)},
      Assume{Eq(Load(m->state("mem"), 0), 3)},
      Assume{Eq(Load(m->state("mem"), 1), 3)}
    });

    // program
    b.insert(b.end(), {
      Call{m->instr("Load")},
      Call{m->instr("Load")},
      Call{m->instr("Add")},
      Call{m->instr("Store")}
    });

    // check stored result
    b.push_back(Assert{Eq(Load(m->state("mem"), 2), 6)});

    ProgramFragment pf {{ }, b}; /* no params */

    PFToCHCEncoder encoder {m, pf};
    
    std::cout << "\nEncoded successfully!\n" << std::endl;

    std::cout << encoder.to_string() << std::endl;

    z3::check_result res = z3::sat;

    try {
      res = encoder.check_assertions();
    } catch (z3::exception e) {
      std::cout << "Got error:\n" << e << std::endl;
    }

    EXPECT_EQ(res, z3::unsat);

  }

}

}