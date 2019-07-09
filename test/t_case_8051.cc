/// file
/// Unit test for the 8051 case study.

#include <ilang/ilang++.h>
#include <ilang/util/fs.h>

#include <cstdio>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

TEST(TestCase, OC_Import_Export_Import) {
  SetToStdErr(false);

  // get the abstraction
  auto oc_data_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "oc");
  auto oc_abst_top = os_portable_append_dir(oc_data_dir, "oc.ila");
  auto oc_ila = ImportSynthAbstraction(oc_abst_top, "oc");
  EXPECT_NE(oc_ila.name(), "");

  // export
  char tmp_file_template[] = "/tmp/oc_ila_XXXXXX";
  auto tmp_file_name = GetRandomFileName(tmp_file_template);
  ExportIlaPortable(oc_ila, tmp_file_name);

  // import
  auto read_back = ImportIlaPortable(tmp_file_name);

  // clear
  auto res = std::remove(tmp_file_name.c_str());
  EXPECT_EQ(res, 0);

  EXPECT_EQ(read_back.state_num(), oc_ila.state_num());
  EXPECT_EQ(read_back.input_num(), oc_ila.input_num());
  EXPECT_EQ(read_back.instr_num(), oc_ila.instr_num());
  EXPECT_EQ(read_back.child_num(), oc_ila.child_num());

  SetToStdErr(false);
};

}; // namespace ilang
