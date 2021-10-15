/// \file
/// Unit test for invariant synthesis

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ilang++.h>
#include <ilang/util/fs.h>
// #include <ilang/vtarget-out/inv-syn/inv_syn_cegar.h>
#include <ilang/vtarget-out/vtarget_gen.h>

#include "unit-include/config.h"
#include "unit-include/memswap.h"
#include "unit-include/pipe_ila.h"
#include "unit-include/util.h"

namespace ilang {

// #ifdef ILANG_BUILD_INVSYN
#if 0

#define DBG_TAG "VlgVerifInvSyn"

class TestVlgVerifInvSyn : public ::testing::Test {
public:
  TestVlgVerifInvSyn() {}
  ~TestVlgVerifInvSyn() {}

  void SetUp() {
    // EnableDebug(DBG_TAG);
    outDir = GetRandomFileName(fs::temp_directory_path());
    os_portable_mkdir(outDir);
  }

  void TearDown() {
    DisableDebug(DBG_TAG);
    os_portable_remove_directory(outDir);
  }

  typedef std::vector<std::string> P;
  fs::path outDir;

}; // class TestVlgVerifInvSyn

// Z3, ABC, FREQHORN
// ABC w. different configurations
// FREQHORN w. different configurations
// SMT IN?
// smt-target-gen

// will not execute any external tools
TEST_F(TestVlgVerifInvSyn, SimpleCntCegar) {
  auto ila_model = CntTest::BuildModel();

  RtlVerifyConfig cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.PonoAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false; // let's test flatten datatype also
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.YosysPath = "N/A";
  cfg.CosaPyEnvironment = "N/A";
  cfg.CosaPath = "N/A";
  cfg.AbcPath = "N/A";
  cfg.Z3Path = "N/A";
  cfg.GrainPath = "N/A";

  auto dirName = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                        P({"unit-data", "inv_syn", "cnt2"}));
  auto refDir = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                       P({"unit-data", "inv_syn", "cnt2-cex"}));
  os_portable_copy_dir(refDir, outDir);

  InvariantSynthesizerCegar vg(
      {}, // no include
      {os_portable_append_dir(dirName, P({"verilog", "opposite.v"}))}, //
      "opposite", // top_module_name
      os_portable_append_dir(dirName,
                             P({"rfmap", "vmap.json"})), // variable mapping
      os_portable_append_dir(dirName, P({"rfmap", "cond-noinv.json"})), outDir,
      ila_model.get(),
      ModelCheckerSelection::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::Z3, cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateVerificationTarget({"1==1"});
  EXPECT_FALSE(vg.RunVerifAuto("INC", "", true));
  vg.ExtractVerificationResult();
  vg.GenerateSynthesisTarget(); // you will need fp engine
  EXPECT_FALSE(vg.RunSynAuto(true));
  vg.ExtractSynthesisResult(); // very weired, it throw away something in arg
  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateInvariantVerificationTarget();
  auto design_stat = vg.GetDesignStatistics();
  design_stat.StoreToFile(os_portable_append_dir(outDir, "design_stat.txt"));
  ILA_INFO << "========== Design Info ==========";
  ILA_INFO << "#bits= " << design_stat.NumOfDesignStateBits;
  ILA_INFO << "#vars=" << design_stat.NumOfDesignStateVars;
  ILA_INFO << "#extra_bits= " << design_stat.NumOfExtraStateBits;
  ILA_INFO << "#extra_vars=" << design_stat.NumOfExtraStateVars;
  ILA_INFO << "t(eq)= " << design_stat.TimeOfEqCheck;
  ILA_INFO << "t(syn)=" << design_stat.TimeOfInvSyn;
  ILA_INFO << "t(proof)= " << design_stat.TimeOfInvProof;
  ILA_INFO << "t(validate)=" << design_stat.TimeOfInvValidate;
  design_stat.LoadFromFile(os_portable_append_dir(outDir, "design_stat.txt"));

  vg.LoadPrevStatisticsState(os_portable_append_dir(outDir, "design_stat.txt"));
  // test save invariants / load invariants
  vg.GetInvariants().ExportToFile(os_portable_append_dir(outDir, "inv.txt"));
  vg.LoadCandidateInvariantsFromFile(os_portable_append_dir(outDir, "inv.txt"));
  EXPECT_EQ(vg.GetCandidateInvariants().NumInvariant(),
            vg.GetInvariants().NumInvariant());
  vg.RemoveInvariantsByIdx(0);
  EXPECT_EQ(vg.GetInvariants().NumInvariant(), 1);

  {
    InvariantInCnf cnf1;
    vg.ExtractInvariantVarForEnhance(0, cnf1, true, {});
    std::ofstream fout(os_portable_append_dir(outDir, "cnf1.txt"));
    cnf1.ExportInCnfFormat(fout);
    fout.close();
  }
  {
    InvariantInCnf cnf2;
    vg.ExtractInvariantVarForEnhance(0, cnf2, false, {});
    std::ofstream fout(os_portable_append_dir(outDir, "cnf2.txt"));
    cnf2.ExportInCnfFormat(fout);
    fout.close();
  }

  InvariantObject inv_obj;
  inv_obj.InsertFromAnotherInvObj(vg.GetInvariants());

  vg.LoadInvariantsFromFile(os_portable_append_dir(outDir, "inv.txt"));
  EXPECT_EQ(vg.GetInvariants().NumInvariant(), 3);
  vg.GenerateInvariantVerificationTarget();

  inv_obj.ClearAllInvariants();
  vg.SupplyCandidateInvariant("1==1");
  vg.AcceptAllCandidateInvariant();
  EXPECT_FALSE(vg.GetRunnableTargetScriptName().empty());
  vg.CexGeneralizeRemoveStates({});
  vg.LoadDesignSmtInfo(
      os_portable_join_dir({outDir, "inv-syn", "__design_smt.smt2"}));

} // CegarPipelineExample

