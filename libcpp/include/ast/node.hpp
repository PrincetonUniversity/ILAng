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
    class NodeVisitorI;

    typedef boost::shared_ptr<Node> nptr_t;
    typedef std::vector<nptr_t> nptr_vec_t;

    struct npair_t {
        nptr_t var;
        nptr_t init;
        nptr_t ipred;
        nptr_vec_t next_vec;
        nptr_t next;
        const npair_t* parent;

        // construct arch state.
        npair_t(const nptr_t& v, const nptr_t& n)
          : var(v) 
          , init(v)
          , ipred(NULL)
          , next(n) 
          , parent(NULL)
        {
        }

        npair_t(const npair_t* p)
          : var(p->var)
          , init(p->init)
          , ipred(p->ipred)
          , next(NULL)
          , parent(p->parent ? p->parent : p)
        {
        }

        // destructor.
        ~npair_t() 
        {
        }
    };
    typedef std::map<std::string, npair_t> nmap_t;

    class Node {
        // ----------------- PRIVATE MEMBERS ----------------- //
        static int totalObjCnt;
    private:
        // ----------------- PRIVATE METHODS ----------------- //
        void _initName();
    protected:
        // -------------------- DATA MEMBERS ----------------- //
    protected:
        // name for this node.
        std::string name;
        // unique id.
        const int id;
    public: //TODO : for now leave it as public
        // type of this node.
        NodeType type;

    public:
        // ------------ CONSTRUCTORS/DESTRUCTORS ------------ //
        // default constructor.
        Node();
        // constructor.
        Node(NodeType t);
        // destructor.
        virtual ~Node();

        // ---------------------- UTILITIES ------------------ //
        std::string& getName() {
            return name;
        }

        const std::string& getName() const {
            return name;
        }

        int getId() { return id; }
        NodeType getType() { return type; }

        // ---------------------- METHODS ------------------- //
        // polymorphic clone method: do we need this?
        virtual Node* clone() const;
        // polymorphic equality method.
        virtual bool equal(const Node* that) const;
        // output to a stream.
        virtual std::ostream& write(std::ostream& out) const;
        // return the value associated with this object (or None) 
        // if it doesn't exist.
        virtual py::object getValue() const;



        // ----------------- TEMPLATED VISITOR -----------------//
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

        // -------------------- VISITOR ----------------------//
        void visit(NodeVisitorI& vi);


        // number of operands.
        virtual unsigned nArgs() const;

        // operand i.
        virtual nptr_t arg(unsigned i) const;

        // helper function which walks through child nodes in AST
        // and returns true if any "synthesis" construct are present.
        bool hasSynthesisConstructs() const;

        // --------------- STATIC HELPERS --------------------//
        static nptr_t ite(const nptr_t& cond, 
            const nptr_t& t, const nptr_t& f);

        friend class NodeRef;
    };

    std::ostream& operator<<(std::ostream& out, const Node& that);


    // ---------------------------------------------------------------------- //
    struct NodeVisitorI {
        virtual void preVisit(const Node*);
        virtual void postVisit(const Node*);
    };
}

#endif
