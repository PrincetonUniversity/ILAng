/// \file CHC Invariant Input Parsing
// --- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/smt-inout/chc_inv_in.h>


extern "C" {
#include "smtlib2abstractparser_private.h"
}

namespace ilang {
namespace smt {

SmtlibInvariantParser::SmtlibInvariantParser() : 
  parser(new smtlib2_abstract_parser()),
  _bad_state(false) {
    
  if (not parser) {
    _bad_state = true;
    ILA_ERROR << "SMT-LIB2 parser construct allocation failed!";
    return;
  }
}

SmtlibInvariantParser::~SmtlibInvariantParser() {
  if(parser)
    delete parser;
}

bool SmtlibInvariantParser::bad_state_return(void) {
  ILA_ERROR_IF(_bad_state) << "SmtlibInvariantParser is in a bad state, cannot proceed.";
  return _bad_state;
} // bad_state_return




}; // namespace smt
}; // namespace ilang
