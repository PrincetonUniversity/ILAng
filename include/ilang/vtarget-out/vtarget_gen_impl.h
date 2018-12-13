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


#ifdef JSON_INOUT_ENABLE

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/verilog-in/verilog_analysis_wrapper.h>
#include <ilang/verilog-out/verilog_gen.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/interface_directive.h>
#include <ilang/vtarget-out/var_extract.h>
#include "nlohmann/json.hpp"
#include <list>
#include <map>
#include <unordered_map>
#include <vector>

namespace ilang {

/// \brief Generating a target (just the invairant or for an instruction)
class VlgSglTgtGen {

public:
    // --------------------- CONSTRUCTOR ---------------------------- //
    ///
    /// \param[in] output path (ila-verilog, wrapper-verilog, problem.txt, run-verify-by-???, modify-impl, it there is )
    /// \param[in] pointer to the ila
    /// \param[in] the default configuration for outputing verilog
    VlgVerifTgtGen(
      const std::string              & output_path, // will be a sub directory of the output_path of its parent
      const InstrPtr                 & instr_ptr, // which could be an empty pointer, and it will be used to verify invariants
      const VerilogGenerator::VlgGenConfig & config,
      nlohmann::json                 & _rf_vmap,
      nlohmann::json                 & _rf_cond,
      VerilogInfo      *               _vlg_info_ptr,
      const std::string              & vlg_mod_inst_name,
      const std::string              & ila_mod_inst_name
    );

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
    /// record all the referred vlg names, so you can add (*keep*) if needed
    const std::vector<std::string> _all_referred_vlg_names

  private:
    /// Counter of mapping
    unsigned mapping_counter;
    /// Counter of property
    unsigned property_counter;

  protected:
    /// Return a new variable name for mapping
    std::string new_mapping_id();
    /// Return a new variable name for property
    std::string new_property_id();

  protected:
    // --------------- STEPS OF GENERATION ------------------------//
    /// add ila input to the wrapper
    void ConstructWrapper_add_ila_input();
    /// add 
    std::string ConstructWrapper_get_ila_module_inst();
    /// 
    void ConstructWrapper_add_vlg_input_output();
    /// add a cycle counter to be used to deal with the end cycle
    void ConstructWrapper_add_cycle_count_moniter();
    /// generate the `define TRUE 1 
    void ConstructWrapper_generate_header();
    /// add state equ assumptions
    void ConstructWrapper_add_varmap_assumptions();
    /// add state equ assertions 
    void ConstructWrapper_add_varmap_assertions(bool has_flush);
    /// Add invariants as assumptions
    void ConstructWrapper_add_inv_assumptions(bool has_flush);
    /// Add invariants as assertions
    void ConstructWrapper_add_inv_assertions(void);
    /// 
    void ConstructWrapper_add_additional_mapping_control(void);
    /// Generate __ISSUE__, __IEND__, ... signals
    void ConstructWrapper_add_condition_signals(void);
    /// Add instantiation statement of the two modules
    void ConstructWrapper_add_module_instantiation(void);
    /// Add instantiation of the memory and put the needed mem implementation in extra export
    void ConstructWrapper_add_helper_memory(void);
    /// Call the above functions to make a wrapper (not yet export it)
    void ConstructWrapper(void) ;
  public:
    void ExportWrapper(void);
    void ExportIlaVlg(void);
    void ExportScript(void);
    void ExportExtra(void);
    void ExportMem

  protected:
    // helper function to be implemented by COSA/JASPER
    /// Add an assumption
    virtual void add_an_assumption(const std::string & aspt) = 0;
    /// Add an assertion
    virtual void add_an_assertion (const std::string & asst) = 0;

  private:
    // Do not instantiate 
    virtual void do_not_instantiate(void) = 0;

}; // class VlgSglTgtGen


  /// brief Class of Verilog verification target generation, not to be used outside
class VlgVerifTgtGen : public VlgVerifTgtGenBase {
  // --------------------- TYPE DEFINITIONS ---------------------------- //
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
      const InstrPtr                 & instr_ptr,
      const VerilogGenerator::VlgGenConfig& config = VlgGenConfig() 
      );

    /// no copy constructor, please
    VlgVerifTgtGen(const VlgVerifTgtGen &) = delete;
    /// no assignment, please. I don't want to mess up w. vlg_info_ptr
    VlgVerifTgtGen & operator=(const VlgVerifTgtGen &) = delete;


  // --------------------- DESTRUCTOR ---------------------------- //
    /// release verilog info pointer
    ~VlgVerifTgtGen() { if(vlg_info_ptr) delete vlg_info_ptr; }


  protected:
  // --------------------- MEMBERS ---------------------------- //
    /// implementation include path
    const std::vector<std::string> _vlg_impl_include_path;
    /// implementatino path
    const std::string<std::string> _vlg_impl_srcs;
    /// implementation top module name
    const std::string              _vlg_impl_top_name;
    /// refinement relation - variable mapping path
    const std::string              _rf_var_map_name;
    /// refinement relation - condition path
    const std::string              _rf_cond_name;
    /// output path, output the ila-verilog, wrapper-verilog, problem.txt, run-verify-by-???
    const std::string              _output_path; 
    /// The pointer to the instruction that is going to export
    const InstrPtr               & _instr_ptr; 
    /// The name of verilog top module instance in the wrapper
    std::string                    _vlg_mod_inst_name; 
    /// The name of ila-verilog top module instance in the wrapper
    std::string                    _ila_mod_inst_name;

protected:
    /// store the vmap info
    nlohmann::json rf_vmap;
    /// store the condition
    nlohmann::json rf_cond

  public:
  // --------------------- METHODS ---------------------------- //
    /// Generate everything 
    // only set the info pointer within it and delete it afterwards
    void GenerateTarget(void);
    /// Return true if it is in bad state
    bool in_bad_state(void) const { return _bad_state; }

  protected:
    /// If it is bad state, return true and display a message
    bool bad_state_return(void); 
    /// load json from a file name to the given j
    void load_json(const std::string & fname, json & j);


    /// The way to add an assumption and assertion is tool-specific
    virtual void add_an_assumption(const std::string & aspt) = 0;
    /// The way to add an assumption and assertion is tool-specific
    virtual void add_an_assertion (const std::string & asst) = 0;

  private:
    /// If it is in a bad state
    bool _bad_state;

// not override -- should not be instantiated

}; // class VlgVerifTgtGen


}; // namespace ilang


#endif // JSON_INOUT_ENABLE

#endif //VTARGET_GEN_IMPL_H__