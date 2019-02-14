/// \file
/// The implementation of the JSON to ILA deserializer.

#include <ilang/portable/json_to_ila_deserializer.h>
//#include <ilang/portable/serdes_config.h>
#include <ilang/ila/ast_fuse.h>
#include <ilang/util/log.h>

namespace ilang {

J2IDes::J2IDes() {}

J2IDes::~J2IDes() {}

J2IDesPtr J2IDes::New() { return std::make_shared<J2IDes>(); }

SortPtr J2IDes::DesSort(const json& j_sort) const {
  switch (j_sort.at("sort_id").get<unsigned>()) {
  case AST_UID_SORT::BOOL: {
    return Sort::MakeBoolSort();
  }
  case AST_UID_SORT::BV: {
    auto width = j_sort.at("width").get<int>();
    return Sort::MakeBvSort(width);
  }
  case AST_UID_SORT::MEM: {
    auto addr_width = j_sort.at("addr_width").get<int>();
    auto data_width = j_sort.at("data_width").get<int>();
    return Sort::MakeMemSort(addr_width, data_width);
  }
  };
}

ExprPtr J2IDes::DesExpr(const json& j) const {
  return NULL;
  //
}

InstrLvlAbsPtr J2IDes::DesInstrLvlAbs(const json& j_ila) const {
  return NULL;
  //
}

}; // namespace ilang

