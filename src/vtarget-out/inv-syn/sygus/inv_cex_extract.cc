/// \file CounterExample Extractor
// ---Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/inv-syn/sygus/inv_cex_extract.h>

#include <vcdparser/VCDFileParser.hpp>

#include <sstream>

namespace ilang {


static InvCexExtractor::value_t val2str(const VCDValue & v) {
  InvCexExtractor::value_t ret;
  char ch;

  switch(v.get_type()) {
    case (VCD_SCALAR): 
      ret.second._type = smt::var_type::tp::Bool;
      ch = VCDValue::VCDBit2Char(v.get_value_bit());
      ILA_WARN_IF(ch != '0' and ch != '1') << "Got " << ch << " in parsing VCD, treating as 0";
      ret.first = ch == '1' ? "1" : "0";
      break;
    case (VCD_VECTOR):
      {
        const VCDBitVector * vecval = v.get_value_vector();
        ret.second._type  = smt::var_type::tp::BV;
        ret.second._width = vecval->size();
        
        for(auto it = vecval -> begin();
                it != vecval -> end();
                ++it) {
          ch = VCDValue::VCDBit2Char(*it);
          ILA_WARN_IF(ch != '0' and ch != '1') << "Got " << ch << " in parsing VCD, treating as 0";
          ret.first = ret.first + ch;
        } // for
      } // case vector
      break;
    default:
      ILA_ASSERT(false)<<"Unknown value type:"<< v.get_type();
  }
  return ret;
} // val2str

std::string collect_scope_inv_cex(VCDScope * sc) {
  std::string ret;
  while(sc) {
    ret = sc->name + "." + ret;
    sc = sc->parent;
  }
  return ret;
}


void InvCexExtractor::parse_from(const std::string & vcd_file_name, 
  const std::string & scope, is_coi_state_t is_coi) {

  cex.clear();

  VCDFileParser parser;
  VCDFile * trace = parser.parse_file(vcd_file_name);

  if (not trace) {
    ILA_ERROR << "Error while reading waveform from: "<< vcd_file_name;
    return;
  }

  ILA_NOT_NULL(trace -> get_scope("$root"));
  VCDScope* top = NULL;
  for (VCDScope * c : trace -> get_scope("$root")->children)
    if (c->name == "top")
      top = c;
  ILA_NOT_NULL(top);

  VCDTime reset_time = 1;

  for (VCDSignal* root_sig : top -> signals ) {
    // find the hash of it
    std::string vlg_name ( root_sig -> reference );

    if (vlg_name != "rst")
      continue; // if this is not an invariant assert signal
    // now check if it fails
    std::string inv_hash = root_sig -> hash;
    bool found = false;
    VCDSignalValues * start_sig_vals = trace -> get_signal_value(inv_hash);
    for (VCDTimedValue * tv : *start_sig_vals) {
      if ( val2str( *(tv -> value) ).first == "0" and tv -> time > reset_time) {
        reset_time = tv -> time;
        found = true;
        break;
      }
    }
    if(found)
      break;
  } // iterate over all root signals to find the `invariant_assert__`

  VCDTime failing_time = -1;
  // determine the start signal time
  for (VCDSignal* root_sig : top -> signals ) {
    // find the hash of it
    std::string vlg_name ( root_sig -> reference );

    if (vlg_name.find("invariant_assert__") != 0)
      continue; // if this is not an invariant assert signal
    // now check if it fails
    std::string inv_hash = root_sig -> hash;
    bool found = false;
    VCDSignalValues * start_sig_vals = trace -> get_signal_value(inv_hash);
    for (VCDTimedValue * tv : *start_sig_vals) {
      if ( val2str( *(tv -> value) ).first == "0" and tv->time >= reset_time ) {
        failing_time = tv -> time;
        std::cout << "extracting inv-cex @ time : " << failing_time << std::endl;
        found = true;
        break;
      }
    }
    if(found)
      break;
  } // iterate over all root signals to find the `invariant_assert__`

  if (failing_time == -1) {
    ILA_ERROR << "Start time not found from waveform!";
    return;
  }

  std::vector<VCDSignal*>* sigs = trace -> get_signals();


  for ( VCDSignal * sig: *sigs) {

    // ensure it is only register
    if (sig->type != VCDVarType::VCD_VAR_REG)
      continue;

    // check scope
    // if (not in_scope(sig->scope, scope))
    //  continue;

    auto scopes = collect_scope_inv_cex(sig->scope);

    // check scope -- only the top level
    if ( not ( scopes.find("$root." +  scope + ".") == 0 ||
               scopes.find( scope + ".") == 0 ))
      continue;

    auto vlg_name = ReplaceAll(
      scopes + sig->reference, "$root.", "");
    
    std::string check_name = vlg_name;
    {
      auto pos = check_name.find('[');
      if (pos != std::string::npos)
        check_name = check_name.substr(0,pos);
    }

    if(not is_coi(check_name) )
      continue;

    auto vlg_val_ptr = trace->get_signal_value_at( sig->hash, failing_time);

    if (vlg_val_ptr == nullptr) {
      ILA_WARN << "Parsing VCD: " << vlg_name << " gets Xs. Ignored.";
      continue;
    }

    auto val = 
      val2str(
        * vlg_val_ptr );
    
    cex.insert( std::make_pair( vlg_name, val) );
  } // for sig
  ILA_ASSERT(not cex.empty()) << "No counterexample is extracted!";
} // parse_from


InvCexExtractor::InvCexExtractor(const std::string & vcd_file_name, 
  const std::string & scope, is_coi_state_t is_coi) {
  parse_from(vcd_file_name, scope, is_coi);
}

// -------------------- MEMBERS ------------------ //
/// return a string to be added to the design

const InvCexExtractor::cex_t & InvCexExtractor::GetCex() const {
  return cex;
}

}; // namespace ilang