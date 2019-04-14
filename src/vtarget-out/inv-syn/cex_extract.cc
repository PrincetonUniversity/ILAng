/// \file CounterExample Extractor
// ---Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/inv-syn/cex_extract.h>

#include <vcdparser/VCDFileParser.hpp>

#include <sstream>

namespace ilang {


std::string val2str(const VCDValue & v) {
  std::stringstream ret;

  switch(v.get_type()) {
    case (VCD_SCALAR): 
      ret << "1'b" << VCDValue::VCDBit2Char(v.get_value_bit());
      break;
    case (VCD_VECTOR):
      {
        const VCDBitVector * vecval = v.get_value_vector();
        ret << std::to_string(vecval->size())<< "'b";
        for(auto it = vecval -> begin();
                it != vecval -> end();
                ++it)
          ret << VCDValue::VCDBit2Char(*it);
      }
      break;
    case (VCD_REAL):
      ret << v.get_value_real();
      break;
    default:
      ILA_ERROR<<"Unknown value type!";
  }
  return ret.str();
}

std::string prepend(const std::string & prefix, const std::string sig_name ) {
  if (prefix.empty())
    return sig_name;
  return prefix + "." + sig_name;
}

bool in_scope(VCDScope * sc, const std::string & sc_name) {
  VCDScope * sc_traverse = sc;
  while(sc_traverse) {
    if (sc_traverse->name == sc_name)
      return true;
    sc_traverse = sc_traverse->parent;
  }
  return false;
}

std::string collect_scope(VCDScope * sc) {
  std::string ret;
  while(sc) {
    ret = sc->name + "." + ret;
    sc = sc->parent;
  }
  return ret;
}


void CexExtractor::parse_from(const std::string & vcd_file_name, 
  const std::string & scope, is_reg_t is_reg) {

  cex.clear();

  VCDFileParser parser;
  VCDFile * trace = parser.parse_file(vcd_file_name);

  if (not trace) {
    ILA_ERROR << "Error while reading waveform from: "<< vcd_file_name;
    return;
  }

  ILA_NOT_NULL(trace -> get_scope("$root"));

  // determine the start signal time
  std::string start_sig_hash;
  for (VCDSignal* root_sig : trace -> get_scope("$root") -> signals ) {
    // find the hash of it
    if (root_sig -> reference == "__START__" || 
        root_sig -> reference == "__START__[0:0]" )
      start_sig_hash = root_sig -> hash;
  }
  if (start_sig_hash.empty() ) {
    ILA_ERROR << "Error analyzing waveform. "
     << "It is not a trace generated by Verilog Verification Target Generation. "
     << "__START__ signal not found in $root scope";
    return;
  }

  VCDSignalValues * start_sig_vals = trace -> get_signal_value(start_sig_hash);
  VCDTime start_time = -1;
  for (VCDTimedValue * tv : *start_sig_vals) {
    if ( val2str( *(tv -> value) ) == "1'b1" ) {
      start_time = tv -> time;
      break;
    }
  }

  if (start_time == -1) {
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

    auto scopes = collect_scope(sig->scope);

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

    if(not is_reg(check_name) )
      continue;

    auto vlg_val_ptr = trace->get_signal_value_at( sig->hash, start_time);

    if (vlg_val_ptr == nullptr) {
      ILA_INFO << "Parsing VCD: " << vlg_name << " gets Xs. Ignored.";
      continue;
    }

    std::string val = 
      val2str(
        * vlg_val_ptr );
    
    cex.insert( std::make_pair( vlg_name, val) );
    
  } // for sig

  ILA_ASSERT(not cex.empty()) << "No counterexample is extracted!";

} // parse_from


CexExtractor::CexExtractor(const std::string & vcd_file_name, 
  const std::string & scope, is_reg_t is_reg) {
  parse_from(vcd_file_name, scope, is_reg);
}

// -------------------- MEMBERS ------------------ //
/// return a string to be added to the design
std::string CexExtractor::GenInvAssert(const std::string & prefix) const {
  std::string ret = "(1'b1 == 1'b1)"; // true
  for (auto && nv : cex) {
    
    ret += "&& (" + prepend(prefix, 
      ReplaceAll( nv.first , "[0:0]" , "" ) ) + " == " + nv.second + ")";
  }
  return ret;
}

}; // namespace ilang