/// \file
/// Unit test for class Instr.

#include <ilang/ila/ast_hub.h>
#include <ilang/ila/instr.h>

#include "unit-include/util.h"

namespace ilang {

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

  InstrPtr eptr = std::make_shared<Instr>("raw_instr");

  EXPECT_TRUE(eptr->is_instr());
  EXPECT_FALSE(eptr->is_instr_lvl_abs());
  EXPECT_FALSE(eptr->is_ast());
}

TEST_F(TestInstr, DecodeSimplified) {
  InstrPtr ptr = std::make_shared<Instr>("dummy");

// set with NULL (forbiddened)
#ifndef NDEBUG
  EXPECT_DEATH(ptr->set_decode(NULL), ".*");
  EXPECT_DEATH(ptr->ForceSetDecode(NULL), ".*");
#endif

  // set with bitvector update function (forbiddened)
  ExprPtr bv_expr = asthub::BvConst(0, 8);
#ifndef NDEBUG
  EXPECT_DEATH(ptr->set_decode(bv_expr), ".*");
  EXPECT_DEATH(ptr->ForceSetDecode(bv_expr), ".*");
#endif

  // set with bool update function
  ExprPtr bool_expr = asthub::BoolConst(true);
  ptr->set_decode(bool_expr);
  EXPECT_EQ(bool_expr, ptr->decode());

  // try to overwrite
  ExprPtr new_bool_expr = asthub::BoolConst(false);
  std::string msg;
#ifndef NDEBUG
  GET_STDERR_MSG(ptr->set_decode(new_bool_expr), msg);
  EXPECT_FALSE(msg.empty());
#endif
  EXPECT_EQ(bool_expr, ptr->decode());
  EXPECT_NE(new_bool_expr, ptr->decode());

  // force overwrite
  GET_STDERR_MSG(ptr->ForceSetDecode(new_bool_expr), msg);
  EXPECT_TRUE(msg.empty());
  EXPECT_EQ(new_bool_expr, ptr->decode());
  EXPECT_NE(bool_expr, ptr->decode());
}

TEST_F(TestInstr, DecodeNonSimplified) {
  InstrPtr ptr = std::make_shared<Instr>("dummy");

// set with NULL (forbiddened)
#ifndef NDEBUG
  EXPECT_DEATH(ptr->set_decode(NULL), ".*");
  EXPECT_DEATH(ptr->ForceSetDecode(NULL), ".*");
#endif

  // set with bitvector update function (forbiddened)
  ExprPtr bv_expr = asthub::BvConst(0, 8);
#ifndef NDEBUG
  EXPECT_DEATH(ptr->set_decode(bv_expr), ".*");
  EXPECT_DEATH(ptr->ForceSetDecode(bv_expr), ".*");
#endif

  // set with bool update function
  ExprPtr bool_expr = asthub::BoolConst(true);
  ptr->set_decode(bool_expr);
  EXPECT_EQ(bool_expr, ptr->decode());

  // try to overwrite
  ExprPtr new_bool_expr = asthub::BoolConst(false);
  std::string msg;
#ifndef NDEBUG
  GET_STDERR_MSG(ptr->set_decode(new_bool_expr), msg);
  EXPECT_FALSE(msg.empty());
#endif
  EXPECT_EQ(bool_expr, ptr->decode());
  EXPECT_NE(new_bool_expr, ptr->decode());

  // force overwrite
  GET_STDERR_MSG(ptr->ForceSetDecode(new_bool_expr), msg);
  EXPECT_TRUE(msg.empty());
  EXPECT_EQ(new_bool_expr, ptr->decode());
  EXPECT_NE(bool_expr, ptr->decode());
}

TEST_F(TestInstr, UpdateSimplified) {
  InstrPtr ptr = std::make_shared<Instr>("dummy");

  ExprPtr bv_var = asthub::NewBvVar("bv_var", 8);
  ExprPtr bool_var = asthub::NewBoolVar("bool_var");

  // add by name
  ExprPtr bv_update = asthub::BvConst(0, 8);
  ptr->set_update("bv_var", bv_update);
  // get by name
  EXPECT_EQ(bv_update, ptr->update("bv_var"));
  // get by node
  EXPECT_EQ(bv_update, ptr->update(bv_var));

  // add with node
  ExprPtr bool_update = asthub::BoolConst(true);
  ptr->set_update(bool_var, bool_update);
  // get by name
  EXPECT_EQ(bool_update, ptr->update("bool_var"));
  // get by node
  EXPECT_EQ(bool_update, ptr->update(bool_var));

  // try to overwrite (with var)
  std::string msg;
  ExprPtr new_bv_update = asthub::NewBvVar("non-det-bv", 8);
#ifndef NDEBUG
  GET_STDERR_MSG(ptr->set_update(bv_var, new_bv_update), msg);
  EXPECT_FALSE(msg.empty());
#endif
  EXPECT_NE(new_bv_update, ptr->update(bv_var));
  EXPECT_EQ(bv_update, ptr->update(bv_var));

  // force overwrite
  GET_STDERR_MSG(ptr->ForceAddUpdate("bv_var", new_bv_update), msg);
  EXPECT_TRUE(msg.empty());
  EXPECT_EQ(new_bv_update, ptr->update("bv_var"));
  EXPECT_NE(bv_update, ptr->update("bv_var"));
}

TEST_F(TestInstr, UpdateNonSimplified) {
  InstrPtr ptr = std::make_shared<Instr>("dummy");

  ExprPtr bv_var = asthub::NewBvVar("bv_var", 8);
  ExprPtr bool_var = asthub::NewBoolVar("bool_var");

  // add by name
  ExprPtr bv_update = asthub::BvConst(0, 8);
  ptr->set_update("bv_var", bv_update);
  // get by name
  EXPECT_EQ(bv_update, ptr->update("bv_var"));
  // get by node
  EXPECT_EQ(bv_update, ptr->update(bv_var));

  // add with node
  ExprPtr bool_update = asthub::BoolConst(true);
  ptr->set_update(bool_var, bool_update);
  // get by name
  EXPECT_EQ(bool_update, ptr->update("bool_var"));
  // get by node
  EXPECT_EQ(bool_update, ptr->update(bool_var));

  // try to overwrite (with var)
  std::string msg;
  ExprPtr new_bv_update = asthub::NewBvVar("non-det-bv", 8);
#ifndef NDEBUG
  GET_STDERR_MSG(ptr->set_update(bv_var, new_bv_update), msg);
  EXPECT_FALSE(msg.empty());
#endif
  EXPECT_NE(new_bv_update, ptr->update(bv_var));
  EXPECT_EQ(bv_update, ptr->update(bv_var));

  // force overwrite
  GET_STDERR_MSG(ptr->ForceAddUpdate("bv_var", new_bv_update), msg);
  EXPECT_TRUE(msg.empty());
  EXPECT_EQ(new_bv_update, ptr->update("bv_var"));
  EXPECT_NE(bv_update, ptr->update("bv_var"));
}

TEST_F(TestInstr, Print) {
  InstrPtr ptr = std::make_shared<Instr>("dummy");
  std::string msg;

  GET_STDOUT_MSG(ptr->Print(std::cout), msg);
  EXPECT_EQ("Instr.dummy", msg);
}

} // namespace ilang
