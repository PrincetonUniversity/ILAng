/// \file
/// Source for unrolling ILA execution.

#include "verify/unroller.h"
#include "util/log.h"

namespace ila {

Unroller::Unroller(z3::context& ctx) : ctx_(ctx), gen_(Z3ExprAdapter(ctx)) {}

Unroller::~Unroller() {}

z3::expr Unroller::InstrUpdCmpl(const InstrPtr instr, const std::string& prev,
                                const std::string& next) {
  ILA_NOT_NULL(instr);
  auto ila = instr->host(); // can only unroll Instr with host ILA
  ILA_NOT_NULL(ila);

  // update function accumulator
  auto upd_acc = ctx().bool_val(true);
  // enumerate through all states in the ILA.
  auto state_num = ila->state_num();
  for (size_t i = 0; i != state_num; i++) {
    auto var_i = ila->state(i);           // state var
    auto upd_i = instr->GetUpdate(var_i); // next state function

    if (upd_i) { // update function has been defined
      auto next_var = gen_.GetExpr(var_i, next); // next state var
      auto next_upd = gen_.GetExpr(upd_i, prev); // next state function
      auto connect = (next_var == next_upd);     // assert same
      upd_acc = (connect && upd_acc);            // add to the accumulator
    } else { // update function not yet defined
      ILA_DLOG("Unroller") << instr << ": " << var_i << " update not defined.";
    }
  }

  upd_acc = upd_acc.simplify();
  return upd_acc;
}

} // namespace ila

