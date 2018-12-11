/// \file Header for Interace Directive in Refinement relations in Verilog Verification Target Generation
/// Some I/O has special meanings, and special usage
/// The wrapper has to be able to handle it
// --- Hongce Zhang
#ifndef DIRECTIVE_H__
#define DIRECTIVE_H__

#include <string>
#include <ilang/verilog-in/verilog_analysis_wrapper.h>

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
  static bool beginsWith(const std::string & c, const std::string & s);
  static bool isSpecialInputDir(const std::string & c);
  static bool isSpecialInputDirCompatibleWith(const std::string & c, const SignalInfoBase & vlg_sig );
  static bool interfaceDeclare(const std::string & c);
  // --- more to added 

}; // class IntefaceDirectiveRecorder


/*
**MEM**.?
*/

class StateMappingDirectiveRecorder {
public:
  static bool isSpecialStateDir(const std::string & c);

}; // class StateMappingDirectiveRecorder

}; // namespace ilang

#endif // DIRECTIVE_H__