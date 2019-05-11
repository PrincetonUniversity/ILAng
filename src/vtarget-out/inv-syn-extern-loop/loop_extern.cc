/// \file Header Externally Provided Target for inv-syn

#include <ilang/util/log.h>
#include <ilang/util/fs.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/vtarget-out/inv-syn-extern-loop/loop_extern.h>
#include <ilang/vtarget-out/inv-syn-extern-loop/yosys_chc.h>
#include <ilang/vtarget-out/inv-syn-extern-loop/yosys_abc.h>
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
    inv_syn_time(0)
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
	const std::string & fn, const std::string & var_fn) {
	// format : assume { };
	{ // write to fout
		std::ofstream fout(fn);
		if (not fout.is_open()) {
			ILA_ERROR << "Fail to write to :" << fn; return; }
			
		for (auto && inv : inv_obj.GetVlgConstraints() ) {
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


/// run Synthesis : returns reachable/not
bool InvariantSynthesizerExternalCegar::RunSynAuto(bool isSyGuS) {

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
  return cex_reachable;
}


/// to extract reachability test result
void InvariantSynthesizerExternalCegar::ExtractSynthesisResult(bool autodet, bool reachable, 
	const std::string & given_smt_chc_result_txt) {

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
    
  if (1 /*current_inv_type == cur_inv_tp::CHC*/)
    inv_obj.AddInvariantFromChcResultFile(
      *(design_smt_info.get()), "", res_file, 
      _vtg_config.YosysSmtFlattenDatatype,
      _vtg_config.YosysSmtFlattenHierarchy,
      false );
  else
    ILA_ERROR<<"Inv type unknown ";// << current_inv_type;
  
  std::cout << "Confirmed synthesized invariants:" << std::endl;
  for (auto && v : inv_obj.GetVlgConstraints() )
    std::cout << v << std::endl;

  // status = cegar_status::NEXT_V;
  // current_inv_type = cur_inv_tp::NONE; // we have extracted, reset this marker
} // ExtractSynthesisResult


// -------------------- CEGAR ABC ------------------------ //

/// generate chc target
void InvariantSynthesizerExternalCegar::GenerateAbcSynthesisTarget(
  const std::string & precond, const std::string & assume_reg, bool useGla,
  bool useCorr) {
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

	vg.ConstructWrapper("wrapper.v", "wrapper.tpl", precond, assume_reg);
	vg.GenerateBlifProblem("wrapper.blif", "run.sh", "abccmd.txt", useGla, useCorr);

	runnable_script_name = vg.GetRunnableScriptName();
  
  vlg_mod_inst_name = vg.GetDesignUnderVerificationInstanceName();
  inv_obj.set_dut_inst_name(vlg_mod_inst_name);

  if (additional_width_info.empty())
    additional_width_info = vg.GetSupplementaryInfo().width_info;
}


/// run Synthesis : returns reachable/not
bool InvariantSynthesizerExternalCegar::RunSynAbcAuto() {

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

  res = os_portable_execute_shell({"bash",
    os_portable_file_name_from_path( runnable_script_name[0] )},
    redirect_fn, redirect_t::BOTH);
      
  ILA_ERROR_IF(res.failure != execute_result::NONE )
    << "Running synthesis script " << runnable_script_name[0] << " results in error."; 
  ILA_ASSERT(os_portable_chdir(cwd));
  
  inv_syn_time += res.seconds;

  std::stringstream sbuf;
  std::ifstream fin(synthesis_result_fn);
  if (not fin.is_open()) {
      ILA_ERROR << "Unable to read the synthesis result file:" << synthesis_result_fn;
      bad_state = true;
      return true; // reachable
    } 
  sbuf << fin.rdbuf();
  cex_reachable = ! ( S_IN( "Property proved." , sbuf.str()) and S_IN( "Invariant contains " , sbuf.str()) );
  
  // else reachable
  return cex_reachable;
}


/// to extract reachability test result
bool InvariantSynthesizerExternalCegar::ExtractAbcSynthesisResult(const std::string & blifname,
  const std::string &ffmap_file) {

  if(check_in_bad_state()) return false;

  if (cex_reachable) {
    ILA_ERROR << "Verification failed with true counterexample! No invariants can be extracted.";
    return false;
  }
  // ILA_ASSERT(current_inv_type != cur_inv_tp::SYGUS_CEX) 
  //   << "API misuse: should not use this function on SYGUS CEX output, they may not be the invariants, but just candidates!";
    
  bool succeed = inv_obj.AddInvariantFromAbcResultFile(blifname, ffmap_file, true, false);
  if (not succeed)
    return false;
  
  std::cout << "Confirmed synthesized invariants:" << std::endl;
  for (auto && v : inv_obj.GetVlgConstraints() )
    std::cout << v << std::endl;

  return true;
} // ExtractAbcSynthesisResult



// -------------------- SYGUS ------------------ //
/// set the sygus name lists (cannot be empty)
void InvariantSynthesizerExternalCegar::SetSygusVarnameList(const std::vector<std::string> & sygus_var_name) {
  sygus_vars = sygus_var_name;
  for (auto && v : sygus_vars)
    sygus_vars_set.insert(v);
}
/// import datapoints from file (pos example) -- used to prune
void InvariantSynthesizerExternalCegar::ImportDatapointsFromFile(const std::string & fn) {
  CexExtractor cex_temp(fn);
  datapoints.AddPosEx(cex_temp);
}
/// Remove potentially failing candidate invariants (conservative approach remove all candidates)
void InvariantSynthesizerExternalCegar::PruneCandidateInvariant() {
  ILA_ASSERT(not sygus_vars.empty());
  
  DatapointInvariantPruner pruner(inv_candidate,datapoints);
  pruner.PruneByLastFramePosEx(*(design_smt_info.get()), sygus_vars, additional_width_info );
}

/// to generate synthesis target (for using the whole transfer function)
void InvariantSynthesizerExternalCegar::GenerateSynthesisTargetSygusDatapoints(bool enumerate) {
  if (design_smt_info == nullptr) {
    ILA_ERROR << "Please first parse a design_smt_info";
    return;
  }
  datapoints.SetNegEx(* cex_extract.get()); // you can reset the pos ex using SetInitialDatapoint 

  ExternalSygusTargetGen vg(
    os_portable_append_dir( _output_path, "inv-syn-sygus" ),
    additional_width_info,
    _vtg_config,
    & datapoints,
    sygus_vars,
    design_smt_info,
    enumerate
  );
  sygus_gen_corrections = vg.GenerateSygusSynthesisTarget("run.sh","wrapper.smt2");  

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
  const std::string & assertfile, const std::string &propfile) {
  { // cex assert
    std::ofstream fout(assertfile);
    if (!fout.is_open()) { ILA_ERROR << "Cannot write to:" << assertfile ; return;}
    fout << "assert -name cexblock { " << precond << " |-> !(" << cex_extract->GenInvAssert("") + ") }";
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

/// Here you can get the design information
DesignStatistics InvariantSynthesizerExternalCegar::GetDesignStatistics() const {
  DesignStatistics ret;
  ret.TimeOfEqCheck     = eqcheck_time;
  ret.TimeOfInvProof    = inv_proof_attempt_time;
  ret.TimeOfInvSyn      = inv_syn_time;
  ret.TimeOfInvValidate = inv_validate_time;

  if (design_smt_info == nullptr) {
    ILA_ERROR << "Design information not available!";
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
  datapoints.ImportNonprovidedPosEx(fn);
}


}; // namespace ilang
