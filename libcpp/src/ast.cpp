#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>

namespace ila
{
    // ---------------------------------------------------------------------- //
    int Context::getObjId()
    {
        return objCnt++;
    }

    Context::Context()
      : objCnt(0)
    {
    }

    Context::~Context()
    {
    }

    // ---------------------------------------------------------------------- //
    NodeRef* Context::BitvectorVar(const std::string& name, int width)
    {
        return new NodeRef(new ila::BitvectorVar(this, name, width));
    }

    // ---------------------------------------------------------------------- //
    NodeRef::NodeRef()
      : node(new Node())
    {
        throw PyILAException(PyExc_RuntimeError, "Cannot create node's directly. Use the context object.");
    }

    NodeRef::NodeRef(Node* n)
      : node(n)
    {
    }

    NodeRef::NodeRef(const NodeRef& nr)
      : node(nr.node)
    {
    }

    NodeRef::~NodeRef()
    {
    }

    NodeRef& NodeRef::operator=(const NodeRef& other)
    {
        if(this != &other) { 
            node = other.node;
        }
        return *this;
    }

    // ---------------------------------------------------------------------- //
    std::string NodeRef::getName() const
    {
        return node->name;
    }

    NodeType NodeRef::getType() const
    {
        return node->type;
    }

    void NodeRef::doSomething() 
    {
        return node->doSomething();
    }
}
