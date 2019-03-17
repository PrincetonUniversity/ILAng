/// \file Invariant Object --- should be able to parse from
/// a smt-like-output
// Hongce Zhang

#include <ilang/util/str_util.h>
#include <ilang/util/log.h>

#include <ilang/vtarget-out/inv-syn/inv_obj.h>

namespace ilang {

/// empty invariants
InvariantObject::InvariantObject() {
  
}
/// add invariants from smt-like output
void InvariantObject::AddInvariantFromSmt(smt::YosysSmtParser & , const std::string & tag, const std::string & smt_result) {

}
/// add invariants from verilog-like output
void InvariantObject::AddInvariantFromVerilog(const std::string & tag, const std::string & vlg_in) {

}
/// generate invariants
std::string InvariantObject::GenerateVlgConstraints() const {

}

}; // namespace ilang