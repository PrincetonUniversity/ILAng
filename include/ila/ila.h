/// \file
/// Header file for the class Ila and its API

#ifndef __ILA_H__
#define __ILA_H__

#include "ila/ast/ast.h"

namespace ila {

/// \brief The ILA class.
/// A more elaborate class description.
class Ila {
public:
  /// constructore.
  Ila();

  /// destructor
  ~Ila();

  /// a dummy function
  /// \param[in] in an input variable.
  /// \return arbitrary value.
  bool DoSomething(const int &in);

private:
  /// a testing data member.
  int dummy_;
}; // class Ila

}; // namespace ila

#endif // __ILA_H__

