/// \file Source for Verilog Modifier

#include <ilang/vtarget-out/vlg_mod.h>

#include <algorithm>
#include <fstream>

#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

/// Constructor: do nothing
VerilogModifier::VerilogModifier(
    VerilogInfo* _vlg_info_ptr, port_decl_style_t port_decl_style,
    bool add_keep_or_not, const std::map<std::string, int>& _sup_width_info)
    : vlg_info_ptr(_vlg_info_ptr), _port_decl_style(port_decl_style),
      _add_keep_or_not(add_keep_or_not), sup_width_info(_sup_width_info) {}
/// Destructor: do nothing
VerilogModifier::~VerilogModifier() {}

/// do the work : read from fin and append to fout, fout needs to be open with
/// append option
void VerilogModifier::ReadModifyWrite(const std::string& fn, std::istream& fin,
                                      std::ostream& fout) {
  /*
  if (! IN(fn, fn_l_map)) {
    // no need to modify, just copy
    fout << fin.rdbuf();
    return;
  }*/

  // really we need to deal with it
  long lineno = 0;
  std::string line;
  auto& keep_info = fn_l_map[fn];
  auto keep_vec_it = keep_info.begin(); // what if it is end

  auto& mod_decl_info = mod_decl_map[fn];
  auto& mod_inst_info = mod_inst_map[fn];
  auto& assign_info = assign_map[fn];
  auto& add_stmt_info = add_stmt_map[fn];

  auto mod_decl_vec_it = mod_decl_info.begin();
  auto mod_inst_vec_it = mod_inst_info.begin();
  auto assign_vec_it = assign_info.begin();
  auto add_stmt_vec_it = add_stmt_info.begin();

  while (std::getline(fin, line)) {

    // keeps
    while (keep_vec_it != keep_info.end() &&
           lineno == std::get<0>(*keep_vec_it)) {
      // process it
      auto vname = std::get<1>(*keep_vec_it);
      auto is_port = std::get<2>(*keep_vec_it);

      if (_add_keep_or_not) {
        if (!is_port)
          line = add_keep_to_a_line(line, vname);
        else
          line = add_keep_to_port(line, vname);
      }
      // move to the next item on the same line
      keep_vec_it++;
    }
    // todo: check other issues

    while (add_stmt_vec_it != add_stmt_info.end() &&
           lineno == std::get<0>(*add_stmt_vec_it)) {
      const auto& stmt = std::get<1>(*add_stmt_vec_it);
      line = stmt + "\n" + line;
      add_stmt_vec_it++;
    }

    while (assign_vec_it != assign_info.end() &&
           lineno == std::get<0>(*assign_vec_it)) {
      const auto& vname = std::get<1>(*assign_vec_it);
      const auto& width = std::get<2>(*assign_vec_it);
      const auto& signame = std::get<3>(*assign_vec_it);
      line = add_assign_wire_to_this_line(line, vname, width, signame);
      assign_vec_it++;
    }

    while (mod_decl_vec_it != mod_decl_info.end() &&
           lineno >= std::get<0>(*mod_decl_vec_it)) {
      const auto& vname = std::get<1>(*mod_decl_vec_it);
      const auto& width = std::get<2>(*mod_decl_vec_it);
      std::string new_line;
      if (add_mod_decl_wire_to_this_line(line, new_line, vname, width)) {
        line = new_line;
        mod_decl_vec_it++;
      } else
        break;
      // else we will stop handle it and carry this to the next line
    }

    while (mod_inst_vec_it != mod_inst_info.end() &&
           lineno >= std::get<0>(*mod_inst_vec_it)) {
      const auto& vname = std::get<1>(*mod_inst_vec_it);
      const auto& width = std::get<2>(*mod_inst_vec_it);
      std::string new_line;
      if (add_mod_inst_wire_to_this_line(line, new_line, vname, width)) {
        line = new_line;
        mod_inst_vec_it++;
      } else
        break;
      // else we will carry this to the next line
    }

    // check t
    fout << line << std::endl;
    lineno++;
  } // while getline

} // ReadModifyWrite

template <class T> bool compare_tuple(T const& t1, T const& t2) {
  return std::get<0>(t1) < std::get<0>(t2);
}

