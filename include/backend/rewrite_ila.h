/// \file
/// Header for function object for rewriting ILA.

#ifndef REWRITE_ILA_H__
#define REWRITE_ILA_H__

#include "ila/instr_lvl_abs.h"

namespace ila {

/// \brief  Function object for rewriting ILA tree.
class FuncObjRewrIla {
public:
  /// Type for storing ILA to ILA mapping.
  typedef CnstIlaMap IlaMap;

  /// Constructore.
  FuncObjRewrIla(const IlaMap& ila_map, const ExprMap& expr_map)
      : ila_map_(ila_map), expr_map_(expr_map) {}

  /// Return the mapped ILA.
  InstrLvlAbsPtr get(const InstrLvlAbsCnstPtr m) const;

  /// Pre-processing: create new ILA based on the given source.
  bool pre(const InstrLvlAbsCnstPtr src);
  /// Nothing.
  void post(const InstrLvlAbsCnstPtr src) const;

private:
  /// ILA mapping.
  IlaMap ila_map_;
  /// Expr mapping.
  ExprMap expr_map_;

}; // FuncObjRewrIla

} // namespace ila

#endif // REWRITE_ILA_H__

