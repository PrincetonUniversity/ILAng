/// \file
/// Header for evaluate constant width
// -- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/verilog-in/verilog_const_parser.h>

#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/verilog-in/vlog_parser_util.h>

namespace ilang {

VerilogConstantExprEval::VerilogConstantExprEval() : eval_error(false) {
  // do nothing
}

static void* ast_list_get_not_null(ast_list* list, unsigned int item) {
  void* ret = ast_list_get(list, item);
  ILA_NOT_NULL(ret);
  return ret;
}

double
VerilogConstantExprEval::_eval(ast_expression* e,
                               const named_parameter_dict_t& param_defs) {
  // ..
  ILA_NOT_NULL(e);
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
      char* resp = ast_expression_tostring(e);
      double ret;
      if (e->primary->value.number->representation ==
              ast_number_representation_e::REP_BITS ||
          e->primary->value.number->representation ==
              ast_number_representation_e::REP_INTEGER) {
        unsigned base =
            e->primary->value.number->base == ast_number_base_e::BASE_BINARY
                ? 2
                : e->primary->value.number->base ==
                          ast_number_base_e::BASE_OCTAL
                      ? 8
                      : e->primary->value.number->base ==
                                ast_number_base_e::BASE_DECIMAL
                            ? 10
                            : e->primary->value.number->base ==
                                      ast_number_base_e::BASE_HEX
                                  ? 16
                                  : 10;
        ret = StrToLong(resp, base);
      } else { // float
        try {
          ret = std::stod(resp);
        } catch (const std::exception& e) {
          error_str = resp; // id_name not found
          eval_error = true;
          return 0;
        }
      }
      // to explicitly free it
      return ret;
    } else if (e->primary->value_type ==
               ast_primary_value_type::PRIMARY_MINMAX_EXP) {
      if (e->primary->value.minmax->left != NULL ||
          e->primary->value.minmax->right != NULL ||
          e->primary->value.minmax->aux == NULL) {
        error_str = ast_expression_tostring(e);
        ILA_ERROR << "Unable to parse " << error_str;
        eval_error = true;
        return 0;
      }
      return _eval(e->primary->value.minmax->aux, param_defs);
    } else if (e->primary->value_type ==
               ast_primary_value_type::PRIMARY_CONCATENATION) {
      ast_concatenation* cc = e->primary->value.concatenation;
      unsigned repeat = cc->repeat ? _eval(cc->repeat, param_defs) : 1;
      unsigned total_width = 0;
      long long ret = 0;
      for (size_t idx = 0; idx < cc->items->items; ++idx) {
        ast_expression* it =
            (ast_expression*)ast_list_get_not_null(cc->items, idx);
        unsigned v = _eval(it, param_defs);
        unsigned width = it->primary->value.number->width;
        if (width == 0) {
          error_str = ast_expression_tostring(e);
          eval_error = true;
          return 0;
        }
        ret = ret << width;
        ret = ret | v;
        total_width += width;
      }
      unsigned origin = ret;
      for (unsigned idx = 1; idx < repeat; ++idx) {
        ret = ret << total_width;
        ret = ret | origin;
      }
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
    unsigned left = _eval(e->left, param_defs);
    unsigned right = _eval(e->right, param_defs);
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
    if (e->operation == ast_operator::OPERATOR_L_OR)
      return left || right;
    if (e->operation == ast_operator::OPERATOR_L_AND)
      return left && right;
    if (e->operation == ast_operator::OPERATOR_B_OR)
      return left | right;
    if (e->operation == ast_operator::OPERATOR_B_AND)
      return left & right;

    eval_error = true;
    error_str = ast_expression_tostring(e);
    return 0;
  } else if (e->type == ast_expression_type::CONDITIONAL_EXPRESSION) {
    double left = _eval(e->left, param_defs);
    double right = _eval(e->right, param_defs);
    double cond = _eval(e->aux, param_defs);
    return cond ? left : right;
  }

  eval_error = true;
  error_str = ast_expression_tostring(e);
  return 0;
}

double VerilogConstantExprEval::Eval(ast_expression* _s) {
  if (eval_error) {
    ILA_ERROR << "unable to parse: `" << error_str << "` in the background";
    return 0; // error value
  }

  double val = _eval(_s, current_module_param_defs);
  if (eval_error) {
    ILA_ERROR << "unable to parse: " << error_str;
    eval_error = false; // this is not the backgound error
    return 0;           // error value
  }
  return val;
}

