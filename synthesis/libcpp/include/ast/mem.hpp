#ifndef __AST_MEM_HPP_DEFINED__
#define __AST_MEM_HPP_DEFINED__

#include <vector>
#include <utility>

#include <ast.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <memvalues.hpp>

namespace ila 
{
    class Abstraction;
    class FuncReduction;

    // ---------------------------------------------------------------------- //
    // base class for all memory expressions.
    class MemExpr : public Node {
    public:

        // constructor.
        MemExpr(int addrWidth, int dataWidth);
        // constructor for ChoiceExpr.
        MemExpr(NodeType t);
        // destructor.
        virtual ~MemExpr();

    };

    // ---------------------------------------------------------------------- //
    // memory variables.
    class MemVar : public MemExpr {
    public:
        // constructor.
        MemVar(const std::string& n, int addrWidth, int dataWidth);
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
    struct MemConst : public MemExpr {
        // fields.
        MemValues memvalues;

        // constructor with longs.
        MemConst(const MemValues& mv);
        // copy constructor.
        MemConst(const MemConst& that);
        // destructor.
        virtual ~MemConst();

        // clone
        virtual Node* clone() const;
        // equality method.
        virtual bool equal(const Node* that) const;
        // stream output.
        virtual std::ostream& write(std::ostream& out) const;
    };

    // ---------------------------------------------------------------------- //
    // write to memory operator.
    class MemOp : public MemExpr {
    public:
        enum Op { INVALID, STORE, STOREBLOCK, ITE } op;
        endianness_t endian;
        static const std::string operatorNames[];
    protected:
        // data members //
        nptr_vec_t args;
    public:
        // constructor
        MemOp(Op op, const nptr_t& a0, const nptr_t& a1, const nptr_t& a2);
        // constructor for store block.
        MemOp(Op op, const nptr_t& mem, 
                     const nptr_t& addr, 
                     const nptr_t& data,
                     endianness_t e);
        // copy constructor.
        MemOp(const MemOp& that);
        // almost a copy constructor.
        MemOp(const MemOp* that, const nptr_vec_t& args);
        // destructor.
        virtual ~MemOp();

        Op getOp() const { return op; }

        // clone.
        virtual Node* clone() const;
        // equality.
        virtual bool equal(const Node* that) const;
        // stream output.
        virtual std::ostream& write(std::ostream& out) const;

        // number of operands.
        virtual unsigned nArgs() const;
        // operand i.
        virtual boost::shared_ptr<Node> arg(unsigned i) const;
        
        friend class FuncReduction;
    };

}
#endif
