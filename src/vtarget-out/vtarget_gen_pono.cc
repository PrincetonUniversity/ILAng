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
%propselect%
memory %-nomap%;
flatten
setundef -undriven -expose;
sim -clock clk -reset rst -rstlen %rstlen% -n %cycle% -w %module%
)***";
// %propselect% is for

static const std::string show_result_bash_script = R"***(
function show_result () {
    RfError=""
    SanityError=""
    CoverError=""

    if test $RfResult = 0; then RfMsg=" (* buggy)";
    elif test $RfResult = 1; then RfMsg=" (passed)";
    elif test $RfResult = 2; then RfMsg=" (* checker error)";
    elif test $RfResult = 3; then RfMsg=" (skipped)";
    elif test $RfResult = 255; then RfMsg=" (unknown)";
    else echo "UNKNOWN PONO RESULT: " $RfResult; RfMsg=" (* terminated)"; RfResult=2
    fi

    if   test $SanityResult = 0;   then SanityMsg=" (* sanity violation)";
    elif test $SanityResult = 1;   then SanityMsg=" (sanity is proved to hold)";
    elif test $SanityResult = 2;   then SanityMsg=" (* checker error)";
    elif test $SanityResult = 3;   then SanityMsg=" (skipped)";
    elif test $SanityResult = 255; then SanityMsg=" (no sanity violation within bound)";
    else echo "UNKNOWN PONO RESULT: " $SanityResult; SanityMsg=" (* terminated)"; SanityResult=2
    fi

    if   test $CoverResult = 0;   then CoverMsg=" (covered)";
    elif test $CoverResult = 1;   then CoverMsg=" (* not reachable)";
    elif test $CoverResult = 2;   then CoverMsg=" (* checker error)";
    elif test $CoverResult = 3;   then CoverMsg=" (skipped)";
    elif test $CoverResult = 255; then CoverMsg=" (* not yet reachable)";
    else echo "UNKNOWN PONO RESULT: " $CoverResult; CoverMsg=" (* terminated)"; CoverResult=2;
    fi

    echo '============ SUMMARY ============'
    echo 'Refinement Check:' $RfResult $RfMsg
    echo 'Santiy Check:' $SanityResult $SanityMsg
    echo 'Cover Check:' $CoverResult $CoverMsg
    echo '============ END OF SUMMARY ============'
    echo ""

    if [ $RfResult = 2 ] || [ $SanityResult = 2 ] ||  [ $CoverResult = 2 ]; then
        return 2
    fi

    if test $RfResult = 0; then return 0;
    elif test $SanityResult = 0; then return 0;
    elif test $CoverResult = 1; then return 0;
    elif test $CoverResult = 255; then return 255;
    else return $RfResult;
    fi
}

show_result
exit $?

)***";

VlgSglTgtGen_Pono::VlgSglTgtGen_Pono(
    const std::string&
        output_path, // will be a sub directory of the output_path of its parent
    const InstrPtr& instr_ptr, // which could be an empty pointer, and it will
                               // be used to verify invariants
    const InstrLvlAbsPtr& ila_ptr,
    const rfmap::VerilogRefinementMap& refinement, VerilogInfo* _vlg_info_ptr,
    const std::string& wrapper_name,
    const std::vector<std::string>& implementation_srcs,
    const std::vector<std::string>& implementation_include_path,
    const RtlVerifyConfig& vtg_config, ModelCheckerSelection vbackend,
    const target_type_t& target_tp, advanced_parameters_t* adv_ptr)
    : VlgSglTgtGen(output_path, instr_ptr, ila_ptr, refinement, _vlg_info_ptr,
                   wrapper_name, implementation_srcs,
                   implementation_include_path, vtg_config, vbackend, target_tp,
                   adv_ptr) {}

