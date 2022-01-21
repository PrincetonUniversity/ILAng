/// \file Source for Verilog Verification Targets Generation (single target)
///
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <cmath>
#include <fstream>
#include <iostream>

#include <ilang/ila/ast_hub.h>
#include <ilang/mcm/ast_helper.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

// ------------- CONFIGURATIONS -------------------- //

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"

#define IntToStr(x) (std::to_string(x))

// ------------------------------ VlgSglTgtGen ---------------------------------
// //

VlgSglTgtGen::VlgSglTgtGen(
    const std::string&
        output_path, // will be a sub directory of the output_path of its parent
    const InstrPtr& instr_ptr, // which could be an empty pointer, and it will
                               // be used to verify invariants
    const InstrLvlAbsPtr& ila_ptr,
    const rfmap::VerilogRefinementMap& refinement, VerilogInfo* _vlg_info_ptr,
    const std::string& wrapper_name,
    const std::vector<std::string>& implementation_srcs,
    const std::vector<std::string>& implementation_include_path,
    const RtlVerifyConfig& vtg_config, ModelCheckerSelection backend,
    const target_type_t& target_tp, advanced_parameters_t* adv_ptr)
    : _output_path(output_path), _instr_ptr(instr_ptr), _host(ila_ptr),
      _vlg_mod_inst_name("RTL"), _ila_mod_inst_name("ILA"),
      // default option on wrapper
      vlg_wrapper(
          VerilogGenerator::VlgGenConfig(true, // ExternalMem
                                         VerilogGeneratorBase::VlgGenConfig::
                                             funcOption::External, // function
                                         false,  // no start signal
                                         false,  // no pass node name
                                         false,  // no rand init
                                         false,  // no expand memory
                                         false), // no collect ITE unknown
          wrapper_name),
      // use given, except for core options
      vlg_ila(VerilogGeneratorBase::VlgGenConfig(
          false, // default case: internal memory
          VerilogGeneratorBase::VlgGenConfig::funcOption::External, // external
                                                                    // function
          true,                              // w. start signal
          vtg_config.VerilogGenPassNodeName, // pass node name
          true,                             // has rand init
          false,                             // no expand memory
          false                              // no collecte ITE unknown
          )),
      // interface mapping directive
      // -------- CONTROLLING THE RESET CONNECTION ------------- //
      _idr(target_tp == target_type_t::INVARIANTS ||
                   target_tp == target_type_t::INV_SYN_DESIGN_ONLY
               ? true
               : (vtg_config.ForceInstCheckReset ? true : false)),
      // if checking instruction: by default, we don't reset
      // but if forced, we do; For the design only thing
      // we do ensure reset also

      // verilog info
      vlg_info_ptr(_vlg_info_ptr),
      // variable extractor
      //_vext(
      //    [this](const std::string& n) -> bool { return TryFindIlaState(n); },
      //    [this](const std::string& n) -> bool { return TryFindIlaInput(n); },
      //    [this](const std::string& n) -> bool { return TryFindVlgState(n);
      //    }),
      // ref to refmaps
      refinement_map(refinement, /*type checker*/
                     [this](const std::string& n) -> rfmap::RfVarTypeOrig {
                       return this->VarTypeCheckForRfExprParsing(n);
                     }),

      target_type(target_tp), // whether it is
                              // invariant/instructions
      max_bound(127), cnt_width(1), _advanced_param_ptr(adv_ptr),
      has_gussed_synthesized_invariant(
          adv_ptr && adv_ptr->_candidate_inv_ptr &&
          !adv_ptr->_candidate_inv_ptr->GetVlgConstraints().empty()),
      has_confirmed_synthesized_invariant(
          adv_ptr && adv_ptr->_inv_obj_ptr &&
          !adv_ptr->_inv_obj_ptr->GetVlgConstraints().empty()),
      has_rf_invariant(!refinement_map.global_invariants.empty()),
      mapping_counter(0), property_counter(0), top_mod_name(wrapper_name),
      vlg_design_files(implementation_srcs),
      vlg_include_files_path(implementation_include_path),
      _vtg_config(vtg_config), _backend(backend), _bad_state(false) {

  ILA_NOT_NULL(_host);

  ILA_CHECK(target_type == target_type_t::INVARIANTS ||
            target_type == target_type_t::INSTRUCTIONS ||
            target_type == target_type_t::INV_SYN_DESIGN_ONLY)
      << "Implementation bug: unrecognized target type!";

  if (target_type == target_type_t::INSTRUCTIONS) {

    ILA_NOT_NULL(instr_ptr);
    RfmapIlaStateSanityCheck();

    // TODO: insert the memory export directive
    VerilogGeneratorBase::memory_export_annotation_t mem_annotation;
    for (unsigned sidx = 0; sidx < _host->state_num(); ++sidx) {
      const auto& s = _host->state(sidx);
      if (!s->is_mem())
        continue;
      const auto& n = s->name().str();
      auto pos = refinement_map.ila_state_var_map.find(n);
      if (pos == refinement_map.ila_state_var_map.end())
        continue;
      if (pos->second.type == rfmap::IlaVarMapping::StateVarMapType::EXTERNMEM)
        mem_annotation.emplace(n, true);
      else
        mem_annotation.emplace(n, false);
    } // end - for each mem state

    vlg_ila.AnnotateMemory(mem_annotation); // need to change this

    vlg_ila.ExportTopLevelInstr(instr_ptr);

    if (vlg_ila.decodeNames.size() != 1) {
      ILA_ERROR << "Implementation bug btw. vlg gen and vtarget-gen";
      _bad_state = true;
    }

    // vlg_ila.ila_rports/ila_wports -> internal wire
    // register_ila_memory_wires();
    // no this is not needed
    // the ports are connected to wires with names like
    // __IMEM_xxx_...
    // this is in single_target_connect.cc

  } // END of target_type == INSTRUCTION
  else if (target_type == target_type_t::INVARIANTS) {
    ILA_WARN_IF(instr_ptr != nullptr)
        << "Provide an instruction "
        << "when verifying invariants. The instruction will not be used";
  }
} // END of constructor

