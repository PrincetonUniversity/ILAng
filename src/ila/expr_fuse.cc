/// \file
/// Source of the class ExpFusee

#include "ila/expr_fuse.h"
#include "ila/hash_ast.h"
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

ExprPtr ExprFuse::Shl(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpShl>(l, r);
}

ExprPtr ExprFuse::Ashr(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpAshr>(l, r);
}

ExprPtr ExprFuse::Lshr(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpLshr>(l, r);
}

ExprPtr ExprFuse::Add(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpAdd>(l, r);
}

ExprPtr ExprFuse::Sub(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpSub>(l, r);
}

ExprPtr ExprFuse::And(const ExprPtr l, const bool& r) {
  auto rc = ExprFuse::BoolConst(r);
  return ExprFuse::And(l, rc);
}

ExprPtr ExprFuse::Or(const ExprPtr l, const bool& r) {
  auto rc = ExprFuse::BoolConst(r);
  return ExprFuse::Or(l, rc);
}

ExprPtr ExprFuse::Xor(const ExprPtr l, const bool& r) {
  auto rc = ExprFuse::BoolConst(r);
  return ExprFuse::Xor(l, rc);
}

ExprPtr ExprFuse::Shl(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Shl(l, rc);
}

ExprPtr ExprFuse::Ashr(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Ashr(l, rc);
}

ExprPtr ExprFuse::Lshr(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Lshr(l, rc);
}

ExprPtr ExprFuse::Add(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Add(l, rc);
}

ExprPtr ExprFuse::Sub(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Sub(l, rc);
}

ExprPtr ExprFuse::Eq(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpEq>(l, r);
}

ExprPtr ExprFuse::Ne(const ExprPtr l, const ExprPtr r) {
  auto eq = std::make_shared<ExprOpEq>(l, r);
  return std::make_shared<ExprOpNot>(eq);
}

ExprPtr ExprFuse::Lt(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpLt>(l, r);
}

ExprPtr ExprFuse::Gt(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpGt>(l, r);
}

ExprPtr ExprFuse::Le(const ExprPtr l, const ExprPtr r) {
  auto eq = std::make_shared<ExprOpEq>(l, r);
  auto lt = std::make_shared<ExprOpLt>(l, r);
  return std::make_shared<ExprOpOr>(eq, lt);
}

ExprPtr ExprFuse::Ge(const ExprPtr l, const ExprPtr r) {
  auto eq = std::make_shared<ExprOpEq>(l, r);
  auto gt = std::make_shared<ExprOpGt>(l, r);
  return std::make_shared<ExprOpOr>(eq, gt);
}
ExprPtr ExprFuse::Ult(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpUlt>(l, r);
}

ExprPtr ExprFuse::Ugt(const ExprPtr l, const ExprPtr r) {
  return std::make_shared<ExprOpUgt>(l, r);
}

ExprPtr ExprFuse::Ule(const ExprPtr l, const ExprPtr r) {
  auto eq = std::make_shared<ExprOpEq>(l, r);
  auto ult = std::make_shared<ExprOpUlt>(l, r);
  return std::make_shared<ExprOpOr>(eq, ult);
}

ExprPtr ExprFuse::Uge(const ExprPtr l, const ExprPtr r) {
  auto eq = std::make_shared<ExprOpEq>(l, r);
  auto ugt = std::make_shared<ExprOpUgt>(l, r);
  return std::make_shared<ExprOpOr>(eq, ugt);
}

ExprPtr ExprFuse::Eq(const ExprPtr l, const bool& r) {
  auto rc = ExprFuse::BoolConst(r);
  return ExprFuse::Eq(l, rc);
}

ExprPtr ExprFuse::Eq(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Eq(l, rc);
}

ExprPtr ExprFuse::Ne(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Ne(l, rc);
}

ExprPtr ExprFuse::Lt(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Lt(l, rc);
}

ExprPtr ExprFuse::Gt(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Gt(l, rc);
}

ExprPtr ExprFuse::Le(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Le(l, rc);
}

ExprPtr ExprFuse::Ge(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Ge(l, rc);
}

ExprPtr ExprFuse::Ult(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Ult(l, rc);
}

ExprPtr ExprFuse::Ugt(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Ugt(l, rc);
}

ExprPtr ExprFuse::Ule(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Ule(l, rc);
}

ExprPtr ExprFuse::Uge(const ExprPtr l, const int& r) {
  auto rc = ExprFuse::BvConst(r, l->sort()->bit_width());
  return ExprFuse::Uge(l, rc);
}

ExprPtr ExprFuse::Load(const ExprPtr mem, const ExprPtr addr) {
  return std::make_shared<ExprOpLoad>(mem, addr);
}

ExprPtr ExprFuse::Store(const ExprPtr mem, const ExprPtr addr,
                        const ExprPtr data) {
  return std::make_shared<ExprOpStore>(mem, addr, data);
}

ExprPtr ExprFuse::Load(const ExprPtr mem, const int& addr) {
  auto ac = ExprFuse::BvConst(addr, mem->sort()->addr_width());
  return ExprFuse::Load(mem, ac);
}

ExprPtr ExprFuse::Store(const ExprPtr mem, const int& addr, const int& data) {
  auto ac = ExprFuse::BvConst(addr, mem->sort()->addr_width());
  auto dc = ExprFuse::BvConst(data, mem->sort()->data_width());
  return ExprFuse::Store(mem, ac, dc);
}

ExprPtr ExprFuse::Concat(const ExprPtr hi, const ExprPtr lo) {
  return std::make_shared<ExprOpConcat>(hi, lo);
}

ExprPtr ExprFuse::Extract(const ExprPtr bv, const int& hi, const int& lo) {
  return std::make_shared<ExprOpExtract>(bv, hi, lo);
}

ExprPtr ExprFuse::ZExt(const ExprPtr bv, const int& out_width) {
  return std::make_shared<ExprOpZExt>(bv, out_width);
}

ExprPtr ExprFuse::SExt(const ExprPtr bv, const int& out_width) {
  return std::make_shared<ExprOpSExt>(bv, out_width);
}

ExprPtr ExprFuse::AppFunc(const FuncPtr func) {
  return std::shared_ptr<ExprOpAppFunc>(new ExprOpAppFunc(func, {}));
}

ExprPtr ExprFuse::AppFunc(const FuncPtr func, const ExprPtr arg0) {
  return std::shared_ptr<ExprOpAppFunc>(new ExprOpAppFunc(func, {arg0}));
}

ExprPtr ExprFuse::AppFunc(const FuncPtr func, const ExprPtr arg0,
                          const ExprPtr arg1) {
  return std::shared_ptr<ExprOpAppFunc>(new ExprOpAppFunc(func, {arg0, arg1}));
}

ExprPtr ExprFuse::AppFunc(const FuncPtr func, const ExprPtrVec& args) {
  return std::shared_ptr<ExprOpAppFunc>(new ExprOpAppFunc(func, args));
}

ExprPtr ExprFuse::Imply(const ExprPtr p, const ExprPtr q) {
  return std::make_shared<ExprOpImply>(p, q);
}

ExprPtr ExprFuse::Ite(const ExprPtr cnd, const ExprPtr true_expr,
                      const ExprPtr false_expr) {
  return std::make_shared<ExprOpIte>(cnd, true_expr, false_expr);
}

bool ExprFuse::TopEq(const ExprPtr a, const ExprPtr b) {
  ExprMngr m;
  auto x = m.GetRep(a);
  auto y = m.GetRep(b);
  return x == y;
}

} // namespace ila

