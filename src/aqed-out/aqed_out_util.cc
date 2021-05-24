/// \file Utility for generating information to support
/// AQED -- implementation
// --- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/vtarget-out/gen_util.h>
#include <ilang/aqed-out/aqed_out_impl.h>

namespace ilang {


bool AQedInfoGeneratorImpl::bad_state_return(void) {
  ILA_ERROR_IF(_bad_state)
      << "VlgVerifTgtGen is in a bad state, cannot proceed.";
  return _bad_state;
} // bad_state_return


void AQedInfoGeneratorImpl::set_module_instantiation_name() {
  if (bad_state_return())
    return;
  // use the content in the refinement relations to determine the instance name
  auto& model_specified = rf_vmap["models"];
  for (auto&& name_description_pair : model_specified.items()) {
    if (name_description_pair.key() == "ILA") {
      _ila_mod_inst_name = name_description_pair.value();
    } else if (name_description_pair.key() == "VERILOG") {
      _vlg_mod_inst_name = name_description_pair.value();
    } else
      ILA_ERROR << "Unknown model specification:" << name_description_pair.key()
                << " expect VERILOG or ILA";
  }
  // if unset
  if (_vlg_mod_inst_name == "") {
    ILA_WARN
        << "Verilog top module instance name not set, assuming to be VERILOG";
    _vlg_mod_inst_name = "VERILOG";
  }
  if (_ila_mod_inst_name == "") {
    ILA_WARN << "ILA top module instance name not set, assuming to be ILA";
    _ila_mod_inst_name = "ILA";
  }
} // set_module_instantiation_name

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
        ILA_CHECK(ret > 0);
        return ret - 1;
      } else
        next_state = PLAIN;
    }
    state = next_state;
    ++ret;
  }
  return std::string::npos;
}

void AQedInfoGeneratorImpl::load_json(const std::string& fname, nlohmann::json& j) {
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
  while (std::getline(fin, line)) {
    auto comment_begin = find_comments(line);
    if (comment_begin != std::string::npos)
      contents += line.substr(0, comment_begin);
    else
      contents += line;
    contents += "\n";
  }
  j = nlohmann::json::parse(contents);
} // load_json


std::string
AQedInfoGeneratorImpl::CheckNames(
  const VarExtractor::token& t, 
  const std::set<std::string>& ns,
  bool& has_ila_input_state_in_ns, bool& has_ila_input_state_outof_ns ) 
{
  const auto& token_tp = t.first;
  const auto& sname = t.second;
  if (token_tp == VarExtractor::token_type::ILA_S ||
      token_tp == VarExtractor::token_type::ILA_IN
  ) {
    if(IN(sname, ns)) {
      has_ila_input_state_in_ns = true;
      return sname;
    } // else
    auto left_p = sname.find('[');
    auto check_s = sname.substr(0, left_p);
    auto range_s = left_p != std::string::npos ? sname.substr(left_p) : "";
    if(IN(check_s, ns)) {
      has_ila_input_state_in_ns = true;
      return sname;
    }
    
    auto hierName = Split(check_s, ".");
    if (hierName.size() == 2) // maybe it contains an unnecessary head
      if ((hierName[0] == _ila_mod_inst_name || hierName[0] == "ILA") &&
          IN(hierName[1], ns)) {
      has_ila_input_state_in_ns = true;
      return sname;
    }

    has_ila_input_state_outof_ns = true;
  }
  return sname;
} // CheckNames

// for ila state: add __ILA_SO_
// for verilog signal: keep as it is should be fine
// btw, record all referred vlg name
std::string
AQedInfoGeneratorImpl::ModifyCondExprAndRecordVlgName(const VarExtractor::token& t,
  const std::set<std::string>& top_level_vlg_input_names) 
{
  // modify name and ...
  const auto& token_tp = t.first;
  const auto& sname = t.second;

  if (token_tp == VarExtractor::token_type::UNKN_S) {
    // ILA_WARN_IF(!IN(sname, vtgutil::wrapper_signals) && !IN(sname, vlg_wrapper.wires))
    //    << "In refinement relations: unknown reference to name:" << sname
    //    << " keep unchanged.";
    return sname;
  } else if (token_tp == VarExtractor::token_type::KEEP)
    return sname; // NC
  else if (token_tp == VarExtractor::token_type::NUM) {
    // else -- only leave it here
    return sname; // NC
  } else if (token_tp == VarExtractor::token_type::ILA_S) {
    std::string quote = "";
    auto left_p = sname.find('[');
    auto check_s = sname.substr(0, left_p);
    auto range_s = left_p != std::string::npos ? sname.substr(left_p) : "";
    // if (_backend == backend_selector::COSA)
    //  quote = "'";
    // if it refers to ILA state
    if (_ila_ptr->state(check_s))
      return quote + "__ILA_VAR_" + check_s + quote + range_s;
    // if it uses the reference it self
    auto hierName = Split(check_s, ".");
    if (hierName.size() == 2) // maybe it contains an unnecessary head
      if ((hierName[0] == _ila_mod_inst_name || hierName[0] == "ILA") &&
          _ila_ptr->state(hierName[1]))
        return quote + "__ILA_VAR_" + hierName[1] + quote + range_s;
    // should not reachable
    ILA_CHECK(false)
        << "Implementation bug: should not be reachable. token_tp: ILA_S";
    return sname;
  } else if (token_tp == VarExtractor::token_type::ILA_IN) {
    auto left_p = sname.find('[');
    auto check_s = sname.substr(0, left_p);
    auto range_s = left_p != std::string::npos ? sname.substr(left_p) : "";

    std::string quote = "";
    // if (_backend == backend_selector::COSA)
    //  quote = "'";
    // if it refers to ILA state
    if (_ila_ptr->input(check_s))
      return quote + "__ILA_VAR_" + check_s + quote + range_s;
    // if it uses the reference it self
    auto hierName = Split(check_s, ".");
    if (hierName.size() == 2) // maybe it contains an unnecessary head
      if ((hierName[0] == _ila_mod_inst_name || hierName[0] == "ILA") &&
          _ila_ptr->input(hierName[1]))
        return quote + "__ILA_VAR_" + hierName[1] + quote + range_s;
    // should not reachable
    ILA_CHECK(false)
        << "Implementation bug: should not be reachable. token_tp: ILA_IN";
    return sname;
  } else if (token_tp == VarExtractor::token_type::VLG_S) {

    // do nothing for JasperGold
    // will not add to the all_referred name, so will not modify verilog

    std::string quote = "";
    auto left_p = sname.find('[');
    auto check_s = sname.substr(0, left_p);
    auto range_s = left_p != std::string::npos ? sname.substr(left_p) : "";
    auto range_underscore = ReplaceAll(ReplaceAll(range_s, "[", "_"), "]", "_");
    // if (_backend == backend_selector::COSA)
    //  quote = "'";

    auto hierName = Split(check_s, ".");
    if (IN(check_s,top_level_vlg_input_names)) {
      return sname;
    } // else
    if( hierName.size() == 2 && 
        (hierName[0] == _vlg_mod_inst_name || hierName[0] == "VERILOG") &&
        IN(hierName[1],top_level_vlg_input_names)) {
      return (hierName[1] + range_s);
    }


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
    ILA_CHECK(false)
        << "Implementation bug: should not be reachable. token_type: VLG_S";
    return sname;
  }
  ILA_CHECK(false)
      << "Implementation bug: should not reachable. Caused by token_type:"
      << token_tp;
  return sname;
}

} // namespace ilang