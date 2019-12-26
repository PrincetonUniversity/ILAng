/// \file CHC Invariant Input Parsing (a wrapper)
// --- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/smt-inout/chc_inv_in.h>
#include <ilang/smt-inout/chc_inv_in_wrapper.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {
namespace smt {

// we need to make sure this variable is shared
// and it is globally unique... so when invoking
// we can won't have multiple var with the same name
unsigned SmtlibInvariantParserBase::local_var_idx = 0;

SmtlibInvariantParserBase::SmtlibInvariantParserBase() {}  // do nothing
SmtlibInvariantParserBase::~SmtlibInvariantParserBase() {} // do nothing

/// return raw_string
std::string SmtlibInvariantParserBase::GetRawSmtString() const {
  return raw_string;
}


std::string SmtlibInvariantParserBase::get_a_new_local_var_name() {
  return "__INV_EXT_new_local_var_" + std::to_string(local_var_idx++) + "__";
}

unsigned SmtlibInvariantParserBase::get_local_ctr() {
  return local_var_idx;
}

/// set the counter to a new val when loading
void SmtlibInvariantParserBase::set_new_local_ctr(unsigned cnt) {
  if (cnt > local_var_idx)
    local_var_idx = cnt;
  ILA_ERROR_IF(cnt < local_var_idx) << "Trying to rewind local_var_idx from "
    << local_var_idx << " to " << cnt;
}
/// parse the names to set the new counters
void SmtlibInvariantParserBase::parse_local_var_name_to_set_counter(const std::string & name) {
  auto rel = name.rfind("__");
  if (StrStartsWith(name, "__INV_EXT_new_local_var_") && 
                        // 0123456789012345678901234
    (rel != name.npos) && (rel > 24) ) {
      auto num = name.substr(24,rel-24);
      auto idx = StrToInt(num);
      set_new_local_ctr(idx + 1);
  }
}

// -------------- CONSTRUCTOR ------------------- //
SmtlibInvariantParserInstance::SmtlibInvariantParserInstance(
    YosysSmtParser* yosys_smt_info, bool _flatten_datatype,
    bool _flatten_hierarchy, const std::set<std::string>& _inv_pred_name,
    const std::string& dut_inst_name)
    : _ptr(NULL) {

  _ptr = new SmtlibInvariantParser(yosys_smt_info, _flatten_datatype,
                                   _flatten_hierarchy, _inv_pred_name,
                                   dut_inst_name);

  ILA_NOT_NULL(_ptr);
}

SmtlibInvariantParserInstance::~SmtlibInvariantParserInstance() {
  if (_ptr)
    delete _ptr;
}

bool SmtlibInvariantParserInstance::ParseInvResultFromFile(
    const std::string& fname) {
  ILA_NOT_NULL(_ptr);
  return _ptr->ParseInvResultFromFile(fname);
}
// parse from a string: assume we have the (assert ...) there
void SmtlibInvariantParserInstance::ParseSmtResultFromString(
    const std::string& text) {
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
