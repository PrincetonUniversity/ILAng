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

void VlgSglTgtGen::RfmapIlaStateSanityCheck() {
#define ERR_IF(cond,s) do { ILA_ERROR_IF(cond) << (s); _bad_state = true; return; } while(0)

  for(unsigned sidx = 0; sidx < _host->state_num(); ++ sidx) {
    const auto & s = _host->state(sidx);
    const auto & n = s->name().str();
    ERR_IF(!IN(n, refinement_map.ila_state_var_map), "state `" + n + "` not in refinement map" );
  }

  for(unsigned sidx = 0; sidx < _host->input_num(); ++ sidx) {
    const auto & s = _host->input(sidx);
    const auto & n = s->name().str();
    ERR_IF(!IN(n, refinement_map.ila_input_var_map), "input `" + n + "` not in refinement map" );
  }

  for(const auto & n_map_pair : refinement_map.ila_state_var_map) {
    ERR_IF(_host->find_state(n_map_pair.first) == nullptr, "state `" + n_map_pair.first + "` not defined in ILA");
  }

  for(const auto & n_map_pair : refinement_map.ila_input_var_map) {
    ERR_IF(_host->find_input(n_map_pair.first) == nullptr, "input `" + n_map_pair.first + "` not defined in ILA");
  }

#undef ERR_IF
}


void VlgSglTgtGen::ConstructWrapper_add_additional_mapping_control() {
  for(const auto & mapc : refinement_map.additional_mapping) {
    add_an_assumption(ReplExpr(mapc), "additional_mapping_control_assume");
  }
} // ConstructWrapper_add_additional_mapping_control

void VlgSglTgtGen::ConstructWrapper_add_rf_assumptions() {
  for (const auto & assumpt : refinement_map.assumptions) {
    add_an_assumption(ReplExpr(assumpt), "rfassumptions");
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

  for (const auto & uf_app : refinement_map.uf_application) {
    const auto& funcName = uf_app.first;
    const auto& list_of_time_of_apply = uf_app.second.func_applications;
    if(!IN(funcName, name_to_fnapp_vec)) {
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
        ILA_ERROR << "ila func app expect: "
                  << ila_app_item.args.size() << " (args)."
                  << " Given:" << each_apply.arg_map.size()
                  << " items, for func: " << funcName;
        continue;
      }
      const auto & arg_apply = each_apply.arg_map;
      const auto & result_apply = each_apply.result_map;
      std::string func_result_wire = funcName + "_" + IntToStr(idx - 1) + "_result_wire";

      auto res_map = "~( __START__ )||(" + func_result_wire + "==" + ReplExpr(result_apply) + ")";

      std::string prep = VLG_TRUE;
      size_t arg_idx = 0;
      for (const auto & each_arg : arg_apply) {

        std::string func_arg = funcName + "_" + IntToStr(idx - 1) + "_arg" +
                               IntToStr(arg_idx++) + "_wire";

        prep += "&&(~( __START__ )||((" + func_arg + ") == (" + ReplExpr(each_arg) + ")))";
      }
      // (
      //   (decode |-> arg0_output == ??@?? ) && (decode |-> arg1_output == ??@?? )
      //    && ...
      // ) |-> (
      //   (decode |-> result_input == ??@??)
      // )
      add_an_assumption("~(" + prep + ") || (" + res_map + ")", "funcmap");
    } // for each apply in the list of apply

    name_to_fnapp_vec.erase(funcName); // remove from it   
  }

  // check for unmapped func
  for (auto&& nf : name_to_fnapp_vec)
    ILA_ERROR << "lacking function map for func:" << nf.first;
} // ConstructWrapper_add_uf_constraints


void VlgSglTgtGen::ConstructWrapper_add_delay_unit() {
  for(const auto & delay_unit : refinement_map.aux_delays) {
    const auto & name = delay_unit.first;
    const auto & du = delay_unit.second;
    
    ILA_ERROR_IF(du.num_cycle == 0) << "Cannot delay 0 cycle";
    std::string last_reg;
    for(size_t didx = 1; didx <= du.num_cycle; ++ didx) {
      auto curr_name = name+"_d_"+std::to_string(didx);
      auto prev_name = name+"_d_"+std::to_string(didx-1);
      vlg_wrapper.add_reg(curr_name, delay_unit.second.width);
      if(didx == 1) {
        // delay from signal
        auto rhs = ReplExpr(du.signal);
        if (du.delay_type != rfmap::SignalDelay::delay_typeT::SINGLE && du.width > 1)
          rhs = "|(" + rhs + ")";
        vlg_wrapper.add_always_stmt(curr_name + " <= " + rhs);
      } else {
        vlg_wrapper.add_always_stmt(curr_name + " <= " + prev_name + " ;");
      }
      if(didx == du.num_cycle)
        last_reg = curr_name;
    } // end - for each delay
    if(du.delay_type == rfmap::SignalDelay::delay_typeT::SINGLE) {
      vlg_wrapper.add_wire(name, du.width);
      vlg_wrapper.add_assign_stmt(name, last_reg);
      continue;
    } // else
    if(du.delay_type == rfmap::SignalDelay::delay_typeT::TO_INFINITE) {
      auto summary_var = name+"_inf_";
      vlg_wrapper.add_reg(summary_var, 1);
      vlg_wrapper.add_init_stmt(summary_var + "<= 1'b0;");
      vlg_wrapper.add_always_stmt("if( " + last_reg + ") " + summary_var + " <= 1'b1;");
      vlg_wrapper.add_wire(name, 1);
      vlg_wrapper.add_assign_stmt(name, summary_var + " || " + last_reg);
      continue;
    }
    // finally the range
    // if (du.delay_type == rfmap::SignalDelay::delay_typeT::RANGE)
    ILA_ERROR_IF(du.upper_bnd <= du.num_cycle) << "in `##[l:u]`, we need `l < u` ";
    std::string or_reduce = last_reg;
    for(size_t didx = du.num_cycle+1; didx <= du.upper_bnd; ++ didx) {
      auto curr_name = name+"_d_"+std::to_string(didx);
      auto prev_name = name+"_d_"+std::to_string(didx-1);
      vlg_wrapper.add_reg(curr_name, 1);
      vlg_wrapper.add_always_stmt(curr_name + " <= " + prev_name + " ;");
      
      or_reduce += " || " + curr_name;
    }
    vlg_wrapper.add_wire(name, 1);
    vlg_wrapper.add_assign_stmt(name, or_reduce);
  } // end for each delay unit
} // end ConstructWrapper_add_delay_unit

