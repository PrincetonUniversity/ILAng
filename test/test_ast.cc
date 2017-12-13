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

TEST(AST, ObjType) {
  ObjPtr obj_ptr = std::make_shared<Ast>();
  AstPtr ast_ptr = std::make_shared<Ast>();

  EXPECT_TRUE(obj_ptr->IsAst());
  EXPECT_FALSE(obj_ptr->IsInstr());
  EXPECT_FALSE(obj_ptr->IsInstrLvlAbs());

  EXPECT_TRUE(ast_ptr->IsAst());
  EXPECT_FALSE(ast_ptr->IsInstr());
  EXPECT_FALSE(ast_ptr->IsInstrLvlAbs());
}

TEST(AST, AstType) {
  AstPtr ast_ptr = std::make_shared<Ast>();

  EXPECT_FALSE(ast_ptr->IsExpr());
  EXPECT_FALSE(ast_ptr->IsFunc());
}

} // namespace ila

