/// \file
/// The implementation of the abstraction to ILA converter.

#include <ilang/synth-interface/synth_abs_converter.h>
#include <ilang/util/log.h>

namespace ilang {

SynthAbsConverter::SynthAbsConverter() {}

SynthAbsConverter::~SynthAbsConverter() {}

SynthAbsConverterPtr SynthAbsConverter::New() {
  return std::make_shared<SynthAbsConverter>();
}

InstrLvlAbsPtr SynthAbsConverter::Convert(const ilasynth::Abstraction& abs) {
  // destination ILA
  auto model_name = abs.getName();
  auto m = InstrLvlAbs::New(model_name);

  // port basic abstraction definition
  ILA_ERROR_IF(!PortInputs(abs, m)) << "Fail porting input variables";
  ILA_ERROR_IF(!PortStates(abs, m)) << "Fail porting state variables";
  ILA_ERROR_IF(!PortValid(abs, m)) << "Fail porting the valid function";
  ILA_ERROR_IF(!PortFetch(abs, m)) << "Fail porting the fetch function";
  ILA_ERROR_IF(!PortInits(abs, m)) << "Fail porting initial conditions";

  // collect uninterpreted functions
  ILA_ERROR_IF(!PortFuncs(abs, m)) << "Fail porting uninterpreted functions";

  // instruction
#if 0
  // collect decode functions
  auto res = PortDecodeFuncs(abs, m);
  res &= PortNextStateFuncs(abs, m);
  ILA_ERROR_IF(!PortDecodeFuncs(abs, m)) << "Fail getting decode functions";
  // collect next state functions
  ILA_ERROR_IF(!PortNextStateFuncs(abs, m))
      << "Fail getting next state functions";
#endif

  // TODO child-ILAs

  return m;
}

bool SynthAbsConverter::PortInputs(const ilasynth::Abstraction& abs,
                                   const InstrLvlAbsPtr& ila) const {
  auto inps_synth = abs.getInps();
  for (auto it : inps_synth) {
    auto node = it.second.var;
    auto type = node->getType();
    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    if (type.isBool()) {
      ila->NewBoolInput(name);
    } else if (type.isBitvector()) {
      ila->NewBvInput(name, type.bitWidth);
    } else {
      ILA_CHECK(type.isMem()) << "Unknown node type " << type;
      ila->NewMemInput(name, type.addrWidth, type.dataWidth);
    }

    ILA_DLOG("SynthImport") << "Input: " << ila->input(name);
  }

  return true;
}

bool SynthAbsConverter::PortStates(const ilasynth::Abstraction& abs,
                                   const InstrLvlAbsPtr& ila) const {
  // bool
  auto bits_synth = abs.getBits();
  for (auto it : bits_synth) {
    auto node = it.second.var;

    auto type = node->getType();
    ILA_CHECK(type.isBool());

    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    ila->NewBoolState(name);
    ILA_DLOG("SynthImport") << "Bool Var: " << ila->state(name);
  }

  // bv
  auto regs_synth = abs.getRegs();
  for (auto it : regs_synth) {
    auto node = it.second.var;

    auto type = node->getType();
    ILA_CHECK(type.isBitvector());

    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    ila->NewBvState(name, type.bitWidth);
    ILA_DLOG("SynthImport") << "Bv Var: " << ila->state(name);
  }

  // mem
  auto mems_synth = abs.getMems();
  for (auto it : mems_synth) {
    auto node = it.second.var;

    auto type = node->getType();
    ILA_CHECK(type.isMem());

    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    ila->NewMemState(name, type.addrWidth, type.dataWidth);
    ILA_DLOG("SynthImport") << "Mem: " << ila->state(name);
  }

  return true;
}

bool SynthAbsConverter::PortValid(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) const {
  // TODO
  return true;
}

bool SynthAbsConverter::PortFetch(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) const {
  // TODO
  return true;
}

bool SynthAbsConverter::PortInits(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) const {
  // TODO
  return true;
}

bool SynthAbsConverter::PortFuncs(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) {
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

    // add to the mapping
    ILA_ERROR_IF(funcs_.find(name) != funcs_.end()) << "Redefine " << name;

    funcs_[name] = func;
  }

  return true;
}

bool SynthAbsConverter::PortDecodeFuncs(const ilasynth::Abstraction& abs,
                                        const InstrLvlAbsPtr& ila) {
  // TODO
  return true;
}

bool SynthAbsConverter::PortNextStateFuncs(const ilasynth::Abstraction& abs,
                                           const InstrLvlAbsPtr& ila) {
  // TODO
  return true;
}

} // namespace ilang