/// do some work (sorting)
void VerilogModifier::FinishRecording() {

  // sort fn_l_map according to lineno in each file
  for (auto&& fn_tp_pair : fn_l_map) {
    auto& vec = fn_tp_pair.second;
    std::sort(begin(vec), end(vec), compare_tuple<info_t>);
  }
  // same for the other three maps
  for (auto&& fn_tp_pair : mod_decl_map) {
    auto& vec = fn_tp_pair.second;
    std::sort(begin(vec), end(vec), compare_tuple<mod_decl_item_t>);
  }
  for (auto&& fn_tp_pair : mod_inst_map) {
    auto& vec = fn_tp_pair.second;
    std::sort(begin(vec), end(vec), compare_tuple<mod_inst_item_t>);
  }
  for (auto&& fn_tp_pair : assign_map) {
    auto& vec = fn_tp_pair.second;
    std::sort(begin(vec), end(vec), compare_tuple<assign_item_t>);
  }
  for (auto&& fn_tp_pair : add_stmt_map) {
    auto& vec = fn_tp_pair.second;
    std::sort(begin(vec), end(vec), compare_tuple<add_stmt_t>);
  }

} // FinishRecording

/// record the name to add a keep there
void VerilogModifier::RecordKeepSignalName(const std::string& vlg_sig_name) {
  auto vlg_sig_info = vlg_info_ptr->get_signal(vlg_sig_name);
  auto loc = vlg_info_ptr->name2loc(vlg_sig_name);

  // check for repetition:
  for (auto&& info_item : fn_l_map[loc.first]) {
    auto lineno = std::get<0>(info_item);
    // const auto& vname = std::get<1>(info_item); // BYH: unused var
    if (lineno == loc.second /*&& vname == vlg_sig_info.get_signal_name()*/)
      return; // we already add it
    // WARNING: we are not adding keep to the same line!
  }

  fn_l_map[loc.first].push_back(
      info_t(loc.second,                     // lineno
             vlg_sig_info.get_signal_name(), // variable name
             vlg_sig_info.no_internal_def()  // is it a port
             ));
} // RecordKeepSignalName

std::string VerilogModifier::add_keep_to_a_line(const std::string& line_in,
                                                const std::string& vname) {
  if (line_in.find(vname) == std::string::npos) {
    ILA_ERROR << "Implementation bug: not able to add keep to line:" << line_in
              << " required varname:" << vname;
    return line_in;
  }
  auto comment_start = line_in.find("//");
  std::string comment;
  if (comment_start != std::string::npos)
    comment = line_in.substr(comment_start);
  auto line = line_in.substr(0, comment_start);
  auto decls = Split(line, ";");
  for (auto&& decl : decls) {
    if (S_IN(vname, decl) && (S_IN("reg", decl) || S_IN("wire", decl))) {
      decl = "(* keep *) " + decl;
      break;
    }
  }
  auto declcomb = decls.size() > 0 ? Join(decls, ";") + ";" : "";
  return (declcomb + comment);
}

std::string VerilogModifier::add_keep_to_port(const std::string& line_in,
                                              const std::string& vname) {
  // size_t left = 0; // BYH: unused var
  if (line_in.find(vname) == std::string::npos) {
    ILA_ERROR << "Implementation bug: not able to add keep to line:" << line_in
              << " required varname:" << vname;
    return line_in;
  }

  if (std::string::npos == line_in.find('(') &&
      std::string::npos == line_in.find(')') &&
      std::string::npos != line_in.find(';')) {
    // we are dealing with something like output a;
    auto defl = Split(line_in, ";");
    for (auto& def : defl) {
      if (def.find(vname) != std::string::npos) {
        def = "(* keep *)" + def;
        break;
      }
    }
    return Join(defl, ";") + ";";
  }

  size_t left_p = 0;
  size_t right_p = std::string::npos;
  size_t mid_len = std::string::npos;
  if (line_in.find("(") != std::string::npos)
    left_p = line_in.find("(") + 1;
  if (line_in.find(")") != std::string::npos) {
    right_p = line_in.find(")");
    mid_len = right_p - left_p;
  }

  auto left_cut = line_in.substr(0, left_p);
  auto right_cut = right_p != std::string::npos ? line_in.substr(right_p) : "";
  auto middle = line_in.substr(left_p, mid_len);

  ILA_CHECK(left_cut + middle + right_cut == line_in);

  auto midSplit = Split(middle, ",");

  int foundIdx = -1;
  int idx = 0;
  for (auto&& port_decl : midSplit) {
    auto wordList = SplitSpaceTabEnter(port_decl);
    if (std::find(wordList.begin(), wordList.end(), vname) != wordList.end()) {
      foundIdx = idx;
      break;
    }
    idx++;
  }

  if (foundIdx == -1) {
    ILA_ERROR << "not able to modify line: '" << line_in << "' for :" << vname;
    return line_in;
  }

  midSplit[foundIdx] = "(* keep *)" + midSplit[foundIdx];

  auto midMod = Join(midSplit, ",");

  if ((middle.back()) == ',')
    midMod += ',';

  return left_cut + midMod + right_cut;
} // add_keep_to_port

