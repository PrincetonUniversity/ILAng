/// \file Verilog Verification Refinement Map Interface Class
/// External Refinement Map Interface Class
/// --- Hongce Zhang (hongcez@princeton.edu)

#ifndef ILANG_VERILOG_RFMAP_H__
#define ILANG_VERILOG_RFMAP_H__

#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <vexpparser/vexp.h>

namespace ilang {
namespace rfmap {

// ---------------------- varmap ------------------------------- //

/*
"model names" : {
  "ILA" : "SomeNameHere",
  "RTL" : "SomeNameHere"
}
*/

typedef verilog_expr::VExprAst::VExprAstPtr RfExpr;
typedef verilog_expr::VExprAstVar::VExprAstVarPtr RfVar;

/*
"ILA_mem_state_var_2" : {                            // case 4 : external RTL
memory "wen"   : "<refinement-expression>", "waddr" : "<refinement-expression>",
  "wdata" : "<refinement-expression>",
  "ren"   : "<refinement-expression>",
  "raddr" : "<refinement-expression>",
  "rdata" : "<refinement-expression>"
},
*/

struct SingleVarMap {
  /// a single refinement string, will be initialized to NULL
  RfExpr single_map;
  /// a list of pair of string
  std::vector<std::pair<RfExpr, RfExpr>> cond_map;
};

struct ExternalMemPortMap {
  bool wport_mapped;
  bool rport_mapped;
  SingleVarMap wen_map;
  SingleVarMap waddr_map;
  SingleVarMap wdata_map;
  SingleVarMap ren_map;
  SingleVarMap raddr_map;
  SingleVarMap rdata_map;
  ExternalMemPortMap() : wport_mapped(false), rport_mapped(false) {}
}; // struct ExternalMemPortMap

struct IlaVarMapping {
  enum class StateVarMapType { SINGLE, CONDITIONAL, EXTERNMEM } type;
  /// a single refinement string
  SingleVarMap single_map;
  /// the standard 6-port map
  std::vector<ExternalMemPortMap> externmem_map;
}; // struct IlaVarMapping

struct RtlInterfaceMapping {
  /// "CLOCK" : { "clkA" : "wclk", "clkB" : ["rclk", "clk"] }
  // name of the clock domain -> list of clock pins
  std::map<std::string, std::set<std::string>> clock_domain_defs;

  // "RESET" : "reset", // you can have a list of signals here
  std::set<std::string> reset_pins;
  // "NRESET" : ["nreset1", "nreset2"],  // like this
  std::set<std::string> nreset_pins;
  // "CUSTOMRESET" : {"name"  : "input-pin", ...}
  std::map<std::string, std::vector<std::string>> custom_reset_domain_defs;
  // "INPUT/INPUTs/INPUT-ports",
  std::map<std::string, RfExpr> input_port_connection;
}; // struct RtlInterfaceMapping

typedef std::vector<bool> OneBitSignalSequence;

struct ResetSpecification {
  // rtl state var -> value map
  std::map<std::string, RfExpr> initial_state;
  // reset cycle : unsigned int
  unsigned reset_cycle;
  // customized reset sequence
  std::map<std::string, OneBitSignalSequence> custom_reset_sequence;
  // default constructor
  ResetSpecification() : reset_cycle(1) {}
}; // ResetSpecification

struct ClockSpecification {
  struct factor {
    unsigned high;
    unsigned low;
    unsigned offset;
  };

  unsigned gcm_period;
  // per-clock domain specification, name -> sequence
  std::map<std::string, OneBitSignalSequence> custom_clock_sequence;
  // specified by the factor
  std::map<std::string, ClockSpecification::factor> custom_clock_factor;
}; // ClockSpecification

struct UninterpretedFunctionApplication {
  struct Apply {
    RfExpr result_map;
    std::vector<RfExpr> arg_map;
  };
  std::vector<Apply> func_applications;
}; // UninterpretedFunctionApplication

struct GeneralVerilogMonitor {
  struct VarDef {
    enum class var_type { REG, WIRE } type;
    unsigned width;
  }; // VarDef

  std::string verilog_inline; // handle concatnation/load from file etc
  std::string verilog_append; //
  std::map<std::string, VarDef> var_defs;
  std::set<std::string> var_uses;
  bool keep_for_invariant;

