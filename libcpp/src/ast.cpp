#include <ast.hpp>

namespace ila
{
    void Node::setName(std::string n)
    {
        name = n;
    }

    std::string Node::getName()
    {
        return name;
    }
}

