/// \file
/// Unit test for instruction sequencing

#include <ilang/ila/ast_hub.h>
#include <ilang/ila/instr.h>
#include <ilang/ila/transition.h>

#include "unit-include/util.h"

namespace ilang {

class TestInstrSeq : public ::testing::Test {
public:
  TestInstrSeq() {}
  ~TestInstrSeq() {}

  void SetUp() {
    counter = asthub::NewBvVar("counter", 8);
    const_0 = asthub::BvConst(0, 8);
    const_1 = asthub::BvConst(1, 8);
    const_2 = asthub::BvConst(2, 8);
    const_3 = asthub::BvConst(3, 8);
    const_4 = asthub::BvConst(4, 8);
    const_5 = asthub::BvConst(5, 8);

    instr_0 = Instr::New("instr_0");
    instr_1 = Instr::New("instr_1");
    instr_2 = Instr::New("instr_2");
    instr_3 = Instr::New("instr_3");
    instr_4 = Instr::New("instr_4");
    instr_5 = Instr::New("instr_5");
  }

  void TearDown() {}

  InstrSeqPtr InitSeq() {
    auto seq = InstrSeq::New();

    // construct graph
    seq->AddTran(instr_0, instr_1, asthub::Eq(counter, const_1));
    seq->AddTran(instr_1, instr_2, asthub::Eq(counter, const_2));
    seq->AddTran(instr_2, instr_3, asthub::Eq(counter, const_3));
    seq->AddTran(instr_2, instr_0, asthub::Eq(counter, const_0));

    return seq;
  }

  // --------------------- Data members --------------------------------------//
  // states
  ExprPtr counter;
  ExprPtr const_0;
  ExprPtr const_1;
  ExprPtr const_2;
  ExprPtr const_3;
  ExprPtr const_4;
  ExprPtr const_5;

  // instructions
  InstrPtr instr_0;
  InstrPtr instr_1;
  InstrPtr instr_2;
  InstrPtr instr_3;
  InstrPtr instr_4;
  InstrPtr instr_5;

}; // class TestInstrSeq

TEST_F(TestInstrSeq, ItEdge) {
  auto cnd = asthub::Eq(counter, const_0);
  auto edge = std::make_shared<InstrTranEdge>(instr_0, instr_1, cnd);

  EXPECT_EQ(instr_0, edge->src());
  EXPECT_EQ(instr_1, edge->dst());
  EXPECT_EQ(cnd, edge->cnd());
}

TEST_F(TestInstrSeq, ItNode) {
  auto node_0 = std::make_shared<InstrTranNode>(instr_0);
  auto node_1 = std::make_shared<InstrTranNode>(instr_1);
  auto node_2 = std::make_shared<InstrTranNode>(instr_2);
  auto node_3 = std::make_shared<InstrTranNode>(instr_3);

  EXPECT_EQ(instr_0, node_0->instr());
  EXPECT_EQ(instr_1, node_1->instr());
  EXPECT_EQ(instr_2, node_2->instr());
  EXPECT_EQ(instr_3, node_3->instr());

  // construct graph
  node_0->AddNext(node_1);
  node_1->AddPrev(node_0);

  node_1->AddNext(node_1);
  node_2->AddPrev(node_1);

  node_2->AddNext(node_3);
  node_3->AddPrev(node_2);

  node_2->AddNext(node_0);
  node_0->AddPrev(node_2);

  EXPECT_EQ(1, node_0->prev_num());
  EXPECT_EQ(1, node_0->next_num());
  EXPECT_EQ(1, node_2->prev_num());
  EXPECT_EQ(2, node_2->next_num());

  EXPECT_EQ(node_1, node_2->prev(0));
  EXPECT_EQ(node_3, node_2->next(0));
  EXPECT_EQ(node_0, node_2->next(1));
#ifndef NDEBUG
  EXPECT_DEATH(node_3->next(0), ".*");
  EXPECT_DEATH(node_3->prev(1), ".*");
#endif
}

TEST_F(TestInstrSeq, AddTran) { auto seq = InitSeq(); }

} // namespace ilang
