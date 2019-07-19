/// \file Header Externally Provided Target for inv-syn-check-using cosa
/// to generate a invariant validation target with (externally) provided wrapper template
/// instead of constructing the wrapper ourselves
// Hongce Zhang (hongcez@princeton.edu)


#ifndef COSA_INV_CHECK__
#define COSA_INV_CHECK__


#include <ilang/verilog-in/verilog_analysis_wrapper.h>
#include <ilang/vtarget-out/var_extract.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/supplementary_info.h>

#include "nlohmann/json.hpp"

namespace ilang {

class ExternalCosaInvValidateTargetGen : public VlgVerifTgtGenBase {
public:
  // --------------------- TYPE DEFINITIONS ---------------------------- //
  /// tell us which backend to use
  using backend_selector = VlgVerifTgtGenBase::backend_selector;
  /// Type of configuration
  using vtg_config_t = VlgVerifTgtGenBase::vtg_config_t;
  /// Type of advanced parameter
  using advanced_parameters_t = VlgVerifTgtGenBase::advanced_parameters_t;
  /// Type of record of extra info of a signal
  using ex_info_t = VlgVerifTgtGenBase::ex_info_t;

  // --------------------- CONSTRUCTOR ---------------------------- //
  ///
  /// \param[in] implementation's include path (if it uses `include)
  /// \param[in] verilog's path, currently we only handle situation where all in
  /// the same folder \param[in] name of the top module of the implementation,
  /// leave "" to allow auto analysis \param[in] where to get variable mapping
  /// \param[in] where to get refinement relation
  /// \param[in] output path (ila-verilog, wrapper-verilog, problem.txt,
  /// run-verify-by-???, modify-impl, it there is ) \param[in] pointer to the
  /// ila \param[in] (optional) the default configuration for outputing verilog
  ExternalCosaInvValidateTargetGen(const std::vector<std::string>& implementation_include_path,
                 const std::vector<std::string>& implementation_srcs,
                 const std::string& implementation_top_module,
                 const std::string& refinement_variable_mapping,
                 const std::string& refinement_conditions,
                 const std::string& output_path,
                 const std::string& tmpl_top_mod_name,
                 backend_selector backend, 
                 const vtg_config_t& vtg_config,
                 advanced_parameters_t * adv_ptr = NULL);

  /// no copy constructor, please
  ExternalCosaInvValidateTargetGen(const ExternalCosaInvValidateTargetGen&) = delete;
  /// no assignment, please. I don't want to mess up w. vlg_info_ptr
  ExternalCosaInvValidateTargetGen& operator=(const ExternalCosaInvValidateTargetGen&) = delete;

