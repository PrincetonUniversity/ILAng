/// \file
/// The header for the c++ API.

#ifndef ILANG_ILANG_CPP_H__
#define ILANG_ILANG_CPP_H__

#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <variant>

#include <z3++.h>
#ifdef SMTSWITCH_INTERFACE
#include <smt-switch/smt.h>
#endif // SMTSWITCH_INTERFACE

#include <ilang/config.h>

/// \namespace ilang
/// Defines the core data structure and APIs for constructing and storing ILA.
namespace ilang {

/// Data type for numerics. NOTE: SHOULD BE SYNCED WITH BvValType!!
typedef uint64_t NumericType;

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

/******************************************************************************/
// ILA Construction.
/******************************************************************************/
// implementation-specific structure
class Sort;
class Func;
class Expr;
class Instr;
class InstrLvlAbs;
class Unroller;
namespace pfast { class ProgramFragment; }
class PFToCHCEncoder;

// forward declaration
class Ila;

/// \brief The wrapper of Sort (type for different AST nodes).
class SortRef {
private:
  typedef std::shared_ptr<Sort> SortPtr;
  // ------------------------- MEMBERS -------------------------------------- //
  /// Wrapped Sort pointer.
  SortPtr ptr_ = nullptr;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with the pointer of the actual data.
  SortRef(SortPtr ptr);
  /// Default destructor.
  ~SortRef();

  // ------------------------- HELPERS -------------------------------------- //
  /// Return a Boolean Sort.
  static SortRef BOOL();
  /// Return a bit-vector Sort of the given bit-width.
  static SortRef BV(const int& bit_w);
  /// Return a memory (array) Sort of the given address/data bit-width.
  static SortRef MEM(const int& addr_w, const int& data_w);

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the wrapped Sort pointer.
  inline SortPtr get() const { return ptr_; }
}; // class SortRef

/// \brief The wrapper of Expr (e.g. state var, var relation, constant, etc).
class ExprRef {
private:
  typedef std::shared_ptr<Expr> ExprPtr;
  // ------------------------- MEMBERS -------------------------------------- //
  /// Wrapped Expr pointer.
  ExprPtr ptr_ = nullptr;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with the pointer of the actual data.
  ExprRef(ExprPtr ptr);
  /// Default destructor
  ~ExprRef();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the wrapped Expr pointer.
  inline ExprPtr get() const { return ptr_; }
  /// Return the bit-width if is bit-vector; return -1 otherwise.
  int bit_width() const;
  /// Return the address bit-width if is memory; return -1 otherwise.
  int addr_width() const;
  /// Return the data bit-width if is memory; return -1 otherwise.
  int data_width() const;
  /// Return the expression name as std::string.
  std::string name() const;

  // ------------------------- METHODS -------------------------------------- //
  /****************************************************************************/
  // Memory-related operations
  /****************************************************************************/
  /// Load from memory.
  ExprRef Load(const ExprRef& addr) const;
  /// Store to memory.
  ExprRef Store(const ExprRef& addr, const ExprRef& data) const;
  /// Load from memory with constant address.
  ExprRef Load(const NumericType& addr) const;
  /// Store to memory with constant address and data.
  ExprRef Store(const NumericType& addr, const NumericType& data) const;

  /****************************************************************************/
  // Bit manipulation for bit-vectors.
  /****************************************************************************/
  /// Append another bit-vector to the less significant side.
  ExprRef Append(const ExprRef& lsbv) const;
  /// Extract bit-field in the bit-vector.
  ExprRef operator()(const int& hi, const int& lo) const;
  /// Extract single-bit in the bit-vector.
  ExprRef operator()(const int& idx) const;
  /// Zero-extend the bit-vector to the specified length.
  ExprRef ZExt(const int& length) const;
  /// Sign-extend the bit-vector to the specified length.
  ExprRef SExt(const int& length) const;

  /****************************************************************************/
  // Others
  /****************************************************************************/
  /// \brief Replace the i-th argument with the new node.
  void ReplaceArg(const int& i, const ExprRef& new_arg);
  /// \brief Replace the original argument (must exist) with the new argument.
  void ReplaceArg(const ExprRef& org_arg, const ExprRef& new_arg);

