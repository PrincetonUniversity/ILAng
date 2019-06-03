/// \file
/// Helper functions

#include "../unit-include/util.h"

#include <cstdio>

namespace ilang {

std::string GetRandomFileName(char* file_name_template) {
  ILA_NOT_NULL(file_name_template);

#ifdef __unix__
  auto res = mkstemp(file_name_template);
  ILA_CHECK(res != -1) << "Fail creating file";
  return static_cast<std::string>(file_name_template);

#elif __APPLE__
  auto res = mkstemp(file_name_template);
  ILA_CHECK(res != -1) << "Fail creating file";
  return static_cast<std::string>(file_name_template);

#else
  ILA_WARN << "tmpnam may be deprecated -- find alternatives";
  auto fn = std::tmpnam(NULL);
  return static_cast<std::string>(fn);

#endif
}

}; // namespace ilang 
