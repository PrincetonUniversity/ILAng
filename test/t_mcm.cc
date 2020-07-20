/// \file
/// Unit test for class MemoryModel.

#include <ilang/mcm/inter_ila_unroller.h>
#include <ilang/mcm/sc_manual.h>
#include <ilang/mcm/set_op.h>
#include <ilang/mcm/tso_manual.h>

#include "unit-include/mcm_ilas.h"
#include "unit-include/util.h"

#define EXPECT_IN(a, s) EXPECT_TRUE(IN((a), (s)))
#define EXPECT_NOT_IN(a, s) EXPECT_FALSE(IN((a), (s)))

// Test some access things
// Test some axiom functions
namespace ilang {

TEST(TestTraceStep, AccessDeduction) {
  z3::context c;
  z3::solver s(c);
  TraceStep::ZExprVec constraints;

  auto testcase = McmIlaGen();
  auto ila1 = testcase.GetIlaOneInstSimp();
  auto ila1i1 = ila1->instr(0);

  // this is an instruction trace step
  auto ila1i1ts1 = TraceStep(ila1i1, constraints, c, 1);

  EXPECT_EQ(ila1i1ts1.host(), ila1);
  EXPECT_EQ(ila1i1ts1.inst(), ila1i1);
  EXPECT_EQ(ila1i1ts1.type(), TraceStep::TraceStepType::INST_EVT);

  auto ila1i1_read_set = ila1i1ts1.get_inst_read_set();
  EXPECT_IN("pc", ila1i1_read_set);
  EXPECT_IN("r2", ila1i1_read_set);
  EXPECT_IN("r3", ila1i1_read_set);
  EXPECT_NOT_IN("r1", ila1i1_read_set);
  EXPECT_NOT_IN("r0", ila1i1_read_set);

  auto ila1i1_write_set = ila1i1ts1.get_inst_write_set();
  EXPECT_IN("r1", ila1i1_write_set);
  EXPECT_NOT_IN("pc", ila1i1_write_set);
  EXPECT_NOT_IN("r0", ila1i1_write_set);
  EXPECT_NOT_IN("r2", ila1i1_write_set);
  EXPECT_NOT_IN("r3", ila1i1_write_set);

  TraceStep::StateNameSet acclist = {"r0"};
  TraceStep::StateNameSet acclist2 = {"r2", "r3", "r0", "pc"};
  EXPECT_FALSE(ila1i1ts1.Access(AccessType::EITHER, "r0"));
  EXPECT_FALSE(ila1i1ts1.Access(AccessType::WRITE, "r0"));
  EXPECT_FALSE(ila1i1ts1.Access(AccessType::READ, "r0"));
  EXPECT_FALSE(ila1i1ts1.Access(AccessType::EITHER, acclist));
  EXPECT_TRUE(ila1i1ts1.Access(AccessType::READ, "pc"));
  EXPECT_FALSE(ila1i1ts1.Access(AccessType::WRITE, "pc"));
  EXPECT_TRUE(ila1i1ts1.Access(AccessType::READ, acclist2));
  EXPECT_FALSE(ila1i1ts1.Access(AccessType::WRITE, acclist2));
  EXPECT_TRUE(ila1i1ts1.Access(AccessType::EITHER, acclist2));
}

TEST(TestTraceStep, ConvertZ3) {
  z3::context c;
  z3::solver s(c);
  TraceStep::ZExprVec constraints;

  auto testcase = McmIlaGen();
  auto ila1 = testcase.GetIlaOneInstSimp();
  auto ila1i1 = ila1->instr(0);

  auto ila1i1ts1 = TraceStep(ila1i1, constraints, c, 1);
  auto ila1i1ts2 = TraceStep(ila1i1, constraints, c, 2);

  auto update1 = ila1i1ts1.inst()->update("r1");
  auto update2 = ila1i1ts2.inst()->update("r1");

  EXPECT_EQ(update1, update2);
  auto update1z3 = ila1i1ts1.ConvertZ3OnThisStep(update1);
  auto update2z3 = ila1i1ts2.ConvertZ3OnThisStep(update2);
  // std::cout<< update1z3 << std::endl; // (bvadd OneInstSimp_r2_1
  // OneInstSimp_r3_1) std::cout<< update2z3 << std::endl; // (bvadd
  // OneInstSimp_r2_2 OneInstSimp_r3_2)

  s.add(update1z3 != update2z3);
  EXPECT_EQ(z3::sat, s.check());
}

TEST(TestMcm, SingleILAUnroll) {
  z3::context c;
  InterIlaUnroller::IlaPtrVec ila_vec;
  InterIlaUnroller::InstrVec inst_seq_;
  InterIlaUnroller::ProgramTemplate tpl_;
  const std::vector<bool> ordered = {true};

  auto testcase = McmIlaGen();
  auto ila1 = testcase.GetIlaMultiInstLinearSimp();
  ila_vec.push_back(ila1);

  auto instr_1 = ila1->instr(0); // pc-0 r1++;
  auto instr_2 = ila1->instr(1); // pc-1 r1--;
  auto instr_3 = ila1->instr(2); // pc-2 swap r1 r2

  inst_seq_.push_back(instr_1);
  inst_seq_.push_back(instr_2);
  inst_seq_.push_back(instr_3);
  tpl_.push_back(inst_seq_);

  InterIlaUnroller u(c, ila_vec, Tso::TsoModel);

  // check for shared variables

  u.GenSysInitConstraints();
  u.Unroll(tpl_);

  // let's add assertions on it
  u.Push();
  // all (not init) steps sees (beforehand) that, r0 == 0
  u.AddSingleTraceStepProperty(
      asthub::Eq(ila1->state("r0"), asthub::BvConst(0, 8)),
      [](const TraceStep& ts) { return !ts.is_init_tracestep(); });
  u.LinkStates(ordered);
  // all trace step (the pre-value actually)
  // we need to find a way to say something about post-value
  EXPECT_TRUE(u.CheckSat());

  u.Pop();
  u.Push();
  // all (not init) steps sees (beforehand) that, r0 != 0 (False)
  u.AddSingleTraceStepProperty(
      asthub::Not(asthub::Eq(ila1->state("r0"), asthub::BvConst(0, 8))),
      [](const TraceStep& ts) {
        return !ts.is_init_tracestep();
      } // a conjunction on every one
  );
  u.LinkStates(ordered);

  EXPECT_FALSE(u.CheckSat());

  // auto & model = u.GetModel();
  // auto & tsSet = u.DebugAccessAllTraceStepPtrSet();
  auto& cstrSet = u.DebugAccessConstrList();

  // for(auto && tsptr : tsSet) {
  //  std::cout<<tsptr->Print(model)<<std::endl;
  //}
  // std::cout<<"Constraints Dump:"<<std::endl;
  // for(auto && cstr : cstrSet) {
  //  std::cout<< cstr << std::endl;
  //}

  u.Pop();
  u.Push();
  // ts.pos_suffix2 sees that r0 != 0 (False)
  u.AddSingleTraceStepProperty(
      asthub::Not(asthub::Eq(ila1->state("r0"), asthub::BvConst(0, 8))),
      [](const TraceStep& ts) {
        return ts.pos_suffix() == 2;
      } // only on the last one
  );
  u.LinkStates(ordered);

  EXPECT_FALSE(u.CheckSat());

  // test reverse sequence
  // test reverse order?
  // test single ILA memory
}

TEST(TestMcm, SingleILAUnrollOrderedReverse) {
  z3::context c;
  InterIlaUnroller::IlaPtrVec ila_vec;
  InterIlaUnroller::InstrVec inst_seq_;
  InterIlaUnroller::ProgramTemplate tpl_;
  const std::vector<bool> ordered = {true};

  auto testcase = McmIlaGen();
  auto ila1 = testcase.GetIlaMultiInstLinearSimp();
  ila_vec.push_back(ila1);

  auto instr_1 = ila1->instr(0); // pc-0 r1++;
  auto instr_2 = ila1->instr(1); // pc-1 r1--;
  auto instr_3 = ila1->instr(2); // pc-2 swap r1 r2

  inst_seq_.push_back(instr_3);
  inst_seq_.push_back(instr_2);
  inst_seq_.push_back(instr_1);
  tpl_.push_back(inst_seq_);

  InterIlaUnroller u(c, ila_vec, Tso::TsoModel);

  // check for shared variables

  u.GenSysInitConstraints();
  u.Unroll(tpl_);

  // let's add assertions on it
  u.Push();
  // all (not init) steps sees (beforehand) that, r0 == 0
  u.AddSingleTraceStepProperty(
      asthub::Eq(ila1->state("r0"), asthub::BvConst(0, 8)),
      [](const TraceStep& ts) { return !ts.is_init_tracestep(); });
  u.LinkStates(ordered);
  // all trace step (the pre-value actually)
  // we need to find a way to say something about post-value
  EXPECT_TRUE(u.CheckSat());

  u.Pop();
  u.Push();
  // all (not init) steps sees (beforehand) that, r0 != 0 (False)
  u.AddSingleTraceStepProperty(
      asthub::Not(asthub::Eq(ila1->state("r0"), asthub::BvConst(0, 8))),
      [](const TraceStep& ts) {
        return !ts.is_init_tracestep();
      } // a conjunction on every one
  );
  u.LinkStates(ordered);

  EXPECT_FALSE(u.CheckSat());

  u.Pop();
  u.Push();
  // ts.pos_suffix2 sees that r0 != 0 (False)
  u.AddSingleTraceStepProperty(
      asthub::Not(asthub::Eq(ila1->state("r0"), asthub::BvConst(0, 8))),
      [](const TraceStep& ts) {
        return ts.pos_suffix() == 2;
      } // only on the last one
  );
  u.LinkStates(ordered);

  EXPECT_FALSE(u.CheckSat());

  // test reverse order?
  // test single ILA memory
}

TEST(TestMcm, SingleILAUnrollUnorderedReverse) {
  z3::context c;
  InterIlaUnroller::IlaPtrVec ila_vec;
  InterIlaUnroller::InstrVec inst_seq_;
  InterIlaUnroller::ProgramTemplate tpl_;
  const std::vector<bool> ordered = {
      false}; // set the ordered attributes to false

  auto testcase = McmIlaGen();
  auto ila1 = testcase.GetIlaMultiInstLinearSimp();
  ila_vec.push_back(ila1);

  auto instr_1 = ila1->instr(0); // pc-0 r1++;
  auto instr_2 = ila1->instr(1); // pc-1 r1--;
  auto instr_3 = ila1->instr(2); // pc-2 swap r1 r2

  inst_seq_.push_back(instr_3);
  inst_seq_.push_back(instr_2);
  inst_seq_.push_back(instr_1);
  tpl_.push_back(inst_seq_);

  InterIlaUnroller u(c, ila_vec, Tso::TsoModel);

  // check for shared variables

  u.GenSysInitConstraints();
  u.Unroll(tpl_);

  // let's add assertions on it
  u.Push();
  // all (not init) steps sees (beforehand) that, r0 == 0
  u.AddSingleTraceStepProperty(
      asthub::Eq(ila1->state("r0"), asthub::BvConst(0, 8)),
      [](const TraceStep& ts) { return !ts.is_init_tracestep(); });
  u.LinkStates(ordered);
  // all trace step (the pre-value actually)
  // we need to find a way to say something about post-value
  EXPECT_TRUE(u.CheckSat());

  // let's dump the constraints and check if it is as expected
  /*
  auto & tsSet = u.DebugAccessAllTraceStepPtrSet();
  auto & cstrSet = u.DebugAccessConstrList();
  std::cout<<"Constraints Dump:"<<std::endl;
  for(auto && cstr : cstrSet) {
        std::cout<< cstr << std::endl;
  }
  // and also the model
  auto & model = u.GetModel();
  for(auto && tsptr : tsSet) {
  std::cout<<tsptr->Print(model)<<std::endl;
  }*/

  u.Pop();
  u.Push();
  // all (not init) steps sees (beforehand) that, r0 != 0 (False)
  u.AddSingleTraceStepProperty(
      asthub::Not(asthub::Eq(ila1->state("r0"), asthub::BvConst(0, 8))),
      [](const TraceStep& ts) {
        return !ts.is_init_tracestep();
      } // a conjunction on every one
  );
  u.LinkStates(ordered);

  EXPECT_FALSE(u.CheckSat());

  u.Pop();
  u.Push();
  // ts.pos_suffix2 sees that r0 != 0 (False)
  u.AddSingleTraceStepProperty(
      asthub::Not(asthub::Eq(ila1->state("r0"), asthub::BvConst(0, 8))),
      [](const TraceStep& ts) {
        return ts.pos_suffix() == 2;
      } // only on the last one
  );
  u.LinkStates(ordered);

  EXPECT_FALSE(u.CheckSat());

  // test single ILA memory
  // test mem load/store
}

// this seems okay
TEST(TestMcm, SingleIlaMcm) { // multi inst - non linear
  z3::context c;
  InterIlaUnroller::IlaPtrVec ila_vec;
  InterIlaUnroller::InstrVec inst_seq_;
  InterIlaUnroller::ProgramTemplate tpl_;
  const std::vector<bool> ordered = {
      false}; // set the ordered attributes to false

  auto testcase = McmIlaGen();
  auto ila1 = testcase.GetIlaOneInstPcDecode("IlaInstPcDecode", true);
  ila_vec.push_back(ila1);

  auto addi = ila1->instr("ADDI");   // pc-0 r1++;
  auto addr = ila1->instr("ADDR");   // pc-1 r1--;
  auto load = ila1->instr("LOAD");   // pc-2 swap r1 r2
  auto store = ila1->instr("STORE"); // pc-2 swap r1 r2

  inst_seq_.push_back(addi);
  inst_seq_.push_back(addr);
  inst_seq_.push_back(load);
  inst_seq_.push_back(store);
  tpl_.push_back(inst_seq_);

  InterIlaUnroller u(c, ila_vec, Tso::TsoModel);

  // check for shared variables

  u.GenSysInitConstraints();
  u.Unroll(tpl_);

  // let's add assertions on it
  u.Push();
  // give me a trace with 3 registers set
  u.AddSingleTraceStepProperty(
      asthub::And(
          asthub::And(asthub::Eq(ila1->state("r0"), asthub::BvConst(10, 8)),
                      asthub::Eq(ila1->state("r1"), asthub::BvConst(2, 8))),
          asthub::Eq(ila1->state("r2"), asthub::BvConst(10, 8))),
      [](const TraceStep& ts) { return ts.inst()->name().str() == "STORE"; });
  u.LinkStates(ordered); // not ordered
  // all trace step (the pre-value actually)
  // we need to find a way to say something about post-value
  // DebugLog::Enable("InterIlaUnroller.CheckSat");
  EXPECT_TRUE(u.CheckSat());

  // let's dump the constraints and check if it is as expected
  /*
  auto & tsSet = u.DebugAccessAllTraceStepPtrSet();
  auto & cstrSet = u.DebugAccessConstrList();
  std::cout<<"Constraints Dump:"<<std::endl;
  unsigned idx = 0;
  for(auto && cstr : cstrSet) {
        std::cout<< "p"<< (++idx)  <<":" << cstr << std::endl;
  }
  // and also the model
  auto & model = u.GetModel();
  for(auto && tsptr : tsSet) {
  std::cout<<tsptr->Print(model)<<std::endl;
  }
        */

  u.Pop();
}

void TestTsoSb(InstrLvlAbsPtr& T1, InstrLvlAbsPtr& T2) {
  InterIlaUnroller::IlaPtrVec ila_vec;
  InterIlaUnroller::ProgramTemplate tpl_;
  z3::context c;
  const std::vector<bool> ordered = {
      true, true}; // set the ordered attributes to false

  ila_vec.push_back(T1);
  ila_vec.push_back(T2);
  tpl_.push_back({T1->instr(0), T1->instr(1)});
  tpl_.push_back({T2->instr(0), T2->instr(1)});

  InterIlaUnroller u(c, ila_vec, Tso::TsoModel);

  // check for shared variables

  u.GenSysInitConstraints();
  u.Unroll(tpl_);

  // Case 1
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T1->state("r1"), asthub::BvConst(0, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(0, 8))));

  u.LinkStates(ordered);
  EXPECT_TRUE(u.CheckSat());
  /*
  { // dump the model
      auto & tsSet = u.DebugAccessAllTraceStepPtrSet();
      auto & cstrSet = u.DebugAccessConstrList();
      std::cout<<"Constraints Dump:"<<std::endl;
      unsigned idx = 0;
      for(auto && cstr : cstrSet) {
      std::cout<< "p"<< (++idx)  <<":" << cstr << std::endl;
      }
      // and also the model
      auto & model = u.GetModel();
      for(auto && tsptr : tsSet) {
      std::cout<<tsptr->Print(model)<<std::endl;
      }
  }*/

  u.Pop();

  // Case 2
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T1->state("r1"), asthub::BvConst(1, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(0, 8))));

  u.LinkStates(ordered);
  EXPECT_TRUE(u.CheckSat());
  u.Pop();

  // Case 3
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T1->state("r1"), asthub::BvConst(0, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(1, 8))));

  u.LinkStates(ordered);
  EXPECT_TRUE(u.CheckSat());
  u.Pop();

  // Case 4
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T1->state("r1"), asthub::BvConst(1, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(1, 8))));

  u.LinkStates(ordered);
  EXPECT_TRUE(u.CheckSat());
  u.Pop();
}