/// parse only the current module's parameter definitions, will update
/// param_defs
void VerilogConstantExprEval::ParseCurrentModuleParameters(
    ast_module_declaration* m,
    const named_parameter_dict_t& named_parameter_override,
    const ordered_parameter_dict_t& ordered_parameter_override,
    named_parameter_dict_t& output_parameter_dict) {
  // you cannot have ordered parameter and named parameter at the same time
  ILA_ASSERT(named_parameter_override.empty() ||
             ordered_parameter_override.empty());

  if (m == NULL)
    return;
  ast_list* params = m->module_parameters;
  if (params == NULL)
    return;
  ILA_DLOG("vlg_cnst_parser")
      << "For each param in ParseCurrentModuleParameters "
      << _ast_identifier_tostring(m->identifier) << std::endl;
  for (unsigned pi = 0; pi < params->items; ++pi) {

    ILA_DLOG("vlg_cnst_parser") << "  For param " << pi << std::endl;
    ast_parameter_declarations* param_item =
        (ast_parameter_declarations*)ast_list_get_not_null(params, pi);
    // ILA_ASSERT(param_item->type == MOD_ITEM_PARAMETER_DECLARATION)
    //  << "Verilog parser bug: wrong type in param item";
    // ILA_NOT_NULL(param_item->parameter_declaration);
    ast_list* assigns = param_item->assignments;
    ILA_NOT_NULL(assigns);
    ILA_ASSERT(assigns->items > 0);

    ILA_DLOG("vlg_cnst_parser")
        << "  # assignment = " << assigns->items << std::endl;
    for (unsigned assignidx = 0; assignidx < assigns->items; ++assignidx) {
      ast_single_assignment* asn =
          (ast_single_assignment*)ast_list_get_not_null(assigns, assignidx);

      ILA_DLOG("vlg_cnst_parser")
          << "    for assignment #" << assignidx << std::endl;
      auto param_name = _ast_identifier_tostring(asn->lval->data.identifier);

      double val;
      if (pi < ordered_parameter_override.size())
        val = ordered_parameter_override[pi];
      else if (IN(param_name, named_parameter_override))
        val = (named_parameter_override.find(param_name))->second;
      else
        val = _eval(asn->expression, output_parameter_dict);
      if (eval_error) {
        eval_error = false;
        ILA_WARN << "ParseCurrentModuleParameters has error for : " << error_str
                 << std::endl;
        continue; // if we encounter error, just skip it
      }

      ILA_DLOG("vlg_cnst_parser") << "  Done assignment" << std::endl;
      output_parameter_dict.insert(std::make_pair(param_name, val));
    }
  }

  ILA_DLOG("vlg_cnst_parser")
      << "  Done ParseCurrentModuleParameters" << std::endl;
  return;
}

/// parse a hierarchy
void VerilogConstantExprEval::PopulateParameterDefByHierarchy(
    const param_def_hierarchy& hier, ast_module_declaration* current_module) {
  named_parameter_dict_t prev_named_param_defs;
  ordered_parameter_dict_t prev_ordered_param_defs;
  // start from top module
  unsigned hier_idx = 0;
  for (auto&& item : hier) {
    auto& module_ptr = item.first;
    auto& instance_ptr = item.second;
    if (instance_ptr->module_parameters == NULL ||
        instance_ptr->module_parameters->module_parameter == NULL) {
      prev_named_param_defs.clear();
      prev_ordered_param_defs.clear();
      hier_idx++;
      continue; // no override to the next level, we do not need to evaluate the
                // current level's parameter
    }
    named_parameter_dict_t current_module_param_defs;
    ParseCurrentModuleParameters(module_ptr, prev_named_param_defs,
                                 prev_ordered_param_defs,
                                 current_module_param_defs);
    // parse the instantiation parameter override part
    prev_named_param_defs.clear();
    prev_ordered_param_defs.clear();

    if (instance_ptr->module_parameters->type == ORDERED_PARAMETER) {
      for (unsigned param_ov_idx = 0;
           param_ov_idx <
           instance_ptr->module_parameters->module_parameter->items;
           ++param_ov_idx) {
        ILA_DLOG("vlg_cnst_parser")
            << "Hier " << hier_idx << " ast_list_get_not_null ORDERED"
            << std::endl;
        ast_expression* expr = (ast_expression*)ast_list_get_not_null(
            instance_ptr->module_parameters->module_parameter, param_ov_idx);
        double val = _eval(expr, current_module_param_defs);
        if (eval_error)
          return;
        prev_ordered_param_defs.push_back(val);
      }      // for param ovs
    } else { // instance_ptr->module_parameters->type == NAMED_PARAMETER
      for (unsigned param_ov_idx = 0;
           param_ov_idx <
           instance_ptr->module_parameters->module_parameter->items;
           ++param_ov_idx) {
        ILA_DLOG("vlg_cnst_parser")
            << "Hier " << hier_idx << " ast_list_get_not_null NAMED"
            << std::endl;
        ast_port_connection* name_val_pair =
            (ast_port_connection*)ast_list_get_not_null(
                instance_ptr->module_parameters->module_parameter,
                param_ov_idx);
        ILA_NOT_NULL(name_val_pair->port_name);
        auto param_name = _ast_identifier_tostring(name_val_pair->port_name);
        double val =
            _eval(name_val_pair->expression, current_module_param_defs);
        if (eval_error)
          return;
        prev_named_param_defs.insert(std::make_pair(param_name, val));
      } // for param defs
    }   // for ordered/named override
    hier_idx++;
  } // for each module->inst in the hierarchy
  ParseCurrentModuleParameters(current_module, prev_named_param_defs,
                               prev_ordered_param_defs,
                               current_module_param_defs);
}

bool VerilogConstantExprEval::error() const { return eval_error; }

}; // namespace ilang
