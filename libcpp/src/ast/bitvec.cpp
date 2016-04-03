#include <iostream>
#include <boost/lexical_cast.hpp>

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
        "-", "~",
        // binary
        "+", "-", "and", "or", "xor", "xnor", "nand", "nor",
        "div", "udiv", "rem", "urem", "mod", "<<", ">>>", ">>", 
        "*", "lrot", "rrot", "::",
		// ternary
        "if", "extract",
    };

    // ---------------------------------------------------------------------- //
    BitvectorExpr::BitvectorExpr(Abstraction *c, int width) 
        : Node(c, NodeType::getBitvector(width))
    {
    }

    BitvectorExpr::~BitvectorExpr()
    {
    }

    // ---------------------------------------------------------------------- //
    BitvectorVar::BitvectorVar(Abstraction* c, const std::string& n, int width) 
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

    z3::expr BitvectorVar::toZ3(Z3AdapterI& c) const
    {
        return c.bitvectorVar(name, type.bitWidth, false);
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

    BitvectorConst::BitvectorConst(const BitvectorConst& that)
        : BitvectorExpr(that.ctx, that.type.bitWidth)
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

    boost::python::object BitvectorConst::getValue() const
    {
        return value;
    }

    std::ostream& BitvectorConst::write(std::ostream& out) const
    {
        std::string string_value = boost::python::extract<std::string>(boost::python::str(value));
        return (out << string_value);
    }

    z3::expr BitvectorConst::toZ3(Z3AdapterI& c) const
    {
        std::string string_value = 
            boost::python::extract<std::string>(
                boost::python::str(value));
        return c.ctx().bv_val(string_value.c_str(), type.bitWidth);
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

    boost::shared_ptr<Node> BitvectorOp::arg(unsigned i) const
    {
        return i < args.size() ? args[i] : NULL;
    }

    int BitvectorOp::param(unsigned i) const
    {
        return i < params.size() ? params[i] : 0;
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
        if (op >= ADD && op <= MUL) {
            return n1->type.bitWidth;
        } else if (op >= CONCAT && op <= CONCAT) {
            return n1->type.bitWidth + n2->type.bitWidth;
        } else { 
            return n1->type.bitWidth; // INVALID
        }
    }

    int BitvectorOp::getBinaryResultWidth(
        Op op, boost::shared_ptr<Node> n1, int param)
    {
        if (op >= LROTATE || op <= RROTATE) {
            return n1->type.bitWidth;
        } else {
            return n1->type.bitWidth; // INVALID
        }
    }

    int BitvectorOp::getNaryResultWidth(
        Op op, std::vector< boost::shared_ptr<Node> >& args)
    {
        // FIXME: add more code when operators are added.
        if (op == IF && args.size() == 3) {
            // ITE
            return args[1]->type.bitWidth;
        } else {
            return 1;
        }
    }

    int BitvectorOp::getNaryResultWidth(
        Op op, std::vector< boost::shared_ptr<Node> >& args, std::vector< int >& params)
    {
        // FIXME: add more code when operators are added.
        if (op == EXTRACT && params.size() == 2) {
            // EXTRACT
            return (params[1] - params[0] + 1);
        } else {
            return 1;
        }
    }

    bool BitvectorOp::checkUnaryOpWidth(Op op, boost::shared_ptr<Node> arg0, int width)
    {
        // FIXME: add more code when operators are added.
        return arg0->type.isBitvector(width);
    }

    int BitvectorOp::checkBinaryOpWidth(
        Op op, 
        boost::shared_ptr<Node> n1, 
        boost::shared_ptr<Node> n2,
        int width)
    {
        // FIXME: add more code when operators are added.
        if (op >= ADD && op <= MUL) {
            if (!n1->type.isBitvector(width)) {
                return 1;
            }
	        if (!n2->type.isBitvector(width)) {
                return 2;
            }
            return 0;
        }
        // CONCAT can have different operand width
        return 0;
    }

    int BitvectorOp::checkBinaryOpWidth(
        Op op,
        boost::shared_ptr<Node> n1,
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
        } else {
            return 0;
        }
    }
    int BitvectorOp::checkNaryOpWidth(
        Op op,
        std::vector< boost::shared_ptr<Node> >& args,
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
        }
        return 0;
    }

    int BitvectorOp::checkNaryOpWidth(
        Op op,
        std::vector< boost::shared_ptr<Node> >& args,
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
    
    // constructor: bin ops with int input (ex. rotate)
    BitvectorOp::BitvectorOp(Abstraction* c,
        Op op,
        boost::shared_ptr<Node> n1,
        int param
    )
      : BitvectorExpr(c, getBinaryResultWidth(op, n1, param))
      , arity(BINARY)
      , op(op)
    {
        if (!isBinary(op)) {
            throw PyILAException(PyExc_ValueError,
                                 "Invalid binary operator: " + 
                                 operatorNames[op]);
        }

        int error = checkBinaryOpWidth(op, n1, param, type.bitWidth);
        if (error != 0) {
            throw PyILAException(PyExc_TypeError,
                "Invalid operand (" + 
                boost::lexical_cast<std::string>(error) +
                ") for operator: " + operatorNames[op]);
        }
        args.push_back( n1 );
        params.push_back(param);
    }

    // constructor: ternary ops
    BitvectorOp::BitvectorOp(
        Abstraction* c, Op op,
        std::vector< boost::shared_ptr<Node> >& args_
    )
      : BitvectorExpr(c, getNaryResultWidth(op, args_))
      , arity(NARY)
      , op(op)
      , args(args_)
    {
        if (!isTernary(op)) {
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

    // constructor: ternary ops with int input (ex. extract)
    BitvectorOp::BitvectorOp(
        Abstraction* c, Op op, 
        std::vector< boost::shared_ptr<Node> >& args_,
        std::vector< int >& params_
    )
        : BitvectorExpr(c, getNaryResultWidth(op, args_, params_))
        , arity(NARY)
        , op(op)
        , args(args_)
        , params(params_)
    {
        if(!isTernary(op)) {
            throw PyILAException(PyExc_ValueError,
                     "Invalid n-ary operator: " + operatorNames[op]);
        }
        int error = checkNaryOpWidth(op, args, params, type.bitWidth);
        if (error != 0) {
            throw PyILAException(PyExc_TypeError,
                    "Invalid operand (" + 
                    boost::lexical_cast<std::string>(error) + 
                    ") for operator: " + operatorNames[op]);
        }
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

    // equal.
    bool BitvectorOp::equal(const Node* that_) const
    {
        const BitvectorOp* that = dynamic_cast<const BitvectorOp*>(that_);
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
    std::ostream& BitvectorOp::write(std::ostream& out) const
    {
        out << "(" << operatorNames[(int)op];
        for (auto arg: args) {
            arg->write(out << " ");
        }
        out << ")";
        return out;
    }

    z3::expr BitvectorOp::toZ3(Z3AdapterI& c) const
    {
        using namespace z3;

        if (isUnary(op)) {
            expr arg = c.expr(args[0].get());
            if (op == NEGATE) {
                return -arg;
            } else if (op == COMPLEMENT) {
                return ~arg;
            } else if (op == LROTATE) {
                Z3_ast r = Z3_mk_rotate_left(c.ctx(), 1, arg);
                return expr(c.ctx(), r);
            } else if (op == RROTATE) {
                Z3_ast r = Z3_mk_rotate_right(c.ctx(), 1, arg);
                return expr(c.ctx(), r);
            }
        } else if (isBinary(op)) {
            if (op >= LROTATE && op <= RROTATE)
            {
                expr obj = c.expr(args[0].get());
                int par = params[0];
                if (op == LROTATE) {
                    Z3_ast r = Z3_mk_rotate_left(c.ctx(), par, obj);
                    return expr(c.ctx(), r);
                } else if (op == RROTATE) {
                    Z3_ast r = Z3_mk_rotate_right(c.ctx(), par, obj);
                    return expr(c.ctx(), r);
                }
            } else {
                expr arg0 = c.expr(args[0].get());
                expr arg1 = c.expr(args[1].get());

                if (op == ADD) {
                    return arg0 + arg1;
                } else if (op == SUB) {
                    return arg0 - arg1;
                } else if (op == AND) {
                    return (arg0 & arg1);
                } else if (op == OR) {
                    return (arg0 | arg1);
                } else if (op == XOR) {
                    Z3_ast r = Z3_mk_bvxor(c.ctx(), arg0, arg1);
                    return expr(c.ctx(), r);
                } else if (op == XNOR) {
                    Z3_ast r = Z3_mk_bvxnor(c.ctx(), arg0, arg1);
                    return expr(c.ctx(), r);
                } else if (op == NAND) {
                    return ~(arg0 & arg1);
                } else if (op == NOR) {
                    return ~(arg0 | arg1);
                } else if (op == SDIV) {
                    Z3_ast r = Z3_mk_bvsdiv( c.ctx(), arg0, arg1);
                    return expr(c.ctx(), r);
                } else if (op == UDIV) {
                    Z3_ast r = Z3_mk_bvudiv( c.ctx(), arg0, arg1);
                    return expr(c.ctx(), r);
                } else if (op == SREM) {
                    Z3_ast r = Z3_mk_bvsrem( c.ctx(), arg0, arg1);
                    return expr(c.ctx(), r);
                } else if (op == UREM) {
                    Z3_ast r = Z3_mk_bvurem( c.ctx(), arg0, arg1);
                    return expr(c.ctx(), r);
                } else if (op == SMOD) {
                    Z3_ast r = Z3_mk_bvsmod( c.ctx(), arg0, arg1);
                    return expr(c.ctx(), r);
                } else if (op == SHL) {
                    Z3_ast r = Z3_mk_bvshl( c.ctx(), arg0, arg1);
                    return expr(c.ctx(), r);
                } else if (op == LSHR) {
                    Z3_ast r = Z3_mk_bvlshr( c.ctx(), arg0, arg1);
                    return expr(c.ctx(), r);
                } else if (op == ASHR) {
                    Z3_ast r = Z3_mk_bvashr( c.ctx(), arg0, arg1);
                    return expr(c.ctx(), r);
                } else if (op == MUL) {
                    Z3_ast r = Z3_mk_bvmul( c.ctx(), arg0, arg1);
                    return expr(c.ctx(), r);
                } else if (op == CONCAT) {
                    Z3_ast r = Z3_mk_concat( c.ctx(), arg0, arg1);
                    return expr(c.ctx(), r);
                }
            }
        } else if (isTernary(op)) {
            if (op == IF) {
                expr arg0 = c.expr(args[0].get());
                expr arg1 = c.expr(args[1].get());
                expr arg2 = c.expr(args[2].get());
                return ite(arg0, arg1, arg2);
            } else if (op == EXTRACT) {
                expr bv = c.expr(args[0].get());
                unsigned low = static_cast<unsigned> (params[0]);
                unsigned high = static_cast<unsigned> (params[1]);
                Z3_ast r = Z3_mk_extract(c.ctx(), high, low, bv);
                return expr(c.ctx(), r);
            }
        }
        throw PyILAException(PyExc_RuntimeError, 
                "Unable to create Z3 expression for operator: " + operatorNames[op]);
        return c.ctx().bool_val(false);
    }
}

