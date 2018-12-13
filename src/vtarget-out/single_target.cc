/// \file Source for Verilog Verification Targets Generation (single target)
/// 
// --- Hongce Zhang


#include <ilang/util/log.h>
#include <ilang/ila/expr_fuse.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/gen_util.h>

#include <iostream>
#include <cmath>

namespace ilang {

// ------------------------------ CONFIGURATIONS --------------------------------- //
	
#define MAX_CYCLE_CTR 127
#define VLG_TRUE "`true"

// ------------------------------ VlgSglTgtGen --------------------------------- //

VlgSglTgtGen::VlgSglTgtGen(
      const std::string              & output_path, // will be a sub directory of the output_path of its parent
      const InstrPtr                 & instr_ptr, // which could be an empty pointer, and it will be used to verify invariants
      const VerilogGenerator::VlgGenConfig & config,
      nlohmann::json                 & _rf_vmap,
      nlohmann::json                 & _rf_cond,
      VerilogInfo                    * _vlg_info_ptr,
      const std::string              & vlg_mod_inst_name,
      const std::string              & ila_mod_inst_name
    ) : 
  _output_path(output_path), _instr_ptr(instr_ptr),
  _vlg_mod_inst_name(vlg_mod_inst_name),
  _ila_mod_inst_name(ila_mod_inst_name),
  // default option on wrapper
  vlg_wrapper(VerilogGenerator::VlgGenConfig(), "wrapper"),   
  // use given, except for core options
  vlg_ila(VerilogGenerator::VlgGenConfig(vlg_gen_config, true, funcOption::External, true )  ), 
  // verilog info
  vlg_info_ptr(_vlg_info_ptr),
  // variable extractor
  _vext( [this](const std::string &n) -> bool { return TryFindIlaState(n); } , 
         [this](const std::string &n) -> bool { return TryFindVlgState(n); } ),
  // ref to refmaps
  rf_vmap(_rf_vmap),
  rf_cond(_rf_cond) {
    // do nothing
  }
  
