/// \file
/// Source for the class Symbol.

#include <ilang/ila/symbol.h>

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

/// \namespace ilang
namespace ilang {

size_t Symbol::counter_ = 0;

Symbol::Symbol() {
  id_ = ++counter_;
  name_ = "$" + std::to_string(id_);
}

Symbol::Symbol(const char* str) : name_(str) { id_ = ++counter_; }

Symbol::Symbol(const std::string& str) : name_(str) { id_ = ++counter_; }

Symbol::Symbol(const Symbol& rhs) : name_(rhs.name_), id_(rhs.id_) {}

Symbol::~Symbol() {}

const std::string& Symbol::str() const { return name_; }

const char* Symbol::c_str() const { return name_.c_str(); }

const std::string Symbol::format_str(const std::string& prefix,
                                     const std::string& suffix) const {
  std::string res = name_;
  if (!prefix.empty()) {
    res = prefix + "_sEp_" + res;
  }
  if (!suffix.empty()) {
    res = res + "_sEp_" + suffix;
  }
  return res;
}

int Symbol::to_int() const { return StrToInt(name_); }

const size_t& Symbol::id() const { return id_; }

void Symbol::set_name(const std::string& name) { name_ = name; }

std::ostream& Symbol::Print(std::ostream& out) const { return out << name_; }

std::ostream& operator<<(std::ostream& out, const Symbol& s) {
  return s.Print(out);
}

Symbol& Symbol::operator=(const Symbol& rhs) {
  name_ = rhs.name_;
  return *this;
}

bool operator==(const Symbol& lhs, const Symbol& rhs) {
  return (lhs.name_ == rhs.name_);
}

bool operator<(const Symbol& lhs, const Symbol& rhs) {
  return (lhs.name_ < rhs.name_);
}

} // namespace ilang
