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
      , nodeRef(NULL)
      , id(-1)
      , type(NodeType())
    {
    }

    Node::Node(Abstraction* c, NodeType t) 
      : ctx(c)
      , nodeRef(NULL)
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

    void Node::setNodeRef(NodeRef* nr)
    {
        nodeRef = nr;
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

    z3::expr Node::toZ3(ila::Z3AdapterI& C) const
    {
        throw new PyILAException(
            PyExc_RuntimeError,
            "Node::toZ3 not implemented.");
        return C.ctx().bool_val(false);
    }


    // ---------------------------------------------------------------------- //
    void Node::doSomething()
    {
        using namespace z3;
        context c;

        expr x = c.bool_const("x");
        expr y = c.bool_const("y");
        expr conjecture = !(x && y) == (!x || !y);
        
        solver s(c);
        // adding the negation of the conjecture as a constraint.
        s.add(!conjecture);
        std::cout << s << "\n";
        switch (s.check()) {
        case unsat:   std::cout << "de-Morgan is valid\n"; break;
        case sat:     std::cout << "de-Morgan is not valid\n"; break;
        case unknown: std::cout << "unknown\n"; break;
        }
    }

    std::ostream& Node::write(std::ostream& out) const
    {
        return (out << name);
    }
}
