#include <ilang/ila/validate_model.h>

#include <string>

#include "unit-include/config.h"
#include "unit-include/util.h"
#include <ilang/ilang++.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>

namespace ilang {

class TestValidateModel : public ::testing::Test {
public:
  TestValidateModel() {}
  ~TestValidateModel() {}

  void SetUp() { SetToStdErr(1); }

  void TearDown() {}

  std::string msg;
};

TEST_F(TestValidateModel, deterministic_check) {
  auto aes_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "aes");
  auto aes_v_file = os_portable_append_dir(aes_dir, "aes_v.json");
  auto aes_v = ImportIlaPortable(aes_v_file);
  bool res = false;
  GET_STDERR_MSG(res = CheckDeterminism(aes_v.get()), msg);
  EXPECT_TRUE(res);
  EXPECT_TRUE(msg.empty());
}

TEST_F(TestValidateModel, nondeterministic_check) {
  auto aes_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "aes");
  auto aes_nondet_file = os_portable_append_dir(aes_dir, "aes_nondet.json");
  auto aes_nondet = ImportIlaPortable(aes_nondet_file);
  bool res = true;
  GET_STDERR_MSG(res = CheckDeterminism(aes_nondet.get()), msg);
  EXPECT_FALSE(res);
  EXPECT_FALSE(msg.empty());
}

TEST_F(TestValidateModel, completeness) {
  auto aes_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "aes");
  auto aes_v_file = os_portable_append_dir(aes_dir, "aes_v.json");
  auto aes_v = ImportIlaPortable(aes_v_file);
  bool res = true;
  GET_STDERR_MSG(res = CheckCompleteness(aes_v.get()), msg);
  EXPECT_FALSE(res);
  EXPECT_FALSE(msg.empty());
}

TEST_F(TestValidateModel, complete_model_with_old_value) {
  auto aes_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "aes");
  auto aes_v_file = os_portable_append_dir(aes_dir, "aes_v.json");
  auto aes_v = ImportIlaPortable(aes_v_file);
  bool res = true;

  GET_STDERR_MSG(res = CheckCompleteness(aes_v.get()), msg);
  EXPECT_FALSE(res);
  EXPECT_FALSE(msg.empty());

  CompleteModel(aes_v.get(), DEFAULT_UPDATE_METHOD::OLD_VALUE);

  GET_STDERR_MSG(res = CheckCompleteness(aes_v.get()), msg);
  EXPECT_TRUE(res);
  EXPECT_TRUE(msg.empty());
}

TEST_F(TestValidateModel, complete_model_with_nondet_value) {
  auto aes_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "aes");
  auto aes_v_file = os_portable_append_dir(aes_dir, "aes_v.json");
  auto aes_v = ImportIlaPortable(aes_v_file);
  bool res = true;

  GET_STDERR_MSG(res = CheckCompleteness(aes_v.get()), msg);
  EXPECT_FALSE(res);
  EXPECT_FALSE(msg.empty());

  CompleteModel(aes_v.get(), DEFAULT_UPDATE_METHOD::NONDET_VALUE);

  GET_STDERR_MSG(res = CheckCompleteness(aes_v.get()), msg);
  EXPECT_TRUE(res);
  EXPECT_TRUE(msg.empty());
}

} // namespace ilang
