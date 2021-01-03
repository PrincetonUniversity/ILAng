#include <ilang/target-sc/ila_sim.h>
#include <ilang/util/log.h>

#include "ast_fuse.h"

namespace ilang {

void IlaSim::create_input(const ExprPtr& input_expr) {
  auto input_uid = GetUidExpr(input_expr);

  ILA_CHECK(input_uid == AST_UID_EXPR::VAR) << "ILA input sort must be var.";
  auto input_sort = input_expr->sort();
  auto input_sort_uid = GetUidSort(input_sort);

  ILA_CHECK(input_sort_uid != AST_UID_SORT::MEM)
      << "ILA input sort can't be mem.";
  if (input_sort_uid == AST_UID_SORT::BOOL) {
    create_bool_input(input_expr);
  }
  if (input_sort_uid == AST_UID_SORT::BV) {
    create_bv_input(input_expr);
  }
  return;
}

void IlaSim::create_bool_input(const ExprPtr& expr) {
  if (qemu_device_) {
    auto input_name_str = expr->host()->name().str() + "_" + expr->name().str();
    header_ << header_indent_ << "bool " << input_name_str << ";\n";
  } else {
    auto input_name_str = expr->host()->name().str() + "_" + expr->name().str();
    header_ << header_indent_ << "sc_in<bool> " << input_name_str << "_in;\n";
    header_ << header_indent_ << "bool " << input_name_str << ";\n";
  }
}

void IlaSim::create_bv_input(const ExprPtr& expr) {
  if (qemu_device_) {
    auto bit_width = expr->sort()->bit_width();
    auto input_name_str = expr->host()->name().str() + "_" + expr->name().str();
    auto input_type_str = "uint" + std::to_string(bit_width) + "_t ";
    header_ << header_indent_ << input_type_str << input_name_str << ";\n";
  } else {
    auto bit_width = expr->sort()->bit_width();
    auto input_name_str = expr->host()->name().str() + "_" + expr->name().str();
    auto input_type_str = "sc_biguint<" + std::to_string(bit_width) + "> ";
    header_ << header_indent_ << "sc_in< " << input_type_str << "> "
            << input_name_str << "_in;\n";
    header_ << header_indent_ << input_type_str << input_name_str << ";\n";
  }
}

}; // namespace ilang
