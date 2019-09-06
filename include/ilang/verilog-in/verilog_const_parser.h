/// \file
/// Header for evaluate constant width
// -- Hongce Zhang (hongcez@princeton.edu)

#ifndef ILANG_VERILOG_IN_VERILOG_CONST_PARSER_H__
#define ILANG_VERILOG_IN_VERILOG_CONST_PARSER_H__

#include <map>
#include <string>
#include <vector>

extern "C" {
#include <verilogparser/verilog_ast.h>
}

/// \namespace ilang
namespace ilang {

/// \brief The class to convert a constant expr
/// to an integer number
class VerilogConstantExprEval {
public:
  // --------------------- Type Definitions ---------------------------- //
  /// An item in the hierarchy
  typedef std::pair<ast_module_declaration*, ast_module_instantiation*>
      param_hier_item_t;
  /// The hierarchy
  typedef std::vector<param_hier_item_t> param_def_hierarchy;
  /// named parameter dictionary
  typedef std::map<std::string, double> named_parameter_dict_t;
  /// ordered paramater dictionary
  typedef std::vector<double> ordered_parameter_dict_t;

protected:
  /// record if there was an error in eval
  bool eval_error;
  /// record the errorneous part:
  std::string error_str;
  /// to record the variable binding in the current module
  named_parameter_dict_t current_module_param_defs;
  ///
  // --------------------- HELPER FUNC ---------------------------- //
  double virtual _eval(ast_expression* e,
                       const named_parameter_dict_t& param_defs);
  /// parse only the current module's parameter definitions, will update
  /// param_defs
  void ParseCurrentModuleParameters(
      ast_module_declaration* m,
      const named_parameter_dict_t& named_parameter_override,
      const ordered_parameter_dict_t& ordered_parameter_override,
      named_parameter_dict_t& output_parameter_dict);

public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  /// input : the string to evaluate
  VerilogConstantExprEval();
  /// parse a hierarchy
  void PopulateParameterDefByHierarchy(const param_def_hierarchy& hier,
                                       ast_module_declaration* current_module);
  /// Get the value
  double Eval(ast_expression* _s);
  /// Get parsing error
  bool error() const;
}; // class VerilogConstantExprEval

}; // namespace ilang

#endif // ILANG_VERILOG_IN_VERILOG_CONST_PARSER_H__
