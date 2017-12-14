/// \file
/// Source for the class Symbol.

#include "ila/symbol.h"
#include "util/log.h"

/// \namespace ila
namespace ila {

unsigned Symbol::counter_ = 0;

Symbol::Symbol() { data_ = std::to_string(++counter_); }

Symbol::Symbol(const char* str) : data_(str) {}

Symbol::Symbol(const std::string& str) : data_(str) {}

Symbol::~Symbol() {}

const std::string& Symbol::str() const { return data_; }

const char* Symbol::c_str() const { return data_.c_str(); }

int Symbol::to_int() const {
  try {
    return std::stoi(data_);
  } catch (const std::exception& e) {
    ILA_ERROR << "Converting non-numeric value " << data_ << " to int.\n";
    return -1;
  }
}

int Symbol::Hash() const {
  // TODO
  ILA_ERROR << "Symbol hashing not implemented.\n";
  return 0;
}

std::ostream& Symbol::Print(std::ostream& out) const { return out << data_; }

Symbol& Symbol::operator=(const Symbol& rhs) {
  data_ = s.data_;
  return *this;
}

bool operator==(const Symbol& lhs, const Symbol& rhs) {
  return (lhs.data_ == rhs.data_);
}

std::ostream& operator<<(std::ostream& out, const Symbol& s) {
  return s.Print(out);
}

} // namespace ila

