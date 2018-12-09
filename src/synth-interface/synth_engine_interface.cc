/// \file
/// The implementation of the elavated synthesis engine interface.

#include <ilang/synth-interface/synth_abs_converter.h>
#include <ilang/synth-interface/synth_engine_interface.h>
#include <ilang/util/log.h>
#include <sys/stat.h>

namespace ilang {

InstrLvlAbsPtr ImportSynthAbsFromFile(const std::string& fileName,
                                      const std::string& name) {
  struct stat buffer;
  ILA_CHECK(stat(fileName.c_str(), &buffer) == 0) << fileName << " not exist";

  // read in abstraction from file
  ilasynth::Abstraction abs(name);
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

InstrLvlAbsPtr ImportSynthAbsFromFileHier(const std::string& fileName,
                                          const InstrLvlAbsPtr parent,
                                          const std::string& name) {
  struct stat buffer;
  ILA_CHECK(stat(fileName.c_str(), &buffer) == 0) << fileName << " not exist";

  // read in abstraction from file
  ilasynth::Abstraction abs(name);
  try {
    abs.importAllFromFile(fileName);
  } catch (...) {
    ILA_ERROR << "Fail importing ILAs from " << fileName;
  }

  // port the abstraction onto the parent
  auto child_ila = parent->NewChild(name);
  auto converter = SynthAbsConverter::New();
  converter->Port(abs, child_ila);

  return child_ila;
}

}; // namespace ilang

