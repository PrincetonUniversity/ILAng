/// \file
/// Class Expr - base class of expression nodes.

#ifndef ILANG_ILA_AST_EXPR_H__
#define ILANG_ILA_AST_EXPR_H__

#include <memory>
#include <ostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <z3++.h>
#include <z3_api.h>

#include <ilang/ila/ast/ast.h>
#include <ilang/ila/ast/sort.h>

/// \namespace ilang
namespace ilang {

/// \brief The class for expression, which is the basic type for variables,
/// constraints, state update expressions, etc.
class Expr : public Ast, public std::enable_shared_from_this<Expr> {
public:
  /// Pointer type for normal use of Expr.
  typedef std::shared_ptr<Expr> ExprPtr;
  /// Type for storing a set of Expr.
  typedef std::vector<ExprPtr> ExprPtrVec;

protected:
  /// Vector type for z3 expression.
  typedef std::vector<z3::expr> Z3ExprVec;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  Expr();
  /// Constructor with name.
  Expr(const std::string& name);
  /// Default destructor.
  virtual ~Expr();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the pointer of the sort.
  inline const SortPtr sort() const { return sort_; }
  /// Retrun the number of argument (arity).
  inline size_t arg_num() const { return args_.size(); }
  /// Return the i-th argument.
  inline ExprPtr arg(const size_t& i) const { return args_.at(i); }
  /// Return the number of parameters.
  inline size_t param_num() const { return params_.size(); }
  /// Return the i-th paramter.
  inline int param(const size_t& i) const { return params_.at(i); }

  /// Set the sort of the expression.
  void set_sort(const SortPtr sort);
  /// Set the arguments.
  void set_args(const ExprPtrVec& args);
  /// Set the parameters.
  void set_params(const std::vector<int> params);
  /// Replace the i-th argument.
  void replace_arg(const int& idx, const ExprPtr& arg);
  /// Replace the "a" argument with "b" argument with "exist".
  void replace_arg(const ExprPtr& a, const ExprPtr& b);

  /// Is type expr (object).
  bool is_expr() const { return true; }

  /// Return true if this is a constant.
  virtual bool is_const() const { return false; }
  /// Return true if this is a variable.
  virtual bool is_var() const { return false; }
  /// Return true if this is an operation.
  virtual bool is_op() const { return false; }

  /// Return true if this is a Boolean expression.
  inline bool is_bool() const { return sort_->is_bool(); }
  /// Return true if this is a Bitvector expression.
  inline bool is_bv(const int& width = 0) const { return sort_->is_bv(width); }
  /// Return true if this is an Array expression.
  inline bool is_mem() const { return sort_->is_mem(); }

  // ------------------------- METHODS -------------------------------------- //
  /// Return the z3 expression for the node.
  virtual z3::expr GetZ3Expr(z3::context& z3_ctx, const Z3ExprVec& z3expr_vec,
                             const std::string& suffix = "") const = 0;

  /// Output to stream.
  virtual std::ostream& Print(std::ostream& out) const = 0;

  /// Pretty output function
  virtual std::ostream& PrintPretty(std::ostream& out) const = 0;

  /// Overload output stream operator for pointer.
  friend std::ostream& operator<<(std::ostream& out, const ExprPtr& expr) {
    return expr->Print(out);
  }

  /// \brief Templated visitor: visit each node in a depth-first order and apply
  /// the function object F on it.
  template <class F> void DepthFirstVisit(F& func) {
    for (size_t i = 0; i != arg_num(); i++) {
      auto arg_i = this->arg(i);
      arg_i->DepthFirstVisit<F>(func);
    }
    func(shared_from_this());
  }

  /// \brief Templated visitor: visit each node in a depth-first order and apply
  /// the function object F pre/pose on it.
  template <class F> void DepthFirstVisitPrePost(F& func) {
    // pre check
    if (func.pre(shared_from_this())) { // break if return true
      return;
    }
    // traverse child
    for (size_t i = 0; i != arg_num(); i++) {
      auto arg_i = this->arg(i);
      arg_i->DepthFirstVisitPrePost<F>(func);
    }
    // post
    func.post(shared_from_this());
  }

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The sort of the expr.
  SortPtr sort_;
  /// Vector of arguments.
  ExprPtrVec args_;
  /// Vector of parameters.
  std::vector<int> params_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class Expr

/// Pointer type for normal use of Expr.
typedef Expr::ExprPtr ExprPtr;
/// Type for storing a set of Expr.
typedef Expr::ExprPtrVec ExprPtrVec;

/// \brief The function object for hashing Expr. The hash value is the id of the
/// symbol, which is supposed to be unique.
class ExprHash {
public:
  /// Function object for hashing
  size_t operator()(const ExprPtr& expr) const { return expr->name().id(); }
}; // class ExprHash

/// Type for mapping between Expr.
typedef std::unordered_map<const ExprPtr, const ExprPtr, ExprHash> ExprMap;
/// Type for storing a set of Expr.
typedef std::unordered_set<ExprPtr, ExprHash> ExprSet;

} // namespace ilang

#endif // ILANG_ILA_AST_EXPR_H__
