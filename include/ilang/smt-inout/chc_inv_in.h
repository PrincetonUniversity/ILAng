/// \file CHC Invariant Input Parsing
// --- Hongce Zhang (hongcez@princeton.edu)

#ifndef CHC_INV_IN_H__
#define CHC_INV_IN_H__

#include <functional>

extern "C" {
#include "smtlib2abstractparser.h"
}

namespace ilang {
namespace smt {

/// \brief the class for parsing invariant
class SmtlibInvariantParser {
public:
  // -------------- TYPEs ------------------- //
  /// a function to map state name (internal name reference to verilog signal)
  typedef std::function<std::string(const std::string &)>
    verilog_internal_name_lookup_fn_t;
public:
  // -------------- CONSTRUCTOR ------------------- //
  SmtlibInvariantParser();
  /// no copy constructor
  SmtlibInvariantParser(const SmtlibInvariantParser &) = delete;
  /// no assignment
  SmtlibInvariantParser & operator=(const SmtlibInvariantParser &) = delete;

  // -------------- DESTRUCTOR ------------------- //
  ~SmtlibInvariantParser();

protected:
  // ----------------- MEMBERS ------------------- //
  /// the parser interface
  smtlib2_abstract_parser * parser;
  /// bad state
  bool _bad_state;
  /// If it is bad state, return true and display a message
  bool bad_state_return(void);

public:
  /// check if this module is in a bad state
  bool in_bad_state(void) const { return _bad_state; }
  
}; // SmtlibInvariantParser


}; // namespace smt
}; // namespace ilang

#endif // CHC_INV_IN_H__
