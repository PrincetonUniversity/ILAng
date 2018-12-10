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

#ifndef VTARGET_GEN_H__
#define VTARGET_GEN_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/verilog-in/verilog_analysis_wrapper.h>
#include <ilang/verilog-out/verilog_gen.h>
#include <ilang/vtarget-out/interface_directive.h>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>

namespace ilang {

  /// brief Class of Verilog verification target generation
class VlgVerifTgtGen {
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

  protected:
    /// Generator for the wrapper module
    VerilogGenerator vlg_wrapper;
    /// Generator for the ila verilog
    VerilogGenerator vlg_ila;
    /// Analyzer for the implementation
    // we don't know the module name, before analyzing the rfmap. so we cannot initialize in the beginning
    VerilogInfo      *vlg_info_ptr;
    /// inteface directive recorder
    IntefaceDirectiveRecorder _idr;

    /// store the vmap info
    json rf_vmap;
    /// store the condition
    json rf_cond

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

  private:
    /// If it is in a bad state
    bool _bad_state;



}; // class VlgVerifTgtGen


class VlgVerifTgtGen_Cosa : public VlgVerifTgtGen {

}; // class VlgVerifTgtGenCosa

class VlgVerifTgtGenCosa_Jasper : public VlgVerifTgtGen {

}; // class VlgVerifTgtGenCosaJasper

}; // namespace ilang

#endif //VTARGET_GEN_H__