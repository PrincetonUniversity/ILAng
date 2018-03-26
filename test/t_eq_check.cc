/// \file
/// Unit test for commutating diagram-based equivalence checking

#include "backend/unroller.h"
#include "refinement/eq_check_crr.h"
#include "unit-include/eq_ilas.h"
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
    DebugLog::Enable("Verbose-CheckRefine");
  }
  void TearDown() {
    SetToStdErr(0);
    DebugLog::Disable("EqCheck");
    DebugLog::Disable("Verbose-CheckRefine");
  }

  z3::context c;
  z3::solver s = z3::solver(c);
  Z3ExprAdapter g = Z3ExprAdapter(c);

  EqIlaGen ila_gen;
  InstrLvlAbsPtr f1 = ila_gen.GetIlaFlat1("f1");
  InstrLvlAbsPtr f2 = ila_gen.GetIlaFlat2("f2");
  // InstrLvlAbsPtr h1_ = ila_gen_.GetIlaHier1("h1");
  // InstrLvlAbsPtr h2_ = ila_gen_.GetIlaHier2("h2");
};

TEST_F(TestEqCheck, CommDiag_FF) {
  SetToStdErr(1);

  // Test:
  // 1. coi analysis
  // 2. step specified
  // 3. step not specified with different bound

  for (size_t instr_idx = 0; instr_idx != 3; instr_idx++) {
    // refinement for f1
    RefPtr ref1 = RefinementMap::New();
    ref1->set_tgt(f1);
    ref1->set_appl(f1->instr(instr_idx)->decode());
    ref1->set_flush(Not(f1->input("start")));
    ref1->set_cmpl(BoolConst(true));
    ref1->set_step(0);
    ref1->add_inv(Ule(f1->state("counter"), 7));
    // refinement for f2
    RefPtr ref2 = RefinementMap::New();
    ref2->set_tgt(f2);
    ref2->set_appl(f2->instr(instr_idx)->decode());
    ref2->set_flush(Not(f2->input("start")));
    ref2->set_cmpl(BoolConst(true));
    ref2->add_inv(Ule(f2->state("counter"), 7));
    // ref2->set_step(0);
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

    for (auto i = 0; i != 1; i++) {
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

      auto sanity = cd.GenVerCondTran(i);
      s.reset();
      s.add(sanity);
      EXPECT_EQ(z3::sat, s.check());
    }
  }
}

} // namespace ila

