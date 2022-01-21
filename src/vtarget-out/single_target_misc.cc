/// \file Source for Verilog Verification Targets Generation (single target)
/// the miscs : UF/MEM/AMC/Post-value-holder/cycle-count
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <cmath>
#include <fstream>
#include <iostream>

#include <ilang/ila/ast_hub.h>
#include <ilang/rfmap-in/rfexpr_shortcut.h>
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

void VlgSglTgtGen::RfmapIlaStateSanityCheck() {
#define ERR_IF(cond, s)                                                        \
  do {                                                                         \
    ILA_ERROR_IF(cond) << (s);                                                 \
    if (cond) {                                                                \
      _bad_state = true;                                                       \
      return;                                                                  \
    }                                                                          \
  } while (0)

  for (unsigned sidx = 0; sidx < _host->state_num(); ++sidx) {
    const auto& s = _host->state(sidx);
    const auto& n = s->name().str();
    ERR_IF(!IN(n, refinement_map.ila_state_var_map),
           "state `" + n + "` not in refinement map");
  }

  for (unsigned sidx = 0; sidx < _host->input_num(); ++sidx) {
    const auto& s = _host->input(sidx);
    const auto& n = s->name().str();
    ERR_IF(!IN(n, refinement_map.ila_input_var_map),
           "input `" + n + "` not in refinement map");
  }

  for (const auto& n_map_pair : refinement_map.ila_state_var_map) {
    ERR_IF(_host->find_state(n_map_pair.first) == nullptr,
           "state `" + n_map_pair.first + "` not defined in ILA");
  }

  for (const auto& n_map_pair : refinement_map.ila_input_var_map) {
    ERR_IF(_host->find_input(n_map_pair.first) == nullptr,
           "input `" + n_map_pair.first + "` not defined in ILA");
  }

#undef ERR_IF
}

void VlgSglTgtGen::ConstructWrapper_add_additional_mapping_control() {
  for (const auto& mapc : refinement_map.additional_mapping) {
    add_an_assumption(mapc, "additional_mapping_control_assume");
  }
} // ConstructWrapper_add_additional_mapping_control

void VlgSglTgtGen::ConstructWrapper_add_rf_assumptions() {
  for (const auto& assumpt : refinement_map.assumptions) {
    add_an_assumption(assumpt, "rfassumptions");
  }
} // ConstructWrapper_add_rf_assumptions

void VlgSglTgtGen::ConstructWrapper_add_uf_constraints() {
  if (refinement_map.uf_application.empty())
    return;

  // convert vlg_ila.ila_func_app to  name->list of func_app
  std::map<std::string, VerilogGeneratorBase::function_app_vec_t>
      name_to_fnapp_vec;
  for (auto&& func_app : vlg_ila.ila_func_app) {
    name_to_fnapp_vec[func_app.func_name].push_back(func_app);
  }

  for (const auto& uf_app : refinement_map.uf_application) {
    const auto& funcName = uf_app.first;
    const auto& list_of_time_of_apply = uf_app.second.func_applications;
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
    for (auto&& each_apply : list_of_time_of_apply) {

      auto& ila_app_item = ila_app_list[idx];
      idx++;
      if (each_apply.arg_map.size() != ila_app_item.args.size()) {
        ILA_ERROR << "ila func app expect: " << ila_app_item.args.size()
                  << " (args)."
                  << " Given:" << each_apply.arg_map.size()
                  << " items, for func: " << funcName;
        continue;
      }
      const auto& arg_apply = each_apply.arg_map;
      const auto& result_apply = each_apply.result_map;
      std::string func_result_wire =
          funcName + "_" + IntToStr(idx - 1) + "_result_wire";

      auto res_map =
          rfmap_imply(rfmap_var("decode"),
                      rfmap_eq(rfmap_var(func_result_wire), result_apply));

      std::vector<rfmap::RfExpr> prep;
      size_t arg_idx = 0;
      for (const auto& each_arg : arg_apply) {

        std::string func_arg = funcName + "_" + IntToStr(idx - 1) + "_arg" +
                               IntToStr(arg_idx++) + "_wire";
        prep.push_back(rfmap_imply(rfmap_var("decode"),
                                   rfmap_eq(rfmap_var(func_arg), each_arg)));
      }
      // (
      //   (decode |-> arg0_output == ??@?? ) && (decode |-> arg1_output ==
      //   ??@?? )
      //    && ...
      // ) |-> (
      //   (decode |-> result_input == ??@??)
      // )
      auto pre_cond = prep.empty() ? rfmap_true() : rfmap_and(prep);
      add_an_assumption(rfmap_imply(pre_cond, res_map), "funcmap");
    } // for each apply in the list of apply

    name_to_fnapp_vec.erase(funcName); // remove from it
  }

  // check for unmapped func
  for (auto&& nf : name_to_fnapp_vec)
    ILA_ERROR << "lacking function map for func:" << nf.first;
} // ConstructWrapper_add_uf_constraints

