/// \file
/// Implementation of the ExprOp - operational expressions

#include <ilang/ila/ast/expr_op.h>

#include <set>
#include <unordered_map>

#include <ilang/ila/ast/func.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/util/log.h>
#include <ilang/util/z3_helper.h>

namespace ilang {

// verbose operation name
static const std::unordered_map<AstUidExprOp, std::string> kOpName{
    {AstUidExprOp::kNegate, "NEGATE"},
    {AstUidExprOp::kNot, "NOT"},
    {AstUidExprOp::kComplement, "COMPLEMENT"},
    {AstUidExprOp::kAnd, "AND"},
    {AstUidExprOp::kOr, "OR"},
    {AstUidExprOp::kXor, "XOR"},
    {AstUidExprOp::kShiftLeft, "SHL"},
    {AstUidExprOp::kArithShiftRight, "ASHR"},
    {AstUidExprOp::kLogicShiftRight, "LSHR"},
    {AstUidExprOp::kAdd, "ADD"},
    {AstUidExprOp::kSubtract, "SUB"},
    {AstUidExprOp::kMultiply, "MUL"},
    {AstUidExprOp::kEqual, "EQ"},
    {AstUidExprOp::kLessThan, "LT"},
    {AstUidExprOp::kGreaterThan, "GT"},
    {AstUidExprOp::kUnsignedLessThan, "ULT"},
    {AstUidExprOp::kUnsignedGreaterThan, "UGT"},
    {AstUidExprOp::kLoad, "LOAD"},
    {AstUidExprOp::kStore, "STORE"},
    {AstUidExprOp::kConcatenate, "CONCAT"},
    {AstUidExprOp::kExtract, "EXTRACT"},
    {AstUidExprOp::kZeroExtend, "ZERO_EXTEND"},
    {AstUidExprOp::kSignedExtend, "SIGN_EXTEND"},
    {AstUidExprOp::kApplyFunc, "APP"},
    {AstUidExprOp::kImply, "IMPLY"},
    {AstUidExprOp::kIfThenElse, "ITE"},
    {AstUidExprOp::kDivide, "DIV"},
    {AstUidExprOp::kRotateLeft, "LEFT_ROTATE"},
    {AstUidExprOp::kRotateRight, "RIGHT_ROTATE"},
    {AstUidExprOp::kSignedRemainder, "SREM"},
    {AstUidExprOp::kUnsignedRemainder, "UREM"},
    {AstUidExprOp::kSignedModular, "SMOD"}};

// ------------------------- Class ExprOp ----------------------------------- //

ExprOp::ExprOp(const ExprPtr& arg) {
  // arg
  set_args({arg});
  // host
  set_host(GetHost({arg}));
}

ExprOp::ExprOp(const ExprPtr& arg0, const ExprPtr& arg1) {
  // args
  set_args({arg0, arg1});
  // set host
  set_host(GetHost({arg0, arg1}));
}

ExprOp::ExprOp(const ExprPtr& arg0, const ExprPtr& arg1, const ExprPtr& arg2) {
  // args
  set_args({arg0, arg1, arg2});
  // set host
  set_host(GetHost({arg0, arg1, arg2}));
}

ExprOp::ExprOp(const ExprPtr& arg0, const int& param1) {
  // args
  set_args({arg0});
  // params
  set_params({param1});
  // set host
  set_host(GetHost({arg0}));
}

ExprOp::ExprOp(const ExprPtr& arg0, const int& param1, const int& param2) {
  // args
  set_args({arg0});
  // params
  set_params({param1, param2});
  // set hsot
  set_host(GetHost({arg0}));
}

ExprOp::ExprOp(const ExprPtrVec& args) {
  // args
  set_args(args);
  // host
  auto args_set = ExprSet();
  for (const auto& arg_i : args) {
    args_set.insert(arg_i);
  }
  set_host(GetHost(args_set));
}

ExprOp::~ExprOp() {}

std::string ExprOp::op_name() const {
  auto pos = kOpName.find(uid());
  ILA_ASSERT(pos != kOpName.end());
  return pos->second;
}

std::ostream& ExprOp::Print(std::ostream& out) const {
  return out << name().format_str(op_name(), "");
}

SortPtr ExprOp::GetSortBinaryOperation(const ExprPtr& e0, const ExprPtr& e1) {
  auto s0 = e0->sort();
  auto s1 = e1->sort();
  ILA_ASSERT(s0 == s1) << "Mismatch sorts " << s0 << " and " << s1;
  // return the same sort as input arguments.
  return s0;
}

SortPtr ExprOp::GetSortBinaryComparison(const ExprPtr& e0, const ExprPtr& e1) {
  auto s0 = e0->sort();
  auto s1 = e1->sort();
  ILA_ASSERT(s0 == s1) << "Mismatch sorts " << s0 << " and " << s1;
  // return boolean sort.
  return Sort::MakeBoolSort();
}

ExprOp::InstrLvlAbsPtr ExprOp::GetHost(const ExprSet& args) const {
  // get all hosts
  std::set<InstrLvlAbsPtr> hosts;
  for (const auto& arg_i : args) {
    auto host_i = arg_i->host();
    if (host_i) {
      hosts.insert(host_i);
    }
  }
  // find host with no child in the hosts ("one of" the leaf hosts)
  InstrLvlAbsPtr leaf = nullptr;
  for (const auto& host_i : hosts) {
    if (host_i->child_num() == 0) { // XXX pick one if multiple leaves
      return host_i;
    } else {
      auto is_leaf = true;
      for (decltype(host_i->child_num()) j = 0; j != host_i->child_num(); j++) {
        auto child_ij = host_i->child(j);
        is_leaf &= (hosts.find(child_ij) == hosts.end());
      }
      if (is_leaf) {
        return host_i;
      }
    }
  }
  return leaf;
}

// ------------------------- Class ExprOpNeg -------------------------------- //
ExprOpNeg::ExprOpNeg(const ExprPtr& arg) : ExprOp(arg) {
  ILA_ASSERT(arg->is_bv()) << "Negate can only be applied to bitvector.";
  set_sort(arg->sort());
}

z3::expr ExprOpNeg::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Negate is a unary function.";
  return -expr_vec[0];
}

