/// \file
/// Unit test SMT parser

#include <ilang/smt-inout/chc_inv_in_wrapper.h>
#include <ilang/smt-inout/smt_ast.h>
#include <ilang/util/fs.h>
#include <iostream>
#include <sstream>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

TEST(TestSmtParse, Type) {
  smt::var_type t1, t2;
  t1._type = smt::var_type::tp::Bool;
  t2._type = smt::var_type::tp::BV;
  EXPECT_FALSE(smt::var_type::eqtype(t1, t2));
  t1._type = smt::var_type::tp::Datatype;
  t1.module_name = "m1";
  EXPECT_FALSE(smt::var_type::eqtype(t1, t2));
  EXPECT_EQ(t1.toString(), "|m1_s|");

  EXPECT_EQ(smt::convert_to_binary(5, 4), "#b0101");
  EXPECT_EQ(smt::convert_to_binary("0011", 2, 4), "#b0011");
  EXPECT_EQ(smt::convert_to_binary("0011", 2, 5), "#b00011");
  EXPECT_EQ(smt::convert_to_binary("0011", 2, 3), "#b011");
}

TEST(TestSmtParse, Parse) {
  auto fn = os_portable_append_dir(
      ILANG_TEST_SRC_ROOT, {"unit-data", "smt", "pipeline_design.smt2"});
  auto fo = os_portable_append_dir(ILANG_TEST_SRC_ROOT,
                                   {"unit-data", "smt", "smt-out.smt2"});

  std::ifstream fin(fn);
  std::stringstream buffer;
  buffer << fin.rdbuf();
  fin.close();

  smt::smt_file smtinfo;
  smt::str_iterator smt_string_iterator(buffer.str());
  smt::ParseFromString(smt_string_iterator, smtinfo);

  {
    std::ofstream fout(fo);
    ILA_ERROR_IF(!fout.is_open()) << "Error writing to: " << fo;
    fout << smtinfo.toString();
    fout.close();
    os_portable_remove_file(fo);
  }
  // Expect no error...
}

#ifdef ILANG_BUILD_INVSYN

