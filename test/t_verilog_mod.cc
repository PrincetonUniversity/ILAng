/// \file
/// Unit test for Verilog analyzer.
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include <ilang/ila-mngr/u_abs_knob.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/verilog-in/verilog_analysis_wrapper.h>
#include <ilang/verilog-out/verilog_gen.h>
#include <ilang/vtarget-out/vlg_mod.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

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

  std::string fn = os_portable_join_dir(
      {ILANG_TEST_SRC_ROOT, "unit-data", "verilog_sample", "t_ana_insta.v"});
  auto ofn = GetRandomFileName(fs::temp_directory_path());

  VerilogInfo va(VerilogInfo::path_vec_t(), VerilogInfo::path_vec_t({fn}),
                 "m1");

  VerilogModifier vm(&va, VerilogModifier::port_decl_style_t::AUTO, true, {});

  vm.RecordKeepSignalName("m1.__COUNTER_start__n3");
  vm.RecordKeepSignalName("m1.__ILA_proc_decode_of_Add__");
  vm.RecordKeepSignalName("m1.subm4.a");
  vm.RecordConnectSigName("m1.subm4.b");
  vm.RecordConnectSigName("m1.n27");
  vm.RecordConnectSigName("m1.ir");
  vm.RecordAdditionalVlgModuleStmt("wire abcd; assign abcd = 1'b1;", "m1");
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

  fin.close();
  fout.close();
  os_portable_remove_file(ofn);
}

}; // namespace ilang
