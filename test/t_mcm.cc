/// \file
/// Unit test for class MemoryModel.

#include "mcm/memory_model.h"
#include "unit-include/util.h"
#include "unit-include/mcm_ilas.h"

#define EXPECT_IN(a,s) EXPECT_TRUE( IN((a),(s)) )
#define EXPECT_NOT_IN(a,s) EXPECT_FALSE( IN((a),(s)) )

// Test some access things
// Test some axiom functions
namespace ila {

TEST_F(TestTraceStep, AccessDeduction) {
  z3::context c;
  z3::solver s(c);
  auto z3adapterptr = std::make_shared<Z3ExprAdapter>(c);
  TraceStep::ZExprVec constraints;

  auto testcase = McmIlaGen();
  auto ila1 = testcase.GetIlaOneInstSimp();
  auto ila1i1 = il1.instr(0);

  auto ila1i1ts1 = TraceStep(ila1i1, constraints, c, 1, z3adapterptr);

  EXPECT_EQ(ila1i1ts1.host() , ila1);
  EXPECT_EQ(ila1i1ts1.inst() , ilai1);
  EXPECT_EQ(ila1i1ts1.type() , TraceStep::TraceStepType::INST_EVT);

  auto ila1i1_read_set = ila1i1ts1.get_inst_read_set();
  EXPECT_IN("pc", ila1i1_read_set);
  EXPECT_IN("r2", ila1i1_read_set);
  EXPECT_IN("r3", ila1i1_read_set);
  EXPECT_NOT_IN("r1", ila1i1_read_set);
  EXPECT_NOT_IN("r0", ila1i1_read_set);

  auto ila1i1_write_set = ila1i1ts1.get_inst_write_set();
  EXPECT_IN("r1", ila1i1_read_set);
  EXPECT_NOT_IN("pc", ila1i1_read_set);
  EXPECT_NOT_IN("r0", ila1i1_read_set);
  EXPECT_NOT_IN("r2", ila1i1_read_set);
  EXPECT_NOT_IN("r3", ila1i1_read_set);

  TraceStep::StateNameSet acclist = {"r0"}
  TraceStep::StateNameSet acclist2 = {"r2","r3","r0", "pc"}
  EXPECT_FALSE( ila1i1ts1.access(TraceStep::AccessType::EITHER, "r0") );
  EXPECT_FALSE( ila1i1ts1.access(TraceStep::AccessType::WRITE,  "r0") );
  EXPECT_FALSE( ila1i1ts1.access(TraceStep::AccessType::READ,   "r0") );
  EXPECT_FALSE( ila1i1ts1.access(TraceStep::AccessType::EITHER, acclist) );
  EXPECT_TRUE ( ila1i1ts1.access(TraceStep::AccessType::READ, "pc") );
  EXPECT_FALSE( ila1i1ts1.access(TraceStep::AccessType::WRITE, "pc") );
  EXPECT_TRUE ( ila1i1ts1.access(TraceStep::AccessType::READ, acclist2) );
  EXPECT_TRUE ( ila1i1ts1.access(TraceStep::AccessType::WRITE, acclist2) );
  EXPECT_TRUE ( ila1i1ts1.access(TraceStep::AccessType::EITHER, acclist2) );
}

TEST_F(TestTraceStep, ConvertZ3) {
  z3::context c;
  z3::solver s(c);
  auto z3adapterptr = std::make_shared<Z3ExprAdapter>(c);
  TraceStep::ZExprVec constraints;

  auto testcase = McmIlaGen();
  auto ila1 = testcase.GetIlaOneInstSimp();
  auto ila1i1 = il1.instr(0);

  auto ila1i1ts1 = TraceStep(ila1i1, constraints, c, 1, z3adapterptr);
  auto ila1i1ts2 = TraceStep(ila1i1, constraints, c, 2, z3adapterptr);
  

}

} // namespace ila