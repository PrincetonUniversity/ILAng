/// \file Source for invariant synthesis --- using CEGAR loop
// Hongce Zhang

#include <ilang/config.h>
#ifdef INVSYN_INTERFACE

#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/verilog-in/verilog_analysis.h>
#include <ilang/vtarget-out/inv-syn/inv_syn_cegar.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <memory>

namespace ilang {

static std::string select_script_to_run(const std::vector<std::string>& scripts,
                                        const std::string& sel) {
  ILA_CHECK(!sel.empty()) << "no selection is provided in RunVerifAuto";
  std::vector<std::string> sels;
  for (auto&& sc : scripts)
    if (S_IN(sel, sc))
      sels.push_back(sc);
  ILA_CHECK(!sels.empty()) << "Auto run: no selection!";
  if (sels.size() > 1) {
    ILA_ERROR << "Multi scripts selected!";
    for (auto&& sc : sels)
      ILA_ERROR << sc;
    ILA_CHECK(false);
  }
  return sels[0];
}

// problem: you cannot create and keep the objs
// so you need to keep the infos
InvariantSynthesizerCegar::InvariantSynthesizerCegar(
    const std::vector<std::string>& implementation_include_path,
    const std::vector<std::string>& implementation_srcs,
    const std::string& implementation_top_module,
    const std::string& refinement_variable_mapping,
    const std::string& refinement_conditions, const std::string& output_path,
    const InstrLvlAbsPtr& ila_ptr, verify_backend_selector vbackend,
    synthesis_backend_selector sbackend, const vtg_config_t& vtg_config,
    const VerilogGenerator::VlgGenConfig& config)
    : status(cegar_status::NEXT_V), bad_state(false), round_id(0),
      // book-keeping
      implementation_incl_path(implementation_include_path),
      implementation_srcs_path(implementation_srcs),
      implementation_top_module_name(implementation_top_module),
      refinement_variable_mapping_path(refinement_variable_mapping),
      refinement_condition_path(refinement_conditions),
      _output_path(output_path), _host(ila_ptr), v_backend(vbackend),
      s_backend(sbackend), _vtg_config(vtg_config), _vlg_config(config),
      // ------------ statistics bookkeeping --------------- //
      eqcheck_time(0), inv_validate_time(0), inv_proof_attempt_time(0),
      inv_syn_time(0), inv_enhance_time(0), total_grain_cand(0) {
  // detect some wrong settings here
  if (vbackend != verify_backend_selector::COSA) {
    ILA_ERROR << "Implementation bug: currently only support COSA.";
    bad_state = true;
    return;
  }
  // BUG: should also consider Yosys single inv?

  // we need to have the vcd generated
  _vtg_config.CosaGenTraceVcd = true;
  // for other backend, enable similar options

  current_inv_type = cur_inv_tp::NONE;

} // end of constructor

bool InvariantSynthesizerCegar::check_in_bad_state() const {
  ILA_ERROR_IF(bad_state) << "In bad state, cannot proceed.";
  return bad_state;
}

// -------------------------------- VERIFICATION TARGETS
// ------------------------------------------- //

/// to generate a target to validate the given and synthesize invariants and
/// guessed ones
void InvariantSynthesizerCegar::GenerateInvariantVerificationTarget() {
  if (check_in_bad_state())
    return;

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj;
  adv_param._candidate_inv_ptr = &inv_candidate;

  auto inv_gen_vtg_config = _vtg_config;
  inv_gen_vtg_config.target_select = inv_gen_vtg_config.INV;
  // no overwite
  // inv_gen_vtg_config.ValidateSynthesizedInvariant =
  // vtg_config_t::_validate_synthesized_inv::ALL; // overwrite

  VlgVerifTgtGen vg(implementation_incl_path,         // include
                    implementation_srcs_path,         // sources
                    implementation_top_module_name,   // top_module_name
                    refinement_variable_mapping_path, // variable mapping
                    refinement_condition_path,        // conditions
                    _output_path,                     // output path
                    _host,                            // ILA
                    v_backend,          // verification backend setting
                    inv_gen_vtg_config, // target configuration
                    _vlg_config,        // verilog generator configuration
                    &adv_param          // advanced parameter
  );

  vg.GenerateTargets();
}

// the reason we need to do this is that we need to know
// in the verilog design, which is (true)reg, which is not (true)reg
void InvariantSynthesizerCegar::GenerateTargetAndExtractSmt() {
  // generate a target -- based on selection
  if (check_in_bad_state())
    return;

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = NULL;
  adv_param._candidate_inv_ptr = NULL;

  VlgVerifTgtGen vg(
      implementation_incl_path,         // include
      implementation_srcs_path,         // sources
      implementation_top_module_name,   // top_module_name
      refinement_variable_mapping_path, // variable mapping
      refinement_condition_path,        // conditions
      _output_path,                     // output path
      _host,                            // ILA
      verify_backend_selector::YOSYS,   // verification backend setting
      _vtg_config,                      // target configuration
      _vlg_config,                      // verilog generator configuration
      &adv_param                        // advanced parameter
  );

  //  design_smt_info = vg.GenerateSmtTargets();
}

unsigned
InvariantSynthesizerCegar::QueryRtlStateWidth(const std::string& name) const {
  if (design_smt_info == nullptr)
    return 0;
  const auto& sts = design_smt_info->get_var_idx();
  auto pos = sts.find(name);
  if (pos == sts.end())
    return 0;
  return pos->second->_type.GetBoolBvWidth();
}

// to do things separately, you can provide the run function yourself
// or even do it step by step
/// to generate targets using the current invariants
void InvariantSynthesizerCegar::GenerateVerificationTarget() {
  // generate a target -- based on selection
  if (check_in_bad_state())
    return;
  ILA_WARN_IF(status != cegar_status::NEXT_V)
      << "CEGAR-loop: repeated verification step.";

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj;
  adv_param._candidate_inv_ptr = &inv_candidate;

  VlgVerifTgtGen vg(implementation_incl_path,         // include
                    implementation_srcs_path,         // sources
                    implementation_top_module_name,   // top_module_name
                    refinement_variable_mapping_path, // variable mapping
                    refinement_condition_path,        // conditions
                    _output_path,                     // output path
                    _host,                            // ILA
                    v_backend,   // verification backend setting
                    _vtg_config, // target configuration
                    _vlg_config, // verilog generator configuration
                    &adv_param   // advanced parameter
  );

  vg.GenerateTargets();

  vlg_mod_inst_name = vg.GetVlgModuleInstanceName();
  inv_obj.set_dut_inst_name(vlg_mod_inst_name);
  inv_candidate.set_dut_inst_name(vlg_mod_inst_name);

  runnable_script_name = vg.GetRunnableScriptName();
  if (additional_width_info.empty())
    additional_width_info = vg.GetSupplementaryInfo().width_info;

  status = cegar_status::V_RES;
}

/// to generate targets using the provided invariants
void InvariantSynthesizerCegar::GenerateVerificationTarget(
    const std::vector<std::string>& invs) {
  for (auto&& inv : invs)
    inv_obj.AddInvariantFromVerilogExpr(std::to_string(round_id), inv);
  GenerateVerificationTarget();
} // to generate targets using the provided invariants

// -------------------------------- CHC SYNTHESIS TARGETS
// ------------------------------------------- //

/// to generate synthesis target
void InvariantSynthesizerCegar::GenerateSynthesisTarget() {
  // generate a target -- based on selection
  if (check_in_bad_state())
    return;
  ILA_WARN_IF(status != cegar_status::NEXT_S)
      << "CEGAR-loop: not expecting synthesis step.";

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj;
  adv_param._candidate_inv_ptr = NULL;
  adv_param._cex_obj_ptr = cex_extract.get();

  VlgVerifTgtGen vg(
      implementation_incl_path,         // include
      implementation_srcs_path,         // sources
      implementation_top_module_name,   // top_module_name
      refinement_variable_mapping_path, // variable mapping
      refinement_condition_path,        // conditions
      _output_path,                     // output path
      _host,                            // ILA
      verify_backend_selector::YOSYS,   // verification backend setting
      _vtg_config,                      // target configuration
      _vlg_config,                      // verilog generator configuration
      &adv_param                        // advanced parameter
  );

  if (s_backend == synthesis_backend_selector::ABC) {
    vg.GenerateInvSynTargetsAbc(_vtg_config.AbcUseGla, _vtg_config.AbcUseCorr,
                                _vtg_config.AbcUseAiger);
    current_inv_type = cur_inv_tp::CEGAR_ABC;
  } else {
    design_smt_info = vg.GenerateInvSynTargets(s_backend); // general chc
    current_inv_type = s_backend == synthesis_backend_selector::GRAIN
                           ? cur_inv_tp::GRAIN_CHC
                           : cur_inv_tp::CHC;
  }

  runnable_script_name = vg.GetRunnableScriptName();

  status = cegar_status::S_RES;

} // GenerateSynthesisTarget

static int inline retrieveColonEol(const std::string& msg,
                                   const std::string& label) {
  size_t pos_1, endl_1;
  pos_1 = msg.find(label);
  endl_1 = msg.find('\n', pos_1);
  return StrToInt(msg.substr(pos_1 + label.length(), endl_1));
}

const InvariantInCnf& InvariantSynthesizerCegar::GetCurrentCnfEnhance() const {
  return inv_cnf;
}
/// merge cnfs
void InvariantSynthesizerCegar::MergeCnf(
    const InvariantInCnf& incremental_cnf) {
  inv_cnf.InsertClauseIncremental(incremental_cnf);
}

/// extra variable for enhancement, so not really a cnf
void InvariantSynthesizerCegar::ExtractInvariantVarForEnhance(
    size_t inv_idx, InvariantInCnf& incremental_cnf, bool per_clause,
    const std::set<std::string>& vars_to_remove) {
  ILA_CHECK(inv_idx < inv_obj.NumInvariant());
  const auto& inv_vlg = inv_obj.GetVlgConstraints().at(inv_idx);
  VarExtractor vext(
      [](const std::string& s) -> bool { return false; }, // not ila input
      [](const std::string& s) -> bool { return false; }, // not ila state
      [](const std::string& scalbln) -> bool {
        return true;
      } // but verilog state
  );
  vext.ParseToExtract(inv_vlg, true); // force verilog state

  InvariantInCnf::clause cl;
  std::set<std::string> v_in_this_cl;
  vext.ForEachTokenReplace(
      [&cl, &incremental_cnf, &v_in_this_cl, per_clause,
       &vars_to_remove](const VarExtractor::token& t) -> std::string {
        if (per_clause && t.second.find("&&") != t.second.npos) {
          incremental_cnf.InsertClause(cl);
          cl.clear();
          v_in_this_cl.clear();
        }
        if (t.first != VarExtractor::token_type::VLG_S)
          return t.second;
        const auto& vname = t.second;
        auto pos = vname.rfind('[');
        std::string vn = vname;
        if (pos != vname.npos)
          vn = vname.substr(0, pos);
        if (!IN(vn, v_in_this_cl) && !(IN(vn, vars_to_remove))) {
          cl.push_back(std::make_tuple(false, vn, 0U));
          v_in_this_cl.insert(vn);
        }
        return t.second;
      });
  incremental_cnf.InsertClause(cl);
}

bool InvariantSynthesizerCegar::WordLevelEnhancement(
    const InvariantInCnf& incremental_cnf, bool under_test) {
  if (check_in_bad_state())
    return false;
  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj;
  adv_param._candidate_inv_ptr = NULL;
  adv_param._cex_obj_ptr = cex_extract.get();
  // TODO:
  // generate grain (enhance) target
  // run the script
  // extract the result
  std::vector<std::string> runnable_scripts;
  { // generate grain target
    VlgVerifTgtGen vg(
        implementation_incl_path,         // include
        implementation_srcs_path,         // sources
        implementation_top_module_name,   // top_module_name
        refinement_variable_mapping_path, // variable mapping
        refinement_condition_path,        // conditions
        _output_path,                     // output path
        _host,                            // ILA
        verify_backend_selector::YOSYS,   // verification backend setting
        _vtg_config,                      // target configuration
        _vlg_config,                      // verilog generator configuration
        &adv_param                        // advanced parameter
    );

    design_smt_info = vg.GenerateInvSynEnhanceTargets(incremental_cnf);
    runnable_scripts = vg.GetRunnableScriptName();
  } // generate grain target

  // merge the cnfs
  // incremental_cnf.Clear();

  ILA_CHECK(runnable_scripts.size() == 1)
      << "BUG: GenerateInvSynEnhanceTargets should create only 1 target "
         "script ";
  auto synthesis_result_fn =
      os_portable_append_dir(_output_path, "__enhance_result.txt");
  auto redirect_fn = os_portable_append_dir("../", "__enhance_result.txt");

  auto cwd = os_portable_getcwd();
  auto new_wd = os_portable_path_from_path(runnable_scripts[0]);
  ILA_ERROR_IF(!os_portable_chdir(new_wd))
      << "WordLevelEnhancement: cannot change dir to:" << new_wd;
  ILA_INFO << "Executing script:" << runnable_scripts[0];
  execute_result res;

  if (under_test) {
    res.subexit_normal = true;
    res.seconds = 0;
    res.ret = 0;
    res.failure = res.NONE;
    res.timeout = false;
  } else
    res = os_portable_execute_shell(
        {"bash", os_portable_file_name_from_path(runnable_scripts[0])},
        redirect_fn, redirect_t::BOTH);

  ILA_ERROR_IF(res.failure != execute_result::NONE)
      << "Running synthesis script " << runnable_scripts[0]
      << " results in error.";
  ILA_CHECK(os_portable_chdir(cwd));

  inv_enhance_time += res.seconds;
  // inv_syn_time_series.push_back(res.seconds);

  bool freq_enhance_okay = false;
  { // run grain
    std::stringstream sbuf;
    std::ifstream fin(synthesis_result_fn);
    if (!fin.is_open()) {
      ILA_ERROR << "Unable to read the synthesis result file:"
                << synthesis_result_fn;
      freq_enhance_okay = false;
    } else {
      sbuf << fin.rdbuf();
      freq_enhance_okay =
          S_IN("proved", sbuf.str()) || S_IN("proven", sbuf.str());
      if (S_IN("unknown", sbuf.str()))
        freq_enhance_okay = false;
      if (freq_enhance_okay) {
        ILA_INFO << "Enhance Info: Lemma/Gen/Spec = "
                 << retrieveColonEol(sbuf.str(), "learned lemmas:") << " "
                 << retrieveColonEol(sbuf.str(), "TotalGen:") << " "
                 << retrieveColonEol(sbuf.str(), "TotalSpec:") << " "
                 << retrieveColonEol(sbuf.str(), "TotalCand:");
        total_grain_cand += retrieveColonEol(sbuf.str(), "TotalCand:");
      }
    }
  } // end of grain chc result
  // else reachable
  if (!freq_enhance_okay)
    return false;

  if (design_smt_info == nullptr) {
    ILA_ERROR << "BUG: Design SMT-LIB2 info is not available. ";
    return false;
  }
  inv_obj.AddInvariantFromGrainResultFile(
      *(design_smt_info.get()), "",
      os_portable_append_dir(_output_path, "grain.result"), true, true);

  // you also need to merge CNF
  status = cegar_status::NEXT_V;
  return true;
}

// -------------------------------- EXTRACTIONS
// ------------------------------------------- //

/// to extract result
void InvariantSynthesizerCegar::ExtractVerificationResult(
    bool autodet, bool pass, const std::string& vcd_file,
    const std::string& mod_inst_name) {
  if (check_in_bad_state())
    return;

  std::string res_file = vcd_file;
  if (autodet) {
    res_file = vcd_file_name;
    pass = verification_pass;
  }
  ILA_WARN_IF(status != cegar_status::V_RES)
      << "CEGAR-loop: repeated verification step.";

  vlg_mod_inst_name =
      vlg_mod_inst_name.empty() ? mod_inst_name : vlg_mod_inst_name;
  if (vlg_mod_inst_name.empty()) {
    ILA_ERROR << "Instance name in vcd is unknown and not specified";
    bad_state = true;
    return;
  }

  if (pass) {
    ILA_INFO << "No counterexample has been found. CEGAR loop finishes.";
    status = cegar_status::DONE;
    return;
  }

  // we still need to create a verilog info analyzer
  VerilogAnalyzer va(implementation_incl_path, implementation_srcs_path,
                     vlg_mod_inst_name, implementation_top_module_name);

  auto is_reg = [&](const std::string& n) -> bool {
    if (!VerilogAnalyzerBase::is_reg(va.check_hierarchical_name_type(n)))
      return false;
    if (design_smt_info) // if available we will use it
      return design_smt_info->is_state_name(n);
    return true; // if not available
  };

  // not passing
  cex_extract = std::unique_ptr<CexExtractor>(new CexExtractor(
      res_file, vlg_mod_inst_name, is_reg, !_vtg_config.CosaFullTrace));
  // advance to synthesis stage
  status = cegar_status::NEXT_S;
} // extract result

/// a helper function (only locally available)
/// to extract vcd file name from the output
std::string extract_vcd_name_from_cex(const std::string& fn) {
  std::ifstream fin(fn);
  if (!fin.is_open()) {
    ILA_ERROR << "Unable to read from:" << fn;
    return "";
  }
  std::string line;
  while (std::getline(fin, line)) {
    if (S_IN("*** TRACES ***", line))
      break;
  }
  if (fin.eof()) {
    ILA_ERROR << "Cannot extract vcd filename, incorrect format, expecting *** "
                 "TRACES ***";
    return "";
  }
  std::string fname;
  fin >> fname;
  fin >> fname; // the first is garbage;
  ILA_ERROR_IF(!S_IN(".vcd", fname))
      << "Expecting vcd file name, get " << fname;
  return fname;
} // extract_vcd_name_from_cex

void InvariantSynthesizerCegar::CexGeneralizeRemoveStates(
    const std::vector<std::string>& n) {
  cex_extract->DropStates(n);
}

void InvariantSynthesizerCegar::ExtractAbcSynthesisResultForEnhancement(
    InvariantInCnf& incremental_cnf, bool autodet, bool reachable) {

  if (check_in_bad_state())
    return;

  if (autodet) {
    reachable = cex_reachable;
  }

  ILA_WARN_IF(status != cegar_status::S_RES)
      << "CEGAR-loop: expecting synthesis result.";

  if (reachable) {
    ILA_ERROR << "Verification failed with true counterexample!";
    status = cegar_status::FAILED;
    return;
  }
  ILA_CHECK(current_inv_type == cur_inv_tp::CEGAR_ABC)
      << "Can only work with CEGAR ABC!";
  // the incremental CNF here
  ILA_CHECK(inv_candidate.AddInvariantFromAbcResultFile(
      _vtg_config.AbcUseAiger
          ? os_portable_append_dir(
                os_portable_path_from_path(runnable_script_name[0]),
                "__aiger_prepare.blif")
          : os_portable_append_dir(
                os_portable_path_from_path(runnable_script_name[0]),
                "wrapper.blif"),
      os_portable_append_dir(
          os_portable_path_from_path(runnable_script_name[0]), "ffmap.info"),
      true, true,
      _vtg_config.AbcUseGla
          ? os_portable_append_dir(
                os_portable_path_from_path(runnable_script_name[0]),
                "glamap.info")
          : "",
      _vtg_config.AbcUseAiger,
      _vtg_config.AbcUseAiger
          ? os_portable_append_dir(
                os_portable_path_from_path(runnable_script_name[0]),
                "wrapper.aig.map")
          : "",
      incremental_cnf, inv_cnf) // incrementally add cnf
             )
      << "Extracting of invariant failed!";

  current_inv_type = cur_inv_tp::NONE; // we have extracted, reset this marker
} // ExtractAbcSynthesisResultForEnhancement

void InvariantSynthesizerCegar::ExtractSynthesisResult(
    bool autodet, bool reachable, const std::string& given_smt_chc_result_txt) {

  if (check_in_bad_state())
    return;

  std::string res_file = given_smt_chc_result_txt;
  if (autodet) {
    reachable = cex_reachable;
    res_file = synthesis_result_fn;
  }

  ILA_WARN_IF(status != cegar_status::S_RES)
      << "CEGAR-loop: expecting synthesis result.";

  if (reachable) {
    ILA_ERROR << "Verification failed with true counterexample!";
    status = cegar_status::FAILED;
    return;
  }

  if (current_inv_type == cur_inv_tp::CHC) {
    if (design_smt_info == nullptr) {
      ILA_ERROR << "Design SMT-LIB2 info is not available. "
                << "You need to run `GenerateSynthesisTarget` or Parse a "
                   "design smt first first.";
      return;
    }
    ILA_CHECK(inv_obj.AddInvariantFromChcResultFile
      (*(design_smt_info.get()), "",
      res_file,
      _vtg_config.YosysSmtFlattenDatatype,
      _vtg_config.YosysSmtFlattenHierarchy));
  } else if (current_inv_type == cur_inv_tp::GRAIN_CHC) {
    if (design_smt_info == nullptr) {
      ILA_ERROR << "Design SMT-LIB2 info is not available. "
                << "You need to run `GenerateSynthesisTarget` or Parse a "
                   "design smt first first.";
      return;
    }
    inv_obj.AddInvariantFromGrainResultFile(
        *(design_smt_info.get()), "",
        os_portable_append_dir(_output_path, "grain.result"), true, true);
  } else if (current_inv_type == cur_inv_tp::CEGAR_ABC) {
    ILA_CHECK(inv_obj.AddInvariantFromAbcResultFile(
        _vtg_config.AbcUseAiger
            ? os_portable_append_dir(
                  os_portable_path_from_path(runnable_script_name[0]),
                  "__aiger_prepare.blif")
            : os_portable_append_dir(
                  os_portable_path_from_path(runnable_script_name[0]),
                  "wrapper.blif"),
        os_portable_append_dir(
            os_portable_path_from_path(runnable_script_name[0]), "ffmap.info"),
        true, true,
        _vtg_config.AbcUseGla
            ? os_portable_append_dir(
                  os_portable_path_from_path(runnable_script_name[0]),
                  "glamap.info")
            : "",
        _vtg_config.AbcUseAiger,
        _vtg_config.AbcUseAiger
            ? os_portable_append_dir(
                  os_portable_path_from_path(runnable_script_name[0]),
                  "wrapper.aig.map")
            : "",
        inv_cnf, InvariantInCnf()))
        << "Extracting of invariant failed!";
  } else
    ILA_ERROR << "Inv type unknown:" << current_inv_type;

  std::cout << "Confirmed synthesized invariants:" << std::endl;
  for (auto&& v : inv_obj.GetVlgConstraints())
    std::cout << v << std::endl;

  status = cegar_status::NEXT_V;
  current_inv_type = cur_inv_tp::NONE; // we have extracted, reset this marker

} // ExtractSynthesisResult

// -------------------------------- AUTO RUNS
// ------------------------------------------- //

/// a helper function (only locally available)
/// to detect tool error (e.g., verilog parsing error)
bool static has_verify_tool_error_cosa(const std::string& fn) {
  std::ifstream fin(fn);
  if (!fin.is_open()) {
    ILA_ERROR << "Unable to read from:" << fn;
    return true;
  }

  std::string line;
  while (std::getline(fin, line)) {
    if (S_IN("See yosys-err.log for more info.", line))
      return true;
  }
  return false;
} // has_verify_tool_error_cosa

/// a helper function (only locally available)
/// to detect tool error (e.g., verilog parsing error)
bool static has_verify_tool_unknown_cosa(const std::string& fn) {
  std::ifstream fin(fn);
  if (!fin.is_open()) {
    ILA_ERROR << "Unable to read from:" << fn;
    return true;
  }

  std::string line;
  while (std::getline(fin, line)) {
    if (S_IN("UNKNOWN != TRUE <<<---------| ERROR", line))
      return true;
  }
  return false;
} // has_verify_tool_error_cosa
/// run Verification
bool InvariantSynthesizerCegar::RunVerifAuto(
    const std::string& script_selection, const std::string& pid_fname,
    bool under_test, unsigned timeout) {
  auto script_sel =
      select_script_to_run(runnable_script_name, script_selection);
  if (check_in_bad_state())
    return true;
  // Not implemented
  auto result_fn =
      os_portable_append_dir(_output_path, "__verification_result.txt");
  auto redirect_fn = os_portable_append_dir("..", "__verification_result.txt");
  auto cwd = os_portable_getcwd();
  auto new_wd = os_portable_path_from_path(script_sel);
  ILA_ERROR_IF(!os_portable_chdir(new_wd))
      << "RunVerifAuto: cannot change dir to:" << new_wd;
  ILA_INFO << "Executing verify script:" << script_sel;

  execute_result res;
  if (under_test) {
    res.subexit_normal = true;
    res.seconds = 0;
    res.ret = 0;
    res.failure = res.NONE;
    res.timeout = false;
  } else {
    res = os_portable_execute_shell(
        {"bash", os_portable_file_name_from_path(script_sel)}, redirect_fn,
        redirect_t::BOTH, timeout, pid_fname);
  }

  ILA_ERROR_IF(res.failure != execute_result::NONE)
      << "Running verification script " << script_sel << " results in error.";
  ILA_CHECK(os_portable_chdir(cwd));
  // the last line contains the result
  // above it you should have *** TRACES ***
  // the vcd file resides within the new dir
  ILA_ERROR_IF(has_verify_tool_error_cosa(result_fn))
      << "----------- Verification tool reported error! Please check the log "
         "output!";
  ILA_ERROR_IF(has_verify_tool_unknown_cosa(result_fn))
      << "UNKNOWN Verif result";

  eqcheck_time += res.seconds;

  auto lastLine = os_portable_read_last_line(result_fn);
  ILA_ERROR_IF(lastLine.empty()) << "Unable to extract verification result.";
  if (S_IN("Verifications with unexpected result", lastLine)) {
    ILA_INFO << "Counterexample found.";

    vcd_file_name = extract_vcd_name_from_cex(result_fn);
    vcd_file_name = os_portable_append_dir(new_wd, vcd_file_name);

    verification_pass = false;
    return false;
  }
  verification_pass = true;
  status = cegar_status::DONE;
  ILA_INFO << "No counterexample has been found. CEGAR loop finishes.";
  return true;
}

/// run Synthesis
bool InvariantSynthesizerCegar::RunSynAuto(bool under_test) {
  if (check_in_bad_state())
    return true;

  ILA_CHECK(runnable_script_name.size() == 1)
      << "Please run GenerateInvSynTargets function first";
  synthesis_result_fn =
      os_portable_append_dir(_output_path, "__synthesis_result.txt");
  auto redirect_fn = os_portable_append_dir("..", "__synthesis_result.txt");

  auto cwd = os_portable_getcwd();
  auto new_wd = os_portable_path_from_path(runnable_script_name[0]);
  ILA_ERROR_IF(!os_portable_chdir(new_wd))
      << "RunSynAuto: cannot change dir to:" << new_wd;
  ILA_INFO << "Executing synthesis script:" << runnable_script_name[0];

  execute_result res;
  if (under_test) {
    res.subexit_normal = true;
    res.seconds = 0;
    res.ret = 0;
    res.failure = res.NONE;
    res.timeout = false;
  } else {
    res = os_portable_execute_shell(
        {"bash", os_portable_file_name_from_path(runnable_script_name[0])},
        redirect_fn, redirect_t::BOTH);
  }

  ILA_ERROR_IF(res.failure != execute_result::NONE)
      << "Running synthesis script " << runnable_script_name[0]
      << " results in error.";
  ILA_CHECK(os_portable_chdir(cwd));

  inv_syn_time += res.seconds;
  inv_syn_time_series.push_back(res.seconds);

  if (current_inv_type == CEGAR_ABC) {
    std::stringstream sbuf;
    std::ifstream fin(synthesis_result_fn);
    if (!fin.is_open()) {
      ILA_ERROR << "Unable to read the synthesis result file:"
                << synthesis_result_fn;
      status = cegar_status::FAILED;
      bad_state = true;
      return true; // reachable
    }
    sbuf << fin.rdbuf();
    cex_reachable = !(S_IN("Property proved.", sbuf.str()) &&
                      S_IN("Invariant contains ", sbuf.str()));
  } else if (current_inv_type == GRAIN_CHC) {
    std::stringstream sbuf;
    std::ifstream fin(synthesis_result_fn);
    if (!fin.is_open()) {
      ILA_ERROR << "Unable to read the synthesis result file:"
                << synthesis_result_fn;
      status = cegar_status::FAILED;
      bad_state = true;
      return true; // reachable
    }
    sbuf << fin.rdbuf();
    cex_reachable = !(S_IN("proved", sbuf.str()));
    if (S_IN("unknown", sbuf.str()))
      cex_reachable = true;
    // count cands
    total_grain_cand += retrieveColonEol(sbuf.str(), "TotalCand:");
  } else {
    std::string line;
    { // read the result
      std::ifstream fin(synthesis_result_fn);
      if (!fin.is_open()) {
        ILA_ERROR << "Unable to read the synthesis result file:"
                  << synthesis_result_fn;
        status = cegar_status::FAILED;
        bad_state = true;
        return true; // reachable
      }
      std::getline(fin, line);
    } // finish file reading
    cex_reachable = true;
    if (S_IN("unsat", line))
      cex_reachable = false; // not reachable
  }
  // else reachable
  return cex_reachable;
}

// -------------------------------- MISCS
// ------------------------------------------- //

void InvariantSynthesizerCegar::LoadDesignSmtInfo(const std::string& fn) {
  std::ifstream fin(fn);
  if (!fin.is_open()) {
    ILA_ERROR << "Unable to read from : " << fn;
    return;
  }
  std::stringstream sbuf;
  sbuf << fin.rdbuf();
  design_smt_info = std::make_shared<smt::YosysSmtParser>(sbuf.str());
}

const std::vector<std::string>&
InvariantSynthesizerCegar::GetRunnableTargetScriptName() const {
  return runnable_script_name;
}

void InvariantSynthesizerCegar::LoadPrevStatisticsState(const std::string& fn) {
  DesignStatistics local_info;
  local_info.LoadFromFile(fn);
  if (eqcheck_time != 0 || inv_proof_attempt_time != 0 || inv_syn_time != 0 ||
      inv_validate_time != 0 || inv_enhance_time != 0 ||
      !inv_syn_time_series.empty()) {
    ILA_ERROR << "Not loading the statistics state from initial time!";
  }
  eqcheck_time += local_info.TimeOfEqCheck;
  inv_proof_attempt_time += local_info.TimeOfInvProof;
  inv_syn_time += local_info.TimeOfInvSyn;
  inv_enhance_time += local_info.TimeOfInvSynEnhance;
  inv_validate_time += local_info.TimeOfInvValidate;
  inv_syn_time_series.insert(inv_syn_time_series.end(),
                             local_info.TimeOfInvSynSeries.begin(),
                             local_info.TimeOfInvSynSeries.end());
}

DesignStatistics InvariantSynthesizerCegar::GetDesignStatistics() const {
  DesignStatistics ret;

  ret.TimeOfEqCheck = eqcheck_time;
  ret.TimeOfInvProof = inv_proof_attempt_time;
  ret.TimeOfInvSyn = inv_syn_time;
  ret.TimeOfInvSynEnhance = inv_enhance_time;
  ret.TimeOfInvValidate = inv_validate_time;
  ret.TimeOfInvSynSeries = inv_syn_time_series;

  if (design_smt_info == nullptr) {
    ILA_ERROR << "Design information not available!";
    return ret;
  }

  ILA_ERROR_IF(vlg_mod_inst_name.empty())
      << "vlg_mod_inst_name is empty, will not distinguish in/out module state";

  for (auto&& st : design_smt_info->get_module_flatten_dt("wrapper")) {

    if (StrStartsWith(st.verilog_name, vlg_mod_inst_name + ".")) {
      ret.NumOfDesignStateBits += st._type.GetBoolBvWidth();
      ret.NumOfDesignStateVars++;
    } else {
      ret.NumOfExtraStateBits += st._type.GetBoolBvWidth();
      ret.NumOfExtraStateVars++;
    }
  }
  return ret;
}

const InvariantObject& InvariantSynthesizerCegar::GetInvariants() const {
  return inv_obj;
}

void InvariantSynthesizerCegar::RemoveInvariantsByIdx(size_t idx) {
  inv_obj.RemoveInvByIdx(idx);
}

/// Here you can extract the invariants and export them if needed
const InvariantObject&
InvariantSynthesizerCegar::GetCandidateInvariants() const {
  return inv_candidate;
}

void InvariantSynthesizerCegar::ClearAllCandidateInvariants() {
  inv_candidate.ClearAllInvariants();
}

void InvariantSynthesizerCegar::LoadInvariantsFromFile(const std::string& fn) {
  inv_obj.ImportFromFile(fn);
}
void InvariantSynthesizerCegar::LoadCandidateInvariantsFromFile(
    const std::string& fn) {
  inv_candidate.ImportFromFile(fn);
}

void InvariantSynthesizerCegar::AcceptAllCandidateInvariant() {
  if (inv_candidate.NumInvariant() != 0) {
    inv_obj.InsertFromAnotherInvObj(inv_candidate);
    inv_candidate.ClearAllInvariants();
  } else
    ILA_INFO << "All candidate invariants have been accepted.";
}

/// Supply Verilog candidate invariants
void InvariantSynthesizerCegar::SupplyCandidateInvariant(
    const std::string& vlg_expr) {
  ILA_WARN << "Verilog invariant cannot be pruned";
  inv_candidate.AddInvariantFromVerilogExpr("", vlg_expr);
}

// -------------------- GrainChc ------------------ //
void InvariantSynthesizerCegar::ChangeGrainSyntax(
    const std::vector<std::string>& syn) {
  _vtg_config.GrainOptions = syn;
}

}; // namespace ilang

#endif // INVSYN_INTERFACE
