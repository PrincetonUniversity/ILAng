/// \file Utility to deal with filesystem
/// This could be possible OS dependent so we want to provide a portable layer
// C++17 and after should support something like experimental/filesystem, but
// we don't rely on it
// --- Hongce Zhang
// Now that ILAng require C++17, we can utilize some of the supports.

#include <ilang/util/fs.h>

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iomanip>

#ifdef FS_INCLUDE
#include <filesystem>
#else // FS_INCLUDE
#include <experimental/filesystem>
#endif // FS_INCLUDE

#if defined(_WIN32) || defined(_WIN64)
// windows
#include <direct.h>
#include <windows.h>
//#include <winbase.h>
#include <time.h>
#else
// on *nix
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#endif

#include <fmt/format.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

#ifdef FS_INCLUDE
namespace fs = std::filesystem;
#else  // FS_INCLUDE
namespace fs = std::experimental::filesystem;
#endif // FS_INCLUDE

bool os_portable_exist(const std::string& path) { return fs::exists(path); }

/// Create a dir, true -> suceeded , ow false
bool os_portable_mkdir(const std::string& dir) {
  if (fs::is_directory(dir)) {
    return true;
  }

  try {
    return fs::create_directory(dir);
  } catch (fs::filesystem_error& e) {
    ILA_ERROR << e.what();
    return false;
  }
}

/// Append two path (you have to decide whether it is / or \)
std::string os_portable_append_dir(const std::string& dir1,
                                   const std::string& dir2) {
  return (fs::path(dir1) / fs::path(dir2)).string();
}

/// Append two path (you have to decide whether it is / or \)
std::string os_portable_append_dir(const std::string& dir1,
                                   const std::vector<std::string>& dirs) {
  auto acc = fs::path(dir1);
  for (auto&& d : dirs) {
    acc /= fs::path(d);
  }
  return acc.string();
}

/// Append two path (you have to decide whether it is / or \)
std::string os_portable_join_dir(const std::vector<std::string>& dirs) {
  ILA_WARN_IF(dirs.empty()) << "No dir to join!";
  if (dirs.empty())
    return "";
  std::string ret = dirs[0];
  for (auto pos = dirs.begin() + 1; pos != dirs.end(); ++pos)
    ret = os_portable_append_dir(ret, *pos);
  return ret;
}

/// C:\a\b\c.txt -> c.txt
/// d/e/ghi  -> ghi
std::string os_portable_file_name_from_path(const std::string& path) {
  return fs::path(path).filename().string();
}

/// Copy all file from a source dir to the destination dir
bool os_portable_copy_dir(const std::string& src, const std::string& dst) {
  ILA_ASSERT(fs::is_directory(src) && fs::is_directory(dst));
  // fs::copy can only have one copy_options,
  // either recursive or overwrite_existing
  // therefore, we explicitly iterate through the hierarchy
  for (auto& p : fs::directory_iterator(src)) {
    auto dst_p = fs::path(dst) / p.path().filename();
    // directory_entry::is_regular_file not supported in experimental
    if (fs::is_regular_file(p.path())) {
      try {
        fs::copy_file(p.path(), dst_p, fs::copy_options::overwrite_existing);
      } catch (fs::filesystem_error& e) {
        ILA_ERROR << e.what();
        return false;
      }
    } else if (fs::is_directory(p.path())) {
      try {
        fs::create_directory(dst_p);
      } catch (fs::filesystem_error& e) {
        ILA_ERROR << e.what();
      }
      os_portable_copy_dir(p.path().string(), dst_p.string());
    }
  }
  return true;
}

/// Copy the source file to the destination dir
bool os_portable_copy_file_to_dir(const std::string& src,
                                  const std::string& dst) {
  ILA_ASSERT(fs::is_regular_file(src) && fs::is_directory(dst));

  try {
    fs::copy(src, dst, fs::copy_options::overwrite_existing);
  } catch (fs::filesystem_error& e) {
    ILA_ERROR << e.what();
    return false;
  }

  return true;
}

bool os_portable_move_file_to_dir(const std::string& src,
                                  const std::string& dst) {
  ILA_ASSERT(fs::is_regular_file(src) && fs::is_directory(dst));
  try {
    fs::rename(src, dst);
  } catch (fs::filesystem_error& e) {
    ILA_ERROR << e.what();
    return false;
  }
  return true;
}

