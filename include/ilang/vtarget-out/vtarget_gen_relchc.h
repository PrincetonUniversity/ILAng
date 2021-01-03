/// \file Verilog Verification Target Generator -- for Relchc 
/// We use yosys to convert Verilog to smt-lib2, and then
/// it will be converted to horn clause
/// This file should not be included, as it requires the impl.
/// Internally, we use the
// ---Hongce Zhang

#ifndef VTARGET_GEN_RELCHC_H__
#define VTARGET_GEN_RELCHC_H__

#include <ilang/config.h>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/vtarget-out/vlg_mod.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>
#include <iostream>
#include <string>
#include <vector>

namespace ilang {

class VlgSglTgtGen_Relchc;

/// \brief a class to store (and generate) the problem for Relchc (Z3)
class Relchc_problem {
  friend class VlgSglTgtGen_Relchc;
  /// Type of assertions and assumptions
  typedef std::vector<std::string> prop_t;
  /// Type of a problem --- we  can handle multiple several problems (may not
  /// needed)
  typedef struct {
    // the name in [??]
    // std::string  problem_name;
    /// will be conjuncted and put in the question
    prop_t exprs;
  } problem_t;
  /// set of problems
  typedef std::map<std::string, problem_t> problemset_t;

protected:
  /// assumptions are not shared (unlike CoSA)
  problemset_t assumptions;
  /// problems are splitted into items
  problemset_t assertions;

}; // Relchc_problem


/// \brief a class to interface w.  Relchc Z3
class VlgSglTgtGen_Relchc : public VlgSglTgtGen {
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
  VlgSglTgtGen_Relchc(
      const std::string& output_path, // will be a sub directory of the
                                      // output_path of its parent
      const InstrPtr& instr_ptr, // which could be an empty pointer, and it will
                                 // be used to verify invariants
      const InstrLvlAbsPtr& ila_ptr,
      const VerilogGenerator::VlgGenConfig& config, nlohmann::json& _rf_vmap,
      nlohmann::json& _rf_cond, VlgTgtSupplementaryInfo & _sup_info, VerilogInfo* _vlg_info_ptr,
      const std::string& vlg_mod_inst_name,
      const std::string& ila_mod_inst_name, const std::string& wrapper_name,
      const std::vector<std::string>& implementation_srcs,
      const std::vector<std::string>& include_dirs,
      const vtg_config_t& vtg_config, backend_selector backend,
      const target_type_t& target_tp,
      advanced_parameters_t * adv_ptr);
  
  /// Destructor: do nothing , most importantly it is virtual
  virtual ~VlgSglTgtGen_Relchc() {}

protected:
  /// Relchc problem generate
  Relchc_problem _problems;
  /// Relchc problem file name
  std::string relchc_prob_fname;
  /// Relchc script 'run.sh' name
  std::string relchc_run_script_name;
  /// the invariants on the design
  std::vector<std::string> vlg_mod_inv_vec;

protected:
  /// Add a direct assumption -- needed by base class
  virtual void add_a_direct_assumption(const std::string& aspt,
                                       const std::string& dspt) override;
  /// Add a direct assertion -- needed by base class
  virtual void add_a_direct_assertion(const std::string& asst,
                                      const std::string& dspt) override;

  /// Pre export work : add assume and asssert to the top level
  void virtual PreExportProcess() override;
  /// export the script to run the verification
  virtual void Export_script(const std::string& script_name) override;
  /// export extra things: the relchc script, the smt template
  virtual void
  Export_problem(const std::string& extra_name) override;
  /// export the memory abstraction (implementation)
  /// Yes, this is also implementation specific, (jasper may use a different
  /// one)
  virtual void Export_mem(const std::string& mem_name) override;
  /// For jasper, this means do nothing, for relchc, you need to add (*keep*)
  virtual void Export_modify_verilog() override;

private:
  // Here begins the specific functions
  // single_inv_problem()  : gensmt.ys
  // dual_inv_problem()    : gensmt.ys
  // single_inv_script()   : same run.sh
  // dual_inv_script() 
  // single_inv_tpl() :
  // dual_inv_tpl() :

  /// generate the Relchc script for dual invariant
  void dual_inv_problem(const std::string& ys_script_name);

  /// generate the template file
  void dual_inv_tpl(const std::string & tpl_name, const std::string & smt_info);

  /// generate the wrapper's smt first
  std::string dual_inv_gen_smt(
    const std::string & smt_name,
    const std::string & ys_script_name);
  

public:
                         
  /// Deprecation of the one without smt info
  void virtual ExportAll(const std::string& wrapper_name,
                         const std::string& ila_vlg_name,
                         const std::string& script_name,
                         const std::string& extra_name,
                         const std::string& mem_name) override;
  

  /// It is okay to instantiation
  virtual void do_not_instantiate(void) override { };

}; // class VlgVerifTgtGenRelchc


}; // namespace ilang

#endif // VTARGET_GEN_RELCHC_H__
