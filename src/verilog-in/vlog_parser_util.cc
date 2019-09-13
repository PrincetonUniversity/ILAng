/// \file Source of Verilog parser utils
///

#include <ilang/verilog-in/vlog_parser_util.h>

#include <ilang/config.h>

namespace ilang {

#ifdef STATIC_ANALYSIS
extern void _static_analysis_only_free(char* x);
#endif

std::string _ast_identifier_tostring(ast_identifier id) {
  auto id_cptr = ast_identifier_tostring(id);
  auto id_bstr = static_cast<std::string>(id_cptr);

#ifdef STATIC_ANALYSIS
  _static_analysis_only_free(id_cptr);
#endif

  return id_bstr;
}

}; // namespace ilang
