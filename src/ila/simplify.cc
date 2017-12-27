/// \file
/// Source for the class ExprSimplifier

#include "ila/simplify.h"

namespace ila {

ExprSimplifier::ExprSimplifier() {}

ExprSimplifier::~ExprSimplifier() {}

void ExprSimplifier::Reset() { map_.clear(); }

ExprPtr ExprSimplifier::Simplify(const ExprPtr node) {
  // TODO
  return node;
}

} // namespace ila

