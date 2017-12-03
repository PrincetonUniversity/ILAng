
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
    class FuncReduction;

    // ---------------------------------------------------------------------- //
    // Bitvector expressions are derived from this class.
    class BitvectorExpr : public Node {
    public:
        // constructor.
        BitvectorExpr(int width);
        // constructor for ChoiceExpr.
        BitvectorExpr(NodeType t);
        // destructor.
        virtual ~BitvectorExpr();
    };

    // ---------------------------------------------------------------------- //
    // Bitvector variables.
    class BitvectorVar : public BitvectorExpr {
    public:
        // constructor.
        BitvectorVar(const std::string& n, int width) ;
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
        mp_int_t value;
    public:
        // constructor with longs.
        BitvectorConst(const mp_int_t& v, int width);
        // constructor with ints.
        BitvectorConst(unsigned int v, int width);
        // copy constructor.
        BitvectorConst(const BitvectorConst& other);
        // destructor.
        virtual ~BitvectorConst();
        // clone
        virtual Node* clone() const;
        // equality method.
        virtual bool equal(const Node* that) const;
        // get value.
        const mp_int_t& val() const { return value; }
        // return value.
        virtual py::object getValue() const;
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
            MUL, CONCAT, GET_BIT, READMEM, READMEMBLOCK,
            // ternary
            IF, APPLY_FUNC 
        } op;

        static const std::string operatorNames[];

    private:
        // the operands themselves.
        nptr_vec_t args;
        std::vector< int > params;        

        // Don't forget to update these helper functions below.
        static bool isUnary(Op op) { 
            return op >= NEGATE && op <= EXTRACT; 
        }
        static bool isBinary(Op op) { 
            return op >= ADD && op <= READMEMBLOCK;
        }
        static bool isTernary(Op op) { 
            return op >= IF && op <= IF; 
        }
        static bool isNary(Op op) {
            return op >= APPLY_FUNC && op <= APPLY_FUNC;
        }
        // helper functions to determine result and argument types.
        static int getUnaryResultWidth(
            Op op, 
            const nptr_t& n);
        static int getBinaryResultWidth(
            Op op, 
            const nptr_t& n1, 
            const nptr_t& n2);
        static int getBinaryResultWidth(
            Op op, 
            const nptr_t& n1, 
            const nptr_t& n2,
            int param);
        static int getBinaryResultWidth(
            Op op,
            const nptr_t& n1,
            int param);
        static int getNaryResultWidth(
            Op op, nptr_vec_t& args);
        static int getNaryResultWidth(
            Op op, nptr_vec_t& args, 
            std::vector< int >& params);

        static bool checkUnaryOpWidth(
            Op op, const nptr_t& n, int width);
        static int checkBinaryOpWidth(
            Op op, 
            const nptr_t& n1, 
            const nptr_t& n2, 
            int width);
        static int checkBinaryOpWidth(
            Op op, 
            const nptr_t& n1, 
            const nptr_t& n2, 
            int param,
            int width);
        static int checkBinaryOpWidth(
            Op op,
            const nptr_t& n1,
            int param,
            int width);
        static int checkNaryOpWidth(
            Op op, nptr_vec_t& args,
            int width);
        static int checkNaryOpWidth(
            Op op,
            nptr_vec_t& args,
            std::vector< int >& params,
            int width);


    public:
        // constructors.
        // Unary op
        BitvectorOp(Op op, 
                    const nptr_t& n1);
        BitvectorOp(Op op,
                    const nptr_t& n1,
                    int param);
        BitvectorOp(Op op, 
                    const nptr_t& n1,
                    int p1, int p2);
        // Binary op
        BitvectorOp(Op op, 
                    const nptr_t& n1, 
                    const nptr_t& n2);
        // Binary op with params (read-block)
        BitvectorOp(Op op, 
                    const nptr_t& n1,
                    const nptr_t& n2,
                    int blocks, endianness_t e);
        // Ternary op
        BitvectorOp(Op op,
                    nptr_vec_t& args_);
        // copy-constructor with a fresh set of args.
        BitvectorOp(const BitvectorOp* other, 
                nptr_vec_t& args_);
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
        virtual nptr_t arg(unsigned i) const;

        Op getOp() const { return op; }

        // number of params
        unsigned nParams() const;

        // the ith param.
        int param(unsigned i) const;

        friend class FuncReduction;
    };
}
#endif
