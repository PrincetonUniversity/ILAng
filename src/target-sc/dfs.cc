// dfs.cc

#include <fmt/format.h>

#include <ilang/target-sc/ila_sim.h>
#include <ilang/util/log.h>

#include "ast_fuse.h"

namespace ilang {

std::string IlaSim::get_type_str(const ExprPtr& expr) {
  if (expr->is_bv()) {
    return (qemu_device_)
               ? fmt::format("uint{}_t", expr->sort()->bit_width())
               : fmt::format("sc_biguint<{}>", expr->sort()->bit_width());
  } else {
    return expr->is_bool() ? "bool" : "";
  }
}

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
  auto func_name = func->name().str();
  auto func_out_sort = func->out();

  header_ << header_indent_;

  if (func_out_sort->is_bool()) {
    header_ << fmt::format("bool {} (", func_name);
  } else {
    auto out_width = func_out_sort->is_bv() ? func_out_sort->bit_width()
                                            : func_out_sort->data_width();
    auto out_type = (qemu_device_) ? fmt::format("uint{}_t", out_width)
                                   : fmt::format("sc_biguint<{}>", out_width);
    if (func_out_sort->is_bv()) {
      header_ << fmt::format("{} {} (", out_type, func_name);
    } else { // is_mem()
      header_ << fmt::format("{}* {} (", out_type, func_name);
    }
  }

  for (unsigned int i = 0; i < func->arg_num(); i++) {
    if (i != 0) {
      header_ << ", ";
    }

    auto arg_i = func->arg(i);
    if (arg_i->is_bool()) {
      header_ << fmt::format("bool arg_{}", i);
    } else {
      auto width = arg_i->is_bv() ? arg_i->bit_width() : arg_i->data_width();
      auto type = (qemu_device_) ? fmt::format("uint{}_t", width)
                                 : fmt::format("sc_biguint<{}>", width);
      header_ << fmt::format("{} arg_{}", type, i);
    }
  }
  header_ << ");\n";
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
      auto const_mem_array = fmt::format("c_{}[{}]", id, array_size);

      if (qemu_device_) {
        header_ << indent
                << fmt::format("const uint{}_t {} = {{",
                               std::to_string(sort->data_width()),
                               const_mem_array);
      } else {
        header_ << indent
                << fmt::format("const sc_biguint<{}> {} = {{",
                               std::to_string(sort->data_width()),
                               const_mem_array);
      }
      for (unsigned i = 0; i < array_size - 1; i++)
        header_ << val_map[i] << ", ";
      header_ << val_map[array_size - 1] << "};\n";
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

  std::string op_str = "";
  switch (GetUidExprOp(expr)) {
  case AST_UID_EXPR_OP::NEG: {
    op_str = "-";
    break;
  }
  case AST_UID_EXPR_OP::NOT: {
    op_str = "!";
    break;
  }
  case AST_UID_EXPR_OP::COMPL: {
    op_str = "~";
    break;
  }
  default: {
    op_str = "";
    break;
  }
  }; // siwtch GetUidExprOp(expr)

  // TODO(yuex): be careful with the diff between NEG and COMPL
  auto out_type_str = get_type_str(expr);

  declare_variable_with_id(id, out_type_str, out_str);
  dfs_simulator << indent << out_str << " = " << op_str << arg_str << ";\n";
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

  auto uid = GetUidExprOp(expr);

  std::string op_str = "";
  switch (uid) {
  case AST_UID_EXPR_OP::EQ: {
    op_str = "==";
    break;
  }
  case AST_UID_EXPR_OP::LT: {
    op_str = "<";
    break;
  }
  case AST_UID_EXPR_OP::GT: {
    op_str = ">";
    break;
  }
  case AST_UID_EXPR_OP::ULT: {
    op_str = "<";
    break;
  }
  case AST_UID_EXPR_OP::UGT: {
    op_str = ">";
    break;
  }
  default: {
    op_str = "";
    break;
  }
  }; // switch GetUidExprOp(expr)

  declare_variable_with_id(id, "bool", out_str);

