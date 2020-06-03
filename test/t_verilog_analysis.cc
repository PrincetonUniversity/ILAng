/// \file
/// Unit test for Verilog analyzer.
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include <ilang/ila-mngr/u_abs_knob.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/verilog-in/verilog_analysis_wrapper.h>
#include <ilang/verilog-in/verilog_parse.h>
#include <ilang/verilog-out/verilog_gen.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

// this will probably create problem as it only init but does no
// release, removed
// TEST(TestVerilogAnalysis, ParserInit) { TestParseVerilog(); }

TEST(TestVerilogAnalysis, BaseFuncNoError) {
  auto fn = std::string(ILANG_TEST_SRC_ROOT) +
            "/unit-data/verilog_sample/t_ana_inst.v";

  EXPECT_EQ(TestParseVerilogFrom(fn), 0);
}

TEST(TestVerilogAnalysis, Init) {

  VerilogInfo va(
      VerilogInfo::path_vec_t(),
      VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                               "/unit-data/verilog_sample/t_ana_inst.v"}),
      "m1");
}

#ifdef TEST_BAD_STATE
TEST(TestVerilogAnalysis, BadState) {
  VerilogInfo va(VerilogInfo::path_vec_t(),
                 VerilogInfo::path_vec_t(
                     {std::string(ILANG_TEST_SRC_ROOT) +
                      "/unit-data/verilog_sample/t_ana-nonexisting.v"}),
                 "m1");

  // The above will make it into bad state
  // but it should not affect other things

  auto tp_ = va.check_hierarchical_name_type("m1.__ILA_proc_valid__");
  VerilogAnalyzerBase::is_reg(tp_);
  VerilogAnalyzerBase::is_io_sig(tp_);
  VerilogAnalyzerBase::is_wire(tp_);
  va.check_hierarchical_name_type("m1.__ILA_proc_decode_of_Add__");

  va.check_hierarchical_name_type("m2.__ILA_proc_decode_of_Add__");
}
#endif

TEST(TestVerilogAnalysis, FnameMeta) {
  VerilogInfo va(VerilogInfo::path_vec_t(),
                 VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                          "/unit-data/vpipe/simple_pipe.v"}),
                 "m1");

  ILA_INFO << "Location of: m1.ex_wb_rd:" << va.name2loc("m1.ex_wb_rd");
  ILA_INFO << "End loc of m1:" << va.get_endmodule_loc("m1");
}

TEST(TestVerilogAnalysis, Include) {
  VerilogInfo va(VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                          "/unit-data/verilog_sample/"}),
                 VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                          "/unit-data/verilog_sample/m1.v"}),
                 "m1");

  ILA_DLOG("TestVerilogAnalysis.Include")
      << "Location of: m1.r1:" << va.name2loc("m1.r1");
  ILA_DLOG("TestVerilogAnalysis.Include")
      << "End loc of m1:" << va.get_endmodule_loc("m1");
}

