/// \file
/// The implementation of the ILA to JSON serializer.

#include <ilang/target-json/ila_to_json_serializer.h>

#include <ilang/ila/ast_hub.h>
#include <ilang/target-json/serdes_config.h>
#include <ilang/util/log.h>

namespace ilang {

//
// type and helpers
//

typedef size_t ID_t;

inline ExprTypeId GetUidExpr(const ExprPtr& expr) {
  return expr->is_var() ? ExprTypeId::kVar
                        : expr->is_op() ? ExprTypeId::kOp : ExprTypeId::kConst;
}

//
// I2JSer
//

I2JSer::I2JSer() {}

I2JSer::~I2JSer() {}

I2JSerPtr I2JSer::New() { return std::make_shared<I2JSer>(); }

json I2JSer::SerInstrLvlAbs(const InstrLvlAbsPtr& i_ila) {
  ILA_NOT_NULL(i_ila);

  auto j_global = json::object();

  // top-level ila
  auto j_top = SerInstrLvlAbsNoAst(i_ila);
  j_global.emplace(SERDES_GLOBAL_TOP, j_top);

  // all ast expressions
  ILA_DLOG("Portable") << "Serialize all ast nodes";
  j_global.emplace(SERDES_GLOBAL_AST, j_expr_arr_);

  // all func
  ILA_DLOG("Portable") << "Serialize all func";
  j_global.emplace(SERDES_GLOBAL_FUNC, j_func_arr_);

  return j_global;
}

json I2JSer::SerSort(const SortPtr& i_sort) const {
  auto j_sort = json::object();

  // sort type
  auto sort_uid = i_sort->uid();
  j_sort.emplace(SERDES_SORT_UID, sort_uid);

  switch (sort_uid) {
  // bit-vector
  case AstUidSort::kBv: {
    j_sort.emplace(SERDES_SORT_WIDTH, i_sort->bit_width());
    break;
  }
  // memory
  case AstUidSort::kMem: {
    j_sort.emplace(SERDES_SORT_ADDR_WIDTH, i_sort->addr_width());
    j_sort.emplace(SERDES_SORT_DATA_WIDTH, i_sort->data_width());
    break;
  }
  // boolean
  default: {
    ILA_ASSERT(i_sort->is_bool()) << "unknown sort " << i_sort;
    break;
  }
  }; // switch sort_uid

  return j_sort;
}

json I2JSer::SerFunc(const FuncPtr& i_func) {
  // func id
  auto id = i_func->name().id();

  // check if i_func has been visited
  auto pos = func_id_idx_map_.find(id);
  if (pos != func_id_idx_map_.end()) {
    return j_func_arr_.at(pos->second);
  }

  // i_func has not been serialized yet, create a new JSON object
  auto j_func = json::object();
  j_func.emplace(SERDES_FUNC_ID, id);

  // func name
  auto func_name = i_func->name().str();
  j_func.emplace(SERDES_FUNC_NAME, func_name);

  // output sort (range)
  auto i_out_sort = i_func->out();
  auto j_out_sort = SerSort(i_out_sort);
  j_func.emplace(SERDES_FUNC_OUT, j_out_sort);

  // arguments sort (domain)
  auto j_arg_sort_arr = json::array();
  for (decltype(i_func->arg_num()) i = 0; i < i_func->arg_num(); i++) {
    auto i_arg_sort = i_func->arg(i);
    auto j_arg_sort = SerSort(i_arg_sort);
    j_arg_sort_arr.push_back(j_arg_sort);
  }
  j_func.emplace(SERDES_FUNC_ARGS, j_arg_sort_arr);

  // book keeping
  j_func_arr_.push_back(j_func);

  return j_func;
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

json I2JSer::SerConstVal(const ExprPtr& i_expr) const {
  auto i_expr_const = std::static_pointer_cast<ExprConst>(i_expr);
  ILA_NOT_NULL(i_expr_const);

  // create a new JSON object
  auto j_val = json::object();

  if (i_expr->is_bool()) { // Boolean constant
    j_val.emplace(SERDES_CONST_VAL, i_expr_const->val_bool()->val());
  } else if (i_expr->is_bv()) { // bit-vector constant
    j_val.emplace(SERDES_CONST_VAL, i_expr_const->val_bv()->val());
  } else { // memory (array) constant
    auto mem_val = i_expr_const->val_mem();
    j_val.emplace(SERDES_CONST_DEF, mem_val->def_val());

    auto j_val_map = json::object();
    for (const auto& it : mem_val->val_map()) {
      auto addr_str = std::to_string(it.first);
      j_val_map.emplace(addr_str, it.second);
    }
    j_val.emplace(SERDES_CONST_MAP, j_val_map);
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
  j_expr.emplace(SERDES_EXPR_ID, id);

  // expr ast type
  auto expr_uid = GetUidExpr(i_expr);
  j_expr.emplace(SERDES_EXPR_UID, expr_uid);

  switch (expr_uid) {
  // serialize variable
  case ExprTypeId::kVar: {
    j_expr.emplace(SERDES_EXPR_SORT, SerSort(i_expr->sort()));
    j_expr.emplace(SERDES_EXPR_NAME, i_expr->name().str());
    break;
  }
  // serialize constant
  case ExprTypeId::kConst: {
    j_expr.emplace(SERDES_EXPR_SORT, SerSort(i_expr->sort()));
    j_expr.emplace(SERDES_EXPR_VAL, SerConstVal(i_expr));
    break;
  }
  // serialize operator
  case ExprTypeId::kOp: {
    // op
    auto expr_op_uid = asthub::GetUidExprOp(i_expr);
    j_expr.emplace(SERDES_EXPR_OP, expr_op_uid);

    // args
    auto j_arg_arr = json::array();
    for (decltype(i_expr->arg_num()) i = 0; i < i_expr->arg_num(); i++) {
      auto arg_id = i_expr->arg(i)->name().id();
      j_arg_arr.push_back(arg_id);
    }
    j_expr.emplace(SERDES_EXPR_ARGS, j_arg_arr);

    // params
    auto j_param_arr = json::array();
    for (decltype(i_expr->param_num()) i = 0; i < i_expr->param_num(); i++) {
      j_param_arr.push_back(i_expr->param(i));
    }
    j_expr.emplace(SERDES_EXPR_PARAMS, j_param_arr);

    // only for apply function
    if (expr_op_uid == AstUidExprOp::kApplyFunc) {
      auto i_expr_op_appfunc = std::static_pointer_cast<ExprOpAppFunc>(i_expr);
      ILA_NOT_NULL(i_expr_op_appfunc);
      auto j_func = SerFunc(i_expr_op_appfunc->func());
      j_expr.emplace(SERDES_EXPR_FUNC, j_func.at(SERDES_FUNC_ID).get<ID_t>());
    }
    break;
  }
  }; // switch expr_uid

  // book keeping
  id_idx_map_.emplace(id, j_expr_arr_.size());
  j_expr_arr_.push_back(j_expr);

  return j_expr;
}

json I2JSer::SerInstr(const InstrPtr& i_instr) {
  ILA_NOT_NULL(i_instr);

  // create a new JSON object
  auto j_instr = json::object();
  j_instr.emplace(SERDES_INSTR_NAME, i_instr->name().str());

  // decode
  auto j_decode = SerExpr(i_instr->decode());
  j_instr.emplace(SERDES_INSTR_DECODE, j_decode.at(SERDES_EXPR_ID).get<ID_t>());

  // state updates
  auto j_update = json::object();
  auto host = i_instr->host();
  for (decltype(host->state_num()) i = 0; i < host->state_num(); i++) {
    auto i_state = host->state(i);
    auto i_next = i_instr->update(i_state);
    i_next = i_next ? i_next : i_state; // NULL is unchanged
    auto j_next = SerExpr(i_next);
    j_update.emplace(i_state->name().str(),
                     j_next.at(SERDES_EXPR_ID).get<ID_t>());
  }
  j_instr.emplace(SERDES_INSTR_UPDATE, j_update);

  return j_instr;
}

json I2JSer::SerInstrLvlAbsNoAst(const InstrLvlAbsPtr& i_ila) {
  ILA_NOT_NULL(i_ila);

  // create a new JSON object
  auto j_ila = json::object();
  j_ila.emplace(SERDES_ILA_NAME, i_ila->name().str());

  // input
  ILA_DLOG("Portable") << "Serialize input variables of " << i_ila;
  auto j_inp_arr = json::array();
  for (decltype(i_ila->input_num()) i = 0; i < i_ila->input_num(); i++) {
    auto j_inp = SerExpr(i_ila->input(i));
    j_inp_arr.push_back(j_inp.at(SERDES_EXPR_ID).get<ID_t>());
  }
  j_ila.emplace(SERDES_ILA_INPUT, j_inp_arr);

  // state
  ILA_DLOG("Portable") << "Serialize state variables of " << i_ila;
  auto j_state_arr = json::array();
  for (decltype(i_ila->state_num()) i = 0; i < i_ila->state_num(); i++) {
    auto j_state = SerExpr(i_ila->state(i));
    j_state_arr.push_back(j_state.at(SERDES_EXPR_ID).get<ID_t>());
  }
  j_ila.emplace(SERDES_ILA_STATE, j_state_arr);

  // fetch
  ILA_DLOG("Portable") << "Serialize fetch function of " << i_ila;
  if (i_ila->fetch()) {
    auto j_fetch = SerExpr(i_ila->fetch());
    j_ila.emplace(SERDES_ILA_FETCH, j_fetch.at(SERDES_EXPR_ID).get<ID_t>());
  }

  // valid
  ILA_DLOG("Portable") << "Serialize valid function of " << i_ila;
  auto j_valid = SerExpr(i_ila->valid());
  j_ila.emplace(SERDES_ILA_VALID, j_valid.at(SERDES_EXPR_ID).get<ID_t>());

  // instructions
  ILA_DLOG("Portable") << "Serialize instructions of " << i_ila;
  auto j_instr_arr = json::array();
  for (decltype(i_ila->instr_num()) i = 0; i < i_ila->instr_num(); i++) {
    j_instr_arr.push_back(SerInstr(i_ila->instr(i)));
  }
  j_ila.emplace(SERDES_ILA_INSTR, j_instr_arr);

  // init
  ILA_DLOG("Portable") << "Serialize initial condition of " << i_ila;
  auto j_init_arr = json::array();
  for (decltype(i_ila->init_num()) i = 0; i < i_ila->init_num(); i++) {
    auto j_init = SerExpr(i_ila->init(i));
    j_init_arr.push_back(j_init.at(SERDES_EXPR_ID).get<ID_t>());
  }
  j_ila.emplace(SERDES_ILA_INIT, j_init_arr);

  // child
  ILA_DLOG("Portable") << "Serialize child ILAs of " << i_ila;
  auto j_child_arr = json::array();
  for (decltype(i_ila->child_num()) i = 0; i < i_ila->child_num(); i++) {
    auto j_child = SerInstrLvlAbsNoAst(i_ila->child(i));
    j_child_arr.push_back(j_child);
  }
  j_ila.emplace(SERDES_ILA_CHILD, j_child_arr);

  return j_ila;
}

} // namespace ilang
