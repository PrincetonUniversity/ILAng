/// \file
/// Simplify Expr node syntactically (structurally).

#include <ilang/ila-mngr/pass.h>

#include <ilang/ila/hash_ast.h>
#include <ilang/util/log.h>

namespace ilang {

namespace pass {

bool SimplifySyntactic(const InstrLvlAbsCnstPtr& m) {
  ILA_NOT_NULL(m);

  auto mngr = ExprMngr::New();
  auto visiter = [&mngr](const InstrLvlAbsCnstPtr& current) {
    try {
      // only simplify instructions
      for (size_t i = 0; i < current->instr_num(); i++) {
        auto instr = current->instr(i);
        // decode
        ILA_NOT_NULL(instr->decode());
        instr->ForceSetDecode(mngr->GetRep(instr->decode()));
        // state updates
        auto updated_states = instr->updated_states();
        for (const auto& state : updated_states) {
          instr->ForceAddUpdate(state, mngr->GetRep(instr->update(state)));
        }
      }
    } catch (...) {
      ILA_ERROR << "Fail simplify " << current;
    }
  };

  m->DepthFirstVisit(visiter);
  return true;
}

} // namespace pass

} // namespace ilang
