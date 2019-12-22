/// \file
/// To emulate some posix functions on Windows
// I hate Windows programming
// Hongce Zhang (hongcez@princeton.edu)

#if defined(_WIN32) || defined(_WIN64)
#include <ilang/util/posix_emu.h>
#include <windows.h>

namespace ilang {

/// Hongce's note: This file was intended to include the code
/// to emulate some posix functions
/// One of it is fmemopen
/// However, it is under GPLv2 license.
/// For license issue we don't include its implementation here
/// You can find implementations for example:
/// https://git.ligo.org/finesse/finesse/blob/611196fba8104bf7f7ca982f4222834261700783/src/fmemopen.c

}; // namespace ilang

#endif // defined(_WIN32) || defined(_WIN64)

