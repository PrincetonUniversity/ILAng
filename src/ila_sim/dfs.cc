#include "ila_sim.h"

namespace ilang {

void IlaSim::dfs_store_op(const ExprPtr &expr) {
  auto expr_uid = GetUidExpr(expr);
  if (expr_uid == AST_UID_EXPR::OP) {
    auto expr_op = GetUidExprOp(expr);
    if (expr_op == AST_UID_EXPR_OP::STORE) {
      ld_st_counter_ += 1;
      cout << "Warning: store after load has not been implemented" << endl;
    }
  }
}

void IlaSim::dfs_load_from_store(const ExprPtr &expr) {
  auto expr_uid = GetUidExpr(expr);
  if (expr_uid == AST_UID_EXPR::OP) {
    auto expr_op = GetUidExprOp(expr);
    if (expr_op == AST_UID_EXPR_OP::LOAD) {
      dfs_store_op(expr->arg(0));
      dfs_store_op(expr->arg(1));
    }
  }
}

void IlaSim::dfs_external_mem_load(const ExprPtr &expr) {
  auto expr_uid = GetUidExpr(expr);
  if (expr_uid == AST_UID_EXPR::OP) {
    auto expr_op = GetUidExprOp(expr);
    if (expr_op == AST_UID_EXPR_OP::LOAD) {
      dfs_ld_search_set_.insert(expr->name().id());
    }
  }
}

void IlaSim::dfs_uninterpreted_func_decl(const FuncPtr &func) {
  auto func_name = func->name();
  auto func_out_sort = func->out();
  header_ << header_indent_;
  if (func_out_sort->is_bool()) {
    header_ << "bool " << func_name << "(";
  } else if (func_out_sort->is_bv()) {
    header_ << "sc_biguint<" << func_out_sort->bit_width() << "> " << func_name
            << "(";
  } else if (func_out_sort->is_mem()) {
    cout << "Warning: 2d array might have trouble as function output" << endl;
    header_ << "sc_biguint<" << func_out_sort->data_width() << "> " << func_name
            << "(";
  }

  for (int i = 0; i < func->arg_num(); i++) {
    if (i != 0) {
      header_ << ", ";
    }
    auto arg_sort = func->arg(i);
    if (arg_sort->is_bool()) {
      header_ << "bool arg_" << i;
    } else if (arg_sort->is_bv()) {
      header_ << "sc_biguint<" << arg_sort->bit_width() << "> "
              << "arg_" << i;
    } else {
      auto addr_size = 1;
      addr_size <<= arg_sort->addr_width();
      header_ << "sc_biguint<" << arg_sort->data_width() << "> "
              << "arg_" << i;
    }
  }
  header_ << ");" << endl;
}

void IlaSim::dfs_const_node(stringstream &dfs_simulator, string &indent,
                            const ExprPtr &expr) {
  auto id = expr->name().id();
  auto sort = expr->sort();
  if (GetUidSort(sort) == AST_UID_SORT::MEM) {
    bool const_mem_not_defined =
        (const_mem_set_.find(id) == const_mem_set_.end());
    if (const_mem_not_defined) {
      const_mem_set_.insert(id);
      auto addr_width = sort->addr_width();
      int array_size = 1;
      array_size <<= addr_width;
      auto expr_const = dynamic_pointer_cast<ExprConst>(expr);
      auto val_map = expr_const->val_mem()->val_map();
      string const_mem_array =
          "c_" + to_string(id) + "[" + to_string(array_size) + "]";
      header_ << indent << "const " << const_mem_array << " = {";
      for (int i = 0; i < array_size - 1; i++)
        header_ << val_map[i] << ", ";
      header_ << val_map[array_size - 1] << "};" << endl;
    }
  }
}

void IlaSim::dfs_unary_op_check(const ExprPtr &expr) {
  if (expr->is_mem())
    cout << "Error: unary_op shouldn't output memory";
}

void IlaSim::dfs_unary_op(stringstream &dfs_simulator, string &indent,
                          const ExprPtr &expr) {
  dfs_unary_op_check(expr);
  auto id = expr->name().id();
  string arg_str = get_arg_str(expr->arg(0));
  string out_str = "c_" + to_string(expr->name().id());
  string op_str =
      (GetUidExprOp(expr) == AST_UID_EXPR_OP::NEG)
          ? "-"
          : (GetUidExprOp(expr) == AST_UID_EXPR_OP::NOT)
                ? "!"
                : (GetUidExprOp(expr) == AST_UID_EXPR_OP::COMPL) ? "~" : "";
  // TODO(yuex): be careful with the diff between NEG and COMPL
  string out_type_str =
      (expr->is_bool())
          ? "bool "
          : (expr->is_bv())
                ? "sc_biguint<" + to_string(expr->sort()->bit_width()) + "> "
                : "";

  declare_variable_with_id(id, out_type_str, out_str);
  dfs_simulator << indent << out_str << " = " << op_str << arg_str << ";"
                << endl;
}

void IlaSim::dfs_binary_op_bool_out_check(const ExprPtr &expr) {
  if (!expr->is_bool())
    cout << "Error: EQ/LT/GT/ULT/UGT/IMPLY must use bool as output type."
         << endl;
}

void IlaSim::dfs_binary_op_bool_out(stringstream &dfs_simulator, string &indent,
                                    const ExprPtr &expr) {
  dfs_binary_op_bool_out_check(expr);
  auto id = expr->name().id();
  string arg0_str = get_arg_str(expr->arg(0));
  string arg1_str = get_arg_str(expr->arg(1));
  string out_str = "c_" + to_string(expr->name().id());
  string op_str =
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
                  << arg1_str << ";" << endl;
  } else {
    dfs_simulator << indent << out_str << " = " << arg0_str << op_str
                  << arg1_str << ";" << endl;
  }
}

