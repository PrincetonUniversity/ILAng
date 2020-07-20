/// \file
/// The implementation of the JSON to ILA deserializer.

#include <ilang/target-json/json_to_ila_deserializer.h>

#include <cstdlib>
#include <unordered_set>
#include <vector>

#include <ilang/ila/ast_hub.h>
#include <ilang/target-json/serdes_config.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

typedef size_t UID_t;
typedef size_t ID_t;

J2IDes::J2IDes() {}

J2IDes::~J2IDes() {}

J2IDesPtr J2IDes::New() { return std::make_shared<J2IDes>(); }

InstrLvlAbsPtr J2IDes::DesInstrLvlAbs(const json& j_global) {
  auto j_expr_arr = j_global.at(SERDES_GLOBAL_AST);
  auto j_func_arr = j_global.at(SERDES_GLOBAL_FUNC);

  // extract hier structure and set up state/input
  auto j_top = j_global.at(SERDES_GLOBAL_TOP);
  DesVarHier(j_top, j_expr_arr, nullptr);

  // func
  ILA_DLOG("Portable") << "Deserialize all uninterpreted functions";
  for (const auto& j_func : j_func_arr) {
    DesFunc(j_func);
  }

  // ast expressions
  ILA_DLOG("Portable") << "Deserialize all ast nodes";
  for (const auto& j_expr : j_expr_arr) {
    DesExpr(j_expr);
  }

  // extract ila info
  DesIlaHier(j_top);

  // get the top-level ila
  auto name = j_top.at(SERDES_ILA_NAME).get<std::string>();
  auto pos = ila_name_ptr_map_.find(name);
  ILA_ASSERT(pos != ila_name_ptr_map_.end()) << name;
  auto top_ila = pos->second;
  return top_ila;
}

SortPtr J2IDes::DesSort(const json& j_sort) {
  switch (j_sort.at(SERDES_SORT_UID).get<UID_t>()) {
  // bool
  case AstUidSort::kBool: {
    return Sort::MakeBoolSort();
  }
  // bit-vector
  case AstUidSort::kBv: {
    auto width = j_sort.at(SERDES_SORT_WIDTH).get<int>();
    return Sort::MakeBvSort(width);
  }
  // memory (array)
  case AstUidSort::kMem: {
    auto addr_width = j_sort.at(SERDES_SORT_ADDR_WIDTH).get<int>();
    auto data_width = j_sort.at(SERDES_SORT_DATA_WIDTH).get<int>();
    return Sort::MakeMemSort(addr_width, data_width);
  }
  default: { return nullptr; }
  }; // switch j_sort id
}

FuncPtr J2IDes::DesFunc(const json& j_func) {
  // check if the func has been des'ed
  auto id = j_func.at(SERDES_FUNC_ID).get<ID_t>();
  auto pos = id_func_map_.find(id);
  if (pos != id_func_map_.end()) {
    return pos->second;
  } // j_func has not been des'ed yet

  // func name
  auto name = j_func.at(SERDES_FUNC_NAME).get<std::string>();

  // output sort (range)
  auto j_out_sort = j_func.at(SERDES_FUNC_OUT);
  auto i_out_sort = DesSort(j_out_sort);

  // argument sort (domain)
  auto j_arg_sort_arr = j_func.at(SERDES_FUNC_ARGS);
  auto i_arg_sort_vec = std::vector<SortPtr>();
  for (const auto& j_arg_sort : j_arg_sort_arr) {
    auto i_arg_sort = DesSort(j_arg_sort);
    i_arg_sort_vec.push_back(i_arg_sort);
  }

  // construct new func & book keeping
  auto i_func = Func::New(name, i_out_sort, i_arg_sort_vec);
  id_func_map_.emplace(id, i_func);

  return i_func;
}

