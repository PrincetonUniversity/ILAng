/// \file
/// Source for the class ExprConst

#include "ila/ast/expr_const.h"
#include "util/log.h"

/// \namespace ila
namespace ila {

const std::string ExprConst::k_prefix_const_ = "const";

ExprConst::ExprConst() {
  ILA_ERROR << "Undefined default constructor for class ExprConst.\n";
}

ExprConst::ExprConst(const BoolVal& bool_val) : bool_val_(bool_val) {
  set_arity(0);
  set_num_param(0);
  set_sort(Sort());
}

ExprConst::ExprConst(const BvVal& bv_val, const int& bit_width)
    : bv_val_(bv_val) {
  set_arity(0);
  set_num_param(0);
  set_sort(Sort(bit_width));
}

ExprConst::ExprConst(const MemVal& mem_val, const int& addr_width,
                     const int& data_width)
    : mem_val_(mem_val) {
  set_arity(0);
  set_num_param(0);
  set_sort(Sort(addr_width, data_width));
}

ExprConst::~ExprConst() {}

z3::expr ExprConst::GetZ3Expr(z3::context& ctx,
                              const Z3ExprVec& z3expr_vec) const {
  if (IsBool()) {
    return ctx.bool_val(bool_val_.val());
  } else if (IsBv()) {
    return ctx.bv_val(bv_val_.val(), sort().bit_width());
  } else if (IsMem()) {
    ILA_ERROR << "Not implemented.\n"; // TODO
    return ctx.bv_val(0, sort().data_width());
  } else {
    ILA_ERROR << "Undefined sort for constantc\n";
    return ctx.bool_val(false);
  }
}

std::ostream& ExprConst::Print(std::ostream& out) const {
  if (IsBool()) {
    return out << bool_val_;
  } else if (IsBv()) {
    return out << bv_val_;
  } else if (IsMem()) {
    return out << mem_val_;
  } else {
    ILA_ERROR << "Undefined sort for constant.\n";
    return out;
  }
}

} // namespace ila

