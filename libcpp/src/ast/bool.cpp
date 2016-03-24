#include <iostream>
#include <boost/lexical_cast.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <abstraction.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    const char* BoolOp::operatorNames[] = {
        "not", 
        "and", "or", "xor", "xnor", "nand", "nor",
        "if"
    };

    // ---------------------------------------------------------------------- //
    BoolExpr::BoolExpr(Abstraction* c)
      : Node(c, NodeType::getBool())
    {
    }

    BoolExpr::~BoolExpr()
    {
    }

    // ---------------------------------------------------------------------- //
    BoolVar::BoolVar(Abstraction* c, const std::string& name)
      : BoolExpr(c)
    {
        this->name = name;
    }

    BoolVar::~BoolVar()
    {
    }

    Node* BoolVar::clone() const
    {
        return new BoolVar(ctx, name);
    }

    std::ostream& BoolVar::write(std::ostream& out) const
    {
        return (out << name);
    }

    // ---------------------------------------------------------------------- //
    BoolConst::BoolConst(Abstraction* c, bool v)
      : BoolExpr(c)
      , value(v)
    {
    }

    BoolConst::BoolConst(Abstraction* c, int v)
      : BoolExpr(c)
      , value(v != 0)
    {
    }

    BoolConst::BoolConst(Abstraction* c, boost::python::long_ v)
      : BoolExpr(c)
      , value(v != 0)
    {
    }

    BoolConst::~BoolConst()
    {
    }

    Node* BoolConst::clone() const
    {
        return new BoolConst(ctx, value);
    }

    std::ostream& BoolConst::write(std::ostream& out) const
    {
        return (out << (value ? "true" : "false"));
    }

    // ---------------------------------------------------------------------- //
    bool BoolOp::checkUnaryOpTypes(
        Op op, boost::shared_ptr<Node> arg0)
    {
        return arg0->type.isBool();
    }

    bool BoolOp::checkBinaryOpTypes(
        Op op, 
        boost::shared_ptr<Node> n1, 
        boost::shared_ptr<Node> n2)
    {
        if (op == EQUAL || op == DISTINCT) {
            return n1->type == n2->type;
        } else {
            return n1->type.isBool() && n2->type.isBool();
        }
    }

    // constructor: unary ops.
    BoolOp::BoolOp(Abstraction* c, 
        Op op, 
        boost::shared_ptr<Node> n1
    )
      : BoolExpr(c)
      , arity(UNARY)
      , op(op)
    {

        // check if for the correct operator.
        if (!isUnary(op)) {
            throw PyILAException(PyExc_ValueError, 
                                 "Invalid unary operator.");
        }
        // check for the right type.
        if (!checkUnaryOpTypes(op, n1)) {
            throw PyILAException(
                PyExc_TypeError, 
                "Invalid type for unary operator argument.");
        }

        // push this into the vector.
        args.push_back( n1 );
    }

    // constructor: binary ops.
    BoolOp::BoolOp(Abstraction* c, 
        Op op,
        boost::shared_ptr<Node> n1,
        boost::shared_ptr<Node> n2
    )
      : BoolExpr(c)
      , arity(BINARY)
      , op(op)
    {
        if (!isBinary(op)) {
            throw PyILAException(PyExc_ValueError,
                                 "Invalid binary operator.");
        }

        if (!checkBinaryOpTypes(op, n1, n2)) {
            throw PyILAException(
                PyExc_TypeError, 
                "Invalid type for binary operator argument.");
        }

        args.push_back( n1 );
        args.push_back( n2 );
    }

    // destructor.
    BoolOp::~BoolOp()
    {
    }

    // clone.
    Node* BoolOp::clone() const
    {
        if (arity == UNARY) {
            ILA_ASSERT(args.size() == 1, 
                "Unary op must have exactly one argument.");
            return new BoolOp(ctx, op, args[0]);
        } else if(arity == BINARY) {
            ILA_ASSERT(args.size() == 2,
                "Binary op must have exactly two arguments.");
            return new BoolOp(ctx, op, args[0], args[1]);
        } else {
            ILA_ASSERT(false, "Unsupported arity in BoolOp");
            return NULL;
        }
    }

    // stream output.
    std::ostream& BoolOp::write(std::ostream& out) const
    {
        out << "(" << operatorNames[(int)op];
        for (auto arg: args) {
            arg->write(out << " ");
        }
        out << ")";
        return out;
    }
}
