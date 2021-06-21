/// \file rfexpr_to_smt.cc Refinement map to smt-lib2
/// Hongce Zhang (hongcez@princeton.edu)


#ifndef ILANG_RFEXPR_TO_SMT_H__
#define ILANG_RFEXPR_TO_SMT_H__

#include <ilang/rfmap-in/rfmap_typecheck.h>

namespace ilang {
namespace rfmap {

struct RfExpr2Smt{

public:
  static std::string to_smt2(const RfExpr &in, bool request_bool);

protected:
  // helper function
  static std::string to_smt2_const(const std::shared_ptr<verilog_expr::VExprAstConstant> & in, bool request_bool);
  static std::string to_smt2_var(const std::shared_ptr<verilog_expr::VExprAstVar> & in, bool request_bool);

}; // struct RfExpr2Smt


} // namespace rfmap
} // namespace ilang


#endif // ILANG_RFEXPR_TO_SMT_H__
