/// \file
/// Unit tests for importing ILA from the synthesis engine

#include "unit-include/config.h"
#include "unit-include/util.h"
#include <ilang/synth-interface/synth_engine_interface.h>

namespace ilang {

TEST(TestSynthImport, AES) {
  SetToStdErr(1);
  // DebugLog::Enable("SynthImport");

  auto file_name = std::string(TEST_CONFIG_TEST_ROOT) + "/unit-data/aes_v/all";
  auto m = ImportSynthAbsFromFile(file_name, "AES");

  DebugLog::Disable("SynthImport");
  SetToStdErr(0);
}

TEST(TestSynthImport, microAES) {
  SetToStdErr(1);
  // DebugLog::Enable("SynthImport");

  auto file_name = std::string(TEST_CONFIG_TEST_ROOT) + "/unit-data/aes_v/allu";
  auto m = ImportSynthAbsFromFile(file_name, "AES_U");

  DebugLog::Disable("SynthImport");
  SetToStdErr(0);
}

TEST(TestSynthImport, AddChild) {
  SetToStdErr(1);
  // DebugLog::Enable("SynthImport");

  auto aes_file = std::string(TEST_CONFIG_TEST_ROOT) + "/unit-data/aes_v/all";
  auto aesu_file = std::string(TEST_CONFIG_TEST_ROOT) + "/unit-data/aes_v/allu";
  auto aes = ImportSynthAbsFromFile(aes_file, "AES");
  auto aesu = ImportSynthAbsFromFile(aesu_file, "AES_U");

  aes->AddChild(aesu);
  // aes->MergeChild();

  DebugLog::Disable("SynthImport");
  SetToStdErr(0);
}

TEST(TestSynthImport, PortChild) {
  SetToStdErr(1);
  // DebugLog::Enable("SynthImport");

  auto aes_file = std::string(TEST_CONFIG_TEST_ROOT) + "/unit-data/aes_v/all";
  auto aesu_file = std::string(TEST_CONFIG_TEST_ROOT) + "/unit-data/aes_v/allu";

  auto aes_ila = ImportSynthAbsFromFile(aes_file, "AES");
  auto aesu_ila = ImportSynthAbsFromFileHier(aesu_file, aes_ila, "AES_U");

  DebugLog::Disable("SynthImport");
  SetToStdErr(0);
}

}; // namespace ilang

