/// \file
/// Source for the class ExprMngr and the corresponding hash

#include <ilang/ila/hash_ast.h>

#include <fmt/format.h>
#include <functional>

#include <ilang/ila/ast_fuse.h>
#include <ilang/util/log.h>

namespace ilang {

ExprMngr::ExprMngr() {}

ExprMngr::~ExprMngr() {}

ExprMngrPtr ExprMngr::New() { return std::make_shared<ExprMngr>(); }

void ExprMngr::clear() { map_.clear(); }

ExprPtr ExprMngr::GetRep(const ExprPtr& node) {
  node->DepthFirstVisit(*this);

  auto pos = map_.find(Hash(node));
  ILA_ASSERT(pos != map_.end()) << "Representative not found for " << node;
  if (pos->second != node) {
    ILA_DLOG("HashAst") << "Replace " << node << " with " << pos->second;
  }
  return pos->second;
}

void ExprMngr::operator()(const ExprPtr& node) {
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
    map_.emplace(hash, node);
  }
}

std::string ExprMngr::Hash(const ExprPtr& expr) {
  static const char* template_var = "var::{id}";
  static const char* template_const = "const::{sort}::{value}";
  static const char* template_op = "op::{op}::{arg_list}::{param_list}";

  if (expr->is_var()) {
    return fmt::format(template_var, fmt::arg("id", expr->name().id()));

  } else if (expr->is_const()) {
    auto const_expr = std::static_pointer_cast<ExprConst>(expr);

    std::string value = std::to_string(expr->name().id());
    if (expr->is_bool()) {
      value = const_expr->val_bool()->str();
    } else if (expr->is_bv()) {
      value = fmt::format("{}_{}", const_expr->val_bv()->val(),
                          expr->sort()->bit_width());
    }
    // skip sharing memory constants

    return fmt::format(template_const,
                       fmt::arg("sort", GetUidSort(expr->sort())),
                       fmt::arg("value", value));
  } else {
    ILA_ASSERT(expr->is_op());
    std::vector<size_t> arg_list;
    for (size_t i = 0; i < expr->arg_num(); i++) {
      arg_list.push_back(expr->arg(i)->name().id());
    }

    std::vector<size_t> param_list;
    for (size_t i = 0; i < expr->param_num(); i++) {
      param_list.push_back(expr->param(i));
    }

    return fmt::format(template_op, fmt::arg("op", GetUidExprOp(expr)),
                       fmt::arg("arg_list", fmt::join(arg_list, ",")),
                       fmt::arg("param_list", fmt::join(param_list, ",")));
  }
}

} // namespace ilang
