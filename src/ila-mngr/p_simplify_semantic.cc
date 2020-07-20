/// \file
/// Simplify instruction state update functions.

#include <ilang/ila-mngr/pass.h>

#include <ilang/target-smt/z3_expr_adapter.h>
#include <ilang/util/log.h>

namespace ilang {

namespace pass {

class FuncObjEqSubtree {
public:
  FuncObjEqSubtree(const ExprPtr& target, const ExprPtr& assump)
      : target_(target), assump_(assump) {}

  ExprPtr get(const ExprPtr& e) const {
    auto pos = rule_.find(e);
    ILA_CHECK(pos != rule_.end()) << "No mapping for " << e;
    return pos->second;
  }

  bool pre(const ExprPtr& e) const {
    auto pos = rule_.find(e);
    return pos != rule_.end(); // if found --> break
  }

  void post(const ExprPtr& e) {
    auto dst = Rewrite(e);
    rule_.insert({e, dst});
  }

private:
  ExprMap rule_;
  ExprPtr target_;
  ExprPtr assump_;
  ExprPtr candidate_ = nullptr;

  ExprPtr Rewrite(const ExprPtr& e) {

    // assump -> (e == target)
    auto CheckEqModAssump = [=](const ExprPtr& x) {
      z3::context ctx;
      z3::solver s(ctx);
      auto gen = Z3ExprAdapter(ctx);

      auto ass = gen.GetExpr(assump_);
      auto tar = gen.GetExpr(target_);
      auto can = gen.GetExpr(x);

      s.add(ass && (can != tar));
      return (s.check() == z3::unsat);
    };

    // skip target itself
    if (e == target_) {
      return candidate_ ? candidate_ : e;
    }

    // check equivalence if not found yet and have a same type
    if (!candidate_ && e->sort() == target_->sort()) {
      if (CheckEqModAssump(e)) {
        candidate_ = e;
      }
    }

    return e;
  }

}; // class FuncObjSimpInstrUpdateRedundant

bool SimplifySemantic(const InstrLvlAbsCnstPtr& m, const int& timeout) {
  ILA_NOT_NULL(m);
  ILA_INFO << "Start pass: semantic simplification";

  // pattern - equivalent sub-tree modulo valid and decode
  auto SimpEqSubtree = [=](const ExprPtr& e, const InstrPtr& i) {
    auto host = i->host();
    ILA_NOT_NULL(host);

    auto valid = host->valid();
    ILA_NOT_NULL(valid);

    auto decode = i->decode();
    ILA_NOT_NULL(decode);

    auto func = FuncObjEqSubtree(e, asthub::And(valid, decode));
    e->DepthFirstVisitPrePost(func);

    auto new_update = func.get(e);
    if (new_update != e) {
      ILA_DLOG("PassSimpSemantic") << "Equivalent sub-tree of " << i;
    }
    return new_update;
  };

  if (timeout > 0) {
    z3::set_param("timeout", timeout);
  }

  auto visiter = [&SimpEqSubtree](const InstrLvlAbsCnstPtr& current) {
    try {
      // only simplify instructions
      for (size_t i = 0; i < current->instr_num(); i++) {
        auto instr = current->instr(i);
        // DO NOT rewrite decode (valid & decode used as the env.)
        // state updates
        for (const auto& state : instr->updated_states()) {
          instr->ForceAddUpdate(state,
                                SimpEqSubtree(instr->update(state), instr));
        }
      }
    } catch (...) {
      ILA_ERROR << "Fail simplify " << current;
    }
  };

  m->DepthFirstVisit(visiter);

  z3::reset_params();

  return true;
}

} // namespace pass

} // namespace ilang
