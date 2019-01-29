/// \file
/// The implementation of the ILA portable manager.

#include <ilang/portable/portable_mngr.h>
#include <ilang/util/log.h>

namespace ilang {

PortableMngr::PortableMngr() {}

PortableMngr::~PortableMngr() {}

PortableMngrPtr PortableMngr::New() { return std::make_shared<PortableMngr>(); }

bool PortableMngr::ExportToFile(const InstrLvlAbsPtr& m,
                                const std::string& fileName) const {
  auto ila_j = json::object();

  // XXX child is exported separatly

  ila_j["name"] = m->name().str();

  // input
  auto inp_arr_j = json::array();
  for (auto i = 0; i < m->input_num(); i++) {
    inp_arr_j.push_back(SerExpr(m->input(i)));
  }

  // state

  // fetch

  ila_j["inputs"] = inp_arr_j;

  ILA_DLOG("Portable") << ila_j.dump(2) << std::endl;

  return true;
}

InstrLvlAbsPtr PortableMngr::ImportFromFile(const std::string& fileName) const {
  return NULL;
  // TODO
}

json PortableMngr::SerSort(const SortPtr& s) const {
  auto js = json::object();

  js.emplace("sort_id", s->sort_id());

  if (s->is_bv()) {
    js.emplace("width", s->bit_width());
  } else if (s->is_mem()) {
    js.emplace("addr_width", s->addr_width());
    js.emplace("data_width", s->data_width());
  }

  return js;
}

SortPtr PortableMngr::DesSort(const json& j) const {
  switch (j.at("sort_id").get<unsigned>()) {
  case Sort::SORT_ID::BOOL: {
    return Sort::MakeBoolSort();
  }
  case Sort::SORT_ID::BITVECTOR: {
    auto width = j.at("width").get<int>();
    return Sort::MakeBvSort(width);
  }
  case Sort::SORT_ID::MEMORY: {
    auto addr_width = j.at("addr_width").get<int>();
    auto data_width = j.at("data_width").get<int>();
    return Sort::MakeMemSort(addr_width, data_width);
  }
  };
}

json PortableMngr::SerExpr(const ExprPtr& e) const {
  auto je = json::object();

  je.emplace("name", e->name().str());
  je.emplace("id", e->name()->id());
  je.emplace("sort", SerSort(e->sort()));

  return je;
}

ExprPtr PortableMngr::DesExpr(const json& j) const {
  return NULL;
  //
}

} // namespace ilang