  // --------------------- DESTRUCTOR ---------------------------- //
  /// release verilog info pointer
  virtual ~ExternalCosaInvValidateTargetGen();

protected:
  // --------------------- MEMBERS ---------------------------- //
  /// implementation include path
  const std::vector<std::string> _vlg_impl_include_path;
  /// implementatino path
  const std::vector<std::string> _vlg_impl_srcs;
  /// implementation top module name
  const std::string _vlg_impl_top_name;
  /// refinement relation - variable mapping path
  const std::string _rf_var_map_name;
  /// refinement relation - condition path
  const std::string _rf_cond_name;
  /// output path, output the ila-verilog, wrapper-verilog, problem.txt,
  /// run-verify-by-???
  const std::string _output_path;
  /// the module name of the provided wrapper template 
  const std::string top_mod_name;
  /// The name of verilog top module instance in the wrapper
  std::string _vlg_mod_inst_name;
  /// A pointer to create verilog analyzer
  VerilogInfo* vlg_info_ptr;
  /// to store the backend
  const backend_selector _backend;
  /// to store the configuration
  vtg_config_t _vtg_config;
  /// to store the advanced parameter configurations
  advanced_parameters_t * _advanced_param_ptr;
  /// to store the generate script name
  std::vector<std::string> runnable_script_name;

protected:
  /// store the vmap info
  nlohmann::json rf_vmap;
  /// store the condition
  nlohmann::json rf_cond;
  /// refinement relation : supplementary information
  VlgTgtSupplementaryInfo sup_info;

protected:
  // --------------------- dealing w. invariants  ---------------------------- //
  /// has guessed synthesized invariant
  const bool has_gussed_synthesized_invariant;
  /// has confirmed synthesized invariant
  const bool has_confirmed_synthesized_invariant;
  /// has rf provided invariant, we cannot decide it at the construction time
  bool has_rf_invariant;
  /// has counterexample provided?
  const bool has_cex;


protected:
  // --------------------- for adding constraints  ---------------------------- //
  /// variable extractor to handle property expressions
  VarExtractor _vext;
  /// record all the referred vlg names, so you can add (*keep*) if needed
  std::map<std::string, ex_info_t> _all_referred_vlg_names;
  /// Counter of property
  unsigned property_counter;
  /// Return a new variable name for property
  std::string new_property_id();
  /// Test if a string represents a Verilog signal name
  bool TryFindVlgState(const std::string& sname);
  /// Modify a token and record its use
  std::string ModifyCondExprAndRecordVlgName(const VarExtractor::token& t);
  /// Parse and modify a condition string
  std::string ReplExpr(const std::string& expr, bool force_vlg_sts = false);

  
protected:
  // --------------------- for rf parsing (not very useful)  ----------------- //
  /// load json from a file name to the given j
  void load_json(const std::string& fname, nlohmann::json& j);
  /// Get instance name from rfmap
  void set_module_instantiation_name();

protected:
  // --------------------- for Verilog export purpose  ---------------------------- //
  /// the wires we are going to add
  std::map<std::string, unsigned> wire_defs;
  /// the output we are going to add
  std::map<std::string, unsigned> output_defs;
  /// the output we are going to add
  std::map<std::string, unsigned> input_defs;
  /// the statements to add
  std::vector<std::string> stmt_defs;
  /// the extra connection to add to instantiation
  std::map<std::string,std::string> implport_def;
  /// the assume property (...) that we are going to have
  std::vector<std::string> assume_props;
  /// assertions
  std::vector<std::string> assert_props;
  /// top verilog module file name
  std::string top_file_name;
  /// chc file name
  std::string cosa_prob_fname;
  // helper function to be implemented by COSA/JASPER
  /// Add an assumption
  virtual void add_an_assumption(const std::string& aspt,
                                 const std::string& dspt);
  /// Add an assertion
  virtual void add_an_assertion(const std::string& asst,
                                const std::string& dspt);
  /// add an invariant object as assertion
  void add_inv_obj_as_assertion( InvariantObject * inv_obj);
  /// add an invariant object as an assumption
  void add_inv_obj_as_assumption( InvariantObject * inv_obj);
  /// add rf inv as assumptions (if there are)
  void add_rf_inv_as_assumption();
  /// add rf inv as assumptions (if there are)
  void add_rf_inv_as_assertion();
  /// add property to vlg
  void add_property(const std::string &precond, const std::set<std::string> & focus_name);
  /// the wires referred needs to be added to wire/ports/implports
  void register_extra_io_wire();
  /// read in wrapper_tmpl_name and generate wrapper_name
  void wrapper_tmpl_substitute(const std::string& wrapper_name, const std::string &wrapper_tmpl_name);
  /// export the rest of modules and also copy includes if any
  void export_modify_verilog(const std::string& wrapper_name);
  /// export the script to run the verification
  void export_script(const std::string& script_name);
  /// export extra things (problem)
  void export_problem(const std::string& extra_name); // only for cosa
  // ----------------------- BAD STATE -------------------- //
public:
  /// check if this module is in a bad state
  bool in_bad_state(void) const { return _bad_state; }
protected:
  /// If it is bad state, return true and display a message
  bool bad_state_return(void);
  /// If it is in a bad state
  bool _bad_state;


public:
  // ----------------------- STEPs -------------------- //
  /// step 1: to verilog
  void ConstructWrapper(
    const std::string& wrapper_name,
    const std::string& wrapper_tmpl_name,
    const std::string& precond,
    const std::set<std::string> & focus_name); // allow you to generalize using drop_var_set feature

  /// step 2: to script/cosa problem
  void GenerateVerifyTarget(
    const std::string& cosa_problem_name,
    const std::string& script_name);

  // ----------------------- ACCESSOR -------------------- //
  /// get the script names (should be only 1)
  const std::vector<std::string> & GetRunnableScriptName() const;
  /// get the parsed suppplementary information
  const VlgTgtSupplementaryInfo & GetSupplementaryInfo() const;
  /// get the D-U-V instance name
  std::string GetDesignUnderVerificationInstanceName() const;

  // okay to instantiate
  void do_not_instantiate() override {};
}; // class ExternalCosaInvValidateTargetGen


}; //namespace ilang

#endif // COSA_INV_CHECK__
