/// \file
/// Unit tests for exporting and importing ILA portables.

#include <ilang/ilang++.h>
#include <ilang/target-json/interface.h>
#include <ilang/verification/legacy_bmc.h>

#include "unit-include/config.h"
#include "unit-include/util.h"
#include <z3++.h>

#if 0
#include <ilang/verification/abs_knob.h>
#include <ilang/verification/eq_check_crr.h>
#include <ilang/verification/unroller.h>
#endif

namespace ilang {

TEST(TestPortable, AES) {
  SetToStdErr(0);
  // DebugLog::Enable("Portable");

  auto aes_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/aes_v/all";
  auto aes_ila = ImportSynthAbstraction(aes_file, "AES").get();

  auto tmp_aes = ImportSynthAbstraction(aes_file, "AES_DES").get();
  auto ser_aes = IlaSerDesMngr::Serialize(tmp_aes);
  auto des_aes = IlaSerDesMngr::Deserialize(ser_aes);

  EXPECT_EQ(aes_ila->state_num(), des_aes->state_num());
  EXPECT_EQ(aes_ila->instr_num(), des_aes->instr_num());

  // eq check (no child)
  auto state_mapping = ExprFuse::BoolConst(true);
  for (decltype(aes_ila->state_num()) i = 0; i < aes_ila->state_num(); i++) {
    auto var_org = aes_ila->state(i);
    try {
      auto var_des = des_aes->state(var_org->name().str());
      state_mapping =
          ExprFuse::And(state_mapping, ExprFuse::Eq(var_org, var_des));
    } catch (...) {
      ILA_DLOG("Portable") << "Fail automatically matcing state vars";
    }
  }

  for (auto i = 0; i < aes_ila->instr_num(); i++) {
    LegacyBmc bmc;

    auto decode = aes_ila->instr(i)->decode();
    bmc.AddInit(decode);

    EXPECT_EQ(z3::unsat, bmc.Check(aes_ila, 1, des_aes, 1));
  }

#if 0
  auto relation = RelationMap::New();
  for (decltype(aes_ila->state_num()) i = 0; i < aes_ila->state_num(); i++) {
    auto var_org = aes_ila->state(i);
    if (var_org->is_mem())
      continue; // skip XRAM for top level AES
    try {
      auto var_des = des_aes->state(var_org->name().str());
      relation->add(ExprFuse::Eq(var_org, var_des));
    } catch (...) {
      ILA_DLOG("Portable") << "Fail automatically matcing state vars";
    }
  }

  // for (auto i = 0; i != aes_ila->instr_num(); i++) {
  for (auto i = 0; i < 2; i++) {
    auto ref_org = RefinementMap::New();
    {
      auto top = aes_ila;
      ref_org->set_tgt(top->instr(i));
      ref_org->set_appl(top->instr(i)->decode());
      auto instrs = AbsKnob::GetInstrTree(top);
      auto cmpl = ExprFuse::BoolConst(true);
      for (auto it = instrs.begin(); it != instrs.end(); it++) {
        auto instr = *it;
        cmpl = ExprFuse::And(cmpl, ExprFuse::Not(instr->decode()));
      }
      // ref_org->set_cmpl(cmpl);
      ref_org->set_flush(cmpl);
      // ref_org->set_flush(ExprFuse::BoolConst(true)); // TODO
      ref_org->set_step_orig(1);
      ref_org->set_step_appl(1);
      ref_org->add_inv(ExprFuse::Eq(top->state("aes_state"), 0));
    }
    auto ref_des = RefinementMap::New();
    {
      auto top = des_aes;
      ref_des->set_tgt(top->instr(i));
      ref_des->set_appl(top->instr(i)->decode());
      auto instrs = AbsKnob::GetInstrTree(top);
      auto cmpl = ExprFuse::BoolConst(true);
      for (auto it = instrs.begin(); it != instrs.end(); it++) {
        auto instr = *it;
        cmpl = ExprFuse::And(cmpl, ExprFuse::Not(instr->decode()));
      }
      // ref_des->set_cmpl(cmpl);
      ref_des->set_flush(cmpl);
      // ref_des->set_flush(ExprFuse::BoolConst(true));
      ref_des->set_step_orig(1);
      ref_des->set_step_appl(1);
      ref_des->add_inv(ExprFuse::Eq(top->state("aes_state"), 0));
    }

    z3::context c;

    auto crr = CompRefRel::New(ref_org, ref_des, relation);
    auto cd = CommDiag(c, crr);

    EXPECT_TRUE(cd.EqCheck(10));
  }
#endif

  DebugLog::Disable("Portable");
  SetToStdErr(0);
}

TEST(TestPortable, UAES) {
  SetToStdErr(1);
  // DebugLog::Enable("Portable");

  auto aesu_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/aes_v/allu";
  auto org_ila = ImportSynthAbstraction(aesu_file, "AESU").get();

  auto tmp_ila = ImportSynthAbstraction(aesu_file, "AESU_TMP").get();
  auto ser_ila = IlaSerDesMngr::Serialize(tmp_ila);
#if 0 // TODO APP_FUNC SER/DES not yet implemented
  auto des_ila = IlaSerDesMngr::Deserialize(ser_ila);

  EXPECT_EQ(org_ila->state_num(), des_ila->state_num());
  EXPECT_EQ(org_ila->instr_num(), des_ila->instr_num());

  // eq check (no child)
  auto state_mapping = ExprFuse::BoolConst(true);
  for (decltype(org_ila->state_num()) i = 0; i < org_ila->state_num(); i++) {
    auto var_org = org_ila->state(i);
    try {
      auto var_des = des_ila->state(var_org->name().str());
      state_mapping =
          ExprFuse::And(state_mapping, ExprFuse::Eq(var_org, var_des));
    } catch (...) {
      ILA_DLOG("Portable") << "Fail automatically matcing state vars";
    }
  }

  for (auto i = 0; i < org_ila->instr_num(); i++) {
    LegacyBmc bmc;

    auto decode = org_ila->instr(i)->decode();
    bmc.AddInit(decode);

    EXPECT_EQ(z3::unsat, bmc.Check(org_ila, 1, des_ila, 1));
  }
#endif

  DebugLog::Disable("Portable");
  SetToStdErr(0);
}

TEST(TestPortable, RBM) {
  SetToStdErr(1);
  // DebugLog::Enable("Portable");

  auto rbm_portable_file =
      std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/rbm/rbm.json";
  auto rbm_ila = IlaSerDesMngr::DesFromFile(rbm_portable_file);

  auto ser_rbm = IlaSerDesMngr::Serialize(rbm_ila);
  auto des_rbm = IlaSerDesMngr::Deserialize(ser_rbm);

  DebugLog::Disable("Portable");
}

} // namespace ilang
