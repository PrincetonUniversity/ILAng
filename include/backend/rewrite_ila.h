/// \file
/// Header for function object for rewriting ILA.

#ifndef REWRITE_ILA_H__
#define REWRITE_ILA_H__

#include "ila/instr_lvl_abs.h"

namespace ila {

class FuncObjRewrIla {
public:
  typedef CnstIlaMap IlaMap;

  FuncObjRewrIla(const IlaMap& ila_map, const ExprMap& expr_map)
      : ila_map_(ila_map), expr_map_(expr_map) {}

  inline InstrLvlAbsPtr get(const InstrLvlAbsCnstPtr m) const {
    auto pos = ila_map_.find(m);
    ILA_ASSERT(pos != ila_map_.end()) << m << " not found";
    return pos->second;
  }

  bool pre(const InstrLvlAbsCnstPtr src);
  void post(const InstrLvlAbsCnstPtr src) const;

private:
  IlaMap ila_map_;
  ExprMap expr_map_;

  inline void UpdtIla(const InstrLvlAbsCnstPtr src, const InstrLvlAbsPtr dst) {
    ILA_ASSERT(ila_map_.find(src) == ila_map_.end()) << "Re-mapping " << src;
    ila_map_.insert({src, dst});
  }

  inline void UpdtExpr(const ExprPtr src, const ExprPtr dst) {
    ILA_ASSERT(expr_map_.find(src) == expr_map_.end()) << "Re-mapping " << src;
    expr_map_.insert({src, dst});
  }

  void ImitateInput(const InstrLvlAbsCnstPtr src, const InstrLvlAbsPtr dst);

  void ImitateState(const InstrLvlAbsCnstPtr src, const InstrLvlAbsPtr dst);

  ExprPtr NewInput(const InstrLvlAbsPtr m, const ExprPtr inp);
  ExprPtr NewState(const InstrLvlAbsPtr m, const ExprPtr stt);

  void RewriteInstr(const InstrCnstPtr src, const InstrPtr dst);

}; // FuncObjRewrIla

} // namespace ila

#endif // REWRITE_ILA_H__

