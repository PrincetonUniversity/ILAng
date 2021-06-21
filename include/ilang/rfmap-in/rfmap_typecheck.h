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

  TypeAnnotation() {}
  TypeAnnotation(const ::ilang::rfmap::RfVarTypeOrig & r):
    ::ilang::rfmap::RfVarTypeOrig(r) {}
}; // TypeAnnotation


/// \class structure for recording variable replacement
struct VarReplacement {
  RfExpr origvar; // this is certainly a var
  RfExpr newvar; // this is certainly a var
  std::string range_o; // but this could be different

  VarReplacement(const RfExpr & o, const RfExpr & n, const std::string & r = "") :
    origvar(o), newvar(n), range_o (r) {}

  std::string get_orig_name() const {
    if(is_orig_var_array() && !range_o.empty()) 
        return (
          std::dynamic_pointer_cast<verilog_expr::VExprAstVar>
          (origvar)->get_name().first + "[" + range_o + "]"
        );
    // else
    return std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(
      origvar)->get_name().first;
    }

  std::string get_new_name() const{
    //if(is_orig_var_array() && !range_o.empty()) 
    //  return (
    //      std::dynamic_pointer_cast<verilog_expr::VExprAstVar>
    //      (origvar)->get_name().first + "_" + ReplaceAll(range_o,"'","") + "_"
    //    );
    // else
    return std::dynamic_pointer_cast<verilog_expr::VExprAstVar>
      (newvar)->get_name().first; }

  RfVarTypeOrig get_type_new() const {
    /*if(is_orig_var_array() && !range_o.empty()) {
      TypeAnnotation ret;
      ret.type = RfMapVarType(get_type_orig().type.data_width);
      ret.var_ref_type = TypeAnnotation::VARTYPE::NOTVAR;
      return ret;
    }*/
    return get_type_orig();
  }

private:
  RfVarTypeOrig get_type_orig() const {
    auto annotation_ptr = newvar->get_annotation<TypeAnnotation>();
    return annotation_ptr?*annotation_ptr:RfVarTypeOrig();
  }

  bool is_orig_rtlv() const {
    return get_type_orig().var_ref_type == RfVarTypeOrig::VARTYPE::RTLV;
  }
  bool is_orig_ila_state() const{
    return get_type_orig().var_ref_type == RfVarTypeOrig::VARTYPE::ILAS;
  }
  bool is_orig_ila_input() const{
    return get_type_orig().var_ref_type == RfVarTypeOrig::VARTYPE::ILAI;
  }

  bool is_orig_var_array() const {
    return get_type_orig().type.is_array();
  }
};

// convert RfExpr constant -> out
bool _compute_const(const RfExpr & in, unsigned & out);

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
  
  TypedVerilogRefinementMap(
    const VerilogRefinementMap & refinement,
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

  /// used by vtarget_gen to replace rtl/ila vars
  RfExpr ReplacingRtlIlaVar(const RfExpr & in, bool replace_dot);

  /// the replacement used for creating new wires
  std::map<std::string, VarReplacement> var_replacement; // including rtl/ilas/ilav

  /// determine if a rf expr is a boolean expr
  static bool IsLastLevelBooleanOp(const RfExpr & in);

protected:

  void initialize();
  void CollectInternallyDefinedVars();

  void TraverseRfExpr(RfExpr & inout, std::function<void(RfExpr & inout)> func) ;
  void TraverseCondMap(SingleVarMap & inout, std::function<void(RfExpr & inout)> func) ;

  var_typecheck_t typechecker;

  // internal use only, does not do recursion itself
  // therefore, an order of invocation is needed
  void infer_type_op(const RfExpr & inout) ;
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

}; // TypedVerilogRefinementMap

} // namespace rfmap
} // namespace ilang

#endif // ILANG_RFMAP_TYPECHECK_H__


