/// \file
/// Some helper macros, functions for writing tests.

#ifndef UNIT_INCLUDE_UTIL_H__
#define UNIT_INCLUDE_UTIL_H__

#include "gtest/gtest-spi.h"
#include "gtest/gtest.h"

#include <memory>
#include <string>

#include <ilang/config.h>
#include <ilang/ila/expr_fuse.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/util/log.h>

namespace ilang {

/// \def Start to capture the log to stderr
void RecordLog();
/// \def Stop to capture the log to stderr
void EndRecordLog();

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

std::string GetRandomFileName(char* file_name_template);

void CheckIlaEqLegacy(const InstrLvlAbsPtr& a, const InstrLvlAbsPtr& b);

} // namespace ilang

#endif // UNIT_INCLUDE_UTIL_H__