TEST(TestVerilogAnalysis, RangeAnalysis) {

#define IS_WIDTH(n, w) EXPECT_EQ(va.get_signal("m1." n).get_width(), w)

  { // test 1
    VerilogInfo va(
        VerilogInfo::path_vec_t(
            {std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/verilog_sample/"}),
        VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                 "/unit-data/verilog_sample/range.v"}),
        "m1");

    IS_WIDTH("r1", 8);
    IS_WIDTH("r2", 8);
    IS_WIDTH("r3", 8);
    IS_WIDTH("r4", 8);

    IS_WIDTH("r12", 8);
    IS_WIDTH("r22", 8);
    IS_WIDTH("r32", 8);
    IS_WIDTH("r42", 8);

    IS_WIDTH("r14", 9);
    IS_WIDTH("r24", 7);
    IS_WIDTH("r34", 8);
    IS_WIDTH("r44", 8);

    IS_WIDTH("rm", 2);
    IS_WIDTH("a", 1); // F
    IS_WIDTH("b", 1); // F
    IS_WIDTH("c", 2); // F
    IS_WIDTH("d", 1); // F
  }                   // end of test1
  {                   // test 2
    VerilogInfo va(
        VerilogInfo::path_vec_t(
            {std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/verilog_sample/"}),
        VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                 "/unit-data/verilog_sample/range2.v"}),
        "m1");

    IS_WIDTH("r1", 8);
    IS_WIDTH("r2", 8);
    IS_WIDTH("r3", 8);
    IS_WIDTH("r4", 8);

    IS_WIDTH("r12", 8);
    IS_WIDTH("r22", 8);
    IS_WIDTH("r32", 8);
    IS_WIDTH("r42", 8);

    IS_WIDTH("r14", 9);
    IS_WIDTH("r24", 7);
    IS_WIDTH("r34", 8);
    IS_WIDTH("r44", 8);
  } // end of test2

  { // test 3 -- parameters
    VerilogInfo va(
        VerilogInfo::path_vec_t(
            {std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/verilog_sample/"}),
        VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                 "/unit-data/verilog_sample/range3.v"}),
        "m1");

    IS_WIDTH("r1", 2);
    IS_WIDTH("r2", 6);
  } // end of test3

  { // test 4 -- parameter and instantiation
    VerilogInfo va(
        VerilogInfo::path_vec_t(
            {std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/verilog_sample/"}),
        VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                 "/unit-data/verilog_sample/range4.v"}),
        "m1");

    IS_WIDTH("i1.sig", 2);
    IS_WIDTH("i1.a", 6);
    IS_WIDTH("i2.sig", 10);
    IS_WIDTH("i2.a", 30);
    IS_WIDTH("i3.sig", 5);
    IS_WIDTH("i3.a", 15);
    IS_WIDTH("i4.sig", 2);
    IS_WIDTH("i4.a", 5);
    IS_WIDTH("wn1", 42);
    IS_WIDTH("wn2", 5);
    IS_WIDTH("wn3", 42);
  } // end of test4
}


TEST(TestVerilogAnalysis, RangeAnalysisOverwriteWidth) {

  { // test 1 -- no error overwrite
    VerilogInfo va(
        VerilogInfo::path_vec_t(
            {std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/verilog_sample/"}),
        VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                 "/unit-data/verilog_sample/range4.v"}),
        "m1");

    {
      EXPECT_EQ(va.get_signal("m1.i1.sig").get_width(), 2);

      std::map<std::string,int> width_overwrite_map({{"m1.i1.sig", 5}});
      EXPECT_EQ(va.get_signal("m1.i1.sig", width_overwrite_map).get_width(), 5);

      { // no overwrite case
        VerilogInfo::module_io_vec_t top_io = va.get_top_module_io();
        auto pos = top_io.find("in1");
        EXPECT_TRUE( pos != top_io.end() );
        if (pos != top_io.end()) {
          EXPECT_EQ(pos->second.get_width(), 4);
        }
      }

      { // overwrite case
        std::map<std::string,int> width_overwrite_map2({{"m1.in1", 10}});
        VerilogInfo::module_io_vec_t top_io = va.get_top_module_io(width_overwrite_map2);
        auto pos = top_io.find("in1");
        EXPECT_TRUE( pos != top_io.end() );
        if (pos != top_io.end()) {
          EXPECT_EQ(pos->second.get_width(), 10);
        }
      }
    }
  } // end of test1

  { // test 2 -- error overwrite
    VerilogInfo va(
        VerilogInfo::path_vec_t(
            {std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/verilog_sample/"}),
        VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                 "/unit-data/verilog_sample/range5.v"}),
        "m1");

    {
      EXPECT_EQ(va.get_signal("m1.in1").get_width(), 4);

      std::map<std::string,int> width_overwrite_map({{"m1.in1", 5}});
      EXPECT_EQ(va.get_signal("m1.in1", width_overwrite_map).get_width(), 5);

      { // no overwrite case
        VerilogInfo::module_io_vec_t top_io = va.get_top_module_io();
        auto pos = top_io.find("in1");
        EXPECT_TRUE( pos != top_io.end() );
        if (pos != top_io.end()) {
          EXPECT_EQ(pos->second.get_width(), 4);
        }
      }

      { // overwrite case
        std::map<std::string,int> width_overwrite_map2({{"m1.in1", 10}});
        VerilogInfo::module_io_vec_t top_io = va.get_top_module_io(width_overwrite_map2);
        auto pos = top_io.find("in1");
        EXPECT_TRUE( pos != top_io.end() );
        if (pos != top_io.end()) {
          EXPECT_EQ(pos->second.get_width(), 10);
        }
      }


      std::map<std::string,int> width_overwrite_map3({{"m1.in2", 128}});
      EXPECT_EQ(va.get_signal("m1.in2", width_overwrite_map3).get_width(), 128);


      { // overwrite case
        std::map<std::string,int> width_overwrite_map2({{"m1.in2", 256}});
        VerilogInfo::module_io_vec_t top_io = va.get_top_module_io(width_overwrite_map2);
        auto pos = top_io.find("in2");
        EXPECT_TRUE( pos != top_io.end() );
        if (pos != top_io.end()) {
          EXPECT_EQ(pos->second.get_width(), 256);
        }
      }

    }
  } // end of test2
} 

