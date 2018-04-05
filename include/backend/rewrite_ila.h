/// \file
/// Header for function object for rewriting ILA.

#ifndef REWRITE_ILA_H__
#define REWRITE_ILA_H__

#include "ila/instr_lvl_abs.h"

namespace ila {

class FuncObjRewrIla {
public:
  typedef CnstIlaMap IlaMap;

  FuncObjRewrIla(const IlaMap& rule) : rule_(rule) {}

  inline InstrLvlAbsPtr get(const InstrLvlAbsCnstPtr m) const {
    auto pos = rule_.find(m);
    ILA_ASSERT(pos != rule_.end()) << m << " not found";
    return pos->second;
  }

  bool pre(const InstrLvlAbsCnstPtr src) const;
  void post(const InstrLvlAbsCnstPtr src) const;

private:
  IlaMap rule_;

}; // FuncObjRewrIla

} // namespace ila

#endif // REWRITE_ILA_H__