// ------------------------- Class ExprOpNot -------------------------------- //
ExprOpNot::ExprOpNot(const ExprPtr& arg) : ExprOp(arg) {
  ILA_ASSERT(arg->is_bool()) << "Not can only be applied to bool.";
  set_sort(arg->sort());
}

z3::expr ExprOpNot::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Not is a unary function.";
  return !expr_vec[0];
}

// ------------------------- Class ExprOpCompl ------------------------------ //
ExprOpCompl::ExprOpCompl(const ExprPtr& arg) : ExprOp(arg) {
  ILA_ASSERT(arg->is_bv()) << "Complement can only be applied to bitvector.";
  set_sort(arg->sort());
}

z3::expr ExprOpCompl::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                                const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Negate is a unary function.";
  return ~expr_vec[0];
}

// ------------------------- Class ExprOpAnd -------------------------------- //
ExprOpAnd::ExprOpAnd(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0, arg1));
}

z3::expr ExprOpAnd::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2);
  ILA_ASSERT(is_bool() || is_bv()) << "AND can only be either bool or bv.";
  if (is_bool()) {
    return expr_vec[0] && expr_vec[1];
  } else {
    return expr_vec[0] & expr_vec[1];
  }
}

// ------------------------- Class ExprOpOr --------------------------------- //
ExprOpOr::ExprOpOr(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0, arg1));
}

z3::expr ExprOpOr::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                             const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2);
  ILA_ASSERT(is_bool() || is_bv()) << "OR can only be either bool or bv.";
  if (is_bool()) {
    return expr_vec[0] || expr_vec[1];
  } else {
    return expr_vec[0] | expr_vec[1];
  }
}

// ------------------------- Class ExprOpXor -------------------------------- //
ExprOpXor::ExprOpXor(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0, arg1));
}

z3::expr ExprOpXor::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2);
  ILA_ASSERT(is_bool() || is_bv()) << "XOR can only be either bool or bv.";
  if (is_bv()) {
    // auto ast_xor = Z3_mk_bvxor(ctx, expr_vec[0], expr_vec[1]);
    return expr_vec[0] ^ expr_vec[1];
    // return z3::to_expr(ctx, ast_xor);
  } else {
    auto ast_xor = Z3_mk_xor(ctx, expr_vec[0], expr_vec[1]);
    return z3::to_expr(ctx, ast_xor);
  }
}

// ------------------------- Class ExprOpShl -------------------------------- //
ExprOpShl::ExprOpShl(const ExprPtr& bv, const ExprPtr& n) : ExprOp(bv, n) {
  ILA_ASSERT(bv->is_bv()) << "Left shift can only be applied to bit-vectors.";
  set_sort(GetSortBinaryOperation(bv, n));
}

z3::expr ExprOpShl::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2) << "Left shift is binary operation.";
  return Z3Shl(ctx, expr_vec[0], expr_vec[1]);
}