// will not execute any external tools
TEST_F(TestVlgVerifInvSyn, SimpleCntCegarWithAssumptions) {
  auto ila_model = CntTest::BuildModel();

  RtlVerifyConfig cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = true;
  cfg.PonoAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false; // let's test flatten datatype also
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.YosysPath = "N/A";
  cfg.CosaPyEnvironment = "N/A";
  cfg.CosaPath = "N/A";
  cfg.AbcPath = "N/A";
  cfg.Z3Path = "N/A";
  cfg.GrainPath = "N/A";

  auto dirName = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                        P({"unit-data", "inv_syn", "cnt2"}));
  auto refDir = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                       P({"unit-data", "inv_syn", "cnt2-cex"}));
  os_portable_copy_dir(refDir, outDir);

  InvariantSynthesizerCegar vg(
      {}, // no include
      {os_portable_append_dir(dirName, P({"verilog", "opposite.v"}))}, //
      "opposite", // top_module_name
      os_portable_append_dir(dirName,
                             P({"rfmap", "vmap.json"})), // variable mapping
      os_portable_append_dir(dirName, P({"rfmap", "cond-noinv.json"})), outDir,
      ila_model.get(),
      ModelCheckerSelection::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::Z3, cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateVerificationTarget({"1==1"});
  EXPECT_FALSE(vg.RunVerifAuto("INC", "", true));
  vg.ExtractVerificationResult();
  vg.GenerateSynthesisTarget(); // you will need fp engine
  EXPECT_FALSE(vg.RunSynAuto(true));
  vg.ExtractSynthesisResult(); // very weired, it throw away something in arg
  EXPECT_FALSE(vg.in_bad_state());
}

