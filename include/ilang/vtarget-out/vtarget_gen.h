/// \file Header for wrapper for verilog verification target generation
/// This is used to avoid include json explicitly
// --- Hongce Zhang

#ifndef VTARGET_GEN_H__
#define VTARGET_GEN_H__

#include <ilang/config.h>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/verilog-out/verilog_gen.h>
#include <ilang/vtarget-out/inv-syn/inv_obj.h>
#include <ilang/vtarget-out/inv-syn/cex_extract.h>

namespace ilang {

/// \brief VlgVerifTgtGenBase: do nothing, should not instantiate
class VlgVerifTgtGenBase {
  // ----------------------- Type Definition ----------------------- //
public:
  /// Type of record of extra info of a signal
  struct ex_info_t {
    std::string range;
    ex_info_t(const std::string& r) : range(r) {}
  };
  /// Type of the backend
  typedef enum { NONE = 0, COSA = 1, JASPERGOLD = 2, YOSYS = 3 } backend_selector;
  /// Type of invariant synthesis backend
  typedef enum {Z3, FreqHorn, CVC4, ABC} synthesis_backend_selector;
  /// Type of the chc target
  enum _chc_target_t {CEX, INVCANDIDATE, GENERAL_PROPERTY};
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
    /// Tell whether we assume the invariants only on the initial state
    /// when checking instructions
    /// I couldn't think of a reason why not, maybe this is
    /// faster for the solver? maybe
    /// for Yosys, we will ignore this
    // bool OnlyEnforceInvariantsOnInitialStateOfInstrCheck; // true
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
    /// or allow the verilog modify detect it (detection could fail or 
    /// make mistakes, so you may want to force it)
    enum { AUTO = 0, NEW = 1, OLD = 2 } PortDeclStyle; // default : AUTO
    /// Generate a jg script to help validate cosa?
    bool CosaGenJgTesterScript; // default : false
    /// generate the trace for all variables?
    bool CosaFullTrace;
    /// For CoSA backend: do we add (* keep *)? default true, however, it can be
    /// buggy, so you can disable it if you want
    bool CosaAddKeep;
    // The bound of BMC, default 127
    unsigned MaxBound;
    /// Only enforce var eq on updated vars, should not be used
    bool OnlyAssumeUpdatedVarsEq; // should be false
    /// Assumption OverConstrainCheck
    bool CosaAssumptionOverlyConstrainedCheck;
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
    // ----------- Options for Yosys SMT-LIB2 Generator -------------- //
    /// The path to yosys, if yosys is not in the PATH, default empty
    std::string YosysPath;
    /// whether to explicitly turn the undriven net to input
    /// for smt-backend, the top level undriven net seems always turned into
    /// inputs, but the lower level may not 
    bool YosysUndrivenNetAsInput;
    /// Whether to use array sort on register file, not compatible with
    /// BitVec in YosysSmtStateSort, default false
    bool YosysSmtArrayForRegFile;
    /// How to encode Verilog state
    /// DataSort seems to use PDR engine, while bitvec seems Datalog
    /// Not 100% sure of it
    typedef enum  { 
      UnintepretedFunc /*not supported*/ , 
      DataSort, /*by default*/
      BitVec /*not supported*/
      } _state_sort_t;
    _state_sort_t YosysSmtStateSort;
    /// whether to remove the extra issue cycle and starts from reset
    bool VerificationSettingAvoidIssueStage;
    /// for invariant synthesis do we keep memory abstraction in Verilog
    /// you can keep it true, untill the invariant refers to some memory there
    bool InvariantSynthesisKeepMemory;
    /// for invariant check, do we keep memory abstraction in Verilog
    bool InvariantCheckKeepMemory;
    // ----------- Options for Z3/FreqHorn/ABC Solver -------------- //
    /// The path to Z3, if "z3" is not in the PATH, default empty
    std::string Z3Path;
    /// The path to FreqHorn, if "freqhorn" is not in the PATH, default empty
    std::string FreqHornPath;
    /// FreqHorn Configuration Options
    std::vector<std::string> FreqHornOptions;
    /// FreqHorn style (cocistyple, cnfstyle)
    bool FreqHornHintsUseCnfStyle;
    /// The path to ABC, if "abc" is not in the PATH, default empty
    std::string AbcPath;
    /// Whether to flatten the module hierarchy
    bool YosysSmtFlattenHierarchy;
    /// Whether to flatten the datatypes
    bool YosysSmtFlattenDatatype;
    /// Whether to assume the old invariants when check for reachability
    /// It seems for Z3, setting this to be false is faster (I don't know why)
    /// For freqhorn-enhance, this will be (internally) overwritten to be true
    bool InvariantSynthesisReachableCheckKeepOldInvariant;
    /// ABC option : whether to use gate-level abstraction
    bool AbcUseGla;
    /// ABC option : whether to use correlation analysis
    bool AbcUseCorr;  
    /// ABC option : whether to pass aiger to ABC
    bool AbcUseAiger;  
    /// ABC option : whether to minimize invariant
    bool AbcMinimizeInv;
    /// ABC option : the way to handle assumptions
    typedef enum _abc_assumption_style_t {
      AigMiterExtraOutput = 0, // Use AIG's extra output to represent, cannot use with GLA
      AssumptionRegister = 1   // Use extra register, may have issues in interpreting the invariant
    } AbcAssumptionStyle_t;
    AbcAssumptionStyle_t AbcAssumptionStyle;
    /// Configure the behavior of INV target, if false,
    /// will not check synthesized invariants by default (unless call generateInvariantVerificationTarget)
    /// if true, will check by default
    enum _validate_synthesized_inv { NOINV, CANDIDATE, CONFIRMED, ALL } ValidateSynthesizedInvariant;
    // ----------- Options for SyGuS Solver for Invariant Synthesis ----------- //
    /// The path to CVC4, if "cvc4" is not in the PATH, default empty
    std::string Cvc4Path;
    /// the SyGuS solver options --- not limited to CVC4
    struct _sygus_options_t{
      /// The type of synthesis (datapoint/transfer function)
      enum _sygus_pass_info_t {DataPoints, TransferFunc} SygusPassInfo;
      /// whether to use bvcomparison
      bool UseEqOnlyBvComparison;

