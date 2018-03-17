/// \file
/// Source for the class Object.

#include "ila/object.h"

/// \namespace ila
namespace ila {

Object::Object() {}

Object::Object(const std::string& name) : symbol_(name) {}

Object::~Object() {}

const Symbol& Object::name() const { return symbol_; }

} // namespace ila

