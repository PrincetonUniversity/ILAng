/// \file
/// The source for the ILA portable interface.

#include <ilang/target-json/interface.h>

#include <fstream>

#include <ilang/target-json/ila_to_json_serializer.h>
#include <ilang/target-json/json_to_ila_deserializer.h>

namespace ilang {

json IlaSerDesMngr::Serialize(const InstrLvlAbsPtr& m) {
  auto i2j_ser = I2JSer::New();
  auto res = i2j_ser->SerInstrLvlAbs(m);
  return res;
}

InstrLvlAbsPtr IlaSerDesMngr::Deserialize(const json& j) {
  auto j2i_des = J2IDes::New();
  auto res = j2i_des->DesInstrLvlAbs(j);
  return res;
}

bool IlaSerDesMngr::SerToFile(const InstrLvlAbsPtr& m,
                              const std::string& file_name, const int& indent) {
  std::ofstream fout(file_name);

  if (fout.is_open()) {
    auto j_ila = Serialize(m);
    if (indent == -1) {
      fout << j_ila.dump();
    } else {
      fout << j_ila.dump(indent);
    }
  }

  fout.close();
  return true;
}

InstrLvlAbsPtr IlaSerDesMngr::DesFromFile(const std::string& file_name) {
  std::ifstream fin(file_name);

  if (fin.is_open()) {
    auto j_ila = json::object();
    fin >> j_ila;

    auto m = Deserialize(j_ila);

    fin.close();
    return m;
  }

  return nullptr;
}

} // namespace ilang
