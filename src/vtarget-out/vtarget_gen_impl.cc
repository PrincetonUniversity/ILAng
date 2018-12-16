/// \file Source for Verilog Verification Targets Generation
/// 
// --- Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/util/fs.h>
#include <ilang/util/str_util.h>
#include <ilang/ila/expr_fuse.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>
#include <ilang/vtarget-out/vtarget_gen_cosa.h>
#include <ilang/vtarget-out/vtarget_gen_jasper.h>

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
      const InstrLvlAbsPtr           & ila_ptr,
      backend_selector                 backend,
      const VerilogGenerator::VlgGenConfig& vlg_gen_config = VerilogGenerator::VlgGenConfig() 
      ):
  _vlg_impl_include_path(implementation_include_path),
  _vlg_impl_srcs        (implementation_srcs),
  _vlg_impl_top_name    (implementation_top_module),
  _rf_var_map_name      (refinement_variable_mapping),
  _rf_cond_name         (refinement_conditions),
  _output_path          (output_path),
  _ila_ptr              (ila_ptr),
  // configure is only for ila, generate the start signal
  vlg_info_ptr(NULL), // not creating it now, because we don't have the info to do so
  _backend(backend),
  _cfg(vlg_gen_config),
  _bad_state(false)
  {
    load_json(_rf_var_map_name, rf_vmap);
    load_json(_rf_cond_name   , rf_cond);
    set_module_instantiation_name();
    if(_ila_ptr == nullptr) {
      ILA_ERROR<<"ILA should not be none";
      _bad_state = true;
    }
  }

  VlgVerifTgtGen::~VlgVerifTgtGen()
 { if(vlg_info_ptr) delete vlg_info_ptr; }


  void VlgVerifTgtGen::GenerateTargets(void) {
    if(bad_state_return()) return;

    vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs, _vlg_mod_inst_name, _vlg_impl_top_name );

    if (vlg_info_ptr == NULL or vlg_info_ptr->in_bad_state()) {
      ILA_ERROR << "Unable to generate targets. Verilog parser failed.";
      return; // 
    }

    if ( _backend != backend_selector::COSA &&
         _backend != backend_selector::JASPERGOLD ) {
           ILA_ERROR << "Unknown backend specification:"<< _backend <<", quit.";
           return;
         }

    if( _backend == backend_selector::COSA ) {
      auto target = VlgSglTgtGen_Cosa(
        os_portable_append_dir( _output_path, "invariants" ),
        NULL, // invariant
        _cfg,
        rf_vmap,
        rf_cond,
        vlg_info_ptr,
        _vlg_mod_inst_name,
        _ila_mod_inst_name,
        "wrapper",
        _vlg_impl_srcs
      );
      target.ExportAll("wrapper.v", "ila.v", "run.sh" , "problem.txt" , "absmem.v");
    }
    else if (_backend == backend_selector::JASPERGOLD ) {
      auto target = VlgSglTgtGen_Jasper(
        os_portable_append_dir( _output_path, "invariants" ),
        NULL, // invariant
        _cfg,
        rf_vmap,
        rf_cond,
        vlg_info_ptr,
        _vlg_mod_inst_name,
        _ila_mod_inst_name,
        "wrapper",
        _vlg_impl_srcs
      );
      target.ExportAll("wrapper.v", "ila.v", "run.sh" , "do.tcl" , "absmem.v");
    }

    // now let's deal w. instructions in rf_cond
    auto & instrs = rf_cond["instructions"];  
    for (auto && instr : instrs) {
      std::string iname = instr["instruction"].get<std::string>();
      auto instr_ptr = _ila_ptr->instr(iname);
      if(instr_ptr == nullptr) {
        ILA_ERROR << "ila:"<<ila_ptr->name().str()<<" has no instruction:"<< instr_ptr;
        continue;
      }
      if( _backend == backend_selector::COSA ) {
            auto target = VlgSglTgtGen_Cosa(
              os_portable_append_dir( _output_path, iname ),
              instr_ptr, // invariant
              _cfg,
              rf_vmap,
              rf_cond,
              vlg_info_ptr,
              _vlg_mod_inst_name,
              _ila_mod_inst_name,
              "wrapper",
              _vlg_impl_srcs
            );
            target.ExportAll("wrapper.v", "ila.v", "run.sh" , "problem.txt" , "absmem.v");
          }
          else if (_backend == backend_selector::JASPERGOLD ) {
            auto target = VlgSglTgtGen_Jasper(
              os_portable_append_dir( _output_path, iname ),
              instr_ptr, // invariant
              _cfg,
              rf_vmap,
              rf_cond,
              vlg_info_ptr,
              _vlg_mod_inst_name,
              _ila_mod_inst_name,
              "wrapper",
              _vlg_impl_srcs
            );
            target.ExportAll("wrapper.v", "ila.v", "run.sh" , "do.tcl" , "absmem.v");
          }
    }// end for


    if(vlg_info_ptr) {
      delete vlg_info_ptr;
      vlg_info_ptr = NULL;
    }
  } // end of function GenerateTargets

  void VlgVerifTgtGen::set_module_instantiation_name() {
    if(bad_state_return()) return;
    // use the content in the refinement relations to determine the instance name
    auto & model_specified = rf_cond["models"];
    for ( auto && name_description_pair: nlohmann::json::iterator_wrapper(model_specified)  ) {
      if(name_description_pair.key() == "ILA" ) {
        _ila_mod_inst_name = name_description_pair.value();
      } else if (name_description_pair.key() == "VERILOG") {
        _vlg_mod_inst_name = name_description_pair.value();
      } else ILA_ERROR << "Unknown model specification:"<<name_description_pair.key() <<" expect VERILOG or ILA";
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


  bool VlgVerifTgtGen::bad_state_return(void) {
    ILA_ERROR_IF(_bad_state) <<"VlgVerifTgtGen is in a bad state, cannot proceed.";
    return _bad_state;
  } // bad_state_return

  void VlgVerifTgtGen::load_json(const std::string & fname, nlohmann::json & j) {
    if(bad_state_return()) return;
    std::ifstream fin(fname);
    if(!fin.is_open() ) {
      ILA_ERROR << "Cannot read from file:"<<fname;
      _bad_state = true;
      return;
    }
    fin >> j;
  } // load_json


}; // namespace ilang