  /// \brief Set the entry number of the memory (size regardless of bit-width).
  bool SetEntryNum(const int& num);
  /// \brief GEt the entry number of the memory (size regardless of bit-width).
  int GetEntryNum();

}; // class ExprRef

/******************************************************************************/
// Unary operation
/******************************************************************************/
/// Arithmetic negate for bit-vectors.
ExprRef operator-(const ExprRef& a);
/// Logical not for Booleans.
ExprRef operator!(const ExprRef& a);
/// Bit-wise complement for bit-vectors.
ExprRef operator~(const ExprRef& a);

/******************************************************************************/
// Binary operation
/******************************************************************************/
/// Logical AND (bit-wise for bit-vectors).
ExprRef operator&(const ExprRef& a, const ExprRef& b);
/// Logical OR (bit-wise for bit-vectors).
ExprRef operator|(const ExprRef& a, const ExprRef& b);
/// Logical XOR (bit-wise for bit-vectors).
ExprRef operator^(const ExprRef& a, const ExprRef& b);
/// Left shift for bit-vectors.
ExprRef operator<<(const ExprRef& a, const ExprRef& b);
/// Arithmetic right shift for bit-vectors.
ExprRef operator>>(const ExprRef& a, const ExprRef& b);
/// Logical right shift for bit-vectors.
ExprRef Lshr(const ExprRef& a, const ExprRef& b);
/// Unsigned addition for bit-vectors.
ExprRef operator+(const ExprRef& a, const ExprRef& b);
/// Unsigned subtraction for bit-vectors.
ExprRef operator-(const ExprRef& a, const ExprRef& b);
/// Unsigned multiply for bit-vectors.
ExprRef operator*(const ExprRef& a, const ExprRef& b);
/// Unsigned division for bit-vectors.
ExprRef operator/(const ExprRef& a, const ExprRef& b);

/// Logical AND with Boolean constant.
ExprRef operator&(const ExprRef& a, const bool& b);
/// Logical OR with Boolean constant.
ExprRef operator|(const ExprRef& a, const bool& b);
/// Logical XOR with Boolean constant.
ExprRef operator^(const ExprRef& a, const bool& b);
/// Left shift with int constant.
ExprRef operator<<(const ExprRef& a, const int& b);
/// Arithmetic right shift with int constant.
ExprRef operator>>(const ExprRef& a, const int& b);
/// Logical right shift with int constant.
ExprRef Lshr(const ExprRef& a, const int& b);
/// Unsigned addition with constant.
ExprRef operator+(const ExprRef& a, const NumericType& b);
/// Unsigned subtraction with constant.
ExprRef operator-(const ExprRef& a, const NumericType& b);
/// Unsigned multiply with constant.
ExprRef operator*(const ExprRef& a, const NumericType& b);
/// Arithmetic signed remainder.
ExprRef SRem(const ExprRef& a, const ExprRef& b);
/// Arithmetic unsigned remainder.
ExprRef URem(const ExprRef& a, const ExprRef& b);
/// Arithmetic signed modular.
ExprRef SMod(const ExprRef& a, const ExprRef& b);

/******************************************************************************/
// Binary comparison
/******************************************************************************/
/// Set the default behavior of operator <, <=, > and >=, by default, signed
/// compare
void SetUnsignedComparison(bool sign);
/// Equal.
ExprRef operator==(const ExprRef& a, const ExprRef& b);
/// Not equal.
ExprRef operator!=(const ExprRef& a, const ExprRef& b);
/// Signed/Unsigned less than (bit-vectors only).
ExprRef operator<(const ExprRef& a, const ExprRef& b);
/// Signed/Unsigned greater than (bit-vectors only).
ExprRef operator>(const ExprRef& a, const ExprRef& b);
/// Signed/Unsigned less than or equal to (bit-vectors only).
ExprRef operator<=(const ExprRef& a, const ExprRef& b);
/// Signed/Unsigned greater than or equal to (bit-vectors only).
ExprRef operator>=(const ExprRef& a, const ExprRef& b);
/// Unsigned less than (bit-vectors only).
ExprRef Ult(const ExprRef& a, const ExprRef& b);
/// Unsigned greater than (bit-vectors only).
ExprRef Ugt(const ExprRef& a, const ExprRef& b);
/// Unsigned less than or equal to (bit-vectors only).
ExprRef Ule(const ExprRef& a, const ExprRef& b);
/// Unsigned greater than or equal to (bit-vectors only).
ExprRef Uge(const ExprRef& a, const ExprRef& b);
/// Signed less than (bit-vectors only).
ExprRef Slt(const ExprRef& a, const ExprRef& b);
/// Signed greater than (bit-vectors only).
ExprRef Sgt(const ExprRef& a, const ExprRef& b);
/// Signed less than or equal to (bit-vectors only).
ExprRef Sle(const ExprRef& a, const ExprRef& b);
/// Signed greater than or equal to (bit-vectors only).
ExprRef Sge(const ExprRef& a, const ExprRef& b);

// helper functions with constants
#if 0
/// Equal to Boolean constant.
ExprRef operator==(const ExprRef& a, const bool& b);
#endif
/// Equal to constant.
ExprRef operator==(const ExprRef& a, const NumericType& b);
/// Not equal to constant.
ExprRef operator!=(const ExprRef& a, const NumericType& b);
/// Signed/Unsigned less than constant (bit-vectors only).
ExprRef operator<(const ExprRef& a, const NumericType& b);
/// Signed/Unsigned greater than constant (bit-vectors only).
ExprRef operator>(const ExprRef& a, const NumericType& b);
/// Signed/Unsigned less than or equal to constant (bit-vectors only).
ExprRef operator<=(const ExprRef& a, const NumericType& b);
/// Signed/Unsigned greater than or equal to constant (bit-vectors only).
ExprRef operator>=(const ExprRef& a, const NumericType& b);
/// Unsigned less than constant (bit-vectors only).
ExprRef Ult(const ExprRef& a, const NumericType& b);
/// Unsigned greater than constant (bit-vectors only).
ExprRef Ugt(const ExprRef& a, const NumericType& b);
/// Unsigned less than or equal to constant (bit-vectors only).
ExprRef Ule(const ExprRef& a, const NumericType& b);
/// Unsigned greater than or equal to constant (bit-vectors only).
ExprRef Uge(const ExprRef& a, const NumericType& b);
/// Signed less than constant (bit-vectors only).
ExprRef Slt(const ExprRef& a, const NumericType& b);
/// Signed greater than constant (bit-vectors only).
ExprRef Sgt(const ExprRef& a, const NumericType& b);
/// Signed less than or equal to constant (bit-vectors only).
ExprRef Sle(const ExprRef& a, const NumericType& b);
/// Signed greater than or equal to constant (bit-vectors only).
ExprRef Sge(const ExprRef& a, const NumericType& b);

/******************************************************************************/
// Memory-related operations
/******************************************************************************/
/// Load from memory.
ExprRef Load(const ExprRef& mem, const ExprRef& addr);
/// Store to memory.
ExprRef Store(const ExprRef& mem, const ExprRef& addr, const ExprRef& data);
/// Load from memory with constant address.
ExprRef Load(const ExprRef& mem, const NumericType& addr);
/// Store to memory at constant address and data.
ExprRef Store(const ExprRef& mem, const NumericType& addr,
              const NumericType& data);

/******************************************************************************/
// Bit manipulation for bit-vectors.
/******************************************************************************/
/// \brief Concatenate two bit-vectors.
/// \param[in] msbv bit-vector on the more-significant side.
/// \param[in] lsbv bit-vector on the less-significant side.
ExprRef Concat(const ExprRef& msbv, const ExprRef& lsbv);
/// \brief Extract bit-field in the bit-vector.
/// \param[in] bv source bit-vector.
/// \param[in] hi the index of the most-significant bit.
/// \param[in] lo the index of the least-significant bit.
ExprRef Extract(const ExprRef& bv, const int& hi, const int& lo);
/// \brief Extract single bit in the bit-vector.
/// \param[in] bv source bit-vector.
/// \param[in] idx the index of the selected bit.
ExprRef SelectBit(const ExprRef& bv, const int& idx);
/// \brief Zero-extend the bit-vector to the specified length.
/// \param[in] bv source bit-vector.
/// \param[in] length bit-width of the extended (result) bit-vector.
ExprRef ZExt(const ExprRef& bv, const int& length);
/// \brief Sign-extend the bit-vector to the specified length.
/// \param[in] bv source bit-vector.
/// \param[in] length bit-width of the extended (result) bit-vector.
ExprRef SExt(const ExprRef& bv, const int& length);
/// \brief Left-rotate the bit-vector with immediate number of times.
/// \param[in] bv source bit-vector
/// \param[in] immediate number of times to rotate the bv
ExprRef LRotate(const ExprRef& bv, const int& immediate);
/// \brief Right-rotate the bit-vector with immediate number of times.
/// \param[in] bv source bit-vector
/// \param[in] immediate number of times to rotate the bv
ExprRef RRotate(const ExprRef& bv, const int& immediate);

/******************************************************************************/
// Others
/******************************************************************************/
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
ExprRef BvConst(const NumericType& bv_val, const int& bit_width);

/// \brief Return a memory constant.
/// \param[in] def_val default value.
/// \param[in] vals non-default address-data mapping.
/// \param[in] addr_width address bit-width.
/// \param[in] data_width data bit-width.
ExprRef MemConst(const NumericType& def_val,
                 const std::map<NumericType, NumericType>& vals,
                 const int& addr_width, const int& data_width);

/******************************************************************************/
// Non-AST-construction
/******************************************************************************/
/// \brief Topologically equivalent.
bool TopEqual(const ExprRef& a, const ExprRef& b);

/// \brief The wrapper of Func (uninterpreted function).
class FuncRef {
private:
  typedef std::shared_ptr<Func> FuncPtr;
  // ------------------------- MEMBERS -------------------------------------- //
  /// Wrapped Func pointer.
  FuncPtr ptr_ = nullptr;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with zero input argument (domain).
  FuncRef(const std::string& name, const SortRef& range);
  /// Constructor with one input argument (domain).
  FuncRef(const std::string& name, const SortRef& range, const SortRef& d0);
  /// Constructor with two input arguments (domain).
  FuncRef(const std::string& name, const SortRef& range, const SortRef& d0,
          const SortRef& d1);
  /// Constructor with multiple input arguments (domain).
  FuncRef(const std::string& name, const SortRef& range,
          const std::vector<SortRef>& dvec);
  /// Default destructor.
  ~FuncRef();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the function name as std::string.
  std::string name() const;
  /// Return the wrapped Func pointer.
  inline FuncPtr get() const { return ptr_; }

