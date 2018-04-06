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

  InstrLvlAbsPtr get(const InstrLvlAbsCnstPtr m) const;

  bool pre(const InstrLvlAbsCnstPtr src);
  void post(const InstrLvlAbsCnstPtr src) const;

private:
  IlaMap ila_map_;
  ExprMap expr_map_;

}; // FuncObjRewrIla

} // namespace ila

#endif // REWRITE_ILA_H__

