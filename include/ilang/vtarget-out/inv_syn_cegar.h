/// \file The file for managing several targets
// ---Hongce Zhang

#ifndef INV_SYN_CEGAR_H__
#define INV_SYN_CEGAR_H__

//#include <ilang/vtarget-out/cex_extract.h>
#include <ilang/vtarget-out/vtarget_gen.h>

#include <string>

namespace ilang {

/// \brief the implementation of the synthesizer class
class InvariantSynthesizerCegar {

public:
  // -------------------- TYPES ------------------ //
  /// Type of the verification backend
  using backend_selector = VlgVerifTgtGenBase::backend_selector;
  /// Type of configuration
  using vtg_config_t = VlgVerifTgtGenBase::vtg_config_t;
  /// Type of invariant synthesis backend
  typedef enum {Z3, FreqHorn} synthesis_backend_selector;
  /// Type of the cegar loop status
  /// next to verify, wait_for_verify_result
  /// next to synthesis, wait_for_synthesis_result
  typedef enum {NEXT_V, V_RES, NEXT_S, S_RES} cegar_status;

public:
  // -------------------- CONSTRUCTOR ------------------ //
  /// to create an inv-syn target
  InvariantSynthesizerCegar(
    const std::vector<std::string>& implementation_include_path,
    const std::vector<std::string>& implementation_srcs,
    const std::string& implementation_top_module,
    const std::string& refinement_variable_mapping,
    const std::string& refinement_conditions, const std::string& output_path,
    const InstrLvlAbsPtr& ila_ptr, backend_selector backend,
    const vtg_config_t& vtg_config = vtg_config_t(),
    const VerilogGenerator::VlgGenConfig& config =
        VerilogGenerator::VlgGenConfig());
public:
  // -------------------- HELPERs ------------------ //
  // to do things separately, you can provide the run function your self
  // or even do it step by step
  /// to generate targets using the current invariants
  void GenerateVerificationTarget();
  /// to generate targets using the provided invariants
  void GenerateVerificationTarget(const std::vector<std::string> & invs);
  /// to extract result 
  void ExtractVerificationResult(bool autodet = true, bool pass = true, const std::string & res_file = "");
  /// to generate 
  void GenerateSynthesisTarget();
  /// run Verification
  bool virtual RunVerifAuto();
  /// run Synthesis
  void virtual RunSynAuto();

protected:
  /// the found invariants, in Verilog expression
  std::vector<std::string> invariants;
  /// the status of the loop
  cegar_status status;

}; // class InvariantSynthesizerCegar 

};

#endif // INV_SYN_CEGAR_H__