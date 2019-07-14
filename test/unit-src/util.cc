/// \file
/// Helper functions

#include "../unit-include/util.h"

#include <cstdio>

#include <ilang/verification/legacy_bmc.h>

namespace ilang {

std::string GetRandomFileName(char* file_name_template) {
  ILA_NOT_NULL(file_name_template);

#ifdef __unix__
  auto res = mkstemp(file_name_template);
  ILA_CHECK(res != -1) << "Fail creating file";
  return static_cast<std::string>(file_name_template);

#elif __APPLE__
  auto res = mkstemp(file_name_template);
  ILA_CHECK(res != -1) << "Fail creating file";
  return static_cast<std::string>(file_name_template);

#else
  ILA_WARN << "tmpnam may be deprecated -- find alternatives";
  auto fn = std::tmpnam(NULL);
  return static_cast<std::string>(fn);

#endif
}

void CheckIlaEqLegacy(const InstrLvlAbsPtr& a, const InstrLvlAbsPtr& b) {
  auto ila = a;
  auto des = b;

  EXPECT_EQ(ila->state_num(), des->state_num());
  EXPECT_EQ(ila->instr_num(), des->instr_num());

  // eq check (no child)
  auto state_mapping = ExprFuse::BoolConst(true);
  for (decltype(ila->state_num()) i = 0; i < ila->state_num(); i++) {
    auto var_org = ila->state(i);
    try {
      auto var_des = des->state(var_org->name().str());
      state_mapping =
          ExprFuse::And(state_mapping, ExprFuse::Eq(var_org, var_des));
    } catch (...) {
      ILA_DLOG("Portable") << "Fail automatically matcing state vars";
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
