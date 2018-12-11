/// \file
/// Source for some utility functions for string formating.

#include <regex>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

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
  ILA_ASSERT((up == "TRUE") || (up == "FALSE"))
      << "Unknown boolean value " << up << "\n";
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


std::vector<std::string> Split(const std::string& str, const std::string& delim)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

std::string Join(const std::vector<std::string> & in, const std::string& delim)
{
  std::string ret;
  std::string d = "";
  for(auto && s:in) {
    ret += (d + s);
    d = delim;
  }
  return ret;
}

// GCC supports this after 4.9.0
// not available on Ubuntu 14.04 LTS

#ifdef __GNUC__
#if (__GNUC__ > 4  || (__GNUC__ == 4 &&  __GNUC_MINOR__ >= 9)   ) 

std::vector<std::string> ReFindList(const std::string& s, const std::string& re)
{
  std::vector<std::string> tokens;
  std::regex word_regex(re);
  auto words_begin = std::sregex_iterator(s.begin(), s.end(), word_regex);
  auto words_end   = std::sregex_iterator();

  for(std::sregex_iterator i = words_begin; i != words_end; ++i) {
    std::smatch match = *i;
    std::string match_str = match.str();
    tokens.push_back( match_str );
  }
  return tokens;
}

std::vector<std::string> ReFindAndDo(const std::string& s, const std::string& re, std::function<std::string(std::string)> f)
{
  std::vector<std::string> tokens;
  std::regex word_regex(re);
  auto words_begin = std::sregex_iterator(s.begin(), s.end(), word_regex);
  auto words_end   = std::sregex_iterator();

  for(std::sregex_iterator i = words_begin; i != words_end; ++i) {
    std::smatch match = *i;
    std::string match_str = match.str();
    tokens.push_back( f(match_str) );
  }
  return tokens;
}


bool IsRExprUsable() { return true; }

#else
// not supported
std::vector<std::string> ReFindList(const std::string& s, const std::string& re)
{
  ILA_ASSERT(false) << "Not suppported: please use GCC 4.9.0 or above to enable this function";
  return std::vector<std::string>();
}

std::vector<std::string> ReFindAndDo(const std::string& s, const std::string& re, std::function<std::string(std::string)> f)
{
  ILA_ASSERT(false) << "Not suppported: please use GCC 4.9.0 or above to enable this function";
  return std::vector<std::string>();
}


bool IsRExprUsable() { return false; }

#endif

#else
 // not defined
std::vector<std::string> ReFindList(const std::string& s, const std::string& re)
{
  ILA_ASSERT(false) << "Not suppported: please use GCC 4.9.0 or above to enable this function";
  return std::vector<std::string>();
}

std::vector<std::string> ReFindAndDo(const std::string& s, const std::string& re, std::function<std::string(std::string)> f)
{
  ILA_ASSERT(false) << "Not suppported: please use GCC 4.9.0 or above to enable this function";
  return std::vector<std::string>();
}


bool IsRExprUsable() { return false; }
#endif


#if 0
std::string StrConcat(const std::string& l, const std::string& r) {
  return (l + "_" + r);
}

std::string StrConcat(const std::string& l, const std::string& m,
                      const std::string& r) {
  return (l + "_" + m + "_" + r);
}
#endif

} // namespace ilang
