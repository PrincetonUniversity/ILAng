/// \file
/// Source for function object for rewriting Expr.

#include <ilang/util/log.h>
#include <ilang/verification/rewrite_expr.h>

namespace ilang {

using namespace ExprFuse;

bool FuncObjRewrExpr::pre(const ExprPtr e) const {
  // check rewriting rule to see if defined/visited
  auto pos = rule_.find(e);
  return pos != rule_.end(); // if found --> break
}

void FuncObjRewrExpr::post(const ExprPtr e) {
  auto dst = Rewrite(e);
  auto ok = rule_.insert({e, dst}).second;
  // must not be defined, otherwise, there is a cycle.
  ILA_ASSERT(ok) << "Rewriting rule redefined (exist cycle in the AST)";
}

ExprPtr FuncObjRewrExpr::Rewrite(const ExprPtr e) const {
  if (e->is_var() || e->is_const()) {
    return e;
  } else {
    ILA_ASSERT(e->is_op()) << "Unkown type for " << e;
    return RewriteOp(e);
  }
}

ExprPtr FuncObjRewrExpr::RewriteOp(const ExprPtr e) const {
  // check each type of op
  if (std::dynamic_pointer_cast<ExprOpNeg>(e)) { // Negate
    auto a = get(e->arg(0));
    return Negate(a);
  } else if (std::dynamic_pointer_cast<ExprOpNot>(e)) { // Not
    auto a = get(e->arg(0));
    return Not(a);
  } else if (std::dynamic_pointer_cast<ExprOpCompl>(e)) { // Complement
    auto a = get(e->arg(0));
    return Complement(a);
  } else if (std::dynamic_pointer_cast<ExprOpAnd>(e)) { // And
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return And(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpOr>(e)) { // Or
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Or(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpXor>(e)) { // Xor
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Xor(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpShl>(e)) { // Shl
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Shl(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpAshr>(e)) { // Ashl
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Ashr(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpLshr>(e)) { // Lshl
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Lshr(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpAdd>(e)) { // Add
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Add(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpSub>(e)) { // Sub
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Sub(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpEq>(e)) { // Eq
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Eq(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpLt>(e)) { // Lt
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Lt(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpGt>(e)) { // Gt
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Gt(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpUlt>(e)) { // Ult
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Ult(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpUgt>(e)) { // Ugt
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Ugt(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpLoad>(e)) { // Load
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Load(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpStore>(e)) { // Store
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    auto a2 = get(e->arg(2));
    return Store(a0, a1, a2);
  } else if (std::dynamic_pointer_cast<ExprOpConcat>(e)) { // Concat
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Concat(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpExtract>(e)) { // Extract
    auto a0 = get(e->arg(0));
    auto p0 = e->param(0);
    auto p1 = e->param(1);
    return Extract(a0, p0, p1);
  } else if (std::dynamic_pointer_cast<ExprOpZExt>(e)) { // ZExt
    auto a0 = get(e->arg(0));
    auto p0 = e->param(0);
    return ZExt(a0, p0);
  } else if (std::dynamic_pointer_cast<ExprOpSExt>(e)) { // SExt
    auto a0 = get(e->arg(0));
    auto p0 = e->param(0);
    return SExt(a0, p0);
  } else if (std::dynamic_pointer_cast<ExprOpImply>(e)) { // Imply
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    return Imply(a0, a1);
  } else if (std::dynamic_pointer_cast<ExprOpIte>(e)) { // Ite
    auto a0 = get(e->arg(0));
    auto a1 = get(e->arg(1));
    auto a2 = get(e->arg(2));
    return Ite(a0, a1, a2);
  } else { // AppFunc
    auto e_derive = std::dynamic_pointer_cast<ExprOpAppFunc>(e);
    ILA_ASSERT(e_derive) << "Fail copying " << e;

    auto f = e_derive->func();
    ExprPtrVec args;
    for (decltype(e->arg_num()) i = 0; i != e->arg_num(); i++) {
      args.push_back(get(e->arg(i)));
    }
    return AppFunc(f, args);
  }
}

} // namespace ilang
