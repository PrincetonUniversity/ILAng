/// \file Verilog Verification Target Generator -- for JasperGold
/// This file should not be included, as it requires the impl.
/// Internally, we use the 
// ---Hongce Zhang

#ifndef VTARGET_GEN_COSA_H__
#define VTARGET_GEN_COSA_H__


#include <ilang/config.h>

#ifdef JSON_INOUT_ENABLE

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>
#include <iostream>
#include <string>
#include <vector>

namespace ilang {

class VlgSglTgtGen_Cosa;

/// \brief a class to store (and generate) the problem for cosa
class Cosa_problem {
  friend class VlgSglTgtGen_Cosa;
  /// Type of assertions and assumptions
  typedef std::vector<std::string> prop_t;
  /// Type of a problem --- we  can handle multiple several problems (may not needed)
  typedef struct {
    std::string problem_name;
    prop_t  assumptions;
    prop_t  assertions;
  } problem_t;
  /// set of problems
  typedef std::vector<problem_t> problemset_t;

protected:
  problemset_t _ps;

public:
  void generate_to_file(std::ostream & os) const;
  

}; // Cosa_problem

/// \brief a class to interface w.  COSA
class VlgSglTgtGen_Cosa : public VlgSglTgtGen {
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
  VlgSglTgtGen_Cosa(
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
  );

protected:
  /// Cosa problem generate
  Cosa_problem _problems;

protected:
  /// Add an assumption
  virtual void add_an_assumption(const std::string & aspt, const std::string & dspt) override;
  /// Add an assertion
  virtual void add_an_assertion (const std::string & asst, const std::string & dspt) override;

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
  // It is okay to instantiation 
  virtual void do_not_instantiate(void) override {} ;


}; // class VlgVerifTgtGenCosa  

}; // namespace ilang

#endif // JSON_INOUT_ENABLE

#endif // VTARGET_GEN_COSA_H__