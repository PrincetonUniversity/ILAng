/// \file
/// Pass template for rewriting AST in an ILA.

#include <ilang/ila-mngr/pass.h>

#include <ilang/util/log.h>

namespace ilang {

bool PassRewriteGeneric(const InstrLvlAbsPtr& m,
                        std::function<ExprPtr(const ExprPtr)> Rewr) {
  ILA_NOT_NULL(m);

  // rewrite valid
  auto new_valid = Rewr(m->valid());
  if (new_valid) {
    m->ForceSetValid(new_valid);
  }

  // rewrite fetch
  auto new_fetch = Rewr(m->fetch());
  if (new_fetch) {
    m->ForceSetFetch(new_fetch);
  }

  // TODO rewrite init

  // for each instruction
  for (size_t i = 0; i < m->instr_num(); i++) {
    auto instr = m->instr(i);

    // rewrite decode
    auto new_decode = Rewr(instr->decode());
    if (new_decode) {
      instr->ForceSetDecode(new_decode);
    }

    // rewrite updates
    for (size_t s = 0; s < m->state_num(); s++) {
      auto new_update = Rewr(instr->update(m->state(s)));
      if (new_update) {
        instr->ForceAddUpdate(m->state(s)->name().str(), new_update);
      }
    }
  }

  // traverse the ILA hierarchy
  for (size_t c = 0; c < m->child_num(); c++) {
    PassRewriteGeneric(m->child(c), Rewr);
  }

  return true;
}

}; // namespace ilang
