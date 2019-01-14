/// \file
/// Unit test for utility functions

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

  EXPECT_EQ( os_portable_file_name_path("a"),     "a" );
  EXPECT_EQ( os_portable_file_name_path("a/b"),   "b" );
  EXPECT_EQ( os_portable_file_name_path("./a/b"), "b" );

  EXPECT_ERROR( os_portable_file_name_path("a/") );

}

} // namespace ilang