void VlgSglTgtGen::ConstructWrapper_add_delay_unit() {
  // for (const auto& delay_unit : refinement_map.aux_delays) {
  //  std::cout << delay_unit.first << " : expr = "
  //    << (delay_unit.second.signal) << std::endl;
  // }

  for (const auto& delay_unit : refinement_map.aux_delays) {
    const auto& name = delay_unit.first;
    const auto& du = delay_unit.second;
    unsigned width = du.width;
    auto rhs = du.signal;
    if (du.delay_type != rfmap::SignalDelay::delay_typeT::SINGLE &&
        du.width > 1) {
      width = 1;
      rhs = rfmap_reduce_or(rhs);
    }

    ILA_ERROR_IF(du.num_cycle == 0) << "Cannot delay 0 cycle";
    std::string last_reg;
    for (size_t didx = 1; didx <= du.num_cycle; ++didx) {
      auto curr_name = name + "_d_" + std::to_string(didx);
      auto prev_name = name + "_d_" + std::to_string(didx - 1);
      vlg_wrapper.add_reg(curr_name, width);
      if (didx == 1) {
        // delay from signal
        vlg_wrapper.add_wire(prev_name, width, true);
        vlg_wrapper.add_output(prev_name, width);
        rfmap_add_internal_wire(prev_name, width);
        add_wire_assign_assumption(prev_name, rhs, "delay_unit");
      }
      vlg_wrapper.add_always_stmt(curr_name + " <= " + prev_name + " ;");
      vlg_wrapper.add_init_stmt(curr_name + "<= 0;");
      if (didx == du.num_cycle)
        last_reg = curr_name;
    } // end - for each delay
    if (du.delay_type == rfmap::SignalDelay::delay_typeT::SINGLE) {
      vlg_wrapper.add_wire(name, width);
      vlg_wrapper.add_assign_stmt(name, last_reg);
      continue;
    } // else
    if (du.delay_type == rfmap::SignalDelay::delay_typeT::TO_INFINITE) {
      auto summary_var = name + "_inf_";
      vlg_wrapper.add_reg(summary_var, 1);
      vlg_wrapper.add_init_stmt(summary_var + "<= 1'b0;");
      vlg_wrapper.add_always_stmt("if( " + last_reg + ") " + summary_var +
                                  " <= 1'b1;");
      vlg_wrapper.add_wire(name, 1);
      vlg_wrapper.add_assign_stmt(name, summary_var + " || " + last_reg);
      continue;
    }
    // finally the range
    // if (du.delay_type == rfmap::SignalDelay::delay_typeT::RANGE)
    ILA_ERROR_IF(du.upper_bnd <= du.num_cycle)
        << "in `##[l:u]`, we need `l < u` ";
    std::string or_reduce = last_reg;
    for (size_t didx = du.num_cycle + 1; didx <= du.upper_bnd; ++didx) {
      auto curr_name = name + "_d_" + std::to_string(didx);
      auto prev_name = name + "_d_" + std::to_string(didx - 1);
      vlg_wrapper.add_reg(curr_name, 1);
      vlg_wrapper.add_init_stmt(curr_name + " <= 0;");
      vlg_wrapper.add_always_stmt(curr_name + " <= " + prev_name + " ;");

      or_reduce += " || " + curr_name;
    }
    vlg_wrapper.add_wire(name, 1);
    vlg_wrapper.add_assign_stmt(name, or_reduce);
  } // end for each delay unit
} // end ConstructWrapper_add_delay_unit

