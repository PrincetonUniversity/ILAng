/// file
/// Unit test for the Gaussian Blur case study.

#include "unit-include/config.h"
#include "unit-include/util.h"

#include <ilang/ilang++.h>
#include <ilang/util/fs.h>

namespace ilang {

#if 0
TEST(TestCase, GB_Convert_Export) {
  SetToStdErr(true);

  // get the abstraction
  auto gb_data_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "gb");

  // XXX need to expose the api
  auto gb_abst_top = os_portable_append_dir(gb_data_dir, "gb_top.ila");
  auto gb_ila = ImportSynthAbsFromFile(gb_abst_top, "gb_top");
  EXPECT_NE(gb_ila.name(), "");

  auto gb_abst_child = os_portable_append_dir(gb_data_dir, "gb_child.ila");
  auto child = ImportSynthAbsFromFileHier(gb_abst_child, gb_ila, "gb_child");
  EXPECT_NE(child.name(), "");

  // export
  IlaSerDesMngr::SerToFile(parent, "gb_low.json"); // FIXME tmp file name

#if 0
  EXPECT_GT(gb_ila.state_num(), 0);
  EXPECT_GT(gb_ila.input_num(), 0);
  EXPECT_GT(gb_ila.instr_num(), 0);
  EXPECT_GT(gb_ila.child_num(), 0);
#endif

  SetToStdErr(false);
};
#endif

TEST(TestCase, GB_Import) {
  SetToStdErr(true);

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