void VlgSglTgtGen::ConstructWrapper_add_stage_tracker() {
  for(const auto & n_tracker : refinement_map.phase_tracker) {
    
    const auto & tracker = n_tracker.second;
    for (const auto & vardef : tracker.var_defs) {
      const auto & vn = vardef.first;
      if ( vardef.second.type == rfmap::GeneralVerilogMonitor::VarDef::var_type::REG )
        vlg_wrapper.add_reg(vn, vardef.second.width);
      else
        vlg_wrapper.add_wire(vn, vardef.second.width);
    }
    for ( const auto & event_alias : tracker.event_alias) {
      vlg_wrapper.add_wire( event_alias.first, 1);
      vlg_wrapper.add_assign_stmt(event_alias.first, ReplExpr(event_alias.second));
    }
    unsigned sidx = 0;
    for (const auto & stage : tracker.rules) {
      std::string stage_name = stage.stage_name.empty() ? "stage" + std::to_string(sidx) : stage.stage_name;
      vlg_wrapper.add_reg(stage_name , 1);
      
      vlg_wrapper.add_always_stmt("if(" + ReplExpr(stage.enter_rule)  + ") begin " + stage_name + " <= 1'b1;" );
      for(const auto & action : stage.enter_action)
        vlg_wrapper.add_always_stmt(action.LHS + " <= " + ReplExpr(action.RHS));
      vlg_wrapper.add_always_stmt("end");
      vlg_wrapper.add_always_stmt("else if(" + ReplExpr(stage.exit_rule) + ") begin " + stage_name + " <= 1'b0;");
      for(const auto & action : stage.exit_action)
        vlg_wrapper.add_always_stmt(action.LHS + " <= " + ReplExpr(action.RHS));
      vlg_wrapper.add_always_stmt("end");

      sidx ++;
    } // for each stage
  } // for each tracker
} // ConstructWrapper_add_stage_tracker

void VlgSglTgtGen::ConstructWrapper_add_post_value_holder() {
  for(const auto & post_val_holder : refinement_map.value_recorder) {
    const auto & pv_name = post_val_holder.first;
    vlg_wrapper.add_reg(pv_name, post_val_holder.second.width);
    add_reg_cassign_assumption(pv_name, 
      ReplExpr(post_val_holder.second.value), 
      post_val_holder.second.width,
      ReplExpr(post_val_holder.second.condition),
      "post_value_holder");
  }
} // ConstructWrapper_add_post_value_holder

void VlgSglTgtGen::ConstructWrapper_add_vlg_monitor() {
  if(refinement_map.customized_monitor.empty())
    return;
    
  const auto& monitor_rec = refinement_map.customized_monitor;

  for (auto&& m_rec : monitor_rec) {
    
    const auto& mdef = m_rec.second; // generalMonitor

    std::string vlg_expr;
    std::vector<std::string> repl_list;
    bool keep_for_non_instruction_target = mdef.keep_for_invariant;

    if (target_type != target_type_t::INSTRUCTIONS &&
        !keep_for_non_instruction_target)
      continue;

    for (const auto & n_def : mdef.var_defs) {
      if(n_def.second.type == rfmap::GeneralVerilogMonitor::VarDef::var_type::REG)
        vlg_wrapper.add_reg(n_def.first, n_def.second.width);
      else
        vlg_wrapper.add_wire(n_def.first, n_def.second.width);
    }

    std::vector<std::pair<std::string, std::string>> replace_list;
    for (const auto & vref : mdef.var_uses) {
      auto vref_node = ::verilog_expr::VExprAst::MakeVar(vref);
      auto new_name = ReplExpr(vref_node);
      replace_list.push_back(std::make_pair(vref, new_name));
    }

    auto vlog_inline = mdef.verilog_inline;
    for (const auto & old_new_pair : replace_list) {
      vlog_inline = ReplaceAll(vlog_inline, old_new_pair.first, old_new_pair.second);
    }
    vlg_wrapper.add_stmt(vlog_inline);
    
  } // for monitor_rec.items()
} // ConstructWrapper_add_vlg_monitor


const rfmap::InstructionCompleteCondition & VlgSglTgtGen::get_current_instruction_rf() {
  ILA_NOT_NULL(_instr_ptr);
  const auto & inst_name = _instr_ptr->name().c_str();
  auto pos = refinement_map.inst_complete_cond.find(inst_name);
  ILA_ERROR_IF(pos == refinement_map.inst_complete_cond.end())
    << "Cannot find the completion condition for " << inst_name;
  return pos->second;
} // get_current_instruction_rf

} // namespace ilang
