/// \file Source of generating Yosys accepted problem, vlg, mem, script
// --- Hongce Zhang

#include <algorithm>
#include <fstream>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/absmem.h>
#include <ilang/vtarget-out/vtarget_gen_yosys.h>
#include <iostream>

namespace ilang {

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"

VlgSglTgtGen_Yosys::VlgSglTgtGen_Yosys(
    const std::string&
        output_path, // will be a sub directory of the output_path of its parent
    const InstrPtr& instr_ptr, // which could be an empty pointer, and it will
                               // be used to verify invariants
    const InstrLvlAbsPtr& ila_ptr, const VerilogGenerator::VlgGenConfig& config,
    nlohmann::json& _rf_vmap, nlohmann::json& _rf_cond,
    VerilogInfo* _vlg_info_ptr, const std::string& vlg_mod_inst_name,
    const std::string& ila_mod_inst_name, const std::string& wrapper_name,
    const std::vector<std::string>& implementation_srcs,
    const std::vector<std::string>& implementation_include_path,
    const vtg_config_t& vtg_config, backend_selector backend,
    const target_type_t& target_tp)
    : VlgSglTgtGen(output_path, instr_ptr, ila_ptr, config, _rf_vmap, _rf_cond,
                   _vlg_info_ptr, vlg_mod_inst_name, ila_mod_inst_name,
                   wrapper_name, implementation_srcs,
                   implementation_include_path, vtg_config, backend,
                   target_tp) { 

// initialize templates
yosysGenerateSmtScript_wo_Array = R"***(
flatten
memory -nordff
)***";

yosysGenerateSmtScript_w_Array = R"***(
hierarchy -check
proc
opt
opt_expr -mux_undef
opt
opt
memory_dff -wr_only
memory_collect;
flatten;
memory_unpack
splitnets -driver
opt;;
memory_collect;
pmuxtree
proc
opt;;
)***";
                    }


void VlgSglTgtGen_Yosys::add_wire_assign_assumption(
    const std::string& varname, const std::string& expression,
    const std::string& dspt) {
  //_problems.assumptions.push_back(varname + " = " +
  //                                convert_expr_to_yosys(expression));
  vlg_wrapper.add_assign_stmt(varname, expression);
  ILA_ERROR_IF(expression.find(".") != std::string::npos)
      << "expression:" << expression << " contains unfriendly dot.";
}

void VlgSglTgtGen_Yosys::add_reg_cassign_assumption(
    const std::string& varname, const std::string& expression,
    const std::string& cond, const std::string& dspt) {
  // vlg_wrapper.add_always_stmt(varname + " <= " + varname + ";");
  // _problems.assumptions.push_back("(!( " + convert_expr_to_yosys(cond) +
  //                                 " ) | (" + varname + " = " +
  //                                convert_expr_to_yosys(expression) + "))");
  ILA_ERROR_IF(expression.find(".") != std::string::npos)
      << "expression:" << expression << " contains unfriendly dot.";
  // vlg_wrapper.add_always_stmt("if (" + cond + ") " + varname +
  //                            " <= " + expression + "; //" + dspt);
  // we prefer the following way, as we get the value instantaneously
  vlg_wrapper.add_init_stmt(varname + " <= " + expression + ";");
  vlg_wrapper.add_always_stmt(varname + " <= " + varname + ";");
  add_an_assumption(
      "(~(" + cond + ") || ((" + varname + ") == (" + expression + ")))", dspt);
}

