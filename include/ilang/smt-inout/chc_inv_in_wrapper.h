/// \file CHC Invariant Input Parsing (a wrapper)
// --- Hongce Zhang (hongcez@princeton.edu)

#ifndef CHC_INV_IN_WRAPPER_H__
#define CHC_INV_IN_WRAPPER_H__

#include <ilang/smt-inout/yosys_smt_parser.h>

namespace ilang {
namespace smt {

/// \brief this a base class, should not be instantiated
class SmtlibInvariantParserBase {
protected:
  // the raw result (not including the sat/unsat)
  std::string raw_string;

public:
  // -------------- CONSTRUCTOR ------------------- //
  // -------------- CONSTRUCTOR ------------------- //
  SmtlibInvariantParserBase(); // do nothing
  /// no copy constructor
  SmtlibInvariantParserBase(const SmtlibInvariantParserBase&) = delete;
  /// no assignment
  SmtlibInvariantParserBase&
  operator=(const SmtlibInvariantParserBase&) = delete;
  // -------------- DESTRUCTOR ------------------- //
  virtual ~SmtlibInvariantParserBase(); // do nothing

  // -------------- METHODS ------------------- //
  // parse from a file, we will add something there to make
  // if sat --> failed (return false)
  // if unsat --> add the (assert ...)
  virtual bool ParseInvResultFromFile(const std::string& fname) = 0;
  // parse from a string: assume we have the (assert ...) there
  virtual void ParseSmtResultFromString(const std::string& text) = 0;
  /// get the translate result
  virtual std::string GetFinalTranslateResult() const = 0;
  /// get the local variable definitions
  // virtual const local_vars_t & GetLocalVarDefs() const = 0;

  /// return raw_string
  std::string GetRawSmtString() const;

  /// set the counter to a new val when loading
  static void set_new_local_ctr(unsigned cnt);
  /// parse the names to set the new counters
  static void parse_local_var_name_to_set_counter(const std::string & name);
  /// to check the value of this counter
  static unsigned get_local_ctr();

protected:
  /// a counter to get local variable name
  static std::string get_a_new_local_var_name();
  /// the idx to it
  static unsigned local_var_idx;

}; // class SmtlibInvariantParserBase

/// \brief this a base class, should not be instantiated
class SmtlibInvariantParserInstance {
protected:
  // the pointer that will be used to cast to internal datatype
  SmtlibInvariantParserBase* _ptr;

public:
  // -------------- CONSTRUCTOR ------------------- //
  SmtlibInvariantParserInstance(YosysSmtParser* yosys_smt_info,
                                bool _flatten_datatype, bool _flatten_hierarchy,
                                const std::set<std::string>& _inv_pred_name,
                                const std::string& dut_inst_name);
  /// no copy constructor
  SmtlibInvariantParserInstance(const SmtlibInvariantParserInstance&) = delete;
  /// no assignment
  SmtlibInvariantParserInstance&
  operator=(const SmtlibInvariantParserInstance&) = delete;

  // -------------- DESTRUCTOR ------------------- //
  virtual ~SmtlibInvariantParserInstance();

  // -------------- METHODS ------------------- //
  // parse from a file, we will add something there to make
  // if sat --> failed (return false)
  // if unsat --> add the (assert ...)
  bool ParseInvResultFromFile(const std::string& fname);
  // parse from a string: assume we have the (assert ...) there
  void ParseSmtResultFromString(const std::string& text);
  /// get the translate result
  std::string GetFinalTranslateResult() const;
  /// get the local variable definitions
  // const local_vars_t & GetLocalVarDefs() const; // no available
}; // class SmtlibInvariantParserInstance

}; // namespace smt
}; // namespace ilang

#endif // CHC_INV_IN_WRAPPER_H__
