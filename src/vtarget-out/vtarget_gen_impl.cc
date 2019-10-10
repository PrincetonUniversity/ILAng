/// \file Source for Verilog Verification Targets Generation
///
// --- Hongce Zhang

#include <ilang/ila/expr_fuse.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/vtarget_gen_cosa.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>
#include <ilang/vtarget-out/vtarget_gen_jasper.h>
#include <ilang/vtarget-out/vtarget_gen_yosys.h>
// for invariant synthesis
#include <ilang/vtarget-out/inv-syn/vtarget_gen_inv_chc.h>
#include <ilang/vtarget-out/inv-syn/vtarget_gen_inv_enhance.h>
#include <ilang/vtarget-out/inv-syn/vtarget_gen_inv_abc.h>
#include <ilang/vtarget-out/inv-syn/sygus/vtarget_gen_inv_sygus.h>

#include <cmath>
#include <iostream>

namespace ilang {

// ------------------------------ VlgVerifTgtGen
// --------------------------------- //

VlgVerifTgtGen::VlgVerifTgtGen(
    const std::vector<std::string>& implementation_include_path,
    const std::vector<std::string>& implementation_srcs,
    const std::string& implementation_top_module,
    const std::string& refinement_variable_mapping,
    const std::string& refinement_conditions, const std::string& output_path,
    const InstrLvlAbsPtr& ila_ptr, backend_selector backend,
    const vtg_config_t& vtg_config,
    const VerilogGenerator::VlgGenConfig& vlg_gen_config,
    advanced_parameters_t * adv_ptr)
    : _vlg_impl_include_path(implementation_include_path),
      _vlg_impl_srcs(implementation_srcs),
      _vlg_impl_top_name(implementation_top_module),
      _rf_var_map_name(refinement_variable_mapping),
      _rf_cond_name(refinement_conditions), _output_path(output_path),
      _ila_ptr(ila_ptr),
      // configure is only for ila, generate the start signal
      vlg_info_ptr(
          NULL), // not creating it now, because we don't have the info to do so
      _backend(backend), _cfg(vlg_gen_config), _vtg_config(vtg_config),
      _advanced_param_ptr(adv_ptr),
      _bad_state(false) {
  load_json(_rf_var_map_name, rf_vmap);
  load_json(_rf_cond_name, rf_cond);
  sup_info.FromJson(rf_vmap);
  set_module_instantiation_name();
  if (_ila_ptr == nullptr) {
    ILA_ERROR << "ILA should not be none";
    _bad_state = true;
  }
  // check for json file -- global invariants
  if (not IN("global invariants", rf_cond)) {
    ILA_ERROR << "'global invariants' must exist, can be an empty array";
    _bad_state = true;
  } else if (not rf_cond["global invariants"].is_array()) {
    ILA_ERROR << "'global invariants' must be an array of string";
    _bad_state = true;
  } else if (rf_cond["global invariants"].size() != 0) {
    if (not rf_cond["global invariants"][0].is_string()) {
      ILA_ERROR << "'global invariants' must be an array of string";
      _bad_state = true;
    }
  }
  // check for json file -- instructions
  if (not IN("instructions", rf_cond)) {
    ILA_ERROR << "'instructions' must exist.";
    _bad_state = true;
  } else if (not rf_cond["instructions"].is_array()) {
    ILA_ERROR << "'instructions' must be an array of objects.";
    _bad_state = true;
  } else if (rf_cond["instructions"].size() == 0) {
    ILA_WARN << "No instruction in the rf specification";
  } else {
    for (auto&& it : rf_cond["instructions"].items()) {
      if (not it.value().is_object()) {
        ILA_ERROR << "'instructions' must be an array of objects.";
        _bad_state = true;
        break;
      } else {
        if (not IN("instruction", it.value())) {
          ILA_ERROR << "'instruction' field must exist in the rf object.";
          _bad_state = true;
          break;
        } else if (not it.value()["instruction"].is_string()) {
          ILA_ERROR
              << "'instruction' field must be a string of instruction name.";
          _bad_state = true;
          break;
        }
      }
    }
  }

  // check vmap
  if (!IN("models", rf_vmap) || !rf_vmap["models"].is_object()) {
    ILA_ERROR << "'model' field must exist in vmap and be a map of ILA/VERILOG "
                 "-> 'instance name' ";
    _bad_state = true;
  }
  if (!IN("state mapping", rf_vmap) || !rf_vmap["state mapping"].is_object()) {
    ILA_ERROR << "'state mapping' field must exist in vmap and be a map : "
                 "ila_var -> impl_var";
    _bad_state = true;
  }
  // TODO: check more
}

VlgVerifTgtGen::~VlgVerifTgtGen() {
  if (vlg_info_ptr)
    delete vlg_info_ptr;
}


const std::vector<std::string> & VlgVerifTgtGen::GetRunnableScriptName() const {
  return runnable_script_name;
}


const VlgTgtSupplementaryInfo & VlgVerifTgtGen::GetSupplementaryInfo() const {
  return sup_info;
}

const Cvc4SygusBase::correction_t & VlgVerifTgtGen::GetParsingCorrections() const {
  return inv_parsing_corrections;
}

// ------------------------- SMT TARGET ------------------------- //

/*
std::shared_ptr<smt::YosysSmtParser> VlgVerifTgtGen::GenerateSmtTargets() {
  ILA_ERROR_IF(_backend != backend_selector::YOSYS) << "All inv-syn relies on yosys!";

  if (vlg_info_ptr)
    delete vlg_info_ptr;
  
  vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs,
                                 _vlg_mod_inst_name, _vlg_impl_top_name);
  if (vlg_info_ptr == NULL or vlg_info_ptr->in_bad_state()) {
    ILA_ERROR << "Unable to generate targets. Verilog parser failed.";
    return nullptr; //
  }
  auto target = VlgSglTgtGen_Smt(
      os_portable_append_dir(_output_path, "inv-syn/"),
      NULL, // invariant
      _ila_ptr, _cfg, rf_vmap, rf_cond, sup_info , vlg_info_ptr, _vlg_mod_inst_name,
      _ila_mod_inst_name, "wrapper", _vlg_impl_srcs, _vlg_impl_include_path,
      _vtg_config, _backend, s_backend, target_type_t::INV_SYN_DESIGN_ONLY,
      _advanced_param_ptr, true, _chc_target_t::CEX);
  target.ConstructWrapper();
  target.ExportAll("wrapper.v", "ila.v", //USELESS
   "run.sh", "wrapper.smt2",
                    "absmem.v"  //USELESS
                    );

  return target.GetDesignSmtInfo();
}*/


// ------------------------- SYNTHESIS TARGET ------------------------- //


std::shared_ptr<smt::YosysSmtParser> VlgVerifTgtGen::GenerateInvSynSygusTargets(synthesis_backend_selector s_backend,
    TraceDataPoints * dp, const std::vector<std::string> & sygus_var_names, bool enumerate,
    const Cvc4Syntax & syntax) {
  ILA_ASSERT(not sygus_var_names.empty()) << "BUG: must call SetSygusVarNames before _generate_sygus_inv_syn_target";

  if (vlg_info_ptr)
    delete vlg_info_ptr;
  
  vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs,
                                 _vlg_mod_inst_name, _vlg_impl_top_name);
  if (vlg_info_ptr == NULL or vlg_info_ptr->in_bad_state()) {
    ILA_ERROR << "Unable to generate targets. Verilog parser failed.";
    return nullptr; //
  }
  auto target = VlgSglTgtGen_Cvc4SyGuS(
      os_portable_append_dir(_output_path, "inv-syn-sygus/"),
      NULL, // inst_ptr -- not for an instruction
      _ila_ptr, _cfg, rf_vmap, rf_cond, sup_info , vlg_info_ptr, _vlg_mod_inst_name,
      _ila_mod_inst_name, "wrapper", _vlg_impl_srcs, _vlg_impl_include_path,
      _vtg_config, _backend, s_backend, target_type_t::INV_SYN_DESIGN_ONLY,
      _advanced_param_ptr, 
      (_vtg_config.SygusOptions.SygusPassInfo == 
        VlgVerifTgtGenBase::_vtg_config::_sygus_options_t::TransferFunc ? 
          NULL : dp) , // disable datapoint if using transfer function
      sygus_var_names, enumerate ); // no datapoints
  target.ConstructWrapper();
  target.ExportAll("wrapper.v", "ila.v" /*USELESS*/, "run.sh", "wrapper.smt2",
                    "absmem.v"  /*USELESS*/, syntax);
  runnable_script_name.clear();
  runnable_script_name.push_back(
    os_portable_append_dir(
      os_portable_append_dir(_output_path, "inv-syn-sygus/"), "run.sh"));
  
