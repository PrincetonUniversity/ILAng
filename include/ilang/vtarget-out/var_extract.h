/// \file Header of variable extractor
/// This is use to extract variable from expression (string)
/// See whether it is ila-state(I/O) / vlg-state and ...
/// and change their name if needed and generate a string
// --- Hongce Zhang

#ifndef ILANG_VTARGET_OUT_VAR_EXTRACT_H__
#define ILANG_VTARGET_OUT_VAR_EXTRACT_H__

#include <functional>
#include <string>
#include <vector>

namespace ilang {

class VarExtractor {

public:
  /// Type of tokens
  typedef enum { KEEP = 0, ILA_S, ILA_IN, VLG_S, UNKN_S, NUM } token_type;
  /// Tokens
  typedef std::pair<token_type, std::string> token;
  /// Type of function pointer of string judger
  typedef std::function<bool(const std::string&)> str_j;
  /// Type of function pointer of string replacer
  typedef std::function<std::string(const token&)> str_r;

protected:
  /// token from parsed string
  std::vector<token> _tokens;
  /// a pointer to string judger (is ila state?)
  str_j _is_ila_state;
  /// a pointer to string judge (is ila input?)
  str_j _is_ila_input;
  /// a pointer to string judger (is vlg signal?)
  str_j _is_vlg_sig;

public:
  // ---------------------- CONSTRUCTOR ----------------- //
  VarExtractor(str_j is_ila_state, str_j is_ila_input, str_j is_vlg_sig);
  // ---------------------- METHODS ----------------- //
  /// Parse a string and populate the token vector, will clear the _tokens
  /// storage
  void
  ParseToExtract(const std::string& in,
                 bool force_vlg_statename =
                     false); // the later is only used in dealing w. invariants
  /// Traverse the tokens, see if replace is needed
  void ForEachTokenReplace(
      str_r replacer); // you can return the same so it will not be replaced
  /// Get back string
  std::string GenString() const;
  /// A shortcut to do all at once
  std::string Replace(const std::string& in, bool force_vlg_statename,
                      str_r replacer) {
    ParseToExtract(in, force_vlg_statename);
    ForEachTokenReplace(replacer);
    return GenString();
  }
  // ---------------------- HELPERS ----------------- //
  static bool contains_mod_inst_name(const std::string& s,
                                     const std::string& mi);

}; // class VarExtractor

}; // namespace ilang

#endif // ILANG_VTARGET_OUT_VAR_EXTRACT_H__
