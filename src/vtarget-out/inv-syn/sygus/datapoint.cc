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
  for(auto && e : ex.GetCex() ) {
    neg_ex.insert(std::make_pair(vcd_remove_extra_bracket(e.first), vlg_val_to_smt_val(e.second)));
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


// specialized instantiation
template <> void TraceDataPoints::AddPosEx<SimTraceExtractor> (const SimTraceExtractor & ex) {
  for(auto && e : ex.GetEx() ) {
    pos_ex.push_back(example_map_t());
    for(auto && var_value : e)
      pos_ex.back().insert(
        std::make_pair(
          vcd_remove_extra_bracket(var_value.first),
          vlg_val_to_smt_val(var_value.second)));
  }
}

void TraceDataPoints::ClearPosEx() {
  pos_ex.clear();
}
}; // namespace ilang