  inv_parsing_corrections = target.GetParsingCorrections();

  return target.GetDesignSmtInfo();

}

void VlgVerifTgtGen::GenerateInvSynTargetsAbc(bool useGla, bool useCorr, bool useAiger) {
  ILA_ERROR_IF(_backend != backend_selector::YOSYS) << "All inv-syn relies on yosys!";

  if (vlg_info_ptr)
    delete vlg_info_ptr;
  
  vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs,
                                 _vlg_mod_inst_name, _vlg_impl_top_name);
  if (vlg_info_ptr == NULL or vlg_info_ptr->in_bad_state()) {
    ILA_ERROR << "Unable to generate targets. Verilog parser failed.";
    return; //
  }
  auto target = VlgSglTgtGen_Abc(
      os_portable_append_dir(_output_path, "inv-syn-abc/"),
      NULL, // invariant
      _ila_ptr, _cfg, rf_vmap, rf_cond, sup_info , vlg_info_ptr, _vlg_mod_inst_name,
      _ila_mod_inst_name, "wrapper", _vlg_impl_srcs, _vlg_impl_include_path,
      _vtg_config, _backend, synthesis_backend_selector::ABC,
      target_type_t::INV_SYN_DESIGN_ONLY,
      _advanced_param_ptr, true, _chc_target_t::CEX,
      useGla, useCorr, useAiger);
  target.ConstructWrapper();
  target.ExportAll("wrapper.v", "ila.v" /*USELESS*/, "run.sh",  useAiger ?  "wrapper.aig" : "wrapper.blif",
                    "absmem.v"  /*USELESS*/);
                    
  runnable_script_name.clear();
  runnable_script_name.push_back(
    os_portable_append_dir(
      os_portable_append_dir(_output_path, "inv-syn-abc/"), "run.sh"));
}


