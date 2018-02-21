/// \file
/// Source for the class BoolVal, BvVal, and MemVal

#include "ila/ast/sort_value.h"
#include "util/log.h"
#include "util/str_util.h"

namespace ila {

// ------------------------- Class BoolVal ---------------------------------- //
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
MemVal::MemVal(const int& def_val) : default_(def_val) { val_map_.clear(); }

MemVal::MemVal(const int& def_val, const MemValMap& val_map)
    : default_(def_val) {
  val_map_ = val_map;
}

MemVal::~MemVal() {}

const MemValMap& MemVal::val_map() const { return val_map_; }

const int& MemVal::def_val() const { return default_; }

const int& MemVal::get_data(const int& addr) const {
  auto pos = val_map_.find(addr);
  if (pos == val_map_.end()) {
    return default_;
  } else {
    return pos->second;
  }
}

void MemVal::set_data(const int& addr, const int& data) {
  val_map_[addr] = data;
}

std::ostream& MemVal::Print(std::ostream& out) const {
  out << "[Def: " << default_ << "][";
  for (auto val : val_map_) {
    out << "(" << val.first << ", " << val.second << ")";
  }
  return out << "]";
}

std::ostream& operator<<(std::ostream& out, const MemVal& val) {
  return val.Print(out);
}

} // namespace ila

