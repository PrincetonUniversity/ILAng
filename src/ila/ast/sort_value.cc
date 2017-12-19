/// \file
/// Source for the class BoolVal, BvVal, and MemVal

#include "ila/ast/sort_value.h"
#include "util/log.h"
#include "util/str_util.h"

namespace ila {

// ------------------------- Class BoolVal ---------------------------------- //
BoolVal::BoolVal() {
  ILA_ERROR << "Undefined default constructor for class BoolVal.\n";
}

BoolVal::BoolVal(const bool& val) : val_(val) {}

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
  ILA_ERROR << "Undefined default constructor for class BvVal.\n";
}

BvVal::BvVal(const int& val) : val_(val) {}

BvVal::BvVal(const std::string& str) { val_ = StrToInt(str); }

BvVal::~BvVal() {}

std::string BvVal::str() const { return std::to_string(val_); }

const int& BvVal::val() const { return val_; }

std::ostream& BvVal::Print(std::ostream& out) const { return out << str(); }

std::ostream& operator<<(std::ostream& out, const BvVal& val) {
  return val.Print(out);
}

// ------------------------- Class MemVal ------------------------------------//
MemVal::MemVal() {
  ILA_ERROR << "Undefined default constructor for class MemVal.\n";
}

MemVal::~MemVal() {}

const std::map<BvVal, BvVal>& MemVal::val() const { return map_; }

const BvVal& MemVal::default_val() const { return default_; }

std::ostream& MemVal::Print(std::ostream& out) const {
  ILA_WARN << "Not Implemented.\n"; // TODO
  return out;
}

std::ostream& operator<<(std::ostream& out, const MemVal& val) {
  return val.Print(out);
}

} // namespace ila

