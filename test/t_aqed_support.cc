/// \file
/// Unit test for generating aqed-support

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ilang++.h>
#include <ilang/util/fs.h>
#include <ilang/aqed-out/aqed_out.h>

#include "unit-include/config.h"
#include "unit-include/pipe_ila.h"
#include "unit-include/util.h"


namespace ilang {

TEST(TestAqedSupport, PipeExample) {
  auto ila_model = SimplePipe::BuildModel();
  auto dirName = os_portable_append_dir(ILANG_TEST_DATA_DIR, "vpipe");
  auto VerilogPath = os_portable_append_dir(dirName, "simple_pipe.v");
  auto rfDir = os_portable_append_dir(dirName, "rfmap");
  auto OutputPath = os_portable_append_dir(dirName, "aqed");
  
  auto aqed_out = AQedInfoGenerator::Create(
    {}, // no include
    {VerilogPath},                // designs
    "pipeline_v",                 // top_module_name
    os_portable_append_dir(rfDir, "vmap.json"),         // variable mapping
    os_portable_append_dir(rfDir, "cond.json"),         // instruction-mapping
    ila_model.get());

  aqed_out->ExportVerilogTopLevelIOInfo(os_portable_append_dir(OutputPath , "io.txt"));
  aqed_out->ExportInstructionAndDecode (os_portable_append_dir(OutputPath , "decoder.v"));
  aqed_out->ExportExtraSignalReferenced(os_portable_append_dir(OutputPath , "var_ref.txt"));
}

} // namespace ilang

