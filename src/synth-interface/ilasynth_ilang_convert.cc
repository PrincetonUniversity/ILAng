/// \file
/// Internal helpers for converting ILAsynth to ILAng data structure.

#include "ilasynth_ilang_convert.h"
#include <ilang/util/log.h>

namespace ilang {

bool PortVars(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila) {
  // inputs
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

  // state vars -- bool
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

  // state vars -- bv
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

  // state vars -- mem
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

std::vector<FuncPtr> PortFunc(const ilasynth::Abstraction& abs) {
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
  }
}

bool PortInit(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila) {
  // TODO
  // abs.getInit()
  // abs.getIpred()
  return true;
}

bool PortFetch(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila) {
  // TODO
  // abs.getFetchExpr()
  // abs.getFetchExprRef()
  return true;
}

bool PortValid(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila) {
  // TODO
  // abs.getFetchValid()
  // abs.getFetchValidRef()
  return true;
}

bool PortDecodes(const ilasynth::Abstraction& abs,
                 std::vector<ExprPtr>& decodes) {
  // TODO
  // abs.getDecodeExprs()
  // abs.getDecodeExpressions()
  return true;
}

bool PortNexts(const ilasynth::Abstraction& abs,
               std::map<std::string, ExprPtr>& nexts) {
  // TODO
  // abs.getNext()
  // abs.getNextI()
  return true;
}

}; // namespace ilang

