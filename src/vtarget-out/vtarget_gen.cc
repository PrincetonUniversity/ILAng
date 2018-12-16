/// \file Source for wrapper for verilog verification target generation
/// This is used to avoid include json explicitly
// --- Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>
#include <ilang/vtarget-out/vtarget_gen_cosa.h>
#include <ilang/vtarget-out/vtarget_gen_jasper.h>

namespace ilang {

VerilogVerificationTargetGenerator::VerilogVerificationTargetGenerator(
    const std::vector<std::string> & implementation_include_path,
    const std::vector<std::string> & implementation_srcs,
    const std::string              & implementation_top_module,
    const std::string              & refinement_variable_mapping,
    const std::string              & refinement_conditions,
    const std::string              & output_path,
    const InstrPtr                 & instr_ptr,
    backend_selector                 backend,
    const VerilogGenerator::VlgGenConfig& config = VerilogGenerator::VlgGenConfig() 
    ) : _generator(NULL) {

	if (backend == backend_selector::COSA) {
		_generator = new VlgVerifTgtGen_Cosa(
			implementation_include_path,
			implementation_srcs,
			implementation_top_module,
			refinement_variable_mapping,
			refinement_conditions,
			output_path,
			instr_ptr,
			config );
	} else if (backend == backend_selector::JASPERGOLD ) {
		_generator = new VlgVerifTgtGen_Jasper(
			implementation_include_path,
			implementation_srcs,
			implementation_top_module,
			refinement_variable_mapping,
			refinement_conditions,
			output_path,
			instr_ptr,
			config );
	} else ILA_ERROR << "Unknown backend specified #"<<backend;
}

VerilogVerificationTargetGenerator::~VerilogVerificationTargetGenerator();
{ if (_generator) delete _generator; }



}; // namespace ilang
