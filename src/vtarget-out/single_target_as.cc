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


void VlgSglTgtGen::add_an_assumption(const rfmap::RfExpr& aspt,
                                const std::string& dspt) {
  all_assumptions[dspt].push_back(aspt);
}

/// Add an assertion -- JasperGold will override this
void VlgSglTgtGen::add_an_assertion(const rfmap::RfExpr& asst,
                              const std::string& dspt) {
  all_assertions[dspt].push_back(asst);
}

static std::string const_to_unified_str(const rfmap::RfExpr & in) {
  auto cnst = verilog_expr::VExprAstConstant::cast_ptr(in);
  ILA_NOT_NULL(cnst);
  auto b_w_lit = cnst->get_constant();
  auto base = std::get<0>(b_w_lit);
  auto lit = std::get<2>(b_w_lit);
  if(base == 10 || base == 0)
    return lit;
  // else other base
  auto n = StrToULongLong(lit, base); 
  if(lit != "0" && n == 0) 
    return "error";
  return IntToStrCustomBase(n, 10, false);
}

static void find_and_replace_array_const(
  rfmap::RfExpr & expr, 
  std::map<std::string, rfmap::RfExpr> & array_const_set, // RTL.a.b.c[const]
  std::unordered_map<std::string, RtlExtraWire> & extra_wire) {
    auto fd_rp_array_const_func = [
      &array_const_set,&extra_wire
      ](rfmap::RfExpr & inout) {
      if(inout->get_op() == verilog_expr::voperator::INDEX &&
         inout->get_child_cnt() == 2 &&
         inout->child(0)->is_var() &&
         inout->child(1)->is_constant() &&
         rfmap::RfExprAstUtility::GetType(inout->child(0)).type.is_array()
         ) {
        auto hier_name = inout->to_verilog();
        auto cnst = const_to_unified_str(inout->child(1));
        if(cnst == "error" ) // if cannot convert
          return;
        
        auto new_name = ReplaceAll(hier_name,".","__DOT__");
        new_name += "_"+cnst+"_";
        if(array_const_set.find(new_name) != array_const_set.end()) {
          inout = array_const_set.at(new_name);
          return;
        }

        const auto last_dot_pos = hier_name.rfind(".");
        ILA_CHECK(last_dot_pos != std::string::npos);
        const auto hierarchy = hier_name.substr(0,last_dot_pos);
        const auto internal = hier_name.substr(last_dot_pos+1) + "["+cnst+"]";
        ILA_CHECK(!IN(new_name, extra_wire));


        auto tp = rfmap::RfExprAstUtility::GetType(inout->child(0)).type;
        auto w = tp.unified_width();

        extra_wire.emplace(new_name, 
          RtlExtraWire(new_name, hierarchy, internal, w));
        // new_name is the wire name

        // replace var
        auto repl = verilog_expr::VExprAst::MakeSpecialName(new_name);
        auto new_tp = std::make_shared<rfmap::TypeAnnotation>();
        new_tp->var_ref_type = rfmap::TypeAnnotation::VARTYPE::INTERNAL;
        new_tp->type = rfmap::RfMapVarType(w);
        repl->set_annotation(new_tp);
        inout = repl;

        array_const_set.emplace(new_name,repl);
      }
    };
    rfmap::RfExprAstUtility::TraverseRfExpr(expr, fd_rp_array_const_func);
} // find_and_replace_array_const

void VlgSglTgtGen::add_wire_assign_assumption(const std::string& varname,
                                          const rfmap::RfExpr &aspt,
                                          const std::string& dspt) {
  assign_or_assumptions.push_back(std::make_tuple(dspt, varname, aspt, nullptr));
}

  // read assumption/assertion, decide where to put them rtl/smt
  // perform the reg[n] optimize
  // populate the RtlExtraWire data structure