bool os_portable_remove_file(const std::string& file) {
  ILA_ASSERT(fs::is_regular_file(file));
  try {
    return fs::remove(file);
  } catch (fs::filesystem_error& e) {
    ILA_ERROR << e.what();
    return false;
  }
}

bool os_portable_remove_directory(const std::string& dir) {
  ILA_ASSERT(fs::is_directory(dir));
  // A bug in g++5 will throw exception:
  // - cannot remove all: Directory not empty
  // - https://gcc.gnu.org/bugzilla/show_bug.cgi?id=71313
  try {
    fs::remove_all(fs::path(dir));
  } catch (fs::filesystem_error& e) {
    ILA_ERROR << e.what();
    return false;
  }
  return true;
}

/// Extract path from path
/// C:\a\b\c.txt -> "C:\a\b\"
/// C:\a\b\c -> C:\a\b
/// d/e/ghi  -> d/e/
std::string os_portable_path_from_path(const std::string& path) {
  auto p = fs::path(path).parent_path().string();

  // for backward compatibility
  if (p.empty()) {
#if defined(_WIN32) || defined(_WIN64) // on windows
    return ".\\";
#else // on *nix
    return "./";
#endif
  }

  return p;
}

/// C:\\a.txt -> C:\\a   or  /a/b/c.txt -> a/b/c
std::string os_portable_remove_file_name_extension(const std::string& fname) {
  auto name = fs::path(fname);
  name.replace_extension();
  return name.string();
}

#if defined(__unix__) || defined(unix) || defined(__APPLE__) ||                \
    defined(__MACH__) || defined(__linux__) || defined(__FreeBSD__)

volatile sig_atomic_t child_pid;
volatile sig_atomic_t shared_time_out;

void parent_alarm_handler(int signum) {
  if (child_pid != 0) {
    kill(-child_pid, SIGTERM);
    shared_time_out = 1;
  }
}
#endif

#if defined(_WIN32) || defined(_WIN64)
#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
#define DELTA_EPOCH_IN_MICROSECS 11644473600000000Ui64
#else
#define DELTA_EPOCH_IN_MICROSECS 11644473600000000ULL
#endif

struct timezone {
  int tz_minuteswest; /* minutes W of Greenwich */
  int tz_dsttime;     /* type of dst correction */
};

int gettimeofday(struct timeval* tv, struct timezone* tz) {
  FILETIME ft;
  unsigned __int64 tmpres = 0;

  if (NULL != tv) {
    GetSystemTimeAsFileTime(&ft);

    tmpres |= ft.dwHighDateTime;
    tmpres <<= 32;
    tmpres |= ft.dwLowDateTime;

    /*converting file time to unix epoch*/
    tmpres -= DELTA_EPOCH_IN_MICROSECS;
    tmpres /= 10; /*convert into microseconds*/
    tv->tv_sec = (long)(tmpres / 1000000UL);
    tv->tv_usec = (long)(tmpres % 1000000UL);
  }

  ILA_ERROR_IF(tz != NULL) << "Not implemented: timezone feature.";
  return 0;
}

#endif

