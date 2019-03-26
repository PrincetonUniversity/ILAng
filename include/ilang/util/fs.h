/// \file Utility to deal with filesystem
/// This could be possible OS dependent
/// So we want to provide a portable layer
/// C++17 and after should support something like
/// experimental/filesystem, but we don't rely on it
// --- Hongce Zhang

#ifndef FS_H__
#define FS_H__

#include <string>
#include <vector>

namespace ilang {

/// Create a dir, true -> suceeded , ow false
bool os_portable_mkdir(const std::string& dir);

/// Copy all file from a source dir to the destination dir
bool os_portable_copy_dir(const std::string& src, const std::string& dst);

/// Copy one file to the destination dir
bool os_portable_copy_file_to_dir(const std::string& src,
                                  const std::string& dst);

/// Append two path (you have to decide whether it is / or \)
std::string os_portable_append_dir(const std::string& dir1,
                                   const std::string& dir2);

/// C:\\a.txt -> C:\\a   or  /a/b/c.txt -> a/b/c
std::string os_portable_remove_file_name_extension(const std::string fname);

/// execute some executables that are shell scripts
bool os_portable_execute_shell(const std::vector<std::string> & cmdargs, const std::string & redirect_output_file = "");

/// Extract filename from path
/// C:\a\b\c.txt -> c.txt
/// d/e/ghi  -> ghi
std::string os_portable_file_name_from_path(const std::string& path);

}; // namespace ilang

#endif // FS_H__
