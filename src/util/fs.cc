/// \file Utility to deal with filesystem
/// This could be possible OS dependent
/// So we want to provide a portable layer
/// C++17 and after should support something like
/// experimental/filesystem, but we don't rely on it
// --- Hongce Zhang

#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

#include <cstdlib>
#if defined(_WIN32) || defined(_WIN64)
// on windows
#include <direct.h>
#else
// on *nix
#include <sys/stat.h>
#include <sys/types.h>
#endif

namespace ilang {

static bool endsWith(const std::string& str, const std::string& suffix) {
  return str.size() >= suffix.size() and
         0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
}

static bool startsWith(const std::string& str, const std::string& prefix) {
  return str.size() >= prefix.size() and
         0 == str.compare(0, prefix.size(), prefix);
}

/// Create a dir, true -> suceeded , ow false
bool os_portable_mkdir(const std::string& dir) {
#if defined(_WIN32) || defined(_WIN64)
  // on windows
  return _mkdir(dir.c_str()) == 0;
#else
  // on *nix
  return mkdir(dir.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0;
#endif
}

/// Append two path (you have to decide whether it is / or \)
std::string os_portable_append_dir(const std::string& dir1,
                                   const std::string& dir2) {
  std::string sep;
#if defined(_WIN32) || defined(_WIN64)
  // on windows
  sep = "\\";
#else
  // on *nix
  sep = "/";
#endif
  auto str1 = dir1;
  auto str2 = dir2;
  if (not endsWith(str1, sep))
    str1 += sep;
  if (startsWith(dir2, sep)) {
    ILA_ERROR << "appending root path:" << dir2 << " to " << dir1;
    str2 = dir2.substr(1);
  }
  return str1 + str2;
}

/// C:\a\b\c.txt -> c.txt
/// d/e/ghi  -> ghi
std::string os_portable_file_name_from_path(const std::string& path) {
  std::string sep;
#if defined(_WIN32) || defined(_WIN64)
  // on windows
  sep = "\\";
#else
  // on *nix
  sep = "/";
#endif
  return Split(path, sep).back();
}


/// Copy all file from a source dir to the destination dir
bool os_portable_copy_dir(const std::string &src, const std::string &dst) {
  int ret;
#if defined(_WIN32) || defined(_WIN64)
  // on windows
  ret = std::system(("xcopy " + os_portable_append_dir(src,"*") + " " + dst).c_str());
#else
  // on *nix
  ret = std::system(("cp " + os_portable_append_dir(src,"*") + " " + dst).c_str());
#endif
  return ret == 0;
}

}; // namespace ilang