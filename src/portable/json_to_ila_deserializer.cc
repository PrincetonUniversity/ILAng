/// \file
/// The implementation of the JSON to ILA deserializer.

#include <cstdlib>
#include <ilang/ila/ast_fuse.h>
#include <ilang/portable/json_to_ila_deserializer.h>
#include <ilang/portable/serdes_config.h>
#include <ilang/util/log.h>

namespace ilang {

typedef unsigned UID_t;
typedef size_t ID_t;

J2IDes::J2IDes() {}

J2IDes::~J2IDes() {}

J2IDesPtr J2IDes::New() { return std::make_shared<J2IDes>(); }

#if 0
SortPtr J2IDes::DesSort(const json& j_sort) const {
  switch (j_sort.at(SERDES_SORT_UID).get<UID_t>()) {
  case AST_UID_SORT::BOOL: {
    return Sort::MakeBoolSort();
  }
  case AST_UID_SORT::BV: {
    // auto width = j_sort.at(SERDES_SORT_WIDTH).get<int>();
    auto width = j_sort.at(SERDES_SORT_WIDTH).get<int>();
    return Sort::MakeBvSort(width);
  }
  case AST_UID_SORT::MEM: {
    auto addr_width = j_sort.at(SERDES_SORT_ADDR_WIDTH).get<int>();
    auto data_width = j_sort.at(SERDES_SORT_DATA_WIDTH).get<int>();
    return Sort::MakeMemSort(addr_width, data_width);
  }
  };
}
#endif

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
      i_expr = DesExprState(name, sort, i_host);
    } else {
      ILA_ASSERT(input_id_set_.find(id) != input_id_set_.end())
          << "State/input " << name << " not found.";
      i_expr = DesExprInput(name, sort, i_host);
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
  id_expr_map_.emplace(id, i_expr);
  return i_expr;
}

InstrPtr J2IDes::DesInstr(const json& j_instr,
                          const InstrLvlAbsPtr& i_host) const {
  return NULL;
  //
}

InstrLvlAbsPtr J2IDes::DesInstrLvlAbs(const json& j_ila) {
  // update input state set
  return NULL;
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
  default: {
    ILA_ERROR << "Unknown sort for input " << name;
    return NULL;
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
  return NULL;
}

}; // namespace ilang

