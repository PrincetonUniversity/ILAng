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
  TraceDataPoints * datapoints
  ) : Cvc4SygusBase(smt_design_info, inv_var_name_vec, SygusOptions, ""),
      dpts(datapoints)
      // not customize inv arg
  { }

std::string Cvc4SygusInputGenerator::generate_datapoint_constraints(TraceDataPoints * dpts) const {
  // pos ex
  const auto & var_idx = design_info.get_var_idx();
  std::vector<std::string> constraints;
  for(const auto & aframe : dpts->pos_ex ) {
    std::vector<std::string> frame_vals;
    for (const auto & vname : var_names) {
      ILA_ASSERT(IN(vname, aframe)) << vname << " is not in the datapoint frame!";
      ILA_ASSERT(IN(vname, var_idx)) << vname << " is not in the smt!";
      auto data_type_ptr = var_idx.at(vname);
      auto width = data_type_ptr->_type._width;
      ILA_ASSERT( data_type_ptr->_type.GetBoolBvWidth() 
        == aframe.at(vname).second.GetBoolBvWidth()) << "Bit-width does not match!";
      if (data_type_ptr->_type.is_bool())
        frame_vals.push_back( aframe.at(vname).first == 0 ? "false" : "true"  );
      else
        frame_vals.push_back( convert_to_binary(aframe.at(vname).first, width));
    }
    constraints.push_back( ReplaceAll(cnst_pos_template, 
      "%pos_vals%", Join(frame_vals," ") ));
  }

  std::vector<std::string> frame_vals;
  const auto & aframe = dpts->neg_ex;
  for (const auto & vname : var_names) {
    ILA_ASSERT(IN(vname, aframe)) << vname << " is not in the datapoint frame!";
    ILA_ASSERT(IN(vname, var_idx)) << vname << " is not in the smt!";
    auto data_type_ptr = var_idx.at(vname);
    auto width = data_type_ptr->_type._width;
    ILA_ASSERT( data_type_ptr->_type.GetBoolBvWidth() 
      == aframe.at(vname).second.GetBoolBvWidth()) << "Bit-width does not match!";
    if (data_type_ptr->_type.is_bool())
      frame_vals.push_back( aframe.at(vname).first == 0 ? "false" : "true"  );
    else
      frame_vals.push_back( convert_to_binary(aframe.at(vname).first, width));
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