/// \file
/// The source for the ILA context -- the manager of all ILA objects.

#include "context.h"

namespace ila {

Context::Context() {}

Context::~Context() {}

void Context::InitLogging() {
  logger_.InitGlog(0, "", 0);
  logger_.InitDlog();
}

void Context::CloseLogging() {
  logger_.CloseGlog();
  logger_.CloseDlog();
}

} // namespace ila

