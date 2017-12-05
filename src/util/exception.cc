/// \file
/// The source file for the exception/assertion system.

#include "util/exception.h"

namespace ila {

void ila_assert(bool b, const char* msg, const char* file, int line) { return; }

void ila_assert(bool b, const std::string& msg, const char* file, int line) {
  return;
}

} // namespace ila

