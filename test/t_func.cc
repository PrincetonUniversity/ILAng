/// \file
/// Unit test for function declaration.

#include "ila/ast/func.h"
#include "unit-include/util.h"

namespace ila {

TEST(TestFunc, Temporary) {
  Func func;
  std::string msg;
  GET_STDOUT_MSG(func.Print(std::cout), msg);
}

} // namespace ila

