/// \file
/// The header for the c++ API.

#ifndef __ILAPP_H__
#define __ILAPP_H__

#include <map>
#include <memory>

/// \namespace ila
namespace ila {

class Expr;
class Instr;
class InstrLvlAbs;

/// \brief The reference of Expr (e.g. state var, var relation, constant, etc).
class ExprRef {
private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Wrapped Expr pointer.
  std::shared_ptr<Expr> ptr_;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with the pointer of the actual data.
  ExprRef(std::shared_ptr<Expr> ptr);
  /// Default destructor
  ~ExprRef();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the wrapped Expr pointer.
  inline std::shared_ptr<Expr> get() const { return ptr_; }

  // ------------------------- METHODS -------------------------------------- //
  /// Arithmetic negate for bit-vector.
  ExprRef operator-() const;
  /// Unsigned add for bit-vector.
  ExprRef operator+(const ExprRef& rhs) const;

}; // class NodeRef

/// \brief Return a Boolean constant.
/// \param[in] bool_val value of the Boolean constant.
ExprRef BoolConst(bool bool_val);

/// \brief Return a bit-vector constant.
/// \param[in] bv_val value of the bit-vector constant.
/// \param[in] bit_width data bit-width.
ExprRef BvConst(const int& bv_val, const int& bit_width);

/// \brief Return a memory constant.
/// \param[in] def_val default value.
/// \param[in] vals non-default address-data mapping.
/// \param[in] addr_width address bit-width.
/// \param[in] data_width data bit-width.
ExprRef MemConst(const int& def_val, const std::map<int, int>& vals,
                 const int& addr_width, const int& data_width);

class InstrRef {
private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Wrapped Instr pointer.
  std::shared_ptr<Instr> ptr_;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with the pointer of the actual data.
  InstrRef(std::shared_ptr<Instr> ptr);
  /// Default destructor
  ~InstrRef();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Set the decode function of the instruction.
  /// \param[in] decode the Boolean typed decode function.
  void SetDecode(const ExprRef& decode);

  /// \brief Set the update function of the given state variable.
  /// \param[in] state the state variable to set.
  /// \param[in] update the update function (should be the same type as state).
  void SetUpdate(const ExprRef& state, const ExprRef& update);

}; // class InstrRef

} // namespace ila

#endif // __ILAPP_H__

