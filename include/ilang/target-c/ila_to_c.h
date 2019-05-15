/// \file
/// ILA to C target generator..

#ifndef ILANG_TARGET_C_ILA_TO_C_H__
#define ILANG_TARGET_C_ILA_TO_C_H__

#include <memory>
#include <unordered_map>

#include <ilang/ila/instr_lvl_abs.h>

/// \namespace ilang
namespace ilang {

/// \brief The calss for converting an ILA model to a C target.
class I2CMngr {
public:
  /// Pointer type for normal use of I2CMngr.
  typedef std::shared_ptr<I2CMngr> I2CMngrPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  I2CMngr();
  /// Default destructor.
  ~I2CMngr();

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new I2CMngr. Used for hiding implementation specific type
  /// details.
  static I2CMngrPtr New();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Generate a C target of the given ILA model.
  /// \param[in] ila The top-level ILA model to generate the C target for.
  /// \param[out] C intermediate representation.
  void GenerateCTarget(const InstrLvlAbsPtr& ila);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// A map from visited i_expr id to c_var array index.
  std::unordered_map<size_t, size_t> id_var_map_;

  // ------------------------- METHODS -------------------------------------- //
  /// Convert constant node to c contant.
  void ConvertConst(const ExprPtr& expr) const;

}; // class I2CMngr

/// Pointer type for normal use of I2CMngr.
typedef I2CMngr::I2CMngrPtr I2CMngrPtr;

}; // namespace ilang

#endif // ILANG_TARGET_C_ILA_TO_C_H__
