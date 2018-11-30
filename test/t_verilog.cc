/// \file
/// Unit test for Verilog parser.

#include <ilang/verilog-in/verilog_parse.h>
#include "unit-include/util.h"

#ifdef VERILOG_IN_ENABLE

namespace ilang {

TEST(TestVerilogParse, Init) { TestParseVerilog(); }

};  // namespace ilang

#endif  // VERILOG_IN_ENABLE
