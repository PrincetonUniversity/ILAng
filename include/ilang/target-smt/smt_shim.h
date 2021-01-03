/// \file
/// Templated class SmtShim - higher-level wrapper for z3 and smt-switch.

#ifndef ILANG_TARGET_SMT_SMT_SHIM_H__
#define ILANG_TARGET_SMT_SMT_SHIM_H__

#include <ilang/ila/ast/func.h>
#include <ilang/ila/ast_hub.h>

/// \namespace ilang
namespace ilang {

/// \brief A templated class for wrapping z3 and smt-switch to provide a unified
/// interface for different application, e.g., unroller.
template <class Generator> class SmtShim {
public:
  /// Constructor.
  SmtShim(Generator& gen) : gen_(gen) {}

private:
  /// Reference to the underlying SMT formula generator.
  Generator& gen_;
  /// Type alias for expression.
  typedef decltype(gen_.GetShimExpr(nullptr, "")) ShimExprType;

public:
  /// Unified interface to get expression.
  inline auto GetShimExpr(const ExprPtr& expr, const std::string& suffix = "") {
    return gen_.GetShimExpr(expr, suffix);
  }
  /// Unified interface to get function declaration.
  inline auto GetShimFunc(const FuncPtr& func) {
    return gen_.GetShimFunc(func);
  }
  /// Unified interface to AND two boolean expressions.
  inline auto BoolAnd(const ShimExprType& a, const ShimExprType& b) {
    return gen_.BoolAnd(a, b);
  }
  /// Unified interface to Equal two expressions.
  inline auto Equal(const ShimExprType& a, const ShimExprType& b) {
    return gen_.Equal(a, b);
  }
  /// Return the underlying generator.
  inline Generator& get() const { return gen_; }

}; // class SmtShim

} // namespace ilang

#endif // ILANG_TARGET_SMT_SMT_SHIM_H__
