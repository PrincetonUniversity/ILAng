#include <iostream>
#include <boost/lexical_cast.hpp>
#include <cstdint>
#include <limits>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <abstraction.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    const std::string BitvectorOp::operatorNames[] = {
        "invalid",
        // unary
        "neg", "~",
        "rotate-left", "rotate-right", "zero-extend", "sign-extend", "extract",
        // binary
        "+", "-", "and", "or", "xor", "xnor", "nand", "nor",
        "div", "udiv", "rem", "urem", "mod", "shl", "lshr", "ashr", 
        "*", "concat", "get-bit", "readmem", "read-block",
		// ternary
        "if", "apply_fun", 
    };

    // ---------------------------------------------------------------------- //
    BitvectorExpr::BitvectorExpr(int width) 
        : Node(NodeType::getBitvector(width))
    {
    }

    BitvectorExpr::BitvectorExpr(NodeType t)
        : Node(t)
    {
        ILA_ASSERT(t.isBitvector(), "BitvectorExpr type mismatch.");
    }

    BitvectorExpr::~BitvectorExpr()
    {
    }

    // ---------------------------------------------------------------------- //
    BitvectorVar::BitvectorVar(const std::string& n, int width) 
        : BitvectorExpr(width)
    {
        this->name = n;
    }

    BitvectorVar::~BitvectorVar()
    {
    }

    Node* BitvectorVar::clone() const
    {
        return new BitvectorVar(name, type.bitWidth);
    }

    bool BitvectorVar::equal(const Node* that_) const
    {
        const BitvectorVar* that = dynamic_cast<const BitvectorVar*>(that_);
        if (that != NULL) {
            return that->type == this->type &&
                   that->name == this->name;
        } else {
            return false;
        }
    }

    std::ostream& BitvectorVar::write(std::ostream& out) const
    {
        return (out << name);
    }


    // ---------------------------------------------------------------------- //
    BitvectorConst::BitvectorConst(
        const mp_int_t& v, int w)
        : BitvectorExpr(w)
        , value(v)
    {
    }

    BitvectorConst::BitvectorConst(unsigned int v, int w)
        : BitvectorExpr(w)
        , value(v)
    {
    }

    BitvectorConst::BitvectorConst(const BitvectorConst& that)
        : BitvectorExpr(that.type.bitWidth)
        , value(that.value)
    {
    }

    BitvectorConst::~BitvectorConst()
    {
    }

    Node* BitvectorConst::clone() const
    {
        return new BitvectorConst(*this);
    }

    bool BitvectorConst::equal(const Node* that_) const
    {
        const BitvectorConst* that = dynamic_cast<const BitvectorConst*>(that_);
        if (that != NULL) {
            return that->type == this->type &&
                   that->value == this->value;
        } else {
            return false;
        }
    }

    py::object BitvectorConst::getValue() const
    {
        using namespace py;

        std::string vstr = boost::lexical_cast<std::string>(value);
        PyObject* l_e = PyInt_FromString((char*) vstr.c_str(), NULL, 0);
        object o_e(handle<>(borrowed(l_e)));
        return o_e;
    }

    std::ostream& BitvectorConst::write(std::ostream& out) const
    {
        return (out << value);
    }

    // ---------------------------------------------------------------------- //
    unsigned BitvectorOp::nArgs() const
    {
        return args.size();
    }

    unsigned BitvectorOp::nParams() const
    {
        return params.size();
    }

    nptr_t BitvectorOp::arg(unsigned i) const
    {
        return i < args.size() ? args[i] : NULL;
    }

    int BitvectorOp::param(unsigned i) const
    {
        return i < params.size() ? params[i] : 0;
    }
    // ---------------------------------------------------------------------- //
    int BitvectorOp::getUnaryResultWidth(Op op, const nptr_t& n)
    {
        // FIXME: add more code when operators are added.
        if (op >= NEGATE && op <= RROTATE) {
            return n->type.bitWidth;
        } else { 
            return n->type.bitWidth;
        }
    }

    int BitvectorOp::getBinaryResultWidth(
        Op op, const nptr_t& n1, const nptr_t& n2)
    {
        // FIXME: add more code when operators are added.
        if (op >= ADD && op <= MUL) {
            return n1->type.bitWidth;
        } else if (op == CONCAT) {
            return n1->type.bitWidth + n2->type.bitWidth;
        } else if (op == GET_BIT) {
            return 1;
        } else if (op == READMEM) {
            return n1->type.dataWidth;
        } else { 
            return n1->type.bitWidth; // INVALID
        }
    }

    int BitvectorOp::getBinaryResultWidth(
        Op op, const nptr_t& n1, const nptr_t& n2, int param)
    {
        if (op == READMEMBLOCK) {
            return n1->type.dataWidth*param;
        } else {
            // INVALID
            return 0;
        }
    }

    int BitvectorOp::getBinaryResultWidth(
        Op op, const nptr_t& n1, int param)
    {
        if (op >= Z_EXT && op <= S_EXT) {
            return param;
        } else {
            return n1->type.bitWidth;
        }
    }

    int BitvectorOp::getNaryResultWidth(
        Op op, nptr_vec_t& args)
    {
        // FIXME: add more code when operators are added.
        if (op == IF && args.size() == 3) {
            // ITE
            return args[1]->type.bitWidth;
        } else if (op == APPLY_FUNC) {
            // Apply function
            return args[0]->type.bitWidth;
        } else {
            return 1;
        }
    }

    int BitvectorOp::getNaryResultWidth(
        Op op, nptr_vec_t& args, std::vector< int >& params)
    {
        // FIXME: add more code when operators are added.
        if (op == EXTRACT && params.size() == 2) {
            // EXTRACT
            return (params[1] - params[0] + 1);
        } else {
            return 1;
        }
    }

    bool BitvectorOp::checkUnaryOpWidth(Op op, const nptr_t& arg0, int width)
    {
        // FIXME: add more code when operators are added.
        if (op >= Z_EXT && op <= S_EXT) {
            return (arg0->type.isBitvector() && arg0->type.bitWidth <= width);
        } else {
            return arg0->type.isBitvector(width);
        }
    }

    int BitvectorOp::checkBinaryOpWidth(
        Op op, 
        const nptr_t& n1, 
        const nptr_t& n2,
        int width)
    {
        // FIXME: add more code when operators are added.
        if (op >= ADD && op <= MUL) {
            if (!n1->type.isBitvector(width)) {
                return 1;
            } else if (!n2->type.isBitvector(width)) {
                return 2;
            } else {
                return 0;
            }
        } else if (op == GET_BIT) {
            if (!n1->type.isBitvector()) {
                return 1;
            } else if (!n2->type.isBitvector()) {
                return 2;
            } else {
                return 0;
            }
        } else if (op == READMEM) {
            if (!n1->type.isMem()) {
                return 1;
            } else if (!n2->type.isBitvector(n1->type.addrWidth)) {
                return 2;
            } else {
                return 0;
            }
        }
        // CONCAT can have different operand width
        return 0;
    }

    int BitvectorOp::checkBinaryOpWidth(
        Op op, 
        const nptr_t& n1, 
        const nptr_t& n2,
        int param,
        int width)
    {
        // FIXME: add more code when operators are added.
        if (op == READMEMBLOCK) {
            if (!n1->type.isMem()) {
                return 1;
            } else if (!n2->type.isBitvector(n1->type.addrWidth)) {
                return 2;
            } else {
                return 0;
            }
        }
        ILA_ASSERT(false, "Unknown binary operator with param.");
        return 0;
    }

    int BitvectorOp::checkBinaryOpWidth(
        Op op,
        const nptr_t& n1,
        int param,
        int width)
    {
        if (op >= LROTATE && op <= RROTATE) {
            if (param > width) {
                return 2;
            } else if (!n1->type.isBitvector(width)) {
                return 1;
            } else {
                return 0;
            }
        } else if (op >= Z_EXT && op <= S_EXT) {
            if (param < width) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    int BitvectorOp::checkNaryOpWidth(
        Op op,
        nptr_vec_t& args,
        int width)
    {
        // FIXME: modify the code if other n-ary ops are added.
        if (op >= IF && op <= IF && args.size() == 3) {
            // (cond, trueExp, falseExp)
            for (unsigned i=1; i != args.size(); i++) {
                if (!args[1]->type.isBitvector(width)) {
                    return i+1;
                }
            }
            if (!args[0]->type.isBool() /* or nonzero (bv) */ ) {
                return 1;
            } 
        } else if (op == APPLY_FUNC) {
            // (f, ip0, ip1, ...)
            std::vector<int> argWidth;
            for (unsigned i = 1; i != args.size(); i++) {
                argWidth.push_back(args[i]->type.bitWidth);
            }
            if (!args[0]->type.isFunc(width, argWidth)) {
                return 1;
            }
            for (unsigned i = 1; i != args.size(); i++) {
                if (!args[i]->type.isBitvector(args[0]->type.argsWidth[i-1])) {
                    return i + 1;
                }
            }
            return 0;
        }
        return 0;
    }

    int BitvectorOp::checkNaryOpWidth(
        Op op,
        nptr_vec_t& args,
        std::vector< int >& params,
        int width)
    {
        // FIXME: modify the code if other n-ary ops are added
        if (op >= EXTRACT && op <= EXTRACT) {
            // (bv, start, end)
            if (params.size() == 2 && args.size() == 1) {
                if (params[0] < 0) {
                    return 2;
                } else if (params[1] >= args[0]->type.bitWidth) {
                    return 3;
                } else if (!args[0]->type.isBitvector()) {
                    return 1;
                }
            }
        }
        return 0;
    }

    // ---------------------------------------------------------------------- //
    // constructor: unary ops.
    BitvectorOp::BitvectorOp(
        Op op, 
        const nptr_t& n1
    )
      : BitvectorExpr(getUnaryResultWidth(op, n1))
      , arity(UNARY)
      , op(op)
    {

        // check if for the correct operator.
        if (!isUnary(op)) {
            throw PyILAException(PyExc_ValueError, 
                                 "Invalid unary operator: " +
                                 operatorNames[op]);
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

    // constructor: unary op with int input (ex. rotate)
    BitvectorOp::BitvectorOp(
        Op op,
        const nptr_t& n1,
        int param
    )
      : BitvectorExpr(getBinaryResultWidth(op, n1, param))
      , arity(UNARY)
      , op(op)
    {
        if (!isUnary(op)) {
            throw PyILAException(PyExc_ValueError,
                                 "Invalid binary operator: " + 
                                 operatorNames[op]);
        }
        if(!checkUnaryOpWidth(op, n1, type.bitWidth)) {
            throw PyILAException(PyExc_TypeError,
                "Invalid operand for operator: " + operatorNames[op]);
        }
        args.push_back( n1 );
        params.push_back(param);
    }

    // constructor: extract
    BitvectorOp::BitvectorOp(
        Op op, 
        const nptr_t& n1,
        int p1, int p2
    )
        : BitvectorExpr((p1 - p2)+1)
        , arity(UNARY)
        , op(op)
    {
        if(op != EXTRACT) {
            throw PyILAException(PyExc_ValueError,
                     "Invalid operator: " + operatorNames[op]);
        } else if(p1 < p2) {
            throw PyILAException(PyExc_ValueError,
                     "Invalid indices to extract.");
        }
        if (!(n1->type.isBitvector()    &&
              n1->type.bitWidth >= p1   &&
              n1->type.bitWidth >= p2)) 
        {
            throw PyILAException(PyExc_TypeError,
                    "Invalid type for operator: " + operatorNames[op]);
        }
        args.push_back(n1);
        params.push_back(p1);
        params.push_back(p2);
    }

    // constructor: binary ops.
    BitvectorOp::BitvectorOp(
        Op op,
        const nptr_t& n1,
        const nptr_t& n2
    )
      : BitvectorExpr(getBinaryResultWidth(op, n1, n2))
      , arity(BINARY)
      , op(op)
    {
        if (!isBinary(op)) {
            throw PyILAException(PyExc_ValueError,
                                 "Invalid binary operator: " + 
                                 operatorNames[op]);
        }

        int error = checkBinaryOpWidth(op, n1, n2, type.bitWidth);
        if (error != 0) {
            throw PyILAException(PyExc_TypeError,
                "Invalid operand (" + 
                boost::lexical_cast<std::string>(error) +
                ") for operator: " + operatorNames[op]);
        }
        args.push_back( n1 );
        args.push_back( n2 );
    }

    BitvectorOp::BitvectorOp(Op op,
        const nptr_t& n1,
        const nptr_t& n2,
        int blocks,
        endianness_t e)
      : BitvectorExpr(getBinaryResultWidth(op, n1, n2, blocks))
      , arity(BINARY)
      , op(op)
    {
        if (op != READMEMBLOCK) {
            throw PyILAException(PyExc_ValueError,
                                 "Invalid binary operator; expected read-block.");
        }
        if (blocks < 1) {
            throw PyILAException(PyExc_ValueError,
                                 "Invalid number of chunks.");
        }
        if (e != LITTLE_E && e != BIG_E) {
            throw PyILAException(PyExc_ValueError,
                                "Invalid endianness value.");
        }

        int error = checkBinaryOpWidth(op, n1, n2, blocks, type.bitWidth);
        if (error != 0) {
            throw PyILAException(PyExc_TypeError,
                "Invalid operand (" + 
                boost::lexical_cast<std::string>(error) +
                ") for operator: " + operatorNames[op]);
        }
        args.push_back( n1 );
        args.push_back( n2 );
        params.push_back( blocks );
        params.push_back( (int) e);
    }

    
    // constructor: ternary ops
    BitvectorOp::BitvectorOp(
        Op op, nptr_vec_t& args_
    )
      : BitvectorExpr(getNaryResultWidth(op, args_))
      , arity(NARY)
      , op(op)
      , args(args_)
    {
        if (!isTernary(op) && !isNary(op)) {
            throw PyILAException(PyExc_ValueError,
                                 "Invalid n-ary operator: " + 
                                 operatorNames[op]);
        }
        int error = checkNaryOpWidth(op, args, type.bitWidth);
        if (error != 0) {
            throw PyILAException(PyExc_TypeError,
                "Invalid operand (" + 
                boost::lexical_cast<std::string>(error) +
                ") for operator: " + operatorNames[op]);
        }
    }

    BitvectorOp::BitvectorOp(const BitvectorOp* other, nptr_vec_t& args_)
      : BitvectorExpr(other->type.bitWidth)
      , arity(other->arity)
      , op(other->op)
      , args(args_)
      , params(other->params)
    {
    }

    // destructor.
    BitvectorOp::~BitvectorOp()
    {
    }

    // ---------------------------------------------------------------------- //
    // clone.
    Node* BitvectorOp::clone() const
    {
        if (arity == UNARY) {
            ILA_ASSERT(args.size() == 1, 
                "Unary op must have exactly one argument.");
            // check type if it is zero/sign_extend
            if(op == Z_EXT || op == S_EXT)
                return new BitvectorOp(op, args[0], params[0]);
            else if (op == EXTRACT)
                return new BitvectorOp(op, args[0], params[0], params[1]);
            else
                return new BitvectorOp(op, args[0]);
        } else if(arity == BINARY) {
            ILA_ASSERT(args.size() == 2,
                "Binary op must have exactly two arguments.");
            return new BitvectorOp(op, args[0], args[1]);
        } else if (arity == NARY) {
            ILA_ASSERT(args.size() >= 1,
                "Nary op must have more than one arguments.");
            nptr_vec_t newargs;
            for (unsigned i = 0; i != args.size(); i++)
                newargs.push_back(args[i]);
            return new BitvectorOp(op, newargs);
        } else {
            ILA_ASSERT(false, "Unsupported arity in BitvectorOp");
            return NULL;
        }
    }

    // equal.
    bool BitvectorOp::equal(const Node* that_) const
    {
        const BitvectorOp* that = dynamic_cast<const BitvectorOp*>(that_);
        if (that != NULL) {
            // compare op and type..
            bool t1 = that->type == this->type && this->op == that->op &&
                      that->args.size() == this->args.size()           &&
                      that->params.size() == this->params.size();
            if (!t1) return false;

            // compare params.
            for (unsigned i=0; i != params.size(); i++) {
                if (this->params[i] != that->params[i]) {
                    return false;
                }
            }

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
    std::ostream& BitvectorOp::write(std::ostream& out) const
    {
        out << "(" << operatorNames[(int)op];
        for (auto arg: args) {
            out << " " << *arg.get();
        }
        for (auto p : params) {
            out << " #" << p;
        }
        out << ")";
        return out;
    }

}

