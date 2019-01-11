/// \file Header for wrapper for verilog verification target generation
/// This is used to avoid include json explicitly
// --- Hongce Zhang

#ifndef VTARGET_GEN_H__
#define VTARGET_GEN_H__

#include <ilang/config.h>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/verilog-out/verilog_gen.h>

namespace ilang {

/// \brief VlgVerifTgtGenBase: do nothing, should not instantiate
class VlgVerifTgtGenBase {
  // ----------------------- Type Definition ----------------------- //
public:
  /// Type of the backend
  typedef enum { NONE = 0, COSA = 1, JASPERGOLD = 2 } backend_selector;
  /// Verilog Target Generation Configuration
  typedef struct _vtg_config {
    /// Set the targets: instructions/invariants/both
    enum { INST, INV, BOTH } target_select;
    /// If not an empty string, then only check for that instruction
    std::string CheckThisInstructionOnly;
    /// Ensure the instruction will not be reseted while
    /// in the whole execution of checking instruction
    /// from reseted --> to forever
    bool InstructionNoReset; // true
    /// Does not insert assertions of variable mapping
    /// if an instruction does not update that var
    bool OnlyCheckInstUpdatedVars; // true
    /// Do we set separate problems for different var map (CoSA only)
    bool PerVariableProblemCosa; // true
    /// Whether to abstract the memory read
    bool MemAbsReadAbstraction; // false
    /// Whether to force the instruction check to start from reset state
    bool ForceInstCheckReset;
    /// For COSA target generator : whether to force NEW/OLD port declaration
    enum { AUTO = 0, NEW = 1, OLD = 2 } PortDeclStyle;
    /// Generate a jg script to help validate cosa?
    bool CosaGenJgTesterScript;
    /// For CoSA backend: do we add (* keep *)? default true, however, it can be buggy, so you can disable it if you want
    bool CosaAddKeep;
    // The bound of BMC, default 127
    unsigned MaxBound;
    /// Only enforce var eq on updated vars, should not be used
    bool OnlyAssumeUpdatedVarsEq; // should be false
    // ----------- Options for CoSA script -------------- //
    /// If not empty, the generated script will include the path of Cosa
    std::string CosaPath;
    /// If not empty, the generated script will include sourcing a script
    std::string CosaPyEnvironment;
    /// A choice of solver (in the script)
    std::string CosaSolver;
    /// Whether the Solver should generate vcd trace
    bool CosaGenTraceVcd;
    /// other CoSA options
    std::string CosaOtherSolverOptions;
    /// The default constructor for default values
    _vtg_config()
        : target_select(BOTH), CheckThisInstructionOnly(""),
          InstructionNoReset(true), OnlyCheckInstUpdatedVars(true),
          PerVariableProblemCosa(false), MemAbsReadAbstraction(false),
          CosaGenJgTesterScript(false), CosaAddKeep(true),
          MaxBound(127), ForceInstCheckReset(false), PortDeclStyle(AUTO),
          OnlyAssumeUpdatedVarsEq(false), CosaPath(""),
          CosaPyEnvironment(""), CosaSolver(""), CosaGenTraceVcd(true),
          CosaOtherSolverOptions("") {}
  } vtg_config_t;

public:
  // ----------------------- Constructor/Destructor ----------------------- //
  // constructor : do nothing
  VlgVerifTgtGenBase() {}
  // destructor : do nothing (make it virtual !!!)
  virtual ~VlgVerifTgtGenBase() {}

private:
  // avoid instantiation
  virtual void do_not_instantiate(void) = 0;
}; // class VlgVerifTgtGenBase

class VerilogVerificationTargetGenerator {
public:
  /// Type of the backend
  using backend_selector = VlgVerifTgtGenBase::backend_selector;
  /// Type of configuration
  using vtg_config_t = VlgVerifTgtGenBase::vtg_config_t;

public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  ///
  /// \param[in] implementation's include path (if it uses `include)
  /// \param[in] verilog's path, currently we only handle situation where all in
  /// the same folder \param[in] name of the top module of the implementation,
  /// leave "" to allow auto analysis \param[in] where to get variable mapping
  /// \param[in] where to get refinement relation
  /// \param[in] output path (ila-verilog, wrapper-verilog, problem.txt,
  /// run-verify-by-???, modify-impl, it there is ) \param[in] pointer to the
  /// ila \param[in] the backend selector \param[in] (optional) the default
  /// configuration for outputing verilog
  VerilogVerificationTargetGenerator(
      const std::vector<std::string>& implementation_include_path,
      const std::vector<std::string>& implementation_srcs,
      const std::string& implementation_top_module,
      const std::string& refinement_variable_mapping,
      const std::string& refinement_conditions, const std::string& output_path,
      const InstrLvlAbsPtr& ila_ptr, backend_selector backend,
      const vtg_config_t& vtg_config = vtg_config_t(),
      const VerilogGenerator::VlgGenConfig& config =
          VerilogGenerator::VlgGenConfig());
  // --------------------- DECONSTRUCTOR ---------------------------- //
  virtual ~VerilogVerificationTargetGenerator();

  /// export all targets
  void GenerateTargets(void);
  /// return true if the generator's in a bad state and cannot proceed.
  bool in_bad_state(void) const;

private:
  /// will be casted to different generator inside the implementation
  VlgVerifTgtGenBase* _generator;

}; // VerilogVerificationTargetGenerator

}; // namespace ilang

#endif // VTARGET_GEN_H__