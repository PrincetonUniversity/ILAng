/// \file Source for Verilog Verification Targets Generation (single target)
/// the invariants (how they assume and assert)
/// the support for inv-syn (monolithic/cegar)
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

  
//
// should not have the flush condition set -- > because this should only be
// called when target is invariants

void VlgSglTgtGen::ConstructWrapper_add_inv_assertions() {
  ILA_ASSERT(target_type == target_type_t::INVARIANTS)
      << "Implementation bug: should only be used when verifying invariants";
  
  ILA_WARN_IF (_advanced_param_ptr && _advanced_param_ptr->_inv_obj_ptr) 
    << "additional invariants will not be checked here.";

  if (not IN("global invariants", rf_cond))
    return;
  if (rf_cond["global invariants"].size() == 0)
    return; // no invariants to add
  if (not rf_cond["global invariants"].is_array()) {
    ILA_ERROR << "'global invariants' field in refinement relation has to be a "
                 "JSON array.";
    return;
  }
  for (auto& cond : rf_cond["global invariants"]) {
    auto new_cond = ReplExpr(cond.get<std::string>(), true); // force vlg state
    add_an_assertion("(" + new_cond + ")", "invariant_assert");
  }
} // ConstructWrapper_add_inv_assertions


void VlgSglTgtGen::ConstructWrapper_add_inv_assumptions() {
  ILA_ASSERT(target_type == target_type_t::INSTRUCTIONS)
      << "Implementation bug: inv assumpt should only be used when verifying "
         "instructions.";

  // the precondition of invariants
  std::string precondition;
  if (_vtg_config.OnlyEnforceInvariantsOnInitialStateOfInstrCheck)
    precondition = has_flush ? "(~ __RESETED__) || " : "(~ __START__) || ";
  else
    precondition = ""; // always assume no matter what

  if ( IN("global invariants", rf_cond) 
    && rf_cond["global invariants"].size() > 0 ) {
    if (not rf_cond["global invariants"].is_array()) {
        ILA_ERROR << "'global invariants' field in refinement relation has to be a "
                    "JSON array.";
        return;
    } // type check of global invariants
    
    for (auto& cond : rf_cond["global invariants"]) {
      auto new_cond = ReplExpr(cond.get<std::string>(), true);
      // inv-syn will ignore the precondition anyway
      if(_backend == backend_selector::YOSYS)
        add_a_direct_assumption(new_cond, "invariant_assume"); // without new var added
      else
        add_an_assumption(precondition + "(" + new_cond + ")", "invariant_assume");
    } // for inv in global invariants field
  } // insert from global invariant
  
  // check the additional invariants
  if (_advanced_param_ptr && _advanced_param_ptr->_inv_obj_ptr) {
    // do you need to provide sub-module instance name?

    ILA_ASSERT(_backend != backend_selector::YOSYS) 
      << "YOSYS target is for non-cegar-loop invariant synthesis,"
      << "Please use CHC target instead.";

    for (auto && name_expr_pair : _advanced_param_ptr->_inv_obj_ptr->GetExtraVarDefs() ){
      vlg_wrapper.add_wire(name_expr_pair.first, 1, true);
      vlg_wrapper.add_assign_stmt(name_expr_pair.first, 
        ReplExpr(name_expr_pair.second, true) );
    }
    for (auto && inv_expr : _advanced_param_ptr->_inv_obj_ptr->GetVlgConstraints()) {
      auto new_cond = ReplExpr( inv_expr, true );
      add_an_assumption( precondition + "(" + new_cond + ")" , "invariant_assume");
    }
  } // end of adding additional invariants
} // ConstructWrapper_add_inv_assumptions


void VlgSglTgtGen::ConstructWrapper_inv_syn_add_cex_assertion() {
  ILA_ASSERT(target_type == target_type_t::INV_SYN_DESIGN_ONLY);
  ILA_ASSERT(_advanced_param_ptr and _advanced_param_ptr->_cex_obj_ptr);

  auto new_cond = ReplExpr(
    _advanced_param_ptr->_cex_obj_ptr->GenInvAssert(""), true); // force vlg state

  add_an_assertion("~(" + new_cond + ")", "cex_nonreachable_assert");
}

void VlgSglTgtGen::ConstructWrapper_inv_syn_add_inv_assumptions() {
  ILA_ASSERT(target_type == target_type_t::INV_SYN_DESIGN_ONLY);
  if (not _vtg_config.InvariantSynthesisReachableCheckKeepOldInvariant) {
    ILA_INFO << "Ignore existing invariants in cex check";
    return;
  }

  if ( IN("global invariants", rf_cond) 
    && rf_cond["global invariants"].size() > 0 ) {
    if (not rf_cond["global invariants"].is_array()) {
        ILA_ERROR << "'global invariants' field in refinement relation has to be a "
                    "JSON array.";
        return;
    } // type check of global invariants
    
    for (auto& cond : rf_cond["global invariants"]) {
      auto new_cond = ReplExpr(cond.get<std::string>(), true);
      add_a_direct_assumption(new_cond, "invariant_assume"); // without new var added
    } // for inv in global invariants field
  } // insert from global invariant

  // check the additional invariants
  if (_advanced_param_ptr && _advanced_param_ptr->_inv_obj_ptr) {
    // do you need to provide sub-module instance name?
    for (auto && name_expr_pair : _advanced_param_ptr->_inv_obj_ptr->GetExtraVarDefs() ){
      vlg_wrapper.add_wire(name_expr_pair.first, 1, true);
      vlg_wrapper.add_assign_stmt(name_expr_pair.first, 
        ReplExpr(name_expr_pair.second, true) );
    }
    for (auto && inv_expr : _advanced_param_ptr->_inv_obj_ptr->GetVlgConstraints()) {
      auto new_cond = ReplExpr( inv_expr, true );
      add_an_assumption( new_cond , "invariant_assume");
    }
  } // end of adding additional invariants
} // ConstructWrapper_inv_syn_add_inv_assumptions


void VlgSglTgtGen::ConstructWrapper_inv_syn_connect_mem() {
  ILA_ASSERT(target_type == target_type_t::INV_SYN_DESIGN_ONLY
    or target_type == target_type_t::INVARIANTS);

  std::set<std::string> ila_mem_state_names;

  for (size_t state_idx = 0; state_idx < _host->state_num(); ++state_idx) {
    if (_host->state(state_idx)->is_mem())
      ila_mem_state_names.insert(_host->state(state_idx)->name().str());
  }

  for (auto& i : (rf_vmap["state mapping"]).items()) {
    auto sname = i.key(); // ila state name
    if (not IN(sname, ila_mem_state_names))
      continue; // we only care about the mem states
    ila_mem_state_names.erase(sname);
    // Connect memory here
    _idr.SetMemName(i.value(), sname, _vtg_config.MemAbsReadAbstraction);
  }

  // check for unmapped memory
  for (auto && m : ila_mem_state_names)
    ILA_ERROR << "No mapping exists for memory : " << m;
} // ConstructWrapper_inv_syn_connect_mem

} // namespace ilang

