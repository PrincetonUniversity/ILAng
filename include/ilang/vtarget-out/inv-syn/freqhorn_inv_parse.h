/// \file Invariant Synthesis -- CHC FreqHorn
/// to work with FreqHorn (bv branch)
/// to parse the sythesize result -- need to do the similar thing
///
// Hongce Zhang

/* Example :
(declare-fun S_m1.id_ex_reg_wen () (_ BitVec 1))
(declare-fun S_m1.id_ex_op () (_ BitVec 2))

(assert (=> (= S_m1.id_ex_op #b00) (= S_m1.id_ex_reg_wen #b0)))
(check-sat)
*/

#ifndef FREQHORN_INV_PARSE_H__
#define FREQHORN_INV_PARSE_H__

#include <ilang/smt-inout/chc_inv_in.h>

namespace ilang {
namespace smt {

/// \brief this class is used to parse the result from FreqHorn 
class FreqHornInvariantParser : public SmtlibInvariantParser {

public:
  // -------------- CONSTRUCTOR ------------------- //
  /// 1. the first argument : design_smt_info_ptr
  ///    is only used for sanity check...
  /// 2. _flatten_datatype/hierarchy : does not really affect the behavior
  /// 4. if you give dut_verilog_instance_name, you can  
  ///    disable the sanity check and safely set yosys_smt_info to NULL
  FreqHornInvariantParser(YosysSmtParser * yosys_smt_info, 
    const std::string & dut_instance_name,
    bool discourage_outside_var = true,
    bool outside_var_to_freevar = true);
  /// no copy constructor
  FreqHornInvariantParser(const FreqHornInvariantParser &) = delete;
  /// no assignment
  FreqHornInvariantParser & operator=(const FreqHornInvariantParser &) = delete;

  // -------------- DESTRUCTOR ------------------- //
  virtual ~FreqHornInvariantParser();

protected:
  // -------------- MEMBER ------------------- //
  bool convert_out_var_to_free_var;

public:
  // -------------- INTERFACE ------------------- //
  /// Interface function
  bool virtual ParseInvResultFromFile(const std::string & fname) override;
  
  // -------------- CALLBACK FNs ------------------- //

  /// override!
  /// call back function to create a sort
  virtual var_type * make_sort(const std::string &name, const std::vector<int> &) override;
  /// this is actually declare variables
  void declare_function(const std::string &name, var_type * sort) override; 
  
  /// this function receives the final assert result
  // virtual void assert_formula(SmtTermInfoVlgPtr result) override; -- use the old one

  // -------------- Below are Disabled!--------------------- //
  /// call back function to handle (define-fun
  virtual SmtTermInfoVlgPtr push_quantifier_scope() override;
  /// call back function to handle ) of define-fun
  virtual SmtTermInfoVlgPtr pop_quantifier_scope() override;
  
  /// call back function to create a temporary (function-arg variable)
  virtual void declare_quantified_variable(const std::string &name, var_type * sort ) override;
  /// call back function to apply an uninterpreted function
  /// fall-through case if it is not an defined op, if failed, return NULL
  virtual SmtTermInfoVlgPtr mk_function(
    const std::string &name, var_type * sort, 
    const std::vector<int> & idx, const std::vector<SmtTermInfoVlgPtr> & args) override;

  /// call back function to make a number term
  // virtual SmtTermInfoVlgPtr mk_number(const std::string & rep, int width, int base) override;
  
  /// find if a certain var is a function-arg variable
  virtual SmtTermInfoVlgPtr search_quantified_var_stack(const std::string & name) override;

  /// this function receives the final result
  virtual void define_function(const std::string &func_name, 
    const std::vector<SmtTermInfoVlgPtr> & args, var_type * ret_type,
    SmtTermInfoVlgPtr func_body) override;



}; // class FreqHornInvariantParser

}; // namespace smt
}; // namespace ilang

#endif // FREQHORN_INV_PARSE_H__
