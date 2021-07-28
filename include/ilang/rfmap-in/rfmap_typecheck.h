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

  VarReplacement(const RfExpr & o, const RfExpr & n);

  // returns v or v[range]
  std::string get_orig_name() const {
    return std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(
      origvar)->get_name().first;
    }

  std::string get_new_name() const{
    return std::dynamic_pointer_cast<verilog_expr::VExprAstVar>
      (newvar)->get_name().first; }

  RfVarTypeOrig get_type_new() const {
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

class TypeAnalysisUtility {

public:
  typedef std::function<RfVarTypeOrig(const std::string &)> var_typecheck_t;
  TypeAnalysisUtility(var_typecheck_t type_checker) : typechecker(type_checker) { }

public:
  /// Annotate the type of a refinement expression
  /// and this process will be recursive
  // this function is to help with unit testing
  void AnnotateType(const RfExpr & inout);

protected:
  var_typecheck_t typechecker;
  // used in TypedVerilogRefinementMap::TypeInferTravserRfExpr
  // this is only used in the first stage : aux var width determination

  // internal use only, does not do recursion itself
  // therefore, an order of invocation is needed
  static void infer_type_based_on_op_child(const RfExpr & inout) ;

}; // struct TypeAnalysisUtility

class RfExprAstUtility {
public:
  static bool HasArrayVar(const RfExpr & in, std::map<std::string, RfVar> & array_var);
  /// determine if a rf expr is a boolean expr
  static bool IsLastLevelBooleanOp(const RfExpr & in);
  /// get the variables from a expression
  static void GetVars(const RfExpr & in, 
    std::unordered_map<std::string, RfVar> & vars_out);
  static RfVarTypeOrig GetType(const RfExpr & in);
};


struct TypedVerilogRefinementMap : 
  public VerilogRefinementMap,
  public TypeAnalysisUtility,
  public RfExprAstUtility {

  // type definitions
  using var_typecheck_t = TypeAnalysisUtility::var_typecheck_t;
  using VarDef = GeneralVerilogMonitor::VarDef;
  
  // constructor
  // typechecker is only used in TypeInferTraverseRfExpr
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
  std::map<std::string, VarDef> all_var_def_types;
  // the above is only used in the first round
  // 2. second round : AST type check
  // so this is NOT used in creating vars?
  // Var creating stage should deal with separate ones

  // this should include phase-tracker (m,v,alias)
  // ... ? 
  void TraverseAllRfExpr(std::function<void(RfExpr & inout)> func);

  /// used by vtarget_gen to replace rtl/ila vars
  RfExpr ReplacingRtlIlaVar(const RfExpr & in);

  /// Register internal variables and also the mapping
  void RegisterInternalVariableWithMapping(
    const std::string & n, 
    const VarReplacement & in) { var_replacement.emplace(n, in); }

  VarReplacement * CheckReplacement(const std::string & origname) const {
    auto pos = var_replacement.find(origname);
    if(pos != var_replacement.end())
      return &(pos->second);
    return NULL;
  }

protected:

  /// the replacement used for creating new wires
  std::map<std::string, VarReplacement> var_replacement; // including rtl/ilas/ilav

  void initialize();
  void CollectInternallyDefinedVars();

  void TraverseRfExpr(RfExpr & inout, std::function<void(RfExpr & inout)> func) ;
  void TraverseCondMap(SingleVarMap & inout, std::function<void(RfExpr & inout)> func) ;


private:
  
  // help with naming
  unsigned counter;
  std::string new_id();

  // helper for AST traversal
  void collect_inline_value_recorder_func(RfExpr & inout);
  void collect_inline_delay_func(RfExpr & inout);
  void CollectInlineDelayValueHolder();

  // this function is used in value holder/delay : width determination
  // will use all_var_def_types
  RfMapVarType TypeInferTravserRfExpr(const RfExpr & in); 
  
  void ComputeDelayValueHolderWidth();

}; // TypedVerilogRefinementMap

} // namespace rfmap
} // namespace ilang

#endif // ILANG_RFMAP_TYPECHECK_H__


