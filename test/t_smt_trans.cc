/// \file
/// Unit test SMT translator


#include <ilang/smt-inout/yosys_smt_parser.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

TEST(TestSmtTrans,ReplaceAndAddKeep) {

  auto fn = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/smt/pipeline_design.smt2";
  auto fo = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/smt/smt-out-trans.smt2";
  
  std::ifstream fin(fn);
  std::stringstream buffer;
  buffer << fin.rdbuf();

  smt::YosysSmtParser smt_in(buffer.str());
  smt_in.BreakDatatypes();
  smt_in.AddNoChangeStateUpdateFunction();

  {
    std::ofstream fout(fo);
    ILA_ERROR_IF(not fout.is_open()) << "Error writing to: " << fo;
    fout << smt_in.Export();
  }

}

}; // namespace ilang
