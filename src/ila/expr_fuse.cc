/// \file
/// Source of the class ExpFusee

#include "ila/expr_fuse.h"
#include "util/str_util.h"

namespace ila {

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
  return std::make_shared<ExprConst>(BoolVal(val));
}

ExprPtr ExprFuse::BoolConst(const BoolVal& val) {
  return std::make_shared<ExprConst>(val);
}

ExprPtr ExprFuse::BvConst(const int& val, const int& bit_width) {
  return std::make_shared<ExprConst>(BvVal(val), bit_width);
}

ExprPtr ExprFuse::BvConst(const BvVal& val, const int& bit_width) {
  return std::make_shared<ExprConst>(val, bit_width);
}

ExprPtr ExprFuse::MemConst(const int& def_val, const int& addr_width,
                           const int& data_width) {
  return std::make_shared<ExprConst>(MemVal(def_val), addr_width, data_width);
}

ExprPtr ExprFuse::MemConst(const MemVal& val, const int& addr_width,
                           const int& data_width) {
  return std::make_shared<ExprConst>(val, addr_width, data_width);
}

ExprPtr ExprFuse::Negate(const ExprPtr arg) {
  return std::make_shared<ExprOpNeg>(arg);
}

ExprPtr ExprFuse::Not(const ExprPtr arg) {
  return std::make_shared<ExprOpNot>(arg);
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

ExprPtr ExprFuse::Xor(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpXor>(l, r);
}

ExprPtr ExprFuse::Add(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpAdd>(l, r);
}

ExprPtr ExprFuse::Eq(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpEq>(l, r);
}

ExprPtr ExprFuse::Ne(const ExprPtr l, const ExprPtr r) {
  auto eq = std::make_shared<ExprOpEq>(l, r);
  return std::make_shared<ExprOpNot>(eq);
}

ExprPtr ExprFuse::Load(const ExprPtr mem, const ExprPtr addr) {
  return std::make_shared<ExprOpLoad>(mem, addr);
}

ExprPtr ExprFuse::Store(const ExprPtr mem, const ExprPtr addr,
                        const ExprPtr data) {
  return std::make_shared<ExprOpStore>(mem, addr, data);
}

ExprPtr ExprFuse::Concat(const ExprPtr hi, const ExprPtr lo) {
  return std::make_shared<ExprOpConcat>(hi, lo);
}

ExprPtr ExprFuse::Extract(const ExprPtr bv, const int& hi, const int& lo) {
  return std::make_shared<ExprOpExtract>(bv, hi, lo);
}

ExprPtr ExprFuse::Ite(const ExprPtr cnd, const ExprPtr true_expr,
                      const ExprPtr false_expr) {
  return std::make_shared<ExprOpIte>(cnd, true_expr, false_expr);
}

} // namespace ila