void IlaSim::dfs_binary_op_non_mem_check(const ExprPtr &expr) {
  if (expr->is_mem())
    cout << "Error: AND/OR/XOR/SHL/LSHR/ASHR/ADD/MUL/CONCAT shouldn't output "
            "memory";
}

void IlaSim::dfs_binary_op_non_mem(stringstream &dfs_simulator, string &indent,
                                   const ExprPtr &expr) {
  dfs_binary_op_non_mem_check(expr);
  auto id = expr->name().id();
  string arg0_str = get_arg_str(expr->arg(0));
  string arg1_str = get_arg_str(expr->arg(1));
  string out_str = "c_" + to_string(expr->name().id());
  string out_type_str =
      (expr->is_bool())
          ? "bool "
          : (expr->is_bv())
                ? "sc_biguint<" + to_string(expr->sort()->bit_width()) + "> "
                : "";
  string op_str =
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
                                                    : (GetUidExprOp(expr) ==
                                                       AST_UID_EXPR_OP::MUL)
                                                          ? " * "
                                                          : (GetUidExprOp(
                                                                 expr) ==
                                                             AST_UID_EXPR_OP::
                                                                 CONCAT)
                                                                ? ", "
                                                                : "";
  declare_variable_with_id(id, out_type_str, out_str);
  dfs_simulator << indent << out_str << " = (" << arg0_str << op_str << arg1_str
                << ");" << endl;
}

void IlaSim::dfs_binary_op_mem(stringstream &dfs_simulator, string &indent,
                               const ExprPtr &expr) {
  auto id = expr->name().id();
  string arg0_str = get_arg_str(expr->arg(0));
  string arg1_str = get_arg_str(expr->arg(1));
  arg1_str = (arg1_str == "true")
                 ? "1"
                 : (arg1_str == "false") ? "0" : arg1_str + ".to_int()";
  string out_str = "c_" + to_string(expr->name().id());
  string out_type_str =
      (expr->is_bool())
          ? "bool "
          : (expr->is_bv())
                ? "sc_biguint<" + to_string(expr->sort()->bit_width()) + "> "
                : "";
  bool is_load = GetUidExprOp(expr) == AST_UID_EXPR_OP::LOAD;
  if (is_load) {
    if (declared_id_set_.find(id) == declared_id_set_.end()) {
      declared_id_set_.insert(id);
      header_ << header_indent_ << out_type_str << out_str << ";" << endl;
      if (EXTERNAL_MEM_) {
        header_ << header_indent_ << "int " << out_str << "_ctrl;" << endl;
        ld_info current_load;
        current_load.mem_str = arg0_str;
        current_load.addr_str = arg1_str;
        current_load.dest_str = out_str;
        external_ld_set_.push_back(current_load);
      }
    }
  }
  if (is_load) {
    if (EXTERNAL_MEM_) {
      dfs_simulator << indent << "if (" << out_str << "_ctrl == 0"
                    << ") {" << endl;
      dfs_simulator << indent << "  " << out_str << "_ctrl = 1;" << endl;
      dfs_simulator << indent << "  "
                    << "return 0;" << endl;
      dfs_simulator << indent << "} else if (" << out_str << "_ctrl == 1) {"
                    << endl;
      dfs_simulator << indent << "  return 0;" << endl;
      dfs_simulator << indent << "} else if (" << out_str << "_ctrl != 2) {"
                    << endl;
      dfs_simulator << indent << "  cout << \"Error: Load wrong\" << endl;"
                    << endl;
      dfs_simulator << indent << "}" << endl;
    } else
      dfs_simulator << indent << out_str << " = " << arg0_str << "[" << arg1_str
                    << "];" << endl;
  } else {
    string arg2_str = get_arg_str(expr->arg(2));
    arg2_str = (arg2_str == "true")
                   ? "1"
                   : (arg2_str == "false") ? "0" : arg2_str + ".to_int()";
    dfs_simulator << indent << "mem_update_map[" << arg1_str
                  << "] = " << arg2_str << ";" << endl;
  }
}

