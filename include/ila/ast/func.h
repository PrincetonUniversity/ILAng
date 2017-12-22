/// file
/// Header for the class Func (uninterpreted function).

#ifndef __FUNC_H__
#define __FUNC_H__

#include "ila/ast/ast.h"
#include "ila/ast/sort.h"

/// \namespace ila
namespace ila {

/// \class Func
/// The class for uninterpreted function declaration and constraints.
class Func : public Ast {
public:
  /// \def FuncPtr
  typedef std::shared_ptr<Func> FuncPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  Func();
  /// Default destructor.
  ~Func();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  // ------------------------- METHODS -------------------------------------- //
private:
  // ------------------------- MEMBERS -------------------------------------- //
  // ------------------------- HELPERS -------------------------------------- //
}; // class Func

typedef Func::FuncPtr FuncPtr;

} // namespace ila

#endif // __FUNC_H__

