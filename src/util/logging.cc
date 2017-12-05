/// \file
/// The source file for the logging system.

#include "util/logging.h"
#include <fstream>
#include <set>
#include <string>

namespace ila {

std::ostream* infostream;
std::ostream* log1stream;
std::ostream* log2stream;
std::ostream* nullstream;
std::set<std::string> enabledLogs;

void InitLog() {
  infostream = &std::cout;
  log1stream = new std::ofstream("/dev/null");
  log2stream = new std::ofstream("/dev/null");
  nullstream = new std::ofstream("/dev/null");
}

std::ostream& _log(std::ostream& l, std::string s) {
  // std::vector<std::string> parts;
  // boost::split(parts, s, boost::is_any_of("."));

  // ILA_ASSERT(parts.size() > 0, "Cannot be empty.");
  // std::string prefix = parts[0];
  // std::string prefix = static_cast<std::string>(s);
  std::string prefix = s;
  if (enabledLogs.find(prefix) != enabledLogs.end()) {
    return l << "[" << s << "] ";
  }
  /*
  for (unsigned i = 1; i != parts.size(); i++) {
    prefix += "." + parts[i];
    if (enabledLogs.find(prefix) != enabledLogs.end()) {
      return l << "[" << s << "] ";
    }
  }
  */
  return *nullstream;
}

std::ostream& INFO(std::string l) { return _log(*infostream, l); }
std::ostream& LOG1(std::string l) { return _log(*log1stream, l); }
std::ostream& LOG2(std::string l) { return _log(*log2stream, l); }

void ClearStream(std::ostream*& ptr) {
  if (ptr != &std::cout) {
    delete ptr;
  }
  ptr = new std::ofstream("/dev/null");
}

void SetStream(std::ostream*& ptr, const std::string& filename) {
  if (ptr != &std::cout) {
    delete ptr;
  }
  if (filename == "") {
    ptr = &std::cout;
  } else {
    ptr = new std::ofstream(filename);
  }
}

void SetLogLevel(int l, const std::string& name) {
  if (l == 0) {
    ClearStream(infostream);
    ClearStream(log1stream);
    ClearStream(log2stream);
  } else if (l == 1) {
    SetStream(infostream, name);
    ClearStream(log1stream);
    ClearStream(log2stream);
  } else if (l == 2) {
    SetStream(infostream, name);
    log1stream = infostream;
    ClearStream(log2stream);
  } else {
    SetStream(infostream, name);
    log1stream = infostream;
    log2stream = infostream;
  }
}

void EnableLog(const std::string& name) { enabledLogs.insert(name); }

void DisableLog(const std::string& name) { enabledLogs.erase(name); }

void ClearLogs() { enabledLogs.clear(); }

} // namespace ila

