/// \file
/// Source for the class ExprMngr

#include "ila/simplify.h"

namespace ila {

ExprMngr::ExprMngr() {}

ExprMngr::~ExprMngr() {}

ExprMngrPtr ExprMngr::New() { return std::make_shared<ExprMngr>(); }

void ExprMngr::clear() { map_.clear(); }

ExprPtr ExprMngr::Simplify(const ExprPtr node, bool simplify) {
  // TODO
  if (!simplify)
    return node;

  return node;
}

} // namespace ila

