/// \file
/// Source for the class ExprMngr and the corresponding hash

#include "ila/hash_ast.h"

namespace ila {

size_t AstHash::operator()(const ExprPtr n) const {
  if (n->is_op()) { // ExprOp
    auto n_op = std::dynamic_pointer_cast<ExprOp>(n);
    ILA_ASSERT(n_op) << "Dynamic cast fail for ExprOp " << n;
    size_t hash = std::hash<std::string>{}(n_op->op_name());
    for (size_t i = 0; i != n->arg_num(); i++) {
      auto arg_hash = (*this)(n->arg(i));
      hash = arg_hash ^ (hash << 1);
    }
    for (size_t i = 0; i != n->param_num(); i++) {
      auto param_hash = static_cast<size_t>(n->param(i));
      hash = param_hash ^ (hash << 1);
    }
    return hash;
  } else if (n->is_var()) { // ExprVar
    return n->name().id();
  } else { // ExprConst
    ILA_ASSERT(n->is_const()) << "Unrecognized expr type";
    auto n_const = std::dynamic_pointer_cast<ExprConst>(n);
    ILA_ASSERT(n_const) << "Dynamic cast fail for ExprConst " << n;
    if (n_const->is_bool()) {
      return std::hash<std::string>{}(n_const->val_bool()->str());
    } else if (n_const->is_bv()) {
      return std::hash<std::string>{}(n_const->val_bv()->str());
    } else {
      ILA_ASSERT(n_const->is_mem()) << "Unrecognized constant type";
      // mem constant sharing not supported yet
      return n_const->name().id();
    }
  }
}

ExprMngr::ExprMngr() {}

ExprMngr::~ExprMngr() {}

ExprMngrPtr ExprMngr::New() { return std::make_shared<ExprMngr>(); }

void ExprMngr::clear() { map_.clear(); }

ExprPtr ExprMngr::Simplify(const ExprPtr node, bool simplify) {
  if (!simplify)
    return node;

  node->DFV(*this);

  auto pos = map_.find(node);
  ILA_ASSERT(pos != map_.end()) << "Representative not found for " << node;
  return pos->second;
}

void ExprMngr::operator()(const ExprPtr node) {
  ExprPtrVec reps;
  // replace child (must exist)
  for (size_t i = 0; i != node->arg_num(); i++) {
    auto arg_i = node->arg(i);
    auto pos_i = map_.find(arg_i);
    ILA_ASSERT(pos_i != map_.end()) << "Child arg representative not found.";
    reps.push_back(pos_i->second);
  }
  node->set_args(reps);

  auto pos = map_.find(node);
  // new node
  if (pos == map_.end()) {
    map_.insert({node, node});
  }
}

} // namespace ila