// will not execute any external tools
TEST_F(TestVlgVerifInvSyn, LoadInvFromBeginning) {
  auto ila_model = CntTest::BuildModel();

  RtlVerifyConfig cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.PonoAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false; // let's test flatten datatype also
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.ValidateSynthesizedInvariant = cfg.CANDIDATE;
  cfg.YosysPath = "N/A";
  cfg.CosaPyEnvironment = "N/A";
  cfg.CosaPath = "N/A";
  cfg.AbcPath = "N/A";
  cfg.Z3Path = "N/A";
  cfg.GrainPath = "N/A";

  auto dirName = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                        P({"unit-data", "inv_syn", "cnt2"}));
  auto refDir = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                       P({"unit-data", "inv_syn", "cnt2-cex"}));
  os_portable_copy_dir(refDir, outDir);

  {
    InvariantSynthesizerCegar vg(
        {}, // no include
        {os_portable_append_dir(dirName, P({"verilog", "opposite.v"}))}, //
        "opposite", // top_module_name
        os_portable_append_dir(dirName,
                               P({"rfmap", "vmap.json"})), // variable mapping
        os_portable_append_dir(dirName, P({"rfmap", "cond-noinv.json"})),
        outDir, ila_model.get(),
        ModelCheckerSelection::COSA,
        VerilogVerificationTargetGenerator::synthesis_backend_selector::Z3,
        cfg);

    EXPECT_FALSE(vg.in_bad_state());

    vg.LoadCandidateInvariantsFromFile(
        os_portable_append_dir(outDir, "inv2.txt"));
    vg.LoadInvariantsFromFile(os_portable_append_dir(outDir, "inv2.txt"));
    vg.GenerateInvariantVerificationTarget();
  }
  cfg.ValidateSynthesizedInvariant = cfg.CONFIRMED;
  {
    InvariantSynthesizerCegar vg(
        {}, // no include
        {os_portable_append_dir(dirName, P({"verilog", "opposite.v"}))}, //
        "opposite", // top_module_name
        os_portable_append_dir(dirName,
                               P({"rfmap", "vmap.json"})), // variable mapping
        os_portable_append_dir(dirName, P({"rfmap", "cond-noinv.json"})),
        outDir, ila_model.get(),
        ModelCheckerSelection::COSA,
        VerilogVerificationTargetGenerator::synthesis_backend_selector::Z3,
        cfg);

    EXPECT_FALSE(vg.in_bad_state());

    vg.LoadCandidateInvariantsFromFile(
        os_portable_append_dir(outDir, "inv2.txt"));
    vg.LoadInvariantsFromFile(os_portable_append_dir(outDir, "inv2.txt"));
    vg.GenerateInvariantVerificationTarget();
  }
  cfg.ValidateSynthesizedInvariant = cfg.NOINV;
  {
    InvariantSynthesizerCegar vg(
        {}, // no include
        {os_portable_append_dir(dirName, P({"verilog", "opposite.v"}))}, //
        "opposite", // top_module_name
        os_portable_append_dir(dirName,
                               P({"rfmap", "vmap.json"})), // variable mapping
        os_portable_append_dir(dirName, P({"rfmap", "cond-noinv.json"})),
        outDir, ila_model.get(),
        ModelCheckerSelection::COSA,
        VerilogVerificationTargetGenerator::synthesis_backend_selector::Z3,
        cfg);

    EXPECT_FALSE(vg.in_bad_state());

    vg.LoadCandidateInvariantsFromFile(
        os_portable_append_dir(outDir, "inv2.txt"));
    vg.LoadInvariantsFromFile(os_portable_append_dir(outDir, "inv2.txt"));
    vg.GenerateInvariantVerificationTarget();
    vg.GenerateVerificationTarget();
    EXPECT_FALSE(vg.RunVerifAuto("INC", "", true));
    vg.ExtractVerificationResult();
    vg.GenerateSynthesisTarget(); // you will need fp engine
    EXPECT_FALSE(vg.RunSynAuto(true));
    vg.ExtractSynthesisResult();
    EXPECT_FALSE(vg.in_bad_state());
  }

  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = true;
  {
    InvariantSynthesizerCegar vg(
        {}, // no include
        {os_portable_append_dir(dirName, P({"verilog", "opposite.v"}))}, //
        "opposite", // top_module_name
        os_portable_append_dir(dirName,
                               P({"rfmap", "vmap.json"})), // variable mapping
        os_portable_append_dir(dirName, P({"rfmap", "cond-noinv.json"})),
        outDir, ila_model.get(),
        ModelCheckerSelection::COSA,
        VerilogVerificationTargetGenerator::synthesis_backend_selector::Z3,
        cfg);

    EXPECT_FALSE(vg.in_bad_state());

    vg.LoadCandidateInvariantsFromFile(
        os_portable_append_dir(outDir, "inv2.txt"));
    vg.LoadInvariantsFromFile(os_portable_append_dir(outDir, "inv2.txt"));
    vg.GenerateInvariantVerificationTarget();
    vg.GenerateVerificationTarget();
    EXPECT_FALSE(vg.RunVerifAuto("INC", "", true));
    vg.ExtractVerificationResult();
    vg.GenerateSynthesisTarget(); // you will need fp engine
    EXPECT_FALSE(vg.RunSynAuto(true));
    vg.ExtractSynthesisResult();
    EXPECT_FALSE(vg.in_bad_state());
  }

} // CegarPipelineExample

