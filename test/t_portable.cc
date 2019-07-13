/// \file
/// Unit tests for exporting and importing ILA portables.

#include <ilang/ilang++.h>
#include <ilang/target-json/interface.h>
#include <ilang/util/fs.h>

#include "unit-include/config.h"
#include "unit-include/util.h"
#include <z3++.h>

namespace ilang {

void Check(Ila& a, Ila& b) { CheckIlaEqLegacy(a.get(), b.get()); }

void SerDes(const std::string& dir, const std::string& file,
            bool check = true) {
  auto file_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, dir);
  auto aes_file = os_portable_append_dir(file_dir, file);
  auto ila = ImportIlaPortable(aes_file);

  char tmp_file_template[] = "/tmp/ila_XXXXXX";
  auto tmp_file_name = GetRandomFileName(tmp_file_template);

  ExportIlaPortable(ila, tmp_file_name);
  auto des = ImportIlaPortable(tmp_file_name);

  if (check) {
    Check(ila, des);
  }
}

TEST(TestPortable, AES_V_TOP) { SerDes("aes", "aes_v_top.json"); }

TEST(TestPortable, AES_V_CHILD) { SerDes("aes", "aes_v_child.json"); }

TEST(TestPortable, AES_V) { SerDes("aes", "aes_v.json"); }

TEST(TestPortable, AES_C_TOP) { SerDes("aes", "aes_c_top.json"); }

TEST(TestPortable, AES_C_CHILD) { SerDes("aes", "aes_c_child.json"); }

TEST(TestPortable, AES_C) { SerDes("aes", "aes_c.json"); }

TEST(TestPortable, GB_LOW) { SerDes("gb", "gb_low.json"); }

TEST(TestPortable, RBM) { SerDes("rbm", "rbm.json"); }

TEST(TestPortable, OC8051) { SerDes("oc", "oc.json", false); }

} // namespace ilang
