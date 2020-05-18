/// \file
/// Rewrite the STORE-LOAD pattern in the AST.

#include <ilang/ila-mngr/pass.h>

#include <ilang/ila-mngr/u_rewriter.h>
#include <ilang/ila/ast_fuse.h>
#include <ilang/util/log.h>

namespace ilang {

#if 0
class FuncObjStoreStore {
public:
  inline const ExprPtrVec& addr() const { return addr_; }
  inline const ExprPtrVec& data() const { return data_; }

  bool pre(const ExprPtr e) {
    // ILA_ASSERT(GetUidExprOp(e) == AST_UID_EXPR_OP::LOAD);
    // can be load from store/var/const/ite

    addr_.push_back(e->arg(1));
    data_.push_back(e->arg(2));

    // return true if is store to store
    return e->arg(0)->is_op();
  }

  void post(const ExprPtr e) {}

private:
  ExprPtrVec addr_;
  ExprPtrVec data_;

}; // class FuncObjStoreStore
#endif

class FuncObjRewrStoreLoad : public FuncObjRewrExpr {
public:
  FuncObjRewrStoreLoad() : FuncObjRewrExpr({}) {}

private:
  ExprPtr RewriteOp(const ExprPtr e) const {
    // override LOAD op; use default otherwise
    if (GetUidExprOp(e) == AST_UID_EXPR_OP::LOAD) {
      return RewriteLoad(e);
    }
    return FuncObjRewrExpr::RewriteOp(e);
  }

  ExprPtr RewriteLoad(const ExprPtr e) const {
    auto mem = get(e->arg(0));
    if (mem->is_var() || mem->is_const()) {
      return e;
    }

    auto IsStore = [=](const ExprPtr x) {
      ILA_ASSERT(x && x->is_mem()) << "Invariant violation " << x;
      if (x->is_op()) {
        return GetUidExprOp(x) == AST_UID_EXPR_OP::STORE;
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
      auto cond = ExprFuse::Eq(addr_load, addr_store);
      auto data_load = ExprFuse::Load(mem->arg(0), addr_load);
      auto data_store = mem->arg(2);
      return ExprFuse::Ite(cond, data_store, data_load);
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

bool PassRewriteStoreLoad(const InstrLvlAbsPtr& m) {
  ILA_NOT_NULL(m);

  auto func = FuncObjRewrStoreLoad();
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
