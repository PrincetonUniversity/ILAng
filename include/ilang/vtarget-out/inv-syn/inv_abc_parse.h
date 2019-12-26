/// \file Parsing ABC invariant synthesis result
/// what we need are : blif file, clauses file
/// dut name and whether to discourage use of outside variable
// ---Hongce Zhang

#ifndef ILANG_VTARGET_OUT_INV_ABC_PARSE_H__
#define ILANG_VTARGET_OUT_INV_ABC_PARSE_H__

#include <ilang/config.h>
#ifdef INVSYN_INTERFACE

#include <ilang/vtarget-out/inv-syn/inv_cnf.h>

#include <set>
#include <string>
#include <vector>

namespace ilang {

/// \brief Parser for ABC pdr result
class AbcInvariantParser {

protected:
  /// the parsing result
  std::string parse_result;
  /// only 1-bit
  std::set<std::string> outside_reference;

  /// the real parsing function
  void parse(const std::string& blif_name, const std::string& abc_result_fn);

  /// the real parsing function
  void parse(const std::string& blif_name, const std::string& abc_result_fn,
             const std::string& gla_map_fn);

  /// the real parsing function -- without gla use aiger
  void parseAigerResultWoGLA(const std::string& aig_map_fn,
                             const std::string& abc_result_fn,
                             InvariantInCnf& inv_cnf,
                             const InvariantInCnf& ref_cnf,
                             const std::string& blif_fn_name);

  /// the real parsing function
  void parseAigerResultWithGLA(const std::string& aig_map_fn,
                               const std::string& abc_result_fn,
                               const std::string& gla_map_fn,
                               InvariantInCnf& inv_cnf,
                               const InvariantInCnf& ref_cnf,
                               const std::string& blif_fn_name);

  /// dut name
  const std::string dut_name;
  /// whether to warn names
  const bool discourage_outside_var_ref;
  /// whether to replace names
  const bool replace_outside_var_ref;
  /// whether parsing is successful
  bool parse_succeed;

public:
  AbcInvariantParser(const std::string& blif_name,
                     const std::string& abc_result_fn,
                     const std::string& dut_name,
                     bool discourage_outside_variable_reference,
                     bool replace_outside_variable_reference,
                     const std::string& gla_abs_fn, bool useAiger,
                     const std::string& aiger_map_name, InvariantInCnf& inv_cnf,
                     const InvariantInCnf& ref_cnf);

  std::string GetParseResult() const { return parse_result; }

  const std::set<std::string>& GetNewVarDefs() const {
    return outside_reference;
  }

  bool get_parse_status() const { return parse_succeed; }
}; // class AbcInvariantParser

}; // namespace ilang

#endif // INVSYN_INTERFACE

#endif // ILANG_VTARGET_OUT_INV_ABC_PARSE_H__
