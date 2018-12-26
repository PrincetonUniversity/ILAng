/// \file
/// The implementation of the ILA portable manager.

#include <ilang/portable/portable_mngr.h>
#include <ilang/util/log.h>

namespace ilang {

PortableMngr::PortableMngr() {}

PortableMngr::~PortableMngr() {}

PortableMngrPtr PortableMngr::New() { return std::make_shared<PortableMngr>(); }

bool PortableMngr::ExportToFile(const std::string& fileName) const {
  return true;
  // TODO
}

InstrLvlAbsPtr PortableMngr::ImportFromFile(const std::string& fileName) const {
  return NULL;
  // TODO
}

json PortableMngr::GenJsonObjOfInstr(const InstrPtr& instr) {
  auto j = json();
  return j;
  // TODO
}

} // namespace ilang
