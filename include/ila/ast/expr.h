/// \file
/// Header for the class Expr and its hash

#ifndef __EXPR_H__
#define __EXPR_H__

#include "ila/ast/ast.h"
#include "ila/ast/sort.h"
#include "z3++.h"
#include "z3_api.h"
#include <memory>
#include <ostream>
#include <string>
#include <vector>

/// \namespace ila
namespace ila {

/// \brief The class for expression, which is the basic type for variables,
/// constraints, state update expressions, etc.
class Expr : public Ast {
public:
  /// Pointer type only for visitor function objects.
  typedef Expr* ExprPtrRaw;
  /// Pointer type for normal use of Expr.
  typedef std::shared_ptr<Expr> ExprPtr;
  /// Type for storing a set of Expr.
  typedef std::vector<ExprPtr> ExprPtrVec;
  /// Type for storing a set of z3 expr.
  typedef std::vector<z3::expr> Z3ExprVec;
  /// Pointer type for Z3ExprVec.
  //  typedef std::shared_ptr<Z3ExprVec> Z3ExprVecPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  Expr();
  /// Default destructor.
  virtual ~Expr();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the prefix of the expression (depends on type).
  virtual const std::string& prefix() const { return k_prefix_expr_; }

  /// Return the pointer of the sort.
  const Sort& sort() const;
  /// Return the arity.
  const size_t& arity() const;
  /// Return the i-th argument.
  ExprPtr arg(const size_t& i) const;
  /// Return the number of parameters.
  const size_t& num_param() const;
  /// Return the i-th paramter.
  const int& param(const size_t& i) const;

  /// Set the sort of the expression.
  void set_sort(const Sort& sort);
  /// Set the arity and reserve/resize the argument vector.
  void set_arity(const size_t& arity);
  /// Set the arguments.
  void set_args(const ExprPtrVec& args);
  /// Set the number of parameters.
  void set_num_param(const size_t& num_param);
  /// Set the parameters.
  void set_params(const std::vector<int> params);

  /// Is type expr (object).
  bool is_expr() const { return true; }

  /// Return true if this is a constant.
  virtual bool is_const() const { return false; }
  /// Return true if this is a variable.
  virtual bool is_var() const { return false; }
  /// Return true if this is an operation.
  virtual bool is_op() const { return false; }

  /// Return true if this is a Boolean expression.
  bool is_bool() const { return sort_.is_bool(); }
  /// Return true if this is a Bitvector expression.
  bool is_bv() const { return sort_.is_bv(); }
  /// Return true if this is an Array expression.
  bool is_mem() const { return sort_.is_mem(); }
  /// Return true if this is an Application expression.
  bool is_app() const { return sort_.is_app(); }

  // ------------------------- METHODS -------------------------------------- //
  /// Return the z3 expression for the node.
  virtual z3::expr GetZ3Expr(z3::context& z3_ctx, const Z3ExprVec& z3expr_vec,
                             const std::string& prefix = "",
                             const std::string& suffix = "") const = 0;

  /// Output to stream.
  virtual std::ostream& Print(std::ostream& out) const = 0;

  /// Compare two expression with object.
  static bool Equal(const Expr& lhs, const Expr& rhs);
  /// Compare two expression with pointer.
  static bool Equal(const ExprPtr lhs, const ExprPtr rhs);
  /// Overload comparison.
  friend bool operator==(const Expr& lhs, const Expr& rhs);
  /// Overload output stream operator
  friend std::ostream& operator<<(std::ostream& out, const Expr& expr);

  /// \brief Templated visitor: visit each node in a depth-first order and apply
  /// the function object F on it.
  template <class F> void DepthFirstVisit(F& func) {
    size_t n = arity();
    for (size_t i = 0; i != n; i++) {
      const ExprPtr arg_i = this->arg(i);
      arg_i->DepthFirstVisit<F>(func);
    }
    func(this);
  }

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The sort of the expr.
  Sort sort_;
  /// Number of arguments.
  size_t arity_;
  /// Vector of arguments.
  ExprPtrVec args_;
  /// Number of parameters.
  size_t num_param_;
  /// Vector of parameters.
  std::vector<int> params_;

  /// Static counter for expressions.
  static unsigned coutner_;
  /// Static prefix for intermediate expression name.
  static const std::string k_prefix_expr_;

  // ------------------------- HELPERS -------------------------------------- //
  /// Return true if the expression is well-sorted.
  bool IsWellSorted() const;

}; // class Expr

/// Pointer type only for visitor function objects.
typedef Expr::ExprPtrRaw ExprPtrRaw;
/// Pointer type for normal use of Expr.
typedef Expr::ExprPtr ExprPtr;
/// Type for storing a set of Expr.
typedef Expr::ExprPtrVec ExprPtrVec;
/// Type for storing a set of z3 expr.
typedef Expr::Z3ExprVec Z3ExprVec;
/// Pointer type for Z3ExprVec.
// typedef std::shared_ptr<Z3ExprVec> Z3ExprVecPtr;

/// \brief The function object for hashing Expr. The hash value is the id of the
/// symbol, which is supposed to be unique.
class ExprHash {
public:
  /// Function object for hashing
  size_t operator()(const ExprPtrRaw expr) const { return expr->name().id(); }
}; // struct ExprHash

} // namespace ila

#endif // __EXPR_H__

