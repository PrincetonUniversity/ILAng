#ifndef __AST_BOOL_HPP_DEFINED__
#define __AST_BOOL_HPP_DEFINED__

#include <iostream>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#include <z3++.h>
#include <assert.h>
#include <type.hpp>

#include <ast.hpp>

namespace ila 
{
    class Abstraction;

    // ---------------------------------------------------------------------- //
    // Boolean expressions are derived from this class.
    class BoolExpr : public Node {
    public:
        // constructor.
        BoolExpr(Abstraction* c);
        // constructor needed for ChoiceExpr
        BoolExpr(Abstraction* c, NodeType t);
        // destructor.
        virtual ~BoolExpr();
    };

    // ---------------------------------------------------------------------- //
    // Boolean variables.
    class BoolVar : public BoolExpr {
    public:
        BoolVar(Abstraction* c, const std::string& name);
        virtual ~BoolVar();
        virtual Node* clone() const;
        virtual bool equal(const Node* that) const;
        virtual std::ostream& write(std::ostream& out) const;
    };

    // ---------------------------------------------------------------------- //
    // Boolean constants.
    class BoolConst : public BoolExpr {
    protected:
        bool value;
    public:
        BoolConst(Abstraction* c, bool value);
        BoolConst(Abstraction* c, int value);
        BoolConst(Abstraction* c, const mp_int_t& l);
        virtual ~BoolConst();
        virtual Node* clone() const;
        virtual bool equal(const Node* that) const;
        virtual boost::python::object getValue() const;
        virtual std::ostream& write(std::ostream& out) const;

        // helper functions.
        bool val() const { return value; }
    };

    // ---------------------------------------------------------------------- //
    // Boolean operators.
    class BoolOp : public BoolExpr {
    public:
        // Number of operands.
        enum Arity { UNARY, BINARY, TERNARY } arity; 

        // What is the operation?
        enum Op { 
            // invalid
            INVALID,
            // unary
            NOT, 
            // binary.
            AND, OR, XOR, XNOR, NAND, NOR, IMPLY,
            SLT, SGT, SLE, SGE, ULT, UGT, ULE, UGE, 
            EQUAL, DISTINCT,
            // ternary
            IF
        } op;

        static const std::string operatorNames[];

        // the operands themselves.
        nptr_vec_t args;

    private:
        // Don't forget to update these helper functions below.
        static bool isUnary(Op op) { return op >= NOT && op <= NOT; }
        static bool isBinary(Op op) { return op >= AND && op <= DISTINCT; }
        static bool isTernary(Op op) { return op >= IF && op <= IF; }
        // helper functions to check argument types.
        static bool checkUnaryOpTypes(Op op, const nptr_t& n);
        static bool checkBinaryOpTypes(Op op, const nptr_t& n1, const nptr_t& n2);
        static int checkTernaryOpTypes(Op op, nptr_vec_t args_);

    public:
        // constructors.
        BoolOp(Abstraction* c, Op op, const nptr_t& n1);
        BoolOp(Abstraction* c, Op op, const nptr_t& n1, const nptr_t& n2);
        BoolOp(Abstraction* c, Op op, nptr_vec_t& args_);
        // kind of like a copy constructor, but use a fresh set of args.
        BoolOp(const BoolOp* other, nptr_vec_t& args_);
        // destructors.
        virtual ~BoolOp();

        // clone.
        virtual Node* clone() const;

        // equal.
        virtual bool equal(const Node* that) const;

        // stream output.
        virtual std::ostream& write(std::ostream& out) const;

        // number of operands.
        virtual unsigned nArgs() const;

        // operand i.
        virtual nptr_t arg(unsigned i) const;

        // operation.
        Op getOp() const { return op; }
    };
}
#endif
