/// \file Source for Verilog Verification Targets Generation (single target)
/// assumption and assertion handling generic case -- JasperGold has its
/// override
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <cmath>
#include <fstream>
#include <iostream>

#include <ilang/ila/ast_hub.h>
#include <ilang/mcm/ast_helper.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/rfmap-in/rfexpr_to_smt.h>
#include <ilang/rfmap-in/rfexpr_shortcut.h>

namespace ilang {

// NOTE: add_an_assumption, add_an_assertion are not defined in base class

void VlgSglTgtGen::add_reg_cassign_assumption(const std::string& varname,
                                              const rfmap::RfExpr& expression,
                                              int width,
                                              const rfmap::RfExpr& cond,
                                              const std::string& dspt) {
                                                
  std::string rand_in_name = "__" + varname + "_init__";
  vlg_wrapper.add_input(rand_in_name, width);
  vlg_wrapper.add_wire(rand_in_name, width);

  vlg_wrapper.add_init_stmt(varname + " <= " + rand_in_name + ";");
  vlg_wrapper.add_always_stmt(varname + " <= " + varname + ";");
  add_an_assumption(
    rfmap_imply(cond, rfmap_eq(rfmap_var(varname), expression)), dspt);
} // add_reg_cassign_assumption


void VlgSglTgtGen::add_smt_assumption(
  const rfmap::RfExpr & body,
  const std::string & dspt)
{ 
  std::unordered_map<std::string, rfmap::RfVar> vars;
  rfmap::RfExprAstUtility::GetVars(body, vars);

  std::string body_smt2 = 
    rfmap::RfExpr2Smt::to_smt2(body, rfmap::SmtType() /*Bool type*/ );
  std::vector<std::string> arg;
  for(const auto & n_expr_pair : vars) {
    auto tp = refinement_map.GetType( n_expr_pair.second );
    auto smt_tp = rfmap::SmtType(tp.type, false);
    const auto & n = n_expr_pair.first;
    arg.push_back("("+n + " " + smt_tp.type_to_smt2() + ")");
  } 
  add_a_direct_smt_assumption(
    "("+Join(arg, " ")+")", "Bool", body_smt2, dspt);
}

// Add SMT assertion (using rfexpr)
void VlgSglTgtGen::add_smt_assertion(
  const rfmap::RfExpr & body,
  const std::string & dspt)
{
  std::unordered_map<std::string, rfmap::RfVar> vars;
  rfmap::RfExprAstUtility::GetVars(body, vars);

  std::string body_smt2 = 
    rfmap::RfExpr2Smt::to_smt2(body, rfmap::SmtType() /*Bool type*/ );
  std::vector<std::string> arg;
  for(const auto & n_expr_pair : vars) {
    auto tp = refinement_map.GetType( n_expr_pair.second );
    auto smt_tp = rfmap::SmtType(tp.type, false);
    const auto & n = n_expr_pair.first;
    arg.push_back("("+n + " " + smt_tp.type_to_smt2() + ")");
  } 
  add_a_direct_smt_assertion(
    "("+Join(arg, " ")+")", "Bool", body_smt2, dspt);
}


}; // namespace ilang