void VlgSglTgtGen::ConstructWrapper_translate_property_and_collect_all_rtl_connection_var() {
  bool is_jg = _backend == VlgSglTgtGen::backend_selector::JASPERGOLD;

  for(auto & dspt_vn_rfexpr_eq : assign_or_assumptions) {
    const auto & vn = std::get<1>(dspt_vn_rfexpr_eq);
    const auto & rfe = std::get<2>(dspt_vn_rfexpr_eq);
    std::get<3>(dspt_vn_rfexpr_eq) = 
      ReplExpr(rfmap_eq( rfmap_var(vn), rfe));
  } // for each assign/assumption

  for(auto & dspt_aspt : all_assumptions) {
    for(auto & aspt : dspt_aspt.second) 
      aspt = ReplExpr(aspt);
  }
  
  for (auto & dspt_asst : all_assertions) {
    for (auto & asst : dspt_asst.second) 
      asst = ReplExpr(asst);
  }

  if(is_jg) {
    for(auto & dspt_aspt : all_assumptions) {
      for(auto & aspt : dspt_aspt.second) 
        add_a_direct_assumption(  aspt->to_verilog(), dspt_aspt.first );
    }
    for(auto & dspt_asst : all_assertions) {
      for(auto & asst : dspt_asst.second) 
        add_a_direct_assumption(  asst->to_verilog(), dspt_asst.first );
    }
    for (auto & dspt_vn_rfexpr_eq : assign_or_assumptions) {
      const auto & vn = std::get<1>(dspt_vn_rfexpr_eq);
      const auto & eq = std::get<3>(dspt_vn_rfexpr_eq);
      // we know it is eq(vn, rhs);
      vlg_wrapper.add_assign_stmt(vn, eq->child(1)->to_verilog());
    }
    return;
  }

  for(const auto & repl : refinement_map.GetVarReplacement()) {
    ILA_CHECK( 
      StrStartsWith(repl.second.get_orig_name(), "RTL." ) ==
      repl.second.is_orig_rtlv()
    );

    if(!repl.second.is_orig_rtlv())
      continue;

    if(repl.second.is_orig_var_array())
      continue; // do not connect array
    
    ILA_CHECK(StrStartsWith(repl.second.get_new_name(), "RTL__DOT__"))
      << repl.second.get_new_name() << "is not replaced";
    // jaspergold should not reach here

    const auto full_name = repl.second.get_orig_name();
    const auto last_dot_pos = full_name.rfind(".");
    const auto hierarchy = full_name.substr(0,last_dot_pos);
    const auto internal = full_name.substr(last_dot_pos+1);
    unsigned width = repl.second.get_type_orig().type.unified_width();

    rtl_extra_wire.emplace(repl.second.get_new_name(),
      RtlExtraWire(repl.second.get_new_name(), hierarchy, internal, width));
  }

  std::map<std::string, rfmap::RfExpr> array_const_set;
  // below will also update `rtl_extra_wire`
  for(auto & dspt_aspt : all_assumptions) {
    for(auto & aspt : dspt_aspt.second) {
      find_and_replace_array_const(aspt, array_const_set, rtl_extra_wire);
    }
  }

  for(auto & dspt_asst : all_assertions) {
    for(auto & asst : dspt_asst.second) {
      find_and_replace_array_const(asst, array_const_set, rtl_extra_wire);
    }
  }

  for(auto & dspt_vn_rfexpr_eq : assign_or_assumptions) {
    auto & eq = std::get<3>(dspt_vn_rfexpr_eq);
    find_and_replace_array_const(eq, array_const_set, rtl_extra_wire);
  }

  // last step
  // if a=b[c] contains array not handled, then we need to have 
  // smt assumptions
  // otherwise, we can add it as an assign
  for (const auto & dspt_vn_rfexpr_eq : assign_or_assumptions) {
    const auto & eq = std::get<3>(dspt_vn_rfexpr_eq);
    const auto & dspt = std::get<0>(dspt_vn_rfexpr_eq);
    const auto & wn = std::get<1>(dspt_vn_rfexpr_eq);

    std::map<std::string, rfmap::RfVar>  array_var;
    if(rfmap::RfExprAstUtility::HasArrayVar(eq, array_var))
      add_smt_assumption(eq, dspt);
    else
      vlg_wrapper.add_assign_stmt(wn, eq->child(1)->to_verilog());
  }

  for(const auto & dspt_aspt : all_assumptions) {
    for(const auto & aspt : dspt_aspt.second) {
      std::map<std::string, rfmap::RfVar>  array_var;
      if(rfmap::RfExprAstUtility::HasArrayVar(aspt, array_var))
        add_smt_assumption(aspt, dspt_aspt.first);
      else
        add_a_direct_assumption(aspt->to_verilog(), dspt_aspt.first);
    }
  }

  for(const auto & dspt_asst : all_assertions) {
    for(const auto & asst : dspt_asst.second) {
      std::map<std::string, rfmap::RfVar>  array_var;
      if(rfmap::RfExprAstUtility::HasArrayVar(asst, array_var))
        add_smt_assertion(asst, dspt_asst.first);
      else
        add_a_direct_assertion(asst->to_verilog(), dspt_asst.first);
    }
  }
  
} // ConstructWrapper_translate_property_and_collect_all_rtl_connection_var


}; // namespace ilang