/// Add an assumption
void VlgSglTgtGen_Pono::add_a_direct_assumption(const std::string& aspt,
                                                const std::string& dspt) {
  auto wire_name = dspt + new_property_id();
  vlg_wrapper.add_wire(wire_name, 1);
  vlg_wrapper.add_output(wire_name, 1);
  vlg_wrapper.add_assign_stmt(wire_name, aspt);
  _problems.assumptions[dspt].exprs.push_back(wire_name);
}
/// Add an assertion
void VlgSglTgtGen_Pono::add_a_direct_assertion(const std::string& asst,
                                               const std::string& dspt) {
  auto wire_name = dspt + new_property_id();
  vlg_wrapper.add_wire(wire_name, 1);
  vlg_wrapper.add_output(wire_name, 1);
  vlg_wrapper.add_assign_stmt(wire_name, asst);
  _problems.assertions[dspt].exprs.push_back(wire_name);
}

/// Add an assertion
void VlgSglTgtGen_Pono::add_a_direct_sanity_assertion(const std::string& asst,
                                                      const std::string& dspt) {
  auto wire_name = dspt + new_property_id();
  vlg_wrapper.add_wire(wire_name, 1);
  vlg_wrapper.add_output(wire_name, 1);
  vlg_wrapper.add_assign_stmt(wire_name, asst);
  _problems.sanity_assertions[dspt].exprs.push_back(wire_name);
}

/// Add a cover assertion
void VlgSglTgtGen_Pono::add_a_direct_cover_check(const std::string& asst,
                                                const std::string& dspt) {
  auto wire_name = dspt + new_property_id();
  vlg_wrapper.add_wire(wire_name, 1);
  vlg_wrapper.add_output(wire_name, 1);
  vlg_wrapper.add_assign_stmt(wire_name, asst);
  _problems.cover_checks[dspt].exprs.push_back(wire_name);
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
  fout << "echo \"* Remove prior results...\"" << std::endl;
  fout << "rm -f *.btor2 *.vcd __yosys*.txt" << std::endl;

  fout << "echo \"* Parsing input...\"" << std::endl;

  std::string yosys = "yosys";

  if (!_vtg_config.YosysPath.empty())
    yosys = os_portable_append_dir(_vtg_config.YosysPath, yosys);

  // execute it
  fout << yosys << " -s " << ys_script_name << " > __yosys_exec_result.txt\n";

  std::string pono = "pono";
  std::string options;

  if (!_vtg_config.PonoVcdOutputName.empty())
    options += " --vcd " + _vtg_config.PonoVcdOutputName;
  if (!_vtg_config.PonoEngine.empty())
    options += " -e " + _vtg_config.PonoEngine;
  options += " " + _vtg_config.PonoOtherOptions;

  // no need, copy is good enough
  // if(vlg_include_files_path.size() != 0)
  //  options += " -I./";

  if (!_vtg_config.PonoPath.empty()) {
    pono = os_portable_append_dir(_vtg_config.PonoPath, pono);
  }

  std::string extra_smt_properties;
  if (!_problems.smt_assertions.empty() || !_problems.smt_assumptions.empty()) {
    extra_smt_properties += " --property-file property.smt2 ";
  }

  fout << "echo \"* Run Pono to check refinement...\"" << std::endl;
  fout << pono << options << extra_smt_properties << " problem.btor2 "
       << std::endl;

  fout << "RfResult=$?" << std::endl;

  if (!_problems.sanity_assertions.empty()) {
    fout << "echo \"* Parsing sanity check input...\"" << std::endl;
    fout << yosys
         << " -s gen_sanity_prop.ys > __yosys_exec_result.sanity.txt\n";
    // here we intentionally leave out the property interface file.

    fout << "echo \"* Run Pono to check assumption sanity...\"" << std::endl;
    fout << pono << options << extra_smt_properties << " sanity.btor2 " << std::endl;
    fout << "SanityResult=$?" << std::endl;
  } else {
    fout << "SanityResult=3" << std::endl;
  }

  if(all_cover_assert_property_names.empty()) {
    fout << "CoverResult=3" << std::endl;
  } else
    fout << "CoverResult=0" << std::endl;

  for (unsigned idx = 0; idx < all_cover_assert_property_names.size(); ++idx) {
    auto cover_fname = "cover" + std::to_string(idx)+".btor2";
    std::string cover_options = " -e bmc " + _vtg_config.PonoOtherOptions;
    cover_options += extra_smt_properties;

    fout << "echo \"* Parsing cover check input #" <<idx<<" ...\"" << std::endl;
    fout << yosys
         << " -s gen_cover_prop" << idx <<".ys > __yosys_exec_result.cover" << idx<<".txt\n";
    
    fout << "echo \"Run Pono to check cover property (expecting sat)...\"" << std::endl;
    fout << pono << cover_options << " " << cover_fname << std::endl;
    fout << "if test $? != 0; then CoverResult=$?; fi" << std::endl;
  }

  fout << show_result_bash_script << std::endl;

} // Export_script


