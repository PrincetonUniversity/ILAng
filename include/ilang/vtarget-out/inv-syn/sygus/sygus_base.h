/// \file Invariant Synthesis -- SyGuS
/// to work with CVC4 (the latest version)
/// Base for data-point and transition function
///
// Hongce Zhang (hongcez@princeton.edu)

#ifndef SYGUS_BASE_H__
#define SYGUS_BASE_H__


#include <ilang/vtarget-out/inv-syn/sygus/datapoint.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/smt-inout/yosys_smt_parser.h>

#include <string>
#include <vector>
#include <map>

namespace ilang
{


struct extract_op {
  unsigned high;
  unsigned low;
  unsigned from;
  unsigned to;
  const std::string reps;
  const std::string smt;
  const std::string replacement;
  const std::string exheading;
  const std::set<std::string> from_state_name;
  extract_op (unsigned h, unsigned l, unsigned f, unsigned t, const std::set<std::string> & s = std::set<std::string>());
};

  /// \brief cvc4sy grammar 
  struct Cvc4Syntax{
    /// control data width sep
    unsigned ctrl_data_sep_width;
    /// other sep
    unsigned other_comp_sep_width;
    /// comparator ops (2-ary)
    std::vector<std::string> compOp;
    /// width -> numbers
    std::map<int,std::set<unsigned>> nums;
    /// bitwidth -> (op -> n-ary) 
    std::map<unsigned,std::map<std::string,unsigned>> arithmOp;
    /// extracts
    std::map<unsigned, std::vector<extract_op>> extractExtOp;
  }; // struct Cvc4Syntax


  /// \brief to generate an input based on pos/neg examples
  class Cvc4SygusBase {
  public:
    /// the options it takes
    using sygus_options_t = VlgVerifTgtGenBase::vtg_config_t::_sygus_options_t;
    /// the corrections (mainly for cvc4 quirks, ex. extract )
    typedef std::map<std::string,std::string> correction_t;

  protected:
    // ------------- MEMBER ---------------- //
    /// the vocabulary -- the variables to consider
    std::vector<std::string> var_names;
    /// we need a pointer to smt-parsed data
    const smt::YosysSmtParser & design_info;
    /// a local copy of the options
    sygus_options_t options;
    /// record the corrections we have
    mutable correction_t corrections;
    
  public:
    // ------------- Constructor ---------------- //
    Cvc4SygusBase(
      const smt::YosysSmtParser & _design_info,         // the design info is needed
      const std::vector<std::string> & _var_name_vec,   // the variables we are going to consider
      const sygus_options_t & SygusOptions,             // the options
      const std::string & customized_invariant_arg,      // whether to replace the %arg% w. something new
      const std::map<std::string, int> & additional_width_info,
      const Cvc4Syntax & syntax
      );
    /// no copy constructor
    Cvc4SygusBase(const Cvc4SygusBase &) = delete;
    
    virtual ~Cvc4SygusBase();
    // ------------- Methods ---------------- //
    /// Export to a file
    virtual void ExportToFile(const std::string & fn) = 0;
    /// the replacement needed 
    const correction_t & GetCorrectionMap() const;

  protected:
    // ------------- Members ---------------- //
    /// get template based on the arithmetic it supported
    std::string get_template_basic() const;
    /// get template based on the arithmetic it supported
    std::string get_template_lv1() const;
    /// get template based on the arithmetic it supported
    std::string get_template_lvR() const;
    /// a new style of template --- hardwired one
    std::string get_template_hardwired() const;
    /// generate the constant in a syntax
    std::string generate_syntax_const(unsigned) const;
    /// auto decide arithmetic template
    std::string get_template() const;

    /// make template : varOrValN
    void add_val_or_var_no_eec(std::string & varOrVal) const;
    /// make template : vars
    void add_vars_no_eec(std::string & vars) const;
    /// make template : vals
    void add_vals(std::string & val) const;
    
  protected:
    // width to names (available after initialization)
    std::map<unsigned, std::vector<std::string>> width_to_names;
    // the list of all args
    std::vector<std::string> args_list;
    // additional width info
    const std::map<std::string, int> & additional_width_info;

  private:
    // ------------- Preprocessing step ---------------- //
    /// convert vname to arg
    void arg_to_widx();
    /// whether to replace 
    const bool inv_arg_customize;
    /// what to replace
    const std::string invariant_arg;
    

  }; // class Cvc4SygusInputGenerator
    

}; // namespace ilang

#endif // SYGUS_BASE_H__