void VlgSglTgtGen::ConstructWrapper_generate_header() {
  vlg_wrapper.add_preheader("\n`define true  1'b1\n");
  vlg_wrapper.add_preheader("\n`define false 1'b0\n");
  vlg_wrapper.add_preheader("\n" + _vtg_config.WrapperPreheader + "\n");
} // ConstructWrapper_generate_header

void VlgSglTgtGen::ConstructWrapper_add_inputmap_assumptions() {

  std::set<std::string> ila_input_names;

  for (size_t input_idx = 0; input_idx < _host->input_num(); ++input_idx)
    ila_input_names.insert(_host->input(input_idx)->name().str());

  for (const auto& iv_rfmap : refinement_map.ila_input_var_map) {
    const auto& iname = iv_rfmap.first;
    if (ila_input_names.find(iname) == ila_input_names.end()) {
      ILA_ERROR << "Cannot find ILA input with name: " << iname;
      continue;
    }
    ila_input_names.erase(iname);

    Gen_input_map_assumpt(iname, iv_rfmap.second, "input_map_assume_");
  }

  if (!ila_input_names.empty()) {
    ILA_ERROR << "Lack input var map for the following variables:";
    for (const auto& in : ila_input_names)
      ILA_ERROR << in;
  }
}

// for special memory, we don't need to do anything?
void VlgSglTgtGen::ConstructWrapper_add_varmap_assumptions() {
  ILA_CHECK(target_type == target_type_t::INSTRUCTIONS)
      << "Implementation bug: vmap assumpt should only be used when verifying "
         "instructions.";
  std::set<std::string> ila_state_names;

  for (size_t state_idx = 0; state_idx < _host->state_num(); ++state_idx)
    ila_state_names.insert(_host->state(state_idx)->name().str());

  for (const auto& sv_rfmap : refinement_map.ila_state_var_map) {
    const auto& sname = sv_rfmap.first;
    if (!IN(sname, ila_state_names)) {
      ILA_ERROR << sname
                << " is not a state of the ILA:" << _host->name().str();
      continue;
    }

    if (_vtg_config.OnlyAssumeUpdatedVarsEq &&
        _instr_ptr->update(sname) == nullptr) {
      ILA_DLOG("VtargetGen") << "Skip assume EQ on variable:" << sname
                             << " for instruction:" << _instr_ptr->name().str();
      continue;
    }
    ila_state_names.erase(sname);
    ILA_DLOG("VtargetGen.ConstructWrapper_add_varmap_assumptions") << sname;

    std::string problem_name = "variable_map_assume_";

    Gen_varmap_assumpt_assert(sname, sv_rfmap.second, problem_name, true);
  } // end for each state variable

  ILA_DLOG("VtargetGen") << "STEP:"
                         << "5.2.2";
  // check for unmapped states
  if (!ila_state_names.empty()) {
    ILA_ERROR << "Refinement relation: missing state-mapping for the following "
                 "state variables:";
    for (auto&& sn : ila_state_names)
      ILA_ERROR << "  " << sn;
  }
} // ConstructWrapper_add_varmap_assumptions

