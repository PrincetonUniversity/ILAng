/// \file Source for Interace Directive in Refinement relations in Verilog Verification Target Generation
// --- Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/vtarget-out/interface_directive.h>

namespace ilang {

  bool IntefaceDirectiveRecorder::beginsWith(const std::string & c, const std::string & s) { 
    return c.find(s) == 0;
  }

  bool IntefaceDirectiveRecorder::isSpecialInputDir(const std::string & c)  {
   return beginsWith(c,"**"); 
  }

  bool IntefaceDirectiveRecorder::isSpecialInputDirCompatibleWith(const std::string & c, const SignalInfoBase & vlg_sig ) {
    ILA_ASSERT(isSpecialInputDir(c));
    if(c == "**KEEP**") return true;
    if(c == "**NC**")   return true;
    if(c == "**SO**")   return vlg_sig.is_output();
    if(c == "**RESET**" || c == "**CLOCK**") return vlg_sig.is_output();
    if(beginsWith(c, "**MEM**")) {
      auto first_dot_loc = c.find(".");
      auto port_name = c.substr(first_dot_loc + 1);
      if( beginsWith(port_name,"waddr") || beginsWith(port_name,"wdata") || beginsWith(port_name,"wen") || 
          beginsWith(port_name,"raddr") || beginsWith(port_name,"ren") )
        return vlg_sig.is_output();
      if( beginsWith(port_name,"rdata") ) return vlg_sig.is_input();
      ILA_ERROR<<"Unknown IO directive in refinement relations:"<<c;
      return false;
    }
    ILA_ERROR<<"Unknown IO directive in refinement relations:"<<c;
    return false;
  }
  bool IntefaceDirectiveRecorder::interfaceDeclare(const std::string & c) {
    ILA_ASSERT(isSpecialInputDir(c));
    if(c == "**KEEP**") return true;
    if(c == "**NC**")   return true;
    if(c == "**SO**")   return true;
    if(c == "**RESET**" || c == "**CLOCK**") return false;
    if(beginsWith(c, "**MEM**")) {
      auto first_dot_loc = c.find(".");
      auto port_name = c.substr(first_dot_loc + 1);
      if( beginsWith(port_name,"waddr") || beginsWith(port_name,"wdata") || beginsWith(port_name,"wen") || 
          beginsWith(port_name,"raddr") || beginsWith(port_name,"ren") )
        return false;
      if( beginsWith(port_name,"rdata") ) 
        return false; // 
      ILA_ERROR<<"Unknown IO directive in refinement relations:"<<c;
      return true;
    }
    ILA_ERROR<<"Unknown IO directive in refinement relations:"<<c;
    return true;   
  }

} // namespace ilang