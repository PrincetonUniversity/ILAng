/// \file
/// Unit test for class Ast.

#include "ila/ast.h"
#include "test_util.h"

namespace ila {

TEST(AST, Construct) {
  Ast ast;
  Ast ast_copy = ast;
  EXPECT_EQ(ast.Name(), ast_copy.Name());

  AstPtr arity_ptr = std::make_shared<Ast>(1);
  EXPECT_EQ(1, arity_ptr->Arity());

  AstPtr name_ptr = std::make_shared<Ast>("ast_name");
  EXPECT_EQ("ast_name", name_ptr->Name().Str());

  AstPtr all_ptr = std::make_shared<Ast>("2input", 2);
  EXPECT_EQ("2input", all_ptr->Name().Str());
  EXPECT_EQ(2, all_ptr->Arity());
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