  void VlgSglTgtGen::ConstructWrapper_add_ila_input() {
    // add ila input
    size_t ila_input_num = instr_ptr->host()->input_num();
    for(size_t input_idx = 0; input_idx < ila_input_num; input_idx ++) {
      const auto & input_ = instr_ptr->host()->input(input_idx);
      const auto & name_  = input_->name().str();
      auto width_   = get_width( input_ );

      vlg_wrapper.add_wire ( "__ILA_I_" + name_, width_);
      vlg_wrapper.add_input( "__ILA_I_" + name_, width_);
    }
    // remember to add ila_outputs (reg)
    size_t ila_state_num = instr_ptr->host()->state_num();
    for(size_t state_idx = 0; state_idx < ila_state_num; ++ state_idx) {
      const auto & state_ = instr_ptr->host()->state(state_idx);
      const auto & name_  = state->name().str();
      auto width_ = get_width(state_);

      vlg_wrapper.add_wire  ("__ILA_SO_" + name_, width_);
      vlg_wrapper.add_output("__ILA_SO_" + name_, width_); 
      .. // remember to connect in the instantiation step

    }

  std::string VlgSglTgtGen::ConstructWrapper_get_ila_module_inst() {

    ILA_ASSERT(vlg_ila.decodeNames.size() == 1) << "Implementation bug: decode condition.";
    vlg_wrapper.add_wire( vlg_ila.validName , 1 ); 
    vlg_wrapper.add_wire( vlg_ila.decodeNames[0], 1 );

    .. assume valid
    .. assume decode
    .. record function

    auto retStr = vlg_ila.moduleName + " " + _vlg_impl_top_name + " (\n";
    retStr += "   ." + vlg_ila.clkName + "(" + vlg_wrapper.clkName +"),\n";
    retStr += "   ." + vlg_ila.rstName + "(" + vlg_wrapper.rstName +"),\n";
    retStr += "   ." + vlg_ila.validName + "(" + vlg_ila.validName +"),\n";

    // handle input
    for(auto && w : vlg_ila.inputs) {
      // deal w. clock
      if(w.first == vlg_ila.clkName) 
        retStr += "   ." + vlg_ila.clkName + "(" + vlg_wrapper.clkName +"),\n";
      else if (w.first == vlg_ila.rstName)
        retStr += "   ." + vlg_ila.rstName + "(" + vlg_wrapper.rstName +"),\n";
      else
        retStr += "   ." + w.first + "(__ILA_I_" +  w.first +"),\n";
    }

    // TODO:: FUnction here !
    // handle output
    for(auto && w : vlg_ila.outputs) {
      // deal w. valid and decode
      if (w.first == vlg_ila.decodeNames[0])
        retStr += "   ." + vlg_ila.decodeNames[0] + "(" + vlg_ila.decodeNames[0] +"),\n";
      else if (w.first == vlg_ila.validName)
        retStr += "   ." + vlg_ila.validName + "(" + vlg_ila.validName +"),\n";
      else 
        retStr += "   ." + w.first + "(__ILA_I_" +  w.first +"),\n";
    }
    // handle memory io - use internal storage for this purpose
    for( auto && ila_name_rport_pair : vlg_ila.ila_rports) {
      const auto & ila_name = ila_name_rport_pair.first;
      const auto & rports   = ila_name_rport_pair.second;
      const auto adw = GetMemInfo(ila_name);
      auto aw = adw.first; auto dw = adw.second; // address/data width
      ILA_ASSERT(aw > 0 and dw > 0) <<"Implementation bug: unable to find mem:"<<ila_name;

      for(auto && rport : rports) {
        auto no = rport.first; // is the num
        auto port = rport.second; // is the port
        auto rdw = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_rdata";
        auto raw = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_raddr";
        // auto rew = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_ren"; no need, r_en is the start signal

        vlg_wrapper.add_wire( rdw, dw );
        vlg_wrapper.add_wire( raw, aw );

        retStr += "   ." + port.rdata + "(" + rdw + "),\n";
        retStr += "   ." + port.raddr + "(" + raw + "),\n";

      } // for rport
    } // for ila_rports

    for( auto && ila_name_wport_pair : vlg_ila.ila_wports) {
      const auto & ila_name = ila_name_wport_pair.first;
      const auto & wports   = ila_name_wport_pair.second;
      const auto adw = GetMemInfo(ila_name);
      auto aw = adw.first; auto dw = adw.second; // address/data width
      ILA_ASSERT(aw > 0 and dw > 0) <<"Implementation bug: unable to find mem:"<<ila_name;

      for(auto && wport : wports) {
        auto no = wport.first; // is the num
        auto port = wport.second; // is the port
        auto wdw = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_wdata";
        auto waw = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_waddr";
        auto wew = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_wen"; 

        vlg_wrapper.add_wire( wdw, dw );
        vlg_wrapper.add_wire( wdw, aw );
        vlg_wrapper.add_wire( wew, 1 );

        retStr += "   ." + port.wdata + "(" + wdw + "),\n";
        retStr += "   ." + port.waddr + "(" + waw + "),\n";
        retStr += "   ." + port.wen + "(" + wew + "),\n";

      } // for wport
    } // for ila_wports

    // handle state-output
    auto sep;
    for(auto && r: vlg_ila.regs) {
      retStr += sep + "   ." + r.first + "(__ILA_SO_" + w.first + ")";
      sep = ",\n";
    }
    retStr += "\n);"
  }


  } // ConstructWrapper_add_ila_input()

  void VlgSglTgtGen::ConstructWrapper_add_vlg_input_output() {
    // clear the old record, if any
    _idr.Clear();

    auto vlg_inputs = vlg_info_ptr->get_top_module_io();
    auto & io_map = rf_vmap["interface mapping"];
    for(auto && name_siginfo_pair : vlg_inputs) { 
      std::string refstr =  IN(name_signal.first , io_map) ? io_map[name_signal.first].get<std::string>() : "";
      _idr.RegisterInterface( name_siginfo_pair.second, refstr,
        // Verifier_compatible_w_ila_input
        [this] (const std::string &ila_name, const SignalInfoBase & vlg_sig_info) -> bool {
          return TypeMatched(IlaGetInput(ila_name), vlg_sig_info) != 0; } ,
        // Verifier_get_ila_mem_info
        [this] (const std::string &ila_mem_name) -> std::pair<unsigned,unsigned> {
          return GetMemInfo(ila_mem_name);  }
         ); // end of function call: RegisterInterface
    }
  } // ConstructWrapper_wrapper_addinput

