/// \file
/// Unit test for importing ILA from the synthesis engine

#include "unit-include/util.h"
#include <ilang/synth-interface/synth_engine_mngr.h>

namespace ilang {

TEST(TestSynthImport, State) {
  SetToStdErr(1);
  DebugLog::Enable("SynthImport");

  auto fileName = "test/unit-data/aes_v/all";
  auto porter = SynEngMngr::New();
  auto m = porter->ImportIlaFromFile(fileName);

  DebugLog::Disable("SynthImport");
  SetToStdErr(0);
}

}; // namespace ilang

