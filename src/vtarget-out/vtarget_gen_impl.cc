/// \file Source for Verilog Verification Targets Generation
///
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <cmath>
#include <iostream>

#include <ilang/ila/ast_hub.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/vtarget_gen_jasper.h>
#include <ilang/vtarget-out/vtarget_gen_pono.h>
// #include <ilang/vtarget-out/vtarget_gen_relchc.h>
// #include <ilang/vtarget-out/vtarget_gen_yosys.h>
// for invariant synthesis
// #include <ilang/vtarget-out/inv-syn/vtarget_gen_inv_abc.h>
// #include <ilang/vtarget-out/inv-syn/vtarget_gen_inv_chc.h>
// #include <ilang/vtarget-out/inv-syn/vtarget_gen_inv_enhance.h>

namespace ilang {

// ------------------------------ VlgVerifTgtGen ---------------------------- //

VlgVerifTgtGen::VlgVerifTgtGen(
    const std::vector<std::string>& implementation_include_path,
    const std::vector<std::string>& implementation_srcs,
    const std::string& implementation_top_module,
    const rfmap::VerilogRefinementMap& refinement,
    const std::string& output_path, const InstrLvlAbsPtr& ila_ptr,
    ModelCheckerSelection backend, const RtlVerifyConfig& vtg_config,
    advanced_parameters_t* adv_ptr)
    : _vlg_impl_include_path(implementation_include_path),
      _vlg_impl_srcs(implementation_srcs),
      _vlg_impl_top_name(implementation_top_module), _refinement(refinement),
      _output_path(output_path), _ila_ptr(ila_ptr),
      // configure is only for ila, generate the start signal
      vlg_info_ptr(
          NULL), // not creating it now, because we don't have the info to do so
      _backend(backend), _vtg_config(vtg_config), _advanced_param_ptr(adv_ptr),
      _bad_state(false) {

  if (_ila_ptr == nullptr) {
    ILA_ERROR << "ILA should not be none";
    _bad_state = true;
  }

  // TODO: check more
}

VlgVerifTgtGen::~VlgVerifTgtGen() {
  if (vlg_info_ptr)
    delete vlg_info_ptr;
}

const std::vector<std::string>& VlgVerifTgtGen::GetRunnableScriptName() const {
  return runnable_script_name;
}

void VlgVerifTgtGen::GenerateTargets(void) {
  if (bad_state_return())
    return;

  runnable_script_name.clear();

  vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs, "RTL",
                                 _vlg_impl_top_name);

  if (vlg_info_ptr == NULL || vlg_info_ptr->in_bad_state()) {
    ILA_ERROR << "Unable to generate targets. Verilog parser failed.";
    return; //
  }

  if (!isValidVerifBackend(_backend)) {
    ILA_ERROR << "Unknown backend specification:" << int(_backend) << ", quit.";
    return;
  }

