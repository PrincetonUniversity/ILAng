#include <ilang/target-sc/ila_sim.h>

#include <ilang/ila/ast_fuse.h>
#include <ilang/util/log.h>

namespace ilang {

void IlaSim::dfs_store_op(const ExprPtr& expr) {
  auto expr_uid = GetUidExpr(expr);
  if (expr_uid == AST_UID_EXPR::OP) {
    auto expr_op = GetUidExprOp(expr);
    if (expr_op == AST_UID_EXPR_OP::STORE) {
      ld_st_counter_ += 1;
      ILA_WARN << "Warning: store after load has not been implemented";
    }
  }
}

void IlaSim::dfs_load_from_store(const ExprPtr& expr) {
  auto expr_uid = GetUidExpr(expr);
  if (expr_uid == AST_UID_EXPR::OP) {
    auto expr_op = GetUidExprOp(expr);
    if (expr_op == AST_UID_EXPR_OP::LOAD) {
      dfs_store_op(expr->arg(0));
      dfs_store_op(expr->arg(1));
    }
  }
}

void IlaSim::dfs_int_var_width(const ExprPtr& expr) {
  auto expr_uid_sort = GetUidSort(expr->sort());
  if (expr_uid_sort == AST_UID_SORT::BV) {
    int_var_width_set_.insert(expr->sort()->bit_width());
  } else if (expr_uid_sort == AST_UID_SORT::MEM) {
    int_var_width_set_.insert(expr->sort()->addr_width());
    int_var_width_set_.insert(expr->sort()->data_width());
  }
}

void IlaSim::dfs_external_mem_load(const ExprPtr& expr) {
  auto expr_uid = GetUidExpr(expr);
  if (expr_uid == AST_UID_EXPR::OP) {
    auto expr_op = GetUidExprOp(expr);
    if (expr_op == AST_UID_EXPR_OP::LOAD) {
      auto expr_arg0_uid = GetUidExpr(expr->arg(0));
      if (expr_arg0_uid == AST_UID_EXPR::VAR)
        dfs_ld_search_set_.insert(expr->name().id());
    }
  }
}

void IlaSim::dfs_uninterpreted_func_decl(const FuncPtr& func) {
  auto func_name = func->name();
  auto func_out_sort = func->out();
  header_ << header_indent_;
  if (func_out_sort->is_bool()) {
    header_ << "bool " << func_name << "(";
  } else if (func_out_sort->is_bv()) {
    if (qemu_device_)
      header_ << "uint" << func_out_sort->bit_width() << "_t " << func_name
              << "(";
    else
      header_ << "sc_biguint<" << func_out_sort->bit_width() << "> "
              << func_name << "(";
  } else if (func_out_sort->is_mem()) {
    ILA_WARN << "Warning: 2d array might have trouble as function output";
    if (qemu_device_)
      header_ << "uint" << func_out_sort->bit_width() << "_t* " << func_name
              << "(";
    else
      header_ << "sc_biguint<" << func_out_sort->data_width() << ">* "
              << func_name << "(";
  }

  for (unsigned int i = 0; i < func->arg_num(); i++) {
    if (i != 0) {
      header_ << ", ";
    }
    auto arg_sort = func->arg(i);
    if (arg_sort->is_bool()) {
      header_ << "bool arg_" << i;
    } else if (arg_sort->is_bv()) {
      if (qemu_device_)
        header_ << "uint" << arg_sort->bit_width() << "_t arg_" << i;
      else
        header_ << "sc_biguint<" << arg_sort->bit_width() << "> "
                << "arg_" << i;
    } else {
      // TODO(yuex): add func_decl with memory arg.
      if (qemu_device_)
        header_ << "uint" << arg_sort->data_width() << "_t arg_" << i;
      else
        header_ << "sc_biguint<" << arg_sort->data_width() << "> "
                << "arg_" << i;
    }
  }
  header_ << ");" << std::endl;
}

void IlaSim::dfs_const_node(std::stringstream& dfs_simulator,
                            std::string& indent, const ExprPtr& expr) {
  auto id = expr->name().id();
  auto sort = expr->sort();
  if (GetUidSort(sort) == AST_UID_SORT::MEM) {
    bool const_mem_not_defined =
        (const_mem_set_.find(id) == const_mem_set_.end());
    if (const_mem_not_defined) {
      const_mem_set_.insert(id);
      auto addr_width = sort->addr_width();
      unsigned int array_size = 1;
      array_size <<= addr_width;
      auto expr_const = std::dynamic_pointer_cast<ExprConst>(expr);
      auto val_map = expr_const->val_mem()->val_map();
      std::string const_mem_array =
          "c_" + std::to_string(id) + "[" + std::to_string(array_size) + "]";
      if (qemu_device_) {
        header_ << indent << "const "
                << "uint" << sort->data_width() << "_t " << const_mem_array
                << " = {";
      } else {
        header_ << indent << "const "
                << "sc_biguint<" << sort->data_width() << "> "
                << const_mem_array << " = {";
      }
      for (int i = 0; i < array_size - 1; i++)
        header_ << val_map[i] << ", ";
      header_ << val_map[array_size - 1] << "};" << std::endl;
    }
  }
}

void IlaSim::dfs_unary_op_check(const ExprPtr& expr) {
  ILA_CHECK(!expr->is_mem())
      << "Memory sort is not supported as an unary operation's output.";
}

void IlaSim::dfs_unary_op(std::stringstream& dfs_simulator, std::string& indent,
                          const ExprPtr& expr) {
  dfs_unary_op_check(expr);
  auto id = expr->name().id();
  std::string arg_str = get_arg_str(expr->arg(0));
  std::string out_str = "c_" + std::to_string(expr->name().id());
  std::string op_str =
      (GetUidExprOp(expr) == AST_UID_EXPR_OP::NEG)
          ? "-"
          : (GetUidExprOp(expr) == AST_UID_EXPR_OP::NOT)
                ? "!"
                : (GetUidExprOp(expr) == AST_UID_EXPR_OP::COMPL) ? "~" : "";
  // TODO(yuex): be careful with the diff between NEG and COMPL
  std::string out_type_str =
      (expr->is_bool())
          ? "bool "
          : (expr->is_bv())
                ? "sc_biguint<" + std::to_string(expr->sort()->bit_width()) +
                      "> "
                : "";
  if (qemu_device_)
    out_type_str =
        (expr->is_bool())
            ? "bool "
            : (expr->is_bv())
                  ? "uint" + std::to_string(expr->sort()->bit_width()) + "_t "
                  : "";

  declare_variable_with_id(id, out_type_str, out_str);
  dfs_simulator << indent << out_str << " = " << op_str << arg_str << ";"
                << std::endl;
}

void IlaSim::dfs_binary_op_bool_out_check(const ExprPtr& expr) {
  ILA_CHECK(expr->is_bool())
      << "Output sort for EQ/LT/GT/ULT/UGT/IMPLY operation is not bool.";
}

void IlaSim::dfs_binary_op_bool_out(std::stringstream& dfs_simulator,
                                    std::string& indent, const ExprPtr& expr) {
  dfs_binary_op_bool_out_check(expr);
  auto id = expr->name().id();
  std::string arg0_str = get_arg_str(expr->arg(0));
  std::string arg1_str = get_arg_str(expr->arg(1));
  std::string out_str = "c_" + std::to_string(expr->name().id());
  std::string op_str =
      (GetUidExprOp(expr) == AST_UID_EXPR_OP::EQ)
          ? " == "
          : (GetUidExprOp(expr) == AST_UID_EXPR_OP::LT)
                ? " < "
                : (GetUidExprOp(expr) == AST_UID_EXPR_OP::GT)
                      ? " > "
                      : (GetUidExprOp(expr) == AST_UID_EXPR_OP::ULT)
                            ? " < "
                            : (GetUidExprOp(expr) == AST_UID_EXPR_OP::UGT)
                                  ? " > "
                                  : "";

  declare_variable_with_id(id, "bool ", out_str);

  if (GetUidExprOp(expr) == AST_UID_EXPR_OP::IMPLY) {
    dfs_simulator << indent << out_str << " = (!" << arg0_str << ") & "
                  << arg1_str << ";" << std::endl;
  } else {
    dfs_simulator << indent << out_str << " = " << arg0_str << op_str
                  << arg1_str << ";" << std::endl;
  }
}

void IlaSim::dfs_binary_op_non_mem_check(const ExprPtr& expr) {
  ILA_CHECK(!expr->is_mem()) << "AND/OR/XOR/SHL/LSHR/ASHR/ADD/MUL/CONCAT's "
                                "output shouldn't have memory sort.";
}

void IlaSim::dfs_binary_op_non_mem(std::stringstream& dfs_simulator,
                                   std::string& indent, const ExprPtr& expr) {
  dfs_binary_op_non_mem_check(expr);
  auto id = expr->name().id();
  std::string arg0_str = get_arg_str(expr->arg(0));
  std::string arg1_str = get_arg_str(expr->arg(1));
  std::string out_str = "c_" + std::to_string(expr->name().id());
  std::string out_type_str =
      (expr->is_bool())
          ? "bool "
          : (expr->is_bv())
                ? "sc_biguint<" + std::to_string(expr->sort()->bit_width()) +
                      "> "
                : "";
  if (qemu_device_)
    out_type_str =
        (expr->is_bool())
            ? "bool "
            : (expr->is_bv())
                  ? "uint" + std::to_string(expr->sort()->bit_width()) + "_t "
                  : "";
  std::string op_str =
      (GetUidExprOp(expr) == AST_UID_EXPR_OP::AND)
          ? " & "
          : (GetUidExprOp(expr) == AST_UID_EXPR_OP::OR)
                ? " | "
                : (GetUidExprOp(expr) == AST_UID_EXPR_OP::XOR)
                      ? " ^ "
                      : (GetUidExprOp(expr) == AST_UID_EXPR_OP::SHL)
                            ? " << "
                            : (GetUidExprOp(expr) == AST_UID_EXPR_OP::LSHR)
                                  ? " >> "
                                  : (GetUidExprOp(expr) ==
                                     AST_UID_EXPR_OP::ASHR)
                                        ? " >> "
                                        : (GetUidExprOp(expr) ==
                                           AST_UID_EXPR_OP::ADD)
                                              ? " + "
                                              : (GetUidExprOp(expr) ==
                                                 AST_UID_EXPR_OP::SUB)
                                                    ? " - "
                                                    /*TODO(yuex) check in the
                                                    MUL_op
                                                    : (GetUidExprOp(expr) ==
                                                       AST_UID_EXPR_OP::MUL)
                                                          ? " * "*/
                                                    : (GetUidExprOp(expr) ==
                                                       AST_UID_EXPR_OP::CONCAT)
                                                          ? ", "
                                                          : "";
  declare_variable_with_id(id, out_type_str, out_str);
  if (qemu_device_) {
    if (GetUidExprOp(expr) == AST_UID_EXPR_OP::CONCAT) {
      auto arg0_width = expr->arg(0)->sort()->bit_width();
      auto arg1_width = expr->arg(1)->sort()->bit_width();
      auto out_width = arg0_width + arg1_width;
      dfs_simulator << indent << out_str << " = (static_cast<uint" << out_width
                    << "_t>(" << arg0_str << ") << " << arg1_width
                    << ") + (static_cast<uint" << out_width << "_t>("
                    << arg1_str << "));" << std::endl;
    } else {
      dfs_simulator << indent << out_str << " = (" << arg0_str << op_str
                    << arg1_str << ");" << std::endl;
    }
  } else {
    dfs_simulator << indent << out_str << " = (" << arg0_str << op_str
                  << arg1_str << ");" << std::endl;
  }
}

void IlaSim::dfs_binary_op_mem(std::stringstream& dfs_simulator,
                               std::string& indent, const ExprPtr& expr) {
  auto id = expr->name().id();
  std::string arg0_str = get_arg_str(expr->arg(0));
  std::string arg1_str = get_arg_str(expr->arg(1));
  if (qemu_device_)
    arg1_str =
        (arg1_str == "true") ? "1" : (arg1_str == "false") ? "0" : arg1_str;
  else
    arg1_str = (arg1_str == "true") ? "1" : (arg1_str == "false")
                                                ? "0"
                                                : arg1_str + ".to_int()";

  std::string out_str = "c_" + std::to_string(expr->name().id());
  std::string out_type_str =
      (expr->is_bool())
          ? "bool "
          : (expr->is_bv())
                ? "sc_biguint<" + std::to_string(expr->sort()->bit_width()) +
                      "> "
                : "";
  if (qemu_device_)
    out_type_str =
        (expr->is_bool())
            ? "bool "
            : (expr->is_bv())
                  ? "uint" + std::to_string(expr->sort()->bit_width()) + "_t "
                  : "";

  bool is_load = GetUidExprOp(expr) == AST_UID_EXPR_OP::LOAD;
  auto arg0_uid = GetUidExpr(expr->arg(0));
  if (is_load) {
    if (declared_id_set_.find(id) == declared_id_set_.end()) {
      declared_id_set_.insert(id);
      header_ << header_indent_ << out_type_str << out_str << ";" << std::endl;
      if ((EXTERNAL_MEM_) && (arg0_uid == AST_UID_EXPR::VAR)) {
        header_ << header_indent_ << "int " << out_str << "_ctrl;" << std::endl;
        ld_info current_load;
        current_load.mem_str = arg0_str;
        current_load.addr_str = arg1_str;
        current_load.dest_str = out_str;
        external_ld_set_.push_back(current_load);
      }
    }
  }
  if (is_load) {
    if ((EXTERNAL_MEM_) && (arg0_uid == AST_UID_EXPR::VAR)) {
      dfs_simulator << indent << "if (" << out_str << "_ctrl == 0"
                    << ") {" << std::endl;
      dfs_simulator << indent << "  " << out_str << "_ctrl = 1;" << std::endl;
      dfs_simulator << indent << "  "
                    << "return 0;" << std::endl;
      dfs_simulator << indent << "} else if (" << out_str << "_ctrl == 1) {"
                    << std::endl;
      dfs_simulator << indent << "  return 0;" << std::endl;
      dfs_simulator << indent << "} else if (" << out_str << "_ctrl != 2) {"
                    << std::endl;
      dfs_simulator << indent << "  cout << \"Error: Load wrong\" << endl;"
                    << std::endl;
      dfs_simulator << indent << "}" << std::endl;
    } else
      dfs_simulator << indent << out_str << " = " << arg0_str << "[" << arg1_str
                    << "];" << std::endl;
  } else {
    std::string arg2_str = get_arg_str(expr->arg(2));
    if (qemu_device_)
      arg2_str =
          (arg2_str == "true") ? "1" : (arg2_str == "false") ? "0" : arg2_str;
    else
      arg2_str = (arg2_str == "true") ? "1" : (arg2_str == "false")
                                                  ? "0"
                                                  : arg2_str + ".to_int()";
    dfs_simulator << indent << "mem_update_map[" << arg1_str
                  << "] = " << arg2_str << ";" << std::endl;
  }
}

void IlaSim::dfs_extract_op(std::stringstream& dfs_simulator,
                            std::string& indent, const ExprPtr& expr) {
  auto id = expr->name().id();
  std::string arg_str = get_arg_str(expr->arg(0));
  auto param0 = static_cast<unsigned>(expr->param(0));
  auto param1 = static_cast<unsigned>(expr->param(1));
  auto out_str = "c_" + std::to_string(expr->name().id());
  std::string out_type_str =
      (expr->is_bool())
          ? "bool "
          : (expr->is_bv())
                ? "sc_biguint<" + std::to_string(expr->sort()->bit_width()) +
                      "> "
                : "";
  if (qemu_device_)
    out_type_str =
        (expr->is_bool())
            ? "bool "
            : (expr->is_bv())
                  ? "uint" + std::to_string(expr->sort()->bit_width()) + "_t "
                  : "";
  declare_variable_with_id(id, out_type_str, out_str);
  if (qemu_device_) {
    std::string tmp_str = "tmp_" + std::to_string(expr->name().id());
    int cast_length = param0 - param1 + 1;
    dfs_simulator << indent << "uint" << cast_length << "_t " << tmp_str
                  << " = "
                  << "0 - 1;" << std::endl;
    dfs_simulator << indent << out_str << " = static_cast<uint" << (cast_length)
                  << "_t> ((" << arg_str << " >> " << param1 << ") & "
                  << tmp_str << ");" << std::endl;
  } else {
    dfs_simulator << indent << out_str << " = " << arg_str << ".range("
                  << param0 << ", " << param1 << ");" << std::endl;
  }
}

void IlaSim::dfs_ext_op(std::stringstream& dfs_simulator, std::string& indent,
                        const ExprPtr& expr) {
  auto id = expr->name().id();
  auto arg = expr->arg(0);
  std::string arg_str = get_arg_str(arg);
  auto out_str = "c_" + std::to_string(expr->name().id());
  std::string out_type_str =
      (expr->is_bool())
          ? "bool "
          : (expr->is_bv())
                ? "sc_biguint<" + std::to_string(expr->sort()->bit_width()) +
                      "> "
                : "";
  if (qemu_device_)
    out_type_str =
        (expr->is_bool())
            ? "bool "
            : (expr->is_bv())
                  ? "uint" + std::to_string(expr->sort()->bit_width()) + "_t "
                  : "";

  declare_variable_with_id(id, out_type_str, out_str);

  if (GetUidExprOp(expr) == AST_UID_EXPR_OP::ZEXT) {
    dfs_simulator << indent << out_str << " = "
                  << "0;" << std::endl;
    if (qemu_device_) {
      dfs_simulator << indent << out_str << " = "
                    << "static_cast<uint" << expr->sort()->bit_width() << "_t>("
                    << arg_str << ");" << std::endl;
    } else {
      dfs_simulator << indent << out_str << " = " << arg_str << ";"
                    << std::endl;
    }
  } else {
    if (qemu_device_) {
      dfs_simulator << indent << out_str << " = "
                    << "static_cast<uint" << expr->sort()->bit_width() << "_t>("
                    << arg_str << ");" << std::endl;
      dfs_simulator << indent << out_str << " = (" << arg_str << " >> "
                    << (arg->sort()->bit_width() - 1) << ") ? static_cast<uint"
                    << expr->sort()->bit_width() << "_t>(~" << arg_str << ") : "
                    << "static_cast<uint" << expr->sort()->bit_width() << "_t>("
                    << arg_str << ");" << std::endl;
      dfs_simulator << indent << out_str << " = (" << arg_str << " >> "
                    << (arg->sort()->bit_width() - 1) << ") ? (~" << out_str
                    << ") : " << out_str << ";" << std::endl;
    } else {
      dfs_simulator << indent << out_str << " = (" << arg_str << "["
                    << (arg->sort()->bit_width() - 1) << "] == 1) ? (~"
                    << arg_str << ") : " << arg_str << ";" << std::endl;
      dfs_simulator << indent << out_str << " = (" << arg_str << "["
                    << (arg->sort()->bit_width() - 1) << "] == 1) ? (~"
                    << out_str << ") : " << out_str << ";" << std::endl;
    }
  }
}

void IlaSim::dfs_func_op_check(const ExprPtr& expr) {
  ILA_CHECK(!expr->is_mem())
      << "Memory is not supported as APPFUNC's output sort";
}

void IlaSim::dfs_func_op(std::stringstream& dfs_simulator, std::string& indent,
                         const ExprPtr& expr) {
  dfs_func_op_check(expr);
  auto id = expr->name().id();
  auto appfunc_expr = std::dynamic_pointer_cast<ExprOpAppFunc>(expr);
  auto func = appfunc_expr->func();
  auto func_name = func->name().str();
  if (func_set_.find(func_name) == func_set_.end()) {
    func_set_.insert(func_name);
    dfs_uninterpreted_func_decl(func);
  }
  auto out_str = "c_" + std::to_string(expr->name().id());
  std::string out_type_str =
      (expr->is_bool())
          ? "bool "
          : (expr->is_bv())
                ? "sc_biguint<" + std::to_string(expr->sort()->bit_width()) +
                      "> "
                : "";
  if (qemu_device_)
    out_type_str =
        (expr->is_bool())
            ? "bool "
            : (expr->is_bv())
                  ? "uint" + std::to_string(expr->sort()->bit_width()) + "_t "
                  : "";
  declare_variable_with_id(id, out_type_str, out_str);
  dfs_simulator << indent << out_str << " = " << func_name << "(";
  for (unsigned int i = 0; i < appfunc_expr->arg_num(); i++) {
    if (i != 0)
      dfs_simulator << ", ";
    dfs_simulator << get_arg_str(appfunc_expr->arg(i));
  }
  dfs_simulator << ");" << std::endl;
}

void IlaSim::dfs_ite_op(std::stringstream& dfs_simulator, std::string& indent,
                        const ExprPtr& expr) {
  auto id = expr->name().id();
  auto cond_str = get_arg_str(expr->arg(0));
  auto true_str = get_arg_str(expr->arg(1));
  auto false_str = get_arg_str(expr->arg(2));
  auto out_str = "c_" + std::to_string(expr->name().id());
  std::string out_type_str =
      (expr->is_bool())
          ? "bool "
          : (expr->is_bv())
                ? "sc_biguint<" + std::to_string(expr->sort()->bit_width()) +
                      "> "
                : "";
  if (qemu_device_)
    out_type_str =
        (expr->is_bool())
            ? "bool "
            : (expr->is_bv())
                  ? "uint" + std::to_string(expr->sort()->bit_width()) + "_t "
                  : "";

  if (!expr->is_mem()) {
    declare_variable_with_id(id, out_type_str, out_str);
    dfs_simulator << indent << out_str << " = (" << cond_str << ") ? "
                  << true_str << " : " << false_str << ";" << std::endl;
  } else {
    if (store_ite_set_.find(id) == store_ite_set_.end()) {
      store_ite_set_.insert(id);
      searched_id_set_.insert(id);
      dfs_simulator << indent << "ite_" << id << "(mem_update_map);"
                    << std::endl;
    }
  }
}

void IlaSim::dfs_kernel(std::stringstream& dfs_simulator, std::string& indent,
                        const ExprPtr& expr) {
  auto expr_uid = GetUidExpr(expr);
  if (expr_uid == AST_UID_EXPR::VAR) {
    return;
  } else if (expr_uid == AST_UID_EXPR::CONST) {
    dfs_const_node(dfs_simulator, indent, expr);
    return;
  } else { // (expr_uid == AST_UID_EXPR::OP)
    auto id = expr->name().id();
    bool op_has_been_defined =
        (searched_id_set_.find(id) != searched_id_set_.end());
    if (op_has_been_defined)
      return;
    else
      searched_id_set_.insert(id);
    auto expr_op_uid = GetUidExprOp(expr);
    bool unary_op = ((expr_op_uid == AST_UID_EXPR_OP::NEG) ||
                     (expr_op_uid == AST_UID_EXPR_OP::NOT) ||
                     (expr_op_uid == AST_UID_EXPR_OP::COMPL));
    bool binary_op_bool_out = ((expr_op_uid == AST_UID_EXPR_OP::EQ) ||
                               (expr_op_uid == AST_UID_EXPR_OP::LT) ||
                               (expr_op_uid == AST_UID_EXPR_OP::GT) ||
                               (expr_op_uid == AST_UID_EXPR_OP::ULT) ||
                               (expr_op_uid == AST_UID_EXPR_OP::UGT) ||
                               (expr_op_uid == AST_UID_EXPR_OP::IMPLY));
    bool binary_op_non_mem = ((expr_op_uid == AST_UID_EXPR_OP::SUB) ||
                              (expr_op_uid == AST_UID_EXPR_OP::AND) ||
                              (expr_op_uid == AST_UID_EXPR_OP::OR) ||
                              (expr_op_uid == AST_UID_EXPR_OP::XOR) ||
                              (expr_op_uid == AST_UID_EXPR_OP::SHL) ||
                              (expr_op_uid == AST_UID_EXPR_OP::ASHR) ||
                              (expr_op_uid == AST_UID_EXPR_OP::LSHR) ||
                              (expr_op_uid == AST_UID_EXPR_OP::ADD) ||
                              /*TODO(yuex): check in MUL op.
                              (expr_op_uid == AST_UID_EXPR_OP::MUL) ||*/
                              (expr_op_uid == AST_UID_EXPR_OP::CONCAT));
    bool binary_op_mem = ((expr_op_uid == AST_UID_EXPR_OP::LOAD) ||
                          (expr_op_uid == AST_UID_EXPR_OP::STORE));
    bool extract_op = (expr_op_uid == AST_UID_EXPR_OP::EXTRACT);
    bool ext_op = (expr_op_uid == AST_UID_EXPR_OP::ZEXT) ||
                  (expr_op_uid == AST_UID_EXPR_OP::SEXT);
    bool func_op = expr_op_uid == AST_UID_EXPR_OP::APP_FUNC;
    bool ite_op = expr_op_uid == AST_UID_EXPR_OP::ITE;

    if (unary_op) {
      dfs_unary_op(dfs_simulator, indent, expr);
      return;
    } else if (binary_op_bool_out) {
      dfs_binary_op_bool_out(dfs_simulator, indent, expr);
      return;
    } else if (binary_op_non_mem) {
      dfs_binary_op_non_mem(dfs_simulator, indent, expr);
      return;
    } else if (binary_op_mem) {
      dfs_binary_op_mem(dfs_simulator, indent, expr);
      return;
    } else if (extract_op) {
      dfs_extract_op(dfs_simulator, indent, expr);
      return;
    } else if (ext_op) {
      dfs_ext_op(dfs_simulator, indent, expr);
      return;
    } else if (func_op) {
      dfs_func_op(dfs_simulator, indent, expr);
      return;
    } else if (ite_op) {
      dfs_ite_op(dfs_simulator, indent, expr);
      return;
    } else {
      ILA_ERROR << "Error: OP_ID = " << expr_op_uid
                << " is not supported by ILA";
      ILA_CHECK(false) << "Unsupported operation sort.";
    }
  }
}

}; // namespace ilang