  GeneralVerilogMonitor() : keep_for_invariant(false) {}
}; // GeneralVerilogMonitor

struct ValueRecorder {
  RfExpr condition;
  RfExpr value;
  unsigned width;

  ValueRecorder() : condition(nullptr), value(nullptr), width(0) {}
};

// this is not directly used
struct SignalDelay {

  SignalDelay(const RfExpr& _signal, unsigned n_cycle)
      : delay_type(delay_typeT::SINGLE), signal(_signal), num_cycle(n_cycle),
        width(0), upper_bnd(0) {}

  SignalDelay(const RfExpr& _signal, unsigned n_cycle, unsigned u_bnd)
      : delay_type(u_bnd == 0 ? delay_typeT::TO_INFINITE : delay_typeT::RANGE),
        signal(_signal), num_cycle(n_cycle), width(0), upper_bnd(u_bnd) {}

  enum class delay_typeT { SINGLE, RANGE, TO_INFINITE } delay_type;
  RfExpr signal;
  unsigned num_cycle;
  unsigned width;

  unsigned upper_bnd;
};

struct AuxVar {
  std::string name;
  RfExpr val;
  unsigned width;
  AuxVar(const std::string & n) : name(n), width(0) {}
};

struct PhaseTracker {
  struct Assignment {
    std::string LHS; // a state name
    RfExpr RHS;      // a rhs expression
  };
  typedef std::vector<Assignment> Action;
  struct Rule {
    std::string stage_name;
    RfExpr enter_rule; // this is not using Verilog signals
    RfExpr exit_rule;
    Action enter_action;
    Action exit_action;
  };

  using VarDef = GeneralVerilogMonitor::VarDef;
  // name to defs
  std::map<std::string, VarDef> var_defs;
  std::map<std::string, RfExpr> event_alias;
  std::vector<Rule> rules;
};

// ---------------------- inst-cond ------------------------------- //

struct InstructionCompleteCondition {
  std::string instruction_name;
  enum class ConditionType { BOUND, SIGNAL } type;
  unsigned ready_bound;
  unsigned max_bound;
  std::vector<RfExpr> start_condition;
  RfExpr ready_signal;

  InstructionCompleteCondition()
      : ready_bound(0), max_bound(0), ready_signal(nullptr) {}
  bool is_readybound() const { return type == ConditionType::BOUND; }
  bool is_readysignal() const { return type == ConditionType::SIGNAL; }
}; //

struct VerilogRefinementMap {
  // ---------------------- varmap ------------------------------- //
  /// State mapping section
  std::map<std::string, IlaVarMapping> ila_state_var_map;
  /// State mapping section
  std::map<std::string, IlaVarMapping> ila_input_var_map;
  /// RTL interface connection specification
  RtlInterfaceMapping rtl_interface_connection;
  /// reset section
  ResetSpecification reset_specification;
  /// clock section
  ClockSpecification clock_specification;
  /// Uninterpreted function map : func-name -> applications
  std::map<std::string, UninterpretedFunctionApplication> uf_application;
  /// "additional mapping"  section
  std::vector<RfExpr> additional_mapping;
  /// "assumptions" section
  std::vector<RfExpr> assumptions;
  /// Customized Verilog Monitor
  std::map<std::string, PhaseTracker> phase_tracker;
  std::map<std::string, ValueRecorder> value_recorder;
  std::map<std::string, GeneralVerilogMonitor> customized_monitor;
  std::map<std::string, AuxVar> direct_aux_vars;

  // ---------------------- inst-cond ------------------------------- //
  std::map<std::string, InstructionCompleteCondition> inst_complete_cond;
  std::vector<RfExpr> global_invariants;

  // ---------------------- supplementary_info -------------------------------
  // //
  std::map<std::string, int>
      width_info; // this is needed in case our width inference failed
  std::map<std::string, int>
      range_info; // this is needed in case our width inference failed

  // member function : return true if checking passed
  bool SelfCheckField() const;

  // from JSON
  VerilogRefinementMap(const std::string& varmap_json_file,
                       const std::string& instcond_json_file);

  static RfExpr ParseRfExprFromString(const std::string& in);

}; // VerilogRefinementMap

} // namespace rfmap
} // namespace ilang

#endif // ILANG_VERILOG_RFMAP_H__
