/// \file Source for Verilog Verification Targets Generation (single target)
/// the miscs : UF/MEM/AMC/Post-value-holder/cycle-count
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <cmath>
#include <fstream>
#include <iostream>

#include <ilang/ila/ast_hub.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

// ------------- CONFIGURATIONS -------------------- //

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"

#define IntToStr(x) (std::to_string(x))

// ------------- END of CONFIGURAIONS -------------------- //

bool VlgSglTgtGen::bad_state_return(void) {
  ILA_ERROR_IF(_bad_state) << "VlgSglTgtGen is in a bad state, cannot proceed.";
  return _bad_state;
} // bad_state_return

void VlgSglTgtGen::ConstructWrapper_add_additional_mapping_control() {
  if (IN("mapping control", rf_vmap)) {
    if (!rf_vmap["mapping control"].is_array())
      ILA_ERROR << "mapping control field must be an array of string";
    for (auto&& c : rf_vmap["mapping control"]) {
      if (!c.is_string()) {
        ILA_ERROR << "mapping control field must be an array of string";
        continue;
      }
      add_an_assumption(ReplExpr(c.get<std::string>()),
                        "additional_mapping_control_assume");
    }
  }
} // ConstructWrapper_add_additional_mapping_control

void VlgSglTgtGen::ConstructWrapper_add_rf_assumptions() {
  if (IN("assumptions", rf_vmap)) {
    if (!rf_vmap["assumptions"].is_array())
      ILA_ERROR << "`assumptions` field must be an array of string";
    for (auto&& c : rf_vmap["assumptions"]) {
      if (!c.is_string()) {
        ILA_ERROR << "`assumptions` field must be an array of string";
        continue;
      }
      add_an_assumption(ReplExpr(c.get<std::string>()), "rfassumptions");
    }
  }
} // ConstructWrapper_add_rf_assumptions

void VlgSglTgtGen::ConstructWrapper_add_helper_memory() {
  auto endCond =
      has_flush ? "__ENDFLUSH__ || __FLUSHENDED__" : "__IEND__ || __ENDED__";

  // here we insert the memory ports
  for (auto&& memname_ports_pair : supplementary_info.memory_ports) {
    // add wire
    for (auto&& port_expr_port : memname_ports_pair.second) {
      if (RemoveWhiteSpace(port_expr_port.second).empty())
        _idr.KeepMemoryPorts(memname_ports_pair.first, port_expr_port.first,
                             false);
      // does not need to create extra wires
      else {
        // create wire as abs_mem_will not
        auto wn = _idr.KeepMemoryPorts(memname_ports_pair.first,
                                       port_expr_port.first, true);
        vlg_wrapper.add_wire(wn.first, wn.second, true);
        vlg_wrapper.add_assign_stmt(wn.first, ReplExpr(port_expr_port.second));
      }
    }
  }

  auto stmt = _idr.GetAbsMemInstString(vlg_wrapper, endCond);

  if (!((target_type == target_type_t::INV_SYN_DESIGN_ONLY &&
         !_vtg_config.InvariantSynthesisKeepMemory) ||
        (target_type == target_type_t::INVARIANTS &&
         !_vtg_config.InvariantCheckKeepMemory)))
    vlg_wrapper.add_stmt(stmt);

  // check if we need to insert any assumptions
  auto inserter = [this](const std::string& p) -> void {
    if (target_type == target_type_t::INSTRUCTIONS)
      add_an_assumption(p, "absmem");
  };
  _idr.InsertAbsMemAssmpt(inserter);
} // ConstructWrapper_add_helper_memory