ExprPtr J2IDes::DesExpr(const json& j_expr) {
  // check if the expr has been des'ed
  auto id = j_expr.at(SERDES_EXPR_ID).get<ID_t>();
  auto pos = id_expr_map_.find(id);
  if (pos != id_expr_map_.end()) {
    return pos->second;
  }

  // j_expr has not been des'ed yet
  decltype(pos->second) i_expr = nullptr;

  // expr ast type
  auto expr_uid = j_expr.at(SERDES_EXPR_UID).get<UID_t>();
  switch (expr_uid) {
  // deserialze variable
  case ExprTypeId::kVar: {
    ILA_ERROR << "Var w/o host " << j_expr.at(SERDES_EXPR_NAME);
    break;
  }
  // deserialize constant
  case ExprTypeId::kConst: {
    auto sort = j_expr.at(SERDES_EXPR_SORT);
    auto value = j_expr.at(SERDES_EXPR_VAL);
    i_expr = DesExprConst(sort, value);
    break;
  }
  // deserialize operator
  case ExprTypeId::kOp: {
    auto expr_op_uid = j_expr.at(SERDES_EXPR_OP).get<UID_t>();

    if (expr_op_uid == AstUidExprOp::kApplyFunc) {
      auto& j_func_id = j_expr.at(SERDES_EXPR_FUNC);
      auto& j_arg_arr = j_expr.at(SERDES_EXPR_ARGS);
      i_expr = DesExprOpAppFunc(j_func_id, j_arg_arr);
    } else {
      auto& j_arg_arr = j_expr.at(SERDES_EXPR_ARGS);
      auto& j_param_arr = j_expr.at(SERDES_EXPR_PARAMS);
      i_expr = DesExprOp(expr_op_uid, j_arg_arr, j_param_arr);
    }
    break;
  }
  }; // switch expr_uid

  // book keeping
  ILA_NOT_NULL(i_expr);
  id_expr_map_.emplace(id, i_expr);
  return i_expr;
}

ExprPtr J2IDes::DesExprState(const json& j_sort, const std::string& name,
                             const InstrLvlAbsPtr& i_host) const {
  switch (j_sort.at(SERDES_SORT_UID).get<UID_t>()) {
  // bool
  case AstUidSort::kBool: {
    return i_host->NewBoolState(name);
  }
  // bit-vector
  case AstUidSort::kBv: {
    auto width = j_sort.at(SERDES_SORT_WIDTH).get<int>();
    return i_host->NewBvState(name, width);
  }
  // memory (array)
  case AstUidSort::kMem: {
    auto addr_width = j_sort.at(SERDES_SORT_ADDR_WIDTH).get<int>();
    auto data_width = j_sort.at(SERDES_SORT_DATA_WIDTH).get<int>();
    return i_host->NewMemState(name, addr_width, data_width);
  }
  default: { return nullptr; }
  }; // switch j_sort id
}

ExprPtr J2IDes::DesExprInput(const json& j_sort, const std::string& name,
                             const InstrLvlAbsPtr& i_host) const {
  switch (j_sort.at(SERDES_SORT_UID).get<UID_t>()) {
  // bool
  case AstUidSort::kBool: {
    return i_host->NewBoolInput(name);
  }
  // bit-vector
  case AstUidSort::kBv: {
    auto width = j_sort.at(SERDES_SORT_WIDTH).get<int>();
    return i_host->NewBvInput(name, width);
  }
  // memory (array)
  case AstUidSort::kMem: {
    auto addr_width = j_sort.at(SERDES_SORT_ADDR_WIDTH).get<int>();
    auto data_width = j_sort.at(SERDES_SORT_DATA_WIDTH).get<int>();
    return i_host->NewMemInput(name, addr_width, data_width);
  }
  default: { return nullptr; }
  }; // switch j_sort id
}

ExprPtr J2IDes::DesExprConst(const json& j_sort, const json& j_val) const {
  switch (j_sort.at(SERDES_SORT_UID).get<UID_t>()) {
  // bool
  case AstUidSort::kBool: {
    auto value = j_val.at(SERDES_CONST_VAL).get<bool>();
    return asthub::BoolConst(value);
  }
  // bit-vector
  case AstUidSort::kBv: {
    auto width = j_sort.at(SERDES_SORT_WIDTH).get<int>();
    auto value = j_val.at(SERDES_CONST_VAL).get<BvValType>();
    return asthub::BvConst(value, width);
  }
  // memory (array)
  case AstUidSort::kMem: {
    auto addr_width = j_sort.at(SERDES_SORT_ADDR_WIDTH).get<int>();
    auto data_width = j_sort.at(SERDES_SORT_DATA_WIDTH).get<int>();

    auto default_value = j_val.at(SERDES_CONST_DEF).get<BvValType>();
    auto j_value_map = j_val.at(SERDES_CONST_MAP);

    auto i_value_map = MemVal::MemValMap();
    for (const auto& [addr_str, data] : j_value_map.items()) {
      auto addr_val = StrToULongLong(addr_str);
      i_value_map[addr_val] = data;
    }
    auto mem_val = MemVal(default_value, i_value_map);

    return asthub::MemConst(mem_val, addr_width, data_width);
  }
  default: { return nullptr; }
  }; // switch j_sort id
}

