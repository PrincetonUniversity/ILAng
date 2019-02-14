/// \file
/// JSON to ILA deserializer.

#ifndef ILANG_PORTABLE_J2I_DES_H__
#define ILANG_PORTABLE_J2I_DES_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <memory>
#include <nlohmann/json.hpp>
#include <unordered_map>

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
  /// \brief Deserialize Sort from JSON.
  SortPtr DesSort(const json& j_sort) const;
  /// \brief Deserialize Expr from JSON.
  ExprPtr DesExpr(const json& j_expr);
  /// \brief Deserialize Instr from JSON.
  InstrPtr DesInstr(const json& j_instr) const;
  /// \brief Deserialize InstrLvlAbs from JSON.
  InstrLvlAbsPtr DesInstrLvlAbs(const json& j_ila);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// A mapping from id to expressions.
  std::unordered_map<size_t, ExprPtr> id_expr_map_;

}; // class J2IDes

/// Pointer type for normal use of J2IDes.
typedef J2IDes::J2IDesPtr J2IDesPtr;

}; // namespace ilang

#endif // ILANG_PORTABLE_J2i_DES_H__
