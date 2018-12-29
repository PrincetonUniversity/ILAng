/// \file
/// Unit test for Verilog parser.
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <ilang/verification/abs_knob.h>
#include <ilang/verilog-in/verilog_parse.h>
#include <ilang/verilog-out/verilog_gen.h>

#include "unit-include/eq_ilas.h"
#include "unit-include/simple_cpu.h"
#include "unit-include/util.h"

namespace ilang {

void parseable(const std::string& fname, VerilogGenerator& vgen) {
  std::ofstream fout(fname);
  if (fout.is_open()) {
    vgen.DumpToFile(fout);
    fout.close();
  } else
    ILA_WARN << "Cannot write tmpfile:" << fname << " for vlog-gen test.";

  std::FILE* fp = std::fopen(fname.c_str(), "r");
  if (fp) {
    int result = TestParseVerilogFrom(fp);
    std::fclose(fp);
    EXPECT_EQ(result, 0);
    if (result != 0)
      ILA_INFO << "ParseErrorFileName = " << fname;
  } else
    ILA_WARN << "Cannot read tmpfile:" << fname << " for vlog-gen test.";
}

TEST(TestVerilogGen, Init) { VerilogGenerator(); }
TEST(TestVerilogGen, ParseInst) {
  auto ila_ptr_ = SimpleCpu("proc");
  // test 1 gen Add : internal mem
  {
    auto vgen = VerilogGenerator();

    // DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
    vgen.ExportTopLevelInstr(ila_ptr_->instr("Add"));

    parseable("Testing/Temporary/t_proc_Add.v", vgen);
  }
  // test 2 gen Add : external mem
  {
    auto config = VerilogGenerator::VlgGenConfig(
        true, VerilogGenerator::VlgGenConfig::funcOption::Internal);
    auto vgen = VerilogGenerator(config);

    // DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
    vgen.ExportTopLevelInstr(ila_ptr_->instr("Add"));

    parseable("Testing/Temporary/t_proc_Add_extmem.v", vgen);
  }
  // test 3 gen Load : internal mem
  {
    auto vgen = VerilogGenerator();
    // DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
    vgen.ExportTopLevelInstr(ila_ptr_->instr("Load"));
    parseable("Testing/Temporary/t_proc_Load.v", vgen);
  }
  // test 4 gen Store : internal mem
  {
    auto vgen = VerilogGenerator();
    // DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
    vgen.ExportTopLevelInstr(ila_ptr_->instr("Store"));
    parseable("Testing/Temporary/t_proc_Store.v", vgen);
  }
  // test 5 gen Load : external mem
  {
    auto config = VerilogGenerator::VlgGenConfig(
        true, VerilogGenerator::VlgGenConfig::funcOption::Internal);
    auto vgen = VerilogGenerator(config);
    // DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
    vgen.ExportTopLevelInstr(ila_ptr_->instr("Load"));
    parseable("Testing/Temporary/t_proc_Load_extmem.v", vgen);
  }
  // test 6 gen Store : external mem
  {
    auto config = VerilogGenerator::VlgGenConfig(
        true, VerilogGenerator::VlgGenConfig::funcOption::Internal);
    auto vgen = VerilogGenerator(config);
    // DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
    vgen.ExportTopLevelInstr(ila_ptr_->instr("Store"));
    parseable("Testing/Temporary/t_proc_Store_extmem.v", vgen);
  }
} // TEST (ParseInst)

TEST(TestVerilogGen, ParseIla) {
  auto ila_ptr_ = SimpleCpu("proc");
  // test 1 gen all : internal mem
  {
    auto vgen = VerilogGenerator();
    vgen.ExportIla(ila_ptr_);
    parseable("Testing/Temporary/t_proc_all.v", vgen);
  }
  // test 2 gen all : external mem
  {
    auto config = VerilogGenerator::VlgGenConfig(
        true, VerilogGenerator::VlgGenConfig::funcOption::Internal);
    auto vgen = VerilogGenerator(config);
    vgen.ExportIla(ila_ptr_);
    parseable("Testing/Temporary/t_proc_all_extmem.v", vgen);
  }
} // TEST: ParseILA
TEST(TestVerilogGen, FlattenIla) {
  EqIlaGen ila_gen;
  auto ila_ptr = ila_gen.GetIlaHier1("CpReg");

  auto dep_ila_ptr =
      AbsKnob::ExtrDeptModl(ila_ptr->instr("instr1"), "FlattenCpReg");
  AbsKnob::FlattenIla(dep_ila_ptr);

  auto vgen = VerilogGenerator();
  vgen.ExportIla(dep_ila_ptr);

  parseable("Testing/Temporary/t_proc_flatten.v", vgen);

} // TEST: FlattenILA

}; // namespace ilang
