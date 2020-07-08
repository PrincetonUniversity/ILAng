/// \file
/// Implementation of DFS visitor to translate expr in Ilator.

#include <fmt/format.h>

#include <ilang/ila/ast_fuse.h>
#include <ilang/util/log.h>

#include <ilang/target-sc/ilator.h>

namespace ilang {

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
  static const char* const_mem_template = "auto& {local_var} = {const_mem};\n";
  if (expr->is_mem()) {
    fmt::format_to(buff, const_mem_template, //
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
  static const char* const_non_mem_template =
      "{var_type} {local_var} = {const_value};\n";
  fmt::format_to(buff, const_non_mem_template, //
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

  if (auto uid = GetUidExprOp(expr); uid == AST_UID_EXPR_OP::STORE) {
    static const char* mem_store_template =
#ifdef ILATOR_PRECISE_MEM
        "tmp_memory[{address}] = {data};\n";
#else
        "tmp_memory[{address}.to_int()] = {data}.to_int();\n";
#endif
    fmt::format_to(buff, mem_store_template,
                   fmt::arg("address", LookUp(expr->arg(1), lut)),
                   fmt::arg("data", LookUp(expr->arg(2), lut)));
  } else { // ite
    static const char* mem_ite_template = "{ite_update_func}(tmp_memory);\n";
    auto mem_update_func = RegisterMemoryUpdate(expr);
    fmt::format_to(buff, mem_ite_template,
                   fmt::arg("ite_update_func", mem_update_func->name));
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

  std::vector<std::string> arguments;
  for (size_t i = 0; i < func->arg_num(); i++) {
    arguments.push_back(LookUp(app_func->arg(i), lut));
  }

  static const char* app_func_template =
      "auto {return_var} = {func_name}({argument_list});\n";
  fmt::format_to(buff, app_func_template, //
                 fmt::arg("return_var", local_var),
                 fmt::arg("func_name", func_cxx->name),
                 fmt::arg("argument_list", fmt::join(arguments, ", ")));
}

void Ilator::DfsOpSpecial(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) {
  auto local_var = GetLocalVar(lut);
  auto [it, status] = lut.insert({expr, local_var});
  ILA_ASSERT(status);

  switch (auto uid = GetUidExprOp(expr); uid) {
  case AST_UID_EXPR_OP::LOAD: {
    static const char* load_template =
        "auto {local_var} = {memory_source}[{address}{mem_suffix}];\n";
    fmt::format_to(buff, load_template, //
                   fmt::arg("local_var", local_var),
                   fmt::arg("memory_source", LookUp(expr->arg(0), lut)),
                   fmt::arg("address", LookUp(expr->arg(1), lut)),
#ifdef ILATOR_PRECISE_MEM
                   fmt::arg("mem_suffix", "")
#else
                   fmt::arg("mem_suffix", ".to_int()")
#endif
    );
    break;
  }
  case AST_UID_EXPR_OP::CONCAT: {
    // concate using "," in SystemC needs to be global
    auto global_var = GetCxxName(expr);
    auto [itg, stg] = lut.insert_or_assign(expr, global_var);
    ILA_ASSERT(!stg);
    global_vars_.insert(expr);

    static const char* concat_template =
        "{global_var} = ({type_0}({arg_0}), {type_1}({arg_1}));\n";
    auto arg0 = expr->arg(0);
    auto arg1 = expr->arg(1);
    fmt::format_to(buff, concat_template, //
                   fmt::arg("global_var", global_var),
                   fmt::arg("type_0", GetCxxType(arg0)),
                   fmt::arg("arg_0", LookUp(arg0, lut)),
                   fmt::arg("type_1", GetCxxType(arg1)),
                   fmt::arg("arg_1", LookUp(arg1, lut)));
    break;
  }
  case AST_UID_EXPR_OP::EXTRACT: {
    static const char* extract_template =
        "auto {extract} = {origin}.range({loc_high}, {loc_low});\n";
    fmt::format_to(buff, extract_template, //
                   fmt::arg("extract", local_var),
                   fmt::arg("origin", LookUp(expr->arg(0), lut)),
                   fmt::arg("loc_high", expr->param(0)),
                   fmt::arg("loc_low", expr->param(1)));
    break;
  }
  case AST_UID_EXPR_OP::ZEXT:
    [[fallthrough]];
  case AST_UID_EXPR_OP::SEXT: {
    static const char* extend_template =
        "auto {extend} = ({origin}[{sign}] == 1) ? (~{origin}) : {origin};\n"
        "{extend} = ({origin}[{sign}] == 1) ? (~{extend}) : {extend};\n";
    auto origin_expr = expr->arg(0);
    fmt::format_to(buff, extend_template, //
                   fmt::arg("extend", local_var),
                   fmt::arg("origin", LookUp(origin_expr, lut)),
                   fmt::arg("sign", origin_expr->sort()->bit_width() - 1));
    break;
  }
  case AST_UID_EXPR_OP::IMPLY: {
    static const char* imply_template =
        "auto {local_var} = (!{if_var}) & {then_var};\n";
    fmt::format_to(buff, imply_template, //
                   fmt::arg("local_var", local_var),
                   fmt::arg("if_var", LookUp(expr->arg(0), lut)),
                   fmt::arg("then_var", LookUp(expr->arg(1), lut)));
    break;
  }
  case AST_UID_EXPR_OP::ITE: {
    static const char* ite_template =
        "auto {local_var} = ({condition}) ? {true_branch} : {false_branch};\n";
    fmt::format_to(buff, ite_template, //
                   fmt::arg("local_var", local_var),
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

  static const char* unary_op_template =
      "{var_type} {local_var} = {unary_op}{arg_0};\n";
  static const char* binary_op_template =
      "{var_type} {local_var} = ({arg_0} {binary_op} {arg_1});\n";

  if (expr->arg_num() == 1) {
    fmt::format_to(buff, unary_op_template, //
                   fmt::arg("var_type", GetCxxType(expr)),
                   fmt::arg("local_var", local_var),
                   fmt::arg("unary_op", pos->second),
                   fmt::arg("arg_0", LookUp(expr->arg(0), lut)));
  } else if (expr->arg_num() == 2) {
    fmt::format_to(buff, binary_op_template, //
                   fmt::arg("var_type", GetCxxType(expr)),
                   fmt::arg("local_var", local_var),
                   fmt::arg("arg_0", LookUp(expr->arg(0), lut)),
                   fmt::arg("binary_op", pos->second),
                   fmt::arg("arg_1", LookUp(expr->arg(1), lut)));
  }
  ILA_ASSERT(expr->arg_num() <= 2);
}

} // namespace ilang
