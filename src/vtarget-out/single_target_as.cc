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
#include <ilang/rfmap-in/rfexpr_shortcut.h>
#include <ilang/rfmap-in/rfexpr_to_smt.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

// NOTE: add_an_assumption, add_an_assertion are not defined in base class

void VlgSglTgtGen::add_reg_cassign_assumption(const std::string& varname,
                                              const rfmap::RfExpr& expression,
                                              int width,
                                              const rfmap::RfExpr& cond,
                                              const std::string& dspt) {
  rfmap::RfExprAstUtility::RfMapNoNullNode(expression);
  rfmap::RfExprAstUtility::RfMapNoNullNode(cond);

  std::string rand_in_name = "__" + varname + "_init__";
  vlg_wrapper.add_input(rand_in_name, width);
  vlg_wrapper.add_wire(rand_in_name, width);

  vlg_wrapper.add_init_stmt(varname + " <= " + rand_in_name + ";");
  vlg_wrapper.add_always_stmt(varname + " <= " + varname + ";");
  add_an_assumption(rfmap_imply(cond, rfmap_eq(rfmap_var(varname), expression)),
                    dspt);
} // add_reg_cassign_assumption

void VlgSglTgtGen::add_smt_assumption(const rfmap::RfExpr& body,
                                      const std::string& dspt) {
  rfmap::RfExprAstUtility::RfMapNoNullNode(body);

  std::unordered_map<std::string, rfmap::RfVar> vars;
  rfmap::RfExprAstUtility::GetVars(body, vars);

  std::string body_smt2 =
      rfmap::RfExpr2Smt::to_smt2(body, rfmap::SmtType() /*Bool type*/);
  std::vector<std::string> arg;
  for (const auto& n_expr_pair : vars) {
    auto tp = refinement_map.GetType(n_expr_pair.second);
    auto smt_tp = rfmap::SmtType(tp.type, false);
    const auto& n = n_expr_pair.first;
    arg.push_back("(|" + n + "| " + smt_tp.type_to_smt2() + ")");
  }
  add_a_direct_smt_assumption("(" + Join(arg, " ") + ")", "Bool", body_smt2,
                              dspt);
}

// Add SMT assertion (using rfexpr)
void VlgSglTgtGen::add_smt_assertion(const rfmap::RfExpr& body,
                                     const std::string& dspt) {
  rfmap::RfExprAstUtility::RfMapNoNullNode(body);

  std::unordered_map<std::string, rfmap::RfVar> vars;
  rfmap::RfExprAstUtility::GetVars(body, vars);

  std::string body_smt2 =
      rfmap::RfExpr2Smt::to_smt2(body, rfmap::SmtType() /*Bool type*/);
  std::vector<std::string> arg;
  for (const auto& n_expr_pair : vars) {
    auto tp = refinement_map.GetType(n_expr_pair.second);
    auto smt_tp = rfmap::SmtType(tp.type, false);
    const auto& n = n_expr_pair.first;
    arg.push_back("(|" + n + "| " + smt_tp.type_to_smt2() + ")");
  }
  add_a_direct_smt_assertion("(" + Join(arg, " ") + ")", "Bool", body_smt2,
                             dspt);
}

void VlgSglTgtGen::add_an_assumption(const rfmap::RfExpr& aspt,
                                     const std::string& dspt) {

  rfmap::RfExprAstUtility::RfMapNoNullNode(aspt);
  all_assumptions[dspt].push_back(aspt);
}

void VlgSglTgtGen::add_an_assertion(const rfmap::RfExpr& asst,
                                    const std::string& dspt) {
  rfmap::RfExprAstUtility::RfMapNoNullNode(asst);
  all_assertions[dspt].push_back(asst);
}

void VlgSglTgtGen::add_a_cover(const rfmap::RfExpr& asst,
                                    const std::string& dspt) {
  rfmap::RfExprAstUtility::RfMapNoNullNode(asst);
  all_covers[dspt].push_back(asst);
}

