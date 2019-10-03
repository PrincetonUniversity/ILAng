/// \file Invariant Synthesis -- SyGuS
/// to work with CVC4 (the latest version please)
/// The chc approach
/// (passing the whole transition function)
/// 
// Hongce Zhang

#ifndef SYGUS_CHC_H__
#define SYGUS_CHC_H__

#include <ilang/vtarget-out/inv-syn/sygus/sygus_base.h>

#include <string>
#include <vector>
#include <map>

namespace ilang
{
  /// \brief to generate an input based on YosysSmt info
  class Cvc4SygusChcGenerator : public Cvc4SygusBase {
    /// the options it takes
    using sygus_options_t = VlgVerifTgtGenBase::vtg_config_t::_sygus_options_t;
  public:
    // ------------- Constructor ---------------- //
    Cvc4SygusChcGenerator(
      const smt::YosysSmtParser & _design_info,       // the design info is needed
      const std::vector<std::string> & _var_name_vec, // the variables we are going to consider
      const sygus_options_t & SygusOptions,           // the options
      const std::string & flattened_smt,
      const std::map<std::string,int> & additional_width_info,
      const Cvc4Syntax & syntax
      );
    /// no copy constructor
    Cvc4SygusChcGenerator(const Cvc4SygusChcGenerator &) = delete;
    /// no assignment
    Cvc4SygusChcGenerator operator=(const Cvc4SygusChcGenerator &) = delete;
    // ------------- Methods ---------------- //
    /// Export to a file
    virtual void ExportToFile(const std::string & fn) override;

  protected:
    // ------------- Members ---------------- //
    /// a reference to the converted smt
    const std::string & smt_converted;
    /// put smt, declare variable, generate the transition relation...
    std::string smt_var_trans() const;
  }; // class Cvc4SygusChcGenerator

}; // namespace ilang

#endif // SYGUS_CHC_H__

