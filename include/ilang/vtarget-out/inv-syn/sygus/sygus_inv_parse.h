/// \file Invariant Synthesis -- SyGuS
/// to work with CVC4 (the latest version please)
/// to parse the sythesize result -- need to do the similar thing 
/// 
// Hongce Zhang

/*
Example:

unsat
(define-fun INV ((x (BitVec 8)) (y (BitVec 8)) (z (BitVec 8))) Bool (or (not (= x y)) (= z #b00000000)))

It uses (define-fun) rather than (forall)
*/

#ifndef SYGUS_INV_PARSE_H__
#define SYGUS_INV_PARSE_H__

#include <ilang/smt-inout/chc_inv_in.h>

namespace ilang {
namespace smt {

/// \brief this class is used to parse the result from CVC4 SyGuS
class SyGuSInvariantParser : public SmtlibInvariantParser {
  /// the corrections (mainly for cvc4 quirks, ex. extract )
  typedef std::map<std::string,std::string> correction_t;
public:
  // -------------- CONSTRUCTOR ------------------- //
  /// 1. the first argument : design_smt_info_ptr
  ///    is only used for sanity check...
  /// 2. _flatten_datatype : does not really affect the behavior
  /// 3. _inv_pred_name : {INV} the function name
  /// 4. if you give dut_verilog_instance_name, you can  
  ///    disable the sanity check and safely set yosys_smt_info to NULL
  SyGuSInvariantParser(YosysSmtParser * yosys_smt_info, 
    bool _flatten_datatype, bool _flatten_hierarchy,
    const std::set<std::string> & _inv_pred_name,
    const std::string & dut_instance_name,
    bool discourage_outside_var = true,
    const correction_t & corrections = correction_t());
  /// no copy constructor
  SyGuSInvariantParser(const SyGuSInvariantParser &) = delete;
  /// no assignment
  SyGuSInvariantParser & operator=(const SyGuSInvariantParser &) = delete;

  // -------------- DESTRUCTOR ------------------- //
  virtual ~SyGuSInvariantParser();

protected:
  // -------------- MEMBERS ------------------- //
  // for correctness checking
  std::set<std::string> _all_allowable_names;
  // to correct CVC4's output on BitVec
  virtual std::string correct_cvc4_bv_output(const std::string & in);
  // the corrections
  const correction_t corrections;
public: 
  // -------------- INTERFACE ------------------- //
  /// Interface function
  bool virtual ParseInvResultFromFile(const std::string & fname) override;
  
  // -------------- CALLBACK FNs ------------------- //
  /// call back function to handle (define-fun
  virtual SmtTermInfoVlgPtr push_quantifier_scope() override;
  /// call back function to handle ) of define-fun
  virtual SmtTermInfoVlgPtr pop_quantifier_scope() override;
  
  /// override!
  /// call back function to create a sort
  virtual var_type * make_sort(const std::string &name, const std::vector<int> &) override;
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
  /// this function receives the final assert result
  virtual void assert_formula(SmtTermInfoVlgPtr result) override;
  /// this function receives the final result
  virtual void define_function(const std::string &func_name, 
    const std::vector<SmtTermInfoVlgPtr> & args, var_type * ret_type,
    SmtTermInfoVlgPtr func_body) override;

}; // class SyGuSInvariantParser

}; // namespace smt
}; // namespace ilang

#endif // SYGUS_INV_PARSE_H__