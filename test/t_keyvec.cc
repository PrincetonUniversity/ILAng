/// \file
/// Unit test for KeyVec

#include <string>

#include <ilang/ila/ast_hub.h>
#include <ilang/ila/symbol.h>
#include <ilang/util/container.h>

#include "unit-include/util.h"

namespace ilang {

TEST(TestKeyVec, StringString) {
  KeyVec<std::string, std::string> kv;

  EXPECT_EQ(0, kv.size());

  // k1 --> abc
  // k2 --> 123
  // k3 --> xyz
  kv.push_back("k1", "abc");
  kv.push_back("k2", "123");
  kv.push_back("k3", "xyz");

  EXPECT_FALSE(kv.push_back("k2", "#$%"));
  EXPECT_EQ(kv.find("k2")->second, "123");

  EXPECT_EQ(3, kv.size());

  EXPECT_EQ("abc", kv[0]);
  EXPECT_EQ("123", kv[1]);
  EXPECT_EQ("xyz", kv[2]);
  EXPECT_ANY_THROW(kv[3]);

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
  ExprPtr bv_var = asthub::NewBvVar("bv_var", 8);
  ExprPtr bool_const = asthub::BoolConst(true);
  ExprPtr mem_var = asthub::NewMemVar("mem_var", 8, 32);

  kv.push_back(bv_var->name(), bv_var);
  kv.push_back(bool_const->name(), bool_const);
  kv.push_back(mem_var->name(), mem_var);

  EXPECT_FALSE(kv.push_back(Symbol("bv_var"), bool_const));
  EXPECT_EQ(kv[0], bv_var);

  EXPECT_EQ(3, kv.size());

  EXPECT_EQ(bv_var, kv[0]);
  EXPECT_EQ(bool_const, kv[1]);
  EXPECT_EQ(mem_var, kv[2]);
  EXPECT_ANY_THROW(kv[3]);

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

} // namespace ilang