void VlgSglTgtGen::ConstructWrapper_add_stage_tracker() {
  for (const auto& n_tracker : refinement_map.phase_tracker) {
    const auto& tracker_name = n_tracker.first;
    const auto& tracker = n_tracker.second;

    for (const auto& vardef : tracker.var_defs) {
      // already in refinement_map.all_var_def_types
      const auto& vn = vardef.first;
      if (vardef.second.type ==
          rfmap::GeneralVerilogMonitor::VarDef::var_type::REG)
        vlg_wrapper.add_reg(vn, vardef.second.width);
      else
        vlg_wrapper.add_wire(vn, vardef.second.width);
    }
    for (const auto& event_alias : tracker.event_alias) {
      vlg_wrapper.add_wire(event_alias.first, 1);
      vlg_wrapper.add_output(event_alias.first, 1);
      rfmap_add_internal_wire(event_alias.first, 1);
      // add_wire_assign_assumption
      add_wire_assign_assumption(event_alias.first, event_alias.second,
                                 "stage_tracker");
    }
    unsigned sidx = 0;
    for (const auto& stage : tracker.rules) {
      const std::string& stage_name = stage.stage_name;
      ILA_CHECK(!stage_name.empty())
          << "stage name is empty for " << tracker_name;
      vlg_wrapper.add_reg(stage_name, 1);

      std::string enter_cond_wire_name = stage_name + "_enter_cond";
      std::string exit_cond_wire_name = stage_name + "_exit_cond";
      std::string enter_action_wire_name = stage_name + "_enter_action";
      std::string exit_action_wire_name = stage_name + "_exit_action";

      vlg_wrapper.add_init_stmt(stage_name + "<= 1'b0;");
      vlg_wrapper.add_always_stmt("if(" + enter_cond_wire_name + ") begin " +
                                  stage_name + " <= 1'b1;");
      vlg_wrapper.add_wire(enter_cond_wire_name, 1, true);
      vlg_wrapper.add_output(enter_cond_wire_name, 1);
      rfmap_add_internal_wire(enter_cond_wire_name, 1);
      ILA_NOT_NULL(stage.enter_rule);
      add_wire_assign_assumption(enter_cond_wire_name, stage.enter_rule,
                                 "phase_tracker");

      unsigned idx = 0;
      for (const auto& action : stage.enter_action) {
        auto pos_def_var = refinement_map.all_var_def_types.find(action.LHS);
        ILA_ERROR_IF(pos_def_var == refinement_map.all_var_def_types.end())
            << "Cannot find var def for " << action.LHS
            << " used in LHS of phase tracker " << tracker_name;

        std::string action_name =
            enter_action_wire_name + std::to_string(idx++);
        vlg_wrapper.add_always_stmt(action.LHS + " <= " + action_name + ";");

        vlg_wrapper.add_wire(action_name, pos_def_var->second.width, true);
        vlg_wrapper.add_output(action_name, pos_def_var->second.width);
        rfmap_add_internal_wire(action_name, pos_def_var->second.width);
        add_wire_assign_assumption(action_name, action.RHS, "phase_tracker");
      }

      vlg_wrapper.add_always_stmt("end");
      vlg_wrapper.add_always_stmt("else if(" + exit_cond_wire_name +
                                  ") begin " + stage_name + " <= 1'b0;");

      vlg_wrapper.add_wire(exit_cond_wire_name, 1, true);
      vlg_wrapper.add_output(exit_cond_wire_name, 1);
      rfmap_add_internal_wire(exit_cond_wire_name, 1);
      if (stage.exit_rule == nullptr)
        vlg_wrapper.add_assign_stmt(exit_cond_wire_name, "1'b0");
      else
        add_wire_assign_assumption(exit_cond_wire_name, stage.exit_rule,
                                  "phase_tracker");

      idx = 0;
      for (const auto& action : stage.exit_action) {
        auto pos_def_var = refinement_map.all_var_def_types.find(action.LHS);
        ILA_ERROR_IF(pos_def_var == refinement_map.all_var_def_types.end())
            << "Cannot find var def for " << action.LHS
            << " used in LHS of phase tracker " << tracker_name;

        std::string action_name = exit_action_wire_name + std::to_string(idx++);
        vlg_wrapper.add_always_stmt(action.LHS + " <= " + action_name + ";");
        vlg_wrapper.add_wire(action_name, pos_def_var->second.width, true);
        vlg_wrapper.add_output(action_name, pos_def_var->second.width);
        rfmap_add_internal_wire(action_name, pos_def_var->second.width);
        add_wire_assign_assumption(action_name, action.RHS, "phase_tracker");
      }

      vlg_wrapper.add_always_stmt("end");

      sidx++;
    } // for each stage
  }   // for each tracker
} // ConstructWrapper_add_stage_tracker