// ------------------------- Class ExprOpAshr ------------------------------- //
ExprOpAshr::ExprOpAshr(const ExprPtr& bv, const ExprPtr& n) : ExprOp(bv, n) {
  ILA_ASSERT(bv->is_bv()) << "Right shift can only be applied to bit-vectors.";
  set_sort(GetSortBinaryOperation(bv, n));
}

z3::expr ExprOpAshr::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                               const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2) << "Right shift is binary operation.";
  return Z3Ashr(ctx, expr_vec[0], expr_vec[1]);
}

// ------------------------- Class ExprOpLshr ------------------------------- //
ExprOpLshr::ExprOpLshr(const ExprPtr& bv, const ExprPtr& n) : ExprOp(bv, n) {
  ILA_ASSERT(bv->is_bv()) << "Right shift can only be applied to bit-vectors.";
  set_sort(GetSortBinaryOperation(bv, n));
}

z3::expr ExprOpLshr::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                               const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2) << "Right shift is binary operation.";
  return Z3Lshr(ctx, expr_vec[0], expr_vec[1]);
}

// ------------------------- Class ExprOpAdd -------------------------------- //
ExprOpAdd::ExprOpAdd(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0, arg1));
}

z3::expr ExprOpAdd::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2) << "Add is binary operation.";
  ILA_ASSERT(is_bv()) << "ADD can only be applied to bv.";
  return expr_vec[0] + expr_vec[1];
}

// ------------------------- Class ExprOpSub -------------------------------- //
ExprOpSub::ExprOpSub(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0, arg1));
}

z3::expr ExprOpSub::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2) << "Sub is binary operation.";
  ILA_ASSERT(is_bv()) << "Sub can only be applied to bv.";
  return expr_vec[0] - expr_vec[1];
}

// ------------------------- Class ExprOpDiv ------------------------------- //
ExprOpDiv::ExprOpDiv(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0, arg1));
}

z3::expr ExprOpDiv::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffic) const {
  ILA_ASSERT(expr_vec.size() == 2) << "Div is binary operation.";
  ILA_ASSERT(is_bv()) << "Div can only be applied to bv.";
  return expr_vec[0] / expr_vec[1];
}

// ------------------------- Class ExprOpSRem ------------------------------- //
ExprOpSRem::ExprOpSRem(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0, arg1));
}

z3::expr ExprOpSRem::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                               const std::string& suffic) const {
  ILA_ASSERT(expr_vec.size() == 2) << "SRem is binary operation.";
  ILA_ASSERT(is_bv()) << "SRem can only be applied to bv.";
  return Z3SRem(ctx, expr_vec[0], expr_vec[1]);
}

// ------------------------- Class ExprOpURem ------------------------------- //
ExprOpURem::ExprOpURem(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0, arg1));
}

z3::expr ExprOpURem::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                               const std::string& suffic) const {
  ILA_ASSERT(expr_vec.size() == 2) << "URem is binary operation.";
  ILA_ASSERT(is_bv()) << "URem can only be applied to bv.";
  return Z3URem(ctx, expr_vec[0], expr_vec[1]);
}

// ------------------------- Class ExprOpSMod ------------------------------- //
ExprOpSMod::ExprOpSMod(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0, arg1));
}

z3::expr ExprOpSMod::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                               const std::string& suffic) const {
  ILA_ASSERT(expr_vec.size() == 2) << "SMod is binary operation.";
  ILA_ASSERT(is_bv()) << "SMod can only be applied to bv.";
  return Z3SMod(ctx, expr_vec[0], expr_vec[1]);
}

// ------------------------- Class ExprOpMul ------------------------------- //
ExprOpMul::ExprOpMul(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0, arg1));
}

z3::expr ExprOpMul::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2) << "Mul is binary operation.";
  ILA_ASSERT(is_bv()) << "Mul can only be applied to bv.";
  return expr_vec[0] * expr_vec[1];
}

// ------------------------- Class ExprOpEq --------------------------------- //
ExprOpEq::ExprOpEq(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryComparison(arg0, arg1));
}

z3::expr ExprOpEq::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                             const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2) << "Eq is binary comparison.";
  return expr_vec[0] == expr_vec[1];
}

// ------------------------- Class ExprOpLt --------------------------------- //
ExprOpLt::ExprOpLt(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryComparison(arg0, arg1));
}

z3::expr ExprOpLt::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                             const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2) << "Lt is binary comparison.";
  return expr_vec[0] < expr_vec[1];
}

// ------------------------- Class ExprOpGt --------------------------------- //
ExprOpGt::ExprOpGt(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryComparison(arg0, arg1));
}

