/// \file Header Externally Provided Target for inv-syn

#include <ilang/util/log.h>
#include <ilang/util/fs.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/verilog-in/verilog_analysis.h>
#include <ilang/vtarget-out/inv-syn-extern-loop/loop_extern.h>
#include <ilang/vtarget-out/inv-syn-extern-loop/yosys_chc.h>
#include <ilang/vtarget-out/inv-syn-extern-loop/yosys_abc.h>
#include <ilang/vtarget-out/inv-syn-extern-loop/cosa_inv_check.h>
#include <ilang/vtarget-out/inv-syn/sygus/datapoint_inv_prune.h>

#include <fstream>

namespace ilang {


InvariantSynthesizerExternalCegar::InvariantSynthesizerExternalCegar(
	const std::vector<std::string>& implementation_include_path,
	const std::vector<std::string>& implementation_srcs,
	const std::string& implementation_top_module,
	const std::string& refinement_variable_mapping,
	const std::string& refinement_conditions,
	const std::string& output_path,
	const std::string& tmpl_top_mod_name,
	verify_backend_selector vbackend,
	synthesis_backend_selector sbackend,
	const vtg_config_t& vtg_config) :
		bad_state(false),
    implementation_incl_path(implementation_include_path),
    implementation_srcs_path(implementation_srcs),
    implementation_top_module_name(implementation_top_module),
    refinement_variable_mapping_path(refinement_variable_mapping),
    refinement_condition_path(refinement_conditions),
    _output_path(output_path),
		tmpl_top_module_name(tmpl_top_mod_name),
		v_backend(vbackend),s_backend(sbackend),
    _vtg_config(vtg_config),
    // ------------ statistics bookkeeping --------------- //
		eqcheck_time(0), inv_validate_time(0), inv_proof_attempt_time(0), 
    inv_syn_time(0), total_freqhorn_cand(0)
	{

	}



/// convert a widith to a verilog string
static std::string WidthToRange(int w) {
  if (w > 1)
    return std::string("[") + std::to_string(w - 1) + ":0]";
  return "";
}

/// to generate targets using the current invariants
void InvariantSynthesizerExternalCegar::ExportInvariantsToJasperAssumptionFile(
	const std::string & fn, const std::string & var_fn, const std::map<std::string, std::string> & repl_lists ) {
	// format : assume { };
	{ // write to fout
		std::ofstream fout(fn);
		if (not fout.is_open()) {
			ILA_ERROR << "Fail to write to :" << fn; return; }
			
		for (auto inv : inv_obj.GetVlgConstraints() ) {
      for (auto && orig_repl_pair : repl_lists) {
        inv = ReplaceAll(inv, orig_repl_pair.first, orig_repl_pair.second);
      }
			auto inv_no_linebreak = ReplaceAll(ReplaceAll(inv, "\n" , " "), "\r", " ");
			fout << "assume { " <<  inv_no_linebreak << " } \n";
		}
	}

	{ // write to vardefs
		std::ofstream fout(var_fn);
		if (not fout.is_open()) {
			ILA_ERROR << "Fail to write to :" << var_fn; return; }
			
		for (auto && vars : inv_obj.GetExtraFreeVarDefs() )
			fout << "wire " << WidthToRange(vars.second) << " " << vars.first << " ; \n";
		for (auto && vars : inv_obj.GetExtraVarDefs() ) {
			fout << "wire " << WidthToRange(std::get<2>(vars)) << " " << std::get<0>(vars)
				<< " = " << std::get<1>(vars) << " ;\n";
		}
	} // write to vardefs

}
/// load return counterexample from file
void InvariantSynthesizerExternalCegar::LoadCexFromFile(const std::string & fn) {
	cex_extract = std::unique_ptr<CexExtractor>(new CexExtractor(fn));
}

/// generate chc target
void InvariantSynthesizerExternalCegar::GenerateChcSynthesisTarget(const std::string & precond) {
  if (check_in_bad_state()) return;
  if (s_backend != synthesis_backend_selector::Z3) {
    ILA_ERROR << "Must use Z3 backend with GenerateChcSynthesisTarget";
    return;
  }

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj; 
	adv_param._candidate_inv_ptr = NULL;
  adv_param._cex_obj_ptr = cex_extract.get();

	ExternalChcTargetGen vg(
		implementation_incl_path,
		implementation_srcs_path,
		implementation_top_module_name,
		refinement_variable_mapping_path,
		refinement_condition_path,
		os_portable_append_dir(_output_path,"inv-syn-cegar") ,
		tmpl_top_module_name,
		v_backend, s_backend,
		_vtg_config, &adv_param		
	);

	vg.ConstructWrapper("wrapper.v", "wrapper.tpl", precond);

	design_smt_info = vg.GenerateChc("wrapper.smt2", "run.sh");

	runnable_script_name = vg.GetRunnableScriptName();
  
  vlg_mod_inst_name = vg.GetDesignUnderVerificationInstanceName();
  inv_obj.set_dut_inst_name(vlg_mod_inst_name);

  if (additional_width_info.empty())
    additional_width_info = vg.GetSupplementaryInfo().width_info;
}


/// generate chc target
void InvariantSynthesizerExternalCegar::GenerateChcSynthesisTarget(const std::string & precond,
  const std::string& cnf_name, const InvariantInCnf & inv_cnf) {
  if (check_in_bad_state()) return;
  if (s_backend != synthesis_backend_selector::FreqHorn) {
    ILA_ERROR << "Must use FreqHorn backend with this GenerateChcSynthesisTarget";
    return;
  }

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj; 
	adv_param._candidate_inv_ptr = NULL;
  adv_param._cex_obj_ptr = cex_extract.get();

	ExternalChcTargetGen vg(
		implementation_incl_path,
		implementation_srcs_path,
		implementation_top_module_name,
		refinement_variable_mapping_path,
		refinement_condition_path,
		os_portable_append_dir(_output_path,"inv-syn-cegar-freqhorn") ,
		tmpl_top_module_name,
		v_backend, s_backend,
		_vtg_config, &adv_param		
	);

	vg.ConstructWrapper("wrapper.v", "wrapper.tpl", precond);

  vg.ExportCnf(inv_cnf,cnf_name);

	design_smt_info = vg.GenerateChc("wrapper.smt2", "run.sh", cnf_name);

	runnable_script_name = vg.GetRunnableScriptName();
  
  vlg_mod_inst_name = vg.GetDesignUnderVerificationInstanceName();
  inv_obj.set_dut_inst_name(vlg_mod_inst_name);

  if (additional_width_info.empty())
    additional_width_info = vg.GetSupplementaryInfo().width_info;
}


static int inline retrieveColonEol(const std::string & msg, const std::string & label) {
  size_t pos_1, endl_1;
  pos_1 = msg.find(label);
  endl_1 = msg.find('\n', pos_1);
  return StrToInt(msg.substr(pos_1 + label.length(),endl_1));
}



/// run Synthesis : returns reachable/not
bool InvariantSynthesizerExternalCegar::RunSynAuto(bool isSyGuS, bool use_freqhorn) {

  if(check_in_bad_state())
    return true;
  
  ILA_ASSERT(runnable_script_name.size() == 1) << "Please run GenerateInvSynTargets function first";
  synthesis_result_fn = os_portable_append_dir(_output_path, "__synthesis_result.txt");
  auto redirect_fn = os_portable_append_dir("../", "__synthesis_result.txt");

  auto cwd = os_portable_getcwd();
  auto new_wd = os_portable_path_from_path(runnable_script_name[0]);
  ILA_ERROR_IF(not os_portable_chdir(new_wd)) 
    << "RunVerifAuto: cannot change dir to:" << new_wd;
  ILA_INFO << "Executing synthesis script:" <<  runnable_script_name[0] ;
  execute_result res;
  if (isSyGuS) {
    res = os_portable_execute_shell({"bash",
      os_portable_file_name_from_path( runnable_script_name[0] )}); // we don't need to redirect
  }
  else {
    res = os_portable_execute_shell({"bash",
      os_portable_file_name_from_path( runnable_script_name[0] )},
      redirect_fn, redirect_t::BOTH);
  }
  ILA_ERROR_IF(res.failure != execute_result::NONE )
    << "Running synthesis script " << runnable_script_name[0] << " results in error."; 
  ILA_ASSERT(os_portable_chdir(cwd));
  
  inv_syn_time += res.seconds;
  inv_syn_time_series.push_back(res.seconds);

  if (use_freqhorn) {
    std::stringstream sbuf;
    std::ifstream fin(synthesis_result_fn);
    if (not fin.is_open()) {
        ILA_ERROR << "Unable to read the synthesis result file:" << synthesis_result_fn;
        bad_state = true;
        return true; // reachable
    } 
    sbuf << fin.rdbuf();
    cex_reachable = !(S_IN("proved",sbuf.str()));
    if (S_IN("unknown",sbuf.str())) cex_reachable = true;
    total_freqhorn_cand += retrieveColonEol (sbuf.str(), "TotalCand:");
  } else if (isSyGuS) {
    std::string line;
    { // read the result
      std::ifstream fin(synthesis_result_fn);
      if (not fin.is_open()) {
        ILA_ERROR << "Unable to read the synthesis result file:" << synthesis_result_fn;
        cex_reachable = true;
        bad_state = true;
        return true; // reachable
      } 
      std::getline(fin,line);  
    } // finish file reading
    cex_reachable = line.find("unknown") == 0;
  }
  else {
    std::string line;
    { // read the result
      std::ifstream fin(synthesis_result_fn);
      if (not fin.is_open()) {
        ILA_ERROR << "Unable to read the synthesis result file:" << synthesis_result_fn;
        bad_state = true;
        return true; // reachable
      } 
      std::getline(fin,line);  
    } // finish file reading
    cex_reachable = true;
    if (S_IN("unsat", line))
      cex_reachable = false; // not reachable
    // else reachable
  }
  return cex_reachable;
}


/// to extract reachability test result
void InvariantSynthesizerExternalCegar::ExtractSynthesisResult( bool use_freqhorn, bool autodet, bool reachable, 
	const std::string & given_smt_chc_result_txt, bool isCvc4Syn) {

  if(check_in_bad_state()) return;

  std::string res_file = given_smt_chc_result_txt;
  if (autodet) {
    reachable = cex_reachable;
    res_file = synthesis_result_fn;
  }
  
  if (design_smt_info == nullptr) {
    ILA_ERROR << "Design SMT-LIB2 info is not available. "
      << "You need to run `GenerateSynthesisTarget` first.";
    return;
  }

  if (reachable) {
    ILA_ERROR << "Verification failed with true counterexample!";
    return;
  }

  // ILA_ASSERT(current_inv_type != cur_inv_tp::SYGUS_CEX) 
  //   << "API misuse: should not use this function on SYGUS CEX output, they may not be the invariants, but just candidates!";
  if (use_freqhorn) {
    inv_obj.AddInvariantFromFreqHornResultFile(
      *(design_smt_info.get()), "", os_portable_append_dir(_output_path, "freqhorn.result"), 
      true,
      true );
  } else if (isCvc4Syn) {
    ILA_ASSERT(
      inv_obj.AddInvariantFromSygusResultFile(
      *(design_smt_info.get()), "", res_file, 
      _vtg_config.YosysSmtFlattenDatatype,
      _vtg_config.YosysSmtFlattenHierarchy,
      true,
      sygus_gen_corrections
       )) // correction is needed
    << "SyGuS solver failed to generate an invariant";
  }
  else
    inv_obj.AddInvariantFromChcResultFile(
      *(design_smt_info.get()), "", res_file, 
      _vtg_config.YosysSmtFlattenDatatype,
      _vtg_config.YosysSmtFlattenHierarchy,
      false );
  
  std::cout << "Confirmed synthesized invariants:" << std::endl;
  for (auto && v : inv_obj.GetVlgConstraints() )
    std::cout << v << std::endl;

  // status = cegar_status::NEXT_V;
  // current_inv_type = cur_inv_tp::NONE; // we have extracted, reset this marker
} // ExtractSynthesisResult


// -------------------- CEGAR FREQHORN ------------------------ //

/// extra variable for enhancement, so not really a cnf
void InvariantSynthesizerExternalCegar::ExtractInvariantVarForEnhance(const std::string & vexpr, InvariantInCnf& incremental_cnf , bool per_clause) {
  const auto & inv_vlg = vexpr;
  VarExtractor vext(
    [](const std::string&s) -> bool {return false;}, // not ila input
    [](const std::string&s) -> bool {return false;}, // not ila state
    [](const std::string&s) -> bool {return true;} // but verilog state
  );
  vext.ParseToExtract(inv_vlg, true); // force verilog state

  InvariantInCnf::clause cl;
  std::set<std::string> v_in_this_cl;
  vext.ForEachTokenReplace(
    [&cl, &incremental_cnf, &v_in_this_cl, per_clause]
     (const VarExtractor::token &t) -> std::string {
      if (per_clause && t.second.find("&&")!=t.second.npos) {
        incremental_cnf.InsertClause(cl);
        cl.clear();
        v_in_this_cl.clear();
      }
      if(t.first != VarExtractor::token_type::VLG_S)
        return t.second;
      const auto & vname = t.second;
      auto pos = vname.rfind('[');
      std::string vn = vname;
      if (pos != vname.npos)
        vn = vname.substr(0,pos);
      if (!IN(vn,v_in_this_cl)) {
        cl.push_back({false, vn,0});
        v_in_this_cl.insert(vn);
      }
      return t.second;
    }
  );
  incremental_cnf.InsertClause(cl);
}

/// extra variable for enhancement, so not really a cnf
void InvariantSynthesizerExternalCegar::ExtractInvariantVarForEnhance(size_t inv_idx, InvariantInCnf& incremental_cnf , bool per_clause) {
  ILA_ASSERT(inv_idx < inv_obj.NumInvariant());
  const auto & inv_vlg = inv_obj.GetVlgConstraints().at(inv_idx);
  ExtractInvariantVarForEnhance(inv_vlg, incremental_cnf, per_clause );
}


void InvariantSynthesizerExternalCegar::VarlistToCnf(const std::set<std::string> & var_list, InvariantInCnf& incremental_cnf) const {
  InvariantInCnf::clause cl;
  for (auto && vn : var_list) {
      ILA_WARN_IF (vn.find(vlg_mod_inst_name+".") != 0) << vn << " does not start with : " << vlg_mod_inst_name+".";
      cl.push_back({false, vn,0});
  }
  incremental_cnf.InsertClause(cl);
}

// -------------------- CEGAR ABC ------------------------ //

/// generate chc target
void InvariantSynthesizerExternalCegar::GenerateAbcSynthesisTarget(
  bool useAiger,
  bool useGla,
  bool useCorr, unsigned gla_frame, unsigned gla_time,
  const std::set<std::string> & focus_set) {
  if (check_in_bad_state()) return;

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj; 
	adv_param._candidate_inv_ptr = NULL;
  adv_param._cex_obj_ptr = cex_extract.get();

	ExternalAbcTargetGen vg(
		implementation_incl_path,
		implementation_srcs_path,
		implementation_top_module_name,
		refinement_variable_mapping_path,
		refinement_condition_path,
		os_portable_append_dir(_output_path,"inv-syn-cegar-abc") ,
		tmpl_top_module_name,
		v_backend, s_backend,
		_vtg_config, &adv_param		
	);

	vg.ConstructWrapper("wrapper.v", "wrapper.tpl", focus_set);
  if (useAiger) {
    vg.GenerateAigerProblem("wrapper.aig", "run.sh", "abccmd.txt");
  } else {
    vg.GenerateBlifProblem("wrapper.blif", "run.sh", "abccmd.txt", useGla, useCorr,
      gla_frame, gla_time);
  }

	runnable_script_name = vg.GetRunnableScriptName();
  
  vlg_mod_inst_name = vg.GetDesignUnderVerificationInstanceName();
  ILA_INFO << "dut name : " << vlg_mod_inst_name;
  inv_obj.set_dut_inst_name(vlg_mod_inst_name);

  if (additional_width_info.empty())
    additional_width_info = vg.GetSupplementaryInfo().width_info;
}


/// run Synthesis : returns reachable/not
InvariantSynthesizerExternalCegar::_inv_check_res_t InvariantSynthesizerExternalCegar::RunSynAbcAuto(unsigned timeout) {

  if(check_in_bad_state())
    return _inv_check_res_t::INV_UNKNOWN;
  
  ILA_ASSERT(runnable_script_name.size() == 1) << "Please run GenerateInvSynTargets function first";
  synthesis_result_fn = os_portable_append_dir(_output_path, "__synthesis_result.txt");
  auto redirect_fn = os_portable_append_dir("../", "__synthesis_result.txt");

  auto cwd = os_portable_getcwd();
  auto new_wd = os_portable_path_from_path(runnable_script_name[0]);
  ILA_ERROR_IF(not os_portable_chdir(new_wd)) 
    << "RunVerifAuto: cannot change dir to:" << new_wd;
  ILA_INFO << "Executing synthesis script:" <<  runnable_script_name[0] ;
  execute_result res;

  res = os_portable_execute_shell({"bash",
    os_portable_file_name_from_path( runnable_script_name[0] )},
    redirect_fn, redirect_t::BOTH, timeout);
      
  ILA_ERROR_IF(res.failure != execute_result::NONE )
    << "Running synthesis script " << runnable_script_name[0] << " results in error."; 
  ILA_ASSERT(os_portable_chdir(cwd));

  if (res.timeout) {
    ILA_ERROR << "Set time out!";
    return _inv_check_res_t::INV_UNKNOWN;
  }
  
  inv_syn_time += res.seconds;
  inv_syn_time_series.push_back(res.seconds);

  std::stringstream sbuf;
  std::ifstream fin(synthesis_result_fn);
  if (not fin.is_open()) {
      ILA_ERROR << "Unable to read the synthesis result file:" << synthesis_result_fn;
      bad_state = true;
      return _inv_check_res_t::INV_UNKNOWN; // reachable
    } 
  sbuf << fin.rdbuf();
  cex_reachable = ! ( S_IN( "Property proved." , sbuf.str()) and S_IN( "Invariant contains " , sbuf.str()) );
  
  // else reachable
  return cex_reachable ? _inv_check_res_t::INV_INVALID : _inv_check_res_t::INV_PROVED;
}

void InvariantSynthesizerExternalCegar::JumpStart_FromExtract(bool cex_r) {
  cex_reachable = cex_r;
}

/// to extract reachability test result
bool InvariantSynthesizerExternalCegar::ExtractAbcSynthesisResult(InvariantInCnf & incremental_cnf, bool use_aiger, bool use_gla,
  const InvariantInCnf & inv_cnf) {

  if(check_in_bad_state()) return false;

  if (cex_reachable) {
    ILA_ERROR << "Verification failed with true counterexample! No invariants can be extracted.";
    return false;
  }
  // ILA_ASSERT(current_inv_type != cur_inv_tp::SYGUS_CEX) 
  //   << "API misuse: should not use this function on SYGUS CEX output, they may not be the invariants, but just candidates!";
  // not using aiger !!!
  ILA_ASSERT(runnable_script_name.size() >= 1);

  bool succeed = 
    inv_obj.AddInvariantFromAbcResultFile(
      use_aiger ?
          os_portable_append_dir( os_portable_path_from_path( runnable_script_name[0] ) , "__aiger_prepare.blif"):
          os_portable_append_dir( os_portable_path_from_path( runnable_script_name[0] ) , "wrapper.blif"),
      os_portable_append_dir( os_portable_path_from_path( runnable_script_name[0] ) , "ffmap.info"),
      true,true, use_gla ? 
        os_portable_append_dir( os_portable_path_from_path( runnable_script_name[0] ) , "glamap.info") : "",
      use_aiger,
      use_aiger ?
          os_portable_append_dir( os_portable_path_from_path( runnable_script_name[0] ) , "wrapper.aig.map") : "",
      incremental_cnf, inv_cnf ); // incrementall

  if (not succeed)
    return false;
  
  std::cout << "Confirmed synthesized invariants:" << std::endl;
  for (auto && v : inv_obj.GetVlgConstraints() )
    std::cout << v << std::endl;

  return true;
} // ExtractAbcSynthesisResult


// -------------------- SYGUS ------------------ //
void InvariantSynthesizerExternalCegar::GenerateCexSimplifyTarget(
  const std::string precond, const std::set<std::string> & focus_set ) {

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj; 
	adv_param._candidate_inv_ptr = NULL;
  adv_param._cex_obj_ptr = cex_extract.get();

	ExternalCosaInvValidateTargetGen vg(
		implementation_incl_path,
		implementation_srcs_path,
		implementation_top_module_name,
		refinement_variable_mapping_path,
		refinement_condition_path,
		os_portable_append_dir(_output_path,"cex-block") ,
		tmpl_top_module_name,
		v_backend,
		_vtg_config, &adv_param		
	);

	vg.ConstructWrapper("wrapper.v", "wrapper.tpl", precond, focus_set);
  vg.GenerateVerifyTarget("problem.txt", "run.sh");

	runnable_script_name = vg.GetRunnableScriptName();

  if (vlg_mod_inst_name.empty()) {
    vlg_mod_inst_name = vg.GetDesignUnderVerificationInstanceName();
    inv_obj.set_dut_inst_name(vlg_mod_inst_name);
  }

  if (additional_width_info.empty())
    additional_width_info = vg.GetSupplementaryInfo().width_info;
}

// -------------------------------- AUTO RUNS ------------------------------------------- //

/// a helper function (only locally available)
/// to detect tool error (e.g., verilog parsing error)
bool static has_verify_tool_error_cosa(const std::string & fn) {
  std::ifstream fin(fn);
  if (not fin.is_open()) {
    ILA_ERROR<<"Unable to read from:"<<fn;
    return true;
  }

  std::string line;
  while(std::getline(fin,line)) {
    if (S_IN("See yosys-err.log for more info." , line))
      return true;
  }
  return false;
} // has_verify_tool_error_cosa