// for memory, we need to assert new data match and ?
//
void VlgSglTgtGen::ConstructWrapper_add_varmap_assertions() {
  ILA_CHECK(target_type == target_type_t::INSTRUCTIONS)
      << "Implementation bug: vmap assts should only be used when verifying "
         "instructions.";
  std::set<std::string> ila_state_names;

  // put the ila_states to the set, so we can know if state-mapping
  // refers to some wrong state names
  for (size_t state_idx = 0; state_idx < _host->state_num(); ++state_idx)
    ila_state_names.insert(_host->state(state_idx)->name().str());

  for (const auto& sv_rfmap : refinement_map.ila_state_var_map) {
    const auto& sname = sv_rfmap.first;
    if (!IN(sname, ila_state_names)) {
      ILA_ERROR << sname
                << " is not a state of the ILA:" << _host->name().str();
      continue;
    }
    ila_state_names.erase(sname);

    if (_vtg_config.OnlyCheckInstUpdatedVars &&
        _instr_ptr->update(sname) == nullptr) {
      ILA_DLOG("VtargetGen") << "Skip assume EQ on variable:" << sname
                             << " for instruction:" << _instr_ptr->name().str();
      continue;
    }
    ILA_DLOG("VtargetGen.ConstructWrapper_add_varmap_assertions") << sname;

    // just check if we miss any function in uf section
    FunctionApplicationFinder func_app_finder(_instr_ptr->update(sname));
    for (auto&& func_ptr : func_app_finder.GetReferredFunc()) {
      // handle the IteUnknown function case
      ILA_ERROR_IF(!IN(func_ptr->name().str(), refinement_map.uf_application))
          << "uf: " << func_ptr->name().str() << " in "
          << _instr_ptr->name().str() << " updating state:" << sname
          << " is not provided in rfmap!";
    }

    std::string problem_name = "variable_map_assert";
    // for Yosys, we must keep the name the same
    // so it knows these are for variable map assertions

    // 'true' below means it is for assertions (only different for mapping
    // memory) if assumption, nothing to be done if assertions, ask _idr to
    // connect and get the eq name

    // for Yosys inv-synthesis, we don't mind the precondition
    // that's part the assertions, so it should be fine

    Gen_varmap_assumpt_assert(sname, sv_rfmap.second, problem_name, false);
  } // end - for each state var
} // ConstructWrapper_add_varmap_assertions

