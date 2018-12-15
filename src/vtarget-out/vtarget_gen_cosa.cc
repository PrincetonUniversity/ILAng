/// \file Source of generating CoSA accepted problem, vlg, mem, script
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen_cosa.h>

namespace ilang {

    VlgSglTgtGen_Cosa::VlgSglTgtGen_Cosa(
    const std::string              & output_path, // will be a sub directory of the output_path of its parent
    const InstrPtr                 & instr_ptr, // which could be an empty pointer, and it will be used to verify invariants
    const VerilogGenerator::VlgGenConfig & config,
    nlohmann::json                 & _rf_vmap,
    nlohmann::json                 & _rf_cond,
    VerilogInfo      *               _vlg_info_ptr,
    const std::string              & vlg_mod_inst_name,
    const std::string              & ila_mod_inst_name,
    const std::string              & wrapper_name,
    const std::vector<std::string> & implementation_srcs
  ):VlgSglTgtGen(
      output_path, instr_ptr, config, _rf_vmap, _rf_cond, 
      _vlg_info_ptr, vlg_mod_inst_name, ila_mod_inst_name,
      wrapper_name, implementation_srcs )
  {

  }


}; // namespace ilang