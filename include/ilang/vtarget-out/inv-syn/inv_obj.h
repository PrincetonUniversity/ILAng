/// \file Invariant Object --- should be able to parse from
/// a smt-like-output
// Hongce Zhang

#ifndef ILANG_VTARGET_OUT_INV_OBJ_H__
#define ILANG_VTARGET_OUT_INV_OBJ_H__

#include <ilang/config.h>

#include <ilang/smt-inout/yosys_smt_parser.h>
#include <ilang/vtarget-out/inv-syn/inv_cnf.h>

#include <string>
#include <tuple>
#include <vector>

namespace ilang {

/// declaration for cnf (ref)
class InvariantInCnf;

/// \brief the invariant object, it needs smt-info to parse
class InvariantObject {
public:
  // ----------- TYPE DEFs ---------- //
  /// the vector of multiple invariants
  typedef std::vector<std::string> inv_vec_t;
  /// the vector of extra_var defs exprs
  typedef std::vector<std::tuple<std::string, std::string, int>>
      extra_var_def_vec_t;
  /// the vector  of free var defs exprs
  typedef std::map<std::string, int> extra_free_var_def_vec_t;
  /// the vector of original smt-formula for datapoint attempt
  typedef std::vector<std::string> smt_formula_vec_t;
  // ----------- CONSTRUCTOR ---------- //
  /// empty invariants
  InvariantObject();
  /// copy constructor = default

#ifdef INVSYN_INTERFACE

  /// add invariants from smt-like output
  bool AddInvariantFromChcResultFile(
      smt::YosysSmtParser& design_info, const std::string& tag,
      const std::string& chc_result_fn, bool flatten_datatype,
      bool flatten_hierarchy, bool discourage_outside_var_referral = true);

  /// add invariants from smt-like output
  void
  AddInvariantFromGrainResultFile(smt::YosysSmtParser& design_info,
                                  const std::string& tag,
                                  const std::string& chc_result_fn,
                                  bool discourage_outside_var_referral = true,
                                  bool change_outside_var = true);

  /// add invariants from abc result
  bool AddInvariantFromAbcResultFile(
      const std::string& blif_fname, const std::string& abc_fname,
      bool warning_outside_var, bool replace_outside_var,
      const std::string& gla_map_fname, bool useAiger,
      const std::string& aiger_map_name, InvariantInCnf& inv_cnf,
      const InvariantInCnf& ref_cnf);

#endif // INVSYN_INTERFACE

  /// add invariants from verilog-like output
  void AddInvariantFromVerilogExpr(const std::string& tag,
                                   const std::string& vlg_in);
  /// generate invariants
  const inv_vec_t& GetVlgConstraints() const;
  /// get the vars
  const extra_var_def_vec_t& GetExtraVarDefs() const;
  /// get the free vars
  const extra_free_var_def_vec_t& GetExtraFreeVarDefs() const;
  /// get the smt formula
  const smt_formula_vec_t& GetSmtFormulae() const;
  /// called by the target generator?
  void set_dut_inst_name(const std::string& name);
  /// clear all stored invariants
  void ClearAllInvariants();
  /// export invariants to a file
  void ExportToFile(const std::string& fn,
                    bool export_smt_encoding = true) const;
  /// import invariants that has been previous exported
  void ImportFromFile(const std::string& fn);
  /// this is to support making candidate invariant as confirmed
  void InsertFromAnotherInvObj(const InvariantObject& r);
  /// the number of invariants
  size_t NumInvariant() const;
  /// remove an invariant by its index
  void RemoveInvByIdx(size_t idx);

protected:
  /// the expressions
  std::vector<std::string> inv_vlg_exprs;
  /// the extra variables that are needed to ...
  extra_var_def_vec_t inv_extra_vlg_vars;
  /// the extra free variables // there might be repetition // check it
  extra_free_var_def_vec_t inv_extra_free_vars;
  /// the original smt formula
  smt_formula_vec_t smt_formula_vec;
  /// the buffered dut instance name
  std::string dut_inst_name;
};

}; // namespace ilang

#endif // ILANG_VTARGET_OUT_INV_OBJ_H__
