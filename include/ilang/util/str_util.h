/// \file
/// Header for some utily functions for string formating.

#ifndef ILANG_UTIL_STR_UTIL_H__
#define ILANG_UTIL_STR_UTIL_H__

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

/// \namespace ilang
namespace ilang {

// (itoa is not part of the standard actually,
// so I hesitated whether to use it actually)
// on the other hand, snprintf only supports 8/10/16
/// Transform int to string with different bases
std::string IntToStrCustomBase(uint64_t value, unsigned base, bool uppercase);

/// Transform basic string to upper case.
std::string StrToUpper(const std::string& str);

/// Transform basic string to lower case.
std::string StrToLower(const std::string& str);

/// Return true if string is "true" or "True".
bool StrToBool(const std::string& str);

/// Return the value represented in the string, e.g. "10".
int StrToInt(const std::string& str, int base = 10);

/// Return the value represented in the string in long type, e.g. "10".
long long StrToLong(const std::string& str, int base = 10);

/// Return the value represented in the string in unsigned long long, e.g. "10".
unsigned long long StrToULongLong(const std::string& str, int base = 10);



/// Trim a string from start (in place)
void StrLeftTrim(std::string& s);

/// Trim a string from end (in place)
void StrRightTrim(std::string& s);

/// Trim a string from both ends (in place)
void StrTrim(std::string &s);


/// Python-style split , return a vector of splitted strings
std::vector<std::string> Split(const std::string& str,
                               const std::string& delim);

///  Python-style split behavior, delim: space tab enter and their combiniations
std::vector<std::string> SplitSpaceTabEnter(const std::string& str);

/// Python-style join, return a string that joins the list by the delim
std::string Join(const std::vector<std::string>& in, const std::string& delim);

/// Remove whitespace " \n\t\r\f\v" from the input string
std::string RemoveWhiteSpace(const std::string & in);

/// Replace all occurrance of substring a by substring b
std::string ReplaceAll(const std::string& str, const std::string& a,
                       const std::string& b);

/// Filter out a list of substring by the regular expression
std::vector<std::string> ReFindList(const std::string& s,
                                    const std::string& re);

/// Filter out a list of substring by the regular expression, call f each time
/// and use its return value in the list, f can also do something else in itself
std::vector<std::string> ReFindAndDo(const std::string& s,
                                     const std::string& re,
                                     std::function<std::string(std::string)> f);

bool IsRExprUsable();

/// Finds out if str ends with suffix
bool StrEndsWith(const std::string& str, const std::string& suffix);

/// Finds out if str starts with prefix
bool StrStartsWith(const std::string& str, const std::string& prefix);


} // namespace ilang

#endif // ILANG_UTIL_STR_UTIL_H__
