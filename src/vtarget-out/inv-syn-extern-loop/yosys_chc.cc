/// \file Source for Externally Provided Target for inv-syn
/// to generate a synthesis target with (externally) provided wrapper template
/// instead of constructing the template ourselves
// Hongce Zhang (hongcez@princeton.edu)

#include <ilang/util/str_util.h>
#include <ilang/util/log.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/vtarget-out/inv-syn-extern-loop/yosys_chc.h>

#include <iostream>

namespace ilang{


ExternalChcTargetGen::ExternalChcTargetGen(const std::vector<std::string>& implementation_include_path,
                const std::vector<std::string>& implementation_srcs,
                const std::string& implementation_top_module,
                const std::string& refinement_variable_mapping,
                const std::string& refinement_conditions,
                const std::string& output_path,
                backend_selector backend, const vtg_config_t& vtg_config,
                advanced_parameters_t * adv_ptr = NULL):
  _vlg_impl_include_path(implementation_include_path),
  _vlg_impl_srcs(implementation_srcs),
  _vlg_impl_top_name(implementation_top_module),
  _rf_var_map_name(refinement_variable_mapping),
  _rf_cond_name(refinement_conditions),
  _output_path(output_path),
  vlg_info_ptr(NULL), // not creating it now, because we don't have the info to do so
  _backend(backend), _vtg_config(vtg_config),
  _advanced_param_ptr(adv_ptr),
  has_confirmed_synthesized_invariant(
        adv_ptr && 
        adv_ptr->_inv_obj_ptr && 
        ! adv_ptr->_inv_obj_ptr->GetVlgConstraints().empty()),
  has_gussed_synthesized_invariant(
    adv_ptr && 
    adv_ptr->_candidate_inv_ptr && 
    ! adv_ptr->_candidate_inv_ptr->GetVlgConstraints().empty()),
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
    rf_cond["global invariants"].is_array() ||
    rf_cond["global invariants"].size() != 0  ) ;
  
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

// --------------------- for rf parsing (not very useful)  ----------------- //

// return npos if no comments in
static size_t find_comments(const std::string &line) {
  enum state_t {PLAIN, STR, LEFT }  state, next_state;
  state = PLAIN;
  size_t ret = 0;
  for (const auto & c : line) {
    if (state == PLAIN) {
      if (c == '/')
        next_state = LEFT;
      else
        next_state = PLAIN;
    } else if (state == STR) {
      if (c == '"')
        next_state = PLAIN;
      else
        next_state = STR;
    } else if (state == LEFT) {
      if (c == '/') {
        ILA_ASSERT(ret > 0);
        return ret-1;
      }
      else
        next_state = PLAIN;
    } else
      ILA_ASSERT(false);
    state = next_state;
    ++ ret;
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
std::string ExternalChcTargetGen::ReplExpr(const std::string& expr, bool force_vlg_sts = false) {
  return _vext.Replace(expr, force_vlg_sts,
                       [this](const VarExtractor::token& t) {
                         return ModifyCondExprAndRecordVlgName(t);
                       });
}


// --------------------- for export purpose  ---------------------------- //

// some short cuts
#define ADD_WIRE(s,w) (wire_defs.insert(std::make_pair((s),(w))))
#define ADD_OUTPUT(s,w) (output_defs.insert(std::make_pair((s),(w))))
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
  assume_props.push_back(assertion_wire_name);
}

// ----------------------- BAD STATE -------------------- //
/// If it is bad state, return true and display a message
bool ExternalChcTargetGen::bad_state_return(void) {
  ILA_ERROR_IF(_bad_state)
      << "ExternalChcTargetGen is in a bad state, cannot proceed.";
  return _bad_state;
} // bad_state_return


}; // namespace ilang

