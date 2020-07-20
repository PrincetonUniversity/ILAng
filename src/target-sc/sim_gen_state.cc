#include <fmt/format.h>

#include <ilang/target-sc/ila_sim.h>
#include <ilang/util/log.h>

#include "ast_fuse.h"

namespace ilang {

void IlaSim::create_mem_state(const ExprPtr& expr) {
  auto state_name_str = expr->host()->name().str() + "_" + expr->name().str();
  auto id = expr->name().id();
  bool state_not_defined =
      (defined_state_set_.find(id) == defined_state_set_.end());
  auto mem_addr_width = expr->sort()->addr_width();
  auto mem_data_width = expr->sort()->data_width();
  if (state_not_defined) {
    defined_state_set_.insert(id);
    if (mem_addr_width <= MEM_MAP_ARRAY_DIV) {
      defined_state_set_.insert(id);
      auto array_size = (1 << mem_addr_width);
      if (qemu_device_) {
        header_ << header_indent_;
        header_ << fmt::format("uint{}_t {}[{}];\n", mem_data_width,
                               state_name_str, array_size);
      } else {
        header_ << header_indent_;
        header_ << fmt::format("sc_biguint<{}> {}[{}];\n", mem_data_width,
                               state_name_str, array_size);
      }
    } else {
      if (qemu_device_) {
        header_ << header_indent_;
        header_ << fmt::format("std::map<uint{}_t, uint{}_t> {};\n",
                               mem_addr_width, mem_data_width, state_name_str);
      } else {
        header_ << header_indent_;
        header_ << fmt::format("std::map<sc_biguint<{}>, sc_biguint<{}>> {};\n",
                               mem_addr_width, mem_data_width, state_name_str);
      }
    }
  }
}

void IlaSim::create_bool_state(const ExprPtr& expr, bool child) {
  auto state_name_str = expr->host()->name().str() + "_" + expr->name().str();
  auto id = expr->name().id();
  bool state_not_defined =
      (defined_state_set_.find(id) == defined_state_set_.end());
  if (state_not_defined) {
    defined_state_set_.insert(id);
    if (qemu_device_)
      header_ << header_indent_ << "bool " << state_name_str << ";\n";
    else {
      if (!child) {
#if 0
        header_ << header_indent_ << "sc_out<bool> " << state_name_str
                << "_out;\n";
#endif
      }
      header_ << header_indent_ << "bool " << state_name_str << ";\n";
    }
  }
}

void IlaSim::create_bv_state(const ExprPtr& expr, bool child) {
  auto state_name_str = expr->host()->name().str() + "_" + expr->name().str();
  auto state_type_str =
      "sc_biguint<" + std::to_string(expr->sort()->bit_width()) + "> ";
  auto id = expr->name().id();
  auto state_not_defined =
      (defined_state_set_.find(id) == defined_state_set_.end());
  if (state_not_defined) {
    defined_state_set_.insert(id);
    if (qemu_device_) {
      header_ << header_indent_ << "uint" << expr->sort()->bit_width() << "_t "
              << state_name_str << ";\n";
    } else {
#if 0
      if (!child) {
        header_ << header_indent_ << "sc_out< " << state_type_str << "> "
                << state_name_str << "_out;\n";
      }
#endif
      header_ << header_indent_ << state_type_str << state_name_str << ";\n";
    }
  }
}

void IlaSim::create_external_mem_port(const ExprPtr& expr) {
  auto state_name_str = expr->host()->name().str() + "_" + expr->name().str();
  auto id = expr->name().id();
  auto pos = defined_state_set_.find(id);
  bool state_not_defined = (pos == defined_state_set_.end());
  if (state_not_defined) {
    defined_state_set_.insert(id);

    // FIXME sc_in only works in non-qemu mode
    header_ << fmt::format("{0}sc_in<sc_biguint<1>> {1}_read_valid;\n"
                           "{0}sc_in<sc_biguint<{2}>> {1}_read_data;\n"
                           "{0}sc_out<sc_biguint<1>> {1}_read_ready;\n"
                           "{0}sc_out<sc_biguint<{3}>> {1}_read_address;\n"
                           "{0}sc_in<sc_biguint<1>> {1}_write_ready;\n"
                           "{0}sc_out<sc_biguint<{3}>> {1}_write_address;\n"
                           "{0}sc_out<sc_biguint<1>> {1}_write_valid;\n"
                           "{0}sc_out<sc_biguint<{2}>> {1}_write_data;\n",
                           header_indent_,              // 0
                           state_name_str,              // 1
                           expr->sort()->data_width(),  // 2
                           expr->sort()->addr_width()); // 3
  }
}

void IlaSim::create_state(const ExprPtr& state_expr) {
  auto state_name_str =
      state_expr->host()->name().str() + "_" + state_expr->name().str();
  auto uid = GetUidExpr(state_expr);
  if (uid != AST_UID_EXPR::VAR) {
    ILA_WARN << "Warning: " << state_name_str << " is not a variable."
             << " It will not appear as an output port in simualtor.";
  }
  auto state_sort_uid = GetUidSort(state_expr->sort());
  if (state_sort_uid == AST_UID_SORT::MEM) {
    ILA_WARN << "Warning: " << state_name_str << " is a mem variable."
             << " It will not appear as an output port in simulator.";
    if (!EXTERNAL_MEM_) {
      create_mem_state(state_expr);
    } else {
      create_external_mem_port(state_expr);
    }
  }
  if (state_sort_uid == AST_UID_SORT::BOOL) {
    create_bool_state(state_expr);
  }
  if (state_sort_uid == AST_UID_SORT::BV) {
    create_bv_state(state_expr);
  }
}

void IlaSim::create_child_state(const ExprPtr& state_expr) {
  auto state_name_str =
      state_expr->host()->name().str() + "_" + state_expr->name().str();
  auto uid = GetUidExpr(state_expr);
  if (uid != AST_UID_EXPR::VAR) {
    ILA_WARN << "Warning: " << state_name_str << " is not a variable."
             << " It will not appear as an output port in simualtor.";
  }
  auto state_sort_uid = GetUidSort(state_expr->sort());

  if (state_sort_uid == AST_UID_SORT::MEM) {
    if (!EXTERNAL_MEM_) {
      create_mem_state(state_expr);
    } else {
      create_external_mem_port(state_expr);
    }
  }
  if (state_sort_uid == AST_UID_SORT::BOOL) {
    create_bool_state(state_expr, true);
  }
  if (state_sort_uid == AST_UID_SORT::BV) {
    create_bv_state(state_expr, true);
  }
}

}; // namespace ilang
