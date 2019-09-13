/// \file Header of Verilog parser utils
///
/// To provide utils and wrappers for the external Verilog parser.
///   - resource-leak-free string translation of ast id

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
