/// \file
/// Unit test for class InstrLvlAbs.

#include "ila/instr_lvl_abs.h"
#include "unit-include/util.h"

namespace ila {

TEST(TestInstrLvlAbs, Construct) {
  InstrLvlAbs ila_dummy;
  InstrLvlAbs ila_obj("ila_obj");
  auto ptr = InstrLvlAbs::New("ila_ptr");

  EXPECT_TRUE(ila_dummy.is_instr_lvl_abs());
  EXPECT_FALSE(ila_dummy.is_instr());
  EXPECT_FALSE(ila_dummy.is_ast());

  EXPECT_TRUE(ila_obj.is_instr_lvl_abs());
  EXPECT_EQ(Symbol("ila_obj"), ila_obj.name());

  EXPECT_TRUE(ptr->is_instr_lvl_abs());
  EXPECT_EQ(Symbol("ila_ptr"), ptr->name());
}

TEST(TestInstrLvlAbs, Spec) {
  auto ila = InstrLvlAbs::New("ila");

  EXPECT_TRUE(ila->is_spec());

  ila->set_spec(false);
  EXPECT_FALSE(ila->is_spec());
}

TEST(TestInstrLvlAbs, Simplifier) {
  auto ila = InstrLvlAbs::New("ila");

  ExprMngrPtr new_mngr = std::make_shared<ExprMngr>();
  EXPECT_NE(new_mngr.get(), ila->expr_mngr().get());
  ila->set_expr_mngr(new_mngr);
  EXPECT_EQ(new_mngr.get(), ila->expr_mngr().get());
}

TEST(TestInstrLvlAbs, Input) {
  auto ila = InstrLvlAbs::New("ila");

  // Add
  ExprPtr bool_input = ExprFuse::NewBoolVar("bool_input");
  ila->AddInput(bool_input);

  ExprPtr bool_const = ExprFuse::BoolConst(true);
#ifndef NDEBUG
  EXPECT_DEATH(ila->AddInput(bool_const), ".*");
  EXPECT_DEATH(ila->AddInput(NULL), ".*");
#endif

  ExprPtr new_bool_input = ExprFuse::NewBoolVar("bool_input");
#ifndef NDEBUG
  EXPECT_DEATH(ila->AddInput(new_bool_input), ".*");
#endif

  // New
  ExprPtr bool_in_emb = ila->NewBoolInput("bool_in_emb");
  ExprPtr bv_in_emb = ila->NewBvInput("bv_in_emb", 8);
#ifndef NDEBUG
  EXPECT_DEATH(ila->NewBoolInput("bool_in_emb"), ".*");
  EXPECT_DEATH(ila->NewBvInput("bv_in_emb", 8), ".*");
#endif

  // Get
  EXPECT_EQ(3, ila->input_num());
  EXPECT_EQ(bool_input, ila->input(0));
  EXPECT_EQ(bool_in_emb, ila->input(1));
  EXPECT_EQ(bv_in_emb, ila->input(2));
#ifndef NDEBUG
  EXPECT_DEATH(ila->input(3), ".*");
#endif

  ExprPtr get_bool_input = ila->input("bool_input");
#ifndef NDEBUG
  EXPECT_EQ(bool_input, get_bool_input);
#endif

  ExprPtr get_fail = ila->input("non-exist");
  EXPECT_TRUE(get_fail == NULL);
}

TEST(TestInstrLvlAbs, State) {
  auto ila = InstrLvlAbs::New("ila");

  // Add
  ExprPtr bool_state = ExprFuse::NewBoolVar("bool_state");
  ila->AddState(bool_state);

  ExprPtr bool_const = ExprFuse::BoolConst(true);
#ifndef NDEBUG
  EXPECT_DEATH(ila->AddState(bool_const), ".*");

  EXPECT_DEATH(ila->AddState(NULL), ".*");
#endif

  ExprPtr new_bool_state = ExprFuse::NewBoolVar("bool_state");
#ifndef NDEBUG
  EXPECT_DEATH(ila->AddState(new_bool_state), ".*");
#endif

  // New
  ExprPtr bool_st_emb = ila->NewBoolState("bool_st_emb");
  ExprPtr bv_st_emb = ila->NewBvState("bv_st_emb", 8);
#ifndef NDEBUG
  EXPECT_DEATH(ila->NewBoolState("bool_st_emb"), ".*");
  EXPECT_DEATH(ila->NewBvState("bv_st_emb", 8), ".*");
#endif

  // Get
  EXPECT_EQ(3, ila->state_num());
  EXPECT_EQ(bool_state, ila->state(0));
  EXPECT_EQ(bool_st_emb, ila->state(1));
  EXPECT_EQ(bv_st_emb, ila->state(2));
#ifndef NDEBUG
  EXPECT_DEATH(ila->state(3), ".*");
#endif

  ExprPtr get_bool_state = ila->state("bool_state");
  EXPECT_EQ(bool_state, get_bool_state);

  ExprPtr get_fail = ila->state("non-exist");
  EXPECT_TRUE(get_fail == NULL);
}

TEST(TestInstrLvlAbs, Init) {
  auto ila = InstrLvlAbs::New("ila");
  auto varx = ila->NewBvState("varx", 8);
  auto vary = ila->NewBvState("vary", 8);
  auto bv0 = ExprFuse::BvConst(0, 8);
  auto bv1 = ExprFuse::BvConst(1, 8);

  auto init0 = ExprFuse::Eq(varx, bv0);
  auto init1 = ExprFuse::Ne(vary, bv1);
  auto bad_cntr = ExprFuse::And(varx, bv1);

  ila->AddInit(init0);
  ila->AddInit(init1);
#ifndef NDEBUG
  EXPECT_DEATH(ila->AddInit(bad_cntr), ".*");
  EXPECT_DEATH(ila->AddInit(NULL), ".*");
#endif

  EXPECT_EQ(2, ila->init_num());
  EXPECT_EQ(init0, ila->init(0));
  EXPECT_EQ(init1, ila->init(1));
}

TEST(TestInstrLvlAbs, Fetch) {
  auto ila = InstrLvlAbs::New("ila");
  auto varx = ila->NewBvState("varx", 8);
  auto vary = ila->NewBvState("vary", 8);
  auto varb = ila->NewBoolState("varb");
  auto mem = ila->NewMemState("mem", 8, 32);

  auto fetch = ExprFuse::Load(mem, varx);
  auto new_f = ExprFuse::Or(varx, vary);

#ifndef NDEBUG
  EXPECT_DEATH(ila->SetFetch(varb), ".*");
  EXPECT_DEATH(ila->SetFetch(NULL), ".*");
#endif

  ila->SetFetch(fetch);
#ifndef NDEBUG
  EXPECT_DEATH(ila->SetFetch(new_f), ".*");
#endif

  EXPECT_EQ(fetch, ila->fetch());
  EXPECT_NE(new_f, ila->fetch());
}

TEST(TestInstrLvlAbs, Valid) {
  auto ila = InstrLvlAbs::New("ila");
  auto varx = ila->NewBvState("varx", 8);
  auto varb = ila->NewBoolState("varb");
  auto mem = ila->NewMemState("mem", 8, 32);
  auto bv0 = ExprFuse::BvConst(0, 32);

  auto opcode = ExprFuse::Load(mem, varx);
  auto valid = ExprFuse::Eq(opcode, bv0);
  auto new_v = varb;

#ifndef NDEBUG
  EXPECT_DEATH(ila->SetValid(opcode), ".*");
  EXPECT_DEATH(ila->SetValid(NULL), ".*");
#endif

  ila->SetValid(valid);
#ifndef NDEBUG
  EXPECT_DEATH(ila->SetValid(new_v), ".*");
#endif

  EXPECT_EQ(valid, ila->valid());
  EXPECT_NE(new_v, ila->valid());
}

TEST(TestInstrLvlAbs, Instr) {
  auto ila = InstrLvlAbs::New("ila");

  // external un-named instruction (Fixed to have name).
  auto instr_ex = Instr::New("instr_ex");
  ila->AddInstr(instr_ex);

  // external named instruction
  auto instr_ex_n = Instr::New("instr_ex_n");
  ila->AddInstr(instr_ex_n);

  // embedded un-named instruction
  auto instr_em = ila->NewInstr();

  // embedded named instruction
  auto instr_em_n = ila->NewInstr("instr_em_n");

  EXPECT_EQ(4, ila->instr_num());

// add existed instr
#ifndef NDEBUG
  EXPECT_DEATH(ila->NewInstr("instr_ex_n"), ".*");
  EXPECT_DEATH(ila->NewInstr(instr_em_n->name().str()), ".*");
#endif
  EXPECT_EQ(4, ila->instr_num());

  // find non-existed
  auto instr_null = ila->instr("dummy_instr");
  EXPECT_TRUE(instr_null == NULL);

  // find existed
  EXPECT_EQ(instr_ex, ila->instr(instr_ex->name().str()));
  EXPECT_EQ(instr_ex_n, ila->instr("instr_ex_n"));
  EXPECT_EQ(instr_em, ila->instr(instr_em->name().str()));
  EXPECT_EQ(instr_em_n, ila->instr("instr_em_n"));

  // random access
  EXPECT_EQ(instr_ex, ila->instr(0));
  EXPECT_EQ(instr_ex_n, ila->instr(1));
  EXPECT_EQ(instr_em, ila->instr(2));
  EXPECT_EQ(instr_em_n, ila->instr(3));
#ifndef NDEBUG
  EXPECT_DEATH(ila->instr(5), ".*");
#endif
}

TEST(TestInstrLvlAbs, Child) {
  auto ila = InstrLvlAbs::New("ila");

  // add external
  auto child1 = InstrLvlAbs::New("child1");
  ila->AddChild(child1);
  EXPECT_TRUE(child1->parent() == NULL);

  // add embedded
  auto child2 = ila->NewChild("child2");
  EXPECT_EQ(ila, child2->parent());

  EXPECT_EQ(2, ila->child_num());

// add existed
#ifndef NDEBUG
  EXPECT_DEATH(ila->AddChild(child2), ".*");
  EXPECT_DEATH(ila->NewChild("child1"), ".*");
#endif

  EXPECT_EQ(2, ila->child_num());

  // find non-existed
  auto child_null = ila->child("child3");
  EXPECT_TRUE(child_null == NULL);

  // find existed
  EXPECT_EQ(child1, ila->child("child1"));
  EXPECT_EQ(child2, ila->child("child2"));

  // random access
  EXPECT_EQ(child1, ila->child(0));
  EXPECT_EQ(child2, ila->child(1));
#ifndef NDEBUG
  EXPECT_DEATH(ila->child(3), ".*");
#endif
}

TEST(TestInstrLvlAbs, CheckAll) {
  auto ila = InstrLvlAbs::New("ila");
  EXPECT_TRUE(ila->Check());
}

TEST(TestInstrLvlAbs, MergeAll) {
  auto ila = InstrLvlAbs::New("ila");
  ila->MergeChild();
  // TODO
}

TEST(TestInstrLvlAbs, SortInstr) {
  auto ila = InstrLvlAbs::New("ila");
  ila->SortInstr();
  // TODO
}

TEST(TestInstrLvlAbs, SeqTran) {
  auto ila = InstrLvlAbs::New("ila");

  auto instr_0 = ila->NewInstr("instr_0");
  auto instr_1 = ila->NewInstr("instr_1");
  auto instr_2 = ila->NewInstr("instr_2");
  auto counter = ila->NewBvState("counter", 8);
  auto const_1 = ExprFuse::BvConst(1, 8);
  auto const_2 = ExprFuse::BvConst(2, 8);
  auto cnd_1 = ExprFuse::Eq(counter, const_1);
  auto cnd_2 = ExprFuse::Eq(counter, const_2);

  ila->AddSeqTran(instr_0, instr_1, cnd_1);
  ila->AddSeqTran(instr_1, instr_2, cnd_2);
  // TODO
}

TEST(TestInstrLvlAbs, Print) {
  InstrLvlAbs ila("ila");
  std::string msg;
  std::string ref_msg = "ILA.ila";

  GET_STDOUT_MSG(std::cout << ila, msg);
  EXPECT_EQ(ref_msg, msg);

  GET_STDOUT_MSG(ila.Print(std::cout), msg);
  EXPECT_EQ(ref_msg, msg);
}

} // namespace ila

