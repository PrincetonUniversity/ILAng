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
  auto vtg_config = VerilogVerificationTargetGenerator::vtg_config_t();
  vtg_config.CosaGenJgTesterScript = true;

  VerilogVerificationTargetGenerator vg(
      {},                                                 // no include
      {os_portable_append_dir(dirName, "simple_pipe.v")}, // vlog files
      "pipeline_v",                                       // top_module_name
      os_portable_append_dir(rfDir, "vmap.json"),         // variable mapping
      os_portable_append_dir(rfDir, "cond.json"),         // instruction-mapping
      os_portable_append_dir(dirName, "verify"),          // verification dir
      ila_model.get(),                                    // ILA model
      VerilogVerificationTargetGenerator::backend_selector::COSA, // engine
      vtg_config);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, PipeExampleZ3) {
  auto ila_model = SimplePipe::BuildModel();

  auto dirName = os_portable_append_dir(ILANG_TEST_DATA_DIR, "vpipe");
  auto rfDir = os_portable_append_dir(dirName, "rfmap");
  auto vtg_config = VerilogVerificationTargetGenerator::vtg_config_t();
  vtg_config.YosysPath = "N/A";
  vtg_config.Z3Path = "N/A";

  VerilogVerificationTargetGenerator vg(
      {},                                                 // no include
      {os_portable_append_dir(dirName, "simple_pipe.v")}, // vlog files
      "pipeline_v",                                       // top_module_name
      os_portable_append_dir(rfDir, "vmap.json"),         // variable mapping
      os_portable_append_dir(rfDir, "cond.json"),         // instruction-mapping
      os_portable_append_dir(dirName, "verify-z3"),       // verification dir
      ila_model.get(),                                    // ILA model
      VerilogVerificationTargetGenerator::backend_selector::Z3PDR, // engine
      vtg_config);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, PipeExampleGrain) {
  auto ila_model = SimplePipe::BuildModel();

  auto dirName = os_portable_append_dir(ILANG_TEST_DATA_DIR, "vpipe");
  auto rfDir = os_portable_append_dir(dirName, "rfmap");
  auto vtg_config = VerilogVerificationTargetGenerator::vtg_config_t();
  vtg_config.YosysPath = "N/A";
  vtg_config.GrainPath = "N/A";
  vtg_config.YosysSmtFlattenDatatype = true;
  vtg_config.GrainHintsUseCnfStyle = true;
  vtg_config.GrainOptions = {
      "--skip-cnf --skip-const-check --skip-stat-collect --ante-size 1 "
      "--conseq-size 1  --cnf cnt-no-group.cnf --use-arith-bvnot "
      "--no-const-enum-vars-on m1.v,m1.imp"};

  VerilogVerificationTargetGenerator vg(
      {},                                                 // no include
      {os_portable_append_dir(dirName, "simple_pipe.v")}, // vlog files
      "pipeline_v",                                       // top_module_name
      os_portable_append_dir(rfDir, "vmap.json"),         // variable mapping
      os_portable_append_dir(rfDir, "cond.json"),         // instruction-mapping
      os_portable_append_dir(dirName, "verify-grain"),    // verification dir
      ila_model.get(),                                    // ILA model
      VerilogVerificationTargetGenerator::backend_selector::
          GRAIN_SYGUS, // engine
      vtg_config);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, PipeExampleGrainDeath) {
  auto ila_model = SimplePipe::BuildModel();

  auto dirName = os_portable_append_dir(ILANG_TEST_DATA_DIR, "vpipe");
  auto rfDir = os_portable_append_dir(dirName, "rfmap");
  auto vtg_config = VerilogVerificationTargetGenerator::vtg_config_t();
  vtg_config.YosysSmtFlattenDatatype = false;
  vtg_config.YosysPath = "N/A";
  vtg_config.GrainPath = "N/A";
  vtg_config.Z3Path = "N/A";

  VerilogVerificationTargetGenerator vg(
      {},                                                 // no include
      {os_portable_append_dir(dirName, "simple_pipe.v")}, // vlog files
      "pipeline_v",                                       // top_module_name
      os_portable_append_dir(rfDir, "vmap.json"),         // variable mapping
      os_portable_append_dir(rfDir, "cond.json"),         // instruction-mapping
      os_portable_append_dir(dirName, "verify-grain"),    // verification dir
      ila_model.get(),                                    // ILA model
      VerilogVerificationTargetGenerator::backend_selector::
          GRAIN_SYGUS, // engine
      vtg_config);

  EXPECT_FALSE(vg.in_bad_state());

  EXPECT_DEATH(vg.GenerateTargets(), ".*");
}

