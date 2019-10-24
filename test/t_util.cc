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
  std::string bit1_times63;
  unsigned long long v;
  for (int i=0;i<63;++i) {
    bit1_times63 += "1";
    v = v << 1;
    v = v | 1;
  }
  auto ret = StrToLong(bit1_times63,2);
  EXPECT_EQ(ret,v); // 63-bit does work

  std::string bit1_times64 = bit1_times63 + "1";
  auto bad = StrToLong(bit1_times64,2);
  EXPECT_EQ(bad,0); // 64-bit does not work
}

} // namespace ilang
