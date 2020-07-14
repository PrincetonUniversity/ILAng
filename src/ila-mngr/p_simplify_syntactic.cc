/// \file
/// Simplify Expr node syntactically (structurally).

#include <ilang/ila-mngr/pass.h>

#include <ilang/ila/hash_ast.h>
#include <ilang/util/log.h>

namespace ilang {

namespace pass {

bool SimplifySyntactic(const InstrLvlAbsPtr& m) {
  ILA_NOT_NULL(m);
  ILA_INFO << "Start pass: syntactic simplification";

  auto mngr = ExprMngr::New();
  auto Rewr = [&mngr](const ExprPtr& expr) { return mngr->GetRep(expr); };
  try {
    return RewriteGeneric(m, Rewr);
  } catch (...) {
    return false;
  }
}

} // namespace pass

} // namespace ilang