  /// a helper function (only locally available)
/// to detect tool error (e.g., verilog parsing error)
bool static has_verify_tool_unknown_cosa(const std::string & fn) {
  std::ifstream fin(fn);
  if (not fin.is_open()) {
    ILA_ERROR<<"Unable to read from:"<<fn;
    return true;
  }
  
  std::string line;
  while(std::getline(fin,line)) {
    if (S_IN("UNKNOWN != TRUE <<<---------| ERROR" , line))
      return true;
  }
  return false;
} // has_verify_tool_error_cosa

InvariantSynthesizerExternalCegar::_inv_check_res_t InvariantSynthesizerExternalCegar::RunVerifyAuto(unsigned timeout) {
  ILA_ASSERT(runnable_script_name.size() == 1) << "No idea which script to run!";
  auto script_sel = runnable_script_name [0];
  if(check_in_bad_state())
    return _inv_check_res_t::INV_UNKNOWN;
  // Not implemented
  auto result_fn = os_portable_append_dir(_output_path, "__verification_result.txt");
  auto redirect_fn = os_portable_append_dir("../", "__verification_result.txt");
  auto cwd = os_portable_getcwd();
  auto new_wd = os_portable_path_from_path(script_sel);
  ILA_ERROR_IF(not os_portable_chdir(new_wd)) 
    << "RunVerifAuto: cannot change dir to:" << new_wd;
  ILA_INFO << "Executing verify script:" << script_sel;
  auto res = os_portable_execute_shell({"bash", 
    os_portable_file_name_from_path( script_sel) },
   redirect_fn, redirect_t::BOTH, timeout);
  ILA_ERROR_IF(res.failure != execute_result::NONE)
    << "Running verification script " << script_sel << " results in error."; 
  ILA_ASSERT(os_portable_chdir(cwd));
  // the last line contains the result
  // above it you should have *** TRACES ***
  // the vcd file resides within the new dir
  ILA_ERROR_IF(has_verify_tool_error_cosa(result_fn)) << "----------- Verification tool reported error! Please check the log output!";
  ILA_ERROR_IF(has_verify_tool_unknown_cosa(result_fn)) << "UNKNOWN Verif result";

  eqcheck_time += res.seconds;
  if (res.timeout)
    return _inv_check_res_t::INV_UNKNOWN;

  auto lastLine = os_portable_read_last_line(result_fn);
  ILA_ERROR_IF(lastLine.empty()) << "Unable to extract verification result.";
  if (S_IN("Verifications with unexpected result", lastLine))
    return _inv_check_res_t::INV_INVALID;
  return _inv_check_res_t::INV_PROVED;
}

void InvariantSynthesizerExternalCegar::AcceptNegCex(const std::set<std::string> & focus_var) {
  inv_obj.AddInvariantFromVerilogExpr("", cex_extract->GenInvAssert("", focus_var) );
}

// -------------------- SYGUS ------------------ //
/// set the sygus name lists (cannot be empty)
void InvariantSynthesizerExternalCegar::SetSygusVarnameList(const std::vector<std::string> & sygus_var_name) {
  sygus_vars = sygus_var_name;
  for (auto && v : sygus_vars)
    sygus_vars_set.insert(v);
}

void InvariantSynthesizerExternalCegar::FindRegAmongNames(
  const std::string & top_module_instance_name,
  std::set<std::string> & nameset) {

  VerilogAnalyzer va(
    implementation_incl_path,
    implementation_srcs_path,
    top_module_instance_name,
    implementation_top_module_name);
  
  for (auto && var : nameset) {
    auto tp = va.check_hierarchical_name_type(var);

    if (tp == va.NONE){
      nameset.erase(var);
      ILA_ERROR << var << " is not a valid design net name!";
      continue;
    } else if (not VerilogAnalyzerBase::is_reg(tp)) {
      std::cout << "remove non state: " << var << std::endl;
      nameset.erase(var);
    }
  }
}

std::set<std::string> InvariantSynthesizerExternalCegar::SetSygusVarnameListAndDeduceWidth(
  const std::vector<std::string> & sygus_var_name,
  const std::string & top_module_instance_name) {
  VerilogAnalyzer va(
    implementation_incl_path,
    implementation_srcs_path,
    top_module_instance_name,
    implementation_top_module_name);
  
  ILA_ERROR_IF(sygus_var_name.empty()) << "Giving empty sygus var names!";
  std::set<std::string> missing_names;

  sygus_vars = sygus_var_name;
  sygus_vars_set.clear();
  for (auto && vname : sygus_var_name)
    sygus_vars_set.insert(vname);
  for (auto && var : sygus_var_name) {
    auto tp = va.check_hierarchical_name_type(var);
    if (tp == va.NONE){
      missing_names.insert(var);
      continue;
    }
    auto sig_info = va.get_signal(var, & additional_width_info); // will use the RF provided one if available
    if (IN(var, additional_width_info))
      ILA_ERROR_IF (additional_width_info.at(var) != sig_info.get_width())
        << "The width info in refinement does not match the width in design";
    else
      additional_width_info.insert(
        std::make_pair(var,sig_info.get_width()));
  }
  return missing_names;
}

/// import datapoints from file (pos example) -- used to prune
void InvariantSynthesizerExternalCegar::ImportDatapointsFromFile(const std::string & fn) {
  CexExtractor cex_temp(fn);
  datapoints.AddPosEx(cex_temp);
}
/// Remove potentially failing candidate invariants (conservative approach remove all candidates)
void InvariantSynthesizerExternalCegar::PruneCandidateInvariant(const std::set<std::string> &drop_names) {
  ILA_ASSERT(not sygus_vars.empty());
  
  DatapointInvariantPruner pruner(inv_candidate,datapoints);
  if (drop_names.empty())
    pruner.PruneByLastFramePosEx(*(design_smt_info.get()), sygus_vars, additional_width_info );
  else{
    std::vector<std::string> local_vars;
    { // remove those to drop
      for (auto && vn : sygus_vars)
        if (IN(vn, drop_names)) continue;
        else local_vars.push_back(vn);
    }
      pruner.PruneByLastFramePosEx(*(design_smt_info.get()), local_vars, additional_width_info );
  }
}

/// Remove potentially failing candidate invariants (conservative approach remove all candidates)
void InvariantSynthesizerExternalCegar::RemoveAllCandidateInvariant(){
  inv_candidate.ClearAllInvariants();
}


/// to generate synthesis target (for using the whole transfer function)
void InvariantSynthesizerExternalCegar::GenerateSynthesisTargetSygusDatapoints(
    const std::set<std::string> &drop_names,
    const Cvc4Syntax & syntax,
    bool enumerate) {
  if (design_smt_info == nullptr) {
    ILA_ERROR << "Please first parse a design_smt_info";
    return;
  }
  // datapoints.SetNegEx(* cex_extract.get()); // you can reset the pos ex using SetInitialDatapoint 

  std::vector<std::string> local_vars;
  { // remove those to drop
    for (auto && vn : sygus_vars)
      if (IN(vn, drop_names)) continue;
      else local_vars.push_back(vn);
  }

  ExternalSygusTargetGen vg(
    os_portable_append_dir( _output_path, "inv-syn-sygus" ),
    additional_width_info,
    _vtg_config,
    NULL,
    local_vars,
    design_smt_info,
    enumerate
  );
  sygus_gen_corrections = vg.GenerateSygusSynthesisTarget("run.sh","wrapper.smt2", syntax);  

	runnable_script_name = vg.GetRunnableScriptName();
}



/// to generate synthesis target (for using the whole transfer function)
void InvariantSynthesizerExternalCegar::GenerateSynthesisTargetSygusTransFunc(
    const std::set<std::string> &drop_names,
    const Cvc4Syntax & syntax,
    bool enumerate) {
  // if (design_smt_info == nullptr) {
  //  ILA_ERROR << "Please first parse a design_smt_info";
  //  return;
  //}

  {
    // to send in the invariants
    advanced_parameters_t adv_param;
    adv_param._inv_obj_ptr = &inv_obj; 
    adv_param._candidate_inv_ptr = NULL;
    adv_param._cex_obj_ptr = cex_extract.get();

    ExternalChcTargetGen vg(
      implementation_incl_path,
      implementation_srcs_path,
      implementation_top_module_name,
      refinement_variable_mapping_path,
      refinement_condition_path,
      os_portable_append_dir(_output_path,"inv-syn-cegar") ,
      tmpl_top_module_name,
      v_backend, synthesis_backend_selector::Z3,
      _vtg_config, &adv_param		
    );

    vg.ConstructWrapper("wrapper.v", "wrapper.tpl", ""); // precod

    design_smt_info = vg.GenerateChc("wrapper-chc.smt2", "run.sh");
    vlg_mod_inst_name = vg.GetDesignUnderVerificationInstanceName();
    inv_obj.set_dut_inst_name(vlg_mod_inst_name);
  }

  // datapoints.SetNegEx(* cex_extract.get()); 
  // you can reset the pos ex using SetInitialDatapoint 

  std::vector<std::string> local_vars;
  { // remove those to drop
    for (auto && vn : sygus_vars)
      if (IN(vn, drop_names)) continue;
      else local_vars.push_back(vn);
  }

  ExternalSygusTargetGen vg(
    os_portable_append_dir( _output_path, "inv-syn-sygus" ),
    additional_width_info,
    _vtg_config,
    NULL,
    local_vars,
    design_smt_info,
    enumerate
  );
  sygus_gen_corrections = vg.GenerateSygusSynthesisTarget("run.sh","wrapper.smt2", syntax);  

	runnable_script_name = vg.GetRunnableScriptName();
}
/// to generate targets using the current invariants
void InvariantSynthesizerExternalCegar::ExportCandidateInvariantsToJasperAssertionFile(
  const std::string & precond,
  const std::string & fn,
  const std::string & var_fn, const std::string & pn_file) {
	// format : assert -name p? { };
  unsigned pn = 0;
	{ // write to fout
		std::ofstream fout(fn);
		if (not fout.is_open()) {
			ILA_ERROR << "Fail to write to :" << fn; return; }
			
		for (auto && inv : inv_candidate.GetVlgConstraints() ) {
			auto inv_no_linebreak = ReplaceAll(ReplaceAll(inv, "\n" , " "), "\r", " ");
			fout << "assert -name p" <<(pn++)  << " { " << precond << "|-> ( " <<  inv_no_linebreak << ") } \n";
		}
	} // from the number of lines, you known how many there are
  {
    std::ofstream fout(pn_file);
		if (not fout.is_open()) {
			ILA_ERROR << "Fail to write to :" << fn; return; }
    for(auto idx = 0; idx < pn; ++ idx)
      fout << "p" <<(idx++) << "\n";
  }
	{ // write to vardefs
		std::ofstream fout(var_fn);
		if (not fout.is_open()) {
			ILA_ERROR << "Fail to write to :" << var_fn; return; }
			
		for (auto && vars : inv_candidate.GetExtraFreeVarDefs() )
			fout << "wire " << WidthToRange(vars.second) << " " << vars.first << " ; \n";
		for (auto && vars : inv_candidate.GetExtraVarDefs() ) {
			fout << "wire " << WidthToRange(std::get<2>(vars)) << " " << std::get<0>(vars)
				<< " = " << std::get<1>(vars) << " ;\n";
		}
	} // write to vardefs
} // ExportCandidateInvariantsToJasperAssumptionFile

/// load inv pos ex from simtrace
void InvariantSynthesizerExternalCegar::LoadDatapointPosExFromSim(const SimTraceExtractor & sim) {
  if (not sygus_vars.empty())
    datapoints.AddPosEx(sim, sygus_vars);
  else
    datapoints.AddPosEx(sim);
}

/// here you can acess the internal datapoint object
const TraceDataPoints & InvariantSynthesizerExternalCegar::GetDatapoints() const {
  return datapoints;
}
/// Here you can extract the invariants and export them if needed
const InvariantObject & InvariantSynthesizerExternalCegar::GetCandidateInvariants() const {
  return inv_candidate;
}
/// export the cex check to make sure cex is unreachable
void InvariantSynthesizerExternalCegar::ExportCexCheck(
  const std::string & precond,
  const std::string & assertfile,
  const std::string &propfile,
  const std::set<std::string> &drop_names ) {
  { // cex assert
    std::ofstream fout(assertfile);
    if (!fout.is_open()) { ILA_ERROR << "Cannot write to:" << assertfile ; return;}

    std::set<std::string> difference;
    DIFFERENCE(sygus_vars_set,drop_names,difference);
    ILA_ERROR_IF(sygus_vars_set.size() - drop_names.size() != difference.size())
      << "Drop names is not a subset of sygus_var_set";
    fout << "assert -name cexblock { " << precond << " |-> !(" << cex_extract->GenInvAssert("", difference) + ") }";
  } // cex assert
  { // prop
    std::ofstream fout(propfile);
    if (!fout.is_open()) { ILA_ERROR << "Cannot write to:" << propfile ; return;}
    fout << "cexblock";
  } // prop
}

/// accept all candidate invariants as confirmed ones
void InvariantSynthesizerExternalCegar::AcceptAllCandidateInvariant() {
  if(inv_candidate.NumInvariant() != 0) {
    inv_obj.InsertFromAnotherInvObj(inv_candidate);
    inv_candidate.ClearAllInvariants();
  } else 
    ILA_INFO <<"All candidate invariants have been accepted.";
}


/// to extract the synthesis attempt
bool InvariantSynthesizerExternalCegar::ExtractSygusDatapointSynthesisResultAsCandidateInvariant(
  const std::string & duv_inst_name) {

  if(check_in_bad_state()) return false;

  std::string res_file = synthesis_result_fn;
  
  if (design_smt_info == nullptr) {
    ILA_ERROR << "Design SMT-LIB2 info is not available. "
      << "You need to run `LoadDesignSmtInfoFromSmt` first.";
    return false;
  }

  inv_candidate.set_dut_inst_name(duv_inst_name);
  // inv_candidate.ClearAllInvariants();  -- we will keep the old ones
  if( inv_candidate.AddInvariantFromSygusResultFile(
      *(design_smt_info.get()), "", res_file, 
      _vtg_config.YosysSmtFlattenDatatype,
      _vtg_config.YosysSmtFlattenHierarchy,
      false, sygus_gen_corrections ) == false) {
    return false; // sygus failed
  }
    
  std::cout << "INV candidate:" << std::endl;
  for (auto && v : inv_candidate.GetVlgConstraints() )
    std::cout << v << std::endl;
  return true;
}

/// load design smt info from a given design file 
void InvariantSynthesizerExternalCegar::LoadDesignSmtInfoFromSmt(const std::string & fn) {
  std::ifstream fin(fn);
  if (not fin.is_open()) {
    ILA_ERROR << "Cannot read from:" << fn;
    return;
  }
  std::stringstream sbuf;
  sbuf << fin.rdbuf();
  design_smt_info = std::make_shared<smt::YosysSmtParser>(sbuf.str());
}

