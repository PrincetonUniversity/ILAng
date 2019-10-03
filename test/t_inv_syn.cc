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
  cfg.YosysSmtFlattenDatatype = false; // let's test flatten datatype also
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
    }while(not vg.in_bad_state());
  
  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateInvariantVerificationTarget();
  auto design_stat = vg.GetDesignStatistics();
  ILA_INFO << "========== Design Info ==========" ;
  ILA_INFO << "#bits= " << design_stat.NumOfDesignStateBits;
  ILA_INFO << "#vars=" << design_stat.NumOfDesignStateVars;
  ILA_INFO << "#extra_bits= " << design_stat.NumOfExtraStateBits;
  ILA_INFO << "#extra_vars=" << design_stat.NumOfExtraStateVars;
  ILA_INFO << "t(eq)= " << design_stat.TimeOfEqCheck;
  ILA_INFO << "t(syn)=" << design_stat.TimeOfInvSyn;
  ILA_INFO << "t(proof)= " << design_stat.TimeOfInvProof;
  ILA_INFO << "t(validate)=" << design_stat.TimeOfInvValidate;
} // CegarPipelineExample


TEST(TestVlgVerifInvSyn, CegarCntAbc) {
  auto ila_model = CntTest::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false;
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.CosaPyEnvironment = "/home/hongce/cosaEnv/bin/activate";
  cfg.CosaPath = "/home/hongce/CoSA/";
  cfg.AbcPath = "/home/hongce/abc/";
  cfg.AbcUseGla = true;
  cfg.AbcUseAiger = true;
  cfg.AbcUseCorr = false;
  cfg.CosaSolver = "btor";

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/cnt2/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/cnt-abc/";

  InvariantSynthesizerCegar vg(
      {},                          // no include
      {dirName + "verilog/opposite.v"}, //
      "opposite",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::ABC,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

    do{
      vg.GenerateVerificationTarget();
      if(vg.RunVerifAuto("INC")) // the ADD
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
  ILA_INFO << "t(eq)= " << design_stat.TimeOfEqCheck;
  ILA_INFO << "t(syn)=" << design_stat.TimeOfInvSyn;
  ILA_INFO << "t(proof)= " << design_stat.TimeOfInvProof;
  ILA_INFO << "t(validate)=" << design_stat.TimeOfInvValidate;

} // CegarCntAbc


TEST(TestVlgVerifInvSyn, SimpleCntCegarFreqHorn) {
  auto ila_model = CntTest::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = true; // let's test flatten datatype also
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.YosysUndrivenNetAsInput = true;
  cfg.CosaPyEnvironment = "/home/hongce/cosaEnv/bin/activate";
  cfg.CosaPath = "/home/hongce/CoSA/";
  cfg.Z3Path = "N/A";
  cfg.FreqHornPath = "/home/hongce/ila/aeval/build/tools/bv/";
  cfg.FreqHornHintsUseCnfStyle = true;
  cfg.FreqHornOptions = {
    "--skip-cnf --skip-const-check --skip-stat-collect --ante-size 1 --conseq-size 1  --cnf cnt-no-group.cnf --use-arith-bvnot --no-const-enum-vars-on m1.v,m1.imp"};
  cfg.CosaSolver = "btor";

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/cnt2/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/cnt2-cegar-freqhorn/";
  
  InvariantInCnf var_in_cnf;
  { // save grammar file
    os_portable_mkdir(outDir + "inv-syn");
    InvariantInCnf::clause cl;
    InvariantInCnf::VarsToClause( {
      "m1.imp", "m1.v"
      } , cl);
    var_in_cnf.InsertClause(cl);
    std::ofstream fout(outDir + "inv-syn/cnt-no-group.cnf");
    if (fout.is_open())
      var_in_cnf.ExportInCnfFormat(fout);
    else
      EXPECT_TRUE(false);
  } // save grammar file
  
  InvariantSynthesizerCegar vg(
      {},                          // no include
      {dirName + "verilog/opposite.v"}, //
      "opposite",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::FreqHorn,
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
    }while(not vg.in_bad_state());

  vg.GenerateInvariantVerificationTarget();
  auto design_stat = vg.GetDesignStatistics();
  ILA_INFO << "========== Design Info ==========" ;
  ILA_INFO << "#bits= " << design_stat.NumOfDesignStateBits;
  ILA_INFO << "#vars=" << design_stat.NumOfDesignStateVars;
  ILA_INFO << "#extra_bits= " << design_stat.NumOfExtraStateBits;
  ILA_INFO << "#extra_vars=" << design_stat.NumOfExtraStateVars;
  ILA_INFO << "t(eq)= " << design_stat.TimeOfEqCheck;
  ILA_INFO << "t(syn)=" << design_stat.TimeOfInvSyn;
  ILA_INFO << "t(proof)= " << design_stat.TimeOfInvProof;
  ILA_INFO << "t(validate)=" << design_stat.TimeOfInvValidate;
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
  ILA_INFO << "t(eq)= " << design_stat.TimeOfEqCheck;
  ILA_INFO << "t(syn)=" << design_stat.TimeOfInvSyn;
  ILA_INFO << "t(proof)= " << design_stat.TimeOfInvProof;
  ILA_INFO << "t(validate)=" << design_stat.TimeOfInvValidate;

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



TEST(TestVlgVerifInvSyn, CegarPipelineAbc) {
  auto ila_model = SimplePipe::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false;
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.CosaPyEnvironment = "/home/hongce/cosaEnv/bin/activate";
  cfg.CosaPath = "/home/hongce/CoSA/";
  cfg.AbcPath = "/home/hongce/abc/";
  cfg.AbcUseGla = true;
  cfg.AbcUseCorr = false;
  cfg.CosaSolver = "btor";

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/vpipe-out-abc/";

  InvariantSynthesizerCegar vg(
      {},                          // no include
      {dirName + "simple_pipe.v"}, //
      "pipeline_v",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::ABC,
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
  ILA_INFO << "t(eq)= " << design_stat.TimeOfEqCheck;
  ILA_INFO << "t(syn)=" << design_stat.TimeOfInvSyn;
  ILA_INFO << "t(proof)= " << design_stat.TimeOfInvProof;
  ILA_INFO << "t(validate)=" << design_stat.TimeOfInvValidate;

} // CegarPipelineAbc



TEST(TestVlgVerifInvSyn, CegarPipelineAbcAig) {
  auto ila_model = SimplePipe::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false;
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.CosaPyEnvironment = "/home/hongce/cosaEnv/bin/activate";
  cfg.CosaPath = "/home/hongce/CoSA/";
  cfg.AbcPath = "/home/hongce/abc/";
  cfg.AbcUseGla = true;
  cfg.AbcUseAiger = true;
  cfg.AbcMinimizeInv = false;
  cfg.AbcUseCorr = false;
  cfg.CosaSolver = "btor";

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/vpipe-out-abc-aig/";

  InvariantSynthesizerCegar vg(
      {},                          // no include
      {dirName + "simple_pipe.v"}, //
      "pipeline_v",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::ABC,
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
  ILA_INFO << "t(eq)= " << design_stat.TimeOfEqCheck;
  ILA_INFO << "t(syn)=" << design_stat.TimeOfInvSyn;
  ILA_INFO << "t(proof)= " << design_stat.TimeOfInvProof;
  ILA_INFO << "t(validate)=" << design_stat.TimeOfInvValidate;

} // CegarPipelineAbc



TEST(TestVlgVerifInvSyn, CegarPipelineAbcAigEnhance) {
  auto ila_model = SimplePipe::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  // cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = true; // for freqhorn
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.CosaPyEnvironment = "/home/hongce/cosaEnv/bin/activate";
  cfg.CosaPath = "/home/hongce/CoSA/";
  cfg.AbcPath = "/home/hongce/abc/";
  cfg.AbcUseGla = true;
  cfg.AbcUseAiger = true;
  cfg.AbcUseCorr = false;
  cfg.CosaSolver = "btor";

  cfg.Z3Path = "N/A";
  cfg.FreqHornPath = "/home/hongce/ila/aeval/build/tools/bv/";
  cfg.FreqHornOptions = {"--ante-size", "1", "--conseq-size", "1" , "--gen-spec-only"};

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/vpipe-out-abc-aig-enhance/";

  InvariantSynthesizerCegar vg(
      {},                          // no include
      {dirName + "simple_pipe.v"}, //
      "pipeline_v",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::ABC,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

  /// The incremental cnf
  InvariantInCnf incremental_cnf;

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
      vg.ExtractAbcSynthesisResultForEnhancement(incremental_cnf);
      { // what inv to enhance
        const auto & inv_to_enhance = 
          vg.GetCandidateInvariants();
        ILA_ASSERT(inv_to_enhance.NumInvariant() == 1);
        std::cout << "INV to enhance:" << inv_to_enhance.GetVlgConstraints()[0] << std::endl;
      }
      bool retried = false;
retry:
      // This is the function we need to write
      if (!vg.WordLevelEnhancement(incremental_cnf) ) {
        // if freqhorn fail, we shall manually fall back to use the original one
        // method #1:
        if (retried) {
          vg.AcceptAllCandidateInvariant();
          vg.MergeCnf(incremental_cnf);
          incremental_cnf.Clear();
          EXPECT_TRUE(false); // should not failed
        } else {
          // you can update syntax here and goes back to ...
          vg.ChangeFreqHornSyntax({"--ante-size", "1", "--conseq-size", "1" });
          retried = true;
          goto retry;
          //break;
        }
      } else  {
        vg.MergeCnf(incremental_cnf);
        incremental_cnf.Clear();
        vg.ClearAllCandidateInvariants(); // already included (you can also accept but unnecessary)
      }

      vg.GetInvariants().ExportToFile(outDir + "inv.txt");
    }while(not vg.in_bad_state());

  vg.GenerateInvariantVerificationTarget();
  auto design_stat = vg.GetDesignStatistics();
  ILA_INFO << "========== Design Info ==========" ;
  ILA_INFO << "#bits= " << design_stat.NumOfDesignStateBits;
  ILA_INFO << "#vars=" << design_stat.NumOfDesignStateVars;
  ILA_INFO << "#extra_bits= " << design_stat.NumOfExtraStateBits;
  ILA_INFO << "#extra_vars=" << design_stat.NumOfExtraStateVars;
  ILA_INFO << "t(eq)= " << design_stat.TimeOfEqCheck;
  ILA_INFO << "t(syn)=" << design_stat.TimeOfInvSyn;
  ILA_INFO << "t(proof)= " << design_stat.TimeOfInvProof;
  ILA_INFO << "t(validate)=" << design_stat.TimeOfInvValidate;

} // CegarPipelineAbc

// This test uses CEGAR loop
// This tests has no extra start cycle
TEST(TestVlgVerifInvSyn, CegarPipelineExampleFreqHorn) {
  auto ila_model = SimplePipe::BuildModel();


  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = true;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = true;
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.YosysUndrivenNetAsInput = true;
  cfg.CosaPyEnvironment = "/home/hongce/cosaEnv/bin/activate";
  cfg.CosaPath = "/home/hongce/CoSA/";
  cfg.Z3Path = "N/A";
  cfg.FreqHornPath = "/home/hongce/ila/aeval/build/tools/bv/";
  cfg.FreqHornHintsUseCnfStyle = true;

  std::vector<std::string> fh_options = {
    "--ante-size","1","--conseq-size","1","--find-one",
    "--skip-cnf --skip-const-check --skip-stat-collect","--ctrl-no-cross-var-eq",
    "--cti-prune --no-merge-cti --cnf pipe-no-group.cnf --grammar pipe.gmr"};

  //std::vector<std::string> fh_options = {
  //  "--ante-size","1","--conseq-size","1", "--2-chance",
  //  "--skip-cnf --skip-const-check --skip-stat-collect","--ctrl-no-cross-var-eq",
  //  "--no-merge-cti --cnf pipe-no-group.cnf --grammar pipe.gmr"};

  cfg.FreqHornOptions = fh_options;
  cfg.CosaSolver = "btor";

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/vpipe-out-freqhorn/";

  InvariantInCnf var_in_cnf;
  { // save grammar file
    os_portable_mkdir(outDir + "inv-syn");
    InvariantInCnf::clause cl;
    InvariantInCnf::VarsToClause( {
      "m1.reg_0_w_stage","m1.reg_1_w_stage", "m1.reg_2_w_stage", "m1.reg_3_w_stage",
      "m1.id_ex_reg_wen","m1.ex_wb_reg_wen", "m1.id_ex_rd", "m1.ex_wb_rd"
      } , cl);
    var_in_cnf.InsertClause(cl);
    std::ofstream fout(outDir + "inv-syn/pipe-no-group.cnf");
    if (fout.is_open())
      var_in_cnf.ExportInCnfFormat(fout);
    else
      EXPECT_TRUE(false);
  } // save grammar file

  InvariantSynthesizerCegar vg(
      {},                          // no include
      {dirName + "simple_pipe.v"}, //
      "pipeline_v",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::FreqHorn,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

    do{
      vg.GenerateVerificationTarget();
      if(vg.RunVerifAuto("ADD")) // the ADD
        break; // no more cex found
      vg.ExtractVerificationResult();

      unsigned conseq_size = 1;
      
  pipe_conseq_retry:
      fh_options[3] = std::to_string(conseq_size);
      vg.ChangeFreqHornSyntax(fh_options);

      vg.GenerateSynthesisTarget();
      if(vg.RunSynAuto()) {
        conseq_size ++;
        ILA_INFO << "Conseq size increase to #" << conseq_size;
        if (conseq_size < 3)
          goto pipe_conseq_retry;
        // else
        ILA_ERROR<<"Unexpected counterexample! Probably the syntax is not good enough!";
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
  ILA_INFO << "t(eq)= " << design_stat.TimeOfEqCheck;
  ILA_INFO << "t(syn)=" << design_stat.TimeOfInvSyn;
  ILA_INFO << "t(proof)= " << design_stat.TimeOfInvProof;
  ILA_INFO << "t(validate)=" << design_stat.TimeOfInvValidate;

  // test invariant import and export also here
  vg.GetInvariants().ExportToFile(outDir+"inv_results.txt");

} // CegarPipelineExample


TEST(TestVlgVerifInvSyn, InvariantImportExport) {

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
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/inv_obj_test/";

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
  vg.SupplyCandidateInvariant("(1'b1) == (((m1.reg_1_w_stage[0:0]) ||(!((m1.ex_wb_rd) == (2'b01))) ||(!((m1.ex_wb_reg_wen) == (1'b1)))) &&((!((m1.id_ex_rd) == (2'b01))) ||(!((m1.id_ex_reg_wen) == (1'b1))) ||((m1.reg_1_w_stage[1:1]) == (1'b1))))");
  EXPECT_EQ( vg.ValidateSygusDatapointCandidateInvariant(), vg.INV_PROVED );
  vg.SupplyCandidateInvariant("(1'b1) == ((!((m1.reg_3_w_stage[1:1]) == (1'b1))) ||((m1.id_ex_rd[1:1]) == (1'b1)))");

  { // check confirmed inv
    EXPECT_EQ(vg.GetInvariants().NumInvariant(),1);

    InvariantObject invs(vg.GetInvariants());
    invs.ExportToFile(outDir+"confirmed_inv_results.txt");
    invs.ClearAllInvariants();
    invs.ImportFromFile(outDir+"confirmed_inv_results.txt");
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

    for (auto pos = invs.GetSmtFormulae().begin(), 
          pos2 = vg.GetInvariants().GetSmtFormulae().begin(); 
        pos != invs.GetSmtFormulae().end();
        ++ pos, ++ pos2  ) {
      EXPECT_EQ(*pos, *pos2);
    }
  } // finish check confirmed

  { // check confirmed inv
    EXPECT_EQ(vg.GetCandidateInvariants().NumInvariant(),1);

    InvariantObject invs(vg.GetCandidateInvariants());
    invs.ExportToFile(outDir+"confirmed_inv_results.txt");
    invs.ClearAllInvariants();
    invs.ImportFromFile(outDir+"confirmed_inv_results.txt");
    // check they are the same
    EXPECT_EQ(
      vg.GetCandidateInvariants().NumInvariant(), 
      invs.NumInvariant());
    EXPECT_EQ(
      vg.GetCandidateInvariants().GetExtraVarDefs().size(), 
      invs.GetExtraVarDefs().size());
    EXPECT_EQ(
      vg.GetCandidateInvariants().GetExtraFreeVarDefs().size(), 
      invs.GetExtraFreeVarDefs().size());

    for (auto pos = invs.GetVlgConstraints().begin(), 
          pos2 = vg.GetCandidateInvariants().GetVlgConstraints().begin(); 
        pos != invs.GetVlgConstraints().end();
        ++ pos, ++ pos2  ) {
      EXPECT_EQ(*pos, *pos2);
    }

    for (auto pos = invs.GetSmtFormulae().begin(), 
          pos2 = vg.GetCandidateInvariants().GetSmtFormulae().begin(); 
        pos != invs.GetSmtFormulae().end();
        ++ pos, ++ pos2  ) {
      EXPECT_EQ(*pos, *pos2);
    }
  } // finish check confirmed
  EXPECT_EQ( vg.ProofCandidateInvariants(), vg.INV_PROVED );
}


TEST(TestVlgVerifInvSyn, CegarPipelineExampleSygusDatapointSimple) {
  unsigned num_cegar = 0;
  unsigned num_force = 0;
  unsigned num_prune = 0;

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
  cfg.CosaSolver = "z3";
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
  
  Cvc4Syntax syntax;
  syntax.ctrl_data_sep_width = 2;
  syntax.other_comp_sep_width = 2;

  vg.SetSygusVarnameList(sygus_var_name);
  vg.SetInitialDatapoint(dp); // assign (reset) the datapoints
    do{
      vg.GenerateVerificationTarget();
      if(vg.RunVerifAuto("ADD")) // the ADD
        break; // no more cex found

      num_cegar ++;

      std::cout << "EQ check cex found, query sygus for invariant candidate..."; std::cout.flush();
      vg.ExtractVerificationResult(); // also the cex

      bool succeed = true;
      bool prev_succeed;
  retry:
      prev_succeed = succeed;
      vg.GenerateSynthesisTargetSygusDatapoints(syntax,!succeed); // the cex is used in this step
      vg.RunSynAuto();
      succeed = vg.ExtractSygusDatapointSynthesisResultAsCandidateInvariant(); // extracted to the candidate invariant
      if (not succeed) {
        EXPECT_TRUE(prev_succeed);
        num_force ++;
        goto retry;
      }
      //if (vg.ProofCandidateInvariants() != vg.INV_PROVED) {
        auto res = vg.ValidateSygusDatapointCandidateInvariant();
        if (res != vg.INV_PROVED) {
          vg.PruneCandidateInvariant();
          num_prune ++;
          goto retry;
        }
      //}
      // quick proof attempt  -- if proved, add to confirmed
      // quick disaprove attempt -- if disaproved add to cex, if proved add to confirm
      // proof attempt (assert all) (assume none)
      // disaprove attempt (assert all) (assume rf/confirmed)
    }while(not vg.in_bad_state()); // first generate enough guesses
    std::cout << "No more EQ check cex found, begin validating candidate invariants...\n";
    // if ( vg.ProofCandidateInvariant(time) )  // if it can be proved in a time bound, we are good, will add to ...
 
  // final validation
  vg.GenerateInvariantVerificationTarget(); // finally we revalidate the result
  std::cout << "---------Synthesized Invariants----------\n";
  for (auto && vlg: vg.GetInvariants().GetVlgConstraints() )
    std::cout << vlg << std::endl;
  
  vg.GetInvariants().ExportToFile(outDir+"confirmed_inv.txt");

  auto design_stat = vg.GetDesignStatistics();
  ILA_INFO << "========== Design Info ==========" ;
  ILA_INFO << "#bits= " << design_stat.NumOfDesignStateBits;
  ILA_INFO << "#vars=" << design_stat.NumOfDesignStateVars;
  ILA_INFO << "#extra_bits= " << design_stat.NumOfExtraStateBits;
  ILA_INFO << "#extra_vars=" << design_stat.NumOfExtraStateVars;
  ILA_INFO << "t(eq)= " << design_stat.TimeOfEqCheck;
  ILA_INFO << "t(syn)=" << design_stat.TimeOfInvSyn;
  ILA_INFO << "t(proof)= " << design_stat.TimeOfInvProof;
  ILA_INFO << "t(validate)=" << design_stat.TimeOfInvValidate;

  ILA_INFO << "#cegar= " << num_cegar;
  ILA_INFO << "#force=" << num_force;
  ILA_INFO << "#prune= " << num_prune;
}


TEST(TestVlgVerifInvSyn, CegarPipelineExampleSygusDatapoint) {
  unsigned num_cegar = 0;
  unsigned num_force = 0;
  unsigned num_prune = 0;

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

  Cvc4Syntax syntax;
  syntax.ctrl_data_sep_width = 2;
  syntax.other_comp_sep_width = 2;
  
  vg.SetSygusVarnameList(sygus_var_name);
  vg.SetInitialDatapoint(dp); // assign (reset) the datapoints
  do {
    do{
      vg.GenerateVerificationTarget();
      if(vg.RunVerifAuto("ADD")) // the ADD
        break; // no more cex found

      num_cegar ++;

      std::cout << "EQ check cex found, query sygus for invariant candidate..."; std::cout.flush();
      vg.ExtractVerificationResult(); // also the cex

      bool succeed = true;
      bool prev_succeed;
  retry:
      prev_succeed = succeed;
      vg.GenerateSynthesisTargetSygusDatapoints(syntax,!succeed); // the cex is used in this step
      vg.RunSynAuto();
      succeed = vg.ExtractSygusDatapointSynthesisResultAsCandidateInvariant(); // extracted to the candidate invariant
      if (not succeed) {
        EXPECT_TRUE(prev_succeed);
        num_force ++;
        goto retry;
      }
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
    num_prune ++;
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
  
  vg.GetInvariants().ExportToFile(outDir+"confirmed_inv.txt");

  auto design_stat = vg.GetDesignStatistics();
  ILA_INFO << "========== Design Info ==========" ;
  ILA_INFO << "#bits= " << design_stat.NumOfDesignStateBits;
  ILA_INFO << "#vars=" << design_stat.NumOfDesignStateVars;
  ILA_INFO << "#extra_bits= " << design_stat.NumOfExtraStateBits;
  ILA_INFO << "#extra_vars=" << design_stat.NumOfExtraStateVars;
  ILA_INFO << "t(eq)= " << design_stat.TimeOfEqCheck;
  ILA_INFO << "t(syn)=" << design_stat.TimeOfInvSyn;
  ILA_INFO << "t(proof)= " << design_stat.TimeOfInvProof;
  ILA_INFO << "t(validate)=" << design_stat.TimeOfInvValidate;

  ILA_INFO << "#cegar= " << num_cegar;
  ILA_INFO << "#force=" << num_force;
  ILA_INFO << "#prune= " << num_prune;
}

/*

// ------------------- hardwired templates --------------------- //
const unsigned ctrl_data_sep_width = 5;

const unsigned other_comp_sep_width = ctrl_data_sep_width;

const std::vector<std::string> compOp({});

const std::map<int,std::set<unsigned>> nums(
  {
    //{16,{0xff00,0xff01,0xff02, 0xff04, 0xff10, 0xff20}},
    {28,{0}}
  }
);
// bitwidth -> (op -> n-ary)
const std::map<unsigned,std::map<std::string,unsigned>> arithmOp (
  {{4,{{"bvnot",1}}}}
);

// to -> (op -> from)
// result_width : h,l, from, result_width
const std::map<unsigned, std::vector<extract_op>> extractExtOp (
  {
    {5, {
      extract_op(11,7,32,5, {"dut.mem_reg_inst", "dut.wb_reg_inst", "dut.ex_reg_inst"}),
      extract_op(19,15,32,5, {"dut.mem_reg_inst", "dut.wb_reg_inst", "dut.ex_reg_inst"}),
      extract_op(24,20,32,5, {"dut.mem_reg_inst", "dut.wb_reg_inst", "dut.ex_reg_inst"})} }, //  extract_15_0_128_16
    
  }
);
*/

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

  Cvc4Syntax syntax;
  syntax.ctrl_data_sep_width = 5;
  syntax.other_comp_sep_width = 5;
  syntax.arithmOp = {{4,{{"bvnot",1}}}};

    do{
      vg.GenerateVerificationTarget();
      if(vg.RunVerifAuto("INC")) // the INC
        break; // no more cex found
      vg.ExtractVerificationResult();
      //vg.SetInitialDatapoint(dp);
      vg.SetSygusVarnameList(sygus_var_name);
      vg.GenerateSynthesisTargetSygusTransFunc(syntax);
      if ( vg.RunSynAuto() ) {
        ILA_ERROR << "CEX reachable, possibly bad syntax!";
        break;
      }
      vg.ExtractSynthesisResult(); // if should be the correct invariants
    }while(not vg.in_bad_state());
  vg.GenerateInvariantVerificationTarget(); // finally we revalidate the result


  auto design_stat = vg.GetDesignStatistics();
  ILA_INFO << "========== Design Info ==========" ;
  ILA_INFO << "#bits= " << design_stat.NumOfDesignStateBits;
  ILA_INFO << "#vars=" << design_stat.NumOfDesignStateVars;
  ILA_INFO << "#extra_bits= " << design_stat.NumOfExtraStateBits;
  ILA_INFO << "#extra_vars=" << design_stat.NumOfExtraStateVars;
  ILA_INFO << "t(eq)= " << design_stat.TimeOfEqCheck;
  ILA_INFO << "t(syn)=" << design_stat.TimeOfInvSyn;
  ILA_INFO << "t(proof)= " << design_stat.TimeOfInvProof;
  ILA_INFO << "t(validate)=" << design_stat.TimeOfInvValidate;

} // CegarCntSygusTransFunc

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

  Cvc4Syntax syntax;
  syntax.ctrl_data_sep_width = 5;
  syntax.other_comp_sep_width = 5;

    do{
      vg.GenerateVerificationTarget();
      if(vg.RunVerifAuto("ADD")) // the ADD
        break; // no more cex found
      vg.ExtractVerificationResult();
      //vg.SetInitialDatapoint(dp);
      vg.SetSygusVarnameList(sygus_var_name);
      vg.GenerateSynthesisTargetSygusTransFunc(syntax);
      vg.RunSynAuto();
      vg.ExtractSynthesisResult();
    }while(not vg.in_bad_state());
  vg.GenerateInvariantVerificationTarget(); // finally we revalidate the result

}

}; // namespace ilang
