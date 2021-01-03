/// \file
/// Unit test SMT translator

#include <ilang/smt-inout/yosys_smt_parser.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/str_util.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

TEST(TestSmtTrans, ReplaceAndAddKeep) {

  auto fn = os_portable_append_dir(
      ILANG_TEST_SRC_ROOT, {"unit-data", "smt", "pipeline_design.smt2"});
  auto fo = os_portable_append_dir(ILANG_TEST_SRC_ROOT,
                                   {"unit-data", "smt", "smt-out-trans.smt2"});

  std::ifstream fin(fn);
  EXPECT_TRUE(fin.is_open());
  if (!fin.is_open()) {
    ILA_ERROR << "Unable to read from " << fn;
    return;
  }
  std::stringstream buffer;
  buffer << fin.rdbuf();
  fin.close();

  smt::YosysSmtParser smt_in(buffer.str());
  smt_in.BreakDatatypes();
  smt_in.AddNoChangeStateUpdateFunction();

  {
    std::ofstream fout(fo);
    ILA_ERROR_IF(!fout.is_open()) << "Error writing to: " << fo;
    fout << smt_in.Export();
    fout.close();
    os_portable_remove_file(fo);
  }
}

}; // namespace ilang
