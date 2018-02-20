/// \file
/// Unit test for Sort.

#include "ila/ast/sort.h"
#include "unit-include/util.h"
#include <iostream>
#include <string>

namespace ila {

TEST(TestSort, Boolean) {
  Sort bool_sort;
  EXPECT_TRUE(bool_sort.is_ast());
  EXPECT_TRUE(bool_sort.is_sort());
  EXPECT_FALSE(bool_sort.is_expr());
  EXPECT_FALSE(bool_sort.is_func());
  EXPECT_TRUE(bool_sort.is_bool());

  EXPECT_EQ(0, bool_sort.bit_width());
  EXPECT_EQ(0, bool_sort.addr_width());
  EXPECT_EQ(0, bool_sort.data_width());

  std::string msg;
  GET_STDOUT_MSG(std::cout << bool_sort, msg);
  EXPECT_EQ("Boolean", msg);

  Sort wrap = Sort::MakeBoolSort();
  EXPECT_EQ(wrap, bool_sort);
}

TEST(TestSort, Bitvector) {
  Sort bv_sort(8);
  EXPECT_TRUE(bv_sort.is_ast());
  EXPECT_TRUE(bv_sort.is_sort());
  EXPECT_FALSE(bv_sort.is_expr());
  EXPECT_FALSE(bv_sort.is_func());
  EXPECT_TRUE(bv_sort.is_bv());

  EXPECT_EQ(8, bv_sort.bit_width());
  EXPECT_EQ(0, bv_sort.addr_width());
  EXPECT_EQ(0, bv_sort.data_width());

  std::string msg;
  GET_STDOUT_MSG(std::cout << bv_sort, msg);
  EXPECT_EQ("Bv(8)", msg);

  Sort wrap = Sort::MakeBvSort(8);
  EXPECT_EQ(wrap, bv_sort);
}

TEST(TestSort, Memory) {
  Sort mem_sort(2, 32);
  EXPECT_TRUE(mem_sort.is_ast());
  EXPECT_TRUE(mem_sort.is_mem());

  EXPECT_EQ(0, mem_sort.bit_width());
  EXPECT_EQ(2, mem_sort.addr_width());
  EXPECT_EQ(32, mem_sort.data_width());

  std::string msg;
  GET_STDOUT_MSG(std::cout << mem_sort, msg);
  EXPECT_EQ("Mem(2, 32)", msg);

  Sort wrap = Sort::MakeMemSort(2, 32);
  EXPECT_EQ(wrap, mem_sort);
}

} // namespace ila

