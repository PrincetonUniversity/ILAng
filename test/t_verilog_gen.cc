/// \file
/// Unit test for Verilog parser.

#include "verilog-out/verilog_gen.h"
#include "unit-include/simple_cpu.h"
#include "unit-include/util.h"

// always enabled, because we don't rely on other sources
// #ifdef VERILOG_OUT_ENABLE

namespace ila {

TEST(TestVerilogGen, Init) { VerilogGenerator(); }
TEST(TestVerilogGen, ParseInst) {
	auto ila_ptr_ = SimpleCpu("proc");
	// test 1 gen Add : internal mem
	{
		auto vgen = VerilogGenerator();

		//DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
		vgen.ExportTopLevelInstr( ila_ptr_->instr("Add") );
		vgen.DumpToFile(std::cout);
	}
	// test 2 gen Add : external mem
	{
		auto config = VerilogGenerator::VlgGenConfig( true , VerilogGenerator::VlgGenConfig::funcOption::Internal );
		auto vgen = VerilogGenerator( config );

		//DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
		vgen.ExportTopLevelInstr( ila_ptr_->instr("Add") );
		vgen.DumpToFile(std::cout);
	}
	// test 3 gen Load : internal mem
	{
		auto vgen = VerilogGenerator();
		//DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
		vgen.ExportTopLevelInstr( ila_ptr_->instr("Load") );
		vgen.DumpToFile(std::cout);
	}
	// test 4 gen Store : internal mem
	{
		auto vgen = VerilogGenerator();
		//DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
		vgen.ExportTopLevelInstr( ila_ptr_->instr("Store") );
		vgen.DumpToFile(std::cout);
	}
	// test 5 gen Load : external mem
	{
		auto config = VerilogGenerator::VlgGenConfig( true , VerilogGenerator::VlgGenConfig::funcOption::Internal );
		auto vgen = VerilogGenerator( config );
		//DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
		vgen.ExportTopLevelInstr( ila_ptr_->instr("Load") );
		vgen.DumpToFile(std::cout);
	}
	// test 6 gen Store : external mem
	{
		auto config = VerilogGenerator::VlgGenConfig( true , VerilogGenerator::VlgGenConfig::funcOption::Internal );
		auto vgen = VerilogGenerator( config );
		//DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
		vgen.ExportTopLevelInstr( ila_ptr_->instr("Store") );
		vgen.DumpToFile(std::cout);
	}
}


}; // namespace ila

// #endif // VERILOG_OUT_ENABLE
