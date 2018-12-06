/// \file
/// Elevated interface for the synthesis engine.

#ifndef SYNTH_ENGINE_INTERFACE_H__
#define SYNTH_ENGINE_INTERFACE_H__

#include <ilang/ila/instr_lvl_abs.h>

/// \namespace ilang
namespace ilang {

InstrLvlAbsPtr ImportSynthAbsFromFile(const std::string& fileName);

}; // namespace ilang

#endif // SYNTH_ENGINE_INTERFACE_H__

