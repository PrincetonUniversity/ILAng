/// \file Verilog Verification Refinement Map Interface Class
/// Type checker
/// --- Hongce Zhang (hongcez@princeton.edu)

#ifndef ILANG_RFMAP_TYPECHECK_H__
#define ILANG_RFMAP_TYPECHECK_H__

#include <ilang/rfmap-in/rfvar_type.h>
#include <ilang/rfmap-in/verilog_rfmap.h>

#include <functional>

// define annotation

namespace ilang {
namespace rfmap {

class TypeAnnotation : public ::verilog_expr::AbstractInternalInfo,
                       public ::ilang::rfmap::RfVarTypeOrig {

public:
  // allow instantiation
  virtual void should_not_instantiate() override {}

  TypeAnnotation() {}
  TypeAnnotation(const ::ilang::rfmap::RfVarTypeOrig& r)
      : ::ilang::rfmap::RfVarTypeOrig(r) {}
}; // TypeAnnotation

/// \class structure for recording variable replacement
struct VarReplacement {
  RfExpr origvar; // this is certainly a var
  RfExpr newvar;  // this is certainly a var

  VarReplacement(const RfExpr& o, const RfExpr& n);

  // returns v, there would not be `v[range]` at all
  std::string get_orig_name() const {
    return std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(origvar)
        ->get_name()
        .first;
  }

  std::string get_new_name() const {
    return std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(newvar)
        ->get_name()
        .first;
  }

  RfVarTypeOrig get_type_new() const { return get_type_orig(); }

  RfVarTypeOrig get_type_orig() const {
    auto annotation_ptr = newvar->get_annotation<TypeAnnotation>();
    return annotation_ptr ? *annotation_ptr : RfVarTypeOrig();
  }

  bool is_orig_rtlv() const {
    return get_type_orig().var_ref_type == RfVarTypeOrig::VARTYPE::RTLV;
  }
  bool is_orig_ila_state() const {
    return get_type_orig().var_ref_type == RfVarTypeOrig::VARTYPE::ILAS;
  }
  bool is_orig_ila_input() const {
    return get_type_orig().var_ref_type == RfVarTypeOrig::VARTYPE::ILAI;
  }

  bool is_orig_var_array() const { return get_type_orig().type.is_array(); }
};

// convert RfExpr constant -> out
bool _compute_const(const RfExpr& in, unsigned& out);

// type infer rules
//

// provide function:

// try_find_ila_type -> TypeAnnotation
// try find_rtl_type -> TypeAnnotation
// type annotation & checking & replacing : all-together

class TypeAnalysisUtility {

public:
  typedef std::function<RfVarTypeOrig(const std::string&)> var_typecheck_t;

public:
  /// Annotate the type of a refinement expression
  /// and this process will be recursive
  static void AnnotateType(const RfExpr& inout,
    const std::map<std::string,int> & quantified_var_type);

protected:
  // internal use only, does not do recursion itself
  // therefore, an order of invocation is needed
  static void infer_type_based_on_op_child(const RfExpr& inout);

}; // struct TypeAnalysisUtility

class RfExprAstUtility {
private:
  /// will only replace the free var, so we need to keep track
  /// if some var inside are quantified, in that case, should not mask 
  static RfExpr ReplaceQuantifiedVar(const std::string &n,
    const RfExpr & in, const RfExpr & newexpr,
    const std::set<std::string> & quantified_var);

  /// expand the current one, should be invoked from the leaf node
  static RfExpr QuantifierInstantiation(const RfExpr& in);

public:
  /// determine if a rf expr has array variable in it
  static bool HasArrayVar(const RfExpr& in);
  /// determine if a rf expr has quantifier in it
  static bool HasQuantifier(const RfExpr& in);
  ///  for pono, this will cause to use text
  /// FORALL -> /\ /\ /\ ...  (JasperGold)
  /// EXISTS -> \/ \/ \/ ...
  static RfExpr FindExpandQuantifier(const RfExpr& in);


