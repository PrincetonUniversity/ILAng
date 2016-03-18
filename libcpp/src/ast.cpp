#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>


namespace ila
{
    int Node::totalObjCnt = 0;

    Node::~Node()
    {
        std::cout << "node destroyed; name:" << name << std::endl;
    }

    void Node::_initName()
    {
        name = "n" + boost::lexical_cast<std::string>(id);
        std::cout << "node created." << std::endl;
    }

    Node* Node::clone() const
    {
        return new Node();
    }

    Node* Node::complement() const
    {
        throw PyILAException(PyExc_NotImplementedError, "Complement not implemented.");
        return NULL;
    }

    Node* Node::negate() const
    {
        throw PyILAException(PyExc_NotImplementedError, "Negate not implemented.");
    }

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

    BitvectorExpr::~BitvectorExpr()
    {
    }

    BitvectorVar::~BitvectorVar()
    {
    }

    Node* BitvectorVar::complement() const
    {
        return new BitvectorOp(BitvectorOp::COMPLEMENT, *this);
    }

    Node* BitvectorVar::clone() const
    {
        return new BitvectorVar(name, type.bitWidth);
    }

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
    BitvectorOp::BitvectorOp(Op op, const Node& n1)
      : BitvectorExpr(getUnaryResultWidth(op, n1))
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
        return new BitvectorOp(op, *args[0]);
    }
}

