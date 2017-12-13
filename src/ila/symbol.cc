/// \file
/// Source for the class Symbol.

#include "ila/symbol.h"
#include "util/log.h"

/// \namespace ila
namespace ila {

unsigned Symbol::counter_ = 0;

Symbol::Symbol() { data_ = std::to_string(counter_++); }

Symbol::Symbol(const std::string& str) { data_ = str; }

Symbol::~Symbol() {}

int Symbol::ToInt() const {
  try {
    return std::stoi(data_);
  } catch (const std::exception& e) {
    ILA_ERROR << "Try to convert " << data_ << " to int.\n";
  }
  return -1;
}

const std::string& Symbol::Str() const { return data_; }

Symbol& Symbol::operator=(const Symbol& s) {
  data_ = s.data_;
  return *this;
}

bool operator==(const Symbol& lhs, const Symbol& rhs) {
  return (lhs.data_ == rhs.data_);
}

std::ostream& operator<<(std::ostream& out, const Symbol& s) {
  return out << s.data_;
}

#if 0
std::fstream& operator<<(std::fstream& out, const Symbol& s) {
  return out << s.data_;
}
#endif

} // namespace ila

