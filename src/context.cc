/// \file
/// The source for the ILA context -- the manager of all ILA objects.

#include "context.h"

namespace ila {

Context::Context(bool enable_logging) : enable_logging_(enable_logging) {}

Context::~Context() {}

void Context::Initialize() {
  if (enable_logging_) {
    logger_.InitGlog(0, "", 0);
    logger_.InitDlog();
  }
}

void Context::ClearUp() {
  if (enable_logging_) {
    logger_.CloseGlog();
    logger_.CloseDlog();
  }
}

} // namespace ila

