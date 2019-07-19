#include "z3++.h"
#include <ilang/util/log.h>
#include <ilang/util/validate_model.h>

namespace ilang {
bool deterministic_check(const InstrLvlAbsPtr& model_ptr) {
  if (model_ptr->instr_num() < 2) {
    return true;
  }
  for (int i = 0; i < model_ptr->instr_num(); i++) {
    for (int j = i + 1; j < model_ptr->instr_num(); j++) {
      auto decode_0 = model_ptr->instr(i)->decode();
      auto decode_1 = model_ptr->instr(j)->decode();
      z3::context ctx;
      z3::solver sol(ctx);
      Z3ExprAdapter z3_adapter(ctx);
      auto z3_decode_0 = z3_adapter.GetExpr(decode_0);
      auto z3_decode_1 = z3_adapter.GetExpr(decode_1);
      sol.add(z3_decode_0 && z3_decode_1);
      if (sol.check() == z3::sat) {
        auto model = sol.get_model();
        ILA_ERROR << "Instr-" << model_ptr->instr(i)->name() << " and "
                  << "Instr-" << model_ptr->instr(j)->name() << " both "
                  << "decode true with the same input and state:";
        ILA_ERROR << model;
        return false;
      }
    }
  }
  return true;
}

bool complete_check(const InstrLvlAbsPtr& model_ptr) {
  z3::context ctx;
  z3::solver sol(ctx);
  Z3ExprAdapter z3_adapter(ctx);
  if (model_ptr->valid() != NULL) {
    auto z3_valid = z3_adapter.GetExpr(model_ptr->valid());
    sol.add(z3_valid);
  }
  z3::expr or_decode = ctx.bool_val(false);
  for (int i = 0; i < model_ptr->instr_num(); i++) {
    auto instr = model_ptr->instr(i);
    auto decode = instr->decode();
    or_decode = or_decode || z3_adapter.GetExpr(decode);
  }
  sol.add(!or_decode);
  if (sol.check() == z3::sat) {
    auto model = sol.get_model();
    ILA_ERROR << "ILA is not complete. There's no next-state function when: "
              << model;
    return false;
  }
  return true;
}
}
