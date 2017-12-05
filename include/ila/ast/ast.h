/// \file
/// Header file for the class Ast and its API

#ifndef __AST_H__
#define __AST_H__

#include <memory>

namespace ila {

/// \brief The ILA AST class
/// A more elaborate class description.
class Ast {
public:
  /// constructor.
  Ast();

  /// destructor.
  ~Ast();

  /// a testing function.
  /// \param[in,out] inout a pointer.
  /// \return arbitrary value.
  bool DummyTest(int *inout);

private:
  /// a testing data member.
  const int dummy_ = 1;
}; // class Ast

/// \typedef Pointer type for Ast nodes.
typedef std::shared_ptr<Ast> AstPtr;

}; // namespace ila

#endif // __AST_H__

