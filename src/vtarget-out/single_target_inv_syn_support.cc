/// \file Source for Verilog Verification Targets Generation (single target)
/// the invariants (how they assume and assert)
/// the support for inv-syn (monolithic/cegar)
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

//
// should not have the flush condition set -- > because this should only be
// called when target is invariants

/*

What to assume and what to assert

Target : INVARIANT (may not be inductive)

           |  GUESSED  |  CONFIRMED |  RF provided |
  --------------------------------------------------
  ALL      |   assert  |   assert   |    assert    |
  CONFIRM  |           |   assert   |    assume    |
  CANDIDATE|   assert  |   assume   |    assume    |
  NOINV    |           |            |    assert    |


Target : INV_SYN_DESIGN_ONLY (reachability check)

    * reset used

  will call the following 3 functions
    * ConstructWrapper_inv_syn_add_cex_assertion    --- use cex as assertion
    * ConstructWrapper_inv_syn_add_inv_assumptions  --- depends on
InvariantSynthesisReachableCheckKeepOldInvariant
    * ConstructWrapper_inv_syn_connect_mem (also used in INVARIANT)

  Potentially also used as invariant-Z3 flow...
  then ConstructWrapper_inv_syn_add_cex_assertion use guessed invariant as
assertion

Target : INSTRUCTION

    * dummy_reset used

  1. all will be assume
  2. none will be assert
  3. alert for using GUESSED

*/

void VlgSglTgtGen::add_inv_obj_as_assertion(InvariantObject* inv_obj) {
  for (auto&& name_expr_pair : inv_obj->GetExtraVarDefs()) {
    vlg_wrapper.add_wire(std::get<0>(name_expr_pair),
                         std::get<2>(name_expr_pair), true);
    vlg_wrapper.add_assign_stmt(std::get<0>(name_expr_pair),
                                ReplExpr(std::get<1>(name_expr_pair), true));
  }
  for (auto&& name_w_pair : inv_obj->GetExtraFreeVarDefs()) {
    vlg_wrapper.add_wire(name_w_pair.first, name_w_pair.second, true);
    vlg_wrapper.add_input(name_w_pair.first, name_w_pair.second);
  }
  for (auto&& inv_expr : inv_obj->GetVlgConstraints()) {
    auto new_cond = ReplExpr(inv_expr, true);
    ILA_CHECK(!S_IN("][", new_cond))
        << "Inv translate error: ][ found in:" << new_cond;
    add_an_assertion(new_cond, "invariant_assert");
  }
} // add_inv_obj_as_assertion

void VlgSglTgtGen::add_inv_obj_as_assumption(InvariantObject* inv_obj) {
  // do you need to provide sub-module instance name?
  for (auto&& name_expr_pair : inv_obj->GetExtraVarDefs()) {
    vlg_wrapper.add_wire(std::get<0>(name_expr_pair),
                         std::get<2>(name_expr_pair), true);
    vlg_wrapper.add_assign_stmt(std::get<0>(name_expr_pair),
                                ReplExpr(std::get<1>(name_expr_pair), true));
  }
  for (auto&& name_w_pair : inv_obj->GetExtraFreeVarDefs()) {
    vlg_wrapper.add_wire(name_w_pair.first, name_w_pair.second, true);
    vlg_wrapper.add_input(name_w_pair.first, name_w_pair.second);
  }
  for (auto&& inv_expr : inv_obj->GetVlgConstraints()) {
    auto new_cond = ReplExpr(inv_expr, true);
    ILA_CHECK(!S_IN("][", new_cond))
        << "Inv translate error: ][ found in:" << new_cond;
    add_an_assumption(new_cond, "invariant_assume");
  }
} // add_inv_obj_as_assumption

void VlgSglTgtGen::add_rf_inv_as_assumption() {
  if (has_rf_invariant) {
    nlohmann::json& inv = IN("global invariants", rf_cond)
                              ? rf_cond["global invariants"]
                              : rf_cond["global-invariants"];
    for (auto& cond : inv) {
      auto new_cond = ReplExpr(cond.get<std::string>(), true);
      add_an_assumption(new_cond, "invariant_assume"); // without new var added
    } // for inv in global invariants field
  }
} // add_rf_inv_as_assumption

