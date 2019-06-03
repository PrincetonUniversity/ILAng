/// \file
/// Unit tests for importing ILA from the synthesis engine

#include <ilang/target-itsy/interface.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

class TestSynthImport : public ::testing::Test {
public:
  TestSynthImport() {}
  ~TestSynthImport() {}
  void SetUp() {
    // SetToStdErr(1);
    DebugLog::Enable("SynthImport");
  }
  void TearDown() {
    DebugLog::Disable("SynthImport");
    // SetToStdErr(0);
  }

  const std::string test_data_root =
      std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/";

  const std::string file_abs_aes_v_top = test_data_root + "aes_v/all";
  const std::string file_abs_aes_v_child = test_data_root + "aes_v/allu";
  const std::string file_abs_aes_c_top = test_data_root + "aes_c/all";
  const std::string file_abs_aes_c_child = test_data_root + "aes_c/allu";

}; // class TestSynthImport

TEST_F(TestSynthImport, AES_V) {
  auto m = ImportSynthAbsFromFile(file_abs_aes_v_top, "AES");
  EXPECT_NE(m, nullptr);
}

TEST_F(TestSynthImport, AES_V_child) {
  auto m = ImportSynthAbsFromFile(file_abs_aes_v_child, "AES_U");
  EXPECT_NE(m, nullptr);
}

TEST_F(TestSynthImport, Add_child_AES_V) {
  auto aes = ImportSynthAbsFromFile(file_abs_aes_v_top, "AES");
  auto aesu = ImportSynthAbsFromFile(file_abs_aes_v_child, "AES_U");

  ASSERT_NE(aes, nullptr);
  ASSERT_NE(aesu, nullptr);

  aes->AddChild(aesu);
  auto child = aes->child("AES_U");
  EXPECT_EQ(child, aesu);
}

TEST_F(TestSynthImport, Port_child_AES_V) {
  auto aes = ImportSynthAbsFromFile(file_abs_aes_v_top, "AES");
  ASSERT_NE(aes, nullptr);

  auto aesu = ImportSynthAbsFromFileHier(file_abs_aes_v_child, aes, "AES_U");
  EXPECT_NE(aesu, nullptr);
}

TEST_F(TestSynthImport, AES_C) {
  auto m = ImportSynthAbsFromFile(file_abs_aes_c_top, "AES");
  EXPECT_NE(m, nullptr);
}

TEST_F(TestSynthImport, AES_C_child) {
  auto m = ImportSynthAbsFromFile(file_abs_aes_c_child, "AES_U");
  EXPECT_NE(m, nullptr);
}

TEST_F(TestSynthImport, Add_child_AES_C) {
  auto aes = ImportSynthAbsFromFile(file_abs_aes_c_top, "AES");
  ASSERT_NE(aes, nullptr);

  auto aesu = ImportSynthAbsFromFile(file_abs_aes_c_child, "AES_U");
  EXPECT_NE(aesu, nullptr);
}

TEST_F(TestSynthImport, Port_child_AES_C) {
  auto aes = ImportSynthAbsFromFile(file_abs_aes_c_top, "AES");
  ASSERT_NE(aes, nullptr);

  auto aesu = ImportSynthAbsFromFileHier(file_abs_aes_c_child, aes, "AES_U");
  EXPECT_NE(aesu, nullptr);
}

}; // namespace ilang