  // -------------------- ACCESSOR ------------------ //
bool InvariantSynthesizerExternalCegar::check_in_bad_state() const {
  ILA_ERROR_IF(bad_state) << "In bad state, cannot proceed.";
  return bad_state;
}

void InvariantSynthesizerExternalCegar::LoadPrevStatisticsState(const std::string & fn) {
  DesignStatistics local_info;
  local_info.LoadFromFile(fn);
  if ( eqcheck_time != 0 || 
      inv_proof_attempt_time != 0 ||
      inv_syn_time != 0 ||
      inv_validate_time != 0 ||
      ! inv_syn_time_series.empty() ) {
    ILA_ERROR << "Not loading the statistics state from initial time!";
    }
  eqcheck_time += local_info.TimeOfEqCheck;
  inv_proof_attempt_time += local_info.TimeOfInvProof;
  inv_syn_time += local_info.TimeOfInvSyn;
  inv_validate_time += local_info.TimeOfInvValidate;
  inv_syn_time_series.insert(inv_syn_time_series.end(),local_info.TimeOfInvSynSeries.begin(), local_info.TimeOfInvSynSeries.end());
}

/// Here you can get the design information
DesignStatistics InvariantSynthesizerExternalCegar::GetDesignStatistics() const {
  DesignStatistics ret;
  ret.TimeOfEqCheck     = eqcheck_time;
  ret.TimeOfInvProof    = inv_proof_attempt_time;
  ret.TimeOfInvSyn      = inv_syn_time;
  ret.TimeOfInvValidate = inv_validate_time;
  ret.TimeOfInvSynSeries= inv_syn_time_series;

  if (design_smt_info == nullptr) {
    ILA_WARN << "Design information not available!";
    return ret;
  }
  std::string query_mod_name = implementation_top_module_name;
  
  ILA_ERROR_IF(vlg_mod_inst_name.empty()) << "vlg_mod_inst_name is empty, will not distinguish in/out module state";

  for (auto && st : design_smt_info->get_module_flatten_dt("wrapper")) {
    if ( st.verilog_name.find(vlg_mod_inst_name + ".") == 0 ) {
      ret.NumOfDesignStateBits += st._type.GetBoolBvWidth();
      ret.NumOfDesignStateVars ++;
    } else {
      ret.NumOfExtraStateBits += st._type.GetBoolBvWidth();
      ret.NumOfExtraStateVars ++;
    }
  }
  return ret;
} // GetDesignStatistics

/// Here you can extract the invariants and export them if needed
const InvariantObject & InvariantSynthesizerExternalCegar::GetInvariants() const {
  return inv_obj;
}

/// load states -- confirmed invariants
void InvariantSynthesizerExternalCegar::LoadInvariantsFromFile(const std::string &fn) {
  inv_obj.ImportFromFile(fn);
}

void InvariantSynthesizerExternalCegar::LoadCandidateInvariantsFromFile(const std::string &fn) {
  inv_candidate.ImportFromFile(fn);
}
void InvariantSynthesizerExternalCegar::LoadDatapointFromFile(const std::string &fn) {
  datapoints.ImportNonprovidedPosEx(fn, sygus_vars);
}


}; // namespace ilang
