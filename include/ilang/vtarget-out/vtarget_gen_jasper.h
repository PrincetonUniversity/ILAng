/// \file Verilog Verification Target Generator -- for JasperGold
// ---Hongce Zhang

#ifndef VTARGET_GEN_JASPER_H__
#define VTARGET_GEN_JASPER_H__

#include <ilang/vtarget-out/vtarget_gen_impl.h>

namespace ilang {

/// \brief  Verilog Verification Target Generator -- for JasperGold
/// Unlike for cosa, we don't need a separate file
/// although we do have some ...
class VlgVerifTgtGenCosa_Jasper : public VlgVerifTgtGen {
  
public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  ///
  /// \param[in] output path (ila-verilog, wrapper-verilog, problem.txt, run-verify-by-???, modify-impl, it there is )
  /// \param[in] pointer to the instruction
  /// \param[in] the default configuration for outputing verilog
  /// \param[in] the variable map
  /// \param[in] the conditions
  /// \param[in] pointer to verify info class
  /// \param[in] verilog module name
  /// \param[in] ila module name
  VlgVerifTgtGen(
    const std::string              & output_path, // will be a sub directory of the output_path of its parent
    const InstrPtr                 & instr_ptr, // which could be an empty pointer, and it will be used to verify invariants
    const VerilogGenerator::VlgGenConfig & config,
    nlohmann::json                 & _rf_vmap,
    nlohmann::json                 & _rf_cond,
    VerilogInfo      *               _vlg_info_ptr,
    const std::string              & vlg_mod_inst_name,
    const std::string              & ila_mod_inst_name,
    const std::string              & wrapper_name
  );

protected:

  /// Add an assumption
  virtual void add_an_assumption(const std::string & aspt, const std::string & dspt) override;
  /// Add an assertion
  virtual void add_an_assertion (const std::string & asst, const std::string & dspt) override
  
private:
  // It is okay to instantiation 
  virtual void do_not_instantiate(void) override {} ;

}; // class VlgVerifTgtGenCosaJasper


}; // namespace ilang

#endif // VTARGET_GEN_JASPER_H__