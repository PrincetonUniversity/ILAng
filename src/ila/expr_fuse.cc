/// \file
/// Source of the class ExpFusee

#include "ila/expr_fuse.h"
#include "util/str_util.h"

namespace ila {

std::string ExprFuse::prefix_ = "";

std::string ExprFuse::suffix_ = "";

ExprFuse::ExprFuse() {}

ExprFuse::~ExprFuse() {}

const std::string& ExprFuse::prefix() { return prefix_; }

const std::string& ExprFuse::suffix() { return suffix_; }

void ExprFuse::set_prefix(const std::string& prefix) { prefix_ = prefix; }

void ExprFuse::set_suffix(const std::string& suffix) { suffix_ = suffix; }

void ExprFuse::Reset() {
  prefix_ = "";
  suffix_ = "";
}

ExprPtr ExprFuse::NewBoolVar(const std::string& name) {
  std::string var_name = (prefix_ == "") ? name : StrConcat(prefix_, name);
  var_name = (suffix_ == "") ? var_name : StrConcat(var_name, suffix_);
  return std::make_shared<ExprVar>(var_name);
}

ExprPtr ExprFuse::NewBvVar(const std::string& name, const int& bit_width) {
  std::string var_name = (prefix_ == "") ? name : StrConcat(prefix_, name);
  var_name = (suffix_ == "") ? var_name : StrConcat(var_name, suffix_);
  return std::make_shared<ExprVar>(var_name, bit_width);
}

ExprPtr ExprFuse::NewMemVar(const std::string& name, const int& addr_width,
                            const int& data_width) {
  std::string var_name = (prefix_ == "") ? name : StrConcat(prefix_, name);
  var_name = (suffix_ == "") ? var_name : StrConcat(var_name, suffix_);
  return std::make_shared<ExprVar>(var_name, addr_width, data_width);
}

ExprPtr ExprFuse::BoolConst(const bool& val) {
  BoolVal v(val);
  return std::make_shared<ExprConst>(v);
}

ExprPtr ExprFuse::BoolConst(const BoolVal& val) {
  return std::make_shared<ExprConst>(val);
}

ExprPtr ExprFuse::BvConst(const int& val, const int& bit_width) {
  BvVal v(val);
  return std::make_shared<ExprConst>(v, bit_width);
}

ExprPtr ExprFuse::BvConst(const BvVal& val, const int& bit_width) {
  return std::make_shared<ExprConst>(val, bit_width);
}

ExprPtr ExprFuse::MemConst(const int& def_val, const int& addr_width,
                           const int& data_width) {
  MemVal v(addr_width, data_width, def_val);
  return std::make_shared<ExprConst>(v, addr_width, data_width);
}

ExprPtr ExprFuse::MemConst(const MemVal& val, const int& addr_width,
                           const int& data_width) {
  return std::make_shared<ExprConst>(val, addr_width, data_width);
}

ExprPtr ExprFuse::Negate(const ExprPtr arg) {
  return std::make_shared<ExprOpNeg>(arg);
}

ExprPtr ExprFuse::Complement(const ExprPtr arg) {
  return std::make_shared<ExprOpCompl>(arg);
}

ExprPtr ExprFuse::And(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpAnd>(l, r);
}

ExprPtr ExprFuse::Or(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpOr>(l, r);
}

ExprPtr ExprFuse::Eq(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpEq>(l, r);
}

} // namespace ila

