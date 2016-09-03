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
        "lt", "gt", "le", "ge", "ult", "ugt", "ule", "uge", 
        "eq", "neq",
        "if"
    };

    nptr_t BoolConst::true_node(new BoolConst(true));
    nptr_t BoolConst::false_node(new BoolConst(false));

    // ---------------------------------------------------------------------- //
    BoolExpr::BoolExpr()
      : Node(NodeType::getBool())
    {
    }

    BoolExpr::BoolExpr(NodeType t)
      : Node(t)
    {
        ILA_ASSERT(t.isBool(), "BoolExpr type mismatch.");
    }

    BoolExpr::~BoolExpr()
    {
    }

    // ---------------------------------------------------------------------- //
    BoolVar::BoolVar(const std::string& name)
      : BoolExpr()
    {
        this->name = name;
    }

    BoolVar::~BoolVar()
    {
    }

    Node* BoolVar::clone() const
    {
        return new BoolVar(name);
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
    BoolConst::BoolConst(bool v)
      : BoolExpr()
      , value(v)
    {
    }

    BoolConst::BoolConst(int v)
      : BoolExpr()
      , value(v != 0)
    {
    }

    BoolConst::BoolConst(const mp_int_t& v)
      : BoolExpr()
      , value(v != 0)
    {
    }

    BoolConst::~BoolConst()
    {
    }

    Node* BoolConst::clone() const
    {
        return new BoolConst(value);
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

    nptr_t BoolOp::arg(unsigned i) const
    {
        return i < args.size() ? args[i] : NULL;
    }
    // ---------------------------------------------------------------------- //
    bool BoolOp::checkUnaryOpTypes(Op op, const nptr_t& arg0)
    {
        return arg0->type.isBool();
    }

    bool BoolOp::checkBinaryOpTypes(Op op, const nptr_t& n1, const nptr_t& n2)
    {
        if (op >= SLT || op <= DISTINCT) {
            return n1->type == n2->type;
        } else {
            return n1->type.isBool() && n2->type.isBool();
        }
    }

    int BoolOp::checkTernaryOpTypes(
       Op op, nptr_vec_t args_)
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
    BoolOp::BoolOp(Op op, const nptr_t& n1)
      : BoolExpr()
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
    BoolOp::BoolOp(Op op, const nptr_t& n1, const nptr_t& n2)
      : BoolExpr()
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

    BoolOp::BoolOp(Op op, nptr_vec_t& args_)
        : BoolExpr()
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
            
    BoolOp::BoolOp(const BoolOp* other, nptr_vec_t& args_)
      : arity(other->arity)
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
            return new BoolOp(op, args[0]);
        } else if(arity == BINARY) {
            ILA_ASSERT(args.size() == 2,
                "Binary op must have exactly two arguments.");
            return new BoolOp(op, args[0], args[1]);
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
            if (!t1) return false;
            // compare args.
            for (unsigned i=0; i < args.size(); i++) {
                if (!this->args[i]->equal(that->args[i].get())) {
                    return false;
                }
            }
            return true;
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

    nptr_t& BoolOp::negate(const nptr_t& n, rwmap_t& cache)
    {
        auto pos = cache.find(n.get());
        if (pos != cache.end()) {
            return pos->second;
        }

        ILA_ASSERT(
            n->type.isBool(), 
            "Argument to negate must be a boolean.");
        const BoolOp* boolop = dynamic_cast<const BoolOp*>(n.get());
        if (boolop == NULL || boolop->op != BoolOp::NOT) {
            nptr_t nptr(new BoolOp(BoolOp::NOT, n));
            cache[n.get()] = nptr;
        } else {
            cache[n.get()] = boolop->arg(0);
        }
        return cache[n.get()];
    }
}