std::shared_ptr<smt::YosysSmtParser> VlgVerifTgtGen::GenerateInvSynEnhanceTargets(const InvariantInCnf & cnf) {
  ILA_ERROR_IF(_backend != backend_selector::YOSYS) << "All inv-syn relies on yosys!";

  if (vlg_info_ptr)
    delete vlg_info_ptr;
  
  vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs,
                                 _vlg_mod_inst_name, _vlg_impl_top_name);
  if (vlg_info_ptr == NULL or vlg_info_ptr->in_bad_state()) {
    ILA_ERROR << "Unable to generate targets. Verilog parser failed.";
    return nullptr; //
  }

  // use a temporary configuration
  auto tmp_vtg_config = _vtg_config;
  tmp_vtg_config.InvariantSynthesisReachableCheckKeepOldInvariant = true;
  tmp_vtg_config.YosysSmtFlattenDatatype = true;

#if 0
  // currently we do this on the outer level
  // here we remove the last one, because it is the one we want to enhance
  InvariantObject * inv_obj_backup = NULL;
  if (_advanced_param_ptr->_inv_obj_ptr) {
    InvariantObject * reduced_inv = new InvariantObject(*( _advanced_param_ptr->_inv_obj_ptr)); // make a copy
    ILA_NOT_NULL(reduced_inv);
    if (reduced_inv->NumInvariant() > 0)
      reduced_inv->RemoveInvByIdx(reduced_inv->NumInvariant()-1);
    inv_obj_backup = _advanced_param_ptr->_inv_obj_ptr;
    _advanced_param_ptr->_inv_obj_ptr = reduced_inv;
  }
