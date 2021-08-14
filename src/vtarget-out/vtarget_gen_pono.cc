/// \file Source of generating Pono accepted problem, vlg, mem, script
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen_pono.h>

#include <algorithm>
#include <fstream>
#include <iostream>

#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"


// should not be used
static std::string yosysGenerateBtor = R"***(
hierarchy -check
proc
chformal -assume -early;
memory -nomap;
flatten
sim -clock clk -reset rst -rstlen %rstlen% -n %cycle% -w %module%
)***";


VlgSglTgtGen_Pono::VlgSglTgtGen_Pono(
    const std::string&
        output_path, // will be a sub directory of the output_path of its parent
    const InstrPtr& instr_ptr, // which could be an empty pointer, and it will
                               // be used to verify invariants
    const InstrLvlAbsPtr& ila_ptr, 
    const rfmap::VerilogRefinementMap & refinement,
    VerilogInfo* _vlg_info_ptr,
    const std::string& wrapper_name,
    const std::vector<std::string>& implementation_srcs,
    const std::vector<std::string>& implementation_include_path,
    const vtg_config_t& vtg_config, backend_selector vbackend,
    const target_type_t& target_tp, advanced_parameters_t* adv_ptr)
    : VlgSglTgtGen(output_path, instr_ptr, ila_ptr, refinement,
                   _vlg_info_ptr, wrapper_name, implementation_srcs,
                   implementation_include_path, vtg_config, vbackend, target_tp,
                   adv_ptr) {}


/// Add an assumption
void VlgSglTgtGen_Pono::add_a_direct_assumption(const std::string& aspt,
                                                const std::string& dspt) {
  _problems.assumptions[dspt].exprs.push_back(aspt);
}
/// Add an assertion
void VlgSglTgtGen_Pono::add_a_direct_assertion(const std::string& asst,
                                               const std::string& dspt) {
  _problems.assertions[dspt].exprs.push_back(asst);
}

/// export the script to run the verification
void VlgSglTgtGen_Pono::Export_script(const std::string& script_name) {

  auto fname = os_portable_append_dir(_output_path, script_name);
  std::ofstream fout(fname);
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing to file:" << fname;
    return;
  }
  fout << "#!/bin/bash" << std::endl;
 
  {
    std::string yosys = "yosys";

    if (!_vtg_config.YosysPath.empty())
      yosys = os_portable_append_dir(_vtg_config.YosysPath, yosys);

    // execute it
    fout << yosys << " -s " << ys_script_name << " > __yosys_exec_result.txt\n"; 
  }


  std::string pono = "pono";
  std::string options;

  if (!_vtg_config.PonoVcdOutputName.empty())
    options += " --vcd " + _vtg_config.PonoVcdOutputName;
  options += " " + _vtg_config.PonoOtherOptions;

  // no need, copy is good enough
  // if(vlg_include_files_path.size() != 0)
  //  options += " -I./";

  if (!_vtg_config.PonoPath.empty()) {
    pono = os_portable_append_dir(_vtg_config.PonoPath, pono);
  }

  fout << pono << " problem.btor2 " << std::endl;

}


/// Add SMT-lib2 assumption
void VlgSglTgtGen_Pono::add_a_direct_smt_assumption(const std::string& arg,
                                      const std::string& ret,
                                      const std::string& body,
                                      const std::string& dspt) {
  size_t idx = _problems.smt_assumptions.size();
  _problems.smt_assumptions.push_back(
    "(define-fun assumption."+std::to_string(idx)+" " + arg + " " + ret + " " + body+")");
  
}

/// Add SMT-lib2 assertion
void VlgSglTgtGen_Pono::add_a_direct_smt_assertion(const std::string& arg,
                                    const std::string& ret,
                                    const std::string& body,
                                    const std::string& dspt) {
  size_t idx = _problems.smt_assertions.size();
  _problems.smt_assertions.push_back(
    "(define-fun assertion."+std::to_string(idx)+" " + arg + " " + ret + " " + body+")");
}

/// export the yosys script
void VlgSglTgtGen_Pono::Export_problem(const std::string& yosys_script_name) {
  if (_problems.assertions.empty()) {
    ILA_ERROR << "Nothing to prove, no assertions inserted!";
    return;
  }

  ys_script_name = yosys_script_name;

  std::string ys_script_name_path = os_portable_append_dir(_output_path, ys_script_name);
  { // export to ys_script_name
    std::ofstream ys_script_fout(ys_script_name_path);

    std::string write_btor_options;
    write_btor_options += _vtg_config.BtorAddCommentsInOutputs ? " -v" : "";
    write_btor_options += _vtg_config.BtorSingleProperty ? " -s" : "";

    ys_script_fout << "read_verilog -sv "
                   << os_portable_append_dir(_output_path, top_file_name)
                   << std::endl;
    ys_script_fout << "prep -top " << top_mod_name << std::endl;

    ys_script_fout << 
      ReplaceAll(
        ReplaceAll(
          ReplaceAll(yosysGenerateBtor, 
            "%rstlen%",
              std::to_string(
                refinement_map.reset_specification.reset_cycle)),
            "%cycle%",
              std::to_string(
                refinement_map.reset_specification.reset_cycle)),
        "%module%", top_mod_name);

    // this is for pono, I don't know why it is unhappy, but we need fix this
    // in the long run
    ys_script_fout << "setundef -undriven -zero\n";
    ys_script_fout << "write_btor " << write_btor_options << " problem.btor2" << std::endl;
  } // finish writing


  auto smt_property_fname =
      os_portable_append_dir(_output_path, "property.smt2");
  {
    std::ofstream smt_fout(smt_property_fname);
    for(const auto & prop : _problems.smt_assumptions)
      smt_fout << prop << std::endl;
    
    for(const auto & prop : _problems.smt_assertions)
      smt_fout << prop << std::endl;
  }
} // only for Pono



// PreExportProcess is about how to add assumption/assertions
void VlgSglTgtGen_Pono::PreExportProcess() {

  std::string all_assert_wire_content;
  std::string all_assume_wire_content;

  // you need to add assumptions as well
  for (auto&& pbname_prob_pair : _problems.assumptions) {
    const auto& prbname = pbname_prob_pair.first;
    const auto& prob = pbname_prob_pair.second;
    ILA_DLOG("VlgSglTgtGen_Pono.PreExportProcess")
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

  vlg_wrapper.add_stmt(
      "assert property ( __all_assert_wire__ ); // the only assertion \n");
  if (!all_assume_wire_content.empty())
    vlg_wrapper.add_stmt(
        "assume property ( __all_assume_wire__ ); // the only assumption \n");
} // PreExportProcess

/// For jasper, this means do nothing, for yosys, you need to add (*keep*)
void VlgSglTgtGen_Pono::Export_modify_verilog() {
  // collect all locations: filename -> lineno
  // open, read, count and write
  // if it is a port name, we will ask user to specify its upper level
  // signal name
  VerilogModifier vlg_mod(vlg_info_ptr,
                          static_cast<VerilogModifier::port_decl_style_t>(
                              _vtg_config.PortDeclStyle),
                          _vtg_config.PonoAddKeep,
                          refinement_map.width_info);

  for (auto && wn_extraw : rtl_extra_wire) {
    ILA_CHECK(StrStartsWith(wn_extraw.first, "RTL__DOT__"));
    vlg_mod.RecordConnectSigName(wn_extraw.second.wire_name,
      wn_extraw.second.hierarchy,
      wn_extraw.second.internal_name,
      wn_extraw.second.width);
    // will not record keep
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

}; // namespace ilang
