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

TEST(TestVlgTargetGen, AesIlaInfo) {

  auto aesFile = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/aes_v/all";
  auto aesuFile = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/aes_v/allu";
  auto aes = ImportSynthAbsFromFile(aesFile, "AES");
  auto aesu = ImportSynthAbsFromFile(aesuFile, "AES_U");

  // aes->AddChild(aesu);

  ILA_DLOG("TestVlgTargetGen.IlaInfo") << "No. instr:" << aes->instr_num();
  for (unsigned i = 0; i < aes->instr_num(); ++i) {
    ILA_DLOG("TestVlgTargetGen.IlaInfo") << "\t" << aes->instr(i)->name().str()
                                         << "\t" << aes->instr(i)->decode();
  }
  ILA_DLOG("TestVlgTargetGen.IlaInfo") << "No. state:" << aes->state_num();
  for (unsigned i = 0; i < aes->state_num(); ++i) {
    ILA_DLOG("TestVlgTargetGen.IlaInfo") << "\t" << aes->state(i)->name().str();
  }
  ILA_DLOG("TestVlgTargetGen.IlaInfo") << std::endl;

  ILA_DLOG("TestVlgTargetGen.IlaInfo") << "No. instr:" << aesu->instr_num();
  for (unsigned i = 0; i < aes->instr_num(); ++i) {
    ILA_DLOG("TestVlgTargetGen.IlaInfo") << "\t" << aesu->instr(i)->name().str()
                                         << "\t" << aesu->instr(i)->decode();
  }
  ILA_DLOG("TestVlgTargetGen.IlaInfo") << "No. state:" << aesu->state_num();
  for (unsigned i = 0; i < aesu->state_num(); ++i) {
    ILA_DLOG("TestVlgTargetGen.IlaInfo")
        << "\t" << aesu->state(i)->name().str();
  }
  ILA_DLOG("TestVlgTargetGen.IlaInfo") << std::endl;
}

#ifdef VERILOG_IN_ENABLE

TEST(TestVlgTargetGen, PipeExample) {
  auto ila_model = SimplePipe::BuildModel();

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/";
  VerilogVerificationTargetGenerator vg(
      {},                          // no include
      {dirName + "simple_pipe.v"}, //
      "pipeline_v",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond.json", dirName + "verify/", ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, PipeExampleNotEqu) {
  auto ila_model = SimplePipe::BuildModel();

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/";
  VerilogVerificationTargetGenerator vg(
      {},                          // no include
      {dirName + "simple_pipe_wrong.v"}, //
      "pipeline_v",                // top_module_name
      dirName + "rfmap/vmap.json", // variable mapping
      dirName + "rfmap/cond.json", dirName + "disprove/", ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();
}

TEST(TestVlgTargetGen, Memory) {
  auto ila_model = MemorySwap::BuildModel();

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/vmem/";
  VerilogVerificationTargetGenerator vg(
      {},                    // no include
      {dirName + "swap.v"},  // vlog files
      "swap",                // top_module_name
      dirName + "vmap.json", // variable mapping
      dirName + "cond.json", // cond path
      dirName,               // output path
      ila_model.get(),
      VerilogVerificationTargetGenerator::backend_selector::COSA);

  EXPECT_FALSE(vg.in_bad_state());

  vg.GenerateTargets();

}



TEST(TestVlgTargetGen, AesExample) {}

#endif // VERILOG_IN_ENABLE

}; // namespace ilang
