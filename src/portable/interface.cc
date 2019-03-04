/// \file
/// The source for the ILA portable interface.

#include <ilang/portable/ila_to_json_serializer.h>
#include <ilang/portable/interface.h>
#include <ilang/portable/json_to_ila_deserializer.h>

namespace ilang {

json IlaSerDesMngr::Serialize(const InstrLvlAbsPtr& m) {
  auto i2jser = I2JSer::New();
  auto res = i2jser->SerInstrLvlAbs(m);
  return res;
}

InstrLvlAbsPtr IlaSerDesMngr::Deserialize(const json& j) {
  auto j2ides = J2IDes::New();
  auto res = j2ides->DesInstrLvlAbs(j);
  return res;
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
