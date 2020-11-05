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
  EXPECT_FALSE(bool_sort->is_struct());
  EXPECT_FALSE(bool_sort->is_vec());

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
  EXPECT_FALSE(s->is_struct());
  EXPECT_FALSE(s->is_vec());

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
  EXPECT_FALSE(s->is_struct());
  EXPECT_FALSE(s->is_vec());

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

TEST(TestSort, Struct) {
  auto s = Sort::MakeStructSort({
    {"a", Sort::MakeBoolSort()},
    {"b", Sort::MakeBvSort(8)},
    {"c", Sort::MakeMemSort(2, 4)}
  });
  EXPECT_TRUE(s->is_ast());
  EXPECT_FALSE(s->is_expr());
  EXPECT_FALSE(s->is_func());
  EXPECT_FALSE(s->is_bool());
  EXPECT_FALSE(s->is_bv());
  EXPECT_FALSE(s->is_mem());
  EXPECT_TRUE(s->is_struct());
  EXPECT_FALSE(s->is_vec());

#ifndef NDEBUG
  EXPECT_DEATH(s->bit_width(), ".*");
  EXPECT_DEATH(s->addr_width(), ".*");
  EXPECT_DEATH(s->data_width(), ".*");
#else
  EXPECT_EQ(0, s->bit_width());
  EXPECT_EQ(0, s->addr_width());
  EXPECT_EQ(0, s->data_width());
#endif
}

TEST(TestSort, Struct2) {
  auto s = Sort::MakeStructSort({
    {"a", Sort::MakeBoolSort()},
    {"b", Sort::MakeBvSort(8)},
    {"c", Sort::MakeMemSort(2, 4)}
  });

  // s2 is identical to s
  auto s2 = Sort::MakeStructSort({
    {"a", Sort::MakeBoolSort()},
    {"b", Sort::MakeBvSort(8)},
    {"c", Sort::MakeMemSort(2, 4)}
  });
  EXPECT_EQ(s, s2);

  // reorder shouldn't be the same
  EXPECT_NE(s, Sort::MakeStructSort({
    {"b", Sort::MakeBvSort(8)},
    {"a", Sort::MakeBoolSort()},
    {"c", Sort::MakeMemSort(2, 4)}
  }));

  EXPECT_NE(s, Sort::MakeStructSort({
    {"a", Sort::MakeBoolSort()},
    {"b", Sort::MakeBvSort(5)}, // different from s.b
    {"c", Sort::MakeMemSort(2, 4)}
  }));

  // nested structs
  auto t = Sort::cast_sort<SortStruct>(Sort::MakeStructSort({
    {"a", s2}, {"b", Sort::MakeBoolSort()}, {"c", s}}
  ));
  
  // test get_member_sort
  EXPECT_NE(s, t);
  EXPECT_EQ(s, t->get_member_sort("a"));
  EXPECT_NE(s, t->get_member_sort("b"));
  EXPECT_EQ(t->get_member_sort("b"), Sort::MakeBoolSort());
  EXPECT_EQ(s, t->get_member_sort("c"));
#ifndef NDEBUG
  EXPECT_DEATH(t->get_member_sort("d"), ".*");
#else
  EXPECT_FALSE(t->get_member_sort("d"));
#endif

  // casting
  auto ss = Sort::cast_sort<SortStruct>(s);

  // printing
  std::string msg, a_sort, b_sort, c_sort;
  GET_STDOUT_MSG(std::cout << s, msg);
  GET_STDOUT_MSG(std::cout << ss->get_member_sort("a"), a_sort);
  GET_STDOUT_MSG(std::cout << ss->get_member_sort("b"), b_sort);
  GET_STDOUT_MSG(std::cout << ss->get_member_sort("c"), c_sort);
  EXPECT_EQ("{ a: " + a_sort + ", b: " + b_sort 
            + ", c: " + c_sort + " }", msg);
  
  // z3 sort should be constant, at least for the same pointer.
  z3::context c {};
  EXPECT_EQ(s->GetZ3Sort(c).name(), s->GetZ3Sort(c).name());

  // TODO: consider making the following test pass (though it 
  // doesn't really matter, since both sorts are uninterpreted).

  // EXPECT_EQ(s->GetZ3Sort(c).name(), s2->GetZ3Sort(c).name());
}

TEST(TestSort, Vector) {
  auto s = Sort::MakeVectorSort(Sort::MakeBoolSort(), 12);
  EXPECT_TRUE(s->is_ast());
  EXPECT_FALSE(s->is_expr());
  EXPECT_FALSE(s->is_func());
  EXPECT_FALSE(s->is_bool());
  EXPECT_FALSE(s->is_bv());
  EXPECT_FALSE(s->is_mem());
  EXPECT_FALSE(s->is_struct());
  EXPECT_TRUE(s->is_vec());

#ifndef NDEBUG
  EXPECT_DEATH(s->bit_width(), ".*");
  EXPECT_DEATH(s->addr_width(), ".*");
  EXPECT_DEATH(s->data_width(), ".*");
#else
  EXPECT_EQ(0, s->bit_width());
  EXPECT_EQ(0, s->addr_width());
  EXPECT_EQ(0, s->data_width());
#endif

  EXPECT_EQ(s, Sort::MakeVectorSort(Sort::MakeBoolSort(), 12));
  EXPECT_NE(s, Sort::MakeVectorSort(Sort::MakeBoolSort(), 5));
}

TEST(TestSort, Vector2) {
  auto s = Sort::MakeVectorSort(Sort::MakeBoolSort(), 12);

  auto sv = Sort::cast_sort<SortVector>(s);
  EXPECT_EQ(sv->data_atom(), Sort::MakeBoolSort());
  EXPECT_EQ(sv->vec_size(), 12);

  // printing
  std::string msg, da_sort;
  GET_STDOUT_MSG(std::cout << s, msg);
  GET_STDOUT_MSG(std::cout << sv->data_atom(), da_sort);
  EXPECT_EQ("Array[12](" + da_sort + ")", msg);

  // z3 sort should be constant, at least for the same pointer.
  z3::context c {};
  EXPECT_EQ(s->GetZ3Sort(c).name(), s->GetZ3Sort(c).name());

  // Note that z3 sort is not the same for an identical sort:

  // EXPECT_EQ(s->GetZ3Sort(c).name(), 
  //   (Sort::MakeVectorSort(Sort::MakeBoolSort(), 12))->GetZ3Sort(c).name());

  // test vectors of structs containing vectors
  auto da = Sort::MakeStructSort({
    {"a", Sort::MakeBoolSort()},
    {"b", s}
  });
  auto t1 = Sort::MakeVectorSort(da, 10);
  auto t2 = Sort::MakeVectorSort(da, 10);
  EXPECT_EQ(t1, t2);
  
  auto t1_da = Sort::cast_sort<SortVector>(t1)->data_atom();
  auto s3 = Sort::cast_sort<SortStruct>(t1_da)->get_member_sort("b");
  EXPECT_EQ(s, s3);
}

} // namespace ilang
