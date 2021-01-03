/// \file
/// Sanity check on instruction completeness and determinism. Fix if possible.

#include <ilang/ila-mngr/pass.h>

#include <z3++.h>

#include <ilang/ila-mngr/u_abs_knob.h>
#include <ilang/target-smt/z3_expr_adapter.h>
#include <ilang/util/log.h>

namespace ilang {

namespace pass {

z3::context ctx;
z3::solver solver(ctx);
Z3ExprAdapter gen(ctx);

bool CheckDeterminism(const InstrLvlAbsCnstPtr& m) {

  class DetermVisitor {
  public:
    bool pre(const InstrLvlAbsCnstPtr& loc) { return !is_determ; }

    void post(const InstrLvlAbsCnstPtr& loc) {
      if (!is_determ) {
        return;
      }
      auto valid = loc->valid() ? loc->valid() : asthub::BoolConst(true);
      auto instr_num = loc->instr_num();
      for (size_t i = 0; i < instr_num; i++) {
        auto instr_i = loc->instr(i);
        for (size_t j = i + 1; j < instr_num; j++) {
          auto instr_j = loc->instr(j);
          auto non_det = asthub::And(instr_i->decode(), instr_j->decode());
          solver.reset();
          solver.add(gen.GetExpr(valid));
          solver.add(gen.GetExpr(non_det));
          if (solver.check() == z3::sat) {
            ILA_DLOG("PassSanityCheck")
                << "Overlapping: " << instr_i << " & " << instr_j;
            is_determ = false;
            return;
          }
        }
      }
    }

    bool is_determ = true;
  };

  DetermVisitor visitor;
  m->DepthFirstVisitPrePost(visitor);
  return visitor.is_determ;
}

bool SanityCheckAndFix(const InstrLvlAbsPtr& m) {
  ILA_NOT_NULL(m);
  ILA_INFO << "Start pass: sanity check and fix";

  // check determinism across the hierarchy
  auto is_determ = CheckDeterminism(m);
  ILA_WARN_IF(!is_determ) << "Non-deterministic instruction set.";

  // check completeness
  auto acc = asthub::BoolConst(false);
  for (const auto& instr : absknob::GetInstrTree(m)) {
    auto host = instr->host();
    ILA_NOT_NULL(host);
    auto valid = host->valid() ? host->valid() : asthub::BoolConst(true);
    auto decode = asthub::And(valid, instr->decode());
    acc = asthub::Or(acc, decode);
  }
  solver.reset();
  solver.add(!gen.GetExpr(acc));
  auto is_complete = (solver.check() == z3::unsat);
  if (!is_complete) {
    ILA_WARN << "Incomplete instruction set - create default instruction";
    auto clean = true;
    for (const auto& var : absknob::GetVar(acc)) {
      auto is_top_state = m->find_state(var->name());
      auto is_top_input = m->find_input(var->name());
      clean &= (is_top_state || is_top_input);
    }
    if (clean) {
      auto default_instr = m->NewInstr("PASS_ADD_DEFAULT_INSTR");
      default_instr->set_decode(asthub::Not(acc));
    }
    ILA_ERROR_IF(!clean) << "Fail adding default instruction";
    is_complete &= clean;
  }
  return is_determ && is_complete;
}

} // namespace pass

} // namespace ilang
