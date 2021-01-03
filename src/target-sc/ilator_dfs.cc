/// \file
/// Implementation of DFS visitor to translate expr in Ilator.

#include <ilang/target-sc/ilator.h>

#include <fmt/format.h>

#include <ilang/ila/ast_hub.h>
#include <ilang/util/log.h>

namespace ilang {

void Ilator::DfsExpr(const ExprPtr& e, StrBuff& buff, ExprVarMap& lut) {
  if (auto pos = lut.find(e); pos == lut.end()) {
    if (e->is_var()) {
      DfsVar(e, buff, lut);
    } else if (e->is_const()) {
      DfsConst(e, buff, lut);
    } else {
      ILA_ASSERT(e->is_op());
      DfsOp(e, buff, lut);
    }
  }
  ILA_ASSERT((e->is_mem() && e->is_op()) || (lut.find(e) != lut.end()));
}

void Ilator::DfsVar(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) const {
  auto [it, status] = lut.try_emplace(expr, GetCxxName(expr));
  ILA_ASSERT(status);
  // no need to define new variable
}

void Ilator::DfsConst(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) {
  auto local_var = GetLocalVar(lut);
  auto [it, status] = lut.try_emplace(expr, local_var);
  ILA_ASSERT(status);

  // alias for constant memory
  static const char* kConstMemTemplate = "auto& {local_var} = {const_mem};\n";
  if (expr->is_mem()) {
    fmt::format_to(buff, kConstMemTemplate, //
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
  static const char* kConstNonMemTemplate =
      "{var_type} {local_var} = {const_value};\n";
  fmt::format_to(buff, kConstNonMemTemplate, //
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

  switch (auto uid = asthub::GetUidExprOp(expr); uid) {
  // apply function
  case AstUidExprOp::kApplyFunc:
    DfsOpAppFunc(expr, buff, lut);
    break;
  // special cases
  case AstUidExprOp::kLoad:
    [[fallthrough]];
  case AstUidExprOp::kConcatenate:
    [[fallthrough]];
  case AstUidExprOp::kExtract:
    [[fallthrough]];
  case AstUidExprOp::kZeroExtend:
    [[fallthrough]];
  case AstUidExprOp::kSignedExtend:
    [[fallthrough]];
  case AstUidExprOp::kImply:
    [[fallthrough]];
  case AstUidExprOp::kIfThenElse:
    DfsOpSpecial(expr, buff, lut);
    break;
  // regular operator
  default:
    DfsOpRegular(expr, buff, lut);
    break;
  };
}

void Ilator::DfsOpMemory(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) {

  if (auto uid = asthub::GetUidExprOp(expr); uid == AstUidExprOp::kStore) {
    static const char* kMemStoreTemplate =
#ifdef ILATOR_PRECISE_MEM
        "tmp_memory[{address}] = {data};\n";
#else
        "tmp_memory[{address}.to_int()] = {data}.to_int();\n";
#endif
    fmt::format_to(buff, kMemStoreTemplate,
                   fmt::arg("address", LookUp(expr->arg(1), lut)),
                   fmt::arg("data", LookUp(expr->arg(2), lut)));
  } else { // ite
    static const char* kMemIteTemplate = "{ite_update_func}(tmp_memory);\n";
    auto mem_update_func = RegisterMemoryUpdate(expr);
    fmt::format_to(buff, kMemIteTemplate,
                   fmt::arg("ite_update_func", mem_update_func->name));
  }
}

void Ilator::DfsOpAppFunc(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) {
  ILA_CHECK(!expr->is_mem()) << "Func returning memory not supported yet";

  auto local_var = GetLocalVar(lut);
  auto [it, status] = lut.try_emplace(expr, local_var);
  ILA_ASSERT(status);

  // apply uninterpreted function
  auto app_func = std::dynamic_pointer_cast<ExprOpAppFunc>(expr);
  auto func = app_func->func();
  auto func_cxx = RegisterExternalFunc(func);

  std::vector<std::string> arguments;
  for (size_t i = 0; i < func->arg_num(); i++) {
    arguments.push_back(LookUp(app_func->arg(i), lut));
  }

  static const char* kAppFuncTemplate =
      "auto {return_var} = {func_name}({argument_list});\n";
  fmt::format_to(buff, kAppFuncTemplate, //
                 fmt::arg("return_var", local_var),
                 fmt::arg("func_name", func_cxx->name),
                 fmt::arg("argument_list", fmt::join(arguments, ", ")));
}

void Ilator::DfsOpSpecial(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) {
  auto local_var = GetLocalVar(lut);
  auto [it, status] = lut.try_emplace(expr, local_var);
  ILA_ASSERT(status);

  switch (auto uid = asthub::GetUidExprOp(expr); uid) {
  case AstUidExprOp::kLoad: {
    static const char* kLoadTemplate =
        "auto {local_var} = {memory_source}[{address}{mem_suffix}];\n";
    fmt::format_to(buff, kLoadTemplate, //
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
  case AstUidExprOp::kConcatenate: {
    // concate using "," in SystemC needs to be global
    auto global_var = GetCxxName(expr);
    auto [itg, stg] = lut.insert_or_assign(expr, global_var);
    ILA_ASSERT(!stg);
    global_vars_.insert(expr);

    static const char* kConcatTemplate =
        "{global_var} = ({type_0}({arg_0}), {type_1}({arg_1}));\n";
    auto arg0 = expr->arg(0);
    auto arg1 = expr->arg(1);
    fmt::format_to(buff, kConcatTemplate, //
                   fmt::arg("global_var", global_var),
                   fmt::arg("type_0", GetCxxType(arg0)),
                   fmt::arg("arg_0", LookUp(arg0, lut)),
                   fmt::arg("type_1", GetCxxType(arg1)),
                   fmt::arg("arg_1", LookUp(arg1, lut)));
    break;
  }
  case AstUidExprOp::kExtract: {
    static const char* kExtractTemplate =
        "auto {extract} = {origin}.range({loc_high}, {loc_low});\n";
    fmt::format_to(buff, kExtractTemplate, //
                   fmt::arg("extract", local_var),
                   fmt::arg("origin", LookUp(expr->arg(0), lut)),
                   fmt::arg("loc_high", expr->param(0)),
                   fmt::arg("loc_low", expr->param(1)));
    break;
  }
  case AstUidExprOp::kZeroExtend:
    [[fallthrough]];
  case AstUidExprOp::kSignedExtend: {
    static const char* kExtendTemplate =
        "auto {extend} = ({origin}[{sign}] == 1) ? (~{origin}) : {origin};\n"
        "{extend} = ({origin}[{sign}] == 1) ? (~{extend}) : {extend};\n";
    auto origin_expr = expr->arg(0);
    fmt::format_to(buff, kExtendTemplate, //
                   fmt::arg("extend", local_var),
                   fmt::arg("origin", LookUp(origin_expr, lut)),
                   fmt::arg("sign", origin_expr->sort()->bit_width() - 1));
    break;
  }
  case AstUidExprOp::kImply: {
    static const char* kImplyTemplate =
        "auto {local_var} = (!{if_var}) & {then_var};\n";
    fmt::format_to(buff, kImplyTemplate, //
                   fmt::arg("local_var", local_var),
                   fmt::arg("if_var", LookUp(expr->arg(0), lut)),
                   fmt::arg("then_var", LookUp(expr->arg(1), lut)));
    break;
  }
  case AstUidExprOp::kIfThenElse: {
    static const char* kIteTemplate =
        "auto {local_var} = ({condition}) ? {true_branch} : {false_branch};\n";
    fmt::format_to(buff, kIteTemplate, //
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

static const std::unordered_map<AstUidExprOp, std::string> kOpSymbols = {
    // unary
    {AstUidExprOp::kNegate, "-"},
    {AstUidExprOp::kNot, "!"},
    {AstUidExprOp::kComplement, "~"},
    // binary compare
    {AstUidExprOp::kEqual, "=="},
    {AstUidExprOp::kLessThan, "<"},
    {AstUidExprOp::kGreaterThan, ">"},
    {AstUidExprOp::kUnsignedLessThan, "<"},
    {AstUidExprOp::kUnsignedGreaterThan, ">"},
    // binary arith
    {AstUidExprOp::kAnd, "&"},
    {AstUidExprOp::kOr, "|"},
    {AstUidExprOp::kXor, "^"},
    {AstUidExprOp::kShiftLeft, "<<"},
    {AstUidExprOp::kLogicShiftRight, ">>"},
    {AstUidExprOp::kArithShiftRight, ">>"},
    {AstUidExprOp::kAdd, "+"},
    {AstUidExprOp::kSubtract, "-"},
    {AstUidExprOp::kMultiply, "*"},
    {AstUidExprOp::kDivide, "/"},
    {AstUidExprOp::kUnsignedRemainder, "%"}};

void Ilator::DfsOpRegular(const ExprPtr& expr, StrBuff& buff,
                          ExprVarMap& lut) const {
  auto local_var = GetLocalVar(lut);
  auto [it, status] = lut.try_emplace(expr, local_var);
  ILA_ASSERT(status);

  // get the corresponding operator symbol
  auto uid = asthub::GetUidExprOp(expr);
  auto pos = kOpSymbols.find(uid);
  ILA_ASSERT(pos != kOpSymbols.end()) << uid;

  static const char* kUnaryOpTemplate =
      "{var_type} {local_var} = {unary_op}{arg_0};\n";
  static const char* kBinaryOpTemplate =
      "{var_type} {local_var} = ({arg_0} {binary_op} {arg_1});\n";

  if (expr->arg_num() == 1) {
    fmt::format_to(buff, kUnaryOpTemplate, //
                   fmt::arg("var_type", GetCxxType(expr)),
                   fmt::arg("local_var", local_var),
                   fmt::arg("unary_op", pos->second),
                   fmt::arg("arg_0", LookUp(expr->arg(0), lut)));
  } else if (expr->arg_num() == 2) {
    fmt::format_to(buff, kBinaryOpTemplate, //
                   fmt::arg("var_type", GetCxxType(expr)),
                   fmt::arg("local_var", local_var),
                   fmt::arg("arg_0", LookUp(expr->arg(0), lut)),
                   fmt::arg("binary_op", pos->second),
                   fmt::arg("arg_1", LookUp(expr->arg(1), lut)));
  }
  ILA_ASSERT(expr->arg_num() <= 2);
}

} // namespace ilang
