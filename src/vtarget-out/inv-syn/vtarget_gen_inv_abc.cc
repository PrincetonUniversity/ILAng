/// \file Source of generating Yosys accepted problem, vlg, mem, script
/// the inv-syn related HC generation is located in inv_syn.cc
// --- Hongce Zhang

#include <ilang/config.h>
#ifdef INVSYN_INTERFACE

#include <algorithm>
#include <fstream>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/absmem.h>
#include <ilang/vtarget-out/inv-syn/vtarget_gen_inv_abc.h>
#include <iostream>

namespace ilang {

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"

// initialize templates
static std::string abcGenerateSmtScript_wo_Array = R"***(
read_verilog -formal %topfile%
prep -top %module%
flatten
sim -clock clk -reset rst -rstlen %rstlen% -n %cycle% -w %module%
miter -assert %module%
%setundef -undriven -init -expose%
memory -nordff
techmap; opt -fast
write_blif %blifname%
)***";

// flatten before sim to avoid sim's none unique issue
// yosys template
static std::string abcGenerateAigerWInit_wo_Array = R"***(
read_verilog -formal %topfile%
prep -top %module%
flatten
sim -clock clk -reset rst -rstlen %rstlen% -n %cycle% -w %module%
miter -assert %module%
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
  pdr
  {inv_min}
  inv_print -v
)***";

static std::string abcAigCmdGLA = R"***(
  &read %aigname%
  &gla -T 500 -F 200 -v
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
  pdr
  {inv_min}
  inv_print -v
)***";

static std::string abcCmdNoGLA = R"***(
  read_blif %blifname%
  strash
  pdr
  {inv_min}
  inv_print -v
)***";

static std::string abcCmdGLA = R"***(
  read_blif %blifname%
  &get -n
  &gla -T 500 -F 200 -v
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
  pdr
  {inv_min}
  inv_print -v
)***";

VlgSglTgtGen_Abc::~VlgSglTgtGen_Abc() {}

VlgSglTgtGen_Abc::VlgSglTgtGen_Abc(
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
    advanced_parameters_t* adv_ptr, bool GenerateProof, _chc_target_t chctarget,
    bool useGLA, bool useCORR, bool useAIGER)
    : VlgSglTgtGen(output_path, instr_ptr, ila_ptr, config, _rf_vmap, _rf_cond,
                   _sup_info, _vlg_info_ptr, vlg_mod_inst_name,
                   ila_mod_inst_name, wrapper_name, implementation_srcs,
                   implementation_include_path, vtg_config, vbackend, target_tp,
                   adv_ptr),
      s_backend(sbackend), generate_proof(GenerateProof),
      has_cex(adv_ptr && adv_ptr->_cex_obj_ptr), chc_target(chctarget),
      useGla(useGLA), useCorr(useCORR), useAiger(useAIGER), disallowGla(false) {

  ILA_CHECK(vbackend == backend_selector::YOSYS)
      << "Only support using yosys for chc target";

  ILA_CHECK(chctarget == _chc_target_t::CEX) << "Target must be cex";
  ILA_CHECK(target_tp == target_type_t::INV_SYN_DESIGN_ONLY)
      << "for cex chc, target type must be INV_SYN_DESIGN_ONLY: " << target_tp;
  ILA_CHECK(has_cex) << "for cex chc, cex must be provided!";

  ILA_CHECK(sbackend == synthesis_backend_selector::ABC)
      << "Unknown synthesis backend:" << sbackend;

  ILA_CHECK(_vtg_config.YosysSmtFlattenHierarchy)
      << "For ABC, hierarchy must be flattened!";
}

/// Add an assumption
void VlgSglTgtGen_Abc::add_a_direct_assumption(const std::string& aspt,
                                               const std::string& dspt) {
  _problems.assumptions[dspt].exprs.push_back(aspt);
}
/// Add an assertion
void VlgSglTgtGen_Abc::add_a_direct_assertion(const std::string& asst,
                                              const std::string& dspt) {
  _problems.assertions[dspt].exprs.push_back(asst);
}

