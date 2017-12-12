/// \file
/// The source for the class Context.

#include "context.h"
#include "config.h"

/// \namespace ila
namespace ila {

Context::Context() {
  logging_inited_ = false;

#ifdef DEBUG
  logging_enable_ = true;
#else  // DEBUG
  logging_enable_ = false;
#endif // DEBUG
}

Context::~Context() {}

void Context::Init() { InitLogging(); }

void Context::Clear() { ClearLogging(); }

void Context::SetLoggingPath(const std::string& path) { logging_path_ = path; }

void Context::SetLogToStdErr(bool b) { logging_stderr_ = b; }

void Context::InitLogging() {
  if (logging_enable_ && !logging_inited_) {
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

