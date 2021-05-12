/// \file rfmap_typecheck.cc Refinement map typecheck
///  Second pass : rfexpr typecheck

#include <ilang/rfmap-in/rfmap_typecheck.h>

#include <string>

namespace ilang {
namespace rfmap {

using namespace verilog_expr;

std::string TypedVerilogRefinementMap::new_id() {
  return "__auxvar"+std::to_string(counter++) + "__";
}


TypedVerilogRefinementMap::TypedVerilogRefinementMap(
  const std::string & varmap_json_file,
  const std::string & instcond_json_file,
  var_typecheck_t ila_var_type_check,
  var_typecheck_t rtl_var_type_check
  ) : VerilogRefinementMap(varmap_json_file, instcond_json_file),
    counter(0) {
  
  CreateInternalSignals();
  
  // we are not allowing recursive value recorder in the value field
  CollectInlineValueRecorder();
  AnnotateValueRecorderType();

  // Gather 1. value recorder
  // 2. delay vars
  // 3. def vars ()
  // 4. stage or others are 1 cycle
  CollectInternallyDefinedVars();


  AnnotateAllTypes();
  // additionally you can have an RTL signal replace pass?
  
  
} // TypedVerilogRefinementMap::TypedVerilogRefinementMap

void TypedVerilogRefinementMap::CollectInlineValueRecorderFunc(RfExpr & inout) {
  if(inout->get_op() == voperator::AT) {
    auto recorder_name = new_id();
    auto new_node = VExprAst::MakeVar(recorder_name);
    VExprAst::VExprAstPtrVec child(inout->get_child());
    ValueRecorder tmp_value_recorder;
    tmp_value_recorder.width = 0;
    tmp_value_recorder.value = child.at(0);
    if (child.at(1)->is_constant()) {
      // deal with value@0

      auto new_cond = VExprAst::MakeBinaryAst(voperator::L_EQ,
        
        )

    } else
      tmp_value_recorder.condition = child.at(1);
    
    
  }
} // CollectInlineValueRecorder

void TypedVerilogRefinementMap::CollectInternallyDefinedVars() {

#define ERRIF(cond,str) do{ ILA_ERROR_IF(cond) << str ; if(cond) return; } while(false)

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
      all_var_def_types.emplace(n_st.first);
    }
    for (const auto & n_st : customized_monitor) {
      ERRIF( !is_valid_id_name(n_st.first) ,  "Monitor name " + n_st.first + " is not valid" );
      ERRIF( IN(n_st.first, monitor_names) , "Monitor name " + n_st.first + " has been used" );
      monitor_names.insert(n_st.first);
      
      for (const auto & var_def : n_st.second.var_defs ) {
        ERRIF( IN(var_def.first, var_def_names) , "Variable " + n_st.first + " has been defined already" );
        var_def_names.insert(var_def.first);
      }
    }
#undef ERRIF
} // CollectInternallyDefinedVars



} // namespace rfmap
} // namespace ilang