z3::expr ExprOpGt::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                             const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2) << "Gt is binary comparison.";
  return expr_vec[0] > expr_vec[1];
}

// ------------------------- Class ExprOpUlt -------------------------------- //
ExprOpUlt::ExprOpUlt(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryComparison(arg0, arg1));
}

z3::expr ExprOpUlt::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2) << "ULt is binary comparison.";
  return z3::ult(expr_vec[0], expr_vec[1]);
}

// ------------------------- Class ExprOpUgt -------------------------------- //
ExprOpUgt::ExprOpUgt(const ExprPtr& arg0, const ExprPtr& arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryComparison(arg0, arg1));
}

z3::expr ExprOpUgt::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2) << "UGt is binary comparison.";
  return z3::ugt(expr_vec[0], expr_vec[1]);
}

// ------------------------- Class ExprOpLoad ------------------------------- //
ExprOpLoad::ExprOpLoad(const ExprPtr& mem, const ExprPtr& addr)
    : ExprOp(mem, addr) {
  ILA_ASSERT(mem->sort()->addr_width() == addr->sort()->bit_width());
  // sort should be the data sort of the mem
  auto data_sort = Sort::MakeBvSort(mem->sort()->data_width());
  set_sort(data_sort);
}

z3::expr ExprOpLoad::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                               const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2);
  return z3::select(expr_vec[0], expr_vec[1]);
}

// ------------------------- Class ExprOpLoad ------------------------------- //
ExprOpStore::ExprOpStore(const ExprPtr& mem, const ExprPtr& addr,
                         const ExprPtr& data)
    : ExprOp(mem, addr, data) {
  ILA_ASSERT(mem->sort()->addr_width() == addr->sort()->bit_width());
  ILA_ASSERT(mem->sort()->data_width() == data->sort()->bit_width());
  set_sort(mem->sort());
}

z3::expr ExprOpStore::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                                const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 3) << "Store takes 3 arguments.";
  auto mem = expr_vec[0];
  auto addr = expr_vec[1];
  auto data = expr_vec[2];
  return z3::store(mem, addr, data);
}

// ------------------------- Class ExprOpConcat ----------------------------- //
ExprOpConcat::ExprOpConcat(const ExprPtr& hi, const ExprPtr& lo)
    : ExprOp(hi, lo) {
  ILA_ASSERT(hi->is_bv()) << "Concat non-bv var " << hi;
  ILA_ASSERT(lo->is_bv()) << "Concat non-bv var " << lo;
  set_sort(Sort::MakeBvSort(hi->sort()->bit_width() + lo->sort()->bit_width()));
}

z3::expr ExprOpConcat::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                                 const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2) << "Concat takes 2 arguments.";
  auto hi = expr_vec[0];
  auto lo = expr_vec[1];
  return z3::concat(hi, lo);
}

// ------------------------- Class ExprOpExtract ---------------------------- //
ExprOpExtract::ExprOpExtract(const ExprPtr& bv, const int& hi, const int& lo)
    : ExprOp(bv, hi, lo) {
  ILA_ASSERT(bv->is_bv()) << "Extract can only be applied to bitvector.";
  ILA_ASSERT(hi >= lo) << "Invalid boundary for extraction.";
  set_sort(Sort::MakeBvSort(hi - lo + 1));
}

z3::expr ExprOpExtract::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                                  const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Extract take 1 argument.";
  ILA_ASSERT(param_num() == 2) << "Extract need two parameters.";
  auto bv = expr_vec[0];
  auto hi = static_cast<unsigned>(param(0));
  auto lo = static_cast<unsigned>(param(1));
  return bv.extract(hi, lo);
}

// ------------------------- Class ExprOpZExt ------------------------------- //
ExprOpZExt::ExprOpZExt(const ExprPtr& bv, const int& bit_width)
    : ExprOp(bv, bit_width) {
  ILA_ASSERT(bv->is_bv()) << "Zero-extend can only be applied to bit-vector.";
  ILA_ASSERT(bit_width >= bv->sort()->bit_width());
  set_sort(Sort::MakeBvSort(bit_width));
}

z3::expr ExprOpZExt::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                               const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Extend take 1 argument.";
  ILA_ASSERT(param_num() == 1) << "Extend need one parameter.";
  auto bv = expr_vec[0];
  auto org_wid = arg(0)->sort()->bit_width();
  auto wid = static_cast<unsigned>(param(0) - org_wid);
  return Z3ZExt(ctx, bv, wid);
}

