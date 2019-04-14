/// \file Invariant Synthesis -- SyGuS
/// to work with CVC4 (the latest version please)
/// The data-point (dp) approach
/// (not passing the whole transition function)
/// 
// Hongce Zhang

#ifndef SYGUS_DP_H__
#define SYGUS_DP_H__

#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/smt-inout/yosys_smt_parser.h>

#include <string>
#include <vector>
#include <map>

namespace ilang
{
  /// \brief the data point type
  struct TraceDataPoints {
    // ------------- TYPES ---------------- //
    /// the type of values
    /// the number here will be converted to #x... / #b... when needed
    typedef std::pair<unsigned, smt::var_type> value_t;
    /// the type of example collectors: name -> value
    typedef std::map<std::string,value_t> example_map_t;
    // ------------- MEMBER ---------------- //
    /// The positive examples
    example_map_t pos_ex;
    /// The negative examples
    example_map_t neg_ex;
  };  // struct TraceDataPoints

  /// \brief to generate an input based on pos/neg examples
  class Cvc4SygusInputGenerator {
    /// the options it takes
    using sygus_options_t = VlgVerifTgtGenBase::vtg_config_t::_sygus_options_t;
  protected:
    // ------------- MEMBER ---------------- //
    /// the vocabulary -- the variables to consider
    std::vector<std::string> var_names;
    /// we need a pointer to smt-parsed data
    const smt::YosysSmtParser & design_info;
    /// a local copy of the options
    sygus_options_t options;
  public:
    // ------------- Constructor ---------------- //
    Cvc4SygusInputGenerator(
      const smt::YosysSmtParser & _design_info,       // the design info is needed
      const std::vector<std::string> & _var_name_vec, // the variables we are going to consider
      const sygus_options_t & SygusOptions           // the options
      );
    /// no copy constructor
    Cvc4SygusInputGenerator(const Cvc4SygusInputGenerator &) = delete;
    /// no assignment
    Cvc4SygusInputGenerator operator=(const Cvc4SygusInputGenerator &) = delete;
    // ------------- Methods ---------------- //
    /// Export to a file
    void ExportToFile(const std::string & fn, TraceDataPoints * dpts);
  }; // class Cvc4SygusInputGenerator

}; // namespace ilang

#endif // SYGUS_DP_H__