TEST(TestVlgTargetGen, PipeExampleEldaricaDeath) {
  auto ila_model = SimplePipe::BuildModel();

  auto dirName = os_portable_append_dir(ILANG_TEST_DATA_DIR, "vpipe");
  auto rfDir = os_portable_append_dir(dirName, "rfmap");
  auto vtg_config = VerilogVerificationTargetGenerator::vtg_config_t();
  vtg_config.YosysPath = "N/A";
  vtg_config.GrainPath = "N/A";
  vtg_config.Z3Path = "N/A";

  VerilogVerificationTargetGenerator vg(
      {},                                                 // no include
      {os_portable_append_dir(dirName, "simple_pipe.v")}, // vlog files
      "pipeline_v",                                       // top_module_name
      os_portable_append_dir(rfDir, "vmap.json"),         // variable mapping
      os_portable_append_dir(rfDir, "cond.json"),         // instruction-mapping
      os_portable_append_dir(dirName, "verify-grain"),    // verification dir
      ila_model.get(),                                    // ILA model
      VerilogVerificationTargetGenerator::backend_selector::ELD_CEGAR, // engine
      vtg_config);

  EXPECT_FALSE(vg.in_bad_state());

  EXPECT_DEATH(vg.GenerateTargets(), ".*");
}

TEST(TestVlgTargetGen, PipeExampleBtor) {
  auto ila_model = SimplePipe::BuildModel();

  auto dirName = os_portable_append_dir(ILANG_TEST_DATA_DIR, "vpipe");
  auto rfDir = os_portable_append_dir(dirName, "rfmap");
  auto vtg_config = VerilogVerificationTargetGenerator::vtg_config_t();
  vtg_config.YosysPath = "N/A";
  vtg_config.GrainPath = "N/A";
  vtg_config.Z3Path = "N/A";

  VerilogVerificationTargetGenerator vg(
      {},                                                 // no include
      {os_portable_append_dir(dirName, "simple_pipe.v")}, // vlog files
      "pipeline_v",                                       // top_module_name
      os_portable_append_dir(rfDir, "vmap.json"),         // variable mapping
      os_portable_append_dir(rfDir, "cond.json"),         // instruction-mapping
      os_portable_append_dir(dirName, "verify-btor"),     // verification dir
      ila_model.get(),                                    // ILA model
      VerilogVerificationTargetGenerator::backend_selector::
          BTOR_GENERIC, // engine
      vtg_config);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, PipeExampleAbc) {
  auto ila_model = SimplePipe::BuildModel();

  auto dirName = os_portable_append_dir(ILANG_TEST_DATA_DIR, "vpipe");
  auto rfDir = os_portable_append_dir(dirName, "rfmap");
  auto vtg_config = VerilogVerificationTargetGenerator::vtg_config_t();
  vtg_config.YosysPath = "N/A";
  vtg_config.GrainPath = "N/A";
  vtg_config.Z3Path = "N/A";
  vtg_config.AbcPath = "N/A";

  VerilogVerificationTargetGenerator vg(
      {},                                                 // no include
      {os_portable_append_dir(dirName, "simple_pipe.v")}, // vlog files
      "pipeline_v",                                       // top_module_name
      os_portable_append_dir(rfDir, "vmap.json"),         // variable mapping
      os_portable_append_dir(rfDir, "cond.json"),         // instruction-mapping
      os_portable_append_dir(dirName, "verify-abc"),      // verification dir
      ila_model.get(),                                    // ILA model
      VerilogVerificationTargetGenerator::backend_selector::ABCPDR, // engine
      vtg_config);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, PipeExampleRfmapPost) {
  auto ila_model = SimplePipe::BuildModel();

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
      VerilogVerificationTargetGenerator::backend_selector::COSA // engine
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
      VerilogVerificationTargetGenerator::backend_selector::JASPERGOLD);

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
      VerilogVerificationTargetGenerator::backend_selector::COSA);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

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
      VerilogVerificationTargetGenerator::backend_selector::COSA);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, MemoryInternal) { // test the expansion of memory

  auto ila_model = MemorySwap::BuildSimpleSwapModel();

  VerilogVerificationTargetGenerator::vtg_config_t
      vtg_cfg; // default configuration
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
      VerilogVerificationTargetGenerator::backend_selector::COSA, vtg_cfg,
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
      VerilogVerificationTargetGenerator::backend_selector::COSA);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, MemoryInternalExternalEntry6) {
  auto ila_model = MemorySwap::BuildRfAsMemModelRegEntry6();
  VlgVerifTgtGenBase::vtg_config_t vtg_cfg;
  vtg_cfg.CosaAddKeep = false;

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/vmem/";
  VerilogVerificationTargetGenerator vg(
      {},                            // no include
      {dirName + "rf_as_mem_6rf.v"}, // vlog files
      "proc",                        // top_module_name
      dirName + "vmap-rfarray.json", // variable mapping
      dirName + "cond-rfarray.json", // cond path
      dirName + "rfarray_rf6/",      // output path
      ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA, vtg_cfg);

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
      VerilogVerificationTargetGenerator::backend_selector::COSA);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, MemoryAbsRead) {
  VerilogVerificationTargetGenerator::vtg_config_t vtg_cfg;

  vtg_cfg.MemAbsReadAbstraction = true; // enable read abstraction

  auto ila_model = MemorySwap::BuildModel();

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/vmem/";
  VerilogVerificationTargetGenerator vg(
      {},                    // no include
      {dirName + "swap.v"},  // vlog files
      "swap",                // top_module_name
      dirName + "vmap.json", // variable mapping
      dirName + "cond.json", // cond path
      dirName + "rdabs/",    // output path
      ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA, vtg_cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, MemoryReadAbsRead) {
  VerilogVerificationTargetGenerator::vtg_config_t vtg_cfg;

  vtg_cfg.MemAbsReadAbstraction = true; // enable read abstraction

  auto ila_model = MemorySwap::BuildRdModel();

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/vmem/";
  VerilogVerificationTargetGenerator vg(
      {},                       // no include
      {dirName + "read.v"},     // vlog files
      "rdtop",                  // top_module_name
      dirName + "vmap-rd.json", // variable mapping
      dirName + "cond-rd.json", // cond path
      dirName + "rdabs/",       // output path
      ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA, vtg_cfg);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, MemoryReadAbsReadJasperGold) {
  VerilogVerificationTargetGenerator::vtg_config_t vtg_cfg;

  vtg_cfg.MemAbsReadAbstraction = true; // enable read abstraction

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
      VerilogVerificationTargetGenerator::backend_selector::JASPERGOLD,
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
      VerilogVerificationTargetGenerator::backend_selector::COSA);

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
      VerilogVerificationTargetGenerator::backend_selector::COSA);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, UndetFuncIteUnknown) {
  auto ila_model = UndetFunc::BuildIteUknModel();
  auto vtg_cfg = VerilogVerificationTargetGenerator::vtg_config_t();
  vtg_cfg.IteUnknownAutoIgnore = true;

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/undetf2/";
  VerilogVerificationTargetGenerator vg(
      {},                         // no include
      {dirName + "func.v"},       // vlog files
      "undetfunc",                // top_module_name
      dirName + "vmap-func.json", // variable mapping
      dirName + "cond-func.json", // cond path
      dirName,                    // output path
      ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA, vtg_cfg);

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
        VerilogVerificationTargetGenerator::backend_selector::COSA);

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
            {dirName, "rfmap", "vmap-e2.json"}), // variable mapping
        os_portable_join_dir({dirName, "rfmap", "cond.json"}), // cond path
        os_portable_append_dir(dirName, "out"),                // output path
        ila_model.get(),
        VerilogVerificationTargetGenerator::backend_selector::COSA);

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
            {dirName, "rfmap", "vmap-e3.json"}), // variable mapping
        os_portable_join_dir({dirName, "rfmap", "cond.json"}), // cond path
        os_portable_append_dir(dirName, "out"),                // output path
        ila_model.get(),
        VerilogVerificationTargetGenerator::backend_selector::COSA);

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
            {dirName, "rfmap", "vmap-e4.json"}), // variable mapping
        os_portable_join_dir({dirName, "rfmap", "cond.json"}), // cond path
        os_portable_append_dir(dirName, "out"),                // output path
        ila_model.get(),
        VerilogVerificationTargetGenerator::backend_selector::COSA);

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
        os_portable_append_dir(dirName, "out"),                // output path
        ila_model.get(),
        VerilogVerificationTargetGenerator::backend_selector::COSA);

    EXPECT_FALSE(vg.in_bad_state());

    vg.GenerateTargets();
  }
}

