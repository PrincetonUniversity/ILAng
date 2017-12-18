/// \file
/// Source for the class BoolVal, BvVal, and MemVal

#include "ila/ast/sort_value.h"
#include "util/log.h"
#include <locale>

namespace ila {

// ------------------------- Class BoolVal ---------------------------------- //
BoolVal::BoolVal() {
  ILA_ERROR << "Undefined default constructor for class BoolVal.\n";
}

BoolVal::BoolVal(const bool& val) : val_(val) {}

bool StrToBool(const std::string& str) {
  std::locale loc;
  std::string up = std::toupper(str, loc);
  ILA_ASSERT((up == "TRUE") || (up == "FALSE")) << "Unknown boolean value "
                                                << up << "\n";
  return (up == "TRUE");
}

BoolVal::BoolVal(const std::string& str) { val_ = StrToBool(str); }

BoolVal::BoolVal(const char* cstr) { val_ = StrToBool(std::string(cstr)); }

BoolVal::~BoolVal() {}

std::string BoolVal::str() const { return (val_ ? "TRUE" : "FALSE"); }

const bool& BoolVal::val() const { return val_; }

std::ostream& BoolVal::Print(std::ostream& out) const { return out << str(); }

std::ostream& operator<<(std::ostream& out, const BoolVal& val) {
  return val.Print(out);
}

// ------------------------- Class BvVal -------------------------------------//
BvVal::BvVal() {
  ILA_ERROR << "Undefined default constructor for class BoolVal.\n";
}

BvVal::BvVal(const int& val) : val_(val) {}

BvVal::BvVal(const std::string& str) {
  try {
    val_ = std::stoi(str);
  } catch (const std::exception& e) {
    ILA_ERROR << "Converting non-numeric value " << str << " to int.\n";
    val_ = 0;
  }
}

BvVal::~BvVal() {}

std::string BvVal::str() const { return std::to_string(val_); }

const int& BvVal::val() const { return val_; }

std::ostream& BvVal::Print(std::ostream& out) const { return out << str(); }

std::ostream& operator<<(std::ostream& out, const BvVal& val) {
  return val.Print(out);
}

// ------------------------- Class MemVal ------------------------------------//
MemVal::MemVal() {
  ILA_ERROR << "Undefined default constructor for class BoolVal.\n";
}

} // namespace ila