  // ------------------------- METHODS -------------------------------------- //
  /// Apply the function with no argument.
  ExprRef operator()() const;
  /// Apply the function with one argument.
  ExprRef operator()(const ExprRef& arg0) const;
  /// Apply the function with two arguments.
  ExprRef operator()(const ExprRef& arg0, const ExprRef& arg1) const;
  /// Apply the function with multiple arguments.
  ExprRef operator()(const std::vector<ExprRef>& argvec) const;

}; // class FuncRef

/// \brief The wrapper of Instr (instruction).
class InstrRef {
private:
  typedef std::shared_ptr<Instr> InstrPtr;
  // ------------------------- MEMBERS -------------------------------------- //
  /// Wrapped Instr pointer.
  InstrPtr ptr_ = nullptr;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with the pointer of the actual data.
  InstrRef(InstrPtr ptr);
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

  /// \brief Set the child-program of the instruction.
  /// \param[in] prog the child-ILA representing the child-program.
  void SetProgram(const Ila& prog);

  /// \brief Get the decode function of the instruction.
  /// \return the decode function wrapped in Expression reference.
  ExprRef GetDecode() const;

  /// \brief Set the update function of the given state variable.
  /// \param[in] state the state variable to set.
  /// \return the update function.
  ExprRef GetUpdate(const ExprRef& state) const;

