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
        // types.
        typedef boost::multiprecision::cpp_int mp_int_t;

        // constructor.
        MemExpr(Abstraction* c, int addrWidth, int dataWidth);
        // constructor for ChoiceExpr.
        MemExpr(Abstraction* c, NodeType t);
        // destructor.
        virtual ~MemExpr();

        // store in memory.
        // virtual void store(const mp_int_t& addr, const mp_int_t& data) = 0;
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

        typedef std::pair<mp_int_t, mp_int_t> pair_t;
        typedef std::vector<pair_t> mem_values_t;

    protected:
        mp_int_t def_value;
        mem_values_t mem_values;
    public:
        // constructor with longs.
        MemConst(Abstraction* c, int addrWidth, int dataWidth, boost::python::long_ v);
        // constructor with ints.
        MemConst(Abstraction* c, int addrWidth, int dataWidth, int v);
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
    // read from memory operator.

    // ---------------------------------------------------------------------- //
    // write to memory operator.
    class MemWr : public MemExpr {
    protected:
        // data members //
        mp_int_t addr;
        mp_int_t data;
        const MemExpr& mem;
    public:
        // constructor
        MemWr(const MemExpr& mem, int addr, int data);
        // constructor with long
        MemWr(const MemExpr& mem, boost::python::long_ addr, boost::python::long_ data);
        // copy constructor.
        MemWr(const MemWr& that);
        // destructor.
        virtual ~MemWr();

        // clone.
        virtual Node* clone() const;
        // equality.
        virtual bool equal(const Node* that) const;
        // stream output.
        virtual std::ostream& write(std::ostream& out) const;
    };

}
#endif
