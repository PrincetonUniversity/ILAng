/// \file Verilog Verification Target Generator -- for Pono
/// This file should not be included, as it requires the impl.
// ---Hongce Zhang

#ifndef ILANG_VTARGET_OUT_VTARGET_GEN_PONO_H__
#define ILANG_VTARGET_OUT_VTARGET_GEN_PONO_H__

#include <ilang/vtarget-out/vlg_mod.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <iostream>
#include <string>
#include <vector>

#include <ilang/config.h>
#include <ilang/ila/instr_lvl_abs.h>

namespace ilang {

class VlgSglTgtGen_Pono;

/// \brief a class to store (and generate) the problem for pono
class Pono_problem {
  friend class VlgSglTgtGen_Pono;
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
  /// assumptions are not shared
  problemset_t assumptions;
  /// problems are splitted into items
  problemset_t assertions;
  /// problems are splitted into items
  problemset_t sanity_assertions;
  /// problems are splitted into items
  problemset_t cover_checks;

  /// SMT-LIB2 assumptions
  prop_t smt_assumptions;
  /// SMT-LIB2 assertions
  prop_t smt_assertions;

}; // Pono_problem

/// \brief a class to interface w.  PONO
class VlgSglTgtGen_Pono : public VlgSglTgtGen {
public:
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
  /// run-verify-by-???, modify-impl, it there is )
  /// \param[in] pointer to the instruction
  /// \param[in] the refinement map
  /// \param[in] pointer to verify info class
  /// \param[in] verilog module name
  /// \param[in] ila module name,
  /// \param[in] all implementation sources
  /// \param[in] all include paths
  /// \param[in] which backend to use, it needs this info to gen proper
  /// properties
  VlgSglTgtGen_Pono(
      const std::string& output_path, // will be a sub directory of the
                                      // output_path of its parent
      const InstrPtr& instr_ptr, // which could be an empty pointer, and it will
                                 // be used to verify invariants
      const InstrLvlAbsPtr& ila_ptr,
      const rfmap::VerilogRefinementMap& refinement, VerilogInfo* _vlg_info_ptr,
      const std::string& wrapper_name,
      const std::vector<std::string>& implementation_srcs,
      const std::vector<std::string>& include_dirs,
      const RtlVerifyConfig& vtg_config, ModelCheckerSelection backend,
      const target_type_t& target_tp, advanced_parameters_t* adv_ptr);

protected:
  /// Pono problem generate
  Pono_problem _problems;
  /// Pono problem file name
  std::string ys_script_name;
  /// all cover assert property names
  std::vector<std::string> all_cover_assert_property_names;

protected:
  /// Add a direct assumption
  virtual void add_a_direct_assumption(const std::string& aspt,
                                       const std::string& dspt) override;
  /// Add a direct assertion
  virtual void add_a_direct_assertion(const std::string& asst,
                                      const std::string& dspt) override;
  /// Add a direct sanity assertion
  virtual void add_a_direct_sanity_assertion(const std::string& asst,
                                             const std::string& dspt) override;
  /// Add a direct cover check
  virtual void add_a_direct_cover_check(const std::string& asst,
                                        const std::string& dspt) override;

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

  /// Pre export work : nothing for pono
  void virtual PreExportProcess() override;

  // A helper function to generate Yosys script
  void GenYosysScript(
      const std::string& ys_script_name_path,
      const std::string& property_selection_cmd,
      const std::string& generated_btor_name );

  /// export the script to run the verification
  virtual void Export_script(const std::string& script_name) override;
  /// export extra things (problem)
  virtual void
  Export_problem(const std::string& extra_name) override; // only for pono

  /// For jasper, this means do nothing, for yosys, you need to add (*keep*)
  virtual void Export_modify_verilog() override;

public:
  /// It is okay to instantiation
  virtual void do_not_instantiate(void) override{};

}; // class VlgVerifTgtGenPono

}; // namespace ilang

#endif // ILANG_VTARGET_OUT_VTARGET_GEN_PONO_H__
