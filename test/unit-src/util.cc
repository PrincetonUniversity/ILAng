/// \file
/// Helper functions

#include "../unit-include/util.h"

#include <cstdio>
#include <random>

#include <ilang/ila-mngr/v_eq_check_legacy_bmc.h>

namespace ilang {

static const std::string CHARACTERS =
    "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

std::string random_string(std::size_t length) {
  std::random_device random_device;
  std::mt19937 generator(random_device());
  std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

  std::string random_string;

  for (std::size_t i = 0; i < length; ++i) {
    random_string += CHARACTERS[distribution(generator)];
  }

  return random_string;
}

std::string GetRandomFileName(const std::string& dir) {
  auto root = fs::path(dir);
  if (dir.empty() || !fs::is_directory(dir)) {
    root = fs::temp_directory_path();
  }

  auto file_name = fs::path(random_string(6));
  while (fs::exists(root / file_name)) {
    file_name = fs::path(random_string(6));
  }
  return (root / file_name).string();
}

void CheckIlaEqLegacy(const InstrLvlAbsPtr& a, const InstrLvlAbsPtr& b) {
  auto ila = a;
  auto des = b;

  EXPECT_EQ(ila->state_num(), des->state_num());
  EXPECT_EQ(ila->instr_num(), des->instr_num());

  // eq check (no child)
  auto state_mapping = asthub::BoolConst(true);
  for (decltype(ila->state_num()) i = 0; i < ila->state_num(); i++) {
    auto var_org = ila->state(i);
    try {
      auto var_des = des->state(var_org->name().str());
      state_mapping = asthub::And(state_mapping, asthub::Eq(var_org, var_des));
    } catch (...) {
      ILA_WARN << "Fail automatically matching state vars";
    }
  }

  for (auto i = 0; i < ila->instr_num(); i++) {
    LegacyBmc bmc;

    auto decode = ila->instr(i)->decode();
    bmc.AddInit(decode);

    EXPECT_EQ(z3::unsat, bmc.Check(ila, 1, des, 1));
  }
}

}; // namespace ilang
