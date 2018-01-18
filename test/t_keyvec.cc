/// \file
/// Unit test for KeyVec

#include "ila/expr_fuse.h"
#include "ila/symbol.h"
#include "unit-include/util.h"
#include "util/container.h"
#include <string>

namespace ila {

TEST(TestKeyVec, StringString) {
  KeyVec<std::string, std::string> kv;

  EXPECT_EQ(0, kv.size());

  // k1 --> abc
  // k2 --> 123
  // k3 --> xyz
  kv.push_back("k1", "abc");
  kv.push_back("k2", "123");
  kv.push_back("k3", "xyz");

#ifndef NDEBUG
  EXPECT_DEATH(kv.push_back("k2", "#$%"), ".*");
#endif

  EXPECT_EQ(3, kv.size());

  EXPECT_EQ("abc", kv[0]);
  EXPECT_EQ("123", kv[1]);
  EXPECT_EQ("xyz", kv[2]);
#ifndef NDEBUG
  EXPECT_DEATH(kv[3], ".*");
#endif

  auto pos = kv.find("k1");
  EXPECT_NE(pos, kv.end());
  EXPECT_EQ("k1", pos->first);
  EXPECT_EQ("abc", pos->second);

  pos = kv.find("k4");
  EXPECT_EQ(pos, kv.end());

  kv.clear();
  pos = kv.find("k2");
  EXPECT_EQ(pos, kv.end());
}

TEST(TestKeyVec, SymbolExpr) {
  KeyVec<Symbol, ExprPtr> kv;
  EXPECT_EQ(0, kv.size());

  // bv --> bv_var
  // bool --> bool_const
  // mem --> mem_var
  ExprPtr bv_var = ExprFuse::NewBvVar("bv_var", 8);
  ExprPtr bool_const = ExprFuse::BoolConst(true);
  ExprPtr mem_var = ExprFuse::NewMemVar("mem_var", 8, 32);

  kv.push_back(bv_var->name(), bv_var);
  kv.push_back(bool_const->name(), bool_const);
  kv.push_back(mem_var->name(), mem_var);

#ifndef NDEBUG
  EXPECT_DEATH(kv.push_back(Symbol("bv_var"), bool_const), ".*");
#endif

  EXPECT_EQ(3, kv.size());

  EXPECT_EQ(bv_var, kv[0]);
  EXPECT_EQ(bool_const, kv[1]);
  EXPECT_EQ(mem_var, kv[2]);
#ifndef NDEBUG
  EXPECT_DEATH(kv[3], ".*");
#endif

  auto pos = kv.find(bv_var->name());
  EXPECT_NE(pos, kv.end());
  EXPECT_EQ(bv_var->name(), pos->first);
  EXPECT_EQ(bv_var, pos->second);

  pos = kv.find(Symbol("dummy"));
  EXPECT_EQ(pos, kv.end());

  kv.clear();
  pos = kv.find(bool_const->name());
  EXPECT_EQ(pos, kv.end());
}

} // namespace ila