void VlgSglTgtGen::add_rf_inv_as_assertion() {
  // the provided invariants
  if (has_rf_invariant) {
    nlohmann::json& inv = IN("global invariants", rf_cond)
                              ? rf_cond["global invariants"]
                              : rf_cond["global-invariants"];
    for (auto& cond : inv) {
      auto new_cond =
          ReplExpr(cond.get<std::string>(), true); // force vlg state
      add_an_assertion("(" + new_cond + ")", "invariant_assert");
    }
  } // has_rf_invariant
} // add_rf_inv_as_assertion

// this is for cosa
void VlgSglTgtGen::
    ConstructWrapper_add_inv_assumption_or_assertion_target_invariant() {
  ILA_CHECK(target_type == target_type_t::INVARIANTS);
  if (_vtg_config.ValidateSynthesizedInvariant ==
          vtg_config_t::_validate_synthesized_inv::NOINV &&
      !has_rf_invariant) {
    ILA_CHECK(false)
        << "No invariant to handle for INVARIANT target, this is a bug!";
  }

  if (_vtg_config.ValidateSynthesizedInvariant ==
      vtg_config_t::_validate_synthesized_inv::ALL) {
    ILA_CHECK(has_confirmed_synthesized_invariant ||
              has_gussed_synthesized_invariant || has_rf_invariant)
        << "No invariant to handle for INVARIANT target, this is a bug!";
    if (has_confirmed_synthesized_invariant)
      add_inv_obj_as_assertion(_advanced_param_ptr->_inv_obj_ptr);
    if (has_gussed_synthesized_invariant)
      add_inv_obj_as_assertion(_advanced_param_ptr->_candidate_inv_ptr);
    add_rf_inv_as_assertion();

  } else if (_vtg_config.ValidateSynthesizedInvariant ==
             vtg_config_t::_validate_synthesized_inv::CANDIDATE) {
    ILA_CHECK(has_gussed_synthesized_invariant)
        << "No invariant to handle for INVARIANT target, need candidate "
           "invariant!";
    // check candidate
    add_inv_obj_as_assertion(_advanced_param_ptr->_candidate_inv_ptr);
    // assume rf and confirmed
    if (has_confirmed_synthesized_invariant)
      add_inv_obj_as_assumption(_advanced_param_ptr->_inv_obj_ptr);
    add_rf_inv_as_assumption();

  } else if (_vtg_config.ValidateSynthesizedInvariant ==
             vtg_config_t::_validate_synthesized_inv::CONFIRMED) {
    ILA_INFO_IF(has_confirmed_synthesized_invariant)
        << "Will ignore candidate invariants when checking confirmed "
           "invariants";
    ILA_CHECK(has_confirmed_synthesized_invariant)
        << "No invariant to handle for INVARIANT target, need candidate "
           "invariant!";
    // check confirmed
    add_inv_obj_as_assertion(_advanced_param_ptr->_inv_obj_ptr);
    // assume rf
    add_rf_inv_as_assumption();
  } else if (_vtg_config.ValidateSynthesizedInvariant ==
             vtg_config_t::_validate_synthesized_inv::NOINV) {
    // assert rf
    add_rf_inv_as_assertion();
  }
}

void VlgSglTgtGen::
    ConstructWrapper_add_inv_assumption_or_assertion_target_instruction() {
  ILA_CHECK(target_type == target_type_t::INSTRUCTIONS);
  ILA_WARN_IF(has_gussed_synthesized_invariant)
      << "Using guessed invariants also, please check to confirm them!";

  // -- assertions -- //
  // > NONE

  // -- assumption -- //
  if (has_confirmed_synthesized_invariant)
    add_inv_obj_as_assumption(_advanced_param_ptr->_inv_obj_ptr);
  if (has_gussed_synthesized_invariant)
    add_inv_obj_as_assumption(_advanced_param_ptr->_candidate_inv_ptr);
  add_rf_inv_as_assumption();
}

