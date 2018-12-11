/// \file
/// Header for some utily functions for string formating.

#ifndef STR_UTIL_H__
#define STR_UTIL_H__

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

/// \namespace ilang
namespace ilang {

/// Transform basic string to upper case.
std::string StrToUpper(const std::string& str);

/// Transform basic string to lower case.
std::string StrToLower(const std::string& str);

/// Return true if string is "true" or "True".
bool StrToBool(const std::string& str);

/// Return the value represented in the string, e.g. "10".
int StrToInt(const std::string& str);

/// Python-style split , return a vector of splitted strings
std::vector<std::string> Split(const std::string& str, const std::string& delim);

/// Python-style join, return a string that joins the list by the delim
std::string Join(const std::vector<std::string> & in, const std::string& delim);

/// Filter out a list of substring by the regular expression
std::vector<std::string> ReFindList(const std::string& s, const std::string& re);

/// Filter out a list of substring by the regular expression, call f each time and use its return value in the list, f can also do something else in itself
std::vector<std::string> ReFindAndDo(const std::string& s, const std::string& re, std::function<std::string(std::string)> f);

bool IsRExprUsable();

#if 0
/// Concatenate two string with "_".
std::string StrConcat(const std::string& l, const std::string& r);

/// Concatenate three string with "_".
std::string StrConcat(const std::string& l, const std::string& m,
                      const std::string& r);
#endif

} // namespace ilang

#endif // STR_UTIL_H__
