/// \file Invariant Object --- should be able to parse from
/// a smt-like-output
// Hongce Zhang

#ifndef INV_OBJ_H__
#define INV_OBJ_H__

#include <ilang/smt-inout/yosys_smt_parser.h>

#include <tuple>
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
  typedef std::vector <std::tuple<std::string,std::string, int>> extra_var_def_vec_t;
  /// the vector  of free var defs exprs
  typedef std::map <std::string, int> extra_free_var_def_vec_t;
  // ----------- CONSTRUCTOR ---------- //
  /// empty invariants
  InvariantObject();
  /// copy constructor = default
  
  /// add invariants from smt-like output
  void AddInvariantFromChcResultFile(
    smt::YosysSmtParser & design_info, 
    const std::string & tag, const std::string & chc_result_fn,
    bool flatten_datatype, bool flatten_hierarchy );

  /// add invariants from sygus output
  void AddInvariantFromSygusResultFile(
    smt::YosysSmtParser & design_info, 
    const std::string & tag, const std::string & chc_result_fn,
    bool flatten_datatype, bool flatten_hierarchy );

  /// add invariants from verilog-like output
  void AddInvariantFromVerilogExpr(const std::string & tag, const std::string & vlg_in);
  /// generate invariants
  const inv_vec_t & GetVlgConstraints() const;
  /// get the vars
  const extra_var_def_vec_t & GetExtraVarDefs() const;
  /// get the free vars
  const extra_free_var_def_vec_t & GetExtraFreeVarDefs() const;
  /// called by the target generator?
  void set_dut_inst_name(const std::string & name);
  /// clear all stored invariants
  void ClearAllInvariants();
  /// export invariants to a file
  void ExportToFile(const std::string &fn) const;
  /// import invariants that has been previous exported
  void ImportFromFile(const std::string &fn);

protected:
  /// the expressions
  std::vector <std::string> inv_vlg_exprs;
  /// the extra variables that are needed to ...
  extra_var_def_vec_t inv_extra_vlg_vars;
  /// the extra free variables // there might be repetition // check it
  extra_free_var_def_vec_t inv_extra_free_vars;
  /// the buffered dut instance name
  std::string dut_inst_name;

};

}; // namespace ilang

#endif // INV_OBJ_H__