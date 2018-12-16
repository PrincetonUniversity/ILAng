/// \file Header for Verilog Verification Target Generation
/// Functions
///   1. Generate monitors if necessary! (no doing this now)
///   2. Putting together the modules
///      - Wrapper gen: signals, connections
///      - (* keep *)
///   3. Generate the problem.txt
///      -. we don't call verifier internally
///         though we can provide script for users to invoke
///      -. no need to generate a single file for verification
///         although it might be easier
///  we need to copy some of the vlg-out's functionality

#ifndef VTARGET_GEN_IMPL_H__
#define VTARGET_GEN_IMPL_H__

#include <ilang/config.h>

#ifdef JSON_INOUT_ENABLE

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/verilog-in/verilog_analysis_wrapper.h>
#include <ilang/verilog-out/verilog_gen.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/directive.h>
#include <ilang/vtarget-out/var_extract.h>
#include "nlohmann/json.hpp"
#include <list>
#include <map>
#include <unordered_map>
#include <vector>

namespace ilang {

/// \brief Generating a target (just the invairant or for an instruction)
class VlgSglTgtGen {
    // --------------------- TYPE DEFINITION ------------------------ //
    /// Type of the target
    typedef enum { INVARIANTS, INSTRUCTIONS } target_type_t;
    /// Type of the ready condition
    typedef enum { NA = 0, READY_SIGNAL = 1, READY_BOUND = 2, BOTH = 3 }  ready_type_t;
    /// Per func apply counter
    typedef std::map<std::string, unsigned>  func_app_cnt_t;

public:
    // --------------------- CONSTRUCTOR ---------------------------- //
    ///
    /// \param[in] output path (ila-verilog, wrapper-verilog, problem.txt, run-verify-by-???, modify-impl, it there is )
    /// \param[in] pointer to the instruction
    /// \param[in] the default configuration for outputing verilog
    /// \param[in] the variable map
    /// \param[in] the conditions
    /// \param[in] pointer to verify info class
    /// \param[in] verilog module name
    /// \param[in] ila module name
    /// \param[in] verilog wrapper module name
    /// \param[in] implemenation sources, can be used to modify and copy
    VlgSglTgtGen(
      const std::string              & output_path, // will be a sub directory of the output_path of its parent
      const InstrPtr                 & instr_ptr, // which could be an empty pointer, and it will be used to verify invariants
      const VerilogGenerator::VlgGenConfig & config,
      nlohmann::json                 & _rf_vmap,
      nlohmann::json                 & _rf_cond,
      VerilogInfo      *               _vlg_info_ptr,
      const std::string              & vlg_mod_inst_name,
      const std::string              & ila_mod_inst_name,
      const std::string              & wrapper_name,
      const std::vector<std::string> & implementation_srcs
    );

    /// Destructor: do nothing , most importantly it is virtual
    virtual ~VlgSglTgtGen() {}

  protected:
    // --------------------- MEMBERS ---------------------------- //
    // the following are used to store info presented
    /// output path, output the ila-verilog, wrapper-verilog, problem.txt, run-verify-by-???
    const std::string              _output_path; 
    /// The pointer to the instruction that is going to export
    InstrPtr                       _instr_ptr;  // could be nullptr
    /// The name of verilog top module instance in the wrapper
    const std::string              _vlg_mod_inst_name; 
    /// The name of ila-verilog top module instance in the wrapper
    const std::string              _ila_mod_inst_name;
    
    /// Generator for the wrapper module
    VerilogGeneratorBase vlg_wrapper;
    /// Generator for the ila verilog
    VerilogGenerator vlg_ila;
    /// Analyzer for the implementation
    // we don't know the module name, before analyzing the rfmap. so we cannot initialize in the beginning
    VerilogInfo      *vlg_info_ptr;
    /// inteface directive recorder
    IntefaceDirectiveRecorder _idr;
    /// state directive recorder
    StateMappingDirectiveRecorder _sdr;
    /// variable extractor to handle property expressions
    VarExtractor _vext;
    /// refinement relation variable mapping
    nlohmann::json    & rf_vmap;
    /// refinement relation instruction conditions
    nlohmann::json    & rf_cond;
    /// An empty json for default fallthrough cases
    nlohmann::json      empty_json;
    /// record all the referred vlg names, so you can add (*keep*) if needed
    std::vector<std::string> _all_referred_vlg_names;
    /// target type 
    target_type_t       target_type;
    /// a shortcut of whether rf has flush condition set
    bool                has_flush;
    /// ready type
    ready_type_t        ready_type;
    /// func apply counter
    func_app_cnt_t      func_cnt;
    /// max bound , default 127
    unsigned            max_bound;


  private:
    /// Counter of mapping
    unsigned mapping_counter;
    /// Counter of property
    unsigned property_counter;