/// Add SMT-lib2 assumption
void VlgSglTgtGen_Pono::add_a_direct_smt_assumption(const std::string& arg,
                                                    const std::string& ret,
                                                    const std::string& body,
                                                    const std::string& dspt) {
  size_t idx = _problems.smt_assumptions.size();
  _problems.smt_assumptions.push_back("(define-fun assumption." +
                                      std::to_string(idx) + " " + arg + " " +
                                      ret + " " + body + ")");
}

/// Add SMT-lib2 assertion
void VlgSglTgtGen_Pono::add_a_direct_smt_assertion(const std::string& arg,
                                                   const std::string& ret,
                                                   const std::string& body,
                                                   const std::string& dspt) {
  size_t idx = _problems.smt_assertions.size();
  _problems.smt_assertions.push_back("(define-fun assertion." +
                                     std::to_string(idx) + " " + arg + " " +
                                     ret + " " + body + ")");
}


void VlgSglTgtGen_Pono::GenYosysScript(
    const std::string& ys_script_name_path,
    const std::string& property_selection_cmd,
    const std::string& generated_btor_name )
{  
  // export to ys_script_name
  std::ofstream ys_script_fout(ys_script_name_path);

  std::string write_btor_options;
  write_btor_options += _vtg_config.BtorAddCommentsInOutputs ? " -v" : "";
  write_btor_options += _vtg_config.BtorSingleProperty ? " -s" : "";

  ys_script_fout << "read_verilog -sv "
                  << top_file_name // os_portable_append_dir(_output_path, top_file_name)
                  << std::endl;
  ys_script_fout << "prep -top " << top_mod_name << std::endl;

  ILA_CHECK(
    refinement_map.clock_specification.custom_clock_factor.empty() &&
    refinement_map.clock_specification.custom_clock_sequence.empty()
    ) << "TODO: custom clock sequence not implemented yet";
  
  ILA_CHECK(
    refinement_map.reset_specification.custom_reset_sequence.empty() &&
    refinement_map.reset_specification.initial_state.empty()
    ) << "TODO: custom reset sequence not implemented yet";

  ys_script_fout << ReplaceAll(
    ReplaceAll(
      ReplaceAll(
          ReplaceAll(
              ReplaceAll(yosysGenerateBtor, "%rstlen%",
                          std::to_string(
                              refinement_map.reset_specification.reset_cycle)),
              "%cycle%",
              std::to_string(refinement_map.reset_specification.reset_cycle)),
          "%module%", top_mod_name),
      "%propselect%", property_selection_cmd),
    "%-nomap%", _vtg_config.YosysSmtArrayForRegFile ? "-nomap" : "" );

  // this is for pono, I don't know why it is unhappy, but we need fix this
  // in the long run
  if (_vtg_config.YosysSetUndrivenZero)
    ys_script_fout << "setundef -undriven -zero\n";

  ys_script_fout << "write_btor " << write_btor_options 
                 << " " << generated_btor_name
                 << std::endl;
} // VlgSglTgtGen_Pono::GenYosysScript

