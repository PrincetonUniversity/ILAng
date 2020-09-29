/// \file
/// Unit test for commutating diagram-based equivalence checking

#include <z3++.h>

#include <ilang/ila-mngr/u_abs_knob.h>
#include <ilang/ila-mngr/u_unroller.h>
#include <ilang/ila-mngr/v_eq_check_refinement.h>

#include "unit-include/eq_ilas.h"
#include "unit-include/stream_buffer.h"
#include "unit-include/util.h"

namespace ilang {

using namespace asthub;

class TestEqCheck : public ::testing::Test {
public:
  TestEqCheck() {}
  ~TestEqCheck() {}
  void SetUp() {
    DebugLog::Enable("EqCheck");
    DebugLog::Enable("Verbose-CrrEqCheck");
  }
  void TearDown() {
    DebugLog::Disable("EqCheck");
    DebugLog::Disable("Verbose-CrrEqCheck");
  }

  z3::context c;
  z3::solver s = z3::solver(c);
  Z3ExprAdapter g = Z3ExprAdapter(c);

  EqIlaGen ila_gen;
  InstrLvlAbsPtr f1 = ila_gen.GetIlaFlat1("f1");
  InstrLvlAbsPtr f2 = ila_gen.GetIlaFlat2("f2");
  InstrLvlAbsPtr h1 = ila_gen.GetIlaHier1("h1");

  RefPtr GetRefine(const InstrLvlAbsPtr top, const int& instr_idx, bool comp,
                   bool flat);
  RelPtr GetRelation(const InstrLvlAbsPtr m1, const InstrLvlAbsPtr m2);

  void CustF1(const RefPtr ref);
  void CustF2(const RefPtr ref);
  void CustH1(const RefPtr ref);
};

TEST_F(TestEqCheck, FF_Mono) {
  for (auto instr_idx : {0, 1, 2, 3}) {
    // refinement
    auto ref1 = GetRefine(f1, instr_idx, false, true);
    auto ref2 = GetRefine(f2, instr_idx, false, true);
    // relation
    auto rel = GetRelation(f1, f2);
    // crr
    auto crr = CompRefRel::New(ref1, ref2, rel);
    auto cd = CommDiag(c, crr);
    // check
    if (instr_idx != 3) {
      EXPECT_TRUE(cd.EqCheck());
    } else {
      EXPECT_FALSE(cd.EqCheck());
    }
  }
}

TEST_F(TestEqCheck, CommDiag_HF) {
  // DebugLog::Disable("Verbose-CrrEqCheck");
  for (auto instr_idx : {0}) {
    // refinement
    auto ref1 = GetRefine(f1, instr_idx, false, true);
    auto ref2 = GetRefine(h1, instr_idx, true, false);
    // relation
    auto rel = GetRelation(ref1->coi(), ref2->coi());
    // crr
    auto crr = CompRefRel::New(ref1, ref2, rel);
    auto cd = CommDiag(c, crr);
    // invariant
    CustF1(ref1);
    CustH1(ref2);

    EXPECT_TRUE(cd.EqCheck(100));
  }
}

TEST_F(TestEqCheck, IncCommDiag_HF) {
  // DebugLog::Disable("Verbose-CrrEqCheck");
  for (auto instr_idx : {0}) {
    // refinement
    auto ref1 = GetRefine(f1, instr_idx, false, true);
    auto ref2 = GetRefine(h1, instr_idx, true, false);
    // relation
    auto rel = GetRelation(ref1->coi(), ref2->coi());
    // crr
    auto crr = CompRefRel::New(ref1, ref2, rel);
    auto cd = CommDiag(c, crr);
    // invariant
    CustF1(ref1);
    CustH1(ref2);

    EXPECT_TRUE(cd.IncEqCheck(0, 90, 10));
  }
}

TEST_F(TestEqCheck, NewIncCommDiag_HF) {
  // DebugLog::Disable("Verbose-CrrEqCheck");
  for (auto instr_idx : {0}) {
    // refinement
    auto ref1 = GetRefine(f1, instr_idx, false, true);
    auto ref2 = GetRefine(h1, instr_idx, true, false);
    // relation
    auto rel = GetRelation(ref1->coi(), ref2->coi());
    // crr
    auto crr = CompRefRel::New(ref1, ref2, rel);
    auto cd = CommDiag(c, crr);
    // invariant
    CustF1(ref1);
    CustH1(ref2);

    // EXPECT_TRUE(cd.IncCheck(0, 90, 10));
    EXPECT_TRUE(cd.IncCheck(10, 90, 10));
  }
}

RefPtr TestEqCheck::GetRefine(const InstrLvlAbsPtr top, const int& instr_idx,
                              bool comp, bool flat) {
  auto ref = RefinementMap::New();
  // target
  if (comp) { // compositional
    ref->set_tgt(top->instr(instr_idx));
  } else { // monolithic
    ref->set_tgt(top);
  }
  // apply
  ref->set_appl(top->instr(instr_idx)->decode());
  // flush
  ref->set_flush(Not(top->input("start")));
  // complete
  auto instrs = absknob::GetInstrTree(top);
  auto cmpl = BoolConst(true);
  for (auto it = instrs.begin(); it != instrs.end(); it++) {
    auto instr = *it;
    cmpl = And(cmpl, Not(instr->decode()));
  }
  ref->set_cmpl(cmpl);
  // step
  if (flat) {
    ref->set_step_orig(0);
    ref->set_step_appl(0);
  }
  // invariant
  ref->add_inv(Ule(top->state("counter"), 7));

  return ref;
}

RelPtr TestEqCheck::GetRelation(const InstrLvlAbsPtr m1,
                                const InstrLvlAbsPtr m2) {
  auto rel = RelationMap::New();
  for (decltype(m1->state_num()) i = 0; i != m1->state_num(); i++) {
    auto var1 = m1->state(i);
    try {
      auto var2 = m2->state(var1->name().str());
      rel->add(Eq(var1, var2));
    } catch (...) {
      ILA_DLOG("EqCheck") << "Manual relation mapping required.";
    }
  }
  return rel;
}

void TestEqCheck::CustF1(const RefPtr ref) {
  //
}

void TestEqCheck::CustF2(const RefPtr ref) {
  //
}

void TestEqCheck::CustH1(const RefPtr ref) {
  auto c1 = h1->child(0);
  auto ucnt = h1->state("c1vld");
  auto uptr = c1->state("uptr");
  ILA_NOT_NULL(ucnt);
  ILA_NOT_NULL(uptr);

  ref->add_inv(Uge(ucnt, 0));
  // ref->add_inv(Ult(ucnt, 2));
  ref->add_inv(Ule(ucnt, ila_gen.reg_num()));
  ref->add_inv(Uge(uptr, 0));
  ref->add_inv(Ult(uptr, ila_gen.reg_num()));

  // ref->set_step_orig(5);
  // ref->set_step_appl(5);
  ref->set_step_orig(60);
  ref->set_step_appl(70);
}

} // namespace ilang
