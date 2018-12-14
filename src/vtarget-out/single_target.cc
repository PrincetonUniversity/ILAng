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
#define VLG_FALSE "`false"
#define ONLY_INITIAL_INV true

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
  // interface mapping directive
  _idr( instr_ptr == nullptr ? true : false ), // if nullptr, verify inv., reset it
  // state mapping directive
  _sdr(), // currently no
  // verilog info
  vlg_info_ptr(_vlg_info_ptr),
  // variable extractor
  _vext( [this](const std::string &n) -> bool { return TryFindIlaState(n); } ,
         [this](const std::string &n) -> bool { return TryFindIlaInput(n); } ,
         [this](const std::string &n) -> bool { return TryFindVlgState(n); }  ),
  // ref to refmaps
  rf_vmap(_rf_vmap),
  rf_cond(_rf_cond),
  target_type( instr_ptr == nullptr ? 
    target_type_t::INVARIANTS : target_type_t::INSTRUCTIONS ), // whether it is invariant/instructions
  has_flush(false),
  ready_type(ready_type_t::NA)
  _bad_state(false),
   {
    // do nothing
    if (target_type == target_type_t::INSTRUCTIONS) {

      vlg_ila.ExportTopLevelInstr(instr_ptr);
      if( vlg_ila.decodeNames.size() != 1 ) {
        ILA_ERROR << "Implementation bug btw. vlg gen and vtarget-gen";
        _bad_state = true;
      }

      auto & instr = get_current_instruction_rf();
      if ( instr.is_null() ) {
        ILA_ERROR 
          << "No refinement relation is defined for current instruction:"
          << instr_ptr->name().str();
        _bad_state = true;
      }
      if( IN( "flush constraint" ,instr) and instr["flush constraint"]) {
        if ( IN( "pre-flush end" ,instr) and instr["pre-flush end"] and 
             IN( "post-flush end" ,instr) and instr["post-flush end"] )
          has_flush = true; // requiring three items
        else {
          ILA_ERROR << "When using flushing, 'pre-flush end' and 'post-flush end' "
            << "must be specify";
          _bad_state = true;
        }
      }
      if( IN("ready signal", instr) and instr["ready signal"] ) 
        ready_type |= ready_type_t::READY_SIGNAL;
      if( IN("ready bound", instr) and instr["ready bound"] )
        ready_type |= ready_type_t::READY_BOUND;
      if( ready_type == ready_type_t::NA ) {
        ILA_ERROR << "refinement relation for:"<< instr_ptr->name().str()
          << " has to specify a ready condition";
        _bad_state = true;
      }
    }
  } // END of constructor
  
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
      if( state->sort()->is_mem() ) 
        continue; // please ignore memory, they should not be connected this way
      auto width_ = get_width(state_);

      vlg_wrapper.add_wire  ("__ILA_SO_" + name_, width_);
      vlg_wrapper.add_output("__ILA_SO_" + name_, width_); 
      // remember to connect in the instantiation step
    }
  } // ConstructWrapper_add_ila_input

  std::string VlgSglTgtGen::ConstructWrapper_get_ila_module_inst() {

    ILA_ASSERT(vlg_ila.decodeNames.size() == 1) << "Implementation bug: decode condition.";
    vlg_wrapper.add_wire( vlg_ila.validName , 1 ); 
    vlg_wrapper.add_wire( vlg_ila.decodeNames[0], 1 );

    // .. record function

    auto retStr = vlg_ila.moduleName + " " + _vlg_impl_top_name + " (\n";

    // handle input
    for(auto && w : vlg_ila.inputs) {
      // deal w. clock
      if(w.first == vlg_ila.clkName) // .clk(clk)
        retStr += "   ." + vlg_ila.clkName + "(" + vlg_wrapper.clkName +"),\n";
      else if (w.first == vlg_ila.rstName) // .rst(rst) -- this does not need to be changed
        retStr += "   ." + vlg_ila.rstName + "(" + vlg_wrapper.rstName +"),\n"; // no init anyway!
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
  } // ConstructWrapper_get_ila_module_inst()

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
  } // ConstructWrapper_add_vlg_input_output

  void VlgSglTgtGen::ConstructWrapper_add_cycle_count_moniter() {
    // find in rf_cond, how many cycles will be needed
    unsigned max_bound = 0;

    auto & instr = get_current_instruction_rf();

    if(! instr.is_null() and instr["ready bound"]) 
      max_bound = StrToInt(instr["ready bound"]);
    else
      max_bound = MAX_CYCLE_CTR;

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

    // remember to generate
    // __RESETED__
    // __ISSUE__ == start condition (if no flush, issue == true?)
    // __IEND__ == ( end condition ) &&  STARTED
    // __ENDFLUSH__ == (end flush condition ) && ENDED
    // flush : !( __ISSUE__ ? || __START__ || __STARTED__ ) |-> flush 
  } // ConstructWrapper_add_cycle_count_moniter

  void VlgSglTgtGen::ConstructWrapper_generate_header() {
    vlg_wrapper.add_preheader("\n`define true  1\n");
    vlg_wrapper.add_preheader("\n`define false 0\n");
  } // ConstructWrapper_generate_header

  // for special memory, we don't need to do anything?
  void VlgSglTgtGen::ConstructWrapper_add_varmap_assumptions() {
    ILA_ASSERT(target_type == target_type_t::INSTRUCTIONS) <<
      "Implementation bug: vmap assumpt should only be used when verifying instructions.";
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
  } // ConstructWrapper_add_varmap_assumptions

  // for memory, we need to assert new data match and ?
  // 
  void VlgSglTgtGen::ConstructWrapper_add_varmap_assertions() {
    ILA_ASSERT(target_type == target_type_t::INSTRUCTIONS) <<
      "Implementation bug: vmap assts should only be used when verifying instructions.";
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
  } // ConstructWrapper_add_varmap_assertions


  void VlgSglTgtGen::ConstructWrapper_add_inv_assumptions() {
    ILA_ASSERT(target_type == target_type_t::INSTRUCTIONS) <<
      "Implementation bug: inv assumpt should only be used when verifying instructions.";
    if ( not rf_cond["global invariants"] ) return; // no invariants to add
    if ( not rf_cond["global invariants"].is_array() ) { 
      ILA_ERROR << "'global invariants' field in refinement relation has to be a JSON array."
      return;
    }
    for( auto & cond :  rf_cond["global invariants"] ) {
      auto new_cond = ReplExpr(cond.get<std::string>(), true);
      auto precondition
      if(ONLY_INITIAL_INV)
        precondition = has_flush ? "~ __RESETED__ || " : "~ __START__ || " ;
      else
        precondition = ""; // always assme no matter what

      add_an_assumption( precondition + "(" + new_cond + ")" );
    }
  } // ConstructWrapper_add_inv_assumptions

  // 
  // should not have the flush condition set -- > because this should only be called when target is invariants

  void VlgSglTgtGen::ConstructWrapper_add_inv_assertions() {
    ILA_ASSERT(target_type == target_type_t::INVARIANTS) <<
      "Implementation bug: should only be used when verifying invariants";
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

  void VlgSglTgtGen::ConstructWrapper_add_additional_mapping_control() {
    if(IN("mapping control", rf_vmap)) {
      for(auto && c : rf_vmap["mapping control"]) {
        add_an_assumption( ReplExpr(c.get<std::string>()) );
      }
    }
  } // ConstructWrapper_add_additional_mapping_control

  void VlgSglTgtGen::ConstructWrapper_add_condition_signals()  {
    // TODO 
    // remember to generate
    // __ISSUE__ == start condition (if no flush, issue == true?)
    // __IEND__ == ( end condition ) &&  STARTED
    // __ENDFLUSH__ == (end flush condition ) && ENDED
    // flush : !( __ISSUE__ ? || __START__ || __STARTED__ ) |-> flush 

    if (target_type == target_type_t::INVARIANTS)
      return; 
      // we don't need additional signals, just make reset drives the design

    // find the instruction 
    auto & instr = get_current_instruction_rf();
    ILA_ASSERT ( ! instr.is_null() ) ;

    // __IEND__
    std::string iend_cond = VLG_FALSE;
    if(ready_type & ready_type_t::READY_SIGNAL) {
      if( instr["ready signal"].is_string() ) {
        iend_cond += "|| (" + ReplExpr(instr["ready signal"].get<std::string>(), true) + ")"; // force vlg
      } else if (instr["ready signal"].is_array()) {
        for(auto && cond : instr["ready signal"] )
          if (cond.is_string())
            iend_cond += " || (" + ReplExpr(cond.get<std::string>()) + ")";
          else
            ILA_ERROR << "ready signal field of instruction: " 
              << instr_ptr->name().str() 
              << " has to be string or array or string";
      } else 
        ILA_ERROR << "ready signal field of instruction: " 
          << instr_ptr->name().str() 
          << " has to be string or array or string";
    }
    if(ready_type & ready_type_t::READY_BOUND) { // can be both applied
      if ( instr["ready bound"].is_number_integer() ) {
        int bound = instr["ready bound"].get<int>();
        if( bound > 0 ) {
          // okay now we enforce the bound
          iend_cond += "|| ( __CYCLE_CNT__ == " + IntToStr(bound) + ")";
        }
        else
          ILA_ERROR << "ready bound field of instruction: " 
          << instr_ptr->name().str() 
          << " has to a positive integer";
      }
      else
        ILA_ERROR << "ready bound field of instruction: " 
          << instr_ptr->name().str() 
          << " has to a positive integer";
    } // end of ready bound/condition
    vlg_wrapper.add_wire( "__IEND__" , 1 );
    vlg_wrapper.add_assign_stmt("__IEND__" , "(" + iend_cond + ") && __STARTED__");
    
    add_an_assumption( "~ __ISSUE__ || (" + vlg_ila.decodeNames[0] + ")" ); // __ISSUE__ |=> decode
    add_an_assumption( "~ __ISSUE__ || (" + vlg_ila.validName + ")" ); // __ISSUE__ |=> decode

    if(has_flush) {
      ILA_ASSERT( instr["pre-flush end"] and instr["post-flush end"] ); // there has to be something

      auto issue_cond = "(" + ReplExpr( instr["pre-flush end"].get<std::string>() ) + ") && __RESETED__";
      vlg_wrapper.add_wire("__ISSUE__" , 1);
      vlg_wrapper.add_assign_stmt( "__ISSUE__", issue_cond );
      
      auto finish_cond = "(" + ReplExpr( instr["post-flush end"].get<std::string>() ) + ") && __ENDED__";
      vlg_wrapper.add_wire("__ENDFLUSH__" , 1);
      vlg_wrapper.add_assign_stmt( "__ENDFLUSH__", finish_cond );

      // enforcing flush constraints
      std::string flush_enforcement = VLG_TRUE;
      if( instr["flush constraints"].is_string() ) {
        flush_enforcement += "&& (" + ReplExpr(instr["flush constraints"].get<std::string>()) + ")"; 
      } else if (instr["flush constraints"].is_array() )  {
        for (auto && c: instr["flush constraints"])
          if(c.is_string())
            flush_enforcement += "&& (" + ReplExpr(c.get<std::string>()) + ")"; 
          else
            ILA_ERROR << "flush constraint field of instruction:" << instr_ptr->name().str()
              << " must be a string or an array of string.";
      } else 
        ILA_ERROR << "flush constraint field of instruction:" << instr_ptr->name().str()
          << " must be string or array of string.";

      add_an_assumption ("~ ( __RESETED__ && ~ ( __START__  || __STARTED__ ) ) || (" + flush_enforcement + ")");
      add_an_assumption ("~ ( __ENDED__ ) || (" + flush_enforcement + ")");

    } else {
      vlg_wrapper.add_wire("__ISSUE__" , 1);
      vlg_wrapper.add_assign_stmt( "__ISSUE__", VLG_TRUE ); // issue ASAP
      // start decode -- issue enforce (e.g. valid, input)
    } // end of no flush
  }

  void VlgSglTgtGen::ConstructWrapper_add_module_instantiation() {
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

  void VlgSglTgtGen::ConstructWrapper_add_helper_memory() {
    // TODO ..
  }

  // for invariants or for instruction
  void VlgSglTgtGen::ConstructWrapper() {
    ILA_ASSERT(
      target_type == target_type_t::INVARIANTS ||
      target_type == target_type_t::INSTRUCTIONS );

    // 0. The headers you may need to have
    ConstructWrapper_generate_header();

    // 1. add input
    if(target_type == target_type_t::INVARIANTS)
      vlg_wrapper.add_input ("dummy_reset", 1);

    // -- find out the inputs
    ConstructWrapper_add_vlg_input();
    ConstructWrapper_add_ila_input();

    // 2. add some monitors (bound cnt)
    ConstructWrapper_add_cycle_count_moniter();

    // 3. add assumptions & assertions
    if(target_type == target_type_t::INSTRUCTIONS) {
      ConstructWrapper_add_varmap_assumptions();
      ConstructWrapper_add_varmap_assertions();
      ConstructWrapper_add_inv_assumptions();
    }
    else if (target_type == target_type_t::INVARIANTS) {
      ConstructWrapper_add_inv_assertions();
    }
    // 4. additional mapping if any 
    ConstructWrapper_add_additional_mapping_control();

    // if invariants, will do nothing
    ConstructWrapper_add_condition_signals();

    // 5. module instantiation
    ConstructWrapper_add_module_instantiation();

    // 6. helper memory
    ConstructWrapper_add_helper_memory();

    // 7. uni-functions
    ConstructWrapper_add_uf_buffers();
    

  }

} // namespace ilang