ExprPtr J2IDes::DesExprOp(const unsigned& ast_expr_op_uid,
                          const json& j_arg_arr,
                          const json& j_param_arr) const {
  // arguments
  auto args = std::vector<ExprPtr>();
  for (const auto& it : j_arg_arr) {
    auto arg_id = it.get<ID_t>();
    auto arg_it = id_expr_map_.find(arg_id);
    ILA_ASSERT(arg_it != id_expr_map_.end()) << "Missing arg " << arg_id;
    args.push_back(arg_it->second);
  }
  // parameters
  auto params = std::vector<int>();
  for (const auto& it : j_param_arr) {
    auto param = it.get<int>();
    params.push_back(param);
  }
  // construct ExprOp
  switch (ast_expr_op_uid) {
  case AstUidExprOp::kNegate: {
    return asthub::Negate(args.at(0));
  }
  case AstUidExprOp::kNot: {
    return asthub::Not(args.at(0));
  }
  case AstUidExprOp::kComplement: {
    return asthub::Complement(args.at(0));
  }
  case AstUidExprOp::kAnd: {
    return asthub::And(args.at(0), args.at(1));
  }
  case AstUidExprOp::kOr: {
    return asthub::Or(args.at(0), args.at(1));
  }
  case AstUidExprOp::kXor: {
    return asthub::Xor(args.at(0), args.at(1));
  }
  case AstUidExprOp::kShiftLeft: {
    return asthub::Shl(args.at(0), args.at(1));
  }
  case AstUidExprOp::kArithShiftRight: {
    return asthub::Ashr(args.at(0), args.at(1));
  }
  case AstUidExprOp::kLogicShiftRight: {
    return asthub::Lshr(args.at(0), args.at(1));
  }
  case AstUidExprOp::kAdd: {
    return asthub::Add(args.at(0), args.at(1));
  }
  case AstUidExprOp::kSubtract: {
    return asthub::Sub(args.at(0), args.at(1));
  }
  case AstUidExprOp::kDivide: {
    return asthub::Div(args.at(0), args.at(1));
  }
  case AstUidExprOp::kSignedRemainder: {
    return asthub::SRem(args.at(0), args.at(1));
  }
  case AstUidExprOp::kUnsignedRemainder: {
    return asthub::URem(args.at(0), args.at(1));
  }
  case AstUidExprOp::kSignedModular: {
    return asthub::SMod(args.at(0), args.at(1));
  }
  case AstUidExprOp::kMultiply: {
    return asthub::Mul(args.at(0), args.at(1));
  }
  case AstUidExprOp::kEqual: {
    return asthub::Eq(args.at(0), args.at(1));
  }
  case AstUidExprOp::kLessThan: {
    return asthub::Lt(args.at(0), args.at(1));
  }
  case AstUidExprOp::kGreaterThan: {
    return asthub::Gt(args.at(0), args.at(1));
  }
  case AstUidExprOp::kUnsignedLessThan: {
    return asthub::Ult(args.at(0), args.at(1));
  }
  case AstUidExprOp::kUnsignedGreaterThan: {
    return asthub::Ugt(args.at(0), args.at(1));
  }
  case AstUidExprOp::kLoad: {
    return asthub::Load(args.at(0), args.at(1));
  }
  case AstUidExprOp::kStore: {
    return asthub::Store(args.at(0), args.at(1), args.at(2));
  }
  case AstUidExprOp::kConcatenate: {
    return asthub::Concat(args.at(0), args.at(1));
  }
  case AstUidExprOp::kExtract: {
    return asthub::Extract(args.at(0), params.at(0), params.at(1));
  }
  case AstUidExprOp::kZeroExtend: {
    return asthub::ZExt(args.at(0), params.at(0));
  }
  case AstUidExprOp::kSignedExtend: {
    return asthub::SExt(args.at(0), params.at(0));
  }
  case AstUidExprOp::kRotateLeft: {
    return asthub::LRotate(args.at(0), params.at(0));
  }
  case AstUidExprOp::kRotateRight: {
    return asthub::RRotate(args.at(0), params.at(0));
  }
  case AstUidExprOp::kImply: {
    return asthub::Imply(args.at(0), args.at(1));
  }
  case AstUidExprOp::kIfThenElse: {
    return asthub::Ite(args.at(0), args.at(1), args.at(2));
  }
  default: {
    ILA_ERROR << "No Ser/Des (yet) for op " << ast_expr_op_uid;
    return nullptr;
  }
  }; // switch ast_expr_op_uid
}

