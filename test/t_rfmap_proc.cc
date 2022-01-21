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

TEST(TestRfmapProcess, TypeResolve) {
  auto ila_model = SimplePipe::BuildModel();

  auto dirName = os_portable_append_dir(ILANG_TEST_DATA_DIR, "vpipe");
  auto rfDir = os_portable_append_dir(dirName, "rfmap_t");
  auto outDir = os_portable_append_dir(os_portable_append_dir(dirName, "rfmap_t_out"), "t1");
  auto vtg_config = RtlVerifyConfig();

  VerilogVerificationTargetGenerator vg(
      {},                                                 // no include
      {os_portable_append_dir(dirName, "simple_pipe.v")}, // vlog files
      "pipeline_v",                                       // top_module_name
      os_portable_append_dir(rfDir, "vmap-1.json"),         // variable mapping
      os_portable_append_dir(rfDir, "cond-1.json"),         // instruction-mapping
      outDir,          // verification dir
      ila_model.get(),                                    // ILA model
      ModelCheckerSelection::PONO, // engine
      vtg_config);

  EXPECT_FALSE(vg.in_bad_state());
  vg.GenerateTargets();
} // TEST(TestRfmapProcess, TypeResolve) 


}; // namespace ilang
