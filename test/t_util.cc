/// \file
/// Unit test for utility functions

#include "unit-include/config.h"
#include "unit-include/util.h"
#include <ilang/util/str_util.h>
#include <ilang/util/fs.h>
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

TEST(TestUtil, DirAppend) {

  EXPECT_EQ( os_portable_append_dir("/a","b"),  "/a/b" );
  EXPECT_EQ( os_portable_append_dir("/a/","b"), "/a/b" );
  EXPECT_EQ( os_portable_append_dir("a/","b"),  "a/b"  );
  EXPECT_EQ( os_portable_append_dir("a","b"),   "a/b"  );
  EXPECT_EQ( os_portable_append_dir("a/","./b"),"a/./b"  );
  EXPECT_EQ( os_portable_append_dir("/a/","./b"),"/a/./b"  );

  EXPECT_ERROR( os_portable_append_dir("a","/b") );
  EXPECT_ERROR( os_portable_append_dir("/a/","/b") );
  EXPECT_ERROR( os_portable_append_dir("/a","/b") );
}


TEST(TestUtil, FileNameFromDir) {

  EXPECT_EQ( os_portable_file_name_from_path("a"),     "a" );
  EXPECT_EQ( os_portable_file_name_from_path("a/b"),   "b" );
  EXPECT_EQ( os_portable_file_name_from_path("./a/b"), "b" );

  EXPECT_ERROR( os_portable_file_name_from_path("a/") );

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

  EXPECT_TRUE(os_portable_execute_shell(scriptName));
}

TEST(TestUtil, RegularExpr) {
  if(IsRExprUsable() ) {
    auto l = ReFindList("s1 == 2", "[A-Za-z0-9]+");
    EXPECT_EQ(l.size(), 2);
    EXPECT_EQ(l[0], "s1");
    EXPECT_EQ(l[1], "2");

    auto l2 = ReFindAndDo("s1 == 2", "[A-Za-z0-9]+", [](std::string s) -> std::string {return s;} );

    EXPECT_EQ(l2.size(), 2);
    EXPECT_EQ(l2[0], "s1");
    EXPECT_EQ(l2[1], "2");
  }
}

} // namespace ilang