  protected:
    // --------------------- HELPERS ---------------------------- //
    /// Return a new variable name for mapping
    std::string new_mapping_id();
    /// Return a new variable name for property
    std::string new_property_id();
    /// Get the pointer of a ila state, it must exist
    const ExprPtr IlaGetState(const std::string &sname) const;
    /// Get the pointer of an ila input, it must exist
    const ExprPtr IlaGetInput(const std::string &sname) const;
    /// Get (a,d) width of a memory, if not existing, (0,0)
    std::pair<unsigned,unsigned> GetMemInfo( const std::string &ila_mem_name ) const;
    /// Test if a string represents an ila state name
    bool TryFindIlaState(const std::string &sname);
    /// Test if a string represents an ila input name
    bool TryFindIlaInput(const std::string &sname);
    /// Test if a string represents a Verilog signal name
    bool TryFindVlgState(const std::string &sname);
    /// Modify a token and record its use
    std::string ModifyCondExprAndRecordVlgName(const VarExtractor::token &t );
    /// Check if ila name and vlg name are type compatible (not including special directives)
    static unsigned TypeMatched(const ExprPtr & ila_var, const SignalInfoBase & vlg_var);
    /// get width of an ila node
    static unsigned get_width( const ExprPtr& n );
    /// Parse and modify a condition string 
    std::string ReplExpr(const std::string & expr , bool force_vlg_sts = false) ;
    /// handle a single string map (s-name/equ-string)
    std::string PerStateMap(const std::string & ila_state_name_or_equ, const std::string & vlg_st_name ) ;
    /// handle a var map
    /// will create new variables "m?" and return it
    /// 1.  "ila-state":"**MEM**.?"
    /// 2a. "ila-state":"statename"  --> PerStateMap
    /// 2b. "ila-state":"(cond)&map"   --> PerStateMap
    /// 3.  "ila-state":[ "cond&map" ]
    /// 4.  "ila-state":[ {"cond":,"map":}, ] 
    std::string GetStateVarMapExpr(const std::string & ila_state_name, nlohmann::json & m) ;
    /// Find the current instruction mapping
    nlohmann::json & get_current_instruction_rf();


  protected:
    // --------------- STEPS OF GENERATION ------------------------//
    /// add ila input to the wrapper
    void ConstructWrapper_add_ila_input();
    /// add the vlg input ouput to the wrapper I/O
    void ConstructWrapper_add_vlg_input_output();
    /// add a cycle counter to be used to deal with the end cycle
    void ConstructWrapper_add_cycle_count_moniter();
    /// generate the `define TRUE 1 
    void ConstructWrapper_generate_header();
    /// add state equ assumptions
    void ConstructWrapper_add_varmap_assumptions();
    /// add state equ assertions 
    void ConstructWrapper_add_varmap_assertions();
    /// Add invariants as assumptions
    void ConstructWrapper_add_inv_assumptions();
    /// Add invariants as assertions
    void ConstructWrapper_add_inv_assertions();
    /// Add more assumptions/assertions
    void ConstructWrapper_add_additional_mapping_control();
    /// Generate __ISSUE__, __IEND__, ... signals
    void ConstructWrapper_add_condition_signals();
    /// Add instantiation statement of the two modules
    void ConstructWrapper_add_module_instantiation();
    /// Add instantiation of the memory and put the needed mem implementation in extra export
    /// This also include the assertions
    void ConstructWrapper_add_helper_memory();
    /// Add buffers and assumption/assertions about the 
    void ConstructWrapper_add_uf_buffers();
    /// Call the above functions to make a wrapper (not yet export it)
    void ConstructWrapper() ;

  protected:
    /// get the ila module instantiation string
    std::string ConstructWrapper_get_ila_module_inst();

  protected:
    // ----------------------- MEMBERS for Export ------------------- //
    /// top verilog module name
    std::string top_mod_name;
    /// top verilog module file
    std::string top_file_name;
    /// top verilog module file
    std::string ila_file_name;
    /// design files
    std::vector<std::string> vlg_design_files; // mainly design file


  public:
    /// create the wrapper file
    void virtual Export_wrapper(const std::string & wrapper_name);
    /// export the ila verilog
    void virtual Export_ila_vlg(const std::string & ila_vlg_name);
    /// export the script to run the verification
    void virtual Export_script(const std::string & script_name) = 0;
    /// export extra things (problem)
    void virtual Export_problem(const std::string & extra_name) = 0; // only for cosa
    /// export the memory abstraction (implementation)
    /// Yes, this is also implementation specific, (jasper may use a different one)
    void virtual Export_mem(const std::string & mem_name) = 0;
    /// For jasper, this means do nothing, for yosys, you need to add (*keep*)
    void virtual Export_modify_verilog() = 0;
    /// Take care of exporting all of a single target
    void virtual ExportAll(
        const std::string & wrapper_name,
        const std::string & ila_vlg_name,
        const std::string & script_name,
        const std::string & extra_name,
        const std::string & mem_name);

