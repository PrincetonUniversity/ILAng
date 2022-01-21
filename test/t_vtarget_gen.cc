/// \file
/// Unit test for generating Verilog verification target

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ilang++.h>
#include <ilang/util/fs.h>
#include <ilang/vtarget-out/vtarget_gen.h>

#include "unit-include/config.h"
#include "unit-include/memswap.h"
#include "unit-include/pipe_ila.h"
#include "unit-include/util.h"

namespace ilang {

typedef std::vector<std::string> P;

TEST(TestVlgTargetGen, PipeExample) {
  auto ila_model = SimplePipe::BuildModel();

  auto dirName = os_portable_append_dir(ILANG_TEST_DATA_DIR, "vpipe");
  auto rfDir = os_portable_append_dir(dirName, "rfmap");
  auto vtg_config = RtlVerifyConfig();

  VerilogVerificationTargetGenerator vg(
      {},                                                 // no include
      {os_portable_append_dir(dirName, "simple_pipe.v")}, // vlog files
      "pipeline_v",                                       // top_module_name
      os_portable_append_dir(rfDir, "vmap.json"),         // variable mapping
      os_portable_append_dir(rfDir, "cond.json"),         // instruction-mapping
      os_portable_append_dir(dirName, "verify"),          // verification dir
      ila_model.get(),                                    // ILA model
      ModelCheckerSelection::PONO, // engine
      vtg_config);

  EXPECT_FALSE(vg.in_bad_state());
  vg.GenerateTargets();
}


TEST(TestVlgTargetGen, PipeExampleRfmapPost) {
  auto ila_model = SimplePipe::BuildModel();

  RtlVerifyConfig cfg;
  cfg.CheckInstrCommitSatisfiable = true;
  cfg.PonoGenJgScript = true;

  auto dirName = os_portable_append_dir(ILANG_TEST_DATA_DIR, "vpipe");
  auto rfDir = os_portable_append_dir(dirName, "rfmap");

  VerilogVerificationTargetGenerator vg(
      {},                                                 // no include
      {os_portable_append_dir(dirName, "simple_pipe.v")}, // vlog files
      "pipeline_v",                                       // top_module_name
      os_portable_append_dir(rfDir,
                             "vmap-rfmap-pvholder.json"), // variable mapping
      os_portable_append_dir(rfDir,
                             "cond-rfmap-pvholder.json"), // instruction-mapping
      os_portable_append_dir(dirName, "verify_pvholder"), // verification dir
      ila_model.get(),                                    // ILA model
      ModelCheckerSelection::PONO, // engine
      cfg
  );

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}


TEST(TestVlgTargetGen, PipeExampleRfmapPostResetStart) {
  auto ila_model = SimplePipe::BuildModel();
  RtlVerifyConfig cfg;
  cfg.PonoGenJgScript = true;
  cfg.ForceInstCheckReset = true;
  cfg.CheckInstrCommitSatisfiable = true;
  cfg.PonoOtherOptions = " -v 1 ";

  auto dirName = os_portable_append_dir(ILANG_TEST_DATA_DIR, "vpipe");
  auto rfDir = os_portable_append_dir(dirName, "rfmap");

  VerilogVerificationTargetGenerator vg(
      {},                                                 // no include
      {os_portable_append_dir(dirName, "simple_pipe.v")}, // vlog files
      "pipeline_v",                                       // top_module_name
      os_portable_append_dir(rfDir,
                             "vmap-rfmap-pvholder-reset.json"), // variable mapping
      os_portable_append_dir(rfDir,
                             "cond-rfmap-pvholder-reset.json"), // instruction-mapping
      os_portable_append_dir(dirName, "verify_pvholder_reset"), // verification dir
      ila_model.get(),                                    // ILA model
      ModelCheckerSelection::PONO, // engine
      cfg
  );

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, PipeStallRfmapShortNoValueHolder) {
  RtlVerifyConfig cfg;
  cfg.PonoEngine = "bmc";
  cfg.PonoOtherOptions = " -k 5 -v 1 ";

  auto ila_model = SimplePipe::BuildStallModel();

  auto dirName = os_portable_append_dir(ILANG_TEST_DATA_DIR, "vpipe");
  auto rfDir = os_portable_append_dir(dirName, "rfmap");

  VerilogVerificationTargetGenerator vg(
      {}, // no include
      {os_portable_append_dir(dirName,
                              "simple_pipe_stall_short.v")}, // vlog files
      "pipeline_v",                                          // top_module_name
      os_portable_append_dir(rfDir,
                             "vmap-rfmap-stall-short.json"), // variable mapping
      os_portable_append_dir(
          rfDir,
          "cond-rfmap-stall-short.json"), // instruction-mapping
      os_portable_append_dir(
          dirName, "verify_stall_short_nopvholder"), // verification dir
      ila_model.get(),                               // ILA model
      ModelCheckerSelection::PONO, // engine
      cfg
  );

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

// stall short has no instruction buffer
// it is 1 stage shorter than stall
TEST(TestVlgTargetGen, PipeStallRfmapShort) {
  RtlVerifyConfig cfg;
  cfg.PonoEngine = "bmc";
  cfg.PonoOtherOptions = " -k 5 -v 1 ";
  
  auto ila_model = SimplePipe::BuildStallModel();

  auto dirName = os_portable_append_dir(ILANG_TEST_DATA_DIR, "vpipe");
  auto rfDir = os_portable_append_dir(dirName, "rfmap");

  VerilogVerificationTargetGenerator vg(
      {}, // no include
      {os_portable_append_dir(dirName,
                              "simple_pipe_stall_short.v")}, // vlog files
      "pipeline_v",                                          // top_module_name
      os_portable_append_dir(
          rfDir,
          "vmap-rfmap-pvholder-stall-short.json"), // variable mapping
      os_portable_append_dir(
          rfDir,
          "cond-rfmap-pvholder-stall-short.json"), // instruction-mapping
      os_portable_append_dir(dirName, "verify_stall_short"), // verification dir
      ila_model.get(),                                       // ILA model
      ModelCheckerSelection::PONO, // engine
      cfg
  );

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, PipeStallRfmap) {
  RtlVerifyConfig cfg;
  cfg.PonoEngine = "bmc";
  cfg.PonoOtherOptions = " -k 5 -v 1 ";
  
  auto ila_model = SimplePipe::BuildStallModel();

  auto dirName = os_portable_append_dir(ILANG_TEST_DATA_DIR, "vpipe");
  auto rfDir = os_portable_append_dir(dirName, "rfmap");

  VerilogVerificationTargetGenerator vg(
      {},                                                       // no include
      {os_portable_append_dir(dirName, "simple_pipe_stall.v")}, // vlog files
      "pipeline_v", // top_module_name
      os_portable_append_dir(
          rfDir,
          "vmap-rfmap-pvholder-stall.json"), // variable mapping
      os_portable_append_dir(
          rfDir,
          "cond-rfmap-pvholder-stall.json"),           // instruction-mapping
      os_portable_append_dir(dirName, "verify_stall"), // verification dir
      ila_model.get(),                                 // ILA model
      ModelCheckerSelection::PONO, // engine
      cfg
  );

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

// test all kinds of rfmap issue
// test bad states

TEST(TestVlgTargetGen, PipeExampleJasperGold) {
  auto ila_model = SimplePipe::BuildModel();

  auto dirName =
      os_portable_join_dir({ILANG_TEST_SRC_ROOT, "unit-data", "vpipe"});
  VerilogVerificationTargetGenerator vg(
      {},                                                 // no include
      {os_portable_append_dir(dirName, "simple_pipe.v")}, //
      "pipeline_v",                                       // top_module_name
      os_portable_append_dir(dirName,
                             P({"rfmap", "vmap.json"})), // variable mapping
      os_portable_append_dir(dirName, P({"rfmap", "cond.json"})),
      os_portable_append_dir(dirName, "verify_jg/"), ila_model.get(),
      ModelCheckerSelection::JASPERGOLD);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, PipeExampleNotEqu) {
  auto ila_model = SimplePipe::BuildModel();

  auto dirName =
      os_portable_join_dir({ILANG_TEST_SRC_ROOT, "unit-data", "vpipe"});
  VerilogVerificationTargetGenerator vg(
      {},                                                       // no include
      {os_portable_append_dir(dirName, "simple_pipe_wrong.v")}, //
      "pipeline_v", // top_module_name
      os_portable_append_dir(dirName,
                             P({"rfmap", "vmap.json"})), // variable mapping
      os_portable_append_dir(dirName, P({"rfmap", "cond.json"})),
      os_portable_append_dir(dirName, "disprove/"), ila_model.get(),
      ModelCheckerSelection::PONO);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}


TEST(TestVlgTargetGen, PipeExampleNotEquFromReset) {
  auto ila_model = SimplePipe::BuildModel();
  RtlVerifyConfig cfg;
  cfg.ForceInstCheckReset = true;
  cfg.PonoGenJgScript = true;

  auto dirName =
      os_portable_join_dir({ILANG_TEST_SRC_ROOT, "unit-data", "vpipe"});
  VerilogVerificationTargetGenerator vg(
      {},                                                       // no include
      {os_portable_append_dir(dirName, "simple_pipe_wrong.v")}, //
      "pipeline_v", // top_module_name
      os_portable_append_dir(dirName,
                             P({"rfmap", "vmap.json"})), // variable mapping
      os_portable_append_dir(dirName, P({"rfmap", "cond.json"})),
      os_portable_append_dir(dirName, "disprove-reset/"), ila_model.get(),
      ModelCheckerSelection::PONO,
      cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

// #warning "Continue your test from here"

TEST(TestVlgTargetGen, Memory) {
  auto ila_model = MemorySwap::BuildModel();

  auto dirName =
      os_portable_join_dir({ILANG_TEST_SRC_ROOT, "unit-data", "vpipe", "vmem"});
  VerilogVerificationTargetGenerator vg(
      {},                                                // no include
      {os_portable_append_dir(dirName, "swap.v")},       // vlog files
      "swap",                                            // top_module_name
      os_portable_append_dir(dirName, P({"vmap.json"})), // variable mapping
      os_portable_append_dir(dirName, P({"cond.json"})),
      dirName, // output path
      ila_model.get(),
      ModelCheckerSelection::PONO);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, MemoryInternal) { // test the expansion of memory

  auto ila_model = MemorySwap::BuildSimpleSwapModel();

  RtlVerifyConfig vtg_cfg; // default configuration
  VerilogGeneratorBase::VlgGenConfig vlg_cfg;
  vlg_cfg.extMem = false;
  auto dirName =
      os_portable_join_dir({ILANG_TEST_SRC_ROOT, "unit-data", "vpipe", "vmem"});
  VerilogVerificationTargetGenerator vg(
      {},                                                  // no include
      {os_portable_append_dir(dirName, "swap_im.v")},      // vlog files
      "swap",                                              // top_module_name
      os_portable_append_dir(dirName, "vmap-expand.json"), // variable mapping
      os_portable_append_dir(dirName, "cond-expand.json"),
      dirName, // output path
      ila_model.get(),
      ModelCheckerSelection::PONO, vtg_cfg,
      vlg_cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, MemoryInternalExternal) {
  auto ila_model = MemorySwap::BuildRfAsMemModel();

  auto dirName =
      os_portable_join_dir({ILANG_TEST_SRC_ROOT, "unit-data", "vpipe", "vmem"});

  VerilogVerificationTargetGenerator vg(
      {},                                                   // no include
      {os_portable_append_dir(dirName, "rf_as_mem.v")},     // vlog files
      "proc",                                               // top_module_name
      os_portable_append_dir(dirName, "vmap-rfarray.json"), // variable mapping
      os_portable_append_dir(dirName, "cond-rfarray.json"),
      dirName, // output path
      ila_model.get(),
      ModelCheckerSelection::PONO);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, MemoryInternalExternalEntry6) {
  auto ila_model = MemorySwap::BuildRfAsMemModelRegEntry6();

  // DebugLog::Enable("VTG.ReplWireEq");
  // DebugLog::Enable("VTG.ReplAssert");
  // DebugLog::Enable("VTG.ReplAssume");

  // DebugLog::Enable("VTG.AddWireEq");
  // DebugLog::Enable("VTG.AddAssert");
  // DebugLog::Enable("VTG.AddAssume");

  RtlVerifyConfig vtg_cfg;
  vtg_cfg.PonoAddKeep = false;

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/vmem/";
  VerilogVerificationTargetGenerator vg(
      {},                             // no include
      {dirName + "rf_as_mem_6rf.v"},  // vlog files
      "proc",                         // top_module_name
      dirName + "vmap-rfarray6.json", // variable mapping
      dirName + "cond-rfarray.json",  // cond path
      dirName + "rfarray_rf6/",       // output path
      ila_model.get(),
      ModelCheckerSelection::PONO, vtg_cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, MemoryRead) {
  auto ila_model = MemorySwap::BuildRdModel();

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/vmem/";
  VerilogVerificationTargetGenerator vg(
      {},                       // no include
      {dirName + "read.v"},     // vlog files
      "rdtop",                  // top_module_name
      dirName + "vmap-rd.json", // variable mapping
      dirName + "cond-rd.json", // cond path
      dirName,                  // output path
      ila_model.get(),
      ModelCheckerSelection::PONO);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, MemoryReadAbsReadJasperGold) {
  RtlVerifyConfig vtg_cfg;

  auto ila_model = MemorySwap::BuildRdModel();

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/vmem/";
  VerilogVerificationTargetGenerator vg(
      {},                       // no include
      {dirName + "read.v"},     // vlog files
      "rdtop",                  // top_module_name
      dirName + "vmap-rd.json", // variable mapping
      dirName + "cond-rd.json", // cond path
      dirName + "rdabs_jg/",    // output path
      ila_model.get(),
      ModelCheckerSelection::JASPERGOLD,
      vtg_cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}


TEST(TestVlgTargetGen, MemoryForallEqualPono) {
  RtlVerifyConfig vtg_cfg;

  auto ila_model = MemorySwap::BuildSimpleLargeArray();

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/vmem/";
  VerilogVerificationTargetGenerator vg(
      {},                       // no include
      {dirName + "smallarray.v"},     // vlog files
      "top",                  // top_module_name
      dirName + "vmap-forall.json", // variable mapping
      dirName + "cond-forall.json", // cond path
      dirName + "large_small_forall/",    // output path
      ila_model.get(),
      ModelCheckerSelection::PONO,
      vtg_cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}


TEST(TestVlgTargetGen, MemoryForallEqualJg) {
  RtlVerifyConfig vtg_cfg;

  auto ila_model = MemorySwap::BuildSimpleLargeArray();

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/vmem/";
  VerilogVerificationTargetGenerator vg(
      {},                       // no include
      {dirName + "smallarray.v"},     // vlog files
      "top",                  // top_module_name
      dirName + "vmap-forall.json", // variable mapping
      dirName + "cond-forall.json", // cond path
      dirName + "large_small_forall_jg/",    // output path
      ila_model.get(),
      ModelCheckerSelection::JASPERGOLD,
      vtg_cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}


TEST(TestVlgTargetGen, UndetValue) {
  auto ila_model = UndetVal::BuildModel();

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/undetf/";
  VerilogVerificationTargetGenerator vg(
      {},                        // no include
      {dirName + "val.v"},       // vlog files
      "undetval",                // top_module_name
      dirName + "vmap-val.json", // variable mapping
      dirName + "cond-val.json", // cond path
      dirName,                   // output path
      ila_model.get(),
      ModelCheckerSelection::PONO);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, UndetFunc) {
  auto ila_model = UndetFunc::BuildModel();

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/undetf/";
  VerilogVerificationTargetGenerator vg(
      {},                         // no include
      {dirName + "func.v"},       // vlog files
      "undetfunc",                // top_module_name
      dirName + "vmap-func.json", // variable mapping
      dirName + "cond-func.json", // cond path
      dirName,                    // output path
      ila_model.get(),
      ModelCheckerSelection::PONO);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, ResetAnnotation) {
  {
    auto ila_model = MemorySwap::BuildResetterTest();
    auto dirName = os_portable_join_dir(
        {ILANG_TEST_SRC_ROOT, "unit-data", "vpipe", "reset"});

    VerilogVerificationTargetGenerator vg(
        {}, // no include
        {os_portable_join_dir(
            {dirName, "verilog", "resetter.v"})}, // vlog files
        "resetter",                               // top_module_name
        os_portable_join_dir(
            {dirName, "rfmap", "vmap-e1.json"}), // variable mapping
        os_portable_join_dir({dirName, "rfmap", "cond.json"}), // cond path
        os_portable_append_dir(dirName, "out"),                // output path
        ila_model.get(),
        ModelCheckerSelection::PONO);

    EXPECT_FALSE(vg.in_bad_state());

    vg.GenerateTargets();
  }
  {
    auto ila_model = MemorySwap::BuildResetterTest();
    auto dirName = os_portable_join_dir(
        {ILANG_TEST_SRC_ROOT, "unit-data", "vpipe", "reset"});

    VerilogVerificationTargetGenerator vg(
        {}, // no include
        {os_portable_join_dir(
            {dirName, "verilog", "resetter.v"})}, // vlog files
        "resetter",                               // top_module_name
        os_portable_join_dir(
            {dirName, "rfmap", "vmap.json"}), // variable mapping
        os_portable_join_dir({dirName, "rfmap", "cond.json"}), // cond path
        os_portable_append_dir(dirName, "out2"),               // output path
        ila_model.get(),
        ModelCheckerSelection::PONO);

    EXPECT_FALSE(vg.in_bad_state());

    vg.GenerateTargets();
  }
}

}; // namespace ilang