  // ------------------------- GENERATORS --------------------------------- //
  /// \brief Export instruction without child-program as Verilog
  /// \param[in] filename the file name of the generated Verilog source
  void ExportToVerilog(std::ostream& fout) const;

  /// \brief Export instruction with the child-program as Verilog
  /// \param[in] filename the file name of the generated Verilog source
  void ExportToVerilogWithChild(std::ostream& fout) const;

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the wrapped ILA pointer.
  inline InstrPtr get() const { return ptr_; }

  /// Return the instruction name as std::string.
  std::string name() const;

}; // class InstrRef

/// \brief The wrapper of InstrLvlAbs (ILA).
class Ila {
private:
  typedef std::shared_ptr<InstrLvlAbs> IlaPtr;
  // ------------------------- MEMBERS -------------------------------------- //
  /// Wrapped InstrLvlAbs pointer.
  IlaPtr ptr_ = nullptr;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with the specified name.
  Ila(const std::string& name);
  /// Constructor with the pointer of the actual data.
  Ila(IlaPtr ptr);
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

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the number of input variables.
  size_t input_num() const;
  /// Return the number of state variables.
  size_t state_num() const;
  /// Return the number of instructions.
  size_t instr_num() const;
  /// Return the number of child-ILAs.
  size_t child_num() const;
  /// Return the number of initial condition.
  size_t init_num() const;

