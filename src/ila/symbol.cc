/// \file
/// Source for the class Symbol.

#include "ila/symbol.h"
#include "util/log.h"

/// \namespace ila
namespace ila {

size_t Symbol::counter_ = 0;

Symbol::Symbol() : name_("") { id_ = ++counter_; }

#if 0
Symbol::Symbol(const Symbol& sym) : name_(sym.name_) { id_ = ++counter_; }
#endif

Symbol::Symbol(const char* str) : name_(str) { id_ = ++counter_; }

Symbol::Symbol(const std::string& str) : name_(str) { id_ = ++counter_; }

Symbol::~Symbol() {}

const std::string& Symbol::str() const { return name_; }

const char* Symbol::c_str() const { return name_.c_str(); }

int Symbol::to_int() const {
  try {
    return std::stoi(name_);
  } catch (const std::exception& e) {
    ILA_ERROR << "Converting non-numeric value " << name_ << " to int.\n";
    return -1;
  }
}

const size_t& Symbol::id() const { return id_; }

bool Symbol::set_name(const std::string& name) {
  if (name_ != "") {
    ILA_WARN << "Name has been assigned. Previously as " << name_ << ".\n";
    return false;
  }

  name_ = name;
  return true;
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

