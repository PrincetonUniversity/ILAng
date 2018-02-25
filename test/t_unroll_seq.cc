/// \file
/// Unit test for unrolling a sequence of instruction.

#include "unit-include/eq_ilas.h"
#include "unit-include/util.h"
#include "verify/unroller.h"
#include <iostream>

namespace ila {

TEST(TestUnroll, InstrSeqFlat) {
  SetToStdErr(0);
  DebugLog::Enable("Unroller.InstrSeq");
  EqIlaGen ila_gen;
  auto m = ila_gen.GetIlaFlat1();

  std::vector<InstrPtr> seq;
  for (size_t i = 0; i != m->instr_num(); i++) {
    seq.push_back(m->instr(i));
  }

  z3::context c;
  Unroller* unroller = new ListUnroll(c, seq);
  auto cstr = unroller->InstrSeq(seq);

  // std::cout << cstr << std::endl;
  SetToStdErr(0);
}

TEST(TestUnroll, InsteSeqFlatSimpleProp) {
  SetToStdErr(0);
  DebugLog::Enable("Unroller.InstrSeq");
  //
  SetToStdErr(0);
}

} // namespace ila

