/// \file
/// Pass template for rewriting AST in an ILA.

#include <ilang/ila-mngr/pass.h>

#include <ilang/util/log.h>

namespace ilang {

namespace pass {

bool RewriteGeneric(const InstrLvlAbsPtr& m,
                    std::function<ExprPtr(const ExprPtr)> Rewr) {
  ILA_NOT_NULL(m);

  // rewrite valid
  if (m->valid()) {
    m->ForceSetValid(Rewr(m->valid()));
  }

  // rewrite fetch
  if (m->fetch()) {
    m->ForceSetFetch(Rewr(m->fetch()));
  }

  // TODO rewrite init

  // for each instruction
  for (size_t i = 0; i < m->instr_num(); i++) {
    auto instr = m->instr(i);

    // rewrite decode
    ILA_NOT_NULL(instr->decode());
    instr->ForceSetDecode(Rewr(instr->decode()));

    // rewrite updates
    for (const auto& state : instr->updated_states()) {
      instr->ForceAddUpdate(state, Rewr(instr->update(state)));
    }
  }

  // traverse the ILA hierarchy
  for (size_t c = 0; c < m->child_num(); c++) {
    RewriteGeneric(m->child(c), Rewr);
  }

  return true;
}

} // namespace pass

} // namespace ilang
