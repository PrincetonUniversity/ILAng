/// \file The header for design statistics
// ---Hongce Zhang

#ifndef ILANG_VTARGET_OUT_DESIGN_STAT_H__
#define ILANG_VTARGET_OUT_DESIGN_STAT_H__

#include <string>
#include <vector>

namespace ilang {

/// \brief design statistics information
struct DesignStatistics {
  /// the number of state variables
  unsigned NumOfDesignStateVars;
  /// the total width of these variables
  unsigned NumOfDesignStateBits;
  /// the number of extra (outside DUV) state variables
  unsigned NumOfExtraStateVars;
  /// the total width of extra (outside DUV) variables
  unsigned NumOfExtraStateBits;
  // ----------- The timing information ----------------
  /// time for equivalence checking
  double TimeOfEqCheck;
  /// time for validation of invariants
  double TimeOfInvValidate;
  /// time for z3 proving attempt
  double TimeOfInvProof;
  /// the synthesis time of invariants : chc
  double TimeOfInvSyn;
  /// the time for generalizing invariants
  double TimeOfInvSynEnhance;
  /// the series of time spent on each cegar iteration
  std::vector<double> TimeOfInvSynSeries;
  /// Total time
  double TotalTime;

  /// Constructor -- reset all values to 0
  DesignStatistics()
      : NumOfDesignStateVars(0), NumOfDesignStateBits(0),
        NumOfExtraStateVars(0), NumOfExtraStateBits(0), TimeOfEqCheck(0),
        TimeOfInvValidate(0), TimeOfInvProof(0), TimeOfInvSyn(0), TotalTime(0) {
  }

  /// Save statistics to file
  void StoreToFile(const std::string& fn) const;

  /// Load statistics from file (checkpoints)
  void LoadFromFile(const std::string& fn);

}; // struct DesignStatistics

}; // namespace ilang

#endif // ILANG_VTARGET_OUT_DESIGN_STAT_H__