#include <ilang/ila/validate_model.h>

#include "z3++.h"
#include <ilang/ila/ast_fuse.h>
#include <ilang/ila/z3_expr_adapter.h>
#include <ilang/util/log.h>

namespace ilang {
bool CheckDeterminism(const InstrLvlAbsPtr& model_ptr) {
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

bool CheckCompleteness(const InstrLvlAbsPtr& model_ptr) {
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

void CompleteModel(const InstrLvlAbsPtr& model_ptr, DEFAULT_UPDATE_METHOD dum) {
  auto or_decode = ExprFuse::BoolConst(false);
  for (int i = 0; i < model_ptr->instr_num(); i++) {
    or_decode = (ExprFuse::Or(or_decode, model_ptr->instr(i)->decode()));
  }
  {
    auto default_instr = model_ptr->NewInstr("DEFAULT_INSTR");
    default_instr->set_decode(ExprFuse::Not(or_decode));
    z3::context ctx;
    Z3ExprAdapter z3_adapter(ctx);
    if (dum == DEFAULT_UPDATE_METHOD::OLD_VALUE) {
      for (int i = 0; i < model_ptr->state_num(); i++)
        default_instr->set_update(model_ptr->state(i), model_ptr->state(i));
    } else if (dum == DEFAULT_UPDATE_METHOD::NONDET_VALUE) {
      for (int i = 0; i < model_ptr->state_num(); i++) {
        auto state = model_ptr->state(i);
        auto state_sort_uid = GetUidSort(state->sort());
        if (state_sort_uid == AST_UID_SORT::BOOL) {
          auto out_sort = Sort::MakeBoolSort();
          auto func =
              Func::New("default_update_" + state->name().str(), out_sort);
          default_instr->set_update(state, ExprFuse::AppFunc(func));
        } else if (state_sort_uid == AST_UID_SORT::BV) {
          auto out_sort = Sort::MakeBvSort(state->sort()->bit_width());
          auto func =
              Func::New("default_update_" + state->name().str(), out_sort);
          default_instr->set_update(state, ExprFuse::AppFunc(func));
        } else if (state_sort_uid == AST_UID_SORT::MEM) {
          auto out_sort = Sort::MakeMemSort(state->sort()->addr_width(),
                                            state->sort()->data_width());
          auto func =
              Func::New("default_update_" + state->name().str(), out_sort);

          default_instr->set_update(state, ExprFuse::AppFunc(func));
        } else {
          ILA_ERROR << "ILA state type must be one of bool, bitvector, memory.";
        }
      }
    }
  }
}
} // namespace ilang
