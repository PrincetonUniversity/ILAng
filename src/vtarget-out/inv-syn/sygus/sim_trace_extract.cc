/// \file Invariant Synthesis -- SyGuS
/// Bootstrap : extract simulation trace
/// You can start without bootstrap
/// but it does not work well I guess
/// --- Hongce Zhang

#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/inv-syn/sygus/sim_trace_extract.h>

#include <vcdparser/VCDFileParser.hpp>

namespace ilang {

static std::string val2str_sim(const VCDValue & v) {
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

std::string collect_scope_sim(VCDScope * sc) {
  std::string ret;
  while(sc) {
    ret = sc->name + "." + ret;
    sc = sc->parent;
  }
  return ret;
}


void SimTraceExtractor::parse_from(
    const std::string & vcd_file_name, 
    const std::string & scope, 
    rec_this_frame_t rec_this_frame,
    sig_rename_func_t renamer) {

  _ex.clear();

  VCDFileParser parser;
  VCDFile * trace = parser.parse_file(vcd_file_name);

  if (not trace) {
    ILA_ERROR << "Error while reading waveform from: "<< vcd_file_name;
    return;
  }

  ILA_NOT_NULL(trace -> get_scope("$root"));
  std::vector<VCDSignal*>* sigs = trace -> get_signals();

  std::vector<
    std::pair<VCDSignalValues::iterator,
      VCDSignalValues::iterator>> related_iterators;

  for ( VCDSignal * sig: *sigs) {

    // check scope
    // if (not in_scope(sig->scope, scope))
    //  continue;

    auto scopes = collect_scope_sim(sig->scope);

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
    if (not IN(check_name, coi))
      continue;
    VCDSignalValues * start_sig_vals = trace -> get_signal_value(sig->hash);
    related_iterators.push_back(
      std::make_pair(start_sig_vals->begin(),start_sig_vals->end()));
  }

  ILA_ERROR_IF(related_iterators.empty()) << "No vcd signal is in COI!";

  while(true) {
    bool no_available = true;
    VCDTime cur_time = std::numeric_limits<double>::max();
    for (const auto & cur_end_pos : related_iterators) {
      const auto & cur_pos = cur_end_pos.first;
      const auto & end_pos = cur_end_pos.second;
      if (cur_pos == end_pos)
        continue;

      no_available = false;
      if ( (*cur_pos)->time < cur_time )
        cur_time  = (*cur_pos)->time;
    }
    if (no_available)
      break; // we have iterate every possible time-vals

    // --------------- retrieve the signals ----------------- //
    
    // build_and_check_frame(scope,rec_this_frame,renamer);
    _ex.push_back(ex_t());
    bool successful = true;

    for ( VCDSignal * sig: *sigs) {
      auto scopes = collect_scope_sim(sig->scope);
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
      if (not IN(check_name, coi))
        continue;
      auto hash = sig->hash;
      auto vlg_val_ptr = trace->get_signal_value_at(hash,cur_time);
      if (vlg_val_ptr == nullptr) {
        ILA_ERROR << "Parsing VCD: " << vlg_name << " gets Xs. Ignore this frame.";
        successful = false;
        continue;
      }
      else {
        std::string val = 
          val2str_sim(
            * vlg_val_ptr );
        // insert to the last frame
        if (S_IN('X',val)) {
          ILA_WARN << "Parsing VCD: " << vlg_name << " gets Xs. Ignore this frame.";
          successful = false;
          continue;
        }
        _ex.back().insert( std::make_pair( 
          renamer(check_name),val));
      }
    } // frame is ready at this point
    ILA_ERROR_IF( (_ex.back().size() != coi.size()) and successful)
      << "Some COI signals are not recorded from VCD at time:" << cur_time;
    if (_ex.back().size() != coi.size()) {
      for (auto && s : coi) {
        if (not IN(renamer(s), _ex.back())) {
          ILA_ERROR << "coi: " << s << " not recorded."; } }
    } // end of check

    if (not successful || not rec_this_frame(cur_time,_ex.back()))
      _ex.pop_back();

    // --------------- move to the next frame ----------------- //
    no_available = true;
    for (auto & cur_end_pos : related_iterators) {
      auto & cur_pos = cur_end_pos.first;
      auto & end_pos = cur_end_pos.second;
      if (cur_pos == end_pos)
        continue;

      no_available = false;
      if ( (*cur_pos)->time <= cur_time )
        cur_pos ++;
    }
  }
} // parse_from


SimTraceExtractor::SimTraceExtractor(
    const std::string & vcd_file_name, 
    const std::string & scope,
    const std::set<std::string> & signals_of_interest,
    rec_this_frame_t rec_this_frame,
    sig_rename_func_t renamer) : coi(signals_of_interest) {

  parse_from(vcd_file_name, scope,
    rec_this_frame, renamer);
}

// -------------------- MEMBERS ------------------ //

const SimTraceExtractor::exs_t & SimTraceExtractor::GetEx() const {
  return _ex;
}


}; // namespace ilang