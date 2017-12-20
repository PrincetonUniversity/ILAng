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

ExprConst::ExprConst(const BoolVal& bool_val)
    : bool_ptr_(NULL), bv_ptr_(NULL), mem_ptr_(NULL) {
  set_arity(0);
  set_num_param(0);
  set_sort(Sort());
  bool_ptr_ = std::make_shared<BoolVal>(bool_val);
}

ExprConst::ExprConst(const BvVal& bv_val, const int& bit_width)
    : bool_ptr_(NULL), bv_ptr_(NULL), mem_ptr_(NULL) {
  set_arity(0);
  set_num_param(0);
  set_sort(Sort(bit_width));
  bv_ptr_ = std::make_shared<BvVal>(bv_val);
}

ExprConst::ExprConst(const MemVal& mem_val, const int& addr_width,
                     const int& data_width)
    : bool_ptr_(NULL), bv_ptr_(NULL), mem_ptr_(NULL) {
  set_arity(0);
  set_num_param(0);
  set_sort(Sort(addr_width, data_width));
  mem_ptr_ = std::make_shared<MemVal>(mem_val);
}

ExprConst::~ExprConst() {}

z3::expr ExprConst::GetZ3Expr(z3::context& ctx, const Z3ExprVec& z3expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(z3expr_vec.empty()) << "Constant should be terminating nodes.\n";

  if (IsBool()) {
    return ctx.bool_val(bool_ptr_->val());
  } else if (IsBv()) {
    return ctx.bv_val(bv_ptr_->val(), sort().bit_width());
  } else if (IsMem()) {
    auto addr_sort = ctx.bv_sort(sort().addr_width());
    auto data_sort = ctx.bv_sort(sort().data_width());

    auto def_str = std::to_string(mem_ptr_->def_val());
    auto def_expr = ctx.bv_val(def_str.c_str(), sort().data_width());

    auto e1 = z3::const_array(addr_sort, def_expr);
    auto& val_map = mem_ptr_->val_map();
    for (auto p : val_map) {
      auto addr_str = std::to_string(p.first);
      auto addr_expr = ctx.bv_val(addr_str.c_str(), sort().addr_width());
      auto data_str = std::to_string(p.second);
      auto data_expr = ctx.bv_val(data_str.c_str(), sort().data_width());
      auto e2 = z3::store(e1, addr_expr, data_expr);
      e1 = e2;
    }
    return e1;
  } else {
    ILA_ERROR << "Undefined sort for constantc\n";
    return ctx.bool_val(false);
  }
}

std::ostream& ExprConst::Print(std::ostream& out) const {
  if (IsBool()) {
    return bool_ptr_->Print(out);
  } else if (IsBv()) {
    return bv_ptr_->Print(out);
  } else if (IsMem()) {
    return mem_ptr_->Print(out);
  } else {
    ILA_ERROR << "Undefined sort for constant.\n";
    return out;
  }
}

} // namespace ila

