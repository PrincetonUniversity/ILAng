/// \file Verilog Verification Refinement Map Interface Class
/// Type checker
/// --- Hongce Zhang (hongcez@princeton.edu)


#ifndef RFMAP_TYPECHECK_H__
#define RFMAP_TYPECHECK_H__

#include <ilang/rfmap-in/verilog_rfmap.h>
#include <functional>

namespace ilang {
namespace rfmap {

// define type
struct RfMapType {
  enum class TYPE {BV, MEM} type;
  unsigned width;
  unsigned addr_width;
  unsigned data_width;
};

// define annotation
namespace verilog_expr{
class TypeAnnotation : public AbstractInternalInfo {
  public:
    enum class VARTYPE {
      NOTVAR, /*also unknown type*/
      ILAS /*state var*/,
      ILAI, /*ila input*/
      RTLV, /*rtl signal*/
      PHASE,  /*stage name*/
      DEFINE_VAR, /*defined vars*/
      DELAY, /*inline delay*/
      VALUE_RECORDER, /*inline value recorder*/
      INTERNAL /* those already translated:
      like  __CYCLE_CNT__, __START__*/ }; 
    
    // allow instantiation
    virtual void should_not_instantiate() override {}
    
    VARTYPE var_ref_type;
    RfMapType type;

    unsigned width() { return type.type == RfMapType::BV ? width : data_width; }
}; // TypeAnnotation
}

struct InternalSignals {
  RfExpr start;
  RfExpr issue;
  RfExpr iend;
  RfExpr cycle_cnt;
  // and others if necessary
  // __STARTED__
};

// type infer rules
// 

// provide function: 

// try_find_ila_type -> TypeAnnotation
// try find_rtl_type -> TypeAnnotation
// type annotation & checking & replacing : all-together

struct TypedVerilogRefinementMap : public VerilogRefinementMap {

  // type definitions
  typedef std::function<verilog_expr::TypeAnnotation(const std::string &)> var_typecheck_t;
  using VarDef = GeneralVerilogMonitor::VarDef;
  
  // constructor
  TypedVerilogRefinementMap(
    const std::string & varmap_json_file,
    const std::string & instcond_json_file,
    var_typecheck_t ila_var_type_check,
    var_typecheck_t rtl_var_type_check
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

protected:
  void CollectInternallyDefinedVars();
  // internal signals
  InternalSignals internals_;

private:
  
  // help with naming
  unsigned counter;
  std::string new_id();

};

} // namespace rfmap
} // namespace ilang

#endif // RFMAP_TYPECHECK_H__


