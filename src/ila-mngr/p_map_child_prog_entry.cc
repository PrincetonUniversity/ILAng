/// \file
/// Map the child program (and its entry point) to the parent instruction

#include <ilang/ila-mngr/pass.h>

#include <ilang/ila-mngr/u_unroller.h>
#include <ilang/util/log.h>

namespace ilang {

namespace pass {

bool MapChildProgEntryPoint(const InstrLvlAbsPtr& m) {
  ILA_NOT_NULL(m);
  ILA_INFO << "Start pass: mapping child program entry";

  // check if a can trigger b
  auto CheckCausality = [=](InstrPtr a, InstrPtr b) {
    z3::context ctx;
    z3::solver s(ctx);
    PathUnroll unroller(ctx);

    // a.decode && a.update && !b.valid -> b.valid && b.decode
    auto path = unroller.PathAssn({a});

    auto decode = unroller.GetZ3Expr(b->decode(), 1);

    ILA_NOT_NULL(b->host());
    auto valid_prev = unroller.GetZ3Expr(b->host()->valid(), 0);
    auto valid_next = unroller.GetZ3Expr(b->host()->valid(), 1);

    s.add(!valid_prev);
    ILA_WARN_IF(s.check() == z3::unsat)
        << "Trivial valid " << b->host()->valid();
    s.reset();

    s.add(!valid_prev && path && decode && valid_next);

    auto res = s.check();
    return (res == z3::sat);
  };

  // for each instructions
  for (size_t i = 0; i < m->instr_num(); i++) {
    auto instr = m->instr(i);

    // for each child-ILAs (child-programs)
    for (size_t j = 0; j < m->child_num(); j++) {
      auto child = m->child(j);

      if (child->instr_seq()) {
        auto entry = child->instr_seq()->root();

        if (entry) { // if root already found

          auto res = CheckCausality(instr, entry);
          if (res && !instr->program()) {
            instr->set_program(child);
          }

        } else { // no root defined

          for (size_t k = 0; k < child->instr_num(); k++) {
            // check if can be triggered
            auto res = CheckCausality(instr, child->instr(k));

            ILA_WARN_IF(res && child->instr_seq()->root())
                << "Multiple entry of " << child << " - " << child->instr(k);

            if (res && !child->instr_seq()->root()) {

              ILA_DLOG("PassMapChildProgEntry")
                  << "Set " << child->instr(k) << " as entry of " << child;
              ILA_DLOG("PassMapChildProgEntry")
                  << "Set " << child << " as child-program of " << instr;

              child->instr_seq()->set_root(child->instr(k));
              if (!instr->program()) {
                instr->set_program(child);
              }
              // break;
            }
          }
        }
      }
    }
  }

  // check if all childs program sequence is defined and has a root
  for (size_t i = 0; i < m->child_num(); i++) {
    auto prog = m->child(i)->instr_seq();
    ILA_WARN_IF(!prog) << "No instr seq found in " << m->child(i);
    ILA_WARN_IF(prog && !prog->root()) << "No root found in " << m->child(i);
  }

  return true;
}

} // namespace pass

} // namespace ilang
