/// \file
/// Unit test for Verilog analyzer.
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include <ilang/util/container_shortcut.h>
#include <ilang/verification/abs_knob.h>
#include <ilang/verilog-in/verilog_analysis_wrapper.h>
#include <ilang/verilog-out/verilog_gen.h>
#include <ilang/vtarget-out/vlg_mod.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

#ifdef VERILOG_IN_ENABLE

TEST(TestVerilogMod, Modify) {

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

  std::string fn = std::string(ILANG_TEST_SRC_ROOT) +
                   "/unit-data/verilog_sample/t_ana_insta.v";
  std::string ofn = std::string(ILANG_TEST_SRC_ROOT) +
                    "/unit-data/verilog_sample/t_ana_insta_mod.v";

  VerilogInfo va(VerilogInfo::path_vec_t(), VerilogInfo::path_vec_t({fn}),
                 "m1");

  VerilogModifier vm(&va);

  vm.RecordKeepSignalName("m1.__COUNTER_start__n3");
  vm.RecordKeepSignalName("m1.__ILA_proc_decode_of_Add__");
  vm.RecordKeepSignalName("m1.subm4.a");
  vm.RecordConnectSigName("m1.subm4.b");
  vm.RecordConnectSigName("m1.n27");
  vm.RecordConnectSigName("m1.ir");
  vm.FinishRecording();

  std::ifstream fin(fn);
  std::ofstream fout(ofn);

  if (!fin.is_open()) {
    ILA_ERROR << fn << " is not readable";
    return;
  }

  if (!fout.is_open()) {
    ILA_ERROR << ofn << " is not readable";
    return;
  }

  vm.ReadModifyWrite(fn, fin, fout);
}

#endif // VERILOG_IN_ENABLE
};     // namespace ilang
