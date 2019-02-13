/// \file
/// ILA to JSON serializer.

#ifndef ILANG_PORTABLE_I2J_SER_H__
#define ILANG_PORTABLE_I2J_SER_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <memory>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/// \namespace ilang
namespace ilang {

/// \brief The class for serialize an ILA model to JSON format.
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
  /// \brief Serialize InstrLvlAbs to JSON.
  json SerInstrLvlAbs(const InstrLvlAbsPtr& i_ila) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The set of all expressions.
  std::vector<int> arr_; // XXX

}; // class I2JSer

}; // namespace ilang

#endif // ILANG_PORTABLE_I2J_SER_H__
