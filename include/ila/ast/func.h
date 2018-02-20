/// \file
/// Header for the class Func (uninterpreted function).

#ifndef FUNC_H__
#define FUNC_H__

#include "ila/ast/ast.h"
#include "ila/ast/sort.h"
#include "ila/defines.h"

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
  /// Constructor for zero-argument function (non-determinism).
  Func(const std::string& name, const Sort& out = Sort::MakeBoolSort());
  /// Constructor for one-argument function.
  Func(const std::string& name, const Sort& out, const Sort& arg0);
  /// Constructor for two-argument function.
  Func(const std::string& name, const Sort& out, const Sort& arg0,
       const Sort& arg1);
  /// Constructor for multiple-argument function.
  Func(const std::string& name, const Sort& out, const std::vector<Sort>& args);

  /// Default destructor.
  ~Func();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the output sort.
  const Sort& out() const { return out_; }
  /// Return the number of arguments.
  size_t arg_num() const { return args_.size(); }
  /// Return the sort of the i-th argument.
  const Sort& arg(const int& i) const { return args_.at(i); }

  // ------------------------- METHODS -------------------------------------- //
  /// Check if the input arguments match the specified sort.
  bool Check(const std::vector<std::shared_ptr<Expr>>& args) const;

  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;

  /// Overload output stream.
  friend std::ostream& operator<<(std::ostream& out, const FuncPtr f) {
    return f->Print(out);
  }

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Sort of the output (range).
  Sort out_;
  /// Sort of the input arguments (domain).
  std::vector<Sort> args_;

  // ------------------------- HELPERS -------------------------------------- //
}; // class Func

/// Pointer type for normal use of Func.
typedef Func::FuncPtr FuncPtr;

} // namespace ila

#endif // FUNC_H__

