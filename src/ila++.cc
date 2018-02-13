/// \file
/// Source for the c++ API.

#include "ila++.h"
#include "ila/instr_lvl_abs.h"

namespace ila {

ExprRef::ExprRef(std::shared_ptr<Expr> ptr) : ptr_(ptr) {}

ExprRef::~ExprRef() {}

ExprRef ExprRef::operator+(const ExprRef& rhs) const {
  auto s = ExprFuse::Add(ptr_, rhs.ptr_);
  return ExprRef(s);
}

ExprRef BoolConst(bool val) {
  auto v = ExprFuse::BoolConst(val);
  return ExprRef(v);
}

ExprRef BvConst(const int& bv_val, const int& bit_width) {
  auto v = ExprFuse::BvConst(bv_val, bit_width);
  return ExprRef(v);
}

} // namespace ila