  protected:
    // helper function to be implemented by COSA/JASPER
    /// Add an assumption
    virtual void add_an_assumption(const std::string & aspt, const std::string & dspt) = 0;
    /// Add an assertion
    virtual void add_an_assertion (const std::string & asst, const std::string & dspt) = 0;

  private:
    // Do not instantiate 
    virtual void do_not_instantiate(void) = 0;

  // ----------------------- BAD STATE -------------------- //
  public:
    /// check if this module is in a bad state
    bool in_bad_state(void) const { return _bad_state; }
  protected:
    /// If it is bad state, return true and display a message
    bool bad_state_return(void); 
  private:
    /// If it is in a bad state
    bool _bad_state;

}; // class VlgSglTgtGen


  /// brief Class of Verilog verification target generation, not to be used outside
class VlgVerifTgtGen : public VlgVerifTgtGenBase {
  // --------------------- TYPE DEFINITIONS ---------------------------- //
    /// tell us which backend to use
    using backend_selector = VlgVerifTgtGenBase::backend_selector;
  public:
  // --------------------- CONSTRUCTOR ---------------------------- //
    ///
    /// \param[in] implementation's include path (if it uses `include)
    /// \param[in] verilog's path, currently we only handle situation where all in the same folder
    /// \param[in] name of the top module of the implementation, leave "" to allow auto analysis
    /// \param[in] where to get variable mapping 
    /// \param[in] where to get refinement relation
    /// \param[in] output path (ila-verilog, wrapper-verilog, problem.txt, run-verify-by-???, modify-impl, it there is )
    /// \param[in] pointer to the ila
    /// \param[in] (optional) the default configuration for outputing verilog
    VlgVerifTgtGen(
      const std::vector<std::string> & implementation_include_path,
      const std::vector<std::string> & implementation_srcs,
      const std::string              & implementation_top_module,
      const std::string              & refinement_variable_mapping,
      const std::string              & refinement_conditions,
      const std::string              & output_path,
      const InstrLvlAbsPtr           & ila_ptr,
      backend_selector                 backend,
      const VerilogGenerator::VlgGenConfig& config = VerilogGenerator::VlgGenConfig() 
      );

    /// no copy constructor, please
    VlgVerifTgtGen(const VlgVerifTgtGen &) = delete;
    /// no assignment, please. I don't want to mess up w. vlg_info_ptr
    VlgVerifTgtGen & operator=(const VlgVerifTgtGen &) = delete;


  // --------------------- DESTRUCTOR ---------------------------- //
    /// release verilog info pointer
    virtual ~VlgVerifTgtGen();


  protected:
  // --------------------- MEMBERS ---------------------------- //
    /// implementation include path
    const std::vector<std::string> _vlg_impl_include_path;
    /// implementatino path
    const std::vector<std::string> _vlg_impl_srcs;
    /// implementation top module name
    const std::string              _vlg_impl_top_name;
    /// refinement relation - variable mapping path
    const std::string              _rf_var_map_name;
    /// refinement relation - condition path
    const std::string              _rf_cond_name;
    /// output path, output the ila-verilog, wrapper-verilog, problem.txt, run-verify-by-???
    const std::string              _output_path; 
    /// The pointer to the instruction that is going to export
    const InstrLvlAbsPtr         & _ila_ptr;
    /// The name of verilog top module instance in the wrapper
    std::string                    _vlg_mod_inst_name; 
    /// The name of ila-verilog top module instance in the wrapper
    std::string                    _ila_mod_inst_name;
    /// A pointer to create verilog analyzer
    VerilogInfo      *             vlg_info_ptr;
    /// to store the verilog configuration
    VerilogGenerator::VlgGenConfig _cfg;
    /// to store the backend
    backend_selector               _backend;


protected:
    /// store the vmap info
    nlohmann::json rf_vmap;
    /// store the condition
    nlohmann::json rf_cond;

  public:
  // --------------------- METHODS ---------------------------- //
    /// Generate everything 
    // only set the info pointer within it and delete it afterwards
    void GenerateTargets(void);
    /// Return true if it is in bad state
    bool in_bad_state(void) const { return _bad_state; }

  protected:
    /// If it is bad state, return true and display a message
    bool bad_state_return(void); 
    /// load json from a file name to the given j
    void load_json(const std::string & fname, nlohmann::json & j);
    /// Get instance name from rfmap
    void set_module_instantiation_name();

  private:
    /// If it is in a bad state
    bool _bad_state;
    /// okay it is fine to instantiate this class
    virtual void do_not_instantiate() override {}

}; // class VlgVerifTgtGen


}; // namespace ilang


#endif // JSON_INOUT_ENABLE

#endif //VTARGET_GEN_IMPL_H__