#endif

  // TODO: you may need to change a bit of _advanced_param_ptr's inv
  // and maybe the assume inv part
  auto target = VlgSglTgtGen_Chc_wCNF(
      os_portable_append_dir(_output_path, "inv-enhance/"),
      NULL, // invariant
      _ila_ptr, _cfg, rf_vmap, rf_cond, sup_info , vlg_info_ptr, _vlg_mod_inst_name,
      _ila_mod_inst_name, "wrapper", _vlg_impl_srcs, _vlg_impl_include_path,
      tmp_vtg_config, _backend, VlgVerifTgtGenBase::synthesis_backend_selector::FreqHorn, 
      target_type_t::INV_SYN_DESIGN_ONLY,
      _advanced_param_ptr, true, _chc_target_t::CEX);
  target.ConstructWrapper();
  target.ExportAll("wrapper.v", "ila.v" /*USELESS*/, "run.sh", "wrapper.smt2",
                    "absmem.v"  /*USELESS*/, "inv_cnf.txt" , cnf);
  runnable_script_name.clear();
  runnable_script_name.push_back(
    os_portable_append_dir(
      os_portable_append_dir(_output_path, "inv-enhance/"), "run.sh"));
#if 0
  if (inv_obj_backup) { // recover the invariant
    delete (_advanced_param_ptr->_inv_obj_ptr);
    _advanced_param_ptr->_inv_obj_ptr = inv_obj_backup;
  } // recover the invariant
#endif

  return target.GetDesignSmtInfo();
}

std::shared_ptr<smt::YosysSmtParser> VlgVerifTgtGen::GenerateInvSynTargets(synthesis_backend_selector s_backend) {
  ILA_ERROR_IF(_backend != backend_selector::YOSYS) << "All inv-syn relies on yosys!";

  if (vlg_info_ptr)
    delete vlg_info_ptr;
  
  vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs,
                                 _vlg_mod_inst_name, _vlg_impl_top_name);
  if (vlg_info_ptr == NULL or vlg_info_ptr->in_bad_state()) {
    ILA_ERROR << "Unable to generate targets. Verilog parser failed.";
    return nullptr; //
  }
  auto target = VlgSglTgtGen_Chc(
      os_portable_append_dir(_output_path, "inv-syn/"),
      NULL, // invariant
      _ila_ptr, _cfg, rf_vmap, rf_cond, sup_info , vlg_info_ptr, _vlg_mod_inst_name,
      _ila_mod_inst_name, "wrapper", _vlg_impl_srcs, _vlg_impl_include_path,
      _vtg_config, _backend, s_backend, target_type_t::INV_SYN_DESIGN_ONLY,
      _advanced_param_ptr, true, _chc_target_t::CEX);
  target.ConstructWrapper();
  target.ExportAll("wrapper.v", "ila.v" /*USELESS*/, "run.sh", "wrapper.smt2",
                    "absmem.v"  /*USELESS*/);
  runnable_script_name.clear();
  runnable_script_name.push_back(
    os_portable_append_dir(
      os_portable_append_dir(_output_path, "inv-syn/"), "run.sh"));

  return target.GetDesignSmtInfo();
}


