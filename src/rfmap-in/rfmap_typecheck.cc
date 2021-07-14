/// \file rfmap_typecheck.cc Refinement map typecheck
///  Second pass : rfexpr typecheck

#include <ilang/rfmap-in/rfmap_typecheck.h>
#include <ilang/util/str_util.h>
#include <ilang/util/log.h>

#include <string>
#include <list>
#include <cassert>

namespace ilang {
namespace rfmap {

using namespace verilog_expr;

std::string TypedVerilogRefinementMap::new_id() {
  return "__auxvar"+std::to_string(counter++) + "__";
}

TypedVerilogRefinementMap::TypedVerilogRefinementMap(
  const VerilogRefinementMap & refinement,
  var_typecheck_t type_checker,
  const std::string & ila_inst_decode_signal_name,
  const std::string & ila_valid_signal_name
 ) : VerilogRefinementMap(refinement), counter(0), TypeAnalysisUtility(type_checker) {
  initialize(ila_inst_decode_signal_name,ila_valid_signal_name);
}

TypedVerilogRefinementMap::TypedVerilogRefinementMap(
  const std::string & varmap_json_file,
  const std::string & instcond_json_file,
  var_typecheck_t type_checker,
  const std::string & ila_inst_decode_signal_name,
  const std::string & ila_valid_signal_name
  ) : VerilogRefinementMap(varmap_json_file, instcond_json_file),
    counter(0), TypeAnalysisUtility(type_checker) {
  initialize(ila_inst_decode_signal_name,ila_valid_signal_name);
} // TypedVerilogRefinementMap::TypedVerilogRefinementMap
 
void TypedVerilogRefinementMap::initialize(
  const std::string & ila_inst_decode_signal_name,
  const std::string & ila_valid_signal_name) {
  // collect those with unknown types
  // a. delay
  // b. value holder
  CollectInlineDelayValueHolder();

  // collect those new vars with user-defined types
  CollectInternallyDefinedVars(
    ila_inst_decode_signal_name,
    ila_valid_signal_name
  );

  // determine the types of delay and value holder
  ComputeDelayValueHolderWidth();

} // initialize


// this function will iteratively make a new copy of the whole AST.
RfExpr TypedVerilogRefinementMap::ReplacingRtlIlaVar(
  const RfExpr & in,
  bool replace_internal_wire) 
{
  // skip state memory mapped 
  // provide a function to ReplExpr...
  auto tp_annotate = in->get_annotation<TypeAnnotation>();

  if(in->is_var()) {
    auto var_ptr = std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(in);
    ILA_NOT_NULL(var_ptr);
    auto n = var_ptr->get_name();

    if(var_replacement.find(n.first) != var_replacement.end()) {
      return var_replacement.at(n.first).newvar;
    }

    RfVarTypeOrig tp;

    if(tp_annotate != nullptr)
      tp = *tp_annotate;
    if(tp.type.is_unknown()) {
      auto pos_def_var = all_var_def_types.find(n.first);
      auto rtl_ila_tp = typechecker(n.first);

      if(n.second) { // if it is special name
        if(pos_def_var != all_var_def_types.end()) {
          tp.var_ref_type = RfVarTypeOrig::VARTYPE::DEFINE_VAR;
          tp.type = RfMapVarType(pos_def_var->second.width);
        } else {
          tp = rtl_ila_tp;
        }
      } else { // if it is not special name
        if(!rtl_ila_tp.type.is_unknown())
          tp = rtl_ila_tp;
        else if(pos_def_var != all_var_def_types.end()) {
          tp.var_ref_type = RfVarTypeOrig::VARTYPE::DEFINE_VAR;
          tp.type = RfMapVarType(pos_def_var->second.width);
        }
      }
      // put back the annotation? in new expr?
    } // end if it is unknown
    ILA_WARN_IF(tp.type.is_unknown()) << "type of var: " << (n.second?"#":"") << n.first << " is still unknown.";

    
    if(tp.var_ref_type == RfVarTypeOrig::VARTYPE::RTLV) {

      bool is_array = tp.type.is_array();
      if(!replace_internal_wire || is_array) {
        auto ret_copy = std::make_shared<verilog_expr::VExprAstVar>(*var_ptr);
        ret_copy->set_annotation(std::make_shared<TypeAnnotation>(tp));
        return ret_copy;
        // 1 will not do replacement
        // 2 will not record that
      }

      auto new_name = ReplaceAll(n.first, ".", "__DOT__");
      auto new_node = verilog_expr::VExprAst::MakeSpecialName(new_name);
      new_node->set_annotation(std::make_shared<TypeAnnotation>(tp));
      var_replacement.emplace(n.first, VarReplacement(in, new_node));
      return new_node;
    } else if (tp.var_ref_type == RfVarTypeOrig::VARTYPE::ILAI) {
      auto new_name = "__ILA_I_" + n.first;
      auto new_node = verilog_expr::VExprAst::MakeSpecialName(new_name);
      new_node->set_annotation(std::make_shared<TypeAnnotation>(tp));
      var_replacement.emplace(n.first, VarReplacement(in, new_node));
      return new_node;      
    } else if (tp.var_ref_type == RfVarTypeOrig::VARTYPE::ILAS) {
      auto new_name = "__ILA_SO_" + n.first;
      auto new_node = verilog_expr::VExprAst::MakeSpecialName(new_name);
      new_node->set_annotation(std::make_shared<TypeAnnotation>(tp));
      var_replacement.emplace(n.first, VarReplacement(in, new_node));
      return new_node;
    }
    
    auto ret_copy = std::make_shared<verilog_expr::VExprAstVar>(*var_ptr);
    ret_copy->set_annotation(std::make_shared<TypeAnnotation>(tp));
    return ret_copy; // will return the annotated one anyway
  } // is_var
  else if (in->is_constant()) {
    auto cptr = std::dynamic_pointer_cast<verilog_expr::VExprAstConstant>(in);
    ILA_NOT_NULL(cptr);
    auto ret_copy = std::make_shared<verilog_expr::VExprAstConstant>(*cptr);
    if(tp_annotate == nullptr || tp_annotate->type.is_unknown()) {
      RfVarTypeOrig tp;
      tp.type = RfMapVarType(std::get<1>(cptr->get_constant())); // base, width,...
      ret_copy->set_annotation(std::make_shared<TypeAnnotation>(tp));
    }
    return ret_copy; // no annotation needed
  } else {
    // check type 
    auto ret_copy = std::make_shared<verilog_expr::VExprAst>(*in);
    for (size_t idx = 0 ; idx < ret_copy->get_child_cnt(); ++ idx) {
      ret_copy->child(idx) = 
        ReplacingRtlIlaVar(
          ret_copy->get_child().at(idx), replace_internal_wire);
    } // for each child

    if(!replace_internal_wire &&
       ret_copy->child(0)->is_var() && 
       ret_copy->get_op() == verilog_expr::voperator::INDEX) {

      std::shared_ptr<TypeAnnotation> annotate = 
        ret_copy->child(0)->get_annotation<TypeAnnotation>();

      if(annotate != nullptr && annotate->type.is_array()) {
        assert(ret_copy->get_child_cnt() == 2);
        auto array_index = ret_copy->child(1);
        auto n = std::dynamic_pointer_cast<verilog_expr::VExprAstVar>
          ( ret_copy->child(0) )->get_name();
        
        if( array_index->is_constant() ) {
          std::string range_o = array_index->to_verilog();

          auto new_name = ReplaceAll(n.first, ".", "__DOT__") + "_"+ ReplaceAll(range_o,"'","") +"_";
          auto orig_name = n.first+"["+range_o+"]";
          
          if(var_replacement.find(orig_name) != var_replacement.end())
            return var_replacement.at(orig_name).newvar;

          auto new_node = verilog_expr::VExprAst::MakeSpecialName(new_name);
          auto new_annotation = std::make_shared<TypeAnnotation>();
          new_annotation->type = RfMapVarType(annotate->type.unified_width());
          new_node->set_annotation(new_annotation);

          var_replacement.emplace(orig_name, VarReplacement(in, new_node, range_o));
          return new_node; 
        } else {
          ILA_CHECK(false) << "FIXME: currently does not handle dynamic index into array";
          // HZ note: in the future we can do this
          // by allowing array shadowing, this will definitely need smt-lib2 expression
          // or Jasper's capability, because we can never connect a whole Verilog array out
          // using Yosys's SVA.

        } // end if it is const
      } 
    } // special handling for array[idx]
    // to determine the type of ret_copy
    infer_type_based_on_op_child(ret_copy);
    return ret_copy; // may use new_node instead in the special case
  } // end of is_op
  assert(false); // Should not be reachable  
} // AnnotateSignalsAndCollectRtlVars


void TypedVerilogRefinementMap::collect_inline_value_recorder_func(RfExpr & inout) {
  if(inout->get_op() == verilog_expr::voperator::AT) {
    auto recorder_name = new_id()+"recorder";
    auto new_node = verilog_expr::VExprAst::MakeVar(recorder_name);

    verilog_expr::VExprAst::VExprAstPtrVec child(inout->get_child());
    ValueRecorder tmp_value_recorder;
    tmp_value_recorder.width = 0;
    tmp_value_recorder.value = child.at(0);
    // TODO: deal with value@CLK.n
    if (child.at(1)->is_constant()) {
      // deal with value@0
      auto new_cond = verilog_expr::VExprAst::MakeBinaryAst(verilog_expr::voperator::L_EQ,
          verilog_expr::VExprAst::MakeVar("__CYCLE_CNT__"),
          child.at(1)
        );
      tmp_value_recorder.condition = new_cond;
    } else
      tmp_value_recorder.condition = child.at(1);
    value_recorder.emplace(recorder_name, tmp_value_recorder);    
    inout = new_node; // rewrite the node
  }
} // collect_inline_value_recorder_func

void TypedVerilogRefinementMap::collect_inline_delay_func(RfExpr & inout) {
  if(inout->get_op() == voperator::DELAY) {
    assert(inout->get_parameter().size() == inout->get_str_parameter().size());
    assert(inout->get_child().size() == 1 || inout->get_child().size() == 2);
    assert(inout->get_parameter().size() == 1 || inout->get_parameter().size() == 2);

    auto delay_name = new_id()+"delay";
    auto new_node = VExprAst::MakeVar(delay_name);

    if( inout->get_parameter().size() == 1 ) {
      int delay = inout->get_parameter().at(0);
      aux_delays.emplace(delay_name, SignalDelay(inout->get_child().at(0), delay) );
    } else { // inout->get_parameter().size() == 2
      int delay = inout->get_parameter().at(0);
      int delay_upper = inout->get_parameter().at(1);
      aux_delays.emplace(delay_name, SignalDelay(inout->get_child().at(0), delay, delay_upper) );
    }

    if(inout->get_child().size() == 1) {
      inout = new_node;
    } else {
      assert(inout->get_child().size() == 2);
      auto tmp_node = VExprAst::MakeBinaryAst(voperator::L_AND,
        new_node, inout->get_child().at(1)  );
      inout = tmp_node;
    }
  }
} // collect_inline_delay_func

void TypedVerilogRefinementMap::CollectInlineDelayValueHolder() {
  TraverseAllRfExpr([this](RfExpr & inout) -> void { this->collect_inline_delay_func(inout);} );
  TraverseAllRfExpr([this](RfExpr & inout) -> void { this->collect_inline_value_recorder_func(inout);} );
}


void TypedVerilogRefinementMap::CollectInternallyDefinedVars(
  const std::string & ila_inst_decode_signal_name,
  const std::string & ila_valid_signal_name
) {
  for (const auto & n_st : phase_tracker) {
    for (const auto & var_def : n_st.second.event_alias ) {
      VarDef tmp;
      tmp.type = VarDef::var_type::WIRE;
      tmp.width = 1;
      all_var_def_types.emplace(var_def.first, tmp);
    }
    for (const auto & var_def : n_st.second.var_defs ) {
      all_var_def_types.emplace(var_def.first, var_def.second);
    }
  }
  for (const auto & n_st : value_recorder) {
    VarDef tmp;
    if(n_st.second.width != 0) {
      tmp.width = n_st.second.width;
      tmp.type = VarDef::var_type::REG;
      all_var_def_types.emplace(n_st.first, tmp);
    }      
  } // value recorder

  for (const auto & n_st : customized_monitor) {      
    for (const auto & var_def : n_st.second.var_defs ) {
      all_var_def_types.emplace(var_def.first, var_def.second);
    }
  }

  // add internal signals
  { // add decode,commit, $decode, $valid
    VarDef tmp;
    tmp.width = 1;
    tmp.type = VarDef::var_type::WIRE;
    auto onebit_anno = std::make_shared<TypeAnnotation>();
    onebit_anno->type = RfMapVarType(1);
    onebit_anno->var_ref_type = RfVarTypeOrig::VARTYPE::INTERNAL;

    all_var_def_types.emplace("decode", tmp); // these are the stage info
    all_var_def_types.emplace("commit", tmp);

    // decode and commit stage replacement
    var_replacement.emplace("decode", 
      VarReplacement(
        verilog_expr::VExprAst::MakeSpecialName("decode"),
        verilog_expr::VExprAst::MakeSpecialName("__START__")
        ));

    var_replacement.emplace("commit", 
      VarReplacement(
        verilog_expr::VExprAst::MakeSpecialName("commit"),
        verilog_expr::VExprAst::MakeSpecialName("__IEND__")
        ));
    
    var_replacement.at("decode").newvar->set_annotation(onebit_anno);
    var_replacement.at("commit").newvar->set_annotation(onebit_anno);
    
    all_var_def_types.emplace("$decode", tmp); // these are the ila.decode/ila.valid info
    all_var_def_types.emplace("$valid", tmp);


    // decode and commit stage replacement
    var_replacement.emplace("$decode", 
      VarReplacement(
        verilog_expr::VExprAst::MakeSpecialName("$decode"),
        verilog_expr::VExprAst::MakeSpecialName(ila_inst_decode_signal_name)
        ));
    var_replacement.emplace("$valid", 
      VarReplacement(
        verilog_expr::VExprAst::MakeSpecialName("commit"),
        verilog_expr::VExprAst::MakeSpecialName(ila_valid_signal_name)
        ));

    var_replacement.at("$decode").newvar->set_annotation(onebit_anno);
    var_replacement.at("$valid").newvar->set_annotation(onebit_anno);

  } // end of add decode,commit, $decode, $valid
  
    
} // CollectInternallyDefinedVars

void TypedVerilogRefinementMap::TraverseCondMap(SingleVarMap & inout, std::function<void(RfExpr & inout)> func) {
  if(inout.single_map)
    TraverseRfExpr(inout.single_map, func);
  else
    for (auto & c : inout.cond_map) {
      TraverseRfExpr(c.first, func);
      TraverseRfExpr(c.second, func);
    }
} // TraverseCondMap

void TypedVerilogRefinementMap::TraverseAllRfExpr(std::function<void(RfExpr & inout)> func) {
  for(auto & sv : ila_state_var_map) {
    if(sv.second.type == IlaVarMapping::StateVarMapType::SINGLE)
      TraverseRfExpr(sv.second.single_map.single_map,func);
    else if(sv.second.type == IlaVarMapping::StateVarMapType::CONDITIONAL) {
      for (auto & c : sv.second.single_map.cond_map) {
        TraverseRfExpr(c.first, func);
        TraverseRfExpr(c.second, func);
      }
    } else { // extern map
      for (auto & m : sv.second.externmem_map) {
        TraverseCondMap(m.raddr_map, func);
        TraverseCondMap(m.rdata_map, func);
        TraverseCondMap(m.ren_map, func);
        TraverseCondMap(m.waddr_map, func);
        TraverseCondMap(m.wdata_map, func);
        TraverseCondMap(m.wen_map, func);
      }
    }
  } // sv map

  for(auto & sv : ila_input_var_map) {
    if(sv.second.type == IlaVarMapping::StateVarMapType::SINGLE)
      TraverseRfExpr(sv.second.single_map.single_map,func);
    else /* if(sv.second.type == IlaVarMapping::StateVarMapType::CONDITIONAL) */ {
      for (auto & c : sv.second.single_map.cond_map) {
        TraverseRfExpr(c.first, func);
        TraverseRfExpr(c.second, func);
      }
    }
  } // input var

  for(auto & ufa : uf_application) {
    for (auto & fapp : ufa.second.func_applications) {
      TraverseRfExpr(fapp.result_map, func);
      for( auto & a : fapp.arg_map)
        TraverseRfExpr(a, func);
    }
  } // uf application
  for( auto & a : assumptions)
    TraverseRfExpr(a, func);
  for( auto & a : additional_mapping)
    TraverseRfExpr(a, func);
  
  for(auto & ptracker : phase_tracker) {
    for(auto & a : ptracker.second.event_alias)
      TraverseRfExpr(a.second, func);
    for(auto & r : ptracker.second.rules) {
      TraverseRfExpr(r.enter_rule, func);
      TraverseRfExpr(r.exit_rule, func);
      for(auto & act : r.enter_action)
        TraverseRfExpr(act.RHS, func);
      for(auto & act : r.exit_action)
        TraverseRfExpr(act.RHS, func);
    }
  } // phase tracker
  for (auto & pv : value_recorder) {
    TraverseRfExpr(pv.second.condition, func);
    TraverseRfExpr(pv.second.value, func);
  }
  // ALERT: do not handle customized recorder

  for (auto & instcond : inst_complete_cond) {
    if ( instcond.second.type == InstructionCompleteCondition::ConditionType::SIGNAL )
      TraverseRfExpr(instcond.second.ready_signal, func);
    for( auto & cond : instcond.second.start_condition)
      TraverseRfExpr(cond, func);
  }

  for (auto & a : global_invariants)
    TraverseRfExpr(a, func);
  
} // TraverseAllRfExpr

void TypedVerilogRefinementMap::TraverseRfExpr(RfExpr & inout, std::function<void(RfExpr & inout)> func) {
  // DFS -- Note: we need to call func on the parent's child
  // and make sure it runs the first
  std::vector<std::pair<RfExpr, unsigned>> parent_stack;
  parent_stack.push_back(std::make_pair(inout,0U));
  while(!parent_stack.empty()) {
    auto & lastlv = parent_stack.back();
    auto cnt = lastlv.first->get_child_cnt();
    auto & idx = lastlv.second;
    if(idx >= cnt) {
      parent_stack.pop_back();
      if(!parent_stack.empty()) {
        func( parent_stack.back().first->child( parent_stack.back().second ) );
        ++ parent_stack.back().second;
      }
      continue;
    } else {
      // enter c[idx]
      if(lastlv.first->get_child_cnt() == 0) {
        func ( lastlv.first->child(idx) );
        ++idx;
      } else {
        parent_stack.push_back( std::make_pair(lastlv.first->child(idx), 0U ));
      }
    }
  } // end of while
  func(inout);
} // TraverseRfExpr

// ------------------------------------------------------------------------------


// helper for type inference
bool _compute_const(const RfExpr & in, unsigned & out) {
  if(!in->is_constant())
    return false;
  std::shared_ptr<VExprAstConstant> cst_ast_ptr = std::dynamic_pointer_cast<VExprAstConstant>(in);
  if(cst_ast_ptr == nullptr)
    return false;
  auto bws = cst_ast_ptr->get_constant();
  auto base = std::get<0>(bws);
  auto width = std::get<1>(bws);
  out = StrToLong(std::get<2>(bws), base);
  return true;  
}



void TypedVerilogRefinementMap::ComputeDelayValueHolderWidth() {
  for(auto & name_delay_pair: aux_delays) {
    if(name_delay_pair.second.width == 0) {
      auto tp = TypeInferTravserRfExpr(name_delay_pair.second.signal);
      ILA_ERROR_IF(tp.is_array()) << "Currently does not support to delay a memory variable";
      ILA_ERROR_IF(tp.is_unknown()) << "Type inference failed on: " << name_delay_pair.second.signal->to_verilog();
      name_delay_pair.second.width = tp.unified_width();

      // replendish all_var_def_types
      VarDef internal_var_def;
      internal_var_def.width = tp.unified_width(); 
      internal_var_def.type = VarDef::var_type::REG;

      all_var_def_types.emplace(name_delay_pair.first, internal_var_def);
    }
  }
  for (auto & name_vr : value_recorder) {
    if (name_vr.second.width == 0) {
      auto tp = TypeInferTravserRfExpr(name_vr.second.value);
      ILA_ERROR_IF(tp.is_array()) << "Currently does not support to delay a memory variable";
      ILA_ERROR_IF(tp.is_unknown()) << "Type inference failed on: " << name_vr.second.value->to_verilog();
      name_vr.second.width = tp.unified_width();

      // replendish all_var_def_types
      VarDef internal_var_def;
      internal_var_def.width = tp.unified_width(); 
      internal_var_def.type = VarDef::var_type::REG;

      all_var_def_types.emplace(name_vr.first, internal_var_def);
    }
  }  // replendish internal defined vars
} // ComputeDelayValueHolderWidth


RfMapVarType TypedVerilogRefinementMap::TypeInferTravserRfExpr(const RfExpr & in) {

  if(in->is_constant()) {
    auto c = std::dynamic_pointer_cast<verilog_expr::VExprAstConstant>(in)->get_constant();
    return RfMapVarType(std::get<1>(c));
  } else if (in->is_var()) {
    auto n = std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(in)->get_name();

    auto pos_def_var = all_var_def_types.find(n.first);

    if(n.second) { // is a special name
      // check special name first
      if (pos_def_var != all_var_def_types.end())
       return RfMapVarType(pos_def_var->second.width);

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
      if (pos_def_var != all_var_def_types.end())
       return RfMapVarType(pos_def_var->second.width);
      
    } // if # ... # else not
    return RfMapVarType();  // unknown type  
  } else { // has op
    if(in->get_op() == verilog_expr::voperator::STAR ||
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
       in->get_op() == verilog_expr::voperator::B_NOR
      ) {
        // the max of the args
        unsigned nchild = in->get_child_cnt();
        unsigned maxw = 0;
        for(size_t idx = 0; idx < nchild; idx ++) {
          RfMapVarType t = TypeInferTravserRfExpr( in->child(idx) );
          if(t.is_bv())
            maxw = std::max(maxw, t.unified_width());
        }
        return RfMapVarType(maxw);
    } else if (
       in->get_op() == verilog_expr::voperator::ASL ||
       in->get_op() == verilog_expr::voperator::ASR ||
       in->get_op() == verilog_expr::voperator::LSL ||
       in->get_op() == verilog_expr::voperator::LSR ||
       in->get_op() == verilog_expr::voperator::AT
       ) { // the left type
       assert( in->get_child_cnt() == 2);
       return TypeInferTravserRfExpr(in->child(0));
    } else if ( in->get_op() == verilog_expr::voperator::DELAY) {
      // arg 1: width of first
      // arg 2: width is 1 !!!
      assert(in->get_child_cnt() == 1 ||  in->get_child_cnt() == 2);
      if (in->get_child_cnt() == 2)
        return RfMapVarType(1);
      
      // set return type to be the same as the first one
      return TypeInferTravserRfExpr(in->child(0));
    } else if (
      in->get_op() == verilog_expr::voperator::GTE ||
      in->get_op() == verilog_expr::voperator::LTE ||
      in->get_op() == verilog_expr::voperator::GT ||
      in->get_op() == verilog_expr::voperator::LT ||
      in->get_op() == verilog_expr::voperator::C_EQ ||
      in->get_op() == verilog_expr::voperator::L_EQ ||
      in->get_op() == verilog_expr::voperator::C_NEQ ||
      in->get_op() == verilog_expr::voperator::L_NEQ ||
      in->get_op() == verilog_expr::voperator::L_NEG ||
      in->get_op() == verilog_expr::voperator::L_AND ||
      in->get_op() == verilog_expr::voperator::L_OR
      ) {
      return RfMapVarType(1);
    } else if (in->get_op() == verilog_expr::voperator::INDEX) {
      RfMapVarType child_type = TypeInferTravserRfExpr(in->child(0));
      if (child_type.is_array())
        return RfMapVarType(child_type.unified_width()); // data width
      // TODO: check index within ?
      if (child_type.is_bv())
        return RfMapVarType(1);
      return RfMapVarType(); // UNKNOWN type
    } else if (
      in->get_op() == verilog_expr::voperator::IDX_PRT_SEL_PLUS ||
      in->get_op() == verilog_expr::voperator::IDX_PRT_SEL_MINUS) {
      assert(in->get_child().size() == 3);
      unsigned diff;
      bool succ = _compute_const(in->child(2), diff /*ref*/);
      // TODO: check index within ?
      if (succ)
        return RfMapVarType(diff);
      return RfMapVarType();
    } else if (in->get_op() == verilog_expr::voperator::RANGE_INDEX) {
      assert(in->get_child_cnt() == 3);
      unsigned l,r;
      
      bool succ = _compute_const(in->child(1), l /*ref*/),
      succ = succ && _compute_const(in->child(2), r /*ref*/);
      if(!succ)
        return RfMapVarType();
      // TODO: check width!
      return RfMapVarType(std::max(l,r)-std::min(l,r) + 1);
    } else if (in->get_op() == verilog_expr::voperator::STORE_OP) {
      // TODO: check width!
      // actually not implemented
      return TypeInferTravserRfExpr(in->child(0));
    } else if (in->get_op() == verilog_expr::voperator::TERNARY) {
      auto left =  TypeInferTravserRfExpr(in->child(1));
      auto right =  TypeInferTravserRfExpr(in->child(2));
      if(left.is_array() || right.is_array())
        return left; // TODO: check compatibility
      return RfMapVarType(std::max(left.unified_width(), right.unified_width()));
    } else if (in->get_op() == verilog_expr::voperator::FUNCTION_APP) {
      return RfMapVarType();
    } else if(in->get_op() == verilog_expr::voperator::CONCAT) {
      unsigned nchild = in->get_child_cnt();
      unsigned sumw = 0;
      for(size_t idx = 0; idx < nchild; idx ++) {
        RfMapVarType t = TypeInferTravserRfExpr( in->child(idx) );
        if(t.is_bv())
          sumw += t.unified_width();
        else
          return RfMapVarType(); // cannot decide
      }
      return RfMapVarType(sumw);
    } else if (in->get_op() == verilog_expr::voperator::REPEAT) {
      assert( in->get_child_cnt() == 2 );
      unsigned ntimes;
      if(!_compute_const(in->child(0), ntimes))
        return RfMapVarType();
      auto tp = TypeInferTravserRfExpr(in->child(1));
      return RfMapVarType(tp.unified_width()*ntimes);      
    }
    ILA_ASSERT(false) << "BUG: Operator " << int(in->get_op()) << " is not handled";
  } // end of else has op
  return RfMapVarType();
} // TypeInferTravserRfExpr


// --------------------------------------------------------
//  RfExprAstUtility
// --------------------------------------------------------


RfVarTypeOrig RfExprAstUtility::GetType(const RfExpr & in) {
  auto anno = in->get_annotation<TypeAnnotation>();
  ILA_NOT_NULL(anno);
  return *anno;
}

void RfExprAstUtility::GetVars(const RfExpr & in, 
  std::unordered_map<std::string, RfVar> & vars_out)
{
  // bfs walk
  std::vector<std::pair<RfExpr, bool> > stack;
  stack.push_back(std::make_pair(in, false));
  while(!stack.empty()) {
    auto & back = stack.back();
    if(back.second) {
      stack.pop_back();
      continue;
    }
    // back.second == false
    back.second = true;
    for(const auto & c : back.first->get_child())
      stack.push_back(std::make_pair(c, false));
    if(back.first->is_var()) {
      ILA_ASSERT(back.first->get_child().size() == 0);
      verilog_expr::VExprAstVar::VExprAstVarPtr varptr = 
        std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(back.first);
      ILA_NOT_NULL(varptr);
      vars_out.emplace(varptr->get_name().first, varptr);
    }
  } // end while (stack is not empty)
} // end of GetVars

bool RfExprAstUtility::IsLastLevelBooleanOp(const RfExpr & in) {
  std::set<verilog_expr::voperator> boolean_op = {
    verilog_expr::voperator::GTE,
    verilog_expr::voperator::LTE,
    verilog_expr::voperator::GT,
    verilog_expr::voperator::LT,
    verilog_expr::voperator::C_EQ,
    verilog_expr::voperator::L_EQ,
    verilog_expr::voperator::C_NEQ,
    verilog_expr::voperator::L_NEQ,
    verilog_expr::voperator::L_NEG,
    verilog_expr::voperator::L_AND,
    verilog_expr::voperator::L_OR
  };

  if(in->is_constant() || in->is_var())
    return false;
  auto op = in->get_op();
  return (boolean_op.find(op) == boolean_op.end());
}


// --------------------------------------------------------
//  TypeAnalysisUtility
// --------------------------------------------------------

// type inference rules
// differences from TypedVerilogRefinementMap::ReplacingRtlIlaVar
// 1. no var replacement (__ILA_I_, __ILA_SO_, __DOT__), array[idx]
// 2. no special name handling
void TypeAnalysisUtility::AnnotateType(const RfExpr & inout)  {
  auto tp_annotate = inout->get_annotation<TypeAnnotation>();

  if(inout->is_var()) {
    auto var_ptr = std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(inout);
    ILA_NOT_NULL(var_ptr);
    auto n = var_ptr->get_name();

    if(tp_annotate == nullptr || tp_annotate->type.is_unknown()) {
      auto rtl_ila_tp = typechecker(n.first);
      inout->set_annotation(std::make_shared<TypeAnnotation>(rtl_ila_tp));
    }    
  } else if (inout->is_constant()) {
    if(tp_annotate == nullptr || tp_annotate->type.is_unknown()) {
      RfVarTypeOrig tp;
      auto cptr = std::dynamic_pointer_cast<verilog_expr::VExprAstConstant>(inout);
      ILA_NOT_NULL(cptr);
      tp.type = RfMapVarType(std::get<1>(cptr->get_constant())); // base, width,...
      inout->set_annotation(std::make_shared<TypeAnnotation>(tp));
    } // end if no annotation
  } else { // op
    for (size_t idx = 0 ; idx < inout->get_child_cnt(); ++ idx)
      AnnotateType(inout->child(idx));
    infer_type_based_on_op_child(inout);
    // for each child
  } // end if-else- op
} // TypeAnalysisUtility::AnnotateType

void TypeAnalysisUtility::infer_type_based_on_op_child(const RfExpr & inout) {
  assert(
    inout->get_op() != verilog_expr::voperator::MK_CONST &&
    inout->get_op() != verilog_expr::voperator::MK_VAR  );

  if(inout->get_op() == verilog_expr::voperator::STAR ||
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
     inout->get_op() == verilog_expr::voperator::B_NOR
    ) {
    // the max of the args
    unsigned nchild = inout->get_child_cnt();
    unsigned maxw = 0;
    for(size_t idx = 0; idx < nchild; idx ++) {
      RfMapVarType t = inout->child(idx)->get_annotation<TypeAnnotation>()->type;
      if(t.is_bv())
        maxw = std::max(maxw, t.unified_width());
    }
    auto new_annotation = std::make_shared<TypeAnnotation>();
    new_annotation->type = RfMapVarType(maxw);
    inout->set_annotation(new_annotation);
    return;
  }

  if (
    inout->get_op() == verilog_expr::voperator::ASL ||
    inout->get_op() == verilog_expr::voperator::ASR ||
    inout->get_op() == verilog_expr::voperator::LSL ||
    inout->get_op() == verilog_expr::voperator::LSR ||
    inout->get_op() == verilog_expr::voperator::AT
    ) { // the left type
    assert( inout->get_child_cnt() == 2);
    inout->set_annotation(inout->child(0)->get_annotation<TypeAnnotation>());
    return;
  } else if ( inout->get_op() == verilog_expr::voperator::DELAY) {
      // arg 1: width of first
      // arg 2: width is 1 !!!
      assert(inout->get_child_cnt() == 1 ||  inout->get_child_cnt() == 2);
      if (inout->get_child_cnt() == 2) {
        auto new_annotation = std::make_shared<TypeAnnotation>();
        new_annotation->type = RfMapVarType(1);
        inout->set_annotation(new_annotation);
        return ;
      }
      
      // set return type to be the same as the first one
      inout->set_annotation(inout->child(0)->get_annotation<TypeAnnotation>());
      return;

    } else if (
      inout->get_op() == verilog_expr::voperator::GTE ||
      inout->get_op() == verilog_expr::voperator::LTE ||
      inout->get_op() == verilog_expr::voperator::GT ||
      inout->get_op() == verilog_expr::voperator::LT ||
      inout->get_op() == verilog_expr::voperator::C_EQ ||
      inout->get_op() == verilog_expr::voperator::L_EQ ||
      inout->get_op() == verilog_expr::voperator::C_NEQ ||
      inout->get_op() == verilog_expr::voperator::L_NEQ ||
      inout->get_op() == verilog_expr::voperator::L_NEG ||
      inout->get_op() == verilog_expr::voperator::L_AND ||
      inout->get_op() == verilog_expr::voperator::L_OR
      ) {
      auto new_annotation = std::make_shared<TypeAnnotation>();
      new_annotation->type = RfMapVarType(1);
      inout->set_annotation(new_annotation);
      return ;
    } else if (inout->get_op() == verilog_expr::voperator::INDEX) {
      RfMapVarType child_type = inout->child(0)->get_annotation<TypeAnnotation>()->type;

      auto new_annotation = std::make_shared<TypeAnnotation>();
      if (child_type.is_array())
        new_annotation->type = RfMapVarType(child_type.unified_width());
      // TODO: check index within ?
      else
        new_annotation->type = RfMapVarType(1);
      inout->set_annotation(new_annotation);
      return;
    } else if (
      inout->get_op() == verilog_expr::voperator::IDX_PRT_SEL_PLUS ||
      inout->get_op() == verilog_expr::voperator::IDX_PRT_SEL_MINUS) {
      assert(inout->get_child().size() == 3);
      unsigned diff = 0;
      bool succ = _compute_const(inout->child(2), diff /*ref*/);
      ILA_ASSERT(succ);

      auto new_annotation = std::make_shared<TypeAnnotation>();
      new_annotation->type = RfMapVarType(diff);
      inout->set_annotation(new_annotation);

      // TODO: check index within ?
      return;
      
    } else if (inout->get_op() == verilog_expr::voperator::RANGE_INDEX) {
      assert(inout->get_child_cnt() == 3);
      unsigned l,r;
      
      bool succ = _compute_const(inout->child(1), l /*ref*/),
      succ = succ && _compute_const(inout->child(2), r /*ref*/);
      ILA_ASSERT(succ);

      auto new_annotation = std::make_shared<TypeAnnotation>();
      new_annotation->type = RfMapVarType(std::max(l,r)-std::min(l,r) + 1);
      inout->set_annotation(new_annotation);
      
      return ;
    } else if (inout->get_op() == verilog_expr::voperator::STORE_OP) {
      inout->set_annotation(inout->child(0)->get_annotation<TypeAnnotation>());
      return;

    } else if (inout->get_op() == verilog_expr::voperator::TERNARY) {
      inout->set_annotation(inout->child(1)->get_annotation<TypeAnnotation>());
      return;
    } else if (inout->get_op() == verilog_expr::voperator::FUNCTION_APP) {
      ILA_ASSERT(false);
      auto new_annotation = std::make_shared<TypeAnnotation>();
      new_annotation->type = RfMapVarType(0);
      inout->set_annotation(new_annotation);
      return;
    } else if(inout->get_op() == verilog_expr::voperator::CONCAT) {
      unsigned nchild = inout->get_child_cnt();
      unsigned sumw = 0;
      for(size_t idx = 0; idx < nchild; idx ++) {
        RfMapVarType t = ( inout->child(idx)->get_annotation<TypeAnnotation>()->type );
        sumw += t.unified_width();
      }
      auto new_annotation = std::make_shared<TypeAnnotation>();
      new_annotation->type = RfMapVarType(sumw);
      inout->set_annotation(new_annotation);
      return;
    } else if (inout->get_op() == verilog_expr::voperator::REPEAT) {
      assert( inout->get_child_cnt() == 2 );
      unsigned ntimes;
      if(!_compute_const(inout->child(0), ntimes))
        ILA_ASSERT(false);
      auto tp = ( inout->child(1)->get_annotation<TypeAnnotation>()->type );

      auto new_annotation = std::make_shared<TypeAnnotation>();
      new_annotation->type = RfMapVarType(tp.unified_width()*ntimes);
      inout->set_annotation(new_annotation);

      return ;      
    }
    ILA_ASSERT(false) << "BUG: Operator " << int(inout->get_op()) << " is not handled";

    auto new_annotation = std::make_shared<TypeAnnotation>();
    new_annotation->type = RfMapVarType(0);
    inout->set_annotation(new_annotation);
} // infer_type_op


} // namespace rfmap
} // namespace ilang

