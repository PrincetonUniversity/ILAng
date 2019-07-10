/// file
/// Unit test for the AES Verlog vs C equivalence checking.

#include <ilang/ilang++.h>
#include <ilang/verification/abs_knob.h>
#include <ilang/verification/eq_check_crr.h>

#include <ilang/util/fs.h>
#include <z3++.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

TEST(TestCase, AES_V_C_EQ) {
  SetToStdErr(0);
  DebugLog::Enable("CaseAesEq");
  DebugLog::Enable("EqCheck");
  DebugLog::Enable("Verbose-CrrEqCheck");

  // get the ILA model
  auto aes_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "aes");
  auto aes_v_file = os_portable_append_dir(aes_dir, "aes_v.json");
  auto aes_c_file = os_portable_append_dir(aes_dir, "aes_c.json");

  auto aes_v = ImportIlaPortable(aes_v_file);
  auto aes_c = ImportIlaPortable(aes_c_file);

  auto m_v = aes_v.get();
  auto m_c = aes_c.get();
  auto u_v = m_v->child(0);
  auto u_c = m_c->child(0);

  ASSERT_NE(m_v, nullptr);
  ASSERT_NE(u_v, nullptr);
  ASSERT_NE(m_c, nullptr);
  ASSERT_NE(u_c, nullptr);

  // determine which instruction is the start encrypt (i.e., cmdaddr == 0xff00)
  auto FindStartInstr = [=](InstrLvlAbsPtr ila) {
    z3::context c;
    z3::solver s = z3::solver(c);
    auto z3gen = Z3ExprAdapter(c);

    for (auto i = 0; i < ila->instr_num(); i++) {
      auto decode = ila->instr(i)->decode();
      auto cmdaddr = ila->input("cmdaddr");
      auto subtree = ExprFuse::Eq(cmdaddr, 0xff00);

      auto pred_expr = ExprFuse::And(decode, subtree);
      auto pred_z3 = z3gen.GetExpr(pred_expr);
      s.reset();
      s.add(pred_z3);
      if (s.check() == z3::sat) {
        return ila->instr(i);
      }
    }
    ILA_ERROR << "Fail finding start instruction";
    return InstrPtr(NULL);
  };

  auto start_v = FindStartInstr(m_v);
  auto start_c = FindStartInstr(m_c);
  ILA_NOT_NULL(start_v);
  ILA_NOT_NULL(start_c);
  ILA_DLOG("CaseAesEq") << "Found " << start_v << " for " << m_v;
  ILA_DLOG("CaseAesEq") << "Found " << start_c << " for " << m_c;

  // relation (state mapping)
  auto relation = RelationMap::New();
  for (auto i = 0; i < u_v->state_num(); i++) {
    auto var_v = u_v->state(i);
    auto var_c = u_c->state(var_v->name().str());
    if (var_c && var_v->sort() == var_c->sort()) {
      ILA_DLOG("CaseAesEq") << var_v << " -> " << var_c;
      relation->add(ExprFuse::Eq(var_v, var_c));
    } else {
      ILA_DLOG("CaseAesEq") << "Cannot find corresponding var for " << var_v;
    }
  }

  // refinement mapping
  auto DefaultRefinement = [=](InstrLvlAbsPtr ila, InstrPtr target_instr) {
    // target
    auto ref = RefinementMap::New();
    // ref->set_tgt(ila); // FIXME
    ref->set_tgt(target_instr);

    // apply
    ref->set_appl(target_instr->decode());

    // flush
    auto has_instr = ExprFuse::BoolConst(false);
    for (auto i = 0; i < ila->instr_num(); i++) {
      has_instr = ExprFuse::Or(has_instr, ila->instr(i)->decode());
    }
    ref->set_flush(ExprFuse::Not(has_instr));

    // ready
    auto instrs = AbsKnob::GetInstrTree(ila);
    auto ready = ExprFuse::BoolConst(true);
    for (auto it = instrs.begin(); it != instrs.end(); it++) {
      auto instr = *it;
      ready = ExprFuse::And(ready, ExprFuse::Not(instr->decode()));
    }
    ref->set_cmpl(ready);

    return ref;
  };

  auto refinement_v = DefaultRefinement(m_v, start_v);
  auto refinement_c = DefaultRefinement(m_c, start_c);

  // invariant TODO

  // check
  auto crr = CompRefRel::New(refinement_v, refinement_c, relation);
  z3::context ctx;
  auto cd = CommDiag(ctx, crr);

  cd.IncCheck(10, 50, 50);

  SetToStdErr(0);
  DebugLog::Disable("CaseAesEq");
  DebugLog::Disable("EqCheck");
  DebugLog::Disable("Verbose-CrrEqCheck");
};

}; // namespace ilang
