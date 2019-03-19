/// \file Source for wrapper for verilog verification target generation
/// This is used to avoid include json explicitly
// --- Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>

namespace ilang {

VerilogVerificationTargetGenerator::VerilogVerificationTargetGenerator(
    const std::vector<std::string>& implementation_include_path,
    const std::vector<std::string>& implementation_srcs,
    const std::string& implementation_top_module,
    const std::string& refinement_variable_mapping,
    const std::string& refinement_conditions, const std::string& output_path,
    const InstrLvlAbsPtr& ila_ptr, backend_selector backend,
    const vtg_config_t& vtg_config,
    const VerilogGenerator::VlgGenConfig& config,
    advanced_parameters_t * adv_ptr)
    : _generator(new VlgVerifTgtGen(
          implementation_include_path, implementation_srcs,
          implementation_top_module, refinement_variable_mapping,
          refinement_conditions, output_path, ila_ptr, backend, vtg_config,
          config, adv_ptr)) {}

VerilogVerificationTargetGenerator::~VerilogVerificationTargetGenerator() {
  if (_generator)
    delete _generator;
}

void VerilogVerificationTargetGenerator::GenerateTargets(void) {
  VlgVerifTgtGen* ptr_ = dynamic_cast<VlgVerifTgtGen*>(_generator);
  ILA_NOT_NULL(ptr_);
  ptr_->GenerateTargets();
}

bool VerilogVerificationTargetGenerator::in_bad_state(void) const {
  VlgVerifTgtGen* ptr_ = dynamic_cast<VlgVerifTgtGen*>(_generator);
  ILA_NOT_NULL(ptr_);
  return ptr_->in_bad_state();
}

std::string VerilogVerificationTargetGenerator::GetVlgModuleInstanceName(void) const {
  VlgVerifTgtGen* ptr_ = dynamic_cast<VlgVerifTgtGen*>(_generator);
  ILA_NOT_NULL(ptr_);
  return ptr_->GetVlgModuleInstanceName();
}

}; // namespace ilang
