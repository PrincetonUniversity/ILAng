/// \file
/// Header for helpers for interfacing the z3 API

#ifndef ILANG_UTIL_Z3_HELPER_H__
#define ILANG_UTIL_Z3_HELPER_H__

#include <string>

#include <ilang/config.h>
#include <ilang/ila/ast/sort_value.h>
#include <z3++.h>

namespace ilang {

#ifndef Z3_LEGACY_API
/// \brief Interface z3 bit-vector constant numeric.
inline BvValType Z3BvVal(const BvValType& bv_val) { return bv_val; }
#else
/// \brief Interface z3 bit-vector constant numeric.
inline __int64 Z3BvVal(const BvValType& bv_val) {
  return static_cast<__int64>(bv_val);
}
#endif

/// \brief Interface z3 implies ast node construction.
inline z3::expr Z3Implies(z3::context& ctx, const z3::expr& a,
                          const z3::expr& b) {
#ifndef Z3_LEGACY_API
  return z3::implies(a, b);
#else
  return z3::expr(ctx, Z3_mk_implies(ctx, a, b));
#endif
}

/// \brief Interface z3 shl ast node construction.
inline z3::expr Z3Shl(z3::context& ctx, const z3::expr& a, const z3::expr& b) {
#ifndef Z3_LEGACY_API
  return z3::shl(a, b);
#else
  return z3::expr(ctx, Z3_mk_bvshl(ctx, a, b));
#endif
}

/// \brief Interface z3 ashr ast node construction.
inline z3::expr Z3Ashr(z3::context& ctx, const z3::expr& a, const z3::expr& b) {
#ifndef Z3_LEGACY_API
  return z3::ashr(a, b);
#else
  return z3::expr(ctx, Z3_mk_bvashr(ctx, a, b));
#endif
}

/// \brief Interface z3 lshr ast node construction.
inline z3::expr Z3Lshr(z3::context& ctx, const z3::expr& a, const z3::expr& b) {
#ifndef Z3_LEGACY_API
  return z3::lshr(a, b);
#else
  return z3::expr(ctx, Z3_mk_bvlshr(ctx, a, b));
#endif
}

/// \brief Interface z3 shl ast node construction.
inline z3::expr Z3SRem(z3::context& ctx, const z3::expr& a, const z3::expr& b) {
#ifndef Z3_LEGACY_API
  return z3::srem(a, b);
#else
  return z3::expr(ctx, Z3_mk_bvsrem(ctx, a, b));
#endif
}

/// \brief Interface z3 shl ast node construction.
inline z3::expr Z3URem(z3::context& ctx, const z3::expr& a, const z3::expr& b) {
#ifndef Z3_LEGACY_API
  return z3::urem(a, b);
#else
  return z3::expr(ctx, Z3_mk_bvurem(ctx, a, b));
#endif
}

/// \brief Interface z3 shl ast node construction.
inline z3::expr Z3SMod(z3::context& ctx, const z3::expr& a, const z3::expr& b) {
#ifndef Z3_LEGACY_API
  return z3::smod(a, b);
#else
  return z3::expr(ctx, Z3_mk_bvsmod(ctx, a, b));
#endif
}

/// \brief Interface z3 zext ast node construction.
inline z3::expr Z3ZExt(z3::context& ctx, const z3::expr& e, const unsigned& w) {
#ifndef Z3_LEGACY_API
  return z3::zext(e, w);
#else
  return z3::expr(ctx, Z3_mk_zero_ext(ctx, w, e));
#endif
}

/// \brief Interface z3 sext ast node construction.
inline z3::expr Z3SExt(z3::context& ctx, const z3::expr& e, const unsigned& w) {
#ifndef Z3_LEGACY_API
  return z3::sext(e, w);
#else
  return z3::expr(ctx, Z3_mk_sign_ext(ctx, w, e));
#endif
}

/// \brief Interface z3 left rotate ast node construction.
inline z3::expr Z3LRotate(z3::context& ctx, z3::expr& e, unsigned& w) {
#ifndef Z3_LEGACY_API
  return e.rotate_left(w);
#else
  return z3::expr(ctx, Z3_mk_rotate_left(ctx, w, e));
#endif
}

/// \brief Interface z3 right rotate ast node construction.
inline z3::expr Z3RRotate(z3::context& ctx, z3::expr& e, unsigned& w) {
#ifndef Z3_LEGACY_API
  return e.rotate_right(w);
#else
  return z3::expr(ctx, Z3_mk_rotate_right(ctx, w, e));
#endif
}

/// \brief Return the output string of the given z3::expr.
inline std::string Z3Expr2String(z3::context& ctx, const z3::expr& e) {
#ifndef Z3_LEGACY_API
  return e.to_string();
#else
  return static_cast<std::string>(Z3_ast_to_string(ctx, e));
#endif
}

}; // namespace ilang

#endif // ILANG_UTIL_Z3_HELPER_H__
