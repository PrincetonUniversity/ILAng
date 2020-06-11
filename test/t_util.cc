/// \file
/// Unit test for utility functions

#include <vector>

#include <ilang/util/fs.h>
#include <ilang/util/str_util.h>

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
  SetToStdErr(0); // not log to stderr
}

#define EXPECT_ERROR(m)                                                        \
  do {                                                                         \
    RecordLog();                                                               \
    std::string error_msg;                                                     \
    GET_STDERR_MSG(m, error_msg);                                              \
    EndRecordLog();                                                            \
  } while (0);

#if defined(_WIN32) || defined(_WIN64)
TEST(TestUtil, DirAppend) {

  EXPECT_EQ(os_portable_join_dir({}), "");
  EXPECT_EQ(os_portable_append_dir("\\a", "b"), "\\a\\b");
  EXPECT_EQ(os_portable_append_dir("\\a\\", "b"), "\\a\\b");
  EXPECT_EQ(os_portable_append_dir("a\\", "b"), "a\\b");
  EXPECT_EQ(os_portable_append_dir("a", "b"), "a\\b");
  EXPECT_EQ(os_portable_append_dir("a\\", ".\\b"), "a\\.\\b");
  EXPECT_EQ(os_portable_append_dir("\\a\\", ".\\b"), "\\a\\.\\b");

  EXPECT_ERROR(os_portable_append_dir("a", "\\b"));
  EXPECT_ERROR(os_portable_append_dir("\\a\\", "\\b"));
  EXPECT_ERROR(os_portable_append_dir("\\a", "\\b"));

  EXPECT_EQ(os_portable_append_dir("a", {"b", "c"}), "a\\b\\c");
}
#else
TEST(TestUtil, DirAppend) {

  EXPECT_EQ(os_portable_join_dir({}), "");
  EXPECT_EQ(os_portable_append_dir("/a", "b"), "/a/b");
  EXPECT_EQ(os_portable_append_dir("/a/", "b"), "/a/b");
  EXPECT_EQ(os_portable_append_dir("a/", "b"), "a/b");
  EXPECT_EQ(os_portable_append_dir("a", "b"), "a/b");
  EXPECT_EQ(os_portable_append_dir("a/", "./b"), "a/./b");
  EXPECT_EQ(os_portable_append_dir("/a/", "./b"), "/a/./b");

  EXPECT_ERROR(os_portable_append_dir("a", "/b"));
  EXPECT_ERROR(os_portable_append_dir("/a/", "/b"));
  EXPECT_ERROR(os_portable_append_dir("/a", "/b"));

  EXPECT_EQ(os_portable_append_dir("/a", std::vector<std::string>({"b", "c"})),
            "/a/b/c");
}
#endif

TEST(TestUtil, CopyDir) {
  auto src_dir = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                        {"unit-data", "fs", "cpsrc"});
  auto dst_dir = os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                                        {"unit-data", "fs", "cpdst"});
  auto dummy_path = os_portable_append_dir(dst_dir, "dummy");

  EXPECT_TRUE(os_portable_mkdir(dst_dir));

  EXPECT_TRUE(os_portable_copy_dir(src_dir, dst_dir));
  EXPECT_TRUE(fs::exists(dummy_path));
  EXPECT_FALSE(fs::is_directory(dummy_path));

  EXPECT_FALSE(os_portable_mkdir(dummy_path));
  EXPECT_TRUE(fs::exists(dummy_path));
  EXPECT_FALSE(fs::is_directory(dummy_path));
}

#if defined(_WIN32) || defined(_WIN64)
TEST(TestUtil, FileNameFromDir) {

  EXPECT_EQ(os_portable_remove_file_name_extension(".\\a"), ".\\a");
  EXPECT_EQ(os_portable_remove_file_name_extension(".\\a.out"), ".\\a");
  EXPECT_EQ(os_portable_remove_file_name_extension("a.out"), "a");
  EXPECT_EQ(os_portable_remove_file_name_extension("a"), "a");
  EXPECT_EQ(os_portable_path_from_path("a"), ".\\");

  EXPECT_EQ(os_portable_file_name_from_path("a"), "a");
  EXPECT_EQ(os_portable_file_name_from_path("a\\b"), "b");
  EXPECT_EQ(os_portable_file_name_from_path(".\\a\\b"), "b");

  EXPECT_ERROR(os_portable_file_name_from_path("a\\"));
}
#else
TEST(TestUtil, FileNameFromDir) {

  EXPECT_EQ(os_portable_remove_file_name_extension("./a"), "./a");
  EXPECT_EQ(os_portable_remove_file_name_extension("./a.out"), "./a");
  EXPECT_EQ(os_portable_remove_file_name_extension("a.out"), "a");
  EXPECT_EQ(os_portable_remove_file_name_extension("a"), "a");
  EXPECT_EQ(os_portable_path_from_path("a"), "./");

  EXPECT_EQ(os_portable_file_name_from_path("a"), "a");
  EXPECT_EQ(os_portable_file_name_from_path("a/b"), "b");
  EXPECT_EQ(os_portable_file_name_from_path("./a/b"), "b");

  EXPECT_ERROR(os_portable_file_name_from_path("a/"));
}
#endif

