/// \file Invariant Synthesis -- SyGuS
/// to work with CVC4 (the latest version please)
/// The chc approach
/// (passing the whole transition function)
/// 
// Hongce Zhang (hongcez@princeton.edu)


#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/inv-syn/sygus/sygus_chc.h>

#include <fstream>

namespace ilang {


Cvc4SygusChcGenerator::Cvc4SygusChcGenerator(
  const smt::YosysSmtParser & smt_design_info,       // the design info is needed
  const std::vector<std::string> & inv_var_name_vec, // the variables we are going to consider
  const sygus_options_t & SygusOptions           // the options
  ) : Cvc4SygusBase(smt_design_info, inv_var_name_vec, SygusOptions) {

  ILA_WARN_IF(SygusOptions.UseExtract) << "Not supported yet : extract";
  ILA_WARN_IF(SygusOptions.UseExtend)  << "Not supported yet : extend";
  ILA_WARN_IF(SygusOptions.UseConcat)  << "Not supported yet : concat";
    
}

}; // namespace ilang

