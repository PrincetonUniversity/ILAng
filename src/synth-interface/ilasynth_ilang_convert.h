/// \file
/// Internal helpers for converting ILAsynth to ILAng data structure.

#ifndef ILASYNTH_ILANG_CONVERT_H__
#define ILASYNTH_ILANG_CONVERT_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <ilasynth/abstraction.hpp>
#include <map>
#include <string>
#include <vector>

/// \namespace ilang
namespace ilang {

bool PortVars(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);

std::vector<FuncPtr> PortFunc(const ilasynth::Abstraction& abs);

bool PortInit(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);

bool PortFetch(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);

bool PortValid(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);

bool PortDecodes(const ilasynth::Abstraction& abs,
                 std::vector<ExprPtr>& decodes);

bool PortNexts(const ilasynth::Abstraction& abs,
               std::map<std::string, ExprPtr>& nexts);

}; // namespace ilang

#endif // ILASYNTH_ILANG_CONVERT_H__

