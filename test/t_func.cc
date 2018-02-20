/// \file
/// Unit test for function declaration.

#include "ila/ast/func.h"
#include "ila/expr_fuse.h"
#include "unit-include/util.h"

namespace ila {

class TestFunc : public ::testing::Test {
public:
  TestFunc() {}
  ~TestFunc() {}
  void SetUp() {}
  void TearDown() {}

  Sort b = Sort::MakeBoolSort();
  Sort bv = Sort::MakeBvSort(8);
  Sort mem = Sort::MakeMemSort(8, 8);
}; // class TestFunc

TEST_F(TestFunc, Atom) {
  auto f = Func::New("func");
  EXPECT_EQ(b, f->out());
  EXPECT_EQ(0, f->arg_num());
  EXPECT_ANY_THROW(f->arg(0));
  EXPECT_TRUE(f->Check({}));

  auto f_bv = Func::New("func", bv);
  EXPECT_EQ(bv, f_bv->out());

  std::string msg = "";
  GET_STDOUT_MSG(std::cout << f, msg);
  EXPECT_EQ(msg, "Func.func");
}

TEST_F(TestFunc, Unary) {
  auto f = Func::New("func", b, bv);
  EXPECT_EQ(b, f->out());
  EXPECT_EQ(1, f->arg_num());
  EXPECT_EQ(bv, f->arg(0));
  EXPECT_ANY_THROW(f->arg(1));
  EXPECT_TRUE(f->Check({ExprFuse::NewBvVar("bv_var", 8)}));
  EXPECT_DEATH(f->Check({ExprFuse::NewBvVar("bv_var", 6)}), ".*");
  EXPECT_DEATH(f->Check({ExprFuse::NewBoolVar("bool_var")}), ".*");
}

TEST_F(TestFunc, Binary) {
  auto f = Func::New("func", bv, b, bv);
  EXPECT_EQ(bv, f->out());
  EXPECT_EQ(2, f->arg_num());
  EXPECT_EQ(b, f->arg(0));
  EXPECT_EQ(bv, f->arg(1));
  EXPECT_ANY_THROW(f->arg(2));
  auto b_var = ExprFuse::NewBoolVar("bool_var");
  auto bv_var = ExprFuse::NewBvVar("bv_var", 8);
  EXPECT_TRUE(f->Check({b_var, bv_var}));
  EXPECT_DEATH(f->Check({b_var}), ".*");
  EXPECT_DEATH(f->Check({b_var, b_var}), ".*");
}

} // namespace ila