TEST(TestVlgTargetGen, ResetAnnotationZ3) {
  auto ila_model = MemorySwap::BuildResetterTest();
  auto dirName = os_portable_join_dir(
      {ILANG_TEST_SRC_ROOT, "unit-data", "vpipe", "reset"});

  auto vtg_config = VerilogVerificationTargetGenerator::vtg_config_t();
  vtg_config.YosysPath = "N/A";
  vtg_config.GrainPath = "N/A";
  vtg_config.Z3Path = "N/A";
  vtg_config.AbcPath = "N/A";

  VerilogVerificationTargetGenerator vg(
      {},                                                         // no include
      {os_portable_join_dir({dirName, "verilog", "resetter.v"})}, // vlog files
      "resetter",                                            // top_module_name
      os_portable_join_dir({dirName, "rfmap", "vmap.json"}), // variable mapping
      os_portable_join_dir({dirName, "rfmap", "cond.json"}), // cond path
      os_portable_append_dir(dirName, "out-z3"),             // output path
      ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::Z3PDR, vtg_config);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, ResetAnnotationABC) {
  auto ila_model = MemorySwap::BuildResetterTest();
  auto dirName = os_portable_join_dir(
      {ILANG_TEST_SRC_ROOT, "unit-data", "vpipe", "reset"});

  auto vtg_config = VerilogVerificationTargetGenerator::vtg_config_t();
  vtg_config.YosysPath = "N/A";
  vtg_config.GrainPath = "N/A";
  vtg_config.Z3Path = "N/A";
  vtg_config.AbcPath = "N/A";

  VerilogVerificationTargetGenerator vg(
      {},                                                         // no include
      {os_portable_join_dir({dirName, "verilog", "resetter.v"})}, // vlog files
      "resetter",                                            // top_module_name
      os_portable_join_dir({dirName, "rfmap", "vmap.json"}), // variable mapping
      os_portable_join_dir({dirName, "rfmap", "cond.json"}), // cond path
      os_portable_append_dir(dirName, "out-abc"),            // output path
      ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::ABCPDR, vtg_config);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, AesExample) {}

}; // namespace ilang
