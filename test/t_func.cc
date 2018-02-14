/// \file
/// Unit test for function declaration.

#include "ila/ast/func.h"
#include "unit-include/util.h"

namespace ila {

TEST(TestFunc, Temporary) {
  Func func;
  z3::context c;
  Z3ExprVec vec;
  auto e = func.GetZ3Expr(c, vec, "");
  std::string msg;
  GET_STDOUT_MSG(func.Print(std::cout), msg);
}

} // namespace ila

