/// \file Verilog Verification Target Generator -- for JasperGold
// ---Hongce Zhang

#ifndef ILANG_VTARGET_OUT_VTARGET_GEN_JASPER_H__
#define ILANG_VTARGET_OUT_VTARGET_GEN_JASPER_H__

#include <ilang/vtarget-out/vtarget_gen_impl.h>

namespace ilang {

/// \brief  Verilog Verification Target Generator -- for JasperGold
/// Unlike for cosa, we don't need a separate file
/// although we do have some ...
class VlgSglTgtGen_Jasper : public VlgSglTgtGen {
  /// using the target type
  using target_type_t = VlgSglTgtGen::target_type_t;
  /// Type of advanced parameter
  using advanced_parameters_t = VlgVerifTgtGenBase::advanced_parameters_t;

public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  ///
  /// \param[in] output path (ila-verilog, wrapper-verilog, problem.txt,
  /// run-verify-by-???, modify-impl, it there is ) \param[in] pointer to the
  /// instruction \param[in] the default configuration for outputing verilog
  /// \param[in] the variable map
  /// \param[in] the conditions
  /// \param[in] pointer to verify info class
  /// \param[in] verilog module name
  /// \param[in] ila module name,
  /// \param[in] all implementation sources
  /// \param[in] all include paths
  /// \param[in] which backend to use, it needs this info to gen proper
  /// properties
  VlgSglTgtGen_Jasper(
      const std::string& output_path, // will be a sub directory of the
                                      // output_path of its parent
      const InstrPtr& instr_ptr, // which could be an empty pointer, and it will
                                 // be used to verify invariants
      const InstrLvlAbsPtr& ila_ptr,
      const VerilogGenerator::VlgGenConfig& config, nlohmann::json& _rf_vmap,
      nlohmann::json& _rf_cond, VlgTgtSupplementaryInfo& _supplementary_info,
      VerilogInfo* _vlg_info_ptr, const std::string& vlg_mod_inst_name,
      const std::string& ila_mod_inst_name, const std::string& wrapper_name,
      const std::vector<std::string>& implementation_srcs,
      const std::vector<std::string>& include_dirs,
      const vtg_config_t& vtg_config, backend_selector backend,
      const target_type_t& target_tp, advanced_parameters_t* adv_ptr);

  /// if you have signals that are controled by assumptions to be equal as
  /// the outer clock, you need to put them here,
  /// because the assumptions do not work in the jaspergold reset step
  /// (unlike COSA)
  void add_addition_clock_info(const std::string& expr);
  void add_addition_reset_info(const std::string& expr);

protected:
  /// internal storage of problems
  /// vector of pairs of <assumption, description>
  std::vector<std::pair<std::string, std::string>> assumptions;
  /// vector of pairs of <assertions, description>
  std::vector<std::pair<std::string, std::string>> assertions;
  /// vector of clock signals that need to be taken care of
  std::vector<std::string>
      additional_clock_expr; // we don't put the "clk" here, as by default it
                             // will be there
  /// vector of clock signals that need to be taken care of
  std::vector<std::string> additional_reset_expr;
  /// Name of the problem file
  std::string jg_script_name;
  /// Name of the problem file
  std::string abs_mem_name;

protected:
  /// Add an assumption
  virtual void add_an_assumption(const std::string& aspt,
                                 const std::string& dspt) override;
  /// Add an assertion
  virtual void add_an_assertion(const std::string& asst,
                                const std::string& dspt) override;
  /// Add a direct assumption
  virtual void add_a_direct_assumption(const std::string& aspt,
                                       const std::string& dspt) override;
  /// Add a direct assertion
  virtual void add_a_direct_assertion(const std::string& asst,
                                      const std::string& dspt) override;

  /// Add an assignment which in JasperGold could be an assignment, but in CoSA
  /// has to be an assumption
  virtual void add_wire_assign_assumption(const std::string& varname,
                                          const std::string& expression,
                                          const std::string& dspt) override;
  /// Add an assignment to a register which in JasperGold could be an
  /// assignment, but in CoSA has to be an assumption
  virtual void add_reg_cassign_assumption(const std::string& varname,
                                          const std::string& expression,
                                          int width, const std::string& cond,
                                          const std::string& dspt) override;

  /// Pre export work : nothing for cosa
  void virtual PreExportProcess() override {}
  /// export the script to run the verification
  virtual void Export_script(const std::string& script_name) override;
  /// export extra things (problem)
  virtual void
  Export_problem(const std::string& extra_name) override; // only for cosa
  /// export the memory abstraction (implementation)
  /// Yes, this is also implementation specific, (jasper may use a different
  /// one)
  virtual void Export_mem(const std::string& mem_name) override;
  /// For jasper, this means do nothing, for yosys, you need to add (*keep*)
  virtual void Export_modify_verilog() override;

public:
  /// It is okay to instantiation
  virtual void do_not_instantiate(void) override{};

}; // class VlgVerifTgtGenCosaJasper

}; // namespace ilang

#endif // ILANG_VTARGET_OUT_VTARGET_GEN_JASPER_H__
