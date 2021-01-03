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
    const InstrLvlAbsPtr& ila_ptr, const VerilogGenerator::VlgGenConfig& config,
    nlohmann::json& _rf_vmap, nlohmann::json& _rf_cond,
    VlgTgtSupplementaryInfo& _supplementary_info, VerilogInfo* _vlg_info_ptr,
    const std::string& vlg_mod_inst_name, const std::string& ila_mod_inst_name,
    const std::string& wrapper_name,
    const std::vector<std::string>& implementation_srcs,
    const std::vector<std::string>& implementation_include_path,
    const vtg_config_t& vtg_config, backend_selector backend,
    const target_type_t& target_tp, advanced_parameters_t* adv_ptr)
    : _output_path(output_path), _instr_ptr(instr_ptr), _host(ila_ptr),
      _vlg_mod_inst_name(vlg_mod_inst_name),
      _ila_mod_inst_name(ila_mod_inst_name),
      // default option on wrapper
      vlg_wrapper(
          VerilogGenerator::VlgGenConfig(config, // use default configuration
                                         true,
                                         VerilogGeneratorBase::VlgGenConfig::
                                             funcOption::External, // function
                                         false,  // no start signal
                                         false,  // no rand init
                                         false,  // no expand memory
                                         false), // no collect ITE unknown
          wrapper_name),
      // use given, except for core options
      vlg_ila(VerilogGeneratorBase::VlgGenConfig(
          config,
          // except overwriting these: external memory
          // if expand memory, then the ila's memory must be internal
          config
              .extMem, // this depends on the given configuration (default case)
          VerilogGeneratorBase::VlgGenConfig::funcOption::External, true,
          true, // rand init
          true, // for internal should always expand (probe) memory
          vtg_config
              .IteUnknownAutoIgnore // may collect depends on configuration
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

      // state-mapping directive
      _sdr(), // currently no
      // verilog info
      vlg_info_ptr(_vlg_info_ptr),
      // variable extractor
      _vext(
          [this](const std::string& n) -> bool { return TryFindIlaState(n); },
          [this](const std::string& n) -> bool { return TryFindIlaInput(n); },
          [this](const std::string& n) -> bool { return TryFindVlgState(n); }),
      // ref to refmaps
      rf_vmap(_rf_vmap), rf_cond(_rf_cond), empty_json(nullptr),
      supplementary_info(_supplementary_info),
      target_type(target_tp), // whether it is
                              // invariant/instructions
      has_flush(false), ready_type(ready_type_t::NA), max_bound(127),
      cnt_width(1), _advanced_param_ptr(adv_ptr),
      has_gussed_synthesized_invariant(
          adv_ptr && adv_ptr->_candidate_inv_ptr &&
          !adv_ptr->_candidate_inv_ptr->GetVlgConstraints().empty()),
      has_confirmed_synthesized_invariant(
          adv_ptr && adv_ptr->_inv_obj_ptr &&
          !adv_ptr->_inv_obj_ptr->GetVlgConstraints().empty()),
      has_rf_invariant((IN("global invariants", _rf_cond) &&
                        rf_cond["global invariants"].size() != 0) ||
                       (IN("global-invariants", _rf_cond) &&
                        rf_cond["global-invariants"].size() != 0)),
      mapping_counter(0), property_counter(0), top_mod_name(wrapper_name),
      vlg_design_files(implementation_srcs),
      vlg_include_files_path(implementation_include_path),
      _vtg_config(vtg_config), _vlg_cfg(config), _backend(backend),
      _bad_state(false) {

  ILA_NOT_NULL(_host);

  ILA_CHECK(target_type == target_type_t::INVARIANTS ||
            target_type == target_type_t::INSTRUCTIONS ||
            target_type == target_type_t::INV_SYN_DESIGN_ONLY)
      << "Implementation bug: unrecognized target type!";

  // reset absmem's counter
  VlgAbsMem::ClearAbsMemRecord();

  if (has_rf_invariant) {
    if (IN("global invariants", rf_cond) &&
        !rf_cond["global invariants"].is_array()) {
      ILA_ERROR
          << "'global invariants' field in refinement relation has to be a "
             "JSON array.";
      _bad_state = true;
      return;
    }
    if (IN("global-invariants", rf_cond) &&
        !rf_cond["global-invariants"].is_array()) {
      ILA_ERROR
          << "'global-invariants' field in refinement relation has to be a "
             "JSON array.";
      _bad_state = true;
      return;
    }
  }

  if (target_type == target_type_t::INSTRUCTIONS) {

    ILA_NOT_NULL(instr_ptr);
    // TODO: insert the memory export directive
    vlg_ila.AnnotateMemory(supplementary_info.memory_export);

    vlg_ila.ExportTopLevelInstr(instr_ptr);

    if (vlg_ila.decodeNames.size() != 1) {
      ILA_ERROR << "Implementation bug btw. vlg gen and vtarget-gen";
      _bad_state = true;
    }

    auto& instr = get_current_instruction_rf();
    if (instr.is_null()) {
      ILA_ERROR << "No refinement relation is defined for current instruction:"
                << instr_ptr->name().str();
      _bad_state = true;
    }
    // check for fields in
    if (!IN("instruction", instr) || !instr["instruction"].is_string()) {
      ILA_ERROR << "RF: `instruction` field must be a string for "
                << instr_ptr->name().str();
      _bad_state = true;
    }

    if (IN("flush constraint", instr) &&
        not instr["flush constraint"].is_array()) {
      ILA_ERROR
          << "RF: 'flush constraint' filed must be an array of string for "
          << instr_ptr->name().str();
      _bad_state = true;
    }

    if (IN("pre-flush end", instr) && !instr["pre-flush end"].is_string()) {
      ILA_ERROR << "RF: 'pre-flush end' field must be a string for "
                << instr_ptr->name().str();
      _bad_state = true;
    }

    if (IN("post-flush end", instr) &&
        not instr["post-flush end"].is_string()) {
      ILA_ERROR << "RF: 'post-flush end' filed must be a string for "
                << instr_ptr->name().str();
      _bad_state = true;
    }

    if (IN("flush constraint", instr) &&
        instr["flush constraint"].size() != 0) {
      if (IN("pre-flush end", instr) && instr["pre-flush end"].size() != 0 &&
          IN("post-flush end", instr) && instr["post-flush end"].size() != 0)
        has_flush = true; // requiring three items
      else {
        ILA_ERROR
            << "When using flushing, 'pre-flush end' and 'post-flush end' "
            << "must be specify";
        _bad_state = true;
      }
    }

    if (IN("ready signal", instr) &&
        instr["ready signal"].size() !=
            0) // whether a none-empty string or array...
      ready_type = (ready_type_t)(ready_type | ready_type_t::READY_SIGNAL);
    if (IN("ready bound", instr) && instr["ready bound"].is_number_integer())
      ready_type = (ready_type_t)(ready_type | ready_type_t::READY_BOUND);
    if (ready_type == ready_type_t::NA) {
      ILA_ERROR << "refinement relation for:" << instr_ptr->name().str()
                << " has to specify a ready condition";
      _bad_state = true;
    }
  } // END of target_type == INSTRUCTION
  else if (target_type == target_type_t::INVARIANTS) {
    ILA_WARN_IF(instr_ptr != nullptr)
        << "Provide an instruction "
        << "when verifying invariants. The instruction will not be used";
  }
  // if you supply additional invariant in the invariant synthesis
  // they will still be a target for invariant generated.
  // you can use it to verify the invariants if you like
  ILA_CHECK(!(has_flush &&
              (backend & backend_selector::YOSYS) == backend_selector::YOSYS))
      << "Currently does not support flushing in invariant synthesis."
      << "Future work.";

  ILA_CHECK(!(has_flush && vtg_config.VerificationSettingAvoidIssueStage))
      << "it is impossible to avoid issue stage for flushing refinement map, "
      << "ignore this configuration option.";
} // END of constructor

void VlgSglTgtGen::ConstructWrapper_generate_header() {
  vlg_wrapper.add_preheader("\n`define true  1'b1\n");
  vlg_wrapper.add_preheader("\n`define false 1'b0\n");
  vlg_wrapper.add_preheader("\n" + _vtg_config.WrapperPreheader + "\n");
} // ConstructWrapper_generate_header

// for special memory, we don't need to do anything?
void VlgSglTgtGen::ConstructWrapper_add_varmap_assumptions() {
  ILA_CHECK(target_type == target_type_t::INSTRUCTIONS)
      << "Implementation bug: vmap assumpt should only be used when verifying "
         "instructions.";
  std::set<std::string> ila_state_names;

  for (size_t state_idx = 0; state_idx < _host->state_num(); ++state_idx)
    ila_state_names.insert(_host->state(state_idx)->name().str());

  nlohmann::json& state_mapping = IN("state mapping", rf_vmap)
                                      ? rf_vmap["state mapping"]
                                      : rf_vmap["state-mapping"];
  for (auto& i : state_mapping.items()) {
    auto sname = i.key();
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
    // __START__ ==> vmap
    ILA_DLOG("VtargetGen.ConstructWrapper_add_varmap_assumptions") << sname;

    std::string problem_name = "variable_map_assume_";
    if (_vtg_config.PerVariableProblemCosa &&
        _backend != backend_selector::RELCHC)
      problem_name += "_" + sname;
    // if we are targeting yosys, we should make sure they have the same
    // problem_name so the it knowns these are the assumptions for varmap

    if (_backend == backend_selector::RELCHC) {

      add_an_assumption(GetStateVarMapExpr(sname, i.value()), problem_name);
      // its signal reference will be replaced, but this should be fine
      // because the names on any level is the same!
    } else
      add_an_assumption("(~ __START__ )|| (" +
                            GetStateVarMapExpr(sname, i.value()) + ")",
                        problem_name);
  }
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

  nlohmann::json& state_mapping = IN("state mapping", rf_vmap)
                                      ? rf_vmap["state mapping"]
                                      : rf_vmap["state-mapping"];
  for (auto& i : state_mapping.items()) {
    auto sname = i.key();
    if (!IN(sname, ila_state_names)) {
      ILA_ERROR << sname
                << " is not a state of the ILA:" << _host->name().str();
      continue;
    }
    if (_vtg_config.OnlyCheckInstUpdatedVars &&
        _instr_ptr->update(sname) == nullptr) {

      // do not skip memory, though we don't use the eq signal it returns
      if (_host->state(sname)->is_mem())
        GetStateVarMapExpr(sname, i.value(), true);

      ILA_DLOG("VtargetGen") << "Skip checking variable:" << sname
                             << " for instruction:" << _instr_ptr->name().str();
      continue;
    }

    ila_state_names.erase(sname);

    // report the need of refinement map
    if (_instr_ptr->update(sname)) {
      FunctionApplicationFinder func_app_finder(_instr_ptr->update(sname));
      for (auto&& func_ptr : func_app_finder.GetReferredFunc()) {
        // handle the IteUnknown function case
        if (_vtg_config.IteUnknownAutoIgnore &&
            _sdr.isSpecialUnknownFunction(func_ptr))
          continue;
        ILA_ERROR_IF(!(IN("functions", rf_vmap) &&
                       rf_vmap["functions"].is_object() &&
                       IN(func_ptr->name().str(), rf_vmap["functions"])))
            << "uf: " << func_ptr->name().str() << " in "
            << _instr_ptr->name().str() << " updating state:" << sname
            << " is not provided in rfmap!";
      }
    }

    // ISSUE ==> vmap
    std::string precondition =
        has_flush ? "(~ __ENDFLUSH__) || " : "(~ __IEND__) || ";

    if (IN(sname, vlg_ila.state_update_ite_unknown)) {
      auto pos = vlg_ila.state_update_ite_unknown.find(sname);
      precondition += "(~ " + pos->second.condition + ") ||";
    }

    std::string problem_name = "variable_map_assert";
    if (_vtg_config.PerVariableProblemCosa &&
        (_backend & backend_selector::YOSYS) != backend_selector::YOSYS)
      problem_name += "_" + sname;
    // for Yosys, we must keep the name the same
    // so it knows these are for variable map assertions

    // 'true' below means it is for assertions (only different for mapping
    // memory) if assumption, nothing to be done if assertions, ask _idr to
    // connect and get the eq name

    // for Yosys inv-synthesis, we don't mind the precondition
    // that's part the assertions, so it should be fine
    add_an_assertion(precondition + "(" +
                         GetStateVarMapExpr(sname, i.value(), true) + ")",
                     problem_name);
  }
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

//  FLUSH case
//  1 RESET
//  2             RESETED                   ---> assume flush & preflush cond
//  ...                                     ---> assume flush & preflush cond
//  n ISSUE = pre-flush end                 ---> assume flush & preflush cond
//  n+1           START                     ---> assume varmap  ---> assume inv
//  (maybe globally?) n+2                   STARTED n+3 STARTED
//  ...                   ... (forever)
//  m             IEND
//  m+1                    ENDED            ---> assume flush & postflush cond
//  ...                    ENDED (forever)  ---> assume flush & postflush cond
//  l             ENDFLUSH = post-flush end ---> assume flush & postflush cond
//  ---> assert varmap l+1                    FLUSHENDED       ---> assume flush
//  & postflush cond
//

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

  // 1. dealing with reset
  ConstructWrapper_reset_setup();

  ILA_DLOG("VtargetGen") << "STEP:" << 3;
  // -- find out the inputs
  ConstructWrapper_add_vlg_input_output();
  ILA_DLOG("VtargetGen") << "STEP:" << 4;
  ConstructWrapper_add_ila_input();
  ILA_DLOG("VtargetGen") << "STEP:" << 5;

  // 2. add some monitors (bound cnt)
  // 3. add assumptions & assertions
  if (target_type == target_type_t::INSTRUCTIONS) {

    ILA_DLOG("VtargetGen") << "STEP:" << 5.1;
    ConstructWrapper_add_cycle_count_moniter();
    ILA_DLOG("VtargetGen") << "STEP:" << 5.2;
    ConstructWrapper_add_varmap_assumptions();
    ILA_DLOG("VtargetGen") << "STEP:" << 5.3;
    ConstructWrapper_add_varmap_assertions();
    ILA_DLOG("VtargetGen") << "STEP:" << 5.4;
    ConstructWrapper_add_inv_assumption_or_assertion_target_instruction();
  } else if (target_type == target_type_t::INVARIANTS) {
    ConstructWrapper_inv_syn_connect_mem(); // the same as inv-syn so I add it
                                            // here
    ConstructWrapper_add_inv_assumption_or_assertion_target_invariant();
    max_bound = _vtg_config.MaxBound;
  } else if (target_type == target_type_t::INV_SYN_DESIGN_ONLY) {
    ConstructWrapper_inv_syn_cond_signals();
    ConstructWrapper_inv_syn_connect_mem();
    ConstructWrapper_add_inv_assumption_or_assertion_target_inv_syn_design_only();
  }

  ILA_DLOG("VtargetGen") << "STEP:" << 6;
  // 4. additional mapping if any
  if (target_type == target_type_t::INSTRUCTIONS)
    ConstructWrapper_add_additional_mapping_control();

  ConstructWrapper_add_rf_assumptions();

  ILA_DLOG("VtargetGen") << "STEP:" << 7;
  // if invariants, will do nothing
  if (target_type == target_type_t::INSTRUCTIONS)
    ConstructWrapper_add_condition_signals();

  ILA_DLOG("VtargetGen") << "STEP:" << 8;

  // 7. uni-functions
  if (target_type == target_type_t::INSTRUCTIONS)
    ConstructWrapper_add_uf_constraints();

  // post value holder --- ABC cannot work on this
  if (target_type == target_type_t::INSTRUCTIONS) {
    ConstructWrapper_add_post_value_holder();
  }
  ConstructWrapper_add_vlg_monitor();
  // add monitor -- inside the monitor, there will be
  // disable logic if it is for invariant type target

  // 6. helper memory
  ConstructWrapper_add_helper_memory(); // need to decide what is the target
                                        // type

  // 5.0 add the extra wires to the top module wrapper
  if (_backend == backend_selector::COSA ||
      (_backend & backend_selector::YOSYS) == backend_selector::YOSYS)
    ConstructWrapper_register_extra_io_wire();

  ILA_DLOG("VtargetGen") << "STEP:" << 9;
  // 5. module instantiation
  ConstructWrapper_add_module_instantiation();
}

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
  if (_backend == backend_selector::COSA ||
      (_backend & backend_selector::YOSYS) == backend_selector::YOSYS ||
      (_backend == backend_selector::RELCHC)) {
    fn = os_portable_append_dir(_output_path, top_file_name);
    fout.open(fn, std::ios_base::app);
  } else if (_backend == backend_selector::JASPERGOLD) {
    fn = os_portable_append_dir(_output_path, ila_vlg_name);
    fout.open(fn);
  }
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing ila to file: " << fn;
    return;
  }
  vlg_ila.DumpToFile(fout);
}

void VlgSglTgtGen::ExportAll(const std::string& wrapper_name,
                             const std::string& ila_vlg_name,
                             const std::string& script_name,
                             const std::string& extra_name,
                             const std::string& mem_name) {
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
  Export_mem(mem_name);

  Export_problem(extra_name);
  Export_script(script_name);
}

} // namespace ilang
