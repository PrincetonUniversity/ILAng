/// \file Source for Externally Provided Target for inv-syn
/// to generate a synthesis target with (externally) provided wrapper template
/// instead of constructing the template ourselves
// Hongce Zhang (hongcez@princeton.edu)

#include <ilang/util/str_util.h>
#include <ilang/util/log.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/vtarget-out/inv-syn-extern-loop/yosys_chc.h>
#include <ilang/vtarget-out/vlg_mod.h>

#include <iostream>

namespace ilang{

// ------------------------------------------
/// temporary parameters

const bool generate_proof = true;

/// end of temporary parameters
// ------------------------------------------

ExternalChcTargetGen::ExternalChcTargetGen(const std::vector<std::string>& implementation_include_path,
                const std::vector<std::string>& implementation_srcs,
                const std::string& implementation_top_module,
                const std::string& refinement_variable_mapping,
                const std::string& refinement_conditions,
                const std::string& output_path,
                 const std::string& tmpl_top_mod_name,
                backend_selector backend, synthesis_backend_selector sbackend,
                const vtg_config_t& vtg_config,
                advanced_parameters_t * adv_ptr):
  _vlg_impl_include_path(implementation_include_path),
  _vlg_impl_srcs(implementation_srcs),
  _vlg_impl_top_name(implementation_top_module),
  _rf_var_map_name(refinement_variable_mapping),
  _rf_cond_name(refinement_conditions),
  _output_path(output_path), top_mod_name(tmpl_top_mod_name),
  vlg_info_ptr(NULL), // not creating it now, because we don't have the info to do so
  _backend(backend), s_backend(sbackend), _vtg_config(vtg_config),
  _advanced_param_ptr(adv_ptr),
  has_confirmed_synthesized_invariant(
        adv_ptr && 
        adv_ptr->_inv_obj_ptr && 
        ! adv_ptr->_inv_obj_ptr->GetVlgConstraints().empty()),
  has_gussed_synthesized_invariant(
    adv_ptr && 
    adv_ptr->_candidate_inv_ptr && 
    ! adv_ptr->_candidate_inv_ptr->GetVlgConstraints().empty()),
  has_cex(
    adv_ptr && 
    adv_ptr->_cex_obj_ptr && 
    ! adv_ptr->_cex_obj_ptr->GetCex().empty()),
  _vext(
          [    ](const std::string& n) -> bool { return false; }, // TryFindIlaState(n)
          [    ](const std::string& n) -> bool { return false; }, // TryFindIlaInput(n)
          [this](const std::string& n) -> bool { return TryFindVlgState(n); }),
  property_counter(0),
  _bad_state(false)
{
  load_json(_rf_var_map_name, rf_vmap);
  load_json(_rf_cond_name, rf_cond);    
  sup_info.FromJson(rf_vmap);
  set_module_instantiation_name();

  has_rf_invariant =  ( IN("global invariants", rf_cond) && 
    ( rf_cond["global invariants"].is_array() &&
    rf_cond["global invariants"].size() != 0 ) ) ;
  
  // check vmap -- we just want to known their names
  if (not IN("models", rf_vmap) || not rf_vmap["models"].is_object()) {
    ILA_ERROR << "'model' field must exist in vmap and be a map of ILA/VERILOG "
                 "-> 'instance name' ";
    _bad_state = true;
  }
}


ExternalChcTargetGen::~ExternalChcTargetGen() {
  if (vlg_info_ptr)
    delete vlg_info_ptr;
}

const std::vector<std::string> & ExternalChcTargetGen::GetRunnableScriptName() const {
  return runnable_script_name;
}

const VlgTgtSupplementaryInfo & ExternalChcTargetGen::GetSupplementaryInfo() const {
  return sup_info;
}

std::string ExternalChcTargetGen::GetDesignUnderVerificationInstanceName() const {
  return _vlg_mod_inst_name;
}

// --------------------- for rf parsing (not very useful)  ----------------- //

// return npos if no comments in
static size_t find_comments(const std::string& line) {
  enum state_t { PLAIN, STR, LEFT } state, next_state;
  state = PLAIN;
  size_t ret = 0;
  for (const auto& c : line) {
    if (state == PLAIN) {
      if (c == '/')
        next_state = LEFT;
      else if (c == '"')
        next_state = STR;
      else
        next_state = PLAIN;
    } else if (state == STR) {
      if (c == '"' || c == '\n')
        next_state = PLAIN;
      // the '\n' case is in case we encounter some issue to find
      // the ending of a string
      else
        next_state = STR;
    } else if (state == LEFT) {
      if (c == '/') {
        ILA_ASSERT(ret > 0);
        return ret - 1;
      } else
        next_state = PLAIN;
    } else
      ILA_ASSERT(false);
    state = next_state;
    ++ret;
  }
  return std::string::npos;
}
/// load json from a file name to the given j
void ExternalChcTargetGen::load_json(const std::string& fname, nlohmann::json& j) {
  if (bad_state_return())
    return;
  std::ifstream fin(fname);
  if (!fin.is_open()) {
    ILA_ERROR << "Cannot read from file:" << fname;
    _bad_state = true;
    return;
  }
  // remove the comments
  std::string contents;
  std::string line;
  while(std::getline(fin,line)) {
    auto comment_begin = find_comments(line);
    if (comment_begin != std::string::npos)
      contents += line.substr(0,comment_begin);
    else
      contents += line;
    contents += "\n";
  }
  j = nlohmann::json::parse(contents);
  // fin >> j;
} // load_json

/// Get instance name from rfmap
void ExternalChcTargetGen::set_module_instantiation_name() {
  if (bad_state_return())
    return;
  // use the content in the refinement relations to determine the instance name
  auto& model_specified = rf_vmap["models"];
  for (auto&& name_description_pair : model_specified.items()) {
    if (name_description_pair.key() == "ILA") {
      // _ila_mod_inst_name = name_description_pair.value(); // do nothing
    } else if (name_description_pair.key() == "VERILOG") {
      _vlg_mod_inst_name = name_description_pair.value();
    } else
      ILA_ERROR << "Unknown model specification:" << name_description_pair.key()
                << " expect VERILOG or ILA";
  } // end-for
  // if unset
  if (_vlg_mod_inst_name == "") {
    ILA_WARN
        << "Verilog top module instance name not set, assuming to be VERILOG";
    _vlg_mod_inst_name = "VERILOG";
  }
} // set_module_instantiation_name

// --------------------- for adding constraints  ---------------------------- //
/// Return a new variable name for property
std::string ExternalChcTargetGen::new_property_id() {
  return std::string("__p") + std::to_string(property_counter++) + "__";
}

/// Test if a string represents a Verilog signal name
bool ExternalChcTargetGen::TryFindVlgState(const std::string& sname) {
  if (vlg_info_ptr->check_hierarchical_name_type(sname) !=
      VerilogInfo::hierarchical_name_type::NONE)
    return true;
  if (vlg_info_ptr->check_hierarchical_name_type(_vlg_mod_inst_name + "." +
                                                 sname) !=
      VerilogInfo::hierarchical_name_type::NONE)
    return true;
  return false;
}

/// Modify a token and record its use
std::string ExternalChcTargetGen::ModifyCondExprAndRecordVlgName(const VarExtractor::token& t) {
  // modify name and ...
  const auto& token_tp = t.first;
  const auto& sname = t.second;

  if (token_tp == VarExtractor::token_type::UNKN_S) {
    ILA_WARN << "In refinement relations: unknown reference to name:" << sname
             << " keep unchanged.";
    return sname;
  } else if (token_tp == VarExtractor::token_type::KEEP )
    return sname; // NC
  else if (token_tp == VarExtractor::token_type::NUM) {
    return sname; // NC
  } else if (token_tp == VarExtractor::token_type::ILA_S) {
    ILA_ERROR << sname << " is wrongly considered as ILA state";
    return sname;
  } else if (token_tp == VarExtractor::token_type::ILA_IN) {
    ILA_ERROR << sname << " is wrongly considered as ILA input";
    return sname;
  } else if (token_tp == VarExtractor::token_type::VLG_S) {
    // do nothing for JasperGold
    // will not add to the all_referred name, so will not modify verilog
    if (_backend == backend_selector::JASPERGOLD)
      return sname;
    std::string quote = "";
    auto left_p = sname.find('[');
    auto check_s = sname.substr(0, left_p);
    auto range_s = left_p != std::string::npos ? sname.substr(left_p) : "";
    auto range_underscore = ReplaceAll(ReplaceAll(range_s, "[", "_"), "]", "_");
    // if (_backend == backend_selector::COSA)
    //  quote = "'";

    if (vlg_info_ptr->check_hierarchical_name_type(check_s) !=
        VerilogInfo::hierarchical_name_type::NONE) {
      _all_referred_vlg_names.insert({check_s + range_s, ex_info_t(range_s)});
      auto remove_dot_name = ReplaceAll(check_s, ".", "__DOT__");
      // Convert the check_s to
      return quote + remove_dot_name + quote + range_underscore;
    }
    if (vlg_info_ptr->check_hierarchical_name_type(_vlg_mod_inst_name + "." +
                                                   check_s) !=
        VerilogInfo::hierarchical_name_type::NONE) {
      _all_referred_vlg_names.insert(
          {_vlg_mod_inst_name + "." + check_s + range_s, ex_info_t(range_s)});
      auto remove_dot_name = ReplaceAll(check_s, ".", "__DOT__");
      return quote + _vlg_mod_inst_name + "__DOT__" + remove_dot_name + quote +
             range_underscore;
    }
    ILA_ASSERT(false)
        << "Implementation bug: should not be reachable. token_type: VLG_S";
    return sname;
  }
  ILA_ASSERT(false)
      << "Implementation bug: should not reachable. Caused by token_type:"
      << token_tp;
  return sname;
} // ModifyCondExprAndRecordVlgName

/// Parse and modify a condition string
std::string ExternalChcTargetGen::ReplExpr(const std::string& expr, bool force_vlg_sts) {
  return _vext.Replace(expr, force_vlg_sts,
                       [this](const VarExtractor::token& t) {
                         return ModifyCondExprAndRecordVlgName(t);
                       });
}

// --------------------- for export Verilog ---------------------------- //

// some short cuts
#define ADD_WIRE(s,w) (wire_defs.insert(std::make_pair((s),(w))))
#define ADD_OUTPUT(s,w) (output_defs.insert(std::make_pair((s),(w))))
#define ADD_INPUT(s,w) (input_defs.insert(std::make_pair((s),(w))))
#define ADD_ASSIGN(s,v) (stmt_defs.push_back( "assign " + (s) + " = " + (v) + ";" ))

/// Add an assumption
void ExternalChcTargetGen::add_an_assumption(const std::string& aspt,
                                const std::string& dspt) {
  auto assumption_wire_name = dspt + new_property_id();
  ADD_WIRE(assumption_wire_name, 1);
  ADD_OUTPUT(assumption_wire_name,1);
  ILA_ASSERT(aspt.find(".") == std::string::npos)
      << "aspt:" << aspt << " contains unfriendly dot.";
  ADD_ASSIGN(assumption_wire_name, aspt);
  assume_props.push_back(assumption_wire_name);
}

/// Add an assertion
void ExternalChcTargetGen::add_an_assertion(const std::string& asst,
                              const std::string& dspt) {
  auto assertion_wire_name = dspt + new_property_id();
  ADD_WIRE(assertion_wire_name, 1);
  ADD_OUTPUT(assertion_wire_name,1);
  ILA_ASSERT(asst.find(".") == std::string::npos)
      << "asst:" << asst << " contains unfriendly dot.";
  ADD_ASSIGN(assertion_wire_name, asst);
  assert_props.push_back(assertion_wire_name);
}


void ExternalChcTargetGen::add_inv_obj_as_assertion( InvariantObject * inv_obj) {
  for (auto && name_expr_pair : inv_obj->GetExtraVarDefs() ){
    ADD_WIRE(std::get<0>(name_expr_pair), std::get<2>(name_expr_pair) );
    ADD_OUTPUT(std::get<0>(name_expr_pair), std::get<2>(name_expr_pair));
    ADD_ASSIGN(std::get<0>(name_expr_pair), 
      ReplExpr(std::get<1>(name_expr_pair), true) );
  }
  for (auto && name_w_pair : inv_obj->GetExtraFreeVarDefs()) {
    ADD_WIRE(name_w_pair.first, name_w_pair.second);
    ADD_INPUT(name_w_pair.first, name_w_pair.second);
  }
  for (auto && inv_expr : inv_obj->GetVlgConstraints()) {
    auto new_cond = ReplExpr( inv_expr, true );
    add_an_assertion( new_cond , "invariant_assert");
  }
} // add_inv_obj_as_assertion


void ExternalChcTargetGen::add_inv_obj_as_assumption( InvariantObject * inv_obj) {
    // do you need to provide sub-module instance name?
    for (auto && name_expr_pair : inv_obj->GetExtraVarDefs() ){
      ADD_WIRE(std::get<0>(name_expr_pair), std::get<2>(name_expr_pair));
      ADD_OUTPUT(std::get<0>(name_expr_pair), std::get<2>(name_expr_pair));
      ADD_ASSIGN(std::get<0>(name_expr_pair), 
        ReplExpr(std::get<1>(name_expr_pair), true) );
    }
    for (auto && name_w_pair : inv_obj->GetExtraFreeVarDefs()) {
      ADD_WIRE(name_w_pair.first, name_w_pair.second);
      ADD_INPUT(name_w_pair.first, name_w_pair.second);
    }
    for (auto && inv_expr : inv_obj->GetVlgConstraints()) {
      auto new_cond = ReplExpr( inv_expr, true );
      add_an_assumption( new_cond , "invariant_assume");
    }
} // add_inv_obj_as_assumption

void ExternalChcTargetGen::add_rf_inv_as_assumption() {
  if ( has_rf_invariant ) {    
    for (auto& cond : rf_cond["global invariants"]) {
      auto new_cond = ReplExpr(cond.get<std::string>(), true);
      add_an_assumption(new_cond, "invariant_assume"); // without new var added
    } // for inv in global invariants field
  }
} // add_rf_inv_as_assumption

void ExternalChcTargetGen::add_rf_inv_as_assertion() {
  // the provided invariants
  if (has_rf_invariant)
    for (auto& cond : rf_cond["global invariants"]) {
      auto new_cond = ReplExpr(cond.get<std::string>(), true); // force vlg state
      add_an_assertion("(" + new_cond + ")", "invariant_assert");
    }
} // add_rf_inv_as_assertion

void ExternalChcTargetGen::add_property(const std::string &precond) {
  if (has_cex) {
    auto inv = _advanced_param_ptr->_cex_obj_ptr->GenInvAssert("");
    {
      std::ofstream fout(os_portable_append_dir(_output_path, "cex.tcl"));
      if (!precond.empty())
        fout << "assert { " << precond << "|->" << inv << " }; " << std::endl;
      else
        fout << "assert { " << inv << " }; " << std::endl;
    }
    auto new_cond = ReplExpr(inv, true);
    if (!precond.empty())
      add_an_assertion("! (" + precond + ") || ( ~(" + new_cond + ") )", "cex_nonreachable_assert");
    else
      add_an_assertion("~(" + new_cond + ")", "cex_nonreachable_assert");
    /// add rf_assumption
    if (_vtg_config.InvariantSynthesisReachableCheckKeepOldInvariant) {
      add_rf_inv_as_assumption();
      if (has_confirmed_synthesized_invariant)
        add_inv_obj_as_assumption(_advanced_param_ptr->_inv_obj_ptr);
      if (has_gussed_synthesized_invariant) {
        ILA_WARN << "Using guessed invariants also, please check to confirm them!";
        add_inv_obj_as_assumption(_advanced_param_ptr->_candidate_inv_ptr);
      }
    }
    /// add 
  } else if (has_gussed_synthesized_invariant) { 
    // if this is general design invariant checking checking
    add_inv_obj_as_assertion(_advanced_param_ptr->_candidate_inv_ptr);

    if(has_confirmed_synthesized_invariant)
      add_inv_obj_as_assumption(_advanced_param_ptr->_inv_obj_ptr);
    add_rf_inv_as_assumption();
    /*
    if(has_confirmed_synthesized_invariant)
      add_inv_obj_as_assertion(_advanced_param_ptr->_inv_obj_ptr);
    add_rf_inv_as_assertion();
    */
  }
  else
    ILA_ASSERT(false) << "Unknown invariant handling for design_only target!";
  
}


void ExternalChcTargetGen::register_extra_io_wire() {
  for (auto&& refered_vlg_item : _all_referred_vlg_names) {

    auto idx = refered_vlg_item.first.find("[");
    auto removed_range_name = refered_vlg_item.first.substr(0, idx);
    auto vlg_sig_info = vlg_info_ptr->get_signal(removed_range_name, sup_info.width_info);

    auto vname = ReplaceAll(
        ReplaceAll(ReplaceAll(refered_vlg_item.first, ".", "__DOT__"), "[",
                   "_"),
        "]", "_");
    // + ReplaceAll(ReplaceAll(refered_vlg_item.second.range, "[","_"),"]","_");
    // // name for verilog
    auto width = vlg_sig_info.get_width();

    ADD_WIRE(vname, width); // keep
    ADD_OUTPUT(vname, width);  // add as output of the wrapper
    implport_def.insert(std::make_pair(vname, vname));
    // these will be connected to the verilog module, so register as extra wires
    // so, later they will be connected
  }
} // ConstructWrapper_register_extra_io_wire



/// convert a widith to a verilog string
static std::string WidthToRange(int w) {
  if (w > 1)
    return std::string("[") + std::to_string(w - 1) + ":0]";
  return "";
}

void ExternalChcTargetGen::wrapper_tmpl_substitute(const std::string& wrapper_name, const std::string &wrapper_tmpl_name)
{
  // read in the template
  auto tmpl_full_name = os_portable_append_dir(_output_path, wrapper_tmpl_name);
  auto wrapper_full_name = os_portable_append_dir(_output_path, wrapper_name);
  std::ifstream tmpl_in(tmpl_full_name);
  if (not tmpl_in.is_open()) { ILA_ERROR << "Unable to read from:" << tmpl_full_name; return;}
  std::stringstream tmpl_txt;
  tmpl_txt << tmpl_in.rdbuf();
  auto tmpl = tmpl_txt.str();
  if (_vtg_config.PortDeclStyle == _vtg_config.OLD) {
    ILA_ERROR_IF(not S_IN("%ports%", tmpl))   << "Require %ports% field!";
    ILA_ERROR_IF(not S_IN("%wires%",   tmpl)) << "Require %wires% field!";
    ILA_ERROR_IF(not S_IN("%inputs%",  tmpl)) << "Require %inputs% field!";
    ILA_ERROR_IF(not S_IN("%outputs%", tmpl)) << "Require %outputs% field!";

    std::string wires;
    std::string inputs;
    std::string outputs;
    std::string ports;

    std::set<std::string> port_wires;

    for(auto && wn : input_defs) {
      inputs += "input " + WidthToRange(wn.second) + " " + wn.first + ";\n";
      ILA_ERROR_IF(IN(wn.first, port_wires)) << "Redeclaration of " << wn.first;
      port_wires.insert(wn.first);
    }
    for(auto && wn : output_defs) {
      outputs += "output " + WidthToRange(wn.second) + " " + wn.first + ";\n";
      ILA_ERROR_IF(IN(wn.first, port_wires)) << "Redeclaration of " << wn.first;
      port_wires.insert(wn.first);
    }
    for(auto && wn : wire_defs) {
      wires += "wire " + WidthToRange(wn.second) + " " + wn.first + ";\n";
    }
    for (auto && p : port_wires)
      ports += ",\n" + p;
    
    tmpl = ReplaceAll(tmpl, "%ports%" ,   ports);
    tmpl = ReplaceAll(tmpl, "%inputs%" ,  inputs);
    tmpl = ReplaceAll(tmpl, "%outputs%" , outputs);
    tmpl = ReplaceAll(tmpl, "%wires%" ,   wires);
  } else if (_vtg_config.PortDeclStyle == _vtg_config.NEW) {

    ILA_ERROR_IF(not S_IN("%ports%", tmpl))   << "Require %ports% field!";
    ILA_ERROR_IF(not S_IN("%wires%",   tmpl)) << "Require %wires% field!";

    std::string wires;
    std::string ports;

    std::set<std::string> port_wires;

    for(auto && wn : input_defs) {
      ports += ",\n input " + WidthToRange(wn.second) + " " + wn.first;
      ILA_ERROR_IF(IN(wn.first, port_wires)) << "Redeclaration of " << wn.first;
      port_wires.insert(wn.first);
    }
    for(auto && wn : output_defs) {
      ports += ",\n output " + WidthToRange(wn.second) + " " + wn.first;
      ILA_ERROR_IF(IN(wn.first, port_wires)) << "Redeclaration of " << wn.first;
      port_wires.insert(wn.first);
    }
    for(auto && wn : wire_defs) {
      if (IN(wn.first, port_wires))
        continue; // no need to redeclare
      wires += "wire " + WidthToRange(wn.second) + " " + wn.first + ";\n";
    }
    //for (auto && p : port_wires)
    //  ports += ",\n" + p;
    
    tmpl = ReplaceAll(tmpl, "%ports%" ,   ports);
    tmpl = ReplaceAll(tmpl, "%wires%" ,   wires);
  } else
    ILA_ASSERT(false) << "Not able to autodetermine the port declaration style, future work";

  { // replace stmt assumes asserts
    ILA_ERROR_IF(not S_IN("%stmts%",   tmpl)) << "Require %stmts% field!";
    ILA_ERROR_IF(not S_IN("%assumes%", tmpl)) << "Require %assumes% field!";
    ILA_ERROR_IF(not S_IN("%asserts%", tmpl)) << "Require %asserts% field!";
    std::string stmts;
    std::string assumes;
    std::string asserts;
    for (auto && s : stmt_defs)
      stmts += s + "\n";
    for (auto && a : assert_props)
      asserts += "assert property (" + a + ");\n";
    for (auto && a : assume_props)
      assumes += "assume property (" + a + ");\n";
    
    tmpl = ReplaceAll(tmpl, "%stmts%" ,   stmts);
    tmpl = ReplaceAll(tmpl, "%assumes%" , assumes);
    tmpl = ReplaceAll(tmpl, "%asserts%" , asserts);
  } // replace stmt assumes asserts

  { // replace , \n .n(n)
    ILA_ERROR_IF(not S_IN("%implports%",tmpl)) << "Require %implports% field!";
    std::string implports;
    for (auto && arg : implport_def) {
      implports += ",\n."+arg.first+"(" + arg.second+")";
    }
    tmpl = ReplaceAll(tmpl, "%implports%", implports);
  }

  std::ofstream wrapper_out(wrapper_full_name);
  if (not wrapper_out.is_open()) { ILA_ERROR << "Unable to write to:" << wrapper_full_name; return;}
  
  wrapper_out << tmpl;    
} // wrapper_tmpl_substitute


void ExternalChcTargetGen::export_modify_verilog(const std::string& wrapper_name) {
  // collect all locations: filename -> lineno
  // open, read, count and write
  // if it is a port name, we will ask user to specify its upper level
  // signal name
  VerilogModifier vlg_mod(vlg_info_ptr,
    static_cast<VerilogModifier::port_decl_style_t>(_vtg_config.PortDeclStyle),
    _vtg_config.CosaAddKeep, sup_info.width_info);

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
  auto tmp_fn = os_portable_append_dir(_output_path, wrapper_name);
  // now let's do the job
  for (auto&& fn : _vlg_impl_srcs) {
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
  if (_vlg_impl_include_path.size() != 0) {
    // copy the files and specify the -I commandline to the run.sh
    for (auto&& include_path : _vlg_impl_include_path)
      os_portable_copy_dir(include_path, _output_path);
  }  
} // export_modify_verilog

void ExternalChcTargetGen::ConstructWrapper(
  const std::string& wrapper_name, const std::string &wrapper_tmpl_name,
  const std::string & precond) {

  top_file_name = wrapper_name;

  // verilog info
  if (vlg_info_ptr)
    delete vlg_info_ptr;

  vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs,
                                 _vlg_mod_inst_name, _vlg_impl_top_name);

  if (vlg_info_ptr == NULL or vlg_info_ptr->in_bad_state()) {
    ILA_ERROR << "Unable to generate targets. Verilog parser failed.";
    return; //
  }
  // add cex / (if no cex) candidate ... prop to check
  add_property(precond);
  // register the wires...
  register_extra_io_wire();
  // replace text &
  wrapper_tmpl_substitute(wrapper_name, wrapper_tmpl_name);
  // copy files/copy include
  export_modify_verilog(wrapper_name); 
}

// --------------------- for CHC template ---------------------------- //

// initialize templates
static std::string chcGenerateSmtScript_wo_Array = R"***(
hierarchy -check
proc
opt
opt_expr -mux_undef
opt
opt
%flatten%
%setundef -undriven -expose%
memory -nordff
proc
opt;;
)***";