TEST_F(TestVlgVerifInvSyn, SimpleCntCegarPassed) {
  auto ila_model = CntTest::BuildModel();

  RtlVerifyConfig cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.PonoAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false; // let's test flatten datatype also
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.YosysPath = "N/A";
  cfg.CosaPyEnvironment = "N/A";
  cfg.CosaPath = "N/A";
  cfg.AbcPath = "N/A";
  cfg.Z3Path = "N/A";
  cfg.GrainPath = "N/A";

  auto dirName = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                        P({"unit-data", "inv_syn", "cnt2"}));
  auto refDir =
      os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                             P({"unit-data", "inv_syn", "cnt2-pass"}));
  os_portable_copy_dir(refDir, outDir);

  InvariantSynthesizerCegar vg(
      {}, // no include
      {os_portable_append_dir(dirName, P({"verilog", "opposite.v"}))}, //
      "opposite", // top_module_name
      os_portable_append_dir(dirName,
                             P({"rfmap", "vmap.json"})), // variable mapping
      os_portable_append_dir(dirName, P({"rfmap", "cond-noinv.json"})), outDir,
      ila_model.get(),
      ModelCheckerSelection::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::Z3, cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateVerificationTarget();
  EXPECT_TRUE(vg.RunVerifAuto("INC", "", true));
  EXPECT_TRUE(vg.GetCandidateInvariants().GetSmtFormulae().empty());

} // SimpleCntCegarPassed

TEST_F(TestVlgVerifInvSyn, CegarCntAbc) {
  auto ila_model = CntTest::BuildModel();

  RtlVerifyConfig cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.PonoAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false;
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.AbcUseGla = true;
  cfg.AbcUseAiger = true;
  cfg.AbcUseCorr = false;
  cfg.YosysPath = "N/A";
  cfg.CosaPyEnvironment = "N/A";
  cfg.CosaPath = "N/A";
  cfg.AbcPath = "N/A";
  cfg.Z3Path = "N/A";
  cfg.GrainPath = "N/A";

  auto dirName = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                        {"unit-data", "inv_syn", "cnt2"});
  auto refDir = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                       {"unit-data", "inv_syn", "cnt2-abc"});
  os_portable_copy_dir(refDir, outDir);

  InvariantSynthesizerCegar vg(
      {}, // no include
      {os_portable_append_dir(dirName, P({"verilog", "opposite.v"}))},
      "opposite", // top_module_name
      os_portable_append_dir(dirName,
                             P({"rfmap", "vmap.json"})), // variable mapping
      os_portable_append_dir(dirName, P({"rfmap", "cond-noinv.json"})), outDir,
      ila_model.get(),
      ModelCheckerSelection::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::ABC, cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateVerificationTarget();
  EXPECT_FALSE(vg.RunVerifAuto("INC", "", true));
  vg.ExtractVerificationResult();
  vg.GenerateSynthesisTarget(); // you will need fp engine
  EXPECT_FALSE(vg.RunSynAuto(true));
  vg.ExtractSynthesisResult(); // very weired, it throw away something in arg
  EXPECT_FALSE(vg.in_bad_state());

  EXPECT_EQ(vg.GetCandidateInvariants().NumInvariant(), 0);
  EXPECT_EQ(vg.GetInvariants().NumInvariant(), 1);
  vg.GetInvariants().ExportToFile(os_portable_append_dir(outDir, "inv.txt"));

} // CegarCntAbc

TEST_F(TestVlgVerifInvSyn, CegarCntAbcBlif) {
  auto ila_model = CntTest::BuildModel();

  RtlVerifyConfig cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.PonoAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false;
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.AbcUseGla = true;
  cfg.AbcUseAiger = false;
  cfg.AbcAssumptionStyle = cfg.AssumptionRegister;
  cfg.AbcUseCorr = false;
  cfg.YosysPath = "N/A";
  cfg.CosaPyEnvironment = "N/A";
  cfg.CosaPath = "N/A";
  cfg.AbcPath = "N/A";
  cfg.Z3Path = "N/A";
  cfg.GrainPath = "N/A";

  auto dirName = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                        {"unit-data", "inv_syn", "cnt2"});
  auto refDir =
      os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                             {"unit-data", "inv_syn", "cnt2-abc-blif"});
  os_portable_copy_dir(refDir, outDir);

  InvariantSynthesizerCegar vg(
      {}, // no include
      {os_portable_append_dir(dirName, P({"verilog", "opposite.v"}))},
      "opposite", // top_module_name
      os_portable_append_dir(dirName,
                             P({"rfmap", "vmap.json"})), // variable mapping
      os_portable_append_dir(dirName, P({"rfmap", "cond-noinv.json"})), outDir,
      ila_model.get(),
      ModelCheckerSelection::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::ABC, cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateVerificationTarget();
  EXPECT_FALSE(vg.RunVerifAuto("INC", "", true));
  vg.ExtractVerificationResult();
  vg.GenerateSynthesisTarget(); // you will need fp engine
  EXPECT_FALSE(vg.RunSynAuto(true));
  vg.ExtractSynthesisResult(); // very weired, it throw away something in arg
  EXPECT_FALSE(vg.in_bad_state());

  EXPECT_EQ(vg.GetCandidateInvariants().NumInvariant(), 0);
  vg.GetInvariants().ExportToFile(os_portable_append_dir(outDir, "inv.txt"));

} // CegarCntAbc

