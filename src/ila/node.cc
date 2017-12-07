/// \file
/// The source for the class Node.

#include "ila/node.h"

namespace ila {

Node::Node() {}

Node::~Node() {}

void Node::SetName(const std::string& name) { name_ = name; }

const std::string& Node::GetName() const { return name_; }

} // namespace ila

