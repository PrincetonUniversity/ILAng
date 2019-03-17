/// \file Invariant Object --- should be able to parse from
/// a smt-like-output
// Hongce Zhang

#ifndef INV_OBJ_H__
#define INV_OBJ_H__

#include <ilang/smt-inout/yosys_smt_parser.h>

#include <string>

namespace ilang {

/// \brief the invariant object, it needs smt-info to parse
class InvariantObject{
public:
  // ----------- CONSTRUCTOR ---------- //
  /// empty invariants
  InvariantObject();
  /// add invariants from smt-like output
  void AddInvariantFromSmt(smt::YosysSmtParser & , const std::string & tag, const std::string & smt_result);
  /// add invariants from verilog-like output
  void AddInvariantFromVerilog(const std::string & tag, const std::string & vlg_in);
  /// generate invariants
  std::string GenerateVlgConstraints() const;
};

}; // namespace ilang

#endif // INV_OBJ_H__