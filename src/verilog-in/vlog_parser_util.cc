/// \file Source of Verilog parser utils
///

#include <ilang/verilog-in/vlog_parser_util.h>

#include <ilang/config.h>

namespace ilang {

std::string _ast_identifier_tostring(ast_identifier id) {
  auto id_cptr = ast_identifier_tostring(id);
  auto id_bstr = static_cast<std::string>(id_cptr);

#ifdef COVERITY
  // Used only for static analysis for it cannot identify the free phase
  free(id_cptr);
#endif

  return id_bstr;
}

}; // namespace ilang
