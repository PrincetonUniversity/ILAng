/// \file
/// Unit test SMT parser

#include <iostream>
#include <sstream>
#include <ilang/smt-inout/smt_ast.h>
#include <ilang/smt-inout/chc_inv_in_wrapper.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

TEST(TestSmtParse, Parse) {
  auto fn = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/smt/pipeline_design.smt2";
  auto fo = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/smt/smt-out.smt2";
  
  std::ifstream fin(fn);
  std::stringstream buffer;
  buffer << fin.rdbuf();

  smt::smt_file smtinfo;
  smt::str_iterator smt_string_iterator(buffer.str());
  smt::ParseFromString(smt_string_iterator, smtinfo);

  {
    std::ofstream fout(fo);
    ILA_ERROR_IF(not fout.is_open()) << "Error writing to: " << fo;
    fout << smtinfo.toString();
  }
  // Expect no error...
}

TEST(TestSmtParse, ChcParse) {
  auto fn     = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/smt/aes.smt2";
  auto chc_fn = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/smt/aes-chc.chc";
  bool flatten_datatype = false;
  bool flatten_hierarchy = true;
  
  std::ifstream fin(fn);
  std::stringstream buffer;
  buffer << fin.rdbuf();
  
  smt::YosysSmtParser design_info(buffer.str());
  smt::SmtlibInvariantParserInstance chc_parser(
    &design_info,flatten_datatype,flatten_hierarchy,{"INV"},
    "m1");
  chc_parser.ParseInvResultFromFile(chc_fn);
  ILA_DLOG("TestSmtParse.ChcParse")
    << chc_parser.GetFinalTranslateResult();
}


}; // namespace ilang
