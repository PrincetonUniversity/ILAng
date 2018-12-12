/// \file Source for Interace Directive in Refinement relations in Verilog Verification Target Generation
// --- Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/directive.h>

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
  bool IntefaceDirectiveRecorder::interfaceDeclareTop(const std::string & c) {
    ILA_ASSERT(isSpecialInputDir(c));
    if(c == "**KEEP**") return true;
    if(c == "**NC**")   return false;
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

  void ConnectModuleInputAddWire(const std::string & short_name, unsigned width)  {
      mod_inst_input_sigs.push_back( {short_name, width} );
      mod_inst_rec.insert( {short_name, std::make_pair({ inf_dir_t::INPUT ,  short_name}) } );
  }

  void ConnectModuleOutputAddWire(const std::string & short_name, unsigned width)  {
      mod_inst_output_sigs.push_back( {short_name, width} );
      mod_inst_rec.insert( {short_name, std::make_pair({ inf_dir_t::OUTPUT ,  short_name}) } );
  }


  /// Return a string used for instantiating
  std::string IntefaceDirectiveRecorder::GetVlgModInstString(void) const {

  }
  /// Add signals to the wrapper_generator
  void IntefaceDirectiveRecorder::VlgAddTopInteface(VerilogGeneratorBase & gen) const {

  }
  /// Used to tell this module about the refinement relations , ... , ila interface checker?
  void IntefaceDirectiveRecorder::RegisterInterface(
    const SignalInfoBase & vlg_sig, 
    const std::string & refstr,
    ila_input_checker_t chk) {

    auto & short_name = vlg_sig.get_signal_name();
    bool is_input     = vlg_sig.is_input();
    bool is_output    = vlg_sig.is_output();
    unsigned width    = vlg_sig.get_width();

    // temporary fix if cannot get its width
    if (width == 0 ) { 
      ILA_WARN << "assuming " << short_name << " has width 1"; 
      width = 1; 
    }
    if (not is_input and not is_output)
      ILA_ERROR << "Implementation bug: I/O direction is unknown for " << short_name ;

    if (is_input and is_output) { 
      ILA_WARN << "not handling inout wire: " << short_name << ", will not be connected"; 
      // nc and skip
      mod_inst_rec.push_back( {short_name, std::make_pair({ inf_dir_t::NC ,  ""}) } );
      return;
    }

    if( refstr == "" ) {
      ILA_WARN << "Verilog I/O:"<<short_name << " is not mentioned in the input mapping";
      // add an KEEP directive
      mod_inst_rec.insert( {short_name, std::make_pair({ inf_dir_t::KEEP ,  short_name}) } );
      if( is_input ) 
        mod_inst_input_sigs.push_back( {short_name, width} );
      else if(is_output)
        mod_inst_output_signs.push_back( {short_name, width} );

      return;
    }

    if ( isSpecialInputDir(refstr) ) {
      ILA_ERROR_IF( ! isSpecialInputDirCompatibleWith(refstr, vlg_sig )) 
        << short_name 
        << " in refinement (special directive) does not match the verilog interface.";

      if (refstr == "**KEEP**") {
        if(is_input)  ConnectModuleInputAddWire ("__VLG_I_" + short_name, width);
        if(is_output) ConnectModuleOutputAddWire("__VLG_O_" + short_name, width);
      } else if (refstr == "**NC**") {
        mod_inst_rec.push_back( {short_name, std::make_pair({ inf_dir_t::NC ,  ""}) } );
      } else if ( refstr == "**SO**" ) {
        ILA_ERROR_IF ( ! is_output ) << "Forcing a non-output signal to be connected as output:" << short_name;
        ConnectModuleOutputAddWire(short_name, width);
      } else if ( refstr ==  "**RESET**" ) {
        mod_inst_rec.insert( {short_name, std::make_pair({ inf_dir_t::RESET ,  "rst"}) } );
      } else if ( refstr == "**CLOCK**" ) {
        mod_inst_rec.insert( {short_name, std::make_pair({ inf_dir_t::CLOCK ,  "clk"}) } );
      } else if ( beginsWith(refstr, "**MEM**") ) {
        // now we need to keep recording it , how many mems mentiond, how many connected
        //1. get the remaining part
        if( refstr.length() <= 7 ) { ILA_ERROR << "Bad mem directive:" << refstr; return; }
        auto dirm = refstr.substr(7); // [7:]
        auto dirv = Split(dirm,".");
        if( dirv.size() < 2 or dirv.size() > 3 )  { ILA_ERROR << "Bad mem directive:" << refstr; return; }
        if( dirv.size() == 2 ) dirv.push_back("0"); // refer to 0 by default
        const auto & ila_mem_name = dirv[0];
        const auto & port = dirv[1];
        unsigned connector_no = StrToInt(dirv[2]);
        // you may need more to put it inside there .
        ..
      } else
        ILA_ERROR << "Ignoring unknown verilog interface directive:" << refstr;

      // decide how to connect and signals to create
      return;
    }

    // exists and not special input directive, connected the name they are given.
    // this name should be an ila-input, maybe we can check 

    if(is_input) {
      // TODO: FIXME: NEED TO CHECK w. ILA
      // ILA_ERROR_IF( refstr is not an ila input )
      ILA_ERROR_IF( not chk(refstr, vlg_sig) ) 
        << "Uncompatible input refinement:" 
        << refstr << "for " << short_name
        << ". Connect anyway. Please check."
      ConnectModuleInputAddWire( "__ILA_I_" + refstr, width);
    }
    if(is_output) {
      ILA_ERROR << "Cannot map output signals to ILA input for :" << refstr << ", left unconnected.";
      mod_inst_rec.push_back( {short_name, std::make_pair({ inf_dir_t::NC ,  ""}) } ); 
    } // ignoring it
    // okay we are done now
  }


  void IntefaceDirectiveRecorder::Clear() {
    mod_inst_rec.clear();
    mod_inst_input_sigs.clear();
    mod_inst_wires.clear();
    mod_inst_output_signs.clear();
    abs_mems.clear();
  }

  // ------------------------------------------------------------------------


  bool StateMappingDirectiveRecorder::isSpecialStateDir(const std::string & c)
  {
    return IntefaceDirectiveRecorder::beginsWith(c,"**"); 
  }

} // namespace ilang