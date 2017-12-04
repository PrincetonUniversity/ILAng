/// \file
/// Unit test for ILA structure

#include "ila/ila.h"
#include "ila/ast/ast.h"
#include "gtest/gtest.h"

TEST(IlaUnitTest, AstConstructor) {
  ila::Ast astNode;
  int *somePointer = new int(1);

  bool result = astNode.DummyTest(somePointer);
  EXPECT_EQ(true, result);

  delete somePointer;
}

TEST(IlaUnitTest, IlaConstructor) {
  ila::Ila ilaNode;
  int arbitraryVal;

  bool result = ilaNode.DoSomething(arbitraryVal);
  ASSERT_TRUE(result);
  ASSERT_EQ(true, result);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
