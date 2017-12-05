/// \file
/// Unit test for ILA structure

#include "ila/ast/ast.h"
#include "ila/ila.h"
#include "gtest/gtest.h"

TEST(IlaUnitTest, AstConstructor) {
  ila::Ast ast_node;
  int* some_ptr = new int(1);

  bool result = ast_node.DummyTest(some_ptr);
  EXPECT_EQ(true, result);

  ila::AstPtr ast_ptr(new ila::Ast);
  result = ast_ptr->DummyTest(some_ptr);
  ASSERT_TRUE(result);

  delete some_ptr;
}

TEST(IlaUnitTest, IlaConstructor) {
  ila::Ila ila_node;
  std::string some_name = "testing ila name";

  ila_node.SetName(some_name);
  std::string result = ila_node.GetName();

  ASSERT_TRUE("testing ila name" == result);
  ASSERT_EQ("testing ila name", result);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
