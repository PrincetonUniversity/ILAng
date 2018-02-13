/// \file
/// The header for the c++ API.

#ifndef __ILAPP_H__
#define __ILAPP_H__

#include <memory>

/// \namespace ila
namespace ila {

class Expr;

/// \brief The reference of Expr (e.g. state var, var relation, constant, etc).
class ExprRef {
private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Pointer to the actual data.
  std::shared_ptr<Expr> ptr_;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with the pointer of the actual data.
  ExprRef(std::shared_ptr<Expr> ptr);
  /// Default destructor
  ~ExprRef();

  // ------------------------- METHODS -------------------------------------- //
  /// Overload unsigned add.
  ExprRef operator+(const ExprRef& rhs) const;

}; // class NodeRef

static ExprRef BoolConst(bool bool_val);
static ExprRef BvConst(const int& bv_val, const int& bit_width);

class InstrRef {
  // TODO
}; // class

} // namespace ila

#endif // __ILAPP_H__

