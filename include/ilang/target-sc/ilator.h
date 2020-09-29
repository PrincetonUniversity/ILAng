/// \file
/// The header file of ILAtor - a simulator generator of ILA models.

#ifndef ILANG_TARGET_SC_ILATOR_H__
#define ILANG_TARGET_SC_ILATOR_H__

#include <memory>
#include <string>

#include <fmt/format.h>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/util/log.h>

/// \namespace ilang
namespace ilang {

#define ILATOR_PRECISE_MEM

/// \brief The ILAtor class - for CMake-based SystemC simulator generation.
class Ilator {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with a fixed ILA model.
  Ilator(const InstrLvlAbsPtr& m);
  /// Destructor.
  ~Ilator();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Generate the SystemC simulator.
  /// \param[in] dst the directory path for the generated simulator.
  /// \param[in] opt set true to enable optimization.
  void Generate(const std::string& dst, bool opt);

private:
  /// Internal type of the string buffer.
  typedef fmt::memory_buffer StrBuff;
  /// Internal type of Expr to var name look-up table.
  typedef std::unordered_map<ExprPtr, std::string, ExprHash> ExprVarMap;
  /// Internal type to manage functions.
  class CxxFunc {
  public:
    CxxFunc(const std::string& in_name, const ExprPtr& in_ret,
            const ExprPtr& in_target = nullptr)
        : name(in_name), ret(in_ret), target(in_target) {}
    CxxFunc(const std::string& in_name, const SortPtr& in_ret_type)
        : name(in_name), ret_type(in_ret_type) {}
    const std::string name = "";
    const ExprPtr ret = nullptr;
    const ExprPtr target = nullptr;
    const SortPtr ret_type = nullptr;
    std::vector<SortPtr> args;
  };

  // ------------------------- MEMBERS -------------------------------------- //
  /// The ILA model to generate.
  InstrLvlAbsPtr m_;

  /// Generated functions (with definition).
  std::map<std::string, CxxFunc*> functions_;
  /// Generated functions (without definition).
  std::map<std::string, CxxFunc*> externs_;
  /// Wrapper functions to update memory values.
  std::map<std::string, CxxFunc*> memory_updates_;
  /// Generated sources files.
  std::set<std::string> source_files_;
  /// Constant memory that needs to be initialzied.
  std::set<ExprPtr> const_mems_;
  /// Global variables other than state variables.
  std::set<ExprPtr> global_vars_;

  // ------------------------- HELPERS -------------------------------------- //
  /// Reset all internal trackers.
  void Reset();
  /// Check if the ILA model contains unsupported patterns.
  bool SanityCheck() const;
  /// Generation bootstrap, e.g., creating directories.
  bool Bootstrap(const std::string& root, bool opt);

  /// Interpret non-instr basics, e.g., valid.
  bool GenerateIlaBasics(const std::string& dir);
  /// Interpret instruction semantics (decode and state updates).
  bool GenerateInstrContent(const InstrPtr& instr, const std::string& dir);
  /// Special handle for memory updates.
  bool GenerateMemoryUpdate(const std::string& dir);
  /// Special handle for constant memory.
  bool GenerateConstantMemory(const std::string& dir);
  /// Generate setup function for initial condition.
  bool GenerateInitialSetup(const std::string& dir);
  /// Generate the instruction scheduler and driver.
  bool GenerateExecuteKernel(const std::string& dir);
  /// Generate the shared header files.
  bool GenerateGlobalHeader(const std::string& dir);
  /// Generate the CMake recipe and other placeholders.
  bool GenerateBuildSupport(const std::string& dir);

  /// Translate expression node to SystemC statements.
  bool RenderExpr(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut);
  /// Translation routine for entrypoint.
  void DfsExpr(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut);
  /// Translation routine for variable.
  void DfsVar(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) const;
  /// Translation routine for constant.
  void DfsConst(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut);
  /// Translation routine for operation.
  void DfsOp(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut);
  /// Translation routine for memory type operation.
  void DfsOpMemory(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut);
  /// Translation routine for function application.
  void DfsOpAppFunc(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut);
  /// Translation routine for non-regular operation.
  void DfsOpSpecial(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut);
  /// Translation routine for regular operation.
  void DfsOpRegular(const ExprPtr& expr, StrBuff& buff, ExprVarMap& lut) const;

  /// Request a function with the specified name and return var.
  CxxFunc* RegisterFunction(const std::string& func_name,
                            ExprPtr return_expr = nullptr);
  /// Request a function simulating the uninterpreted function.
  CxxFunc* RegisterExternalFunc(const FuncPtr& func);
  /// Request a wrapping function for memory operation.
  CxxFunc* RegisterMemoryUpdate(const ExprPtr& expr);

  /// Start function definition.
  void BeginFuncDef(CxxFunc* func, StrBuff& buff) const;
  /// Finish function definition.
  void EndFuncDef(CxxFunc* func, StrBuff& buff) const;
  /// Write function declaration.
  void WriteFuncDecl(CxxFunc* func, StrBuff& buff) const;
  /// Record and write the source to file.
  void CommitSource(const std::string& file_name, const std::string& dir,
                    const StrBuff& buff);

  /// Get the project name.
  inline std::string GetProjectName() const { return m_->name().str(); }
  /// Create a local variable name.
  static inline std::string GetLocalVar(const ExprVarMap& lut) {
    return fmt::format("local_var_{}", lut.size());
  }
  /// Get the type of expr in SystemC.
  static inline std::string GetCxxType(const ExprPtr& expr) {
    return GetCxxType(expr->sort());
  }
  /// Get the type of sort in SystemC.
  static std::string GetCxxType(const SortPtr& sort);
  /// Get the variable name in SystemC.
  static std::string GetCxxName(const ExprPtr& expr);
  /// Get the valid function name of the ILA.
  static std::string GetValidFuncName(const InstrLvlAbsCnstPtr& m);
  /// Get the decode function name of the instruction.
  static std::string GetDecodeFuncName(const InstrPtr& instr);
  /// Get the state update function name of the instruction.
  static std::string GetUpdateFuncName(const InstrPtr& instr);
  /// Get the memory update function name.
  static std::string GetMemoryFuncName(const ExprPtr& expr);
  /// Helper for look up variable name in the table.
  inline std::string LookUp(const ExprPtr& e, const ExprVarMap& lut) const {
    auto pos = lut.find(e);
    ILA_ASSERT(pos != lut.end());
    return pos->second;
  }

}; // class Ilator

} // namespace ilang

#endif // ILANG_TARGET_SC_ILATOR_H__
