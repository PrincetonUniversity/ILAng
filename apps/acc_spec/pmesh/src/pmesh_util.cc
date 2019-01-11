/// \file Utility function for constructing the AES model
///  Hongce Zhang (hongcez@princeton.edu)

#include "pmesh_l15_ila.h"
#include <cmath>
#include <string>

ExprRef PMESH_L15::unknown_range(unsigned low, unsigned high) {
  unsigned width = (unsigned)std::ceil(std::log2(high + 1));
  auto val = unknown(width)();
  model.AddInit((val >= low) & (val <= high));
  return val;
}

ExprRef PMESH_L15::unknown_choice(const ExprRef& a, const ExprRef& b) {
  return Ite(unknown(1)() == 1, a, b);
}

ExprRef PMESH_L15::lConcat(const std::vector<ExprRef> & l) {
  assert(l.size() >= 1);
  auto ret = l[0];

  for(auto beg = l.begin()+1; beg != l.end(); ++ beg )
    ret = Concat(ret, *beg);
  return ret;
}


/// build a map relation
ExprRef PMESH_L15::Map(const std::string & name, unsigned retLen, const ExprRef & val) {
  return FuncRef(name, SortRef::BV(retLen), SortRef::BV(val.bit_width()) )( val );
}

unsigned nondet_counter = 0;

FuncRef PMESH_L15::unknown(unsigned width) {
  return FuncRef("unknown" + std::to_string(nondet_counter++),
                 SortRef::BV(width));
}