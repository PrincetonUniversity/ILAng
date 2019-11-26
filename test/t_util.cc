/// \file
/// Unit test for utility functions

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

#define TestTrim(fa, in, out) { \
std::string a = in; \
fa (a); \
EXPECT_EQ(a, out); \
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