  void VlgSglTgtGen::ConstructWrapper_add_cycle_count_moniter() {
    // find in rf_cond, how many cycles will be needed
    unsigned max_bound = 0;
    auto & instrs = rf_cond["instructions"];
    for (auto && instr : instrs) {
      if(instr["instruction"] != instr_ptr->name().str() ) continue; // not this entry
      if(instr["ready bound"]) {
        bound = StrToInt(instr["ready bound"]);
        if (max_bound < bound) max_bound = bound;
      }
    }
    if (max_bound == 0) max_bound = MAX_CYCLE_CTR;

    auto cnt_width = (int) std::ceil( std::log2 ( max_bound + 10 ) );
    vlg_wrapper.add_reg("__CYCLE_CNT__", cnt_width); // by default it will be an output reg
    vlg_wrapper.add_always_stmt("if (rst) __CYCLE_CNT__ <= 0;")
    vlg_wrapper.add_always_stmt("else if ( ( __START__ || __STARTED__ ) &&  __CYCLE_CNT__ < " + IntToStr(MAX_CYCLE_CTR+5) + ") __CYCLE_CNT__ <= __CYCLE_CNT__ + 1;");
    
    vlg_wrapper.add_reg("__START__", 1);
    vlg_wrapper.add_always_stmt("if (rst) __START__ <= 0;");
    vlg_wrapper.add_always_stmt("else if (__ISSUE__) __START__ <= 1;");
    vlg_wrapper.add_always_stmt("else if (__START__ || __STARTED__) __START__ <= 0;");

    vlg_wrapper.add_reg("__STARTED__", 1);
    vlg_wrapper.add_always_stmt("if (rst) __STARTED__ <= 0;");
    vlg_wrapper.add_always_stmt("else if (__START__) __STARTED__ <= 1;"); // will never return to zero
    
    vlg_wrapper.add_reg("__ENDED__", 1);
    vlg_wrapper.add_always_stmt("if (rst) __ENDED__ <= 0;");
    vlg_wrapper.add_always_stmt("else if (__IEND__) __ENDED__ <= 1;"); // will never return to zero

    vlg_wrapper.add_reg("__RESETED__", 1);
    vlg_wrapper.add_always_stmt("if (rst) __RESETED__ <= 1;");

    .. // remember to generate
    // __RESETED__
    // __ISSUE__ == start condition (if no flush, issue == true?)
    // __IEND__ == ( end condition ) &&  STARTED
    // __ENDFLUSH__ == (end flush condition ) && ENDED
    // flush : !( __ISSUE__ ? || __START__ || __STARTED__ ) |-> flush 
  }

  void VlgSglTgtGen::ConstructWrapper_generate_header() {
    vlg_wrapper.add_preheader("\n`define \"true\"  1\n");
  }

  // for special memory, we don't need to do anything?
  void VlgSglTgtGen::ConstructWrapper_add_varmap_assumptions() {
    std::set<std::string> ila_state_names;

    for ( size_t state_idx = 0; state_idx < instr_ptr->host()->state_num() ; ++ state_idx )
      ila_state_names.insert( instr_ptr->host()->state(state_idx)->name().str() );

    for ( auto & i : rf_vmap ) {
      auto sname = i.key().get<std::string>();
      if( not IN(sname, ila_state_names) )  {
        ILA_ERROR << sname << " is not a state of the ILA:" << instr_ptr->host()->name().str();
        continue;
      }
      ila_state_names.erase(sname);
      // ISSUE ==> vmap
      add_an_assumption( "~ __START__ || " +"(" + GetStateVarMapExpr(sname, i.value()) +")" );
    }
    // check for unmapped states
    if( not ila_state_names.empty() ) {
      ILA_ERROR<<"Refinement relation: missing state mapping for the following states:";
      for (auto && sn : ila_state_names)
        ILA_ERROR<<"  "<<sn;
    }
  }