// ------------------------- Class ExprOpSExt ------------------------------- //
ExprOpSExt::ExprOpSExt(const ExprPtr& bv, const int& bit_width)
    : ExprOp(bv, bit_width) {
  ILA_ASSERT(bv->is_bv()) << "Sign-extend can only be applied to bit-vector.";
  ILA_ASSERT(bit_width >= bv->sort()->bit_width());
  set_sort(Sort::MakeBvSort(bit_width));
}

z3::expr ExprOpSExt::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                               const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Extend take 1 argument.";
  ILA_ASSERT(param_num() == 1) << "Extend need one parameter.";
  auto bv = expr_vec[0];
  auto org_wid = arg(0)->sort()->bit_width();
  unsigned wid = static_cast<unsigned>(param(0) - org_wid);
  return Z3SExt(ctx, bv, wid);
}

// ------------------------- Class ExprOpLRotate ---------------------------- //
ExprOpLRotate::ExprOpLRotate(const ExprPtr& bv, const int& immediate)
    : ExprOp(bv, immediate) {
  ILA_ASSERT(bv->is_bv()) << "Left-rotate can only be applied to bit-vector.";
  ILA_ASSERT(immediate >= 0) << "Invalid number of times to rotate.";
  set_sort(bv->sort());
}

z3::expr ExprOpLRotate::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                                  const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Rotate takes 1 argument.";
  ILA_ASSERT(param_num() == 1) << "Rotate takes 1 parameter.";
  auto bv = expr_vec[0];
  unsigned immediate = static_cast<unsigned>(param(0));
  return Z3LRotate(ctx, bv, immediate);
}

// ------------------------- Class ExprOpRRotate ---------------------------- //
ExprOpRRotate::ExprOpRRotate(const ExprPtr& bv, const int& immediate)
    : ExprOp(bv, immediate) {
  ILA_ASSERT(bv->is_bv()) << "Right-rotate can only be applied to bit-vector.";
  ILA_ASSERT(immediate >= 0) << "Invalid number of times to rotate.";
  set_sort(bv->sort());
}

z3::expr ExprOpRRotate::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                                  const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Rotate takes 1 argument.";
  ILA_ASSERT(param_num() == 1) << "Rotate takes 1 parameter.";
  auto bv = expr_vec[0];
  unsigned immediate = static_cast<unsigned>(param(0));
  return Z3RRotate(ctx, bv, immediate);
}

// ------------------------- Class ExprOpAppFunc ---------------------------- //
ExprOpAppFunc::ExprOpAppFunc(const FuncPtr& _f, const ExprPtrVec& args)
    : ExprOp(args), f(_f) {
  ILA_ASSERT(_f->CheckSort(args));
  set_sort(_f->out());
}

z3::expr ExprOpAppFunc::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                                  const std::string& suffix) const {
  if (expr_vec.empty()) {                               // non-deterministic
    auto prefix = (host()) ? host()->name().str() : ""; // XXX with host?
    auto name = f->name().format_str(prefix, suffix);
    return f->out()->GetZ3Expr(ctx, name); // get a free variable of the Sort
  }
  auto f_decl = f->GetZ3FuncDecl(ctx);
  return f_decl(expr_vec.size(), expr_vec.data());
}

// ------------------------- Class ExprOpImply ------------------------------ //
ExprOpImply::ExprOpImply(const ExprPtr& ante, const ExprPtr& cons)
    : ExprOp(ante, cons) {
  ILA_ASSERT(ante->is_bool()) << "Antecedent must be Boolean.";
  ILA_ASSERT(cons->is_bool()) << "Consequent must be Boolean.";
  set_sort(Sort::MakeBoolSort());
}

z3::expr ExprOpImply::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                                const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2) << "Imply takes two arguments.";
  auto ante = expr_vec[0];
  auto cons = expr_vec[1];
  return Z3Implies(ctx, ante, cons);
}

// ------------------------- Class ExprOpIte -------------------------------- //
ExprOpIte::ExprOpIte(const ExprPtr& cnd, const ExprPtr& true_expr,
                     const ExprPtr& false_expr)
    : ExprOp(cnd, true_expr, false_expr) {
  ILA_ASSERT(cnd->is_bool()) << "Condition must be Boolean.";
  ILA_ASSERT(true_expr->sort() == false_expr->sort()) << "sort mismatch";
  set_sort(true_expr->sort());
}

z3::expr ExprOpIte::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 3) << "Ite takes 3 arguments.";
  auto cnd = expr_vec[0];
  auto t_e = expr_vec[1];
  auto t_f = expr_vec[2];
  return z3::ite(cnd, t_e, t_f);
}

} // namespace ilang
