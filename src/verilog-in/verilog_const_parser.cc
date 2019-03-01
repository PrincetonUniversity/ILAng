/// \file 
/// Header for evaluate constant width
// -- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/verilog-in/verilog_const_parser.h>

namespace ilang {

VerilogConstantExprEval::VerilogConstantExprEval(ast_expression * _s) :
  eval_expr(_s), evaluated(false), cached_value(0), eval_error(false)
{
  // do nothing
}



unsigned VerilogConstantExprEval::_eval(ast_expression * e) {
  // ..
  if ( e->type == ast_expression_type::PRIMARY_EXPRESSION ) {
    return StrToInt(ast_expression_tostring(e));
  } else if ( e->type == ast_expression_type::UNARY_EXPRESSION ) {
    eval_error = true;
    error_str = ast_expression_tostring(e);
    return 0;
  } else if ( e->type == ast_expression_type::BINARY_EXPRESSION ) {
    unsigned left = _eval(e->left);
    unsigned right = _eval(e->right);
    if (e->operation == ast_operator::OPERATOR_STAR)
      return left * right;
    if (e->operation == ast_operator::OPERATOR_PLUS)
      return left + right;
    if (e->operation == ast_operator::OPERATOR_MINUS)
      return left - right;
    if (e->operation == ast_operator::OPERATOR_DIV)
      return left / right;
    if (e->operation == ast_operator::OPERATOR_MOD)
      return left % right;
    
    eval_error = true;
    error_str = ast_expression_tostring(e);
    return 0;
  }

  eval_error = true;
  error_str = ast_expression_tostring(e);
  return 0;

}

unsigned VerilogConstantExprEval::Eval() {
  if (not evaluated) {
    cached_value = _eval(eval_expr);
    evaluated = true;
  }

  if (eval_error) {
    ILA_ERROR << "unable to parse: " << error_str;
    return 0; // error value
  }

  return cached_value;
}


}; // namespace ilang