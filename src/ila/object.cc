/// \file
/// Source for the class Object.

#include "ila/object.h"

/// \namespace ila
namespace ila {

Object::Object() {}

Object::Object(const char* name) : symbol_(name) {}

Object::Object(const std::string& name) : symbol_(name) {}

Object::~Object() {}

const Symbol& Object::name() const { return symbol_; }

bool Object::set_name(const std::string& name) {
  return symbol_.set_name(name);
}

} // namespace ila

