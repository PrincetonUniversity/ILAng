/// \file
/// Class J2IDes - JSON to ILA deserializer.

#ifndef ILANG_TARGET_JSON_J2I_DES_H__
#define ILANG_TARGET_JSON_J2I_DES_H__

#include <memory>
#include <unordered_map>

#include <nlohmann/json.hpp>

#include <ilang/ila/instr_lvl_abs.h>

using json = nlohmann::json;

/// \namespace ilang
namespace ilang {

/// \brief The class for deserializing an ILA model from JSON format.
class J2IDes {
public:
  /// Pointer type for normal use of J2IDes.
  typedef std::shared_ptr<J2IDes> J2IDesPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  J2IDes();
  /// Default destructor.
  ~J2IDes();

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new J2IDes. Used for hiding implementation specific type
  /// details.
  static J2IDesPtr New();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Deserialize InstrLvlAbs from JSON.
  InstrLvlAbsPtr DesInstrLvlAbs(const json& j_global);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// A mapping from id to expression.
  std::unordered_map<size_t, ExprPtr> id_expr_map_;
  /// A mapping from id to function.
  std::unordered_map<size_t, FuncPtr> id_func_map_;
  /// The mapping from ila name to pointer.
  std::unordered_map<std::string, const InstrLvlAbsPtr> ila_name_ptr_map_;

  // ------------------------- METHODS -------------------------------------- //
  /// Deserialize Sort from JSON.
  SortPtr DesSort(const json& j_sort);

  /// Deserialize Func from JSON.
  FuncPtr DesFunc(const json& j_func);

  /// Deserialize Expr from JSON.
  ExprPtr DesExpr(const json& j_expr);
  /// Deserialize ExprVar into state from JSON.
  ExprPtr DesExprState(const json& j_sort, const std::string& name,
                       const InstrLvlAbsPtr& i_host) const;
  /// Deserialize ExprVar into input from JSON.
  ExprPtr DesExprInput(const json& j_sort, const std::string& name,
                       const InstrLvlAbsPtr& i_host) const;
  /// Deserialize ExprConstant from JSON.
  ExprPtr DesExprConst(const json& j_sort, const json& j_val) const;
  /// Deserialize ExprOp from JSON.
  ExprPtr DesExprOp(const unsigned& ast_expr_op_uid, const json& j_arg_arr,
                    const json& j_param_arr) const;
  /// Deserialize ExprOpAppFunc from JSON.
  ExprPtr DesExprOpAppFunc(const json& j_func_id, const json& j_arg_arr) const;

  /// Deserialize state/input variables. Note: the ILA model will be
  /// constructed on-the-fly.
  void DesVarUnit(const json& j_ila, const json& j_ast_list,
                  const InstrLvlAbsPtr& i_parent);
  /// Deserialize state/input variables hierarchically. Note: ILA model will be
  /// constructed on-the-fly.
  void DesVarHier(const json& j_ila, const json& j_ast_list,
                  const InstrLvlAbsPtr& i_parent);

  /// \brief Deserialize Instr from JSON.
  InstrPtr DesInstr(const json& j_instr, const InstrLvlAbsPtr& i_host) const;

  /// Deserialize ILA info, e.g., fetch, valid, instructions, etc.
  void DesIlaUnit(const json& j_ila);
  /// Deserialize ILA info hierarchically.
  void DesIlaHier(const json& j_ila);

}; // class J2IDes

/// Pointer type for normal use of J2IDes.
typedef J2IDes::J2IDesPtr J2IDesPtr;

} // namespace ilang

#endif // ILANG_TARGET_JSON_J2I_DES_H__
