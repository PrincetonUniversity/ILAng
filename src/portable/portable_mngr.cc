/// \file
/// The implementation of the ILA portable manager.

#include <ilang/portable/portable_mngr.h>
#include <ilang/util/log.h>

namespace ilang {

IlaPortableMngr::IlaPortableMngr() {}

IlaPortableMngr::~IlaPortableMngr() {}

IlaPortableMngrPtr IlaPortableMngr::New() {
  return std::make_shared<IlaPortableMngr>();
}

bool IlaPortableMngr::ExportToFile(const std::string& fileName) const {
  return true;
  // TODO
}

InstrLvlAbsPtr
IlaPortableMngr::ImportFromFile(const std::string& fileName) const {
  return NULL;
  // TODO
}

} // namespace ilang

