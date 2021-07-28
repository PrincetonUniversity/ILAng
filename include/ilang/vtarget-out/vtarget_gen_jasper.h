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
      const rfmap::VerilogRefinementMap & refinement,
      VerilogInfo* _vlg_info_ptr, const std::string& wrapper_name,
      const std::vector<std::string>& implementation_srcs,
      const std::vector<std::string>& include_dirs,
      const vtg_config_t& vtg_config, backend_selector backend,
      const target_type_t& target_tp, advanced_parameters_t* adv_ptr);


protected:
  /// internal storage of problems
  /// vector of pairs of <assumption, description>
  std::vector<std::pair<std::string, std::string>> assumptions;
  /// vector of pairs of <assertions, description>
  std::vector<std::pair<std::string, std::string>> assertions;
  /// vector of clock signals that need to be taken care of
                             
  /// Name of the problem file
  std::string jg_script_name;

protected:
  /// Add SMT-lib2 assumption
  virtual void add_a_direct_smt_assumption(const std::string& arg,
                                       const std::string& ret,
                                       const std::string& body,
                                       const std::string& dspt) override;
  /// Add SMT-lib2 assertion
  virtual void add_a_direct_smt_assertion(const std::string& arg,
                                      const std::string& ret,
                                      const std::string& body,
                                      const std::string& dspt) override;
  /// Add an assumption
  virtual void add_an_assumption(const rfmap::RfExpr& aspt,
                                 const std::string& dspt) override;
  /// Add an assertion
  virtual void add_an_assertion(const rfmap::RfExpr& asst,
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
                                          const rfmap::RfExpr& expression,
                                          const std::string& dspt) override;

  /// Pre export work : nothing for cosa
  void virtual PreExportProcess() override {}
  /// export the script to run the verification
  virtual void Export_script(const std::string& script_name) override;
  /// export extra things (problem)
  virtual void
  Export_problem(const std::string& extra_name) override; // only for cosa
  /// For jasper, this means do nothing, for yosys, you need to add (*keep*)
  virtual void Export_modify_verilog() override;

public:
  /// It is okay to instantiation
  virtual void do_not_instantiate(void) override{};

}; // class VlgVerifTgtGenCosaJasper

}; // namespace ilang

#endif // ILANG_VTARGET_OUT_VTARGET_GEN_JASPER_H__
