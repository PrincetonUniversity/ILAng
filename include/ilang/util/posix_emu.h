/// \file
/// To emulate some posix functions on Windows
// I hate Windows programming
// Hongce Zhang (hongcez@princeton.edu)

#ifndef ILANG_UTIL_POSIX_EMULATE_H__
#define ILANG_UTIL_POSIX_EMULATE_H__

#if defined(_WIN32) || defined(_WIN64)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace ilang {

FILE *fmemopen(void *buf, size_t size, const char *mode);


} // namespace ilang

#endif // defined(_WIN32) || defined(_WIN64)

#endif // ILANG_UTIL_POSIX_EMULATE_H__

