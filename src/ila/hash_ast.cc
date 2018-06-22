/// \file
/// Source for the class ExprMngr and the corresponding hash

// XXX Current replacing is not efficient.

#include "ila/hash_ast.h"
#include "util/log.h"

namespace ila {

ExprMngr::ExprMngr() {}

ExprMngr::~ExprMngr() {}

ExprMngrPtr ExprMngr::New() { return std::make_shared<ExprMngr>(); }

void ExprMngr::clear() { map_.clear(); }

ExprPtr ExprMngr::GetRep(const ExprPtr node) {
  node->DepthFirstVisit(*this);

  auto pos = map_.find(Hash(node));
  ILA_ASSERT(pos != map_.end()) << "Representative not found for " << node;
  if (pos->second != node) {
    ILA_DLOG("HashAst") << "Replace " << node << " with " << pos->second;
  }
  return pos->second;
}

void ExprMngr::operator()(const ExprPtr node) {
  ExprPtrVec reps;
  // replace child (must exist)
  for (size_t i = 0; i != node->arg_num(); i++) {
    auto arg_i = node->arg(i);
    auto pos_i = map_.find(Hash(arg_i));
    ILA_ASSERT(pos_i != map_.end()) << "Child arg representative not found.";
    reps.push_back(pos_i->second);
    if (pos_i->second != arg_i) {
      ILA_DLOG("HashAst") << "Replace " << arg_i << " with " << pos_i->second;
    }
  }
  node->set_args(reps);

  auto hash = Hash(node);
  ILA_DLOG("HashAst") << "Visit " << node << " as " << hash;
  auto pos = map_.find(hash);
  // new node
  if (pos == map_.end()) {
    map_.insert({hash, node});
  }
}

std::string ExprMngr::Hash(const ExprPtr n) const {
  if (n->is_op()) { // ExprOp
    auto n_op = std::dynamic_pointer_cast<ExprOp>(n);
    ILA_ASSERT(n_op) << "Dynamic cast fail for ExprOp " << n;

    std::string hash = n_op->op_name(); // HZ Question: I think this is very dangerous! 
    for (size_t i = 0; i != n->arg_num(); i++) {
      hash += n->arg(i)->name().str();
    }
    for (size_t i = 0; i != n->param_num(); i++) {
      hash += std::to_string(n->param(i));
    }

    return hash;
  } else if (n->is_var()) { // ExprVar
    return n->name().str();
  } else { // ExprConst
    ILA_ASSERT(n->is_const()) << "Unrecognized expr type";
    auto n_const = std::dynamic_pointer_cast<ExprConst>(n);
    ILA_ASSERT(n_const) << "Dynamic cast fail for ExprConst " << n;

    if (n_const->is_bool()) {
      return n_const->val_bool()->str();
    } else if (n_const->is_bv()) {
      return n_const->val_bv()->str() + "_" +
             std::to_string(n_const->sort()->bit_width());
    } else {
      ILA_ASSERT(n_const->is_mem()) << "Unrecognized constant type";
      // mem constant sharing not supported yet
      return n_const->name().str();
    }
  }
}

} // namespace ila

