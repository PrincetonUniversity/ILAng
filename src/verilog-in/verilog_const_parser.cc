/// \file
/// Header for evaluate constant width
// -- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/verilog-in/verilog_const_parser.h>

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

VerilogConstantExprEval::VerilogConstantExprEval(ast_expression* _s)
    : eval_expr(_s), evaluated(false), cached_value(0), eval_error(false) {
  // do nothing
}

double VerilogConstantExprEval::_eval(ast_expression* e) {
  // ..
  if (e->type == ast_expression_type::PRIMARY_EXPRESSION) {
    if (e->primary->value_type == ast_primary_value_type::PRIMARY_IDENTIFIER) {
      // look in the definemap
      std::string id_name = ast_expression_tostring(e);
      auto pos = param_defs.find(id_name);
      if (pos == param_defs.end()) {
        error_str = id_name; // id_name not found
        eval_error = true;
        return 0;
      }
      return pos->second;
    } // else
    else if (e->primary->value_type == ast_primary_value_type::PRIMARY_NUMBER) {
      char * resp = ast_expression_tostring(e);
      double ret;
      if (e->primary->value.number->representation == ast_number_representation_e::REP_BITS ||
          e->primary->value.number->representation == ast_number_representation_e::REP_INTEGER) {
        unsigned base = 
          e->primary->value.number->base == ast_number_base_e::BASE_BINARY ? 2 :
          e->primary->value.number->base == ast_number_base_e::BASE_OCTAL ? 8 :
          e->primary->value.number->base == ast_number_base_e::BASE_DECIMAL ? 10 :
          e->primary->value.number->base == ast_number_base_e::BASE_HEX ? 16 : 10;
        ret = StrToInt(resp, base );
      } else { // float
        try{
          ret = std::stod(resp);
        } catch (const std::exception& e) {
          error_str = resp; // id_name not found
          eval_error = true;
          return 0;
        }
      }
      free(resp); 
      // if it is number, it uses calloc inside, which requires us
      // to explicitly free it
      return ret;
    } else { // parser error: unable to handle
      error_str = ast_expression_tostring(e);
      eval_error = true;
      return 0;
    }
  } else if (e->type == ast_expression_type::UNARY_EXPRESSION) {
    eval_error = true;
    error_str = ast_expression_tostring(e);
    return 0;
  } else if (e->type == ast_expression_type::BINARY_EXPRESSION) {
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

double VerilogConstantExprEval::Eval() {
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

static void* ast_list_get_not_null(ast_list* list, unsigned int item) {
  void* ret = ast_list_get(list, item);
  ILA_NOT_NULL(ret);
  return ret;
}

/// parse only the current module's parameter definitions, will update
/// param_defs
void VerilogConstantExprEval::ParseCurrentModuleParameters(
    ast_module_declaration* m) {
  if (m == NULL)
    return;
  ast_list* params = m->module_parameters;
  if (params == NULL)
    return;
  for (unsigned pi = 0; pi < params->items; ++pi) {
    ast_parameter_declarations* param_item =
        (ast_parameter_declarations*)ast_list_get_not_null(params, pi);
    // ILA_ASSERT(param_item->type == MOD_ITEM_PARAMETER_DECLARATION)
    //  << "Verilog parser bug: wrong type in param item";
    // ILA_NOT_NULL(param_item->parameter_declaration);
    ast_list* assigns = param_item->assignments;
    ILA_NOT_NULL(assigns);
    ILA_ASSERT(assigns->items > 0);
    for (unsigned assignidx = 0; assignidx < assigns->items; ++assignidx) {
      ast_single_assignment* asn =
          (ast_single_assignment*)ast_list_get_not_null(assigns, assignidx);
      std::string param_name =
          ast_identifier_tostring(asn->lval->data.identifier);
      auto val = _eval(asn->expression);
      if (eval_error) {
        eval_error = false;
        continue; // if we encounter error, just skip it
      }
      param_defs.insert(std::make_pair(param_name, val));
    }
  }
  return;
}

}; // namespace ilang
