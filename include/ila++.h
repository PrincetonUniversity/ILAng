/// \file
/// The header for the c++ API.

#ifndef __ILAPP_H__
#define __ILAPP_H__

#include <memory>

/// \namespace ila
namespace ila {

class Expr;

class NodeRef {
private:
  std::shared_ptr<Expr> ptr_;

public:
  NodeRef(std::shared_ptr<Expr> ptr);
  ~NodeRef();

  static NodeRef ConstBool(bool val);

}; // class NodeRef

} // namespace ila

#endif // __ILAPP_H__

