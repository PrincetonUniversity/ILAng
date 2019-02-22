/// \file
/// The implementation of the JSON to ILA deserializer.

#include <cstdlib>
#include <ilang/ila/ast_fuse.h>
#include <ilang/ila/expr_fuse.h>
#include <ilang/portable/json_to_ila_deserializer.h>
#include <ilang/portable/serdes_config.h>
#include <ilang/util/log.h>
#include <vector>

namespace ilang {

typedef unsigned UID_t;
typedef size_t ID_t;

J2IDes::J2IDes() {}

J2IDes::~J2IDes() {}

J2IDesPtr J2IDes::New() { return std::make_shared<J2IDes>(); }

ExprPtr J2IDes::DesExpr(const json& j_expr, const InstrLvlAbsPtr& i_host) {
  // check if the expr has been des'ed
  auto id = j_expr.at(SERDES_EXPR_ID).get<ID_t>();
  auto pos = id_expr_map_.find(id);
  if (pos != id_expr_map_.end()) {
    return pos->second;
  }

  // j_expr has not been des'ed yet
  decltype(pos->second) i_expr = NULL;

  // expr ast type
  auto expr_uid = j_expr.at(SERDES_EXPR_UID).get<UID_t>();
  switch (expr_uid) {
  // deserialze variable
  case AST_UID_EXPR::VAR: {
    auto name = j_expr.at(SERDES_EXPR_NAME).get<std::string>();
    auto sort = j_expr.at(SERDES_EXPR_SORT);
    if (state_id_set_.find(id) != state_id_set_.end()) {
      i_expr = DesExprState(sort, name, i_host);
    } else {
      ILA_ASSERT(input_id_set_.find(id) != input_id_set_.end())
          << "State/input " << name << " not found.";
      i_expr = DesExprInput(sort, name, i_host);
    }
    break;
  }
  // deserialize constant
  case AST_UID_EXPR::CONST: {
    auto sort = j_expr.at(SERDES_EXPR_SORT);
    auto value = j_expr.at(SERDES_EXPR_VAL);
    i_expr = DesExprConst(sort, value);
    break;
  }
  // deserialize operator
  case AST_UID_EXPR::OP: {
    auto expr_op_uid = j_expr.at(SERDES_EXPR_OP).get<UID_t>();
    auto& j_arg_arr = j_expr.at(SERDES_EXPR_ARGS);
    auto& j_param_arr = j_expr.at(SERDES_EXPR_PARAMS);
    i_expr = DesExprOp(expr_op_uid, j_arg_arr, j_param_arr);
    break;
  }
  }; // switch expr_uid

  // book keeping
  ILA_NOT_NULL(i_expr);
  id_expr_map_.emplace(id, i_expr);
  return i_expr;
}

InstrPtr J2IDes::DesInstr(const json& j_instr,
                          const InstrLvlAbsPtr& i_host) const {
  auto name = j_instr.at(SERDES_INSTR_NAME).get<std::string>();
  auto instr = i_host->NewInstr(name);

  auto decode_id = j_instr.at(SERDES_INSTR_DECODE).get<ID_t>();
  auto decode_pos = id_expr_map_.find(decode_id);
  ILA_ASSERT(decode_pos != id_expr_map_.end())
      << "No decode found for instruction " << name;
  instr->set_decode(decode_pos->second);

  auto update = j_instr.at(SERDES_INSTR_UPDATE);
  for (auto i = 0; i < i_host->state_num(); i++) {
    auto state = i_host->state(i);
    // get the id of the update function
    auto next_id_it = update.find(state->name().str());
    ILA_ASSERT(next_id_it != update.end())
        << "Update ID not found for " << state;
    // get the expr of the update function
    auto next_expr_it = id_expr_map_.find(next_id_it.value());
    ILA_ASSERT(next_expr_it != id_expr_map_.end())
        << "Update Expr not found for " << state;
    // set the update function
    instr->set_update(state, next_expr_it->second);
  }
}

InstrLvlAbsPtr J2IDes::DesInstrLvlAbs(const json& j_ila) {
  auto name = j_ila.at(SERDES_ILA_NAME).get<std::string>();
  auto m = InstrLvlAbs::New(name); // XXX parent

  // input
  auto j_inp_arr = j_ila.at(SERDES_ILA_INPUT);
  for (auto inp_id : j_inp_arr) {
    input_id_set_.insert(inp_id.get<ID_t>());
  }

  // state
  auto j_state_arr = j_ila.at(SERDES_ILA_STATE);
  for (auto state_id : j_state_arr) {
    state_id_set_.insert(state_id.get<ID_t>());
  }

  // ast expressions
  auto j_expr_arr = j_ila.at(SERDES_ILA_AST);
  for (auto j_expr : j_expr_arr) {
    DesExpr(j_expr, m);
  }

  // fetch
  auto fetch_id = j_ila.at(SERDES_ILA_FETCH).get<ID_t>();
  auto fetch_it = id_expr_map_.find(fetch_id);
  ILA_ASSERT(fetch_it != id_expr_map_.end()) << "Fetch not found";
  m->SetFetch(fetch_it->second);

  // valid
  auto valid_id = j_ila.at(SERDES_ILA_VALID).get<ID_t>();
  auto valid_it = id_expr_map_.find(valid_id);
  ILA_ASSERT(valid_it != id_expr_map_.end()) << "Valid not found";
  m->SetValid(valid_it->second);

  // instructions
  auto j_instr_arr = j_ila.at(SERDES_ILA_INSTR);
  for (auto j_instr : j_instr_arr) {
    DesInstr(j_instr, m);
  }

  // init
  auto j_init_arr = j_ila.at(SERDES_ILA_INIT);
  for (auto j_init : j_init_arr) {
    auto init_expr_it = id_expr_map_.find(j_init.get<ID_t>());
    ILA_ASSERT(init_expr_it != id_expr_map_.end()) << "Init not found";
    m->AddInit(init_expr_it->second);
  }

  return m;
}

ExprPtr J2IDes::DesExprState(const json& j_sort, const std::string& name,
                             const InstrLvlAbsPtr& i_host) const {
  switch (j_sort.at(SERDES_SORT_UID).get<UID_t>()) {
  // bool
  case AST_UID_SORT::BOOL: {
    return i_host->NewBoolState(name);
  }
  // bit-vector
  case AST_UID_SORT::BV: {
    auto width = j_sort.at(SERDES_SORT_WIDTH).get<int>();
    return i_host->NewBvState(name, width);
  }
  // memory (array)
  case AST_UID_SORT::MEM: {
    auto addr_width = j_sort.at(SERDES_SORT_ADDR_WIDTH).get<int>();
    auto data_width = j_sort.at(SERDES_SORT_DATA_WIDTH).get<int>();
    return i_host->NewMemState(name, addr_width, data_width);
  }
  }; // seitch j_sort id
}

ExprPtr J2IDes::DesExprInput(const json& j_sort, const std::string& name,
                             const InstrLvlAbsPtr& i_host) const {
  switch (j_sort.at(SERDES_SORT_UID).get<UID_t>()) {
  // bool
  case AST_UID_SORT::BOOL: {
    return i_host->NewBoolInput(name);
  }
  // bit-vector
  case AST_UID_SORT::BV: {
    auto width = j_sort.at(SERDES_SORT_WIDTH).get<int>();
    return i_host->NewBvInput(name, width);
  }
  // memory (array)
  case AST_UID_SORT::MEM: {
    auto addr_width = j_sort.at(SERDES_SORT_ADDR_WIDTH).get<int>();
    auto data_width = j_sort.at(SERDES_SORT_DATA_WIDTH).get<int>();
    return i_host->NewMemInput(name, addr_width, data_width);
  }
  }; // switch j_sort id
}

ExprPtr J2IDes::DesExprConst(const json& j_sort, const json& j_val) const {
  switch (j_sort.at(SERDES_SORT_UID).get<UID_t>()) {
  // bool
  case AST_UID_SORT::BOOL: {
    auto value = j_val.at(SERDES_CONST_VAL).get<bool>();
    return ExprFuse::BoolConst(value);
  }
  // bit-vector
  case AST_UID_SORT::BV: {
    auto width = j_sort.at(SERDES_SORT_WIDTH).get<int>();
    auto value = j_val.at(SERDES_CONST_VAL).get<int>();
    return ExprFuse::BvConst(value, width);
  }
  // memory (array)
  case AST_UID_SORT::MEM: {
    auto addr_width = j_sort.at(SERDES_SORT_ADDR_WIDTH).get<int>();
    auto data_width = j_sort.at(SERDES_SORT_DATA_WIDTH).get<int>();

    auto default_value = j_val.at(SERDES_CONST_DEF).get<int>();
    auto j_value_map = j_val.at(SERDES_CONST_MAP);

    auto i_value_map = MemVal::MemValMap();
    for (auto it = j_value_map.begin(); it != j_value_map.end(); it++) {
      // for (auto& it : j_value_map) {
      auto addr_str = it.key();
      auto addr = std::atoi(addr_str.c_str());
      auto data = it.value();
      j_value_map[addr] = data;
    }
    auto mem_val = MemVal(default_value, j_value_map);

    return ExprFuse::MemConst(mem_val, addr_width, data_width);
  }
  }; // seitch j_sort id
}

ExprPtr J2IDes::DesExprOp(const unsigned& ast_expr_op_uid,
                          const json& j_arg_arr,
                          const json& j_param_arr) const {
  // arguments
  auto args = std::vector<ExprPtr>();
  for (auto it = j_arg_arr.begin(); it != j_arg_arr.end(); it++) {
    auto arg_id = (*it).get<ID_t>();
    auto arg_it = id_expr_map_.find(arg_id);
    ILA_ASSERT(arg_it != id_expr_map_.end()) << "Missing arg " << arg_id;
    args.push_back(arg_it->second);
  }
  // parameters
  auto params = std::vector<int>();
  for (auto it = j_param_arr.begin(); it != j_param_arr.end(); it++) {
    auto param = (*it).get<int>();
    params.push_back(param);
  }
  // construct ExprOp
  switch (ast_expr_op_uid) {
  case AST_UID_EXPR_OP::NEG: {
    return ExprFuse::Negate(args.at(0));
  }
  case AST_UID_EXPR_OP::NOT: {
    return ExprFuse::Not(args.at(0));
  }
  case AST_UID_EXPR_OP::COMPL: {
    return ExprFuse::Complement(args.at(0));
  }
  case AST_UID_EXPR_OP::AND: {
    return ExprFuse::And(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::OR: {
    return ExprFuse::Or(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::XOR: {
    return ExprFuse::Xor(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::SHL: {
    return ExprFuse::Shl(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::ASHR: {
    return ExprFuse::Ashr(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::LSHR: {
    return ExprFuse::Lshr(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::ADD: {
    return ExprFuse::Add(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::SUB: {
    return ExprFuse::Sub(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::EQ: {
    return ExprFuse::Eq(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::LT: {
    return ExprFuse::Lt(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::GT: {
    return ExprFuse::Gt(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::ULT: {
    return ExprFuse::Ult(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::UGT: {
    return ExprFuse::Ugt(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::LOAD: {
    return ExprFuse::Load(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::STORE: {
    return ExprFuse::Store(args.at(0), args.at(1), args.at(2));
  }
  case AST_UID_EXPR_OP::CONCAT: {
    return ExprFuse::Concat(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::EXTRACT: {
    return ExprFuse::Extract(args.at(0), params.at(0), params.at(1));
  }
  case AST_UID_EXPR_OP::ZEXT: {
    return ExprFuse::ZExt(args.at(0), params.at(0));
  }
  case AST_UID_EXPR_OP::SEXT: {
    return ExprFuse::SExt(args.at(0), params.at(0));
  }
  case AST_UID_EXPR_OP::IMPLY: {
    return ExprFuse::Imply(args.at(0), args.at(1));
  }
  case AST_UID_EXPR_OP::ITE: {
    return ExprFuse::Ite(args.at(0), args.at(1), args.at(2));
  }
  default: {
    ILA_ERROR << "No Ser/Des (yet) for op " << ast_expr_op_uid;
    return NULL;
  }
  }; // switch ast_expr_op_uid
}

}; // namespace ilang

