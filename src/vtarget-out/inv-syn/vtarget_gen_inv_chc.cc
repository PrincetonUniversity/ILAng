/// \file Source of generating Yosys accepted problem, vlg, mem, script
/// the inv-syn related HC generation is located in inv_syn.cc
// --- Hongce Zhang

#include <ilang/config.h>
#ifdef INVSYN_INTERFACE

#include <algorithm>
#include <fstream>
#include <ilang/config.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/absmem.h>
#include <ilang/vtarget-out/inv-syn/vtarget_gen_inv_chc.h>
#include <iostream>

namespace ilang {

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"

// hierarchy --> opt may not be useful
// mux undef may be useful?

// initialize templates
static std::string chcGenerateSmtScript_wo_Array = R"***(
hierarchy -check
proc
opt
opt_expr -mux_undef
opt
opt
%flatten%
%setundef -undriven -init -expose%
sim -clock clk -reset rst -rstlen %rstlen% -n %cycle% -w %module%
memory -nordff
proc
opt;;
)***";

// should not be used
static std::string chcGenerateSmtScript_w_Array = R"***(
hierarchy -check
proc
opt
opt_expr -mux_undef
opt
opt
%flatten%
%setundef -undriven -init -expose%
sim -clock clk -reset rst -rstlen %rstlen% -n %cycle% -w %module%
memory_dff -wr_only
memory_collect;
memory_unpack
splitnets -driver
opt;;
memory_collect;
pmuxtree
proc
opt;;
)***";

static std::string inv_syn_tmpl_datatypes = R"***(
;----------------------------------------
;  Single Inductive Invariant Synthesis
;  Generated from ILAng
;----------------------------------------
%(set-option :fp.engine spacer)%

%%

(declare-rel INV (|%1%_s|))
(declare-rel fail ())

