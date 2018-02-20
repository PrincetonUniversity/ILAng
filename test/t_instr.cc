/// \file
/// Unit test for class Instr.

#include "ila/expr_fuse.h"
#include "ila/instr.h"
#include "unit-include/util.h"

namespace ila {

class TestInstr : public ::testing::Test {
public:
  TestInstr() { mngr = std::make_shared<ExprMngr>(); }

  ~TestInstr() {}

  void SetUp() { mngr->clear(); }

  void TearDown() {}

  ExprMngrPtr mngr;

}; // class TestInstr

TEST_F(TestInstr, Construct) {
  InstrPtr sptr = std::make_shared<Instr>("simplify_instr");

  EXPECT_TRUE(sptr->is_instr());
  EXPECT_FALSE(sptr->is_instr_lvl_abs());
  EXPECT_FALSE(sptr->is_ast());

  EXPECT_FALSE(sptr->has_view());

  InstrPtr eptr = std::make_shared<Instr>("raw_instr");

  EXPECT_TRUE(eptr->is_instr());
  EXPECT_FALSE(eptr->is_instr_lvl_abs());
  EXPECT_FALSE(eptr->is_ast());

  EXPECT_FALSE(eptr->has_view());

#if 0
  InstrPtr nptr = std::make_shared<Instr>();

  EXPECT_TRUE(nptr->is_instr());
  EXPECT_FALSE(nptr->is_instr_lvl_abs());
  EXPECT_FALSE(nptr->is_ast());

  EXPECT_FALSE(nptr->has_view());

  InstrPtr hptr = Instr::New();

  EXPECT_TRUE(hptr->is_instr());
  EXPECT_FALSE(hptr->is_instr_lvl_abs());
  EXPECT_FALSE(hptr->is_ast());

  EXPECT_FALSE(hptr->has_view());
#endif
}

TEST_F(TestInstr, View) {
  InstrPtr ptr = std::make_shared<Instr>("dummy");

  EXPECT_FALSE(ptr->has_view());
  ptr->set_view(true);
  EXPECT_TRUE(ptr->has_view());
}

TEST_F(TestInstr, DecodeSimplified) {
  InstrPtr ptr = std::make_shared<Instr>("dummy");

// set with NULL (forbiddened)
#ifndef NDEBUG
  EXPECT_DEATH(ptr->SetDecode(NULL), ".*");
  EXPECT_DEATH(ptr->ForceSetDecode(NULL), ".*");
#endif

  // set with bitvector update function (forbiddened)
  ExprPtr bv_expr = ExprFuse::BvConst(0, 8);
#ifndef NDEBUG
  EXPECT_DEATH(ptr->SetDecode(bv_expr), ".*");
  EXPECT_DEATH(ptr->ForceSetDecode(bv_expr), ".*");
#endif

  // set with bool update function
  ExprPtr bool_expr = ExprFuse::BoolConst(true);
  ptr->SetDecode(bool_expr);
  EXPECT_EQ(bool_expr, ptr->GetDecode());

  // try to overwrite
  ExprPtr new_bool_expr = ExprFuse::BoolConst(false);
  std::string msg;
#ifndef NDEBUG
  GET_STDERR_MSG(ptr->SetDecode(new_bool_expr), msg);
  EXPECT_FALSE(msg.empty());
#endif
  EXPECT_EQ(bool_expr, ptr->GetDecode());
  EXPECT_NE(new_bool_expr, ptr->GetDecode());

  // force overwrite
  GET_STDERR_MSG(ptr->ForceSetDecode(new_bool_expr), msg);
  EXPECT_TRUE(msg.empty());
  EXPECT_EQ(new_bool_expr, ptr->GetDecode());
  EXPECT_NE(bool_expr, ptr->GetDecode());
}

TEST_F(TestInstr, DecodeNonSimplified) {
  InstrPtr ptr = std::make_shared<Instr>("dummy");

// set with NULL (forbiddened)
#ifndef NDEBUG
  EXPECT_DEATH(ptr->SetDecode(NULL), ".*");
  EXPECT_DEATH(ptr->ForceSetDecode(NULL), ".*");
#endif

  // set with bitvector update function (forbiddened)
  ExprPtr bv_expr = ExprFuse::BvConst(0, 8);
#ifndef NDEBUG
  EXPECT_DEATH(ptr->SetDecode(bv_expr), ".*");
  EXPECT_DEATH(ptr->ForceSetDecode(bv_expr), ".*");
#endif

  // set with bool update function
  ExprPtr bool_expr = ExprFuse::BoolConst(true);
  ptr->SetDecode(bool_expr);
  EXPECT_EQ(bool_expr, ptr->GetDecode());

  // try to overwrite
  ExprPtr new_bool_expr = ExprFuse::BoolConst(false);
  std::string msg;
#ifndef NDEBUG
  GET_STDERR_MSG(ptr->SetDecode(new_bool_expr), msg);
  EXPECT_FALSE(msg.empty());
#endif
  EXPECT_EQ(bool_expr, ptr->GetDecode());
  EXPECT_NE(new_bool_expr, ptr->GetDecode());

  // force overwrite
  GET_STDERR_MSG(ptr->ForceSetDecode(new_bool_expr), msg);
  EXPECT_TRUE(msg.empty());
  EXPECT_EQ(new_bool_expr, ptr->GetDecode());
  EXPECT_NE(bool_expr, ptr->GetDecode());
}

TEST_F(TestInstr, UpdateSimplified) {
  InstrPtr ptr = std::make_shared<Instr>("dummy");

  ExprPtr bv_var = ExprFuse::NewBvVar("bv_var", 8);
  ExprPtr bool_var = ExprFuse::NewBoolVar("bool_var");

  // add by name
  ExprPtr bv_update = ExprFuse::BvConst(0, 8);
  ptr->AddUpdate("bv_var", bv_update);
  // get by name
  EXPECT_EQ(bv_update, ptr->GetUpdate("bv_var"));
  // get by node
  EXPECT_EQ(bv_update, ptr->GetUpdate(bv_var));

  // add with node
  ExprPtr bool_update = ExprFuse::BoolConst(true);
  ptr->AddUpdate(bool_var, bool_update);
  // get by name
  EXPECT_EQ(bool_update, ptr->GetUpdate("bool_var"));
  // get by node
  EXPECT_EQ(bool_update, ptr->GetUpdate(bool_var));

  // try to overwrite (with var)
  std::string msg;
  ExprPtr new_bv_update = ExprFuse::NewBvVar("non-det-bv", 8);
#ifndef NDEBUG
  GET_STDERR_MSG(ptr->AddUpdate(bv_var, new_bv_update), msg);
  EXPECT_FALSE(msg.empty());
#endif
  EXPECT_NE(new_bv_update, ptr->GetUpdate(bv_var));
  EXPECT_EQ(bv_update, ptr->GetUpdate(bv_var));

  // force overwrite
  GET_STDERR_MSG(ptr->ForceAddUpdate("bv_var", new_bv_update), msg);
  EXPECT_TRUE(msg.empty());
  EXPECT_EQ(new_bv_update, ptr->GetUpdate("bv_var"));
  EXPECT_NE(bv_update, ptr->GetUpdate("bv_var"));
}

TEST_F(TestInstr, UpdateNonSimplified) {
  InstrPtr ptr = std::make_shared<Instr>("dummy");

  ExprPtr bv_var = ExprFuse::NewBvVar("bv_var", 8);
  ExprPtr bool_var = ExprFuse::NewBoolVar("bool_var");

  // add by name
  ExprPtr bv_update = ExprFuse::BvConst(0, 8);
  ptr->AddUpdate("bv_var", bv_update);
  // get by name
  EXPECT_EQ(bv_update, ptr->GetUpdate("bv_var"));
  // get by node
  EXPECT_EQ(bv_update, ptr->GetUpdate(bv_var));

  // add with node
  ExprPtr bool_update = ExprFuse::BoolConst(true);
  ptr->AddUpdate(bool_var, bool_update);
  // get by name
  EXPECT_EQ(bool_update, ptr->GetUpdate("bool_var"));
  // get by node
  EXPECT_EQ(bool_update, ptr->GetUpdate(bool_var));

  // try to overwrite (with var)
  std::string msg;
  ExprPtr new_bv_update = ExprFuse::NewBvVar("non-det-bv", 8);
#ifndef NDEBUG
  GET_STDERR_MSG(ptr->AddUpdate(bv_var, new_bv_update), msg);
  EXPECT_FALSE(msg.empty());
#endif
  EXPECT_NE(new_bv_update, ptr->GetUpdate(bv_var));
  EXPECT_EQ(bv_update, ptr->GetUpdate(bv_var));

  // force overwrite
  GET_STDERR_MSG(ptr->ForceAddUpdate("bv_var", new_bv_update), msg);
  EXPECT_TRUE(msg.empty());
  EXPECT_EQ(new_bv_update, ptr->GetUpdate("bv_var"));
  EXPECT_NE(bv_update, ptr->GetUpdate("bv_var"));
}

TEST_F(TestInstr, Print) {
  InstrPtr ptr = std::make_shared<Instr>("dummy");
  std::string msg;

  GET_STDOUT_MSG(ptr->Print(std::cout), msg);
  EXPECT_EQ("Instr.dummy", msg);
}

} // namespace ila

