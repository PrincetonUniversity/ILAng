/// \file
/// The implementation of the elevated synthesis engine interface.

#include <ilang/target-itsy/interface.h>

#include <sys/stat.h>

#include <ilang/target-itsy/abst_to_ila.h>
#include <ilang/util/log.h>

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

  ILA_CHECK(ila) << "Fail converting ila from " << fileName;

  return ila;
}

InstrLvlAbsPtr ImportSynthAbsFromFileHier(const std::string& fileName,
                                          const InstrLvlAbsPtr& parent,
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
