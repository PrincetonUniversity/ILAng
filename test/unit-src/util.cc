/// \file
/// Helper functions

#include "../unit-include/util.h"

#include <cstdio>

namespace ilang {

std::string GetRandomFileName(char* file_name_template) {
  ILA_NOT_NULL(file_name_template);

#ifdef __unix__
  auto fn = mkstemp(file_name_template);
  return std::to_string(fn);

#elif __APPLE__
  auto fn = mkstemp(file_name_template);
  return std::to_string(fn);

#else
  ILA_WARN << "tmpnam may be deprecated -- find alternatives";
  auto fn = std::tmpnam(NULL);
  return static_cast<std::string>(fn);

#endif
}

}; // namespace ilang 