#if defined(__unix__) || defined(unix) || defined(__APPLE__) ||                \
    defined(__MACH__) || defined(__linux__) || defined(__FreeBSD__)

TEST(TestUtil, ExecShell) {
  typedef std::vector<std::string> P;

  auto scriptName =
      os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                             P({"unit-data", "shell_ex", "shell.sh"}));

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
  auto redirect_file =
      os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                             {"unit-data", "shell_ex", "date_out.txt"});

  auto pid_file =
      os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                             {"unit-data", "shell_ex", "pid_out.txt"});

  auto scriptName = "date";
  std::vector<std::string> cmd;
  cmd.push_back(scriptName);
  execute_result res;

  res = os_portable_execute_shell(cmd, redirect_file, BOTH, 0, pid_file);
  EXPECT_EQ(res.failure, execute_result::NONE);

  std::ifstream d1(redirect_file);
  std::string l1;

  EXPECT_TRUE(d1.is_open());
  if (d1.is_open()) {
    std::getline(d1, l1);
    d1.close();
  }

  sleep(2); // wait for at ~ 2 seconds

  res = os_portable_execute_shell(cmd, redirect_file, BOTH, 0, pid_file);
  EXPECT_EQ(res.failure, execute_result::NONE);

  std::ifstream d2(redirect_file);
  std::string l2;

  EXPECT_TRUE(d2.is_open());
  if (d2.is_open()) {
    std::getline(d2, l2);
    d2.close();
  }

  EXPECT_TRUE(l1 != l2);
}

TEST(TestUtil, ExecShellRedirectTimeOut) {
  auto redirect_file =
      os_portable_append_dir(std::string(ILANG_TEST_SRC_ROOT),
                             {"unit-data", "shell_ex", "sleep_out.txt"});

  std::vector<std::string> s1cmd({"sleep", "1"});
  std::vector<std::string> s10cmd({"sleep", "10"});
  execute_result res;

  res = os_portable_execute_shell(s1cmd, redirect_file, BOTH, 5);
  EXPECT_TRUE(res.failure == execute_result::NONE);
  EXPECT_EQ(res.timeout, false);
  EXPECT_EQ(res.ret, 0);

  res = os_portable_execute_shell(s10cmd, redirect_file, BOTH, 2);
  EXPECT_EQ(res.failure, execute_result::NONE);
  EXPECT_EQ(res.timeout, true);
  // EXPECT_EQ(res.ret, 0); if timeout return value not usable
}
#endif

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
TEST(TestUtil, LongWidth) {
  std::string msg;
  SetToStdErr(1);
  long long ret;

  std::string bit1_times63 = "";
  unsigned long long v = 0;
  for (int i = 0; i < 63; ++i) {
    bit1_times63 += "1";
    v = v << 1;
    v = v | 1;
  }

  GET_STDERR_MSG(ret = StrToLong(bit1_times63, 2), msg);
  EXPECT_EQ(ret, v); // 63-bit should work

#ifndef NDEBUG
  EXPECT_TRUE(msg.empty());
#endif

  std::string bit1_times64 = bit1_times63 + "1";

  GET_STDERR_MSG(ret = StrToLong(bit1_times64, 2), msg);
  EXPECT_EQ(ret, 0); // 64-bit should not work

#ifndef NDEBUG
  EXPECT_FALSE(msg.empty());
#endif
}

