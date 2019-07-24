#include <ilang/ila/validate_model.h>
#include "unit-include/config.h"
#include "unit-include/util.h"
#include "unit-include/validate_aes_model.h"

namespace ilang {

TEST(TestValidateModel, deterministic_check) {
  AES tested_model;
  EXPECT_EQ(CheckDeterminism(tested_model.model.get()), false);
}

TEST(TestValidateModel, completeness) {
  AES tested_model;
  EXPECT_EQ(CheckCompleteness(tested_model.model.get()), false);
}

TEST(TestVlidateModel, complete_model_with_old_value) {
  AES tested_model;
  EXPECT_EQ(CheckCompleteness(tested_model.model.get()), false);
  CompleteModel(tested_model.model.get(), DEFAULT_UPDATE_METHOD::OLD_VALUE);
  EXPECT_EQ(CheckCompleteness(tested_model.model.get()), true);
}

TEST(TestVlidateModel, complete_model_with_nondet_value) {
  AES tested_model;
  EXPECT_EQ(CheckCompleteness(tested_model.model.get()), false);
  CompleteModel(tested_model.model.get(), DEFAULT_UPDATE_METHOD::NONDET_VALUE);
  EXPECT_EQ(CheckCompleteness(tested_model.model.get()), true);
}

} // namespace ilang
