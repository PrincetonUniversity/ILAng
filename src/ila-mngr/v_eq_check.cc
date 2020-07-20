/// \file
/// The implementation for checking the equivalence of two ILAs.

#include <ilang/ila-mngr/v_eq_check.h>

#include <ilang/ila-mngr/v_eq_check_refinement.h>
#include <ilang/ila/ast_hub.h>
#include <ilang/util/log.h>

namespace ilang {

bool CheckEqSameMicroArch(const InstrLvlAbsPtr& a, const InstrLvlAbsPtr& b,
                          bool update) {
  auto ma = a.get();
  auto mb = b.get();

  ILA_NOT_NULL(ma);
  ILA_NOT_NULL(mb);

  if (ma->state_num() != mb->state_num()) {
    ILA_INFO << "#state mismatch";
    return false;
  }

  if (ma->input_num() != mb->input_num()) {
    ILA_INFO << "#input mismatch";
    return false;
  }

  if (ma->instr_num() != mb->instr_num()) {
    ILA_INFO << "#instruction mismatch";
    return false;
  }

  auto relation = RelationMap::New();

  for (decltype(ma->input_num()) i = 0; i != ma->input_num(); i++) {
    auto inp_a = ma->input(i);
    auto inp_b = mb->input(inp_a->name().str());
    if (inp_b && (inp_a->sort() == inp_b->sort())) {
      relation->add(asthub::Eq(inp_a, inp_b));
    } else {
      ILA_INFO << "No corresponding input " << inp_a << " found";
      return false;
    }
  }

  for (decltype(ma->state_num()) i = 0; i != ma->state_num(); i++) {
    auto var_a = ma->state(i);
    auto var_b = mb->state(var_a->name().str());
    if (var_b && (var_a->sort() == var_b->sort())) {
      relation->add(asthub::Eq(var_a, var_b));
    } else {
      ILA_INFO << "No corresponding state var " << var_a << " found";
      return false;
    }
  }

  // TODO
#if 0 
  auto refinement_a = nullptr;
  auto refinement_b = nullptr;

  auto GetFlatRefinement = [=](InstrLvlAbsPtr m, InstrPtr instr) {
    // target
    auto ref = RefinementMap::New();
    ref->set_tgt(instr);

    // apply
    ref->set_appl(instr->decode());

    // flush
    auto has_instr = asthub::BoolConst(false);
    for (unsigned i = 0; i < m->instr_num(); i++) {
      has_instr = asthub::Or(has_instr, m->instr(i)->decode());
    }
    ref->set_flush(asthub::Not(has_instr));

    // ready
    // fix bound 1?
  };
#endif

  if (ma->child_num() != mb->child_num()) {
    return false;
  }

  return true;
}

}; // namespace ilang