TEST(TestUtil, LongWidth_unsigned) {
  std::string msg;
  SetToStdErr(1);
  unsigned long long ret;

  std::string bit1_times63 = "";
  unsigned long long v = 0;
  for (int i = 0; i < 63; ++i) {
    bit1_times63 += "1";
    v = v << 1;
    v = v | 1;
  }

  GET_STDERR_MSG(ret = StrToULongLong(bit1_times63, 2), msg);
  EXPECT_EQ(ret, v); // 63-bit should work

#ifndef NDEBUG
  EXPECT_TRUE(msg.empty());
#endif

  std::string bit1_times64 = bit1_times63 + "1";

  GET_STDERR_MSG(ret = StrToULongLong(bit1_times64, 2), msg);
  EXPECT_EQ(ret, v * 2 + 1); // 64-bit should work

#ifndef NDEBUG
  EXPECT_TRUE(msg.empty());
#endif

  std::string bit1_times65 = bit1_times64 + "1";

  GET_STDERR_MSG(ret = StrToULongLong(bit1_times65, 2), msg);
  EXPECT_EQ(ret, 0); // 65-bit should not work

#ifndef NDEBUG
  EXPECT_FALSE(msg.empty());
#endif
}

TEST(TestUtil, Int2Str) {
  EXPECT_EQ(IntToStrCustomBase(0, 16, true), "0");
  EXPECT_EQ(IntToStrCustomBase(0, 10, true), "0");
  EXPECT_EQ(IntToStrCustomBase(0, 2, true), "0");
  EXPECT_EQ(IntToStrCustomBase(16, 16, true), "10");
  EXPECT_EQ(IntToStrCustomBase(16, 16, false), "10");
  EXPECT_EQ(IntToStrCustomBase(15, 16, false), "f");
  EXPECT_EQ(IntToStrCustomBase(15, 16, true), "F");
  EXPECT_EQ(IntToStrCustomBase(16, 8, true), "20");
  EXPECT_EQ(IntToStrCustomBase(16, 8, false), "20");
  EXPECT_EQ(IntToStrCustomBase(16, 3, false), "121");
  EXPECT_EQ(IntToStrCustomBase(16, 10, false), "16");
  EXPECT_EQ(IntToStrCustomBase(255, 16, true), "FF");
  EXPECT_EQ(IntToStrCustomBase(255, 16, false), "ff");
  EXPECT_EQ(IntToStrCustomBase(100, 16, true), "64");
  EXPECT_EQ(IntToStrCustomBase(100, 10, false), "100");
  EXPECT_EQ(IntToStrCustomBase(2121, 16, false), "849");
  EXPECT_EQ(IntToStrCustomBase(255, 2, true), "11111111");
  EXPECT_EQ(IntToStrCustomBase(255, 2, false), "11111111");

  {
    unsigned max_unsigned_int = -1;
    size_t int_max_size = sizeof(int);
    std::string hex;
    for (int i = 0; i < int_max_size * 2; i++)
      hex += 'F';

    std::string bin;
    for (int i = 0; i < int_max_size * 8; i++)
      bin += '1';

    EXPECT_EQ(IntToStrCustomBase(max_unsigned_int, 16, true), hex);
    EXPECT_EQ(IntToStrCustomBase(max_unsigned_int, 16, false), StrToLower(hex));
    EXPECT_EQ(IntToStrCustomBase(max_unsigned_int, 2, false), bin);
  }
}

#define TestTrim(fa, in, out)                                                  \
  {                                                                            \
    std::string a = in;                                                        \
    fa(a);                                                                     \
    EXPECT_EQ(a, out);                                                         \
  }

TEST(TestUtil, StrTrim) {
  TestTrim(StrLeftTrim, " dfs a b ", "dfs a b ");
  TestTrim(StrLeftTrim, "  dfs a b ", "dfs a b ");
  TestTrim(StrLeftTrim, "   dfs a b ", "dfs a b ");
  TestTrim(StrRightTrim, "   dfs a b", "   dfs a b");
  TestTrim(StrRightTrim, "   dfs a b ", "   dfs a b");
  TestTrim(StrRightTrim, "   dfs a b  ", "   dfs a b");
  TestTrim(StrTrim, "dfs a b", "dfs a b");
  TestTrim(StrTrim, " dfs a b ", "dfs a b");
  TestTrim(StrTrim, "  dfs a b ", "dfs a b");
  TestTrim(StrTrim, "   dfs a b", "dfs a b");
  TestTrim(StrTrim, "   dfs a b ", "dfs a b");
  TestTrim(StrTrim, "   dfs a b  ", "dfs a b");
}

} // namespace ilang
