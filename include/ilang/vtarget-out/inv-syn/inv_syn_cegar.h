/// \file The header for invariant synthesis --- using CEGAR loop
// ---Hongce Zhang

#ifndef INV_SYN_CEGAR_H__
#define INV_SYN_CEGAR_H__

#include <ilang/smt-inout/yosys_smt_parser.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/inv-syn/sygus/datapoint.h>

#include <string>
#include <memory>

namespace ilang {

/// \brief design statistics information 
struct DesignStatistics {
  /// the number of state variables
  unsigned NumOfDesignStateVars;
  /// the total width of these variables
  unsigned NumOfDesignStateBits;
  /// the number of state variables
  unsigned NumOfExtraStateVars;
  /// the total width of these variables
  unsigned NumOfExtraStateBits;
  // ----------- The timing information ----------------
  /// time for equivalence checking
  double TimeOfEqCheck;
  /// time for validation of invariants
  double TimeOfInvValidate;
  /// time for z3 proving attempt
  double TimeOfInvProof;
  /// the synthesis time of invariants : chc/sygus-chc/sygus-dp
  double TimeOfInvSyn;

  /// Constructor -- reset all values to 0
  DesignStatistics() : 
    NumOfDesignStateVars(0),
    NumOfDesignStateBits(0),
    NumOfExtraStateVars(0),
    NumOfExtraStateBits(0),
    TimeOfEqCheck(0), TimeOfInvValidate(0), 
    TimeOfInvProof(0), TimeOfInvSyn(0) {} 

}; // struct DesignStatistics


/// \brief the implementation of the synthesizer class
class InvariantSynthesizerCegar {

public:
  // -------------------- TYPES ------------------ //
  using _state_sort_t = VlgVerifTgtGenBase::_vtg_config::_state_sort_t;
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
  /// the type of invariant check result
  enum _inv_check_res_t {INV_PROVED, INV_INVALID, INV_UNKNOWN};
  /// additional width info
  typedef std::map<std::string,int> additional_width_info_t;


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
  /// to generate a target to validate the given and synthesize invariants
  void GenerateInvariantVerificationTarget();
  /// to extract verification result 
  void ExtractVerificationResult(bool autodet = true, bool pass = true,
    const std::string & res_file = "", const std::string & mod_inst_name = "");
  /// to generate synthesis target
  void GenerateSynthesisTarget();
  /// to extract reachability test result
  void ExtractSynthesisResult(bool autodet = true, bool reachable = true, 
    const std::string & res_file = "");
  /// run Verification : returns eq true/false
  bool virtual RunVerifAuto(const std::string & script_selection);
  /// run Synthesis : returns reachable/not
  bool virtual RunSynAuto();
  /// to generate synthesis target (for using the whole transfer function)
  void GenerateSynthesisTargetSygusTransFunc(bool enumerate = false);
  /// to generate synthesis target (for using the whole transfer function)
  void GenerateSynthesisTargetSygusDatapoints(bool enumerate = false);
  /// to extract the synthesis attempt
  bool ExtractSygusDatapointSynthesisResultAsCandidateInvariant();
  /// to validate if the previous attempt is good (inductive or not)
  /// return true if the invariants are good/o.w. will auto load to datapoint's pos ex
  _inv_check_res_t ValidateSygusDatapointCandidateInvariant(unsigned timeout = 0);
  /// Try proving candidate invariants
  _inv_check_res_t ProofCandidateInvariants(unsigned timeout = 0, 
    _state_sort_t state_encoding = _state_sort_t::BitVec, bool flatten_dp = false);
  /// set the initial datapoints (can be empty, but we suggest using the sim_trace_extract)
  void SetInitialDatapoint(const TraceDataPoints &dp);
  /// set the sygus name lists (cannot be empty)
  void SetSygusVarnameList(const std::vector<std::string> & sygus_var_name);
  /// Forcing to accept all the candidate invariants
  void AcceptAllCandidateInvariant();
  /// Remove potentially failing candidate invariants (conservative approach remove all candidates)
  void PruneCandidateInvariant();
  /// Supply Verilog candidate invariants
  void SupplyCandidateInvariant(const std::string &vlg);

  // -------------------- ACCESSOR ------------------ //
  /// return back state
  bool in_bad_state() const {return bad_state;}
  /// check state
  bool check_in_bad_state() const ;
  /// Here we directly expose the runnable script names (They will never be used as inputs)
  const std::vector<std::string> & GetRunnableTargetScriptName() const;
  /// Here you can get the design information
  DesignStatistics GetDesignStatistics() const;
  /// Here you can extract the invariants and export them if needed
  const InvariantObject & GetInvariants() const;
  /// Here you can extract the invariants and export them if needed
  const InvariantObject & GetCandidateInvariants() const;
  /// here you can acess the internal datapoint object
  const TraceDataPoints & GetDatapoints() const;
  /// load states -- confirmed invariants
  void LoadInvariantsFromFile(const std::string &fn);
  void LoadCandidateInvariantsFromFile(const std::string &fn);
  void LoadDatapointFromFile(const std::string &fn);
  
protected:
  // -------------------- MEMBERS ------------------ //
  /// the found invariants, in Verilog expression
  InvariantObject inv_obj;
  /// the temporary invariants (that might not be inductive)
  InvariantObject inv_candidate;
  /// the pointer to a cegar object
  std::unique_ptr<CexExtractor> cex_extract;
  /// vlg-module instance name;
  std::string vlg_mod_inst_name;
  /// the status of the loop
  cegar_status status;
  /// the SMT-LIB2 information of the design
  std::shared_ptr<smt::YosysSmtParser> design_smt_info;
  /// the supplementary information
  additional_width_info_t additional_width_info;
  /// is in back state?
  bool bad_state;
  /// the round id
  unsigned round_id;
  /// the runnable script name after each target gen
  std::vector<std::string> runnable_script_name;
  /// verification result
  bool verification_pass;
  /// verification result -- the vcd full name/path
  std::string vcd_file_name;
  /// synthesis result
  bool cex_reachable;
  /// the synthesis result file
  std::string synthesis_result_fn;
  /// the invariant type
  enum cur_inv_tp { NONE, SYGUS_CEX, SYGUS_CHC, CHC } current_inv_type;
  /// the datapoint
  TraceDataPoints datapoints;
  /// the sygus varname
  std::vector<std::string> sygus_vars;
  /// will also convert the above to a set (easier to index)
  std::set<std::string> sygus_vars_set;

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


  // --------------------------------------------------
  // for statistics purpose
  // --------------------------------------------------
  /// time for equivalence checking
  double eqcheck_time;
  /// time for validation of invariants
  double inv_validate_time;
  /// time for z3 proving attempt
  double inv_proof_attempt_time;
  /// the synthesis time of invariants : chc/sygus-chc/sygus-dp
  double inv_syn_time;


}; // class InvariantSynthesizerCegar 

};

#endif // INV_SYN_CEGAR_H__