void VlgVerifTgtGen::GenerateDesignOnlyCandidateInvChcCheckTargets(synthesis_backend_selector s_backend) {
  ILA_ERROR_IF(_backend != backend_selector::YOSYS) << "All inv-syn relies on yosys!";
  ILA_ASSERT(s_backend == synthesis_backend_selector::Z3) << "This is intended for Z3";
  ILA_WARN_IF(_vtg_config.YosysSmtStateSort != _vtg_config::BitVec)
    << "For better performance, please consider using Bitvec state encoding in YosysSmtStateSort";
  ILA_ERROR_IF(_vtg_config.CosaGenTraceVcd)
    << "No vcd can be generated.";

  if (vlg_info_ptr)
    delete vlg_info_ptr;
  
  vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs,
                                 _vlg_mod_inst_name, _vlg_impl_top_name);
  if (vlg_info_ptr == NULL or vlg_info_ptr->in_bad_state()) {
    ILA_ERROR << "Unable to generate targets. Verilog parser failed.";
    return; //
  }
  auto target = VlgSglTgtGen_Chc(
      os_portable_append_dir(_output_path, "chc-prop-check/"),
      NULL, // invariant
      _ila_ptr, _cfg, rf_vmap, rf_cond, sup_info , vlg_info_ptr, _vlg_mod_inst_name,
      _ila_mod_inst_name, "wrapper", _vlg_impl_srcs, _vlg_impl_include_path,
      _vtg_config, _backend, s_backend, target_type_t::INV_SYN_DESIGN_ONLY,
      _advanced_param_ptr, false, _chc_target_t::INVCANDIDATE);
  target.ConstructWrapper();
  target.ExportAll("wrapper.v", "ila.v" /*USELESS*/, "run.sh", "wrapper.smt2",
                    "absmem.v"  /*USELESS*/);
  runnable_script_name.clear();
  runnable_script_name.push_back(
    os_portable_append_dir(
      os_portable_append_dir(_output_path, "chc-prop-check/"), "run.sh"));

}

// ------------------------- VERIFICATION TARGET ------------------------- //

