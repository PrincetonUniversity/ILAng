/// \file
/// Unit test for invariant synthesis

#include <ilang/util/fs.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ilang++.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/inv-syn/inv_syn_cegar.h>
#include <ilang/vtarget-out/inv-syn/sygus/sim_trace_extract.h>

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


// This test uses CEGAR loop
// This tests has no extra start cycle
TEST(TestVlgVerifInvSyn, SimpleCntCegar) {
  auto ila_model = CntTest::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = true; // let's test flatten datatype also
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.CosaPyEnvironment = "/home/hongce/cosaEnv/bin/activate";
  cfg.CosaPath = "/home/hongce/CoSA/";
  cfg.Z3Path = "/home/hongce/z3s/bin/";
  cfg.CosaSolver = "btor";

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/cnt2/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/cnt2-cegar/";

  InvariantSynthesizerCegar vg(
      {},                          // no include
      {dirName + "verilog/opposite.v"}, //
      "opposite",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::Z3,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

    do{
      vg.GenerateVerificationTarget();
      if(vg.RunVerifAuto("INC")) // the ADD
        break; // no more cex found
      vg.ExtractVerificationResult();
      vg.GenerateSynthesisTarget(); // you will need fp engine
      if(vg.RunSynAuto()) {
        EXPECT_TRUE(false); // cex is really reachable!!!
        ILA_ERROR<<"Unexpected counterexample!";
        break; 
      }
      vg.ExtractSynthesisResult(); // very weired, it throw away something in arg
      break; // just one round
    }while(not vg.in_bad_state());

  vg.GenerateInvariantVerificationTarget();
  auto design_stat = vg.GetDesignStatistics();
  ILA_INFO << "========== Design Info ==========" ;
  ILA_INFO << "#bits= " << design_stat.NumOfDesignStateBits;
  ILA_INFO << "#vars=" << design_stat.NumOfDesignStateVars;
  ILA_INFO << "#extra_bits= " << design_stat.NumOfExtraStateBits;
  ILA_INFO << "#extra_vars=" << design_stat.NumOfExtraStateVars;
} // CegarPipelineExample


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
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false;
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.CosaPyEnvironment = "/home/hongce/cosaEnv/bin/activate";
  cfg.CosaPath = "/home/hongce/CoSA/";
  cfg.Z3Path = "/home/hongce/z3s/bin/";
  cfg.CosaSolver = "btor";

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
      if(vg.RunVerifAuto("ADD")) // the ADD
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

  vg.GenerateInvariantVerificationTarget();
  auto design_stat = vg.GetDesignStatistics();
  ILA_INFO << "========== Design Info ==========" ;
  ILA_INFO << "#bits= " << design_stat.NumOfDesignStateBits;
  ILA_INFO << "#vars=" << design_stat.NumOfDesignStateVars;
  ILA_INFO << "#extra_bits= " << design_stat.NumOfExtraStateBits;
  ILA_INFO << "#extra_vars=" << design_stat.NumOfExtraStateVars;

  // test invariant import and export also here
  InvariantObject invs(vg.GetInvariants());
  invs.ExportToFile(outDir+"inv_results.txt");
  invs.ClearAllInvariants();
  invs.ImportFromFile(outDir+"inv_results.txt");
  
  // check they are the same
  EXPECT_EQ(
    vg.GetInvariants().NumInvariant(), 
    invs.NumInvariant());
  EXPECT_EQ(
    vg.GetInvariants().GetExtraVarDefs().size(), 
    invs.GetExtraVarDefs().size());
  EXPECT_EQ(
    vg.GetInvariants().GetExtraFreeVarDefs().size(), 
    invs.GetExtraFreeVarDefs().size());

  for (auto pos = invs.GetVlgConstraints().begin(), 
        pos2 = vg.GetInvariants().GetVlgConstraints().begin(); 
      pos != invs.GetVlgConstraints().end();
      ++ pos, ++ pos2  ) {
    EXPECT_EQ(*pos, *pos2);
  }
} // CegarPipelineExample

