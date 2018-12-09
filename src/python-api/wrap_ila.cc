/// \file
/// Source for wrapping ILA

#include <ilang/python-api/wrap_ila.h>

namespace ilang {
namespace pyapi {

ExprWrap* InstrLvlAbsWrap::NewBvInput(const std::string& name,
                                      const int& bit_width) {
  return new ExprWrap(ptr_->NewBvInput(name, bit_width));
}

ExprWrap* InstrLvlAbsWrap::input(const std::string& name) {
  return new ExprWrap(ptr_->input(name));
}

} // namespace pyapi
} // namespace ilang
