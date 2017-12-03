/// \file
/// Unit test for ILA ast

#include "ila/ast/ast.h"
#include <gtest/gtest.h>

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  Ast test_unit;
  int *nullPointer = NULL;
  bool result = test_unit.DummyTest(nullPointer);

  return 0;
}
