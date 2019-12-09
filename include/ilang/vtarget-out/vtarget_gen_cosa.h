/// \file Verilog Verification Target Generator -- for CoSA
/// This file should not be included, as it requires the impl.
// ---Hongce Zhang

#ifndef ILANG_VTARGET_OUT_VTARGET_GEN_COSA_H__
#define ILANG_VTARGET_OUT_VTARGET_GEN_COSA_H__

#include <ilang/vtarget-out/vlg_mod.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <iostream>
#include <string>
#include <vector>

#include <ilang/config.h>
#include <ilang/ila/instr_lvl_abs.h>

namespace ilang {

class VlgSglTgtGen_Cosa;

/// \brief a class to store (and generate) the problem for cosa
class Cosa_problem {
  friend class VlgSglTgtGen_Cosa;
  /// Type of assertions and assumptions
  typedef std::vector<std::string> prop_t;
  /// Type of a problem --- we  can handle multiple several problems (may not
  /// needed)
  typedef struct {
    // the name in [??]
    // std::string  problem_name;
    /// will be conjuncted and put in the question
    prop_t assertions;
  } problem_t;
  /// set of problems
  typedef std::map<std::string, problem_t> problemset_t;

protected:
  /// assumptions are shared
  prop_t assumptions;
  /// problems are splitted into items
  problemset_t probitem;

}; // Cosa_problem

/// \brief a class to interface w.  COSA
class VlgSglTgtGen_Cosa : public VlgSglTgtGen {
  /// using the target type
  using target_type_t = VlgSglTgtGen::target_type_t;
  /// a tuple to store all related info for modification
  using info_t = VerilogModifier::info_t;
  /// filename -> (lineno, varname, is_port_sig) vec
  using fn_l_map_t = VerilogModifier::fn_l_map_t;
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
  VlgSglTgtGen_Cosa(
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

protected:
  /// Cosa problem generate
  Cosa_problem _problems;
  /// Cosa problem file name
  std::string cosa_prob_fname;

protected:
  /// Add a direct assumption
  virtual void add_a_direct_assumption(const std::string& aspt,
                                       const std::string& dspt) override;
  /// Add a direct assertion
  virtual void add_a_direct_assertion(const std::string& asst,
                                      const std::string& dspt) override;

  /// Pre export work : nothing for cosa
  void virtual PreExportProcess() override {}
  /// export the script to run the verification
  virtual void Export_script(const std::string& script_name) override;
  /// export extra things (problem)
  virtual void
  Export_problem(const std::string& extra_name) override; // only for cosa
  /// generate along-side a jg script that you can use in JasperGold
  virtual void Export_jg_tester_script(const std::string& extra_name);

  /// export the memory abstraction (implementation)
  /// Yes, this is also implementation specific, (jasper may use a different
  /// one)
  virtual void Export_mem(const std::string& mem_name) override;
  /// For jasper, this means do nothing, for yosys, you need to add (*keep*)
  virtual void Export_modify_verilog() override;

public:
  /// It is okay to instantiation
  virtual void do_not_instantiate(void) override{};

}; // class VlgVerifTgtGenCosa

}; // namespace ilang

#endif // ILANG_VTARGET_OUT_VTARGET_GEN_COSA_H__