TEST_F(TestVlgVerifInvSyn, CegarCntAbcWithAssumption) {
  auto ila_model = CntTest::BuildModel();

  RtlVerifyConfig cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = true;
  cfg.PonoAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false;
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.AbcUseGla = false;
  cfg.AbcUseAiger = true;
  cfg.AbcUseCorr = false;
  cfg.YosysPath = "N/A";
  cfg.CosaPyEnvironment = "N/A";
  cfg.CosaPath = "N/A";
  cfg.AbcPath = "N/A";
  cfg.Z3Path = "N/A";
  cfg.GrainPath = "N/A";

  auto dirName = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                        {"unit-data", "inv_syn", "cnt2"});
  auto refDir = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                       {"unit-data", "inv_syn", "cnt2-abc"});
  os_portable_copy_dir(refDir, outDir);

  InvariantSynthesizerCegar vg(
      {}, // no include
      {os_portable_append_dir(dirName, P({"verilog", "opposite.v"}))},
      "opposite", // top_module_name
      os_portable_append_dir(dirName,
                             P({"rfmap", "vmap.json"})), // variable mapping
      os_portable_append_dir(dirName, P({"rfmap", "cond-noinv.json"})), outDir,
      ila_model.get(),
      ModelCheckerSelection::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::ABC, cfg);

  EXPECT_FALSE(vg.in_bad_state());
  vg.SupplyCandidateInvariant("1'b1 == 1'b1");

  vg.GenerateVerificationTarget();
  EXPECT_FALSE(vg.RunVerifAuto("INC", "", true));
  vg.ExtractVerificationResult();
  vg.GenerateSynthesisTarget();

} // CegarCntAbc

TEST_F(TestVlgVerifInvSyn, CegarCntAbcInvStart) {
  auto ila_model = CntTest::BuildModel();

  RtlVerifyConfig cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.PonoAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false;
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.AbcUseGla = true;
  cfg.AbcUseAiger = true;
  cfg.AbcUseCorr = false;
  cfg.YosysPath = "N/A";
  cfg.CosaPyEnvironment = "N/A";
  cfg.CosaPath = "N/A";
  cfg.AbcPath = "N/A";
  cfg.Z3Path = "N/A";
  cfg.GrainPath = "N/A";

  auto dirName = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                        {"unit-data", "inv_syn", "cnt2"});
  auto refDir = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                       {"unit-data", "inv_syn", "cnt2-abc"});
  os_portable_copy_dir(refDir, outDir);

  {
    auto inv_in =
        os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                               {"unit-data", "inv_syn", "inv_test", "inv.txt"});
    InvariantSynthesizerCegar vg(
        {}, // no include
        {os_portable_append_dir(dirName, P({"verilog", "opposite.v"}))},
        "opposite", // top_module_name
        os_portable_append_dir(dirName,
                               P({"rfmap", "vmap.json"})), // variable mapping
        os_portable_append_dir(dirName, P({"rfmap", "cond-noinv.json"})),
        outDir, ila_model.get(),
        ModelCheckerSelection::COSA,
        VerilogVerificationTargetGenerator::synthesis_backend_selector::ABC,
        cfg);

    EXPECT_FALSE(vg.in_bad_state());
    vg.LoadInvariantsFromFile(inv_in);
    ILA_DLOG(DBG_TAG) << "--- LOADED ---";
    for (auto&& v : vg.GetInvariants().GetVlgConstraints())
      ILA_DLOG(DBG_TAG) << "[" << v << "]";
    ILA_DLOG(DBG_TAG) << "--- END ---";

    vg.GenerateVerificationTarget();
    EXPECT_FALSE(vg.RunVerifAuto("INC", "", true));
    vg.ExtractVerificationResult();
    vg.GenerateSynthesisTarget(); // you will need fp engine
    EXPECT_FALSE(vg.RunSynAuto(true));
    EXPECT_DEATH(vg.ExtractSynthesisResult(), ".*");
    EXPECT_FALSE(vg.in_bad_state());

    EXPECT_EQ(vg.GetCandidateInvariants().NumInvariant(), 0);
    vg.GetInvariants().ExportToFile(os_portable_append_dir(outDir, "inv.txt"));
    EXPECT_EQ(vg.GetInvariants().NumInvariant(), 1);
  }

  {
    auto inv_in = os_portable_append_dir(
        std::string(ILANG_TEST_SRC_ROOT),
        {"unit-data", "inv_syn", "inv_test", "inv2.txt"});
    InvariantSynthesizerCegar vg(
        {}, // no include
        {os_portable_append_dir(dirName, P({"verilog", "opposite.v"}))},
        "opposite", // top_module_name
        os_portable_append_dir(dirName,
                               P({"rfmap", "vmap.json"})), // variable mapping
        os_portable_append_dir(dirName, P({"rfmap", "cond-noinv.json"})),
        outDir, ila_model.get(),
        ModelCheckerSelection::COSA,
        VerilogVerificationTargetGenerator::synthesis_backend_selector::ABC,
        cfg);

    EXPECT_FALSE(vg.in_bad_state());
    vg.LoadInvariantsFromFile(inv_in);

    vg.GenerateVerificationTarget();
    EXPECT_FALSE(vg.RunVerifAuto("INC", "", true));
    vg.ExtractVerificationResult();
    vg.GenerateSynthesisTarget(); // you will need fp engine
    EXPECT_FALSE(vg.RunSynAuto(true));
    vg.ExtractSynthesisResult();
    EXPECT_FALSE(vg.in_bad_state());

    EXPECT_EQ(vg.GetCandidateInvariants().NumInvariant(), 0);
    vg.GetInvariants().ExportToFile(os_portable_append_dir(outDir, "inv.txt"));
    EXPECT_EQ(vg.GetInvariants().NumInvariant(), 2);
  }

} // CegarCntAbc

