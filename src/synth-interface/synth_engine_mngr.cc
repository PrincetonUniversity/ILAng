/// \file
/// Template-based synthesis engine interface.

#include <ilang/synth-interface/synth_engine_mngr.h>
#include <ilasynth/abstraction.hpp>

namespace ila {

SynEngMngr::SynEngMngr() {
  // TODO
}

SynEngMngr::~SynEngMngr() {
  // TODO
}

SynEngMngrPtr SynEngMngr::New() { return std::make_shared<SynEngMngr>(); }

InstrLvlAbsPtr SynEngMngr::ImportIlaFromFile(const std::string& fileName) {
  Abstraction abs("");
  abs.importAllFromFile(fileName);
  // TODO

  return NULL;
}

} // namespace ila

