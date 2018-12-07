/// \file
/// Unit test for importing ILA from the synthesis engine

#include "unit-include/util.h"
#include <ilang/synth-interface/synth_engine_interface.h>

namespace ilang {

TEST(TestSynthImport, AES) {
  SetToStdErr(1);
  DebugLog::Enable("SynthImport");

  auto fileName = "test/unit-data/aes_v/all";
  auto m = ImportSynthAbsFromFile(fileName);

  DebugLog::Disable("SynthImport");
  SetToStdErr(0);
}

TEST(TestSynthImport, microAES) {
  SetToStdErr(1);
  DebugLog::Enable("SynthImport");

  auto fileName = "test/unit-data/aes_v/allu";
  auto m = ImportSynthAbsFromFile(fileName);

  DebugLog::Disable("SynthImport");
  SetToStdErr(0);
}

}; // namespace ilang

