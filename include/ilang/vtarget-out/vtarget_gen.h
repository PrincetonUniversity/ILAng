/// \file Header for wrapper for verilog verification target generation
/// This is used to avoid include json explicitly
// --- Hongce Zhang

#ifndef ILANG_VTARGET_OUT_VTARGET_GEN_H__
#define ILANG_VTARGET_OUT_VTARGET_GEN_H__

#include <ilang/config.h>
#include <ilang/rtl_verify.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/verilog-out/verilog_gen.h>
#include <ilang/vtarget-out/inv-syn/cex_extract.h>
#include <ilang/vtarget-out/inv-syn/inv_obj.h>

namespace ilang {

/// \brief VlgVerifTgtGenBase: do nothing, should not instantiate
class VlgVerifTgtGenBase {
  // ----------------------- Type Definition ----------------------- //
public:
  /// Type of record of extra info of a signal
  /// Typically this should not be used (expert only feature)
  struct ex_info_t {
    std::string range;
    ex_info_t(const std::string& r) : range(r) {}
  };


  /// decide if a backend needs Yosys
  static bool backend_needs_yosys(ModelCheckerSelection b) {
    return (int(b) & int(ModelCheckerSelection::YOSYS)) ==
           int(ModelCheckerSelection::YOSYS);
  }

  /// Type of invariant synthesis backend
  /*enum class synthesis_backend_selector {
    // Z3       = int(ModelCheckerSelection::Z3PDR)       ^
  int(ModelCheckerSelection::YOSYS), // 01001 GRAIN    =
  int(ModelCheckerSelection::GRAIN_SYGUS) ^ int(ModelCheckerSelection::YOSYS), // 01100
    ABC      = int(ModelCheckerSelection::ABCPDR)      ^
  int(ModelCheckerSelection::YOSYS), // 10000 ELDERICA =
  int(ModelCheckerSelection::ELD_CEGAR)   ^ int(ModelCheckerSelection::YOSYS), // 01010
    NOSYN    = int(ModelCheckerSelection::YOSYS) // 1000000 } ;*/
  /// Type of the chc target
  enum class _chc_target_t { CEX, INVCANDIDATE, GENERAL_PROPERTY };
  

  /// Advanced parameters used for invariant synthesizer
  /// should not be used by generat
  /// NOTE: this function can be inherited
  /// and only expose a visible interface to the outside
  typedef struct _adv_parameters {
    /// invariant object
    InvariantObject* _inv_obj_ptr;
    /// candidate invariants object
    InvariantObject* _candidate_inv_ptr;
    /// counterexample object
    CexExtractor* _cex_obj_ptr;
    /// The default constructor for default values
    _adv_parameters()
        : _inv_obj_ptr(NULL), _candidate_inv_ptr(NULL), _cex_obj_ptr(NULL) {}
    /// virtual destructor
    virtual ~_adv_parameters(){};
  } advanced_parameters_t;

public:
  // ----------------------- Constructor/Destructor ----------------------- //
  // constructor : do nothing
  VlgVerifTgtGenBase() {}
  // destructor : do nothing (make it virtual !!!)
  virtual ~VlgVerifTgtGenBase() {}
  /// check if a backend selector is valid
  static bool isValidVerifBackend(ModelCheckerSelection vbackend);

private:
  // avoid instantiation
  virtual void do_not_instantiate(void) = 0;
}; // class VlgVerifTgtGenBase

class VerilogVerificationTargetGenerator {

public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  ///
  /// \param[in] implementation's include path (if it uses `include)
  /// \param[in] verilog's path, currently we only handle situation where all in
  ///   the same folder
  /// \param[in] name of the top module of the implementation,
  ///   leave "" to allow auto analysis
  /// \param[in] where to get variable mapping
  /// \param[in] where to get refinement relation
  /// \param[in] output path (ila-verilog, wrapper-verilog, problem.txt,
  ///   run-verify-by-???, modify-impl, it there is )
  /// \param[in] pointer to the ila
  /// \param[in] the backend selector
  /// \param[in] (optional) the default
  ///   configuration for outputing verilog
  VerilogVerificationTargetGenerator(
      const std::vector<std::string>& implementation_include_path,
      const std::vector<std::string>& implementation_srcs,
      const std::string& implementation_top_module,
      const std::string& refinement_variable_mapping,
      const std::string& refinement_conditions, const std::string& output_path,
      const InstrLvlAbsPtr& ila_ptr, ModelCheckerSelection backend,
      const RtlVerifyConfig& vtg_config = RtlVerifyConfig(),
      const VerilogGenerator::VlgGenConfig& config =
          VerilogGenerator::VlgGenConfig());
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

#endif // ILANG_VTARGET_OUT_VTARGET_GEN_H__