  if (_vtg_config.target_select == RtlVerifyConfig::BOTH ||
      _vtg_config.target_select == RtlVerifyConfig::INV) {
    // check if there are really invariants:
    bool invariantExists = false;
    if (!_refinement.global_invariants.empty())
      invariantExists = true;

    if ((_vtg_config.ValidateSynthesizedInvariant ==
             RtlVerifyConfig::_validate_synthesized_inv::ALL ||
         _vtg_config.ValidateSynthesizedInvariant ==
             RtlVerifyConfig::_validate_synthesized_inv::CONFIRMED) &&
        (_advanced_param_ptr && _advanced_param_ptr->_inv_obj_ptr != NULL &&
         !_advanced_param_ptr->_inv_obj_ptr->GetVlgConstraints().empty()))
      invariantExists = true;

    if ((_vtg_config.ValidateSynthesizedInvariant ==
             RtlVerifyConfig::_validate_synthesized_inv::ALL ||
         _vtg_config.ValidateSynthesizedInvariant ==
             RtlVerifyConfig::_validate_synthesized_inv::CANDIDATE) &&
        (_advanced_param_ptr &&
         _advanced_param_ptr->_candidate_inv_ptr != NULL &&
         !_advanced_param_ptr->_candidate_inv_ptr->GetVlgConstraints().empty()))
      invariantExists = true;

    auto sub_output_path = os_portable_append_dir(_output_path, "invariants");
    if (_backend == ModelCheckerSelection::PONO && invariantExists) {
      auto target = VlgSglTgtGen_Pono(
          sub_output_path,
          NULL, // invariant
          _ila_ptr, _refinement, vlg_info_ptr, "wrapper", _vlg_impl_srcs,
          _vlg_impl_include_path, _vtg_config, _backend,
          target_type_t::INVARIANTS, _advanced_param_ptr);
      target.ConstructWrapper();
      target.ExportAll("wrapper.v", "ila.v", "run.sh", "gen_btor.ys");
      target.do_not_instantiate(); // no use, just for coverage
    } else if (_backend == ModelCheckerSelection::JASPERGOLD && invariantExists) {
      auto target = VlgSglTgtGen_Jasper(
          sub_output_path,
          NULL, // invariant
          _ila_ptr, _refinement, vlg_info_ptr, "wrapper", _vlg_impl_srcs,
          _vlg_impl_include_path, _vtg_config, _backend,
          target_type_t::INVARIANTS, _advanced_param_ptr);
      target.ConstructWrapper();
      target.ExportAll("wrapper.v", "ila.v", "run.sh", "do.tcl");
      target.do_not_instantiate(); // no use, just for coverage
    }
#if 0 
    else if (_backend == ModelCheckerSelection::RELCHC && invariantExists) {
      // will actually fail : not supported for using relchc for invariant
      // targets
      auto target = VlgSglTgtGen_Relchc(
          sub_output_path,
          NULL, // invariant
          _ila_ptr, _cfg, rf_vmap, rf_cond, supplementary_info, vlg_info_ptr,
          "wrapper", _vlg_impl_srcs,
          _vlg_impl_include_path, _vtg_config, _backend,
          target_type_t::INVARIANTS, _advanced_param_ptr);
      target.ConstructWrapper();
      target.ExportAll("wrapper.v", "ila.v", "run.sh", "__design_smt.smt2",
                       "absmem.v");
      target.do_not_instantiate();
    } else if ((_backend & ModelCheckerSelection::YOSYS) ==
                   ModelCheckerSelection::YOSYS &&
               invariantExists) {
      auto target = VlgSglTgtGen_Yosys(
          sub_output_path,
          NULL, // instruction
          _ila_ptr, _cfg, rf_vmap, rf_cond, supplementary_info, vlg_info_ptr,
          "wrapper", _vlg_impl_srcs,
          _vlg_impl_include_path, _vtg_config, _backend,
          target_type_t::INVARIANTS, _advanced_param_ptr,
          _chc_target_t::GENERAL_PROPERTY);
      target.ConstructWrapper();
      std::string design_file;
      if (_backend == ModelCheckerSelection::ABCPDR)
        design_file = "wrapper.aig";
      else if ((_backend & ModelCheckerSelection::CHC) == ModelCheckerSelection::CHC)
        design_file = "wrapper.smt2";
      else if (_backend == ModelCheckerSelection::BTOR_GENERIC)
        design_file = "wrapper.btor2";
      else
        design_file = "wrapper.unknfmt";

      target.ExportAll("wrapper.v", "ila.v", "run.sh", design_file, "absmem.v");
      target.do_not_instantiate();
    }
#endif
    if (invariantExists)
      runnable_script_name.push_back(
          os_portable_append_dir(sub_output_path, "run.sh"));
    // end if backend...
  } // end if if(_vtg_config.target_select == BOTH || _vtg_config.target_select
    // == INV)

