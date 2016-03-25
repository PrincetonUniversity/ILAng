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
        return _unOp(
            BoolOp::NOT,
            BitvectorOp::COMPLEMENT,
            "complement");
    }

    NodeRef* NodeRef::negate() const
    {
        return _unOp(
            BoolOp::INVALID,
            BitvectorOp::NEGATE,
            "negate");
    }

    NodeRef* NodeRef::logicalNot() const
    {
        return _unOp(
            BoolOp::NOT,
            BitvectorOp::INVALID,
            "not");
    }

    NodeRef* NodeRef::add(NodeRef* other) const
    {
        return _binOp(BitvectorOp::ADD, other);
    }

    NodeRef* NodeRef::addInt(int r) const
    {
        return _binOp(BitvectorOp::ADD, r);
    }

    NodeRef* NodeRef::raddInt(int r) const
    {
        return _binOpR(BitvectorOp::ADD, r);
    }

    NodeRef* NodeRef::sub(NodeRef* other) const
    {
        return _binOp(BitvectorOp::SUB, other);
    }

    NodeRef* NodeRef::subInt(int r) const
    {
        return _binOp(BitvectorOp::SUB, r);
    }

    NodeRef* NodeRef::rsubInt(int r) const
    {
        return _binOpR(BitvectorOp::SUB, r);
    }

    // ---------------------------------------------------------------------- //
    NodeRef* NodeRef::_unOp(
        BoolOp::Op opBool, BitvectorOp::Op opBv, const char* opName) const
    {
        if (opBv != BitvectorOp::INVALID && node->type.isBitvector()) {
            return new NodeRef(new BitvectorOp(node->ctx, opBv, node));
        } else if (opBool != BoolOp::INVALID && node->type.isBool()) {
            return new NodeRef(new BoolOp(node->ctx, opBool, node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 std::string("Incorrect type for ") + 
                                 opName);
            return NULL;
        }
    }

    NodeRef* NodeRef::_binOp(BitvectorOp::Op op, NodeRef* other) const
    {
        if (node->type.isBitvector()) {
            return new NodeRef(new BitvectorOp(
                        node->ctx, op, node, other->node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " + 
                                 BitvectorOp::operatorNames[op]);
        }
    }

    NodeRef* NodeRef::_binOp(BitvectorOp::Op op, int r) const
    {
        if (node->type.isBitvector()) {
            boost::shared_ptr<Node> node_r(
                new BitvectorConst(node->ctx, r, node->type.bitWidth));

            return new NodeRef(new BitvectorOp(
                        node->ctx, op, node, node_r));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " +
                                 BitvectorOp::operatorNames[op]);
        }
    }

    NodeRef* NodeRef::_binOpR(BitvectorOp::Op op, int r) const
    {
        if (node->type.isBitvector()) {
            boost::shared_ptr<Node> node_r(
                new BitvectorConst(node->ctx, r, node->type.bitWidth));

            return new NodeRef(new BitvectorOp(
                        node->ctx, op, node_r, node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " +
                                 BitvectorOp::operatorNames[op]);
        }
    }

    // ---------------------------------------------------------------------- //
    std::ostream& operator<<(std::ostream& out, const NodeRef& n)
    {
        return (n.node->write(out));
    }
}
