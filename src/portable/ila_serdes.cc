/// \file
/// The implementation of the ILA Ser/Des manager.

#include <ilang/portable/ila_serdes.h>
#include <ilang/util/log.h>

namespace ilang {

IlaSerDesMngr::IlaSerDesMngr() {}

IlaSerDesMngr::~IlaSerDesMngr() {}

IlaSerDesMngrPtr IlaSerDesMngr::New() {
  return std::make_shared<IlaSerDesMngr>();
}

bool IlaSerDesMngr::SerToFile(const InstrLvlAbsPtr& m,
                              const std::string& file_name) const {
  return true;
}

InstrLvlAbsPtr IlaSerDesMngr::DesFromFile(const std::string& file_name) const {
  return NULL;
}

json IlaSerDesMngr::Serialize(const InstrLvlAbsPtr& m) const {
  return json::object();
}

InstrLvlAbsPtr IlaSerDesMngr::Deserialize(const json& j) const {
  return NULL;
  //
}

}; // namespace ilang

