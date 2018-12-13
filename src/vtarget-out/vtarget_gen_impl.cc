/// \file Source for Verilog Verification Targets Generation
/// 
// --- Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/ila/expr_fuse.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/gen_util.h>

#include <iostream>
#include <cmath>

namespace ilang {



// ------------------------------ VlgVerifTgtGen --------------------------------- //


  VlgVerifTgtGen::VlgVerifTgtGen(
      const std::vector<std::string> & implementation_include_path,
      const std::vector<std::string> & implementation_srcs,
      const std::string              & implementation_top_module,
      const std::string              & refinement_variable_mapping,
      const std::string              & refinement_conditions,
      const std::string              & output_path,
      const InstrPtr                 & instr_ptr,
      const VerilogGenerator::VlgGenConfig& vlg_gen_config = VlgGenConfig() 
      ):
  _vlg_impl_include_path(implementation_include_path),
  _vlg_impl_srcs        (implementation_srcs),
  _vlg_impl_top_name    (implementation_top_module),
  _rf_var_map_name      (refinement_variable_mapping),
  _rf_cond_name         (refinement_conditions),
  _output_path          (output_path),
  _instr_ptr            (instr_ptr),
  // configure is only for ila, generate the start signal
  vlg_info_ptr(NULL), // not creating it now, because we don't have the info to do so
  _bad_state(false)
  {
    load_json(_rf_var_map_name, rf_vmap);
    load_json(_rf_cond_name   , rf_cond);
    set_module_instantiation_name();
  }



  void VlgVerifTgtGen::GenerateTargets(void) {
    vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs, ???, _vlg_impl_top_name );



    if(vlg_info_ptr) {
      delete vlg_info_ptr;
      vlg_info_ptr = NULL;
    }
  }

  void VlgVerifTgtGen::set_module_instantiation_name() {
    // use the content in the refinement relations to determine the instance name
    auto & model_specified = rf_cond["models"];
    for ( auto && name_description_pair: model_specified ) {
      if(name_description_pair.second == "ILA" ) {
        _ila_mod_inst_name = name_description_pair.first;
      } else if (name_description_pair.second == "VERILOG") {
        _vlg_mod_inst_name = name_description_pair.first;
      } else ILA_ERROR << "Unknown model specification:"<<name_description_pair.second <<" expect VERILOG or ILA";
    }
    // if unset
    if (_vlg_mod_inst_name == "") {
      ILA_WARN<<"Verilog top module instance name not set, assuming to be VERILOG";
      _vlg_mod_inst_name = "VERILOG";
    }
    if (_ila_mod_inst_name == "") {
      ILA_WARN<<"ILA top module instance name not set, assuming to be ILA";
      _ila_mod_inst_name = "ILA";      
    }
  } // set_module_instantiation_name


  void VlgVerifTgtGen::ModifyImplVlg(void) {
    // decide mentions and locations
    // read in and write out
  }

  void VlgVerifTgtGen::GenVerilogs(void) {
    // decide mentions and locations
    // read in and write out
  }

  void VlgVerifTgtGen::GenScript(void) {
    // decide mentions and locations
    // read in and write out
  }

  bool VlgVerifTgtGen::bad_state_return(void) {
    ILA_ERROR_IF(_bad_state) <<"VlgVerifTgtGen is in a bad state, cannot proceed.";
    return _bad_state;
  } // bad_state_return

  void VlgVerifTgtGen::load_json(const std::string & fname, json & j) {
    std::ifstream fin(fname);
    if(!fin.is_open() ) {
      ILA_ERROR << "Cannot read from file:"<<fname;
      _bad_state = true;
      return;
    }
    fname >> j;
  } // load_json


}; // namespace ilang
