/// \file Invariant Synthesis -- SyGuS
/// Extract invariant validating counterexample
/// but it does not work well I guess
/// --- Hongce Zhang

#ifndef INV_CEX_EXTRACT_H__
#define INV_CEX_EXTRACT_H__

#include <ilang/smt-inout/smt_ast.h>

#include <map>

namespace ilang {


/// \brief the class to extract counterexample from a vcd file
class InvCexExtractor {
public:
  // -------------------- TYPES ------------------ //
  /// a uniform value type (any radix/bool/bv should be fine)
  /// radix must be in 2 10 16
  /// here we need to correct this
  typedef std::pair<std::string , smt::var_type> value_t;
  /// val_name -> val
  typedef std::map<std::string, value_t>  cex_t;
  /// a function to determine if some name is a true signal
  /// and a register in the original design or not
  typedef std::function<bool(const std::string &)> is_coi_state_t;

protected:
  /// the stored cex
  cex_t cex;
  /// the helper function to extract info from vcd
  /// for future extension, you can replace this function
  /// to deal with other file format
  void virtual parse_from(const std::string & vcd_file_name, 
    const std::string & scope, is_coi_state_t is_coi);

public:
  // -------------------- CONSTRUCTOR ------------------ //
  /// \brief to specify the input vcd name
  /// and also the scope name (the submodule instance name)
  /// to look at
  InvCexExtractor(const std::string & vcd_file_name, 
    const std::string & scope, is_coi_state_t is_coi);

  // -------------------- MEMBERS ------------------ //
  /// return a string to be added to the design
  const cex_t & GetCex() const;
}; // class InvCexExtractor

}; // namespace ilang

#endif //INV_CEX_EXTRACT_H__