ExprPtr J2IDes::DesExprOpAppFunc(const json& j_func,
                                 const json& j_arg_arr) const {
  // func
  auto func_id = j_func.get<ID_t>();
  auto func_pos = id_func_map_.find(func_id);
  ILA_ASSERT(func_pos != id_func_map_.end()) << j_func;
  auto i_func = func_pos->second;

  // arguments
  auto args = std::vector<ExprPtr>();
  for (const auto& it : j_arg_arr) {
    auto arg_id = it.get<ID_t>();
    auto arg_it = id_expr_map_.find(arg_id);
    ILA_ASSERT(arg_it != id_expr_map_.end()) << "Missing arg " << arg_id;
    args.push_back(arg_it->second);
  }

  auto i_expr_op_app_func = asthub::AppFunc(i_func, args);
  ILA_NOT_NULL(i_expr_op_app_func);

  return i_expr_op_app_func;
}

void J2IDes::DesVarUnit(const json& j_ila, const json& j_ast_list,
                        const InstrLvlAbsPtr& i_parent) {
  auto name = j_ila.at(SERDES_ILA_NAME).get<std::string>();
  ILA_CHECK(ila_name_ptr_map_.find(name) == ila_name_ptr_map_.end()) << name;

  auto i_ila = i_parent ? i_parent->NewChild(name) : InstrLvlAbs::New(name);
  ila_name_ptr_map_.emplace(name, i_ila);

  std::unordered_set<ID_t> input_id_set;
  std::unordered_set<ID_t> state_id_set;

  // input
  auto j_input_arr = j_ila.at(SERDES_ILA_INPUT);
  for (const auto& input_id : j_input_arr) {
    auto id = input_id.get<ID_t>();
    input_id_set.insert(id);
  }
  // state
  auto j_state_arr = j_ila.at(SERDES_ILA_STATE);
  for (const auto& state_id : j_state_arr) {
    auto id = state_id.get<ID_t>();
    state_id_set.insert(id);
  }

  // traverse ast list
  for (const auto& j_expr : j_ast_list) {
    // check if the expr has been des'ed
    auto id = j_expr.at(SERDES_EXPR_ID).get<ID_t>();
    auto pos = id_expr_map_.find(id);
    if (pos != id_expr_map_.end()) {
      continue;
    }

    // j_expr has not been des'ed yet
    decltype(pos->second) i_expr = nullptr;

    // expr ast type
    auto expr_uid = j_expr.at(SERDES_EXPR_UID).get<UID_t>();
    if (expr_uid == ExprTypeId::kVar) {
      auto name = j_expr.at(SERDES_EXPR_NAME).get<std::string>();
      auto sort = j_expr.at(SERDES_EXPR_SORT);
      if (state_id_set.find(id) != state_id_set.end()) {
        i_expr = DesExprState(sort, name, i_ila);
      } else if (input_id_set.find(id) != input_id_set.end()) {
        i_expr = DesExprInput(sort, name, i_ila);
      } else {
        continue;
      }

      // book keeping
      ILA_NOT_NULL(i_expr);
      id_expr_map_.emplace(id, i_expr);
    }
  }
}