/// export the yosys script
void VlgSglTgtGen_Pono::Export_problem(const std::string& yosys_script_name) {

  if (_problems.assertions.empty() && _problems.smt_assertions.empty() &&
      _problems.sanity_assertions.empty() && _problems.cover_checks.empty()
      ) {
    ILA_ERROR << "Nothing to prove, no assertions inserted!";
    return;
  }

  ys_script_name = yosys_script_name;

  { // export the main script
    std::string ys_script_name_path =
        os_portable_append_dir(_output_path, ys_script_name);
    std::string property_selection_cmd;
    if (!_problems.sanity_assertions.empty()) {
      property_selection_cmd +="\n"
                               "select wrapper/sanitycheck\n"
                               "chformal -remove\n"
                               "select *\n";
    }
    if (!_problems.cover_checks.empty()) {
      ILA_CHECK(!all_cover_assert_property_names.empty());
      for(const auto & p : all_cover_assert_property_names)
        property_selection_cmd +="\n"
                                "select wrapper/"+ p +(" \n"
                                "chformal -remove\n"
                                "select *\n");
    }

    GenYosysScript(ys_script_name_path, property_selection_cmd, "problem.btor2");
  } // finish writing

  auto smt_property_fname =
      os_portable_append_dir(_output_path, "property.smt2");
  {
    std::ofstream smt_fout(smt_property_fname);
    for (const auto& prop : _problems.smt_assumptions)
      smt_fout << prop << std::endl;

    for (const auto& prop : _problems.smt_assertions)
      smt_fout << prop << std::endl;
  }

  if (!_problems.sanity_assertions.empty()) {
    std::string ys_script_name_path =
        os_portable_append_dir(_output_path, "gen_sanity_prop.ys");
    std::string property_selection_cmd = "\n"
                                         "select wrapper/normalassert\n"
                                         "chformal -remove\n"
                                         "select *\n";
    
    if (!_problems.cover_checks.empty()) {
      ILA_CHECK(!all_cover_assert_property_names.empty());
      for(const auto & p : all_cover_assert_property_names)
        property_selection_cmd +="\n"
                                "select wrapper/"+ p +(" \n"
                                "chformal -remove\n"
                                "select *\n");
    }

    GenYosysScript(ys_script_name_path, property_selection_cmd, "sanity.btor2");
  } // finish writing sanity check Yosys script

  if (!_problems.cover_checks.empty()) {
    ILA_CHECK(!all_cover_assert_property_names.empty());

    std::string property_selection_cmd_tmpl = "\n"
                                         "select wrapper/normalassert\n"
                                         "chformal -remove\n"
                                         "select *\n";
    
    if(!_problems.sanity_assertions.empty()) {
                property_selection_cmd_tmpl += "\n"
                                         "select wrapper/sanitycheck\n"
                                         "chformal -remove\n"
                                         "select *\n";
    }

    for (unsigned idx = 0; idx < all_cover_assert_property_names.size() ; ++idx) {
      std::string ys_script_name_path =
          os_portable_append_dir(_output_path, "gen_cover_prop" + std::to_string(idx) + ".ys");

      std::string property_selection_cmd = property_selection_cmd_tmpl;
      for(unsigned jdx = 0; jdx < all_cover_assert_property_names.size(); ++jdx) {
        if (jdx == idx)
          continue;
        // remove all other covers
        property_selection_cmd += "\n"
                                  "select wrapper/" + all_cover_assert_property_names.at(jdx) + "\n"
                                  "chformal -remove\n"
                                  "select *\n";
      } // end for each other cover property remove it
      
      GenYosysScript(ys_script_name_path, property_selection_cmd, "cover"+ std::to_string(idx) +".btor2");
    } // end for each cover property
  } // finish writing cover check Yosys script


  if(_vtg_config.PonoGenJgScript) {
    auto jg_script_fname = os_portable_append_dir(_output_path, "jg.tcl");
    std::ofstream fout(jg_script_fname);
    ILA_ERROR_IF(!fout.is_open()) << "Cannot write to " << jg_script_fname;
    fout << "analyze -sva " << top_file_name << std::endl;
    fout << "elaborate -top " << top_mod_name << std::endl;
    fout << "clock clk" << std::endl;
    fout << "reset rst" << std::endl;
    // remove cover assert
    for (const auto & pname : all_cover_assert_property_names) {
      fout << "assert -disable " << pname << std::endl;
    }
    // re-insert as jg covers
    unsigned cover_property_id = 0;
    for (auto && pbname_prob_pair : _problems.cover_checks) {
      // const auto& prbname = pbname_prob_pair.first;
      const auto& prob = pbname_prob_pair.second;

      for (auto&& p : prob.exprs) {
        // there should be only one expression (for cex target)
        // ILA_CHECK(all_assert_wire_content.empty());
        fout << "cover -name " << "cover_"<<(cover_property_id++) << " {"
             << p << "}";
      } // for expr
    } // end for each cover
  } // end for jg script

} // end of Export_problem -- export Yosys script

