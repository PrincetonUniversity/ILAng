/// \file Invariant Object --- should be able to parse from
/// a smt-like-output
// Hongce Zhang

#ifndef INV_OBJ_H__
#define INV_OBJ_H__

#include <ilang/smt-inout/yosys_smt_parser.h>

#include <vector>
#include <string>

namespace ilang {

/// \brief the invariant object, it needs smt-info to parse
class InvariantObject{
public:
  // ----------- TYPE DEFs ---------- //
  /// the vector of multiple invariants
  typedef std::vector <std::string> inv_vec_t;
  /// the vector of extra_var defs exprs
  typedef std::vector <std::pair<std::string,std::string>> extra_var_def_vec_t;
  // ----------- CONSTRUCTOR ---------- //
  /// empty invariants
  InvariantObject();
  /// add invariants from smt-like output
  void AddInvariantFromChcResultFile(
    smt::YosysSmtParser & design_info, 
    const std::string & tag, const std::string & chc_result_fn,
    bool flatten_datatype, bool flatten_hierarchy );
  /// add invariants from verilog-like output
  void AddInvariantFromVerilogExpr(const std::string & tag, const std::string & vlg_in);
  /// generate invariants
  const inv_vec_t & GetVlgConstraints() const;
  /// get the vars
  const extra_var_def_vec_t & GetExtraVarDefs() const;

protected:
  /// the expressions
  std::vector <std::string> inv_vlg_exprs;
  /// the extra variables that are needed to ...
  std::vector <std::pair<std::string,std::string>> inv_extra_vlg_vars;

};

}; // namespace ilang

#endif // INV_OBJ_H__