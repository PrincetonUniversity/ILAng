/// \file
/// JSON to ILA deserializer.

#ifndef ILANG_PORTABLE_J2I_DES_H__
#define ILANG_PORTABLE_J2I_DES_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <map>
#include <memory>
#include <nlohmann/json.hpp>

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
  ExprPtr DesExpr(const json& j_expr) const;
  /// \brief Deserialize Instr from JSON.
  InstrPtr DesInstr(const json& j_instr) const;
  /// \brief Deserialize InstrLvlAbs from JSON.
  InstrLvlAbsPtr DesInstrLvlAbs(const json& j_ila) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// A mapping from id to expressions.
  std::map<unsigned, ExprPtr> i_expr_map_; // XXX unordered_map

}; // class J2IDes

}; // namespace ilang

#endif // ILANG_PORTABLE_J2i_DES_H__
