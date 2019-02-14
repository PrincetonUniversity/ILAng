/// \file
/// The source for the ILA portable interface.

#include <ilang/portable/ila_to_json_serializer.h>
#include <ilang/portable/interface.h>

namespace ilang {

json IlaSerDesMngr::Serialize(const InstrLvlAbsPtr& m) {
  auto i2jser = I2JSer::New();
  auto res = i2jser->SerInstrLvlAbs(m);
  return res;
}

InstrLvlAbsPtr IlaSerDesMngr::Deserialize(const json& j) {
  return NULL;
  //
}

bool IlaSerDesMngr::SerToFile(const InstrLvlAbsPtr& m,
                              const std::string& file_name) {
  return true;
  //
}

InstrLvlAbsPtr IlaSerDesMngr::DesFromFile(const std::string& file_name) {
  return NULL;
  //
}

}; // namespace ilang
