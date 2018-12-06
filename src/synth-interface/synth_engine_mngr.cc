/// \file
/// Template-based synthesis engine interface.

#include <ilang/synth-interface/synth_engine_mngr.h>
#include <ilang/util/log.h>
#include <ilasynth/abstraction.hpp>
// XXX ILA_ASSERT macro redefined in both ilang and ilasynth. Use ILA_CHECK.

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

  // create place holder for the ILA
  auto model_name = abs.getName();
  auto m = InstrLvlAbs::New(model_name);

  // inputs
  auto inps_synth = abs.getInps();
  for (auto it : inps_synth) {
    auto node = it.second.var;
    auto type = node->getType();
    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << "Name mismatch " << name;

    if (type.isBool()) {
      m->NewBoolInput(name);
    } else if (type.isBitvector()) {
      m->NewBvInput(name, type.bitWidth);
    } else {
      ILA_CHECK(type.isMem()) << "Unknown node type " << type;
      m->NewMemInput(name, type.addrWidth, type.dataWidth);
    }

    ILA_DLOG("SynthImport") << "Input: " << m->input(name);
  }

  // state vars -- bits
  auto bits_synth = abs.getBits();
  for (auto it : bits_synth) {
    auto node = it.second.var;

    auto type = node->getType();
    ILA_CHECK(type.isBool());

    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    m->NewBoolState(name);
    ILA_DLOG("SynthImport") << "Bool Var: " << m->state(name);
  }

  // state vars -- regs
  auto regs_synth = abs.getRegs();
  for (auto it : regs_synth) {
    auto node = it.second.var;

    auto type = node->getType();
    ILA_CHECK(type.isBitvector());

    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    m->NewBvState(name, type.bitWidth);
    ILA_DLOG("SynthImport") << "Bv Var: " << m->state(name);
  }

  // state vars -- mem
  auto mems_synth = abs.getMems();
  for (auto it : mems_synth) {
    auto node = it.second.var;

    auto type = node->getType();
    ILA_CHECK(type.isMem());

    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    m->NewMemState(name, type.addrWidth, type.dataWidth);
    ILA_DLOG("SynthImport") << "Mem: " << it.first;
  }

  // functions
  auto funs_synth = abs.getFuns();
  for (auto it : funs_synth) {
    auto node = it.second.var;

    auto type = node->getType();
    ILA_CHECK(type.isFunc());

    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    // output sort
    ILA_CHECK(type.bitWidth > 0) << "Invalid output width " << type.bitWidth;
    auto out_sort = Sort::MakeBvSort(type.bitWidth);

    // argument sort
    std::vector<decltype(Sort::MakeBvSort(1))> args_sort = {};
    auto& args_width = type.argsWidth;
    for (auto i = 0; i != args_width.size(); i++) {
      args_sort.push_back(Sort::MakeBvSort(args_width.at(i)));
    }

    // create the func object
    auto func = Func::New(name, out_sort, args_sort);
    ILA_DLOG("SynthImport") << "Fun: " << func;

    // add the func in the map
    ILA_ERROR_IF(funcs_.find(name) != funcs_.end()) << "Redefine " << name;
    funcs_[name] = func;
  }

  return m;
}

} // namespace ilang