/// Add an assumption
void VlgSglTgtGen_Yosys::add_an_assumption(const std::string& aspt,
                                          const std::string& dspt) {
  auto assumption_wire_name = vlg_wrapper.sanitizeName(dspt) + new_mapping_id();
  vlg_wrapper.add_wire(assumption_wire_name, 1, true);
  vlg_wrapper.add_output(assumption_wire_name,
                         1); // I find it is necessary to connect to the output
  vlg_wrapper.add_assign_stmt(assumption_wire_name, aspt);
  ILA_ERROR_IF(aspt.find(".") != std::string::npos)
      << "aspt:" << aspt << " contains unfriendly dot.";
  _problems.assumptions[dspt].exprs.push_back(assumption_wire_name + " == 1'b1");
  //_problems.assumptions.push_back(convert_expr_to_yosys(aspt));
}
/// Add an assertion
void VlgSglTgtGen_Yosys::add_an_assertion(const std::string& asst,
                                         const std::string& dspt) {
  auto assrt_wire_name = vlg_wrapper.sanitizeName(dspt) + new_property_id();
  vlg_wrapper.add_wire(assrt_wire_name, 1, true);
  vlg_wrapper.add_output(assrt_wire_name,
                         1); // I find it is necessary to connect to the output
  vlg_wrapper.add_assign_stmt(assrt_wire_name, asst);
  _problems.assertions[dspt].exprs.push_back(assrt_wire_name + " == 1'b1");
  ILA_ERROR_IF(asst.find(".") != std::string::npos)
      << "asst:" << asst << " contains unfriendly dot.";
  //_problems.probitem[dspt].assertions.push_back(convert_expr_to_yosys(asst));
}

/// Add an assumption
void VlgSglTgtGen_Yosys::add_a_direct_assumption(const std::string& aspt,
                                                const std::string& dspt) {
  _problems.assumptions[dspt].exprs.push_back(aspt);
}
/// Add an assertion
void VlgSglTgtGen_Yosys::add_a_direct_assertion(const std::string& asst,
                                               const std::string& dspt) {
  _problems.assertions[dspt].exprs.push_back(asst);
}

/// Pre export work : add assume and asssert to the top level
/// collect the type of assumptions and assertions
/// Assertions: variable_map_assert (no invariant_assert --- not for invariant target)
/// Assumptions:
///      1. global: noreset, funcmap, absmem, additonal_mapping_control_assume
///      2. only at starting state:
///          variable_map_assume, issue_decode, issue_valid, ...
///      Question: invariant assume? where to put it? Depends on ?

void VlgSglTgtGen_Yosys::PreExportProcess() {
  // .. ??

  std::string global_assume = "`true";
  std::string start_assume  = "`true";

/*
  for(auto&& dspt_exprs_pair : _problems.assumptions) {
    const auto & dspt = dspt_exprs_pair.first;
    const auto & expr = dspt_exprs_pair.second;
    for (auto&& p: expr.exprs)
      vlg_wrapper.add_stmt(
        "assume property ("+p+"); // " + dspt
      );
  }

  //std::string assmpt = "(" + Join(_problems.assumptions, ") & (") + ")";
*/
  std::string all_assert_wire_content = "`true";

  for (auto&& pbname_prob_pair : _problems.assertions) {
    const auto& prbname = pbname_prob_pair.first;
    const auto& prob = pbname_prob_pair.second;
    
    ILA_ASSERT(prbname == "variable_map_assert"); // sanity check, in case I forget sth.

    for (auto&& p: prob.exprs) {
      vlg_wrapper.add_stmt(
        "assert property ("+p+"); //" + prbname + "\n"
      );
      all_assert_wire_content += "&& ( " + p  + " ) ";
    }
  }

  vlg_wrapper.add_wire("__all_assert_wire__", 1, true);
  vlg_wrapper.add_output("__all_assert_wire__",1);
  vlg_wrapper.add_assign_stmt("__all_assert_wire__", all_assert_wire_content);
} // PreExportProcess

/// export the script to run the verification0
void VlgSglTgtGen_Yosys::Export_script(const std::string& script_name) {
  yosys_run_script_name = script_name;

  auto fname = os_portable_append_dir(_output_path, script_name);
  std::ofstream fout(fname);
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing to file:" << fname;
    return;
  }
  fout << "#!/bin/bash" << std::endl;

  std::string yosys = "yosys";

  // no need, copy is good enough
  // if(vlg_include_files_path.size() != 0)
  //  options += " -I./";

  if (not _vtg_config.YosysPath.empty())
    yosys = os_portable_append_dir(_vtg_config.YosysPath, yosys);

  if (yosys_prob_fname != "")
    fout << yosys << " "<< yosys_prob_fname  << std::endl;
  else
    fout << "echo 'Nothing to check!'" << std::endl;
}


