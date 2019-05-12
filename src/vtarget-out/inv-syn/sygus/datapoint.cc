/// \file The datapoint structure (for SyGuS)
/// 
// Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>

#include <ilang/vtarget-out/inv-syn/sygus/datapoint.h>
#include <ilang/vtarget-out/inv-syn/cex_extract.h>
#include <ilang/vtarget-out/inv-syn/sygus/inv_cex_extract.h>
#include <ilang/vtarget-out/inv-syn/sygus/sim_trace_extract.h>

#include <cmath>
#include <iostream>
#include <fstream>

namespace ilang {

TraceDataPoints::value_t vlg_val_to_smt_val(const std::string & v) {
  TraceDataPoints::value_t ret;
  if (S_IN('.', v)) {
    ILA_ERROR << "Cannot convert verilog value:" << v;
    return ret;
  }
  
  if (S_IN('\'',v)) {
    auto sep_pos = v.find('\'');
    ILA_ERROR_IF(v.length() < sep_pos + 3 ) << "Unable to parse:" << v;
    char radix = v.at(sep_pos + 1);
    int radix_unsigned = (radix == 'h' ? 16 :
        (radix == 'x' ? 16 : 
          (radix == 'o' ? 8 :
            (radix == 'b' ? 2 : 10))));
    std::string val = v.substr(sep_pos+2); // to the end
    ILA_ERROR_IF(not S_IN(radix, std::string("hxob") )) << "Unable to parse, unknown radix:" << v;

    unsigned width;
    if (sep_pos != 0) {
      width = StrToInt(v.substr(0,sep_pos));
    } else {
      width = 1;
      if (val != "0")
        width = (unsigned)(floor(log2(StrToInt(val,radix_unsigned) ))) + 1;
    } // width
    ret.first.val = val;
    ret.first.radix = radix_unsigned;
    ret.second._type = smt::var_type::BV;
    ret.second._width = width;
  } else
  {
    ret.first.val = v;
    ret.first.radix = 10;
    ret.second._type = smt::var_type::BV;
    ret.second._width = 1; // if v == 0
    if (ret.first.val != "0")
      ret.second._width = (unsigned)(floor(log2(  StrToInt(ret.first.val,10)  ))) + 1;
  }
  return ret;  
} // vlg_val_to_smt_val

std::string vcd_remove_extra_bracket(const std::string & vname) {
  if (not S_IN('[', vname))
    return vname;
  auto bracket_pos = vname.rfind('[');
  auto colon_pos = vname.rfind(':');
  if (colon_pos == std::string::npos) // a[3] (this should not be)
    return vname;
  ILA_ASSERT (colon_pos >= bracket_pos) // otherwise we cannot handle
    << "BUG FIX needed: vname:" << vname << " has strange format";
  return vname.substr(0,bracket_pos);
}


/// this function allows to insert the outer cegar result to this datapoint
template <>
void TraceDataPoints::SetNegEx<CexExtractor>(const CexExtractor &ex) {
  neg_ex.clear();
  std::cout << "get eq cex:\n";
  for(auto && e : ex.GetCex() ) {
    neg_ex.insert(std::make_pair(vcd_remove_extra_bracket(e.first), vlg_val_to_smt_val(e.second)));
    //std::cout << e.first << " = " << e.second << "\n";
    auto name = vcd_remove_extra_bracket(e.first);
    if (! pos_ex.empty() && IN(name,pos_ex[0])) {
      std::cout << e.first << " = " << e.second << "\n";
    }
  }
}
/// the same as above

template <>
void TraceDataPoints::AddPosEx<CexExtractor>(const CexExtractor &ex) {
  pos_ex.push_back(example_map_t());
  for(auto && e : ex.GetCex() ) {
    pos_ex.back().insert(std::make_pair(vcd_remove_extra_bracket(e.first), vlg_val_to_smt_val(e.second)));
  }
}


// specialized instantiation
template <> void TraceDataPoints::SetNegEx<InvCexExtractor> (const InvCexExtractor & ex) {
  neg_ex.clear();
  for(auto && e : ex.GetCex() ) {
    neg_ex.insert(std::make_pair(
      vcd_remove_extra_bracket(e.first),
      std::make_pair(radix_val_t(e.second.first,2),e.second.second)
    ));
  }
}

// specialized instantiation
template <> void TraceDataPoints::AddPosEx<InvCexExtractor> (const InvCexExtractor & ex) {
  pos_ex.push_back(example_map_t());
  std::cout << "Adding pos ex:";
  for(auto && e : ex.GetCex() ) {
    pos_ex.back().insert(std::make_pair(
      vcd_remove_extra_bracket(e.first),
      std::make_pair(radix_val_t(e.second.first,2),e.second.second) ));
    std::cout << vcd_remove_extra_bracket(e.first) << ":" << e.second.first << std::endl;
  }
}

/// add positive examples and also check name completeness
template <> bool TraceDataPoints::AddPosEx<SimTraceExtractor>(const SimTraceExtractor & ex, const std::vector<std::string> & required_names) {
  int saved = 0;
  std::set<std::string> valset; // the value hash
  for(auto && e : ex.GetEx() ) {
    pos_ex.push_back(example_map_t());
    std::string v;
    std::string missing_name;
    // check if all required names are there, there could be more, we don't care
    for (auto && vn : required_names ) {
      if (not IN(vn, e)){
        missing_name = vn;
        break;
      }
    }
    if(not missing_name.empty()) {
      ILA_ERROR << "Sim datapoint missing name (at least):" << missing_name << " , ignore this frame";
      continue; // ignore this frame
    }
    for(auto && var_value : e) {
      pos_ex.back().insert(
        std::make_pair(
          vcd_remove_extra_bracket(var_value.first),
          vlg_val_to_smt_val(var_value.second)));
      v += var_value.second;
    }
    if (IN(v, valset)) {
      pos_ex.pop_back();
      saved ++;
      continue;
    }
    valset.insert(v);
  }
  std::cout << "Prune sim datapoint. Saved #:" << saved <<"\n";
  // set marker
  posExMarker = pos_ex.size();
}

// specialized instantiation
template <> void TraceDataPoints::AddPosEx<SimTraceExtractor> (const SimTraceExtractor & ex) {
  int saved = 0;
  std::set<std::string> valset;
  for(auto && e : ex.GetEx() ) {
    pos_ex.push_back(example_map_t());
    std::string v;
    for(auto && var_value : e) {
      pos_ex.back().insert(
        std::make_pair(
          vcd_remove_extra_bracket(var_value.first),
          vlg_val_to_smt_val(var_value.second)));
      v += var_value.second;
    }
    if (IN(v, valset)) {
      pos_ex.pop_back();
      saved ++;
      continue;
    }
    valset.insert(v);
  }
  std::cout << "Prune sim datapoint. Saved #:" << saved <<"\n";
  // set marker
  posExMarker = pos_ex.size();
}

void TraceDataPoints::ClearPosEx() {
  posExMarker = 0;
  pos_ex.clear();
}


// export data point
void TraceDataPoints::ExportNonprovidedPosEx(const std::string & fn) const {
  int ex_size = (int)(pos_ex.size()) - (int)posExMarker;
  ILA_ASSERT(ex_size >= 0) << "pos Ex Marker is too large:" << posExMarker <<","<<pos_ex.size();
  std::ofstream fout (fn);
  if (! fout.is_open()) {
    ILA_ERROR << "cannot open " << fn << " for write";
    return;
  }
  fout << ex_size << "\n";
  for (auto pos = pos_ex.begin() + posExMarker; pos != pos_ex.end() ; ++ pos) {
    fout << (pos->size()) << "\n";
    for (auto && name_val_pair : *pos) {
      fout << name_val_pair.first << " ";
      fout << name_val_pair.second.first.val << " ";
      fout << name_val_pair.second.first.radix << " ";
      fout << (name_val_pair.second.second.is_bv()? "BV":"Bool") << " ";
      fout << name_val_pair.second.second.GetBoolBvWidth() << "\n";
    }
  }
  ILA_INFO << "Saved pos ex:" << ex_size;
}

// insert data point
void TraceDataPoints::ImportNonprovidedPosEx(const std::string & fn, const std::vector<std::string> & required_var_name ) {
  std::ifstream fin(fn);
  if (! fin.is_open()) {
    ILA_ERROR << "cannot open " << fn << " for read";
    return;
  }
  unsigned ex_size;
  fin >> ex_size;

  std::string vname;
  std::string val;
  int radix;
  std::string bvbool;
  unsigned width;

  // statistics;
  unsigned original_frame_size = pos_ex.size();
  unsigned unfit_frame = 0;

  for (unsigned idx = 0; idx < ex_size; ++ idx) {
    unsigned var_map_size;
    fin >> var_map_size;
    pos_ex.push_back(example_map_t());
    for (unsigned vidx = 0; vidx < var_map_size; ++ vidx) {
      fin >> vname;
      fin >> val;
      fin >> radix;
      fin >> bvbool;
      fin >> width;
      smt::var_type tp;
      tp._width = width;
      if (bvbool == "BV") tp._type = tp.BV;
      else if (bvbool == "Bool") tp._type = tp.Bool;
      else ILA_ERROR << "Unknown type:" << bvbool;

      ILA_ERROR_IF(width == 0 || vname.empty() || val.empty() || radix == 0 )
        << "read format error!";
      pos_ex.back().insert(std::make_pair(
        vname,
        std::make_pair(radix_val_t(val,radix),tp)
      ));
    } // for all data item
    // check if all required name exists
    if(not required_var_name.empty()) {
      for (auto && n : required_var_name) {
        if (not IN(n, pos_ex.back())) {
          ILA_ERROR << "At least required state: " << n << " is not log in the stored frame. Will not keep this frame.";
          unfit_frame ++;
          pos_ex.pop_back();
        }
      }
    } // end of checking
  } // end of a frame
  if (unfit_frame == ex_size || pos_ex.size() == original_frame_size)
    ILA_ERROR << "Note: Empty datapoint has been imported!" << (required_var_name.empty() ? "":" (after checking)") ;
} // end of import function

}; // namespace ilang
