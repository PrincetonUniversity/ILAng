/// \file The header for invariant synthesis --- using CEGAR loop
// ---Hongce Zhang

#ifndef ILANG_VTARGET_OUT_INV_SYN_CEGAR_H__
#define ILANG_VTARGET_OUT_INV_SYN_CEGAR_H__

#include <ilang/config.h>
#ifdef INVSYN_INTERFACE

#include <ilang/smt-inout/yosys_smt_parser.h>
#include <ilang/vtarget-out/design_stat.h>
#include <ilang/vtarget-out/vtarget_gen.h>

#include <memory>
#include <string>

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
  using synthesis_backend_selector =
      VlgVerifTgtGenBase::synthesis_backend_selector;
  /// Type of the cegar loop status
  /// next to verify, wait_for_verify_result
  /// next to synthesis, wait_for_synthesis_result
  typedef enum { NEXT_V, V_RES, NEXT_S, S_RES, DONE, FAILED } cegar_status;
  /// Type of advanced parameter
  using advanced_parameters_t = VlgVerifTgtGenBase::advanced_parameters_t;
  /// the type of invariant check result
  enum _inv_check_res_t { INV_PROVED, INV_INVALID, INV_UNKNOWN };
  /// additional width info
  typedef std::map<std::string, int> additional_width_info_t;

public:
  // -------------------- CONSTRUCTOR ------------------ //
  /// to create an inv-syn target
  InvariantSynthesizerCegar(
      const std::vector<std::string>& implementation_include_path,
      const std::vector<std::string>& implementation_srcs,
      const std::string& implementation_top_module,
      const std::string& refinement_variable_mapping,
      const std::string& refinement_conditions, const std::string& output_path,
      const InstrLvlAbsPtr& ila_ptr, verify_backend_selector vbackend,
      synthesis_backend_selector sbackend,
      const vtg_config_t& vtg_config = vtg_config_t(),
      const VerilogGenerator::VlgGenConfig& config =
          VerilogGenerator::VlgGenConfig());
  /// no copy constructor, please.
  InvariantSynthesizerCegar(const InvariantSynthesizerCegar&) = delete;
  /// no assignment, please.
  InvariantSynthesizerCegar&
  operator=(const InvariantSynthesizerCegar&) = delete;

public:
  // -------------------- HELPERs ------------------ //
  // to do things separately, you can provide the run function your self
  // or even do it step by step
  /// to generate targets using the current invariants
  void GenerateVerificationTarget();
  /// to generate targets using the provided invariants
  void GenerateVerificationTarget(const std::vector<std::string>& invs);
  /// to generate a target to validate the given and synthesize invariants
  void GenerateInvariantVerificationTarget();
  /// to extract verification result
  void ExtractVerificationResult(bool autodet = true, bool pass = true,
                                 const std::string& res_file = "",
                                 const std::string& mod_inst_name = "");

  /// genenate a target to extract smt
  void GenerateTargetAndExtractSmt();
  /// get the width of a certain state
  unsigned QueryRtlStateWidth(const std::string& name) const;

  /// remove some states from cex
  void CexGeneralizeRemoveStates(const std::vector<std::string>&);
  /// to generate synthesis target
  void GenerateSynthesisTarget();
  /// to extract reachability test result
  void ExtractSynthesisResult(bool autodet = true, bool reachable = true,
                              const std::string& res_file = "");
  /// to extract reachability test result, this will extract to candidate
  /// invariant
  void ExtractAbcSynthesisResultForEnhancement(InvariantInCnf& incremental_cnf,
                                               bool autodet = true,
                                               bool reachable = true);

  /// run Verification : returns eq true/false
  bool virtual RunVerifAuto(const std::string& script_selection,
                            const std::string& pid_fname = "",
                            bool run_test = false,
                            unsigned timeout = 0);
  /// run Synthesis : returns reachable/not
  bool virtual RunSynAuto(bool run_test = false);

  /// Forcing to accept all the candidate invariants
  void AcceptAllCandidateInvariant();
  /// Remove potentially failing candidate invariants (conservative approach
  /// remove all candidates)
  void PruneCandidateInvariant();
  /// Supply Verilog candidate invariants
  void SupplyCandidateInvariant(const std::string& vlg);
  /// Clear all the candidate invariants
  void ClearAllCandidateInvariants();

  // -------------------- GrainChc ------------------ //
  void ChangeGrainSyntax(const std::vector<std::string>& syn);
  /// generate enhancement target and run it
  /// return false, if grain fails
  bool WordLevelEnhancement(const InvariantInCnf& incremental_cnf,
                            bool run_test = false);
  /// get the current inv in cnf
  const InvariantInCnf& GetCurrentCnfEnhance() const;
  /// merge cnfs
  void MergeCnf(const InvariantInCnf& incremental_cnf);
  /// extra variable for enhancement, so not really a cnf
  void ExtractInvariantVarForEnhance(
      size_t inv_idx, InvariantInCnf& incremental_cnf, bool per_clause,
      const std::set<std::string>& vars_to_remove = {});

  // -------------------- ACCESSOR ------------------ //
  /// return back state
  bool in_bad_state() const { return bad_state; }
  /// check state
  bool check_in_bad_state() const;
  /// load the smt_design file
  void LoadDesignSmtInfo(const std::string& fn);
  /// Here we directly expose the runnable script names (They will never be used
  /// as inputs)
  const std::vector<std::string>& GetRunnableTargetScriptName() const;
  /// Here you can restore the design information
  void LoadPrevStatisticsState(const std::string& fn);
  /// Here you can get the design information
  DesignStatistics GetDesignStatistics() const;
  /// Here you can extract the invariants and export them if needed
  const InvariantObject& GetInvariants() const;
  /// remove a confirmed invariant
  void RemoveInvariantsByIdx(size_t idx);
  /// Here you can extract the invariants and export them if needed
  const InvariantObject& GetCandidateInvariants() const;
  /// load confirmed invariants from file
  void LoadInvariantsFromFile(const std::string& fn);
  /// load invariants as candidates from file
  void LoadCandidateInvariantsFromFile(const std::string& fn);

protected:
  // -------------------- MEMBERS ------------------ //
  /// the found invariants, in Verilog expression
  InvariantObject inv_obj;
  /// the found invariants, in CNF (only for ABC), will be merged to
  InvariantInCnf inv_cnf;
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
  enum cur_inv_tp { NONE, GRAIN_CHC, CHC, CEGAR_ABC } current_inv_type;

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
  /// the enhance ment time
  double inv_enhance_time;
  /// the series of synthesis time
  std::vector<double> inv_syn_time_series;

public:
  /// total cands there are
  long long total_grain_cand;

}; // class InvariantSynthesizerCegar

}; // namespace ilang

#endif // INVSYN_INTERFACE

#endif // ILANG_VTARGET_OUT_INV_SYN_CEGAR_H__