TEST(TestVlgVerifInvSyn, CegarPipelineExampleSygusDatapoint) {

  auto ila_model = SimplePipe::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false; // if not using transfunc it does not matter
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.CosaPyEnvironment = "/home/hongce/cosaEnv/bin/activate";
  cfg.CosaPath = "/home/hongce/CoSA/";
  cfg.Z3Path = "/home/hongce/z3s/bin/";
  cfg.Cvc4Path = "/home/hongce/cvc-installs/latest/bin/";
  cfg.CosaSolver = "btor";
  cfg.SygusOptions.SygusPassInfo = 
    VerilogVerificationTargetGenerator::vtg_config_t::_sygus_options_t::DataPoints;

  TraceDataPoints dp;
  std::vector<std::string> sygus_var_name = {
    "m1.reg_0_w_stage", "m1.reg_1_w_stage", "m1.reg_2_w_stage", "m1.reg_3_w_stage",
    "m1.id_ex_reg_wen", "m1.id_ex_rd", "m1.ex_wb_reg_wen", "m1.ex_wb_rd" };

  std::set<std::string> sim_var_name;
  for (auto &&n : sygus_var_name)
    sim_var_name.insert("sim." + n);

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/vpipe-out-sygus-dp/";

  SimTraceExtractor simtrace(
    dirName + "sim/simtrace.vcd", "sim.m1",
    sim_var_name,
    [](double time, const SimTraceExtractor::ex_t &) -> bool {return time > 40;},
    [](const std::string & name) -> std::string {return name.substr(4); } // remove sim.
  );

  dp.AddPosEx(simtrace);

  InvariantSynthesizerCegar vg(
      {},                          // no include
      {dirName + "simple_pipe.v"}, //
      "pipeline_v",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::CVC4,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());
  
  vg.SetSygusVarnameList(sygus_var_name);
  vg.SetInitialDatapoint(dp); // assign (reset) the datapoints
  do {
    do{
      vg.GenerateVerificationTarget();
      if(vg.RunVerifAuto("ADD")) // the ADD
        break; // no more cex found

      std::cout << "EQ check cex found, query sygus for invariant candidate..."; std::cout.flush();
      vg.ExtractVerificationResult(); // also the cex
      vg.GenerateSynthesisTargetSygusDatapoints(); // the cex is used in this step
      vg.RunSynAuto();
      vg.ExtractSygusDatapointSynthesisResultAsCandidateInvariant(); // extracted to the candidate invariant
      // quick proof attempt  -- if proved, add to confirmed
      // quick disaprove attempt -- if disaproved add to cex, if proved add to confirm
      // proof attempt (assert all) (assume none)
      // disaprove attempt (assert all) (assume rf/confirmed)
    }while(not vg.in_bad_state()); // first generate enough guesses
    std::cout << "No more EQ check cex found, begin validating candidate invariants...\n";
    // if ( vg.ProofCandidateInvariant(time) )  // if it can be proved in a time bound, we are good, will add to ...
    //  break;
    auto confirmed_all_candidates = vg.ProofCandidateInvariants();
    ILA_ASSERT(confirmed_all_candidates != vg.INV_UNKNOWN);
    if (confirmed_all_candidates == vg.INV_PROVED) {
      std::cout << "All candidate invariants have been proved!" << std::endl;
      vg.AcceptAllCandidateInvariant(); // this is also done by validate actually, if it succeeded
      break;
    }
    // else: find cex
    vg.ValidateSygusDatapointCandidateInvariant();
    // 1. generate target
    // 2. run it
    // 3. extract cex to datapoint

    // if cex -> will extract the cex to datapoint, return failed inv
    // else if okay -> add to confirmed invariant

    std::cout << "Validation failed, prune candidate invariants...\n";
    vg.PruneCandidateInvariant();
    // a simple impl: remove all candidate invariants
    // an advanced impl: remove only violating invariants
    // do you want to continue to remove? (hard -- because validating takes time...)
    std::cout << "Search for more invariants...\n";
  } while(not vg.in_bad_state());

  // final validation
  vg.GenerateInvariantVerificationTarget(); // finally we revalidate the result
  std::cout << "---------Synthesized Invariants----------\n";
  for (auto && vlg: vg.GetInvariants().GetVlgConstraints() )
    std::cout << vlg << std::endl;
}



