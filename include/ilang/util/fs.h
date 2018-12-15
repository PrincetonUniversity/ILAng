/// \file Utility to deal with filesystem
/// This could be possible OS dependent
/// So we want to provide a portable layer
/// C++17 and after should support something like
/// experimental/filesystem, but we don't rely on it
// --- Hongce Zhang

#ifndef FS_H__
#define FS_H__

#include <string>

namespace ilang {

  /// Create a dir, true -> suceeded , ow false
  bool os_portable_mkdir(const std::string & dir);

  /// Append two path (you have to decide whether it is / or \)
  void os_portable_append_dir(const std::string & dir1, const std::string & dir2);

}; // namespace ilang


#endif // FS_H__