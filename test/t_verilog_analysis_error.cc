/// \file
/// Unit test for Verilog analyzer.
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <ilang/util/container_shortcut.h>
#include <ilang/verilog-in/verilog_analysis_wrapper.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

#define EXPECT_ERROR(m)                                                        \
  do {                                                                         \
    RecordLog();                                                               \
    std::string error_msg;                                                     \
    GET_STDERR_MSG(m, error_msg);                                              \
    EndRecordLog();                                                            \
  } while (0);

#define EXPECT_ERROR_DEF(m)                                                    \
  RecordLog();                                                                 \
  std::string error_msg;                                                       \
  GET_STDERR_MSG(m, error_msg);                                                \
  EndRecordLog();

#define EXPECT_ERROR_MSG(m, msg)                                               \
  do {                                                                         \
    RecordLog();                                                               \
    std::string error_msg;                                                     \
    GET_STDERR_MSG(m, error_msg);                                              \
    EndRecordLog();                                                            \
  } while (0);

#define EXPECT_NO_ERROR(m)                                                     \
  do {                                                                         \
    RecordLog();                                                               \
    std::string error_msg;                                                     \
    GET_STDERR_MSG(m, error_msg);                                              \
    EXPECT_TRUE(error_msg.empty());                                            \
    EndRecordLog();                                                            \
  } while (0);

#define EXPECT_NO_ERROR_DEF(m)                                                 \
  RecordLog();                                                                 \
  std::string error_msg;                                                       \
  GET_STDERR_MSG(m, error_msg);                                                \
  EXPECT_TRUE(error_msg.empty());                                              \
  EndRecordLog();

TEST(TestVerilogAnalysisErrHandling, NoDoubleInstance) {

  VerilogInfo va1(
      VerilogInfo::path_vec_t(),
      VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                               "/unit-data/verilog_sample/t_ana_inst.v"}),
      "m1");

  // you cannot create two instances
  {
    EXPECT_ERROR_DEF(VerilogInfo va2(
        VerilogInfo::path_vec_t(),
        VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                 "/unit-data/verilog_sample/t_ana_inst.v"}),
        "m2"));

    EXPECT_TRUE(va2.in_bad_state());
    EXPECT_FALSE(va1.in_bad_state());

    EXPECT_ERROR(EXPECT_EQ(va2.check_hierarchical_name_type("nonexistingname"),
                           VerilogAnalyzerBase::hierarchical_name_type::NONE));
    EXPECT_ERROR(va2.get_module_inst_loc("nonexistingmodule"));
    EXPECT_ERROR(EXPECT_EQ(va2.find_declaration_of_name("nonexistingname"),
                           (void*)NULL));
    EXPECT_ERROR(EXPECT_EQ(va2.name2loc("nonexistingname"),
                           VerilogAnalyzerBase::vlg_loc_t()));
    EXPECT_ERROR(va2.get_signal("nonexistingname"));
    EXPECT_ERROR(va2.get_top_module_io());
    EXPECT_ERROR(va2.get_endmodule_loc("nonexistingname"));
  }

  EXPECT_FALSE(va1.in_bad_state());
}

TEST(TestVerilogAnalysisErrHandling, EmptyFile) {
  EXPECT_ERROR_DEF(VerilogInfo va(
      VerilogInfo::path_vec_t(),
      VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                               "/unit-data/verilog_sample/errors/empty.v"}),
      "m1"));

  EXPECT_TRUE(va.in_bad_state());
}

TEST(TestVerilogAnalysisErrHandling, VerilogFileNotFound) {
  EXPECT_ERROR_DEF(
      VerilogInfo va(VerilogInfo::path_vec_t(),
                     VerilogInfo::path_vec_t(
                         {std::string(ILANG_TEST_SRC_ROOT) +
                          "/unit-data/verilog_sample/errors/nonexisting.v"}),
                     "m1"));

  EXPECT_TRUE(va.in_bad_state());
}

TEST(TestVerilogAnalysisErrHandling, VerilogSyntaxError) {
  EXPECT_ERROR_DEF(
      VerilogInfo va(VerilogInfo::path_vec_t(),
                     VerilogInfo::path_vec_t(
                         {std::string(ILANG_TEST_SRC_ROOT) +
                          "/unit-data/verilog_sample/errors/syntax_error.v"}),
                     "m1"));

  EXPECT_TRUE(va.in_bad_state());
}

TEST(TestVerilogAnalysisErrHandling, EmptyModuleName) {
  EXPECT_ERROR_DEF(
      VerilogInfo va(VerilogInfo::path_vec_t(),
                     VerilogInfo::path_vec_t(
                         {std::string(ILANG_TEST_SRC_ROOT) +
                          "/unit-data/verilog_sample/errors/empty_mod_name.v"}),
                     "m1"));

  EXPECT_TRUE(va.in_bad_state());
}

TEST(TestVerilogAnalysisErrHandling, ModuleRedecl) {
  EXPECT_ERROR_DEF(
      VerilogInfo va(VerilogInfo::path_vec_t(),
                     VerilogInfo::path_vec_t(
                         {std::string(ILANG_TEST_SRC_ROOT) +
                          "/unit-data/verilog_sample/errors/mod_redecl.v"}),
                     "m1"));

  EXPECT_FALSE(va.in_bad_state()); // will ignore the decl
}

