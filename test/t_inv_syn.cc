/// \file
/// Unit test for generating Verilog verification target

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ilang++.h>
#include <ilang/synth-interface/synth_engine_interface.h>
#include <ilang/vtarget-out/vtarget_gen.h>

#include "unit-include/config.h"
#include "unit-include/pipe_ila.h"
#include "unit-include/memswap.h"
#include "unit-include/util.h"

namespace ilang {


TEST(TestVlgVerifInvSyn, SimpleCnt) {
  auto ila_model = CntTest::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.CosaAddKeep = false;

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/cnt1/";
  VerilogVerificationTargetGenerator vg(
      {},                          // no include
      {dirName + "verilog/opposite.v"}, //
      "opposite",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", dirName + "out/", ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::YOSYS,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();

}


TEST(TestVlgVerifInvSyn, SimpleCntDeterministicReset) {
  auto ila_model = CntTest::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.CosaAddKeep = false;

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/cnt2/";
  VerilogVerificationTargetGenerator vg(
      {},                          // no include
      {dirName + "verilog/opposite.v"}, //
      "opposite",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", dirName + "out/", ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::YOSYS,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();

}



TEST(TestVlgVerifInvSyn, DirectStart) {
  auto ila_model = CntTest::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/cnt3/";
  VerilogVerificationTargetGenerator vg(
      {},                          // no include
      {dirName + "verilog/opposite.v"}, //
      "opposite",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", dirName + "out/", ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::YOSYS,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();

}

TEST(TestVlgVerifInvSyn, PipeExampleYosys) {
  auto ila_model = SimplePipe::BuildModel();

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/";
  VerilogVerificationTargetGenerator vg(
      {},                          // no include
      {dirName + "simple_pipe.v"}, //
      "pipeline_v",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", dirName + "inv-syn/", ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::YOSYS);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();

}

}; // namespace ilang
