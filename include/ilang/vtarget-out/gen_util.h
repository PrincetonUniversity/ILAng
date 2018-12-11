/// \file Verilog Target Generation Utilities
/// Should only be included in vtarget_gen_impl.cc
/// Should not be used anywhere else
/// Store some functions that the vtarget_gen_impl.cc
/// needes, but not that important so does not need to
/// go in the same file and make it that long.
// --- Hongce Zhang

#ifndef GEN_UTIL_H__
#define GEN_UTIL_H__

namespace ilang {


std::string VlgVerifTgtGen::new_mapping_id() {
  return std::string("__m") + IntToStr(mapping_counter++) + "__";
}
std::string VlgVerifTgtGen::new_property_id(); {
  return std::string("__p") + IntToStr(mapping_counter++) + "__";
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

bool VlgVerifTgtGen::TryFindIlaState(const std::string &sname) {

}
bool VlgVerifTgtGen::TryFindVlgState(const std::string &sname) {
  
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


// will create new variables "m?" and return it
// 1.  "ila-state":"**MEM**.?"
// 2a. "ila-state":"statename"  --> PerStateMap
// 2b. "ila-state":"(cond)&map"   --> PerStateMap
// 3.  "ila-state":[ "cond&map" ]
// 4.  "ila-state":[ {"cond":,"map":}, ] 

std::string VlgVerifTgtGen::PerStateMap(const std::string & ila_state_name_or_equ, const std::string & vlg_st_name ) {

  if( isEqu(ila_state_name_or_equ) ) { // is equ
    // not using re here
    .. change name !!!
    std::string map_sig = new_mapping_id();
    vlg_wrapper.add_wire(map_sig, 1);
    vlg_wrapper.add_assign_stmt(map_sig, ila_state_name_or_equ );
    return map_sig;
  } // else it is a vlg signal name

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
  vlg_wrapper.add_assign_stmt(map_sig, vlg_state_name + " == __ILA_SO_" + ila_state->name().str() );
  return map_sig;
} // PerStateMap

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
} // GetStateVarMapExpr


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

#endif // GEN_UTIL_H__