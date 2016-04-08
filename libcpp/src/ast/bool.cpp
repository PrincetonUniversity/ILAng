#include <iostream>
#include <boost/lexical_cast.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <abstraction.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    const std::string BoolOp::operatorNames[] = {
        "invalid",
        "not", 
        "and", "or", "xor", "xnor", "nand", "nor", "imply",
        "lt", "gt", "le", "ge", "ult", "ugt", "uge", "uge", 
        "eq", "neq",
        "if"
    };

    // ---------------------------------------------------------------------- //
    BoolExpr::BoolExpr(Abstraction* c)
      : Node(c, NodeType::getBool())
    {
    }

    BoolExpr::BoolExpr(Abstraction* c, NodeType t)
      : Node(c, t)
    {
        ILA_ASSERT(t.isBool(), "BoolExpr type mismatch.");
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

    bool BoolVar::equal(const Node* that_) const
    {
        const BoolVar* that = dynamic_cast<const BoolVar*>(that_);
        if (that != NULL) {
            return that->name == this->name;
        } else {
            return false;
        }
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

    BoolConst::BoolConst(Abstraction* c, const boost::multiprecision::cpp_int& v)
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

    bool BoolConst::equal(const Node* that_) const
    {
        const BoolConst* that = dynamic_cast<const BoolConst*>(that_);
        if (that != NULL) {
            return that->value == this->value;
        } else {
            return false;
        }
    }

    boost::python::object BoolConst::getValue() const
    {
        boost::python::object obj(value);
        return obj;
    }

    std::ostream& BoolConst::write(std::ostream& out) const
    {
        return (out << (value ? "true" : "false"));
    }

    // ---------------------------------------------------------------------- //
    unsigned BoolOp::nArgs() const
    {
        return args.size();
    }

    boost::shared_ptr<Node> BoolOp::arg(unsigned i) const
    {
        return i < args.size() ? args[i] : NULL;
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
        if (op >= SLT || op <= DISTINCT) {
            return n1->type == n2->type;
        } else {
            return n1->type.isBool() && n2->type.isBool();
        }
    }

    int BoolOp::checkTernaryOpTypes(
       Op op, std::vector< boost::shared_ptr<Node> > args_)
    {
        for (size_t i=0; i<args_.size(); i++) {
            if (!args_[i]->type.isBool()) {
                return i+1;
            }
        }
        return 0;
    }

    // ---------------------------------------------------------------------- //
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

    BoolOp::BoolOp(
        Abstraction* c,
        Op op,
        std::vector< boost::shared_ptr<Node> >& args_
    )
        : BoolExpr(c)
        , arity(TERNARY)
        , op(op)
        , args(args_)
    {
        if (!isTernary(op)) {
            throw PyILAException(PyExc_ValueError,
                                    "Invalid n-ary operator.");
        }
        int error = checkTernaryOpTypes(op, args);
        if (error != 0) {
            throw PyILAException(
                PyExc_TypeError, 
                "Invalid operand (" + 
                boost::lexical_cast<std::string>(error) + 
                ") for operator: " + 
                operatorNames[op]);
        }
    }
            
    BoolOp::BoolOp(
        const BoolOp* other, 
        std::vector< boost::shared_ptr<Node> >& args_)
      : BoolExpr(other->ctx)
      , arity(other->arity)
      , op(other->op)
      , args(args_)
    {
    }

    // destructor.
    BoolOp::~BoolOp()
    {
    }

    // ---------------------------------------------------------------------- //
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

    bool BoolOp::equal(const Node* that_) const
    {
        const BoolOp* that = dynamic_cast<const BoolOp*>(that_);
        if (that != NULL) {
            bool t1 = that->type == this->type && this->op == that->op &&
                      that->args.size() == this->args.size();
            if (t1) {
                for (unsigned i=0; i < args.size(); i++) {
                    if (!this->args[i]->equal(that->args[i].get())) {
                        return false;
                    }
                }
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    // stream output.
    std::ostream& BoolOp::write(std::ostream& out) const
    {
        out << "(" << operatorNames[(int)op];
        for (auto arg: args) {
            out << " " << *arg.get();
        }
        out << ")";
        return out;
    }
}
