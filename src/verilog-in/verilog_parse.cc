/// \file
/// Test for using third-party verilog-parse

#include "verilog-in/verilog_parse.h"

extern "C" {
#include "byh-verilog-parser/src/verilog_parser.h"
}

namespace ila {

void TestParseVerilog() { verilog_parser_init(); }
int TestParseVerilogFrom(std::FILE * fp) { verilog_parser_init(); return verilog_parse_file(fp);  }

}; // namespace ila
