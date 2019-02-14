/// \file
/// Unit tests for exporting and importing ILA portables.

#include "unit-include/config.h"
#include "unit-include/util.h"
#include <ilang/portable/interface.h>
#include <ilang/synth-interface/synth_engine_interface.h>

namespace ilang {

TEST(TestPortable, AES) {
  SetToStdErr(1);
  DebugLog::Enable("Portable");

  auto aes_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/aes_v/all";
  auto aesu_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/aes_v/allu";

  auto aes_ila = ImportSynthAbsFromFile(aes_file, "AES");
  auto aesu_ila = ImportSynthAbsFromFileHier(aesu_file, aes_ila, "AES_U");

  // TODO
  IlaSerDesMngr::Serialize(aes_ila);

  DebugLog::Disable("Portable");
  SetToStdErr(0);
}

} // namespace ilang
