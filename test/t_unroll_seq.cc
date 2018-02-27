/// \file
/// Unit test for unrolling a sequence of instruction.

#include "unit-include/eq_ilas.h"
#include "unit-include/util.h"
#include "verify/unroller.h"
#include <iostream>

namespace ila {

class TestUnroll : public ::testing::Test {
public:
  TestUnroll() {}
  ~TestUnroll() {}
  void SetUp() {
    SetToStdErr(1);
    DebugLog::Enable("Unroller");
  }
  void TearDown() {
    SetToStdErr(0);
    DebugLog::Disable("Unroller");
  }

  EqIlaGen ila_gen_;
  z3::context ctx_;

}; // class TestUnroll

TEST_F(TestUnroll, InstrSeqFlat) {
  auto m = ila_gen_.GetIlaFlat1();

  std::vector<InstrPtr> seq;
  for (size_t i = 0; i != m->instr_num(); i++) {
    seq.push_back(m->instr(i));
  }

  Unroller* unroller = new ListUnroll(ctx_);
  auto cstr = unroller->InstrSeq(seq);

  // std::cout << cstr << std::endl;
}

TEST_F(TestUnroll, InsteSeqFlatSubs) {
  auto m = ila_gen_.GetIlaFlat1();

  std::vector<InstrPtr> seq;
  for (size_t i = 0; i != m->instr_num(); i++) {
    seq.push_back(m->instr(i));
  }

  ListUnroll* unroller = new ListUnroll(ctx_);
  auto cstr = unroller->InstrSeqSubs(seq);
}

TEST_F(TestUnroll, InsteSeqFlatAssn) {
  auto m = ila_gen_.GetIlaFlat1();

  std::vector<InstrPtr> seq;
  for (size_t i = 0; i != m->instr_num(); i++) {
    seq.push_back(m->instr(i));
  }

  ListUnroll* unroller = new ListUnroll(ctx_);
  auto cstr = unroller->InstrSeqAssn(seq);
}

TEST_F(TestUnroll, InstrSeqFlatNone) {
  auto m = ila_gen_.GetIlaFlat1();
  std::vector<InstrPtr> seq;
  for (size_t i = 0; i != m->instr_num(); i++) {
    seq.push_back(m->instr(i));
  }

  ListUnroll* unroller = new ListUnroll(ctx_);
  auto cstr = unroller->InstrSeqNone(seq);
}

} // namespace ila

