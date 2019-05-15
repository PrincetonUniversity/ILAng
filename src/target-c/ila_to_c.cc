/// \file
/// The implementation of the ILA to C target converter.

#include <ilang/target-c/ila_to_c.h>

#include <ilang/util/log.h>

namespace ilang {

typedef size_t ID_t;

I2CMngr::I2CMngr() {}

I2CMngr::~I2CMngr() {}

I2CMngrPtr I2CMngr::New() { return std::make_shared<I2CMngr>(); }

void I2CMngr::ConvertConst(const ExprPtr& expr) const {
  //
  return;
}

}; // namespace ilang
