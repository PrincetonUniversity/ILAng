#include <cassert>

#include "helpers.hpp"
//#include <ilang/ilang++.h>

ila::ExprRef lConcat(const exp_list& l) {
  assert(l.size() > 1);
  ila::ExprRef ret = *(l.rbegin());
  bool skipLast = true;
  for (auto pos = l.rbegin(); pos != l.rend(); ++pos) {
    if (skipLast) {
      skipLast = false;
      continue;
    }
    ret = Concat(*pos, ret);
  }
  return ret;
}
