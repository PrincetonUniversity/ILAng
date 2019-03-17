/// \file The module to wrap vcd-parser (CounterExample Extractor)
// ---Hongce Zhang

#ifndef CEX_EXTRACT_H__
#define CEX_EXTRACT_H__

#include <string>
#include <map>

namespace ilang {

/// \brief the class to extract counterexample from a vcd file
class CexExtractor {
public:
  // -------------------- TYPES ------------------ //
  /// a uniform value type (any radix/bool/bv should be fine)
  typedef std::string vlg_val;
  /// val_name -> val
  typedef std::map<std::string, vlg_val>  cex_t;

protected:
  /// the stored cex
  cex_t cex;
  /// the helper function to extract info from vcd
  /// for future extension, you can replace this function
  /// to deal with other file format
  void virtual parse_from(const std::string & vcd_file_name, const std::string & scope);

public:
  // -------------------- CONSTRUCTOR ------------------ //
  /// \brief to specify the input vcd name
  /// and also the scope name (the submodule instance name)
  /// to look at
  CexExtractor(const std::string & vcd_file_name, const std::string & scope);

  // -------------------- MEMBERS ------------------ //
  /// return a string to be added to the design
  std::string GenInvAssert(const std::string & sub_mod_inst_name) const;

}; // class CexExtractor


}; // namespace ilang

#endif // CEX_EXTRACT_H__