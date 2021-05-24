/// \file Header for Verilog Verification Target Generation
/// Utilities
/// These functions are made not dependent on an object
/// as I found they are useful


#ifndef ILANG_VTARGET_OUT_GEN_UTIL_H__
#define ILANG_VTARGET_OUT_GEN_UTIL_H__


#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/verilog-in/verilog_analysis_wrapper.h>


namespace ilang {

namespace vtgutil { // verification target generation utility
  /// a set of signal you can ignore
  extern std::set<std::string> wrapper_signals;
  /// Get the pointer of a ila state, it must exist
  const ExprPtr IlaGetState(const std::string& sname, const InstrLvlAbsCnstPtr & _host);
  /// Get the pointer of an ila input, it must exist
  const ExprPtr IlaGetInput(const std::string& sname, const InstrLvlAbsCnstPtr & _host);
  /// Get (a,d) width of a memory, if not existing, (0,0)
  std::pair<unsigned, unsigned>
    GetMemInfo(const std::string& ila_mem_name, const InstrLvlAbsCnstPtr& _host);
  /// Test if a string represents an ila state name
  bool TryFindIlaState(const std::string& sname, 
    const InstrLvlAbsCnstPtr & _host, const std::string& _ila_mod_inst_name);
  /// Test if a string represents an ila input name
  bool TryFindIlaInput(const std::string& sname, 
    const InstrLvlAbsCnstPtr & _host, const std::string& _ila_mod_inst_name);
  /// Try to find a ILA var according to a name
  ExprPtr TryFindIlaVarName(const std::string& sname,
    const InstrLvlAbsCnstPtr & _host, const std::string& _ila_mod_inst_name);
  /// Test if a string represents a Verilog signal name
  bool TryFindVlgState(const std::string& sname,
    const VerilogInfo * const  vlg_info_ptr, const std::string& _vlg_mod_inst_name);
  /// Check if ila name and vlg name are type compatible (not including special
  /// directives)
  unsigned TypeMatched(const ExprPtr& ila_var,
                              const SignalInfoBase& vlg_var);
  /// get width of an ila node
  unsigned get_width(const ExprPtr& n);
  
}; // namespace vtgutil

}; // namespace ilang


#endif // ILANG_VTARGET_OUT_GEN_UTIL_H__
