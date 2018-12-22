/// \file Verilog Verification Target Generator -- for JasperGold
// ---Hongce Zhang

#ifndef VTARGET_GEN_JASPER_H__
#define VTARGET_GEN_JASPER_H__

#include <ilang/vtarget-out/vtarget_gen_impl.h>

namespace ilang {

/// \brief  Verilog Verification Target Generator -- for JasperGold
/// Unlike for cosa, we don't need a separate file
/// although we do have some ...
class VlgSglTgtGen_Jasper : public VlgSglTgtGen {
  /// using the target type
  using target_type_t = VlgSglTgtGen::target_type_t;
  
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
  /// \param[in] ila module name,
  /// \param[in] all implementation sources
  /// \param[in] all include paths
  /// \param[in] which backend to use, it needs this info to gen proper properties
  VlgSglTgtGen_Jasper(
    const std::string              & output_path, // will be a sub directory of the output_path of its parent
    const InstrPtr                 & instr_ptr, // which could be an empty pointer, and it will be used to verify invariants
    const InstrLvlAbsPtr           & ila_ptr, 
    const VerilogGenerator::VlgGenConfig & config,
    nlohmann::json                 & _rf_vmap,
    nlohmann::json                 & _rf_cond,
    VerilogInfo      *               _vlg_info_ptr,
    const std::string              & vlg_mod_inst_name,
    const std::string              & ila_mod_inst_name,
    const std::string              & wrapper_name,
    const std::vector<std::string> & implementation_srcs,
    const std::vector<std::string> & include_dirs,
    backend_selector                 backend
  );

protected:
  /// internal storage of problems
  // TODO:

protected:
  /// Add an assumption
  virtual void add_an_assumption(const std::string & aspt, const std::string & dspt) override;
  /// Add an assertion
  virtual void add_an_assertion (const std::string & asst, const std::string & dspt) override;
  /// Add an assignment which in JasperGold could be an assignment, but in CoSA has to be an assumption
  virtual void add_wire_assign_assumption(const std::string & varname, const std::string & expression, const std::string & dspt ) override;
  /// Add an assignment to a register which in JasperGold could be an assignment, but in CoSA has to be an assumption
  virtual void add_reg_cassign_assumption(const std::string & varname, const std::string & expression, const std::string & cond, const std::string & dspt ) override;
  
  
  /// export the script to run the verification
  virtual void Export_script(const std::string & script_name) override;
  /// export extra things (problem)
  virtual void Export_problem(const std::string & extra_name) override; // only for cosa
  /// export the memory abstraction (implementation)
  /// Yes, this is also implementation specific, (jasper may use a different one)
  virtual void Export_mem(const std::string & mem_name) override;
  /// For jasper, this means do nothing, for yosys, you need to add (*keep*)
  virtual void Export_modify_verilog() override;

private:
  /// It is okay to instantiation 
  virtual void do_not_instantiate(void) override {} ;


}; // class VlgVerifTgtGenCosaJasper


}; // namespace ilang

#endif // VTARGET_GEN_JASPER_H__