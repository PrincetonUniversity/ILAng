/// \file
/// Unit test for generating Verilog verification target

#include <ilang/util/fs.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ilang++.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/inv-syn/inv_syn_cegar.h>

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

TEST(TestVlgVerifInvSyn, PipeExample) {
  auto ila_model = SimplePipe::BuildModel();

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/vpipe-out1/";
  VerilogVerificationTargetGenerator vg(
      {},                          // no include
      {dirName + "simple_pipe.v"}, //
      "pipeline_v",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::YOSYS);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();

}

// This tests uses no extract start cycle
TEST(TestVlgVerifInvSyn, PipeExampleDirect) {
  auto ila_model = SimplePipe::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/vpipe-out2/";

  VerilogVerificationTargetGenerator vg(
      {},                          // no include
      {dirName + "simple_pipe.v"}, //
      "pipeline_v",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::YOSYS,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();

}


// This tests has no extra start cycle
// This test works on wrong implementation
TEST(TestVlgVerifInvSyn, PipeExampleCex) {
  auto ila_model = SimplePipe::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = false;

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/vpipe-out3-cex/";

  VerilogVerificationTargetGenerator vg(
      {},                          // no include
      {dirName + "simple_pipe_wrong.v"}, //
      "pipeline_v",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::YOSYS,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();

}

// This test uses CEGAR loop
// This tests has no extra start cycle
TEST(TestVlgVerifInvSyn, CegarPipelineExample) {
  auto ila_model = SimplePipe::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false;
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.CosaPyEnvironment = "/home/hongce/cosaEnv/bin/activate";
  cfg.CosaPath = "/home/hongce/CoSA/";
  cfg.Z3Path = "/home/hongce/z3s/bin/";

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/vpipe-out4/";

  InvariantSynthesizerCegar vg(
      {},                          // no include
      {dirName + "simple_pipe.v"}, //
      "pipeline_v",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::Z3,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

    do{
      vg.GenerateVerificationTarget();
      if(vg.RunVerifAuto(1)) // the ADD
        break; // no more cex found
      vg.ExtractVerificationResult();
      vg.GenerateSynthesisTarget();
      if(vg.RunSynAuto()) {
        EXPECT_TRUE(false); // cex is really reachable!!!
        ILA_ERROR<<"Unexpected counterexample!";
        break; 
      }
      vg.ExtractSynthesisResult();
    }while(not vg.in_bad_state());
}



}; // namespace ilang
