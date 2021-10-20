/// \file rfexpr_shortcut.h Refinement map expression
/// construction
/// Hongce Zhang (zhanghongce@126.com)

#ifndef ILANG_RFEXPR_SHORTCUT_H__
#define ILANG_RFEXPR_SHORTCUT_H__

#include <ilang/rfmap-in/rfmap_typecheck.h>

namespace ilang {

rfmap::RfExpr rfmap_reduce_or(const rfmap::RfExpr& in);
rfmap::RfExpr rfmap_imply(const rfmap::RfExpr& l, const rfmap::RfExpr& r);
rfmap::RfExpr rfmap_and(const rfmap::RfExpr& l, const rfmap::RfExpr& r);
rfmap::RfExpr rfmap_or(const rfmap::RfExpr& l, const rfmap::RfExpr& r);
rfmap::RfExpr rfmap_and(const std::vector<rfmap::RfExpr>& v);
rfmap::RfExpr rfmap_or(const std::vector<rfmap::RfExpr>& v);

rfmap::RfExpr rfmap_ite(const rfmap::RfExpr& c, const rfmap::RfExpr& l,
                        const rfmap::RfExpr& r);

rfmap::RfExpr rfmap_eq(const rfmap::RfExpr& l, const rfmap::RfExpr& r);
rfmap::RfExpr rfmap_le(const rfmap::RfExpr& l, const rfmap::RfExpr& r);

rfmap::RfExpr rfmap_not(const rfmap::RfExpr& l);

rfmap::RfExpr rfmap_true();
rfmap::RfExpr rfmap_false();
rfmap::RfExpr rfmap_const(unsigned b, unsigned w, unsigned v);
/// if it is RTL. or ILA. then will use MakeVar
/// otherwise will use MakeSpecial
/// will not determine its type
/// ReplExpr will determine the type
rfmap::RfExpr rfmap_var(const std::string& v);

} // namespace ilang

#endif // ILANG_RFEXPR_SHORTCUT_H__