void VlgVerifTgtGen::GenerateTargets(void) {
  if (bad_state_return())
    return;

  runnable_script_name.clear();

  vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs,
                                 _vlg_mod_inst_name, _vlg_impl_top_name);

  if (vlg_info_ptr == NULL or vlg_info_ptr->in_bad_state()) {
    ILA_ERROR << "Unable to generate targets. Verilog parser failed.";
    return; //
  }

  if (_backend != backend_selector::COSA &&
      _backend != backend_selector::JASPERGOLD &&
      _backend != backend_selector::YOSYS ) {
    ILA_ERROR << "Unknown backend specification:" << _backend << ", quit.";
    return;
  }

  if (_vtg_config.target_select == vtg_config_t::BOTH ||
      _vtg_config.target_select == vtg_config_t::INV) {
    // check if there are really invariants:
    bool invariantExists = false;
    if (IN("global invariants", rf_cond)) {
      auto& inv = rf_cond["global invariants"];
      if (inv.is_array() && inv.size() != 0)
        invariantExists = true;
      else if (inv.is_string() && inv.get<std::string>() != "")
        invariantExists = true;
      else if (
        ( _vtg_config.ValidateSynthesizedInvariant == vtg_config_t::_validate_synthesized_inv::ALL or
          _vtg_config.ValidateSynthesizedInvariant == vtg_config_t::_validate_synthesized_inv::CONFIRMED
        ) and
        (_advanced_param_ptr and _advanced_param_ptr->_inv_obj_ptr != NULL and 
          not _advanced_param_ptr->_inv_obj_ptr->GetVlgConstraints().empty()))
        invariantExists = true;
      else if (
        ( _vtg_config.ValidateSynthesizedInvariant == vtg_config_t::_validate_synthesized_inv::ALL or
          _vtg_config.ValidateSynthesizedInvariant == vtg_config_t::_validate_synthesized_inv::CANDIDATE
        ) and
        (_advanced_param_ptr and  _advanced_param_ptr->_candidate_inv_ptr != NULL and 
          not _advanced_param_ptr->_candidate_inv_ptr->GetVlgConstraints().empty()))
        invariantExists = true;
    }
    auto sub_output_path = os_portable_append_dir(_output_path, "invariants");
    if (_backend == backend_selector::COSA && invariantExists) {
      auto target = VlgSglTgtGen_Cosa(
          sub_output_path,
          NULL, // invariant
          _ila_ptr, _cfg, rf_vmap, rf_cond, sup_info , vlg_info_ptr, _vlg_mod_inst_name,
          _ila_mod_inst_name, "wrapper", _vlg_impl_srcs, _vlg_impl_include_path,
          _vtg_config, _backend, target_type_t::INVARIANTS,
          _advanced_param_ptr);
      target.ConstructWrapper();
      target.ExportAll("wrapper.v", "ila.v", "run.sh", "problem.txt",
                       "absmem.v");
    } else if (_backend == backend_selector::JASPERGOLD && invariantExists) {
      auto target = VlgSglTgtGen_Jasper(
          sub_output_path,
          NULL, // invariant
          _ila_ptr, _cfg, rf_vmap, rf_cond, sup_info , vlg_info_ptr, _vlg_mod_inst_name,
          _ila_mod_inst_name, "wrapper", _vlg_impl_srcs, _vlg_impl_include_path,
          _vtg_config, _backend, target_type_t::INVARIANTS,
          _advanced_param_ptr);
      target.ConstructWrapper();
      target.ExportAll("wrapper.v", "ila.v", "run.sh", "do.tcl", "absmem.v");
    } else if (_backend == backend_selector::YOSYS and invariantExists) {
      /*
      auto target = VlgSglTgtGen_Yosys(
          sub_output_path,
          NULL, // invariant
          _ila_ptr, _cfg, rf_vmap, rf_cond, sup_info , vlg_info_ptr, _vlg_mod_inst_name,
          _ila_mod_inst_name, "wrapper", _vlg_impl_srcs, _vlg_impl_include_path,
          _vtg_config, _backend, target_type_t::INVARIANTS,
          _advanced_param_ptr);
      target.ConstructWrapper();
      target.ExportAll("wrapper.v", "ila.v", "run.sh", "gensmt.ys", "absmem.v");
      */
     ILA_WARN << "CHC w. Provided Inv in RFmap, checking Inv skipped.";
    }
    if(invariantExists)
      runnable_script_name.push_back(
        os_portable_append_dir(sub_output_path, "run.sh"));
    // end if backend...
  } // end if if(_vtg_config.target_select == BOTH || _vtg_config.target_select
    // == INV)

  // now let's deal w. instructions in rf_cond
  if (_vtg_config.target_select == vtg_config_t::BOTH ||
      _vtg_config.target_select == vtg_config_t::INST) {
    auto& instrs = rf_cond["instructions"];
    for (auto&& instr : instrs) {
      std::string iname = instr["instruction"].get<std::string>();
      if (_vtg_config.CheckThisInstructionOnly != "" &&
          _vtg_config.CheckThisInstructionOnly != iname)
        continue; // skip, not checking this instruction

      auto instr_ptr = _ila_ptr->instr(iname);
      if (instr_ptr == nullptr) {
        ILA_ERROR << "ila:" << _ila_ptr->name().str()
                  << " has no instruction:" << iname;
        continue;
      }

      auto sub_output_path = os_portable_append_dir(_output_path, iname);

      if (_backend == backend_selector::COSA) {
        auto target = VlgSglTgtGen_Cosa(
            sub_output_path,
            instr_ptr, // instruction
            _ila_ptr, _cfg, rf_vmap, rf_cond, sup_info , vlg_info_ptr, _vlg_mod_inst_name,
            _ila_mod_inst_name, "wrapper", _vlg_impl_srcs,
            _vlg_impl_include_path, _vtg_config, _backend,
            target_type_t::INSTRUCTIONS,
            _advanced_param_ptr);
        target.ConstructWrapper();
        target.ExportAll("wrapper.v", "ila.v", "run.sh", "problem.txt",
                         "absmem.v");
      } else if (_backend == backend_selector::JASPERGOLD) {
        auto target = VlgSglTgtGen_Jasper(
            sub_output_path,
            instr_ptr, // instruction
            _ila_ptr, _cfg, rf_vmap, rf_cond, sup_info , vlg_info_ptr, _vlg_mod_inst_name,
            _ila_mod_inst_name, "wrapper", _vlg_impl_srcs,
            _vlg_impl_include_path, _vtg_config, _backend,
            target_type_t::INSTRUCTIONS,
            _advanced_param_ptr);
        target.ConstructWrapper();
        target.ExportAll("wrapper.v", "ila.v", "run.sh", "do.tcl", "absmem.v");
      } else if (_backend == backend_selector::YOSYS) {
        // in this case we will have two targets to generate
        // one is the target with only the design and
        // and the second one should use the smt file it generates
        // and create conversion (map) function

        auto target = VlgSglTgtGen_Yosys(
            sub_output_path,
            instr_ptr, // instruction
            _ila_ptr, _cfg, rf_vmap, rf_cond, sup_info , vlg_info_ptr, _vlg_mod_inst_name,
            _ila_mod_inst_name, "wrapper", _vlg_impl_srcs,
            _vlg_impl_include_path, _vtg_config, _backend,
            target_type_t::INSTRUCTIONS,
            _advanced_param_ptr);
        target.ConstructWrapper();
        target.ExportAll("wrapper.v", "ila.v", "run.sh", "gensmt.ys", "absmem.v");
      } // end case backend
      runnable_script_name.push_back(
        os_portable_append_dir(sub_output_path, "run.sh"));
    } // end for instrs
  }   // end if target select == ...

  if (vlg_info_ptr) {
    delete vlg_info_ptr;
    vlg_info_ptr = NULL;
  }
} // end of function GenerateTargets

