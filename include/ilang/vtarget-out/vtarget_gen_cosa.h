/// \file Verilog Verification Target Generator -- for JasperGold
/// This file should not be included, as it requires the impl.
/// Internally, we use the 
// ---Hongce Zhang

#ifndef VTARGET_GEN_COSA_H__
#define VTARGET_GEN_COSA_H__

#include <ilang/vtarget-out/vtarget_gen_impl.h>

namespace ilang {


/// \brief a class to store (and generate) the problem for cosa
class Cosa_problem {
  /// Type of assertions and assumptions
  typedef std::vector<std::string> prop_t;

protected:
  prop_t  assumptions;
  prop_t  assertions;

public:
  

}; // Cosa_problem

/// \brief a class to interface w.  COSA
class VlgVerifTgtGen_Cosa : public VlgVerifTgtGen {
public:
  // --------------------- CONSTRUCTOR ---------------------------- //
    /// To construct a target generator
    /// \param[in] implementation's include path (if it uses `include)
    /// \param[in] verilog's path, currently we only handle situation where all in the same folder
    /// \param[in] name of the top module of the implementation, leave "" to allow auto analysis
    /// \param[in] where to get variable mapping 
    /// \param[in] where to get refinement relation
    /// \param[in] output path (ila-verilog, wrapper-verilog, problem.txt, run-verify-by-???, modify-impl, it there is )
    /// \param[in] pointer to the ila
    /// \param[in] (optional) the default configuration for outputing verilog
    VlgVerifTgtGen_Cosa(
      const std::vector<std::string> & implementation_include_path,
      const std::vector<std::string> & implementation_srcs,
      const std::string              & implementation_top_module,
      const std::string              & refinement_variable_mapping,
      const std::string              & refinement_conditions,
      const std::string              & output_path,
      const InstrPtr                 & instr_ptr,
      const VerilogGenerator::VlgGenConfig& config = VlgGenConfig() 
      );

private:
  // It is okay to instantiation 
  virtual void do_not_instantiate(void) override {} ;

}; // class VlgVerifTgtGenCosa  

}; // namespace ilang

#endif // VTARGET_GEN_COSA_H__