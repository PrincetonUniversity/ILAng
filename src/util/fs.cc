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
#include <windows.h>
#else
// on *nix
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
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

  ILA_ERROR_IF(path.back() == sep[0])
      << "Extracting file name from path:" << path << " that ends with:" << sep;
  return Split(path, sep).back();
}

/// Copy all file from a source dir to the destination dir
bool os_portable_copy_dir(const std::string& src, const std::string& dst) {
  int ret;
#if defined(_WIN32) || defined(_WIN64)
  // on windows
  ret = std::system(
      ("xcopy " + os_portable_append_dir(src, "*") + " " + dst).c_str());
#else
  // on *nix
  ret = std::system(
      ("cp " + os_portable_append_dir(src, "*") + " " + dst).c_str());
#endif
  return ret == 0;
}

/// Copy all file from a source dir to the destination dir
bool os_portable_copy_file_to_dir(const std::string& src,
                                  const std::string& dst) {
  int ret;
#if defined(_WIN32) || defined(_WIN64)
  // on windows
  ret = std::system(("xcopy " + src + " " + dst).c_str());
#else
  // on *nix
  ret = std::system(("cp " + src + " " + dst).c_str());
#endif
  return ret == 0;
}


/// C:\\a.txt -> C:\\a   or  /a/b/c.txt -> a/b/c
std::string os_portable_remove_file_name_extension(const std::string fname) {
  std::string sep;
#if defined(_WIN32) || defined(_WIN64)
  // on windows
  sep = "\\";
#else
  // on *nix
  sep = "/";
#endif
  auto dot_pos = fname.rfind('.');
  if(dot_pos == std::string::npos)
    return fname; // no dot
  
  auto sep_pos = fname.rfind(sep);
  
  if (sep_pos == std::string::npos) // no sep and only dot
    return fname.substr(0,dot_pos); // remove after dot

  // no change ./../a -> ./../a
  if(dot_pos < sep_pos)
    return fname;

  // /.asdfaf.d -> /.asdfaf  | /.a -> /.
  return fname.substr(0,dot_pos);
}


bool os_portable_execute_shell(const std::vector<std::string> & cmdargs) 
{
  auto cmdline = Join(cmdargs, ",");
  ILA_ASSERT(not cmdargs.empty()) << "API misuse!";
#ifdef defined(_WIN32) || defined(_WIN64)
  // on windows
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  ZeroMemory( &si, sizeof(si) );
  si.cb = sizeof(si);
  ZeroMemory( &pi, sizeof(pi) );

  // Start the child process. 
  if( !CreateProcess( NULL,   // No module name (use command line)
      cmdline.c_str(),      // Command line
      NULL,           // Process handle not inheritable
      NULL,           // Thread handle not inheritable
      FALSE,          // Set handle inheritance to FALSE
      0,              // No creation flags
      NULL,           // Use parent's environment block
      NULL,           // Use parent's starting directory 
      &si,            // Pointer to STARTUPINFO structure
      &pi )           // Pointer to PROCESS_INFORMATION structure
    )
    return false; // failed
  return true; 
#else
  // on *nix, spawn a child process to do this
  pid_t pid = fork();
  
  if (pid == -1) // not able to create no process
    return false;

  if (pid == 0) {
    // The child
    // will replace the image and execute the bash
    ILA_INFO<<"Execute subprocess: [" << cmdline << "]";

    // this is memory leak, but I have no other way...
    // hope this will be reclaimed by OS
    // + 1 for NULL

    const int MAX_ARG = 64;
    char * argv[MAX_ARG];
    ILA_ASSERT(cmdargs.size() <= MAX_ARG) << "Too many args";

    for(auto it = cmdargs.begin()+1; it != cmdargs.end(); ++ it) {
      // this is memory leak, I know, but what can I do ?
      argv[it-cmdargs.begin()-1] = new char[it->size() + 1];
      strcpy(argv[it-cmdargs.begin()-1], it->c_str());
    }
    argv[ cmdargs.size() -1 ] = NULL;

    exit( execvp(cmdargs[0].c_str(), argv));
  } else {
    // The parent will wait for its end
    int infop;
    if( waitpid(pid, &infop, 0) == -1 )
      return false; // failed call (should not happen normally)
    if(WEXITSTATUS(infop) != 0) {
      ILA_ERROR 
        << "Subprocess [" << cmdline 
        << "] failed with return code: "
        << WEXITSTATUS(infop);
      return false;
    }
  }
  return true;

#endif
}

}; // namespace ilang