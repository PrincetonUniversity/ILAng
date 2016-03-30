
#ifndef __AST_BITVEC_HPP_DEFINED__
#define __AST_BITVEC_HPP_DEFINED__

#include <iostream>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>

#include <z3++.h>
#include <assert.h>
#include <type.hpp>

#include <ast.hpp>

namespace ila 
{
    class Abstraction;

    // ---------------------------------------------------------------------- //
    // Bitvector expressions are derived from this class.
    class BitvectorExpr : public Node {
    public:
        // constructor.
        BitvectorExpr(Abstraction* c, int width);
        // destructor.
        virtual ~BitvectorExpr();
    };

    // ---------------------------------------------------------------------- //
    // Bitvector variables.
    class BitvectorVar : public BitvectorExpr {
    public:
        // constructor.
        BitvectorVar(Abstraction* c, const std::string& n, int width) ;
        // destructor.
        virtual ~BitvectorVar();
        // clone.
        virtual Node* clone() const;
        // equality method.
        virtual bool equal(const Node* that) const;
        // stream output.
        virtual std::ostream& write(std::ostream& out) const;
        // convert to an SMT expr.
        virtual z3::expr toZ3(Z3AdapterI& c) const;
    };

    // ---------------------------------------------------------------------- //
    // Bitvector variables.
    class BitvectorConst : public BitvectorExpr {
    protected:
        boost::python::object value;
    public:
        // constructor with longs.
        BitvectorConst(Abstraction* c, boost::python::long_ v, int width);
        // constructor with ints.
        BitvectorConst(Abstraction* c, int v, int width);
        // copy constructor.
        BitvectorConst(const BitvectorConst& other);
        // destructor.
        virtual ~BitvectorConst();
        // clone
        virtual Node* clone() const;
        // equality method.
        virtual bool equal(const Node* that) const;
        // return value.
        virtual boost::python::object getValue() const;
        // stream output.
        virtual std::ostream& write(std::ostream& out) const;
        // convert to an SMT expr.
        virtual z3::expr toZ3(Z3AdapterI& c) const;
    };

    // ---------------------------------------------------------------------- //
    // Bitvector operators.
    class BitvectorOp : public BitvectorExpr {
    public:
        // Number of operands.
        enum Arity { UNARY, BINARY, TERNARY, NARY } arity; 

        // What is the operation?
        enum Op { 
            // invalid
            INVALID,
            // unary
            NEGATE, COMPLEMENT, LNOT, 
			LROTATE, RROTATE,
            // binary.
            ADD, SUB, AND, OR, XOR, XNOR, NAND, NOR,
			SDIV, UDIV, SREM, UREM, SMOD, SHL, LSHR, ASHR, 
			SLT, SGT, SLE, SGE, ULT, UGT, ULE, UGE, EQUAL, DISTINCT,
			MUL, CONCAT, // REPEAT
            // ternary
            IF, // EXTRACT,
        } op;

        static const std::string operatorNames[];

    protected:
        // the operands themselves.
        std::vector< boost::shared_ptr<Node> > args;

        // Don't forget to update these helper functions below.
        static bool isUnary(Op op) { 
            return op >= NEGATE && op <= RROTATE; 
        }
        static bool isBinary(Op op) { 
            return op >= ADD && op <= CONCAT;
        }
        static bool isTernary(Op op) { 
            return op >= IF && op <= IF; 
        }
        static bool isNary(Op op) {
            return false;
        }
        // helper functions to determine result and argument types.
        static int getUnaryResultWidth(
            Op op, 
            boost::shared_ptr<Node> n);
        static int getBinaryResultWidth(
            Op op, 
            boost::shared_ptr<Node> n1, 
            boost::shared_ptr<Node> n2);
        static int getNaryResultWidth(
            Op op, std::vector< boost::shared_ptr<Node> >& args);
        static bool checkUnaryOpWidth(
            Op op, 
            boost::shared_ptr<Node> n, 
            int width);
        static int checkBinaryOpWidth(
            Op op, 
            boost::shared_ptr<Node> n1, 
            boost::shared_ptr<Node> n2, 
            int width);
        static int checkNaryOpWidth(
            Op op,
            std::vector< boost::shared_ptr<Node> > args,
            int width);
    public:
        // constructors.
        BitvectorOp(Abstraction* c, Op op, 
                    boost::shared_ptr<Node> n1);
        BitvectorOp(Abstraction* c, Op op, 
                    boost::shared_ptr<Node> n1, 
                    boost::shared_ptr<Node> n2);
        BitvectorOp(Abstraction* c, Op op,
                    std::vector< boost::shared_ptr<Node> >& args);
        // destructors.
        virtual ~BitvectorOp();

        // clone.
        virtual Node* clone() const;

        // equality method.
        virtual bool equal(const Node* that) const;

        // stream output.
        virtual std::ostream& write(std::ostream& out) const;

        // convert to an SMT expr.
        virtual z3::expr toZ3(Z3AdapterI& c) const;
    };
}
#endif
