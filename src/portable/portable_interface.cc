/// \file
/// The implementation of the elevated ILA portable interface.

#include <ilang/portable/portable_interface.h>
#include <ilang/portable/portable_mngr.h>

namespace ilang {

bool ExportPortableToFile(const InstrLvlAbsPtr& ila, const std::string& file) {
  auto portMngr = PortableMngr::New();
  portMngr->ExportToFile(ila, file);
  return true;
}

InstrLvlAbsPtr ImportPortableFromFile(const std::string& file) {
  return NULL;
  // TODO
}

}; // namespace ilang
