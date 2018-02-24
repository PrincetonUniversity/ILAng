/// \file
/// Unit test for unrolling a sequence of instruction.

#include "unit-include/eq_ilas.h"
#include "unit-include/util.h"
#include "verify/unroller.h"
#include <iostream>

namespace ila {

TEST(TestUnroll, InstrSeq) {
  SetToStdErr(1);
  DebugLog::Enable("Unroller.InstrSeq");
  EqIlaGen ila_gen;
  auto m = ila_gen.GetIlaFlat1();

  std::vector<InstrPtr> seq;
  for (size_t i = 0; i != m->instr_num(); i++) {
    seq.push_back(m->instr(i));
  }

  z3::context c;
  Unroller unroller(c);
  auto cstr = unroller.InstrSeq(seq);

#if 0
  z3::solver s(c);
  s.add(cstr);
  std::cout << s;
  std::cout << cstr;
#endif
  //
  SetToStdErr(0);
}

} // namespace ila

