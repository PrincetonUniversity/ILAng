/// \file
/// Unit test for utility functions

#include "unit-include/config.h"
#include "unit-include/util.h"
#include <ilang/util/fs.h>
#include <ilang/util/str_util.h>
#include <vector>

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
#else             // NDEBUG
  SetToStdErr(0); // not log to stderr
#endif            // NDEBUG
}

#define EXPECT_ERROR(m)                                                        \
  do {                                                                         \
    RecordLog();                                                               \
    std::string error_msg;                                                     \
    GET_STDERR_MSG(m, error_msg);                                              \
    EndRecordLog();                                                            \
  } while (0);

TEST(TestUtil, DirAppend) {

  EXPECT_EQ(os_portable_append_dir("/a", "b"), "/a/b");
  EXPECT_EQ(os_portable_append_dir("/a/", "b"), "/a/b");
  EXPECT_EQ(os_portable_append_dir("a/", "b"), "a/b");
  EXPECT_EQ(os_portable_append_dir("a", "b"), "a/b");
  EXPECT_EQ(os_portable_append_dir("a/", "./b"), "a/./b");
  EXPECT_EQ(os_portable_append_dir("/a/", "./b"), "/a/./b");

  EXPECT_ERROR(os_portable_append_dir("a", "/b"));
  EXPECT_ERROR(os_portable_append_dir("/a/", "/b"));
  EXPECT_ERROR(os_portable_append_dir("/a", "/b"));
}

TEST(TestUtil, FileNameFromDir) {

  EXPECT_EQ(os_portable_file_name_from_path("a"), "a");
  EXPECT_EQ(os_portable_file_name_from_path("a/b"), "b");
  EXPECT_EQ(os_portable_file_name_from_path("./a/b"), "b");

  EXPECT_ERROR(os_portable_file_name_from_path("a/"));
}

TEST(TestUtil, RemoveExtension) {

  EXPECT_EQ( os_portable_remove_file_name_extension("a"),     "a" );
  EXPECT_EQ( os_portable_remove_file_name_extension("a.txt"), "a" );
  EXPECT_EQ( os_portable_remove_file_name_extension("/a.txt"),"/a");

  EXPECT_EQ( os_portable_remove_file_name_extension("a/b.txt"),"a/b");
  EXPECT_EQ( os_portable_remove_file_name_extension("./a/b.txt"),"./a/b");
  EXPECT_EQ( os_portable_remove_file_name_extension("/a/.b.txt"),"/a/.b");

  // Yes, we are not removing thoroughly
  EXPECT_EQ( os_portable_remove_file_name_extension("/a/b.txt.1"),"/a/b.txt");
}

TEST(TestUtil, ExecShell) {
  auto scriptName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/shell_ex/shell.sh";
  std::vector<std::string> cmd;
  cmd.push_back("bash");
  cmd.push_back(scriptName);
  auto res = os_portable_execute_shell(cmd);
  EXPECT_EQ(res.failure, execute_result::NONE);
}

TEST(TestUtil, ExecShellOSPath) {
  auto scriptName = "ls";
  std::vector<std::string> cmd;
  cmd.push_back(scriptName);
  auto res = os_portable_execute_shell(cmd);
  EXPECT_EQ(res.failure, execute_result::NONE);
}


TEST(TestUtil, ExecShellRedirect) {
  auto redirect_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/shell_ex/date_out.txt";
  auto scriptName = "date";
  std::vector<std::string> cmd;
  cmd.push_back(scriptName);
  execute_result res;

  res = os_portable_execute_shell(cmd,redirect_file, BOTH);
  EXPECT_EQ(res.failure, execute_result::NONE);
  
  std::ifstream d1(redirect_file);
  std::string l1;

  EXPECT_TRUE(d1.is_open());
  if (d1.is_open()) {
    std::getline(d1,l1);
    d1.close();
  }
  
  sleep(2); // wait for at ~ 2 seconds

  res = os_portable_execute_shell(cmd,redirect_file, BOTH);
  EXPECT_EQ(res.failure, execute_result::NONE);

  std::ifstream d2(redirect_file);
  std::string l2;

  EXPECT_TRUE(d2.is_open());
  if (d2.is_open()) {
    std::getline(d2,l2);
    d2.close();
  }

  EXPECT_TRUE(l1 != l2);
}


TEST(TestUtil, ExecShellRedirectTimeOut) {
  auto redirect_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/shell_ex/sleep_out.txt";
  std::vector<std::string> s1cmd({"sleep", "1"});
  std::vector<std::string> s10cmd({"sleep", "10"});
  execute_result res;

  res = os_portable_execute_shell(s1cmd,redirect_file, BOTH, 5);
  EXPECT_TRUE(res.failure == execute_result::NONE);
  EXPECT_EQ(res.timeout, false);
  EXPECT_EQ(res.ret, 0);

  res = os_portable_execute_shell(s10cmd,redirect_file, BOTH, 2);
  EXPECT_EQ(res.failure, execute_result::NONE);
  EXPECT_EQ(res.timeout, true);
  // EXPECT_EQ(res.ret, 0); if timeout return value not usable

}


TEST(TestUtil, RegularExpr) {
  if (IsRExprUsable()) {
    auto l = ReFindList("s1 == 2", "[A-Za-z0-9]+");
    EXPECT_EQ(l.size(), 2);
    EXPECT_EQ(l[0], "s1");
    EXPECT_EQ(l[1], "2");

    auto l2 = ReFindAndDo("s1 == 2", "[A-Za-z0-9]+",
                          [](std::string s) -> std::string { return s; });

    EXPECT_EQ(l2.size(), 2);
    EXPECT_EQ(l2[0], "s1");
    EXPECT_EQ(l2[1], "2");
  }
}



} // namespace ilang
