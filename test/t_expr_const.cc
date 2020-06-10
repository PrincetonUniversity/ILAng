/// file
/// Unit test for ExprConst

#include "unit-include/util.h"
#include "z3++.h"
#include <ilang/ila/ast/expr_const.h>
#include <ilang/ila/ast/sort_value.h>

namespace ilang {

TEST(TestExprConst, Construct) {
  std::string blstr = "false";
  auto bool_const_str = std::make_shared<ExprConst>(BoolVal(blstr));
  auto bool_const = std::make_shared<ExprConst>(BoolVal(true));
  auto bv_const = std::make_shared<ExprConst>(BvVal(1), 8);

  MemValMap mem_map;
  for (int i = 0; i < 10; i++) {
    mem_map[i] = i + 1;
  }
  MemVal mem_val(1, mem_map);
  auto mem_const = std::make_shared<ExprConst>(8, 32);

  EXPECT_TRUE(bool_const->is_const());
  EXPECT_FALSE(bv_const->is_op());
  EXPECT_FALSE(mem_const->is_var());
}

TEST(TestExprConst, BoolZ3Expr) {
  z3::context ctx;
  Z3ExprVec arg_vec;
  z3::solver s(ctx);

  auto bool_const_true = std::make_shared<ExprConst>(BoolVal(true));
  auto bool_const_false = std::make_shared<ExprConst>(BoolVal("False"));
  auto e_true = bool_const_true->GetZ3Expr(ctx, arg_vec);
  auto e_false = bool_const_false->GetZ3Expr(ctx, arg_vec);
  auto bool_eq = (e_true == e_false);
  s.add(bool_eq);
  EXPECT_EQ(z3::unsat, s.check());
}

TEST(TestExprConst, BvZ3Expr) {
  z3::context ctx;
  Z3ExprVec arg_vec;
  z3::solver s(ctx);

  auto bv_const_0 = std::make_shared<ExprConst>(BvVal("0"), 8);
  auto bv_const_1 = std::make_shared<ExprConst>(BvVal(1), 8);
  auto e_0 = bv_const_0->GetZ3Expr(ctx, arg_vec);
  auto e_1 = bv_const_1->GetZ3Expr(ctx, arg_vec);
  auto bv_eq = ((e_0 + e_1) == e_1);
  s.add(!bv_eq);
  EXPECT_EQ(z3::unsat, s.check());
}

TEST(TestExprConst, MemZ3Expr) {
  z3::context ctx;
  Z3ExprVec arg_vec;
  z3::solver s(ctx);

  MemValMap mem_map;
  for (int i = 0; i < 10; i++) {
    mem_map[i] = i + 1;
  }
  MemVal mem_val(1, mem_map);
  auto mem_const_0 = std::make_shared<ExprConst>(mem_val, 8, 32);

  MemVal mem_val_copy(mem_val.def_val());
  for (int i = 0; i < 5; i++) {
    mem_val_copy.set_data(i, mem_val.get_data(i));
  }
  MemValMap mem_map_copy = mem_val.val_map();
  for (int i = 5; i < 10; i++) {
    mem_val_copy.set_data(i, mem_map_copy[i]);
  }
  auto mem_const_1 = std::make_shared<ExprConst>(mem_val_copy, 8, 32);

  auto e_mem_0 = mem_const_0->GetZ3Expr(ctx, arg_vec);
  auto e_mem_1 = mem_const_1->GetZ3Expr(ctx, arg_vec);
  auto mem_eq = (e_mem_0 == e_mem_1);
  s.add(!mem_eq);
  EXPECT_EQ(z3::unsat, s.check());
}

TEST(TestExprConst, BoolVal) {
  auto bool_const = std::make_shared<ExprConst>(BoolVal(true));
  auto bool_const_str = std::make_shared<ExprConst>(BoolVal("false"));

  auto bool_val = bool_const->val_bool();
#ifndef NDEBUG
  EXPECT_DEATH(bool_const->val_bv(), ".*");
  EXPECT_DEATH(bool_const->val_mem(), ".*");
#endif

  EXPECT_EQ(true, bool_val->val());

  std::string ref_str = "TRUE";
  std::string msg;

  EXPECT_EQ(ref_str, bool_val->str());

  GET_STDOUT_MSG(bool_val->Print(std::cout), msg);
  EXPECT_EQ(ref_str, msg);

  GET_STDOUT_MSG(std::cout << *bool_val, msg);
  EXPECT_EQ(ref_str, msg);
}

TEST(TestExprConst, BvVal) {
  auto bv_const = std::make_shared<ExprConst>(BvVal(1), 8);

  auto bv_val = bv_const->val_bv();
#ifndef NDEBUG
  EXPECT_DEATH(bv_const->val_bool(), ".*");
  EXPECT_DEATH(bv_const->val_mem(), ".*");
#endif

  EXPECT_EQ(1, bv_val->val());

  std::string ref_str = "1";
  std::string msg;

  EXPECT_EQ(ref_str, bv_val->str());

  GET_STDOUT_MSG(bv_val->Print(std::cout), msg);
  EXPECT_EQ(ref_str, msg);

  GET_STDOUT_MSG(std::cout << *bv_val, msg);
  EXPECT_EQ(ref_str, msg);
}

TEST(TestExprConst, MemVal) {
  int def = 1;
  MemVal val(def);
  for (int i = 0; i < 2; i++) {
    val.set_data(i, i * 2);
  }
  auto mem_const = std::make_shared<ExprConst>(val, 8, 32);

  auto mem_val = mem_const->val_mem();
#ifndef NDEBUG
  EXPECT_DEATH(mem_const->val_bool(), ".*");
  EXPECT_DEATH(mem_const->val_bv(), ".*");
#endif

  EXPECT_EQ(def, mem_val->def_val());
  MemValMap val_map = mem_val->val_map();
  EXPECT_EQ(0, val_map[0]);
  EXPECT_EQ(2, mem_val->get_data(1));
  EXPECT_EQ(def, mem_val->get_data(2));

  std::string ref_str = "[Def: 1][(0, 0)(1, 2)]";
  std::string msg;

  GET_STDOUT_MSG(mem_val->Print(std::cout), msg);
  EXPECT_EQ(ref_str, msg);

  GET_STDOUT_MSG(std::cout << *mem_val, msg);
  EXPECT_EQ(ref_str, msg);
}

#define BVCONST(v, w) std::make_shared<ExprConst>(BvVal(v), w)

TEST(TestExprConst, BvConstBitwidth) {
  EXPECT_DEATH(BVCONST(1, 0), ".*");
  EXPECT_DEATH(BVCONST(1, -1), ".*");
}

TEST(TestExprConst, BvConstNumeric) {
  SetToStdErr(1);

  // 8-bit
  EXPECT_EQ(BVCONST(0, 8)->val_bv()->val(), 0);
  EXPECT_EQ(BVCONST(1, 8)->val_bv()->val(), 1);
  EXPECT_DEATH(BVCONST(UINT32_MAX, 8), ".*");
  EXPECT_DEATH(BVCONST(UINT64_MAX, 8), ".*");
  EXPECT_DEATH(BVCONST(-1, 8), ".*");

  // 32-bit
  EXPECT_EQ(BVCONST(0, 32)->val_bv()->val(), 0);
  EXPECT_EQ(BVCONST(1, 32)->val_bv()->val(), 1);
  EXPECT_EQ(BVCONST(UINT32_MAX, 32)->val_bv()->val(), UINT32_MAX);
  EXPECT_DEATH(BVCONST(UINT64_MAX, 32), ".*");
  EXPECT_DEATH(BVCONST(-1, 32), ".*");

  // 64-bit
  EXPECT_EQ(BVCONST(0, 64)->val_bv()->val(), 0);
  EXPECT_EQ(BVCONST(1, 64)->val_bv()->val(), 1);
  EXPECT_EQ(BVCONST(UINT32_MAX, 64)->val_bv()->val(), UINT32_MAX);
  EXPECT_EQ(BVCONST(UINT64_MAX, 64)->val_bv()->val(), UINT64_MAX);
  EXPECT_EQ(BVCONST(-1, 64)->val_bv()->val(), UINT64_MAX);

  // 128-bit
  std::string msg;
  decltype(std::make_shared<ExprConst>(BoolVal(true))) bv_const = NULL;

  GET_STDERR_MSG(bv_const = BVCONST(0, 128), msg);
  EXPECT_EQ(bv_const->val_bv()->val(), 0);
#ifndef NDEBUG
  EXPECT_FALSE(msg.empty());
#endif

  GET_STDERR_MSG(bv_const = BVCONST(1, 128), msg);
  EXPECT_EQ(bv_const->val_bv()->val(), 1);
#ifndef NDEBUG
  EXPECT_FALSE(msg.empty());
#endif

  GET_STDERR_MSG(bv_const = BVCONST(UINT32_MAX, 128), msg);
  EXPECT_EQ(bv_const->val_bv()->val(), UINT32_MAX);
#ifndef NDEBUG
  EXPECT_FALSE(msg.empty());
#endif

  GET_STDERR_MSG(bv_const = BVCONST(UINT64_MAX, 128), msg);
  EXPECT_EQ(bv_const->val_bv()->val(), UINT64_MAX);
#ifndef NDEBUG
  EXPECT_FALSE(msg.empty());
#endif

  GET_STDERR_MSG(bv_const = BVCONST(-1, 128), msg);
  EXPECT_EQ(bv_const->val_bv()->val(), UINT64_MAX);
#ifndef NDEBUG
  EXPECT_FALSE(msg.empty());
#endif
}

} // namespace ilang
