#include <iostream>
#include <boost/lexical_cast.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <abstraction.hpp>

namespace ila
{
    BoolExpr::BoolExpr(Abstraction* c)
      : Node(c, NodeType::getBool())
    {
    }

    BoolExpr::~BoolExpr()
    {
    }
}
