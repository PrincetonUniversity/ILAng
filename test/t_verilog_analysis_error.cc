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


void RecordLog() {
  // precondition for log test
  SetLogLevel(0); // log all
  SetLogPath(""); // log to /tmp
  SetToStdErr(1); // log to stderr for easy catching
}

void EndRecordLog() {
  // reset to default condition
  SetLogLevel(0); // log all
  SetLogPath(""); // log to /tmp
#ifndef NDEBUG
  SetToStdErr(0); // still log to stderr
#else               // NDEBUG
  SetToStdErr(0); // not log to stderr
#endif              // NDEBUG
}

#define EXPECT_ERROR( m ) do {        \
  RecordLog();                        \
  std::string error_msg;              \
  GET_STDERR_MSG( m , error_msg );    \
  EXPECT_FALSE(error_msg.empty());    \
  EndRecordLog();                     \
} while(0);


#define EXPECT_NO_ERROR( m ) do {        \
  RecordLog();                        \
  std::string error_msg;              \
  GET_STDERR_MSG( m , error_msg );    \
  EXPECT_TRUE(error_msg.empty());    \
  EndRecordLog();                     \
} while(0);


TEST(TestVerilogAnalysisErrHandling, NoDoubleInstance) {

  VerilogInfo va1(
      VerilogInfo::path_vec_t(),
      VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                               "/unit-data/verilog_sample/t_ana_inst.v"}),
      "m1");

  // you cannot create two instances 
  {
    EXPECT_ERROR(
      VerilogInfo va2(
          VerilogInfo::path_vec_t(),
          VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                   "/unit-data/verilog_sample/t_ana_inst.v"}),
          "m2")
    );

    EXPECT_TRUE(va2.in_bad_state());
    EXPECT_FALSE(va1.in_bad_state());
  }


  EXPECT_FALSE(va1.in_bad_state());

}


TEST(TestVerilogAnalysisErrHandling, VerilogFileNotFound) {
  EXPECT_ERROR(
    VerilogInfo va(
        VerilogInfo::path_vec_t(),
        VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                 "/unit-data/verilog_sample/errors/nonexisting.v"}),
        "m1")
  );

  EXPECT_TRUE(va.in_bad_state());
}

TEST(TestVerilogAnalysisErrHandling, VerilogSyntaxError) {
  EXPECT_ERROR(
    VerilogInfo va(
        VerilogInfo::path_vec_t(),
        VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                 "/unit-data/verilog_sample/errors/syntax_error.v"}),
        "m1")
  );

  EXPECT_TRUE(va.in_bad_state());
}

TEST(TestVerilogAnalysisErrHandling, EmptyModuleName) {
  EXPECT_ERROR(
    VerilogInfo va(
        VerilogInfo::path_vec_t(),
        VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                 "/unit-data/verilog_sample/errors/empty_mod_name.v"}),
        "m1")
  );

  EXPECT_TRUE(va.in_bad_state());
}

TEST(TestVerilogAnalysisErrHandling, ModuleRedecl) {
  EXPECT_ERROR(
    VerilogInfo va(
        VerilogInfo::path_vec_t(),
        VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                 "/unit-data/verilog_sample/errors/mod_redecl.v"}),
        "m1")
  );

  EXPECT_TRUE(va.in_bad_state());
}


TEST(TestVerilogAnalysisErrHandling, MissingModuleDecl) {

  EXPECT_ERROR(
    VerilogInfo va(
        VerilogInfo::path_vec_t(),
        VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                 "/unit-data/verilog_sample/errors/missing_mod_decl.v"}),
        "m1")
  );

  EXPECT_TRUE(va.in_bad_state());
}

TEST(TestVerilogAnalysisErrHandling, ModuleDeclLoop) {

  EXPECT_ERROR(
    VerilogInfo va(
        VerilogInfo::path_vec_t(),
        VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                 "/unit-data/verilog_sample/errors/mod_decl_loop.v"}),
        "m1")
  );

  EXPECT_TRUE(va.in_bad_state());
}

TEST(TestVerilogAnalysisErrHandling, NoSuchModuleAsTop) {

  
  { // expect no error
    EXPECT_NO_ERROR(
      VerilogInfo va(
          VerilogInfo::path_vec_t(),
          VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                   "/unit-data/verilog_sample/errors/mod_normal.v"}),
          "m1"
          )
    );

    EXPECT_FALSE(va.in_bad_state());
  }

  {
    EXPECT_ERROR(
      VerilogInfo va(
          VerilogInfo::path_vec_t(),
          VerilogInfo::path_vec_t({std::string(ILANG_TEST_SRC_ROOT) +
                                   "/unit-data/verilog_sample/errors/mod_normal.v"}),
          "m1",
          "nonexistingtopmodule")
    );

    EXPECT_TRUE(va.in_bad_state());
  }
}

TEST(TestVerilogAnalysisErrHandling, BadStateFunction) {

}

// a.b.c
TEST(TestVerilogAnalysisErrHandling, NoSuchHierarchySignal) {

}

TEST(TestVerilogAnalysisErrHandling, LastLevelModule) {

}

TEST(TestVerilogAnalysisErrHandling, NameRedecl) {

}

TEST(TestVerilogAnalysisErrHandling, InputRegNotAllowed) {

}



}; // namespace ilang