void VlgSglTgtGen::ConstructWrapper_add_post_value_holder() {
  for (const auto& post_val_holder : refinement_map.value_recorder) {
    const auto& pv_name = post_val_holder.first;
    vlg_wrapper.add_reg(pv_name, post_val_holder.second.width);
    rfmap_add_internal_reg(pv_name, post_val_holder.second.width);

    auto eq_cond =
        _vtg_config.EnforcingValueRecorderForOnlyOneCycle
            ? rfmap_and(
                  {rfmap_or(rfmap_var("__START__"), rfmap_var("__STARTED__")),
                   rfmap_not(rfmap_var(pv_name + "_sn_condmet")),
                   post_val_holder.second.condition})
            : post_val_holder.second.condition;

    add_reg_cassign_assumption(pv_name, post_val_holder.second.value,
                               post_val_holder.second.width, eq_cond,
                               "post_value_holder");

    // for sanity check
    vlg_wrapper.add_reg(pv_name + "_sn_vhold", post_val_holder.second.width);
    rfmap_add_internal_reg(pv_name + "_sn_vhold", post_val_holder.second.width);
    vlg_wrapper.add_wire(pv_name + "_sn_value", post_val_holder.second.width);
    rfmap_add_internal_wire(pv_name + "_sn_value",
                            post_val_holder.second.width);

    vlg_wrapper.add_reg(pv_name + "_sn_condmet", 1);
    rfmap_add_internal_reg(pv_name + "_sn_condmet", 1);
    vlg_wrapper.add_wire(pv_name + "_sn_cond", 1);
    rfmap_add_internal_wire(pv_name + "_sn_cond", 1);
    vlg_wrapper.add_init_stmt(pv_name + "_sn_condmet <= 1'b0;");
    vlg_wrapper.add_always_stmt("if (" + pv_name + "_sn_cond ) begin " +
                                pv_name + "_sn_condmet <= 1'b1; " + pv_name +
                                "_sn_vhold <= " + pv_name + "_sn_value; end");

    // pv_sn_cond = <condition> && ( __START__ || __STARTED__ )
    add_wire_assign_assumption(
        pv_name + "_sn_cond",
        rfmap_and({post_val_holder.second.condition,
                  rfmap_or(rfmap_var("__START__"), rfmap_var("__STARTED__")),
                  rfmap_not(rfmap_var("__ENDED__"))
                  }),
        "pvholder_cond_assign");

    // pv_sn_value = <value>
    add_wire_assign_assumption(pv_name + "_sn_value",
                               post_val_holder.second.value,
                               "pvholder_cond_assign");

    add_a_santiy_assertion(
        // cond && cond_met |-> value == value_stored
        rfmap_imply(rfmap_and(rfmap_var(pv_name + "_sn_condmet"),
                              rfmap_var(pv_name + "_sn_cond")),
                    rfmap_eq(rfmap_var(pv_name + "_sn_value"),
                             rfmap_var(pv_name + "_sn_vhold"))),
        "post_value_holder_overly_constrained");

    // check : commit -> _cond_met
    add_a_santiy_assertion(
      rfmap_imply(rfmap_var("commit"), 
      rfmap_or(
       rfmap_var(pv_name + "_sn_condmet"),
       rfmap_var(pv_name + "_sn_cond")
       )),
      "post_value_holder_triggered");
    
  } // for each value recorder
} // ConstructWrapper_add_post_value_holder

