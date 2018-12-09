/// \file
/// Some helper macros, functions for writing tests.

#include "gtest/gtest-spi.h"
#include "gtest/gtest.h"
#include <ilang/config.h>
#include <ilang/ila/expr_fuse.h>
#include <ilang/util/log.h>
#include <memory>

namespace ilang {

/// \def Capture standard output message for cmd to msg.
#define GET_STDOUT_MSG(cmd, msg)                                               \
  ::testing::internal::CaptureStdout();                                        \
  cmd;                                                                         \
  msg = ::testing::internal::GetCapturedStdout();

/// \def Capture standard error message for cmd to msg.
#define GET_STDERR_MSG(cmd, msg)                                               \
  ::testing::internal::CaptureStderr();                                        \
  cmd;                                                                         \
  msg = ::testing::internal::GetCapturedStderr();

} // namespace ilang
