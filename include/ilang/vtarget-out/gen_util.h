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
  if (_instr_ptr->host()->state(sname) ) return true;
  // if it uses the reference it self
  auto hierName = Split(sname, ".");
  if (hierName.size() == 2 ) { // maybe it contains an unnecessary head
    if( (hierName[0] == _ila_mod_inst_name || hierName[0] == "ILA") && _instr_ptr->host()->state(hierName[1]) )
      return true;
    return false;
  }
  return false;
}
bool VlgVerifTgtGen::TryFindVlgState(const std::string &sname) {

  if(vlg_info_ptr->check_hierarchical_name_type(sname) 
     != VerilogInfo::hierarchical_name_type::NONE)
    return true;
  if(vlg_info_ptr->check_hierarchical_name_type( _vlg_mod_inst_name + "." + sname) 
     != VerilogInfo::hierarchical_name_type::NONE)
    return true;
  return false;
}

// for ila state: add __ILA_SO_
// for verilog signal: keep as it is should be fine
// btw, record all referred vlg name
std::string VlgVerifTgtGen::ModifyCondExprAndRecordVlgName(const VarExtractor::token &t ) {
  // modify name and ...
  const auto & token_tp = t.first;
  const auto & sname     = t.second;

  if (token_tp == VarExtractor::token_type::UNKN_S) {
    ILA_WARN << "In refinement relations: unknown reference to name:" << name << " keep unchanged.";
    return sname;
  }
  if (token_tp == VarExtractor::token_type::KEEP || 
      token_tp == VarExtractor::token_type::UNKN_S ||
      token_tp == VarExtractor::token_type::NUM ) 
    return sname; // NC
  if (token_tp == VarExtractor::token_type::ILA_S) {
    // if it refers to ILA state
    if (_instr_ptr->host()->state(sname) ) return "__ILA_SO_" + sname;
    // if it uses the reference it self
    auto hierName = Split(sname, ".");
    if (hierName.size() == 2 && ) // maybe it contains an unnecessary head
      if( (hierName[0] == _ila_mod_inst_name || hierName[0] == "ILA") && _instr_ptr->host()->state(hierName[1]) )
        return "__ILA_SO_" + hierName[1];
    // should not reachable
    ILA_ASSERT(false) << "Implementation bug: should not be reachable. token_tp: ILA_S";
    return sname;
  }
  if (token_tp == VarExtractor::token_type::VLG_S)  {

    if(vlg_info_ptr->check_hierarchical_name_type(sname) 
       != VerilogInfo::hierarchical_name_type::NONE) {
      _all_referred_vlg_names.push_back(sname)
      return sname;
    }
    if(vlg_info_ptr->check_hierarchical_name_type( _vlg_mod_inst_name + "." + sname) 
       != VerilogInfo::hierarchical_name_type::NONE) {
      _all_referred_vlg_names.push_back(_vlg_mod_inst_name + "." + sname)
      return _vlg_mod_inst_name + "." + sname;      
    }
    ILA_ASSERT(false) << "Implementation bug: should not be reachable. token_type: VLG_S";
    return  sname;
  }
  ILA_ASSERT(false) << "Implementation bug: should not reachable. Caused by token_type:" << token_tp;
  return sname;
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

// Replace an expr's variable name
std::string VlgVerifTgtGen::ReplExpr(const std::string & expr , bool force_vlg_sts = false) {
  return _vext.Replace(expr, 
        force_vlg_sts, 
        [this] (const VarExtractor::token &t ) {
          return ModifyCondExprAndRecordVlgName(t) } );
}

std::string VlgVerifTgtGen::PerStateMap(const std::string & ila_state_name_or_equ, const std::string & vlg_st_name ) {

  if( isEqu(ila_state_name_or_equ) ) { // is equ
    // not using re here
    auto new_expr = ReplExpr(ila_state_name_or_equ);

    std::string map_sig = new_mapping_id();
    vlg_wrapper.add_wire(map_sig, 1);
    vlg_wrapper.add_assign_stmt(map_sig, new_expr );
    return map_sig;
  } 
  // else it is a vlg signal name
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
  vlg_wrapper.add_assign_stmt(map_sig, ReplExpr(vlg_state_name, true) + " == __ILA_SO_" + ila_state->name().str() );
  return map_sig;
} // PerStateMap

// return a verilog verilog, that should be asserted to be true for this purpose
std::string VlgVerifTgtGen::GetStateVarMapExpr(const std::string & ila_state_name, nlohmann::json & m) {
  if( m.is_string() ) {
    if ( _sdr.isSpecialStateDir() ) {
      ILA_ASSERT(false) <<"FIXME: not implemented."; .. 
    } else { 
      // return the mapping variable 
      return PerStateMap(ila_state_name, m.get<std::string>());
    }
  } /* else */
  if( m.is_array() ) { // array of string or array of object/array
    std::vector<std::string> all_mappings;
    std::string prev_neg; // make sure it is a priority condition lists

    for (auto & item: m) {
      if (item.is_string() ) {
        auto mapping = ReplExpr(m.get<std::string>());
        all_mappings.push_back(mapping);
      } else if (item.is_array() || item.is_object() ) { // it should only by size of 2
        std::string cond(VLG_TRUE), vmap(VLG_TRUE);
        for (const auto & i : nlohmann::json::iterator_wrapper(item)) {
          if (i.key() == "0" || i.key() == "cond") {
            cond = i.value().get<std::string>();  // set the condtion
            continue;
          }
          if (i.key() == "1" || i.key() == "map") {
            vmap = PerStateMap( ila_state_name, i.value().get<std::string>()); 
            continue; // set the mapping
          }
          ILA_ERROR << "mapping for statename:"<< ila_state_name <<" contains unsupported construct.";
          break;
        }
        // cond ==> vmap    i.e.  ~cond || vmap
        all_mappings.push_back ( "~ (" + prev_neg + cond + ") || (" + vmap + ")" );
        prev_neg += "~(" + cond + ")&&"; 
      } else {
        ILA_ERROR<<"Unable to handle this piece of JSON input:"<<item;
        return VLG_TRUE;
      }
    } // for (item in m)

    if(all_mappings.size() == 0) {
      ILA_ERROR<< "Variable mapping for " << ila_state_name << " is empty!";
      return VLG_TRUE;
    }

    return  "(" + Join(all_mappings, " )&&( " ) + ")" ;
  }// if it is an array 

  // fall-through case
  LA_ERROR<<"Unable to handle this piece of JSON input:"<<m;
  return VLG_TRUE;
} // GetStateVarMapExpr


bool VlgVerifTgtGen::bad_state_return(void) {
  ILA_ERROR_IF(_bad_state) <<"VlgVerifTgtGen is in a bad state, cannot proceed.";
  return _bad_state;
} // bad_state_return

void VlgVerifTgtGen::load_json(const std::string & fname, json & j) {
  std::ifstream fin(fname);
  if(!fin.is_open() ) {
    ILA_ERROR << "Cannot read from file:"<<fname;
    _bad_state = true;
    return;
  }
  fname >> j;
} // load_json

}; // namespace ilang

#endif // GEN_UTIL_H__