TEST(TestVlgVerifInvSyn, CegarCntSygusTransFunc)  {
  auto ila_model = CntTest::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = true; // if not using transfunc it does not matter
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.CosaPyEnvironment = "/home/hongce/cosaEnv/bin/activate";
  cfg.CosaPath = "/home/hongce/CoSA/";
  cfg.Z3Path = "/home/hongce/z3s/bin/";
  cfg.Cvc4Path = "/home/hongce/cvc-installs/latest/bin/";
  cfg.CosaSolver = "btor";
  cfg.SygusOptions.SygusPassInfo = 
    VerilogVerificationTargetGenerator::vtg_config_t::_sygus_options_t::TransferFunc;
  cfg.SygusOptions.UseArithmetics = VerilogVerificationTargetGenerator::vtg_config_t::_sygus_options_t::_use_arithmetics_t::Level1;

  std::vector<std::string> sygus_var_name = {"m1.v", "m1.imp"};

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/cnt2/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/cnt2-sygus-tf/";

  InvariantSynthesizerCegar vg(
      {},                          // no include
      {dirName + "verilog/opposite.v"}, //
      "opposite",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::CVC4,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

    do{
      vg.GenerateVerificationTarget();
      if(vg.RunVerifAuto("INC")) // the INC
        break; // no more cex found
      vg.ExtractVerificationResult();
      //vg.SetInitialDatapoint(dp);
      vg.SetSygusVarnameList(sygus_var_name);
      vg.GenerateSynthesisTargetSygusTransFunc();
      vg.RunSynAuto();
      vg.ExtractSynthesisResult(); // if should be the correct invariants
    }while(not vg.in_bad_state());
  vg.GenerateInvariantVerificationTarget(); // finally we revalidate the result
} // CegarCntSygusTransFunc

#if 0
// no use : does not terminate and the result is not reasonable
TEST(TestVlgVerifInvSyn, CegarPipelineExampleSygusTransFunc)  {

  auto ila_model = SimplePipe::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = true; // if not using transfunc it does not matter
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.CosaPyEnvironment = "/home/hongce/cosaEnv/bin/activate";
  cfg.CosaPath = "/home/hongce/CoSA/";
  cfg.Z3Path = "/home/hongce/z3s/bin/";
  cfg.Cvc4Path = "/home/hongce/cvc-installs/latest/bin/";
  cfg.CosaSolver = "btor";
  cfg.SygusOptions.SygusPassInfo = 
    VerilogVerificationTargetGenerator::vtg_config_t::_sygus_options_t::TransferFunc;

  TraceDataPoints dp;
  std::vector<std::string> sygus_var_name = {
    "m1.reg_0_w_stage", "m1.reg_1_w_stage", "m1.reg_2_w_stage", "m1.reg_3_w_stage",
    "m1.id_ex_reg_wen", "m1.id_ex_rd", "m1.ex_wb_reg_wen", "m1.ex_wb_rd" };

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/vpipe-out-sygus-tf/";

  InvariantSynthesizerCegar vg(
      {},                          // no include
      {dirName + "simple_pipe.v"}, //
      "pipeline_v",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::CVC4,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

    do{
      vg.GenerateVerificationTarget();
      if(vg.RunVerifAuto("ADD")) // the ADD
        break; // no more cex found
      vg.ExtractVerificationResult();
      //vg.SetInitialDatapoint(dp);
      vg.SetSygusVarnameList(sygus_var_name);
      vg.GenerateSynthesisTargetSygusTransFunc();
      vg.RunSynAuto();
      vg.ExtractSynthesisResult();
    }while(not vg.in_bad_state());
  vg.GenerateInvariantVerificationTarget(); // finally we revalidate the result

}
#endif

}; // namespace ilang
