/// \file
/// Unit test for class Ast.

#include "ila/ast.h"
#include "test_util.h"

namespace ila {

TEST(AST, Construct) {
  Ast ast;
  AstPtr ast_ptr = std::make_shared<Ast>();
  Ast ast_copy = ast;

  EXPECT_EQ(ast.Name(), ast_copy.Name());
}

} // namespace ila

