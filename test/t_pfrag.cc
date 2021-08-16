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

  TEST(ProgFrag, StructuralEquality) {

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

  TEST(Pf2chc, Counter) {

    InstrLvlAbsPtr m = simple_counter_ila();
    auto inst_inc = m->instr(COUNTER_INSTR_INC);
    auto inst_dec = m->instr(COUNTER_INSTR_DEC);

    auto ctr = m->state(COUNTER_STATE_CTR);
    auto op = m->input(COUNTER_INPUT_OP);

    auto ctr_w = ctr->sort()->bit_width();
    auto lowbound = m->NewBvFreeVar("lowbound", ctr_w);

    // program fragment
    ProgramFragment pf {{ lowbound }, {
      Assume {asthub::Eq(ctr, 0)},
      Assume {asthub::Eq(lowbound, 0)},
      Call {inst_inc},
      Update {{lowbound, asthub::Add(lowbound, asthub::BvConst(1, ctr_w))}},
      Assert {asthub::Eq(ctr, 1)},
      Call {inst_dec},
      Update {{lowbound, asthub::Sub(lowbound, asthub::BvConst(1, ctr_w))}},
      Call {inst_dec},
      Update {{lowbound, asthub::Sub(lowbound, asthub::BvConst(1, ctr_w))}},
      Assert {asthub::Eq(ctr, 0)},  // dec should not go less than 0
      Block{
        Call {inst_inc},
        Call {inst_inc},
        Call {inst_dec},
        Call {inst_inc},
        Update {{lowbound, asthub::Add(lowbound, asthub::BvConst(3, ctr_w))}},
        Assert {asthub::Eq(ctr, 2)},
      },
      Assert {asthub::Le(lowbound, ctr)}
    }};

    z3::context ctx;
    z3::fixedpoint ctxfp {ctx};
    PFToCHCEncoder encoder {ctx, ctxfp, m, pf};
    
    // std::cout << "\nEncoded successfully!\n" << std::endl;

    // std::cout << encoder.to_string() << std::endl;

    EXPECT_NO_THROW(encoder.to_string());

    z3::check_result res = z3::sat;
    try {
      res = encoder.check_assertions();
    } catch (const z3::exception& e) {
      std::cout << "Error: " << e << std::endl;
    }

    EXPECT_EQ(res, z3::unsat);
  }

  TEST(Pf2chc, CounterFail) {

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

    z3::context ctx;
    z3::fixedpoint ctxfp {ctx};
    PFToCHCEncoder encoder {ctx, ctxfp, m, pf};
    
    // std::cout << "\nEncoded successfully!\n" << std::endl;

    // std::cout << encoder.to_string() << std::endl;

    z3::check_result res = encoder.check_assertions();
    EXPECT_EQ(res, z3::sat);
  }

  TEST(Pf2chc, UnrollerSMTTest) {
    
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

    z3::context ctx;
    z3::fixedpoint ctxfp {ctx};
    
    // use spacer instead of datalog engine
    z3::params p {ctx};
    p.set("engine", "spacer");
    ctxfp.set(p);

    PFToCHCEncoder encoder {ctx, ctxfp, m, pf};
    
    // std::cout << "\nEncoded successfully!\n" << std::endl;

    // std::cout << encoder.to_string() << std::endl;

    z3::check_result res = encoder.check_assertions();
    EXPECT_EQ(res, z3::unsat);

  }

  TEST(Pf2chc, UnrollerSMTTestWithParams) {
    
    using namespace pfast;
    using namespace asthub;

    auto m = SimpleCpu("m");

    // params
    ExprPtr x = m->NewBvFreeVar("x", 8);
    ExprPtr y = m->NewBvFreeVar("y", 8);
    ExprPtr unused = m->NewBvFreeVar("unused", 8);

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

    ProgramFragment pf {{x, y, unused}, b};

    z3::context ctx;
    z3::fixedpoint ctxfp {ctx};
    
    // use spacer instead of datalog
    z3::params p {ctx};
    p.set("engine", "spacer");
    ctxfp.set(p);

    PFToCHCEncoder encoder {ctx, ctxfp, m, pf};
    
    // std::cout << "\nEncoded successfully!\n" << std::endl;

    // std::cout << encoder.to_string() << std::endl;

    z3::check_result res = encoder.check_assertions();

    EXPECT_EQ(res, z3::unsat);

  }

  TEST(Pf2chc, CounterLoop) {

    InstrLvlAbsPtr m = simple_counter_ila();
    auto inst_inc = m->instr(COUNTER_INSTR_INC);
    auto inst_dec = m->instr(COUNTER_INSTR_DEC);

    auto ctr = m->state(COUNTER_STATE_CTR);
    auto op = m->input(COUNTER_INPUT_OP);

    auto ctr_w = ctr->sort()->bit_width();
    auto x = m->NewBvFreeVar("x", ctr_w);
    auto y = m->NewBvFreeVar("y", ctr_w);
    auto i = m->NewBvFreeVar("i", ctr_w);

    auto inv1 = asthub::And(asthub::Eq(ctr, i), asthub::Le(i, x));

    auto inv2 = asthub::And(
      asthub::Ge(ctr, asthub::BvConst(0, ctr_w)),
      asthub::Or(asthub::Eq(ctr, asthub::Sub(x, i)),
                 asthub::Eq(ctr, asthub::BvConst(0, ctr_w)))
    );

    // program fragment
    ProgramFragment pf {{ x, y, i }, {
      Assume {asthub::Eq(ctr, 0)},
      Assume {asthub::Gt(x, 0)},
      Assume {asthub::Gt(y, x)},
      Assume {asthub::Lt(y, 15)},  // keeps runtime short

      Update { {i, asthub::BvConst(0, ctr_w)} },
      Assert { inv1 },
      While { asthub::Lt(i, x), {
        Assume { inv1 },
        Call { inst_inc, asthub::BoolConst(true) },
        Update { {i, asthub::Add(i, asthub::BvConst(1, ctr_w))} },
        Assert { inv1 },
      }},
      Assume { inv1 },

      Update { {i, asthub::BvConst(0, ctr_w)} },
      Assert { inv2 },
      While { asthub::Lt(i, y), {
        Assume { inv2 },
        Call { inst_dec, asthub::BoolConst(true) },
        Update { {i, asthub::Add(i, asthub::BvConst(1, ctr_w))} },
        Assert { inv2 },
      }},
      Assume { inv2 },
      Assert { asthub::Eq(ctr, 0) }
    }};

    z3::context ctx;
    z3::fixedpoint ctxfp {ctx};

    // use spacer instead of datalog
    z3::params p {ctx};
    p.set("engine", "spacer");
    ctxfp.set(p);

    PFToCHCEncoder encoder {ctx, ctxfp, m, pf};
    
    // std::cout << "\nEncoded successfully!\n" << std::endl;

    // std::cout << encoder.to_string() << std::endl;

    EXPECT_NO_THROW(encoder.to_string());

    z3::check_result res = z3::sat;
    try {
      res = encoder.check_assertions();
    } catch (const z3::exception& e) {
      std::cout << "Error: " << e << std::endl;
    }

    EXPECT_EQ(res, z3::unsat);
  }

  TEST(Pf2chc, Hierarchy) {

    Ila m {"Broadcast"};

    constexpr int msg_bits = 64;
    constexpr int port_bits = 8;

    auto next_msg = m.NewBvInput("next_msg", msg_bits);
    auto msg = m.NewBvState("msg", msg_bits);
    
    auto n_ports = m.NewBvState("nports", port_bits);
    auto ports = m.NewMemState("ports", port_bits, msg_bits);

    auto cur_port = m.NewBvState("cur_port", port_bits);

    m.SetValid((n_ports > 0) & (msg == 0 | next_msg == 0));

    auto child = m.NewChild("broadcaster");
    child.SetValid((n_ports > 0) & (msg != 0));
    auto bcast_step = child.NewInstr("bcast_step");
    {
      bcast_step.SetDecode((msg != 0) & (cur_port < n_ports));
      bcast_step.SetUpdate(ports, Store(ports, cur_port, msg));
      bcast_step.SetUpdate(cur_port, cur_port + 1);
      bcast_step.SetUpdate(msg, 
        Ite(cur_port + 1 == n_ports, BvConst(0, msg_bits), msg));
    }

    auto broadcast = m.NewInstr("bcast");
    {
      broadcast.SetDecode((msg == 0) & (next_msg != 0));
      broadcast.SetUpdate(msg, next_msg);
      broadcast.SetUpdate(cur_port, BvConst(0, port_bits));
      broadcast.SetProgram(child);
    }

    auto num = m.get()->NewBvFreeVar("num", msg_bits);
    auto k = m.get()->NewBvFreeVar("k", port_bits);
    auto i = m.get()->NewBvFreeVar("i", port_bits);

    auto inv = asthub::And(
      asthub::Le(i, n_ports.get()),
      asthub::Or(
        asthub::Le(i, k),
        asthub::Eq(asthub::Load(ports.get(), k), num)
      )
    ); 

    /* Program fragment:
    FORALL num, k, i {
      ASSUME 0 < k < n_ports;
      CALL broadcast WHERE next_msg = num;
      UPDATE i = 0;
      ASSERT inv: (i <= n) && (i <= k || ports[k] == num);
      WHILE i < n_ports DO {
        ASSUME inv;
        CALL bcast_step;
        UPDATE i = i + 1;
        ASSERT inv;
      } END;
      ASSUME inv;
      ASSERT ports[k] == num;
    }
    */

    ProgramFragment pf {{num, k, i}, {
      // ASSUME 0 < k < n_ports
      Assume { asthub::Gt(k, asthub::BvConst(0, port_bits)) },
      Assume { asthub::Gt(n_ports.get(), k) },
      // CALL broadcast WHERE next_msg = num
      Call { broadcast.get(), asthub::Eq(next_msg.get(), num) },
      // UPDATE i = 0
      Update { {i, asthub::BvConst(0, port_bits)} },
      // ASSERT inv: (i <= n) && (i <= k || ports[k] == num)
      Assert { inv },
      // WHILE i < n_ports DO
      While { asthub::Lt(i, n_ports.get()), {
        // ASSUME inv
        Assume { inv },
        // CALL bcast_step
        Call { bcast_step.get() },
        // UPDATE i = i + 1
        Update { {i, asthub::Add(i, asthub::BvConst(1, port_bits))} },
        // ASSERT inv
        Assert { inv }
      } }, // END
      // ASSUME inv
      Assume { inv },
      // ASSERT ports[k] = num
      Assert { asthub::Eq(asthub::Load(ports.get(), k), num) }
    }};

    z3::context ctx;
    z3::fixedpoint ctxfp {ctx};

    // use spacer instead of datalog
    z3::params p {ctx};
    p.set("engine", "spacer");
    ctxfp.set(p);

    PFToCHCEncoder encoder {ctx, ctxfp, m.get(), pf};
    
    // std::cout << "\nEncoded successfully!\n" << std::endl;

    // std::cout << encoder.to_string() << std::endl;

    EXPECT_NO_THROW(encoder.to_string());

    z3::check_result res = z3::sat;
    
    try {
      res = encoder.check_assertions();
    } catch (const z3::exception& e) {
      std::cout << "Error: " << e << std::endl;
    }

    EXPECT_EQ(res, z3::unsat);

  }

  TEST(Pf2chc, CounterLoopNested) {

    InstrLvlAbsPtr m = simple_counter_ila();
    auto inst_inc = m->instr(COUNTER_INSTR_INC);
    auto inst_dec = m->instr(COUNTER_INSTR_DEC);

    auto ctr = m->state(COUNTER_STATE_CTR);
    auto op = m->input(COUNTER_INPUT_OP);

    auto ctr_w = ctr->sort()->bit_width();
    auto x = asthub::NewBvVar("x", ctr_w); // asthub::BvConst(3, ctr_w);
    auto y = asthub::NewBvVar("y", ctr_w); // asthub::BvConst(4, ctr_w);
    auto i = asthub::NewBvVar("i", ctr_w);
    auto j = asthub::NewBvVar("j", ctr_w);

    auto inv1 = asthub::And(
      asthub::Eq(ctr, asthub::Mul(i, y)), 
      asthub::Le(i, x)
    );

    auto inv2 = asthub::And(
      asthub::Eq(ctr, asthub::Add(asthub::Mul(i, y), j)), 
      asthub::Le(j, y)
    );

    // program fragment
    ProgramFragment pf {{ x, y, i, j }, {
      Assume {asthub::Eq(ctr, 0)},
      Assume {asthub::Gt(x, 0)},
      Assume {asthub::Gt(y, 0)},
      Assume {asthub::Lt(x, 3)},  // keeps runtime short
      Assume {asthub::Lt(y, 4)},  // keeps runtime short

      Update { {i, asthub::BvConst(0, ctr_w)} },
      Assert { inv1 },
      While { asthub::Lt(i, x), {
        Assume { inv1 },
         Update { {j, asthub::BvConst(0, ctr_w)} },
        Assert { inv2 },
        While { asthub::Lt(j, y), {
          Assume { inv2 },
          Call { inst_inc },
          Update { {j, asthub::Add(j, asthub::BvConst(1, ctr_w))} },
          Assert { inv2 }
        }},
        Assume { inv2 },
        Update { {i, asthub::Add(i, asthub::BvConst(1, ctr_w))} },
        Assert { inv1 },
      }},
      Assume { inv1 },
      Assert { asthub::Eq(ctr, asthub::Mul(x, y)) }
    }};

    z3::context ctx;
    z3::fixedpoint ctxfp {ctx};

    // use spacer instead of datalog
    z3::params p {ctx};
    p.set("engine", "spacer");
    ctxfp.set(p);

    PFToCHCEncoder encoder {ctx, ctxfp, m, pf};
    
    // std::cout << "\nEncoded successfully!\n" << std::endl;

    // std::cout << encoder.to_string() << std::endl;

    EXPECT_NO_THROW(encoder.to_string());

    z3::check_result res = z3::sat;
    try {
      res = encoder.check_assertions();
    } catch (const z3::exception& e) {
      std::cout << "Error: " << e << std::endl;
    }

    EXPECT_EQ(res, z3::unsat);
  }

}

}
