#ifndef __AST_HPP_DEFINED__
#define __AST_HPP_DEFINED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <z3++.h>
#include <assert.h>
#include <type.hpp>

#include <ast/node.hpp>
#include <ast/bitvec.hpp>
#include <boost/shared_ptr.hpp>

namespace ila
{
    class NodeRef 
    {
        boost::shared_ptr<Node> node;
    public:
        // Default constructor. DO NOT USE. Will throw an exception.
        NodeRef(); 
        // Constructor. DO NOT USE. Call factory methods in Context instead.
        NodeRef(Node* node);
        // Copy constructor.
        NodeRef(const NodeRef& nr);
        // Destructor.
        ~NodeRef();

        // assignment operator.
        NodeRef& operator=(const NodeRef& other);

        // ---------------------- METHODS ------------------------------- //
        std::string getName() const;
        NodeType getType() const;
        void doSomething();

        // ---------------------- OPERATORS ----------------------------- //
        NodeRef complement() const;
        NodeRef negate() const;
    };

    class Context
    {
    private:
        int objCnt;
    protected:
        // Get a new ID.
        int getObjId();
    public:
        // Constructor.
        Context();
        // Destructor.
        ~Context();
        // Create a bitvector variable.
        NodeRef* BitvectorVar(const std::string& name, int width);

        friend class Node;
    };
}

#endif 
