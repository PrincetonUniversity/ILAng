/// \file Source of Verilog parser utils
///

#include <ilang/verilog-in/vlog_parser_util.h>

namespace ilang {

std::string _ast_identifier_tostring(ast_identifier id) {
  std::string tr_str(ast_strdup(id->identifier));

  ast_identifier walker = id;

  while (walker->next != NULL) {
    walker = walker->next;
    tr_str += walker->identifier;
  }

  return tr_str;
}

}; // namespace ilang
