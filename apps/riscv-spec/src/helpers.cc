
#include "helpers.hpp"
#include <cassert>

ilang::ExprRef lConcat(const exp_list& l) {
  assert(l.size() > 1);
  ilang::ExprRef ret = *(l.rbegin());
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