TEST_F(TestVlgVerifInvSyn, CegarCntGrain) {
  auto ila_model = CntTest::BuildModel();

  RtlVerifyConfig cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = true;
  cfg.PonoAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = true; // let's test flatten datatype also
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.YosysUndrivenNetAsInput = true;
  cfg.YosysPath = "N/A";
  cfg.CosaPyEnvironment = "N/A";
  cfg.CosaPath = "N/A";
  cfg.AbcPath = "N/A";
  cfg.Z3Path = "N/A";
  cfg.GrainPath = "N/A";

  cfg.GrainHintsUseCnfStyle = true;
  cfg.GrainOptions = {"--skip-cnf --skip-const-check --skip-stat-collect "
                      "--ante-size 1 --conseq-size 1  --cnf cnt-no-group.cnf "
                      "--use-arith-bvnot --no-const-enum-vars-on m1.v,m1.imp"};

  auto dirName = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                        {"unit-data", "inv_syn", "cnt2"});
  auto refDir = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                       {"unit-data", "inv_syn", "cnt2-grain"});
  os_portable_copy_dir(refDir, outDir);

  InvariantInCnf var_in_cnf;
  { // save grammar file
    os_portable_mkdir(os_portable_append_dir(outDir, "inv-syn"));
    InvariantInCnf::clause cl;
    InvariantInCnf::VarsToClause({"m1.imp", "m1.v"}, cl);
    var_in_cnf.InsertClause(cl);
    std::ofstream fout(
        os_portable_append_dir(outDir, P({"inv-syn", "cnt-no-group.cnf"})));
    if (fout.is_open())
      var_in_cnf.ExportInCnfFormat(fout);
    else
      EXPECT_TRUE(false);
    fout.close();
  } // save grammar file

  InvariantSynthesizerCegar vg(
      {}, // no include
      {os_portable_append_dir(dirName, P({"verilog", "opposite.v"}))},
      "opposite", // top_module_name
      os_portable_append_dir(dirName,
                             P({"rfmap", "vmap.json"})), // variable mapping
      os_portable_append_dir(dirName, P({"rfmap", "cond-noinv.json"})), outDir,
      ila_model.get(),
      ModelCheckerSelection::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::GRAIN,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.ChangeGrainSyntax(
      {"--skip-cnf", "--skip-const-check", "--skip-stat-collect",
       "--ante-size 1", "--conseq-size 1", "--cnf cnt-no-group.cnf",
       "--use-arith-bvnot", "--no-const-enum-vars-on m1.v,m1.imp"});

  vg.GenerateVerificationTarget();
  EXPECT_FALSE(vg.RunVerifAuto("INC", "", true));
  vg.ExtractVerificationResult();
  vg.GenerateSynthesisTarget(); // you will need fp engine
  EXPECT_FALSE(vg.RunSynAuto(true));
  vg.ExtractSynthesisResult(); // very weired, it throw away something in arg
  EXPECT_FALSE(vg.in_bad_state());

} // CegarCntGrain

