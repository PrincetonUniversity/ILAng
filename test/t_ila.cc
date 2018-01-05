/// \file
/// Unit test for class InstrLvlAbs.

#include "ila/instr_lvl_abs.h"
#include "util_test.h"

namespace ila {

TEST(TestInstrLvlAbs, Construct) {
  InstrLvlAbs ila_dummy;
  InstrLvlAbs ila_obj("ila_obj");
  auto ptr = InstrLvlAbs::NewILA("ila_ptr");

  EXPECT_TRUE(ila_dummy.is_instr_lvl_abs());
  EXPECT_FALSE(ila_dummy.is_instr());
  EXPECT_FALSE(ila_dummy.is_ast());

  EXPECT_TRUE(ila_obj.is_instr_lvl_abs());
  EXPECT_EQ(Symbol("ila_obj"), ila_obj.name());

  EXPECT_TRUE(ptr->is_instr_lvl_abs());
  EXPECT_EQ(Symbol("ila_ptr"), ptr->name());
}

TEST(TestInstrLvlAbs, Spec) {
  auto ila = InstrLvlAbs::NewILA("ila");

  EXPECT_TRUE(ila->is_spec());

  ila->set_spec(false);
  EXPECT_FALSE(ila->is_spec());
}

TEST(TestInstrLvlAbs, Simplifier) {
  auto ila = InstrLvlAbs::NewILA("ila");

  EXPECT_TRUE(ila->to_simplify());
  ila->set_simplify(false);
  EXPECT_FALSE(ila->to_simplify());

  ExprMngrPtr new_mngr = std::make_shared<ExprMngr>();
  EXPECT_NE(new_mngr.get(), ila->expr_mngr().get());
  ila->set_expr_mngr(new_mngr);
  EXPECT_EQ(new_mngr.get(), ila->expr_mngr().get());
}

TEST(TestInstrLvlAbs, Input) {
  auto ila = InstrLvlAbs::NewILA("ila");

  // Add
  ExprPtr bool_input = ExprFuse::NewBoolVar("bool_input");
  ila->AddInput(bool_input);

  ExprPtr bool_const = ExprFuse::BoolConst(true);
  EXPECT_DEATH(ila->AddInput(bool_const), ".*");

  EXPECT_DEATH(ila->AddInput(NULL), ".*");

  ExprPtr new_bool_input = ExprFuse::NewBoolVar("bool_input");
  EXPECT_DEATH(ila->AddInput(new_bool_input), ".*");

  // New
  ExprPtr bool_in_emb = ila->NewBoolInput("bool_in_emb");
  ExprPtr bv_in_emb = ila->NewBvInput("bv_in_emb", 8);
  EXPECT_DEATH(ila->NewBoolInput("bool_in_emb"), ".*");
  EXPECT_DEATH(ila->NewBvInput("bv_in_emb", 8), ".*");

  // Get
  ExprPtr get_bool_input = ila->GetInput("bool_input");
  EXPECT_EQ(bool_input, get_bool_input);

  ExprPtr get_fail = ila->GetInput("non-exist");
  EXPECT_TRUE(get_fail == NULL);
}

TEST(TestInstrLvlAbs, State) {
  // TODO
}

TEST(TestInstrLvlAbs, Init) {
  // TODO
}

TEST(TestInstrLvlAbs, Fetch) {
  // TODO
}

TEST(TestInstrLvlAbs, Valid) {
  // TODO
}

TEST(TestInstrLvlAbs, Instr) {
  // TODO
}

TEST(TestInstrLvlAbs, Child) {
  // TODO
}

TEST(TestInstrLvlAbs, CheckAll) {
  // TODO
}

TEST(TestInstrLvlAbs, SimplifyAll) {
  // TODO
}

TEST(TestInstrLvlAbs, MergeAll) {
  // TODO
}

TEST(TestInstrLvlAbs, Print) {
  // TODO
}

} // namespace ila

