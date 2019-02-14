/// \file
/// ILA to JSON serializer.

#ifndef ILANG_PORTABLE_I2J_SER_H__
#define ILANG_PORTABLE_I2J_SER_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <memory>
#include <nlohmann/json.hpp>
#include <unorderd_map>
#include <vector>

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
  /// \brief Serialize Sort to JSON.
  json SerSort(const SortPtr& i_sort) const;
  /// \brief Serialize Expr to JSON.
  json SerExpr(const ExprPtr& i_expr) const;
  /// \brief Serialize Instr to JSON.
  json SerInstr(const InstrPtr& i_instr) const;
  /// \brief Serialize InstrLvlAbs to JSON.
  json SerInstrLvlAbs(const InstrLvlAbsPtr& i_ila) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// A map from visited i_expr id to j_expr array index.
  std::unordered_map<size_t, size_t> id_idx_map_;
  /// The list of all serialized expressions (j_expr array).
  json::array j_expr_arr_;

}; // class I2JSer

}; // namespace ilang

#endif // ILANG_PORTABLE_I2J_SER_H__