  // now let's deal w. instructions in rf_cond
  if (_vtg_config.target_select == RtlVerifyConfig::BOTH ||
      _vtg_config.target_select == RtlVerifyConfig::INST) {
    bool generate_forall_inst = _refinement.global_inst_complete_set;

    for (auto&& instr : _refinement.inst_complete_cond) {
      std::string iname = instr.first;
      auto instr_ptr = _ila_ptr->instr(iname);
      ILA_ERROR_IF(instr_ptr == nullptr) 
                << "ila:" << _ila_ptr->name().str()
                << " has no instruction:" << iname;
    }
    for (unsigned inst_idx = 0; inst_idx < _ila_ptr->instr_num() ; ++ inst_idx) {
      auto instr_ptr = _ila_ptr->instr(inst_idx);
      std::string iname = instr_ptr->name().str();
      if (_vtg_config.CheckThisInstructionOnly != "" &&
          _vtg_config.CheckThisInstructionOnly != iname)
        continue; // skip, not checking this instruction
      if (!generate_forall_inst && 
        _refinement.inst_complete_cond.find(iname) == _refinement.inst_complete_cond.end())
        continue;
      
      auto sub_output_path = os_portable_append_dir(_output_path, iname);

      if (_backend == ModelCheckerSelection::PONO) {
        auto target = VlgSglTgtGen_Pono(
            sub_output_path,
            instr_ptr, // instruction
            _ila_ptr, _refinement, vlg_info_ptr, "wrapper", _vlg_impl_srcs,
            _vlg_impl_include_path, _vtg_config, _backend,
            target_type_t::INSTRUCTIONS, _advanced_param_ptr);
        target.ConstructWrapper();
        target.ExportAll("wrapper.v", "ila.v", "run.sh", "gen_btor.ys");
        target.do_not_instantiate();
      } else if (_backend == ModelCheckerSelection::JASPERGOLD) {
        auto target = VlgSglTgtGen_Jasper(
            sub_output_path,
            instr_ptr, // instruction
            _ila_ptr, _refinement, vlg_info_ptr, "wrapper", _vlg_impl_srcs,
            _vlg_impl_include_path, _vtg_config, _backend,
            target_type_t::INSTRUCTIONS, _advanced_param_ptr);
        target.ConstructWrapper();
        target.ExportAll("wrapper.v", "ila.v", "run.sh", "do.tcl");
        target.do_not_instantiate();
      }
      runnable_script_name.push_back(
          os_portable_append_dir(sub_output_path, "run.sh"));
    } // end for instrs
  }   // end if target select == ...

  if (vlg_info_ptr) {
    delete vlg_info_ptr;
    vlg_info_ptr = NULL;
  }
} // end of function GenerateTargets

bool VlgVerifTgtGen::bad_state_return(void) {
  ILA_ERROR_IF(_bad_state)
      << "VlgVerifTgtGen is in a bad state, cannot proceed.";
  return _bad_state;
} // bad_state_return

#if 0

std::shared_ptr<smt::YosysSmtParser>
VlgVerifTgtGen::GenerateInvSynTargets(synthesis_backend_selector s_backend) {
  ILA_CHECK(_backend == ModelCheckerSelection::YOSYS)
      << "All inv-syn relies on yosys!";

  if (vlg_info_ptr)
    delete vlg_info_ptr;

  vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs,
                                 "RTL", _vlg_impl_top_name);
  if (vlg_info_ptr == NULL or vlg_info_ptr->in_bad_state()) {
    ILA_ERROR << "Unable to generate targets. Verilog parser failed.";
    return nullptr; //
  }

  // parameter override
  auto tmp_vtg_config(_vtg_config);
  tmp_vtg_config.CosaDotReferenceNotify =
      RtlVerifyConfig::CosaDotReferenceNotify_t::NOTIFY_PANIC;

  auto target = VlgSglTgtGen_Chc(
      os_portable_append_dir(_output_path, "inv-syn/"),
      NULL, // invariant
      _ila_ptr, _cfg, rf_vmap, rf_cond, supplementary_info, vlg_info_ptr,
      "wrapper", _vlg_impl_srcs,
      _vlg_impl_include_path, tmp_vtg_config, _backend, s_backend,
      target_type_t::INV_SYN_DESIGN_ONLY, _advanced_param_ptr, true,
      _chc_target_t::CEX);
  target.ConstructWrapper();
  target.ExportAll("wrapper.v", "ila.v" /*USELESS*/, "run.sh", "wrapper.smt2",
                   "absmem.v" /*USELESS*/);
  runnable_script_name.clear();
  runnable_script_name.push_back(os_portable_append_dir(
      os_portable_append_dir(_output_path, "inv-syn/"), "run.sh"));

  target.do_not_instantiate();
  return target.GetDesignSmtInfo();
} // GenerateInvSynTargets