void TestTsoMp(InstrLvlAbsPtr& T1, InstrLvlAbsPtr& T2) {
  InterIlaUnroller::IlaPtrVec ila_vec;
  InterIlaUnroller::ProgramTemplate tpl_;
  z3::context c;
  const std::vector<bool> ordered = {
      true, true}; // set the ordered attributes to false

  ila_vec.push_back(T1);
  ila_vec.push_back(T2);
  tpl_.push_back({T1->instr(0), T1->instr(1)});
  tpl_.push_back({T2->instr(0), T2->instr(1)});

  InterIlaUnroller u(c, ila_vec, Tso::TsoModel);

  // check for shared variables

  u.GenSysInitConstraints();
  u.Unroll(tpl_);

  // Case 1
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T2->state("r1"), asthub::BvConst(0, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(0, 8))));

  u.LinkStates(ordered);
  EXPECT_TRUE(u.CheckSat());
  /*
  { // dump the model
      auto & tsSet = u.DebugAccessAllTraceStepPtrSet();
      auto & cstrSet = u.DebugAccessConstrList();
      std::cout<<"Constraints Dump:"<<std::endl;
      unsigned idx = 0;
      for(auto && cstr : cstrSet) {
      std::cout<< "p"<< (++idx)  <<":" << cstr << std::endl;
      }
      // and also the model
      auto & model = u.GetModel();
      for(auto && tsptr : tsSet) {
      std::cout<<tsptr->Print(model)<<std::endl;
      }
  }*/

  u.Pop();

  // Case 2
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T2->state("r1"), asthub::BvConst(1, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(0, 8))));

  u.LinkStates(ordered);
  EXPECT_FALSE(u.CheckSat());
  u.Pop();

  // Case 3
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T2->state("r1"), asthub::BvConst(0, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(1, 8))));

  u.LinkStates(ordered);
  EXPECT_TRUE(u.CheckSat());
  u.Pop();

  // Case 4
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T2->state("r1"), asthub::BvConst(1, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(1, 8))));

  u.LinkStates(ordered);
  EXPECT_TRUE(u.CheckSat());
  u.Pop();
}

