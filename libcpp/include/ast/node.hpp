#ifndef __AST_NODE_HPP_DEFINED__
#define __AST_NODE_HPP_DEFINED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <z3++.h>
#include <assert.h>
#include <type.hpp>

namespace ila 
{
    class Context;

    class Node {
        // ----------------- PRIVATE MEMBERS ----------------- //
        static int totalObjCnt;
    private:
        // ----------------- PRIVATE METHODS ----------------- //
        void _initName();
    protected:
        // -------------------- DATA MEMBERS ----------------- //
        // context pointer.
        Context* ctx;
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
        Node(Context* c, NodeType t);
        // destructor.
        virtual ~Node();

        // ---------------------- METHODS ------------------- //
        // fake method we use to test the Z3 integration.
        void doSomething();
        // polymorphic clone method.
        virtual Node* clone() const;


        // -------------------- ACCESSORS ------------------- //
        std::string getName() const;
        NodeType getType() const;

        // --------------------- OPERATORS ------------------ //
        // bitwise complement.
        virtual Node* complement() const;
        // negation. 
        virtual Node* negate() const;
    };
}

#endif
