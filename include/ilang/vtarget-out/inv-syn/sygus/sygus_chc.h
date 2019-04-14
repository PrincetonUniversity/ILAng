/// \file Invariant Synthesis -- SyGuS
/// to work with CVC4 (the latest version please)
/// The chc approach
/// (passing the whole transition function)
/// 
// Hongce Zhang

#ifndef SYGUS_CHC_H__
#define SYGUS_CHC_H__


#include <string>
#include <vector>
#include <map>

namespace ilang
{
  /// \brief to generate an input based on pos/neg examples
  class Cvc4SygusChcGenerator {
    /// the options it takes
    using sygus_options_t = VlgVerifTgtGenBase::vtg_config_t::_sygus_options_t;
  public:
    // ------------- Constructor ---------------- //
    Cvc4SygusChcGenerator();
    /// no copy constructor
    Cvc4SygusChcGenerator(const Cvc4SygusInputGenerator &) = delete;
    /// no assignment
    Cvc4SygusChcGenerator operator=(const Cvc4SygusInputGenerator &) = delete;
    // ------------- Methods ---------------- //
  }; // class Cvc4SygusChcGenerator

}; // namespace ilang

#endif // SYGUS_CHC_H__