void VlgSglTgtGen_Abc::PreExportProcess() {

  std::string all_assert_wire_content;
  std::string all_assume_wire_content;

  ILA_CHECK(target_type == target_type_t::INV_SYN_DESIGN_ONLY);
  ILA_ERROR_IF(_problems.assertions.size() != 1) << "BUG in cex extract";

  // you need to add assumptions as well
  for (auto&& pbname_prob_pair : _problems.assumptions) {
    const auto& prbname = pbname_prob_pair.first;
    const auto& prob = pbname_prob_pair.second;
    ILA_DLOG("VlgSglTgtGen_Abc.PreExportProcess")
        << "Adding assumption:" << prbname;

    for (auto&& p : prob.exprs) {
      if (all_assume_wire_content.empty())
        all_assume_wire_content = "(" + p + ")";
      else
        all_assume_wire_content += "&& (" + p + ")";
    } // for prob.exprs
  }   // for _problems.assumption

  bool first = true;
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

  std::string precond;
  disallowGla = false;
  if (!all_assume_wire_content.empty()) {
    ILA_CHECK(
        !(_vtg_config.AbcUseAiger == false &&
          _vtg_config.AbcAssumptionStyle == _vtg_config.AigMiterExtraOutput))
        << "If you don't use aiger, and has assumptions, there is no way to "
           "pass the extra output. (Will have an additional latch, but "
           "currently we cannot interprete.)";
    if (_vtg_config.AbcAssumptionStyle == _vtg_config.AigMiterExtraOutput) {
      disallowGla = true;
      vlg_wrapper.add_wire("__all_assume_wire__", 1, true);
      vlg_wrapper.add_output("__all_assume_wire__", 1);
      vlg_wrapper.add_assign_stmt("__all_assume_wire__",
                                  all_assume_wire_content);
      vlg_wrapper.add_stmt("assume property (__all_assume_wire__);\n");
    } else {
      vlg_wrapper.add_reg("__all_assumed_reg__", 1);
      vlg_wrapper.add_stmt("always @(posedge clk) begin");
      vlg_wrapper.add_stmt("if (rst) __all_assumed_reg__ <= 0;");
      vlg_wrapper.add_stmt(
          "else if (!__all_assume_wire__) __all_assumed_reg__ <= 1; end");

      vlg_wrapper.add_wire("__all_assume_wire__", 1, true);
      vlg_wrapper.add_output("__all_assume_wire__", 1);
      vlg_wrapper.add_assign_stmt("__all_assume_wire__",
                                  all_assume_wire_content);
      precond = "!( __all_assume_wire__ && !__all_assumed_reg__) || ";
    }
  } // handle assumptions

  vlg_wrapper.add_stmt("assert property (" + precond +
                       " __all_assert_wire__ ); // the only assertion \n");
} // PreExportProcess

/// export the script to run the verification :
/// like "yosys gemsmt.ys"
void VlgSglTgtGen_Abc::Export_script(const std::string& script_name) {
  abc_run_script_name = script_name;
  /// TODO: BUG: modify this : use z3/freqHorn

  auto fname = os_portable_append_dir(_output_path, script_name);
  std::ofstream fout(fname);
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing to file:" << fname;
    return;
  }
  fout << "#!/bin/bash" << std::endl;
  // fout << "trap \"trap - SIGTERM && kill -- -$$\" SIGINT SIGTERM"<<std::endl;

  std::string runnable = "abc";
  if (!_vtg_config.AbcPath.empty())
    runnable = os_portable_append_dir(_vtg_config.AbcPath, runnable);

  std::string abc_cmd;
  {                 // assemble the abc command
    if (useAiger) { // pass aiger
      ILA_CHECK(!(useGla && disallowGla))
          << "Cannot use GLA with assumptions and assumption style chosen as "
             "AigMiterExtraOutput";
      if (useGla)
        abc_cmd = abcAigCmdGLA;
      else
        abc_cmd = abcAigCmdNoGLA;
    } else { // pass blif
      if (useGla)
        abc_cmd = abcCmdGLA;
      else
        abc_cmd = abcCmdNoGLA;
    }
    abc_cmd =
        ReplaceAll(abc_cmd, "{scorr}", useCorr ? "scorr -v -l -k -F 4" : "");
    abc_cmd = ReplaceAll(abc_cmd, "{lcorr}", useCorr ? "lcorr -v" : "");
    abc_cmd = ReplaceAll(abc_cmd, "{inv_min}",
                         _vtg_config.AbcMinimizeInv ? "inv_min -l" : "");
  } // end assembling the abc command

  auto abc_command_file_name = "abcCmd.txt";
  { // generate abc command
    abc_cmd = ReplaceAll(abc_cmd, "%blifname%", blif_fname);
    abc_cmd = ReplaceAll(abc_cmd, "%aigname%", aiger_fname);
    auto abc_cmd_fname =
        os_portable_append_dir(_output_path, abc_command_file_name);
    std::ofstream abc_cmd_fn(abc_cmd_fname);
    if (!abc_cmd_fn.is_open()) {
      ILA_ERROR << "Error writing to file:" << abc_cmd_fname;
      return;
    }
    abc_cmd_fn << abc_cmd;
  } // generate abc command

  if (aiger_fname != "" || blif_fname != "")
    fout << runnable << " -F " << abc_command_file_name << std::endl;
  else
    fout << "echo 'Nothing to check!'" << std::endl;
} // Export_script

