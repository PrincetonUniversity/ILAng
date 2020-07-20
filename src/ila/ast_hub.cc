/// \file
///

#include <ilang/ila/ast_hub.h>

#include <ilang/ila/hash_ast.h>
#include <ilang/util/log.h>

namespace ilang {

namespace asthub {

ExprPtr NewBoolVar(const std::string& name) {
  return std::make_shared<ExprVar>(name);
}

ExprPtr NewBvVar(const std::string& name, const int& bit_width) {
  return std::make_shared<ExprVar>(name, bit_width);
}

ExprPtr NewMemVar(const std::string& name, const int& addr_width,
                  const int& data_width) {
  return std::make_shared<ExprVar>(name, addr_width, data_width);
}

ExprPtr BoolConst(const bool& val) {
  return std::make_shared<ExprConst>(BoolVal(val));
}

ExprPtr BoolConst(const BoolVal& val) {
  return std::make_shared<ExprConst>(val);
}

ExprPtr BvConst(const BvValType& val, const int& bit_width) {
  return std::make_shared<ExprConst>(BvVal(val), bit_width);
}

ExprPtr BvConst(const BvVal& val, const int& bit_width) {
  return std::make_shared<ExprConst>(val, bit_width);
}

ExprPtr MemConst(const BvValType& def_val, const int& addr_width,
                 const int& data_width) {
  return std::make_shared<ExprConst>(MemVal(def_val), addr_width, data_width);
}

ExprPtr MemConst(const MemVal& val, const int& addr_width,
                 const int& data_width) {
  return std::make_shared<ExprConst>(val, addr_width, data_width);
}

ExprPtr Negate(const ExprPtr& arg) { return std::make_shared<ExprOpNeg>(arg); }

ExprPtr Not(const ExprPtr& arg) { return std::make_shared<ExprOpNot>(arg); }

ExprPtr Complement(const ExprPtr& arg) {
  return std::make_shared<ExprOpCompl>(arg);
}

ExprPtr And(const ExprPtr& l, const ExprPtr& r) {
  if (l->sort() == r->sort()) {
    return std::make_shared<ExprOpAnd>(l, r);
  }
  // support unequal-sort-AND for: Bool AND bv(1)
  if (l->is_bv(1) && r->is_bool()) {
    return And(Eq(l, 1), r);
  } else {
    ILA_ASSERT(l->is_bool() && r->is_bv(1))
        << "AND two expressions of different sorts not supported";
    return And(l, Eq(r, 1));
  }
}

ExprPtr Or(const ExprPtr& l, const ExprPtr& r) {
  if (l->sort() == r->sort()) {
    return std::make_shared<ExprOpOr>(l, r);
  }
  // support unequal-sort-OR for: Bool OR bv(1)
  if (l->is_bv(1) && r->is_bool()) {
    return Or(Eq(l, 1), r);
  } else {
    ILA_ASSERT(l->is_bool() && r->is_bv(1))
        << "OR two expressions of different sorts not supported";
    return Or(l, Eq(r, 1));
  }
}

ExprPtr Xor(const ExprPtr& l, const ExprPtr& r) {
  if (l->sort() == r->sort()) {
    return std::make_shared<ExprOpXor>(l, r);
  }
  // support unequal-sort-XOR for: Bool XOR bv(1)
  if (l->is_bv(1) && r->is_bool()) {
    return Xor(Eq(l, 1), r);
  } else {
    ILA_ASSERT(l->is_bool() && r->is_bv(1))
        << "XOR two expressions of different sorts not supported";
    return Xor(l, Eq(r, 1));
  }
}

ExprPtr Shl(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpShl>(l, r);
}

ExprPtr Ashr(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpAshr>(l, r);
}

ExprPtr Lshr(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpLshr>(l, r);
}

ExprPtr Add(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpAdd>(l, r);
}

ExprPtr Sub(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpSub>(l, r);
}

ExprPtr Div(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpDiv>(l, r);
}

ExprPtr SRem(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpSRem>(l, r);
}

ExprPtr URem(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpURem>(l, r);
}

ExprPtr SMod(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpSMod>(l, r);
}

ExprPtr Mul(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpMul>(l, r);
}

ExprPtr And(const ExprPtr& l, const bool& r) {
  auto rc = BoolConst(r);
  return And(l, rc);
}

ExprPtr Or(const ExprPtr& l, const bool& r) {
  auto rc = BoolConst(r);
  return Or(l, rc);
}

ExprPtr Xor(const ExprPtr& l, const bool& r) {
  auto rc = BoolConst(r);
  return Xor(l, rc);
}

ExprPtr Shl(const ExprPtr& l, const int& r) {
  auto rc = BvConst(r, l->sort()->bit_width());
  return Shl(l, rc);
}

ExprPtr Ashr(const ExprPtr& l, const int& r) {
  auto rc = BvConst(r, l->sort()->bit_width());
  return Ashr(l, rc);
}

ExprPtr Lshr(const ExprPtr& l, const int& r) {
  auto rc = BvConst(r, l->sort()->bit_width());
  return Lshr(l, rc);
}

ExprPtr Add(const ExprPtr& l, const BvValType& r) {
  auto rc = BvConst(r, l->sort()->bit_width());
  return Add(l, rc);
}

ExprPtr Sub(const ExprPtr& l, const BvValType& r) {
  auto rc = BvConst(r, l->sort()->bit_width());
  return Sub(l, rc);
}

ExprPtr Mul(const ExprPtr& l, const BvValType& r) {
  auto rc = BvConst(r, l->sort()->bit_width());
  return Mul(l, rc);
}

ExprPtr Eq(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpEq>(l, r);
}

ExprPtr Ne(const ExprPtr& l, const ExprPtr& r) {
  auto eq = std::make_shared<ExprOpEq>(l, r);
  return std::make_shared<ExprOpNot>(eq);
}

ExprPtr Lt(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpLt>(l, r);
}

ExprPtr Gt(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpGt>(l, r);
}

ExprPtr Le(const ExprPtr& l, const ExprPtr& r) {
  auto eq = std::make_shared<ExprOpEq>(l, r);
  auto lt = std::make_shared<ExprOpLt>(l, r);
  return std::make_shared<ExprOpOr>(eq, lt);
}

ExprPtr Ge(const ExprPtr& l, const ExprPtr& r) {
  auto eq = std::make_shared<ExprOpEq>(l, r);
  auto gt = std::make_shared<ExprOpGt>(l, r);
  return std::make_shared<ExprOpOr>(eq, gt);
}
ExprPtr Ult(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpUlt>(l, r);
}

ExprPtr Ugt(const ExprPtr& l, const ExprPtr& r) {
  return std::make_shared<ExprOpUgt>(l, r);
}

ExprPtr Ule(const ExprPtr& l, const ExprPtr& r) {
  auto eq = std::make_shared<ExprOpEq>(l, r);
  auto ult = std::make_shared<ExprOpUlt>(l, r);
  return std::make_shared<ExprOpOr>(eq, ult);
}

ExprPtr Uge(const ExprPtr& l, const ExprPtr& r) {
  auto eq = std::make_shared<ExprOpEq>(l, r);
  auto ugt = std::make_shared<ExprOpUgt>(l, r);
  return std::make_shared<ExprOpOr>(eq, ugt);
}

#if 0
ExprPtr Eq(const ExprPtr& l, const bool& r) {
  auto rc = BoolConst(r);
  return Eq(l, rc);
}
#endif

ExprPtr Eq(const ExprPtr& l, const BvValType& r) {
  auto rc =
      (l->is_bool()) ? BoolConst(r == 1) : BvConst(r, l->sort()->bit_width());
  return Eq(l, rc);
}

ExprPtr Ne(const ExprPtr& l, const BvValType& r) {
  auto rc =
      (l->is_bool()) ? BoolConst(r == 1) : BvConst(r, l->sort()->bit_width());
  return Ne(l, rc);
}

ExprPtr Lt(const ExprPtr& l, const BvValType& r) {
  auto rc = BvConst(r, l->sort()->bit_width());
  return Lt(l, rc);
}

ExprPtr Gt(const ExprPtr& l, const BvValType& r) {
  auto rc = BvConst(r, l->sort()->bit_width());
  return Gt(l, rc);
}

ExprPtr Le(const ExprPtr& l, const BvValType& r) {
  auto rc = BvConst(r, l->sort()->bit_width());
  return Le(l, rc);
}

ExprPtr Ge(const ExprPtr& l, const BvValType& r) {
  auto rc = BvConst(r, l->sort()->bit_width());
  return Ge(l, rc);
}

ExprPtr Ult(const ExprPtr& l, const BvValType& r) {
  auto rc = BvConst(r, l->sort()->bit_width());
  return Ult(l, rc);
}

ExprPtr Ugt(const ExprPtr& l, const BvValType& r) {
  auto rc = BvConst(r, l->sort()->bit_width());
  return Ugt(l, rc);
}

ExprPtr Ule(const ExprPtr& l, const BvValType& r) {
  auto rc = BvConst(r, l->sort()->bit_width());
  return Ule(l, rc);
}

ExprPtr Uge(const ExprPtr& l, const BvValType& r) {
  auto rc = BvConst(r, l->sort()->bit_width());
  return Uge(l, rc);
}

ExprPtr Load(const ExprPtr& mem, const ExprPtr& addr) {
  return std::make_shared<ExprOpLoad>(mem, addr);
}

ExprPtr Store(const ExprPtr& mem, const ExprPtr& addr, const ExprPtr& data) {
  return std::make_shared<ExprOpStore>(mem, addr, data);
}

ExprPtr Load(const ExprPtr& mem, const BvValType& addr) {
  auto ac = BvConst(addr, mem->sort()->addr_width());
  return Load(mem, ac);
}

ExprPtr Store(const ExprPtr& mem, const BvValType& addr,
              const BvValType& data) {
  auto ac = BvConst(addr, mem->sort()->addr_width());
  auto dc = BvConst(data, mem->sort()->data_width());
  return Store(mem, ac, dc);
}

bool SetMemSize(const ExprPtr& mem, const int& size) {
  ILA_ASSERT(mem->is_mem()) << "Set size to non-memory variable " << mem;
  ILA_ASSERT(size > 0) << "Setting non-positive memory size " << size;

  if (mem->param_num() != 0) {
    ILA_WARN << "Overwriting original paramters of " << mem;
    return false;
  }

  mem->set_params({size});
  return true;
}

int GetMemSize(const ExprPtr& mem) {
  ILA_ASSERT(mem->is_mem()) << "Get size from non-memory variable " << mem;
  if (mem->param_num() == 0) {
    return 0;
  } else {
    ILA_ASSERT(mem->param_num() == 1) << "Unrecognized memory parameter set";
    return mem->param(0);
  }
}

ExprPtr Concat(const ExprPtr& hi, const ExprPtr& lo) {
  auto const_zero = BvConst(0x0, 1);
  auto const_one = BvConst(0x1, 1);
  auto bv_hi = hi->is_bool() ? Ite(hi, const_one, const_zero) : hi;
  auto bv_lo = lo->is_bool() ? Ite(lo, const_one, const_zero) : lo;
  return std::make_shared<ExprOpConcat>(bv_hi, bv_lo);
}

ExprPtr Extract(const ExprPtr& bv, const int& hi, const int& lo) {
  return std::make_shared<ExprOpExtract>(bv, hi, lo);
}

ExprPtr ZExt(const ExprPtr& bv, const int& out_width) {
  return std::make_shared<ExprOpZExt>(bv, out_width);
}

ExprPtr SExt(const ExprPtr& bv, const int& out_width) {
  return std::make_shared<ExprOpSExt>(bv, out_width);
}

ExprPtr LRotate(const ExprPtr& bv, const int& immediate) {
  return std::make_shared<ExprOpLRotate>(bv, immediate);
}

ExprPtr RRotate(const ExprPtr& bv, const int& immediate) {
  return std::make_shared<ExprOpRRotate>(bv, immediate);
}

ExprPtr AppFunc(const FuncPtr& func) {
  return std::shared_ptr<ExprOpAppFunc>(new ExprOpAppFunc(func, {}));
}

ExprPtr AppFunc(const FuncPtr& func, const ExprPtr& arg0) {
  return std::shared_ptr<ExprOpAppFunc>(new ExprOpAppFunc(func, {arg0}));
}

ExprPtr AppFunc(const FuncPtr& func, const ExprPtr& arg0, const ExprPtr& arg1) {
  return std::shared_ptr<ExprOpAppFunc>(new ExprOpAppFunc(func, {arg0, arg1}));
}

ExprPtr AppFunc(const FuncPtr& func, const ExprPtrVec& args) {
  return std::shared_ptr<ExprOpAppFunc>(new ExprOpAppFunc(func, args));
}

ExprPtr Imply(const ExprPtr& p, const ExprPtr& q) {
  return std::make_shared<ExprOpImply>(p, q);
}

ExprPtr Ite(const ExprPtr& cnd, const ExprPtr& true_expr,
            const ExprPtr& false_expr) {
  return std::make_shared<ExprOpIte>(cnd, true_expr, false_expr);
}

bool TopEq(const ExprPtr& a, const ExprPtr& b) {
  ExprMngr m;
  auto x = m.GetRep(a);
  auto y = m.GetRep(b);
  return x == y;
}

} // namespace asthub

} // namespace ilang
