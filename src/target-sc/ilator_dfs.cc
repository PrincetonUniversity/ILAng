/// \file
/// Implementation of DFS visitor to translate expr in Ilator.

#include <fmt/format.h>

#include <ilang/ila/ast_fuse.h>
#include <ilang/util/log.h>

#include <ilang/target-sc/ilator.h>

namespace ilang {

void Ilator::DfsExpr(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) {
  if (auto pos = lut.find(expr); pos == lut.end()) {
    if (expr->is_var()) {
      DfsVar(expr, buff, lut);
    } else if (expr->is_const()) {
      DfsConst(expr, buff, lut);
    } else {
      ILA_ASSERT(expr->is_op());
      DfsOp(expr, buff, lut);
    }
  }
  ILA_ASSERT((expr->is_mem() && expr->is_op()) ||
             (lut.find(expr) != lut.end()));
}

void Ilator::DfsVar(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) const {
  auto [it, status] = lut.insert({expr, GetCxxName(expr)});
  ILA_ASSERT(status);
  // no need to define new variable
}

void Ilator::DfsConst(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) {
  auto local_var = GetLocalVar(lut);
  auto [it, status] = lut.insert({expr, local_var});
  ILA_ASSERT(status);

  // alias for constant memory
  if (expr->is_mem()) {
    fmt::format_to(buff, "auto& {local_var} = {const_mem};\n",
                   fmt::arg("local_var", local_var),
                   fmt::arg("const_mem", GetCxxName(expr)));
    const_mems_.insert(expr);
    return;
  }

  // define new var with constant value
  auto expr_const = std::dynamic_pointer_cast<ExprConst>(expr);
  std::string value = "";
  if (expr->is_bool()) {
    value = expr_const->val_bool()->val() ? "true" : "false";
  } else {
    ILA_ASSERT(expr->is_bv());
    value = std::to_string(expr_const->val_bv()->val());
  }
  fmt::format_to(buff, "{var_type} {local_var} = {const_value};\n",
                 fmt::arg("var_type", GetCxxType(expr)),
                 fmt::arg("local_var", local_var),
                 fmt::arg("const_value", value));
}

void Ilator::DfsOp(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) {
  // store, ite-mem
  if (expr->is_mem()) {
    DfsOpMemory(expr, buff, lut);
    return;
  }

  switch (auto uid = GetUidExprOp(expr); uid) {
  // apply function
  case AST_UID_EXPR_OP::APP_FUNC:
    DfsOpAppFunc(expr, buff, lut);
    break;
  // special cases
  case AST_UID_EXPR_OP::LOAD:
    [[fallthrough]];
  case AST_UID_EXPR_OP::CONCAT:
    [[fallthrough]];
  case AST_UID_EXPR_OP::EXTRACT:
    [[fallthrough]];
  case AST_UID_EXPR_OP::ZEXT:
    [[fallthrough]];
  case AST_UID_EXPR_OP::SEXT:
    [[fallthrough]];
  case AST_UID_EXPR_OP::IMPLY:
    [[fallthrough]];
  case AST_UID_EXPR_OP::ITE:
    DfsOpSpecial(expr, buff, lut);
    break;
  // regular operator
  default:
    DfsOpRegular(expr, buff, lut);
    break;
  };
}

void Ilator::DfsOpMemory(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) {
  auto mem_update_func = RegisterMemoryUpdate(expr);

  if (auto uid = GetUidExprOp(expr); uid == AST_UID_EXPR_OP::STORE) {
    fmt::format_to(buff, "tmp_memory[{address}.to_int()] = {data}.to_int();\n",
                   fmt::arg("address", LookUp(expr->arg(1), lut)),
                   fmt::arg("data", LookUp(expr->arg(2), lut)));
  } else { // ite
    fmt::format_to(buff, "{}(tmp_memory);\n", mem_update_func->name);
  }
}

void Ilator::DfsOpAppFunc(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) {
  ILA_CHECK(!expr->is_mem()) << "Func returning memory not supported yet";

  auto local_var = GetLocalVar(lut);
  auto [it, status] = lut.insert({expr, local_var});
  ILA_ASSERT(status);

  // apply uninterpreted function
  auto app_func = std::dynamic_pointer_cast<ExprOpAppFunc>(expr);
  auto func = app_func->func();
  auto func_cxx = RegisterExternalFunc(func);
  std::string argument_list = "";
  for (size_t i = 0; i < func->arg_num(); i++) {
    if (i != 0) {
      argument_list.append(", ");
    }
    auto arg_i = LookUp(app_func->arg(i), lut);
    argument_list.append(arg_i);
  }
  fmt::format_to(buff, "auto {return_var} = {func_name}({argument_list});\n",
                 fmt::arg("return_var", local_var),
                 fmt::arg("func_name", func_cxx->name),
                 fmt::arg("argument_list", argument_list));
}

void Ilator::DfsOpSpecial(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) {
  auto local_var = GetLocalVar(lut);
  auto [it, status] = lut.insert({expr, local_var});
  ILA_ASSERT(status);

  switch (auto uid = GetUidExprOp(expr); uid) {
  case AST_UID_EXPR_OP::LOAD: {
    fmt::format_to(
        buff, "{var_type} {local_var} = {memory_source}[{address}.to_int()];\n",
        fmt::arg("var_type", GetCxxType(expr)),
        fmt::arg("local_var", local_var),
        fmt::arg("memory_source", LookUp(expr->arg(0), lut)),
        fmt::arg("address", LookUp(expr->arg(1), lut)));
    break;
  }
  case AST_UID_EXPR_OP::CONCAT: {
    // concate using "," in SystemC needs to be global
    auto global_var = GetCxxName(expr);
    auto [itg, stg] = lut.insert_or_assign(expr, global_var);
    ILA_ASSERT(!stg);
    global_vars_.insert(expr);

    auto arg0 = expr->arg(0);
    auto arg1 = expr->arg(1);
    fmt::format_to(buff,
                   "{global_var} = ({type_0}({arg_0}), {type_1}({arg_1}));\n",
                   fmt::arg("global_var", global_var),
                   fmt::arg("type_0", GetCxxType(arg0)),
                   fmt::arg("arg_0", LookUp(arg0, lut)),
                   fmt::arg("type_1", GetCxxType(arg1)),
                   fmt::arg("arg_1", LookUp(arg1, lut)));
    break;
  }
  case AST_UID_EXPR_OP::EXTRACT: {
    fmt::format_to(buff,
                   "auto {extract} = {origin}.range({loc_high}, {loc_low});\n",
                   fmt::arg("extract", local_var),
                   fmt::arg("origin", LookUp(expr->arg(0), lut)),
                   fmt::arg("loc_high", expr->param(0)),
                   fmt::arg("loc_low", expr->param(1)));
    break;
  }
  case AST_UID_EXPR_OP::ZEXT:
    [[fallthrough]];
  case AST_UID_EXPR_OP::SEXT: {
    auto origin_expr = expr->arg(0);
    fmt::format_to(
        buff,
        "auto {extend} = ({origin}[{sign}] == 1) ? (~{origin}) : {origin};\n"
        "{extend} = ({origin}[{sign}] == 1) ? (~{extend}) : {extend};\n",
        fmt::arg("extend", local_var),
        fmt::arg("origin", LookUp(origin_expr, lut)),
        fmt::arg("sign", origin_expr->sort()->bit_width() - 1));
    break;
  }
  case AST_UID_EXPR_OP::IMPLY: {
    fmt::format_to(buff, "auto {local_var} = (!{if_var}) & {then_var};\n",
                   fmt::arg("local_var", local_var),
                   fmt::arg("if_var", LookUp(expr->arg(0), lut)),
                   fmt::arg("then_var", LookUp(expr->arg(1), lut)));
    break;
  }
  case AST_UID_EXPR_OP::ITE: {
    fmt::format_to(
        buff,
        "auto {new_var} = ({condition}) ? {true_branch} : {false_branch};\n",
        fmt::arg("new_var", local_var),
        fmt::arg("condition", LookUp(expr->arg(0), lut)),
        fmt::arg("true_branch", LookUp(expr->arg(1), lut)),
        fmt::arg("false_branch", LookUp(expr->arg(2), lut)));
    break;
  }
  default:
    ILA_CHECK(false) << expr;
    break;
  };
}

static const std::unordered_map<AST_UID_EXPR_OP, std::string> k_op_symbols = {
    // unary
    {AST_UID_EXPR_OP::NEG, "-"},
    {AST_UID_EXPR_OP::NOT, "!"},
    {AST_UID_EXPR_OP::COMPL, "~"},
    // binary compare
    {AST_UID_EXPR_OP::EQ, "=="},
    {AST_UID_EXPR_OP::LT, "<"},
    {AST_UID_EXPR_OP::GT, ">"},
    {AST_UID_EXPR_OP::ULT, "<"},
    {AST_UID_EXPR_OP::UGT, ">"},
    // binary arith
    {AST_UID_EXPR_OP::AND, "&"},
    {AST_UID_EXPR_OP::OR, "|"},
    {AST_UID_EXPR_OP::XOR, "^"},
    {AST_UID_EXPR_OP::SHL, "<<"},
    {AST_UID_EXPR_OP::LSHR, ">>"},
    {AST_UID_EXPR_OP::ASHR, ">>"},
    {AST_UID_EXPR_OP::ADD, "+"},
    {AST_UID_EXPR_OP::SUB, "-"},
    {AST_UID_EXPR_OP::MUL, "*"},
    {AST_UID_EXPR_OP::DIV, "/"},
    {AST_UID_EXPR_OP::UREM, "%"}};

void Ilator::DfsOpRegular(const ExprPtr& expr, StrBuff& buff,
                          ExprVarMap& lut) const {
  auto local_var = GetLocalVar(lut);
  auto [it, status] = lut.insert({expr, local_var});
  ILA_ASSERT(status);

  // get the corresponding operator symbol
  auto uid = GetUidExprOp(expr);
  auto pos = k_op_symbols.find(uid);
  ILA_ASSERT(pos != k_op_symbols.end()) << uid;

  if (expr->arg_num() == 1) {
    fmt::format_to(buff, "auto {local_var} = {unary_op}{argument};\n",
                   fmt::arg("local_var", local_var),
                   fmt::arg("unary_op", pos->second),
                   fmt::arg("argument", LookUp(expr->arg(0), lut)));
  } else if (expr->arg_num() == 2) {
    fmt::format_to(buff, "auto {local_var} = ({arg_0} {binary_op} {arg_1});\n",
                   fmt::arg("local_var", local_var),
                   fmt::arg("arg_0", LookUp(expr->arg(0), lut)),
                   fmt::arg("binary_op", pos->second),
                   fmt::arg("arg_1", LookUp(expr->arg(1), lut)));
  }
  ILA_ASSERT(expr->arg_num() <= 2);
}

} // namespace ilang