void TestScSb(InstrLvlAbsPtr& T1, InstrLvlAbsPtr& T2) {
  InterIlaUnroller::IlaPtrVec ila_vec;
  InterIlaUnroller::ProgramTemplate tpl_;
  z3::context c;
  const std::vector<bool> ordered = {
      true, true}; // set the ordered attributes to false

  ila_vec.push_back(T1);
  ila_vec.push_back(T2);
  tpl_.push_back({T1->instr(0), T1->instr(1)});
  tpl_.push_back({T2->instr(0), T2->instr(1)});

  InterIlaUnroller u(c, ila_vec, Sc::ScModel);

  // check for shared variables

  u.GenSysInitConstraints();
  u.Unroll(tpl_);

  // Case 1
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T1->state("r1"), asthub::BvConst(0, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(0, 8))));

  u.LinkStates(ordered);
  EXPECT_FALSE(u.CheckSat());

  u.Pop();

  // Case 2
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T1->state("r1"), asthub::BvConst(1, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(0, 8))));

  u.LinkStates(ordered);

  // DebugLog::Enable("InterIlaUnroller.CheckSat");
  EXPECT_TRUE(u.CheckSat());

  /*
  { // dump the model
      auto & tsSet = u.DebugAccessAllTraceStepPtrSet();
      auto & cstrSet = u.DebugAccessConstrList();
      std::cout<<"Constraints Dump:"<<std::endl;
      unsigned idx = 0;
      for(auto && cstr : cstrSet) {
      std::cout<< "p"<< (++idx)  <<":" << cstr << std::endl;
      }
      /// and also the model
      //auto & model = u.GetModel();
      //for(auto && tsptr : tsSet) {
      //std::cout<<tsptr->Print(model)<<std::endl;
      //}
  }*/

  u.Pop();

  // Case 3
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T1->state("r1"), asthub::BvConst(0, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(1, 8))));

  u.LinkStates(ordered);
  EXPECT_TRUE(u.CheckSat());
  u.Pop();

  // Case 4
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T1->state("r1"), asthub::BvConst(1, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(1, 8))));

  u.LinkStates(ordered);
  EXPECT_TRUE(u.CheckSat());
  u.Pop();
}

