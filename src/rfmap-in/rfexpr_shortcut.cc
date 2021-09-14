/// \file rfexpr_to_smt.cc Refinement map to smt-lib2
///  Hongce Zhang (zhanghongce@126.com)

#include <ilang/rfmap-in/rfexpr_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

rfmap::RfExpr rfmap_reduce_or(const rfmap::RfExpr& in) {
  return verilog_expr::VExprAst::MakeUnaryAst(verilog_expr::voperator::B_OR,
                                              in);
}

rfmap::RfExpr rfmap_imply(const rfmap::RfExpr& l, const rfmap::RfExpr& r) {
  return rfmap_or(rfmap_not(l), r);
}

rfmap::RfExpr rfmap_and(const rfmap::RfExpr& l, const rfmap::RfExpr& r) {
  return verilog_expr::VExprAst::MakeBinaryAst(verilog_expr::voperator::L_AND,
                                               l, r);
}

rfmap::RfExpr rfmap_or(const rfmap::RfExpr& l, const rfmap::RfExpr& r) {
  return verilog_expr::VExprAst::MakeBinaryAst(verilog_expr::voperator::L_OR, l,
                                               r);
}

rfmap::RfExpr rfmap_and(const std::vector<rfmap::RfExpr>& v) {
  ILA_ERROR_IF(v.empty()) << "rfmap_and([])";

  auto ret = v.at(0);
  for (size_t idx = 1; idx < v.size(); ++idx)
    ret = rfmap_and(ret, v.at(idx));
  return ret;
}

rfmap::RfExpr rfmap_or(const std::vector<rfmap::RfExpr>& v) {
  ILA_ERROR_IF(v.empty()) << "rfmap_or([])";

  auto ret = v.at(0);
  for (size_t idx = 1; idx < v.size(); ++idx)
    ret = rfmap_or(ret, v.at(idx));
  return ret;
}

rfmap::RfExpr rfmap_ite(const rfmap::RfExpr& c, const rfmap::RfExpr& l,
                        const rfmap::RfExpr& r) {
  return verilog_expr::VExprAst::MakeTernaryAst(
      verilog_expr::voperator::TERNARY, c, l, r);
}

rfmap::RfExpr rfmap_eq(const rfmap::RfExpr& l, const rfmap::RfExpr& r) {
  return verilog_expr::VExprAst::MakeBinaryAst(verilog_expr::voperator::L_EQ, l,
                                               r);
}

rfmap::RfExpr rfmap_le(const rfmap::RfExpr& l, const rfmap::RfExpr& r) {
  return verilog_expr::VExprAst::MakeBinaryAst(verilog_expr::voperator::LTE, l,
                                               r);
}

rfmap::RfExpr rfmap_not(const rfmap::RfExpr& l) {
  return verilog_expr::VExprAst::MakeUnaryAst(verilog_expr::voperator::L_NEG,
                                              l);
}

rfmap::RfExpr rfmap_true() {
  return verilog_expr::VExprAst::MakeConstant(2, 1, "1");
}

rfmap::RfExpr rfmap_false() {
  return verilog_expr::VExprAst::MakeConstant(2, 1, "0");
}

rfmap::RfExpr rfmap_const(unsigned b, unsigned w, unsigned v) {
  return verilog_expr::VExprAst::MakeConstant(b, w,
                                              IntToStrCustomBase(v, b, false));
}
/// if it is RTL. or ILA. then will use MakeVar
/// otherwise will use MakeSpecial
/// will not determine its type
/// ReplExpr will determine the type
rfmap::RfExpr rfmap_var(const std::string& v) {
  if (StrStartsWith(v, "RTL.") || StrStartsWith(v, "ILA."))
    return verilog_expr::VExprAst::MakeVar(v);
  return verilog_expr::VExprAst::MakeSpecialName(v);
}

} // namespace ilang
