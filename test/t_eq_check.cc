/// \file
/// Unit test for commutating diagram-based equivalence checking

#include "backend/abs_knob.h"
#include "backend/unroller.h"
#include "refinement/eq_check_crr.h"
#include "unit-include/eq_ilas.h"
#include "unit-include/stream_buffer.h"
#include "unit-include/util.h"
#include "z3++.h"

namespace ila {

using namespace ExprFuse;

class TestEqCheck : public ::testing::Test {
public:
  TestEqCheck() {}
  ~TestEqCheck() {}
  void SetUp() {
    DebugLog::Enable("EqCheck");
    DebugLog::Enable("Verbose-CrrEqCheck");
  }
  void TearDown() {
    SetToStdErr(0);
    DebugLog::Disable("EqCheck");
    DebugLog::Disable("Verbose-CrrEqCheck");
  }

  z3::context c;
  z3::solver s = z3::solver(c);
  Z3ExprAdapter g = Z3ExprAdapter(c);

  EqIlaGen ila_gen;
  InstrLvlAbsPtr f1 = ila_gen.GetIlaFlat1("f1");
  InstrLvlAbsPtr f2 = ila_gen.GetIlaFlat2("f2");
  // InstrLvlAbsPtr h1_ = ila_gen_.GetIlaHier1("h1");
  // InstrLvlAbsPtr h2_ = ila_gen_.GetIlaHier2("h2");

  RefPtr GetRefine(const InstrLvlAbsPtr top, const int& instr_idx, bool comp,
                   bool flat);
  RelPtr GetRelation(const InstrLvlAbsPtr m1, const InstrLvlAbsPtr m2);
};

TEST_F(TestEqCheck, FF_Mono) {
  SetToStdErr(1);
  DebugLog::Disable("Verbose-CrrEqCheck");

  // refinement
  auto instr_idx = 0;
  auto ref1 = GetRefine(f1, instr_idx, false, true);
  auto ref2 = GetRefine(f2, instr_idx, false, true);

  // relation
  auto rel = GetRelation(f1, f2);
  // crr
  auto crr = CompRefRel::New(ref1, ref2, rel);
  auto cd = CommDiag(c, crr);

  auto res = cd.EqCheck();
  EXPECT_TRUE(res);
}

TEST_F(TestEqCheck, CommDiag_FF_Legacy) {
  SetToStdErr(1);

  // 1. coi analysis XXX
  // 2. step specified
  // 3. step not specified with different bound

  // refinement for f1
  RefPtr ref1 = RefinementMap::New();
  ref1->set_tgt(f1);
  ref1->set_flush(Not(f1->input("start")));
  ref1->set_cmpl(BoolConst(true));
  ref1->set_step(0);
  ref1->add_inv(Ule(f1->state("counter"), 7));

  // refinement for f2
  RefPtr ref2 = RefinementMap::New();
  ref2->set_tgt(f2);
  ref2->set_flush(Not(f2->input("start")));
  ref2->set_cmpl(BoolConst(true));
  ref2->add_inv(Ule(f2->state("counter"), 7));
  // ref2 not specify # step

  // relation between f1 and f2
  RelPtr rel = RelationMap::New();
  for (size_t i = 0; i != f1->state_num(); i++) {
    auto var1 = f1->state(i);
    try {
      auto var2 = f2->state(var1->name().str());
      rel->add(Eq(var1, var2));
    } catch (...) {
      ILA_DLOG("EqCheck") << "Manual relation mapping required.";
    }
  }
  // crr
  CrrPtr crr = CompRefRel::New(ref1, ref2, rel);
  CommDiag cd = CommDiag(c, crr);

  for (size_t instr_idx = 0; instr_idx != 3; instr_idx++) {
    ref1->set_appl(f1->instr(instr_idx)->decode());
    ref2->set_appl(f2->instr(instr_idx)->decode());

    for (auto i = 0; i != 2; i++) {
      auto vc = cd.GenVerCond(i);
      s.reset();
      s.add(vc);
      EXPECT_EQ(z3::unsat, s.check());

#if 0
      ILA_DLOG("EqCheck") << s.get_model().eval(
          g.GetExpr(f1->state("counter"), "0o"));
      ILA_DLOG("EqCheck") << s.get_model().eval(
          g.GetExpr(f1->state("counter"), "0n"));
      ILA_DLOG("EqCheck") << s.get_model().eval(
          g.GetExpr(f1->state("counter"), "n"));
      ILA_DLOG("EqCheck") << s.get_model().eval(
          g.GetExpr(f1->state("counter"), "o"));
#endif

      auto tran = cd.GenVerCondTran(i);
      s.reset();
      s.add(tran);
      EXPECT_EQ(z3::sat, s.check());

      auto prop = cd.GenVerCondProp();
      s.reset();
      s.add(tran);
      s.add(prop);
      EXPECT_EQ(z3::sat, s.check());
    }
  }

  auto fail_idx = 3;
  ref1->set_appl(f1->instr(fail_idx)->decode());
  ref2->set_appl(f2->instr(fail_idx)->decode());
  auto vc = cd.GenVerCond(0);
  s.reset();
  s.add(vc);
  EXPECT_EQ(z3::sat, s.check());
}

TEST_F(TestEqCheck, CommDiag_HF) {
  // TODO
  // with and without completion
}

TEST_F(TestEqCheck, CommDiag_HH) {
  // TODO
  // with and without completion
}

TEST_F(TestEqCheck, CommDiag_Pipeline) {
  ExmpStrmBuff sb;
  auto m = sb.GetStrmBuffSpecRaw("spec");
  // TODO
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
  std::set<InstrPtr> instrs;
  AbsKnob::GetInstrOfIla(top, instrs);
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
  ref->add_inv(Ule(f1->state("counter"), 7));

  return ref;
}

RelPtr TestEqCheck::GetRelation(const InstrLvlAbsPtr m1,
                                const InstrLvlAbsPtr m2) {
  auto rel = RelationMap::New();
  for (decltype(f1->state_num()) i = 0; i != f1->state_num(); i++) {
    auto var1 = f1->state(i);
    try {
      auto var2 = f2->state(var1->name().str());
      rel->add(Eq(var1, var2));
    } catch (...) {
      ILA_DLOG("EqCheck") << "Manual relation mapping required.";
    }
  }
  return rel;
}

} // namespace ila

