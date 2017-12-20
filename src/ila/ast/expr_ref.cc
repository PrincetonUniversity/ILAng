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

ExprPtr ExprRef::NewBoolConst(const bool& val) {
  BoolVal v(val);
  return std::make_shared<ExprConst>(v);
}

ExprPtr ExprRef::NewBoolConst(const BoolVal& val) {
  return std::make_shared<ExprConst>(val);
}

ExprPtr ExprRef::NewBvConst(const int& val, const int& bit_width) {
  BvVal v(val);
  return std::make_shared<ExprConst>(v, bit_width);
}

ExprPtr ExprRef::NewBvConst(const BvVal& val, const int& bit_width) {
  return std::make_shared<ExprConst>(val, bit_width);
}

ExprPtr ExprRef::NewMemConst(const int& def_val, const int& addr_width,
                             const int& data_width) {
  MemVal v(addr_width, data_width, def_val);
  return std::make_shared<ExprConst>(v, addr_width, data_width);
}

ExprPtr ExprRef::NewMemConst(const MemVal& val, const int& addr_width,
                             const int& data_width) {
  return std::make_shared<ExprConst>(val, addr_width, data_width);
}

} // namespace ila