void VlgSglTgtGen::add_a_santiy_assertion(const rfmap::RfExpr& asst,
                                          const std::string& dspt) {
  if (dspt == "post_value_holder_overly_constrained" &&
      !_vtg_config.SanityCheck_ValueRecorderOverlyConstrained)
    return;
  if (dspt == "post_value_holder_triggered" &&
      !_vtg_config.SanityCheck_ValueRecorderTriggeredBeforeCommit)
    return;

  rfmap::RfExprAstUtility::RfMapNoNullNode(asst);
  all_sanity_assertions[dspt].push_back(asst);
}

static std::string const_to_unified_str(const rfmap::RfExpr& in) {
  auto cnst = verilog_expr::VExprAstConstant::cast_ptr(in);
  ILA_NOT_NULL(cnst);
  auto b_w_lit = cnst->get_constant();
  auto base = std::get<0>(b_w_lit);
  auto lit = std::get<2>(b_w_lit);
  if (base == 10 || base == 0)
    return lit;
  // else other base
  auto n = StrToULongLong(lit, base);
  if (lit != "0" && n == 0)
    return "error";
  return IntToStrCustomBase(n, 10, false);
}

static std::string GetVlg(const rfmap::RfExpr & e) {
  try {
    return e->to_verilog();
  } catch (...) {
    ILA_ERROR<< "Cannot convert r-expr : " << e;
  }
  return "(error)";
}

static rfmap::RfExpr find_and_replace_array_const(
    const rfmap::RfExpr& expr,
    std::map<std::string, rfmap::RfExpr>& array_const_set, // RTL.a.b.c[const]
    std::unordered_map<std::string, RtlExtraWire>& extra_wire) {
  auto fd_rp_array_const_func = [&array_const_set,
                                 &extra_wire](const rfmap::RfExpr& in) -> rfmap::RfExpr {
    if (in->get_op() == verilog_expr::voperator::INDEX &&
        in->get_child_cnt() == 2 && in->get_child().at(0)->is_var() &&
        in->get_child().at(1)->is_constant() &&
        rfmap::RfExprAstUtility::GetType(in->get_child().at(0)).type.is_array()) {
      auto hier_name = GetVlg(in->get_child().at(0));
      auto cnst = const_to_unified_str(in->get_child().at(1));
      if (cnst == "error") // if cannot convert
        return in;

      auto new_name = ReplaceAll(hier_name, ".", "__DOT__");
      new_name += "_" + cnst + "_";
      rfmap::RfExpr ret;
      if (array_const_set.find(new_name) != array_const_set.end()) {
        ret = array_const_set.at(new_name);
        return ret;
      }

      const auto last_dot_pos = hier_name.rfind(".");
      ILA_CHECK(last_dot_pos != std::string::npos);
      const auto hierarchy = hier_name.substr(0, last_dot_pos);
      const auto internal =
          hier_name.substr(last_dot_pos + 1) + "[" + cnst + "]";
      ILA_CHECK(!IN(new_name, extra_wire));

      auto tp = rfmap::RfExprAstUtility::GetType(in->get_child().at(0)).type;
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
      ret = repl;

      array_const_set.emplace(new_name, repl);
      return ret;
    } // else
    return in;
  };
  return rfmap::RfExprAstUtility::TraverseRfExpr(expr, fd_rp_array_const_func);
} // find_and_replace_array_const

void VlgSglTgtGen::add_wire_assign_assumption(const std::string& varname,
                                              const rfmap::RfExpr& aspt,
                                              const std::string& dspt) {

  rfmap::RfExprAstUtility::RfMapNoNullNode(aspt);
  assign_or_assumptions.push_back(
      std::make_tuple(dspt, varname, aspt, nullptr));
}

