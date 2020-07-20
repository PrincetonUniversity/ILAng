/// \file Utility to deal with filesystem
/// This could be possible OS dependent
/// So we want to provide a portable layer
/// C++17 and after should support something like
/// experimental/filesystem, but we don't rely on it
// --- Hongce Zhang

#ifndef ILANG_UTIL_FS_H__
#define ILANG_UTIL_FS_H__

#include <string>
#include <vector>

namespace ilang {

/// Check if path exist.
bool os_portable_exist(const std::string& path);

/// Create a dir, true -> suceeded , ow false
bool os_portable_mkdir(const std::string& dir);

/// Copy all file from a source dir to the destination dir
bool os_portable_copy_dir(const std::string& src, const std::string& dst);

/// Copy one file to the destination dir
bool os_portable_copy_file_to_dir(const std::string& src,
                                  const std::string& dst);

/// Move one file to the destination dir
bool os_portable_move_file_to_dir(const std::string& src,
                                  const std::string& dst);

/// Remove one file
bool os_portable_remove_file(const std::string& file);

/// Remove one directory
bool os_portable_remove_directory(const std::string& dir);

/// Append two paths
std::string os_portable_append_dir(const std::string& dir1,
                                   const std::string& dir2);

/// Append paths to another
std::string os_portable_append_dir(const std::string& dir1,
                                   const std::vector<std::string>& dirs);

/// Join paths
std::string os_portable_join_dir(const std::vector<std::string>& dirs);

/// C:\\a.txt -> C:\\a   or  /a/b/c.txt -> a/b/c
std::string os_portable_remove_file_name_extension(const std::string& fname);

/// the result from executing
struct execute_result {
  /// has timeout
  bool timeout;
  /// failed execution
  enum _failure { PREIO = 0, FORK = 1, ALARM, ARG, EXEC, WAIT, NONE } failure;
  /// return value
  unsigned ret;
  /// true if it exits with _exit() call
  bool subexit_normal;
  /// the execution time
  double seconds;
};

/// the type of redirect
enum redirect_t { NONE = 0, STDOUT = 1, STDERR = 2, BOTH = 3 };
/// execute some executables that are shell scripts,
/// timeout (if 0 will wait forever)
execute_result
os_portable_execute_shell(const std::vector<std::string>& cmdargs,
                          const std::string& redirect_output_file = "",
                          redirect_t rdt = redirect_t::BOTH,
                          unsigned timeout = 0,
                          const std::string& pid_file_name = "");

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
std::string os_portable_read_last_line(const std::string& filename);

/// Change current directory: true if success
bool os_portable_chdir(const std::string& dirname);

/// Get the current directory
std::string os_portable_getcwd();

#if (defined(__unix__) || defined(unix) || defined(__APPLE__) ||               \
     defined(__MACH__) || defined(__FreeBSD__)) &&                             \
    !defined(__linux__)

#ifdef __cplusplus
extern "C" {
#endif

/**
 * A BSD port of the fmemopen Linux method using funopen.
 *
 * man docs for fmemopen:
 * http://linux.die.net/man/3/fmemopen
 *
 * man docs for funopen:
 * https://developer.apple.com/library/mac/#documentation/Darwin/Reference/ManPages/man3/funopen.3.html
 *
 * This method is ported from ingenuitas' python-tesseract project.
 *
 * You must call fclose on the returned file pointer or memory will be leaked.
 *
 *      @param buf The data that will be used to back the FILE* methods. Must be
 * at least
 *                 @c size bytes.
 *      @param size The size of the @c buf data.
 *      @param mode The permitted stream operation modes.
 *      @returns A pointer that can be used in the fread/fwrite/fseek/fclose
 * family of methods. If a failure occurred NULL will be returned.
 */
FILE* fmemopen_osx(void* buf, size_t size, const char* mode);

#ifdef __cplusplus
}
#endif

#endif // fmemopen_osx guard

}; // namespace ilang

#endif // ILANG_UTIL_FS_H__
