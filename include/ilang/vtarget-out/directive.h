/// \file Header for Interace Directive in Refinement relations in Verilog
/// Verification Target Generation Some I/O has special meanings, and special
/// usage The wrapper has to be able to handle it
// --- Hongce Zhang
#ifndef ILANG_VTARGET_OUT_DIRECTIVE_H__
#define ILANG_VTARGET_OUT_DIRECTIVE_H__

#include <functional>
#include <map>
#include <string>
#include <tuple>

#include <ilang/verilog-in/verilog_analysis_wrapper.h>
#include <ilang/verilog-out/verilog_gen.h>
#include <ilang/vtarget-out/absmem.h>

namespace ilang {

/// \brief Used in Verilog Verification Target Generation
/// for dealing with interface directives
/*
**CLOCK**
**RESET**
**KEEP**
**NC**
**MEM** rdata/raddr/ren/wdata/waddr/wen.?
*/
class IntefaceDirectiveRecorder {
public:
  /// Type interface directives
  typedef enum {
    KEEP = 0,
    NC /*not connected*/,
    SO /*state out*/,
    INPUT /*general input*/,
    RESET,
    CLOCK,
    MEM_R_A,
    MEM_R_D,
    MEM_R_EN,
    MEM_W_A,
    MEM_W_D,
    MEM_W_EN,
    START
  } inf_dir_t;
  /// Type of interface connector
  typedef std::pair<inf_dir_t, std::string> inf_connector_t;
  /// Type of interface connector storage
  typedef std::map<std::string, inf_connector_t> mod_inst_rec_t;
  /// Using vlg-out's signal type
  using vlg_sig_t = VerilogGeneratorBase::vlg_sig_t;
  /// Using vlg-out's signal vector type
  using vlg_sig_vec_t = VerilogGeneratorBase::vlg_sigs_t;
  /// ILA input compatible checker type
  typedef std::function<bool(const std::string&, const SignalInfoBase&)>
      ila_input_checker_t;
  /// Type of call back function to find information about a memory
  typedef std::function<std::pair<unsigned, unsigned>(const std::string&)>
      ila_mem_checker_t;
  /// Type of call back function to insert assumptions
  typedef std::function<void(const std::string&)> assmpt_inserter_t;
  /// type of read port
  using rport_t = VerilogGeneratorBase::rport_t;
  /// type of write port
  using wport_t = VerilogGeneratorBase::wport_t;

public:
  /// Return if a string 'c' begins with string 's'
  static bool beginsWith(const std::string& c, const std::string& s);
  /// Return true if 'c' is special input directive
  static bool isSpecialInputDir(const std::string& c);
  /// Check for compatibility
  static bool isSpecialInputDirCompatibleWith(const std::string& c,
                                              const SignalInfoBase& vlg_sig);
  /// Check if an interface needs to be declare as top module I/O
  // static bool interfaceDeclareTop(const std::string & c);
  // --- more to added
  // -------------------- CONSTRUCTOR ---------------------------- //
  /// \param[in] : whether to connect reset signal to rst/dummy_reset
  /// The former is for invariants, the latter for instructions
  IntefaceDirectiveRecorder(bool reset_vlg) : _reset_vlg(reset_vlg) {}

  // ------------------------ MEMBERS ------------------------ //
  /// clear all internal storage
  void Clear(bool reset_vlg);
  /// Return a string used for instantiating
  std::string GetVlgModInstString(VerilogGeneratorBase& gen) const;
  /// Add signals to the wrapper_generator
  void VlgAddTopInteface(VerilogGeneratorBase& gen) const;
  /// Used to tell this module about the refinement relations
  void RegisterInterface(const SignalInfoBase& vlg_sig,
                         const std::string& refstr, ila_input_checker_t chk,
                         ila_mem_checker_t mget);
  /// Register the extra wire to connect (for extra wire)
  void RegisterExtraWire(const std::string& io_name,
                         const std::string& outside_name);
  /// Register the connection of signals related to a memory
  std::string ConnectMemory(const std::string& directive,
                            const std::string& ila_state_name,
                            const std::map<unsigned, rport_t>& rports,
                            const std::map<unsigned, wport_t>& wports,
                            int ila_addr_width, int ila_data_width,
                            bool abs_read);
  /// Insert memory abstractions' assumptions
  void InsertAbsMemAssmpt(assmpt_inserter_t inserter);

  /// Setting the memory abstraction name, but does not enforce any equality
  /// there
  void SetMemName(const std::string& directive,
                  const std::string& ila_state_name, bool abs_read);

  /// Setting the memory abstraction name, and width...
  /// but does not enforce any equality
  /// there
  void SetMemNameAndWidth(const std::string& directive,
                          const std::string& ila_state_name, bool abs_read, int,
                          int);

  /// Return the memory instantiation string
  std::string GetAbsMemInstString(VerilogGeneratorBase& gen,
                                  const std::string& endCond);
  /// Check if some port has been connected,
  /// if not, connect it to the wire_name (will not create wire!)
  /// if connected, will warn and refuse to connect
  /// should be called before GetAbsMemInstString
  /// return the wire name to create (but no need to create if it is empty)
  std::pair<std::string, unsigned int>
  KeepMemoryPorts(const std::string& mem_name, const std::string& port_name,
                  bool caller_build_wire);

protected:
  /// a sanity check for module instantiation string gen, check if all the vlg
  /// module i/o has been declared correctly.
  void ModuleInstSanityCheck(VerilogGeneratorBase& gen) const;
  /// a shortcut to connect module and add wire
  void ConnectModuleInputAddWire(const std::string& short_name, unsigned width);
  /// a shortcut to connect module and add wire
  void ConnectModuleOutputAddWire(const std::string& short_name,
                                  unsigned width);

protected:
  /// a map of port-name -> (tp, signal name)
  mod_inst_rec_t mod_inst_rec;
  // a wire will not appear in two or more of the category
  /// wires to be declared as input and wire
  vlg_sig_vec_t input_wires;
  /// wires to be declared as output and wire
  vlg_sig_vec_t output_wires;
  /// wires to be declared as just wire
  vlg_sig_vec_t internal_wires;
  /// ila-mem-name -> abs
  std::map<std::string, VlgAbsMem> abs_mems;
  /// whether to reset this vlg (reset to rst or dummy_reset)
  bool _reset_vlg;

}; // class IntefaceDirectiveRecorder

/*
**MEM**.?
*/

/// \brief a class to handle state-mapping directives in the refinement
/// relations
class StateMappingDirectiveRecorder {
public:
  // ------------------------------ HELPER
  // ------------------------------------//
  /// a function to determine if a state map refstr is special directie (**???)
  static bool isSpecialStateDir(const std::string& c);
  /// a function to determine if a state map refstr is special directie (**???)
  static bool isSpecialStateDirMem(const std::string& c);
  /// a function to determine if a function name is an unknown special directive
  static bool isSpecialUnknownFunctionName(const std::string &funcname);
  /// a function to determine if a function (no arg) is an unknown special directive
  static bool isSpecialUnknownFunction(const FuncPtr &func_ptr);
}; // class StateMappingDirectiveRecorder

}; // namespace ilang

#endif // ILANG_VTARGET_OUT_DIRECTIVE_H__
