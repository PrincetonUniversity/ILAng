/// \file Header Externally Provided Target for inv-syn
/// to be specific:
///     1. reachability : add cex assertion, add wires / connect
///         so you need to analyze the low level design indeed, but
///         the top level one: add to placeholder (%assert%) (%declare%)
///         the lowlevel one, do it according to vlg_mod
///         
///         (then generate verilog -> smt -> chc )-> auto run -> ( extract result -> to inv_obj )
///
///     2. eq check : add inv_obj as assumptions (%assumpt%) ?  to a tcl I think is enough
///                     push to server, run it, generate vcd (how?) fetch back, 
///                     cex_extract to extract the counterexample
///
///

#ifndef LOOP_EXTERN_H__
#define LOOP_EXTERN_H__

#include <ilang/smt-inout/yosys_smt_parser.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/inv-syn/sygus/datapoint.h>
#include <ilang/vtarget-out/inv-syn/sygus/sim_trace_extract.h>
#include <ilang/vtarget-out/inv-syn-extern-loop/cvc4_sygus.h>
#include <ilang/vtarget-out/design_stat.h>

// intentionally hide the header of yosys_chc.h here

namespace ilang
{

class InvariantSynthesizerExternalCegar {

public:
  // -------------------- TYPES ------------------ //
  using _state_sort_t = VlgVerifTgtGenBase::_vtg_config::_state_sort_t;
  /// Type of the verification backend
  using verify_backend_selector = VlgVerifTgtGenBase::backend_selector;
  /// Type of configuration
  using vtg_config_t = VlgVerifTgtGenBase::vtg_config_t;
  /// Type of invariant synthesis backend
  using synthesis_backend_selector = VlgVerifTgtGenBase::synthesis_backend_selector;
	/// Type of advanced parameter
  using advanced_parameters_t = VlgVerifTgtGenBase::advanced_parameters_t;
  /// the type of invariant check result
  enum _inv_check_res_t {INV_PROVED, INV_INVALID, INV_UNKNOWN};
  /// additional width info
  typedef std::map<std::string,int> additional_width_info_t;
  /// the correction type
  using correction_t = Cvc4SygusBase::correction_t;


public:
  // -------------------- CONSTRUCTOR ------------------ //
  /// to create an inv-syn target
  InvariantSynthesizerExternalCegar(
    const std::vector<std::string>& implementation_include_path,
    const std::vector<std::string>& implementation_srcs,
    const std::string& implementation_top_module,
    const std::string& refinement_variable_mapping,
    const std::string& refinement_conditions,
		const std::string& output_path,
		const std::string& tmpl_top_mod_name,
    verify_backend_selector vbackend,
    synthesis_backend_selector sbackend,
    const vtg_config_t& vtg_config = vtg_config_t());
  /// no copy constructor, please.
  InvariantSynthesizerExternalCegar(const InvariantSynthesizerExternalCegar&) = delete;
  /// no assignment, please.
  InvariantSynthesizerExternalCegar& operator=(const InvariantSynthesizerExternalCegar&) = delete;
  
  // -------------------- HELPERs ------------------ //
  /// to generate targets using the current invariants
  void ExportInvariantsToJasperAssumptionFile(const std::string & fn,
	  const std::string & var_fn, const std::map<std::string,std::string> & repl_lists = std::map<std::string,std::string>());
	/// load return counterexample from file
	void LoadCexFromFile(const std::string & fn);

  // -------------------- CEGAR CHC ------------------ //
	/// generate chc target
	void GenerateChcSynthesisTarget(const std::string & precond);
	/// generate chc target -- FreqHorn
  void GenerateChcSynthesisTarget(const std::string & precond,
    const std::string& cnf_name, const InvariantInCnf & inv_cnf);
	/// run Synthesis : returns reachable/not
	bool virtual RunSynAuto(bool isSyGuS = false, bool use_freqhorn = false);
  /// to extract reachability test result
  void ExtractSynthesisResult(bool use_freqhorn, bool autodet = true, bool reachable = true, 
    const std::string & res_file = "", bool isCvc4Syn = false);
  /// parse a Z3 invariant for enhancement (for ABC, please use ExtractAbcSynthesisResult instead)
  static void ExtractInvariantVarForEnhance(const std::string & vexpr, InvariantInCnf& incremental_cnf , bool per_clause);
  void ExtractInvariantVarForEnhance(size_t inv_idx, InvariantInCnf& incremental_cnf , bool per_clause);
  void VarlistToCnf(const std::set<std::string> & var_list, InvariantInCnf& incremental_cnf) const;

  // -------------------- CEGAR ABC ------------------ //
	/// generate abc target
  void GenerateAbcSynthesisTarget( bool useAiger, bool useGla, bool useCorr, unsigned gla_frame, unsigned gla_time,
    const std::set<std::string> & focus_set = std::set<std::string>() );
  _inv_check_res_t RunSynAbcAuto(unsigned timeout);
  void JumpStart_FromExtract(bool cex_r);
  bool ExtractAbcSynthesisResult(InvariantInCnf & incremental_cnf, bool use_aiger, bool use_gla,
    const InvariantInCnf & inv_cnf);
  
