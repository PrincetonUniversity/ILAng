/// \file
/// Source for some utility functions for string formating.

#include "util/str_util.h"
#include "util/log.h"

namespace ila {

std::string StrToUpper(const std::string& str) {
  std::string res = str;
  std::transform(res.begin(), res.end(), res.begin(), toupper);
  return res;
}

#if 0
std::string StrToLower(const std::string& str) {
  std::string res = str;
  std::transform(res.begin(), res.end(), res.begin(), tolower);
  return res;
}
#endif

bool StrToBool(const std::string& str) {
  std::string up = StrToUpper(str);
  ILA_ASSERT((up == "TRUE") || (up == "FALSE")) << "Unknown boolean value "
                                                << up << "\n";
  return (up == "TRUE");
}

int StrToInt(const std::string& str) {
  try {
    return std::stoi(str);
  } catch (const std::exception& e) {
    ILA_ERROR << "Converting non-numeric value " << str << " to int.\n";
    return 0;
  }
}

#if 0
std::string StrConcat(const std::string& l, const std::string& r) {
  return (l + "_" + r);
}

std::string StrConcat(const std::string& l, const std::string& m,
                      const std::string& r) {
  return (l + "_" + m + "_" + r);
}
#endif

} // namespace ila