//  NON-FLUSH case
//  1 RESET
//  2 ISSUE = true      RESETED (forever)
//  3           START                     ---> assume varmap  ---> assume inv
//  4                   STARTED
//  5                   STARTED
//  ...                   ...
//  6           IEND                      ---> check varmap
//  7                     ENDED

// for invariants or for instruction
void VlgSglTgtGen::ConstructWrapper() {
  ILA_CHECK(target_type == target_type_t::INVARIANTS ||
            target_type == target_type_t::INSTRUCTIONS ||
            target_type == target_type_t::INV_SYN_DESIGN_ONLY);

  if (bad_state_return())
    return;
  ILA_DLOG("VtargetGen") << "STEP:" << 1;
  // 0. The headers you may need to have
  ConstructWrapper_generate_header();
  ILA_DLOG("VtargetGen") << "STEP:" << 2;

  if (target_type != target_type_t::INSTRUCTIONS)
    max_bound = _vtg_config.MaxBound;

  // if invariants, will do nothing
  if (target_type == target_type_t::INSTRUCTIONS) {
    // __CYCLE_CNT__, START RESETED and etc.
    ConstructWrapper_add_cycle_count_moniter();
    // IEND ENDCOND and etc. (will use cycle count)
    ConstructWrapper_add_condition_signals();
  } else
    ConstructWrapper_inv_syn_cond_signals();

  // 1. dealing with reset
  ConstructWrapper_reset_setup(); // will use __RESETED__

  ILA_DLOG("VtargetGen") << "STEP:" << 3;
  // -- find out the inputs
  ConstructWrapper_add_vlg_input_output();
  ILA_DLOG("VtargetGen") << "STEP:" << 4;
  ConstructWrapper_add_ila_input();
  ILA_DLOG("VtargetGen") << "STEP:" << 5;

  if (target_type == target_type_t::INSTRUCTIONS) {
    ILA_DLOG("VtargetGen") << "STEP:" << 5.1;
    ConstructWrapper_add_inputmap_assumptions();
    ILA_DLOG("VtargetGen") << "STEP:" << 5.2;
    ConstructWrapper_add_varmap_assumptions();
    ILA_DLOG("VtargetGen") << "STEP:" << 5.3;
    ConstructWrapper_add_varmap_assertions();
    ILA_DLOG("VtargetGen") << "STEP:" << 5.4;
    ConstructWrapper_add_inv_assumption_or_assertion_target_instruction();
  } else if (target_type == target_type_t::INVARIANTS) {
    ConstructWrapper_add_inv_assumption_or_assertion_target_invariant();
  } else if (target_type == target_type_t::INV_SYN_DESIGN_ONLY) {
    ConstructWrapper_add_inv_assumption_or_assertion_target_inv_syn_design_only();
  }

  ILA_DLOG("VtargetGen") << "STEP:" << 6;
  // 4. additional mapping if any
  if (target_type == target_type_t::INSTRUCTIONS)
    ConstructWrapper_add_additional_mapping_control();

  ConstructWrapper_add_rf_assumptions();

  ILA_DLOG("VtargetGen") << "STEP:" << 8;

  // post value holder --- ABC cannot work on this
  if (target_type == target_type_t::INSTRUCTIONS) {
    // the vars defined here are already
    // presented in refinement_map.all_var_def_type
    ConstructWrapper_add_post_value_holder();
    ConstructWrapper_add_delay_unit();
    ConstructWrapper_add_stage_tracker();
    // you cannot always add aux vars
    // because it may refer to other aux vars (like post value holder)
    // unless we have a way to check hierarchically
    // the dependency
    ConstructWrapper_add_direct_aux_vars();
  }

  ConstructWrapper_add_vlg_monitor();
  // add monitor -- inside the monitor, there will be
  // disable logic if it is for invariant type target

  // 7. uni-functions
  if (target_type == target_type_t::INSTRUCTIONS)
    ConstructWrapper_add_uf_constraints();

  // instantiate ila module
  if (target_type == target_type_t::INSTRUCTIONS) {
    auto ila_mod_inst = ConstructWrapper_get_ila_module_inst();
    vlg_wrapper.add_stmt(ila_mod_inst);
  }

  // read assumption/assertion, decide where to put them rtl/smt
  // perform the reg[n] optimize
  // populate the RtlExtraWire data structure
  ConstructWrapper_translate_property_and_collect_all_rtl_connection_var();
  // 1. varname 2. hierarchy 3. what to connect inside

  // 5.0 add the extra wires to the top module wrapper
  // will use var_replacement, and will set _idr
  if (VlgVerifTgtGenBase::backend_needs_yosys(_backend))
    ConstructWrapper_register_extra_io_wire();

  ILA_DLOG("VtargetGen") << "STEP:" << 9;
  // 5. module instantiation
  // for the vlg inst: will use _idr
  ConstructWrapper_add_module_instantiation();

  // 2. add some monitors (bound cnt)
  // 3. add assumptions & assertions
} // Construct_wrapper

