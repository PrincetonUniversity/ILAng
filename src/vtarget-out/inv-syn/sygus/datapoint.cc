/// \file The datapoint structure (for SyGuS)
/// 
// Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>

#include <ilang/vtarget-out/inv-syn/sygus/datapoint.h>
#include <ilang/vtarget-out/inv-syn/cex_extract.h>
#include <ilang/vtarget-out/inv-syn/sygus/inv_cex_extract.h>

#include <cmath>

namespace ilang {

TraceDataPoints::value_t vlg_val_to_smt_val(const std::string & v) {
  TraceDataPoints::value_t ret;
  if (S_IN('.', v)) {
    ILA_ERROR << "Cannot convert verilog value:" << v;
    return ret;
  }
  
  if (S_IN('`',v)) {
    auto sep_pos = v.find('`');
    ILA_ERROR_IF(v.length() < sep_pos + 3 ) << "Unable to parse:" << v;
    char radix = v.at(sep_pos + 1);
    unsigned val = StrToInt(v.substr(sep_pos+2),
      (radix == 'h' ? 16 :
        (radix == 'x' ? 16 : 
          (radix == 'o' ? 8 :
            (radix == 'b' ? 2 : 10))))); // to the end
    ILA_ERROR_IF(not S_IN(radix, std::string("hxob") )) << "Unable to parse, unknown radix:" << v;

    unsigned width;
    if (sep_pos != 0) {
      width = StrToInt(v.substr(0,sep_pos));
    } else {
      width = 1;
      if (val != 0)
        width = (unsigned)(floor(log2(val))) + 1;
    } // width
    ret.first = val;
    ret.second._type = smt::var_type::BV;
    ret.second._width = width;
  } else
  {
    ret.first = StrToInt(v);
    ret.second._type = smt::var_type::BV;
    ret.second._width = 1; // if v == 0
    if (ret.first != 0)
      ret.second._width = (unsigned)(floor(log2(ret.first))) + 1;
  }
  return ret;  
} // vlg_val_to_smt_val


/// this function allows to insert the outer cegar result to this datapoint
template <typename T>
void TraceDataPoints::SetNegEx(const T &ex) {
  neg_ex.clear();
  for(auto && e : ex.GetCex() ) {
    neg_ex.insert(std::make_pair(e.first, vlg_val_to_smt_val(e.second)));
  }
}
/// the same as above

template <typename T>
void TraceDataPoints::AddPosEx(const T &ex) {
  pos_ex.push_back(example_map_t());
  for(auto && e : ex.GetCex() ) {
    pos_ex.back().insert(std::make_pair(e.first, vlg_val_to_smt_val(e.second)));
  }
}

void TraceDataPoints::ClearPosEx() {
  pos_ex.clear();
}

// instantiate the templates
template void TraceDataPoints::SetNegEx<CexExtractor> (const CexExtractor & ex);
template void TraceDataPoints::AddPosEx<CexExtractor> (const CexExtractor & ex);
template void TraceDataPoints::SetNegEx<InvCexExtractor> (const InvCexExtractor & ex);
template void TraceDataPoints::AddPosEx<InvCexExtractor> (const InvCexExtractor & ex);

}; // namespace ilang
