#include <iostream>
#include <boost/lexical_cast.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <abstraction.hpp>

namespace ila
{

    // ---------------------------------------------------------------------- //
    NodeRef::NodeRef()
      : node(new Node())
    {
        throw PyILAException(PyExc_RuntimeError, "Cannot create node's directly. Use the context object.");
        node->setNodeRef(this);
    }

    NodeRef::NodeRef(Node* n)
      : node(n)
    {
        node->setNodeRef(this);
    }

    NodeRef::NodeRef(const NodeRef& nr)
      : node(nr.node)
    {
        node->setNodeRef(this);
    }

    NodeRef::~NodeRef()
    {
    }

    NodeRef& NodeRef::operator=(const NodeRef& other)
    {
        if(this != &other) { 
            node = other.node;
            node->setNodeRef(this);
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

    // ---------------------------------------------------------------------- //
    NodeRef* NodeRef::complement() const
    {
        Node* nprime = node->complement();
        return new NodeRef(nprime);
    }

    NodeRef* NodeRef::negate() const
    {
        Node* nprime = node->negate();
        return new NodeRef(nprime);
    }

    NodeRef* NodeRef::logicalNot() const
    {
        Node* nprime = node->logicalNot();
        return new NodeRef(nprime);
    }

    NodeRef* NodeRef::add(NodeRef* other) const
    {
        Node* nprime = node->add(other->node);
        return new NodeRef(nprime);
    }

    // ---------------------------------------------------------------------- //
    std::ostream& operator<<(std::ostream& out, const NodeRef& n)
    {
        return (n.node->write(out));
    }
}
