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
        // polymorphic clone method.
        virtual Node* clone() const;

        // -------------------- ACCESSORS ------------------- //
        void setNodeRef(NodeRef* nr);

        // --------------------- OPERATORS ------------------ //
        // bitwise complement.
        virtual Node* complement() const;
        // negation. 
        virtual Node* negate() const;
        // logical negation.
        virtual Node* logicalNot() const;
        // addition.
        virtual Node* add(boost::shared_ptr<Node> n2) const;
        // addition with an integer.
        virtual Node* addInt(int r) const;
        // output to a stream.
        virtual std::ostream& write(std::ostream& out) const;
    };
}

#endif