// PreExportProcess is about how to add assumption/assertions
void VlgSglTgtGen_Pono::PreExportProcess() {

  std::string all_assert_wire_content;
  std::string all_sanity_assert_wire_content;

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

  // this is to check given assertions
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
        all_assert_wire_content = "(" + p + ")";
      else
        all_assert_wire_content += " && (" + p + ")";
    } // for expr
  }   // for problem
  // add assert wire (though no use : make sure will not optimized away)
  if (_problems.smt_assertions.empty())
    ILA_CHECK(!all_assert_wire_content.empty()) << "no property to check!";

  if (all_assert_wire_content
          .empty()) { // in case all_assert_wire_content is empty
    all_assert_wire_content = "1'b1"; // (assert true)
  }

  // this is to check given sanity assertions
  for (auto&& pbname_prob_pair : _problems.sanity_assertions) {
    // const auto& prbname = pbname_prob_pair.first;
    const auto& prob = pbname_prob_pair.second;

    // ILA_CHECK(prbname == "cex_nonreachable_assert")
    //  << "BUG: assertion can only be cex reachability queries.";
    // sanity check, should only be invariant's related asserts

    for (auto&& p : prob.exprs) {
      // there should be only one expression (for cex target)
      // ILA_CHECK(all_assert_wire_content.empty());
      if (all_sanity_assert_wire_content.empty())
        all_sanity_assert_wire_content = "(" + p + ")";
      else
        all_sanity_assert_wire_content += " && (" + p + ")";
    } // for expr
  }

  unsigned cover_property_id = 0;
  for (auto && pbname_prob_pair : _problems.cover_checks) {
    // const auto& prbname = pbname_prob_pair.first;
    const auto& prob = pbname_prob_pair.second;

    for (auto&& p : prob.exprs) {
      // there should be only one expression (for cex target)
      // ILA_CHECK(all_assert_wire_content.empty());
      auto property_name = "negcoverassert" + std::to_string(cover_property_id ++);
      vlg_wrapper.add_stmt(property_name + ": assert property (!"
        + p +"); /*expecting: false*/");
      all_cover_assert_property_names.push_back(property_name);
    } // for expr
  }

  vlg_wrapper.add_wire("__all_assert_wire__", 1, true);
  vlg_wrapper.add_output("__all_assert_wire__", 1);
  vlg_wrapper.add_assign_stmt("__all_assert_wire__", all_assert_wire_content);
  vlg_wrapper.add_stmt("normalassert: assert property ( __all_assert_wire__ ); "
                       "// the only assertion \n");

  if (!all_assume_wire_content.empty()) {
    vlg_wrapper.add_wire("__all_assume_wire__", 1, true);
    vlg_wrapper.add_output("__all_assume_wire__", 1);
    vlg_wrapper.add_assign_stmt("__all_assume_wire__", all_assume_wire_content);

    vlg_wrapper.add_stmt("all_assume: assume property ( __all_assume_wire__ ); "
                         "// the only sanity assertion \n");
  }

  if (!all_sanity_assert_wire_content.empty()) {
    vlg_wrapper.add_wire("__sanitycheck_wire__", 1, true);
    vlg_wrapper.add_output("__sanitycheck_wire__", 1);
    vlg_wrapper.add_assign_stmt("__sanitycheck_wire__",
                                all_sanity_assert_wire_content);

    vlg_wrapper.add_stmt("sanitycheck: assert property ( __sanitycheck_wire__ "
                         "); // the only assumption \n");
  }
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
                          refinement_map.width_info,
                          refinement_map.range_info);

  for (auto&& wn_extraw : rtl_extra_wire) {
    ILA_CHECK(StrStartsWith(wn_extraw.first, "RTL__DOT__"));
    vlg_mod.RecordConnectSigName(
        wn_extraw.second.wire_name, wn_extraw.second.hierarchy,
        wn_extraw.second.internal_name, wn_extraw.second.width);
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
