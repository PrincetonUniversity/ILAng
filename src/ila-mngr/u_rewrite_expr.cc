/// \file
/// The function object for rewriting Expr.

#include <ilang/ila-mngr/u_rewriter.h>

#include <ilang/ila/ast_fuse.h>
#include <ilang/ila/expr_fuse.h>
#include <ilang/util/log.h>

namespace ilang {

using namespace ExprFuse;

ExprPtr FuncObjRewrExpr::get(const ExprPtr& e) const {
  auto pos = rule_.find(e);
  ILA_CHECK(pos != rule_.end()) << e << " not found";
  return pos->second;
}

bool FuncObjRewrExpr::pre(const ExprPtr& e) const {
  // check rewriting rule to see if defined/visited
  auto pos = rule_.find(e);
  return pos != rule_.end(); // if found --> break
}

void FuncObjRewrExpr::post(const ExprPtr& e) {
  auto dst = Rewrite(e);
  auto [it, ok] = rule_.emplace(e, dst);
  // must not be defined, otherwise, there is a cycle.
  ILA_ASSERT(ok) << "Rewriting rule redefined (exist cycle in the AST)";
}

ExprPtr FuncObjRewrExpr::Rewrite(const ExprPtr& e) const {
  if (e->is_var() || e->is_const()) {
    return e;
  } else {
    ILA_ASSERT(e->is_op()) << "Unkown type for " << e;
    return RewriteOp(e);
  }
}

ExprPtr FuncObjRewrExpr::RewriteOp(const ExprPtr& e) const {
  switch (auto expr_op_uid = GetUidExprOp(e); expr_op_uid) {
  case AST_UID_EXPR_OP::NEG: {
    auto a = get(e->arg(0));
    return Negate(a);
  }
  case AST_UID_EXPR_OP::NOT: {
    auto a = get(e->arg(0));
    return Not(a);
  }
  case AST_UID_EXPR_OP::COMPL: {
    auto a = get(e->arg(0));
    return Complement(a);
  }
  case AST_UID_EXPR_OP::AND: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return And(a0, a1);
  }
  case AST_UID_EXPR_OP::OR: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Or(a0, a1);
  }
  case AST_UID_EXPR_OP::XOR: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Xor(a0, a1);
  }
  case AST_UID_EXPR_OP::SHL: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Shl(a0, a1);
  }
  case AST_UID_EXPR_OP::ASHR: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Ashr(a0, a1);
  }
  case AST_UID_EXPR_OP::LSHR: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Lshr(a0, a1);
  }
  case AST_UID_EXPR_OP::ADD: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Add(a0, a1);
  }
  case AST_UID_EXPR_OP::SUB: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Sub(a0, a1);
  }
  case AST_UID_EXPR_OP::DIV: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Div(a0, a1);
  }
#if 0
  case AST_UID_EXPR_OP::SREM: {
    // TODO
  }
#endif
  case AST_UID_EXPR_OP::UREM: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return URem(a0, a1);
  }
#if 0
  case AST_UID_EXPR_OP::SMOD: {
    // TODO
  }
#endif
  case AST_UID_EXPR_OP::MUL: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Mul(a0, a1);
  }
  case AST_UID_EXPR_OP::EQ: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Eq(a0, a1);
  }
  case AST_UID_EXPR_OP::LT: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Lt(a0, a1);
  }
  case AST_UID_EXPR_OP::GT: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Gt(a0, a1);
  }
  case AST_UID_EXPR_OP::ULT: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Ult(a0, a1);
  }
  case AST_UID_EXPR_OP::UGT: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Ugt(a0, a1);
  }
  case AST_UID_EXPR_OP::LOAD: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Load(a0, a1);
  }
  case AST_UID_EXPR_OP::STORE: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    auto a2 = get(e->arg(2));
    return Store(a0, a1, a2);
  }
  case AST_UID_EXPR_OP::CONCAT: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Concat(a0, a1);
  }
  case AST_UID_EXPR_OP::EXTRACT: {
    auto a0 = get(e->arg(0));
    auto p0 = e->param(0);
    auto p1 = e->param(1);
    return Extract(a0, p0, p1);
  }
  case AST_UID_EXPR_OP::ZEXT: {
    auto a0 = get(e->arg(0));
    auto p0 = e->param(0);
    return ZExt(a0, p0);
  }
  case AST_UID_EXPR_OP::SEXT: {
    auto a0 = get(e->arg(0));
    auto p0 = e->param(0);
    return SExt(a0, p0);
  }
  case AST_UID_EXPR_OP::LROTATE: {
    auto a0 = get(e->arg(0));
    auto p0 = e->param(0);
    return LRotate(a0, p0);
  }
  case AST_UID_EXPR_OP::RROTATE: {
    auto a0 = get(e->arg(0));
    auto p0 = e->param(0);
    return RRotate(a0, p0);
  }
  case AST_UID_EXPR_OP::IMPLY: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Imply(a0, a1);
  }
  case AST_UID_EXPR_OP::ITE: {
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    auto a2 = get(e->arg(2));
    return Ite(a0, a1, a2);
  }
  case AST_UID_EXPR_OP::APP_FUNC: {
    auto e_derive = std::static_pointer_cast<ExprOpAppFunc>(e);
    ILA_NOT_NULL(e_derive);

    auto f = e_derive->func();
    ExprPtrVec args;
    for (decltype(e->arg_num()) i = 0; i != e->arg_num(); i++) {
      args.push_back(get(e->arg(i)));
    }
    return AppFunc(f, args);
  }
  default: {
    ILA_ERROR << "Rewriting " << expr_op_uid << " not implemented";
    return NULL;
  }
  };
}

} // namespace ilang
