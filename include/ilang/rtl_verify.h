/// \file
/// The header for the c++ API.

#ifndef ILANG_RTL_VERIFY_CONFIG_H__
#define ILANG_RTL_VERIFY_CONFIG_H__

#include <map>
#include <memory>
#include <string>
#include <vector>


/// \namespace ilang
/// Defines the configurations for Verilog refinement checking
namespace ilang {


  // ----------- Verification Settings -------------- //
  /// Type of the backend:
  /// Pono, JasperGold
  /// YOSYS is for generic btor generation
  enum class ModelCheckerSelection {
    NONE = 0,
    JASPERGOLD = 2,
    YOSYS = 128, // 10000000
    // CHC = YOSYS + 8,          // 10001000
    // Z3PDR = CHC + 1,          // 10001001
    // ELD_CEGAR = CHC + 2,      // 10001010
    // GRAIN_SYGUS = CHC + 4,    // 10001100
    // ABCPDR = YOSYS + 16,      // 10010000
    PONO = YOSYS + 32,  // 10100000
    RELCHC = YOSYS + 64 // 11000000
  }; // enum class ModelCheckerSelection

/// Verilog Target Generation Configuration
  typedef struct _vtg_config {
    /// Preheader Content : will use in all targets
    std::string WrapperPreheader;
    /// Set the targets: instructions/invariants/both
    enum { INST, INV, BOTH } target_select;
    /// If not an empty string, then only check for that instruction
    std::string CheckThisInstructionOnly;
    /// Ensure the instruction will not be reseted while
    /// in the whole execution of checking instruction
    /// from reseted --> to forever
    bool InstructionNoReset; // true
    /// Ensure the design will not be reseted
    /// from reseted --> to forever
    bool InvariantCheckNoReset; // true
    /// Does not insert assertions of variable mapping
    /// if an instruction does not update that var
    bool OnlyCheckInstUpdatedVars; // true
    /// Whether to pass Verilog node name in reference
    /// generation
    bool VerilogGenPassNodeName;
    /// if false : assume (cond |-> reg == value)
    /// if true : assume ((START || STARTED) && cond && not_triggered)
    ///            |-> reg == value
    bool EnforcingValueRecorderForOnlyOneCycle;


    /// Configure the behavior of INV target, if false,
    /// will not check synthesized invariants by default (unless call
    /// generateInvariantVerificationTarget) if true, will check by default
    enum class _validate_synthesized_inv {
      NOINV,
      CANDIDATE,
      CONFIRMED,
      ALL
    } ValidateSynthesizedInvariant;

    // ----------- Options for Pono settings -------------- //
    /// Whether to force the instruction check to start from reset state
    bool ForceInstCheckReset;
    /// Whether to always instiantiate quantifers in refinement
    bool ForceQuantifierInstantiationInRfExpr;
    /// If true, will generate a separate check that cover the 
    /// the commit condition
    bool CheckInstrCommitSatisfiable;
    /// For Pono target generator : whether to force NEW/OLD port declaration
    enum class PortDeclStyleT { AUTO = 0, NEW = 1, OLD = 2 } PortDeclStyle;

    /// Pono VCD output
    std::string PonoVcdOutputName;
    /// Binary location of Pono
    std::string PonoPath;
    /// For Pono backend: do we add (* keep *)? default true, however, it can be
    /// buggy, so you can disable it if you want
    bool PonoAddKeep;
    /// For Pono backend: the default engine (ind by default)
    /// other options: like bmc, bmc-sp, ind, interp, mbic3,
    /// ic3bits, ic3ia, msat-ic3ia, ic3sa, sygus-pdr
    std::string PonoEngine;
    /// For Pono backend: what more options to add
    std::string PonoOtherOptions;
    /// whether to force dot reference check in the generation
    /// if you expect to use Pono on the it, yes, you need to
    /// use the default setting :  NOTIFY_PANIC
    /// in some rare cases, you may want to use JasperGold after it
    /// in that case, it is okay to just ignore it
    enum class PonoDotReferenceNotify_t {
      NOTIFY_PANIC = 0,
      NOTIFY_WARNING = 1,
      NOTIFY_IGNORE = 2
    } PonoDotReferenceNotify;
    /// whether to generator a script to be used with JG as well
    bool PonoGenJgScript;
    // The bound of BMC, default 127
    unsigned MaxBound;
    /// Only enforce var eq on updated vars, should not be used
    bool OnlyAssumeUpdatedVarsEq; // should be false

    // ----------- Options for Yosys SMT-LIB2 Generator -------------- //
    /// The path to yosys, if yosys is not in the PATH, default empty
    std::string YosysPath;
    /// whether to explicitly turn the undriven net to input
    /// for smt-backend, the top level undriven net seems always turned into
    /// inputs, but the lower level may not
    bool YosysUndrivenNetAsInput;
    /// Whether to flatten the module hierarchy
    bool YosysSmtFlattenHierarchy;
    /// Whether to flatten the datatypes
    bool YosysSmtFlattenDatatype;
    /// Whether to word-blast array or use SMT Array
    /// By default will word-blast
    bool YosysSmtArrayForRegFile;
    /// How to encode Verilog state
    /// DataSort seems to use PDR engine
    enum class YosysStateSortT {
      UnintepretedFunc /*not supported*/,
      Datatypes, /*by default*/
      BitVec     /*optional for property check, not inv-syn*/
    } YosysSmtStateSort;
    /// for invariant synthesis do we keep memory abstraction in Verilog
    /// you can keep it true, untill the invariant refers to some memory there
    bool InvariantSynthesisKeepMemory;
    /// for invariant check, do we keep memory abstraction in Verilog
    bool InvariantCheckKeepMemory;
    /// Whether to assume the old invariants when check for reachability
    /// It seems for Z3, setting this to be false is faster (I don't know why)
    /// For grain-enhance, this will be (internally) overwritten to be true
    bool InvariantSynthesisReachableCheckKeepOldInvariant;
    /// Whether to set undriven net in yosys as 0. In general this should not
    /// be needed, but for some reason, PONO is unhappy sometimes.
    bool YosysSetUndrivenZero;

    // ----------- Options for CHC Solver -------------- //
    /// CHC, whether to turn array into individual registers
    bool ChcWordBlastArray;
    /// CHC, whether to force assumption on the init
    bool ChcAssumptionsReset;
    /// CHC, whether to force assumption on the next T
    bool ChcAssumptionNextState;
    /// CHC, whether to force assumption on the end T
    bool ChcAssumptionEnd;

    // ----------- Options for Btor Output -------------- //
    /// in the format of "xxxx [options] %btorfile% [options]"
    /// will replace %btorfile% with the file
    std::string BtorGenericCmdline;
    /// CHC, whether to turn array into individual registers
    bool BtorSingleProperty;
    /// CHC, whether to force assumption on the init
    bool BtorAddCommentsInOutputs;

    /* TODO: future work:
        bool YosysAssumptionOverlyConstrainedCheck;
    */

    // ----------- Options for Z3/Grain/ABC Solver -------------- //
    /// The path to Z3, if "z3" is not in the PATH, default empty
    std::string Z3Path;
    /// The path to Grain, if "grain" is not in the PATH, default empty
    std::string GrainPath;
    /// Grain Configuration Options
    std::vector<std::string> GrainOptions;
    /// FreqHorn style (cocistyple, cnfstyle)
    bool GrainHintsUseCnfStyle;
    /// The path to ABC, if "abc" is not in the PATH, default empty
    std::string AbcPath;

    // ----------- Extended Options for ABC Solver -------------- //
    /// ABC option : whether to use gate-level abstraction
    bool AbcUseGla;
    /// ABC option : gate-level abstraction time limit
    unsigned AbcGlaTimeLimit;
    /// ABC option : gate-level abstraction frame limit
    unsigned AbcGlaFrameLimit;
    /// ABC option : whether to use correlation analysis
    bool AbcUseCorr;
    /// ABC option : whether to pass aiger to ABC
    bool AbcUseAiger;
    /// ABC option : whether to minimize invariant
    bool AbcMinimizeInv;
    /// ABC option : the way to handle assumptions
    enum class AbcAssumptionStyle_t {
      AigMiterExtraOutput =
          0, // Use AIG's extra output to represent, cannot use with GLA
      AssumptionRegister =
          1 // Use extra register, may have issues in interpreting the invariant
    } AbcAssumptionStyle;

    // ----------- Refinement Sanity Check Options-------------- //
    /// if true: will check if the value recorder is triggered multiple times
    bool SanityCheck_ValueRecorderOverlyConstrained;
    /// if true: will check if the value recorder is not triggered before commit
    bool SanityCheck_ValueRecorderTriggeredBeforeCommit;

    /// The default constructor for default values
    _vtg_config()
        : target_select(BOTH), CheckThisInstructionOnly(""),
          InstructionNoReset(true), InvariantCheckNoReset(false),
          OnlyCheckInstUpdatedVars(true), VerilogGenPassNodeName(false),
          EnforcingValueRecorderForOnlyOneCycle(true),
          ValidateSynthesizedInvariant(_validate_synthesized_inv::ALL),

          // ----------- Options for Pono settings -------------- //
          ForceInstCheckReset(false), 
          ForceQuantifierInstantiationInRfExpr(false),
          CheckInstrCommitSatisfiable(false),
          PortDeclStyle(PortDeclStyleT::AUTO),
          PonoVcdOutputName("cex.vcd"), PonoAddKeep(false), PonoEngine("ind"),
          PonoOtherOptions(""),
          PonoDotReferenceNotify(PonoDotReferenceNotify_t::NOTIFY_PANIC),
          PonoGenJgScript(false),
          MaxBound(127), OnlyAssumeUpdatedVarsEq(false),

          // ----------- Options for Pono script -------------- //
          // PonoAssumptionOverlyConstrainedCheck(false),

          // ----------- Options for Yosys SMT-LIB2 Generator -------------- //
          YosysUndrivenNetAsInput(true), YosysSmtFlattenHierarchy(true),
          YosysSmtFlattenDatatype(false),
          YosysSmtArrayForRegFile(true),
          YosysSmtStateSort(YosysStateSortT::Datatypes),
          InvariantSynthesisKeepMemory(true), InvariantCheckKeepMemory(true),
          InvariantSynthesisReachableCheckKeepOldInvariant(false),
          YosysSetUndrivenZero(false),

          // ----------- Options for CHCs -------------- //
          ChcWordBlastArray(true), ChcAssumptionsReset(false),
          ChcAssumptionNextState(false), ChcAssumptionEnd(false),

          // ----------- Options for Btor Output -------------- //
          /// CHC, whether to turn array into individual registers
          BtorSingleProperty(true),
          /// CHC, whether to force assumption on the init
          BtorAddCommentsInOutputs(false),

          // ----------- Options for Z3/Grain/ABC Solver -------------- //
          GrainHintsUseCnfStyle(true),

          // ----------- Options for ABC -------------- //
          AbcUseGla(false), AbcGlaTimeLimit(500), AbcGlaFrameLimit(200),
          AbcUseCorr(false), AbcUseAiger(true), AbcMinimizeInv(false),
          AbcAssumptionStyle(AbcAssumptionStyle_t::AigMiterExtraOutput),

          // ----------- Options for Refinement Sanity Checks -------------- //
          SanityCheck_ValueRecorderOverlyConstrained(true),
          SanityCheck_ValueRecorderTriggeredBeforeCommit(true) {}
  } RtlVerifyConfig;

} // namespace ilang

#endif // ILANG_RTL_VERIFY_CONFIG_H__
