/// \file
/// Source for the class ExprConst

#include <ilang/ila/ast/expr_const.h>

#include <ilang/util/log.h>
#include <ilang/util/z3_helper.h>

/// \namespace ilang
namespace ilang {

ExprConst::ExprConst(const BoolVal& bool_val) {
  set_sort(Sort::MakeBoolSort());
  val_ = std::make_shared<BoolVal>(bool_val);
}

ExprConst::ExprConst(const BvVal& bv_val, const int& bit_width) {
  // bit-width must be positive
  ILA_CHECK(bit_width > 0) << "Non-positive bit-width " << bit_width;

  // check bv_val < 2 ^ bit_width
  ILA_CHECK((size_t)bit_width >= BvValTypeBitWidth ||
            (bv_val.val() >> bit_width) == 0)
      << bv_val << " width > " << bit_width;

  // MAX is UINT64_MAX - cannot tell if it exceed since it's unsigned
  ILA_WARN_IF((size_t)bit_width > BvValTypeBitWidth)
      << "Define a " << bit_width << "-bit constant " << bv_val;

  set_sort(Sort::MakeBvSort(bit_width));
  val_ = std::make_shared<BvVal>(bv_val);
}

ExprConst::ExprConst(const MemVal& mem_val, const int& addr_width,
                     const int& data_width) {
  set_sort(Sort::MakeMemSort(addr_width, data_width));
  val_ = std::make_shared<MemVal>(mem_val);
}

ExprConst::~ExprConst() {}

z3::expr ExprConst::GetZ3Expr(z3::context& ctx, const Z3ExprVec& z3expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(z3expr_vec.empty()) << "Constant should be terminating nodes.";

  if (is_bool()) {
    auto bool_ptr = val_bool();
    return ctx.bool_val(bool_ptr->val());
  } else if (is_bv()) {
    auto bv_ptr = val_bv();
    return ctx.bv_val(Z3BvVal(bv_ptr->val()), sort()->bit_width());
  } else {
    ILA_ASSERT(is_mem()) << "Neither bool, bv, nor mem.";
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
    ILA_ASSERT(is_mem()) << "Print neither bool, bv, nor mem.";
    auto mem_ptr = val_mem();
    return mem_ptr->Print(out);
  }
}

BoolValPtr ExprConst::val_bool() const {
  ILA_ASSERT(is_bool()) << "Not boolean constant";
  return std::static_pointer_cast<BoolVal>(val_);
}

BvValPtr ExprConst::val_bv() const {
  ILA_ASSERT(is_bv()) << "Not bitvector constant";
  return std::static_pointer_cast<BvVal>(val_);
}

MemValPtr ExprConst::val_mem() const {
  ILA_ASSERT(is_mem()) << "Not memory constatnc";
  return std::static_pointer_cast<MemVal>(val_);
}

} // namespace ilang
