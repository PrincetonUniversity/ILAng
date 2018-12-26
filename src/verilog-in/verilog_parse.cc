/// \file
/// Test for using third-party verilog-parse

#include <ilang/verilog-in/verilog_parse.h>

extern "C" {
#include <verilogparser/verilog_parser.h>
}

namespace ilang {

void TestParseVerilog() { verilog_parser_init(); }
int TestParseVerilogFrom(std::FILE* fp) {
  verilog_parser_init();
  return verilog_parse_file(fp);
}

}; // namespace ilang
