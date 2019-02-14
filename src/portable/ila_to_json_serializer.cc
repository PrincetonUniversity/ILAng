/// \file
/// The implementation of the ILA to JSON serializer.

#include <ilang/ila/ast_fuse.h>
#include <ilang/portable/ila_to_json_serializer.h>
#include <ilang/util/log.h>

namespace ilang {

I2JSer::I2JSer() {}

I2JSer::~I2JSer() {}

I2JSerPtr I2JSer::New() { return std::make_shared<I2JSer>(); }

json I2JSer::SerSort(const SortPtr& i_sort) const {
  auto j_sort = json::object();

  auto sort_uid = GetUidSort(i_sort);
  j_sort.emplace("sort_uid", sort_uid);

  switch (sort_uid) {
  case AST_UID_SORT::BV: {
    j_sort.emplace("width", i_sort->bit_width());
  }
  case AST_UID_SORT::MEM: {
    j_sort.emplace("addr_width", i_sort->addr_width());
    j_sort.emplace("data_width", i_sort->data_width());
  }
  };

  return j_sort;
}

json I2JSer::SerExpr(const ExprPtr& i_expr) {
  // expr node id
  auto id = i_expr->name()->id();

  // check if i_expr has been visited
  auto pos = id_idx_map.find(id);
  if (pos != id_idx_map_.end()) {
    return j_expr_arr_.at(pos->second);
  }

  // i_expr has not been serialized yet, create a new JSON object
  auto j_expr = json::object();
  j_expr.emplace("id", id);

  // expr ast type
  auto expr_uid = GetUidExpr(i_expr);
  j_expr.emplace("expr_uid", expr_uid);

  // serialize based on different expr ast type
  switch (expr_uid) {

  case AST_UID_EXPR::VAR: {
    j_expr.emplace("sort", SerSort(i_expr->sort()));
    j_expr.emplace("name", i_expr->name().str());
  }

  case AST_UID_EXPR::CONST: {
    j_expr.emplace("sort", SerSort(i_expr->sort()));
    j_expr.emplace("value", SerConstVal(i_expr));
  }

  case AST_UID_EXPR::OP: {
    // op
    auto expr_op_uid = GetUidExprOp(i_expr);
    j_expr.emplace("op_uid", expr_op_uid);

    // args
    auto j_arg_arr = json::array();
    for (auto i = 0; i < i_expr->arg_num(); i++) {
      auto arg_id = i_expr->arg(i)->id();
      auto arg_pos = id_idx_map_.find(arg_id);
      ILA_ASSERT(arg_pos != id_idx_map_.end())
          << "Fail serializing " << i_expr << " at arg " << i;
      auto arg_json = j_expr_arr_.at(arg_pos->second);
      j_arg_arr.push_back(arg_json);
    }
    j_expr.emplace("arg_arr", j_arg_arr);

    // params
    auto j_param_arr = json::array();
    for (auto i = 0; i < i_expr->param_num(); i++) {
      j_param_arr.push_back(i_expr->param(i));
    }
    j_expr.emplace("param_arr", j_param_arr);
  }
  };

  return j_expr;
}

json I2JSer::SerInstrLvlAbs(const InstrLvlAbsPtr& i_ila) {
  auto j_ila = json::object();

  j_ila["name"] = i_ila->name().str();

  // input
  auto inp_arr_j = json::array();
  for (auto i = 0; i < i_ila->input_num(); i++) {
    inp_arr_j.push_back(SerExpr(i_ila->input(i)));
  }

  j_ila["inputs"] = inp_arr_j;

  // state var

  // fetch
  // valid

  // XXX child is serialized externally

  ILA_DLOG("Portable") << j_ila.dump(2) << std::endl;

  return j_ila;
}

json I2JSer::SerConstVal(const ExprPtr& i_expr) const {
  auto i_expr_const = std::dynamic_pointer_cast<ExprConst>(i_expr);
  ILA_NOT_NULL(i_expr_const);

  auto j_val = json::object();

  if (i_expr->is_bool()) {
    j_val.emplace("val", i_expr_const->val_bool()->val());
  } else if (i->expr->is_bv()) {
    j_val.emplace("val", i_expr_const->val_bv()->val());
  } else {
    auto mem_val = i_expr_const->val_mem();
    j_val.emplace("default", mem_val->def_val());

    auto j_val_map = json::object();
    for (auto it : mem_val->val_map()) {
      auto addr_str = std::string(it.first);
      j_val_map.emplace(addr_str, it.second);
    }
    j_val.emplace("map", j_val_map);
  }

  return j_val;
}

}; // namespace ilang