  void GenerateCexSimplifyTarget(const std::string precond, const std::set<std::string> & removal_set );
  _inv_check_res_t RunVerifyAuto(unsigned timeout);
  void AcceptNegCex(const std::set<std::string> & focus_var);

  // -------------------- FREQHORN CHC ------------------ //
	/// generate freqchc target
	void GenerateFreqhornChcSynthesisTarget(const std::string & precond);
  /// to extract reachability test result
  void ExtractFreqhornSynthesisResult(bool autodet = true, bool reachable = true, 
    const std::string & res_file = "");

  // -------------------- SYGUS ------------------ //
  /// this function tells you what name are truly states
  void FindRegAmongNames(
    const std::string & top_module_instance_name,
    std::set<std::string> & nameset);
  /// set the sygus name lists (cannot be empty)
  void SetSygusVarnameList(const std::vector<std::string> & sygus_var_name);
  /// set the sygus name lists (but also auto-add width info)
  std::set<std::string> SetSygusVarnameListAndDeduceWidth(
    const std::vector<std::string> & sygus_var_name, 
    const std::string & top_module_instance_name);

  /// import datapoints from file (to the pos example)
  void ImportDatapointsFromFile(const std::string & fn);
  /// Remove potentially failing candidate invariants (conservative approach remove all candidates)
  void PruneCandidateInvariant(const std::set<std::string> &drop_names = std::set<std::string>());
  /// remove all of them
  void RemoveAllCandidateInvariant();
  /// to generate synthesis target (for using the data points)
  void GenerateSynthesisTargetSygusDatapoints(
    const std::set<std::string> &drop_names,
    const Cvc4Syntax & syntax,
    bool enumerate = false);
  /// to generate synthesis target (for using the whole transfer function)
  void GenerateSynthesisTargetSygusTransFunc(
    const std::set<std::string> &drop_names,
    const Cvc4Syntax & syntax,
    bool enumerate = false);
  /// to generate targets using the current invariants
  void ExportCandidateInvariantsToJasperAssertionFile(
    const std::string & precond,
    const std::string & fn,
	  const std::string & var_fn, const std::string & pn_file);
  /// load inv pos ex from simtrace
  void LoadDatapointPosExFromSim(const SimTraceExtractor & sim);
  /// to extract the synthesis attempt
  bool ExtractSygusDatapointSynthesisResultAsCandidateInvariant(const std::string & duv_inst_name);
  /// load design smt info from a given design file 
  void LoadDesignSmtInfoFromSmt(const std::string & fn);
  /// export the cex check to make sure cex is unreachable
  void ExportCexCheck(
    const std::string & precond,
    const std::string & assertfile, const std::string &propfile,
    const std::set<std::string> &drop_names );
  /// accept all candidate invariants as confirmed ones
  void AcceptAllCandidateInvariant();

  /// here you can acess the internal datapoint object
  const TraceDataPoints & GetDatapoints() const;
  /// Here you can extract the invariants and export them if needed
  const InvariantObject & GetCandidateInvariants() const;

  // -------------------- ACCESSOR ------------------ //
  /// return back state
  bool in_bad_state() const {return bad_state;}
  /// check state
  bool check_in_bad_state() const ;
  /// Here you can get the design information
  DesignStatistics GetDesignStatistics() const;
  /// Here you can restore the previous statistics
  void LoadPrevStatisticsState(const std::string & fn);
  /// Here you can extract the invariants and export them if needed
  const InvariantObject & GetInvariants() const;
  /// load states -- confirmed invariants
  void LoadInvariantsFromFile(const std::string &fn);
  void LoadCandidateInvariantsFromFile(const std::string &fn);
  void LoadDatapointFromFile(const std::string &fn);

protected:
	// -------------------- MEMBERS ------------------ //
  /// the found invariants, in Verilog expression
  InvariantObject inv_obj;
  /// the pointer to a cegar object
  std::unique_ptr<CexExtractor> cex_extract;
  /// vlg-module instance name;
  std::string vlg_mod_inst_name;
  /// the SMT-LIB2 information of the design
  std::shared_ptr<smt::YosysSmtParser> design_smt_info;
  /// the supplementary information
  additional_width_info_t additional_width_info;
  /// is in back state?
  bool bad_state;
  /// the runnable script name after each target gen
  std::vector<std::string> runnable_script_name;
  /// the corrections we need to apply from sygus_gen
  correction_t sygus_gen_corrections;

  // --------------------------------------------------
  // for SyGuS
  // --------------------------------------------------

  /// the temporary invariants (that might not be inductive)
  InvariantObject inv_candidate;
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
	/// template top module name
	std::string tmpl_top_module_name;
  /// the verification backend
  verify_backend_selector v_backend;
  /// the synthesis backend selection
  synthesis_backend_selector s_backend; 
  /// the target generator configuration
  vtg_config_t _vtg_config;

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
  /// the time in the series
  std::vector<double> inv_syn_time_series;


  // --------------------------------------------------
  // for looping purpose
  // --------------------------------------------------
	/// synthesis result redirect file
	std::string synthesis_result_fn;
	///
	bool cex_reachable;
  
public:
  long long total_freqhorn_cand;

}; // class InvariantSynthesizerExternalCegar 

}; // namespace ilang


#endif // LOOP_EXTERN_H__
