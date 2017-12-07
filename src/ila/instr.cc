/// \file
/// The source for the class Instr.

#include "ila/instr.h"

namespace ila {

Instr::Instr() {}

Instr::~Instr() {}

void Instr::SetName(const std::string& name) { name_ = name; }

const std::string& Instr::GetName() const { return name_; }

} // namespace ila