  /// determine if a rf expr is a boolean expr
  static bool IsLastLevelBooleanOp(const RfExpr& in);
  /// get the variables from a expression
  static void GetVars(const RfExpr& in,
                      std::unordered_map<std::string, RfVar>& vars_out);
  static RfVarTypeOrig GetType(const RfExpr& in);
  /// will modify where the pointer is pointing to
  /// because we will be creating new rfexpr
  static RfExpr TraverseRfExpr(const RfExpr& inout,
                             std::function<RfExpr(const RfExpr& inout)> func);
  /// will modify where the pointer is pointing to
  /// because we will be creating new rfexpr
  static void TraverseRfExprNoModify(const RfExpr& inout,
                             std::function<void(const RfExpr& inout)> func);
  /// check to make sure no null ptr
  static void RfMapNoNullNode(const RfExpr& in);
};

struct RfExprVarReplUtility {

public:
  /// used by vtarget_gen to replace rtl/ila vars
  RfExpr ReplacingRtlIlaVar(const RfExpr& in, const std::set<std::string> & quantified_vars);

  /// Register internal variables and also the mapping
  void RegisterInternalVariableWithMapping(const std::string& n,
                                           const VarReplacement& in) {
    var_replacement.emplace(n, in);
  }

  VarReplacement* CheckReplacement(const std::string& origname) {
    auto pos = var_replacement.find(origname);
    if (pos != var_replacement.end())
      return &(var_replacement.at(origname));
    return NULL;
  }

  const std::map<std::string, VarReplacement>& GetVarReplacement() const {
    return var_replacement;
  }

protected:
  /// the replacement used for creating new wires
  std::map<std::string, VarReplacement>
      var_replacement; // including rtl/ilas/ilav
};

struct TypedVerilogRefinementMap : public VerilogRefinementMap,
                                   public TypeAnalysisUtility,
                                   public RfExprAstUtility,
                                   public RfExprVarReplUtility {

  // type definitions
  using var_typecheck_t = TypeAnalysisUtility::var_typecheck_t;
  using VarDef = GeneralVerilogMonitor::VarDef;

  // constructor
  // typechecker is only used in TypeInferTraverseRfExpr
  TypedVerilogRefinementMap(const std::string& varmap_json_file,
                            const std::string& instcond_json_file,
                            var_typecheck_t type_checker);

  TypedVerilogRefinementMap(const VerilogRefinementMap& refinement,
                            var_typecheck_t type_checker);

  // references
  // - named defined vars with type
  // - named stages with type bit 1

  // additional delayed
  std::map<std::string, SignalDelay> aux_delays;
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
  void TraverseAllRfExpr(std::function<RfExpr(const RfExpr& inout)> func);

  // this function is used in
  // (1) value holder/delay : width determination
  //                   will use all_var_def_types & typechecker
  // (2) vlg-monitor replace-var
  RfMapVarType TypeInferTravserRfExpr(const RfExpr& in, const std::map<std::string, int> local_var_def);

protected:
  // used in TypedVerilogRefinementMap::TypeInferTravserRfExpr
  // this is only used in the first stage : aux var width determination
  var_typecheck_t typechecker;

  void initialize();
  /// this function will not collect implicity vars
  /// or those with 0/auto width
  /// for the explicity vars
  /// it will add them to the `all_var_def_types`
  /// for the implicit ones, ComputeDelayValueHolderWidth will
  /// compute the width and add them to `all_var_def_types`

  /// this will also create `all_var_def_types`
  /// for 4 virtual vars: decode, commit, $decode, $valid
  /// those replacement are added separately
  void CollectInternallyDefinedVars();

  /// deal with condition map
  void TraverseCondMap(SingleVarMap& inout,
                       std::function<RfExpr(const RfExpr& inout)> func);

private:
  // help with naming
  unsigned counter;
  std::string new_id();

  // helper for AST traversal
  RfExpr collect_inline_value_recorder_func(const RfExpr& inout);
  RfExpr collect_inline_delay_func(const RfExpr& inout);
  // this function uses the above two and the
  void CollectInlineDelayValueHolder();

  void ComputeDelayValueHolderWidth();

}; // TypedVerilogRefinementMap

} // namespace rfmap
} // namespace ilang

#endif // ILANG_RFMAP_TYPECHECK_H__
