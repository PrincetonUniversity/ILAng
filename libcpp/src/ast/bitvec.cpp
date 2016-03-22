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

    Node* BitvectorExpr::add(boost::shared_ptr<Node> n2) const
    {
        ILA_ASSERT(nodeRef != NULL, "Node::nodeRef not initialized.");
        return new BitvectorOp(
            ctx, BitvectorOp::ADD,
            nodeRef->node, n2);
    }

    Node* BitvectorExpr::addInt(int v2) const
    {
        ILA_ASSERT(nodeRef != NULL, "Node::nodeRef not initialized.");
        boost::shared_ptr<Node> n2(new BitvectorConst(ctx, v2, type.bitWidth));
        return new BitvectorOp(
            ctx, BitvectorOp::ADD,
            nodeRef->node, n2);
    }

    Node* BitvectorExpr::raddInt(int v2) const
    {
        ILA_ASSERT(nodeRef != NULL, "Node::nodeRef not initialized.");
        boost::shared_ptr<Node> n2(new BitvectorConst(ctx, v2, type.bitWidth));
        return new BitvectorOp(
            ctx, BitvectorOp::ADD,
            n2, nodeRef->node);
    }

    // ---------------------------------------------------------------------- //
    BitvectorVar::BitvectorVar(Abstraction* c, std::string n, int width) 
        : BitvectorExpr(c, width)
    {
        this->name = n;
    }

    BitvectorVar::~BitvectorVar()
    {
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
    BitvectorConst::BitvectorConst(Abstraction* c, boost::python::long_ v, int w)
        : BitvectorExpr(c, w)
        , value(v)
    {
    }

    BitvectorConst::BitvectorConst(Abstraction* c, int v, int w)
        : BitvectorExpr(c, w)
        , value(v)
    {
    }

    BitvectorConst::~BitvectorConst()
    {
    }

    Node* BitvectorConst::clone() const
    {
        return new BitvectorConst(ctx, value, type.bitWidth);
    }

    std::ostream& BitvectorConst::write(std::ostream& out) const
    {
        std::string string_value = boost::python::extract<std::string>(boost::python::str(value));
        return (out << string_value);
    }

    // ---------------------------------------------------------------------- //
    int BitvectorOp::getUnaryResultWidth(Op op, boost::shared_ptr<Node> n)
    {
        // FIXME: add more code when operators are added.
        return n->type.bitWidth;
    }

    int BitvectorOp::getBinaryResultWidth(
        Op op, boost::shared_ptr<Node> n1, boost::shared_ptr<Node> n2)
    {
        // FIXME: add more code when operators are added.
        return n1->type.bitWidth;
    }

    bool BitvectorOp::checkUnaryOpWidth(Op op, boost::shared_ptr<Node> arg0, int width)
    {
        // FIXME: add more code when operators are added.
        return arg0->type.isBitvector(width);
    }

    bool BitvectorOp::checkBinaryOpWidth(
        Op op, 
        boost::shared_ptr<Node> n1, 
        boost::shared_ptr<Node> n2,
        int width)
    {
        // FIXME: add more code when operators are added.
        return n1->type.isBitvector(width) &&
               n2->type.isBitvector(width);
    }

    // constructor: unary ops.
    BitvectorOp::BitvectorOp(Abstraction* c, 
        Op op, 
        boost::shared_ptr<Node> n1
    )

      : BitvectorExpr(c, getUnaryResultWidth(op, n1))
      , arity(UNARY)
      , op(op)
    {

        // check if for the correct operator.
        if (!isUnary(op)) {
            throw PyILAException(PyExc_ValueError, 
                                 "Invalid unary operator.");
        }
        // check for the right type.
        if (!checkUnaryOpWidth(op, n1, type.bitWidth)) {
            throw PyILAException(
                PyExc_TypeError, 
                "Invalid type for unary operator argument.");
        }

        // push this into the vector.
        args.push_back( n1 );
    }

    // constructor: binary ops.
    BitvectorOp::BitvectorOp(Abstraction* c, 
        Op op,
        boost::shared_ptr<Node> n1,
        boost::shared_ptr<Node> n2
    )
      : BitvectorExpr(c, getBinaryResultWidth(op, n1, n2))
      , arity(BINARY)
      , op(op)
    {
        if (!isBinary(op)) {
            throw PyILAException(PyExc_ValueError,
                                 "Invalid binary operator.");
        }

        if (!checkBinaryOpWidth(op, n1, n2, type.bitWidth)) {
            throw PyILAException(
                PyExc_TypeError, 
                "Invalid type for binary operator argument.");
        }

        args.push_back( n1 );
        args.push_back( n2 );
    }

    // destructor.
    BitvectorOp::~BitvectorOp()
    {
    }

    // clone.
    Node* BitvectorOp::clone() const
    {
        if (arity == UNARY) {
            ILA_ASSERT(args.size() == 1, 
                "Unary op must have exactly one argument.");
            return new BitvectorOp(ctx, op, args[0]);
        } else if(arity == BINARY) {
            ILA_ASSERT(args.size() == 2,
                "Binary op must have exactly two arguments.");
            return new BitvectorOp(ctx, op, args[0], args[1]);
        } else {
            ILA_ASSERT(false, "Unsupported arity in BitvectorOp");
            return NULL;
        }
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

