/// \file The header for design statistics
// ---Hongce Zhang

#ifndef DESIGN_STAT_H__
#define DESIGN_STAT_H__

#include <vector>
#include <string>

namespace ilang {

/// \brief design statistics information 
struct DesignStatistics {
  /// the number of state variables
  unsigned NumOfDesignStateVars;
  /// the total width of these variables
  unsigned NumOfDesignStateBits;
  /// the number of state variables
  unsigned NumOfExtraStateVars;
  /// the total width of these variables
  unsigned NumOfExtraStateBits;
  // ----------- The timing information ----------------
  /// time for equivalence checking
  double TimeOfEqCheck;
  /// time for validation of invariants
  double TimeOfInvValidate;
  /// time for z3 proving attempt
  double TimeOfInvProof;
  /// the synthesis time of invariants : chc/sygus-chc/sygus-dp
  double TimeOfInvSyn;
  /// the synthesis time of invariants : chc/sygus-chc/sygus-dp
  double TimeOfInvSynEnhance;
  /// the series of time
  std::vector<double> TimeOfInvSynSeries;
  /// Total time
  double TotalTime;

  /// Constructor -- reset all values to 0
  DesignStatistics() : 
    NumOfDesignStateVars(0),
    NumOfDesignStateBits(0),
    NumOfExtraStateVars(0),
    NumOfExtraStateBits(0),
    TimeOfEqCheck(0), TimeOfInvValidate(0), 
    TimeOfInvProof(0), TimeOfInvSyn(0), TotalTime(0) {} 
  
  void StoreToFile(const std::string & fn) const;

  void LoadFromFile(const std::string & fn);

}; // struct DesignStatistics

}; // namespace ilang

#endif // DESIGN_STAT_H__
