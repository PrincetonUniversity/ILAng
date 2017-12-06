/// \file
/// Unit test for ILA structure.

#include "ila/ast/ast.h"
#include "ila/ila.h"
#include "gtest/gtest.h"

namespace ila {

TEST(IlaUnitTest, AstConstructor) {
  Ast ast_node;
  int* some_ptr = new int(1);

  bool result = ast_node.DummyTest(some_ptr);
  EXPECT_EQ(true, result);

  AstPtr ast_ptr(new ila::Ast);
  result = ast_ptr->DummyTest(some_ptr);
  ASSERT_TRUE(result);

  delete some_ptr;
}

TEST(IlaUnitTest, IlaConstructor) {
  Ila ila_node;
  std::string some_name = "testing ila name";

  ila_node.SetName(some_name);
  std::string result = ila_node.GetName();

  ASSERT_TRUE("testing ila name" == result);
  ASSERT_EQ("testing ila name", result);
}

} // namespace ila

