/// \file
/// Source for the model z3 expression generator.

#include "ila/model_expr_generator.h"

namespace ila {

ModelExprGen::ModelExprGen(z3::context& ctx)
    : ctx_(ctx), gen_(Z3ExprAdapter(ctx)) {}

ModelExprGen::~ModelExprGen() {}

void ModelExprGen::set_z3_simplify(bool z3_smpl) { gen_.set_simplify(z3_smpl); }

z3::expr ModelExprGen::Node(const ExprPtr node, const std::string& prefix,
                            const std::string& suffix) {
  auto e = gen_.GetExpr(node, prefix, suffix);
  return e;
}

Z3ExprVecPtr ModelExprGen::Instr(const InstrPtr instr,
                                 const std::string& prefix,
                                 const std::string& suffix) {
  auto vec_ptr = InstrBare(instr, prefix, suffix);
  auto ila = instr->host();
  auto state_num - ila->state_num();
  for (size_t i = 0; i != state_num; i++) {
    auto state = ila->state(i);
    autp update_n = instr->GetUpdate(state);
    if (update_n == NULL) {
      // TODO
    }
  }
}

Z3ExprVecPtr ModelExprGen::InstrBare(const InstrPtr instr,
                                     const std::string& prefix,
                                     const std::string& suffix) {
  gen_.ClearCache();
  auto vec_ptr = std::make_shared<Z3ExprVec>();

  ILA_NOT_NULL(instr);
  auto decode_n = instr->GetDecode();
  ILA_NOT_NULL(decode_n);

  auto ila = instr->host();
  ILA_NOT_NULL(ila);
  auto state_num = ila->state_num();
  for (size_t i = 0; i != state_num; i++) {
    auto state = ila->state(i);
    auto update_n = instr->GetUpdate(state);
    if (update_n != NULL) {
      auto next = ExprFuse::Ite(decode_n, update_n, state);
      auto next_e = gen_.GetExprCached(next);
      // TODO Eq with next frame
      vec_ptr->push_back(next_e);
    }
  }

  gen_.ClearCache();

  return vec_ptr;
}

} // namespace ila