/// create the wrapper file
void VlgSglTgtGen::Export_wrapper(const std::string& wrapper_name) {
  top_file_name = wrapper_name;
  std::ofstream fout(os_portable_append_dir(_output_path, wrapper_name));
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing file: "
              << os_portable_append_dir(_output_path, wrapper_name);
    return;
  }
  vlg_wrapper.DumpToFile(fout);

  // for append verilog
  for (const auto& vlg_monitor : refinement_map.customized_monitor) {
    if (vlg_monitor.second.verilog_append.empty())
      continue;
    if (!vlg_monitor.second.keep_for_invariant &&
        target_type != target_type_t::INSTRUCTIONS)
      continue;

    fout << "/***** BEGIN of Monitor for " << vlg_monitor.first << " *****/\n";
    fout << vlg_monitor.second.verilog_append;
    fout << "/***** END of Monitor for " << vlg_monitor.first << " *****/\n";
  }
}

/// export the ila verilog
void VlgSglTgtGen::Export_ila_vlg(const std::string& ila_vlg_name) {

  if (target_type == target_type_t::INVARIANTS) {
    ila_file_name = "";
    ILA_WARN << "Should not export ila when verifying invariants.";
    return;
  }

  ila_file_name = ila_vlg_name;
  std::ofstream fout;
  std::string fn;
  if (VlgVerifTgtGenBase::backend_needs_yosys(_backend)) {
    fn = os_portable_append_dir(_output_path, top_file_name);
    fout.open(fn, std::ios_base::app);
  } else if (_backend == ModelCheckerSelection::JASPERGOLD) {
    fn = os_portable_append_dir(_output_path, ila_vlg_name);
    fout.open(fn);
  }
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing ila to file: " << fn;
    return;
  }
  vlg_ila.DumpToFile(fout);
} // end of Export_ila_vlg

void VlgSglTgtGen::ExportAll(const std::string& wrapper_name,
                             const std::string& ila_vlg_name,
                             const std::string& script_name,
                             const std::string& extra_name) {
  PreExportProcess();
  if (os_portable_mkdir(_output_path) == false)
    ILA_WARN << "Cannot create output directory:" << _output_path;
  // you don't need to worry about the path and names
  Export_wrapper(wrapper_name);
  if (target_type == target_type_t::INSTRUCTIONS)
    Export_ila_vlg(ila_vlg_name); // this has to be after Export_wrapper

  // for Jasper, this will be put to multiple files
  // for CoSA & Yosys, this will be put after the wrapper file (wrapper.v)
  Export_modify_verilog(); // this must be after Export_wrapper

  Export_problem(extra_name); // for JG this is do.tcl
                              // for Pono: this is the yosys.script and
  Export_script(script_name);
} // end of ExportAll

} // namespace ilang
