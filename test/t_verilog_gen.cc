/// \file
/// Unit test for Verilog parser.
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "verilog-out/verilog_gen.h"
#include "verilog-in/verilog_parse.h"

#include "unit-include/simple_cpu.h"
#include "unit-include/util.h"

// always enabled, because we don't rely on other sources
// #ifdef VERILOG_OUT_ENABLE

namespace ila {


#ifdef VERILOG_IN_ENABLE
void parseable(const std::string &fname, VerilogGenerator & vgen ) {
	std::ofstream fout(fname);
	if( fout.is_open() ) {
		vgen.DumpToFile( fout );
		fout.close();
	}
	else 
		ILA_WARN << "Cannot write tmpfile for vlog gen test.";

	std::FILE * fp = std::fopen("./t_proc_Add.v", "r");
	if(fp) {
		int result = TestParseVerilogFrom(fp);
		std::fclose(fp);
		EXPECT_EQ(result, 0);			
	}
	else
		ILA_WARN << "Cannot read tmpfile for vlog gen test.";
}
#endif

TEST(TestVerilogGen, Init) { VerilogGenerator(); }
TEST(TestVerilogGen, ParseInst) {
	auto ila_ptr_ = SimpleCpu("proc");
	// test 1 gen Add : internal mem
	{
		auto vgen = VerilogGenerator();

		//DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
		vgen.ExportTopLevelInstr( ila_ptr_->instr("Add") );

#ifdef VERILOG_IN_ENABLE
		parseable( "Testing/Temporary/t_proc_Add.v" , vgen);
#else
		vgen.DumpToFile( ILA_DLOG("TestVerilogGen.ParseInst") );
#endif
	}
	// test 2 gen Add : external mem
	{
		auto config = VerilogGenerator::VlgGenConfig( true , VerilogGenerator::VlgGenConfig::funcOption::Internal );
		auto vgen = VerilogGenerator( config );

		//DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
		vgen.ExportTopLevelInstr( ila_ptr_->instr("Add") );

#ifdef VERILOG_IN_ENABLE
		parseable( "Testing/Temporary/t_proc_Add_extmem.v" , vgen);
#else
		vgen.DumpToFile( ILA_DLOG("TestVerilogGen.ParseInst") );
#endif

	}
	// test 3 gen Load : internal mem
	{
		auto vgen = VerilogGenerator();
		//DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
		vgen.ExportTopLevelInstr( ila_ptr_->instr("Load") );
#ifdef VERILOG_IN_ENABLE
		parseable( "Testing/Temporary/t_proc_Load.v" , vgen);
#else
		vgen.DumpToFile( ILA_DLOG("TestVerilogGen.ParseInst") );
#endif
	}
	// test 4 gen Store : internal mem
	{
		auto vgen = VerilogGenerator();
		//DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
		vgen.ExportTopLevelInstr( ila_ptr_->instr("Store") );
#ifdef VERILOG_IN_ENABLE
		parseable( "Testing/Temporary/t_proc_Store.v" , vgen);
#else
		vgen.DumpToFile( ILA_DLOG("TestVerilogGen.ParseInst") );
#endif
	}
	// test 5 gen Load : external mem
	{
		auto config = VerilogGenerator::VlgGenConfig( true , VerilogGenerator::VlgGenConfig::funcOption::Internal );
		auto vgen = VerilogGenerator( config );
		//DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
		vgen.ExportTopLevelInstr( ila_ptr_->instr("Load") );
#ifdef VERILOG_IN_ENABLE
		parseable( "Testing/Temporary/t_proc_Load_extmem.v" , vgen);
#else
		vgen.DumpToFile( ILA_DLOG("TestVerilogGen.ParseInst") );
#endif
	}
	// test 6 gen Store : external mem
	{
		auto config = VerilogGenerator::VlgGenConfig( true , VerilogGenerator::VlgGenConfig::funcOption::Internal );
		auto vgen = VerilogGenerator( config );
		//DebugLog::Enable("VerilogGen.ParseNonMemUpdateExpr");
		vgen.ExportTopLevelInstr( ila_ptr_->instr("Store") );
#ifdef VERILOG_IN_ENABLE
		parseable( "Testing/Temporary/t_proc_Store_extmem.v" , vgen);
#else
		vgen.DumpToFile( ILA_DLOG("TestVerilogGen.ParseInst") );
#endif
	}
}


}; // namespace ila

// #endif // VERILOG_OUT_ENABLE
