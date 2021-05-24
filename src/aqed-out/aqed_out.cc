/// \file Source for generating information to support
/// AQED
// --- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/util/log.h>
#include <ilang/aqed-out/aqed_out.h>
#include <ilang/aqed-out/aqed_out_impl.h>
// header of implementation is only included in cc,
// not in its header


namespace ilang{

AQedInfoGenerator::AQedInfoGenerator() {} // do nothing
AQedInfoGenerator::~AQedInfoGenerator() {} // do nothing

AQedInfoGenerator::AQedInfoGeneratorPtr
AQedInfoGenerator::Create(
    const std::vector<std::string>& implementation_include_path,
    const std::vector<std::string>& implementation_srcs,
    const std::string& implementation_top_module,
    const std::string& refinement_variable_mapping,
    const std::string& refinement_conditions,
    const InstrLvlAbsCnstPtr& ila_ptr_) {
  return std::make_shared<AQedInfoGeneratorImpl>(
    implementation_include_path,
    implementation_srcs,
    implementation_top_module,
    refinement_variable_mapping,
    refinement_conditions,
    ila_ptr_ );
}

}; // namespace ilang