/// record the statement to be added to the end of Verilog topmodule
void VerilogModifier::RecordAdditionalVlgModuleStmt(
    const std::string& stmt, const std::string& mod_instance_name) {
  auto loc = vlg_info_ptr->get_endmodule_loc(
      mod_instance_name); // this the endmodule location

  add_stmt_map[loc.first].push_back(add_stmt_t(loc.second, stmt));
}

/// record the name to add a keep there
VerilogModifier::vlg_sig_t
VerilogModifier::RecordConnectSigName(const std::string& vlg_sig_name,
                                      const std::string& suffix) {
  auto vlg_sig_info =
      vlg_info_ptr->get_signal(vlg_sig_name); // will check it exists
  auto width = vlg_sig_info.get_width();
  if (width ==
      0) { // will use the supplementary info if cannot find it find verilog
    auto pos = sup_width_info.find(vlg_sig_name);
    ILA_ERROR_IF(pos == sup_width_info.end() || pos->second == 0)
        << "Unable to determine the width of signal:" << vlg_sig_name;
    if (pos != sup_width_info.end()) {
      width = pos->second;
    }
  }

  auto short_name = vlg_sig_info.get_signal_name();

  auto vname =
      ReplaceAll(vlg_sig_name, ".", "__DOT__") +
      ReplaceAll(ReplaceAll(suffix, "[", "_"), "]", "_"); // name for verilog
  auto mod_hier_name = Split(vlg_sig_name, ".");
  auto hier = mod_hier_name.size();
  auto last_level_name = mod_hier_name[hier - 1];

  ILA_CHECK(hier >= 2);

  // add module decl mod
  std::string inst_name = mod_hier_name[0];
  // add topmodule:
  auto loc = vlg_info_ptr->name2loc(inst_name);
  ILA_CHECK(loc.first != ""); // should be found
  mod_decl_map[loc.first].push_back(mod_decl_item_t(loc.second, vname, width));

  for (unsigned idx = 1; idx < hier - 1; ++idx) { // exclude the last level name
    inst_name += "." + mod_hier_name[idx];

    auto loc = vlg_info_ptr->name2loc(inst_name);
    ILA_CHECK(loc.first != ""); // should be found
    mod_decl_map[loc.first].push_back(
        mod_decl_item_t(loc.second, vname, width));
  }

  // add module inst mod: a.b.signal
  inst_name = mod_hier_name[0];
  for (unsigned idx = 1; idx < hier - 1; ++idx) {
    inst_name += "." + mod_hier_name[idx];
    auto loc = vlg_info_ptr->get_module_inst_loc(inst_name);
    ILA_CHECK(loc.first != ""); // should be found
    mod_inst_map[loc.first].push_back(
        mod_inst_item_t(loc.second, vname, width));
  }

  // use the special location (mod_decl to add wires and ...)
  loc =
      vlg_info_ptr->get_endmodule_loc(inst_name); // this the endmodule location
  assign_map[loc.first].push_back(
      assign_item_t(loc.second, vname, width, short_name + suffix));

  return vlg_sig_t({vname, width});
} // RecordConnectSigName

std::string WidthToRange(unsigned w) {
  if (w > 1)
    return std::string("[") + std::to_string(w - 1) + ":0]";
  return "";
}

std::string VerilogModifier::add_assign_wire_to_this_line(
    const std::string& line_in, const std::string& vname, unsigned width,
    const std::string& short_name) {
  std::string text = " assign " + vname + " = " + short_name + ";\n";
  return text + line_in;
  /*
  auto l = SplitSpaceTabEnter(line_in);
  if (l.size() == 0) return text + line_in;
  auto pos = std::find(l.begin(), l.end(), "endmodule");
  if(pos == l.end()) {
    ILA_ERROR <<"endmodule not found. Insert in place";
    return  text + line_in;
  }
  auto text = l[0];
  for(auto s = l.begin()+1; s != pos; ++s) {

  }*/
}

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
    } else
      ILA_CHECK(false);
    state = next_state;
    ++ret;
  }
  return std::string::npos;
}

