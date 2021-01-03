/// \file
/// Infer the control flow graph among the child-instructions (instr. seq.)

#include <ilang/ila-mngr/pass.h>

#include <ilang/ila-mngr/u_unroller.h>
#include <ilang/util/log.h>

namespace ilang {

namespace pass {

bool InferChildProgCFG(const InstrLvlAbsPtr& m) {
  ILA_NOT_NULL(m);
  ILA_INFO << "Start pass: infer child program control-flow";

  // iterate through child-ILAs
  for (size_t i = 0; i < m->child_num(); i++) {
    auto child = m->child(i);

    // check if the child program is defined
    if (!child->instr_seq()) {

      // check if a can trigger b
      auto CheckCausality = [=](InstrPtr a, InstrPtr b) {
        z3::context ctx;
        z3::solver s(ctx);
        PathUnroll unroller(ctx);

        // a.decode && a.update -> b.decode
        auto path = unroller.PathAssn({a});
        auto decode = unroller.GetZ3Expr(b->decode(), 1);
        s.add(path && decode);

        auto res = s.check();
        if (res == z3::sat) {
          ILA_DLOG("PassInferChildProgCFG") << a << " -> " << b;
          child->AddSeqTran(a, b, asthub::BoolConst(true));
        }
      };

      // iterate through child-instruction combination
      for (size_t j = 0; j < child->instr_num(); j++) {
        CheckCausality(child->instr(j), child->instr(j));

        for (size_t k = j + 1; k < child->instr_num(); k++) {
          CheckCausality(child->instr(j), child->instr(k));
          CheckCausality(child->instr(k), child->instr(j));
        }
      }
    }

    // check if the CFG is inferred
    ILA_WARN_IF(!child->instr_seq()) << "Fail to infer CFG for " << child;

    // traverse the hierarchy
    InferChildProgCFG(child);
  }

  return true;
}

} // namespace pass

} // namespace ilang
