/// \file
/// The header for the c++ API.

#ifndef ILAPP_H__
#define ILAPP_H__

#include <map>
#include <memory>

/// \namespace ila
namespace ila {

class Expr;
class Instr;
class InstrLvlAbs;

/// \brief The wrapper of Expr (e.g. state var, var relation, constant, etc).
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
  /****************************************************************************/
  // Unary operation
  /****************************************************************************/
  /// Arithmetic negate for bit-vectors.
  ExprRef operator-() const;
  /// Logical not for Booleans.
  ExprRef operator!() const;
  /// Bit-wise complement for bit-vectors.
  ExprRef operator~() const;

  /****************************************************************************/
  // Binary operation
  /****************************************************************************/
  /// Logical AND (bit-wise for bit-vectors).
  ExprRef operator&(const ExprRef& rhs) const;
  /// Logical OR (bit-wise for bit-vectors).
  ExprRef operator|(const ExprRef& rhs) const;
  /// Logical XOR (bit-wise for bit-vectors).
  ExprRef operator^(const ExprRef& rhs) const;
  /// Unsigned addition for bit-vector.
  ExprRef operator+(const ExprRef& rhs) const;
  /// Unsigned subtraction for bit-vector.
  ExprRef operator-(const ExprRef& rhs) const;
  // TODO int helper functions

  /****************************************************************************/
  // Binary comparison
  /****************************************************************************/
  /// Equal.
  ExprRef operator==(const ExprRef& rhs) const;
  /// Not equal.
  ExprRef operator!=(const ExprRef& rhs) const;
  /// Unsigned less than (bit-vectors only).
  ExprRef operator<(const ExprRef& rhs) const;
  /// Unsigned greater than (bit-vectors only).
  ExprRef operator>(const ExprRef& rhs) const;
  /// Unsigned less than or equal to (bit-vectors only).
  ExprRef operator<=(const ExprRef& rhs) const;
  /// Unsigned greater than or equal to (bit-vectors only).
  ExprRef operator>=(const ExprRef& rhs) const;

  /****************************************************************************/
  // Memory-related operations
  /****************************************************************************/
  /// Load from memory.
  ExprRef Load(const ExprRef& addr) const;
  /// Store to memory.
  ExprRef Store(const ExprRef& addr, const ExprRef& data) const;

  /****************************************************************************/
  // Bit manipulation for bit-vectors.
  /****************************************************************************/
  // Append another bit-vector to the less significant side.
  ExprRef Append(const ExprRef& lsbv) const;
  /// Extract bit-field in the bit-vector.
  ExprRef operator()(const int& hi, const int& lo) const;
  /// Zero-extend the bit-vector to the specified length.

}; // class ExprRef

/******************************************************************************/
// Others
/******************************************************************************/
/// \brief Concatenate two bit-vectors.
/// \param[in] msb bit-vector on the more-significant side.
/// \param[in] lsb bit-vector on the less-significant side.
ExprRef Concat(const ExprRef& msbv, const ExprRef& lsbv);

/// \brief Logical imply for Booleans.
/// \param[in] ante antecedent for the operator.
/// \param[in] cons consequent for the operator.
ExprRef Imply(const ExprRef& ante, const ExprRef& cons);

/// \brief If-then-else on the Boolean condition.
/// \param[in] cond Boolean type condition.
/// \param[in] t Expression to take when the condition is true.
/// \param[in] f Expression to take when the condition is false.
ExprRef Ite(const ExprRef& cond, const ExprRef& t, const ExprRef& f);

/******************************************************************************/
// Constant
/******************************************************************************/
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

/// \brief The wrapper of Instr (instruction).
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

/// \brief The wrapper of InstrLvlAbs (ILA).
class Ila {
private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Wrapped InstrLvlAbs pointer.
  std::shared_ptr<InstrLvlAbs> ptr_;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with the specified name.
  Ila(const std::string& name);
  /// Constructor with the pointer of the actual data.
  Ila(std::shared_ptr<InstrLvlAbs> ptr);
  /// Default destructor
  ~Ila();

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

  /// \brief Add one initial constraint.
  /// \param[in] init the Boolean type initial constraint.
  void AddInit(const ExprRef& init);

  /// \brief Set the fetch function of the ILA.
  /// \param[in] fetch the bit-vector type fetch function.
  void SetFetch(const ExprRef& fetch);

  /// \brief Set the valid function of the ILA.
  /// \param[in] valid the Boolean type valid function.
  void SetValid(const ExprRef& valid);

  /// \brief Declare an instruction.
  /// \param[in] name instruction name.
  InstrRef NewInstr(const std::string& name);

  /// \brief Declare a child-ILA.
  /// \param[in] name child-ILA name.
  Ila NewChild(const std::string& name);

}; // class Ila

/******************************************************************************/
// Logging system.
/******************************************************************************/
/// \brief Set the minimun log level.
/// Log messages at or above this level will be logged. (Default: 0)
/// - INFO: level 0
/// - WARNING: level 1
/// - ERROR: level 2
/// - FATAL: level 3
void LogLevel(const int& lvl);
/// \brief Set the path for log file.
/// If specified, logfiles are written into this directory instead of the
/// default logging directory (/tmp).
void LogPath(const std::string& path);
/// \brief Pipe log to stderr.
/// Log messages to stderr instead of logfiles, if set to 1.
void LogToErr(bool to_err);
/// Add a debug tag.
void EnableDebug(const std::string& tag);
/// Remove a debug tag.
void DisableDebug(const std::string& tag);

} // namespace ila

#endif // ILAPP_H__

