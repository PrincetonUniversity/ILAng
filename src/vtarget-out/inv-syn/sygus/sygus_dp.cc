/// \file Invariant Synthesis -- SyGuS
/// to work with CVC4 (the latest version please)
/// The data-point (dp) approach
/// (not passing the whole transition function)
/// 
// Hongce Zhang (hongcez@princeton.edu)


#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/inv-syn/sygus/sygus_dp.h>

#include <fstream>

namespace ilang {

const std::string cnst_pos_template = "(constraint (INV %pos_vals%))";
const std::string cnst_neg_template = "(constraint (not (INV %neg_vals%)))";

Cvc4SygusInputGenerator::Cvc4SygusInputGenerator(
  const smt::YosysSmtParser & smt_design_info,       // the design info is needed
  const std::vector<std::string> & inv_var_name_vec, // the variables we are going to consider
  const sygus_options_t & SygusOptions,           // the options
  TraceDataPoints * datapoints,
  const std::map<std::string, int> & additional_width_info,
  const Cvc4Syntax & syntax
  ) : Cvc4SygusBase(smt_design_info, inv_var_name_vec, SygusOptions, "", additional_width_info, syntax),
      dpts(datapoints)
      // not customize inv arg
  { }

std::string Cvc4SygusInputGenerator::generate_datapoint_constraints(TraceDataPoints * dpts) const {
  // pos ex
  std::vector<std::string> missing_signals;
  const auto & var_idx = design_info.get_var_idx();
  std::vector<std::string> constraints;
  for(const auto & aframe : dpts->pos_ex ) {
    std::vector<std::string> frame_vals;
    for (const auto & vname : var_names) {
      if (not IN(vname, aframe)) {
        missing_signals.push_back(vname);
        continue;
      }

      smt::var_type tp;
      
      if (IN (vname,var_idx) ) {
        smt::state_var_t * data_type_ptr = var_idx.at(vname);
        tp = data_type_ptr->_type;
      } else if (IN (vname, additional_width_info)) {
        tp._width = additional_width_info.at(vname);
        tp._type = tp.BV;
      } else {
        tp = aframe.at(vname).second;
        ILA_ERROR << vname << " is not in the smt! Using datapoints width:" << tp.GetBoolBvWidth();
      }

      auto width = tp._width;
      // they should match, but for iverilog, it does not always generate the right width
      // iverilog's bug here!
      if (tp.is_bool())
        frame_vals.push_back( aframe.at(vname).first.val == "0" ? "false" : "true"  );
      else
        frame_vals.push_back( smt::convert_to_binary(aframe.at(vname).first.val, aframe.at(vname).first.radix, width));
    }

    if (not missing_signals.empty()) {
      ILA_ERROR << "The following signals are missing in PosEx frame:";
      for (auto && v : missing_signals)
        ILA_ERROR << v;
      ILA_ASSERT(false) << "Missing signal in datapoint frame!";
    }
    
    constraints.push_back( ReplaceAll(cnst_pos_template, 
      "%pos_vals%", Join(frame_vals," ") ));
  }

  std::vector<std::string> frame_vals;
  const auto & aframe = dpts->neg_ex;
  for (const auto & vname : var_names) {
    bool in_dataframe = IN(vname, aframe);
    bool in_smt = IN (vname,var_idx);
    bool in_additional_winfo = IN (vname, additional_width_info);
    
    smt::var_type tp;
    
    if (in_smt) {
      smt::state_var_t * data_type_ptr = var_idx.at(vname);
      tp = data_type_ptr->_type;
    } else if (in_additional_winfo) {
      tp._width = additional_width_info.at(vname);
      tp._type = tp.BV;
    } else if (in_dataframe) {
      tp = aframe.at(vname).second;
      ILA_ERROR << vname << " is not in the smt! Using datapoint frame width:" << tp.GetBoolBvWidth();
    } else {
      ILA_ASSERT(false) << "No width info for " << vname;
    }
    

    //ILA_ASSERT( data_type_ptr->_type.GetBoolBvWidth() 
    //  == aframe.at(vname).second.GetBoolBvWidth()) << "Bit-width does not match!";
    if (in_dataframe) {
      if (tp.is_bool())
        frame_vals.push_back( aframe.at(vname).first.val == "0" ? "false" : "true"  );
      else
        frame_vals.push_back( smt::convert_to_binary(aframe.at(vname).first.val, aframe.at(vname).first.radix, tp._width));
    } else { // if it is not in data frame, then it means we need to block both 
      ILA_ERROR << vname << " is not in neg data_frame!";
       if (tp.is_bool())
        frame_vals.push_back( "false" );
      else
        frame_vals.push_back( smt::convert_to_binary("0", 2, tp._width));
    }
  }
  constraints.push_back( ReplaceAll(cnst_neg_template, 
    "%neg_vals%", Join(frame_vals," ") ));

  return Join(constraints,"\n"); // TODO:
}

void Cvc4SygusInputGenerator::ExportToFile(const std::string & fn) {
  ILA_NOT_NULL(dpts);
  
  if (dpts->neg_ex.empty()) {
    ILA_ERROR << "No cex inserted! Cannot invoke SyGuS!";
    return;
  }

  std::ofstream fout(fn);
  if (not fout.is_open()) {
    ILA_ERROR << "Cannot open " << fn << " for write.";
    return;
  }
  // to do : add functions here
  // ignore those in dpts but not in inv_var_name_vec!
  fout << "(set-logic BV)\n";
  fout << get_template();
  fout << generate_datapoint_constraints(dpts);
  fout << "\n(check-synth)\n";
}



}; // namespace ilang