void J2IDes::DesVarHier(const json& j_ila, const json& j_ast_list,
                        const InstrLvlAbsPtr& i_parent) {
  // des state/input variables in top-level ILA
  DesVarUnit(j_ila, j_ast_list, i_parent);

  // top-level ILA should have been created
  auto name = j_ila.at(SERDES_ILA_NAME).get<std::string>();
  auto pos = ila_name_ptr_map_.find(name);
  ILA_ASSERT(pos != ila_name_ptr_map_.end()) << "ILA not constructed " << name;
  auto i_ila = pos->second;

  // traverse children
  auto j_child_arr = j_ila.at(SERDES_ILA_CHILD);
  for (const auto& j_child : j_child_arr) {
    DesVarHier(j_child, j_ast_list, i_ila);
  }
}

InstrPtr J2IDes::DesInstr(const json& j_instr,
                          const InstrLvlAbsPtr& i_host) const {
  auto name = j_instr.at(SERDES_INSTR_NAME).get<std::string>();
  auto instr = i_host->NewInstr(name);

  auto decode_id = j_instr.at(SERDES_INSTR_DECODE).get<ID_t>();
  auto decode_pos = id_expr_map_.find(decode_id);
  ILA_ASSERT(decode_pos != id_expr_map_.end()) << "No decode in " << name;
  instr->set_decode(decode_pos->second);

  auto update = j_instr.at(SERDES_INSTR_UPDATE);
  for (decltype(i_host->state_num()) i = 0; i < i_host->state_num(); i++) {
    auto state = i_host->state(i);
    // get the id of the update function
    auto next_id_it = update.find(state->name().str());
    ILA_ASSERT(next_id_it != update.end()) << "No ID for " << state;
    // get the expr of the update function
    auto next_expr_it = id_expr_map_.find(next_id_it.value());
    ILA_ASSERT(next_expr_it != id_expr_map_.end()) << "No next for " << state;
    // set the update function
    instr->set_update(state, next_expr_it->second);
  }

  return instr;
}

void J2IDes::DesIlaUnit(const json& j_ila) {
  auto name = j_ila.at(SERDES_ILA_NAME).get<std::string>();
  auto pos = ila_name_ptr_map_.find(name);
  ILA_ASSERT(pos != ila_name_ptr_map_.end()) << name;
  auto m = pos->second;

  // fetch
  ILA_DLOG("Portable") << "Deserialize fetch function of " << m;
  try {
    auto fetch_id = j_ila.at(SERDES_ILA_FETCH).get<ID_t>();
    auto fetch_it = id_expr_map_.find(fetch_id);
    ILA_WARN_IF(fetch_it == id_expr_map_.end()) << "Fetch not found";
    m->SetFetch(fetch_it->second);
  } catch (...) {
    m->SetFetch(asthub::BvConst(1, 1));
  }

  // valid
  ILA_DLOG("Portable") << "Deserialize valid function of " << m;
  try {
    auto valid_id = j_ila.at(SERDES_ILA_VALID).get<ID_t>();
    auto valid_it = id_expr_map_.find(valid_id);
    ILA_WARN_IF(valid_it == id_expr_map_.end()) << "Valid not found";
    m->SetValid(valid_it->second);
  } catch (...) {
    m->SetValid(asthub::BoolConst(true));
  }

  // instructions
  ILA_DLOG("Portable") << "Deserialize instructions of " << m;
  auto j_instr_arr = j_ila.at(SERDES_ILA_INSTR);
  for (const auto& j_instr : j_instr_arr) {
    DesInstr(j_instr, m);
  }

  // init
  ILA_DLOG("Portable") << "Deserialize initial condition of " << m;
  auto j_init_arr = j_ila.at(SERDES_ILA_INIT);
  for (const auto& j_init : j_init_arr) {
    auto init_expr_it = id_expr_map_.find(j_init.get<ID_t>());
    ILA_ASSERT(init_expr_it != id_expr_map_.end()) << "Init not found";
    m->AddInit(init_expr_it->second);
  }
}

void J2IDes::DesIlaHier(const json& j_ila) {
  // des ila info, e.g., fetch, valid, instr, etc., of top-level ILA
  DesIlaUnit(j_ila);

  // traverse children
  auto j_child_arr = j_ila.at(SERDES_ILA_CHILD);
  for (const auto& j_child : j_child_arr) {
    DesIlaHier(j_child);
  }
}

} // namespace ilang