  /// Return the Ila name.
  std::string name() const;
  /// Return the fetch function.
  ExprRef fetch() const;
  /// Return the valid function.
  ExprRef valid() const;

  /// Access the i-th input variable.
  ExprRef input(const size_t& i) const;
  /// Access the i-th state variable.
  ExprRef state(const size_t& i) const;
  /// Access the i-th instruction.
  InstrRef instr(const size_t& i) const;
  /// Access the i-th child-ILA.
  Ila child(const size_t& i) const;
  /// Access the i-th initial condition.
  ExprRef init(const size_t& i) const;

  /// Return the named input variable; return NULL if not registered.
  ExprRef input(const std::string& name) const;
  /// Return the named state variable; return NULL if not registered.
  ExprRef state(const std::string& name) const;
  /// Return the named instruction; return NULL if not registered.
  InstrRef instr(const std::string& name) const;
  /// Return the named child-ILA; return NULL if not registered.
  Ila child(const std::string& name) const;

  /// Return the wrapped ILA pointer.
  inline IlaPtr get() const { return ptr_; }

  // ------------------------- UTILITIES ------------------------------------ //
  /// \brief Export an ILA as Verilog
  /// \param[in] fout the output stream of the generated Verilog source.
  void ExportToVerilog(std::ostream& fout) const;

  /// \brief Flatten the hierarchy by lifting child-instructions as the
  /// top-level parent instructions.
  void FlattenHierarchy();

  /// \brief Supported pass ID.
  typedef enum PassID {
    SANITY_CHECK_AND_FIX = 0,
    SIMPLIFY_SYNTACTIC,
    SIMPLIFY_SEMANTIC,
    REWRITE_CONDITIONAL_STORE,
    REWRITE_LOAD_FROM_STORE
  } PassID;

  /// \brief Execute the specified passes in order.
  /// \param[in] passes the list of passes to execute.
  bool ExecutePass(const std::vector<PassID>& passes) const;

}; // class Ila

/******************************************************************************/
// Output stream helper
/******************************************************************************/
/// Print out the ExprRef.
std::ostream& operator<<(std::ostream& out, const ExprRef& expr);
/// Print out the Instruction.
std::ostream& operator<<(std::ostream& out, const InstrRef& instr);
/// Print out the ILA.
std::ostream& operator<<(std::ostream& out, const Ila& ila);

/******************************************************************************/
// Converters
/******************************************************************************/
/// \brief Export the ILA portable to file.
/// \param[in] ila the source ILA model to export.
/// \param[in] file_name the name of the exported ILA portable (JSON) file.
bool ExportIlaPortable(const Ila& ila, const std::string& file_name);

/// \brief Import the ILA portable from file.
/// \param[in] file_name the name of the ILA portable (JSON) file to import.
Ila ImportIlaPortable(const std::string& file_name);

#ifdef SYNTH_INTERFACE
/// \brief Import the synthesized abstraction from file.
/// \param[in] file_name the name of the synthesized abstraction (.ila) file.
/// \param[in] ila_name the name of the generated ILA.
Ila ImportSynthAbstraction(const std::string& file_name,
                           const std::string& ila_name);

/// \brief Import the synthesized (child-)abstraction from file, under the given
/// parent ILA.
/// \param[in] file_name the name of the synthesized child-abstraction.
/// \param[in] parent the parent ILA.
/// \param[in] ila_name the name pf the generated child-ILA.
void ImportChildSynthAbstraction(const std::string& file_name, Ila& parent,
                                 const std::string& ila_name);
#endif // SYNTH_INTERFACE

/// \brief Generate the SystemC simulator.
/// \param [in] ila the top-level ILA to generate.
/// \param [in] dir_path directory path of the generated simulator.
/// \param [in] optimize set true to enable optimization.
void ExportSysCSim(const Ila& ila, const std::string& dir_path,
                   bool optimize = false);

/******************************************************************************/
// Verification.
/******************************************************************************/
/// \brief The wrapper of generating z3::expr for verification.
class IlaZ3Unroller {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor
  IlaZ3Unroller(z3::context& ctx, const std::string& suff = "");
  /// Default virtual destructor.
  ~IlaZ3Unroller();

