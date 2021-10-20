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
                         const std::string& refstr);
  /// Register the extra wire to connect (for extra wire)
  void RegisterExtraWire(const std::string& io_name,
                         const std::string& outside_name);

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
  /// whether to reset this vlg (reset to rst or dummy_reset)
  bool _reset_vlg;

}; // class IntefaceDirectiveRecorder

/*
**MEM**.?
*/

}; // namespace ilang

#endif // ILANG_VTARGET_OUT_DIRECTIVE_H__
