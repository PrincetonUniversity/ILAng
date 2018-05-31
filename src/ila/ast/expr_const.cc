/// \file
/// Source for the class ExprConst

#include "ila/ast/expr_const.h"
#include "util/log.h"

/// \namespace ila
namespace ila {

ExprConst::ExprConst(const BoolVal& bool_val) {
  // set_sort(Sort());
  set_sort(Sort::MakeBoolSort());
  val_ = std::make_shared<BoolVal>(bool_val);
}

ExprConst::ExprConst(const BvVal& bv_val, const int& bit_width) {
  set_sort(Sort::MakeBvSort(bit_width));
  // set_sort(Sort(bit_width));
  val_ = std::make_shared<BvVal>(bv_val);
}

ExprConst::ExprConst(const MemVal& mem_val, const int& addr_width,
                     const int& data_width) {
  set_sort(Sort::MakeMemSort(addr_width, data_width));
  // set_sort(Sort(addr_width, data_width));
  val_ = std::make_shared<MemVal>(mem_val);
}

ExprConst::~ExprConst() {}

z3::expr ExprConst::GetZ3Expr(z3::context& ctx, const Z3ExprVec& z3expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(z3expr_vec.empty()) << "Constant should be terminating nodes.\n";

  if (is_bool()) {
    auto bool_ptr = val_bool();
    return ctx.bool_val(bool_ptr->val());
  } else if (is_bv()) {
    auto bv_ptr = val_bv();
    return ctx.bv_val(bv_ptr->val(), sort()->bit_width());
  } else {
    ILA_ASSERT(is_mem()) << "Neither bool, bv, nor mem.\n";
    auto addr_sort = ctx.bv_sort(sort()->addr_width());
    auto data_sort = ctx.bv_sort(sort()->data_width());

    auto mem_ptr = val_mem();
    auto def_str = std::to_string(mem_ptr->def_val());
    auto def_expr = ctx.bv_val(def_str.c_str(), sort()->data_width());

    auto e1 = z3::const_array(addr_sort, def_expr);
    auto& val_map = mem_ptr->val_map();
    for (auto p : val_map) {
      auto addr_str = std::to_string(p.first);
      auto addr_expr = ctx.bv_val(addr_str.c_str(), sort()->addr_width());
      auto data_str = std::to_string(p.second);
      auto data_expr = ctx.bv_val(data_str.c_str(), sort()->data_width());
      auto e2 = z3::store(e1, addr_expr, data_expr);
      e1 = e2;
    }
    return e1;
  }
}

std::ostream& ExprConst::Print(std::ostream& out) const {
  if (is_bool()) {
    auto bool_ptr = val_bool();
    return bool_ptr->Print(out);
  } else if (is_bv()) {
    auto bv_ptr = val_bv();
    return bv_ptr->Print(out);
  } else {
    ILA_ASSERT(is_mem()) << "Print neither bool, bv, nor mem.\n";
    auto mem_ptr = val_mem();
    return mem_ptr->Print(out);
  }
}

BoolValPtr ExprConst::val_bool() const {
  ILA_ASSERT(is_bool()) << "Not boolean constant\n";
  auto ptr = std::dynamic_pointer_cast<BoolVal>(val_);
  ILA_ASSERT(ptr) << "Fail casting to BoolVal\n";
  return ptr;
}

BvValPtr ExprConst::val_bv() const {
  ILA_ASSERT(is_bv()) << "Not bitvector constant\n";
  auto ptr = std::dynamic_pointer_cast<BvVal>(val_);
  ILA_ASSERT(ptr) << "Fail casting to BvVal\n";
  return ptr;
}

MemValPtr ExprConst::val_mem() const {
  ILA_ASSERT(is_mem()) << "Not memory constatnc\n";
  auto ptr = std::dynamic_pointer_cast<MemVal>(val_);
  ILA_ASSERT(ptr) << "Fail casting to MemVal\n";
  return ptr;
}

} // namespace ila

