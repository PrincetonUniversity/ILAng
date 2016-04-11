#ifndef __AST_NODE_HPP_DEFINED__
#define __AST_NODE_HPP_DEFINED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <z3++.h>
#include <assert.h>
#include <type.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/python.hpp>

namespace ila 
{
    class Abstraction;
    class NodeRef;
    class Node;

    typedef boost::shared_ptr<Node> nptr_t;

    class Node {
        // ----------------- PRIVATE MEMBERS ----------------- //
        static int totalObjCnt;
    private:
        // ----------------- PRIVATE METHODS ----------------- //
        void _initName();
    protected:
        // -------------------- DATA MEMBERS ----------------- //
        // context pointer.
        Abstraction* ctx;
    public:
        // name for this node.
        std::string name;
        // unique id.
        const int id;
        // type of this node.
        NodeType type;

    public:
        // ------------ CONSTRUCTORS/DESTRUCTORS ------------ //
        // default constructor.
        Node();
        // constructor.
        Node(Abstraction* c, NodeType t);
        // destructor.
        virtual ~Node();

        // ---------------------- METHODS ------------------- //
        // fake method we use to test the Z3 integration.
        Abstraction* context() const { return ctx; };
        // polymorphic clone method: do we need this?
        virtual Node* clone() const;
        // polymorphic equality method.
        virtual bool equal(const Node* that) const;
        // output to a stream.
        virtual std::ostream& write(std::ostream& out) const;
        // return the value associated with this object (or None) 
        // if it doesn't exist.
        virtual boost::python::object getValue() const;

        // -------------------- VISITOR ----------------------//
        // Visit each child node in a depth-first order and
        // apply the function object F on it.
        template<class F> void depthFirstVisit(F& func) const {
            unsigned n = nArgs();
            for(unsigned i=0; i != n; i++) {
                const nptr_t& arg_i = this->arg(i);
                arg_i->depthFirstVisit<F>(func);
            }
            func(this);
        }

        // number of operands.
        virtual unsigned nArgs() const;

        // operand i.
        virtual nptr_t arg(unsigned i) const;

        friend class NodeRef;
    };

    std::ostream& operator<<(std::ostream& out, const Node& that);
}

#endif
