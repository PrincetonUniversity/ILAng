/// \file
/// Source for the class ExprMngr

#include "ila/simplify.h"

namespace ila {

ExprMngr::ExprMngr() {}

ExprMngr::~ExprMngr() {}

void ExprMngr::clear() { map_.clear(); }

ExprPtr ExprMngr::Simplify(const ExprPtr node, bool simplify) {
  // TODO
  if (!simplify)
    return node;

  return node;
}

} // namespace ila

