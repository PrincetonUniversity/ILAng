/// \file
/// Unit test for function declaration.

#include <ilang/ila/ast/func.h>
#include <ilang/ila/ast_hub.h>

#include "unit-include/util.h"

namespace ilang {

class TestFunc : public ::testing::Test {
public:
  TestFunc() {}
  ~TestFunc() {}
  void SetUp() {}
  void TearDown() {}

  SortPtr b = Sort::MakeBoolSort();
  SortPtr bv = Sort::MakeBvSort(8);
  SortPtr mem = Sort::MakeMemSort(8, 8);
}; // class TestFunc

TEST_F(TestFunc, Atom) {
  auto f = Func::New("func");
  EXPECT_EQ(b, f->out());
  EXPECT_EQ(0, f->arg_num());
  EXPECT_ANY_THROW(f->arg(0));
  EXPECT_TRUE(f->CheckSort({}));

  auto f_bv = Func::New("func", bv);
  EXPECT_EQ(bv, f_bv->out());

  std::string msg = "";
  GET_STDOUT_MSG(std::cout << f, msg);
  EXPECT_EQ(msg, "Func.func");

  z3::context c;
  auto f_decl = f->GetZ3FuncDecl(c);
}

TEST_F(TestFunc, Unary) {
  auto f = Func::New("func", b, bv);
  EXPECT_EQ(b, f->out());
  EXPECT_EQ(1, f->arg_num());
  EXPECT_EQ(bv, f->arg(0));
  EXPECT_ANY_THROW(f->arg(1));
  EXPECT_TRUE(f->CheckSort({asthub::NewBvVar("bv_var", 8)}));
  EXPECT_DEATH(f->CheckSort({asthub::NewBvVar("bv_var", 6)}), ".*");
  EXPECT_DEATH(f->CheckSort({asthub::NewBoolVar("bool_var")}), ".*");

  z3::context c;
  auto f_decl = f->GetZ3FuncDecl(c);
}

TEST_F(TestFunc, Binary) {
  auto f = Func::New("func", bv, b, bv);
  EXPECT_EQ(bv, f->out());
  EXPECT_EQ(2, f->arg_num());
  EXPECT_EQ(b, f->arg(0));
  EXPECT_EQ(bv, f->arg(1));
  EXPECT_ANY_THROW(f->arg(2));
  auto b_var = asthub::NewBoolVar("bool_var");
  auto bv_var = asthub::NewBvVar("bv_var", 8);
  EXPECT_TRUE(f->CheckSort({b_var, bv_var}));
  EXPECT_DEATH(f->CheckSort({b_var}), ".*");
  EXPECT_DEATH(f->CheckSort({b_var, b_var}), ".*");

  z3::context c;
  auto f_decl = f->GetZ3FuncDecl(c);
}

TEST_F(TestFunc, Multiple) {
  auto f = Func::New("fun", b, {b, bv, bv});
  EXPECT_EQ(b, f->out());
  EXPECT_EQ(3, f->arg_num());
  EXPECT_EQ(bv, f->arg(1));
  EXPECT_ANY_THROW(f->arg(3));
  auto b_var = asthub::NewBoolVar("bool_var");
  auto bv_var = asthub::NewBvVar("bv_var", 8);
  EXPECT_TRUE(f->CheckSort({b_var, bv_var, bv_var}));

  z3::context c;
  auto f_decl = f->GetZ3FuncDecl(c);
}

} // namespace ilang
