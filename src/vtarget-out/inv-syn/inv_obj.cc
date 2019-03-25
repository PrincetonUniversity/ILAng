/// \file Invariant Object --- should be able to parse from
/// a smt-like-output
// Hongce Zhang

#include <ilang/util/str_util.h>
#include <ilang/util/log.h>

#include <ilang/vtarget-out/inv-syn/inv_obj.h>
#include <ilang/smt-inout/chc_inv_in.h>

namespace ilang {

/// empty invariants
InvariantObject::InvariantObject() {
  
}
/// add invariants from smt-like output
void InvariantObject::AddInvariantFromChcResultFile(
    smt::YosysSmtParser & design_info, 
    const std::string & tag, const std::string & chc_result_fn,
    bool flatten_datatype, bool flatten_hierarchy ) {

  smt::SmtlibInvariantParser parser(&design_info,flatten_datatype, flatten_hierarchy);
  parser.ParseInvResultFromFile(chc_result_fn);
  ILA_ASSERT(not parser.in_bad_state());
  inv_vlg_exprs.push_back( parser.GetFinalTranslateResult() );
  for (auto && name_vlg_pair : parser.GetLocalVarDefs()) {
    inv_extra_vlg_vars.push_back(std::make_pair(
      name_vlg_pair.first,
      name_vlg_pair.second._translate));
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


}; // namespace ilang