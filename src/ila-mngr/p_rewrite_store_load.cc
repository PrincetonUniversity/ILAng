/// \file
/// Rewrite the STORE-LOAD pattern in the AST.

#include <ilang/ila-mngr/pass.h>

#include <ilang/ila-mngr/u_rewriter.h>
#include <ilang/ila/ast_hub.h>
#include <ilang/util/log.h>

namespace ilang {

namespace pass {

class FuncObjRewrStoreLoad : public FuncObjRewrExpr {
public:
  FuncObjRewrStoreLoad() : FuncObjRewrExpr({}) {}

private:
  ExprPtr RewriteOp(const ExprPtr e) const {
    // override LOAD op; use default otherwise
    if (asthub::GetUidExprOp(e) == AstUidExprOp::kLoad) {
      return RewriteLoad(e);
    }
    return FuncObjRewrExpr::RewriteOp(e);
  }

  ExprPtr RewriteLoad(const ExprPtr& e) const {
    auto mem = get(e->arg(0));
    if (mem->is_var() || mem->is_const()) {
      return e;
    }

    auto IsStore = [=](const ExprPtr& x) {
      ILA_ASSERT(x && x->is_mem()) << "Invariant violation " << x;
      if (x->is_op()) {
        return asthub::GetUidExprOp(x) == AstUidExprOp::kStore;
      }
      return false;
    };

    // pattern 0 - loading from single STORE
    //  Ex. LOAD(STORE(var, a1, d1), a2)
    //  =>  ITE(a1 == a2, d1, LOAD(var, a2))
    if (IsStore(mem) && !(mem->arg(0)->is_op())) {
      ILA_DLOG("PassRewrStoreLoad") << "Single STORE - LD(ST(m, a, b), c)";
      auto addr_load = get(e->arg(1));
      auto addr_store = mem->arg(1);
      auto cond = asthub::Eq(addr_load, addr_store);
      auto data_load = asthub::Load(mem->arg(0), addr_load);
      auto data_store = mem->arg(2);
      return asthub::Ite(cond, data_store, data_load);
    }

    // pattern 1 - loading from multi-store
    //  Ex. LOAD(STORE(STORE(var, a1, d1), a2, d2), a3)
    //  =>  ITE(addr == addr'',
    //          data'',
    //          ITE(addr == addr',
    //              data',
    //              Load(mem', addr)
    //             )
    //         )
    // TODO

    // pattern 2 - loading from conditional memory
    //  Ex. LOAD(ITE(x, m1, m2), addr)
    // TODO

    ILA_DLOG("PassRewrStoreLoad") << "Skip pattern " << mem;

    return FuncObjRewrExpr::RewriteOp(e);
  }

}; // class FuncObjRewrStoreLoad

bool RewriteStoreLoad(const InstrLvlAbsPtr& m) {
  ILA_NOT_NULL(m);
  ILA_INFO << "Start pass: rewrite store-load pattern";

  auto func = FuncObjRewrStoreLoad();
  auto Rewr = [=, &func](const ExprPtr e) {
    if (e) {
      e->DepthFirstVisitPrePost(func);
      return func.get(e);
    }
    return e;
  };

  return RewriteGeneric(m, Rewr);
}

} // namespace pass

} // namespace ilang