void VlgSglTgtGen::
    ConstructWrapper_add_inv_assumption_or_assertion_target_inv_syn_design_only() {
  ILA_CHECK(target_type == target_type_t::INV_SYN_DESIGN_ONLY);

  if (_advanced_param_ptr && _advanced_param_ptr->_cex_obj_ptr) {
    // this is cex reachability checking
    // -- assertions -- //
    auto new_cond =
        ReplExpr(_advanced_param_ptr->_cex_obj_ptr->GenInvAssert(""),
                 true); // force vlg state
    add_an_assertion("~(" + new_cond + ")", "cex_nonreachable_assert");
    // -- assumption -- //
    if (_vtg_config.InvariantSynthesisReachableCheckKeepOldInvariant) {
      add_rf_inv_as_assumption();
      if (has_confirmed_synthesized_invariant)
        add_inv_obj_as_assumption(_advanced_param_ptr->_inv_obj_ptr);
      if (has_gussed_synthesized_invariant) {
        ILA_WARN
            << "Using guessed invariants also, please check to confirm them!";
        add_inv_obj_as_assumption(_advanced_param_ptr->_candidate_inv_ptr);
      }
    }
  } // end of cex checking
  else if (has_gussed_synthesized_invariant) {
    // if this is general design invariant checking checking
    add_inv_obj_as_assertion(_advanced_param_ptr->_candidate_inv_ptr);

    if (has_confirmed_synthesized_invariant)
      add_inv_obj_as_assumption(_advanced_param_ptr->_inv_obj_ptr);
    add_rf_inv_as_assumption();
    /*
    if(has_confirmed_synthesized_invariant)
      add_inv_obj_as_assertion(_advanced_param_ptr->_inv_obj_ptr);
    add_rf_inv_as_assertion();
    */
  } else
    ILA_CHECK(false) << "Unknown invariant handling for design_only target!";
}

void VlgSglTgtGen::ConstructWrapper_inv_syn_cond_signals() {
  ILA_CHECK(target_type == target_type_t::INV_SYN_DESIGN_ONLY ||
            target_type == target_type_t::INVARIANTS);
  vlg_wrapper.add_input("__START__", 1);
  vlg_wrapper.add_input("__STARTED__", 1);
}

void VlgSglTgtGen::ConstructWrapper_inv_syn_connect_mem() {
  ILA_CHECK(target_type == target_type_t::INV_SYN_DESIGN_ONLY ||
            target_type == target_type_t::INVARIANTS);

  std::map<std::string, std::pair<int, int>> ila_mem_state_names;

  for (size_t state_idx = 0; state_idx < _host->state_num(); ++state_idx) {
    if (_host->state(state_idx)->is_mem())
      ila_mem_state_names.insert(
          std::make_pair(_host->state(state_idx)->name().str(),
                         std::make_pair<int, int>(
                             _host->state(state_idx)->sort()->addr_width(),
                             _host->state(state_idx)->sort()->data_width())));
  }
  nlohmann::json& state_mapping = IN("state mapping", rf_vmap)
                                      ? rf_vmap["state mapping"]
                                      : rf_vmap["state-mapping"];
  for (auto& i : state_mapping.items()) {
    auto sname = i.key(); // ila state name
    if (!IN(sname, ila_mem_state_names))
      continue; // we only care about the mem states
    if (i.value().is_null()) {
      ILA_ERROR << "Ignore mapping memory: " << sname;
      continue;
    }
    // ILA_INFO << i.key() << i.value();
    // Connect memory here
    if (i.value().is_string() &&
        StrStartsWith(i.value().get<std::string>(), "**")) {
      _idr.SetMemNameAndWidth(
          i.value(), sname, _vtg_config.MemAbsReadAbstraction,
          ila_mem_state_names[sname].first, ila_mem_state_names[sname].second);
      ila_mem_state_names.erase(sname);
    }
  }

  // check for unmapped memory
  for (auto&& m : ila_mem_state_names)
    ILA_ERROR << "No mapping exists for memory : " << m.first;
} // ConstructWrapper_inv_syn_connect_mem

} // namespace ilang