TEST(TestVerilogAnalysisErrHandling, MissingModuleDecl) {

  EXPECT_ERROR_DEF(VerilogInfo va(
      VerilogInfo::path_vec_t(),
      VerilogInfo::path_vec_t(
          {std::string(ILANG_TEST_SRC_ROOT) +
           "/unit-data/verilog_sample/errors/missing_mod_decl.v"}),
      "m1"));

  EXPECT_FALSE(va.in_bad_state()); // will ignore the error and continue
}

TEST(TestVerilogAnalysisErrHandling, ModuleDeclLoop) {

  EXPECT_ERROR_DEF(
      VerilogInfo va(VerilogInfo::path_vec_t(),
                     VerilogInfo::path_vec_t(
                         {std::string(ILANG_TEST_SRC_ROOT) +
                          "/unit-data/verilog_sample/errors/mod_decl_loop.v"}),
                     "m1"));

  EXPECT_TRUE(va.in_bad_state());
}

TEST(TestVerilogAnalysisErrHandling, NoSuchModuleAsTop) {

  { // expect no error
    EXPECT_NO_ERROR_DEF(
        VerilogInfo va(VerilogInfo::path_vec_t(),
                       VerilogInfo::path_vec_t(
                           {std::string(ILANG_TEST_SRC_ROOT) +
                            "/unit-data/verilog_sample/errors/mod_normal.v"}),
                       "m1"));

    EXPECT_FALSE(va.in_bad_state());

    EXPECT_EQ(va.check_hierarchical_name_type("m1.f2.f"),
              VerilogAnalyzerBase::hierarchical_name_type::NONE);

    EXPECT_EQ(va.check_hierarchical_name_type("m1.f.f2"),
              VerilogAnalyzerBase::hierarchical_name_type::NONE);

    EXPECT_EQ(va.check_hierarchical_name_type("m1.f.f"),
              VerilogAnalyzerBase::hierarchical_name_type::MODULE);

    EXPECT_EQ(
        va.check_hierarchical_name_type("m1.f.in"),
        VerilogAnalyzerBase::hierarchical_name_type::I_WIRE_wo_INTERNAL_DEF);

    EXPECT_TRUE(va.name2loc("m1.f.in").second != 0);

    auto sg_nonexisting_info = va.get_signal("nonexistingname");
    auto sg_no_internal_wire = va.get_signal("m1.f.in");

    EXPECT_ERROR(va.get_signal("m1.f"));
    EXPECT_TRUE(sg_nonexisting_info.is_bad_signal());
    EXPECT_EQ(sg_nonexisting_info.get_decl_loc().second, 0L);
    EXPECT_ERROR(va.get_endmodule_loc("m1.f.in")); // not a module name

    EXPECT_NO_ERROR(EXPECT_TRUE(va.get_module_inst_loc("m1.f.f").second != 0));
    EXPECT_ERROR(va.get_module_inst_loc("m1.f1.f"));
    EXPECT_ERROR(va.get_module_inst_loc("m1.f.f1"));
    EXPECT_ERROR(va.get_module_inst_loc("m.f.f1"));
  }

  {
    EXPECT_ERROR_DEF(
        VerilogInfo va(VerilogInfo::path_vec_t(),
                       VerilogInfo::path_vec_t(
                           {std::string(ILANG_TEST_SRC_ROOT) +
                            "/unit-data/verilog_sample/errors/mod_normal.v"}),
                       "m1", "nonexistingtopmodule"));

    EXPECT_TRUE(va.in_bad_state());
  }
}

TEST(TestVerilogAnalysisErrHandling, TwoTop) {
  // expect no error
  EXPECT_ERROR_DEF(VerilogInfo va(
      VerilogInfo::path_vec_t(),
      VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                               "/unit-data/verilog_sample/errors/whichtop.v"}),
      "m1"));

  EXPECT_FALSE(va.in_bad_state());
}

TEST(TestVerilogAnalysisErrHandling, SigRedecl) {
  // expect no error
  EXPECT_NO_ERROR_DEF(VerilogInfo va(
      VerilogInfo::path_vec_t(),
      VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                               "/unit-data/verilog_sample/errors/sigredecl.v"}),
      "m1"));

  EXPECT_FALSE(va.in_bad_state());

  EXPECT_ERROR(va.check_hierarchical_name_type("m1.a"));
  EXPECT_ERROR(va.check_hierarchical_name_type("m1.b"));
  EXPECT_ERROR(va.check_hierarchical_name_type("m1.full"));
  EXPECT_NO_ERROR(va.check_hierarchical_name_type("m1.p"));
  EXPECT_NO_ERROR(va.check_hierarchical_name_type("m1.q"));
  EXPECT_NO_ERROR(va.check_hierarchical_name_type("m1.ro"));
  EXPECT_NO_ERROR(va.check_hierarchical_name_type("m1.roi"));
}

TEST(TestVerilogAnalysisErrHandling, UnknownPortDirection) {
  // expect no error
  EXPECT_NO_ERROR_DEF(VerilogInfo va(
      VerilogInfo::path_vec_t(),
      VerilogInfo::path_vec_t(
          {std::string(ILANG_TEST_SRC_ROOT) +
           "/unit-data/verilog_sample/errors/unknown_port_dir.v"}),
      "m1"));
  // this tells us if it is not defined inside, it will not be created
  EXPECT_EQ(va.check_hierarchical_name_type("m1.clk"),
            VerilogAnalyzerBase::hierarchical_name_type::NONE);
  EXPECT_ERROR(va.check_hierarchical_name_type("m1.rst"));
  EXPECT_ERROR(va.check_hierarchical_name_type("m1.full"));
}

}; // namespace ilang