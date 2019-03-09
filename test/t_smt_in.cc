/// \file
/// Unit test SMT parser

#include <iostream>
#include <sstream>
#include <ilang/smt-inout/smt_ast.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

TEST(TestSmtParse, Parse) {
  auto fn = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/smt/pipeline_design.smt2";
  auto fo = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/smt/smt-out.smt2";
  
  std::ifstream fin(fn);
  std::stringstream buffer;
  buffer << fin.rdbuf();

  smt_file smt;
  str_iterator smt_string_iterator(buffer.str());
  ParseFromString(smt_string_iterator, smt);

  {
    std::ofstream fout(fo);
    ILA_ERROR_IF(not fout.is_open()) << "Error writing to: " << fo;
    fout << smt.toString();
  }
  // Expect no error...
}

}; // namespace ilang
