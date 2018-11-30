/// \file
/// Source for the class Object.

#include <ilang/ila/object.h>

/// \namespace ilang
namespace ilang {

Object::Object() {}

Object::Object(const std::string& name) : symbol_(name) {}

Object::~Object() {}

const Symbol& Object::name() const { return symbol_; }

} // namespace ilang
