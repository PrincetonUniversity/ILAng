/// file
/// Unit test for the Gaussian Blur case study.

#include "unit-include/config.h"
#include "unit-include/util.h"

#include <cstdio>

#include <ilang/ilang++.h>
#include <ilang/util/fs.h>

namespace ilang {

TEST(TestCase, GB_Import_Export_Import) {
  SetToStdErr(false);

  // get the abstraction
  auto gb_data_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "gb");

  auto gb_abst_top = os_portable_append_dir(gb_data_dir, "gb_top.ila");
  auto gb_ila = ImportSynthAbstraction(gb_abst_top, "gb_top");
  EXPECT_NE(gb_ila.name(), "");

  auto gb_abst_child = os_portable_append_dir(gb_data_dir, "gb_child.ila");
  ImportChildSynthAbstraction(gb_abst_child, gb_ila, "gb_child");

  // export
  auto tmp_file_name = std::tmpnam(NULL);
  ExportIlaPortable(gb_ila, tmp_file_name);

  // import
  auto read_back = ImportIlaPortable(tmp_file_name);

  EXPECT_EQ(read_back.state_num(), gb_ila.state_num());
  EXPECT_EQ(read_back.input_num(), gb_ila.input_num());
  EXPECT_EQ(read_back.instr_num(), gb_ila.instr_num());
  EXPECT_EQ(read_back.child_num(), gb_ila.child_num());

  SetToStdErr(false);
};

TEST(TestCase, GB_Import) {
  SetToStdErr(false);

  // get the ILA model
  auto gb_data_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "gb");
  auto gb_portable = os_portable_append_dir(gb_data_dir, "gb_low.json");

  auto gb_ila = ImportIlaPortable(gb_portable);

  EXPECT_GT(gb_ila.state_num(), 0);
  EXPECT_GT(gb_ila.input_num(), 0);
  EXPECT_GT(gb_ila.instr_num(), 0);
  EXPECT_GT(gb_ila.child_num(), 0);
  SetToStdErr(false);
};

}; // namespace ilang