  // ------------------------- METHODS -------------------------------------- //
  /// Add a predicate that should be asserted globally when unrolled.
  inline void AddGlobPred(const ExprRef& p) { glob_pred_.push_back(p); }
  /// Add a predicate that should be asserted in the initial condition.
  inline void AddInitPred(const ExprRef& p) { init_pred_.push_back(p); }
  /// Add a predicate that should be asserted at the k-th step.
  inline void AddStepPred(const int& k, const ExprRef& p) {
    step_pred_.push_back({k, p});
  }
  /// Clear the global predicates.
  inline void ClearGlobPred() { glob_pred_.clear(); }
  /// Clear the initial predicates.
  inline void ClearInitPred() { init_pred_.clear(); }
  /// Clear the step-specific predicates.
  inline void ClearStepPred() { step_pred_.clear(); }

  /// \brief Unroll the ILA monolithically with each step connected.
  /// \param[in] top the top-level ILA of the hierarchy.
  /// \param[in] k the number of steps to unroll.
  /// \param[in] init the starting time frame.
  z3::expr UnrollMonoConn(const Ila& top, const int& k, const int& init = 0);

  /// \brief Unroll the ILA monolithically with each step freely defined.
  /// \param[in] top the top-level ILA of the hierarchy.
  /// \param[in] k the number of steps to unroll.
  /// \param[in] init the starting time frame.
  z3::expr UnrollMonoFree(const Ila& top, const int& k, const int& init = 0);

  /// \brief Unroll a path with each step connected.
  /// \param[in] path the sequence of instructions.
  /// \param[in] init the starting time frame.
  z3::expr UnrollPathConn(const std::vector<InstrRef>& path,
                          const int& init = 0);

  /// \brief Unroll a path with each step connected with rewriting.
  /// \param[in] path the sequence of instructions.
  /// \param[in] init the starting time frame.
  z3::expr UnrollPathSubs(const std::vector<InstrRef>& path,
                          const int& init = 0);

  /// \brief Unroll a path with each step freely defined.
  /// \param[in] path the sequence of instructions.
  /// \param[in] init the starting time frame.
  z3::expr UnrollPathFree(const std::vector<InstrRef>& path,
                          const int& init = 0);

  // ------------------------- HELPERS -------------------------------------- //
  /// Return the z3::expr representing the current state at the time.
  z3::expr CurrState(const ExprRef& v, const int& t);
  /// Return the z3::expr representing the next state at the time.
  z3::expr NextState(const ExprRef& v, const int& t);
  /// Return the z3::expr representing the current-based Expr at the time.
  z3::expr GetZ3Expr(const ExprRef& v, const int& t = 0);
  /// Return the z3::expr representing a and b are equal at their time.
  z3::expr Equal(const ExprRef& va, const int& ta, const ExprRef& vb,
                 const int& tb);
  /// Return the z3::func_decl representing f.
  z3::func_decl GetZ3FuncDecl(const FuncRef& f) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The underlying z3::context being used.
  z3::context& ctx_;

