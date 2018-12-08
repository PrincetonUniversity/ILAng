/// \file
/// Unit test for importing ILA from the synthesis engine

#include "unit-include/util.h"
#include <ilang/synth-interface/synth_engine_interface.h>

namespace ilang {

TEST(TestSynthImport, AES) {
  SetToStdErr(1);
  // DebugLog::Enable("SynthImport");

  auto fileName = "test/unit-data/aes_v/all";
  auto m = ImportSynthAbsFromFile(fileName, "AES");

  DebugLog::Disable("SynthImport");
  SetToStdErr(0);
}

TEST(TestSynthImport, microAES) {
  SetToStdErr(1);
  // DebugLog::Enable("SynthImport");

  auto fileName = "test/unit-data/aes_v/allu";
  auto m = ImportSynthAbsFromFile(fileName, "AES_U");

  DebugLog::Disable("SynthImport");
  SetToStdErr(0);
}

TEST(TestSynthImport, AddChild) {
  SetToStdErr(1);
  // DebugLog::Enable("SynthImport");

  auto aesFile = "test/unit-data/aes_v/all";
  auto aesuFile = "test/unit-data/aes_v/allu";
  auto aes = ImportSynthAbsFromFile(aesFile, "AES");
  auto aesu = ImportSynthAbsFromFile(aesuFile, "AES_U");

  aes->AddChild(aesu);
  // aes->MergeChild();

  DebugLog::Disable("SynthImport");
  SetToStdErr(0);
}

TEST(TestSynthImport, PortChild) {
  SetToStdErr(1);
  // DebugLog::Enable("SynthImport");

  auto aesFile = "test/unit-data/aes_v/all";
  auto aesuFile = "test/unit-data/aes_v/allu";

  auto aes_ila = ImportSynthAbsFromFile(aesFile, "AES");
  auto aesu_ila = ImportSynthAbsFromFileHier(aesuFile, aes_ila, "AES_U");

  DebugLog::Disable("SynthImport");
  SetToStdErr(0);
}

}; // namespace ilang

