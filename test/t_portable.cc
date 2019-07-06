/// \file
/// Unit tests for exporting and importing ILA portables.

#include <ilang/ilang++.h>
#include <ilang/target-json/interface.h>
#include <ilang/util/fs.h>
#include <ilang/verification/legacy_bmc.h>

#include "unit-include/config.h"
#include "unit-include/util.h"
#include <z3++.h>

namespace ilang {

void Check(Ila& a, Ila& b) {
  auto ila = a.get();
  auto des = b.get();

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

void SerDes(const std::string& dir, const std::string& file) {
  auto file_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, dir);
  auto aes_file = os_portable_append_dir(file_dir, file);
  auto ila = ImportIlaPortable(aes_file);

  char tmp_file_template[] = "/tmp/ila_XXXXXX";
  auto tmp_file_name = GetRandomFileName(tmp_file_template);

  ExportIlaPortable(ila, tmp_file_name);
  auto des = ImportIlaPortable(tmp_file_name);

  Check(ila, des);
}

TEST(TestPortable, AES_V_TOP) { SerDes("aes", "aes_v_top.json"); }

TEST(TestPortable, AES_V_CHILD) { SerDes("aes", "aes_v_child.json"); }

TEST(TestPortable, AES_V) { SerDes("aes", "aes_v.json"); }

TEST(TestPortable, AES_C_TOP) { SerDes("aes", "aes_c_top.json"); }

TEST(TestPortable, AES_C_CHILD) { SerDes("aes", "aes_c_child.json"); }

TEST(TestPortable, AES_C) { SerDes("aes", "aes_c.json"); }

TEST(TestPortable, GB_LOW) { SerDes("gb", "gb_low.json"); }

TEST(TestPortable, RBM) { SerDes("rbm", "rbm.json"); }

} // namespace ilang