void IlaSim::dfs_extract_op(stringstream &dfs_simulator, string &indent,
                            const ExprPtr &expr) {
  auto id = expr->name().id();
  string arg_str = get_arg_str(expr->arg(0));
  auto param0 = static_cast<unsigned>(expr->param(0));
  auto param1 = static_cast<unsigned>(expr->param(1));
  auto out_str = "c_" + to_string(expr->name().id());
  string out_type_str =
      (expr->is_bool())
          ? "bool "
          : (expr->is_bv())
                ? "sc_biguint<" + to_string(expr->sort()->bit_width()) + "> "
                : "";
  declare_variable_with_id(id, out_type_str, out_str);
  dfs_simulator << indent << out_str << " = " << arg_str << ".range(" << param0
                << ", " << param1 << ");" << endl;
}

void IlaSim::dfs_ext_op(stringstream &dfs_simulator, string &indent,
                        const ExprPtr &expr) {
  auto id = expr->name().id();
  auto arg = expr->arg(0);
  string arg_str = get_arg_str(arg);
  auto param = static_cast<unsigned>(expr->param(0));
  auto out_str = "c_" + to_string(expr->name().id());
  string out_type_str =
      (expr->is_bool())
          ? "bool "
          : (expr->is_bv())
                ? "sc_biguint<" + to_string(expr->sort()->bit_width()) + "> "
                : "";
  declare_variable_with_id(id, out_type_str, out_str);

  if (GetUidExprOp(expr) == AST_UID_EXPR_OP::ZEXT) {
    dfs_simulator << indent << out_str << " = "
                  << "0;" << endl;
    dfs_simulator << indent << out_str << " = " << arg_str << ";" << endl;
  } else {
    dfs_simulator << indent << out_str << " = (" << arg_str << "["
                  << (arg->sort()->bit_width() - 1) << "] == 1) ? (~" << arg_str
                  << ") : " << arg_str << ";" << endl;
    dfs_simulator << indent << out_str << " = (" << arg_str << "["
                  << (arg->sort()->bit_width() - 1) << "] == 1) ? (~" << out_str
                  << ") : " << out_str << ";" << endl;
  }
}

void IlaSim::dfs_func_op_check(const ExprPtr &expr) {
  if (expr->is_mem())
    cout << "Error: APPFUNC shouldn't output memory";
}

void IlaSim::dfs_func_op(stringstream &dfs_simulator, string &indent,
                         const ExprPtr &expr) {
  dfs_func_op_check(expr);
  auto id = expr->name().id();
  auto appfunc_expr = dynamic_pointer_cast<ExprOpAppFunc>(expr);
  auto func = appfunc_expr->func();
  auto func_name = func->name().str();
  if (func_set_.find(func_name) == func_set_.end()) {
    func_set_.insert(func_name);
    dfs_uninterpreted_func_decl(func);
  }
  auto out_str = "c_" + to_string(expr->name().id());
  string out_type_str =
      (expr->is_bool())
          ? "bool "
          : (expr->is_bv())
                ? "sc_biguint<" + to_string(expr->sort()->bit_width()) + "> "
                : "";
  declare_variable_with_id(id, out_type_str, out_str);
  dfs_simulator << indent << out_str << " = " << func_name << "(";
  for (int i = 0; i < appfunc_expr->arg_num(); i++) {
    if (i != 0)
      dfs_simulator << ", ";
    dfs_simulator << get_arg_str(appfunc_expr->arg(i));
  }
  dfs_simulator << ");" << endl;
}

void IlaSim::dfs_ite_op(stringstream &dfs_simulator, string &indent,
                        const ExprPtr &expr) {
  auto id = expr->name().id();
  auto cond_str = get_arg_str(expr->arg(0));
  auto true_str = get_arg_str(expr->arg(1));
  auto false_str = get_arg_str(expr->arg(2));
  auto out_str = "c_" + to_string(expr->name().id());
  string out_type_str =
      (expr->is_bool())
          ? "bool "
          : (expr->is_bv())
                ? "sc_biguint<" + to_string(expr->sort()->bit_width()) + "> "
                : "";
  if (!expr->is_mem()) {
    declare_variable_with_id(id, out_type_str, out_str);
    dfs_simulator << indent << out_str << " = (" << cond_str << ") ? "
                  << true_str << " : " << false_str << ";" << endl;
  } else {
    if (store_ite_set_.find(id) == store_ite_set_.end()) {
      store_ite_set_.insert(id);
      searched_id_set_.insert(id);
      dfs_simulator << indent << "ite_" << id << "(mem_update_map);" << endl;
    }
  }
}

void IlaSim::dfs_kernel(stringstream &dfs_simulator, string &indent,
                        const ExprPtr &expr) {
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
                              (expr_op_uid == AST_UID_EXPR_OP::MUL) ||
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
      cout << "Error: OP_ID = " << expr_op_uid << " is not supported by ILA"
           << endl;
      return;
    }
  }
}
}; // namespace ilang