      /// whether to use bit extension
      bool UseExtend;
      /// the bit range to extract from
      std::vector<std::pair<unsigned, unsigned>> ExtendFrom;
      /// the bit range to extract to
      std::vector<std::pair<unsigned, unsigned>> ExtendTo;
      /// the vars to take into consideration
      std::set<std::string> ExtendVars;

      /// whether to use bit extraction
      bool UseExtract;
      /// the bit range to extract from
      std::vector<std::pair<unsigned, unsigned>> ExtractFrom;
      /// the bit range to extract to
      std::vector<std::pair<unsigned, unsigned>> ExtractTo;
      /// the vars to take into consideration
      std::set<std::string> ExtractVars;

      /// whether to use concatnation
      bool UseConcat;
      /// the vars to take into consideration
      std::set<std::string> ConcatVars;

      /// future: use arithmetics?
      enum _use_arithmetics_t {None, Level1, Recursive} UseArithmetics;

      /// constants in the syntax
      /// add all constants if it is or below this size
      unsigned AllConstantUnderThisSize;

      /// all other width : 0 1 half allone-1 allone
      std::set<unsigned> SpecialValueForAllOtherWidth;

      // default constructor
      _sygus_options_t() :
        SygusPassInfo(_sygus_pass_info_t::DataPoints),
        UseEqOnlyBvComparison(true),
        UseExtend(false), UseExtract(false), 
        UseConcat(false) , UseArithmetics(_use_arithmetics_t::None),
        AllConstantUnderThisSize(4) {}
    }; // the options
    _sygus_options_t SygusOptions;



