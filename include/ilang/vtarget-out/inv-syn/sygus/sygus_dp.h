/// \file Invariant Synthesis -- SyGuS
/// to work with CVC4 (the latest version please)
/// The data-point (dp) approach
/// (not passing the whole transition function)
/// 
// Hongce Zhang

#ifndef SYGUS_DP_H__
#define SYGUS_DP_H__

#include <ilang/vtarget-out/inv-syn/sygus/sygus_base.h>

#include <string>
#include <vector>
#include <map>

namespace ilang
{
  /// \brief to generate an input based on pos/neg examples
  class Cvc4SygusInputGenerator : public Cvc4SygusBase {
    /// the options it takes
    using sygus_options_t = VlgVerifTgtGenBase::vtg_config_t::_sygus_options_t;
  public:
    // ------------- Constructor ---------------- //
    Cvc4SygusInputGenerator(
      const smt::YosysSmtParser & _design_info,       // the design info is needed
      const std::vector<std::string> & _var_name_vec, // the variables we are going to consider
      const sygus_options_t & SygusOptions,           // the options
      TraceDataPoints * datapoints,
      const std::map<std::string, int> & additional_wdith_info,
      const Cvc4Syntax & syntax
      );
    /// no copy constructor
    Cvc4SygusInputGenerator(const Cvc4SygusInputGenerator &) = delete;
    /// no assignment
    Cvc4SygusInputGenerator operator=(const Cvc4SygusInputGenerator &) = delete;
    // ------------- Methods ---------------- //
    /// Export to a file
    virtual void ExportToFile(const std::string & fn) override;

  protected:
    // ------------- New Members ---------------- //
    /// generate the constraint based on the provided datapoints
    std::string generate_datapoint_constraints(TraceDataPoints * dpts) const;
    /// the datapoint
    TraceDataPoints * const dpts;

  }; // class Cvc4SygusInputGenerator

}; // namespace ilang

#endif // SYGUS_DP_H__