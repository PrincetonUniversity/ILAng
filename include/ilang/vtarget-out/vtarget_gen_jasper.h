/// \file Verilog Verification Target Generator -- for CoSA
// ---Hongce Zhang

#ifndef VTARGET_GEN_JASPER_H__
#define VTARGET_GEN_JASPER_H__

#include <ilang/vtarget-out/vtarget_gen_impl.h>

namespace ilang {


class VlgVerifTgtGenCosa_Jasper : public VlgVerifTgtGen {
  
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
    VlgVerifTgtGenCosa_Jasper(
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

}; // class VlgVerifTgtGenCosaJasper


}; // namespace ilang

#endif // VTARGET_GEN_JASPER_H__