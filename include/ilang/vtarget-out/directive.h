/// \file Header for Interace Directive in Refinement relations in Verilog Verification Target Generation
/// Some I/O has special meanings, and special usage
/// The wrapper has to be able to handle it
// --- Hongce Zhang
#ifndef DIRECTIVE_H__
#define DIRECTIVE_H__

#include <functional>
#include <tuple>
#include <map>
#include <string>
#include <ilang/verilog-in/verilog_analysis_wrapper.h>
#include <ilang/verilog-out/verilog_gen.h>

namespace ilang {

/// \brief a struct to store abstract memory
struct VlgAbsMem {
  // ---------------------- TYPES --------------- //
  /// type of read port
  typedef struct  {
    /// what to connect for raddr
    std::string raddr; 
    /// what to connect for rdata
    std::string rdata;
    /// what to connect for ren
    std::string ren;
  } rport_t;
  /// type of write port
  typedef struct  {
    /// what to connect for waddr
    std::string waddr;
    /// what to connect for wdata
    std::string wdata;
    /// what to connect for wen
    std::string wen;
  } wport_t;

  // ---------------------- MEMBERS --------------- //
  /// read ports
  std::map<unsigned,rport_t> rports;
  /// write ports
  std::map<unsigned,wport_t> wports;

  /// how many are considered to be concrete
  unsigned concrete_level; 
  /// widths
  unsigned data_width;
  /// widths
  unsigned addr_width;
  /// which ila state it is mapped to
  std::string ila_map_name;
}; // class VlgAbsMem

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
  typedef enum {KEEP = 0, NC /*not connected*/, 
    SO /*state out*/, INPUT /*general input*/, RESET, CLOCK, 
    MEM_R_A, MEM_R_D, MEM_R_EN, MEM_W_A, MEM_W_D, MEM_W_EN } inf_dir_t;
  /// Type of interface connector
  typedef std::pair<inf_dir_t, std::string>            inf_connector_t;
  /// Type of interface connector storage
  typedef std::map<std::string, inf_connector_t>        mod_inst_rec_t;
  /// Using vlg-out's signal type
  using vlg_sig_t = VerilogGeneratorBase::vlg_sig_t;
  /// Using vlg-out's signal vector type
  using vlg_sig_vec_t = VerilogGeneratorBase::vlg_sigs_t;
  /// ILA input compatible checker type
  typedef std::function<bool(const std::string &, const SignalInfoBase & )>
    ila_input_checker_t;
  /// Type of call back function to find information about a memory
  typedef std::function<std::pair<unsigned,unsigned>(const std::string &)>
    ila_mem_checker_t;
  
public:
  /// Return if a string 'c' begins with string 's'
  static bool beginsWith(const std::string & c, const std::string & s);
  /// Return true if 'c' is special input directive
  static bool isSpecialInputDir(const std::string & c);
  /// Check for compatibility
  static bool isSpecialInputDirCompatibleWith(const std::string & c, const SignalInfoBase & vlg_sig );
  /// Check if an interface needs to be declare as top module I/O
  static bool interfaceDeclareTop(const std::string & c);
  // --- more to added 
  // ------------------------ MEMBERS ------------------------ //
  /// clear all internal storage
  void Clear();
  /// Return a string used for instantiating
  std::string GetVlgModInstString(VerilogGeneratorBase & gen) const;
  /// Add signals to the wrapper_generator
  void VlgAddTopInteface(VerilogGeneratorBase & gen) const;
  /// Used to tell this module about the refinement relations
  void RegisterInterface(const SignalInfoBase & vlg_sig, 
    const std::string & refstr,
    ila_input_checker_t chk,
    ila_mem_checker_t   mget);

protected:
  /// a sanity check for module instantiation string gen, check if all the vlg module i/o has been declared correctly.
  void ModuleInstSanityCheck() const;
  /// a shortcut to connect module and add wire
  void ConnectModuleInputAddWire(const std::string & short_name, unsigned width);
  /// a shortcut to connect module and add wire
  void ConnectModuleOutputAddWire(const std::string & short_name, unsigned width);

protected:
  /// a map of port-name -> (tp, signal name)
  mod_inst_rec_t mod_inst_rec;
  // a wire will not appear in two or more of the category
  /// wires to be declared as input and wire
  vlg_sig_vec_t  input_wires;
  /// wires to be declared as output and wire
  vlg_sig_vec_t  output_wires
  /// wires to be declared as just wire
  vlg_sig_vec_t  internal_wires;
  /// ila-mem-name -> abs
  std::map< std::string, VlgAbsMem> abs_mems;
  
}; // class IntefaceDirectiveRecorder


/*
**MEM**.?
*/

/// \brief a class to handle state mapping directives in the refinement relations
class StateMappingDirectiveRecorder {
public:
  // ------------------------------ HELPER ------------------------------------//
  /// a function to determine if a state map refstr is special directie (**???)
  static bool isSpecialStateDir(const std::string & c);

}; // class StateMappingDirectiveRecorder

}; // namespace ilang

#endif // DIRECTIVE_H__