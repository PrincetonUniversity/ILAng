/// \file Utility to deal with filesystem
/// This could be possible OS dependent so we want to provide a portable layer
/// C++17 and after should support something like experimental/filesystem, but
/// we don't rely on it
// --- Hongce Zhang

#include <ilang/util/fs.h>

#include <fstream>
#include <iomanip>

#include <cstdlib>

#if defined(_WIN32) || defined(_WIN64)
// windows
#include <direct.h>
#include <winbase.h>
#include <windows.h>
#else
// on *nix
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#endif

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

static bool endsWith(const std::string& str, const std::string& suffix) {
  return str.size() >= suffix.size() &&
         0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
}

static bool startsWith(const std::string& str, const std::string& prefix) {
  return str.size() >= prefix.size() &&
         0 == str.compare(0, prefix.size(), prefix);
}

/// Create a dir, true -> suceeded , ow false
bool os_portable_mkdir(const std::string& dir) {
#if defined(_WIN32) || defined(_WIN64)
  // on windows
  return _mkdir(dir.c_str()) == 0;
#else
  // on *nix
  struct stat statbuff;
  if (stat(dir.c_str(), &statbuff) != -1) {
    if (S_ISDIR(statbuff.st_mode)) {
      ILA_WARN << "Directory " << dir << " already exists.";
      return true;
    }
  }
  return mkdir(dir.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != -1;
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
  if (!endsWith(str1, sep))
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

/// Extract path from path
/// C:\a\b\c.txt -> C:\a\b\ 
/// C:\a\b\c -> C:\a\b
/// d/e/ghi  -> d/e/
std::string os_portable_path_from_path(const std::string& path) {

  std::string sep;
#if defined(_WIN32) || defined(_WIN64)
  // on windows
  sep = "\\";
#else
  // on *nix
  sep = "/";
#endif
  if (path.find(sep) == path.npos)
    return "./";
  auto pos = path.rfind(sep);
  ILA_ASSERT(pos != path.npos);
  return path.substr(0,pos+1); // include sep
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


#if defined(__unix__) || defined(unix) || defined(__APPLE__) || defined(__MACH__) || defined(__linux__) || defined(__FreeBSD__)

volatile sig_atomic_t child_pid;
volatile sig_atomic_t shared_time_out;

void parent_alarm_handler(int signum) {
  if (child_pid != 0) {
    kill(-child_pid, SIGTERM);
    shared_time_out = 1;
  }
}
#endif

execute_result os_portable_execute_shell(
  const std::vector<std::string> & cmdargs,
  const std::string & redirect_output_file,
  redirect_t rdt,
  unsigned timeout,
  const std::string & pid_file_name ) 
{
  int pipefd[2];
  execute_result _ret;
  struct timeval Time1,Time2; // count the time

  _ret.seconds = 0;
  _ret.timeout = false;
  
  auto cmdline = Join(cmdargs, ",");
  ILA_ASSERT(not cmdargs.empty()) << "API misuse!";

#if defined(_WIN32) || defined(_WIN64)
  ILA_ERROR_IF(timeout != 0) << "Timeout feature is not supported on WIN.";
  HANDLE h;
  if (not redirect_output_file.empty() and rdt != redirect_t::NONE) {
    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(sa);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;
    h = CreateFile(_T(redirect_output_file.c_str()),
        FILE_APPEND_DATA,
        FILE_SHARE_WRITE | FILE_SHARE_READ,
        &sa,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL );
  }

  // on windows
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  ZeroMemory( &si, sizeof(si) );
  si.cb = sizeof(si);
  si.dwFlags |= STARTF_USESTDHANDLES;
  si.hStdInput = NULL;
  if (rdt & redirect_t::STDERR)
    si.hStdError = h;
  if (rdt & redirect_t::STDOUT)
    si.hStdOutput = h;

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
    ) {
      _ret.failure = execute_result::EXEC;
      return _ret;
    }
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);
  _ret.failure = execute_result::NONE;
  return _ret; 
#else
  // set up the pipe to transfer subprocess's information before exec
  // so close on exec
  gettimeofday(&Time1, NULL);

  pipe2(pipefd, O_CLOEXEC); // 
  // on *nix, spawn a child process to do this
  pid_t pid = fork();
  
  if (pid == -1) {
    _ret.failure = execute_result::FORK;
    // not able to create no process
    return _ret;
  }

  // now forked ...
  if (pid == 0) {

    if(timeout != 0) // only if we want to have the time-out feature
      setpgid(0,0); // creates a new proces group 
    
    close(pipefd[0]); // close the read end
    int report_to_parent;

    // The child
    // will replace the image and execute the bash
    ILA_INFO<<"Execute subprocess: [" << cmdline << "]";
    if (not redirect_output_file.empty()) {
      ILA_INFO<<"Redirect to:" << redirect_output_file;
      int fd;
      fd = open(redirect_output_file.c_str(), O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR );
      if (fd < 0) {
        perror(NULL);
        ILA_ERROR << "Failed to open " << redirect_output_file;
        report_to_parent = execute_result::PREIO;
        write(pipefd[1], (void *) & report_to_parent, sizeof(report_to_parent));
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
    char * argv[MAX_ARG];
    if (cmdargs.size() >= MAX_ARG) {
      ILA_ERROR <<"Too many args";
      report_to_parent = execute_result::ARG;
      write(pipefd[1], (void *) & report_to_parent, sizeof(report_to_parent));
      exit(1);
    }
    //ILA_ASSERT(cmdargs.size() < MAX_ARG) << "Too many args";

    for(auto it = cmdargs.begin(); it != cmdargs.end(); ++ it) {
      // this is memory leak, I know, but what can I do ?
      argv[it-cmdargs.begin()] = new char[it->size() + 1];
      strcpy(argv[it-cmdargs.begin()], it->c_str());
    }
    argv[ cmdargs.size() ] = NULL;

    report_to_parent = execute_result::NONE;
    write(pipefd[1], (void *) & report_to_parent, sizeof(report_to_parent));

    int ret = execvp(cmdargs[0].c_str(), argv);
    // if not successful
    if (ret == -1) {
      report_to_parent = execute_result::NONE;
      write(pipefd[1], (void *) & report_to_parent, sizeof(report_to_parent));
    }
    exit(ret);
  } else {
    // The parent will wait for its end
    int infop;
    int child_report;
    struct sigaction new_act;
    struct sigaction old_act;

    close(pipefd[1]); // close the write end
    read(pipefd[0], (void *) &child_report, sizeof(child_report));
    if (child_report != execute_result::NONE) {
      // the child has error before exec
      _ret.failure = static_cast<execute_result::_failure>( child_report) ;
      close(pipefd[0]);
      return _ret;
    }

    child_pid = pid;
    
    if (!pid_file_name.empty()) {
      std::ofstream fout(pid_file_name);
      fout << child_pid << std::endl;
    }
    // set alarm
    if(timeout != 0) {
      shared_time_out = 0;
      new_act.sa_handler = parent_alarm_handler;
      sigemptyset (&new_act.sa_mask);
      new_act.sa_flags = 0;

      sigaction(SIGALRM, &new_act, &old_act);
      alarm(timeout);
    }
    // wait for sub-process
    int wait_pid_res = waitpid(pid, &infop, 0);
    
    gettimeofday(&Time2, NULL);
    _ret.seconds = 
      ( 
        (Time2.tv_usec + Time2.tv_sec*1000000.0) -  
        (Time1.tv_usec + Time1.tv_sec*1000000.0) ) / 1000000.0;

    if(timeout != 0) {
      alarm(0); //cancel if previously set
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
    int sec_read = read(pipefd[0], (void *) &child_report, sizeof(child_report));
    if (sec_read != 0) { // not eof
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
std::string os_portable_read_last_line(const std::string  & filename) {
  std::ifstream fin(filename);
  if(not fin.is_open()) {
    ILA_ERROR << "Error open for read:"<<filename;
    return "";
  }
  fin.seekg(-1, std::ios_base::end);

  bool keepLooping = true;
  bool has_alnum = false;
  while(keepLooping) {
      char ch;
      fin.get(ch);                            // Get current byte's data
      if(std::isalnum(ch))
        has_alnum = true;

      if((int)fin.tellg() <= 1) {             // If the data was at or before the 0th byte
          fin.seekg(0);                       // The first line is the last line
          keepLooping = false;                // So stop there
      }
      else if(ch == '\r' && has_alnum) {
        keepLooping = false; // \n\r or just  \r
      }
      else if(ch == '\n' && has_alnum ) {                   // If the data was a newline
          fin.get(ch);
          keepLooping = false;                // Stop at the current position.
          if (ch != '\r')
            fin.seekg(-1,std::ios_base::cur); // not \n\r, put it back
      }
      else {                                  // If the data was neither a newline nor at the 0 byte
          fin.seekg(-2,std::ios_base::cur);   // Move to the front of that data, then to the front of the data before it
      }
  }

  std::string lastLine;            
  std::getline(fin,lastLine);         
  fin.close();
  return lastLine;
}

/// Change current directory
bool os_portable_chdir(const std::string  & dirname) {

#if defined(_WIN32) || defined(_WIN64)
  // windows
  if (_chdir(dirname.c_str()) != 0) {
    ILA_ERROR << "Failed to change to dir:"<<dirname;
    return false;
  }
  return true;

#else
  int ret = chdir(dirname.c_str());
  ILA_ERROR_IF(ret != 0) << "Failed to change to dir:"<<dirname;
  return ret == 0;
#endif 
}

/// Get the current directory
std::string os_portable_getcwd() {
#if defined(_WIN32) || defined(_WIN64)
  // windows
  size_t len = GetCurrentDirectory(0,NULL);
  char * buffer = new char [len];
  if ( GetCurrentDirectory(buffer,len) == 0) {
    ILA_ERROR << "Unable to get the current working directory.";
    delete [] buffer;
    return "";
  }
  std::string ret(buffer);
  delete [] buffer;
  return ret;
#else
  // *nix
  size_t buff_size = 128;
  char * buffer = new char[buff_size];
  while(getcwd(buffer, buff_size) == NULL) {
    delete [] buffer;
    buff_size *= 2;
    buffer = new char[buff_size]; // resize
  }
  std::string ret(buffer);
  delete []buffer;
  return ret;
#endif 
}

}; // namespace ilang
