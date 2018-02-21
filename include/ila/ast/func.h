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
private:
  /// Internal structure for wrapping constructor arguments from shared_ptr
  struct FuncConfig {
    /// Constructor for wrapping the arguments.
    FuncConfig(const std::string& name, const Sort& out,
               const std::vector<Sort>& args)
        : name_(name), out_(out), args_(args) {}
    /// Wrapped data: function name.
    const std::string& name_;
    /// Wrapped data: output sort.
    const Sort& out_;
    /// Wrapper data: input sorts.
    const std::vector<Sort>& args_;
  }; // struct FuncConfig

public:
  /// Pointer type for normal use of Func.
  typedef std::shared_ptr<Func> FuncPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor for multiple-argument function.
  Func(const FuncConfig& config);

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
  /// Create an uninterpreted function (Func) with no input (nondet).
  static FuncPtr New(const std::string& name,
                     const Sort& out = Sort::MakeBoolSort());
  /// Create an uninterpreted function (Func) with one input.
  static FuncPtr New(const std::string& name, const Sort& out,
                     const Sort& arg0);
  /// Create an uninterpreted function (Func) with two inputs.
  static FuncPtr New(const std::string& name, const Sort& out, const Sort& arg0,
                     const Sort& arg1);
  /// Create an uninterpreted function (Func) with multiple inputs.
  static FuncPtr New(const std::string& name, const Sort& out,
                     const std::vector<Sort>& args);

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
  Sort out_;
  /// Sort of the input arguments (domain).
  std::vector<Sort> args_;

  // ------------------------- HELPERS -------------------------------------- //
}; // class Func

/// Pointer type for normal use of Func.
typedef Func::FuncPtr FuncPtr;

} // namespace ila

#endif // FUNC_H__