void TestScMp(InstrLvlAbsPtr& T1, InstrLvlAbsPtr& T2) {
  InterIlaUnroller::IlaPtrVec ila_vec;
  InterIlaUnroller::ProgramTemplate tpl_;
  z3::context c;
  const std::vector<bool> ordered = {
      true, true}; // set the ordered attributes to false

  ila_vec.push_back(T1);
  ila_vec.push_back(T2);
  tpl_.push_back({T1->instr(0), T1->instr(1)});
  tpl_.push_back({T2->instr(0), T2->instr(1)});

  InterIlaUnroller u(c, ila_vec, Sc::ScModel);

  // check for shared variables

  u.GenSysInitConstraints();
  u.Unroll(tpl_);

  // Case 1
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T2->state("r1"), asthub::BvConst(0, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(0, 8))));

  u.LinkStates(ordered);
  EXPECT_TRUE(u.CheckSat());

  u.Pop();

  // Case 2
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T2->state("r1"), asthub::BvConst(1, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(0, 8))));

  u.LinkStates(ordered);
  EXPECT_FALSE(u.CheckSat());

  u.Pop();

  // Case 3
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T2->state("r1"), asthub::BvConst(0, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(1, 8))));

  u.LinkStates(ordered);
  EXPECT_TRUE(u.CheckSat());
  u.Pop();

  // Case 4
  u.Push();
  u.SetFinalProperty(
      asthub::And(asthub::Eq(T2->state("r1"), asthub::BvConst(1, 8)),
                  asthub::Eq(T2->state("r2"), asthub::BvConst(1, 8))));

  u.LinkStates(ordered);
  EXPECT_TRUE(u.CheckSat());
  u.Pop();
}