static bool is_good_id_name(const std::string& idname) {
  if (idname.length() == 0)
    return false;
  if (!isalpha(idname.at(0)) && idname.at(0) != '_')
    return false;
  for (size_t idx = 1; idx < idname.length(); ++idx) {
    if (!isalnum(idname.at(idx)) && idname.at(idx) != '_')
      return false;
  }
  return true;
}

static bool containUsefulPortInfo(const std::string& line, bool& newstyle) {
  auto pos = find_comments(line);
  auto line_no_comment = line.substr(0, pos);    // remove comment
  auto wl = SplitSpaceTabEnter(line_no_comment); // should not go to the right
  if (std::find(wl.begin(), wl.end(), "output") != wl.end() ||
      std::find(wl.begin(), wl.end(), "input") != wl.end()) {
    newstyle = true;
    return true;
  }
  if (S_IN(',', line_no_comment)) {
    newstyle = false;
    return true;
  }
  if (wl.size() == 1 && is_good_id_name(wl.at(0))) {
    newstyle = false;
    return true;
  }
  return false;
}

bool VerilogModifier::add_mod_decl_wire_to_this_line(const std::string& line_in,
                                                     std::string& line_out,
                                                     const std::string& vname,
                                                     unsigned width) {
  static bool new_style = false;

  auto pos = line_in.find(';'); // the left most ; because we will insert later
  if (pos == std::string::npos) {
    bool set_new_style;
    bool contain_useful_info = containUsefulPortInfo(line_in, set_new_style);
    if (contain_useful_info)
      new_style = set_new_style;
    return false; // unsuccessful
  }

  auto pos_rp = line_in.rfind(')', pos);
  if (pos_rp == std::string::npos) {
    ILA_ERROR
        << "unable to find the right ) to insert port decl, will continue.";
    ILA_ERROR << "Line-in : " << line_in << " vname:" << vname;
    line_out = line_in;
    return true;
  }
  auto left = line_in.substr(0, pos_rp);
  auto right = line_in.substr(pos_rp);

  // auto wl = SplitSpaceTabEnter(left); // should not go to the right

  if (_port_decl_style == port_decl_style_t::AUTO) {

    bool set_new_style;
    bool contain_useful_info = containUsefulPortInfo(left, set_new_style);
    if (contain_useful_info)
      new_style = set_new_style;
    /*
    new_style = false;
    if (std::find(wl.begin(), wl.end(), "output") != wl.end())
      new_style = true;
    if (std::find(wl.begin(), wl.end(), "input") != wl.end())
      new_style = true;*/
  } else {
    new_style = _port_decl_style == port_decl_style_t::NEW ? true : false;
  }

  if (new_style) {
    auto text = ", output wire " + WidthToRange(width) + " " + vname;
    line_out = left + text + right;
    return true;
  }

  // old style
  auto text = ", " + vname;
  auto end_text = "\n output " + WidthToRange(width) + " " + vname + ";";
  line_out = left + text + right + end_text;
  return true;
} // add_mod_decl_wire_to_this_line

bool VerilogModifier::add_mod_inst_wire_to_this_line(const std::string& line_in,
                                                     std::string& line_out,
                                                     const std::string& vname,
                                                     unsigned width) {

  /*  static int left_para_layer = 0;
    if (left_para_layer == 0) {
      // start the find
      for(auto && c : line_in) {
        if ( c == '(') left_para_layer ++;
        else if(c == ')') { left_para_layer --; }
      }
    }*/
  // static bool with_name_index = true;
  // this is definitely a bug, we cannot handle
  // anonymous argument

  auto pos = line_in.find(';');
  if (pos == std::string::npos)
    return false; // unsuccessful, try next line
  auto pos_rp = line_in.rfind(')', pos);
  if (pos_rp == std::string::npos) {
    ILA_ERROR
        << "unable to find the right ) to insert port decl, will continue.";
    line_out = line_in;
    return true;
  }
  auto left = line_in.substr(0, pos_rp);
  auto right = line_in.substr(pos_rp);
  auto text = " ,." + vname + "(" + vname + ")";
  line_out = left + text + right;
  return true;
} // add_mod_inst_wire_to_this_line

}; // namespace ilang
