/// \file The header for invariant synthesis --- using CEGAR loop
// ---Hongce Zhang

#ifndef INV_SYN_CEGAR_H__
#define INV_SYN_CEGAR_H__

#include <ilang/vtarget-out/vtarget_gen.h>

#include <string>
#include <memory>

namespace ilang {

/// \brief the implementation of the synthesizer class
class InvariantSynthesizerCegar {

public:
  // -------------------- TYPES ------------------ //
  /// Type of the verification backend
  using verify_backend_selector = VlgVerifTgtGenBase::backend_selector;
  /// Type of configuration
  using vtg_config_t = VlgVerifTgtGenBase::vtg_config_t;
  /// Type of invariant synthesis backend
  using synthesis_backend_selector = VlgVerifTgtGenBase::synthesis_backend_selector;
  /// Type of the cegar loop status
  /// next to verify, wait_for_verify_result
  /// next to synthesis, wait_for_synthesis_result
  typedef enum {NEXT_V, V_RES, NEXT_S, S_RES, DONE, FAILED} cegar_status;
  /// Type of advanced parameter
  using advanced_parameters_t = VlgVerifTgtGenBase::advanced_parameters_t;

public:
  // -------------------- CONSTRUCTOR ------------------ //
  /// to create an inv-syn target
  InvariantSynthesizerCegar(
    const std::vector<std::string>& implementation_include_path,
    const std::vector<std::string>& implementation_srcs,
    const std::string& implementation_top_module,
    const std::string& refinement_variable_mapping,
    const std::string& refinement_conditions, const std::string& output_path,
    const InstrLvlAbsPtr& ila_ptr,
    verify_backend_selector vbackend,
    synthesis_backend_selector sbackend,
    const vtg_config_t& vtg_config = vtg_config_t(),
    const VerilogGenerator::VlgGenConfig& config =
        VerilogGenerator::VlgGenConfig());
  /// no copy constructor, please.
  InvariantSynthesizerCegar(const InvariantSynthesizerCegar&) = delete;
  /// no assignment, please.
  InvariantSynthesizerCegar& operator=(const InvariantSynthesizerCegar&) = delete;
  
public:
  // -------------------- HELPERs ------------------ //
  // to do things separately, you can provide the run function your self
  // or even do it step by step
  /// to generate targets using the current invariants
  void GenerateVerificationTarget();
  /// to generate targets using the provided invariants
  void GenerateVerificationTarget(const std::vector<std::string> & invs);
  /// to extract verification result 
  void ExtractVerificationResult(bool autodet = true, bool pass = true,
    const std::string & res_file = "", const std::string & mod_inst_name = "");
  /// to generate synthesis target
  void GenerateSynthesisTarget();
  /// to extract reachability test result
  void ExtractSynthesisResult(bool autodet = true, bool reachable = true, 
    const std::string & res_file = "");
  /// run Verification : returns eq true/false
  bool virtual RunVerifAuto();
  /// run Synthesis : returns reachable/not
  bool virtual RunSynAuto();
  /// return back state
  bool in_bad_state() const {return bad_state;}
  /// check state
  bool check_in_bad_state() const ;

protected:
  // -------------------- MEMBERS ------------------ //
  /// the found invariants, in Verilog expression
  InvariantObject inv_obj;
  /// the pointer to a cegar object
  std::unique_ptr<CexExtractor> cex_extract;
  /// vlg-module instance name;
  std::string vlg_mod_inst_name;
  /// the status of the loop
  cegar_status status;
  /// is in back state?
  bool bad_state;
  /// the round id
  unsigned round_id;

  // --------------------------------------------------
  // for book-keeping purpose
  // --------------------------------------------------
  /// path for verilog includes
  std::vector<std::string> implementation_incl_path;
  /// path for verilog sources
  std::vector<std::string> implementation_srcs_path;
  /// the top module name
  std::string implementation_top_module_name;
  /// path to the variable mapping file
  std::string refinement_variable_mapping_path;
  /// path to the conditions
  std::string refinement_condition_path;
  /// the output path (must exists)
  std::string _output_path;
  /// the pointer to ILA
  InstrLvlAbsPtr _host;
  /// the verification backend
  verify_backend_selector v_backend;
  /// the synthesis backend selection
  synthesis_backend_selector s_backend; 
  /// the target generator configuration
  vtg_config_t _vtg_config;
  /// the verilog gnerator configuration
  VerilogGenerator::VlgGenConfig _vlg_config;

}; // class InvariantSynthesizerCegar 

};

#endif // INV_SYN_CEGAR_H__