  /// The container for storing global predicates when unrolling.
  std::vector<ExprRef> glob_pred_;
  /// The container for storing initial predicates when unrolling.
  std::vector<ExprRef> init_pred_;
  /// The container for storing step-specific predicates when unrolling.
  std::vector<std::pair<int, ExprRef>> step_pred_;
  /// The extra suffix used when unrolling.
  std::string extra_suff_;

  /// Pointer for calling universal functions.
  std::shared_ptr<Unroller> univ_ = nullptr;

  // ------------------------- HELPERS -------------------------------------- //
  /// Initialize the unroller based on its dynamic type.
  template <class T> void InitializeUnroller(T unroller) {
    for (auto it = glob_pred_.begin(); it != glob_pred_.end(); it++) {
      unroller->AddGlobPred(it->get());
    }
    for (auto it = init_pred_.begin(); it != init_pred_.end(); it++) {
      unroller->AddInitPred(it->get());
    }
    for (auto it = step_pred_.begin(); it != step_pred_.end(); it++) {
      unroller->AddStepPred(it->second.get(), it->first);
    }
    // unroller->SetExtraSuffix(extra_suff_);
  }

}; // class IlaZ3Unroller

#ifdef SMTSWITCH_INTERFACE

/// \brief Generate the SMT Term (for smt-switch).
/// \param[in] solver The SMT solver in smt-switch.
/// \param[in] expr The target ILA expression.
/// \param[in] suffix The suffix to add on SMT symbols' name.
smt::Term GetSmtTerm(smt::SmtSolver& solver, const ExprRef& expr,
                     const std::string& suffix = "");

#endif // SMTSWITCH_INTERFACE

namespace programfragment {
  
  /// \brief The type of a constraint in the program fragment language.
  using Constraint = ExprRef;
  
  /// \brief Wrapper for a bitvector that allows it to be automatically 
  /// zero/sign extended as part of an Update statement.
  struct ExtendableBv { 
    ExprRef expr;
    enum ExtMode {EXT_ZERO, EXT_SIGNED} ext_mode;

    /// \brief Constructs an ExtendableBv from a bitvector expr.
    /// \param[in] expr The ILA expression to extend as needed.
    explicit ExtendableBv(const ExprRef& expr): ExtendableBv{expr, EXT_ZERO} {}

    /// \brief Constructs an ExtendableBv from a bitvector expr.
    /// \param[in] expr The ILA expression to extend as needed.
    /// \param[in] ext_mode How the expression should be extended.
    explicit ExtendableBv(const ExprRef& expr, ExtMode ext_mode)
      : expr{expr}, ext_mode{ext_mode} {}

    /// Default destructor.
    ~ExtendableBv()=default;

    /// \brief Extends the wrapped bitvector expression to match the given expr.
    /// \param[in] other The ILA expression whose bitwidth to match.
    ExprRef extend_to(const ExprRef& other) const;
  };

  /// \brief Valid types for the RHS of an update.
  using AssignmentExpr = std::variant<ExprRef, NumericType, ExtendableBv>;

  /// \brief A list of variables and what they should be updated to.
  using VarMap = std::vector<std::pair<ExprRef, AssignmentExpr>>;

  /// forward declarations
  struct Assert;
  struct Assume;
  struct Call;
  struct Update;
  struct While;
  struct Block;

  /// \brief A statement within a program fragment.
  using Stmt = std::variant<Assert, Assume, Call, Update, While, Block>;

  /// \brief A sequence of statements.
  struct Block : public std::vector<Stmt> {
    using base=std::vector<Stmt>;
    using base::base;
    using base::operator=;
  };

  /// \brief An assertion that a given constraint holds at a given 
  /// location of a program fragment.
  /// Will be checked once encoded for and sent to a solver.
  struct Assert {
    Constraint assertion;  // The constraint that must hold.
  };

  /// \brief An assumption that a given constraint holds at a given 
  /// location of a program fragment.
  struct Assume {
    Constraint assumption;  // The constraint assumed to hold.
  };

  /// \brief "Calls" the given instruction with the given inputs.
  /// Assumes the decode of the given instruction holds.
  struct Call {
    InstrRef instr;    // The instruction to call.
    VarMap inputs {};  // Assignments to the inputs of instr's ILA.
  };

