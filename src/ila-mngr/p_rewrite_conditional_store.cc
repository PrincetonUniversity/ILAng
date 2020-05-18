/// \file
/// Rewrite the conditional STORE pattern in the AST.

#include <ilang/ila-mngr/pass.h>

#include <ilang/ila-mngr/u_rewriter.h>
#include <ilang/ila/ast_fuse.h>
#include <ilang/ila/expr_fuse.h>
#include <ilang/util/log.h>

namespace ilang {

class FuncObjRewrCondStore : public FuncObjRewrExpr {
public:
  FuncObjRewrCondStore() : FuncObjRewrExpr({}) {}

private:
  ExprPtr RewriteOp(const ExprPtr e) const {
    // override memory ITE
    if (e->is_mem() && GetUidExprOp(e) == AST_UID_EXPR_OP::ITE) {
      return RewriteCondMem(e);
    }
    return FuncObjRewrExpr::RewriteOp(e);
  }

  ExprPtr RewriteCondMem(const ExprPtr e) const {
    ILA_NOT_NULL(e);
    auto cond = get(e->arg(0));
    auto mem1 = get(e->arg(1));
    auto mem2 = get(e->arg(2));

    auto IsStore = [=](const ExprPtr x) {
      ILA_ASSERT(x && x->is_mem()) << "Invariant violation " << x;
      if (x->is_op()) {
        return GetUidExprOp(x) == AST_UID_EXPR_OP::STORE;
      }
      return false;
    };

    // pattern 0 - identical branch
    //  Ex. ITE(x, m, m)
    if (mem1 == mem2) {
      ILA_DLOG("PassRewrCondStore") << "Identical branches - ITE(x, m, m)";
      return mem1;
    }

    // pattern 1 - single store or none
    //  Ex. ITE(x, var, STORE(var, addr, data))
    if (IsStore(mem1) && !mem2->is_op()) {
      if (mem1->arg(0) == mem2) {

        ILA_DLOG("PassRewrCondStore")
            << "Single STORE - ITE(x, m, ST(m, a, d))";

        auto mem1_addr = mem1->arg(1);
        auto mem1_data = mem1->arg(2);
        auto new_data =
            ExprFuse::Ite(cond, mem1_data, ExprFuse::Load(mem2, mem1_addr));
        return ExprFuse::Store(mem2, mem1_addr, new_data);
      }
    }

    if (!mem1->is_op() && IsStore(mem2)) {
      if (mem2->arg(0) == mem1) {

        ILA_DLOG("PassRewrCondStore")
            << "Single STORE - ITE(x, ST(m, a, d), m)";

        auto mem2_addr = mem2->arg(1);
        auto mem2_data = mem2->arg(2);
        auto new_data =
            ExprFuse::Ite(cond, ExprFuse::Load(mem1, mem2_addr), mem2_data);
        return ExprFuse::Store(mem1, mem2_addr, new_data);
      }
    }

    // pattern 2 - identical store target
    //  Ex. ITE(x, STORE(m, a1, d1), STORE(m, a2, d2))
    if (IsStore(mem1) && IsStore(mem2)) {
      if (mem1->arg(0) == mem2->arg(0)) {

        ILA_DLOG("PassRewrCondStore")
            << "Identical STORE dest. - ITE(x, ST(m,a,b), ST(m,c,d))";

        auto new_addr = ExprFuse::Ite(cond, mem1->arg(1), mem2->arg(1));
        auto new_data = ExprFuse::Ite(cond, mem1->arg(2), mem2->arg(2));
        return ExprFuse::Store(mem1->arg(0), new_addr, new_data);
      }
    }

    // pattern 3 - conditional store or none
    //  Ex. ITE(x, var, ITE(y, m1, m2))
    // TODO

    // pattern 4 - multi-store or none
    //  Ex. ITE(x, var, STORE(STORE(var, a1, d1), a2, d2))
    // TODO

    // pattern 5 - cascading store
    //  Ex. ITE(x, STORE(STORE(v, a1, d1), a2, d2), STORE(v, a3, d3))
    // TODO extend the shorter one ... (any benefit?)

    ILA_DLOG("PassRewrCondStore") << "Skip pattern " << mem1 << " " << mem2;

    return FuncObjRewrExpr::RewriteOp(e);
  }

}; // class FuncObjRewrCondStore

bool PassRewriteConditionalStore(const InstrLvlAbsPtr& m) {
  ILA_NOT_NULL(m);

  auto func = FuncObjRewrCondStore();
  auto Rewr = [=, &func](const ExprPtr e) {
    if (e) {
      e->DepthFirstVisitPrePost(func);
      return func.get(e);
    }
    return e;
  };

  return PassRewriteGeneric(m, Rewr);
}

}; // namespace ilang
