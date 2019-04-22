/// \file Invariant Pruner for SyGuS 
/// for sygus datapoint approach
// Hongce Zhang

#ifndef DATAPOINT_INV_PRUNE_H__
#define DATAPOINT_INV_PRUNE_H__

#include <ilang/vtarget-out/inv-syn/sygus/datapoint.h>
#include <ilang/vtarget-out/inv-syn/inv_obj.h>

namespace ilang {

class DatapointInvariantPruner {

protected:
  // ----------- MEMBERS ---------- //
  /// the invariants to prune
  InvariantObject & invs;
  /// the datapoint we get
  const TraceDataPoints & dpts;

public:
  // ----------- CONSTRUCTOR ---------- //
  /// initially, you need to give the invariant and also the datapoint
  DatapointInvariantPruner(InvariantObject & _invs, const TraceDataPoints & _dpts);
  /// to prune using the last frame of pos example
  void PruneByLastFramePosEx(const smt::YosysSmtParser & design_info,
    std::vector<std::string> var_name_vec,
    const std::map<std::string,int> & additional_width_info
     ); // the second is the argument order
  
}; // class DatapointInvariantPruner

};

#endif // DATAPOINT_INV_PRUNE_H__