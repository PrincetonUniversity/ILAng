/// \file
/// Test for using third-party verilog-parse

#include <ilang/verilog-in/verilog_parse.h>

extern "C" {
#include <verilogparser/verilog_parser.h>
}

namespace ilang {

// we need to use this, so vlg parser will record memory usage and free later
static void* VlgParserAllocCstr(const std::string& str) {
  char* ret = (char*)ast_calloc(str.size() + 1, sizeof(char));
  strcpy(ret, str.c_str());
  return (void*)ret;
}

// void TestParseVerilog() { verilog_parser_init(); }

int TestParseVerilogFrom(const std::string& fn) {
  std::FILE* fp = std::fopen(fn.c_str(), "r");
  if (fp == NULL)
    return 1;
  verilog_parser_init();

  verilog_preprocessor_set_file(yy_preproc, (char*)VlgParserAllocCstr(fn));
  auto ret = verilog_parse_file(fp);
  std::fclose(fp);

  ast_free_all();
  yy_preproc = NULL;
  yy_verilog_source_tree = NULL;

  return ret;
}

}; // namespace ilang
