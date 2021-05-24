/// \file Header for generating information to support
/// AQED
// --- Hongce Zhang (hongcez@princeton.edu)

#ifndef ILANG_AQED_OUT_AQED_OUT_H__
#define ILANG_AQED_OUT_AQED_OUT_H__

#include <ilang/ila/instr_lvl_abs.h>

namespace ilang {

/// \brief the interface class for info generator
/// must be instantiated through the factory
/// just to hide the implementation details
class AQedInfoGenerator {
  typedef std::shared_ptr<AQedInfoGenerator> AQedInfoGeneratorPtr;
public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  AQedInfoGenerator();
  // --------------------- DESTRUCTOR ---------------------------- //
  virtual ~AQedInfoGenerator();

  // --------------------- MEMBER FUNCTIONS ---------------------------- //
  /// Export the top-level io in  a file
  /// \param[in] filename to be exported
  virtual void ExportVerilogTopLevelIOInfo(const std::string& fname) = 0;
  /// Export the decode function and etc
  /// \param[in] filename to be exported
  virtual void ExportInstructionAndDecode(const std::string& filename) = 0;
  /// Export the signal references
  /// \param[in] filename to be exported
  virtual void ExportExtraSignalReferenced(const std::string& fname) = 0;
  /// the factory to create such an object
  static AQedInfoGeneratorPtr Create(
    const std::vector<std::string>& implementation_include_path,
    const std::vector<std::string>& implementation_srcs,
    const std::string& implementation_top_module,
    const std::string& refinement_variable_mapping,
    const std::string& refinement_conditions,
    const InstrLvlAbsCnstPtr& ila_ptr_);
}; // class AQedInfoGeneratorBase

}; // namespace ilang


#endif // ILANG_AQED_OUT_AQED_OUT_H__