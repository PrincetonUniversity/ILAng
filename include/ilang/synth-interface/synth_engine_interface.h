/// \file
/// Elevated interface for the synthesis engine.

#ifndef SYNTH_ENGINE_INTERFACE_H__
#define SYNTH_ENGINE_INTERFACE_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <string>

/// \namespace ilang
namespace ilang {

InstrLvlAbsPtr ImportSynthAbsFromFile(const std::string& fileName,
                                      const std::string& name = "");

InstrLvlAbsPtr ImportSynthAbsFromFileHier(const std::string& fileName,
                                          const InstrLvlAbsPtr parent,
                                          const std::string& name = "");

}; // namespace ilang

#endif // SYNTH_ENGINE_INTERFACE_H__

