/// \file Header for wrapper for verilog verification target generation
/// This is used to avoid include json explicitly
// --- Hongce Zhang

#ifndef VTARGET_GEN_H__
#define VTARGET_GEN_H__

#include <ilang/config.h>

#ifdef JSON_INOUT_ENABLE

namespace ilang {


/// \brief VlgVerifTgtGenBase: do nothing, should not instantiate
class VlgVerifTgtGenBase {
public:
  // constructor : do nothing
  VlgVerifTgtGenBase() {} 
  // destructor : do nothing (make it virtual !!!)
  virtual ~VlgVerifTgtGenBase() {}
private:
  // avoid instantiation 
  virtual void do_not_instantiate(void) = 0;
}; // class VlgVerifTgtGenBase

class VerilogVerificationTargetGenerator {
public:
  typedef enum { NONE = 0, COSA = 1, JASPERGOLD = 2 } backend_selector;

public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  ///
  /// \param[in] implementation's include path (if it uses `include)
  /// \param[in] verilog's path, currently we only handle situation where all in the same folder
  /// \param[in] name of the top module of the implementation, leave "" to allow auto analysis
  /// \param[in] where to get variable mapping 
  /// \param[in] where to get refinement relation
  /// \param[in] output path (ila-verilog, wrapper-verilog, problem.txt, run-verify-by-???, modify-impl, it there is )
  /// \param[in] pointer to the ila
  /// \param[in] the string 
  /// \param[in] (optional) the default configuration for outputing verilog
  VerilogVerificationTargetGenerator(
    const std::vector<std::string> & implementation_include_path,
    const std::vector<std::string> & implementation_srcs,
    const std::string              & implementation_top_module,
    const std::string              & refinement_variable_mapping,
    const std::string              & refinement_conditions,
    const std::string              & output_path,
    const InstrPtr                 & instr_ptr,
    backend_selector                 backend,
    const VerilogGenerator::VlgGenConfig& config = VerilogGenerator::VlgGenConfig() 
    );
  // --------------------- DECONSTRUCTOR ---------------------------- //
  ~VerilogVerificationTargetGenerator();
private:
  /// will be casted to different generator inside the implementation
  VlgVerifTgtGenBase * _generator;

}; // VerilogVerificationTargetGenerator

}; // namespace ilang

#endif // JSON_INOUT_ENABLE

#endif // VTARGET_GEN_H__