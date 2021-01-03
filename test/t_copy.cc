/// \file
/// Unit tests for exporting and importing ILA portables.

#include <ilang/ila-mngr/u_abs_knob.h>
#include <ilang/ilang++.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

void Check(InstrLvlAbsPtr& a, InstrLvlAbsPtr& b) { CheckIlaEqLegacy(a, b); }

void Copy(const std::string& dir, const std::string& file, bool check = true) {
  SetLogLevel(0);
  auto file_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, dir);
  auto ila_file = os_portable_append_dir(file_dir, file);
  auto ila = ImportIlaPortable(ila_file).get();

  auto copy = absknob::CopyIlaTree(ila, "copied");

  if (check) {
    Check(ila, copy);
  }
}

TEST(TestCopyTree, AES_V_TOP) { Copy("aes", "aes_v_top.json"); }

TEST(TestCopyTree, AES_V_CHILD) { Copy("aes", "aes_v_child.json"); }

TEST(TestCopyTree, AES_V) { Copy("aes", "aes_v.json"); }

TEST(TestCopyTree, AES_C_TOP) { Copy("aes", "aes_c_top.json"); }

TEST(TestCopyTree, AES_C_CHILD) { Copy("aes", "aes_c_child.json"); }

TEST(TestCopyTree, AES_C) { Copy("aes", "aes_c.json"); }

TEST(TestCopyTree, GB_LOW) { Copy("gb", "gb_low.json"); }

TEST(TestCopyTree, RBM) { Copy("rbm", "rbm.json"); }

TEST(TestCopyTree, OC8051) { Copy("oc", "oc.json", false); }

} // namespace ilang
