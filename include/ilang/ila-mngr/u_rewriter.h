/// \file
/// Function objects for rewriting ILA and Expr.

#ifndef ILANG_ILA_MNGR_U_REWRITER_H__
#define ILANG_ILA_MNGR_U_REWRITER_H__

#include <ilang/ila/instr_lvl_abs.h>

namespace ilang {

/// \brief Function object for rewriting Expr.
class FuncObjRewrExpr {
public:
  /// Constructor, initialize rewriting rule.
  FuncObjRewrExpr(const ExprMap& rule) : rule_(rule) {}

  /// Return the rewritten result.
  ExprPtr get(const ExprPtr& e) const;

  /// Pre-process: return true (break) if the node has been visited.
  bool pre(const ExprPtr& e) const;
  /// Post-process: update the rewriting rule map.
  void post(const ExprPtr& e);

protected:
  /// Internal rewriting table.
  ExprMap rule_;

  /// Rewrite all sorts of Expr.
  virtual ExprPtr Rewrite(const ExprPtr& e) const;
  /// Rewrite Operation sorted Expr.
  virtual ExprPtr RewriteOp(const ExprPtr& e) const;

}; // class FuncObjRewrExpr

/// \brief  Function object for rewriting ILA tree.
class FuncObjRewrIla {
private:
  /// Type for storing ILA to ILA mapping.
  typedef CnstIlaMap IlaMap;

public:
  /// Constructor.
  FuncObjRewrIla(const IlaMap& ila_map, const ExprMap& expr_map)
      : ila_map_(ila_map), expr_map_(expr_map) {}

  /// Return the mapped ILA.
  InstrLvlAbsPtr get(const InstrLvlAbsCnstPtr& m) const;

  /// Pre-processing: create new ILA based on the given source.
  bool pre(const InstrLvlAbsCnstPtr& src);
  /// Nothing.
  void post(const InstrLvlAbsCnstPtr& src) const;

private:
  /// ILA mapping.
  IlaMap ila_map_;
  /// Expr mapping.
  ExprMap expr_map_;

}; // FuncObjRewrIla

/// \brief  Function object for flatten ILA tree.
class FuncObjFlatIla {

  /* There is currently a problem:
  This func obj calls duplInst which in turn uses rewriteExpr and rewriteExpr
  does not change the host of of state variables, so the flatten expression
  still has the host pointed to their original ILA. This is fine for Verilog
  Gen, which only depends on variable names to generate variables but may not be
  good enough for other purpose.
    - Hongce
  */

private:
  /// Type for storing ILA to ILA mapping.
  typedef CnstIlaMap IlaMap;

public:
  /// Constructor.
  FuncObjFlatIla(const InstrLvlAbsCnstPtr& top_, const IlaMap& ila_map,
                 const ExprMap& expr_map);

  /// Pre-processing: create new ILA based on the given source.
  bool pre(const InstrLvlAbsCnstPtr& src);
  /// Nothing.
  void post(const InstrLvlAbsCnstPtr& src);

private:
  /// Type for holding valid condition stack across the hierarchy.
  typedef std::stack<ExprPtr> ValidCondStack;

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

#endif // ILANG_ILA_MNGR_U_REWRITER_H__
