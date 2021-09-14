/// \file rfexpr_to_smt.cc Refinement map to smt-lib2
/// Hongce Zhang (hongcez@princeton.edu)

#ifndef ILANG_RFEXPR_TO_SMT_H__
#define ILANG_RFEXPR_TO_SMT_H__

#include <ilang/rfmap-in/rfmap_typecheck.h>

namespace ilang {
namespace rfmap {

struct SmtType : public RfMapVarType {
  bool bool_or_bv;

  SmtType() : RfMapVarType(1), bool_or_bv(true) {}
  SmtType(unsigned w) : RfMapVarType(w), bool_or_bv(false) {}
  SmtType(unsigned a, unsigned d) : RfMapVarType(a, d), bool_or_bv(false) {}
  SmtType(const RfMapVarType& r, bool request_bool)
      : RfMapVarType(r), bool_or_bv(request_bool) {}

  bool is_bool() const { return bool_or_bv && (RfMapVarType::is_bv()); }
  bool is_bv() const { return (!bool_or_bv) && (RfMapVarType::is_bv()); }
  bool operator==(const SmtType& r) const {
    if (bool_or_bv != r.bool_or_bv)
      return false;
    if (type != r.type)
      return false;
    if (type == TYPE::BV)
      return width == r.width;
    if (type == TYPE::MEM)
      return data_width == r.data_width && addr_width == r.addr_width;
    return false; // unknown type , unknown
  }               // operator=

  std::string type_to_smt2() const;

}; // SmtType

struct RfExpr2Smt {

public:
  static std::string to_smt2(const RfExpr& in, SmtType expected_type);

protected:
  // helper function
  static std::string
  to_smt2_const(const std::shared_ptr<verilog_expr::VExprAstConstant>& in,
                SmtType expected_type);
  static std::string
  to_smt2_var(const std::shared_ptr<verilog_expr::VExprAstVar>& in,
              SmtType expected_type);

}; // struct RfExpr2Smt

} // namespace rfmap
} // namespace ilang

#endif // ILANG_RFEXPR_TO_SMT_H__
