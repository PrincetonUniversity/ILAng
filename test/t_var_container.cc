/// \file
/// Unit tests for VarContainer.

#include "unit-include/util.h"
#include <ilang/ila/var_container.h>
#include <ilang/ila/ast_hub.h>

#ifndef NDEBUG
  #define EXPECT_DEATH_OR_DEFAULT(stmt, default) EXPECT_DEATH(stmt, ".*")
#else
  #define EXPECT_DEATH_OR_DEFAULT(stmt, default) EXPECT_EQ(stmt, default) 
#endif

namespace ilang {

/* Checks that there is exactly one type function that is true for a 
   given VarContainerPtr. */
void check_container_type(const VarContainerPtr& p) {
  std::vector<std::pair<VarContainer::ContainerType, bool>> is_known_types = {
    {VarContainer::ContainerType::primitive, p->is_primitive()},
    {VarContainer::ContainerType::structure, p->is_struct()},
    {VarContainer::ContainerType::vector, p->is_vector()}
  };
  int num_true = 0;
  for (auto& [t, is_t] : is_known_types) {
    EXPECT_EQ(p->container_type() == t, is_t);
    num_true += is_t;
  }
  EXPECT_EQ(num_true, 1);
}

void test_not_primitive(const VarContainerPtr& p) {
  if (p->is_primitive()) return;
  EXPECT_DEATH_OR_DEFAULT(p->to_primitive_expr(), nullptr);
}

void test_not_vector(const VarContainerPtr& p) {
  if (p->is_vector()) return;
  EXPECT_DEATH_OR_DEFAULT(p->nth(0), nullptr);
  EXPECT_DEATH_OR_DEFAULT(p->size(), 0);
  EXPECT_DEATH_OR_DEFAULT(p->elements().size(), 0);
}

void test_not_struct(const VarContainerPtr& p) {
  if (p->is_struct()) return;
  EXPECT_DEATH_OR_DEFAULT(p->member("a"), nullptr);
  EXPECT_DEATH_OR_DEFAULT(p->members().size(), 0);
}

void basic_tests(const VarContainerPtr& p) {
  check_container_type(p);
  test_not_primitive(p);
  test_not_vector(p);
  test_not_struct(p);
}


TEST(TestVarContainer, Primitive) {
  auto e1 = VarContainer::Make("a", Sort::MakeBoolSort());
  basic_tests(e1);
  EXPECT_EQ(e1->sort(), Sort::MakeBoolSort());
  EXPECT_NE(e1->sort(), Sort::MakeMemSort(5, 10));

  auto e2 = VarContainer::Make("b", Sort::MakeBvSort(3));
  basic_tests(e2);
  EXPECT_EQ(e2->sort(), Sort::MakeBvSort(3));
  EXPECT_NE(e2->sort(), Sort::MakeBvSort(5));

  // check conversion to exprs
  auto f = asthub::And(e1, asthub::NewBoolVar("b"));
}

TEST(TestVarContainer, Vector) {
  auto xs = VarContainer::Make("xs", Sort::MakeVectorSort(Sort::MakeBoolSort(), 3));
  basic_tests(xs);

  // size
  EXPECT_EQ(xs->size(), 3);

  // nth
  auto e0 = 
    asthub::Or(asthub::Or(asthub::Or(
      asthub::BoolConst(false), xs->nth(0)), xs->nth(1)), xs->nth(2))
    ;
  EXPECT_DEATH_OR_DEFAULT(xs->nth(1000), nullptr);
  EXPECT_DEATH_OR_DEFAULT(xs->nth(-1), nullptr);

  // size and nth
  auto e1 = asthub::BoolConst(false);
  for (int i = 0; i != xs->size(); ++i) {
    e1 = asthub::Or(e1, xs->nth(i));
  }

  EXPECT_TRUE(asthub::TopEq(e0, e1));

  // elements
  auto e2 = asthub::BoolConst(false);
  for (auto& x : xs->elements()) {
    e2 = asthub::Or(e2, x);
  }

  EXPECT_TRUE(asthub::TopEq(e1, e2));

  // different computations
  auto e3 = asthub::BoolConst(true);
  for (auto& x : xs->elements()) {
    e3 = asthub::Or(e3, x);
  }
  EXPECT_FALSE(asthub::TopEq(e2, e3));

  // vectors of vectors
  auto m = VarContainer::Make("m", 
    Sort::MakeVectorSort(Sort::MakeVectorSort(Sort::MakeBvSort(8), 16),16));
  for (auto& row : m->elements()) {
    for (auto& x : row->elements()) {
      EXPECT_EQ(x->sort(), Sort::MakeBvSort(8));
    }
  }

  // TODO: consider testing for collision avoidance?
  // This passes but is brittle and may be incorrect:
  // auto row = VarContainer::Make("m_0_", Sort::MakeVectorSort(Sort::MakeBoolSort(), 5));
  // for (int i = 0; i != row->size(); ++i) {
  //   EXPECT_FALSE(asthub::TopEq(row->nth(i), m->nth(0)->nth(i)));
  // }

}

TEST(TestVarContainer, VectorPartitioning) {
  int n_elems = 16, n_parts = 4;
  auto xs = VarContainer::Make("xs", Sort::MakeVectorSort(Sort::MakeBoolSort(), n_elems));
  auto xs_parted = 
    xs->order_preserving_partition(n_parts, [n_parts](size_t n) {return n / n_parts;});
  for (int i = 0; i != n_elems; ++i) {
    EXPECT_EQ(xs->nth(i), xs_parted[i / n_parts]->nth(i % n_parts));
  }
}

TEST(TestVarContainer, Struct) {
  int bvsize = 8;
  auto Point = Sort::MakeStructSort({
    {"x", Sort::MakeBvSort(bvsize)}, {"y", Sort::MakeBvSort(bvsize)}
  });
  auto p1 = VarContainer::Make("p1", Point);
  auto p2 = VarContainer::Make("p2", Point);
  basic_tests(p1);
  EXPECT_EQ(p1->sort(), Point);
  EXPECT_EQ(p1->sort(), p2->sort());
  EXPECT_EQ(p1->sort(), Sort::MakeStructSort({
    {"x", Sort::MakeBvSort(bvsize)}, {"y", Sort::MakeBvSort(bvsize)}
  }));
  EXPECT_NE(p1->sort(), Sort::MakeStructSort({
    {"x", Sort::MakeBvSort(bvsize)}, {"z", Sort::MakeBvSort(bvsize)}
  }));

  // member
  auto t = 
    asthub::And(
    asthub::And(asthub::BoolConst(true),
                asthub::Eq(p1->member("x"), asthub::BvConst(0, bvsize))), 
      asthub::Eq(p1->member("y"), asthub::BvConst(1, bvsize))
  );
  EXPECT_DEATH_OR_DEFAULT(p1->member("q"), nullptr);
  
  // members
  auto t2 = asthub::BoolConst(true);
  int i = 0;
  for (auto& [name, var] : p1->members()) {
    t2 = asthub::And(t2, asthub::Eq(var, asthub::BvConst(i, bvsize)));
    ++i;
  }
  EXPECT_TRUE(asthub::TopEq(t, t2));

}

TEST(TestVarContainer, Visitor) {
  std::vector<std::tuple<SortPtr, int, int, int>> examples {
    {Sort::MakeMemSort(5, 4), 1, 0, 0},
    {Sort::MakeVectorSort(Sort::MakeBoolSort(), 3), 3, 1, 0},
    {Sort::MakeStructSort(
        {{"x", Sort::MakeVectorSort(Sort::MakeBvSort(4), 3)}, {"y", Sort::MakeBvSort(5)}}
      ), 4, 1, 1},
    {Sort::MakeVectorSort(Sort::MakeStructSort(
        {{"x", Sort::MakeBoolSort()}, {"y", Sort::MakeBvSort(3)}}
      ), 3), 6, 1, 3},
    {Sort::MakeVectorSort(Sort::MakeStructSort(
        {{"x", Sort::MakeVectorSort(Sort::MakeBoolSort(), 2)}, 
         {"y", Sort::MakeVectorSort(Sort::MakeBoolSort(), 3)}}
      ), 3), 15, 7, 3}
  };

  for (auto& [t, np, nv, ns] : examples) {
    int num_primitives {0};
    int num_vectors {0};
    int num_structs {0};
    VarContainer::visitor vis = 
      [&num_primitives, &num_vectors, &num_structs](VarContainer* const vc) {
        num_primitives += vc->is_primitive();
        num_vectors += vc->is_vector();
        num_structs += vc->is_struct();
      }
    ;

    auto expr {VarContainer::Make("ex", t)};
    expr->visit_with(vis);
    EXPECT_EQ(num_primitives, np);
    EXPECT_EQ(num_vectors, nv);
    EXPECT_EQ(num_structs, ns);
  }

}

};