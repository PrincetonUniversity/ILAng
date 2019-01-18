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
    const vtg_config_t& vtg_config, backend_selector backend)
    : VlgSglTgtGen(output_path, instr_ptr, ila_ptr, config, _rf_vmap, _rf_cond,
                   _vlg_info_ptr, vlg_mod_inst_name, ila_mod_inst_name,
                   wrapper_name, implementation_srcs,
                   implementation_include_path, vtg_config, backend) {}


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
  _problems.assumptions.push_back(assumption_wire_name + " = 1'b1");
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
  _problems.probitem[dspt].assertions.push_back(assrt_wire_name + " = 1'b1");
  ILA_ERROR_IF(asst.find(".") != std::string::npos)
      << "asst:" << asst << " contains unfriendly dot.";
  //_problems.probitem[dspt].assertions.push_back(convert_expr_to_yosys(asst));
}

/// Add an assumption
void VlgSglTgtGen_Yosys::add_a_direct_assumption(const std::string& aspt,
                                                const std::string& dspt) {
  _problems.assumptions.push_back(aspt);
}
/// Add an assertion
void VlgSglTgtGen_Yosys::add_a_direct_assertion(const std::string& asst,
                                               const std::string& dspt) {
  _problems.probitem[dspt].assertions.push_back(asst);
}

/// Pre export work : add assume and asssert to the top level
void VlgSglTgtGen_Yosys::PreExportProcess() {
  for (auto&& assmpt : _problems.assumptions) {
    vlg_wrapper.add_stmt(
      "assume property ("+assmpt+");\n"
    );
  }
  
  //std::string assmpt = "(" + Join(_problems.assumptions, ") & (") + ")";
  std::string all_assert_wire_content;

  for (auto&& pbname_prob_pair : _problems.probitem) {
    const auto& prbname = pbname_prob_pair.first;
    const auto& prob = pbname_prob_pair.second;
    for (auto&& p: prob.assertions) {
      vlg_wrapper.add_stmt(
        "assert property ("+p+"); //" + prbname + "\n"
      );
      all_assert_wire_content += "&& ( " + p  + " ) ";
    }
  }

  vlg_wrapper.add_wire("__all_assert_wire__", 1, true);
  vlg_wrapper.add_output("__all_assert_wire__",1);
  vlg_wrapper.add_assign_stmt("__all_assert_wire__", all_assert_wire_content);
}

/// export the script to run the verification
void VlgSglTgtGen_Yosys::Export_script(const std::string& script_name) {
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

  if (not _vtg_config.YosysPath.empty()) {
    yosys = os_portable_append_dir(_vtg_config.YosysPath, yosys) + ".py";
  }
  if (yosys_prob_fname != "")
    fout << yosys << " "<< yosys_prob_fname  << std::endl;
  else
    fout << "echo 'Nothing to check!'" << std::endl;
}

std::string yosysGenerateSmtScript_wo_Array = R"***(
flatten
memory -nordff
)***";


std::string yosysGenerateSmtScript_w_Array = R"***(
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

// o.w. we need to find two ind-inv
std::string dual_ind_inv_tmpl = R"***(
;----------------------------------------
;  Dual Inductive Invariant Synthesis
;  Generated from ILAng
;----------------------------------------

%%

(declare-rel INV1 (|%1%_s|))
(declare-rel INV2 (|%1%_s|))
(declare-rel fail ())

(declare-var |__BI__| |%1%_s|)
(declare-var |__I__| |%1%_s|)

(declare-var |__Si__| |%1%_s|)
(declare-var |__Si'__| |%1%_s|)

(declare-var |__S__| |%1%_s|)
(declare-var |__S'__| |%1%_s|)

(rule (=> (and (|%1%_n rst| |__BI__|) (|%1%_t| |__BI__| |__I__|)) (INV1 |__I__|)))
(rule (=> (and (INV1 |__Si__|) (|%1%_t| |__Si__| |__Si'__|)) (INV1 |__Si'__|)))

(rule (=> (and (INV1 |__S__|) (|%1%_u| |__S__|)) (INV2 |__S__|)))
(rule (=> (and (INV2 |__S__|) (|%1%_t| |__S__| |__S'__|)) (INV2 |__S'__|)))
(rule (=> (and (INV2 |__S__|) (not (|%1%_a| |__S__|))) fail))

(query fail :print-certificate true)

)***";

/// export extra things (problem) : for yosys, it is the gensmt.ys (or
/// its equivalence)
void VlgSglTgtGen_Yosys::Export_problem(const std::string& extra_name) {
  if (_problems.probitem.size() == 0) {
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
  fout << 
    _vtg_config.YosysSmtArrayForRegFile ? 
      yosysGenerateSmtScript_w_Array : yosysGenerateSmtScript_wo_Array ;
  fout << "write_smt2"<<write_smt2_options<<" wrapper.smt2";
/*

  fout << "[GENERAL]" << std::endl;
  fout << "model_file:"; //
  fout << top_file_name << "[" << top_mod_name << "],";
  // if(target_type != target_type_t::INVARIANTS )
  //	fout << ila_file_name<<","; // will be combined
  fout << "rst.ets";
  // for(auto && fn : vlg_design_files) // will be combined
  //  fout << "," << os_portable_file_name_from_path(fn);
  fout << std::endl;

  fout << "assume_if_true: True" << std::endl;
  fout << "abstract_clock: True" << std::endl;
  fout << "[DEFAULT]" << std::endl;
  fout << "bmc_length: " << std::to_string(max_bound + 5) << std::endl;
  fout << "precondition: reset_done" << std::endl;
  fout << std::endl;

  std::string assmpt = "(" + Join(_problems.assumptions, ") & (") + ")";
  for (auto&& pbname_prob_pair : _problems.probitem) {
    const auto& prbname = pbname_prob_pair.first;
    const auto& prob = pbname_prob_pair.second;
    auto asst = "(" + Join(prob.assertions, ") & (") + ")";
    auto prob_name = vlg_wrapper.sanitizeName(prbname);
    fout << "[" << prob_name << "]" << std::endl;
    fout << "description:\"" << prbname << "\"" << std::endl;
    fout << "formula:" << asst << std::endl;
    if (assmpt != "()")
      fout << "assumptions:" << assmpt << std::endl;
    fout << "prove: True" << std::endl;
    fout << "verification: safety" << std::endl;
    if (VlgAbsMem::hasAbsMem())
      fout << "strategy: AUTO" << std::endl;
    else
      fout << "strategy: ALL" << std::endl;
    fout << "expected: True" << std::endl;
  }
*/

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

  // now let's do the job
  for (auto&& fn : vlg_design_files) {
    auto outfn = os_portable_append_dir(_output_path, top_file_name);
    std::ifstream fin(fn);
    std::ofstream fout(outfn, std::ios_base::app); // append
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read file:" << fn;
      continue;
    }
    if (!fout.is_open()) {
      ILA_ERROR << "Cannot open file for write:" << outfn;
      continue;
    }
    vlg_mod.ReadModifyWrite(fn, fin, fout);
  } // for (auto && fn : vlg_design_files)
  // .. (copy all the verilog file in the folder), this has to be os dependent
  if (vlg_include_files_path.size() != 0) {
    // copy the files and specify the -I commandline to the run.sh
    for (auto&& include_path : vlg_include_files_path)
      os_portable_copy_dir(include_path, _output_path);
  }

} // Export_modify_verilog

}; // namespace ilang
