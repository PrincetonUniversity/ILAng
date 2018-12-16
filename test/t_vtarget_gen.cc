/// \file
/// Unit test for generating Verilog verification target

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/synth-interface/synth_engine_interface.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/cpp_api.h>

#include "unit-include/config.h"
#include "unit-include/util.h"
#include "unit-include/pipe_ila.h"

namespace ilang {


TEST(TestVlgTargetGen, AesIlaInfo) {
  SetToStdErr(1);

  auto aesFile = std::string(TEST_CONFIG_TEST_ROOT) + "/unit-data/aes_v/all";
  auto aesuFile = std::string(TEST_CONFIG_TEST_ROOT) + "/unit-data/aes_v/allu";
  auto aes = ImportSynthAbsFromFile(aesFile, "AES");
  auto aesu = ImportSynthAbsFromFile(aesuFile, "AES_U");

  //aes->AddChild(aesu);

  ILA_DLOG("TestVlgTargetGen.IlaInfo") << "No. instr:" << aes->instr_num();
  for (unsigned i = 0; i< aes->instr_num() ; ++ i) {
  	ILA_DLOG("TestVlgTargetGen.IlaInfo") << "\t"<<aes->instr(i)->name().str() << "\t"<<aes->instr(i)->decode();
  }
  ILA_DLOG("TestVlgTargetGen.IlaInfo") << "No. state:" << aes->state_num();
  for (unsigned i = 0; i < aes->state_num() ; ++ i ) {
  	ILA_DLOG("TestVlgTargetGen.IlaInfo") << "\t"<<aes->state(i)->name().str();
  }
  ILA_DLOG("TestVlgTargetGen.IlaInfo") << std::endl;


  ILA_DLOG("TestVlgTargetGen.IlaInfo") << "No. instr:" << aesu->instr_num();
  for (unsigned i = 0; i< aes->instr_num() ; ++ i) {
  	ILA_DLOG("TestVlgTargetGen.IlaInfo") << "\t"<<aesu->instr(i)->name().str() << "\t"<<aesu->instr(i)->decode();
  }
  ILA_DLOG("TestVlgTargetGen.IlaInfo") << "No. state:" << aesu->state_num();
  for (unsigned i = 0; i < aesu->state_num() ; ++ i ) {
  	ILA_DLOG("TestVlgTargetGen.IlaInfo") << "\t"<<aesu->state(i)->name().str();
  }
  ILA_DLOG("TestVlgTargetGen.IlaInfo") << std::endl;

  SetToStdErr(0);
}

#ifdef VERILOG_IN_ENABLE
#ifdef JSON_INOUT_ENABLE

TEST(TestVlgTargetGen, PipeExample) {
	auto ila_model = SimplePipe::BuildModel();

	auto dirName = std::string(TEST_CONFIG_TEST_ROOT) + "/unit-data/vpipe/";
	VerilogVerificationTargetGenerator vg(
		{}, // no include
		{dirName+"simple_pipe.v"}, // 
		"pipeline_v", // top_module_name
		dirName+"rfmap/vmap.json", // variable mapping
		dirName+"rfmap/cond.json",
		dirName+"verify/",
		ila_model.get(),
		VerilogVerificationTargetGenerator::backend_selector::COSA
		);
	

	EXPECT_FALSE(vg.in_bad_state());

	vg.GenerateTargets();
}

TEST(TestVlgTargetGen, AesExample) {

}

#endif // JSON_INOUT_ENABLE
#endif // VERILOG_IN_ENABLE

}; // namespace ilang