TEST(TestSmtParse, ChcParse) {
  auto fn = os_portable_append_dir(ILANG_TEST_SRC_ROOT,
                                   {"unit-data", "smt", "aes.smt2"});
  auto chc_fn = os_portable_append_dir(ILANG_TEST_SRC_ROOT,
                                       {"unit-data", "smt", "aes-chc.chc"});
  bool flatten_datatype = false;
  bool flatten_hierarchy = true;

  std::ifstream fin(fn);
  std::stringstream buffer;
  buffer << fin.rdbuf();
  fin.close();
  {
    smt::YosysSmtParser design_info(buffer.str());
    smt::SmtlibInvariantParserInstance chc_parser(
        &design_info, flatten_datatype, flatten_hierarchy, {"INV"}, "m1");
    chc_parser.ParseInvResultFromFile(chc_fn);
    ILA_INFO << chc_parser.GetFinalTranslateResult();
  }
  {
    std::string test_inv(R"##(
(forall ((A wrapper_s))
  (let ((a!1 (or (not (= (|wrapper#230| A) #b00110))
                 (not ((_ bit2bool 3) (|wrapper#41| A)))))
        (a!2 (or (not ((_ bit2bool 2) (|wrapper#41| A)))
                 (not (= (|wrapper#230| A) #b00000))))
        (a!3 (not (= ((_ extract 0 0) (|wrapper#41| A)) #b1)))
        (a!5 (not (= ((_ extract 2 2) (|wrapper#41| A)) #b1)))
        (a!7 (or (not (= (|wrapper#230| A) #b00010))
                 (not ((_ bit2bool 2) (|wrapper#41| A)))))
        (a!8 (or (not (= (|wrapper#230| A) #b00011))
                 (not ((_ bit2bool 1) (|wrapper#41| A)))
                 (not ((_ bit2bool 2) (|wrapper#41| A)))))
        (a!9 (or (not ((_ bit2bool 1) (|wrapper#41| A)))
                 (not (= (|wrapper#230| A) #b00000))))
        (a!10 (or (not (= (|wrapper#230| A) #b00111))
                  (not ((_ bit2bool 2) (|wrapper#41| A)))
                  (not ((_ bit2bool 3) (|wrapper#41| A)))))
        (a!11 (or (not (= (|wrapper#230| A) #b00001))
                  (not ((_ bit2bool 1) (|wrapper#41| A)))))
        (a!12 (or (not (= (|wrapper#230| A) #b00001))
                  (not ((_ bit2bool 3) (|wrapper#41| A)))))
        (a!13 (or (not (= (|wrapper#230| A) #b00010))
                  (not ((_ bit2bool 0) (|wrapper#41| A)))
                  (not ((_ bit2bool 1) (|wrapper#41| A)))))
        (a!14 (or (not (= (|wrapper#230| A) #b00010))
                  (not ((_ bit2bool 3) (|wrapper#41| A)))))
        (a!15 (or (not (= (|wrapper#230| A) #b00011))
                  (not ((_ bit2bool 0) (|wrapper#41| A)))
                  (not ((_ bit2bool 2) (|wrapper#41| A)))))
        (a!16 (or (not (= (|wrapper#230| A) #b00100))
                  (not ((_ bit2bool 1) (|wrapper#41| A)))
                  (not ((_ bit2bool 2) (|wrapper#41| A)))))
        (a!17 (or (not (= (|wrapper#230| A) #b00100))
                  (not ((_ bit2bool 3) (|wrapper#41| A)))))
        (a!18 (or (not (= (|wrapper#230| A) #b00011))
                  (not ((_ bit2bool 3) (|wrapper#41| A)))))
        (a!19 (or (not ((_ bit2bool 3) (|wrapper#41| A)))
                  (not (= (|wrapper#230| A) #b00000))))
        (a!20 (or (not (= (|wrapper#230| A) #b00101))
                  (not ((_ bit2bool 3) (|wrapper#41| A)))))
        (a!22 (or (not (= (|wrapper#230| A) #b01000))
                  (not ((_ bit2bool 1) (|wrapper#41| A)))
                  (not ((_ bit2bool 2) (|wrapper#41| A)))
                  (not ((_ bit2bool 3) (|wrapper#41| A)))))
        (a!23 (or (not (= (|wrapper#230| A) #b01000))
                  (not ((_ bit2bool 0) (|wrapper#41| A)))
                  (not ((_ bit2bool 2) (|wrapper#41| A)))
                  (not ((_ bit2bool 3) (|wrapper#41| A)))))
        (a!24 (or (not (= (|wrapper#230| A) #b00101))
                  (not ((_ bit2bool 0) (|wrapper#41| A)))
                  (not ((_ bit2bool 1) (|wrapper#41| A)))
                  (not ((_ bit2bool 2) (|wrapper#41| A)))))
        (a!25 (not (= ((_ extract 0 0) (|wrapper#244| A)) #b1))))
  (let ((a!4 (or a!3 (not (= (|wrapper#230| A) #b00000))))
        (a!6 (or (not (= (|wrapper#230| A) #b00001)) a!5))
        (a!21 (or (bvule #b01010 (|wrapper#230| A))
                  a!3
                  (not ((_ bit2bool 1) (|wrapper#41| A)))
                  (not ((_ bit2bool 2) (|wrapper#41| A)))
                  (not ((_ bit2bool 3) (|wrapper#41| A))))))
    (= (INV A)
       (and a!1
            a!2
            a!4
            a!6
            a!7
            a!8
            a!9
            a!10
            a!11
            a!12
            a!13
            a!14
            a!15
            a!16
            a!17
            a!18
            a!19
            a!20
            a!21
            a!22
            a!23
            a!24
            a!25)))))
    )##");

    smt::YosysSmtParser design_info(buffer.str());
    smt::SmtlibInvariantParserInstance chc_parser(
        &design_info, flatten_datatype, flatten_hierarchy, {"INV"}, "m1");

    chc_parser.ParseSmtResultFromString("(assert " + test_inv + ")");
    ILA_INFO << chc_parser.GetFinalTranslateResult();
  }
}
#endif // ILANG_BUILD_INVSYN

}; // namespace ilang
