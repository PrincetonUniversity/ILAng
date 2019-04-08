/// \file
/// Header for evaluate constant width
// -- Hongce Zhang (hongcez@princeton.edu)

#ifndef VERILOG_CONST_PARSER_H__
#define VERILOG_CONST_PARSER_H__

#include <string>

extern "C" {
#include <verilogparser/verilog_ast.h>
}
/// \namespace ilang
namespace ilang {

/// \brief The class to convert a constant expr
/// to an integer number
class VerilogConstantExprEval
{
protected:
  /// the given expression
  ast_expression * eval_expr;
  /// whether it has been evaluated or not
  bool evaluated;
  /// if it has been evaluated store the value here
  unsigned cached_value;
  /// record if there was an error in eval
  bool eval_error;
  /// record the errorneous part:
  std::string error_str;
  // --------------------- HELPER FUNC ---------------------------- //
  unsigned virtual _eval(ast_expression * e);
public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  /// input : the string to evaluate
  VerilogConstantExprEval(ast_expression * e);
  /// Get the value
  unsigned Eval();
  /// Get parsing error
  bool error() const;
}; // class VerilogConstantExprEval

}; // namespace ilang

#endif // VERILOG_CONST_PARSER_H__