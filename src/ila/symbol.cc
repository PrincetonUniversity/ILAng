/// \file
/// Source for the class Symbol.

#include "ila/symbol.h"
#include "util/log.h"
#include "util/str_util.h"

/// \namespace ila
namespace ila {

size_t Symbol::counter_ = 0;

Symbol::Symbol() : name_("") { id_ = ++counter_; }

Symbol::Symbol(const char* str) : name_(str) { id_ = ++counter_; }

Symbol::Symbol(const std::string& str) : name_(str) { id_ = ++counter_; }

Symbol::~Symbol() {}

const std::string& Symbol::str() const { return name_; }

const char* Symbol::c_str() const { return name_.c_str(); }

const std::string Symbol::format_str(const std::string& prefix,
                                     const std::string& suffix) const {
  std::string res = name_;
  if (prefix != "")
    res = prefix + "_" + res;
  if (suffix != "")
    res = res + "_" + suffix;
  return res;
}

#if 0
const char* Symbol::format_c_str(const std::string& prefix,
                                 const std::string& suffix) const {
  const char* res = format_str(prefix, suffix).c_str();
  return res;
}
#endif

int Symbol::to_int() const { return StrToInt(name_); }

const size_t& Symbol::id() const { return id_; }

void Symbol::set_name(const std::string& name) {
  ILA_WARN_IF(name_ != "") << "Update name (previously as " << name_ << ").\n";
  name_ = name;
}

std::ostream& Symbol::Print(std::ostream& out) const { return out << name_; }

Symbol& Symbol::operator=(const Symbol& rhs) {
  name_ = rhs.name_;
  return *this;
}

bool operator==(const Symbol& lhs, const Symbol& rhs) {
  return (lhs.name_ == rhs.name_);
}

std::ostream& operator<<(std::ostream& out, const Symbol& s) {
  return s.Print(out);
}

} // namespace ila

