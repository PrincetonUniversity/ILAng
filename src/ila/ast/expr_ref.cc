/// \file
/// Source of the class ExprRef

#include "ila/ast/expr_ref.h"

namespace ila {

ExprRef::ExprRef() {}

ExprRef::~ExprRef() {}

ExprPtr ExprRef::NewBoolVar(const std::string& name) {
  return std::make_shared<ExprVar>(name);
}

ExprPtr ExprRef::NewBvVar(const std::string& name, const int& bit_width) {
  return std::make_shared<ExprVar>(name, bit_width);
}

ExprPtr ExprRef::NewMemVar(const std::string& name, const int& addr_width,
                           const int& data_width) {
  return std::make_shared<ExprVar>(name, addr_width, data_width);
}

ExprPtr ExprRef::BoolConst(const bool& val) {
  BoolVal v(val);
  return std::make_shared<ExprConst>(v);
}

ExprPtr ExprRef::BoolConst(const BoolVal& val) {
  return std::make_shared<ExprConst>(val);
}

ExprPtr ExprRef::BvConst(const int& val, const int& bit_width) {
  BvVal v(val);
  return std::make_shared<ExprConst>(v, bit_width);
}

ExprPtr ExprRef::BvConst(const BvVal& val, const int& bit_width) {
  return std::make_shared<ExprConst>(val, bit_width);
}

ExprPtr ExprRef::MemConst(const int& def_val, const int& addr_width,
                          const int& data_width) {
  MemVal v(addr_width, data_width, def_val);
  return std::make_shared<ExprConst>(v, addr_width, data_width);
}

ExprPtr ExprRef::MemConst(const MemVal& val, const int& addr_width,
                          const int& data_width) {
  return std::make_shared<ExprConst>(val, addr_width, data_width);
}

ExprPtr ExprRef::LogicalAnd(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpAnd>(l, r);
}

ExprPtr ExprRef::LogicalOr(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpOr>(l, r);
}

ExprPtr ExprRef::CompEq(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpEq>(l, r);
}

} // namespace ila

