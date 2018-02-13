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

/// \brief The reference of Instr (instruction).
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

/// \brief The reference of InstrLvlAbs (ILA).
class IlaRef {
private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Wrapped InstrLvlAbs pointer.
  std::shared_ptr<InstrLvlAbs> ptr_;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with the specified name.
  IlaRef(const std::string& name);
  /// Constructor with the pointer of the actual data.
  IlaRef(std::shared_ptr<InstrLvlAbs> ptr);
  /// Default destructor
  ~IlaRef();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Declare a state variable of Boolean type.
  /// \param[in] name state variable name.
  ExprRef NewBoolState(const std::string& name);
  /// \brief Declare a state variable of bit-vector type.
  /// \param[in] name state variable name.
  /// \param[in] bit_width bit-vector bit-width.
  ExprRef NewBvState(const std::string& name, const int& bit_width);
  /// \brief Declare a state variable of memory (array) type.
  /// \param[in] name state variable name.
  /// \param[in] addr_width address bit-width.
  /// \param[in] data_width data bit-width.
  ExprRef NewMemState(const std::string& name, const int& addr_width,
                      const int& data_width);
  /// \brief Declare an input of Boolean type.
  /// \param[in] name input name.
  ExprRef NewBoolInput(const std::string& name);
  /// \brief Declare an input of bit-vector type.
  /// \param[in] name input name.
  /// \param[in] bit_width bit-vector bit-width.
  ExprRef NewBvInput(const std::string& name, const int& bit_width);

  /// \brief Set the fetch function of the ILA.
  /// \param[in] fetch the bit-vector type fetch function.
  void SetFetch(const ExprRef& fetch);

}; // class IlaRef

} // namespace ila

#endif // __ILAPP_H__

