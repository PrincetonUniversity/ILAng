/// \file
/// The source file for the class Ila.

#include "ila/ila.h"

namespace ila {

Ila::Ila() {}

Ila::Ila(std::string name) : name_(name) {}

Ila::~Ila() {}

void Ila::SetName(const std::string& name) { name_ = name; }

const std::string& Ila::GetName() const { return name_; }

} // namespace ila

