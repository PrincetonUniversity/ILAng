#include <iostream>
#include <boost/lexical_cast.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <abstraction.hpp>


namespace ila
{
    // ---------------------------------------------------------------------- //
    int Node::totalObjCnt = 0;

    // ---------------------------------------------------------------------- //
    Node::Node()
      : ctx(NULL)
      , id(-1)
      , type(NodeType())
    {
    }

    Node::Node(Abstraction* c, NodeType t) 
      : ctx(c)
      , id(ctx->getObjId())
      , type(t) 
    {
        _initName();
    }

    Node::~Node()
    {
    }

    // ---------------------------------------------------------------------- //
    void Node::_initName()
    {
        name = "n" + boost::lexical_cast<std::string>(id);
    }

    // ---------------------------------------------------------------------- //
    unsigned Node::nArgs() const
    {
        return 0;
    }

    boost::shared_ptr<Node> Node::arg(unsigned i) const 
    {
        return NULL;
    }

    // ---------------------------------------------------------------------- //
    Node* Node::clone() const
    {
        return new Node();
    }

    bool Node::equal(const Node* that) const
    {
        throw new PyILAException(
            PyExc_RuntimeError, 
            "Node::equal not implemented.");
        return false;
    }

    boost::python::object Node::getValue() const
    {
        throw PyILAException(PyExc_AttributeError,
            "Object does not have a value attribute.");
        return boost::python::object();
    }


    std::ostream& Node::write(std::ostream& out) const
    {
        return (out << name);
    }

    std::ostream& operator<<(std::ostream& out, const Node& that)
    {
        return that.write(out);
    }
}