// if we are not proving with arb state
// (force initial state)
// then we only need a single ind-inv
std::string single_ind_inv_tmpl = R"***(
;----------------------------------------
;  Single Inductive Invariant Synthesis
;  Generated from ILAng
;----------------------------------------

%%

;(declare-rel INIT (|%1%_s|))
;(declare-rel T (|%1%_s|) (|%1%_s|))
(declare-rel INV (|%1%_s|))
(declare-rel fail ())


(declare-var |__BI__| |%1%_s|)
(declare-var |__I__| |%1%_s|)

(declare-var |__S__| |%1%_s|)
(declare-var |__S'__| |%1%_s|)

;(rule (|%1%_is| |__S__|))
(rule (=> (and (|%1%_n rst| |__BI__|) (|%1%_t| |__BI__| |__I__|)) (INV |__I__|)))
(rule (=> (and (INV |__S__|) (|%1%_t| |__S__| |__S'__|)) (INV |__S'__|)))
(rule (=> (and (INV |__S__|) (not (|%1%_a| |__S__|))) fail))
;(rule (=> (INV |__S__|) (not (|%1%_a| |__S__|))))

(query fail :print-certificate true)

)***";


/// export extra things (problem) : for yosys, it is the gensmt.ys 
/// and also the template : for the single-ind-inv
void VlgSglTgtGen_Yosys::Export_problem(const std::string& extra_name) {
  // should only be used when forcing reset (no inv syn).
  ILA_ASSERT( _vtg_config.ForceInstCheckReset );

  if (_problems.assertions.size() == 0) {
    ILA_ERROR << "Nothing to prove, no assertions inserted!";
    return;
  }
  // First, write the template
  std::string pdr_template_name = 
    os_portable_append_dir(_output_path, "invSyn.tpl");
  {
    std::ofstream fout(pdr_template_name);
    auto const & tmpl = 
      //_vtg_config.ForceInstCheckReset ? 
      single_ind_inv_tmpl; // : dual_ind_inv_tmpl;

    fout << ReplaceAll(tmpl, "%1%", top_mod_name);
  }



  yosys_prob_fname = extra_name;

  std::ofstream fout(os_portable_append_dir(_output_path, extra_name));
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing file: "
              << os_portable_append_dir(_output_path, extra_name);
    return;
  }

  std::string write_smt2_options;

  write_smt2_options += " -mem -bv -wires -tpl " + pdr_template_name ;
  switch(_vtg_config.YosysSmtStateSort) {
    case vtg_config_t::DataSort: write_smt2_options += " -stdt"; break;
    case vtg_config_t::BitVec: write_smt2_options += " -stbv"; 
      ILA_ERROR_IF(_vtg_config.YosysSmtArrayForRegFile)
        << "Bitvector SMT encoding is not compatible w. option YosysSmtArrayForRegFile";
      break;
    case vtg_config_t::UnintepretedFunc: break; // do nothing
    default: ILA_ERROR << "Unknown option for YosysSmtStateSort option";
  }


  fout << "read_verilog -sv "<<top_file_name<< std::endl;
  fout << "prep -top "<<top_mod_name<<std::endl;
  if(_vtg_config.YosysSmtArrayForRegFile)
    fout << yosysGenerateSmtScript_w_Array;
  else
    fout << yosysGenerateSmtScript_wo_Array;
  fout << "write_smt2"<<write_smt2_options
    << os_portable_remove_file_name_extension(top_file_name)
        + ".smt2";
} 

// -------------------------------------------
// Summary of the assertions/assumptions we need to handle
//
// assert: variable_map_assert
// 
// assmpt:  noreset (AMC) 
//          funcmap (AMC)
//          absmem (AMC)
//          additional_mapping_control_assume (AMC)
//          invariant_assume (AMC_design)
//          issue_decode (START -- ASPT)
//          issue_valid  (START -- ASPT)
//          start_condition (START -- ASPT)
//          variable_map_assert (on final step)
//
// (AMC means should always be true)
//

// o.w. we need to find two ind-inv
std::string dual_ind_inv_tmpl = R"***(
;----------------------------------------
;  Dual Inductive Invariant Synthesis
;  Generated from ILAng
;----------------------------------------


%%

; design smt
%designSmt%

