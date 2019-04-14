/// \file Invariant Synthesis -- SyGuS
/// Bootstrap : extract simulation trace
/// You can start without bootstrap
/// but it does not work well I guess
/// --- Hongce Zhang

#ifndef SIM_TRACE_EXTRACT_H__
#define SIM_TRACE_EXTRACT_H__

#include <functional>
#include <string>
#include <map>
#include <vector>

namespace ilang {

/// \brief the class to extract counterexample from a vcd file
class SimTraceExtractor {
public:
  // -------------------- TYPES ------------------ //
  /// a uniform value type (any radix/bool/bv should be fine)
  typedef std::string vlg_val;
  /// val_name -> val
  typedef std::map<std::string, vlg_val>  ex_t;
  /// a function to determine if some name is a true signal
  typedef std::vector<ex_t> exs_t;
  /// and a register in the original design or not
  typedef std::function<bool(double time, const ex_t &)> rec_this_frame_t;
  /// a rename function
  typedef std::function<std::string(const std::string &)> sig_rename_func_t;

protected:
  /// the stored cex
  exs_t _ex;
  /// the set of coi
  const std::set<std::string> & coi;

  /// the helper function to extract info from vcd
  /// for future extension, you can replace this function
  /// to deal with other file format
  void virtual parse_from(
    const std::string & vcd_file_name, 
    const std::string & scope, 
    rec_this_frame_t rec_this_frame,
    sig_rename_func_t renamer);
    

public:
  // -------------------- CONSTRUCTOR ------------------ //
  /// \brief to specify the input vcd name
  /// and also the scope name (the submodule instance name)
  /// to look at
  SimTraceExtractor(
    const std::string & vcd_file_name, 
    const std::string & scope,
    const std::set<std::string> & signals_of_interest,
    rec_this_frame_t rec_this_frame,
    sig_rename_func_t renamer
    );

  // -------------------- MEMBERS ------------------ //
  /// allow direct access to the counterexample
  const exs_t & GetEx() const;

}; // class SimTraceExtractor

}; // namespace ilang

#endif //SIM_TRACE_EXTRACT_H__