  /// \brief Updates the given variables using the expressions they
  /// are mapped to.
  struct Update: public VarMap {
    using base=VarMap;
    using base::base;
    using base::operator=;
  };

  /// \brief A while loop. Repeatedly executes the body while the
  /// given loop condition holds.
  struct While {
    Constraint loop_condition;  // The loop condition
    /// An invariant on the loop provided to help verification.
    /// The invariant is asserted before the loop and at the end
    /// of the loop body, and assumed at the start of the loop
    /// body and after the loop ends.
    Constraint invariant;
    Block body;  // The body of the loop

    /// \brief Constructs a While loop given a loop condition and body.
    /// \param[in] loop_condition The loop condition.
    /// \param[in] body The loop body.
    While(const Constraint& loop_condition, const Block& body);
    /// \brief Constructs a While loop given a loop condition and body.
    /// \param[in] loop_condition  The loop condition.
    /// \param[in] invariant  An invariant on the loop provided 
    /// to help verification.
    /// The invariant is asserted before the loop and at the end
    /// of the loop body, and assumed at the start of the loop
    /// body and after the loop ends.
    /// \param[in] body  The loop body.
    While(const Constraint& loop_condition, 
          const Constraint& invariant, const Block& body);
  };

  /// \brief A program using an ILA.
  class ProgramFragment {

    friend bool operator==(const ProgramFragment& a, const ProgramFragment& b);
    friend std::ostream& operator<<(std::ostream& out, const ProgramFragment& pf);

  public:
    /// Pointer to the internal representation of a program fragment.
    using PfragPtr = std::shared_ptr<pfast::ProgramFragment>;
    /// Pointer to the internal representation of a program fragment.
    using PfragConstPtr = std::shared_ptr<const pfast::ProgramFragment>;

    /// Constructs an empty program fragment.
    ProgramFragment();

    /// Constructs a program fragment consisting of the given block.
    ProgramFragment(const Block& b);

    /// Destroys a program fragment
    ~ProgramFragment()=default;

    /// Creates a new boolean variable and registers it as a parameter
    ExprRef NewBoolVar(const std::string& name);

    /// Creates a new bitvector variable and registers it as a parameter
    ExprRef NewBvVar(const std::string& name, const int& bitwidth);

    /// Creates a new bitvector variable and registers it as a parameter
    ExprRef NewMemVar(const std::string& name, 
                      const int& addrwidth, const int& datawidth);

    // void RegisterApplicationParam(const ExprRef& p);
    // void RegisterHardwareParam(const ExprRef& p);

    /// Adds the given statement to the program fragment
    void AddStatement(const Stmt& s);

    /// Adds the given block of statements to the program fragment
    void AddStatements(const Block& b);

    /// Returns the internal representation of the program fragment
    PfragConstPtr get() const;

  private:
    PfragPtr pf_;
  };

  /// Checks structural equality
  bool operator==(const ProgramFragment& a, const ProgramFragment& b);

  /// Prints a program fragment
  std::ostream& operator<<(std::ostream& out, const ProgramFragment& pf);

} // namespace programfragment


/// An enum representing the result of verifying the system of CHCs
enum class ChcResult: char {
  valid=z3::unsat,
  invalid=z3::sat,
  unknown=z3::unknown
};

std::ostream& operator<<(std::ostream& out, const ChcResult& r);

/// Encodes a program fragment on an ILA into a CHC
class IlaToChcEncoder {
  public:
    // TODO: move parameter registration in program fragments to 
    // internal representation, rename IlaToChcEncoder to PfToChcIncoder,
    // and remove the Ila argument.

    /// Constructs an IlaToChcEncoder
    IlaToChcEncoder(
      z3::context& ctx, z3::fixedpoint& ctxfp,
      const Ila& ila, const programfragment::ProgramFragment& pf);
    
    /// Destructor 
    ~IlaToChcEncoder()=default;

    /// Gives the system of CHCs as a string
    std::string to_string();

    /// Checks the assertion of the system of CHCs
    ChcResult check_assertions();
  
  private:
    std::shared_ptr<PFToCHCEncoder> impl_;
};


} // namespace ilang

#endif // ILANG_ILANG_CPP_H__