static std::string inv_syn_tmpl_datatypes = R"***(
;----------------------------------------
;  Single Inductive Invariant Synthesis
;  Generated from ILAng
;----------------------------------------
(set-option :fp.engine spacer)


%%

;(declare-rel INIT (|%1%_s|))
;(declare-rel T (|%1%_s|) (|%1%_s|))
(declare-rel INV (|%1%_s|))
(declare-rel fail ())


(declare-var |__BI__| |%1%_s|)
(declare-var |__I__| |%1%_s|)

(declare-var |__S__| |%1%_s|)
(declare-var |__S'__| |%1%_s|)

; --------------------------------
; note if you want it a bit faster
; if can try removing wrapper-u in rule 1
; or remove the assume previous invariants
; --------------------------------

; init => inv
(rule (=> (and 
  (|%1%_n rst| |__BI__|)
  ;(|%1%_u| |__BI__|)
  ;(|%1%_u| |__I__|)
  <!>(|%1%_h| |__BI__|)<!>
  <!>(|%1%_h| |__I__|)<!>
  (|%1%_t| |__BI__| |__I__|))
  (INV |__I__|)))

; inv /\ T => inv
(rule (=> (and 
  (INV |__S__|) 
  (|%1%_u| |__S__|)
  (|%1%_u| |__S'__|)
  <!>(|%1%_h| |__S__|)<!>
  <!>(|%1%_h| |__S'__|)<!>
  (|%1%_t| |__S__| |__S'__|)) 
  (INV |__S'__|)))

; inv /\ ~p => \bot
(rule (=> (and 
  (INV |__S__|) 
  (|%1%_u| |__S__|)
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

%%

(declare-rel INV %WrapperDataType%)
(declare-rel fail ())

%BeforeInitVar%
%InitVar%
;(declare-var |__BI__state| Type)
;(declare-var |__I__state|  Type)

%State%
%StatePrime%
;(declare-var |__S__state| Type)
;(declare-var |__S'__state| Type)

; same for flattened

; init => inv
(rule (=> (and 
  (|%WrapperName%_n rst| %BIs%) 
  <!>(|%WrapperName%_h| %BIs%)<!> 
  <!>(|%WrapperName%_h| %Is%)<!>
  (|%WrapperName%_t| %BIs% %Is%)) 
  (INV %Is%)))

; inv /\ T => inv
(rule (=> (and 
  (INV %Ss%) 
  (|%WrapperName%_u| %Ss%) 
  (|%WrapperName%_u| %Sps%) 
  <!>(|%WrapperName%_h| %Ss%)<!>
  <!>(|%WrapperName%_h| %Sps%)<!>
  (|%WrapperName%_t| %Ss% %Sps%)) 
  (INV %Sps%)))

; inv /\ ~p => \bot
(rule (=> (and 
  (INV %Ss%)
  (|%WrapperName%_u| %Ss%) 
  <!>(|%WrapperName%_h| %Ss%)<!>
  (not (|%WrapperName%_a| %Ss%))) 
  fail))

; (query fail :print-certificate true)

)***";

// %WrapperName%
// %WrapperDataType%
// %BeforeInitVar%
// %InitVar%
// %State%
// %StatePrime%
// %BIs% %Is%  %Ss% %Sps%
static std::string RewriteDatatypeChc(
  const std::string & tmpl, const std::vector<smt::state_var_t> & dt,
  const std::string & wrapper_mod_name) {
  
  std::string chc = tmpl;

  std::vector<smt::var_type> inv_tps;
  smt::YosysSmtParser::convert_datatype_to_type_vec(dt, inv_tps);
  auto WrapperDataType = smt::var_type::toString(inv_tps);

  // %BeforeInitVar%
  // %InitVar%
  // %State%
  // %StatePrime%
  // declare-var s ...
  std::string BeforeInitVar;
  std::string InitVar;
  std::string State;
  std::string StatePrime;
  // %BIs% %Is%  %Ss% %Sps%
  std::string BIs;
  std::string Is;
  std::string Ss;
  std::string Sps;
  bool first = true;

  std::set<std::string> name_set; // avoid repetition
  for (auto && st : dt) {
    auto st_name = st.verilog_name.back() == '.' || st.verilog_name.empty() ? st.internal_name : st.verilog_name;
    st_name = ReplaceAll(st_name, "|", ""); // remove its ||
    // check no repetition is very important!
    ILA_ASSERT(not IN(st_name, name_set)) << "Bug: name repetition!";
    ILA_ASSERT(st._type._type != smt::var_type::tp::Datatype);
    name_set.insert(st_name);
    auto type_string = st._type.toString();
    BeforeInitVar += "(declare-var |BI_" + st_name + "| " + type_string + ")\n";
    InitVar       += "(declare-var |I_"  + st_name + "| " + type_string + ")\n";
    State         += "(declare-var |S_"  + st_name + "| " + type_string + ")\n";
    StatePrime    += "(declare-var |S'_" + st_name + "| " + type_string + ")\n";

    if(not first) {
      BIs += " "; Is  += " "; Ss  += " "; Sps += " ";
    }
    first = false;
    BIs += "|BI_" + st_name + "|";
    Is  += "|I_"  + st_name + "|";
    Ss  += "|S_"  + st_name + "|";
    Sps += "|S'_" + st_name + "|";
  }
  // Replacement
  chc = ReplaceAll(chc, "%WrapperName%",     wrapper_mod_name);
  chc = ReplaceAll(chc, "%WrapperDataType%", WrapperDataType);
  chc = ReplaceAll(chc, "%BeforeInitVar%",   BeforeInitVar);
  chc = ReplaceAll(chc, "%InitVar%",         InitVar);
  chc = ReplaceAll(chc, "%State%",           State);
  chc = ReplaceAll(chc, "%StatePrime%",      StatePrime);
  chc = ReplaceAll(chc, "%BIs%",             BIs);
  chc = ReplaceAll(chc, "%Is%",              Is);
  chc = ReplaceAll(chc, "%Ss%",              Ss);
  chc = ReplaceAll(chc, "%Sps%",             Sps);

  return chc;  
} // RewriteDatatypeChc

// --------------------- for export CHC ---------------------------- //

/// generate the wrapper's smt first
void ExternalChcTargetGen::design_only_gen_smt(
  const std::string & smt_name,
  const std::string & ys_script_name) {
  
  auto ys_output_full_name =
      os_portable_append_dir(_output_path, "__yosys_exec_result.txt");
  { // export to ys_script_name
    std::ofstream ys_script_fout( ys_script_name );
    
    std::string write_smt2_options = " -mem -bv "; // future work : -stbv, or nothing
    if (_vtg_config.YosysSmtStateSort == _vtg_config.DataSort)
      write_smt2_options += "-stdt ";
    else if (_vtg_config.YosysSmtStateSort == _vtg_config.BitVec)
      write_smt2_options += "-stbv ";
    else
      ILA_ASSERT(false) << "Unsupported smt state sort encoding:" << _vtg_config.YosysSmtStateSort;


    ys_script_fout << "read_verilog -sv " 
      << os_portable_append_dir( _output_path , top_file_name ) << std::endl;
    ys_script_fout << "prep -top " << top_mod_name << std::endl;
    ys_script_fout << 
      ReplaceAll(
      ReplaceAll(chcGenerateSmtScript_wo_Array, "%flatten%", 
        _vtg_config.YosysSmtFlattenHierarchy ? "flatten;" : ""),
        "%setundef -undriven -expose%", _vtg_config.YosysUndrivenNetAsInput ? "setundef -undriven -expose" : "")
        ;
    ys_script_fout << "write_smt2"<<write_smt2_options 
      << smt_name;   
  } // finish writing

  std::string yosys = "yosys";

  if (not _vtg_config.YosysPath.empty())
    yosys = os_portable_append_dir(_vtg_config.YosysPath, yosys);

  // execute it
  std::vector<std::string> cmd;
  cmd.push_back(yosys); cmd.push_back("-s"); cmd.push_back(ys_script_name);
  auto res = os_portable_execute_shell( cmd, ys_output_full_name );
    ILA_ERROR_IF( res.failure != res.NONE  )
      << "Executing Yosys failed!";
    ILA_ERROR_IF( res.failure == res.NONE && res.ret != 0)
      << "Yosys returns error code:" << res.ret;
} // design_only_gen_smt

void ExternalChcTargetGen::convert_smt_to_chc_bitvec(
    const std::string & smt_fname, const std::string & chc_fname, 
    const std::string & wrapper_mod_name) {
  
  std::stringstream ibuf;
  { // read file
    std::ifstream smt_fin( smt_fname );
    if(not smt_fin.is_open()) {
      ILA_ERROR << "Cannot read from " << smt_fname;
      return;
    }
    ibuf << smt_fin.rdbuf();
  } // end read file

  std::string smt_converted;
  smt_converted = ibuf.str();

  std::string chc;

  chc = inv_syn_tmpl_datatypes;
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
    if (not chc_fout.is_open()) {
      ILA_ERROR << "Error writing to : "<< chc_fname;
      return;
    }
    chc_fout << chc;
  } // end write file
}
  

void ExternalChcTargetGen::convert_smt_to_chc_datatype(const std::string & smt_fname, const std::string & chc_fname) {
  
  std::stringstream ibuf;
  { // read file
    std::ifstream smt_fin( smt_fname );
    if(not smt_fin.is_open()) {
      ILA_ERROR << "Cannot read from " << smt_fname;
      return;
    }
    ibuf << smt_fin.rdbuf();
  } // end read file

  std::string smt_converted;
  design_smt_info = std::make_shared<smt::YosysSmtParser> (ibuf.str());
  if (_vtg_config.YosysSmtFlattenDatatype) {
    design_smt_info->BreakDatatypes();
    //smt_rewriter.AddNoChangeStateUpdateFunction();
    smt_converted = design_smt_info->Export();
  } else {
    smt_converted = ibuf.str();
  }

  std::string wrapper_mod_name = design_smt_info->get_module_def_orders().back();
  // construct the template
  ILA_ASSERT(not (_vtg_config.YosysSmtFlattenDatatype && _vtg_config.YosysSmtStateSort != _vtg_config.DataSort ))
    << "FlattenDatatype can only be used if choosing datatype state encoding";

  std::string chc;
  if (_vtg_config.YosysSmtFlattenDatatype) {
    const auto & datatype_top_mod = design_smt_info->get_module_flatten_dt(wrapper_mod_name);
    auto tmpl = inv_syn_tmpl_wo_datatypes;
    tmpl = ReplaceAll(tmpl, "<!>(|%WrapperName%_h| %Ss%)<!>"  ,_vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%WrapperName%_h| %Ss%)" );
    tmpl = ReplaceAll(tmpl, "<!>(|%WrapperName%_h| %Sps%)<!>" ,_vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%WrapperName%_h| %Sps%)" );
    tmpl = ReplaceAll(tmpl, "<!>(|%WrapperName%_h| %BIs%)<!>" ,_vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%WrapperName%_h| %BIs%)" );
    tmpl = ReplaceAll(tmpl, "<!>(|%WrapperName%_h| %Is%)<!>"  ,_vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%WrapperName%_h| %Is%)" );
    chc = RewriteDatatypeChc(
      tmpl,
      datatype_top_mod, wrapper_mod_name);
    chc = ReplaceAll(chc, "%%", smt_converted );
  } else {
    chc = inv_syn_tmpl_datatypes;
    chc = ReplaceAll(chc, "<!>(|%1%_h| |__BI__|)<!>", _vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%1%_h| |__BI__|)");
    chc = ReplaceAll(chc, "<!>(|%1%_h| |__I__|)<!>" , _vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%1%_h| |__I__|)");
    chc = ReplaceAll(chc, "<!>(|%1%_h| |__S__|)<!>" , _vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%1%_h| |__S__|)");
    chc = ReplaceAll(chc, "<!>(|%1%_h| |__S'__|)<!>", _vtg_config.YosysSmtFlattenHierarchy ? "" : "(|%1%_h| |__S'__|)");
    chc = ReplaceAll(chc,"%1%", wrapper_mod_name);
    chc = ReplaceAll(chc, "%%", smt_converted );
  } // end of ~_vtg_config.YosysSmtFlattenDatatype -- no convert

  { // (query fail :print-certificate true)
    if (generate_proof)
      chc += "\n(query fail :print-certificate true)\n";
    else
      chc += "\n(query fail)\n";
  }

  { // write file
    std::ofstream chc_fout(chc_fname);
    if (not chc_fout.is_open()) {
      ILA_ERROR << "Error writing to : "<< chc_fname;
      return;
    }
    chc_fout << chc;
  } // end write file

} // convert_smt_to_chc_datatype
  
void ExternalChcTargetGen::export_script(const std::string& script_name, const std::string& cnf_name) {
  runnable_script_name.clear();

  auto fname = os_portable_append_dir(_output_path, script_name);
  std::ofstream fout(fname);
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing to file:" << fname;
    return;
  }
  fout << "#!/bin/bash" << std::endl;
  //fout << "trap \"trap - SIGTERM && kill -- -$$\" SIGINT SIGTERM"<<std::endl;

  std::string runable;
  std::string redirect;
  if (s_backend == synthesis_backend_selector::Z3) {
    runable = "z3";
    if (not _vtg_config.Z3Path.empty())
      runable = os_portable_append_dir(_vtg_config.Z3Path, runable);
  }
  else if(s_backend == synthesis_backend_selector::FreqHorn) {
    runable = "bv";
    if (not _vtg_config.FreqHornPath.empty())
      runable = os_portable_append_dir(_vtg_config.FreqHornPath, runable);

    for (auto && op : _vtg_config.FreqHornOptions)
      runable += " " + op;
    
    if (! S_IN("--grammar ", runable))
      ILA_ASSERT(!cnf_name.empty()) << "must provide cnf name for FreqHorn backend.";


    if (_vtg_config.FreqHornHintsUseCnfStyle) {
      if (!cnf_name.empty())
        runable += " --cnf " + cnf_name;
    } else {
      runable += " --grammar-file=\""+cnf_name+"\"";
      runable += " --chc-file=\""+chc_prob_fname+"\"";
    }
    redirect = " 2> ../freqhorn.result";
  }

  if (chc_prob_fname != "") {
    if (s_backend == synthesis_backend_selector::FreqHorn &&  ! _vtg_config.FreqHornHintsUseCnfStyle)
      fout << runable << redirect << std::endl;
    else
      fout << runable << " "<< chc_prob_fname << redirect  << std::endl;
  }
  else
    fout << "echo 'Nothing to check!'" << std::endl;

  runnable_script_name.push_back(fname);
} // export_script

std::shared_ptr<smt::YosysSmtParser> ExternalChcTargetGen::GenerateChc(const std::string& chc_name,
    const std::string & script_name, const std::string& cnf_name) {

  ILA_WARN_IF(!os_portable_mkdir(_output_path) ) << "Cannot create folder: " << _output_path;
  
  chc_prob_fname = chc_name;
  // export 1. yosysscript
  design_only_gen_smt(
    os_portable_append_dir(_output_path, "__design_smt.smt2"),
    os_portable_append_dir(_output_path, "__gen_smt_script.ys"));
  // run yosys --> smt
  // parse smt --> chc
  if (_vtg_config.YosysSmtStateSort == _vtg_config.DataSort)
    convert_smt_to_chc_datatype (
      os_portable_append_dir(_output_path, "__design_smt.smt2"),
      os_portable_append_dir(_output_path, chc_name));
  else if (_vtg_config.YosysSmtStateSort == _vtg_config.BitVec)
    convert_smt_to_chc_bitvec(
      os_portable_append_dir(_output_path, "__design_smt.smt2"),
      os_portable_append_dir(_output_path, chc_name), "wrapper");
  else
    ILA_ASSERT(false) << "I don't know how to generate CHC encoding";
  // generate chc run script
  export_script(script_name, cnf_name);
  // inv_extract need this!
  return design_smt_info;
}



void ExternalChcTargetGen::export_cnf(const InvariantInCnf & cnf, const std::string& cnf_fn) const {
  auto fn = os_portable_append_dir(_output_path, cnf_fn);
  std::ofstream fout(fn);
  if (!fout.is_open()) {
    ILA_ERROR<<"Unable to open " << fn << " for write.";
    return;
  }

  fout << cnf.GetCnfs().size() << std::endl; //# of clauses
  for (auto && clause : cnf.GetCnfs()){
    // for each clause
    fout << clause.second.size()<< std::endl; //# of lterals
    for (auto && literal : clause.second)
      // complement, var, bit-idx
      fout << std::get<1>(literal)  << ' ' << std::get<2>(literal) << ' ' << std::get<0>(literal) << std::endl;
  }
}


void ExternalChcTargetGen::export_coci(const InvariantInCnf & cnf, const std::string& cnf_fn) const {
  auto fn = os_portable_append_dir(_output_path, cnf_fn);
  std::ofstream fout(fn);
  if (!fout.is_open()) {
    ILA_ERROR<<"Unable to open " << fn << " for write.";
    return;
  }
  
  std::vector<std::string> states;
  for (auto && clause : cnf.GetCnfs()){
    // for each clause
    for (auto && literal : clause.second)
      // complement, var, bit-idx
      states.push_back("S_" + std::get<1>(literal) );
  }
  fout << "CTRL-STATE: " << Join(states, ", ") << std::endl;
  fout << "DATA-OUT: " << Join(states, ", ") << std::endl << std::endl;
}

void ExternalChcTargetGen::ExportCnf(const InvariantInCnf & inv_cnf, const std::string& cnf_name) const {

  if (_vtg_config.FreqHornHintsUseCnfStyle)
    export_cnf(inv_cnf, cnf_name);
  else
    export_coci(inv_cnf, cnf_name);
}



// ----------------------- BAD STATE -------------------- //
/// If it is bad state, return true and display a message
bool ExternalChcTargetGen::bad_state_return(void) {
  ILA_ERROR_IF(_bad_state)
      << "ExternalChcTargetGen is in a bad state, cannot proceed.";
  return _bad_state;
} // bad_state_return


}; // namespace ilang