TEST(TestVerilogAnalysis, AnalyzeName) {
  VerilogInfo va(
      VerilogInfo::path_vec_t(),
      VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                               "/unit-data/verilog_sample/t_ana_insta.v"}),
      "m1");

  { // output wire
    auto tp_ = va.check_hierarchical_name_type("m1.__ILA_proc_valid__");
    EXPECT_EQ(tp_, VerilogInfo::hierarchical_name_type::O_WIRE_w_INTERNAL_DEF);
    EXPECT_FALSE(VerilogAnalyzerBase::is_reg(tp_));
    EXPECT_TRUE(VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_TRUE(VerilogAnalyzerBase::is_wire(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::no_internal_def(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_module(tp_));
  }
  { // output wire
    auto tp_ = va.check_hierarchical_name_type("m1.__ILA_proc_decode_of_Add__");
    EXPECT_EQ(tp_, VerilogInfo::hierarchical_name_type::O_WIRE_w_INTERNAL_DEF);
    EXPECT_FALSE(VerilogAnalyzerBase::is_reg(tp_));
    EXPECT_TRUE(VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_TRUE(VerilogAnalyzerBase::is_wire(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::no_internal_def(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_module(tp_));
  }
  { // output reg
    auto tp_ = va.check_hierarchical_name_type("m1.__COUNTER_start__n3");
    // EXPECT_EQ( tp_ ,
    // VerilogInfo::hierarchical_name_type::O_REG_w_INTERNAL_DEF);
    EXPECT_EQ(tp_, VerilogInfo::hierarchical_name_type::O_REG_wo_INTERNAL_DEF);
    EXPECT_TRUE(VerilogAnalyzerBase::is_reg(tp_));
    EXPECT_TRUE(VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_wire(tp_));
    EXPECT_TRUE(VerilogAnalyzerBase::no_internal_def(
        tp_)); // warning : this is no internal def!! because it only has a
               // output reg
    EXPECT_FALSE(VerilogAnalyzerBase::is_module(tp_));
  }
  { // input wire
    auto tp_ = va.check_hierarchical_name_type("m1.clk");
    EXPECT_EQ(tp_, VerilogInfo::hierarchical_name_type::I_WIRE_w_INTERNAL_DEF);
    EXPECT_FALSE(VerilogAnalyzerBase::is_reg(tp_));
    EXPECT_TRUE(VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_TRUE(VerilogAnalyzerBase::is_wire(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::no_internal_def(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_module(tp_));
  }
  { // internal reg
    auto tp_ = va.check_hierarchical_name_type("m1.mem");
    EXPECT_EQ(tp_, VerilogInfo::hierarchical_name_type::REG);
    EXPECT_TRUE(VerilogAnalyzerBase::is_reg(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_wire(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::no_internal_def(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_module(tp_));
  }
  { // module
    auto tp_ = va.check_hierarchical_name_type("m1");
    EXPECT_EQ(tp_, VerilogInfo::hierarchical_name_type::MODULE);
    EXPECT_FALSE(VerilogAnalyzerBase::is_reg(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_wire(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::no_internal_def(tp_));
    EXPECT_TRUE(VerilogAnalyzerBase::is_module(tp_));
  }
  { // Internal wire
    auto tp_ = va.check_hierarchical_name_type("m1.n28");
    EXPECT_EQ(tp_, VerilogInfo::hierarchical_name_type::WIRE);
    EXPECT_FALSE(VerilogAnalyzerBase::is_reg(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_TRUE(VerilogAnalyzerBase::is_wire(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::no_internal_def(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_module(tp_));
  }
  { // Not existing
    auto tp_ = va.check_hierarchical_name_type("m1.r5");
    EXPECT_EQ(tp_, VerilogInfo::hierarchical_name_type::NONE);
    EXPECT_FALSE(VerilogAnalyzerBase::is_reg(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_wire(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::no_internal_def(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_module(tp_));
  }

  {
    EXPECT_TRUE(va.find_declaration_of_name("m1.__ILA_proc_decode_of_Add__") !=
                NULL);
#ifdef TEST_BAD_STATE
    EXPECT_TRUE(va.find_declaration_of_name("m2.__ILA_proc_decode_of_Add__") ==
                NULL);
#endif
    EXPECT_TRUE(va.find_declaration_of_name("m1.clk") != NULL);
    EXPECT_TRUE(va.find_declaration_of_name("m1.pc") != NULL);
#ifdef TEST_BAD_STATE
    EXPECT_TRUE(va.find_declaration_of_name("m1.r10") == NULL);
#endif
  }
  {
    EXPECT_TRUE(va.find_declaration_of_name("m1.__ILA_proc_decode_of_Add__") !=
                NULL);
#ifdef TEST_BAD_STATE
    EXPECT_TRUE(va.find_declaration_of_name("m2.__ILA_proc_decode_of_Add__") ==
                NULL);
#endif
    EXPECT_TRUE(va.find_declaration_of_name("m1.clk") != NULL);
    EXPECT_TRUE(va.find_declaration_of_name("m1.pc") != NULL);
#ifdef TEST_BAD_STATE
    EXPECT_TRUE(va.find_declaration_of_name("m1.r10") == NULL);
#endif
  }

  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")
      << "Location of: m1    :" << va.name2loc("m1");
  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")
      << "Location of: m1.clk:" << va.name2loc("m1.clk");
  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")
      << "Location of: m1.pc :" << va.name2loc("m1.pc");
  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")
      << "Location of: m1.mem:" << va.name2loc("m1.mem");
  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")
      << "Location of: m1.n26:" << va.name2loc("m1.n26");
  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")
      << "Location of: m1.subm1:" << va.name2loc("m1.subm1");
  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")
      << "Location of: m1.subm2:" << va.name2loc("m1.subm2");
  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")
      << "Inst loc of m1.subm1:" << va.get_module_inst_loc("m1.subm1");
  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")
      << "Inst loc of m1.subm2:" << va.get_module_inst_loc("m1.subm2");
  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")
      << "Inst loc of m1.subm3:" << va.get_module_inst_loc("m1.subm3");
  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")
      << "Inst loc of m1.subm4:" << va.get_module_inst_loc("m1.subm4");

  va.get_module_inst_loc("m1.subm1");
}

TEST(TestVerilogAnalysis, GetTopIo) {

  VerilogInfo va(
      VerilogInfo::path_vec_t(),
      VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                               "/unit-data/verilog_sample/t_ana_ila.v"}),
      "m1");
  ILA_DLOG("TestVerilogAnalysis.GetTopIo")
      << "Top module name:" << va.get_top_module_name();
  VerilogInfo::module_io_vec_t top_io = va.get_top_module_io();

  EXPECT_TRUE(IN("clk", top_io));
  EXPECT_TRUE(IN("rst", top_io));
  EXPECT_TRUE(IN("__ILA_proc_grant__", top_io));
  EXPECT_TRUE(IN("__ILA_proc_valid__", top_io));
  EXPECT_TRUE(IN("__ILA_proc_acc_decode__", top_io));
  EXPECT_TRUE(IN("__ILA_proc_decode_of_Load__", top_io));
  EXPECT_TRUE(IN("__ILA_proc_decode_of_Add__", top_io));
  EXPECT_TRUE(IN("__ILA_proc_decode_of_Store__", top_io));
  EXPECT_TRUE(IN("pc", top_io));
  EXPECT_TRUE(IN("r0", top_io));
  EXPECT_TRUE(IN("r1", top_io));
  EXPECT_TRUE(IN("r2", top_io));
  EXPECT_TRUE(IN("r3", top_io));
  EXPECT_TRUE(IN("nouse", top_io));
  EXPECT_FALSE(IN("mem", top_io));
  EXPECT_FALSE(IN("n11", top_io));
  EXPECT_FALSE(IN("n10", top_io));

#define EXPECT_IO_SIGNAL(mdname, name, width, isinput, isreg)                  \
  {                                                                            \
    auto pos = top_io.find(name);                                              \
    EXPECT_FALSE(pos == top_io.end());                                         \
    auto signal = pos->second;                                                 \
    EXPECT_EQ(signal.get_signal_name(), name);                                 \
    EXPECT_EQ(signal.get_hierarchical_name(), mdname "." name);                \
    EXPECT_EQ(signal.get_width(), width);                                      \
    EXPECT_EQ(signal.is_io_sig(), true);                                       \
    EXPECT_EQ(signal.is_reg(), isreg);                                         \
    EXPECT_EQ(VerilogAnalyzerBase::is_input(signal.get_type()), isinput);      \
  }

#define I true
#define O false
#define R true
#define W false

  EXPECT_IO_SIGNAL("m1", "clk", 1, I, W);
  EXPECT_IO_SIGNAL("m1", "rst", 1, I, W);
  EXPECT_IO_SIGNAL("m1", "__ILA_proc_grant__", 3, I, W);
  EXPECT_IO_SIGNAL("m1", "__ILA_proc_valid__", 1, O, W);
  EXPECT_IO_SIGNAL("m1", "__ILA_proc_acc_decode__", 3, O, W);
  EXPECT_IO_SIGNAL("m1", "__ILA_proc_decode_of_Add__", 1, O, W);
  EXPECT_IO_SIGNAL("m1", "__ILA_proc_decode_of_Load__", 1, O, W);
  EXPECT_IO_SIGNAL("m1", "__ILA_proc_decode_of_Store__", 1, O, W);

  EXPECT_IO_SIGNAL("m1", "pc", 8, O, R);
  EXPECT_IO_SIGNAL("m1", "r0", 8, O, R);
  EXPECT_IO_SIGNAL("m1", "r1", 8, O, R);
  EXPECT_IO_SIGNAL("m1", "r2", 8, O, R);
  EXPECT_IO_SIGNAL("m1", "r3", 8, O, R);
  EXPECT_IO_SIGNAL("m1", "nouse", 1, O, R);

#undef I
#undef O
#undef R
#undef W
}

TEST(TestVerilogAnalysis, GetTopIoNewFashion) {

  /* not generating
  auto ila_ptr_ = SimpleCpu("proc");
  ila_ptr_->NewBoolState("nouse");
  // test 1 gen Add : internal mem
  {
    auto vgen = VerilogGenerator();
    vgen.ExportIla(ila_ptr_);
    write_to_file( "test/unit-data/verilog_sample/t_ana_ila.v" , vgen);
  }
  */

  VerilogInfo va(
      VerilogInfo::path_vec_t(),
      VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                               "/unit-data/verilog_sample/t_pipe.v"}),
      "m1");
  ILA_DLOG("TestVerilogAnalysis.GetTopIoNewFashion")
      << "Top module name:" << va.get_top_module_name();
  VerilogInfo::module_io_vec_t top_io = va.get_top_module_io();

  EXPECT_TRUE(IN("clk", top_io));
  EXPECT_TRUE(IN("rst", top_io));
  EXPECT_TRUE(IN("inst", top_io));
  EXPECT_TRUE(IN("dummy_read_rf", top_io));
  EXPECT_TRUE(IN("dummy_rf_data", top_io));

#define EXPECT_IO_SIGNAL(mdname, name, width, isinput, isreg)                  \
  {                                                                            \
    auto pos = top_io.find(name);                                              \
    EXPECT_FALSE(pos == top_io.end());                                         \
    auto signal = pos->second;                                                 \
    EXPECT_EQ(signal.get_signal_name(), name);                                 \
    EXPECT_EQ(signal.get_hierarchical_name(), mdname "." name);                \
    EXPECT_EQ(signal.get_width(), width);                                      \
    EXPECT_EQ(signal.is_io_sig(), true);                                       \
    EXPECT_EQ(signal.is_reg(), isreg);                                         \
    EXPECT_EQ(VerilogAnalyzerBase::is_input(signal.get_type()), isinput);      \
  }

#define I true
#define O false
#define R true
#define W false

  EXPECT_IO_SIGNAL("m1", "clk", 1, I, W);
  EXPECT_IO_SIGNAL("m1", "rst", 1, I, W);
  EXPECT_IO_SIGNAL("m1", "inst", 8, I, W);
  EXPECT_IO_SIGNAL("m1", "dummy_read_rf", 2, I, W);
  EXPECT_IO_SIGNAL("m1", "dummy_rf_data", 8, O, W);

#undef I
#undef O
#undef R
#undef W
  ILA_INFO << "End loc of m1:" << va.get_endmodule_loc("m1");
}

}; // namespace ilang
