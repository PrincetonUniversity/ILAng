/// \file rfmap_typecheck.cc Refinement map typecheck
///  Second pass : rfexpr typecheck

#include <ilang/rfmap-in/rfmap_typecheck.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

#include <cassert>
#include <list>
#include <string>
#include <cmath>

namespace ilang {
namespace rfmap {

using namespace verilog_expr;

std::string TypedVerilogRefinementMap::new_id() {
  return "__auxvar" + std::to_string(counter++) + "__";
}

TypedVerilogRefinementMap::TypedVerilogRefinementMap(
    const VerilogRefinementMap& refinement, var_typecheck_t type_checker)
    : VerilogRefinementMap(refinement), typechecker(type_checker), counter(0) {
  initialize();
}

TypedVerilogRefinementMap::TypedVerilogRefinementMap(
    const std::string& varmap_json_file, const std::string& instcond_json_file,
    var_typecheck_t type_checker)
    : VerilogRefinementMap(varmap_json_file, instcond_json_file),
      typechecker(type_checker), counter(0) {
  initialize();
} // TypedVerilogRefinementMap::TypedVerilogRefinementMap

void TypedVerilogRefinementMap::initialize() {
  // collect those with unknown types
  // a. delay
  // b. value holder
  CollectInlineDelayValueHolder();

  // put existing internal vars in
  // all_var_def_types
  CollectInternallyDefinedVars();

  // determine the types of delay and value holder
  // and add them to all_var_def_types
  // will use current all_var_def_types
  ComputeDelayValueHolderWidth();

} // initialize

// this function will iteratively make a new copy of the whole AST.
RfExpr RfExprVarReplUtility::ReplacingRtlIlaVar(const RfExpr& in, const std::set<std::string> & quantified_vars) {

  // skip state memory mapped
  // provide a function to ReplExpr...
  auto tp_annotate = in->get_annotation<TypeAnnotation>();

  if (in->is_var()) {
    auto var_ptr = std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(in);
    ILA_NOT_NULL(var_ptr);
    auto n = var_ptr->get_name();
    if(quantified_vars.find(n.first) != quantified_vars.end())
      return in; // will not replace a quantified variable

    ILA_CHECK(var_replacement.find(n.first) != var_replacement.end())
        << "variable " << n.first << " has no replacement";

    return var_replacement.at(n.first).newvar;
  } else if (in->is_constant()) {
    return in;
  }
  // else is op
  std::vector<RfExpr> retchild;
  bool has_quantifier = 
    in->get_op() == verilog_expr::voperator::EXIST ||
    in->get_op() == verilog_expr::voperator::FORALL;
  if(has_quantifier) {
    std::set<std::string> new_quantified_vars(quantified_vars);
    ILA_ASSERT(in->get_child_cnt() == 1 && in->get_str_parameter().size() == 1);
    new_quantified_vars.insert(in->get_str_parameter().at(0)); // the quantified var
    retchild.push_back(ReplacingRtlIlaVar(in->get_child().at(0), new_quantified_vars));
  } else {
    for (size_t idx = 0; idx < in->get_child_cnt(); ++idx) {
      retchild.push_back(ReplacingRtlIlaVar(in->get_child().at(idx), quantified_vars));
    }
  }
  auto ret = in->MakeCopyWithNewChild(retchild);
  ret->set_annotation(in->get_annotation<TypeAnnotation>());
  return ret;
} // AnnotateSignalsAndCollectRtlVars

RfExpr TypedVerilogRefinementMap::collect_inline_value_recorder_func(
    const RfExpr& in) {
  if (in->get_op() != verilog_expr::voperator::AT)
    return in;

  auto recorder_name = new_id() + "recorder";
  auto new_node = verilog_expr::VExprAst::MakeVar(recorder_name);

  verilog_expr::VExprAst::VExprAstPtrVec child(in->get_child());
  ValueRecorder tmp_value_recorder;
  tmp_value_recorder.width = 0;
  tmp_value_recorder.value = child.at(0);
  // TODO: deal with value@CLK.n
  if (child.at(1)->is_constant()) {
    // deal with value@0
    auto new_cond = verilog_expr::VExprAst::MakeBinaryAst(
        verilog_expr::voperator::L_EQ,
        verilog_expr::VExprAst::MakeVar("__CYCLE_CNT__"), child.at(1));
    tmp_value_recorder.condition = new_cond;
  } else
    tmp_value_recorder.condition = child.at(1);
  value_recorder.emplace(recorder_name, tmp_value_recorder);
  return new_node; // rewrite the node
} // collect_inline_value_recorder_func

RfExpr TypedVerilogRefinementMap::collect_inline_delay_func(const RfExpr& in) {
  if (in->get_op() != voperator::DELAY)
    return in;
  // else
  assert(in->get_parameter().size() == in->get_str_parameter().size());
  assert(in->get_child().size() == 1 || in->get_child().size() == 2);
  assert(in->get_parameter().size() == 1 || in->get_parameter().size() == 2);

  auto delay_name = new_id() + "delay";
  auto new_node = VExprAst::MakeVar(delay_name);

  if (in->get_parameter().size() == 1) {
    // Single a ##n
    int delay = in->get_parameter().at(0);
    aux_delays.emplace(delay_name, SignalDelay(in->get_child().at(0), delay));
    // std::cout << "SingleDelay:" <<in->get_child().at(0) <<std::endl;
  } else { // in->get_parameter().size() == 2
    // RANGE/INF a ##[n,m] / ##[n,0]   0 represents $
    int delay = in->get_parameter().at(0);
    int delay_upper = in->get_parameter().at(1);
    aux_delays.emplace(delay_name,
                       SignalDelay(in->get_child().at(0), delay, delay_upper));
    // std::cout << "2Delay:" <<in->get_child().at(0) <<std::endl;
  }

  // std::cout << "Repl:" << in ;
  RfExpr ret;
  if (in->get_child().size() == 1) {
    ret = new_node;
  } else {
    assert(in->get_child().size() == 2);
    auto tmp_node = VExprAst::MakeBinaryAst(voperator::L_AND, new_node,
                                            in->get_child().at(1));
    ret = tmp_node;
  }
  // std::cout << "-->:" << ret <<std::endl;
  return ret;
} // collect_inline_delay_func

// will convert delay and @ to internal names
// but will not add type information
// will put in aux_delays
// and value_recorder
void TypedVerilogRefinementMap::CollectInlineDelayValueHolder() {
  TraverseAllRfExpr([this](const RfExpr& in) -> RfExpr {
    return this->collect_inline_delay_func(in);
  });
  TraverseAllRfExpr([this](const RfExpr& in) -> RfExpr {
    return this->collect_inline_value_recorder_func(in);
  });
}

// internal datastructure like
// phase_tracker, value_recorder, customized_monitor, aux_delay ->
// all_var_def_types
//
void TypedVerilogRefinementMap::CollectInternallyDefinedVars() {
  for (const auto& n_st : phase_tracker) {
    for (const auto& var_def : n_st.second.event_alias) {
      VarDef tmp;
      tmp.type = VarDef::var_type::WIRE;
      tmp.width = 1;
      all_var_def_types.emplace(var_def.first, tmp);
    }
    for (const auto& var_def : n_st.second.var_defs) {
      all_var_def_types.emplace(var_def.first, var_def.second);
    }
    for (const auto& stage : n_st.second.rules) {
      VarDef tmp;
      tmp.type = VarDef::var_type::REG;
      tmp.width = 1;
      all_var_def_types.emplace(stage.stage_name, tmp);
    }
  }
  for (const auto& n_st : value_recorder) {
    VarDef tmp;
    if (n_st.second.width != 0) {
      tmp.width = n_st.second.width;
      tmp.type = VarDef::var_type::REG;
      all_var_def_types.emplace(n_st.first, tmp);
    }
  } // value recorder

  for (const auto& n_expr : direct_aux_vars) {
    ILA_CHECK(n_expr.second.width == 0);
  } // direct aux vars

  for (const auto& n_st : customized_monitor) {
    for (const auto& var_def : n_st.second.var_defs) {
      all_var_def_types.emplace(var_def.first, var_def.second);
    }
  }

  // add internal signals
  { // add decode,commit, $decode, $valid
    VarDef tmp;
    tmp.width = 1;
    tmp.type = VarDef::var_type::WIRE;

    all_var_def_types.emplace("decode", tmp);      // these are the stage info
    all_var_def_types.emplace("afterdecode", tmp); // these are the stage info
    all_var_def_types.emplace("commit", tmp);


    all_var_def_types.emplace("start", tmp);      // these are the stage info
    all_var_def_types.emplace("afterstart", tmp); // these are the stage info
    all_var_def_types.emplace("end", tmp);

    all_var_def_types.emplace("$decode",
                              tmp); // these are the ila.decode/ila.valid info
    all_var_def_types.emplace("$valid", tmp);

  } // end of add decode,commit, $decode, $valid

} // CollectInternallyDefinedVars

void TypedVerilogRefinementMap::TraverseCondMap(
    SingleVarMap& inout, std::function<RfExpr(const RfExpr& inout)> func) {
  if (inout.single_map)
    inout.single_map = TraverseRfExpr(inout.single_map, func);
  else
    for (auto& c : inout.cond_map) {
      c.first = TraverseRfExpr(c.first, func);
      c.second = TraverseRfExpr(c.second, func);
    }
} // TraverseCondMap

void TypedVerilogRefinementMap::TraverseAllRfExpr(
    std::function<RfExpr(const RfExpr& inout)> func) {
  for (auto& sv : ila_state_var_map) {
    if (sv.second.type == IlaVarMapping::StateVarMapType::SINGLE)
      sv.second.single_map.single_map =
          TraverseRfExpr(sv.second.single_map.single_map, func);
    else if (sv.second.type == IlaVarMapping::StateVarMapType::CONDITIONAL) {
      for (auto& c : sv.second.single_map.cond_map) {
        c.first = TraverseRfExpr(c.first, func);
        c.second = TraverseRfExpr(c.second, func);
      }
    } else { // extern map
      for (auto& m : sv.second.externmem_map) {
        TraverseCondMap(m.raddr_map, func);
        TraverseCondMap(m.rdata_map, func);
        TraverseCondMap(m.ren_map, func);
        TraverseCondMap(m.waddr_map, func);
        TraverseCondMap(m.wdata_map, func);
        TraverseCondMap(m.wen_map, func);
      }
    }
  } // sv map

  for (auto& sv : ila_input_var_map) {
    if (sv.second.type == IlaVarMapping::StateVarMapType::SINGLE)
      sv.second.single_map.single_map =
          TraverseRfExpr(sv.second.single_map.single_map, func);
    else /* if(sv.second.type == IlaVarMapping::StateVarMapType::CONDITIONAL) */
    {
      for (auto& c : sv.second.single_map.cond_map) {
        c.first = TraverseRfExpr(c.first, func);
        c.second = TraverseRfExpr(c.second, func);
      }
    }
  } // input var

  for (auto& ufa : uf_application) {
    for (auto& fapp : ufa.second.func_applications) {
      fapp.result_map = TraverseRfExpr(fapp.result_map, func);
      for (auto& a : fapp.arg_map)
        a = TraverseRfExpr(a, func);
    }
  } // uf application
  for (auto& a : assumptions)
    a = TraverseRfExpr(a, func);
  for (auto& a : additional_mapping)
    a = TraverseRfExpr(a, func);

  for (auto& ptracker : phase_tracker) {
    for (auto& a : ptracker.second.event_alias)
      a.second = TraverseRfExpr(a.second, func);
    for (auto& r : ptracker.second.rules) {
      r.enter_rule = TraverseRfExpr(r.enter_rule, func);
      if (r.exit_rule)
        r.exit_rule = TraverseRfExpr(r.exit_rule, func);
      for (auto& act : r.enter_action)
        act.RHS = TraverseRfExpr(act.RHS, func);
      for (auto& act : r.exit_action)
        act.RHS = TraverseRfExpr(act.RHS, func);
    }
  } // phase tracker
  for (auto& pv : value_recorder) {
    pv.second.condition = TraverseRfExpr(pv.second.condition, func);
    pv.second.value = TraverseRfExpr(pv.second.value, func);
  }
  for (auto& n_expr : direct_aux_vars) {
    n_expr.second.val = TraverseRfExpr(n_expr.second.val, func);
  }

  // ALERT: NOT handle customized_monitor in TraverseRfExpr

  for (auto& instcond : inst_complete_cond) {
    if (instcond.second.type ==
        InstructionCompleteCondition::ConditionType::SIGNAL)
      instcond.second.ready_signal =
          TraverseRfExpr(instcond.second.ready_signal, func);
    for (auto& cond : instcond.second.start_condition)
      cond = TraverseRfExpr(cond, func);
  }
  if (global_inst_complete_set) {
    if ( global_inst_complete_cond.type == InstructionCompleteCondition::ConditionType::SIGNAL) 
      global_inst_complete_cond.ready_signal = TraverseRfExpr(global_inst_complete_cond.ready_signal, func);
  }

  for (auto& a : global_invariants)
    a = TraverseRfExpr(a, func);

  for (auto& p_rf : rtl_interface_connection.input_port_connection) {
    p_rf.second = TraverseRfExpr(p_rf.second, func);
  }

} // TraverseAllRfExpr

// ------------------------------------------------------------------------------

// helper for type inference
bool _compute_const(const RfExpr& in, unsigned& out) {
  if (!in->is_constant())
    return false;
  std::shared_ptr<VExprAstConstant> cst_ast_ptr =
      std::dynamic_pointer_cast<VExprAstConstant>(in);
  if (cst_ast_ptr == nullptr)
    return false;
  auto bws = cst_ast_ptr->get_constant();
  auto base = std::get<0>(bws);
  if (base == 0)
    base = 10;
  // auto width = std::get<1>(bws);
  out = StrToLong(std::get<2>(bws), base);
  return true;
}

// this does not rely on type annotation
// relies on TypeInferTravserRfExpr
//    and therefore, all_var_def_types
void TypedVerilogRefinementMap::ComputeDelayValueHolderWidth() {


  unsigned failed_cnt = 0;
  unsigned prev_failed_cnt = 0;
  unsigned iter = 0;
  do {
    prev_failed_cnt = failed_cnt;
    failed_cnt = 0;
    for (auto& name_delay_pair : aux_delays) {
      if (name_delay_pair.second.width == 0) {
        auto tp = TypeInferTravserRfExpr(name_delay_pair.second.signal, {});
        ILA_CHECK(!tp.is_array())
            << "Currently does not support to delay a memory variable";

        if (tp.is_array() || tp.is_unknown() || tp.unified_width() == 0) {
          failed_cnt ++;
          continue;
        }

        name_delay_pair.second.width = tp.unified_width();

        // replendish all_var_def_types
        VarDef internal_var_def;
        internal_var_def.width = tp.unified_width();
        internal_var_def.type = VarDef::var_type::REG;

        all_var_def_types.emplace(name_delay_pair.first, internal_var_def);
      }
    }
    for (auto& name_vr : value_recorder) {
      if (name_vr.second.width == 0) {
        auto tp = TypeInferTravserRfExpr(name_vr.second.value, {});
        ILA_CHECK(!tp.is_array())
            << "Currently does not support to delay a memory variable";

        if (tp.is_array() || tp.is_unknown() || tp.unified_width() == 0) {
          failed_cnt ++;
          continue;
        }

        name_vr.second.width = tp.unified_width();

        // replendish all_var_def_types
        VarDef internal_var_def;
        internal_var_def.width = tp.unified_width();
        internal_var_def.type = VarDef::var_type::REG;

        all_var_def_types.emplace(name_vr.first, internal_var_def);
      }
    } // replendish internal defined vars

    for (auto& n_expr : direct_aux_vars) {
      if (n_expr.second.width == 0) {

        auto tp = TypeInferTravserRfExpr(n_expr.second.val, {});
        ILA_CHECK(!tp.is_array())
            << "Currently does not support to delay a memory variable";

        if (tp.is_array() || tp.is_unknown() || tp.unified_width() == 0 ) {
          failed_cnt ++;
          continue;
        }
        n_expr.second.width = tp.unified_width();

        VarDef internal_var_def;
        internal_var_def.width = tp.unified_width();
        internal_var_def.type = VarDef::var_type::WIRE;
        all_var_def_types.emplace(n_expr.first, internal_var_def);
      }
    } // end of for (auto& n_expr : direct_aux_vars)
    ILA_ASSERT(prev_failed_cnt >= failed_cnt || prev_failed_cnt == 0);
    ILA_INFO_IF(failed_cnt > 0) << "Rf Expr Type Resolution: iter "  
      << (iter++) << " remaining: " << failed_cnt;
  }while(prev_failed_cnt != failed_cnt && failed_cnt != 0);
  // the last round : report failed ones
  ILA_INFO_IF(prev_failed_cnt > 0) << "Rf Expr Type Resolution: iter "  
      << (iter++) << " remaining: " << failed_cnt;

    for (auto& name_delay_pair : aux_delays) {
      ILA_ERROR_IF (name_delay_pair.second.width == 0)
            << "Type inference failed on: "
            << name_delay_pair.second.signal->to_verilog();
    }

    for (auto& name_vr : value_recorder) {
      ILA_ERROR_IF (name_vr.second.width == 0) 
            << "Type inference failed on: " << name_vr.second.value->to_verilog();
    }

    for (auto& n_expr : direct_aux_vars) {
        ILA_ERROR_IF(n_expr.second.width == 0)
            << "Type inference failed on: " << n_expr.second.val->to_verilog();
    }
} // ComputeDelayValueHolderWidth

// relies on typechecker and all_var_def_types
RfMapVarType TypedVerilogRefinementMap::TypeInferTravserRfExpr(
    const RfExpr& in, const std::map<std::string, int> local_var_def) {
  
  ILA_CHECK(local_var_def.empty());
  // I believe we will never need to go into
  // a forall/exists case because it is boolean!

  if (in->is_constant()) {
    auto c = std::dynamic_pointer_cast<verilog_expr::VExprAstConstant>(in)
                 ->get_constant();
    return RfMapVarType(std::get<1>(c));
  } else if (in->is_var()) {
    auto n =
        std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(in)->get_name();

    auto local_var_pos = local_var_def.find(n.first);
    if (local_var_pos != local_var_def.end()) {
      ILA_WARN_IF(n.second) << n.first
                            << " is regarded as quantified variable, which "
                               "should not be a special name";
      return RfMapVarType(local_var_pos->second);
    }

    auto pos_def_var = all_var_def_types.find(n.first);

    if (n.second) { // is a special name
      // check special name first
      if (pos_def_var != all_var_def_types.end()) {
        ILA_WARN_IF(pos_def_var->second.width == 0)
            << "Using width of not yet"
            << " determined var " << n.first;
        return RfMapVarType(pos_def_var->second.width);
      }

      RfVarTypeOrig rtl_ila_vartype = typechecker(n.first);
      if (!rtl_ila_vartype.type.is_unknown())
        return rtl_ila_vartype.type;
      // then rtl ila name
    } else {
      // check rtl ila name first
      // then special name
      RfVarTypeOrig rtl_ila_vartype = typechecker(n.first);
      if (!rtl_ila_vartype.type.is_unknown())
        return rtl_ila_vartype.type;
      if (pos_def_var != all_var_def_types.end()) {
        ILA_WARN_IF(pos_def_var->second.width == 0)
            << "Using width of not yet"
            << " determined var " << n.first;
        return RfMapVarType(pos_def_var->second.width);
      }
    }                      // if # ... # else not
    return RfMapVarType(); // unknown type
  } else {                 // has op

    if (in->get_child_cnt() == 1 &&
        (in->get_op() == voperator::B_AND ||  // & a
         in->get_op() == voperator::B_NAND || // ~& a
         in->get_op() == voperator::B_OR ||   // | a
         in->get_op() == voperator::B_NOR ||  // ~| a
         in->get_op() == voperator::B_XOR ||  // ^ a
         in->get_op() == voperator::B_EQU     // "^~"|"~^"
         )) {
      return RfMapVarType(1);
    }

    if (in->get_op() == verilog_expr::voperator::STAR ||
        in->get_op() == verilog_expr::voperator::PLUS ||
        in->get_op() == verilog_expr::voperator::MINUS ||
        in->get_op() == verilog_expr::voperator::DIV ||
        in->get_op() == verilog_expr::voperator::POW ||
        in->get_op() == verilog_expr::voperator::MOD ||
        in->get_op() == verilog_expr::voperator::B_NEG ||
        in->get_op() == verilog_expr::voperator::B_AND ||
        in->get_op() == verilog_expr::voperator::B_OR ||
        in->get_op() == verilog_expr::voperator::B_XOR ||
        in->get_op() == verilog_expr::voperator::B_NAND ||
        in->get_op() == verilog_expr::voperator::B_NOR) {
      // the max of the args
      unsigned nchild = in->get_child_cnt();
      unsigned maxw = 0;
      for (size_t idx = 0; idx < nchild; idx++) {
        RfMapVarType t =
            TypeInferTravserRfExpr(in->get_child().at(idx), local_var_def);
        if (t.is_bv())
          maxw = std::max(maxw, t.unified_width());
      }
      return RfMapVarType(maxw);
    } else if (in->get_op() == verilog_expr::voperator::ASL ||
               in->get_op() == verilog_expr::voperator::ASR ||
               in->get_op() == verilog_expr::voperator::LSL ||
               in->get_op() == verilog_expr::voperator::LSR ||
               in->get_op() == verilog_expr::voperator::AT) { // the left type
      assert(in->get_child_cnt() == 2);
      return TypeInferTravserRfExpr(in->get_child().at(0), local_var_def);
    } else if (in->get_op() == verilog_expr::voperator::DELAY) {
      // arg 1: width of first
      // arg 2: width is 1 !!!
      assert(in->get_child_cnt() == 1 || in->get_child_cnt() == 2);
      if (in->get_child_cnt() == 2)
        return RfMapVarType(1);

      // set return type to be the same as the first one
      return TypeInferTravserRfExpr(in->get_child().at(0), local_var_def);
    } else if (in->get_op() == verilog_expr::voperator::GTE ||
               in->get_op() == verilog_expr::voperator::LTE ||
               in->get_op() == verilog_expr::voperator::GT ||
               in->get_op() == verilog_expr::voperator::LT ||
               in->get_op() == verilog_expr::voperator::C_EQ ||
               in->get_op() == verilog_expr::voperator::L_EQ ||
               in->get_op() == verilog_expr::voperator::C_NEQ ||
               in->get_op() == verilog_expr::voperator::L_NEQ ||
               in->get_op() == verilog_expr::voperator::L_NEG ||
               in->get_op() == verilog_expr::voperator::L_AND ||
               in->get_op() == verilog_expr::voperator::L_OR) {
      return RfMapVarType(1);
    } else if (in->get_op() == verilog_expr::voperator::INDEX) {
      RfMapVarType child_type =
          TypeInferTravserRfExpr(in->get_child().at(0), local_var_def);
      if (child_type.is_array())
        return RfMapVarType(child_type.unified_width()); // data width
      // TODO: check index within ?
      if (child_type.is_bv())
        return RfMapVarType(1);
      return RfMapVarType(); // UNKNOWN type
    } else if (in->get_op() == verilog_expr::voperator::IDX_PRT_SEL_PLUS ||
               in->get_op() == verilog_expr::voperator::IDX_PRT_SEL_MINUS) {
      assert(in->get_child().size() == 3);
      unsigned diff;
      bool succ = _compute_const(in->get_child().at(2), diff /*ref*/);
      // TODO: check index within ?
      if (succ)
        return RfMapVarType(diff);
      return RfMapVarType();
    } else if (in->get_op() == verilog_expr::voperator::RANGE_INDEX) {
      assert(in->get_child_cnt() == 3);
      unsigned l, r;

      bool succ = _compute_const(in->get_child().at(1), l /*ref*/);
      succ = succ && _compute_const(in->get_child().at(2), r /*ref*/);
      if (!succ)
        return RfMapVarType();
      // TODO: check width!
      return RfMapVarType(std::max(l, r) - std::min(l, r) + 1);
    } else if (in->get_op() == verilog_expr::voperator::STORE_OP) {
      // TODO: check width!
      // actually not implemented
      return TypeInferTravserRfExpr(in->get_child().at(0), local_var_def);
    } else if (in->get_op() == verilog_expr::voperator::TERNARY) {
      auto left = TypeInferTravserRfExpr(in->get_child().at(1), local_var_def);
      auto right = TypeInferTravserRfExpr(in->get_child().at(2), local_var_def);
      if (left.is_unknown() && right.is_unknown())
        return RfMapVarType(); // unknown
      if (left.is_unknown())
        return right;
      if (right.is_unknown())
        return left;

      if (left.is_array() || right.is_array())
        return left; // TODO: check compatibility

      return RfMapVarType(
          std::max(left.unified_width(), right.unified_width()));
    } else if (in->get_op() == verilog_expr::voperator::FUNCTION_APP) {
      return RfMapVarType();
    } else if (in->get_op() == verilog_expr::voperator::CONCAT) {
      unsigned nchild = in->get_child_cnt();
      unsigned sumw = 0;
      for (size_t idx = 0; idx < nchild; idx++) {
        RfMapVarType t =
            TypeInferTravserRfExpr(in->get_child().at(idx), local_var_def);
        if (t.is_bv())
          sumw += t.unified_width();
        else
          return RfMapVarType(); // cannot decide
      }
      return RfMapVarType(sumw);
    } else if (in->get_op() == verilog_expr::voperator::REPEAT) {
      assert(in->get_child_cnt() == 2);
      unsigned ntimes;
      if (!_compute_const(in->get_child().at(0), ntimes))
        return RfMapVarType();
      auto tp = TypeInferTravserRfExpr(in->get_child().at(1), local_var_def);
      if (tp.is_unknown())
        return RfMapVarType(); // unknown
      return RfMapVarType(tp.unified_width() * ntimes);
    } else if (in->get_op() == verilog_expr::voperator::FORALL ||
               in->get_op() == verilog_expr::voperator::EXIST) {

      return RfMapVarType(1);
      // std::map<std::string, int> new_var_def;
      // const auto& sparam = in->get_str_parameter();
      // const auto& param = in->get_parameter();
      // ILA_CHECK(sparam.size() == 1 && param.size() == 1);
      // new_var_def.emplace(sparam.at(0), param.at(0));
      // return TypeInferTravserRfExpr(in->get_child().at(0), new_var_def);
    }
    ILA_ASSERT(false) << "BUG: Operator " << int(in->get_op())
                      << " is not handled";
  } // end of else has op
  return RfMapVarType();
} // TypeInferTravserRfExpr

// --------------------------------------------------------
//  RfExprAstUtility
// --------------------------------------------------------

RfVarTypeOrig RfExprAstUtility::GetType(const RfExpr& in) {
  auto anno = in->get_annotation<TypeAnnotation>();
  ILA_NOT_NULL(anno);
  return *anno;
}

void RfExprAstUtility::GetVars(
    const RfExpr& in, std::unordered_map<std::string, RfVar>& vars_out) {
  // bfs walk
  std::vector<std::pair<RfExpr, bool>> stack;
  std::vector<std::set<std::string>> quantified_vars;
  stack.push_back(std::make_pair(in, false));
  quantified_vars.push_back({});
  while (!stack.empty()) {
    auto& back = stack.back();
    const auto &curr_quantified_var = quantified_vars.back();

    auto backvar = back.first;
    if (back.second) {
      quantified_vars.pop_back();
      stack.pop_back();
      continue;
    }
    // back.second == false
    back.second = true;
    if (backvar->is_var()) {
      ILA_ASSERT(backvar->get_child().size() == 0);
      verilog_expr::VExprAstVar::VExprAstVarPtr varptr =
          std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(backvar);
      ILA_NOT_NULL(varptr);
      const auto name = varptr->get_name().first;
      if(curr_quantified_var.find(name) == curr_quantified_var.end())
        vars_out.emplace(name, varptr); // only add it if not quantified
    } // end of is_var
    else {
      auto new_quantified_var(curr_quantified_var); // this is necessary
      // because reference could become invalid when you start to push
      if(backvar->get_op() == verilog_expr::voperator::FORALL || 
          backvar->get_op() == verilog_expr::voperator::EXIST) {
        new_quantified_var.insert(backvar->get_str_parameter().at(0));
      }

      for (const auto& c : backvar->get_child()) {
        stack.push_back(std::make_pair(c, false));
        quantified_vars.push_back(new_quantified_var);
      } // end - for each child
    } // end of else
  } // end while (stack is not empty)
} // end of GetVars


/// will only replace the free var, so we need to keep track
/// if some var inside are quantified, in that case, should not mask 
/// EXPECT: newexpr has annnotation !!!
RfExpr RfExprAstUtility::ReplaceQuantifiedVar(const std::string &name,
    const RfExpr & in, const RfExpr & newexpr,
    const std::set<std::string> & quantified_var) {
  // traverse the tree
  if (in->is_var()) {
    auto var_ptr = std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(in);
    ILA_NOT_NULL(var_ptr);
    auto n = var_ptr->get_name();
    // will only replace free var
    if(quantified_var.find(n.first) != quantified_var.end())
      return in;
    if (n.first == name)
      return newexpr;
    return in;
  } else if (in->is_constant()) {
    return in;
  }
  // else is op
  std::set<std::string> p_quantified_var(quantified_var);
  if(in->get_op() == verilog_expr::voperator::FORALL || 
     in->get_op() == verilog_expr::voperator::EXIST) {
       ILA_ASSERT(in->get_str_parameter().size() == 1);
       p_quantified_var.insert(in->get_str_parameter().at(0));
  }

  std::vector<RfExpr> retchild;
  for (size_t idx = 0; idx < in->get_child_cnt(); ++idx) {
    retchild.push_back(
      ReplaceQuantifiedVar(
        name,
        in->get_child().at(idx),
        newexpr,
        p_quantified_var
        ));
  }
  auto ret = in->MakeCopyWithNewChild(retchild);
  ret->set_annotation(in->get_annotation<TypeAnnotation>());
  return ret;
} // END of ReplaceQuantifiedVar

/// expand the current one, should be invoked from the leaf node
RfExpr RfExprAstUtility::QuantifierInstantiation(const RfExpr& in) {
  ILA_CHECK(in->get_op() == verilog_expr::voperator::FORALL ||
            in->get_op() == verilog_expr::voperator::EXIST);
  ILA_ASSERT(in->get_str_parameter().size() == 1);
  ILA_ASSERT(in->get_parameter().size() == 1);
  ILA_ASSERT(in->get_child_cnt() == 1);

  auto child = in->get_child().at(0);
  bool use_and = in->get_op() == verilog_expr::voperator::FORALL;
  auto anno = in->get_annotation<TypeAnnotation>();
  ILA_WARN_IF(anno && anno->type.unified_width() != 1) 
    << "FORALL/EXIST has non-Boolean Formula as child";

  const std::string quantified_var_name = in->get_str_parameter().at(0);
  const int quantified_var_width = in->get_parameter().at(0);
  ILA_CHECK(quantified_var_width <= 32)
    << "Quantifier instantiation for width > 32 is strongly discouraged";
  long long range = std::pow(2,quantified_var_width);
  RfExpr ret = nullptr;
  for(long long idx = 0; idx < range; ++idx) {
    auto new_const = verilog_expr::VExprAst::MakeConstant(10, quantified_var_width, std::to_string(idx));
    
    RfVarTypeOrig tp;
    tp.type =
        RfMapVarType(quantified_var_width); // base, width,...
    new_const->set_annotation(std::make_shared<TypeAnnotation>(tp));
    RfExpr repl = ReplaceQuantifiedVar(quantified_var_name, child, new_const, {});
    if(ret == nullptr)
      ret = repl;
    else
      ret = verilog_expr::VExprAst::MakeBinaryAst(
        use_and ? verilog_expr::voperator::L_AND : verilog_expr::voperator::L_OR,
        repl, ret);
    ret->set_annotation(anno);
  }
  return ret;
} // END of QuantifierInstantiation


/// determine if a rf expr has quantifier in it
bool RfExprAstUtility::HasQuantifier(const RfExpr& in) {
  bool ret = false;
  TraverseRfExprNoModify(in, [&ret](const RfExpr &e) -> void {
    if(e->get_op() == verilog_expr::voperator::EXIST ||
       e->get_op() == verilog_expr::voperator::FORALL)
       ret = true;
  } );
  return ret;
}
///  for pono, this will cause to use text
/// FORALL -> /\ /\ /\ ...  (JasperGold)
/// EXISTS -> \/ \/ \/ ...
RfExpr RfExprAstUtility::FindExpandQuantifier(const RfExpr& in) {
  return TraverseRfExpr(in, [](const RfExpr &e) -> RfExpr{
    if(e->get_op() == verilog_expr::voperator::EXIST ||
       e->get_op() == verilog_expr::voperator::FORALL)
       return QuantifierInstantiation(e);
    // else
    return e;    
  });
}

bool RfExprAstUtility::HasArrayVar(const RfExpr& in) {
  if (in->is_var()) {
    auto anno = in->get_annotation<TypeAnnotation>();
    ILA_NOT_NULL(anno);
    auto memvar = std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(in);
    ILA_NOT_NULL(memvar);
    if (anno->type.is_array()) {
      // array_var.emplace(std::get<0>(memvar->get_name()), memvar);
      return true;
    }
    return false;
  } else if (in->is_constant()) {
    return false;
  }
  bool has_array = false;
  for (size_t idx = 0; idx < in->get_child_cnt(); idx++) {
    has_array = has_array || HasArrayVar(in->get_child().at(idx));
    if (has_array)
      break;
  }
  return has_array;
}

void RfExprAstUtility::RfMapNoNullNode(const RfExpr& in) {
  ILA_NOT_NULL(in);
  size_t cnt = in->get_child_cnt();
  for (size_t idx = 0; idx < cnt; ++idx)
    RfMapNoNullNode(in->get_child().at(idx));
}

void RfExprAstUtility::TraverseRfExprNoModify(const RfExpr& in,
    std::function<void(const RfExpr& inout)> func) {
  ILA_NOT_NULL(in);
  std::vector<std::pair<RfExpr, unsigned>> parent_stack;
  while (!parent_stack.empty()) {
    auto& lastlv = parent_stack.back();
    auto cnt = lastlv.first->get_child_cnt();
    auto& idx = lastlv.second;
    if (idx >= cnt) { // also cnt could be 0 (leaf)
      func(lastlv.first);
      parent_stack.pop_back();
      if (!parent_stack.empty())
        ++parent_stack.back().second;
      continue;
    }
    ILA_ASSERT(lastlv.first->get_child_cnt() != 0);
    parent_stack.push_back(
        std::make_pair(lastlv.first->get_child().at(idx), 0U));
  }
}

RfExpr RfExprAstUtility::TraverseRfExpr(
    const RfExpr& in, std::function<RfExpr(const RfExpr& inout)> func) {
  ILA_NOT_NULL(in);
  std::vector<std::vector<RfExpr>> child_stack;
  child_stack.push_back({});
  child_stack.push_back({}); // Yes, do it twice!
  std::vector<std::pair<RfExpr, unsigned>> parent_stack;
  parent_stack.push_back(std::make_pair(in, 0U));
  while (!parent_stack.empty()) {
    auto& lastlv = parent_stack.back();
    auto cnt = lastlv.first->get_child_cnt();
    auto& idx = lastlv.second;
    if (idx >= cnt) {
      auto new_c = lastlv.first->MakeCopyWithNewChild(child_stack.back());
      auto new_node = func(new_c);
      new_node->set_annotation(lastlv.first->get_annotation<TypeAnnotation>());
      child_stack.pop_back();
      child_stack.back().push_back(new_node);
      parent_stack.pop_back();
      if (!parent_stack.empty())
        ++parent_stack.back().second;
      continue;
    } // else
    ILA_CHECK(lastlv.first->get_child_cnt() != 0);
    parent_stack.push_back(
        std::make_pair(lastlv.first->get_child().at(idx), 0U));
    child_stack.push_back({});
  } // end of while
  ILA_CHECK(child_stack.size() == 1);
  ILA_CHECK(child_stack.at(0).size() == 1);
  return child_stack.at(0).at(0);
} // TraverseRfExpr

bool RfExprAstUtility::IsLastLevelBooleanOp(const RfExpr& in) {
  std::set<verilog_expr::voperator> boolean_op = {
      verilog_expr::voperator::GTE,   verilog_expr::voperator::LTE,
      verilog_expr::voperator::GT,    verilog_expr::voperator::LT,
      verilog_expr::voperator::C_EQ,  verilog_expr::voperator::L_EQ,
      verilog_expr::voperator::C_NEQ, verilog_expr::voperator::L_NEQ,
      verilog_expr::voperator::L_NEG, verilog_expr::voperator::L_AND,
      verilog_expr::voperator::L_OR,  verilog_expr::voperator::FORALL,
      verilog_expr::voperator::EXIST};

  if (in->is_constant() || in->is_var())
    return false;
  auto op = in->get_op();
  return (boolean_op.find(op) != boolean_op.end());
}

// --------------------------------------------------------
//  TypeAnalysisUtility
// --------------------------------------------------------

// type inference rules
// differences from TypedVerilogRefinementMap::ReplacingRtlIlaVar
// 1. no var replacement (__ILA_I_, __ILA_SO_, __DOT__), array[idx]
// 2. no special name handling
void TypeAnalysisUtility::AnnotateType(const RfExpr& inout,
    const std::map<std::string,int> & quantified_var_type) 
{
  auto tp_annotate = inout->get_annotation<TypeAnnotation>();

  if (inout->is_var()) {
    auto ptr = std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(inout);
    const auto & n = ptr->get_name().first;
    if(tp_annotate == nullptr || tp_annotate->type.is_unknown()) {
      // if it is a quantified var, then we can annotate its type
      auto type_pos = quantified_var_type.find(n);
      if(type_pos != quantified_var_type.end()) {
        auto width = type_pos->second;
        RfVarTypeOrig tp;
        tp.type = RfMapVarType(width); // base, width,...
        tp_annotate = std::make_shared<TypeAnnotation>(tp);
        inout->set_annotation(tp_annotate);
      }
    }
    ILA_CHECK(tp_annotate != nullptr && !tp_annotate->type.is_unknown())
        << n << " has no type annotation";
  } else if (inout->is_constant()) {
    if (tp_annotate == nullptr || tp_annotate->type.is_unknown()) {
      RfVarTypeOrig tp;
      auto cptr =
          std::dynamic_pointer_cast<verilog_expr::VExprAstConstant>(inout);
      ILA_NOT_NULL(cptr);
      tp.type =
          RfMapVarType(std::get<1>(cptr->get_constant())); // base, width,...
      inout->set_annotation(std::make_shared<TypeAnnotation>(tp));
    }      // end if no annotation
  } else { // op
    bool has_quantifier = 
      inout->get_op() == verilog_expr::voperator::EXIST ||
      inout->get_op() == verilog_expr::voperator::FORALL;
    if(has_quantifier) {
      ILA_ASSERT(inout->get_child_cnt() == 1 && 
                 inout->get_str_parameter().size() == 1 &&
                 inout->get_parameter().size() == 1
                 );
      std::map<std::string,int> new_quantified_dict (quantified_var_type);
      new_quantified_dict.emplace(inout->get_str_parameter().at(0),
                                  inout->get_parameter().at(0));
      AnnotateType(inout->get_child().at(0), new_quantified_dict);
    } else
      for (size_t idx = 0; idx < inout->get_child_cnt(); ++idx)
        AnnotateType(inout->get_child().at(idx), quantified_var_type);
    infer_type_based_on_op_child(inout);
    // for each child
  } // end if-else- op
} // TypeAnalysisUtility::AnnotateType

void TypeAnalysisUtility::infer_type_based_on_op_child(const RfExpr& inout) {
  assert(inout->get_op() != verilog_expr::voperator::MK_CONST &&
         inout->get_op() != verilog_expr::voperator::MK_VAR);

  if (inout->get_child_cnt() == 1 &&
      (inout->get_op() == voperator::B_AND ||
       inout->get_op() == voperator::B_NAND ||
       inout->get_op() == voperator::B_OR ||
       inout->get_op() == voperator::B_NOR ||
       inout->get_op() == voperator::B_XOR ||
       inout->get_op() == voperator::B_EQU // "^~"|"~^"
       )) {
    auto new_annotation = std::make_shared<TypeAnnotation>();
    new_annotation->type = RfMapVarType(1);
    inout->set_annotation(new_annotation);
    return;
  }

  if (inout->get_op() == verilog_expr::voperator::STAR ||
      inout->get_op() == verilog_expr::voperator::PLUS ||
      inout->get_op() == verilog_expr::voperator::MINUS ||
      inout->get_op() == verilog_expr::voperator::DIV ||
      inout->get_op() == verilog_expr::voperator::POW ||
      inout->get_op() == verilog_expr::voperator::MOD ||
      inout->get_op() == verilog_expr::voperator::B_NEG ||
      inout->get_op() == verilog_expr::voperator::B_AND ||
      inout->get_op() == verilog_expr::voperator::B_OR ||
      inout->get_op() == verilog_expr::voperator::B_XOR ||
      inout->get_op() == verilog_expr::voperator::B_NAND ||
      inout->get_op() == verilog_expr::voperator::B_NOR) {
    // the max of the args
    unsigned nchild = inout->get_child_cnt();
    unsigned maxw = 0;
    for (size_t idx = 0; idx < nchild; idx++) {
      RfMapVarType t =
          inout->get_child().at(idx)->get_annotation<TypeAnnotation>()->type;
      if (t.is_bv())
        maxw = std::max(maxw, t.unified_width());
    }
    auto new_annotation = std::make_shared<TypeAnnotation>();
    new_annotation->type = RfMapVarType(maxw);
    inout->set_annotation(new_annotation);
    return;
  }

  if (inout->get_op() == verilog_expr::voperator::ASL ||
      inout->get_op() == verilog_expr::voperator::ASR ||
      inout->get_op() == verilog_expr::voperator::LSL ||
      inout->get_op() == verilog_expr::voperator::LSR ||
      inout->get_op() == verilog_expr::voperator::AT) { // the left type
    assert(inout->get_child_cnt() == 2);
    inout->set_annotation(
        inout->get_child().at(0)->get_annotation<TypeAnnotation>());
    return;
  } else if (inout->get_op() == verilog_expr::voperator::DELAY) {
    // arg 1: width of first
    // arg 2: width is 1 !!!
    assert(inout->get_child_cnt() == 1 || inout->get_child_cnt() == 2);
    if (inout->get_child_cnt() == 2) {
      auto new_annotation = std::make_shared<TypeAnnotation>();
      new_annotation->type = RfMapVarType(1);
      inout->set_annotation(new_annotation);
      return;
    }

    // set return type to be the same as the first one
    inout->set_annotation(
        inout->get_child().at(0)->get_annotation<TypeAnnotation>());
    return;

  } else if (inout->get_op() == verilog_expr::voperator::GTE ||
             inout->get_op() == verilog_expr::voperator::LTE ||
             inout->get_op() == verilog_expr::voperator::GT ||
             inout->get_op() == verilog_expr::voperator::LT ||
             inout->get_op() == verilog_expr::voperator::C_EQ ||
             inout->get_op() == verilog_expr::voperator::L_EQ ||
             inout->get_op() == verilog_expr::voperator::C_NEQ ||
             inout->get_op() == verilog_expr::voperator::L_NEQ ||
             inout->get_op() == verilog_expr::voperator::L_NEG ||
             inout->get_op() == verilog_expr::voperator::L_AND ||
             inout->get_op() == verilog_expr::voperator::L_OR) {
    auto new_annotation = std::make_shared<TypeAnnotation>();
    new_annotation->type = RfMapVarType(1);
    inout->set_annotation(new_annotation);
    return;
  } else if (inout->get_op() == verilog_expr::voperator::INDEX) {
    RfMapVarType child_type =
        inout->get_child().at(0)->get_annotation<TypeAnnotation>()->type;

    auto new_annotation = std::make_shared<TypeAnnotation>();
    if (child_type.is_array())
      new_annotation->type = RfMapVarType(child_type.unified_width());
    // TODO: check index within ?
    else
      new_annotation->type = RfMapVarType(1);
    inout->set_annotation(new_annotation);
    return;
  } else if (inout->get_op() == verilog_expr::voperator::IDX_PRT_SEL_PLUS ||
             inout->get_op() == verilog_expr::voperator::IDX_PRT_SEL_MINUS) {
    assert(inout->get_child().size() == 3);
    unsigned diff = 0;
    bool succ = _compute_const(inout->get_child().at(2), diff /*ref*/);
    ILA_ASSERT(succ);

    auto new_annotation = std::make_shared<TypeAnnotation>();
    new_annotation->type = RfMapVarType(diff);
    inout->set_annotation(new_annotation);

    // TODO: check index within ?
    return;

  } else if (inout->get_op() == verilog_expr::voperator::RANGE_INDEX) {
    assert(inout->get_child_cnt() == 3);
    unsigned l, r;

    bool succ = _compute_const(inout->get_child().at(1), l /*ref*/);
    succ = succ && _compute_const(inout->get_child().at(2), r /*ref*/);
    ILA_ASSERT(succ);

    auto new_annotation = std::make_shared<TypeAnnotation>();
    new_annotation->type = RfMapVarType(std::max(l, r) - std::min(l, r) + 1);
    inout->set_annotation(new_annotation);

    return;
  } else if (inout->get_op() == verilog_expr::voperator::STORE_OP) {
    inout->set_annotation(
        inout->get_child().at(0)->get_annotation<TypeAnnotation>());
    return;

  } else if (inout->get_op() == verilog_expr::voperator::TERNARY) {
    inout->set_annotation(
        inout->get_child().at(1)->get_annotation<TypeAnnotation>());
    return;
  } else if (inout->get_op() == verilog_expr::voperator::FUNCTION_APP) {
    ILA_ASSERT(false);
    auto new_annotation = std::make_shared<TypeAnnotation>();
    new_annotation->type = RfMapVarType(0);
    inout->set_annotation(new_annotation);
    return;
  } else if (inout->get_op() == verilog_expr::voperator::CONCAT) {
    unsigned nchild = inout->get_child_cnt();
    unsigned sumw = 0;
    for (size_t idx = 0; idx < nchild; idx++) {
      RfMapVarType t =
          (inout->get_child().at(idx)->get_annotation<TypeAnnotation>()->type);
      sumw += t.unified_width();
    }
    auto new_annotation = std::make_shared<TypeAnnotation>();
    new_annotation->type = RfMapVarType(sumw);
    inout->set_annotation(new_annotation);
    return;
  } else if (inout->get_op() == verilog_expr::voperator::REPEAT) {
    assert(inout->get_child_cnt() == 2);
    unsigned ntimes = 0;
    if (!_compute_const(inout->get_child().at(0), ntimes))
      ILA_ASSERT(false);
    auto tp =
        (inout->get_child().at(1)->get_annotation<TypeAnnotation>()->type);

    auto new_annotation = std::make_shared<TypeAnnotation>();
    new_annotation->type = RfMapVarType(tp.unified_width() * ntimes);
    inout->set_annotation(new_annotation);

    return;
  } else if (inout->get_op() == verilog_expr::voperator::FORALL ||
             inout->get_op() == verilog_expr::voperator::EXIST) {
    assert(inout->get_child_cnt() == 1);
    auto child_anno = inout->get_child().at(0)->get_annotation<TypeAnnotation>();
    ILA_ERROR_IF(child_anno == nullptr || 
       !child_anno->type.is_bv() || 
       child_anno->type.unified_width() != 1) << "type-check: FORALL/EXIST requires Boolean sub-formula";
    
    auto new_annotation = std::make_shared<TypeAnnotation>();
    new_annotation->type = RfMapVarType(1);
    inout->set_annotation(new_annotation);

    return;
  }
  ILA_ASSERT(false) << "BUG: Operator " << int(inout->get_op())
                    << " is not handled";

  auto new_annotation = std::make_shared<TypeAnnotation>();
  new_annotation->type = RfMapVarType(0);
  inout->set_annotation(new_annotation);
} // infer_type_op

VarReplacement::VarReplacement(const RfExpr& o, const RfExpr& n)
    : origvar(o), newvar(n) {
  auto annotation_ptr = newvar->get_annotation<TypeAnnotation>();
  ILA_NOT_NULL(annotation_ptr);
  ILA_CHECK(!annotation_ptr->type.is_unknown())
      << "new var is not typed: " << newvar->to_verilog();
}

} // namespace rfmap
} // namespace ilang
