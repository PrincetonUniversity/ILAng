/// \file
/// The implementation of the elavated synthesis engine interface.

#include <ilang/synth-interface/synth_abs_converter.h>
#include <ilang/synth-interface/synth_engine_interface.h>
#include <ilang/util/log.h>

namespace ilang {

InstrLvlAbsPtr ImportSynthAbsFromFile(const std::string& fileName) {
  // read in abstraction from file
  ilasynth::Abstraction abs("");
  try {
    abs.importAllFromFile(fileName);
  } catch (...) {
    ILA_ERROR << "Fail importing ILAs from " << fileName;
  }

  // convert using the converter
  auto converter = SynthAbsConverter::New();
  auto ila = converter->Convert(abs);

  ILA_NOT_NULL(ila) << "Fail converting ila from " << fileName;

  return ila;
}

}; // namespace ilang