/// For jasper, this means do nothing, for yosys, you need to add (*keep*)
void VlgSglTgtGen_Abc::Export_modify_verilog() {
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
void VlgSglTgtGen_Abc::Export_mem(const std::string& mem_name) {
  // we will ignore the mem_name

  auto outfn = os_portable_append_dir(_output_path, top_file_name);
  std::ofstream fout(outfn, std::ios_base::app); // append

  VlgAbsMem::OutputMemFile(fout,
                           _vtg_config.VerificationSettingAvoidIssueStage);
}

static void correct_blif_remove_non_init(const std::string& fn,
                                         const std::string& fo) {
  std::ifstream fin(fn);
  std::ofstream fout(fo);
  if (!fin.is_open()) {
    ILA_ERROR << "Unable to read " << fn;
    return;
  }
  if (!fout.is_open()) {
    ILA_ERROR << "Unable to write " << fo;
    return;
  }
  std::string line;
  while (std::getline(fin, line)) {
    if (StrStartsWith(line, ".latch ")) {
      auto st_def = SplitSpaceTabEnter(line);
      if (st_def.back() == "2") {
        st_def.back() = "0";
        ILA_WARN << "Force state to be 0: " << st_def.at(2);
        line = Join(st_def, " ");
      }
    }
    // always write back
    fout << line << "\n";
  }
} // correct_blif_remove_non_init

// export the chc file
void VlgSglTgtGen_Abc::Export_problem(const std::string& extra_name) {
  // used by export script!

  if (!useAiger) {
    blif_fname = extra_name;

    // first generate a temporary smt
    // and extract from it the necessary info
    // "yosys --> blif "
    generate_blif(os_portable_append_dir(_output_path, "__blif_prepare.blif"),
                  os_portable_append_dir(_output_path, "__gen_blif_script.ys"));

    correct_blif_remove_non_init(
        os_portable_append_dir(_output_path, "__blif_prepare.blif"),
        os_portable_append_dir(_output_path, blif_fname));
  } else {
    aiger_fname = extra_name;

    generate_aiger(
        os_portable_append_dir(_output_path, "__aiger_prepare.blif"),
        os_portable_append_dir(_output_path, aiger_fname),
        os_portable_append_dir(_output_path, aiger_fname + ".map"),
        os_portable_append_dir(_output_path, "__gen_blif_script.ys"));
  }
} // Export_problem

void VlgSglTgtGen_Abc::ExportAll(const std::string& wrapper_name, // wrapper.v
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
void VlgSglTgtGen_Abc::generate_blif(const std::string& blif_name,
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
                        ReplaceAll(abcGenerateSmtScript_wo_Array, "%topfile%",
                                   os_portable_append_dir(_output_path,
                                                          top_file_name)),
                        "%module%", top_mod_name),
                    "%blifname%", blif_name),
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
} // design_only_gen_smt

/// generate the wrapper's smt first
void VlgSglTgtGen_Abc::generate_aiger(const std::string& blif_name,
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

#endif // INVSYN_INTERFACE
