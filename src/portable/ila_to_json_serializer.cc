/// \file
/// The implementation of the ILA to JSON serializer.

#include <ilang/portable/ila_to_json_serializer.h>
//#include <ilang/portable/serdes_config.h>
#include <ilang/ila/ast_fuse.h>
#include <ilang/util/log.h>

namespace ilang {

I2JSer::I2JSer() {}

I2JSer::~I2JSer() {}

I2JSerPtr I2JSer::New() { return std::make_shared<I2JSer>(); }

json I2JSer::SerSort(const SortPtr& i_sort) const {
  auto j_sort = json::object();

  auto sort_uid = GetUidSort(i_sort);
  j_sort.emplace("sort_id", sort_uid);

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

json IlaSerDesMngr::SerExpr(const ExprPtr& i_expr) const {
  auto id = i_expr->name()->id();

  auto pos = id_idx_map.find(id);
  if (pos != id_idx_map_.end()) {
    return pos->second;
  }

  // i_expr has not been serialized yet

  // auto TestSerExpr = [this](const

  auto j_expr = json::object();

#if 0
  j_expr.emplace("id", i_expr->name()->id());

  if (i_expr->is_var()) {
    j_expr.emplace("expr_type", EXPR_TYPE_ID::VAR);

    j_expr.emplace("name", i_expr->name().str());
    j_expr.emplace("sort", SerSort(i_expr->sort()));

  } else if (i_expr->is_const()) {
    j_expr.emplace("expr_type", EXPR_TYPE_ID::CONST);

    j_expr.emplace("sort", SerSort(i_expr->sort()));
    j_expr.emplace("value", SerConstVal(i_expr));

  } else {
    j_expr.emplace("expr_type", EXPR_TYPE_ID::OP);

    j_expr.emplace("op", i_expr->op_id());
    j_expr.emplace("args", j_args_arr);
    j_expr.emplace("params", j_params_arr);
  }
#endif

  return j_expr;
}

json IlaSerDesMngr::SerInstrLvlAbs(const InstrLvlAbsPtr& i_ila) const {
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

}; // namespace ilang

