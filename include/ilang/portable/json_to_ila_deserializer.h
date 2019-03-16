/// \file
/// JSON to ILA deserializer.

#ifndef ILANG_PORTABLE_J2I_DES_H__
#define ILANG_PORTABLE_J2I_DES_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <memory>
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <unordered_set>

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
  /// \brief Deserialize Expr from JSON.
  ExprPtr DesExpr(const json& j_expr, const InstrLvlAbsPtr& i_host);
  /// \brief Deserialize Instr from JSON.
  InstrPtr DesInstr(const json& j_instr, const InstrLvlAbsPtr& i_host) const;
  /// \brief Deserialize InstrLvlAbs from JSON.
  InstrLvlAbsPtr DesInstrLvlAbs(const json& j_ila);
#if 0
  /// \brief Deserialize top level (parent only) InstrLvlAbs from JSON.
  InstrLvlAbsPtr DesInstrLvlAbsTop(const json& j_ila);
#endif

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// A mapping from id to expressions.
  std::unordered_map<size_t, ExprPtr> id_expr_map_;
#if 0
  /// The set of state variables.
  std::unordered_set<size_t> state_id_set_;
  /// The set of input variables.
  std::unordered_set<size_t> input_id_set_;
#endif
  /// The mapping from ila name to pointer.
  std::unordered_map<std::string, const InstrLvlAbsPtr> ila_name_ptr_map_;

  // ------------------------- METHODS -------------------------------------- //
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

  void DesVarHier(const json& j_ila, const json& j_ast_list,
                  const InstrLvlAbsPtr& i_parent);

  void DesIlaHier(const json& j_ila);

  void DesIlaUnit(const json& j_ila);

}; // class J2IDes

/// Pointer type for normal use of J2IDes.
typedef J2IDes::J2IDesPtr J2IDesPtr;

}; // namespace ilang

#endif // ILANG_PORTABLE_J2i_DES_H__
