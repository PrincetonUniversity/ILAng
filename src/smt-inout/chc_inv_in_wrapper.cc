/// \file CHC Invariant Input Parsing (a wrapper)
// --- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/util/log.h>
#include <ilang/smt-inout/chc_inv_in_wrapper.h>
#include <ilang/smt-inout/chc_inv_in.h>

namespace ilang {
namespace smt {
  
SmtlibInvariantParserBase::SmtlibInvariantParserBase() {} // do nothing
SmtlibInvariantParserBase::~SmtlibInvariantParserBase() {} // do nothing

/// return raw_string
std::string SmtlibInvariantParserBase::GetRawSmtString() const {
  return raw_string;
}


  // -------------- CONSTRUCTOR ------------------- //
SmtlibInvariantParserInstance::SmtlibInvariantParserInstance(YosysSmtParser * yosys_smt_info, 
    bool _flatten_datatype, bool _flatten_hierarchy,
    const std::set<std::string> & _inv_pred_name,
    const std::string & dut_inst_name) :
      _ptr(NULL) {

    _ptr = new SmtlibInvariantParser(
      yosys_smt_info, 
      _flatten_datatype, _flatten_hierarchy,
      _inv_pred_name,
      dut_inst_name);

    ILA_NOT_NULL(_ptr);
}

SmtlibInvariantParserInstance::~SmtlibInvariantParserInstance() {
  if (_ptr)
    delete _ptr;
}

bool SmtlibInvariantParserInstance::ParseInvResultFromFile(const std::string & fname) {
  ILA_NOT_NULL(_ptr);
  return _ptr->ParseInvResultFromFile(fname);
}
// parse from a string: assume we have the (assert ...) there
void SmtlibInvariantParserInstance::ParseSmtResultFromString(const std::string & text) {
  ILA_NOT_NULL(_ptr);
  _ptr->ParseSmtResultFromString(text);
}
  /// get the translate result
std::string SmtlibInvariantParserInstance::GetFinalTranslateResult() const {
  ILA_NOT_NULL(_ptr);
  return _ptr->GetFinalTranslateResult();
}




  
}; // namespace smt
}; // namespace ilang