// this is to test MCMs.
TEST(TestMcm, RegBasedMcmSc) { //
  {
    InstrLvlAbsPtr T1;
    InstrLvlAbsPtr T2;
    auto testcase = McmIlaGen();
    testcase.GetLitmusSbReg(T1, T2);
    TestScSb(T1, T2);
  }

  {
    InstrLvlAbsPtr T1;
    InstrLvlAbsPtr T2;
    auto testcase = McmIlaGen();
    testcase.GetLitmusMpReg(T1, T2);
    TestScMp(T1, T2);
  }
}

TEST(TestMcm, RegBasedMcmTso) { //
  {
    InstrLvlAbsPtr T1;
    InstrLvlAbsPtr T2;
    auto testcase = McmIlaGen();
    testcase.GetLitmusSbReg(T1, T2);
    TestTsoSb(T1, T2);
  }

  {
    InstrLvlAbsPtr T1;
    InstrLvlAbsPtr T2;
    auto testcase = McmIlaGen();
    testcase.GetLitmusMpReg(T1, T2);
    TestTsoMp(T1, T2);
  }
}

TEST(TestMcm, McmSc) { //
  {
    InstrLvlAbsPtr T1;
    InstrLvlAbsPtr T2;
    auto testcase = McmIlaGen();
    testcase.GetLitmusSbMem(T1, T2);
    TestScSb(T1, T2);
  }

  {
    InstrLvlAbsPtr T1;
    InstrLvlAbsPtr T2;
    auto testcase = McmIlaGen();
    testcase.GetLitmusMpMem(T1, T2);
    TestScMp(T1, T2);
  }
}

TEST(TestMcm, McmTso) { //
  {
    InstrLvlAbsPtr T1;
    InstrLvlAbsPtr T2;
    auto testcase = McmIlaGen();
    testcase.GetLitmusSbMem(T1, T2);
    TestTsoSb(T1, T2);
  }
  {
    InstrLvlAbsPtr T1;
    InstrLvlAbsPtr T2;
    auto testcase = McmIlaGen();
    testcase.GetLitmusMpMem(T1, T2);
    TestTsoMp(T1, T2);
  }
}

/*

    { // dump the model
        auto & tsSet = u.DebugAccessAllTraceStepPtrSet();
        auto & cstrSet = u.DebugAccessConstrList();
        std::cout<<"Constraints Dump:"<<std::endl;
        unsigned idx = 0;
        for(auto && cstr : cstrSet) {
        std::cout<< "p"<< (++idx)  <<":" << cstr << std::endl;
        }
        // and also the model
        auto & model = u.GetModel();
        for(auto && tsptr : tsSet) {
        std::cout<<tsptr->Print(model)<<std::endl;
        }
    }
*/

} // namespace ilang
