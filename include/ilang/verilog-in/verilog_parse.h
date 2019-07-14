/// \file
/// Header for testing Verilog files

#ifndef VERILOG_PARSE_H__
#define VERILOG_PARSE_H__

#include <cstdio>
#include <iostream>

/// \namespace ilang
namespace ilang {

void TestParseVerilog();
int TestParseVerilogFrom(const std::string& fn);

}; // namespace ilang

#endif // VERILOG_PARSE_H__
