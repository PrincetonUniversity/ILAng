/// \file
/// Header for evaluate constant width
// -- Hongce Zhang (hongcez@princeton.edu)

#ifndef ILANG_VERILOG_IN_VERILOG_CONST_PARSER_H__
#define ILANG_VERILOG_IN_VERILOG_CONST_PARSER_H__

#include <map>
#include <string>

extern "C" {
#include <verilogparser/verilog_ast.h>
}

/// \namespace ilang
namespace ilang {

/// \brief The class to convert a constant expr
/// to an integer number
class VerilogConstantExprEval {
protected:
  /// the given expression
  ast_expression* eval_expr;
  /// whether it has been evaluated or not
  bool evaluated;
  /// if it has been evaluated store the value here
  unsigned cached_value;
  /// record if there was an error in eval
  bool eval_error;
  /// record the errorneous part:
  std::string error_str;
  /// to record the variable binding
  std::map<std::string, double> param_defs;
  // --------------------- HELPER FUNC ---------------------------- //
  double virtual _eval(ast_expression* e);

public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  /// input : the string to evaluate
  VerilogConstantExprEval(ast_expression* e);
  /// parse only the current module's parameter definitions, will update
  /// param_defs
  void ParseCurrentModuleParameters(ast_module_declaration* m);
  /// parse a hierarchy
  // TODO: add function here
  /// Get the value
  double Eval();
}; // class VerilogConstantExprEval

}; // namespace ilang

#endif // ILANG_VERILOG_IN_VERILOG_CONST_PARSER_H__
