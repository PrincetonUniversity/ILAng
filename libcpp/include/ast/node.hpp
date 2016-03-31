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
#include <boost/python.hpp>

#include <smt.hpp>

namespace ila 
{
    class Abstraction;
    class NodeRef;

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
        // Pointer back to the shared_ptr which holds this node.
        NodeRef* nodeRef;
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
        void doSomething();
        // polymorphic clone method: do we need this?
        virtual Node* clone() const;
        // polymorphic equality method.
        virtual bool equal(const Node* that) const;
        // output to a stream.
        virtual std::ostream& write(std::ostream& out) const;
        // return the value associated with this object (or None) 
        // if it doesn't exist.
        virtual boost::python::object getValue() const;
        // convert to an SMT expr.
        virtual z3::expr toZ3(Z3AdapterI& c) const;
        // rewrite synthesis operators using model.
        virtual z3::expr rewriteToZ3(Z3AdapterI& c, z3::model& m) const;

        // -------------------- ACCESSORS ------------------- //
        void setNodeRef(NodeRef* nr);

        friend class NodeRef;
    };
}

#endif
