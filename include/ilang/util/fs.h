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
  std::string os_portable_append_dir(const std::string & dir1, const std::string & dir2);
  
  /// Extract filename from path
  /// C:\a\b\c.txt -> c.txt
  /// d/e/ghi  -> ghi
  std::string os_portable_file_name_from_path(const std::string & path);

}; // namespace ilang


#endif // FS_H__