TEST_F(TestVlgVerifInvSyn, CegarCntGrainBackVars) {
  auto ila_model = CntTest::BuildModel();

  RtlVerifyConfig cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = true;
  cfg.PonoAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = true; // let's test flatten datatype also
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.YosysUndrivenNetAsInput = true;
  cfg.YosysPath = "N/A";
  cfg.CosaPyEnvironment = "N/A";
  cfg.CosaPath = "N/A";
  cfg.AbcPath = "N/A";
  cfg.Z3Path = "N/A";
  cfg.GrainPath = "N/A";

  cfg.GrainHintsUseCnfStyle = true;
  cfg.GrainOptions = {"--skip-cnf --skip-const-check --skip-stat-collect "
                      "--ante-size 1 --conseq-size 1  --cnf cnt-no-group.cnf "
                      "--use-arith-bvnot --no-const-enum-vars-on m1.v,m1.imp"};

  auto dirName = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                        {"unit-data", "inv_syn", "cnt2"});
  auto refDir =
      os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                             {"unit-data", "inv_syn", "cnt2-grain-back"});
  os_portable_copy_dir(refDir, outDir);

  InvariantInCnf var_in_cnf;
  { // save grammar file
    os_portable_mkdir(os_portable_append_dir(outDir, "inv-syn"));
    InvariantInCnf::clause cl;
    InvariantInCnf::VarsToClause({"m1.imp", "m1.v"}, cl);
    var_in_cnf.InsertClause(cl);
    std::ofstream fout(
        os_portable_append_dir(outDir, P({"inv-syn", "cnt-no-group.cnf"})));
    if (fout.is_open())
      var_in_cnf.ExportInCnfFormat(fout);
    else
      EXPECT_TRUE(false);
    fout.close();
  } // save grammar file

  InvariantSynthesizerCegar vg(
      {}, // no include
      {os_portable_append_dir(dirName, P({"verilog", "opposite.v"}))},
      "opposite", // top_module_name
      os_portable_append_dir(dirName,
                             P({"rfmap", "vmap.json"})), // variable mapping
      os_portable_append_dir(dirName, P({"rfmap", "cond-noinv.json"})), outDir,
      ila_model.get(),
      ModelCheckerSelection::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::GRAIN,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.ChangeGrainSyntax(
      {"--skip-cnf", "--skip-const-check", "--skip-stat-collect",
       "--ante-size 1", "--conseq-size 1", "--cnf cnt-no-group.cnf",
       "--use-arith-bvnot", "--no-const-enum-vars-on m1.v,m1.imp"});

  vg.GenerateVerificationTarget();
  EXPECT_FALSE(vg.RunVerifAuto("INC", "", true));
  vg.ExtractVerificationResult();
  vg.GenerateSynthesisTarget(); // you will need fp engine
  EXPECT_FALSE(vg.RunSynAuto(true));
  vg.ExtractSynthesisResult(); // very weired, it throw away something in arg
  EXPECT_FALSE(vg.in_bad_state());
  vg.GenerateInvariantVerificationTarget();
  vg.GenerateVerificationTarget();

} // CegarCntGrain