; wrapper smt
%wrapperSmt%

; map function
(define-fun |__MAP__w2v| ((|Sw| |%w%_s|) (|Sv| |%d%_s|)) %mapFunc%)

; additional mapping control
; |__AMC__design| is actually the invariants
; 
(define-fun |__AMC__design|  ((|Sv| |%d%_s|)) %amcFunc_design%)
(define-fun |__AMC__wrapper| ((|Sw| |%w%_s|)) %amcFunc_wrapper%)

; includes the start_condition, issue_decode, issue_valid
;(define-fun |__ASPT__| ((|Sw| |%w%_s|)) (??)) 
%ASPT%

; includes the variable_map_assert
;(define-fun |__ASST__| ((|Sw| |%w%_s|)) (??)) 
%ASST%


(declare-rel INV1 (|%d%_s|)) ; inv1 is on design
(declare-rel INV2 (|%w%_s|)) ; inv2 is on wrapper
(declare-rel fail ())

(declare-var |__SvBI__| |%d%_s|) ; design
(declare-var |__SvI__|  |%d%_s|) ; design
(declare-var |__Sv__|   |%d%_s|) ; design
(declare-var |__Sv'__|  |%d%_s|) ; design

(declare-var |__SwBI__| |%w%_s|) ; wrapper : before init
(declare-var |__SwI__|  |%w%_s|) ; wrapper : init state
(declare-var |__Swst__| |%w%_s|) ; wrapper : starting -- __START__ signal is true
(declare-var |__Sw__|   |%d%_s|) ; wrapper : generic state
(declare-var |__Sw'__|  |%d%_s|) ; wrapper : new state
(declare-var |__Svst__| |%d%_s|) ; design  : starting -- __START__ signal is true here


; init => inv1
(rule (=> 
  (and 
    (and
      (|%d%_n rst| |__SvBI__|) 
      (|%d%_t|     |__SvBI__| |__SvI__|))
    (|__AMC__design| |__SvI__|)
  ) (INV1 |__SvI__|)))

; inv1 /\ T => inv1
(rule (=> 
  (and
    (and
      (and
        (INV1    |__Sv__|)
        (|%d%_t| |__Sv__| |__Sv'__|))
      (|__AMC__design| |__Sv__|))
    (|__AMC__design| |__Sv'__|))
  (INV1 |__Sv'__|)))

; init /\ inv1 => inv2
(rule (=> 
    (and
      (and
        (and
          (and
            (and
              (and
                (and
                  (|%w%_n rst| |__SwBI__|)
                  (|%w%_t|     |__SwBI__| |__SwI__|)
                )
                (|__AMC__wrapper| |__SwI__|)
              )
              (|%w%_t| |__SwI__| |__Swst__|)
            )
            (|__AMC__wrapper| |__Swst__|)
          )
          (|__ASPT__| |__Swst__|)
        )
        (|__MAP__w2v| |__Swst__| |__Svst__|)
      )
      (INV1 |__Svst|)
    )
    (INV2 |__Swst__|)
  )
)

; inv2 /\ T => inv2
(rule 
  (=>
    (and
      (and
        (and
          (INV2 |__Sw__|)
          (|%w%_t| |__Sw__| |__Sw'__|)
        )
        (|__AMC__wrapper| |__Sw__|)
      )
      (|__AMC__wrapper| |__Sw'__|)
    )
    (INV2 |__Sw'__|)
  )
)

; inv2 /\ ~ assert => fail
(rule 
  (=> 
    (and
      (and 
        (INV2             |__Sw__|)
        (|__AMC__wrapper| |__Sw__|))
      (not (|__ASST__|    |__Sw__|)))
    fail)
)


(query fail :print-certificate true)

)***";

/// output the template for dual inv syn
std::string VlgSglTgtGen_Yosys::get_smt_template(const YosysDesignSmtInfo & smtinfo) {
// 0. 
//    analyzing the state sequence
//    so you can decide the mapping
  auto smt_file_name = 
      "__wrapper_"
    + os_portable_remove_file_name_extension(top_file_name)
    + ".smt2";

  auto smt_file_path =
    os_portable_append_dir(_output_path, smt_file_name);

  auto state_name_vec = 
    extract_state_info_from_smt(smt_file_path);

// 1. import design_smt/wrapper_smt
  std::string design_smt;
  std::string wrapper_smt;

  {
    std::ifstream design_smt_fin(smtinfo.top_mod_name + ".smt2");
    std::stringstream buffer;
    buffer << design_smt_fin.rdbuf();
    buffer >> design_smt;
  }

  {
    std::ifstream wrapper_smt_fin(smt_file_name);
    std::stringstream buffer;
    buffer << wrapper_smt_fin.rdbuf();
    buffer >> wrapper_smt;
  }

// 2. define map func
  std::string map_func_def;
  std::vector<std::string> map_item;
  // when you map the state name, remember to put the "m0." there
  const auto & design_top_mod_name = smtinfo.top_mod_name;
  for (auto && vlg_sig_ref_pair : smtinfo.state_pos_name_map) {
    auto top_lvl_vlg_name = _vlg_mod_inst_name + "." + vlg_sig_ref_pair.first; // vlg_name
    auto sn_pos = state_name_vec.find(top_lvl_vlg_name);
    ILA_ASSERT( sn_pos != state_name_vec.end() )
      << "BUG: cannot find Verilog state name:"
      << top_lvl_vlg_name << " in top level smt data sort";

    map_item.push_back(
      "(= " +
      (
        ( "(" + sn_pos->second.ref_name + " |Sw|)" )
      +
        ( "(" + vlg_sig_ref_pair.second.vlg_name + " |Sv|)" )
      )
      + ")" );
  }

  { // concat with (and A B)
    ILA_ASSERT(not map_item.empty());
    auto sz = map_item.size();
    if(sz == 1) {
      map_func_def = map_item[0];
    } else {
      map_func_def = "(and " + map_item[0] + " " +  map_item[1] + ")";
      for (decltype(sz) idx = 2; idx < sz; ++ idx)
        map_func_def = "(and " + map_func_def + " " + map_item[idx] + ")";
    }
  } // end concat

// 3. define amc(d/w)/asst/aspt funcs
  std::string amc_design;
  std::string amc_wrapper;
  std::string asst;
  std::string aspt;
  
  // the invariant assert exists in this target
  // should be the same as those exists in the other, but it is better to have
  // this passed through smt_info
  // (|%d%_invariant_assert| |Sv|)

  {

  }




}

// it needs to know the previous smt-info
// generate the problem for dual inv syn
void VlgSglTgtGen_Yosys::Export_problem(const std::string& extra_name, const YosysDesignSmtInfo & smt_info) {

  // should only be used when forcing reset (no inv syn).
  ILA_ASSERT( not _vtg_config.ForceInstCheckReset );
  
  if (_problems.assertions.size() == 0) {
    ILA_ERROR << "Nothing to prove, no assertions inserted!";
    return;
  }
  // First, write the template
  std::string pdr_template_name = 
    os_portable_append_dir(_output_path, "invSyn.tpl");
  {
    std::ofstream fout(pdr_template_name);
    auto const & tmpl = 
      _vtg_config.ForceInstCheckReset ? 
      single_ind_inv_tmpl : dual_ind_inv_tmpl;

    fout << ReplaceAll(tmpl, "%1%", top_mod_name);
  }



  yosys_prob_fname = extra_name;

  std::ofstream fout(os_portable_append_dir(_output_path, extra_name));
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing file: "
              << os_portable_append_dir(_output_path, extra_name);
    return;
  }

  std::string write_smt2_options;

  write_smt2_options += " -mem -bv -wires -tpl " + pdr_template_name ;
  switch(_vtg_config.YosysSmtStateSort) {
    case vtg_config_t::DataSort: write_smt2_options += " -stdt"; break;
    case vtg_config_t::BitVec: write_smt2_options += " -stbv"; 
      ILA_ERROR_IF(_vtg_config.YosysSmtArrayForRegFile)
        << "Bitvector SMT encoding is not compatible w. option YosysSmtArrayForRegFile";
      break;
    case vtg_config_t::UnintepretedFunc: break; // do nothing
    default: ILA_ERROR << "Unknown option for YosysSmtStateSort option";
  }


  fout << "read_verilog -sv "<<top_file_name<< std::endl;
  fout << "prep -top "<<top_mod_name<<std::endl;
  if(_vtg_config.YosysSmtArrayForRegFile)
    fout << yosysGenerateSmtScript_w_Array;
  else
    fout << yosysGenerateSmtScript_wo_Array;
  fout << "write_smt2"<<write_smt2_options
    << os_portable_remove_file_name_extension(top_file_name)
        + ".smt2";
} 

/// export the memory abstraction (implementation)
/// Yes, this is also implementation specific, (jasper may use a different one)
void VlgSglTgtGen_Yosys::Export_mem(const std::string& mem_name) {
  // we will ignore the mem_name

  auto outfn = os_portable_append_dir(_output_path, top_file_name);
  std::ofstream fout(outfn, std::ios_base::app); // append

  VlgAbsMem::OutputMemFile(fout);
}

/// For jasper, this means do nothing, for yosys, you need to add (*keep*)
void VlgSglTgtGen_Yosys::Export_modify_verilog() {
  // collect all locations: filename -> lineno
  // open, read, count and write
  // if it is a port name, we will ask user to specify its upper level
  // signal name
  VerilogModifier vlg_mod(vlg_info_ptr,
                          static_cast<VerilogModifier::port_decl_style_t>(
                              _vtg_config.PortDeclStyle),
                          _vtg_config.CosaAddKeep);

  for (auto&& refered_vlg_item : _all_referred_vlg_names) {
    auto idx = refered_vlg_item.first.find("[");
    auto removed_range_name = refered_vlg_item.first.substr(0, idx);
    vlg_mod.RecordKeepSignalName(removed_range_name);
    // auto sig = // no use, this is too late, vlg_wrapper already exported
    vlg_mod.RecordConnectSigName(removed_range_name,
                                 refered_vlg_item.second.range);
    // vlg_wrapper.add_output(sig.first, sig.second);
  }
  vlg_mod.FinishRecording();


  //auto tmp_fn = os_portable_append_dir(_output_path, tmp_design_file);
  auto tmp_fn = os_portable_append_dir(_output_path, top_file_name);
  // now let's do the job
  for (auto&& fn : vlg_design_files) {
    std::ifstream fin(fn);
    std::ofstream fout(tmp_fn, std::ios_base::app); // append to a temp file
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read file:" << fn;
      continue;
    }
    if (!fout.is_open()) {
      ILA_ERROR << "Cannot open file for write:" << tmp_fn;
      continue;
    }
    vlg_mod.ReadModifyWrite(fn, fin, fout);
  } // for (auto && fn : vlg_design_files)

  /*
  // also make a copy to the top module
  {
    auto wrapper_file_name = os_portable_append_dir(_output_path, top_file_name);
    std::ifstream fin (tmp_fn);
    std::ofstream fout(wrapper_file_name, std::ios_base::app); // append to the wrapper file
    ILA_ERROR_IF(fin.is_open()) << "Cannot open file for read:" << tmp_fn;
    ILA_ERROR_IF(fout.is_open()) << "Cannot open file for write:" << wrapper_file_name;
    if (fin.is_open() and fout.is_open())
      fout << find.rdbuf();
  }
  */
  

  // handles the includes
  // .. (copy all the verilog file in the folder), this has to be os independent
  if (vlg_include_files_path.size() != 0) {
    // copy the files and specify the -I commandline to the run.sh
    for (auto&& include_path : vlg_include_files_path)
      os_portable_copy_dir(include_path, _output_path);
  }

} // Export_modify_verilog

// Export problem for getting the smt of the wrapper
void VlgSglTgtGen_Yosys::Export_problem_design_smt(const std::string& extra_name) {
  // should only be used when forcing reset (no inv syn).
  ILA_ASSERT( not _vtg_config.ForceInstCheckReset );

  if (_problems.assertions.size() == 0) {
    ILA_ERROR << "Nothing to prove, no assertions inserted!";
    return;
  }

  yosys_prob_fname = extra_name;

  std::ofstream fout(os_portable_append_dir(_output_path, extra_name));
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing file: "
              << os_portable_append_dir(_output_path, extra_name);
    return;
  }

  std::string write_smt2_options;

  write_smt2_options += " -mem -bv -wires";

  ILA_ASSERT(_vtg_config.YosysSmtStateSort == vtg_config_t::DataSort)
    << "Not implemented: Yosys inv-syn for stbv/uf, future work.";
  ILA_ASSERT(not _vtg_config.YosysSmtArrayForRegFile)
    << "Not supporting array in Yosys inv-syn. Future work.";

  write_smt2_options += " -stdt";


  /*
  switch(_vtg_config.YosysSmtStateSort) {
    case vtg_config_t::DataSort: write_smt2_options += " -stdt"; break;
    case vtg_config_t::BitVec: write_smt2_options += " -stbv"; 
      ILA_ERROR_IF(_vtg_config.YosysSmtArrayForRegFile)
        << "Bitvector SMT encoding is not compatible w. option YosysSmtArrayForRegFile";
      break;
    case vtg_config_t::UnintepretedFunc: break; // do nothing
    default: ILA_ERROR << "Unknown option for YosysSmtStateSort option";
  }*/


  fout << "read_verilog -sv "<<top_file_name<< std::endl;
  fout << "prep -top "<<top_mod_name<<std::endl;
  fout << yosysGenerateSmtScript_wo_Array;

  // // not supporting the arrays
  //if(_vtg_config.YosysSmtArrayForRegFile)
  //  fout << yosysGenerateSmtScript_w_Array;
  //else
  //  fout << yosysGenerateSmtScript_wo_Array;

  fout << "write_smt2"<<write_smt2_options
    <<    "__wrapper_"
        + os_portable_remove_file_name_extension(top_file_name)
        + ".smt2";
} // Export_problem_design_smt



// Export script for getting the smt of the wrapper
void VlgSglTgtGen_Yosys::Export_script_design_smt(const std::string& script_name) {
  // should not be used when forcing reset (no inv syn).
  ILA_ASSERT( not _vtg_config.ForceInstCheckReset );

  yosys_run_script_name = script_name;

  auto fname = os_portable_append_dir(_output_path, script_name);
  std::ofstream fout(fname);
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing to file:" << fname;
    return;
  }
  fout << "#!/bin/bash" << std::endl;

  std::string yosys = "yosys";

  // no need, copy is good enough
  // if(vlg_include_files_path.size() != 0)
  //  options += " -I./";

  if (not _vtg_config.YosysPath.empty())
    yosys = os_portable_append_dir(_vtg_config.YosysPath, yosys);

  ILA_ASSERT (yosys_prob_fname != "");
  fout << yosys << " "<< yosys_prob_fname  << std::endl;

} // Export_script_smt

// generate smt encoding for the wrapper, return true if success
bool VlgSglTgtGen_Yosys::Gen_wrapper_smt() const {
  ILA_ASSERT(yosys_run_script_name != "");

  auto script_path = 
    os_portable_append_dir(_output_path, yosys_run_script_name);

  bool succeeded = 
    os_portable_execute_shell( script_path );

  ILA_ERROR_IF(not succeeded) << "Cannot execute script:"<<script_path;

  return succeeded;
} // Gen_wrapper_smt

/// Need the smt info, for the final SMT2 generation
/// Take care of exporting all of a single target
void VlgSglTgtGen_Yosys::ExportAll(const std::string& wrapper_name,
                        const std::string& ila_vlg_name,
                        const std::string& script_name,
                        const std::string& extra_name,
                        const std::string& mem_name,
                        const YosysDesignSmtInfo& smt_info) {

  ILA_ASSERT(not has_flush) << "not implemented: future work.";

  if ( _vtg_config.ForceInstCheckReset ) {
    ILA_ERROR
      << "API misuse: when forcing reset state, "
      << "please use the other ExportAll function "
      << "that has no smt_info in its arg.";
    return;
  }

  PreExportProcess();
  if (os_portable_mkdir(_output_path) == false)
    ILA_WARN << "Cannot create output directory:" << _output_path;
  // you don't need to worry about the path and names
  Export_wrapper(wrapper_name);
  if (target_type == target_type_t::INSTRUCTIONS) //  inv\instruction
    Export_ila_vlg(ila_vlg_name); // this has to be after Export_wrapper

  // for Jasper, this will be put to multiple files
  // for CoSA & Yosys, this will be put after the wrapper file (wrapper.v)
  Export_modify_verilog();        // this must be after Export_wrapper
  Export_mem(mem_name);

  // you need to create the map function -- 
  Export_problem_design_smt(extra_name); // the gensmt.ys 
  
  Export_script_design_smt(script_name); // the 

  // execute the script and get the smt
  if(not Gen_wrapper_smt()) {
    ILA_ERROR 
      << "Cannot generate SMT-LIB2 encoding for wrapper. "
      << "Quit invariant synthesis.";
    return;
  }

  // extract the state info --- will be done in Export_problem

  Export_problem(extra_name, smt_info);

  Export_script(script_name);

  ..// todo :
  // 1. change the template for dual
  // 2. gen map function
  // 3. make sure the assumptions and assertions are used in good ways
}
                         
/// Deprecation of the one without smt info
void VlgSglTgtGen_Yosys::ExportAll(const std::string& wrapper_name,
                        const std::string& ila_vlg_name,
                        const std::string& script_name,
                        const std::string& extra_name,
                        const std::string& mem_name) {

  if( not _vtg_config.ForceInstCheckReset ){
    ILA_ERROR
      << "API misuse: when not forcing reset state, "
      << "please use the other ExportAll function "
      << "that HAS smt_info in its arg.";
    return;
  }

  ILA_ASSERT(false) 
   << "Implementation bug: future work.";

  .. // todo : please check the following code to ensure correctness!
  PreExportProcess();
  if (os_portable_mkdir(_output_path) == false)
    ILA_WARN << "Cannot create output directory:" << _output_path;
  // you don't need to worry about the path and names
  Export_wrapper(wrapper_name);
  if (target_type == target_type_t::INSTRUCTIONS)
    Export_ila_vlg(ila_vlg_name); // this has to be after Export_wrapper

  // for Jasper, this will be put to multiple files
  // for CoSA & Yosys, this will be put after the wrapper file (wrapper.v)
  Export_modify_verilog();        // this must be after Export_wrapper
  Export_mem(mem_name);

  // you need to create the map function -- 
  Export_problem(extra_name); // the gensmt.ys 
  
  Export_script(script_name);
}



YosysDesignSmtInfo::pos_name_map_t 
VlgSglTgtGen_Yosys::extract_state_info_from_smt(const std::string &smt_file_path)
{

  std::ifstream smt_fin(smt_file_path);
  if(not smt_fin.is_open()) {
    ILA_ERROR << "Cannot read SMT-LIB2:" << smt_file_path;
    return YosysDesignSmtInfo::pos_name_map_t(); // return an empty one
  }
  // readline- until
  std::string line_in;
  bool in_data_type = false;
  unsigned argNo = 0;

  YosysDesignSmtInfo::pos_name_map_t ret;

  while (std::getline(smt_fin, line_in)) {
    if( line_in.find("(declare-datatype") == 0 ) {
      ILA_ASSERT(argNo == 0) << "Implementation bug.";
      in_data_type = true;
    } else if (line_in.find(")))") == 0) {
      ILA_ERROR_IF(argNo <= 1) << "No state has been extracted from smt";
      ILA_ASSERT(in_data_type);
      break; // okay we are done
    } else if (in_data_type) {
      std::string ref_name;
      {
        auto pos = line_in.find("(");
        ILA_ASSERT(pos != line_in.npos);
        ++ pos;
        auto epos = line_in.find(" ", pos);
        ILA_ASSERT(epos != line_in.npos);
        ref_name = line_in.substr(pos,epos);
      }

      std::string state_name;
      if(argNo == 0) {
        state_name = "is_no_use";
      } else {
        auto pos = line_in.find("; \\");
        pos += 3;
        state_name = line_in.substr(pos); // till the end
      }
      ret.insert( { state_name , sig_tp_state_t(ref_name, state_name)} );
      argNo ++;
    }
  }

  ILA_ASSERT(in_data_type); // we must have got the datatype o.w. it is a bug
  return ret;
}

}; // namespace ilang
