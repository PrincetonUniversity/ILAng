#ifndef __AST_MEM_HPP_DEFINED__
#define __AST_MEM_HPP_DEFINED__

#include <vector>
#include <utility>

#include <ast.hpp>
#include <boost/multiprecision/cpp_int.hpp>

namespace ila 
{
    class Abstraction;

    // ---------------------------------------------------------------------- //
    // base class for all memory expressions.
    class MemExpr : public Node {
    public:
        // constructor.
        MemExpr(Abstraction* c, int addrWidth, int dataWidth);
        // constructor for ChoiceExpr.
        MemExpr(Abstraction* c, NodeType t);
        // destructor.
        virtual ~MemExpr();
    };

    // ---------------------------------------------------------------------- //
    // memory variables.
    class MemVar : public MemExpr {
    public:
        // constructor.
        MemVar(Abstraction* c, const std::string& n, int addrWidth, int dataWidth);
        // destructor.
        virtual ~MemVar();
        // clone.
        virtual Node* clone() const;
        // equality method.
        virtual bool equal(const Node* that) const;
        // stream output.
        virtual std::ostream& write(std::ostream& out) const;
    };

    // ---------------------------------------------------------------------- //
    // bitvector constants.
    class MemConst : public MemExpr {
    public:
        typedef boost::multiprecision::cpp_int mp_int_t;

        typedef std::pair<mp_int_t, mp_int_t> pair_t;
        typedef std::vector<pair_t> mem_values_t;

    protected:
        mp_int_t def_value;
        mem_values_t mem_values;
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
            std::string string_value = 
                boost::python::extract<std::string>(
                    boost::python::str(value));
            return string_value;
        }
    };

    // ---------------------------------------------------------------------- //
    // Bitvector operators.
    class BitvectorOp : public MemExpr {
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
            MUL,  CONCAT,
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