TEST_F(TestVlgVerifInvSyn, CegarPipelineAbcAigEnhance) {
  auto ila_model = SimplePipe::BuildModel();

  RtlVerifyConfig cfg;
  // cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.PonoAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = true; // for freqhorn
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.YosysPath = "N/A";
  cfg.CosaPyEnvironment = "N/A";
  cfg.CosaPath = "N/A";
  cfg.AbcPath = "N/A";
  cfg.Z3Path = "N/A";
  cfg.GrainPath = "N/A";
  cfg.AbcUseGla = true;
  cfg.AbcUseAiger = true;
  cfg.AbcUseCorr = false;
  cfg.CosaSolver = "btor";

  cfg.GrainOptions = {"--ante-size", "1", "--conseq-size", "1",
                      "--gen-spec-only"};

  auto dirName =
      os_portable_join_dir({ILANG_TEST_SRC_ROOT, "unit-data", "vpipe"});
  auto refDir = os_portable_join_dir({ILANG_TEST_SRC_ROOT, "unit-data",
                                      "inv_syn", "vpipe-out-abc-aig-enhance"});
  os_portable_copy_dir(refDir, outDir);

  InvariantSynthesizerCegar vg(
      {},                                                    // no include
      {os_portable_append_dir(dirName, "simple_pipe.v")},    //
      "pipeline_v",                                          // top_module_name
      os_portable_join_dir({dirName, "rfmap", "vmap.json"}), // variable mapping
      os_portable_join_dir({dirName, "rfmap", "cond-noinv.json"}), outDir,
      ila_model.get(),
      ModelCheckerSelection::COSA,
      VerilogVerificationTargetGenerator::synthesis_backend_selector::ABC, cfg);

  EXPECT_FALSE(vg.in_bad_state());

  /// The incremental cnf
  InvariantInCnf incremental_cnf;

  vg.GenerateVerificationTarget();
  EXPECT_FALSE(vg.RunVerifAuto("ADD", "", true)); // should continue : has cex
  vg.ExtractVerificationResult();
  vg.GenerateSynthesisTarget();
  EXPECT_FALSE(vg.RunSynAuto(true));

  vg.ExtractAbcSynthesisResultForEnhancement(incremental_cnf);
  { // what inv to enhance
    const auto& inv_to_enhance = vg.GetCandidateInvariants();
    EXPECT_EQ(inv_to_enhance.NumInvariant(), 1);
    if (inv_to_enhance.NumInvariant() >= 1)
      ILA_DLOG(DBG_TAG) << "INV to enhance:"
                        << inv_to_enhance.GetVlgConstraints()[0];
  }

  // This is the function we need to write
  EXPECT_TRUE(vg.WordLevelEnhancement(incremental_cnf, true));
  vg.MergeCnf(incremental_cnf);
  incremental_cnf.Clear();
  vg.ClearAllCandidateInvariants(); // already included (you can also accept but
                                    // unnecessary)

  vg.GetInvariants().ExportToFile(os_portable_append_dir(outDir, "inv.txt"));

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateInvariantVerificationTarget();
  auto design_stat = vg.GetDesignStatistics();
  ILA_INFO << "========== Design Info ==========";
  ILA_INFO << "#bits= " << design_stat.NumOfDesignStateBits;
  ILA_INFO << "#vars=" << design_stat.NumOfDesignStateVars;
  ILA_INFO << "#extra_bits= " << design_stat.NumOfExtraStateBits;
  ILA_INFO << "#extra_vars=" << design_stat.NumOfExtraStateVars;
  ILA_INFO << "t(eq)= " << design_stat.TimeOfEqCheck;
  ILA_INFO << "t(syn)=" << design_stat.TimeOfInvSyn;
  ILA_INFO << "t(proof)= " << design_stat.TimeOfInvProof;
  ILA_INFO << "t(validate)=" << design_stat.TimeOfInvValidate;
}

TEST_F(TestVlgVerifInvSyn, SimpleCntRelChc) {
  auto ila_model = CntTest::BuildModel();

  RtlVerifyConfig cfg;
  cfg.PonoAddKeep = false;
  cfg.YosysPath = "N/A";
  cfg.YosysSmtFlattenHierarchy = false;

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/cnt2/";
  VerilogVerificationTargetGenerator vg(
      {},                               // no include
      {dirName + "verilog/opposite.v"}, //
      "opposite",                       // top_module_name
      dirName + "rfmap/vmap.json",      // variable mapping
      dirName + "rfmap/cond-relchc.json", dirName + "out/", ila_model.get(),
      ModelCheckerSelection::RELCHC, cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST_F(TestVlgVerifInvSyn, SimpleCntRelChcNoStart) {
  auto ila_model = CntTest::BuildModel();

  RtlVerifyConfig cfg;
  cfg.PonoAddKeep = false;
  cfg.YosysPath = "N/A";
  cfg.YosysSmtFlattenHierarchy = false;
  cfg.VerificationSettingAvoidIssueStage = true;

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_syn/cnt2/";
  VerilogVerificationTargetGenerator vg(
      {},                               // no include
      {dirName + "verilog/opposite.v"}, //
      "opposite",                       // top_module_name
      dirName + "rfmap/vmap.json",      // variable mapping
      dirName + "rfmap/cond-relchc.json", dirName + "out-no-start/",
      ila_model.get(),
      ModelCheckerSelection::RELCHC, cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

#endif // ILANG_BUILD_INVSYN

}; // namespace ilang
