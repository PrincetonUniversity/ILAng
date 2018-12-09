/// \file Source for Verilog Verification Target Generation
/// 
// --- Hongce Zhang

#include <iostream>
#include <ilang/ila/expr_fuse.h>
#include <ilang/vtarget-out/vtarget_gen.h>

namespace ilang {

  VlgVerifTgtGen::VlgVerifTgtGen(
      const std::vector<std::string> & implementation_include_path,
      const std::vector<std::string> & implementation_srcs,
      const std::string              & implementation_top_module,
      const std::string              & refinement_variable_mapping,
      const std::string              & refinement_conditions,
      const std::string              & output_path,
      const InstrPtr                 & instr_ptr,
      const VerilogGenerator::VlgGenConfig& config = VlgGenConfig() 
      ):
  _vlg_impl_include_path(implementation_include_path),
  _vlg_impl_srcs        (implementation_srcs),
  _vlg_impl_top_name    (implementation_top_module),
  _rf_var_map_name      (refinement_variable_mapping),
  _rf_cond_name         (refinement_conditions),
  _output_path          (output_path),
  _instr_ptr            (instr_ptr),
  vlg_wrapper(config, "wrapper"),   // default option
  vlg_ila(config), // configure is only for ila
  vlg_info_ptr(NULL),
  _bad_state(false)
  {
    load_json(_rf_var_map_name, rf_vmap);
    load_json(_rf_cond_name   , rf_cond);

  }

  void VlgVerifTgtGen::GenerateTarget(void) {
    vlg_info_ptr = new VerilogInfo(_vlg_impl_include_path, _vlg_impl_srcs, ???, _vlg_impl_top_name );



    if(vlg_info_ptr) {
      delete vlg_info_ptr;
      vlg_info_ptr = NULL;
    }
  }

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
  bool beginsWith(const std::string & c, const std::string & s) { return c.find(s) == 0;}
  bool isSpecialInputDir(const std::string & c)  { return beginsWith(c,"**"); }

  void VlgVerifTgtGen::ConstructWrapper_add_ila_input() {

  }
  void VlgVerifTgtGen::ConstructWrapper_add_vlg_input() {
    auto vlg_inputs = vlg_info_ptr->get_top_module_io();
    auto & input_map = rf_vmap["input mapping"];
    for(auto && name_siginfo_pair : vlg_inputs) { // for all verilog input, find in rfmap
      auto & short_name = name_siginfo_pair.first.get_signal_name(); // short name
      auto & vlg_sig_info = name_siginfo_pair.second;
      //auto & long_name  = name_siginfo_pair.first.get_hierarchical_name();  // no using it

      // try short name and

      ILA_WARN_IF ( ! IN(short_name, input_map))  << "Verilog input:"<<short_name << " is not mentioned in the input mapping";
      if( IN(short_name,input_map) ) { // check for special cases
        if(input_map[short_name] == "**RESET**") continue;
        if(input_map[short_name] == "**CLOCK**") continue; // do nothing no need to add them
      }


      // check if it is I/O, add wires
      if(vlg_sig_info.is_input()) {
        if ( IN(short_name,input_map) && !isSpecialInputDir(input_map[short_name]) ) {
          // check for ila compatibility
          ..
          continue; // do nothing if you are going to connect something to this input
        }
        .. // if it is memory data input, feed from memory, not outside
        vlg_wrapper.add_input(short_name, vlg_sig_info.get_width() );
        vlg_wrapper.add_wire (short_name, vlg_sig_info.get_width() );
      }
      else if(vlg_sig_info.is_output()) {
        // if it is memory data output, address, enable and etc. we don't need to make them wrapper output?
        vlg_wrapper.add_output(short_name, get_width() );
        vlg_wrapper.add_wire (short_name, get_width() ); // remember to connect later
      }

    }
  } // ConstructWrapper_wrapper_addinput

  void VlgVerifTgtGen::ConstructWrapper(void) {


    // 1. add input
    vlg_wrapper.add_input ("nondet_start", 1);
    vlg_wrapper.add_input ("dummy_reset", 1);
    vlg_wrapper.add_output("allassert", 1);
    // -- find out the inputs
    ConstructWrapper_add_vlg_input();
    ConstructWrapper_add_ila_input();

    // 2. add some monitors (bound cnt)

    // 3. add assumptions

    // 4. add assertions (don't forget to connect allassert) assert property (...); wire ??; assign ?? = ??;

    // 5. add instantiation. 2

    // 6. add helper memory module


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
