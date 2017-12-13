/// \file
/// The source for the class Context.

#include "context.h"

/// \namespace ila
namespace ila {

Context::Context() {
  logging_inited_ = false;

#ifndef NDEBUG
  logging_enable_ = true;
#else  // NDEBUG
  logging_enable_ = false;
#endif // NDEBUG
}

Context::~Context() {}

void Context::Init() { InitLogging(); }

void Context::Clear() { ClearLogging(); }

void Context::SetLoggingPath(const std::string& path) { logging_path_ = path; }

void Context::SetLogToStdErr(bool b) { logging_stderr_ = b; }

void Context::InitLogging() {
  if (!logging_inited_) {
    InitGLog(logging_verbose_, logging_path_, logging_stderr_);
    InitDLog();
    logging_inited_ = true;
  }
}

void Context::ClearLogging() {
  if (logging_inited_) {
    CloseGLog();
    CloseDLog();
  }
}

} // namespace ila

