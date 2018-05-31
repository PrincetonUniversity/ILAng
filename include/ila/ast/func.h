/// \file
/// Header for the class Func (uninterpreted function).

#ifndef FUNC_H__
#define FUNC_H__

#include "ila/ast/ast.h"
#include "ila/ast/sort.h"
#include "ila/defines.h"
#include "z3++.h"

/// \namespace ila
namespace ila {

// Forward declaration.
class Expr;

/// \brief The class for uninterpreted function.
class Func : public Ast {
public:
  /// Pointer type for normal use of Func.
  typedef std::shared_ptr<Func> FuncPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor for multiple-argument function.
  Func(const std::string& name, const SortPtr out,
       const std::vector<SortPtr>& args);

  /// Default destructor.
  ~Func();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the output sort.
  const SortPtr out() const { return out_; }
  /// Return the number of arguments.
  size_t arg_num() const { return args_.size(); }
  /// Return the sort of the i-th argument.
  const SortPtr arg(const int& i) const { return args_.at(i); }

  // ------------------------- METHODS -------------------------------------- //
  /// Create an uninterpreted function (Func) with no input (nondet).
  static FuncPtr New(const std::string& name,
                     const SortPtr out = Sort::MakeBoolSort());
  /// Create an uninterpreted function (Func) with one input.
  static FuncPtr New(const std::string& name, const SortPtr out,
                     const SortPtr arg0);
  /// Create an uninterpreted function (Func) with two inputs.
  static FuncPtr New(const std::string& name, const SortPtr out,
                     const SortPtr arg0, const SortPtr arg1);
  /// Create an uninterpreted function (Func) with multiple inputs.
  static FuncPtr New(const std::string& name, const SortPtr out,
                     const std::vector<SortPtr>& args);

  /// Check if the input arguments match the specified sort.
  bool CheckSort(const std::vector<std::shared_ptr<Expr>>& args) const;

  /// Return the z3 func_decl.
  z3::func_decl GetZ3FuncDecl(z3::context& ctx) const;

  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;

  /// Overload output stream.
  friend std::ostream& operator<<(std::ostream& out, const FuncPtr f) {
    return f->Print(out);
  }

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Sort of the output (range).
  SortPtr out_;
  /// Sort of the input arguments (domain).
  std::vector<SortPtr> args_;

  // ------------------------- HELPERS -------------------------------------- //
}; // class Func

/// Pointer type for normal use of Func.
typedef Func::FuncPtr FuncPtr;

} // namespace ila

#endif // FUNC_H__

