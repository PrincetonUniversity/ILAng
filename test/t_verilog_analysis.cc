/// \file
/// Unit test for Verilog analyzer.
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <ilang/verification/abs_knob.h>
#include <ilang/verilog-in/verilog_analysis_wrapper.h>
#include <ilang/verilog-out/verilog_gen.h>
#include <ilang/util/container_shortcut.h>

#include "unit-include/eq_ilas.h"
#include "unit-include/simple_cpu.h"
#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

#ifdef VERILOG_IN_ENABLE


TEST(TestVerilogAnalysis, Init) {

  /*
  auto ila_ptr_ = SimpleCpu("proc");
  // test 1 gen Add : internal mem
  {
    auto vgen = VerilogGenerator();
    vgen.ExportTopLevelInstr(ila_ptr_->instr("Add"));
    write_to_file( "test/unit-data/verilog_sample/t_ana_inst.v" , vgen);
  }
  */

  VerilogInfo va ( VerilogInfo::path_vec_t() , VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/verilog_sample/t_ana_inst.v"}) , "m1");
}

#ifdef TEST_BAD_STATE
TEST(TestVerilogAnalysis, BadState) {
  VerilogInfo va ( VerilogInfo::path_vec_t() , VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/verilog_sample/t_ana-nonexisting.v"}) , "m1");
  // The above will make it into bad state
  // but it should not affect other things

  auto tp_ = va.check_hierarchical_name_type("m1.__ILA_proc_valid__");
  VerilogAnalyzerBase::is_reg   (tp_);
  VerilogAnalyzerBase::is_io_sig(tp_);
  VerilogAnalyzerBase::is_wire  (tp_);
  va.check_hierarchical_name_type("m1.__ILA_proc_decode_of_Add__");

  va.check_hierarchical_name_type("m2.__ILA_proc_decode_of_Add__");
}
#endif

TEST(TestVerilogAnalysis, AnalyzeName) {

  /*
  auto ila_ptr_ = SimpleCpu("proc");
  ila_ptr_->NewBoolState("nouse");
  // test 1 gen Add : internal mem
  {
    auto vgen = VerilogGenerator();
    vgen.ExportTopLevelInstr(ila_ptr_->instr("Add"));
    write_to_file( "test/unit-data/verilog_sample/t_ana_insta.v" , vgen);
  }
  */

  VerilogInfo va ( VerilogInfo::path_vec_t() , VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/verilog_sample/t_ana_insta.v"}) , "m1");

  { // output wire
    auto tp_ = va.check_hierarchical_name_type("m1.__ILA_proc_valid__");
    EXPECT_EQ( tp_ , VerilogInfo::hierarchical_name_type::O_WIRE_w_INTERNAL_DEF);
    EXPECT_FALSE(VerilogAnalyzerBase::is_reg   (tp_));
    EXPECT_TRUE (VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_TRUE (VerilogAnalyzerBase::is_wire  (tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::no_internal_def(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_module(tp_));
  }
  {  // output wire
    auto tp_ = va.check_hierarchical_name_type("m1.__ILA_proc_decode_of_Add__");
    EXPECT_EQ( tp_ , VerilogInfo::hierarchical_name_type::O_WIRE_w_INTERNAL_DEF);
    EXPECT_FALSE(VerilogAnalyzerBase::is_reg   (tp_));
    EXPECT_TRUE (VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_TRUE (VerilogAnalyzerBase::is_wire  (tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::no_internal_def(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_module(tp_));
  }
  { // output reg
    auto tp_ = va.check_hierarchical_name_type("m1.__COUNTER_start__n3");
    //EXPECT_EQ( tp_ , VerilogInfo::hierarchical_name_type::O_REG_w_INTERNAL_DEF);
    EXPECT_EQ( tp_ , VerilogInfo::hierarchical_name_type::O_REG_wo_INTERNAL_DEF);
    EXPECT_TRUE (VerilogAnalyzerBase::is_reg   (tp_));
    EXPECT_TRUE (VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_wire  (tp_));
    EXPECT_TRUE (VerilogAnalyzerBase::no_internal_def(tp_)); // warning : this is no internal def!! because it only has a output reg
    EXPECT_FALSE(VerilogAnalyzerBase::is_module(tp_));
  }
  { // input wire
    auto tp_ = va.check_hierarchical_name_type("m1.clk");
    EXPECT_EQ( tp_ , VerilogInfo::hierarchical_name_type::I_WIRE_w_INTERNAL_DEF);
    EXPECT_FALSE(VerilogAnalyzerBase::is_reg   (tp_));
    EXPECT_TRUE (VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_TRUE (VerilogAnalyzerBase::is_wire  (tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::no_internal_def(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_module(tp_));
  }
  { // internal reg
    auto tp_ = va.check_hierarchical_name_type("m1.mem");
    EXPECT_EQ( tp_ , VerilogInfo::hierarchical_name_type::REG);
    EXPECT_TRUE (VerilogAnalyzerBase::is_reg   (tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_wire  (tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::no_internal_def(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_module(tp_));
  }
  { // module
    auto tp_ = va.check_hierarchical_name_type("m1");
    EXPECT_EQ( tp_ , VerilogInfo::hierarchical_name_type::MODULE);
    EXPECT_FALSE(VerilogAnalyzerBase::is_reg   (tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_wire  (tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::no_internal_def(tp_));
    EXPECT_TRUE (VerilogAnalyzerBase::is_module(tp_));
  }
  { // Internal wire
    auto tp_ = va.check_hierarchical_name_type("m1.n28");
    EXPECT_EQ( tp_ , VerilogInfo::hierarchical_name_type::WIRE);
    EXPECT_FALSE(VerilogAnalyzerBase::is_reg   (tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_TRUE (VerilogAnalyzerBase::is_wire  (tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::no_internal_def(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_module(tp_));
  }
  { // Not existing
    auto tp_ = va.check_hierarchical_name_type("m1.r5");
    EXPECT_EQ( tp_ , VerilogInfo::hierarchical_name_type::NONE);
    EXPECT_FALSE(VerilogAnalyzerBase::is_reg   (tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_io_sig(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_wire  (tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::no_internal_def(tp_));
    EXPECT_FALSE(VerilogAnalyzerBase::is_module(tp_));
  }

  { 
      EXPECT_TRUE( va.find_declaration_of_name("m1.__ILA_proc_decode_of_Add__") != NULL);
#ifdef TEST_BAD_STATE
      EXPECT_TRUE( va.find_declaration_of_name("m2.__ILA_proc_decode_of_Add__") == NULL);
#endif
      EXPECT_TRUE( va.find_declaration_of_name("m1.clk")                        != NULL);
      EXPECT_TRUE( va.find_declaration_of_name("m1.pc")                         != NULL);
#ifdef TEST_BAD_STATE
      EXPECT_TRUE( va.find_declaration_of_name("m1.r10")                        == NULL);
#endif
  }  
  {
      EXPECT_TRUE( va.find_declaration_of_name("m1.__ILA_proc_decode_of_Add__") != NULL);
#ifdef TEST_BAD_STATE
      EXPECT_TRUE( va.find_declaration_of_name("m2.__ILA_proc_decode_of_Add__") == NULL);
#endif
      EXPECT_TRUE( va.find_declaration_of_name("m1.clk")                        != NULL);
      EXPECT_TRUE( va.find_declaration_of_name("m1.pc")                         != NULL);
#ifdef TEST_BAD_STATE
      EXPECT_TRUE( va.find_declaration_of_name("m1.r10")                        == NULL);
#endif
  }  

  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")<<"Location of: m1    :" <<va.name2loc("m1");
  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")<<"Location of: m1.clk:" <<va.name2loc("m1.clk");
  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")<<"Location of: m1.pc :" <<va.name2loc("m1.pc");
  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")<<"Location of: m1.mem:" <<va.name2loc("m1.mem");
  ILA_DLOG("TestVerilogAnalysis.AnalyzeName")<<"Location of: m1.n26:" <<va.name2loc("m1.n26");

}


TEST(TestVerilogAnalysis, GetTopIo) {

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

  VerilogInfo va ( VerilogInfo::path_vec_t() , VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/verilog_sample/t_ana_ila.v"}) , "m1");
  ILA_DLOG("TestVerilogAnalysis.GetTopIo") << "Top module name:" << va.get_top_module_name();
  VerilogInfo::module_io_vec_t top_io = va.get_top_module_io();

  EXPECT_TRUE ( IN( "clk" , top_io) );
  EXPECT_TRUE ( IN( "rst" , top_io) );
  EXPECT_TRUE ( IN( "__ILA_proc_grant__" , top_io) );
  EXPECT_TRUE ( IN( "__ILA_proc_valid__" , top_io) );
  EXPECT_TRUE ( IN( "__ILA_proc_acc_decode__" , top_io) );
  EXPECT_TRUE ( IN( "__ILA_proc_decode_of_Load__" , top_io) );
  EXPECT_TRUE ( IN( "__ILA_proc_decode_of_Add__" , top_io) );
  EXPECT_TRUE ( IN( "__ILA_proc_decode_of_Store__" , top_io) );
  EXPECT_TRUE ( IN( "pc" , top_io) );
  EXPECT_TRUE ( IN( "r0" , top_io) );
  EXPECT_TRUE ( IN( "r1" , top_io) );
  EXPECT_TRUE ( IN( "r2" , top_io) );
  EXPECT_TRUE ( IN( "r3" , top_io) );
  EXPECT_TRUE ( IN( "nouse" , top_io) );
  EXPECT_FALSE( IN( "mem" , top_io) );
  EXPECT_FALSE( IN( "n11" , top_io) );
  EXPECT_FALSE( IN( "n10" , top_io) );

  #define EXPECT_IO_SIGNAL(mdname,name,width,isinput,isreg) { \
    auto pos = top_io.find(name); EXPECT_FALSE(pos == top_io.end()); \
    auto signal = pos->second; \
    EXPECT_EQ(signal.get_signal_name() , name );  \
    EXPECT_EQ(signal.get_hierarchical_name() , mdname "." name );  \
    EXPECT_EQ(signal.get_width() , width );  \
    EXPECT_EQ(signal.is_io_sig() , true  );  \
    EXPECT_EQ(signal.is_reg()    , isreg ); \
    EXPECT_EQ(VerilogAnalyzerBase::is_input(signal.get_type()) , isinput  );  }

#define I true
#define O false
#define R true
#define W false

  EXPECT_IO_SIGNAL("m1","clk",1,I,W);
  EXPECT_IO_SIGNAL("m1","rst",1,I,W);
  EXPECT_IO_SIGNAL("m1","__ILA_proc_grant__",          3,I,W);
  EXPECT_IO_SIGNAL("m1","__ILA_proc_valid__",          1,O,W);
  EXPECT_IO_SIGNAL("m1","__ILA_proc_acc_decode__",     3,O,W);
  EXPECT_IO_SIGNAL("m1","__ILA_proc_decode_of_Add__",  1,O,W);
  EXPECT_IO_SIGNAL("m1","__ILA_proc_decode_of_Load__", 1,O,W);
  EXPECT_IO_SIGNAL("m1","__ILA_proc_decode_of_Store__",1,O,W);

  EXPECT_IO_SIGNAL("m1","pc",   8,O,R);
  EXPECT_IO_SIGNAL("m1","r0",   8,O,R);
  EXPECT_IO_SIGNAL("m1","r1",   8,O,R);
  EXPECT_IO_SIGNAL("m1","r2",   8,O,R);
  EXPECT_IO_SIGNAL("m1","r3",   8,O,R);
  EXPECT_IO_SIGNAL("m1","nouse",1,O,R);

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

  VerilogInfo va ( VerilogInfo::path_vec_t() , VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/verilog_sample/t_pipe.v"}) , "m1");
  ILA_DLOG("TestVerilogAnalysis.GetTopIoNewFashion") << "Top module name:" << va.get_top_module_name();
  VerilogInfo::module_io_vec_t top_io = va.get_top_module_io();

  EXPECT_TRUE ( IN( "clk" , top_io) );
  EXPECT_TRUE ( IN( "rst" , top_io) );
  EXPECT_TRUE ( IN( "inst" , top_io) );
  EXPECT_TRUE ( IN( "dummy_read_rf" , top_io) );
  EXPECT_TRUE ( IN( "dummy_rf_data" , top_io) );

  #define EXPECT_IO_SIGNAL(mdname,name,width,isinput,isreg) { \
    auto pos = top_io.find(name); EXPECT_FALSE(pos == top_io.end()); \
    auto signal = pos->second; \
    EXPECT_EQ(signal.get_signal_name() , name );  \
    EXPECT_EQ(signal.get_hierarchical_name() , mdname "." name );  \
    EXPECT_EQ(signal.get_width() , width );  \
    EXPECT_EQ(signal.is_io_sig() , true  );  \
    EXPECT_EQ(signal.is_reg()    , isreg ); \
    EXPECT_EQ(VerilogAnalyzerBase::is_input(signal.get_type()) , isinput  );  }

#define I true
#define O false
#define R true
#define W false

  EXPECT_IO_SIGNAL("m1","clk",           1,I,W);
  EXPECT_IO_SIGNAL("m1","rst",           1,I,W);
  EXPECT_IO_SIGNAL("m1","inst",          8,I,W);
  EXPECT_IO_SIGNAL("m1","dummy_read_rf", 2,I,W);
  EXPECT_IO_SIGNAL("m1","dummy_rf_data", 8,O,W);

#undef I 
#undef O
#undef R
#undef W

}

#endif
};  // namespace ilang
