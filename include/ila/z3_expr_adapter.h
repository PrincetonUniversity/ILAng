/// \file
/// Header for the class Z3ExprAdapter

#ifndef __Z3_EXPR_ADAPTER_H__
#define __Z3_EXPR_ADAPTER_H__

#include "ila/ast/expr.h"
#include "z3++.h"
#include <unordered_map>

/// \namespace ila
namespace ila {

/// \class Z3ExprAdapter
/// The class for generating z3 expression from the ast expression.
class Z3ExprAdapter {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor.
  Z3ExprAdapter(z3::context& ctx);
  /// ~Default destructor.
  ~Z3ExprAdapter();

  /// \def ExprMap
  typedef std::unordered_map<const ExprPtrRaw, z3::expr, ExprHash> ExprMap;

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the flag of whether to perform simplification.
  const bool& simplify() const;
  /// Return the underlying z3 context.
  z3::context& ctx() const;

  /// Perform expression simplification if true.
  void set_simplify(const bool& sim);

  // ------------------------- METHODS -------------------------------------- //
  /// Get the z3 expression of the AST node.
  /// \param[in] expr the AST node.
  /// \prram[in] suffix the suffix for terminating nodes (e.g. time frame)
  /// \return z3 expression
  z3::expr GetZ3Expr(const ExprPtr expr, const std::string& suffix = "");

  /// Clear the cached values. (Should be called for every time frame)
  void Clear();

  /// Function object for getting z3 expression.
  void operator()(const ExprPtrRaw expr);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Flag of simplification.
  bool simplify_;
  /// The underlying z3 context.
  z3::context& ctx_;
  /// Container for cacheing intermediate expressions.
  ExprMap expr_map_;
  /// Name suffix for each expression generation (time frame)
  std::string suffix_;

  // ------------------------- HELPERS -------------------------------------- //
  /// Insert the z3 expression of the given node into the map.
  void PopulateExprMap(const ExprPtrRaw expr);

}; // class Z3Adapter

} // namespace ila

#endif // __Z3_EXPR_ADAPTER_H__

