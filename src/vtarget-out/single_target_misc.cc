/// \file Source for Verilog Verification Targets Generation (single target)
/// the miscs : UF/MEM/AMC/Post-value-holder/cycle-count
// --- Hongce Zhang


#include <ilang/ila/expr_fuse.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <cmath>
#include <fstream>
#include <iostream>

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
    if (not rf_vmap["mapping control"].is_array())
      ILA_ERROR << "mapping control field must be an array of string";
    for (auto&& c : rf_vmap["mapping control"]) {
      if (not c.is_string()) {
        ILA_ERROR << "mapping control field must be an array of string";
        continue;
      }
      add_an_assumption(ReplExpr(c.get<std::string>()),
                        "additional_mapping_control_assume");
    }
  }
} // ConstructWrapper_add_additional_mapping_control

void VlgSglTgtGen::ConstructWrapper_add_helper_memory() {
  auto endCond =
      has_flush ? "__ENDFLUSH__ || __FLUSHENDED__" : "__IEND__ || __ENDED__";

  auto stmt = _idr.GetAbsMemInstString(vlg_wrapper, endCond);
  vlg_wrapper.add_stmt(stmt);

  // check if we need to insert any assumptions
  auto inserter = [this](const std::string& p) -> void {
    add_an_assumption(p, "absmem");
  };
  _idr.InsertAbsMemAssmpt(inserter);
} // ConstructWrapper_add_helper_memory


void VlgSglTgtGen::ConstructWrapper_add_uf_constraints() {
  if (not IN("functions", rf_vmap))
    return; // do nothing
  auto& fm = rf_vmap["functions"];
  if (not fm.is_object()) {
    ILA_ERROR << "expect functions field to be funcName -> list of list of "
                 "pair of (cond,val).";
    return;
  }

  // convert vlg_ila.ila_func_app to  name->list of func_app
  std::map<std::string, VerilogGeneratorBase::function_app_vec_t>
      name_to_fnapp_vec;
  for (auto&& func_app : vlg_ila.ila_func_app)
    name_to_fnapp_vec[func_app.func_name].push_back(func_app);

  for (auto&& it : fm.items()) {
    const auto& funcName = it.key();
    const auto& list_of_time_of_apply = it.value();
    if (not list_of_time_of_apply.is_array()) {
      ILA_ERROR << funcName
                << ": expect functions field to be funcName -> list of list of "
                   "pair of (cond,val).";
      continue;
    }
    if (not IN(funcName, name_to_fnapp_vec)) {
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
      if (not each_apply.value().is_array()) {
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



} // namespace ilang
