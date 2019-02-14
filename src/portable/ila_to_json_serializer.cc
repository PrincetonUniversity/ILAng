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

  // sort type
  auto sort_uid = GetUidSort(i_sort);
  j_sort.emplace("sort_uid", sort_uid);

  switch (sort_uid) {
  // bit-vector
  case AST_UID_SORT::BV: {
    j_sort.emplace("width", i_sort->bit_width());
    break;
  }
  // memory
  case AST_UID_SORT::MEM: {
    j_sort.emplace("addr_width", i_sort->addr_width());
    j_sort.emplace("data_width", i_sort->data_width());
    break;
  }
  }; // switch sort_uid

  return j_sort;
}

json I2JSer::SerExpr(const ExprPtr& i_expr) {
  ILA_NOT_NULL(i_expr);

  // Ser i_expr and all its subexpressions
  auto SerExprKernel = [this](const ExprPtr& e) { SerExprUnit(e); };
  i_expr->DepthFirstVisit(SerExprKernel);

  // return the Ser'ed object
  auto id = i_expr->name().id();
  auto pos = id_idx_map_.find(id);
  ILA_ASSERT(pos != id_idx_map_.end()) << "Fail Ser'ing " << i_expr;
  return j_expr_arr_.at(pos->second);
}

json I2JSer::SerInstr(const InstrPtr& i_instr) {
  ILA_NOT_NULL(i_instr);

  // create a new JSON object
  auto j_instr = json::object();
  j_instr.emplace("name", i_instr->name().str());

  // decode
  auto j_decode = SerExpr(i_instr->decode());
  j_instr.emplace("decode", j_decode);

  // state updates
  auto j_update = json::object();
  auto host = i_instr->host();
  for (auto i = 0; i < host->state_num(); i++) {
    auto i_state = host->state(i);
    auto i_next = i_instr->update(i_state);
    auto j_next = SerExpr(i_next);
    j_update.emplace(i_state->name().str(), j_next);
  }
  j_instr.emplace("update", j_update);

  return j_instr;
}

json I2JSer::SerInstrLvlAbs(const InstrLvlAbsPtr& i_ila) {
  ILA_NOT_NULL(i_ila);

  // create a new JSON object
  auto j_ila = json::object();
  j_ila.emplace("name", i_ila->name().str());

  // input
  auto j_inp_arr = json::array();
  for (auto i = 0; i < i_ila->input_num(); i++) {
    j_inp_arr.push_back(SerExpr(i_ila->input(i)));
  }
  j_ila.emplace("input", j_inp_arr);

  // state
  auto j_state_arr = json::array();
  for (auto i = 0; i < i_ila->state_num(); i++) {
    j_state_arr.push_back(SerExpr(i_ila->state(i)));
  }
  j_ila.emplace("state", j_state_arr);

  // fetch
  auto j_fetch = SerExpr(i_ila->fetch());
  j_ila.emplace("fetch", j_fetch);

  // valid
  auto j_valid = SerExpr(i_ila->valid());
  j_ila.emplace("valid", j_valid);

  // instructions
  auto j_instr_arr = json::array();
  for (auto i = 0; i < i_ila->instr_num(); i++) {
    j_instr_arr.push_back(SerInstr(i_ila->instr(i)));
  }
  j_ila.emplace("instr", j_instr_arr);

  // init
  auto j_init_arr = json::array();
  for (auto i = 0; i < i_ila->init_num(); i++) {
    j_init_arr.push_back(SerExpr(i_ila->init(i)));
  }
  j_ila.emplace("init", j_init_arr);

  // XXX child

  // all ast expressions
  j_ila.emplace("ast", j_expr_arr_);

  // ILA_DLOG("Portable") << j_ila.dump(2) << std::endl;

  return j_ila;
}

json I2JSer::SerConstVal(const ExprPtr& i_expr) const {
  auto i_expr_const = std::dynamic_pointer_cast<ExprConst>(i_expr);
  ILA_NOT_NULL(i_expr_const);

  // create a new JSON object
  auto j_val = json::object();

  if (i_expr->is_bool()) { // Boolean constant
    j_val.emplace("val", i_expr_const->val_bool()->val());
  } else if (i_expr->is_bv()) { // bit-vector constant
    j_val.emplace("val", i_expr_const->val_bv()->val());
  } else { // memory (array) constant
    auto mem_val = i_expr_const->val_mem();
    j_val.emplace("default", mem_val->def_val());

    auto j_val_map = json::object();
    for (auto it : mem_val->val_map()) {
      auto addr_str = std::to_string(it.first);
      j_val_map.emplace(addr_str, it.second);
    }
    j_val.emplace("map", j_val_map);
  }

  return j_val;
}

json I2JSer::SerExprUnit(const ExprPtr& i_expr) {
  // expr node id
  auto id = i_expr->name().id();

  // check if i_expr has been visited
  auto pos = id_idx_map_.find(id);
  if (pos != id_idx_map_.end()) {
    return j_expr_arr_.at(pos->second);
  }

  // i_expr has not been serialized yet, create a new JSON object
  auto j_expr = json::object();
  j_expr.emplace("id", id);

  // expr ast type
  auto expr_uid = GetUidExpr(i_expr);
  j_expr.emplace("expr_uid", expr_uid);

  switch (expr_uid) {
  // serialize var
  case AST_UID_EXPR::VAR: {
    j_expr.emplace("sort", SerSort(i_expr->sort()));
    j_expr.emplace("name", i_expr->name().str());
    break;
  }
  // serialize constant
  case AST_UID_EXPR::CONST: {
    j_expr.emplace("sort", SerSort(i_expr->sort()));
    j_expr.emplace("val", SerConstVal(i_expr));
    break;
  }
  // serialize operator
  case AST_UID_EXPR::OP: {
    // op
    auto expr_op_uid = GetUidExprOp(i_expr);
    j_expr.emplace("op", expr_op_uid);

    // args
    auto j_arg_arr = json::array();
    for (auto i = 0; i < i_expr->arg_num(); i++) {
      auto arg_id = i_expr->arg(i)->name().id();
      j_arg_arr.push_back(arg_id);
    }
    j_expr.emplace("args", j_arg_arr);

    // params
    auto j_param_arr = json::array();
    for (auto i = 0; i < i_expr->param_num(); i++) {
      j_param_arr.push_back(i_expr->param(i));
    }
    j_expr.emplace("params", j_param_arr);
    break;
  }
  }; // switch expr_uid

  // book keeping
  id_idx_map_.emplace(id, j_expr_arr_.size());
  j_expr_arr_.push_back(j_expr);

  return j_expr;
}

}; // namespace ilang

