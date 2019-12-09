/// \file Verilog Verification Target Generator -- generating CHC target to
/// enhance invariant (design-only, same as the invariant target) We use yosys
/// to convert Verilog to smt-lib2, and then it will be parsed and re-format by
/// smt-io and use that information, it will create horn clauses This file
/// should not be included by the user code, as it requires the impl.

/// This is for Grain only invariant enhancements/strengthening by syntax
// ---Hongce Zhang

#ifndef VTARGET_GEN_INV_ENHANCE_H__
#define VTARGET_GEN_INV_ENHANCE_H__

#include <ilang/config.h>
#ifdef INVSYN_INTERFACE

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/smt-inout/yosys_smt_parser.h>
#include <ilang/vtarget-out/inv-syn/inv_cnf.h>
#include <ilang/vtarget-out/vlg_mod.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace ilang {

class VlgSglTgtGen_Chc_wCNF;

/// \brief a class to store (and generate) the problem for Chc
class Chc_enhance_problem {
  friend class VlgSglTgtGen_Chc_wCNF;
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

}; // Chc_enhance_problem

/// \brief a class to interface w.  Chc
class VlgSglTgtGen_Chc_wCNF : public VlgSglTgtGen {

public:
  /// using the target type
  using target_type_t = VlgSglTgtGen::target_type_t;
  /// a tuple to store all related info for modification
  using info_t = VerilogModifier::info_t;
  /// filename -> (lineno, varname, is_port_sig) vec
  using fn_l_map_t = VerilogModifier::fn_l_map_t;
  /// Type of advanced parameter
  using advanced_parameters_t = VlgVerifTgtGenBase::advanced_parameters_t;
  /// Type of chc target
  using _chc_target_t = VlgVerifTgtGenBase::_chc_target_t;

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
  VlgSglTgtGen_Chc_wCNF(
      const std::string& output_path, // will be a sub directory of the
                                      // output_path of its parent
      const InstrPtr& instr_ptr, // which could be an empty pointer, and it will
                                 // be used to verify invariants
      const InstrLvlAbsPtr& ila_ptr,
      const VerilogGenerator::VlgGenConfig& config, nlohmann::json& _rf_vmap,
      nlohmann::json& _rf_cond, VlgTgtSupplementaryInfo& _sup_info,
      VerilogInfo* _vlg_info_ptr, const std::string& vlg_mod_inst_name,
      const std::string& ila_mod_inst_name, const std::string& wrapper_name,
      const std::vector<std::string>& implementation_srcs,
      const std::vector<std::string>& include_dirs,
      const vtg_config_t& vtg_config, backend_selector vbackend,
      synthesis_backend_selector sbackend, const target_type_t& target_tp,
      advanced_parameters_t* adv_ptr, bool generate_proof,
      _chc_target_t chc_target);

  // --------------------- Destructor ---------------------------- //
  /// do nothing
  virtual ~VlgSglTgtGen_Chc_wCNF();

protected:
  /// Chc problem generate
  Chc_enhance_problem _problems;
  /// Chc problem file name
  std::string chc_prob_fname;
  /// Chc script 'run.sh' name
  std::string chc_run_script_name;
  /// the invariants on the design
  std::vector<std::string> vlg_mod_inv_vec;
  /// the synthesis backend
  synthesis_backend_selector s_backend;
  /// the smt info of the design
  std::shared_ptr<smt::YosysSmtParser> design_smt_info;
  /// whether to require a proof
  bool generate_proof;
  /// whether a cex is provided
  bool has_cex;
  /// what are the targets
  _chc_target_t chc_target;

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
  virtual void Export_script(const std::string& script_name)
      override; // do nothing - should not be used
  virtual void Export_script(const std::string& script_name,
                             const std::string& cnf_fn);
  /// export extra things: the chc script, the smt template
  virtual void Export_problem(const std::string& extra_name) override;
  /// export the memory abstraction (implementation)
  /// Yes, this is also implementation specific, (jasper may use a different
  /// one)
  virtual void Export_mem(const std::string& mem_name) override;
  /// For jasper, this means do nothing, for chc, you need to add (*keep*)
  virtual void Export_modify_verilog() override;
  /// Export the cnf for Grain's reference
  void Export_cnf(const InvariantInCnf& cnf, const std::string& cnf_fn) const;
  /// Export the cnf for wky's Grain's reference
  void Export_coci(const InvariantInCnf& cnf, const std::string& cnf_fn) const;

private:
  /// Convert the smt file to CHC -- datatype encoding
  void convert_smt_to_chc_datatype(const std::string& smt_fname,
                                   const std::string& chc_fname);
  /// generate the wrapper's smt first
  void design_only_gen_smt(const std::string& smt_name,
                           const std::string& ys_script_name);

public:
  /// do nothing - should not be used
  void virtual ExportAll(const std::string& wrapper_name,
                         const std::string& ila_vlg_name,
                         const std::string& script_name,
                         const std::string& extra_name,
                         const std::string& mem_name) override;
  /// overwrite the Export, use this one:
  void virtual ExportAll(const std::string& wrapper_name,
                         const std::string& ila_vlg_name,
                         const std::string& script_name,
                         const std::string& extra_name,
                         const std::string& mem_name,
                         const std::string& cnf_name,
                         const InvariantInCnf& cnf);
  /// accessor of the design info
  std::shared_ptr<smt::YosysSmtParser> GetDesignSmtInfo() const;
  /// It is okay to instantiation
  virtual void do_not_instantiate(void) override{};

}; // class VlgVerifTgtGenChc

}; // namespace ilang

#endif // INVSYN_INTERFACE

#endif // VTARGET_GEN_INV_ENHANCE_H__
