/// \file
/// Unit test for Sort.

#include "unit-include/util.h"
#include <ilang/ila/ast/sort.h>
#include <iostream>
#include <string>

namespace ilang {

TEST(TestSort, Boolean) {
  auto bool_sort = Sort::MakeBoolSort();
  // Sort bool_sort;
  EXPECT_TRUE(bool_sort->is_bool());
  EXPECT_FALSE(bool_sort->is_bv());
  EXPECT_FALSE(bool_sort->is_mem());

#ifndef NDEBUG
  EXPECT_DEATH(bool_sort->bit_width(), ".*");
  EXPECT_DEATH(bool_sort->addr_width(), ".*");
  EXPECT_DEATH(bool_sort->data_width(), ".*");
#else
  EXPECT_EQ(0, bool_sort->bit_width());
  EXPECT_EQ(0, bool_sort->addr_width());
  EXPECT_EQ(0, bool_sort->data_width());
#endif

  std::string msg;
  GET_STDOUT_MSG(std::cout << bool_sort, msg);
  EXPECT_EQ("Boolean", msg);

  auto wrap = Sort::MakeBoolSort();
  EXPECT_EQ(wrap, bool_sort);

  z3::context c;
  auto z = bool_sort->GetZ3Sort(c);
  EXPECT_TRUE(z.is_bool());
}

TEST(TestSort, Bitvector) {
  auto s = Sort::MakeBvSort(8);
  EXPECT_FALSE(s->is_bool());
  EXPECT_TRUE(s->is_bv());
  EXPECT_FALSE(s->is_mem());

  EXPECT_EQ(8, s->bit_width());
#ifndef NDEBUG
  EXPECT_DEATH(s->addr_width(), ".*");
  EXPECT_DEATH(s->data_width(), ".*");
#else
  EXPECT_EQ(0, s->addr_width());
  EXPECT_EQ(0, s->data_width());
#endif

  std::string msg;
  GET_STDOUT_MSG(std::cout << s, msg);
  EXPECT_EQ("Bv(8)", msg);

  auto s2 = Sort::MakeBvSort(8);
  EXPECT_EQ(s, s2);

  z3::context c;
  auto z = s->GetZ3Sort(c);
  EXPECT_TRUE(z.is_bv());
}

TEST(TestSort, Memory) {
  auto s = Sort::MakeMemSort(2, 32);
  EXPECT_TRUE(s->is_ast());
  EXPECT_FALSE(s->is_expr());
  EXPECT_FALSE(s->is_func());
  EXPECT_FALSE(s->is_bool());
  EXPECT_FALSE(s->is_bv());
  EXPECT_TRUE(s->is_mem());

#ifndef NDEBUG
  EXPECT_DEATH(s->bit_width(), ".*");
#else
  EXPECT_EQ(0, s->bit_width());
#endif
  EXPECT_EQ(2, s->addr_width());
  EXPECT_EQ(32, s->data_width());

  std::string msg;
  GET_STDOUT_MSG(std::cout << s, msg);
  EXPECT_EQ("Mem(2, 32)", msg);

  auto s2 = Sort::MakeMemSort(2, 32);
  EXPECT_EQ(s, s2);

  z3::context c;
  auto z = s->GetZ3Sort(c);
  EXPECT_TRUE(z.is_array());
}

} // namespace ilang
