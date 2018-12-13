/// \file Source for Verilog Verification Target Generation
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

//---------------- CONFIGURATIONS -------------------------
#define MAX_CYCLE_CTR 127
#define VLG_TRUE "`true"

//---------------- SOURCES -------------------------


  VlgVerifTgtGen::VlgVerifTgtGen(
      const std::vector<std::string> & implementation_include_path,
      const std::vector<std::string> & implementation_srcs,
      const std::string              & implementation_top_module,
      const std::string              & refinement_variable_mapping,
      const std::string              & refinement_conditions,
      const std::string              & output_path,
      const InstrPtr                 & instr_ptr,
      const VerilogGenerator::VlgGenConfig& vlg_gen_config = VlgGenConfig() 
      ):
  _vlg_impl_include_path(implementation_include_path),
  _vlg_impl_srcs        (implementation_srcs),
  _vlg_impl_top_name    (implementation_top_module),
  _rf_var_map_name      (refinement_variable_mapping),
  _rf_cond_name         (refinement_conditions),
  _output_path          (output_path),
  _instr_ptr            (instr_ptr),
  vlg_wrapper(VerilogGenerator::VlgGenConfig(), "wrapper"),   // default option
  vlg_ila(VerilogGenerator::VlgGenConfig(vlg_gen_config, true, funcOption::External, true )  ), // configure is only for ila
  vlg_info_ptr(NULL), // not creating it now, because we don't have the info to do so
  _vext( [this](const std::string &n) -> bool { return TryFindIlaState(n); } , 
         [this](const std::string &n) -> bool { return TryFindVlgState(n); } ),
  _bad_state(false)
  {
    load_json(_rf_var_map_name, rf_vmap);
    load_json(_rf_cond_name   , rf_cond);
    set_module_instantiation_name();
  }



  void VlgVerifTgtGen::GenerateTarget(void) {
    vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs, ???, _vlg_impl_top_name );



    if(vlg_info_ptr) {
      delete vlg_info_ptr;
      vlg_info_ptr = NULL;
    }
  }

  void VlgVerifTgtGen::set_module_instantiation_name() {
    // use the content in the refinement relations to determine the instance name
    auto & model_specified = rf_cond["models"];
    for ( auto && name_description_pair: model_specified ) {
      if(name_description_pair.second == "ILA" ) {

      } else if (name_description_pair.second == "VERILOG") {

      } else ILA_ERROR << "Unknown model specification:"<<name_description_pair.second <<" expect VERILOG or ILA";
    }
    if (_vlg_mod_inst_name == "") {
      ILA_WARN<<"Verilog top module instance name not set, assuming to be VERILOG";
      _vlg_mod_inst_name = "VERILOG";
    }
    if (_ila_mod_inst_name == "") {
      ILA_WARN<<"ILA top module instance name not set, assuming to be ILA";
      _vlg_mod_inst_name = "ILA";      
    }
  } // set_module_instantiation_name

  void VlgVerifTgtGen::ConstructWrapper_add_ila_input() {
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


  } // ConstructWrapper_add_ila_input()

  void VlgVerifTgtGen::ConstructWrapper_add_vlg_input_output() {
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

  void VlgVerifTgtGen::AddCycleCountMoniter() {
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

  void VlgVerifTgtGen::GenerateHeader() {
    vlg_wrapper->add_preheader("\n`define \"true\"  1\n");
  }

  // for special memory, we don't need to do anything?
  void VlgVerifTgtGen::AddVarMapAssumptions() {
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
  void VlgVerifTgtGen::AddVarMapAssertions(bool has_flush) {
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


  void VlgVerifTgtGen::AddInvAssumptions(bool has_flush) {
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
  void VlgVerifTgtGen::AddInvAssertions(void) {
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

  void VlgVerifTgtGen::AddAdditionalMappingControl(void) {

  } // AddAdditionalMappingControl

  void VlgVerifTgtGen::AddModuleInstantiation(void) {
    
  }

  void VlgVerifTgtGen::AddHelperMemory(void) {
    
  }

  void VlgVerifTgtGen::ConstructWrapper(void) {

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

  }

  void VlgVerifTgtGen::ModifyImplVlg(void) {
    // decide mentions and locations
    // read in and write out
  }

  void VlgVerifTgtGen::GenVerilogs(void) {
    // decide mentions and locations
    // read in and write out
  }

  void VlgVerifTgtGen::GenScript(void) {
    // decide mentions and locations
    // read in and write out
  }


}; // namespace ilang
