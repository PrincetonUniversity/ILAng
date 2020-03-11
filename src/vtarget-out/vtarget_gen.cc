/// \file Source for wrapper for verilog verification target generation
/// This is used to avoid include json explicitly
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <ilang/util/log.h>

namespace ilang {

bool VlgVerifTgtGenBase::isValidVerifBackend(backend_selector vbackend) {
  if (vbackend == backend_selector::COSA)
    return true;
  if (vbackend == backend_selector::JASPERGOLD)
    return true;
  if (vbackend == backend_selector::RELCHC)
    return true;
  if ((vbackend & backend_selector::YOSYS) == backend_selector::YOSYS) {
    if (vbackend == backend_selector::ABCPDR)
      return true;
    if (vbackend == backend_selector::BTOR_GENERIC)
      return true;
    if ((vbackend & backend_selector::CHC) == backend_selector::CHC) {
      if (vbackend == backend_selector::ELD_CEGAR ||
          vbackend == backend_selector::GRAIN_SYGUS ||
          vbackend == backend_selector::Z3PDR)
        return true;
    }
  }
  return false;
}

VerilogVerificationTargetGenerator::VerilogVerificationTargetGenerator(
    const std::vector<std::string>& implementation_include_path,
    const std::vector<std::string>& implementation_srcs,
    const std::string& implementation_top_module,
    const std::string& refinement_variable_mapping,
    const std::string& refinement_conditions, const std::string& output_path,
    const InstrLvlAbsPtr& ila_ptr, backend_selector backend,
    const vtg_config_t& vtg_config,
    const VerilogGenerator::VlgGenConfig& config)
    : _generator(new VlgVerifTgtGen(
          implementation_include_path, implementation_srcs,
          implementation_top_module, refinement_variable_mapping,
          refinement_conditions, output_path, ila_ptr, backend, vtg_config,
          config, NULL)) {}

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

std::string
VerilogVerificationTargetGenerator::GetVlgModuleInstanceName(void) const {
  VlgVerifTgtGen* ptr_ = dynamic_cast<VlgVerifTgtGen*>(_generator);
  ILA_NOT_NULL(ptr_);
  return ptr_->GetVlgModuleInstanceName();
}

}; // namespace ilang