void VlgSglTgtGen::ConstructWrapper_add_uf_constraints() {
  if (!IN("functions", rf_vmap))
    return; // do nothing
  auto& fm = rf_vmap["functions"];
  if (!fm.is_object()) {
    ILA_ERROR << "expect functions field to be funcName -> list of list of "
                 "pair of (cond,val).";
    return;
  }

  // convert vlg_ila.ila_func_app to  name->list of func_app
  std::map<std::string, VerilogGeneratorBase::function_app_vec_t>
      name_to_fnapp_vec;
  for (auto&& func_app : vlg_ila.ila_func_app) {
    if (_vtg_config.IteUnknownAutoIgnore) {
      if (func_app.args.empty() &&
          _sdr.isSpecialUnknownFunctionName(func_app.func_name))
        continue;
    }
    name_to_fnapp_vec[func_app.func_name].push_back(func_app);
  }

  for (auto&& it : fm.items()) {
    const auto& funcName = it.key();
    const auto& list_of_time_of_apply = it.value();
    if (!list_of_time_of_apply.is_array()) {
      ILA_ERROR << funcName
                << ": expect functions field to be funcName -> list of list of "
                   "pair of (cond,val).";
      continue;
    }
    if (!IN(funcName, name_to_fnapp_vec)) {
      // ILA_WARN << "uninterpreted function mapping:" << funcName
      //         << " does not exist. Skipped.";
      continue;
    }
    if (list_of_time_of_apply.size() != name_to_fnapp_vec[funcName].size()) {
      ILA_ERROR << "uninterpreted function mapping:" << funcName << " map:#"
                << list_of_time_of_apply.size() << " use in ila:#"
                << name_to_fnapp_vec[funcName].size()
                << " not matched. Skipped.";
      continue;
    }

    auto& ila_app_list = name_to_fnapp_vec[funcName];

    size_t idx = 0;
    for (auto&& each_apply : list_of_time_of_apply.items()) {
      if (!each_apply.value().is_array()) {
        ILA_ERROR << funcName
                  << ": expecting mapping to be list of pair of (cond,val).";
        idx++;
        continue;
      }
      auto& ila_app_item = ila_app_list[idx];
      idx++;
      if (each_apply.value().size() != (ila_app_item.args.size() + 1) * 2) {
        ILA_ERROR << "ila func app expect: (1(retval) + "
                  << ila_app_item.args.size() << "(args) )*2"
                  << " items. Given:" << each_apply.value().size()
                  << " items, for func: " << funcName;
        continue;
      }
      auto val_arg_map_str_vec =
          each_apply.value().get<std::vector<std::string>>();

      std::string func_reg = funcName + "_" + IntToStr(idx - 1) + "_result_reg";
      // okay now get the chance
      auto val_cond = ReplExpr(val_arg_map_str_vec[0]);
      auto val_map = ReplExpr(val_arg_map_str_vec[1],
                              true); // force vlg name on the mapping
      auto res_map = "~(" + val_cond + ")||(" + func_reg + "==" + val_map + ")";

      std::string prep = VLG_TRUE;
      for (size_t arg_idx = 2; arg_idx < val_arg_map_str_vec.size();
           arg_idx += 2) {
        const auto& cond = ReplExpr(val_arg_map_str_vec[arg_idx]);
        const auto& map = ReplExpr(val_arg_map_str_vec[arg_idx + 1], true);

        std::string func_arg = funcName + "_" + IntToStr(idx - 1) + "_arg" +
                               IntToStr(arg_idx / 2 - 1) + "_reg";

        prep += "&&(~(" + cond + ")||((" + func_arg + ") == (" + map + ")))";
      }

      add_an_assumption("~(" + prep + ") || (" + res_map + ")", "funcmap");
    } // for each apply in the list of apply

    name_to_fnapp_vec.erase(funcName); // remove from it
  }
  // check for unmapped func
  for (auto&& nf : name_to_fnapp_vec)
    ILA_ERROR << "lacking function map for func:" << nf.first;
} // ConstructWrapper_add_uf_constraints

