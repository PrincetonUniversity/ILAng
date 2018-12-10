/// \file Source for Verilog Verification Target Generation
/// 
// --- Hongce Zhang

#include <iostream>
#include <cmath>
#include <ilang/ila/expr_fuse.h>
#include <ilang/vtarget-out/vtarget_gen.h>

namespace ilang {

//---------------- CONFIGURATIONS -------------------------
#define MAX_CYCLE_CTR 127
  
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

  void VlgVerifTgtGen::ConstructWrapper_add_ila_input() {
    // add ila input
    size_t ila_input_num = instr_ptr->host()->input_num();
    for(size_t input_idx = 0; input_idx < ila_input_num; input_idx ++) {
      auto input_ = instr_ptr->host()->input(input_idx);
      auto & name_= input_->name().str();
      auto width_ = get_width( input_ );

      vlg_wrapper.add_wire (name_, width_);
      vlg_wrapper.add_input(name_, width_);
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
        vlg_wrapper.add_wire (short_name, vlg_sig_info.get_width() );
        // if it is memory data input, feed from memory, not outside
        if ( IN(short_name,io_map) && _idr.isSpecialInputDir(io_map[short_name]) && ! _idr.interfaceDeclare(io_map[short_name]) )
           continue; // do not add input
        vlg_wrapper.add_input(short_name, vlg_sig_info.get_width() );
      } else if(vlg_sig_info.is_output()) {
        ILA_ERROR_IF(  IN(short_name,io_map) && ! _idr.isSpecialInputDir(io_map[short_name]) ) << "Verilog output:" << short_name << " cannot be mapped, treated as **KEEP**";

        vlg_wrapper.add_wire (short_name, get_width() ); // remember to connect later
        // if it is memory data output, address, enable and etc. we don't need to make them wrapper output?
        if ( IN(short_name,io_map) && _idr.isSpecialInputDir(io_map[short_name]) && ! _idr.interfaceDeclare(io_map[short_name]) )
           continue; // do not add input
        vlg_wrapper.add_output(short_name, get_width() );
      } else { ILA_WARN<<short_name<<" is not handled by ConstructWrapper_add_vlg_input_output: unknown IO";  }
    } // for(auto && name_siginfo_pair : vlg_inputs)
  } // ConstructWrapper_wrapper_addinput

  void VlgVerifTgtGen::AddCycleCountMoniter() {
    // find in rf_cond, how many cycles will be needed
    unsigned max_bound = 0;
    auto & instrs = rf_cond["instructions"];
    for (auto && instr : instrs) {
      if(instr["ready bound"]) {
        bound = StrToInt(instr["ready bound"]);
        if (max_bound < bound) max_bound = bound;
      }
    }
    if (max_bound == 0) max_bound = MAX_CYCLE_CTR;

    auto cnt_width = (int) std::ceil( std::log2 ( max_bound + 10 ) );
    vlg_wrapper.add_reg("__CYCLE_CNT__", cnt_width); // by default it will be an output reg
    vlg_wrapper.add_always_stmt("if (rst) __CYCLE_CNT__ <= 0;")
    vlg_wrapper.add_always_stmt("else if ( __CYCLE_CNT__ < " + IntToStr(MAX_CYCLE_CTR+5) + ") __CYCLE_CNT__ <= __CYCLE_CNT__ + 1;");
 
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
