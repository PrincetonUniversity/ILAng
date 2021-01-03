/// \file Source of generating Yosys accepted problem, vlg, mem, script
/// the inv-syn related HC generation is located in inv_syn.cc
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen_yosys.h>

#include <algorithm>
#include <fstream>
#include <iostream>

#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/absmem.h>

namespace ilang {

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"

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

static std::string chc_tmpl_datatypes = R"***(
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

static std::string chc_tmpl_wo_datatypes = R"***(
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

// yosys template
static std::string abcGenerateAigerWInit_wo_Array = R"***(
read_verilog -formal %topfile%
prep -top %module%
sim -clock clk -reset rst -rstlen %rstlen% -n %cycle% -w %module%
miter -assert %module%
flatten
%setundef -undriven -init -expose%
memory -nordff
opt_clean
techmap
abc -fast -g AND
write_aiger -zinit -map %mapname% %aigname%
write_blif %blifname%
)***";

static std::string abcAigCmdNoGLA = R"***(
  &read %aigname%
  &put
  fold
  pdr {-v -d}
  {inv_min}
  {inv_print -v}
)***";

static std::string abcAigCmdGLA = R"***(
  &read %aigname%
  &gla -T %glatime% -F %glaframe% -v
  &gla_derive
  &put
  dc2 -v
  dc2 -v
  dc2 -v
  dc2 -v
  dc2 -v
  dc2 -v
  dc2 -v
  dc2 -v
  {scorr}
  dc2 -v
  dc2 -v
  dc2 -v
  dc2 -v
  {lcorr}
  dc2 -v
  dc2 -v
  dc2 -v
  dc2 -v
  pdr {-v -d}
  {inv_min}
  {inv_print -v}
)***";

#define IMPLY(a, b) (!(a) || (b))

VlgSglTgtGen_Yosys::~VlgSglTgtGen_Yosys() {}

VlgSglTgtGen_Yosys::VlgSglTgtGen_Yosys(
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
    const target_type_t& target_tp, advanced_parameters_t* adv_ptr,
    _chc_target_t _chc_target)
    : VlgSglTgtGen(output_path, instr_ptr, ila_ptr, config, _rf_vmap, _rf_cond,
                   _sup_info, _vlg_info_ptr, vlg_mod_inst_name,
                   ila_mod_inst_name, wrapper_name, implementation_srcs,
                   implementation_include_path, vtg_config, vbackend, target_tp,
                   adv_ptr),

      s_backend(synthesis_backend_selector(vbackend ^ backend_selector::YOSYS)),
      chc_target(_chc_target) {

  ILA_CHECK(chc_target == _chc_target_t::GENERAL_PROPERTY);

  ILA_CHECK(target_tp == target_type_t::INVARIANTS ||
            target_tp == target_type_t::INSTRUCTIONS)
      << "Unknown target type: " << target_tp;

  ILA_CHECK((vbackend & backend_selector::YOSYS) == backend_selector::YOSYS)
      << "Must use Yosys as vbackend";

  ILA_CHECK(s_backend == synthesis_backend_selector::ABC ||
            s_backend == synthesis_backend_selector::Z3 ||
            s_backend == synthesis_backend_selector::GRAIN ||
            s_backend == synthesis_backend_selector::ELDERICA ||
            s_backend == synthesis_backend_selector::NOSYN);

  ILA_CHECK(IMPLY(s_backend == synthesis_backend_selector::GRAIN,
                  vtg_config.YosysSmtFlattenDatatype &&
                      vtg_config.YosysSmtFlattenHierarchy))
      << "Grain requires not to flatten hierarchy/datatype";

  ILA_CHECK(IMPLY(s_backend == synthesis_backend_selector::ABC,
                  _vtg_config.AbcUseAiger))
      << "Currently only support using AIGER";

  ILA_CHECK(IMPLY(s_backend == synthesis_backend_selector::ABC,
                  vtg_config.YosysSmtFlattenHierarchy))
      << "ABC requires to flatten hierarchy";
  // This is hard-coded in the Yosys script
  // if not flattened, abc will be unhappy

  ILA_CHECK(IMPLY(s_backend == synthesis_backend_selector::ABC,
                  vbackend == backend_selector::ABCPDR));

  ILA_CHECK(IMPLY(s_backend == synthesis_backend_selector::GRAIN,
                  vbackend == backend_selector::GRAIN_SYGUS &&
                      _vtg_config.YosysSmtStateSort == _vtg_config.Datatypes));

  ILA_CHECK(IMPLY(s_backend == synthesis_backend_selector::Z3,
                  vbackend == backend_selector::Z3PDR));

  ILA_CHECK(IMPLY(vbackend == backend_selector::BTOR_GENERIC,
                  s_backend == synthesis_backend_selector::NOSYN));

  ILA_CHECK(s_backend != synthesis_backend_selector::ELDERICA)
      << "Bug : not implemented yet!";

  ILA_CHECK(!(_vtg_config.YosysSmtFlattenDatatype &&
              _vtg_config.YosysSmtStateSort != _vtg_config.Datatypes))
      << "Must use Datatypes to encode state in order to flatten";
} // VlgSglTgtGen_Yosys

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

