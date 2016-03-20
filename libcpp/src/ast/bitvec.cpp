#include <iostream>
#include <boost/lexical_cast.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <abstraction.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    const char* BitvectorOp::operatorNames[] = {
        "-", "~", "not", 
        "+", "-", "&", "|", "xor", "xnor", "nand", "nor",
        "if"
    };

    // ---------------------------------------------------------------------- //
    BitvectorExpr::BitvectorExpr(Abstraction *c, int width) 
        : Node(c, NodeType::getBitvector(width))
    {
    }

    BitvectorExpr::~BitvectorExpr()
    {
    }

    BitvectorVar::~BitvectorVar()
    {
    }

    Node* BitvectorExpr::complement() const
    {
        ILA_ASSERT(nodeRef != NULL, "Node::nodeRef not initialized.");
        return new BitvectorOp(ctx, BitvectorOp::COMPLEMENT, nodeRef->node);
    }

    Node* BitvectorExpr::negate() const
    {
        ILA_ASSERT(nodeRef != NULL, "Node::nodeRef not initialized.");
        return new BitvectorOp(ctx, BitvectorOp::NEGATE, nodeRef->node);
    }

    Node* BitvectorExpr::logicalNot() const
    {
        // FIXME: this must return a bool.
        ILA_ASSERT(nodeRef != NULL, "Node::nodeRef not initialized.");
        return new BitvectorOp(ctx, BitvectorOp::LNOT, nodeRef->node);
    }

    // ---------------------------------------------------------------------- //
    BitvectorVar::BitvectorVar(Abstraction* c, std::string n, int width) 
        : BitvectorExpr(c, width)
    {
        this->name = n;
    }

    Node* BitvectorVar::clone() const
    {
        return new BitvectorVar(ctx, name, type.bitWidth);
    }

    std::ostream& BitvectorVar::write(std::ostream& out) const
    {
        return (out << name);
    }

    // ---------------------------------------------------------------------- //
    int BitvectorOp::getUnaryResultWidth(Op op, boost::shared_ptr<Node> n)
    {
        // FIXME: add more code when operators are added.
        return n->type.bitWidth;
    }

    bool BitvectorOp::checkUnaryOpWidth(Op op, boost::shared_ptr<Node> arg0, int width)
    {
        // FIXME: add more code when operators are added.
        return arg0->type.isBitvector(width);
    }

    // constructor.
    BitvectorOp::BitvectorOp(Abstraction* c, Op op, boost::shared_ptr<Node> n1)
      : BitvectorExpr(c, getUnaryResultWidth(op, n1))
      , arity(UNARY)
      , op(op)
    {

        // check if for the correct operator.
        if(!isUnary(op)) {
            throw PyILAException(PyExc_ValueError, "Invalid unary operator.");
        }
        // check for the right type.
        if(!checkUnaryOpWidth(op, n1, type.bitWidth)) {
            throw PyILAException(PyExc_TypeError, "Invalid type for unary operator argument.");
        }

        // push this into the vector.
        args.push_back( n1 );
    }

    // destructor.
    BitvectorOp::~BitvectorOp()
    {
    }

    // clone.
    Node* BitvectorOp::clone() const
    {
        ILA_ASSERT(arity == UNARY, "Unsupported arity in BitvectorOp");
        ILA_ASSERT(args.size() == 1, "Unary op must have exactly one argument.");
        return new BitvectorOp(ctx, op, args[0]);
    }

    // stream output.
    std::ostream& BitvectorOp::write(std::ostream& out) const
    {
        out << "(" << operatorNames[(int)op];
        for (auto arg: args) {
            arg->write(out << " ");
        }
        out << ")";
        return out;
    }
}

