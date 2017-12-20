/// \file
/// Source of the class ExpFusee

#include "ila/expr_fuse.h"

namespace ila {

ExprFuse::ExprFuse() {}

ExprFuse::~ExprFuse() {}

ExprPtr ExprFuse::NewBoolVar(const std::string& name) {
  return std::make_shared<ExprVar>(name);
}

ExprPtr ExprFuse::NewBvVar(const std::string& name, const int& bit_width) {
  return std::make_shared<ExprVar>(name, bit_width);
}

ExprPtr ExprFuse::NewMemVar(const std::string& name, const int& addr_width,
                            const int& data_width) {
  return std::make_shared<ExprVar>(name, addr_width, data_width);
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

ExprPtr ExprFuse::LogicalAnd(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpAnd>(l, r);
}

ExprPtr ExprFuse::LogicalOr(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpOr>(l, r);
}

ExprPtr ExprFuse::CompEq(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpEq>(l, r);
}

} // namespace ila

