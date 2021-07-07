/// \file
/// Unit tests for program fragment checker

#include <ilang/ila-mngr/v_eq_check_progfrag.h>
#include <ilang/ilang++.h>
#include <ilang/util/fs.h>

#include "unit-include/config.h"
#include "unit-include/simple_cpu.h"
#include "unit-include/util.h"

#define COUNTER_INSTR_INC "INC"
#define COUNTER_INSTR_DEC "DEC"

#define COUNTER_OP_INC 1
#define COUNTER_OP_DEC 2

#define COUNTER_STATE_CTR "ctr"
#define COUNTER_INPUT_OP "op"

namespace ilang {

namespace pf2graph {

  using namespace pfast;

  InstrLvlAbsPtr simple_counter_ila() {
    Ila m {"Counter"};

    auto ctr = m.NewBvState(COUNTER_STATE_CTR, 8);
    auto op = m.NewBvInput(COUNTER_INPUT_OP, 2);

    { // increment
      auto instr = m.NewInstr(COUNTER_INSTR_INC);
      instr.SetDecode(op == COUNTER_OP_INC);
      instr.SetUpdate(ctr, ctr + 1);
    }

    { // decrement
      auto instr = m.NewInstr(COUNTER_INSTR_DEC);
      instr.SetDecode(op == COUNTER_OP_DEC);
      instr.SetUpdate(ctr, Ite(ctr == 0, BvConst(0, 8), ctr - 1));
    }

    return m.get();
  }

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

    InstrLvlAbsPtr m = simple_counter_ila();
    auto inst_inc = m->instr(COUNTER_INSTR_INC);
    auto inst_dec = m->instr(COUNTER_INSTR_DEC);

    auto ctr = m->state(COUNTER_STATE_CTR);
    auto op = m->input(COUNTER_INPUT_OP);

    // program fragment
    ProgramFragment pf {{ /* no params */ }, {
      Assume {asthub::Eq(ctr, 0)},
      Call {inst_inc},
      Assert {asthub::Eq(ctr, 1)},
      Call {inst_dec},
      Call {inst_dec},
      Assert {asthub::Eq(ctr, 0)},  // dec should not go less than 0
      Call {inst_inc},
      Call {inst_inc},
      Call {inst_dec},
      Call {inst_inc},
      Assert {asthub::Eq(ctr, 2)}
    }};

    PFToCHCEncoder encoder {m, pf};
    
    // std::cout << "\nEncoded successfully!\n" << std::endl;

    // std::cout << encoder.to_string() << std::endl;

    EXPECT_NO_THROW(encoder.to_string());

    PFToCHCEncoder::Result res = encoder.check_assertions();
    EXPECT_EQ(res, PFToCHCEncoder::VALID);
  }

  TEST(Pf2cfg, CounterFail) {

    // create ILA

    InstrLvlAbsPtr m = simple_counter_ila();
    auto inst_inc = m->instr(COUNTER_INSTR_INC);
    auto inst_dec = m->instr(COUNTER_INSTR_DEC);

    auto ctr = m->state(COUNTER_STATE_CTR);
    auto op = m->input(COUNTER_INPUT_OP);

    // program fragment
    ProgramFragment pf {{ /* no params */ }, {
      Assume {asthub::Eq(ctr, 0)},
      Call {inst_inc},
      Assert {asthub::Eq(ctr, 1)},
      Call {inst_dec},
      Call {inst_dec},
      Assert {asthub::Eq(ctr, 3)},  // assertion should fail
      Call {inst_inc},
      Call {inst_inc},
      Call {inst_dec},
      Call {inst_inc},
      Assert {asthub::Eq(ctr, 2)}
    }};

    PFToCHCEncoder encoder {m, pf};
    
    // std::cout << "\nEncoded successfully!\n" << std::endl;

    // std::cout << encoder.to_string() << std::endl;

    PFToCHCEncoder::Result res = encoder.check_assertions();
    EXPECT_EQ(res, PFToCHCEncoder::INVALID);
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
    
    // std::cout << "\nEncoded successfully!\n" << std::endl;

    // std::cout << encoder.to_string() << std::endl;

    PFToCHCEncoder::Result res = encoder.check_assertions();
    EXPECT_EQ(res, PFToCHCEncoder::VALID);

  }

  TEST(Pf2cfg, UnrollerSMTTestWithParams) {
    
    using namespace pfast;
    using namespace asthub;

    auto m = SimpleCpu("m");

    // params
    ExprPtr x = m->NewBvFreeVar("x", 8);
    ExprPtr y = m->NewBvFreeVar("y", 8);

    // fragment body
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

    // link params and model
    b.insert(b.end(), {
      Assume{Eq(Load(m->state("mem"), 0), x)},
      Assume{Eq(Load(m->state("mem"), 1), y)}
    });

    // program
    b.insert(b.end(), {
      Call{m->instr("Load")},
      Call{m->instr("Load")},
      Call{m->instr("Add")},
      Call{m->instr("Store")}
    });

    // check stored result
    b.push_back(Assert{Eq(Load(m->state("mem"), 2), asthub::Add(x, y))});

    ProgramFragment pf {{x, y}, b}; /* no params */

    PFToCHCEncoder encoder {m, pf};
    
    // std::cout << "\nEncoded successfully!\n" << std::endl;

    // std::cout << encoder.to_string() << std::endl;

    PFToCHCEncoder::Result res = encoder.check_assertions();

    EXPECT_EQ(res, PFToCHCEncoder::VALID);

  }

}

}