/// \file
/// Unit test for Verilog parser.

#include "verilog-out/verilog_gen.h"
#include "unit-include/simple_cpu.h"
#include "unit-include/util.h"

#ifdef VERILOG_OUT_ENABLE

namespace ila {

TEST(TestVerilogGen, Init) { VerilogGenerator(); }
TEST(TestVerilogGen, ParseInst) {
	auto ila_ptr_ = SimpleCpu("proc");

	auto vgen = VerilogGenerator();
	vgen.ExportTopLevelInstr(ila_ptr_);

	vgen.DumpToFile(std::cout);
}


}; // namespace ila

#endif // VERILOG_OUT_ENABLE