// PreExportProcess is about how to add assumption/assertions
void VlgSglTgtGen_Yosys::PreExportProcess() {

  std::string all_assert_wire_content;
  std::string all_assume_wire_content;

  // you need to add assumptions as well
  for (auto&& pbname_prob_pair : _problems.assumptions) {
    const auto& prbname = pbname_prob_pair.first;
    const auto& prob = pbname_prob_pair.second;
    ILA_DLOG("VlgSglTgtGen_Yosys.PreExportProcess")
        << "Adding assumption:" << prbname;

    for (auto&& p : prob.exprs) {
      if (all_assume_wire_content.empty())
        all_assume_wire_content = "(" + p + ")";
      else
        all_assume_wire_content += "&& (" + p + ")";
    } // for prob.exprs
  }   // for _problems.assumption

  // this is to check given invariants
  for (auto&& pbname_prob_pair : _problems.assertions) {
    // const auto& prbname = pbname_prob_pair.first;
    const auto& prob = pbname_prob_pair.second;

    // ILA_CHECK(prbname == "cex_nonreachable_assert")
    //  << "BUG: assertion can only be cex reachability queries.";
    // sanity check, should only be invariant's related asserts

    for (auto&& p : prob.exprs) {
      // there should be only one expression (for cex target)
      // ILA_CHECK(all_assert_wire_content.empty());
      if (all_assert_wire_content.empty())
        all_assert_wire_content = p;
      else
        all_assert_wire_content += " && " + p;
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

  if ((_backend & backend_selector::CHC) == backend_selector::CHC) {
    vlg_wrapper.add_stmt(
        "assert property ( __all_assert_wire__ ); // the only assertion \n");
    if (!all_assume_wire_content.empty())
      vlg_wrapper.add_stmt(
          "assume property ( __all_assume_wire__ ); // the only assumption \n");
  } else if (_backend == backend_selector::ABCPDR) {
    if (all_assume_wire_content.empty()) {
      vlg_wrapper.add_stmt(
          "assert property ( __all_assert_wire__ ); // the only assertion \n");
    } else {
      std::string precond;
      ILA_CHECK(
          !(_vtg_config.AbcUseAiger == false &&
            _vtg_config.AbcAssumptionStyle == _vtg_config.AigMiterExtraOutput))
          << "If you don't use aiger, and has assumptions, there is no way to "
             "pass the extra output.";
      if (_vtg_config.AbcAssumptionStyle == _vtg_config.AigMiterExtraOutput) {
        ILA_CHECK(_vtg_config.AbcUseGla == false) << "Cannot use it with GLA";
        vlg_wrapper.add_stmt("assume property (__all_assume_wire__);\n");
      } else {
        vlg_wrapper.add_reg("__all_assumed_reg__", 1);
        vlg_wrapper.add_stmt("always @(posedge clk) begin");
        vlg_wrapper.add_stmt("if (rst) __all_assumed_reg__ <= 0;");
        vlg_wrapper.add_stmt(
            "else if (!__all_assume_wire__) __all_assumed_reg__ <= 1; end");
        precond = "!( __all_assume_wire__ && !__all_assumed_reg__) || ";
      }
      vlg_wrapper.add_stmt("assert property (" + precond +
                           " __all_assert_wire__ ); // the only assertion \n");
    } // all_assume_wire_content has sth. there
  }   // if (_backend == backend_selector::ABCPDR)
  else {
    // same as CHC
    vlg_wrapper.add_stmt(
        "assert property ( __all_assert_wire__ ); // the only assertion \n");
    if (!all_assume_wire_content.empty())
      vlg_wrapper.add_stmt(
          "assume property ( __all_assume_wire__ ); // the only assumption \n");
  }
} // PreExportProcess

/// For jasper, this means do nothing, for yosys, you need to add (*keep*)
void VlgSglTgtGen_Yosys::Export_modify_verilog() {
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
void VlgSglTgtGen_Yosys::Export_mem(const std::string& mem_name) {
  // we will ignore the mem_name

  auto outfn = os_portable_append_dir(_output_path, top_file_name);
  std::ofstream fout(outfn, std::ios_base::app); // append

  VlgAbsMem::OutputMemFile(fout,
                           _vtg_config.VerificationSettingAvoidIssueStage);
}

void VlgSglTgtGen_Yosys::ExportAll(const std::string& wrapper_name, // wrapper.v
                                   const std::string& ila_vlg_name, // no use
                                   const std::string& script_name, // the run.sh
                                   const std::string& extra_name,  // the chc
                                   const std::string& mem_name) {  // no use

  PreExportProcess();

  if (os_portable_mkdir(_output_path) == false)
    ILA_WARN << "Cannot create output directory:" << _output_path;

  // you don't need to worry about the path and names
  Export_wrapper(wrapper_name);
  // design only
  if (target_type == target_type_t::INSTRUCTIONS)
    Export_ila_vlg(ila_vlg_name); // this has to be after Export_wrapper

  // for Jasper, this will be put to multiple files
  // for CoSA & Yosys, this will be put after the wrapper file (wrapper.v)
  Export_modify_verilog(); // this must be after Export_wrapper
  Export_mem(mem_name);

  // you need to create the map function --
  Export_problem(extra_name); // the gensmt.ys

  Export_script(script_name);
}

// ------------------------------------------------------------------
// The above is generic for all
// The followings are backend specific
// ------------------------------------------------------------------

void VlgSglTgtGen_Yosys::Export_script(const std::string& script_name) {
  run_script_name = script_name;

  auto fname = os_portable_append_dir(_output_path, script_name);
  std::ofstream fout(fname);
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing to file:" << fname;
    return;
  }
  fout << "#!/bin/bash" << std::endl;

  std::string runnable;
  std::string options;
  std::string redirect;

  if (s_backend == synthesis_backend_selector::Z3) {
    runnable = "z3";
    if (!_vtg_config.Z3Path.empty())
      runnable = os_portable_append_dir(_vtg_config.Z3Path, runnable);
  } else if (s_backend == synthesis_backend_selector::GRAIN) {
    runnable = "bv";
    if (!_vtg_config.GrainPath.empty())
      runnable = os_portable_append_dir(_vtg_config.GrainPath, runnable);
    for (auto&& op : _vtg_config.GrainOptions)
      options += " " + op;

    if (_vtg_config.GrainHintsUseCnfStyle) {
      ILA_ERROR_IF(!S_IN(" --cnf ", options) && !S_IN(" --grammar ", options))
          << "You must provide grammar in Grain options!";
    } else {
      ILA_ERROR_IF(!S_IN(" --grammar-file=", options))
          << "You must provide grammar in Grain options!";
      options += " --chc-file=\"" + prob_fname + "\"";
    }
    redirect = " 2> ../grain.result";
  } else if (s_backend == synthesis_backend_selector::ABC) {
    runnable = "abc";
    if (!_vtg_config.AbcPath.empty())
      runnable = os_portable_append_dir(_vtg_config.AbcPath, runnable);
    std::string abc_cmd;
    if (_vtg_config.AbcUseGla)
      abc_cmd = abcAigCmdGLA;
    else
      abc_cmd = abcAigCmdNoGLA;

    abc_cmd = ReplaceAll(abc_cmd, "%glatime%",
                         std::to_string(_vtg_config.AbcGlaTimeLimit));
    abc_cmd = ReplaceAll(abc_cmd, "%glaframe%",
                         std::to_string(_vtg_config.AbcGlaFrameLimit));
    abc_cmd = ReplaceAll(abc_cmd, "{scorr}",
                         _vtg_config.AbcUseCorr ? "scorr -v -l -k -F 4" : "");
    abc_cmd = ReplaceAll(abc_cmd, "{lcorr}",
                         _vtg_config.AbcUseCorr ? "lcorr -v" : "");
    abc_cmd = ReplaceAll(abc_cmd, "{inv_min}",
                         _vtg_config.AbcMinimizeInv ? "inv_min -l" : "");
    abc_cmd =
        ReplaceAll(abc_cmd, "{-v -d}",
                   _vtg_config.YosysPropertyCheckShowProof ? "-v -d" : "");
    abc_cmd = ReplaceAll(
        abc_cmd, "{inv_print -v}",
        _vtg_config.YosysPropertyCheckShowProof ? "inv_print -v" : "");

    std::string abc_command_file_name = "abcCmd.txt";
    { // generate abc command
      abc_cmd = ReplaceAll(abc_cmd, "%blifname%", "__aiger_prepare.blif");
      abc_cmd = ReplaceAll(abc_cmd, "%aigname%", prob_fname);
      auto abc_cmd_fname =
          os_portable_append_dir(_output_path, abc_command_file_name);
      std::ofstream abc_cmd_fn(abc_cmd_fname);
      if (!abc_cmd_fn.is_open()) {
        ILA_ERROR << "Error writing to file:" << abc_cmd_fname;
        return;
      }
      abc_cmd_fn << abc_cmd;
    } // generate abc command
    options = " -F " + abc_command_file_name;

  } else if (s_backend == synthesis_backend_selector::ELDERICA) {
    ILA_CHECK(false) << "Not implemented.";
  } else if (s_backend == synthesis_backend_selector::NOSYN) {
    if (!_vtg_config.BtorGenericCmdline.empty()) {
      runnable =
          ReplaceAll(_vtg_config.BtorGenericCmdline, "%btorfile%", prob_fname);
      options = "";
    } else {
      runnable = "echo";
      options = " \"btor file is available as: " + prob_fname + "\"";
    }
  }

  if (prob_fname != "") {
    if (s_backend == synthesis_backend_selector::Z3 ||
        (s_backend == synthesis_backend_selector::GRAIN &&
         _vtg_config.GrainHintsUseCnfStyle))
      fout << runnable << options << " " << prob_fname << redirect << std::endl;
    else // ABC, GRAIN, None
      fout << runnable << options << redirect << std::endl;
  } else
    fout << "echo 'Nothing to check!'" << std::endl;

} // Export_script

std::shared_ptr<smt::YosysSmtParser>
VlgSglTgtGen_Yosys::GetDesignSmtInfo() const {
  ILA_CHECK((_backend & backend_selector::CHC) == backend_selector::CHC &&
            _vtg_config.YosysSmtStateSort == _vtg_config.Datatypes)
      << "Only CHC target with datatypes will generate suitable smt-lib2.";
  ILA_CHECK(design_smt_info != nullptr);
  return design_smt_info;
}

// export the chc file
void VlgSglTgtGen_Yosys::Export_problem(const std::string& extra_name) {
  // used by export script!
  prob_fname = extra_name;
  if (s_backend == synthesis_backend_selector::ABC) {
    generate_aiger(
        os_portable_append_dir(_output_path, "__aiger_prepare.blif"),
        os_portable_append_dir(_output_path, extra_name),
        os_portable_append_dir(_output_path, extra_name + ".map"),
        os_portable_append_dir(_output_path, "__gen_blif_script.ys"));
  } else if (s_backend == synthesis_backend_selector::GRAIN ||
             s_backend == synthesis_backend_selector::Z3) {
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
    // design_smt_info is assigned here in this function

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
  } else if (s_backend == synthesis_backend_selector::ELDERICA)
    ILA_CHECK(false) << "Not implemented.";
  else if (s_backend == synthesis_backend_selector::NOSYN) {
    design_only_gen_btor(
        os_portable_append_dir(_output_path, extra_name),
        os_portable_append_dir(_output_path, "__gen_btor_script.ys"));
  }
  // else: None , Eldarica
} // Export_problem

/// generate the wrapper's btor
void VlgSglTgtGen_Yosys::design_only_gen_btor(
    const std::string& btor_name, const std::string& ys_script_name) {

  auto ys_output_full_name =
      os_portable_append_dir(_output_path, "__yosys_exec_result.txt");
  { // export to ys_script_name
    std::ofstream ys_script_fout(ys_script_name);

    std::string write_btor_options;
    write_btor_options += _vtg_config.BtorAddCommentsInOutputs ? " -v" : "";
    write_btor_options += _vtg_config.BtorSingleProperty ? " -s" : "";

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

    // this is for cosa2, I don't know why it is unhappy, but we need fix this
    // in the long run
    ys_script_fout << "setundef -undriven -zero\n";
    ys_script_fout << "write_btor " << write_btor_options << " " << btor_name;
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

/// generate the wrapper's smt first
void VlgSglTgtGen_Yosys::design_only_gen_smt(
    const std::string& smt_name, const std::string& ys_script_name) {

  auto ys_output_full_name =
      os_portable_append_dir(_output_path, "__yosys_exec_result.txt");
  { // export to ys_script_name
    std::ofstream ys_script_fout(ys_script_name);

    std::string write_smt2_options =
        " -mem -bv "; // future work : -stbv, or nothing
    if (_vtg_config.YosysSmtStateSort == _vtg_config.Datatypes)
      write_smt2_options += "-stdt ";
    else if (_vtg_config.YosysSmtStateSort == _vtg_config.BitVec)
      write_smt2_options += "-stbv ";
    else
      ILA_CHECK(false) << "Unsupported smt state sort encoding:"
                       << _vtg_config.YosysSmtStateSort;

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

// %WrapperName%
// %WrapperDataType%
// %State%
// %StatePrime%
// %Ss% %Sps%
static std::string RewriteDatatypeChc(const std::string& tmpl,
                                      const std::vector<smt::state_var_t>& dt,
                                      const std::string& wrapper_mod_name) {

  std::string chc = tmpl;

  std::vector<smt::var_type> inv_tps;
  smt::YosysSmtParser::convert_datatype_to_type_vec(dt, inv_tps);
  auto WrapperDataType = smt::var_type::toString(inv_tps);

  // %BeforeInitVar%
  // %InitVar%
  // %State%
  // %StatePrime%
  // declare-var s ...
  std::string State;
  std::string StatePrime;
  // %BIs% %Is%  %Ss% %Sps%
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

void VlgSglTgtGen_Yosys::convert_smt_to_chc_datatype(
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
  if (_vtg_config.YosysSmtStateSort == _vtg_config.Datatypes)
    design_smt_info = std::make_shared<smt::YosysSmtParser>(ibuf.str());

  if (_vtg_config.YosysSmtFlattenDatatype) {
    ILA_NOT_NULL(design_smt_info);
    design_smt_info->BreakDatatypes();
    // smt_rewriter.AddNoChangeStateUpdateFunction();
    smt_converted = design_smt_info->Export();
  } else {
    smt_converted = ibuf.str();
  }

  std::string wrapper_mod_name =
      design_smt_info ? design_smt_info->get_module_def_orders().back()
                      : "wrapper";
  // construct the template

  std::string chc;
  if (_vtg_config.YosysSmtFlattenDatatype) {
    ILA_NOT_NULL(design_smt_info);
    const auto& datatype_top_mod =
        design_smt_info->get_module_flatten_dt(wrapper_mod_name);
    auto tmpl =
        ReplaceAll(chc_tmpl_wo_datatypes, "%(set-option :fp.engine spacer)%",
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
    chc = ReplaceAll(chc_tmpl_datatypes, "%(set-option :fp.engine spacer)%",
                     "(set-option :fp.engine spacer)");

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
    if (_vtg_config.YosysPropertyCheckShowProof)
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

/// generate the wrapper's smt first
void VlgSglTgtGen_Yosys::generate_aiger(const std::string& blif_name,
                                        const std::string& aiger_name,
                                        const std::string& map_name,
                                        const std::string& ys_script_name) {

  auto ys_output_full_name =
      os_portable_append_dir(_output_path, "__yosys_exec_result.txt");
  { // export to ys_script_name
    std::ofstream ys_script_fout(ys_script_name);

    ys_script_fout << ReplaceAll(
        ReplaceAll(
            ReplaceAll(
                ReplaceAll(
                    ReplaceAll(
                        ReplaceAll(
                            ReplaceAll(
                                ReplaceAll(abcGenerateAigerWInit_wo_Array,
                                           "%topfile%",
                                           os_portable_append_dir(
                                               _output_path, top_file_name)),
                                "%module%", top_mod_name),
                            "%blifname%", blif_name),
                        "%aigname%", aiger_name),
                    "%mapname%", map_name),
                "%setundef -undriven -init -expose%",
                _vtg_config.YosysUndrivenNetAsInput
                    ? "setundef -undriven -init -expose"
                    : ""),
            "%rstlen%",
            std::to_string(
                supplementary_info.cosa_yosys_reset_config.reset_cycles)),
        "%cycle%",
        std::to_string(
            supplementary_info.cosa_yosys_reset_config.reset_cycles));
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
} // generate_aiger

}; // namespace ilang
