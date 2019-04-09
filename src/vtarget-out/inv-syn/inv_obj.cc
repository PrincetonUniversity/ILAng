/// \file Invariant Object --- should be able to parse from
/// a smt-like-output
// Hongce Zhang

#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>

#include <ilang/vtarget-out/inv-syn/inv_obj.h>
#include <ilang/smt-inout/chc_inv_in.h>

namespace ilang {

/// empty invariants
InvariantObject::InvariantObject() {
  
}

void InvariantObject::set_dut_inst_name(const std::string & name) {
  dut_inst_name = name;
}

/// add invariants from smt-like output
void InvariantObject::AddInvariantFromChcResultFile(
    smt::YosysSmtParser & design_info, 
    const std::string & tag, const std::string & chc_result_fn,
    bool flatten_datatype, bool flatten_hierarchy ) {

  smt::SmtlibInvariantParser parser(
    &design_info,
    flatten_datatype, flatten_hierarchy,
    {"INV"}, dut_inst_name);

  if (not parser.ParseInvResultFromFile(chc_result_fn) ) {
    ILA_ERROR << "No new invariant has been extracted!";
    return;
  }
  ILA_ASSERT(not parser.in_bad_state());
  inv_vlg_exprs.push_back( parser.GetFinalTranslateResult() );
  for (auto && name_vlg_pair : parser.GetLocalVarDefs()) {
    inv_extra_vlg_vars.push_back(std::make_tuple(
      name_vlg_pair.first,
      name_vlg_pair.second._translate,
      name_vlg_pair.second._type.GetBoolBvWidth()));
  }
  for (auto && name_w_pair : parser.GetFreeVarDefs()) {
    if( IN(name_w_pair.first, inv_extra_free_vars) )
      ILA_ASSERT(inv_extra_free_vars[name_w_pair.first] == name_w_pair.second)
        << "Overwriting free var:" << name_w_pair.first << " w. width: " << name_w_pair.second
        << " old width:" << inv_extra_free_vars[name_w_pair.first];
    inv_extra_free_vars.insert(name_w_pair);
  }
} // AddInvariantFromChcResultFile

/// add invariants from verilog-like output
void InvariantObject::AddInvariantFromVerilogExpr(const std::string & tag, const std::string & vlg_in) {
  inv_vlg_exprs.push_back(vlg_in);
}


const InvariantObject::inv_vec_t & InvariantObject::GetVlgConstraints() const {
  return inv_vlg_exprs;
}
/// get the vars
const InvariantObject::extra_var_def_vec_t & InvariantObject::GetExtraVarDefs() const {
  return inv_extra_vlg_vars;
}

/// get the vars
const InvariantObject::extra_free_var_def_vec_t & InvariantObject::GetExtraFreeVarDefs() const {
  return inv_extra_free_vars;
}


}; // namespace ilang