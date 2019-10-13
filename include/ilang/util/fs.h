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

/// the result from executing
struct execute_result {
  /// has timeout
  bool timeout;
  /// failed execution
  enum _failure {FORK, PREIO, ALARM, ARG, EXEC, WAIT, NONE } failure;
  /// return value
  unsigned ret;
  /// true if it exits with _exit() call
  bool subexit_normal;
  /// the execution time
  double seconds;
};

/// the type of redirect
enum redirect_t {NONE = 0 , STDOUT = 1 , STDERR = 2, BOTH = 3};
/// execute some executables that are shell scripts,
/// timeout (if 0 will wait forever)
execute_result os_portable_execute_shell(const std::vector<std::string> & cmdargs, 
    const std::string & redirect_output_file = "", redirect_t rdt = redirect_t::BOTH,
    unsigned timeout = 0,
    const std::string & pid_file_name = "");

/// Extract filename from path
/// C:\a\b\c.txt -> c.txt
/// d/e/ghi  -> ghi
std::string os_portable_file_name_from_path(const std::string& path);

/// Extract path from path
/// C:\a\b\c.txt -> "C:\a\b\ something "
/// C:\a\b\c -> C:\a\b
/// d/e/ghi  -> "d/e/"
std::string os_portable_path_from_path(const std::string& path);

/// read the last meaningful line from a file
std::string os_portable_read_last_line(const std::string  & filename);

/// Change current directory: true if success
bool os_portable_chdir(const std::string  & dirname);

/// Get the current directory
std::string os_portable_getcwd();



}; // namespace ilang

#endif // FS_H__