  dfs_simulator << indent;
  if (uid == AST_UID_EXPR_OP::IMPLY) {
    dfs_simulator << fmt::format("{} = (!{}) & {};\n", out_str, arg0_str,
                                 arg1_str);
  } else {
    dfs_simulator << fmt::format("{} = {} {} {};\n", out_str, arg0_str, op_str,
                                 arg1_str);
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

  auto out_type_str = get_type_str(expr);

  std::string op_str = "";
  auto uid = GetUidExprOp(expr);
  switch (uid) {
  case AST_UID_EXPR_OP::AND: {
    op_str = "&";
    break;
  }
  case AST_UID_EXPR_OP::OR: {
    op_str = "|";
    break;
  }
  case AST_UID_EXPR_OP::XOR: {
    op_str = "^";
    break;
  }
  case AST_UID_EXPR_OP::SHL: {
    op_str = "<<";
    break;
  }
  case AST_UID_EXPR_OP::LSHR: {
    op_str = ">>";
    break;
  }
  case AST_UID_EXPR_OP::ASHR: {
    op_str = ">>";
    break;
  }
  case AST_UID_EXPR_OP::ADD: {
    op_str = "+";
    break;
  }
  case AST_UID_EXPR_OP::SUB: {
    op_str = "-";
    break;
  }
  case AST_UID_EXPR_OP::MUL: {
    op_str = "*";
    break;
  }
  case AST_UID_EXPR_OP::DIV: {
    op_str = "/";
    break;
  }
  case AST_UID_EXPR_OP::CONCAT: {
    op_str = ",";
    break;
  }
  case AST_UID_EXPR_OP::UREM: {
    op_str = "%";
    break;
  }
  default: {
    op_str = "";
    break;
  }
  }; // switch uid

  declare_variable_with_id(id, out_type_str, out_str);

  dfs_simulator << indent;
  if (uid == AST_UID_EXPR_OP::CONCAT) {
    auto arg0_width = expr->arg(0)->sort()->bit_width();
    auto arg1_width = expr->arg(1)->sort()->bit_width();

    if (qemu_device_) {
      auto out_width = arg0_width + arg1_width;
      dfs_simulator << fmt::format("{} = (static_cast<uint{}_t>({}) << {}) + "
                                   "static_cast<uint{}_t>({});\n",
                                   out_str, out_width, arg0_str, arg1_width,
                                   out_width, arg1_str);
    } else {
      dfs_simulator << fmt::format(
          "{} = (sc_biguint<{}>({}) {} sc_biguint<{}>({}));\n", out_str,
          arg0_width, arg0_str, op_str, arg1_width, arg1_str);
    }
  } else {
    dfs_simulator << fmt::format("{} = ({} {} {});\n", out_str, arg0_str,
                                 op_str, arg1_str);
  }
}

void IlaSim::dfs_binary_op_mem(std::stringstream& dfs_simulator,
                               std::string& indent, const ExprPtr& expr) {
  auto id = expr->name().id();
  std::string arg0_str = get_arg_str(expr->arg(0));
  std::string arg1_str = get_arg_str(expr->arg(1));
  if (qemu_device_) {
    arg1_str =
        (arg1_str == "true") ? "1" : (arg1_str == "false") ? "0" : arg1_str;
  } else {
    arg1_str = (arg1_str == "true")
                   ? "1"
                   : (arg1_str == "false")
                         ? "0"
                         : (GetUidExpr(expr->arg(1)) == AST_UID_EXPR::CONST)
                               ? arg1_str
                               : arg1_str + ".to_int()";
  }

  std::string out_str = "c_" + std::to_string(expr->name().id());

  auto out_type_str = get_type_str(expr);

  bool is_load = GetUidExprOp(expr) == AST_UID_EXPR_OP::LOAD;
  auto arg0_uid = GetUidExpr(expr->arg(0));
  if (is_load) {
    if (declared_id_set_.find(id) == declared_id_set_.end()) {
      declared_id_set_.insert(id);
      header_ << header_indent_
              << fmt::format("{} {};\n", out_type_str, out_str);
      if ((EXTERNAL_MEM_) && (arg0_uid == AST_UID_EXPR::VAR)) {
        header_ << header_indent_ << "int " << out_str << "_ctrl;\n";
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

      dfs_simulator << fmt::format(
          "{0}if ({1}_ctrl == 0) {{\n"
          "{0}  {1}_ctrl = 1;\n"
          "{0}  return 0;\n"
          "{0}}} else if ({1}_ctrl == 1) {{\n"
          "{0}  return 0;\n"
          "{0}}} else if ({1}_ctrl != 2) {{\n"
          "{0}  cout << \"Error: Load wrong\" << endl;\n"
          "{0}}}\n",
          indent, out_str);

    } else {
      dfs_simulator << indent
                    << fmt::format("{} = {}[{}];\n", out_str, arg0_str,
                                   arg1_str);
    }
  } else {
    std::string arg2_str = get_arg_str(expr->arg(2));
    if (qemu_device_) {
      arg2_str =
          (arg2_str == "true") ? "1" : (arg2_str == "false") ? "0" : arg2_str;
    } else {
      arg2_str = (arg2_str == "true")
                     ? "1"
                     : (arg2_str == "false")
                           ? "0"
                           : (GetUidExpr(expr->arg(2)) == AST_UID_EXPR::CONST)
                                 ? arg2_str
                                 : arg2_str + ".to_int()";
    }

    dfs_simulator << indent
                  << fmt::format("mem_update_map[{}] = {};\n", arg1_str,
                                 arg2_str);
  }
}

void IlaSim::dfs_extract_op(std::stringstream& dfs_simulator,
                            std::string& indent, const ExprPtr& expr) {
  auto id = expr->name().id();
  std::string arg_str = get_arg_str(expr->arg(0));
  auto param0 = static_cast<unsigned>(expr->param(0));
  auto param1 = static_cast<unsigned>(expr->param(1));
  auto out_str = "c_" + std::to_string(expr->name().id());

  auto out_type_str = get_type_str(expr);

  declare_variable_with_id(id, out_type_str, out_str);

  if (qemu_device_) {
    auto tmp_str = fmt::format("tmp_{}", expr->name().id());
    int cast_length = param0 - param1 + 1;

    dfs_simulator << fmt::format(
        "{0}uint{1}_t {2} = 0 - 1;\n"
        "{0}{3} = static_cast<uint{1}_t> (({4} >> {5}) & {2});\n",
        indent,      // 0
        cast_length, // 1
        tmp_str,     // 2
        out_str,     // 3
        arg_str,     // 4
        param1       // 5
    );
  } else {
    dfs_simulator << fmt::format("{0}{1} = {2}.range({3}, {4});\n",
                                 indent,  // 0
                                 out_str, // 1
                                 arg_str, // 2
                                 param0,  // 3
                                 param1   // 4
    );
  }
}

void IlaSim::dfs_ext_op(std::stringstream& dfs_simulator, std::string& indent,
                        const ExprPtr& expr) {
  auto id = expr->name().id();
  auto arg = expr->arg(0);
  std::string arg_str = get_arg_str(arg);
  auto out_str = "c_" + std::to_string(expr->name().id());
  auto out_type_str = get_type_str(expr);

  declare_variable_with_id(id, out_type_str, out_str);

  if (GetUidExprOp(expr) == AST_UID_EXPR_OP::ZEXT) {
    dfs_simulator << indent << fmt::format("{} = 0;\n", out_str);
    dfs_simulator << indent;
    if (qemu_device_) {
      dfs_simulator << fmt::format("{} = static_cast<uint{}_t>({});\n", out_str,
                                   expr->sort()->bit_width(), arg_str);
    } else {
      dfs_simulator << fmt::format("{} = {};\n", out_str, arg_str);
    }
  } else {
    if (qemu_device_) {
      dfs_simulator << fmt::format(
          "{0}{1} = static_cast<uint{3}_t>({2});\n"
          "{0}{1} = ({2} >> {4}) ? static_cast<uint{3}_t>(~{2})\n"
          "{0}                   : static_cast<uint{3}_t>({2});\n"
          "{0}{1} = ({2} >> {4}) ? (~{1}) : {1};\n",
          indent,                        // 0
          out_str,                       // 1
          arg_str,                       // 2
          expr->sort()->bit_width(),     // 3
          (arg->sort()->bit_width() - 1) // 4
      );
    } else {
      dfs_simulator << fmt::format("{0}{1} = ({2}[{3}] == 1) ? (~{2}) : {2};\n"
                                   "{0}{1} = ({2}[{3}] == 1) ? (~{1}) : {1};\n",
                                   indent,                        // 0
                                   out_str,                       // 1
                                   arg_str,                       // 2
                                   (arg->sort()->bit_width() - 1) // 3
      );
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
  auto out_type_str = get_type_str(expr);

  declare_variable_with_id(id, out_type_str, out_str);
  dfs_simulator << indent << out_str << " = " << func_name << "(";
  for (unsigned int i = 0; i < appfunc_expr->arg_num(); i++) {
    if (i != 0)
      dfs_simulator << ", ";
    dfs_simulator << get_arg_str(appfunc_expr->arg(i));
  }
  dfs_simulator << ");\n";
}

void IlaSim::dfs_ite_op(std::stringstream& dfs_simulator, std::string& indent,
                        const ExprPtr& expr) {
  auto id = expr->name().id();
  auto cond_str = get_arg_str(expr->arg(0));
  auto true_str = get_arg_str(expr->arg(1));
  auto false_str = get_arg_str(expr->arg(2));
  auto out_str = "c_" + std::to_string(expr->name().id());
  auto out_type_str = get_type_str(expr);

  if (!expr->is_mem()) {
    declare_variable_with_id(id, out_type_str, out_str);
    dfs_simulator << indent
                  << fmt::format("{} = ({}) ? {} : {};\n", out_str, cond_str,
                                 true_str, false_str);
  } else {
    if (store_ite_set_.find(id) == store_ite_set_.end()) {
      store_ite_set_.insert(id);
      searched_id_set_.insert(id);
      dfs_simulator << indent << fmt::format("ite_{}(mem_update_map);\n", id);
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
                              (expr_op_uid == AST_UID_EXPR_OP::MUL) ||
                              (expr_op_uid == AST_UID_EXPR_OP::DIV) ||
                              (expr_op_uid == AST_UID_EXPR_OP::CONCAT) ||
                              (expr_op_uid == AST_UID_EXPR_OP::UREM));
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
