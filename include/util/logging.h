/// \file
/// The header file for the logging system.

#ifndef _LOGGING_H__
#define _LOGGING_H__

#include <iostream>

namespace ila {

std::ostream& INFO(std::string s);
std::ostream& LOG1(std::string s);
std::ostream& LOG2(std::string s);

void InitLog();

void SetLogLevel(int l, const std::string& name);
void EnableLog(const std::string& name);
void DisableLog(const std::string& name);
void ClearLogs();

} // namespace ila

#endif // __LOGGING_H__

