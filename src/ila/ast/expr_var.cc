/// \file
/// Source for the var expression

#include "ila/ast/expr_var.h"
#include "util/log.h"

namespace ila {

const std::string ExprVar::k_prefix_var_ = "var";

ExprVar::ExprVar() { ILA_ERROR << "Undefined ExprVar constructor.\n"; }

ExprVar::ExprVar(const std::string& name) {
  set_name(name);
  set_arity(0);
  // set bool sort
  set_sort(Sort());
}

ExprVar::ExprVar(const std::string& name, const int& bit_width) {
  set_name(name);
  set_arity(0);
  // set bv sort
  set_sort(Sort(bit_width));
}

ExprVar::ExprVar(const std::string& name, const int& addr_width,
                 const int& data_width) {
  set_name(name);
  set_arity(0);
  // set mem sort
  set_sort(Sort(addr_width, data_width));
}

ExprVar::~ExprVar() {}

z3::expr ExprVar::GetZ3Expr(z3::context& ctx, const Z3ExprVec& z3expr_vec,
                            const std::string& suffix) const {
  if (is_bool()) {
    return ctx.bool_const(name().format_c_str("", suffix));
  } else if (is_bv()) {
    return ctx.bv_const(name().format_c_str("", suffix), sort().bit_width());
  } else if (is_mem()) {
    auto addr_sort = ctx.bv_sort(sort().addr_width());
    auto data_sort = ctx.bv_sort(sort().data_width());
    auto mem_sort = ctx.array_sort(addr_sort, data_sort);
    return ctx.constant(name().format_c_str("", suffix), mem_sort);
  } else {
    ILA_ERROR << "Undefined sort for var " << name() << "\n";
    return ctx.bool_const(name().format_c_str("", suffix));
  }
}

std::ostream& ExprVar::Print(std::ostream& out) const {
  if (is_bool()) {
    return PrintBool(out);
  } else if (is_bv()) {
    return PrintBv(out);
  } else if (is_mem()) {
    return PrintMem(out);
  } else {
    ILA_ERROR << "Unknown sort for var " << name() << "\n";
    return out;
  }
}

std::ostream& ExprVar::PrintBool(std::ostream& out) const {
  return out << name().format_str("BoolVar", "");
}

std::ostream& ExprVar::PrintBv(std::ostream& out) const {
  return out << name().format_str("BitvectorVar", "");
}

std::ostream& ExprVar::PrintMem(std::ostream& out) const {
  return out << name().format_str("MemoryVar", "");
}

} // namespace ila

