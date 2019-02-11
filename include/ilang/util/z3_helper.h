/// \file
/// Header for helpers for interfacing the z3 API

#ifndef UTIL_Z3_HELPER_H__
#define UTIL_Z3_HELPER_H__

#include <ilang/config.h>
#include <string>
#include <z3++.h>

namespace ilang {

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

/// \brief Return the output string of the given z3::expr.
inline std::string Z3Expr2String(z3::context& ctx, const z3::expr& e) {
#ifndef Z3_LEGACY_API
  return e.to_string();
#else
  return static_cast<std::string>(Z3_ast_to_string(ctx, e));
#endif
}

}; // namespace ilang

#endif // UTIL_Z3_HELPER_H__

