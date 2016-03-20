#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>

namespace ila
{
    // ---------------------------------------------------------------------- //
    BitvectorExpr::BitvectorExpr(Context *c, int width) 
        : Node(c, NodeType::getBitvector(width))
    {
    }

    BitvectorExpr::~BitvectorExpr()
    {
    }

    BitvectorVar::~BitvectorVar()
    {
    }

    // ---------------------------------------------------------------------- //
    BitvectorVar::BitvectorVar(Context* c, std::string n, int width) 
        : BitvectorExpr(c, width)
    {
        this->name = n;
    }

    Node* BitvectorVar::complement() const
    {
        return new BitvectorOp(ctx, BitvectorOp::COMPLEMENT, *this);
    }

    Node* BitvectorVar::clone() const
    {
        return new BitvectorVar(ctx, name, type.bitWidth);
    }

    // ---------------------------------------------------------------------- //
    int BitvectorOp::getUnaryResultWidth(Op op, const Node& n)
    {
        // FIXME: add more code when operators are added.
        return n.type.bitWidth;
    }

    bool BitvectorOp::checkUnaryOpWidth(Op op, const Node& arg0, int width)
    {
        // FIXME: add more code when operators are added.
        return arg0.type.isBitvector(width);
    }

    // constructor.
    BitvectorOp::BitvectorOp(Context* c, Op op, const Node& n1)
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
        args.push_back( std::unique_ptr<Node>(n1.clone()) );
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
        return new BitvectorOp(ctx, op, *args[0]);
    }
}

