
#ifndef __AST_BITVEC_HPP_DEFINED__
#define __AST_BITVEC_HPP_DEFINED__

#include <iostream>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>

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
        // constructor for ChoiceExpr.
        BitvectorExpr(Abstraction* c, NodeType t);
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
    };

    // ---------------------------------------------------------------------- //
    // Bitvector constants.
    class BitvectorConst : public BitvectorExpr {
    protected:
        boost::multiprecision::cpp_int value;
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
        // get the value as a string.
        std::string vstr() const {
            return boost::lexical_cast<std::string>(value);
        }
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
            NEGATE, COMPLEMENT, 
            LROTATE, RROTATE, Z_EXT, S_EXT, EXTRACT,
            // binary.
            ADD, SUB, AND, OR, XOR, XNOR, NAND, NOR,
            SDIV, UDIV, SREM, UREM, SMOD, SHL, LSHR, ASHR, 
            MUL, CONCAT, GET_BIT,
            // ternary
            IF, 
        } op;

        static const std::string operatorNames[];

    private:
        // the operands themselves.
        std::vector< boost::shared_ptr<Node> > args;
        std::vector< int > params;        

        // Don't forget to update these helper functions below.
        static bool isUnary(Op op) { 
            return op >= NEGATE && op <= EXTRACT; 
        }
        static bool isBinary(Op op) { 
            return op >= ADD && op <= GET_BIT;
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
        static int getBinaryResultWidth(
            Op op,
            boost::shared_ptr<Node> n1,
            int param);
        static int getNaryResultWidth(
            Op op, 
            std::vector< boost::shared_ptr<Node> >& args);
        static int getNaryResultWidth(
            Op op, 
            std::vector< boost::shared_ptr<Node> >& args, 
            std::vector< int >& params);

        static bool checkUnaryOpWidth(
            Op op, 
            boost::shared_ptr<Node> n, 
            int width);
        static int checkBinaryOpWidth(
            Op op, 
            boost::shared_ptr<Node> n1, 
            boost::shared_ptr<Node> n2, 
            int width);
        static int checkBinaryOpWidth(
            Op op,
            boost::shared_ptr<Node> n1,
            int param,
            int width);
        static int checkNaryOpWidth(
            Op op,
            std::vector< boost::shared_ptr<Node> >& args,
            int width);
        static int checkNaryOpWidth(
            Op op,
            std::vector< boost::shared_ptr<Node> >& args,
            std::vector< int >& params,
            int width);


    public:
        // constructors.
        // Unary op
        BitvectorOp(Abstraction* c, Op op, 
                    boost::shared_ptr<Node> n1);
        BitvectorOp(Abstraction* c, Op op,
                    boost::shared_ptr<Node> n1,
                    int param);
        BitvectorOp(Abstraction* c, Op op, 
                    boost::shared_ptr<Node> n1,
                    int p1, int p2);
        // Binary op
        BitvectorOp(Abstraction* c, Op op, 
                    boost::shared_ptr<Node> n1, 
                    boost::shared_ptr<Node> n2);
        // Ternary op
        BitvectorOp(Abstraction* c, Op op,
                    std::vector< boost::shared_ptr<Node> >& args_);
        // copy-constructor with a fresh set of args.
        BitvectorOp(const BitvectorOp* other, 
                std::vector< boost::shared_ptr<Node> >& args_);
        // destructors.
        virtual ~BitvectorOp();

        // clone.
        virtual Node* clone() const;

        // equality method.
        virtual bool equal(const Node* that) const;

        // stream output.
        virtual std::ostream& write(std::ostream& out) const;

        // number of operands.
        virtual unsigned nArgs() const;

        // operand i.
        virtual boost::shared_ptr<Node> arg(unsigned i) const;

        Op getOp() const { return op; }

        // number of params
        unsigned nParams() const;

        // the ith param.
        int param(unsigned i) const;
    };
}
#endif
