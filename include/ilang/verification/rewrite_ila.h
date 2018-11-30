/// \file
/// Header for function object for rewriting ILA.

#ifndef REWRITE_ILA_H__
#define REWRITE_ILA_H__

#include <ilang/ila/instr_lvl_abs.h>

namespace ilang {

/// \brief  Function object for rewriting ILA tree.
class FuncObjRewrIla {
public:
  /// Type for storing ILA to ILA mapping.
  typedef CnstIlaMap IlaMap;

  /// Constructor.
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

/// \brief  Function object for flatten ILA tree.
/// There is currently a problem:
///   this func obj calls duplInst
///   which in turn uses rewriteExpr
///   and rewriteExpr does not change the host of
///   of state variables, so the flatten expression
///   still has the host pointed to their original
///   ILA. This is fine for Verilog Gen, which only
///   depends on variable names to generate variables
///   but may not be good enough for other purpose.
class FuncObjFlatIla {
public:
  /// Type for storing ILA to ILA mapping.
  typedef CnstIlaMap IlaMap;
  typedef std::stack<ExprPtr> ValidCondStack;

  /// Constructor.
  FuncObjFlatIla(const InstrLvlAbsCnstPtr& top_, const IlaMap& ila_map,
                 const ExprMap& expr_map);

  /// Pre-processing: create new ILA based on the given source.
  bool pre(const InstrLvlAbsCnstPtr src);
  /// Nothing.
  void post(const InstrLvlAbsCnstPtr src);

private:
  /// ILA mapping.
  IlaMap ila_map_;
  /// Expr mapping.
  ExprMap expr_map_;
  /// A stack to keep track of the hierarchical valid condition
  ValidCondStack valid_cond_stack_;
  /// Record which ila is the top level one
  InstrLvlAbsCnstPtr top_ila_;
}; // FuncObjRewrIla

} // namespace ilang

#endif // REWRITE_ILA_H__
