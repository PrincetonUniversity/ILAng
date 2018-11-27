/// \file
/// Header for testing Verilog files

#ifndef VERILOG_PARSE_H__
#define VERILOG_PARSE_H__

#include <cstdio>
#include <iostream>

/// \namespace ila
namespace ila {

void TestParseVerilog();
int TestParseVerilogFrom(std::FILE* fp);

};  // namespace ila

#endif  // VERILOG_PARSE_H__
