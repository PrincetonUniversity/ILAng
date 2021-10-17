/// \file Invariant Synthesis -- CHC Grain
/// to work with Grain (bv branch)
/// to parse the sythesize result -- need to do the similar thing
///
// Hongce Zhang

/* Example :
(declare-fun S_m1.id_ex_reg_wen () (_ BitVec 1))
(declare-fun S_m1.id_ex_op () (_ BitVec 2))

(assert (=> (= S_m1.id_ex_op #b00) (= S_m1.id_ex_reg_wen #b0)))
(check-sat)
*/

#ifndef ILANG_VTARGET_OUT_GRAIN_INV_PARSE_H__
#define ILANG_VTARGET_OUT_GRAIN_INV_PARSE_H__

#include <ilang/config.h>
#ifdef INVSYN_INTERFACE

#include <ilang/smt-inout/chc_inv_in.h>

namespace ilang {
namespace smt {

/// \brief this class is used to parse the result from Grain
class GrainInvariantParser : public SmtlibInvariantParser {

public:
  // -------------- CONSTRUCTOR ------------------- //
  /// 1. the first argument : design_smt_info_ptr
  ///    is only used for sanity check...
  /// 2. _flatten_datatype/hierarchy : does not really affect the behavior
  /// 4. if you give dut_verilog_instance_name, you can
  ///    disable the sanity check and safely set yosys_smt_info to NULL
  GrainInvariantParser(YosysSmtParser* yosys_smt_info,
                       const std::string& dut_instance_name,
                       bool discourage_outside_var = true,
                       bool outside_var_to_freevar = true);
  /// no copy constructor
  GrainInvariantParser(const GrainInvariantParser&) = delete;
  /// no assignment
  GrainInvariantParser& operator=(const GrainInvariantParser&) = delete;

  // -------------- DESTRUCTOR ------------------- //
  virtual ~GrainInvariantParser();

protected:
  // -------------- MEMBER ------------------- //
  bool convert_out_var_to_free_var;

public:
  // -------------- INTERFACE ------------------- //
  /// Interface function
  bool virtual ParseInvResultFromFile(const std::string& fname) override;

  // -------------- CALLBACK FNs ------------------- //

  /// this is actually declare variables
  virtual void declare_function(const std::string& name,
                                SortPtrT sort) override;

  /// this function receives the final assert result
  // virtual void assert_formula(SmtTermInfoVlgPtr result) override; -- use the
  // old one

  // -------------- Below are Disabled!--------------------- //
  /// call back function to handle (define-fun
  virtual TermPtrT push_quantifier_scope() override;
  /// call back function to handle ) of define-fun
  virtual TermPtrT pop_quantifier_scope() override;

  /// call back function to create a temporary (function-arg variable)
  virtual void declare_quantified_variable(const std::string& name,
                                           SortPtrT sort) override;
  /// call back function to apply an uninterpreted function
  /// fall-through case if it is not an defined op, if failed, return NULL
  virtual TermPtrT mk_function(const std::string& name, SortPtrT sort,
                               const std::vector<int>& idx,
                               const std::vector<TermPtrT>& args) override;

  /// call back function to make a number term
  // virtual SmtTermInfoVlgPtr mk_number(const std::string & rep, int width, int
  // base) override;

  /// this function receives the final result
  virtual void define_function(const std::string& func_name,
                               const std::vector<TermPtrT>& args,
                               SortPtrT ret_type, TermPtrT func_body) override;

}; // class GrainInvariantParser

}; // namespace smt
}; // namespace ilang

#endif // INVSYN_INTERFACE

#endif // ILANG_VTARGET_OUT_GRAIN_INV_PARSE_H__