// read assumption/assertion, decide where to put them rtl/smt
// perform the reg[n] optimize
// populate the RtlExtraWire data structure
void VlgSglTgtGen::
    ConstructWrapper_translate_property_and_collect_all_rtl_connection_var() {
  bool is_jg = _backend == ModelCheckerSelection::JASPERGOLD;

  for (auto& dspt_vn_rfexpr_eq : assign_or_assumptions) {
    const auto& vn = std::get<1>(dspt_vn_rfexpr_eq);
    const auto& rfe = std::get<2>(dspt_vn_rfexpr_eq);

    ILA_DLOG("VTG.ReplWireEq") << vn << " := " << GetVlg(rfe);
    std::get<3>(dspt_vn_rfexpr_eq) = ReplExpr(rfmap_eq(rfmap_var(vn), rfe));
  } // for each assign/assumption

  for (auto& dspt_aspt : all_assumptions) {
    for (auto& aspt : dspt_aspt.second) {
      ILA_DLOG("VTG.ReplAssume") << GetVlg(aspt);
      aspt = ReplExpr(aspt);
    }
  }

  for (auto& dspt_asst : all_assertions) {
    for (auto& asst : dspt_asst.second) {
      ILA_DLOG("VTG.ReplAssert") << GetVlg(asst);
      asst = ReplExpr(asst);
    }
  }

  for (auto& dspt_asst : all_sanity_assertions) {
    for (auto& asst : dspt_asst.second) {
      ILA_DLOG("VTG.ReplAssert") << GetVlg(asst);
      asst = ReplExpr(asst);
    }
  }

  for (auto& dspt_cvrs : all_covers) {
    for (auto& cvrs : dspt_cvrs.second) {
      ILA_DLOG("VTG.ReplAssert") << GetVlg(cvrs);
      cvrs = ReplExpr(cvrs);
    }
  }

  if (is_jg) {
    for (auto& dspt_aspt : all_assumptions) {
      for (auto& aspt : dspt_aspt.second)
        add_a_direct_assumption(GetVlg(aspt), dspt_aspt.first);
    }
    for (auto& dspt_asst : all_assertions) {
      for (auto& asst : dspt_asst.second)
        add_a_direct_assertion(GetVlg(asst), dspt_asst.first);
    }
    for (auto& dspt_asst : all_sanity_assertions) {
      for (auto& asst : dspt_asst.second)
        add_a_direct_sanity_assertion(GetVlg(asst), dspt_asst.first);
    }
    for (auto& dspt_cvrs : all_covers) {
      for (auto& cvr : dspt_cvrs.second)
        add_a_direct_cover_check(GetVlg(cvr), dspt_cvrs.first);
    }


    for (auto& dspt_vn_rfexpr_eq : assign_or_assumptions) {
      const auto& vn = std::get<1>(dspt_vn_rfexpr_eq);
      const auto& eq = std::get<3>(dspt_vn_rfexpr_eq);
      // we know it is eq(vn, rhs);
      vlg_wrapper.add_assign_stmt(vn, GetVlg(eq->get_child().at(1)));
    }
    return;
  } // end of is_jg (will not continue if using jg)

  for (const auto& repl : refinement_map.GetVarReplacement()) {
    ILA_CHECK(StrStartsWith(repl.second.get_orig_name(), "RTL.") ==
              repl.second.is_orig_rtlv());

    if (!repl.second.is_orig_rtlv())
      continue;

    if (repl.second.is_orig_var_array())
      continue; // do not connect array

    ILA_CHECK(StrStartsWith(repl.second.get_new_name(), "RTL__DOT__"))
        << repl.second.get_new_name() << "is not replaced";
    // jaspergold should not reach here

    const auto full_name = repl.second.get_orig_name();
    const auto last_dot_pos = full_name.rfind(".");
    const auto hierarchy = full_name.substr(0, last_dot_pos);
    const auto internal = full_name.substr(last_dot_pos + 1);
    unsigned width = repl.second.get_type_orig().type.unified_width();

    rtl_extra_wire.emplace(
        repl.second.get_new_name(),
        RtlExtraWire(repl.second.get_new_name(), hierarchy, internal, width));
  }

  std::map<std::string, rfmap::RfExpr> array_const_set;
  // below will also update `rtl_extra_wire`
  for (auto& dspt_aspt : all_assumptions) {
    for (auto& aspt : dspt_aspt.second) {
      aspt = find_and_replace_array_const(aspt, array_const_set, rtl_extra_wire);
      // this will find array[const] and replace as a word reference
    }
  }

  for (auto& dspt_asst : all_assertions) {
    for (auto& asst : dspt_asst.second) {
      asst = find_and_replace_array_const(asst, array_const_set, rtl_extra_wire);
    }
  }

  for (auto& dspt_vn_rfexpr_eq : assign_or_assumptions) {
    auto& eq = std::get<3>(dspt_vn_rfexpr_eq);
    eq = find_and_replace_array_const(eq, array_const_set, rtl_extra_wire);
  }

  // last step
  // if a=b[c] contains array not handled, then we need to have
  // smt assumptions
  // otherwise, we can add it as an assign
  for (const auto& dspt_vn_rfexpr_eq : assign_or_assumptions) {
    const auto& eq = std::get<3>(dspt_vn_rfexpr_eq);
    const auto& dspt = std::get<0>(dspt_vn_rfexpr_eq);
    const auto& wn = std::get<1>(dspt_vn_rfexpr_eq);

    ILA_DLOG("VTG.AddWireEq") << GetVlg(eq);

    std::map<std::string, rfmap::RfVar> array_var;
    if (rfmap::RfExprAstUtility::HasArrayVar(eq, array_var)) {
      ILA_ERROR_IF(!_vtg_config.YosysSmtArrayForRegFile)
        << "Requiring array sort in Yosys when generating"
        << " properties, please enable YosysSmtArrayForRegFile";
      add_smt_assumption(eq, dspt);
    } else
      vlg_wrapper.add_assign_stmt(
        wn, GetVlg(eq->get_child().at(1)));
  }

  for (const auto& dspt_aspt : all_assumptions) {
    for (const auto& aspt : dspt_aspt.second) {
      ILA_DLOG("VTG.AddAssume") << GetVlg(aspt);

      std::map<std::string, rfmap::RfVar> array_var;
      if (rfmap::RfExprAstUtility::HasArrayVar(aspt, array_var)) {
        ILA_ERROR_IF(!_vtg_config.YosysSmtArrayForRegFile)
          << "Requiring array sort in Yosys when generating"
          << " properties, please enable YosysSmtArrayForRegFile";
        add_smt_assumption(aspt, dspt_aspt.first);
      } else
        add_a_direct_assumption(GetVlg(aspt), dspt_aspt.first);
    }
  }

  for (const auto& dspt_asst : all_assertions) {
    for (const auto& asst : dspt_asst.second) {
      ILA_DLOG("VTG.AddAssert") << GetVlg(asst);

      std::map<std::string, rfmap::RfVar> array_var;
      if (rfmap::RfExprAstUtility::HasArrayVar(asst, array_var))
        add_smt_assertion(asst, dspt_asst.first);
      else
        add_a_direct_assertion(GetVlg(asst), dspt_asst.first);
    }
  }

  for (const auto& dspt_asst : all_sanity_assertions) {
    for (const auto& asst : dspt_asst.second) {
      std::map<std::string, rfmap::RfVar> array_var;
      ILA_CHECK(!rfmap::RfExprAstUtility::HasArrayVar(asst, array_var))
          << "Implementation bug: sanity checking assertion should not contain "
             "arrays";

      add_a_direct_sanity_assertion(GetVlg(asst), dspt_asst.first);
    }
  }
  for (const auto& dspt_cvrs : all_covers) {
    for (const auto& cvr : dspt_cvrs.second) {
      std::map<std::string, rfmap::RfVar> array_var;
      ILA_CHECK(!rfmap::RfExprAstUtility::HasArrayVar(cvr, array_var))
          << "Implementation bug: cover checks should not contain "
             "arrays";

      add_a_direct_cover_check(GetVlg(cvr), dspt_cvrs.first);
    }
  }

} // ConstructWrapper_translate_property_and_collect_all_rtl_connection_var

}; // namespace ilang
