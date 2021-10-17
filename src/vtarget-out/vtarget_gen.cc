/// \file Source for wrapper for verilog verification target generation
/// This is used to avoid include json explicitly
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <ilang/util/log.h>

namespace ilang {

bool VlgVerifTgtGenBase::isValidVerifBackend(ModelCheckerSelection vbackend) {
  if (vbackend == ModelCheckerSelection::PONO)
    return true;
  if (vbackend == ModelCheckerSelection::JASPERGOLD)
    return true;
  /*
  if (vbackend == ModelCheckerSelection::RELCHC)
    return true;
  if ((vbackend & ModelCheckerSelection::YOSYS) == ModelCheckerSelection::YOSYS) {
    if (vbackend == ModelCheckerSelection::ABCPDR)
      return true;
    if (vbackend == ModelCheckerSelection::BTOR_GENERIC)
      return true;
    if ((vbackend & ModelCheckerSelection::CHC) == ModelCheckerSelection::CHC) {
      if (vbackend == ModelCheckerSelection::ELD_CEGAR ||
          vbackend == ModelCheckerSelection::GRAIN_SYGUS ||
          vbackend == ModelCheckerSelection::Z3PDR)
        return true;
    }
  }*/
  return false;
}

VerilogVerificationTargetGenerator::VerilogVerificationTargetGenerator(
    const std::vector<std::string>& implementation_include_path,
    const std::vector<std::string>& implementation_srcs,
    const std::string& implementation_top_module,
    const std::string& refinement_variable_mapping,
    const std::string& refinement_conditions, const std::string& output_path,
    const InstrLvlAbsPtr& ila_ptr, ModelCheckerSelection backend,
    const RtlVerifyConfig& vtg_config,
    const VerilogGenerator::VlgGenConfig& notused)
    : _generator(new VlgVerifTgtGen(
          implementation_include_path, implementation_srcs,
          implementation_top_module,
          rfmap::VerilogRefinementMap(refinement_variable_mapping,
                                      refinement_conditions),
          output_path, ila_ptr, backend, vtg_config, NULL)) {}

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
