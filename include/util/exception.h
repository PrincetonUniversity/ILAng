/// \file
/// The header file for the exception/assertion system.

#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string>

namespace ila {

void ila_assert(bool b, const char* msg, const char* file, int line);

void ila_assert(bool b, const std::string& msg, const char* file, int line);

} // namespace ila

#endif // __EXCEPTION_H__

