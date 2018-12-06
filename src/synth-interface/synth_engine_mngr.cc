/// \file
/// Template-based synthesis engine interface.

#include "ilasynth_ilang_convert.h"
#include <ilang/synth-interface/synth_engine_mngr.h>
#include <ilang/util/log.h>
#include <ilasynth/abstraction.hpp>
// XXX ILA_ASSERT macro in both ilang and ilasynth. Use ILA_CHECK.

namespace ilang {

SynEngMngr::SynEngMngr() {}

SynEngMngr::~SynEngMngr() {}

SynEngMngrPtr SynEngMngr::New() { return std::make_shared<SynEngMngr>(); }

InstrLvlAbsPtr SynEngMngr::ImportIlaFromFile(const std::string& fileName) {
  // import the exported model as the synthesis engine internal structure
  ilasynth::Abstraction abs("");
  try {
    abs.importAllFromFile(fileName);
  } catch (...) {
    ILA_ERROR << "Fail importing ILAs from " << fileName;
  }

  // destination ILA
  auto model_name = abs.getName();
  auto m = InstrLvlAbs::New(model_name);

  // inputs and state variables
  ILA_ERROR_IF(!PortVars(abs, m)) << "Fail porting input/state vars";

  // uninterpreted functions
  auto funcs = PortFunc(abs);
  for (auto func : funcs) {
    ILA_NOT_NULL(func) << "NULL func";

    auto name = func->name().str();
    ILA_ERROR_IF(funcs_.find(name) != funcs_.end()) << "Redefine " << name;

    funcs_[name] = func;
  }

  // TODO stage?

  // initial condition
  ILA_ERROR_IF(!PortInit(abs, m)) << "Fail porting initial conditions";

  // fetch function
  ILA_ERROR_IF(!PortFetch(abs, m)) << "Fail porting the fetch function";

  // valid function
  ILA_ERROR_IF(!PortValid(abs, m)) << "Fail porting the valid function";

  // decode functions
  ILA_ERROR_IF(!PortDecodes(abs, decodes_)) << "Fail porting decode functions";

  // next state functions
  ILA_ERROR_IF(!PortNexts(abs, nexts_)) << "Fail porting next state functions";

  // TODO child-ILAs

  return m;
}

} // namespace ilang