  // for memory, we need to assert new data match and ?
  // 
  void VlgSglTgtGen::ConstructWrapper_add_varmap_assertions(bool has_flush) {
    std::set<std::string> ila_state_names;

    for ( size_t state_idx = 0; state_idx < instr_ptr->host()->state_num() ; ++ state_idx )
      ila_state_names.insert( instr_ptr->host()->state(state_idx)->name().str() );

    for ( auto & i : rf_vmap ) {
      auto sname = i.key().get<std::string>();
      if( not IN(sname, ila_state_names) )  {
        ILA_ERROR << sname << " is not a state of the ILA:" << instr_ptr->host()->name().str();
        continue;
      }
      ila_state_names.erase(sname);
      // ISSUE ==> vmap
      auto precondition = has_flush ? "~ __ENDFLUSH__ || " : "~ __IEND__ || " ;
      add_an_assertion( precondition  +"(" + GetStateVarMapExpr(sname, i.value()) +")" );
    }
  }


  void VlgSglTgtGen::ConstructWrapper_add_inv_assumptions(bool has_flush) {
    if ( not rf_cond["global invariants"] ) return; // no invariants to add
    if ( not rf_cond["global invariants"].is_array() ) { 
      ILA_ERROR << "'global invariants' field in refinement relation has to be a JSON array."
      return;
    }
    for( auto & cond :  rf_cond["global invariants"] ) {
      auto new_cond = ReplExpr(cond.get<std::string>(), true);
      auto precondition = has_flush ? "~ __RESETED__ || " : "~ __START__ || " ;
      add_an_assumption( precondition + "(" + new_cond + ")" );
    }
  }

  // 
  // should not have the flush condition set!
  void VlgSglTgtGen::ConstructWrapper_add_inv_assertions(void) {
    if ( not rf_cond["global invariants"] ) return; // no invariants to add
    if ( not rf_cond["global invariants"].is_array() ) { 
      ILA_ERROR << "'global invariants' field in refinement relation has to be a JSON array."
      return;
    }
    for( auto & cond :  rf_cond["global invariants"] ) {
      auto new_cond = ReplExpr(cond.get<std::string>(), true); // force vlg state
      add_an_assertion( "(" + new_cond + ")" );
    }
  }

  void VlgSglTgtGen::ConstructWrapper_add_additional_mapping_control(void) {
    ..
  } // AddAdditionalMappingControl

  void VlgSglTgtGen::ConstructWrapper_add_condition_signals(void)  {
    // TODO 
  }

  void VlgSglTgtGen::ConstructWrapper_add_module_instantiation(void) {
    // instantiate ila module
    auto ila_mod_inst = ConstructWrapper_get_ila_module_inst;
    vlg_wrapper.add_stmt ( ila_mod_inst ); 

    // instantiate verilog module
    std::string verilog_inst_str = 
      vlg_info_ptr->get_top_module_name() 
      + " " + _vlg_mod_inst_name + "(\n";

    _idr.VlgAddTopInteface(vlg_wrapper);
    verilog_inst_str +=
       _idr.GetVlgModInstString(vlg_wrapper);
    verilog_inst_str += ");"

    vlg_wrapper.add_stmt ( verilog_inst_str );
  }

  void VlgSglTgtGen::ConstructWrapper_add_helper_memory(void) {
    // TODO ..
  }

  // for invariants or for instruction
  void VlgSglTgtGen::ConstructWrapper(void) {

    // 0. The headers you may need to have
    GenerateHeader();

    // 1. add input
    vlg_wrapper.add_input ("nondet_start", 1);
    vlg_wrapper.add_input ("dummy_reset", 1);
    vlg_wrapper.add_output("allassert", 1);
    // -- find out the inputs
    ConstructWrapper_add_vlg_input();
    ConstructWrapper_add_ila_input();

    // 2. add some monitors (bound cnt)
    AddCycleCountMoniter();

    // 3. add assumptions
    AddAssumptions();

    // 4. add assertions (don't forget to connect allassert) assert property (...); wire ??; assign ?? = ??;
    AddAssertions();

    // 5. add instantiation. 2
    AddModuleInstantiation();

    // 6. add helper memory module
    AddHelperMemory();

    // 7. additional controls
    AddAdditionalMappingControl();

  }

} // namespace ilang