(declare-var |__S__| |%1%_s|)
(declare-var |__S'__| |%1%_s|)

; --------------------------------
; note if you want it a bit faster
; if can try removing wrapper-u in rule 1
; or remove the assume previous invariants
; --------------------------------

; init => inv
(rule (=> 
  <!>(and<!>
  (|%1%_i| |__S__|)
  <!ui>(|%1%_u| |__S__|)<!>
  <!>(|%1%_h| |__S__|)<!>
  <!>)<!>
  (INV |__S__|)))

; inv /\ T => inv
(rule (=> (and 
  (INV |__S__|) 
  (|%1%_u| |__S__|)
  <!us>(|%1%_u| |__S'__|)<!>
  <!>(|%1%_h| |__S__|)<!>
  <!>(|%1%_h| |__S'__|)<!>
  (|%1%_t| |__S__| |__S'__|)) 
  (INV |__S'__|)))

; inv /\ ~p => \bot
(rule (=> (and 
  (INV |__S__|) 
  <!ue>(|%1%_u| |__S__|)<!>
  <!>(|%1%_h| |__S__|)<!>
  (not (|%1%_a| |__S__|)))
  fail))

; (query fail :print-certificate true)

)***";

static std::string inv_syn_tmpl_wo_datatypes = R"***(
;----------------------------------------
;  Single Inductive Invariant Synthesis
;  Generated from ILAng
;----------------------------------------
%(set-option :fp.engine spacer)%

%%

(declare-rel INV %WrapperDataType%)
(declare-rel fail ())


%State%
%StatePrime%
;(declare-var |__S__state| Type)
;(declare-var |__S'__state| Type)

; same for flattened

; init => inv
(rule (=> 
  <!>(and<!>
  (|%WrapperName%_i| %Ss%) 
  <!ui>(|%WrapperName%_u| %Ss%)<!>
  <!>(|%WrapperName%_h| %Ss%)<!> 
  <!>)<!>
  (INV %Ss%)))

; inv /\ T => inv
(rule (=> (and 
  (INV %Ss%) 
  (|%WrapperName%_u| %Ss%) 
  <!us>(|%WrapperName%_u| %Sps%)<!> 
  <!>(|%WrapperName%_h| %Ss%)<!>
  <!>(|%WrapperName%_h| %Sps%)<!>
  (|%WrapperName%_t| %Ss% %Sps%)) 
  (INV %Sps%)))

; inv /\ ~p => \bot
(rule (=> (and 
  (INV %Ss%)
  <!ue>(|%WrapperName%_u| %Ss%)<!> 
  <!>(|%WrapperName%_h| %Ss%)<!>
  (not (|%WrapperName%_a| %Ss%))) 
  fail))

; (query fail :print-certificate true)

)***";

static std::string RewriteDatatypeChc(const std::string& tmpl,
                                      const std::vector<smt::state_var_t>& dt,
                                      const std::string& wrapper_mod_name);

VlgSglTgtGen_Chc::~VlgSglTgtGen_Chc() {}

VlgSglTgtGen_Chc::VlgSglTgtGen_Chc(
    const std::string&
        output_path, // will be a sub directory of the output_path of its parent
    const InstrPtr& instr_ptr, // which could be an empty pointer, and it will
                               // be used to verify invariants
    const InstrLvlAbsPtr& ila_ptr, const VerilogGenerator::VlgGenConfig& config,
    nlohmann::json& _rf_vmap, nlohmann::json& _rf_cond,
    VlgTgtSupplementaryInfo& _sup_info, VerilogInfo* _vlg_info_ptr,
    const std::string& vlg_mod_inst_name, const std::string& ila_mod_inst_name,
    const std::string& wrapper_name,
    const std::vector<std::string>& implementation_srcs,
    const std::vector<std::string>& implementation_include_path,
    const vtg_config_t& vtg_config, backend_selector vbackend,
    synthesis_backend_selector sbackend, const target_type_t& target_tp,
    advanced_parameters_t* adv_ptr, bool GenerateProof, _chc_target_t chctarget)
    : VlgSglTgtGen(output_path, instr_ptr, ila_ptr, config, _rf_vmap, _rf_cond,
                   _sup_info, _vlg_info_ptr, vlg_mod_inst_name,
                   ila_mod_inst_name, wrapper_name, implementation_srcs,
                   implementation_include_path, vtg_config, vbackend, target_tp,
                   adv_ptr),
      s_backend(sbackend), generate_proof(GenerateProof),
      has_cex(adv_ptr && adv_ptr->_cex_obj_ptr), chc_target(chctarget) {

  ILA_CHECK(vbackend == backend_selector::YOSYS)
      << "Only support using yosys for chc target";

  ILA_CHECK(chctarget == _chc_target_t::CEX)
      << "Bug: VlgSglTgtGen_Chc should only be used for CEX";

  ILA_CHECK(target_tp == target_type_t::INV_SYN_DESIGN_ONLY)
      << "for cex chc, target type must be INV_SYN_DESIGN_ONLY: " << target_tp;
  ILA_CHECK(has_cex) << "for cex chc, cex must be provided!";
  ILA_CHECK(_vtg_config.YosysSmtStateSort == _vtg_config.Datatypes)
      << "invariant synthesis only supports datatypes state encoding.";

  ILA_CHECK(sbackend == synthesis_backend_selector::GRAIN or
             sbackend == synthesis_backend_selector::Z3)
      << "Unknown synthesis backend:" << sbackend;

  if (sbackend == synthesis_backend_selector::GRAIN)
    ILA_CHECK(vtg_config.YosysSmtFlattenDatatype)
        << "For Grain, datatype must be flattened!";

  ILA_CHECK(_vtg_config.YosysSmtFlattenHierarchy)
      << "Currently implementation only supports extract invariants from "
         "flattened hierarchy.";
}

/// Add an assumption
void VlgSglTgtGen_Chc::add_a_direct_assumption(const std::string& aspt,
                                               const std::string& dspt) {
  _problems.assumptions[dspt].exprs.push_back(aspt);
}
/// Add an assertion
void VlgSglTgtGen_Chc::add_a_direct_assertion(const std::string& asst,
                                              const std::string& dspt) {
  _problems.assertions[dspt].exprs.push_back(asst);
}

void VlgSglTgtGen_Chc::PreExportProcess() {

  std::string all_assert_wire_content;
  std::string all_assume_wire_content;

  ILA_CHECK(target_type == target_type_t::INV_SYN_DESIGN_ONLY);
  ILA_ERROR_IF(_problems.assertions.size() != 1) << "BUG in cex extract";

  // you need to add assumptions as well
  for (auto&& pbname_prob_pair : _problems.assumptions) {
    const auto& prbname = pbname_prob_pair.first;
    const auto& prob = pbname_prob_pair.second;
    ILA_DLOG("VlgSglTgtGen_Chc.PreExportProcess")
        << "Adding assumption:" << prbname;

    for (auto&& p : prob.exprs) {
      vlg_wrapper.add_stmt("assume property (" + p + "); //" + prbname + "\n");
      if (all_assume_wire_content.empty())
        all_assume_wire_content = "(" + p + ")";
      else
        all_assume_wire_content += "&& (" + p + ")";
    } // for prob.exprs
  }   // for _problems.assumption

  bool first = true;
  // this is to check given invariants
  for (auto&& pbname_prob_pair : _problems.assertions) {
    const auto& prbname = pbname_prob_pair.first;
    const auto& prob = pbname_prob_pair.second;

    // ILA_CHECK(prbname == "cex_nonreachable_assert")
    //  << "BUG: assertion can only be cex reachability queries.";
    // sanity check, should only be invariant's related asserts

    for (auto&& p : prob.exprs) {
      vlg_wrapper.add_stmt("assert property (" + p + "); //" + prbname + "\n");
      // there should be only one expression (for cex target)
      // ILA_CHECK(all_assert_wire_content.empty());
      if (first)
        all_assert_wire_content = p;
      else
        all_assert_wire_content += " && " + p;

      first = false;
    } // for expr
  }   // for problem
  // add assert wire (though no use : make sure will not optimized away)
  ILA_CHECK(!all_assert_wire_content.empty()) << "no property to check!";

  vlg_wrapper.add_wire("__all_assert_wire__", 1, true);
  vlg_wrapper.add_output("__all_assert_wire__", 1);
  vlg_wrapper.add_assign_stmt("__all_assert_wire__", all_assert_wire_content);

  if (!all_assume_wire_content.empty()) {
    vlg_wrapper.add_wire("__all_assume_wire__", 1, true);
    vlg_wrapper.add_output("__all_assume_wire__", 1);
    vlg_wrapper.add_assign_stmt("__all_assume_wire__", all_assume_wire_content);
  }
} // PreExportProcess

/// export the script to run the verification :
/// like "yosys gemsmt.ys"
void VlgSglTgtGen_Chc::Export_script(const std::string& script_name) {
  chc_run_script_name = script_name;
  /// TODO: BUG: modify this : use z3/freqHorn

  auto fname = os_portable_append_dir(_output_path, script_name);
  std::ofstream fout(fname);
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing to file:" << fname;
    return;
  }
  fout << "#!/bin/bash" << std::endl;
  // fout << "trap \"trap - SIGTERM && kill -- -$$\" SIGINT SIGTERM"<<std::endl;

  std::string runable;
  std::string options;
  std::string redirect;
  if (s_backend == synthesis_backend_selector::Z3) {
    runable = "z3";
    if (!_vtg_config.Z3Path.empty())
      runable = os_portable_append_dir(_vtg_config.Z3Path, runable);
  } else if (s_backend == synthesis_backend_selector::GRAIN) {
    runable = "bv";
    if (!_vtg_config.GrainPath.empty())
      runable = os_portable_append_dir(_vtg_config.GrainPath, runable);
    for (auto&& op : _vtg_config.GrainOptions)
      options += " " + op;

    if (_vtg_config.GrainHintsUseCnfStyle) {
      ILA_ERROR_IF(!S_IN(" --cnf ", options) && !S_IN(" --grammar ", options))
          << "You must provide grammar in Grain options!";
    } else {
      ILA_ERROR_IF(!S_IN(" --grammar-file=", options))
          << "You must provide grammar in Grain options!";
      options += " --chc-file=\"" + chc_prob_fname + "\"";
    }

    redirect = " 2> ../grain.result";
  }

  if (chc_prob_fname != "") {
    if (_vtg_config.GrainHintsUseCnfStyle ||
        s_backend == synthesis_backend_selector::Z3)
      fout << runable << options << " " << chc_prob_fname << redirect
           << std::endl;
    else
      fout << runable << options << redirect << std::endl;
  } else
    fout << "echo 'Nothing to check!'" << std::endl;
} // Export_script

/// For jasper, this means do nothing, for yosys, you need to add (*keep*)
void VlgSglTgtGen_Chc::Export_modify_verilog() {
  // collect all locations: filename -> lineno
  // open, read, count and write
  // if it is a port name, we will ask user to specify its upper level
  // signal name
  VerilogModifier vlg_mod(vlg_info_ptr,
                          static_cast<VerilogModifier::port_decl_style_t>(
                              _vtg_config.PortDeclStyle),
                          _vtg_config.CosaAddKeep,
                          supplementary_info.width_info);

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

  // auto tmp_fn = os_portable_append_dir(_output_path, tmp_design_file);
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

  // handles the includes
  // .. (copy all the verilog file in the folder), this has to be os independent
  if (vlg_include_files_path.size() != 0) {
    // copy the files and specify the -I commandline to the run.sh
    for (auto&& include_path : vlg_include_files_path)
      os_portable_copy_dir(include_path, _output_path);
  }

} // Export_modify_verilog

/// export the memory abstraction (implementation)
/// Yes, this is also implementation specific, (jasper may use a different one)
void VlgSglTgtGen_Chc::Export_mem(const std::string& mem_name) {
  // we will ignore the mem_name

  auto outfn = os_portable_append_dir(_output_path, top_file_name);
  std::ofstream fout(outfn, std::ios_base::app); // append

  VlgAbsMem::OutputMemFile(fout,
                           _vtg_config.VerificationSettingAvoidIssueStage);
}

// export the chc file
void VlgSglTgtGen_Chc::Export_problem(const std::string& extra_name) {
  // used by export script!
  chc_prob_fname = extra_name;

  // first generate a temporary smt
  // and extract from it the necessary info

  // first generate a temporary smt
  // and extract from it the necessary info
  // this is the CHC-style thing
  design_only_gen_smt(
      os_portable_append_dir(_output_path, "__design_smt.smt2"),
      os_portable_append_dir(_output_path, "__gen_smt_script.ys"));
  // if (_vtg_config.YosysSmtStateSort == _vtg_config.DataSort)
  convert_smt_to_chc_datatype(
      os_portable_append_dir(_output_path, "__design_smt.smt2"),
      os_portable_append_dir(_output_path,
                             s_backend == synthesis_backend_selector::GRAIN
                                 ? "grain_prep.txt"
                                 : extra_name));

  // for grain : convert wrapper# --> w wrapper_ --> w
  if (s_backend == synthesis_backend_selector::GRAIN) {
    std::ifstream fin(os_portable_append_dir(_output_path, "grain_prep.txt"));
    std::ofstream fout(os_portable_append_dir(_output_path, extra_name));
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read from : "
                << os_portable_append_dir(_output_path, "grain_prep.txt");
      return;
    }
    if (!fout.is_open()) {
      ILA_ERROR << "Cannot write to : "
                << os_portable_append_dir(_output_path, extra_name);
      return;
    }
    std::string line;
    while (std::getline(fin, line)) {
      fout << ReplaceAll(ReplaceAll(line, "wrapper#", "w"), "wrapper_", "w_")
           << "\n";
    }
  }

} // Export_problem

std::shared_ptr<smt::YosysSmtParser>
VlgSglTgtGen_Chc::GetDesignSmtInfo() const {
  return design_smt_info;
}

void VlgSglTgtGen_Chc::ExportAll(const std::string& wrapper_name, // wrapper.v
                                 const std::string& ila_vlg_name, // no use
                                 const std::string& script_name,  // the run.sh
                                 const std::string& extra_name,   // the chc
                                 const std::string& mem_name) {   // no use

  PreExportProcess();

  if (os_portable_mkdir(_output_path) == false)
    ILA_WARN << "Cannot create output directory:" << _output_path;

  // you don't need to worry about the path and names
  Export_wrapper(wrapper_name);
  // design only
  // if (target_type == target_type_t::INSTRUCTIONS)
  //  Export_ila_vlg(ila_vlg_name); // this has to be after Export_wrapper

  // for Jasper, this will be put to multiple files
  // for CoSA & Yosys, this will be put after the wrapper file (wrapper.v)
  Export_modify_verilog(); // this must be after Export_wrapper
  Export_mem(mem_name);

  // you need to create the map function --
  Export_problem(extra_name); // the gensmt.ys

  Export_script(script_name);
}

/// generate the wrapper's smt first
void VlgSglTgtGen_Chc::design_only_gen_smt(const std::string& smt_name,
                                           const std::string& ys_script_name) {

  auto ys_output_full_name =
      os_portable_append_dir(_output_path, "__yosys_exec_result.txt");
  { // export to ys_script_name
    std::ofstream ys_script_fout(ys_script_name);

    std::string write_smt2_options =
        " -mem -bv "; // future work : -stbv, or nothing
    // if (_vtg_config.YosysSmtStateSort == _vtg_config.DataSort)
    write_smt2_options += "-stdt ";
    // else if (_vtg_config.YosysSmtStateSort == _vtg_config.BitVec)
    //  write_smt2_options += "-stbv ";
    // else
    //  ILA_CHECK(false) << "Unsupported smt state sort encoding:" <<
    //  _vtg_config.YosysSmtStateSort;

    ys_script_fout << "read_verilog -sv "
                   << os_portable_append_dir(_output_path, top_file_name)
                   << std::endl;
    ys_script_fout << "prep -top " << top_mod_name << std::endl;

    auto chcGenSmtTemplate = _vtg_config.ChcWordBlastArray
                                 ? chcGenerateSmtScript_wo_Array
                                 : chcGenerateSmtScript_w_Array;

    ys_script_fout << ReplaceAll(
        ReplaceAll(
            ReplaceAll(
                ReplaceAll(ReplaceAll(chcGenSmtTemplate, "%flatten%",
                                      _vtg_config.YosysSmtFlattenHierarchy
                                          ? "flatten;"
                                          : ""),
                           "%setundef -undriven -init -expose%",
                           _vtg_config.YosysUndrivenNetAsInput
                               ? "setundef -undriven -init -expose"
                               : ""),
                "%rstlen%",
                std::to_string(
                    supplementary_info.cosa_yosys_reset_config.reset_cycles)),
            "%cycle%",
            std::to_string(
                supplementary_info.cosa_yosys_reset_config.reset_cycles)),
        "%module%", top_mod_name);

    ys_script_fout << "write_smt2" << write_smt2_options << smt_name;
  } // finish writing

  std::string yosys = "yosys";

  if (!_vtg_config.YosysPath.empty())
    yosys = os_portable_append_dir(_vtg_config.YosysPath, yosys);

  // execute it
  std::vector<std::string> cmd;
  cmd.push_back(yosys);
  cmd.push_back("-s");
  cmd.push_back(ys_script_name);
  auto res = os_portable_execute_shell(cmd, ys_output_full_name);
  ILA_ERROR_IF(res.failure != res.NONE) << "Executing Yosys failed!";
  ILA_ERROR_IF(res.failure == res.NONE && res.ret != 0)
      << "Yosys returns error code:" << res.ret;
} // design_only_gen_smt

// currently we don't support prepresenting state using a bit vector
#if 0
void VlgSglTgtGen_Chc::convert_smt_to_chc_bitvec(
    const std::string & smt_fname, const std::string & chc_fname, 
    const std::string & wrapper_mod_name) {
  
  std::stringstream ibuf;
  { // read file
    std::ifstream smt_fin( smt_fname );
    if(! smt_fin.is_open()) {
      ILA_ERROR << "Cannot read from " << smt_fname;
      return;
    }
    ibuf << smt_fin.rdbuf();
  } // end read file

  std::string smt_converted;
  smt_converted = ibuf.str();

  std::string chc;

  chc = ReplaceAll(inv_syn_tmpl_datatypes, 
    "%(set-option :fp.engine spacer)%" ,
    s_backend == synthesis_backend_selector::GRAIN ? "" : "(set-option :fp.engine spacer)");
  chc = ReplaceAll(chc, "<!>(|%1%_h| |__BI__|)<!>", _vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%1%_h| |__BI__|)");
  chc = ReplaceAll(chc, "<!>(|%1%_h| |__I__|)<!>" , _vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%1%_h| |__I__|)");
  chc = ReplaceAll(chc, "<!>(|%1%_h| |__S__|)<!>" , _vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%1%_h| |__S__|)");
  chc = ReplaceAll(chc, "<!>(|%1%_h| |__S'__|)<!>", _vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%1%_h| |__S'__|)");
  chc = ReplaceAll(chc,"%1%", wrapper_mod_name);
  chc = ReplaceAll(chc, "%%", smt_converted );

  { // (query fail :print-certificate true)
    if (generate_proof)
      chc += "\n(query fail :print-certificate true)\n";
    else
      chc += "\n(query fail)\n";
  }

  { // write file
    std::ofstream chc_fout(chc_fname);
    if (! chc_fout.is_open()) {
      ILA_ERROR << "Error writing to : "<< chc_fname;
      return;
    }
    chc_fout << chc;
  } // end write file
}
#endif

void VlgSglTgtGen_Chc::convert_smt_to_chc_datatype(
    const std::string& smt_fname, const std::string& chc_fname) {

  std::stringstream ibuf;
  { // read file
    std::ifstream smt_fin(smt_fname);
    if (!smt_fin.is_open()) {
      ILA_ERROR << "Cannot read from " << smt_fname;
      return;
    }
    ibuf << smt_fin.rdbuf();
  } // end read file

  std::string smt_converted;
  design_smt_info = std::make_shared<smt::YosysSmtParser>(ibuf.str());
  if (_vtg_config.YosysSmtFlattenDatatype) {
    design_smt_info->BreakDatatypes();
    // smt_rewriter.AddNoChangeStateUpdateFunction();
    smt_converted = design_smt_info->Export();
  } else {
    smt_converted = ibuf.str();
  }

  std::string wrapper_mod_name =
      design_smt_info->get_module_def_orders().back();
  // construct the template

  std::string chc;
  if (_vtg_config.YosysSmtFlattenDatatype) {
    const auto& datatype_top_mod =
        design_smt_info->get_module_flatten_dt(wrapper_mod_name);
    auto tmpl = ReplaceAll(inv_syn_tmpl_wo_datatypes,
                           "%(set-option :fp.engine spacer)%",
                           s_backend == synthesis_backend_selector::GRAIN
                               ? ""
                               : "(set-option :fp.engine spacer)");

    tmpl = ReplaceAll(
        tmpl, "<!ui>(|%WrapperName%_u| %Ss%)<!>",
        _vtg_config.ChcAssumptionsReset ? "(|%WrapperName%_u| %Ss%)" : "");
    tmpl = ReplaceAll(
        tmpl, "<!us>(|%WrapperName%_u| %Sps%)<!>",
        _vtg_config.ChcAssumptionNextState ? "(|%WrapperName%_u| %Sps%)" : "");
    tmpl = ReplaceAll(tmpl, "<!ue>(|%WrapperName%_u| %Ss%)<!>",
                      _vtg_config.ChcAssumptionEnd ? "(|%WrapperName%_u| %Ss%)"
                                                   : "");
    tmpl = ReplaceAll(
        tmpl, "<!>(|%WrapperName%_h| %Ss%)<!>",
        _vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%WrapperName%_h| %Ss%)");
    tmpl = ReplaceAll(tmpl, "<!>(|%WrapperName%_h| %Sps%)<!>",
                      _vtg_config.YosysSmtFlattenHierarchy
                          ? ""
                          : "(|%WrapperName%_h| %Sps%)");
    tmpl = ReplaceAll(tmpl, "<!>(and<!>",
                      !_vtg_config.ChcAssumptionsReset &&
                              _vtg_config.YosysSmtFlattenHierarchy
                          ? ""
                          : "(and");
    tmpl = ReplaceAll(tmpl, "<!>)<!>",
                      !_vtg_config.ChcAssumptionsReset &&
                              _vtg_config.YosysSmtFlattenHierarchy
                          ? ""
                          : ")");

    chc = RewriteDatatypeChc(tmpl, datatype_top_mod, wrapper_mod_name);

    chc = ReplaceAll(chc, "%%", smt_converted);

  } else {
    chc = ReplaceAll(inv_syn_tmpl_datatypes, "%(set-option :fp.engine spacer)%",
                     s_backend == synthesis_backend_selector::GRAIN
                         ? ""
                         : "(set-option :fp.engine spacer)");

    chc =
        ReplaceAll(chc, "<!ui>(|%1%_u| |__S__|)<!>",
                   _vtg_config.ChcAssumptionsReset ? "(|%1%_u| |__S__|)" : "");
    chc = ReplaceAll(chc, "<!us>(|%1%_u| |__S'__|)<!>",
                     _vtg_config.ChcAssumptionNextState ? "(|%1%_u| |__S'__|)"
                                                        : "");
    chc = ReplaceAll(chc, "<!ue>(|%1%_u| |__S__|)<!>",
                     _vtg_config.ChcAssumptionEnd ? "(|%1%_u| |__S__|)" : "");
    chc = ReplaceAll(
        chc, "<!>(|%1%_h| |__S__|)<!>",
        _vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%1%_h| |__S__|)");
    chc = ReplaceAll(
        chc, "<!>(|%1%_h| |__S'__|)<!>",
        _vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%1%_h| |__S'__|)");
    chc = ReplaceAll(chc, "<!>(and<!>",
                     !_vtg_config.ChcAssumptionsReset &&
                             _vtg_config.YosysSmtFlattenHierarchy
                         ? ""
                         : "(and");
    chc = ReplaceAll(chc, "<!>)<!>",
                     !_vtg_config.ChcAssumptionsReset &&
                             _vtg_config.YosysSmtFlattenHierarchy
                         ? ""
                         : ")");
    chc = ReplaceAll(chc, "%1%", wrapper_mod_name);
    chc = ReplaceAll(chc, "%%", smt_converted);
  } // end of ~_vtg_config.YosysSmtFlattenDatatype -- no convert

  { // (query fail :print-certificate true)
    if (generate_proof)
      chc += "\n(query fail :print-certificate true)\n";
    else
      chc += "\n(query fail)\n";
  }

  { // write file
    std::ofstream chc_fout(chc_fname);
    if (!chc_fout.is_open()) {
      ILA_ERROR << "Error writing to : " << chc_fname;
      return;
    }
    chc_fout << chc;
  } // end write file

} // convert_smt_to_chc_datatype

// %WrapperName%
// %WrapperDataType%
// %BeforeInitVar%
// %InitVar%
// %State%
// %StatePrime%
// %BIs% %Is%  %Ss% %Sps%
static std::string RewriteDatatypeChc(const std::string& tmpl,
                                      const std::vector<smt::state_var_t>& dt,
                                      const std::string& wrapper_mod_name) {

  std::string chc = tmpl;

  std::vector<smt::var_type> inv_tps;
  smt::YosysSmtParser::convert_datatype_to_type_vec(dt, inv_tps);
  auto WrapperDataType = smt::var_type::toString(inv_tps);

  // %State%
  // %StatePrime%
  // declare-var s ...
  std::string State;
  std::string StatePrime;
  // %Ss% %Sps%
  std::string Ss;
  std::string Sps;
  bool first = true;

  std::set<std::string> name_set; // avoid repetition
  for (auto&& st : dt) {
    auto st_name = st.verilog_name.back() == '.' || st.verilog_name.empty()
                       ? st.internal_name
                       : st.verilog_name;
    st_name = ReplaceAll(st_name, "|", ""); // remove its ||
    // check no repetition is very important!
    ILA_CHECK(!IN(st_name, name_set)) << "Bug: name repetition!";
    ILA_CHECK(!st._type.is_datatype());
    name_set.insert(st_name);
    auto type_string = st._type.toString();
    State += "(declare-var |S_" + st_name + "| " + type_string + ")\n";
    StatePrime += "(declare-var |S'_" + st_name + "| " + type_string + ")\n";

    if (!first) {
      Ss += " ";
      Sps += " ";
    }
    first = false;
    Ss += "|S_" + st_name + "|";
    Sps += "|S'_" + st_name + "|";
  }
  // Replacement
  chc = ReplaceAll(chc, "%WrapperName%", wrapper_mod_name);
  chc = ReplaceAll(chc, "%WrapperDataType%", WrapperDataType);
  chc = ReplaceAll(chc, "%State%", State);
  chc = ReplaceAll(chc, "%StatePrime%", StatePrime);
  chc = ReplaceAll(chc, "%Ss%", Ss);
  chc = ReplaceAll(chc, "%Sps%", Sps);

  return chc;
} // RewriteDatatypeChc

}; // namespace ilang

#endif // INVSYN_INTERFACE