/// Add direct aux vars
void VlgSglTgtGen::ConstructWrapper_add_direct_aux_vars() {
  for (const auto & n_expr : refinement_map.direct_aux_vars) {
    const auto & n = n_expr.first;
    auto w = n_expr.second.width;
    ILA_CHECK(w!=0); // aux var should have its width
    vlg_wrapper.add_wire(n,w,true);
    vlg_wrapper.add_output(n,w);
    add_wire_assign_assumption(n, n_expr.second.val, "direct_aux_var");
  }
}

void VlgSglTgtGen::ConstructWrapper_add_vlg_monitor() {
  if (refinement_map.customized_monitor.empty())
    return;

  const auto& monitor_rec = refinement_map.customized_monitor;

  for (auto&& m_rec : monitor_rec) {

    const auto& mname = m_rec.first;
    const auto& mdef = m_rec.second; // generalMonitor

    std::string vlg_expr;
    std::vector<std::string> repl_list;
    bool keep_for_non_instruction_target = mdef.keep_for_invariant;

    if (target_type != target_type_t::INSTRUCTIONS &&
        !keep_for_non_instruction_target)
      continue;

    for (const auto& n_def : mdef.var_defs) {
      // already in refinement_map.all_var_def
      if (n_def.second.type ==
          rfmap::GeneralVerilogMonitor::VarDef::var_type::REG)
        vlg_wrapper.add_reg(n_def.first, n_def.second.width);
      else
        vlg_wrapper.add_wire(n_def.first, n_def.second.width);
    }

    unsigned idx = 0;
    std::vector<std::pair<std::string, std::string>> replace_list;
    for (auto pos1 = mdef.var_uses.begin(); pos1 != mdef.var_uses.end(); ++pos1) {
      for (auto pos2 = mdef.var_uses.begin(); pos2 != mdef.var_uses.end(); ++pos2) {
        if(pos1 == pos2) continue;
        ILA_ERROR_IF( (*pos1).find(*pos2) != std::string::npos) << *pos2 << " is part of " << *pos1;
      }
    }

    for (const auto& vref : mdef.var_uses) {

      auto vref_node = rfmap::VerilogRefinementMap::ParseRfExprFromString(vref);
      auto new_name = mname + "_auxvar" + std::to_string(idx++);

      auto tp = refinement_map.TypeInferTravserRfExpr(vref_node, {});

      ILA_ERROR_IF(tp.is_unknown())
          << "Cannot determine width of " << vref << " in monitor " << mname;

      auto width = tp.unified_width();
      vlg_wrapper.add_wire(new_name, width, true);
      vlg_wrapper.add_output(new_name, width);
      rfmap_add_internal_wire(new_name, width);
      add_wire_assign_assumption(new_name, vref_node, "monitor_auxvar");

      replace_list.push_back(std::make_pair(vref, new_name));
    }

    auto vlog_inline = mdef.verilog_inline;
    for (const auto& old_new_pair : replace_list) {
      // std::cout << vlog_inline << std::endl;
      vlog_inline =
          ReplaceAll(vlog_inline, old_new_pair.first, old_new_pair.second);
      // std::cout << old_new_pair.first << std::endl;
      // std::cout << old_new_pair.second << std::endl;
      // std::cout << vlog_inline << std::endl;
    }
    vlg_wrapper.add_stmt(vlog_inline);

  } // for monitor_rec.items()
} // ConstructWrapper_add_vlg_monitor

const rfmap::InstructionCompleteCondition&
VlgSglTgtGen::get_current_instruction_rf() {
  ILA_NOT_NULL(_instr_ptr);
  const auto& inst_name = _instr_ptr->name().str();
  auto pos = refinement_map.inst_complete_cond.find(inst_name);
  if(pos == refinement_map.inst_complete_cond.end() &&
     refinement_map.global_inst_complete_set)
    return refinement_map.global_inst_complete_cond;
  ILA_ERROR_IF(pos == refinement_map.inst_complete_cond.end() &&
              !refinement_map.global_inst_complete_set)
      << "Cannot find the completion condition for " << inst_name;
  return pos->second;
} // get_current_instruction_rf

} // namespace ilang
