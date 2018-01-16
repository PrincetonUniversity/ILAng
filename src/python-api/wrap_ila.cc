/// \file
/// Source for wrapping ILA

#include "python-api/wrap_ila.h"

namespace ila {
namespace pyapi {

ExprWrap* InstrLvlAbsWrap::NewBvInput(const std::string& name,
                                      const int& bit_width) {
  return new ExprWrap(ptr_->NewBvInput(name, bit_width));
}

ExprWrap* InstrLvlAbsWrap::input(const std::string& name) {
  return new ExprWrap(ptr_->input(name));
}

} // namespace pyapi
} // namespace ila
