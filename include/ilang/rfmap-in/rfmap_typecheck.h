/// \file Verilog Verification Refinement Map Interface Class
/// Type checker
/// --- Hongce Zhang (hongcez@princeton.edu)


#ifndef ILANG_RFMAP_TYPECHECK_H__
#define ILANG_RFMAP_TYPECHECK_H__

#include <ilang/rfmap-in/verilog_rfmap.h>
#include <ilang/rfmap-in/rfvar_type.h>

#include <functional>


// define annotation


namespace ilang {
namespace rfmap {

  
class TypeAnnotation : 
  public ::verilog_expr::AbstractInternalInfo,
  public ::ilang::rfmap::RfVarTypeOrig {
  
public:
  // allow instantiation
  virtual void should_not_instantiate() override {}

}; // TypeAnnotation



// type infer rules
// 

// provide function: 

// try_find_ila_type -> TypeAnnotation
// try find_rtl_type -> TypeAnnotation
// type annotation & checking & replacing : all-together

struct TypedVerilogRefinementMap : public VerilogRefinementMap {

  // type definitions
  typedef std::function<RfVarTypeOrig(const std::string &)> var_typecheck_t;
  using VarDef = GeneralVerilogMonitor::VarDef;
  
  // constructor
  TypedVerilogRefinementMap(
    const std::string & varmap_json_file,
    const std::string & instcond_json_file,
    var_typecheck_t type_checker
    );
    
// references
// - named defined vars with type
// - named stages with type bit 1

// additional delayed
  std::map<std::string,SignalDelay> aux_delays;
// additional value_recoder added to value_recorder

  // defined vars
  // 1. first round : only explict ones
  //    this is to collect information before running the
  //    the AST type checks
  // 2. second round : will be populated by the AST type checks
  // so this can NOT be used in creating vars stage?
  // Var creating stage should deal with separate ones
  std::map<std::string, VarDef> all_var_def_types;
  // this should include phase-tracker (m,v,alias)
  // ... ? 
  void TraverseAllRfExpr(std::function<void(RfExpr & inout)> func);

protected:
  void CollectInternallyDefinedVars();

  void TraverseRfExpr(RfExpr & inout, std::function<void(RfExpr & inout)> func) ;
  void TraverseCondMap(SingleVarMap & inout, std::function<void(RfExpr & inout)> func) ;

  var_typecheck_t typechecker;
private:
  
  // help with naming
  unsigned counter;
  std::string new_id();

  // helper for AST traversal
  void collect_inline_value_recorder_func(RfExpr & inout);
  void collect_inline_delay_func(RfExpr & inout);
  void CollectInlineDelayValueHolder();

  RfMapVarType TypeInferTravserRfExpr(const RfExpr & in);
  void ComputeDelayValueHolderWidth();


};

} // namespace rfmap
} // namespace ilang

#endif // ILANG_RFMAP_TYPECHECK_H__


