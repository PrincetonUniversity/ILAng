/// \file Source for Verilog Verification Target Generation
/// 
// --- Hongce Zhang

#include <iostream>
#include <cmath>
#include <ilang/ila/expr_fuse.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>

namespace ilang {

//---------------- CONFIGURATIONS -------------------------
#define MAX_CYCLE_CTR 127
#define VLG_TRUE "`true"

.. remember to add this to header
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
  vlg_ila(VerilogGenerator::VlgGenConfig(vlg_gen_config, true, funcOption::External )  ), // configure is only for ila
  vlg_info_ptr(NULL),
  _bad_state(false)
  {
    load_json(_rf_var_map_name, rf_vmap);
    load_json(_rf_cond_name   , rf_cond);
    set_module_instantiation_name();
  }


  std::string VlgVerifTgtGen::new_mapping_id() {
    return std::string("__m") + IntToStr(mapping_counter++) + "__";
  }
  std::string VlgVerifTgtGen::new_property_id(); {
    return std::string("__p") + IntToStr(mapping_counter++) + "__";
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

  const ExprPtr VlgVerifTgtGen::IlaGetState(const std::string &sname) {
    auto ptr = _instr_ptr->host()->state(sname);
    ILA_ERROR_IF(ptr == nullptr) << "Cannot find state:"<<sname<<" in ila:"<<_instr_ptr->host()->name().str();
    return ptr;
  }
  const ExprPtr VlgVerifTgtGen::IlaGetInput(const std::string &sname) {
    auto ptr = _instr_ptr->host()->input(sname);
    ILA_ERROR_IF(ptr == nullptr) << "Cannot find state:"<<sname<<" in ila:"<<_instr_ptr->host()->name().str();
    return ptr;
  }

  // static function
  unsigned VlgVerifTgtGen::TypeMatched(const ExprPtr & ila_var, const VerilogInfo & vlg_var) {
    auto ila_sort = ila_var->sort();
    if( vlg_var.get_width() == 0 ) {
      ILA_ERROR<<"Cannot determine type-match for vlg signal"<<vlg_var.get_hierarchical_name();
      return 0;
    }
    if(ila_sort->is_bool()) {
      if( vlg_var.get_width() == 1 ) return 1;
      /*else*/ return 0; /*mismatch*/
    } /*else*/ 
    if(ila_sort->is_bv()) {
      if( ila_sort->bit_width() == vlg_var.get_width() ) return vlg_var.get_width();
      /*else*/ return 0; /*mismatch*/
    } /*else*/ 
    if (ila_sort->is_mem()) {
      if( ila_sort->data_width() == vlg_var.get_width() ) return vlg_var.get_width();
      /*else*/ return 0; /*mismatch*/
    }
    ILA_ASSERT(false)<<"Implementation bug: unknown sort";
    return 0;
  }
  // static function
  unsigned VlgVerifTgtGen::get_width( const ExprPtr& n ) {
    ILA_WARN_IF(n->sort()->is_mem()) << "Using data width for "<<n->name().str();
    return VerilogGenerator::get_width(n);
  }

  // static function
  bool isEqu(const std::string & c)  { return (c.find("=") != std::string::npos); }

  void VlgVerifTgtGen::ConstructWrapper_add_ila_input() {
    // add ila input
    size_t ila_input_num = instr_ptr->host()->input_num();
    for(size_t input_idx = 0; input_idx < ila_input_num; input_idx ++) {
      const auto & input_ = instr_ptr->host()->input(input_idx);
      const auto & name_  = input_->name().str();
      auto width_   = get_width( input_ );

      vlg_wrapper.add_wire (name_, width_);
      vlg_wrapper.add_input(name_, width_);
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
    auto vlg_inputs = vlg_info_ptr->get_top_module_io();
    auto & io_map = rf_vmap["interface mapping"];
    for(auto && name_siginfo_pair : vlg_inputs) { // for all verilog input, find in rfmap
      auto & short_name = name_siginfo_pair.first.get_signal_name(); // short name
      auto & vlg_sig_info = name_siginfo_pair.second;
      //auto & long_name  = name_siginfo_pair.first.get_hierarchical_name();  // no using it
      // try short name and warn if it is not specified
      ILA_WARN_IF ( ! IN(short_name, io_map))  << "Verilog input:"<<short_name << " is not mentioned in the input mapping";

      // Check if directive is compatible w read io
      if ( IN(short_name,io_map) && _idr.isSpecialInputDir(io_map[short_name]) ) 
        ILA_ERROR_IF( ! _idr.isSpecialInputDirCompatibleWith(io_map[short_name], vlg_sig_info )) << short_name << " in refinement does not match the verilog interface.";

      // check if it is I/O, add wires
      if(vlg_sig_info.is_input()) {

        if ( IN(short_name,io_map) && !_idr.isSpecialInputDir(io_map[short_name]) ) {
          // check for ila compatibility
          ILA_ERROR_IF( TypeMatched(IlaGetInput(io_map[short_name]), vlg_sig_info) == 0 ) << "Verilog input:"<< short_name << " is not compatible with ILA input:"<< io_map[short_name];
          continue; // do nothing if you are going to connect something to this input
        }
        
        // if it is memory data input, feed from memory, not outside
        if ( IN(short_name,io_map) && _idr.isSpecialInputDir(io_map[short_name]) && ! _idr.interfaceDeclare(io_map[short_name]) ) {
          vlg_wrapper.add_wire (short_name, vlg_sig_info.get_width(), true ); // keep added 
          continue; // do not add input
        }
        vlg_wrapper.add_wire (short_name, vlg_sig_info.get_width(), false ); 
        vlg_wrapper.add_input(short_name, vlg_sig_info.get_width() );
      } else if(vlg_sig_info.is_output()) {
        ILA_ERROR_IF(  IN(short_name,io_map) && ! _idr.isSpecialInputDir(io_map[short_name]) ) << "Verilog output:" << short_name << " cannot be mapped, treated as **KEEP**";

        // if it is memory data output, address, enable and etc. we don't need to make them wrapper output?
        if ( IN(short_name,io_map) && _idr.isSpecialInputDir(io_map[short_name]) && ! _idr.interfaceDeclare(io_map[short_name]) ) {
          vlg_wrapper.add_wire (short_name, get_width() , true); continue; // do not add input
        }
        vlg_wrapper.add_wire (short_name, get_width() , false); // remember to connect later
        vlg_wrapper.add_output(short_name, get_width() );
      } else { ILA_WARN<<short_name<<" is not handled by ConstructWrapper_add_vlg_input_output: unknown IO";  }
    } // for(auto && name_siginfo_pair : vlg_inputs)
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
    vlg_wrapper.add_always_stmt("else if ( ( __ISSUE__ || __START__ || __STARTED__ ) &&  __CYCLE_CNT__ < " + IntToStr(MAX_CYCLE_CTR+5) + ") __CYCLE_CNT__ <= __CYCLE_CNT__ + 1;");
    
    vlg_wrapper.add_reg("__START__", 1);
    vlg_wrapper.add_always_stmt("if (rst) __START__ <= 0;");
    vlg_wrapper.add_always_stmt("else if (__ISSUE__) __START__ <= 1;");
    vlg_wrapper.add_always_stmt("else if (__START__ || __STARTED__) __START__ <= 0;");

    vlg_wrapper.add_reg("__STARTED__", 1);
    vlg_wrapper.add_always_stmt("if (rst) __STARTED__ <= 0;");
    vlg_wrapper.add_always_stmt("else if (__START__) __STARTED__ <= 1;"); // will never return to zero

    vlg_wrapper.add_reg("__RESETED__", 1);
    vlg_wrapper.add_always_stmt("if (rst) __RESETED__ <= 1;");

    .. // remember to generate
    // __RESETED__
    // __ISSUE__ == start condition 
    // __IEND__ == end condition
    // __ENDFLUSH__ 
    // flush : !( __ISSUE__ || __START__ || __STARTED__ ) |-> flush 
  }

  // will create new variables "m?" and return it
  // 1. "ila-state":"**MEM**.?"
  // 2. "ila-state":"statename"
  // 3. "ila-state":[ "cond&map" ]
  // 4. "ila-state":[ {"cond":,"map":}, ] 

  std::string VlgVerifTgtGen::PerStateMap(const std::string & ila_state_name, const std::string & vlg_st_name ) {
    auto ila_state = IlaGetState(ila_state_name); 
    if (!ila_state) return VLG_TRUE;
    if ( ila_state->sort()->is_mem() ) { ILA_ERROR << "Please use **MEM**.? directive for memory state matching"; return VLG_TRUE; }
    // check for state match
    std::string vlg_state_name = vlg_st_name;
    if (vlg_state_name.find(".") == std::string::npos )  { 
      vlg_state_name = _vlg_mod_inst_name + "." + vlg_state_name ; } // auto-add module name
    auto vlg_sig_info = vlg_info_ptr->get_signal( vlg_state_name )
    ILA_ERROR_IF( !TypeMatched(ila_state, vlg_sig_info ) ) << "ila state:" << ila_state_name <<" has mismatched type w. verilog signal:" << vlg_state_name;
    // add signal
    std::string map_sig = new_mapping_id();
    vlg_wrapper.add_wire(map_sig, 1);
    vlg_wrapper.add_assign(..);
    return map_sig;
  }

  std::string VlgVerifTgtGen::GetStateVarMapExpr(const std::string & ila_state_name) {
    auto & m = rf_vmap[ila_state_name];
    if( m.is_string() ) {
      if ( _sdr.isSpecialStateDir() ) {
        ILA_ASSERT(false) <<"FIXME: not implemented."; .. 
      } else { 
        // return the mapping variable 
        return PerStateMap(ila_state_name, m);
      }
    } /* else */
    if( m.is_array() ) { // array of string or array of object/array
    }// array 
  }

  void VlgVerifTgtGen::AddAssumptions(void) {

  }

  void VlgVerifTgtGen::AddAssertions(void) {
    
  }

  void VlgVerifTgtGen::AddModuleInstantiation(void) {
    
  }

  void VlgVerifTgtGen::AddHelperMemory(void) {
    
  }

  void VlgVerifTgtGen::ConstructWrapper(void) {


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

  bool VlgVerifTgtGen::bad_state_return(void) {
    ILA_ERROR_IF(_bad_state) <<"VlgVerifTgtGen is in a bad state, cannot proceed.";
    return _bad_state;
  }

  void VlgVerifTgtGen::load_json(const std::string & fname, json & j) {
    std::ifstream fin(fname);
    if(!fin.is_open() ) {
      ILA_ERROR << "Cannot read from file:"<<fname;
      _bad_state = true;
      return;
    }
    fname >> j;
  }

}; // namespace ilang
