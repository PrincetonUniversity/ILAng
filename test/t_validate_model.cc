#include <ilang/ila/validate_model.h>
#include <ilang/ilang++.h>

#include <ilang/util/fs.h>
#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

TEST(TestValidateModel, deterministic_check) {
  auto aes_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "aes");
  auto aes_v_file = os_portable_append_dir(aes_dir, "aes_v.json");
  auto aes_v = ImportIlaPortable(aes_v_file);
  EXPECT_EQ(CheckDeterminism(aes_v.get()), true);
}

TEST(TestValidateModel, completeness) {
  auto aes_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "aes");
  auto aes_v_file = os_portable_append_dir(aes_dir, "aes_v.json");
  auto aes_v = ImportIlaPortable(aes_v_file);
  EXPECT_EQ(CheckCompleteness(aes_v.get()), false);
}

TEST(TestVlidateModel, complete_model_with_old_value) {
  auto aes_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "aes");
  auto aes_v_file = os_portable_append_dir(aes_dir, "aes_v.json");
  auto aes_v = ImportIlaPortable(aes_v_file);
 
  EXPECT_EQ(CheckCompleteness(aes_v.get()), false);
  CompleteModel(aes_v.get(), DEFAULT_UPDATE_METHOD::OLD_VALUE);
  EXPECT_EQ(CheckCompleteness(aes_v.get()), true);
}

TEST(TestVlidateModel, complete_model_with_nondet_value) {
  auto aes_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "aes");
  auto aes_v_file = os_portable_append_dir(aes_dir, "aes_v.json");
  auto aes_v = ImportIlaPortable(aes_v_file);
 
  EXPECT_EQ(CheckCompleteness(aes_v.get()), false);
  CompleteModel(aes_v.get(), DEFAULT_UPDATE_METHOD::NONDET_VALUE);
  EXPECT_EQ(CheckCompleteness(aes_v.get()), true);
}

} // namespace ilang