execute_result
os_portable_execute_shell(const std::vector<std::string>& cmdargs,
                          const std::string& redirect_output_file,
                          redirect_t rdt, unsigned timeout,
                          const std::string& pid_file_name) {
  int pipefd[2];
  execute_result _ret;
  struct timeval Time1, Time2; // count the time

  _ret.seconds = 0;
  _ret.timeout = false;

  auto cmdline = Join(cmdargs, ",");
  ILA_ASSERT(!cmdargs.empty()) << "API misuse!";

#if defined(_WIN32) || defined(_WIN64)
  ILA_ERROR_IF(timeout != 0) << "Timeout feature is not supported on WINDOWS.";
  HANDLE h;
  if (!redirect_output_file.empty() && rdt != redirect_t::NONE) {
    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(sa);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;
    h = CreateFile(TEXT(redirect_output_file.c_str()), FILE_APPEND_DATA,
                   FILE_SHARE_WRITE | FILE_SHARE_READ, &sa, OPEN_ALWAYS,
                   FILE_ATTRIBUTE_NORMAL, NULL);
  }

  // on windows
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  si.dwFlags |= STARTF_USESTDHANDLES;
  si.hStdInput = NULL;
  if (rdt & redirect_t::STDERR)
    si.hStdError = h;
  if (rdt & redirect_t::STDOUT)
    si.hStdOutput = h;

  ZeroMemory(&pi, sizeof(pi));

  gettimeofday(&Time1, NULL);

  char* cmdline_ptr = new char[cmdline.length() + 1];
  if (!cmdline_ptr) {
    _ret.failure = execute_result::EXEC;
    return _ret;
  }
  strncpy(cmdline_ptr, cmdline.c_str(), cmdline.length());
  cmdline_ptr[cmdline.length()] = '\0';

  // Start the child process.
  if (!CreateProcess(NULL,        // No module name (use command line)
                     cmdline_ptr, // Command line
                     NULL,        // Process handle not inheritable
                     NULL,        // Thread handle not inheritable
                     FALSE,       // Set handle inheritance to FALSE
                     0,           // No creation flags
                     NULL,        // Use parent's environment block
                     NULL,        // Use parent's starting directory
                     &si,         // Pointer to STARTUPINFO structure
                     &pi)         // Pointer to PROCESS_INFORMATION structure
  ) {
    _ret.failure = execute_result::EXEC;
    delete[] cmdline_ptr;
    return _ret;
  }

  delete[] cmdline_ptr;
  // wait for its exit
  WaitForSingleObject(pi.hProcess, INFINITE);
  DWORD exitCode;
  BOOL result = GetExitCodeProcess(pi.hProcess, &exitCode);

  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);

  gettimeofday(&Time2, NULL);
  _ret.seconds = ((Time2.tv_usec + Time2.tv_sec * 1000000.0) -
                  (Time1.tv_usec + Time1.tv_sec * 1000000.0)) /
                 1000000.0;

  if (!result) {
    _ret.failure = execute_result::WAIT;
    return _ret;
  }

  _ret.ret = exitCode;
  _ret.subexit_normal = true;
  _ret.timeout = false;
  _ret.failure = execute_result::NONE;
  return _ret;
#else
  // set up the pipe to transfer subprocess's information before exec
  // so close on exec
  gettimeofday(&Time1, NULL);

#if defined(__linux__)
  pipe2(pipefd, O_CLOEXEC); // pipe2 is linux only feature!
#elif defined(__unix__) || defined(unix) || defined(__APPLE__) ||              \
    defined(__MACH__) || defined(__FreeBSD__)
  pipe(pipefd);