int VlgSglTgtGen::ConstructWrapper_add_post_value_holder_handle_obj(
    nlohmann::json& pv_cond_val, const std::string& pv_name, int width,
    bool create_reg) {

  std::string cond = VLG_TRUE;
  std::string val = "'hx";
  std::string original_val_field;

  for (auto&& cond_val_pair : pv_cond_val.items()) {
    if (cond_val_pair.key() == "cond")
      cond = ReplExpr(cond_val_pair.value(), true);
    else if (cond_val_pair.key() == "val") {
      original_val_field = cond_val_pair.value();
      StrTrim(original_val_field);
      val = ReplExpr(original_val_field, true);
    } else if (cond_val_pair.key() == "width") {
      if (cond_val_pair.value().is_string()) {
        ILA_CHECK(cond_val_pair.value().get<std::string>() == "auto")
            << "Expecting width to be unsigned int / auto";
        ILA_CHECK(!original_val_field.empty())
            << "You must first provide `val` field before auto";
        if (original_val_field.find("[") != original_val_field.npos)
          original_val_field =
              original_val_field.substr(0, original_val_field.find("["));
        if (S_IN("=", original_val_field)) {
          ILA_WARN << "Creating value-holder for conditions";
          width = 1;
        } else if (vlg_info_ptr->check_hierarchical_name_type(
                       original_val_field) !=
                   VerilogInfo::hierarchical_name_type::NONE) {
          auto vlg_sig_info = vlg_info_ptr->get_signal(
              original_val_field, supplementary_info.width_info);
          width = vlg_sig_info.get_width();
        } else if (vlg_info_ptr->check_hierarchical_name_type(
                       _vlg_mod_inst_name + "." + original_val_field) !=
                   VerilogInfo::hierarchical_name_type::NONE) {
          auto vlg_sig_info = vlg_info_ptr->get_signal(
              _vlg_mod_inst_name + "." + original_val_field,
              supplementary_info.width_info);
          width = vlg_sig_info.get_width();
        } else {
          ILA_ERROR << "Cannot auto-determine value-holder width for val:"
                    << original_val_field;
          width = 0;
        }
      } else
        width = cond_val_pair.value().get<int>();
    } else
      ILA_ERROR << "Unexpected key: " << cond_val_pair.key()
                << " in post-value-holder, expecting 0-2 or cond/val/width";
  }
  ILA_WARN_IF(val == "'hx") << "val field is not provided for " << pv_name;
  ILA_WARN_IF(cond == VLG_TRUE) << "cond field is not provided for " << pv_name;
  ILA_ERROR_IF(width <= 0 && create_reg)
      << "Cannot create signal for " << pv_name << " : unknown width!";
  if (width >= 0 && create_reg) { // error
    // ILA_ERROR << "width of post-value-holder `" << pv_name << "` is
    // unknown!";
    vlg_wrapper.add_reg(pv_name, width);
  }
  add_reg_cassign_assumption(pv_name, val, width, cond, "post_value_holder");

  return width;
}

void VlgSglTgtGen::ConstructWrapper_add_post_value_holder() {
  if (!IN("post-value-holder", rf_vmap) && !IN("value-holder", rf_vmap))
    return; // no need for it
  ILA_WARN_IF(IN("post-value-holder", rf_vmap))
      << "The name `post-value-holder` will be deprecated in the future, "
      << "please use `value-holder` instead";
  auto& post_val_rec = IN("value-holder", rf_vmap)
                           ? rf_vmap["value-holder"]
                           : rf_vmap["post-value-holder"];
  if (!post_val_rec.is_object()) {
    ILA_ERROR << "Expect (post-)value-holder to be map-type";
    return;
  }
  for (auto&& item : post_val_rec.items()) {
    const auto& pv_name = item.key();
    auto& pv_cond_val = item.value();
    ILA_ERROR_IF(!(pv_cond_val.is_array() || pv_cond_val.is_object()))
        << "Expecting (post-)value-holder's content to be list or map type";
    if (pv_cond_val.is_array() &&
        (!pv_cond_val.empty() &&
         (pv_cond_val.begin()->is_array() ||
          pv_cond_val.begin()->is_object()))) { // multiple condition
      int w = 0;
      bool first = true;
      for (auto ptr = pv_cond_val.begin(); ptr != pv_cond_val.end(); ++ptr) {
        w = ConstructWrapper_add_post_value_holder_handle_obj(*ptr, pv_name, w,
                                                              first);
        first = false;
      }
    } else { // it is just a single line
      ConstructWrapper_add_post_value_holder_handle_obj(pv_cond_val, pv_name, 0,
                                                        true);
    }
  } // for item
} // ConstructWrapper_add_post_value_holder

