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
#include "nlohmann/json.hpp"
#include <list>
#include <map>
#include <unordered_map>
#include <vector>

namespace ilang {

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
    bool bad_state_return(void); 
    void load_json(const std::string & fname, json & j);

    std::string new_mapping_id();
    std::string new_property_id();

  private:
    /// If it is in a bad state
    bool _bad_state;
    /// Counter of mapping
    unsigned mapping_counter;
    /// Counter of property
    unsigned property_counter;

// not override -- should not be instantiated

}; // class VlgVerifTgtGen


}; // namespace ilang


#endif // JSON_INOUT_ENABLE

#endif //VTARGET_GEN_IMPL_H__