#endif

  // on *nix, spawn a child process to do this
  pid_t pid = fork();

  if (pid == -1) {
    _ret.failure = execute_result::FORK;
    // not able to create no process
    return _ret;
  }

  // now forked ...
  if (pid == 0) {

    if (timeout != 0) // only if we want to have the time-out feature
      setpgid(0, 0);  // creates a new proces group

    close(pipefd[0]); // close the read end
#if !defined(__linux__)
    fcntl(pipefd[1], F_SETFD, FD_CLOEXEC);
#endif

    unsigned char report_to_parent;

    // The child
    // will replace the image and execute the bash
    ILA_INFO << "Execute subprocess: [" << cmdline << "]";
    if (!redirect_output_file.empty()) {
      ILA_INFO << "Redirect to:" << redirect_output_file;
      int fd;
      fd = open(redirect_output_file.c_str(), O_WRONLY | O_CREAT | O_TRUNC,
                S_IRUSR | S_IWUSR);
      if (fd < 0) {
        perror(NULL);
        ILA_ERROR << "Failed to open " << redirect_output_file;
        report_to_parent = execute_result::PREIO;
        write(pipefd[1], (void*)&report_to_parent, sizeof(report_to_parent));
        exit(1);
      }
      if (rdt & redirect_t::STDOUT)
        dup2(fd, STDOUT_FILENO);
      if (rdt & redirect_t::STDERR)
        dup2(fd, STDERR_FILENO);
      close(fd);
    }

    // this is memory leak, but I have no other way...
    // hope this will be reclaimed by OS
    // + 1 for NULL

    const int MAX_ARG = 64;
    char* argv[MAX_ARG];
    if (cmdargs.size() >= MAX_ARG) {
      ILA_ERROR << "Too many args";
      report_to_parent = execute_result::ARG;
      write(pipefd[1], (void*)&report_to_parent, sizeof(report_to_parent));
      exit(1);
    }
    // ILA_ASSERT(cmdargs.size() < MAX_ARG) << "Too many args";

    for (auto it = cmdargs.begin(); it != cmdargs.end(); ++it) {
      // this is memory leak, I know, but what can I do ?
      argv[it - cmdargs.begin()] = new char[it->size() + 1];
      strcpy(argv[it - cmdargs.begin()], it->c_str());
    }
    argv[cmdargs.size()] = NULL;

    report_to_parent = execute_result::NONE;
    write(pipefd[1], (void*)&report_to_parent, sizeof(report_to_parent));

    int ret = execvp(cmdargs[0].c_str(), argv);
    // if not successful
    if (ret == -1) {
      report_to_parent = execute_result::EXEC;
      write(pipefd[1], (void*)&report_to_parent, sizeof(report_to_parent));
    }
    close(pipefd[1]);
    exit(ret);
  } else {
    // The parent will wait for its end
    int infop;
    unsigned char child_report;
    struct sigaction new_act;
    struct sigaction old_act;
    static_assert(sizeof(child_report) == 1,
                  "Expect child_report to be of 1 byte");

    close(pipefd[1]); // close the write end
    auto readlen = read(pipefd[0], (void*)&child_report,
                        sizeof(child_report)); /* Flawfinder: ignore */
    /*
    Justifications:
    - There is no loop.
    - This is not a typical C string, and we don't rely on the ending '\0'
    - It will read at most 1 byte (guarded by the static assert above)
    */

    if (readlen == -1 || readlen != sizeof(child_report)) {
      _ret.failure = execute_result::PREIO;
      close(pipefd[0]);
      return _ret;
    }
    if (child_report != execute_result::NONE) {
      // the child has error before exec
      _ret.failure = static_cast<execute_result::_failure>(child_report);
      close(pipefd[0]);
      return _ret;
    }

    child_pid = pid;

    if (!pid_file_name.empty()) {
      std::ofstream fout(pid_file_name);
      fout << child_pid << std::endl;
    }
    // set alarm
    if (timeout != 0) {
      shared_time_out = 0;
      new_act.sa_handler = parent_alarm_handler;
      sigemptyset(&new_act.sa_mask);
      new_act.sa_flags = 0;

      sigaction(SIGALRM, &new_act, &old_act);
      alarm(timeout);
    }
    // wait for sub-process
    int wait_pid_res = waitpid(pid, &infop, 0);

    gettimeofday(&Time2, NULL);
    _ret.seconds = ((Time2.tv_usec + Time2.tv_sec * 1000000.0) -
                    (Time1.tv_usec + Time1.tv_sec * 1000000.0)) /
                   1000000.0;

    if (timeout != 0) {
      alarm(0);                           // cancel if previously set
      sigaction(SIGALRM, &old_act, NULL); // restore the old one
    }

    if (timeout == 0 && wait_pid_res == -1) {
      _ret.failure = execute_result::WAIT;
      perror(NULL);
      close(pipefd[0]);
      return _ret;
    }

    if (wait_pid_res != -1)
      _ret.subexit_normal = WIFEXITED(infop);

    // read again, if exec suceeded, it should be EOF (read will fail)
    int sec_read = read(pipefd[0], (void*)&child_report,
                        sizeof(child_report)); /* Flawfinder: ignore */
    /*
    Justifications:
    - There is no loop.
    - This is not a typical C string, and we don't rely on the ending '\0'.
    - It will read at most 1 byte (guarded by the static assert above).
    - We are not using the read data at all.
    */
    child_report = 0;                      // to make static analyzer happy
    if (sec_read != 0 && sec_read != -1) { // not eof
      _ret.failure = execute_result::EXEC;
      close(pipefd[0]);
      return _ret;
    }

    _ret.ret = WEXITSTATUS(infop);
    _ret.failure = execute_result::NONE;
    _ret.timeout = timeout != 0 && shared_time_out;

    if (!pid_file_name.empty()) {
      std::ofstream fout(pid_file_name);
      fout << 0 << std::endl;
    }

    close(pipefd[0]);
    return _ret;
  } // end of parent