    /// The default constructor for default values
    _vtg_config()
        : target_select(BOTH), CheckThisInstructionOnly(""),
          InstructionNoReset(true), 
          // OnlyEnforceInvariantsOnInitialStateOfInstrCheck(true),  // not used, always true
          OnlyCheckInstUpdatedVars(true),
          PerVariableProblemCosa(false), MemAbsReadAbstraction(false),
          ForceInstCheckReset(false), PortDeclStyle(AUTO),
          CosaGenJgTesterScript(false),  CosaFullTrace(false), CosaAddKeep(true), MaxBound(127),
          OnlyAssumeUpdatedVarsEq(false), CosaAssumptionOverlyConstrainedCheck(false), // we suggest you give true
          CosaPath(""), CosaPyEnvironment(""),
          CosaSolver(""), CosaGenTraceVcd(true), CosaOtherSolverOptions(""),
          YosysUndrivenNetAsInput(false),
          YosysSmtArrayForRegFile(false), YosysSmtStateSort(DataSort),
          VerificationSettingAvoidIssueStage(false), 
          InvariantSynthesisKeepMemory(true),
          InvariantCheckKeepMemory(true),
          FreqHornHintsUseCnfStyle(true),
          YosysSmtFlattenHierarchy(false),
          YosysSmtFlattenDatatype(false), InvariantSynthesisReachableCheckKeepOldInvariant(false),
          ValidateSynthesizedInvariant(_validate_synthesized_inv::ALL) ,
          AbcUseGla(true), AbcUseCorr(false), AbcUseAiger(false),
          AbcMinimizeInv(false),
          AbcAssumptionStyle(_abc_assumption_style_t::AssumptionRegister) {}
  } vtg_config_t;

  /// NOTE: this function can be inherited
  /// and only expose a visible interface to the outside
  typedef struct _adv_parameters {
    /// invariant object
    InvariantObject * _inv_obj_ptr;
    /// candidate invariants object
    InvariantObject * _candidate_inv_ptr;
    /// counterexample object
    CexExtractor * _cex_obj_ptr;
    /// The default constructor for default values
    _adv_parameters() : 
      _inv_obj_ptr(NULL),
      _candidate_inv_ptr(NULL),
      _cex_obj_ptr(NULL) {}
    /// virtual destructor
    virtual ~_adv_parameters() {};
  } advanced_parameters_t;

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
  /// Type of the synthesis backend
  using synthesis_backend_selector = VlgVerifTgtGenBase::synthesis_backend_selector;
  /// Type of configuration
  using vtg_config_t = VlgVerifTgtGenBase::vtg_config_t;
  /// Type of advanced parameter
  using advanced_parameters_t = VlgVerifTgtGenBase::advanced_parameters_t;

public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  ///
  /// \param[in] implementation's include path (if it uses `include)
  /// \param[in] verilog's path, currently we only handle situation where all in
  /// the same folder \param[in] name of the top module of the implementation,
  /// leave "" to allow auto analysis \param[in] where to get variable mapping
  /// \param[in] where to get refinement relation
  /// \param[in] output path (ila-verilog, wrapper-verilog, problem.txt,
  /// run-verify-by-???, modify-impl, it there is ) 
  /// \param[in] pointer to the ila
  /// \param[in] the backend selector 
  /// \param[in] (optional) the default configuration for outputing verilog
  /// \param[in] (optional) pointer to an advance parameter
  VerilogVerificationTargetGenerator(
      const std::vector<std::string>& implementation_include_path,
      const std::vector<std::string>& implementation_srcs,
      const std::string& implementation_top_module,
      const std::string& refinement_variable_mapping,
      const std::string& refinement_conditions, const std::string& output_path,
      const InstrLvlAbsPtr& ila_ptr, backend_selector backend,
      const vtg_config_t& vtg_config = vtg_config_t(),
      const VerilogGenerator::VlgGenConfig& config =
          VerilogGenerator::VlgGenConfig(),
      advanced_parameters_t * adv_ptr = NULL);
  // --------------------- DECONSTRUCTOR ---------------------------- //
  virtual ~VerilogVerificationTargetGenerator();

  /// export all targets
  void GenerateTargets(void);
  /// return true if the generator's in a bad state and cannot proceed.
  bool in_bad_state(void) const;
  /// get vlg-module instance name
  std::string GetVlgModuleInstanceName(void) const;

private:
  /// will be casted to different generator inside the implementation
  VlgVerifTgtGenBase* _generator;

}; // VerilogVerificationTargetGenerator

}; // namespace ilang

#endif // VTARGET_GEN_H__