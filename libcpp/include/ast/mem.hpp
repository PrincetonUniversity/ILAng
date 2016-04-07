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

}
#endif
