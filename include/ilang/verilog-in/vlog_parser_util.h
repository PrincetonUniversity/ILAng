/// \file Header of Verilog parser utils
///
/// To provide utils and wrappers for the external Verilog parser.
///   - placeholder for static analysis model (resource leak false positive)

#ifndef ILANG_VERILOG_IN_VLOG_PARSER_UTIL_H__
#define ILANG_VERILOG_IN_VLOG_PARSER_UTIL_H__

extern "C" {
#include <verilogparser/verilog_ast.h>
}

#include <string>

/// \namespace ilang
namespace ilang {

/// A wrapper of the ast_identifier_tostring method with basic string type.
std::string _ast_identifier_tostring(ast_identifier id);

}; // namespace ilang

#endif // ILANG_VERILOG_IN_VLOG_PARSER_UTIL_H__
