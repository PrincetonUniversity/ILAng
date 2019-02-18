/// \file
/// ILA to JSON serializer.

#ifndef ILANG_PORTABLE_I2J_SER_H__
#define ILANG_PORTABLE_I2J_SER_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <memory>
#include <nlohmann/json.hpp>
#include <unordered_map>

using json = nlohmann::json;

/// \namespace ilang
namespace ilang {

/// \brief The class for serializing an ILA model to JSON format.
class I2JSer {
public:
  /// Pointer type for normal use of I2JSer.
  typedef std::shared_ptr<I2JSer> I2JSerPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  I2JSer();
  /// Default destructor.
  ~I2JSer();

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new I2JSer. Used for hiding implementation specific type
  /// details.
  static I2JSerPtr New();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Serialize Expr to JSON (and all its sub-expressions).
  json SerExpr(const ExprPtr& i_expr);
  /// \brief Serialize Instr to JSON.
  json SerInstr(const InstrPtr& i_instr);
  /// \brief Serialize InstrLvlAbs to JSON.
  json SerInstrLvlAbs(const InstrLvlAbsPtr& i_ila);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// A map from visited i_expr id to j_expr array index.
  std::unordered_map<size_t, size_t> id_idx_map_;
  /// The list of all serialized expressions (j_expr array).
  json j_expr_arr_;

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Serialize Sort to JSON.
  json SerSort(const SortPtr& i_sort) const;
  /// Serialize constant value to JSON.
  json SerConstVal(const ExprPtr& i_expr) const;
  /// Serialize one single Expr.
  json SerExprUnit(const ExprPtr& i_expr);

}; // class I2JSer

/// Pointer type for normal use of I2JSer.
typedef I2JSer::I2JSerPtr I2JSerPtr;

}; // namespace ilang

#endif // ILANG_PORTABLE_I2J_SER_H__