void VlgSglTgtGen::ConstructWrapper_add_vlg_monitor() {
  if (!IN("verilog-inline-monitors", rf_vmap))
    return; // no need for it

  auto& monitor_rec = rf_vmap["verilog-inline-monitors"];
  if (!monitor_rec.is_object()) {
    ILA_ERROR << "Expect verilog-inline-monitors to be map-type";
    return;
  }

  for (auto&& m_rec : monitor_rec.items()) {
    const auto& mname = m_rec.key(); // actually no use
    auto& mdef = m_rec.value();
    ILA_ERROR_IF(!(mdef.is_object()))
        << "Expect verilog-inline-monitors's element to be map type";
    std::string vlg_expr;
    std::vector<std::string> repl_list;
    bool keep_for_non_instruction_target = false;
    if (IN("keep-for-invariants", mdef) &&
        mdef["keep-for-invariants"].get<bool>())
      keep_for_non_instruction_target = true;
    if (target_type != target_type_t::INSTRUCTIONS &&
        !keep_for_non_instruction_target)
      continue;
    for (auto&& vlg_inp_pair : mdef.items()) {
      if (vlg_inp_pair.key() == "verilog") {
        auto& vlg_field = vlg_inp_pair.value();
        if (vlg_field.is_string()) {
          vlg_expr = vlg_field.get<std::string>();
        } else if (vlg_field.is_array() or vlg_field.is_object()) {
          for (auto&& line : vlg_field.items()) {
            if (!line.value().is_string()) {
              ILA_ERROR << "Expecting string/list-of-string in `verilog` field "
                           "of `verilog-inline-monitors`";
              continue;
            }
            vlg_expr += line.value().get<std::string>() + "\n";
          }
        } else
          ILA_ERROR << "Expecting string/list-of-string in `verilog` field of "
                       "`verilog-inline-monitors`";
      } else if (vlg_inp_pair.key() == "refs") {
        auto& ref_field = vlg_inp_pair.value();
        if (ref_field.is_string())
          repl_list.push_back(vlg_inp_pair.value().get<std::string>());
        else if (ref_field.is_array()) {
          for (auto&& vlg_name : ref_field.items()) {
            if (!vlg_name.value().is_string()) {
              ILA_ERROR << "Expecting string/list-of-string in `refs` field of "
                           "`verilog-inline-monitors`";
              continue;
            }
            repl_list.push_back(vlg_name.value().get<std::string>());
          }
        } else
          ILA_ERROR << "Expecting string/list-of-string in `refs` field of "
                       "`verilog-inline-monitors`";
      } else if (vlg_inp_pair.key() == "defs") {
        if (vlg_inp_pair.value().is_array()) {
          auto& defs = vlg_inp_pair.value();
          for (auto&& def : defs.items()) {
            std::string defname;
            int width = 0;
            std::string type;

            for (auto&& nwt : def.value().items()) {
              // name , width , type
              if (nwt.key() == "0" || nwt.key() == "name") {
                defname = nwt.value().get<std::string>();
              } else if (nwt.key() == "1" || nwt.key() == "width") {
                width = nwt.value().get<int>();
              } else if (nwt.key() == "2" || nwt.key() == "type") {
                type = nwt.value().get<std::string>();
              } else
                ILA_ERROR << "Expecting key in [0,2] or [name,width,type]";
            }

            if (defname.empty() || width == 0 ||
                (type != "reg" && type != "wire"))
              ILA_ERROR << "Cannot create monitor for " << mname;
            else {
              if (type == "reg")
                vlg_wrapper.add_reg(defname, width);
              else
                vlg_wrapper.add_wire(defname, width, true);
            }
          } // for each def in the array
        } else
          ILA_ERROR << "Expecting list-of-map in `defs` field of "
                       "`verilog-inline-monitors`";
      } else if (vlg_inp_pair.key() == "keep-for-invariants") {
        ILA_ASSERT(vlg_inp_pair.value().get<bool>() ==
                   keep_for_non_instruction_target);
      } else
        ILA_ERROR << "Unexpected key: " << vlg_inp_pair.key()
                  << " in verilog-inline-monitors, expecting "
                     "verilog/refs/defs/keep-for-invariants";
    } // for vlg_inp_pair
    for (const auto& w : repl_list) {
      const std::string repl = ReplExpr(w, true);
      vlg_expr = ReplaceAll(vlg_expr, w, repl);
    }
    vlg_wrapper.add_stmt(vlg_expr);
  } // for monitor_rec.items()
} // ConstructWrapper_add_vlg_monitor

} // namespace ilang
