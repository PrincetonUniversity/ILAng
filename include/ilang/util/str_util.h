/// \file
/// Header for some utily functions for string formating.

#ifndef STR_UTIL_H__
#define STR_UTIL_H__

#include <algorithm>
#include <string>

/// \namespace ila
namespace ila {

/// Transform basic string to upper case.
std::string StrToUpper(const std::string& str);

/// Transform basic string to lower case.
std::string StrToLower(const std::string& str);

/// Return true if string is "true" or "True".
bool StrToBool(const std::string& str);

/// Return the value represented in the string, e.g. "10".
int StrToInt(const std::string& str);

#if 0
/// Concatenate two string with "_".
std::string StrConcat(const std::string& l, const std::string& r);

/// Concatenate three string with "_".
std::string StrConcat(const std::string& l, const std::string& m,
                      const std::string& r);
#endif

} // namespace ila

#endif // STR_UTIL_H__