void VlgVerifTgtGen::set_module_instantiation_name() {
  if (bad_state_return())
    return;
  // use the content in the refinement relations to determine the instance name
  auto& model_specified = rf_vmap["models"];
  for (auto&& name_description_pair : model_specified.items()) {
    if (name_description_pair.key() == "ILA") {
      _ila_mod_inst_name = name_description_pair.value();
    } else if (name_description_pair.key() == "VERILOG") {
      _vlg_mod_inst_name = name_description_pair.value();
    } else
      ILA_ERROR << "Unknown model specification:" << name_description_pair.key()
                << " expect VERILOG or ILA";
  }
  // if unset
  if (_vlg_mod_inst_name == "") {
    ILA_WARN
        << "Verilog top module instance name not set, assuming to be VERILOG";
    _vlg_mod_inst_name = "VERILOG";
  }
  if (_ila_mod_inst_name == "") {
    ILA_WARN << "ILA top module instance name not set, assuming to be ILA";
    _ila_mod_inst_name = "ILA";
  }
} // set_module_instantiation_name

bool VlgVerifTgtGen::bad_state_return(void) {
  ILA_ERROR_IF(_bad_state)
      << "VlgVerifTgtGen is in a bad state, cannot proceed.";
  return _bad_state;
} // bad_state_return

// return npos if no comments in
static size_t find_comments(const std::string& line) {
  enum state_t { PLAIN, STR, LEFT } state, next_state;
  state = PLAIN;
  size_t ret = 0;
  for (const auto& c : line) {
    if (state == PLAIN) {
      if (c == '/')
        next_state = LEFT;
      else if (c == '"')
        next_state = STR;
      else
        next_state = PLAIN;
    } else if (state == STR) {
      if (c == '"' || c == '\n')
        next_state = PLAIN;
      // the '\n' case is in case we encounter some issue to find
      // the ending of a string
      else
        next_state = STR;
    } else if (state == LEFT) {
      if (c == '/') {
        ILA_ASSERT(ret > 0);
        return ret - 1;
      } else
        next_state = PLAIN;
    } else
      ILA_ASSERT(false);
    state = next_state;
    ++ret;
  }
  return std::string::npos;
}

void VlgVerifTgtGen::load_json(const std::string& fname, nlohmann::json& j) {
  if (bad_state_return())
    return;
  std::ifstream fin(fname);

  if (!fin.is_open()) {
    ILA_ERROR << "Cannot read from file:" << fname;
    _bad_state = true;
    return;
  }

  // remove the comments
  std::string contents;
  std::string line;
  while (std::getline(fin,line)) {
    auto comment_begin = find_comments(line);
    if (comment_begin != std::string::npos)
      contents += line.substr(0,comment_begin);
    else
      contents += line;
    contents += "\n";
  }
  j = nlohmann::json::parse(contents);
} // load_json

}; // namespace ilang
