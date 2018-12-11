/// file
/// Unit test for the AES Verlog vs C equivalence checking.

#include "unit-include/config.h"
#include "unit-include/util.h"
#include <ilang/synth-interface/synth_engine_interface.h>

namespace ilang {

TEST(TestCase, AES_V_C_EQ) {
  SetToStdErr(1);
  DebugLog::Enable("EqCheck");
  DebugLog::Enable("Verbose-CrrEqCheck");

  // get the ILA model
  auto file_abs_aes_v_top = std::string(ILANG_TEST_SRC_ROOT) + "aes_v/all";
  auto file_abs_aes_v_child = std::string(ILANG_TEST_SRC_ROOT) + "aes_v/allu";
  auto file_abs_aes_c_top = std::string(ILANG_TEST_SRC_ROOT) + "aes_c/all";
  auto file_abs_aes_c_child = std::string(ILANG_TEST_SRC_ROOT) + "aes_c/allu";

  auto m_v = ImportSynthAbsFromFile(file_abs_aes_v_top, "AES_V");
  ASSERT_NE(m_v, nullptr);
  auto u_v = ImportSynthAbsFromFileHier(file_abs_aes_v_child, m_v, "AES_V_U");
  ASSERT_NE(u_v, nullptr);

  auto m_c = ImportSynthAbsFromFile(file_abs_aes_c_top, "AES_C");
  ASSERT_NE(m_c, nullptr);
  auto u_c = ImportSynthAbsFromFileHier(file_abs_aes_c_child, m_c, "AES_C_U");
  ASSERT_NE(u_c, nullptr);

  // define refinement relation

  // check

  SetToStdErr(0);
  DebugLog::Disable("EqCheck");
  DebugLog::Disable("Verbose-CrrEqCheck");
};

}; // namespace ilang

