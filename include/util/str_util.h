/// \file
/// Header for some utily functions for string formating.

#ifndef __STR_UTIL_H__
#define __STR_UTIL_H__

#include <algorithm>
#include <string>

/// \namespace ila
namespace ila {

std::string StrToUpper(const std::string& str);

std::string StrToLower(const std::string& str);

bool StrToBool(const std::string& str);

int StrToInt(const std::string& str);

} // namespace ila

#endif // __STR_UTIL_H__