std::shared_ptr<smt::YosysSmtParser>
VlgVerifTgtGen::GenerateInvSynEnhanceTargets(const InvariantInCnf& cnf) {
  ILA_ERROR_IF(_backend != ModelCheckerSelection::YOSYS)
      << "All inv-syn relies on yosys!";

  if (vlg_info_ptr)
    delete vlg_info_ptr;

  vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs,
                                 "RTL", _vlg_impl_top_name);
  if (vlg_info_ptr == NULL or vlg_info_ptr->in_bad_state()) {
    ILA_ERROR << "Unable to generate targets. Verilog parser failed.";
    return nullptr; //
  }

  // use a temporary configuration
  auto tmp_vtg_config = _vtg_config;
  tmp_vtg_config.InvariantSynthesisReachableCheckKeepOldInvariant = true;
  tmp_vtg_config.YosysSmtFlattenDatatype = true;
  tmp_vtg_config.CosaDotReferenceNotify =
      RtlVerifyConfig::CosaDotReferenceNotify_t::NOTIFY_PANIC;

  // TODO: you may need to change a bit of _advanced_param_ptr's inv
  // and maybe the assume inv part
  auto target = VlgSglTgtGen_Chc_wCNF(
      os_portable_append_dir(_output_path, "inv-enhance/"),
      NULL, // invariant
      _ila_ptr, _cfg, rf_vmap, rf_cond, supplementary_info, vlg_info_ptr,
      "wrapper", _vlg_impl_srcs,
      _vlg_impl_include_path, tmp_vtg_config, _backend,
      VlgVerifTgtGenBase::synthesis_backend_selector::GRAIN,
      target_type_t::INV_SYN_DESIGN_ONLY, _advanced_param_ptr, true,
      _chc_target_t::CEX);
  target.ConstructWrapper();
  target.ExportAll("wrapper.v", "ila.v" /*USELESS*/, "run.sh", "wrapper.smt2",
                   "absmem.v" /*USELESS*/, "inv_cnf.txt", cnf);
  target.do_not_instantiate();
  runnable_script_name.clear();
  runnable_script_name.push_back(os_portable_append_dir(
      os_portable_append_dir(_output_path, "inv-enhance/"), "run.sh"));


  return target.GetDesignSmtInfo();
} // GenerateInvSynEnhanceTargets

void VlgVerifTgtGen::GenerateInvSynTargetsAbc(bool useGla, bool useCorr,
                                              bool useAiger) {
  ILA_ERROR_IF(_backend != ModelCheckerSelection::YOSYS)
      << "All inv-syn relies on yosys!";

  if (vlg_info_ptr)
    delete vlg_info_ptr;

  vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs,
                                 "RTL", _vlg_impl_top_name);
  if (vlg_info_ptr == NULL or vlg_info_ptr->in_bad_state()) {
    ILA_ERROR << "Unable to generate targets. Verilog parser failed.";
    return; //
  }
  // parameter override
  auto tmp_vtg_config(_vtg_config);
  tmp_vtg_config.CosaDotReferenceNotify =
      RtlVerifyConfig::CosaDotReferenceNotify_t::NOTIFY_PANIC;

  auto target = VlgSglTgtGen_Abc(
      os_portable_append_dir(_output_path, "inv-syn-abc/"),
      NULL, // invariant
      _ila_ptr, _cfg, rf_vmap, rf_cond, supplementary_info, vlg_info_ptr,
      "wrapper", _vlg_impl_srcs,
      _vlg_impl_include_path, tmp_vtg_config, _backend,
      synthesis_backend_selector::ABC, target_type_t::INV_SYN_DESIGN_ONLY,
      _advanced_param_ptr, true, _chc_target_t::CEX, useGla, useCorr, useAiger);
  target.ConstructWrapper();
  target.ExportAll("wrapper.v", "ila.v" /*USELESS*/, "run.sh",
                   useAiger ? "wrapper.aig" : "wrapper.blif",
                   "absmem.v" /*USELESS*/);

  runnable_script_name.clear();
  runnable_script_name.push_back(os_portable_append_dir(
      os_portable_append_dir(_output_path, "inv-syn-abc/"), "run.sh"));
} // GenerateInvSynTargetsAbc

#endif

}; // namespace ilang