#endif
}

/// read the last meaningful line from a file
std::string os_portable_read_last_line(const std::string& filename) {
  std::ifstream fin(filename);
  if (!fin.is_open()) {
    ILA_ERROR << "Error open for read:" << filename;
    return "";
  }
  fin.seekg(-1, std::ios_base::end);

  bool keepLooping = true;
  bool has_alnum = false;
  while (keepLooping) {
    char ch;
    fin.get(ch); // Get current byte's data
    if (std::isalnum(ch))
      has_alnum = true;

    if ((int)fin.tellg() <= 1) { // If the data was at or before the 0th byte
      fin.seekg(0);              // The first line is the last line
      keepLooping = false;       // So stop there
    } else if (ch == '\r' && has_alnum) {
      keepLooping = false;                // \n\r or just  \r
    } else if (ch == '\n' && has_alnum) { // If the data was a newline
      fin.get(ch);
      keepLooping = false; // Stop at the current position.
      if (ch != '\r')
        fin.seekg(-1, std::ios_base::cur); // not \n\r, put it back
    } else { // If the data was neither a newline nor at the 0 byte
      fin.seekg(-2, std::ios_base::cur); // Move to the front of that data, then
                                         // to the front of the data before it
    }
  }

  std::string lastLine;
  std::getline(fin, lastLine);
  fin.close();
  return lastLine;
}

/// Change current directory
bool os_portable_chdir(const std::string& dirname) {

#if defined(_WIN32) || defined(_WIN64)
  // windows
  if (_chdir(dirname.c_str()) != 0) {
    ILA_ERROR << "Failed to change to dir:" << dirname;
    return false;
  }
  return true;

#else
  int ret = chdir(dirname.c_str());
  ILA_ERROR_IF(ret != 0) << "Failed to change to dir:" << dirname;
  return ret == 0;
#endif
}

/// Get the current directory
std::string os_portable_getcwd() {
  return fs::current_path().string();
} // os_portable_getcwd

#if (defined(__unix__) || defined(unix) || defined(__APPLE__) ||               \
     defined(__MACH__) || defined(__FreeBSD__)) &&                             \
    !defined(__linux__)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

struct fmem {
  size_t pos;
  size_t size;
  char* buffer;
};
typedef struct fmem fmem_t;

static int readfn(void* handler, char* buf, int size) {
  fmem_t* mem = (fmem_t*)handler;
  size_t available = mem->size - mem->pos;

  if (size > available) {
    size = available;
  }
  memcpy(buf, mem->buffer, sizeof(char) * size);
  mem->pos += size;

  return size;
}

static int writefn(void* handler, const char* buf, int size) {
  fmem_t* mem = (fmem_t*)handler;
  size_t available = mem->size - mem->pos;

  if (size > available) {
    size = available;
  }
  memcpy(mem->buffer, buf, sizeof(char) * size);
  mem->pos += size;

  return size;
}

static fpos_t seekfn(void* handler, fpos_t offset, int whence) {
  size_t pos;
  fmem_t* mem = (fmem_t*)handler;

  switch (whence) {
  case SEEK_SET:
    pos = offset;
    break;
  case SEEK_CUR:
    pos = mem->pos + offset;
    break;
  case SEEK_END:
    pos = mem->size + offset;
    break;
  default:
    return -1;
  }

  if (pos > mem->size) {
    return -1;
  }

  mem->pos = pos;
  return (fpos_t)pos;
}

static int closefn(void* handler) {
  free(handler);
  return 0;
}

FILE* fmemopen_osx(void* buf, size_t size, const char* mode) {
  // This data is released on fclose.
  fmem_t* mem = (fmem_t*)malloc(sizeof(fmem_t));

  // Zero-out the structure.
  memset(mem, 0, sizeof(fmem_t));

  mem->size = size;
  mem->buffer = (char*)buf;

  // funopen's man page:
  // https://developer.apple.com/library/mac/#documentation/Darwin/Reference/ManPages/man3/funopen.3.html
  return funopen(mem, readfn, writefn, seekfn, closefn);
} // fmemopen_osx

#endif // fmemopen_osx guard

}; // namespace ilang
